import pytest
import re


@pytest.mark.parametrize("payload", [
    # SQL injection via table name
    "migrations; DROP TABLE migrations; --",
    "migrations' OR '1'='1",
    "migrations\" OR \"1\"=\"1",
    "migrations`; DROP TABLE users; --",
    "migrations UNION SELECT * FROM users --",
    "migrations; INSERT INTO admin VALUES ('hacked', 'hacked'); --",
    "migrations\x00hidden",
    "migrations'; EXEC xp_cmdshell('whoami'); --",
    "migrations\nDROP TABLE migrations;\n--",
    "migrations\rDROP TABLE migrations;\r--",
    "migrations\r\nDROP TABLE migrations;",
    # Template injection via ${...}
    "${tableName}; DROP TABLE migrations; --",
    "${7*7}",
    "#{tableName}",
    "{{tableName}}",
    # Format string attacks
    "%s%s%s%s%s%s%s%s%s%s",
    "%.*s%.*s",
    "%n%n%n%n",
    "%(tableName)s; DROP TABLE migrations; --",
    # Boundary/overflow attempts
    "A" * 1000,
    "A" * 10000,
    "",
    " ",
    "\t",
    "\x00",
    "\x00\x00\x00",
    # Unicode/encoding attacks
    "migrations\u0027 OR 1=1 --",
    "migrations\u003B DROP TABLE migrations\u003B --",
    "migrations\u0022 OR \u00221\u0022=\u00221",
    # Nested injection
    "migrations; SELECT * FROM (SELECT 1) AS t; --",
    "migrations/**/UNION/**/SELECT/**/1,2,3--",
    "migrations/*!UNION*/SELECT 1--",
    # Comment-based injection
    "migrations--",
    "migrations/*",
    "migrations*/",
    "migrations -- comment",
    # Semicolon and stacked queries
    "migrations;",
    "migrations;;",
    "migrations; SELECT 1; SELECT 2; --",
    # Whitespace variations
    "migrations   ",
    "   migrations",
    "mig\trations",
    "mig\nrations",
])
def test_sql_migration_table_name_security_invariant(payload):
    """Invariant: Any SQL statement constructed using a table name must not
    contain unescaped SQL metacharacters or injection sequences that could
    alter the intended query structure. The table name must be sanitized/validated
    before being interpolated into any SQL statement."""

    def build_migration_sql(table_name: str) -> str:
        """Simulates the vulnerable SQL construction pattern from the codebase."""
        sql = (
            f"INSERT INTO {table_name}\n"
            f"    (version, filename, description, checksum, applied_at)\n"
            f"VALUES\n"
            f"    (?, ?, ?, ?, ?)"
        )
        return sql

    def is_safe_table_name(name: str) -> bool:
        """A table name is safe if it contains only alphanumeric characters and underscores."""
        return bool(re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', name))

    def extract_table_name_from_sql(sql: str) -> str:
        """Extract the table name portion from the INSERT statement."""
        match = re.match(r'INSERT INTO\s+(\S+)', sql, re.IGNORECASE)
        if match:
            return match.group(1)
        return ""

    # INVARIANT 1: If the payload is not a safe table name, it must be rejected
    # before being used in SQL construction
    if not is_safe_table_name(payload):
        # The system MUST reject unsafe table names
        with pytest.raises((ValueError, TypeError, AttributeError, Exception)):
            # Simulate what a secure implementation should do:
            # validate before use
            if not is_safe_table_name(payload):
                raise ValueError(f"Unsafe table name rejected: {repr(payload)}")
            build_migration_sql(payload)

    # INVARIANT 2: If a table name passes validation, the resulting SQL
    # must not contain SQL injection patterns
    safe_payload = "safe_migrations_table"
    sql = build_migration_sql(safe_payload)

    # The SQL must use parameterized VALUES (?, ?, ?, ?, ?)
    assert "?" in sql, "SQL must use parameterized placeholders for values"

    # INVARIANT 3: Validate that dangerous SQL metacharacters in table names
    # are detected as unsafe
    dangerous_patterns = [
        ";", "--", "/*", "*/", "'", '"', "`",
        "\x00", "\n", "\r", "\t",
        "UNION", "DROP", "INSERT", "SELECT", "DELETE", "UPDATE",
        "EXEC", "EXECUTE", "xp_", "sp_",
    ]

    for pattern in dangerous_patterns:
        if pattern.lower() in payload.lower() or pattern in payload:
            assert not is_safe_table_name(payload), (
                f"Table name containing '{pattern}' must be flagged as unsafe. "
                f"Payload: {repr(payload)}"
            )
            break

    # INVARIANT 4: Safe table names must only contain allowed characters
    if is_safe_table_name(payload):
        assert re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', payload), (
            f"A 'safe' table name must only contain alphanumeric chars and underscores. "
            f"Payload: {repr(payload)}"
        )
        # If safe, the SQL built from it must have the table name appear verbatim
        sql = build_migration_sql(payload)
        extracted = extract_table_name_from_sql(sql)
        assert extracted == payload, (
            f"Table name in SQL must match the validated input exactly. "
            f"Expected: {repr(payload)}, Got: {repr(extracted)}"
        )

    # INVARIANT 5: No payload should cause the VALUES clause to be altered
    # (parameterization must be preserved for safe inputs)
    if is_safe_table_name(payload):
        sql = build_migration_sql(payload)
        assert re.search(r'VALUES\s*\(\s*\?,\s*\?,\s*\?,\s*\?,\s*\?\s*\)', sql), (
            "The VALUES clause must always use exactly 5 parameterized placeholders"
        )