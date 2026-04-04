# std::db::sqlite::sqlite_db

## Functions

<a id="func-connect"></a>

### func Connect(filename: \*const char, conn: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection), flags: i32, enableWAL: bool, allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:42*

---

<a id="func-connectreadonly"></a>

### func ConnectReadOnly(filename: \*const char, conn: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection), flags: i32, allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:66*

---

<a id="func-conn"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) conn() : [SqlConnection](std_db_db.md#trait-sqlconnection)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:86*

---

<a id="func-getallocator"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) getAllocator() : \*const [Allocator](std_mem.md#struct-allocator)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:90*

---

<a id="func-close"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) close() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:94*

---

<a id="func-lasterror"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) lastError() : String

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:100*

---

<a id="func-lastresult"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) lastResult() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:104*

---

<a id="func-haserror"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) hasError() : bool

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:108*

---

<a id="func-clearerror"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) clearError() : void

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:112*

---

<a id="func-seterror"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) setError(error: [SqlResult](std_db_db.md#struct-sqlresult)) : void

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:120*

---

<a id="func-execute"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) execute(sql: \*const char) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:124*

---

<a id="func-enablewal"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) enableWAL() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:189*

---

<a id="func-disablewal"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) disableWAL() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:193*

---

<a id="func-begin"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) begin() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:197*

---

<a id="func-commit"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) commit() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:201*

---

<a id="func-rollback"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) rollback() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:205*

---

<a id="func-prepare"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) prepare(statement: \*[SqlStatement](std_db_db.md#trait-sqlstatement), sql: String) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:214*

---

<a id="func-release"></a>

### func (this: \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection)) release(stmt: [SqlStatement](std_db_db.md#trait-sqlstatement)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:240*

---

<a id="func-connection"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) connection() : [SqlConnection](std_db_db.md#trait-sqlconnection)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:253*

---

<a id="func-bindblob"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindBlob(index: i32, data: \*const void, size: i32) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:257*

---

<a id="func-bindblob64"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindBlob64(index: i32, data: \*const void, size: u64) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:268*

---

<a id="func-bindfloat64"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindFloat64(index: i32, value: f64) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:279*

---

<a id="func-bindint32"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindInt32(index: i32, value: i32) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:290*

---

<a id="func-bindint64"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindInt64(index: i32, value: i64) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:303*

---

<a id="func-bindnull"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindNull(index: i32) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:314*

---

<a id="func-bindpointer"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindPointer(index: i32, ptr: \*void, type: \*const char) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:325*

---

<a id="func-bindtext"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindText(index: i32, data: \*const char, len: i32) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:336*

---

<a id="func-bindtext64"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindText64(index: i32, data: \*const char, len: u64, enc: u8) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:347*

---

<a id="func-bindstring"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindString(index: i32, str: String) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:358*

---

<a id="func-binddatetime"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) bindDateTime(index: i32, dateTime: [DateTime](std_time.md#struct-datetime)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:369*

---

<a id="func-parametercount"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) parameterCount() : i32

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:390*

---

<a id="func-parametername"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) parameterName(index: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:394*

---

<a id="func-parameterindex"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) parameterIndex(name: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:398*

---

<a id="func-clearbindings"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) clearBindings() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:402*

---

<a id="func-step"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) step() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:410*

---

<a id="func-reset"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) reset() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:418*

---

<a id="func-finalize"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) finalize() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:429*

---

<a id="func-close"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) close() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:437*

---

<a id="func-execute"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) execute(resultSet: \*[SqlResultSet](std_db_db.md#trait-sqlresultset)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:448*

---

<a id="func-release"></a>

### func (this: \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement)) release(resultSet: [SqlResultSet](std_db_db.md#trait-sqlresultset)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:461*

---

<a id="func-statement"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) statement() : [SqlStatement](std_db_db.md#trait-sqlstatement)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:469*

---

<a id="func-closeandreleaseall"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) closeAndReleaseAll() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:473*

---

<a id="func-hasnext"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) hasNext() : bool

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:481*

---

<a id="func-next"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) next() : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:493*

---

<a id="func-columncount"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnCount() : i32

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:509*

---

<a id="func-columnblob"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnBlob(column: i32) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:513*

---

<a id="func-columndouble"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnDouble(column: i32) : f64

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:517*

---

<a id="func-columnint32"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnInt32(column: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:521*

---

<a id="func-columnint64"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnInt64(column: i32) : i64

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:525*

---

<a id="func-columntext"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnText(column: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:529*

---

<a id="func-columnstring"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnString(column: i32) : String

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:533*

---

<a id="func-columndatetime"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnDateTime(column: i32) : [DateTime](std_time.md#struct-datetime)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:537*

---

<a id="func-columntype"></a>

### func (this: \*[SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset)) columnType(column: i32) : [SqlColumnType](std_db_db.md#enum-sqlcolumntype)

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:551*

---

## Types

<a id="typedef-xdel"></a>

### typedef xDel = func(\*void) : void

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:14*

---

<a id="struct-sqliteconnection"></a>

### struct SqliteConnection

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:21*

| Field | Type | Description |
|-------|------|-------------|
| `db` | \*[sqlite3](std_db_sqlite.md#struct-sqlite3) |  |
| `error` | [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `connection` | [SqlConnection](std_db_db.md#trait-sqlconnection) |  |

---

<a id="struct-sqlitestatement"></a>

### struct SqliteStatement

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:29*

| Field | Type | Description |
|-------|------|-------------|
| `conn` | \*[SqliteConnection](std_db_sqlite_sqlite_db.md#struct-sqliteconnection) |  |
| `stmt` | \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt) |  |
| `results` | [SqliteResultSet](std_db_sqlite_sqlite_db.md#struct-sqliteresultset) |  |

---

<a id="struct-sqliteresultset"></a>

### struct SqliteResultSet

*public* | *stdlib/std/db/sqlite/sqlite_db.lita:36*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | \*[SqliteStatement](std_db_sqlite_sqlite_db.md#struct-sqlitestatement) |  |
| `status` | i32 |  |
| `checkError` | bool |  |

---

