# std/db

A database abstraction layer for LitaC with built-in support for SQLite and PostgreSQL. The library is structured around four modules:

| Module | Import path | Purpose |
|---|---|---|
| Core | `std/db` | Traits, types, error handling |
| Pool | `std/db/pool` | Thread-safe connection pooling |
| ORM | `std/db/orm` | Generic CRUD helpers |
| Migrations | `std/db/migrations` | Versioned schema migrations |

Driver packages live under `std/db/sqlite/` and `std/db/postgres/`.

---

## Connection

Open a connection directly when you don't need pooling.

### SQLite

```lita
import "std/db"
import "std/db/sqlite/sqlite_db"

// File-based database (WAL mode enabled by default)
var conn: SqliteConnection
var result = Connect("./myapp.db", &conn)
if (result.isError()) {
    // handle error
}

// In-memory database
var memConn: SqliteConnection
Connect(":memory:", &memConn)

// Read-only
var roConn: SqliteConnection
ConnectReadOnly("./myapp.db", &roConn)

// Use as generic SqlConnection trait
var db = conn.conn()
db.execute("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT)")

conn.close()
```

### PostgreSQL

```lita
import "std/db"
import "std/db/postgres/postgres_db"

// Individual parameters
var conn: PgConnection
var result = Connect("localhost", 5432, "mydb", "appuser", "s3cr3t", &conn)
if (result.isError()) {
    // handle error: conn.lastError()
}

// libpq DSN string
var conn2: PgConnection
ConnectDSN("host=localhost port=5432 dbname=mydb user=appuser password=s3cr3t", &conn2)

var db = conn.conn()
db.execute("CREATE TABLE IF NOT EXISTS users (id BIGSERIAL PRIMARY KEY, name TEXT)")

conn.close()
```

### Raw SQL and transactions

```lita
db.begin()

var result = db.execute("INSERT INTO users (name) VALUES ('Alice')")
if (result.isError()) {
    db.rollback()
} else {
    db.commit()
}

// Parameterised query (variadic, type-safe binding)
var rs: SqlResultSet
db.query(&rs, $"SELECT id, name FROM users WHERE id = $1", 42_i64)
while (rs.hasNext()) {
    rs.next()
    var id   = rs.columnInt64(0)
    var name = rs.columnString(1)
}
rs.closeAndReleaseAll()
```

---

## Connection Pool

The pool manages a fixed set of connections and is safe to use from multiple threads.

### SQLite pool

```lita
import "std/db/pool"

var pool: ConnectionPool
var result = ConnectionPoolInit(
    "ldbc://sqlite/./myapp.db?wal=true",
    &pool,
    PoolConfig{.maxSize = 8, .minSize = 2}
)
if (result.isError()) { /* handle */ }

// Acquire (blocks until a connection is free)
var conn: SqlConnection
pool.acquire(&conn)
defer pool.release(conn)

conn.execute("INSERT INTO events (name) VALUES ('startup')")
```

**URI parameters for SQLite:**

| Parameter | Values | Default |
|---|---|---|
| `wal` | `true` / `false` | `true` |
| `readonly` | `true` | `false` |

### PostgreSQL pool

PostgreSQL is not a built-in pool driver. Import `pg_pool_driver` and call `RegisterPostgresDriver()` once before initialising the pool.

```lita
import "std/db/pool"
import "std/db/postgres/pg_pool_driver"

// Register once at startup
RegisterPostgresDriver()

var pool: ConnectionPool
var result = ConnectionPoolInit(
    "ldbc://postgres/mydb?host=localhost&port=5432&user=app&password=s3cr3t",
    &pool,
    PoolConfig{.maxSize = 10, .minSize = 2}
)
if (result.isError()) { /* handle */ }

var conn: SqlConnection
pool.acquire(&conn)
defer pool.release(conn)

conn.execute("INSERT INTO events (name) VALUES ('startup')")
```

**URI parameters for PostgreSQL:**

| Parameter | Default | Description |
|---|---|---|
| `host` | `localhost` | Server hostname |
| `port` | `5432` | Server port |
| `user` | _(empty)_ | Login role |
| `password` | _(empty)_ | Login password |
| `sslmode` | _(libpq default)_ | SSL mode (`disable`, `require`, etc.) |

### Acquire variants

```lita
// Block indefinitely until a connection is available
pool.acquire(&conn)

// Return an error immediately if all connections are in use
pool.tryAcquire(&conn)

// Block up to 5 000 ms, then return an error
pool.acquireTimed(5000_i64, &conn)
```

### Lifecycle

```lita
// Close stops new acquires; in-flight connections remain valid.
pool.close()

// Destroy closes idle connections and frees all pool resources.
// Call after close(), or standalone if no threads are blocked.
pool.destroy()
```

### Custom drivers

Register any driver that implements the `DbDriverFn` signature:

```lita
import "std/db/pool"

func MyConnect(
    path:      *const char,
    params:    *UriParams,
    conn:      *SqlConnection,
    allocator: *const Allocator
) : SqlResult {
    // open a connection, assign *conn = myConnPtr
    ...
}

RegisterDriver(DbDriver{.name = $"mydb", .connect = MyConnect})
// Then: ConnectionPoolInit("ldbc://mydb/path/to/data", &pool, config)
```

