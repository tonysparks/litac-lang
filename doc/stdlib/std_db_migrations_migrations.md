# std::db::migrations::migrations

## Functions

<a id="func-isok"></a>

### func isOk(e: \*[MigrationError](std_db_migrations_migrations.md#struct-migrationerror)) : bool

*public* | *stdlib/std/db/migrations/migrations.lita:43*

---

<a id="func-description"></a>

### func description(e: \*[MigrationError](std_db_migrations_migrations.md#struct-migrationerror)) : String

*public* | *stdlib/std/db/migrations/migrations.lita:48*

---

<a id="func-migratorinit"></a>

### func MigratorInit(conn: [SqlConnection](std_db_db.md#trait-sqlconnection), migrationsDir: String, tableName: String, alloc: \*const [Allocator](std_mem.md#struct-allocator)) : [Migrator](std_db_migrations_migrations.md#struct-migrator)

*public* | *stdlib/std/db/migrations/migrations.lita:82*

---

<a id="func-migrate"></a>

### func migrate(m: \*[Migrator](std_db_migrations_migrations.md#struct-migrator)) : [MigrationError](std_db_migrations_migrations.md#struct-migrationerror)

*public* | *stdlib/std/db/migrations/migrations.lita:102*

---

<a id="func-validate"></a>

### func validate(m: \*[Migrator](std_db_migrations_migrations.md#struct-migrator)) : [MigrationError](std_db_migrations_migrations.md#struct-migrationerror)

*public* | *stdlib/std/db/migrations/migrations.lita:158*

---

<a id="func-status"></a>

### func status(m: \*[Migrator](std_db_migrations_migrations.md#struct-migrator), results: \*[Array](std_array.md#struct-array)\<[MigrationInfo](std_db_migrations_migrations.md#struct-migrationinfo)\>) : [MigrationError](std_db_migrations_migrations.md#struct-migrationerror)

*public* | *stdlib/std/db/migrations/migrations.lita:186*

---

## Types

<a id="enum-migrationstatus"></a>

### enum MigrationStatus

*public* | *stdlib/std/db/migrations/migrations.lita:29*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `IO_ERROR` |  |
| `SQL_ERROR` |  |
| `CHECKSUM_MISMATCH` |  |
| `PARSE_ERROR` |  |
| `OUT_OF_ORDER` |  |

---

<a id="struct-migrationerror"></a>

### struct MigrationError

*public* | *stdlib/std/db/migrations/migrations.lita:38*

| Field | Type | Description |
|-------|------|-------------|
| `status` | [MigrationStatus](std_db_migrations_migrations.md#enum-migrationstatus) |  |
| `message` | \[\]char |  |

---

<a id="struct-migrationinfo"></a>

### struct MigrationInfo

*public* | *stdlib/std/db/migrations/migrations.lita:56*

| Field | Type | Description |
|-------|------|-------------|
| `version` | i64 |  |
| `description` | \[\]char |  |
| `filename` | \[\]char |  |
| `checksum` | \[\]char |  |
| `appliedAt` | \[\]char |  |
| `applied` | bool |  |

---

<a id="struct-migrator"></a>

### struct Migrator

*public* | *stdlib/std/db/migrations/migrations.lita:69*

| Field | Type | Description |
|-------|------|-------------|
| `conn` | [SqlConnection](std_db_db.md#trait-sqlconnection) |  |
| `migrationsDir` | String |  |
| `tableName` | String |  |
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |

---

