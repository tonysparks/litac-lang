# std::db::db

## Functions

<a id="func-iserror"></a>

### func (this: [SqlResult](std_db_db.md#struct-sqlresult)) isError() : bool

*public* | *stdlib/std/db/db.lita:146*

---

<a id="func-isok"></a>

### func (this: [SqlResult](std_db_db.md#struct-sqlresult)) isOk() : bool

*public* | *stdlib/std/db/db.lita:150*

---

<a id="func-isemptyresults"></a>

### func (this: [SqlResult](std_db_db.md#struct-sqlresult)) isEmptyResults() : bool

*public* | *stdlib/std/db/db.lita:154*

---

<a id="func-query"></a>

### func (this: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) query(resultSet: \*[SqlResultSet](std_db_db.md#trait-sqlresultset), sql: String, ...) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/db.lita:159*

---

## Types

<a id="enum-sqlresulttype"></a>

### enum SqlResultType

*public* | *stdlib/std/db/db.lita:38*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `ERROR` |  |

---

<a id="enum-sqlresultcategory"></a>

### enum SqlResultCategory

*public* | *stdlib/std/db/db.lita:43*

| Value | Description |
|-------|-------------|
| `NONE` |  |
| `EMPTY_RESULTS` |  |
| `OUT_OF_MEMORY` |  |

---

<a id="struct-sqlresult"></a>

### struct SqlResult

*public* | *stdlib/std/db/db.lita:49*

| Field | Type | Description |
|-------|------|-------------|
| `type` | [SqlResultType](std_db_db.md#enum-sqlresulttype) |  |
| `category` | [SqlResultCategory](std_db_db.md#enum-sqlresultcategory) |  |
| `errorCode` | i32 |  |
| `description` | String |  |

---

<a id="trait-sqlconnection"></a>

### trait SqlConnection

*public* | *stdlib/std/db/db.lita:56*

| Field | Type | Description |
|-------|------|-------------|
| `getAllocator` | func() : \*const [Allocator](std_mem.md#struct-allocator) |  |
| `lastError` | func() : String |  |
| `lastResult` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `hasError` | func() : bool |  |
| `clearError` | func() : void |  |
| `setError` | func([SqlResult](std_db_db.md#struct-sqlresult)) : void |  |
| `execute` | func(\*const char) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `begin` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `commit` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `rollback` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `prepare` | func(\*[SqlStatement](std_db_db.md#trait-sqlstatement), String) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `release` | func([SqlStatement](std_db_db.md#trait-sqlstatement)) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `close` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `__this` | \*void |  |

---

<a id="trait-sqlstatement"></a>

### trait SqlStatement

*public* | *stdlib/std/db/db.lita:80*

| Field | Type | Description |
|-------|------|-------------|
| `bindBlob` | func(i32, \*const void, i32) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindBlob64` | func(i32, \*const void, u64) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindFloat64` | func(i32, f64) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindInt32` | func(i32, i32) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindInt64` | func(i32, i64) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindNull` | func(i32) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindPointer` | func(i32, \*void, \*const char) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindText` | func(i32, \*const char, i32) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindText64` | func(i32, \*const char, u64, u8) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindString` | func(i32, String) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `bindDateTime` | func(i32, [DateTime](std_time.md#struct-datetime)) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `parameterCount` | func() : i32 |  |
| `parameterName` | func(i32) : \*const char |  |
| `parameterIndex` | func(\*const char) : i32 |  |
| `clearBindings` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `step` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `reset` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `finalize` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `close` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `execute` | func(\*[SqlResultSet](std_db_db.md#trait-sqlresultset)) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `release` | func([SqlResultSet](std_db_db.md#trait-sqlresultset)) : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `connection` | func() : [SqlConnection](std_db_db.md#trait-sqlconnection) |  |
| `__this` | \*void |  |

---

<a id="enum-sqlcolumntype"></a>

### enum SqlColumnType

*public* | *stdlib/std/db/db.lita:109*

| Value | Description |
|-------|-------------|
| `UNKNOWN` |  |
| `NULL` |  |
| `INT` |  |
| `BIGINT` |  |
| `STRING` |  |
| `TEXT` |  |
| `BLOB` |  |
| `DOUBLE` |  |
| `DATE` |  |
| `DATETIME` |  |
| `TIME` |  |
| `CUSTOM` |  |

---

<a id="trait-sqlresultset"></a>

### trait SqlResultSet

*public* | *stdlib/std/db/db.lita:126*

| Field | Type | Description |
|-------|------|-------------|
| `hasNext` | func() : bool |  |
| `next` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `columnCount` | func() : i32 |  |
| `columnBlob` | func(i32) : \*const void |  |
| `columnDouble` | func(i32) : f64 |  |
| `columnInt32` | func(i32) : i32 |  |
| `columnInt64` | func(i32) : i64 |  |
| `columnText` | func(i32) : \*const char |  |
| `columnString` | func(i32) : String |  |
| `columnDateTime` | func(i32) : [DateTime](std_time.md#struct-datetime) |  |
| `columnType` | func(i32) : [SqlColumnType](std_db_db.md#enum-sqlcolumntype) |  |
| `statement` | func() : [SqlStatement](std_db_db.md#trait-sqlstatement) |  |
| `closeAndReleaseAll` | func() : [SqlResult](std_db_db.md#struct-sqlresult) |  |
| `__this` | \*void |  |

---