---

## ORM

The ORM maps structs to database tables via compile-time annotations and generated methods.

### Defining a model

```lita
import "std/db/orm"

@table(.name = "products")
public struct Product {
    @id(.autogenerated = true)
    @column
    id: i64

    @column(.name = "product_name")
    name: String

    @column(.nullable = true)
    description: String

    @column
    price: f64

    @column
    stock: i32

    @db_ignore
    cachedDiscount: f64   // not persisted
}
```

**Annotations:**

| Annotation | Target | Options |
|---|---|---|
| `@table` | struct | `.name` (required), `.schema` |
| `@column` | field | `.name`, `.nullable`, `.length` |
| `@id` | field | `.autogenerated` |
| `@db_ignore` | field | — |


### Insert

```lita
var p = Product{.name = $"Widget", .price = 9.99_f64, .stock = 100}
var inserted = db.insertOne(&p)
// p.id is now set to the generated primary key

var batch = ArrayInit<Product>(4, defaultAllocator)
batch.add(Product{.name = $"Gadget", .price = 19.99_f64, .stock = 50})
batch.add(Product{.name = $"Doohickey", .price = 4.99_f64, .stock = 200})
db.insertMany(&batch)
```

### Query

```lita
// By primary key
var p = Product{}
var found = db.queryOneById<Product, i64>(&p, 42_i64)

// Filtered list — alias matches the table alias in the WHERE clause
var results = ArrayInit<Product>(16, defaultAllocator)
db.queryMany<Product>(defaultAllocator, &results, $"p", $"where p.price < $1", 20.0_f64)
for (var i = 0; i < results.size(); i += 1) {
    var row = results.get(i)
    // use row.name, row.price, etc.
}
results.free()
```

### Update

```lita
p.price = 11.99_f64
db.updateOne(&p)

db.updateMany(&batch)
```

### Delete

```lita
db.deleteOne(&p)                        // by instance
db.deleteById<Product, i64>(42_i64)     // by ID
db.deleteMany(&batch)                   // batch
```

All ORM methods return the number of rows affected (0 means not found or no change).

---

## Migrations

Migrations apply versioned SQL scripts to a database in order. Each migration is wrapped in a transaction; a failure rolls back that migration and stops the run.

### Migration files

Files must be named `V{N}__{description}.sql` and placed in a single directory:

```
migrations/
  V1__create_users.sql
  V2__add_products_table.sql
  V10__create_indexes.sql
```

A file may contain multiple statements separated by `;`. SQL comments (`--` and `/* */`) are stripped before execution.

### Running migrations

```lita
import "std/db/migrations"

// MigratorInit(conn, migrationsDir, tableName?, allocator?)
// tableName defaults to "schema_migrations"
var m = MigratorInit(db, $"./migrations")

var err = m.migrate()
if (!err.isOk()) {
    // err.description() returns a human-readable message
}
```

`migrate()` is idempotent: re-running it only applies pending migrations.

### Validate without applying

```lita
var err = m.validate()
// Checks checksums of already-applied migrations and detects out-of-order files.
// Returns an error if any integrity issue is found; does not apply any SQL.
```

### Migration status

```lita
var infos = ArrayInit<MigrationInfo>(8, defaultAllocator)
var err = m.status(&infos)
for (var i = 0; i < infos.size(); i += 1) {
    var info = infos.get(i)
    // info.version, info.description, info.applied, info.appliedAt (ISO 8601)
}
infos.free()
```

### MigrationError

```lita
enum MigrationStatus {
    OK,
    IO_ERROR,         // could not read migration directory or file
    SQL_ERROR,        // statement execution failed
    CHECKSUM_MISMATCH,// file was modified after it was applied
    PARSE_ERROR,      // could not parse a migration file
    OUT_OF_ORDER,     // higher version already applied
}
```

### Tracking table

The migrator creates a `schema_migrations` table (or a custom name) automatically:

```sql
CREATE TABLE schema_migrations (
    version     INTEGER NOT NULL,
    filename    TEXT    NOT NULL,
    description TEXT    NOT NULL,
    checksum    TEXT    NOT NULL,  -- 40-char hex SHA1
    applied_at  TEXT    NOT NULL,  -- ISO 8601
    PRIMARY KEY (version)
)
```

---

## Error handling

All operations return or cache a `SqlResult`:

```lita
struct SqlResult {
    type:        SqlResultType      // OK or ERROR
    category:    SqlResultCategory  // NONE, EMPTY_RESULTS, OUT_OF_MEMORY
    errorCode:   i32
    description: String
}
```

Errors are sticky: once a connection has an error, subsequent operations are skipped until `clearError()` is called. This lets you chain calls and check once at the end:

```lita
db.begin()
db.execute("INSERT INTO a VALUES (1)")
db.execute("INSERT INTO b VALUES (2)")
if (db.hasError()) {
    db.rollback()
    db.clearError()
} else {
    db.commit()
}
```
