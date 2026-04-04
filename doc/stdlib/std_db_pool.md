# std::db::pool

## Functions

<a id="func-get"></a>

### func (this: \*[UriParams](std_db_pool.md#struct-uriparams)) get(key: \*const char) : \*const char

*public* | *stdlib/std/db/pool.lita:35*

---

<a id="func-getbool"></a>

### func (this: \*[UriParams](std_db_pool.md#struct-uriparams)) getBool(key: \*const char, defaultVal: bool) : bool

*public* | *stdlib/std/db/pool.lita:44*

---

<a id="func-registerdriver"></a>

### func RegisterDriver(driver: [DbDriver](std_db_pool.md#struct-dbdriver)) : void

*public* | *stdlib/std/db/pool.lita:96*

---

<a id="func-connectionpoolinit"></a>

### func ConnectionPoolInit(uri: \*const char, pool: \*[ConnectionPool](std_db_pool.md#struct-connectionpool), config: [PoolConfig](std_db_pool.md#struct-poolconfig)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/pool.lita:144*

---

<a id="func-acquire"></a>

### func (this: \*[ConnectionPool](std_db_pool.md#struct-connectionpool)) acquire(conn: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/pool.lita:190*

---

<a id="func-tryacquire"></a>

### func (this: \*[ConnectionPool](std_db_pool.md#struct-connectionpool)) tryAcquire(conn: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/pool.lita:227*

---

<a id="func-acquiretimed"></a>

### func (this: \*[ConnectionPool](std_db_pool.md#struct-connectionpool)) acquireTimed(timeoutMs: i64, conn: \*[SqlConnection](std_db_db.md#trait-sqlconnection)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/pool.lita:258*

---

<a id="func-release"></a>

### func (this: \*[ConnectionPool](std_db_pool.md#struct-connectionpool)) release(conn: [SqlConnection](std_db_db.md#trait-sqlconnection)) : void

*public* | *stdlib/std/db/pool.lita:298*

---

<a id="func-close"></a>

### func (this: \*[ConnectionPool](std_db_pool.md#struct-connectionpool)) close() : void

*public* | *stdlib/std/db/pool.lita:316*

---

<a id="func-destroy"></a>

### func (this: \*[ConnectionPool](std_db_pool.md#struct-connectionpool)) destroy() : void

*public* | *stdlib/std/db/pool.lita:326*

---

## Types

<a id="struct-uriparams"></a>

### struct UriParams

*public* | *stdlib/std/db/pool.lita:30*

| Field | Type | Description |
|-------|------|-------------|
| `params` | \[\]UriParam |  |
| `count` | i32 |  |

---

<a id="typedef-dbdriverfn"></a>

### typedef DbDriverFn = func(\*const char, \*[UriParams](std_db_pool.md#struct-uriparams), \*[SqlConnection](std_db_db.md#trait-sqlconnection), \*const [Allocator](std_mem.md#struct-allocator)) : [SqlResult](std_db_db.md#struct-sqlresult)

*public* | *stdlib/std/db/pool.lita:80*

---

<a id="struct-dbdriver"></a>

### struct DbDriver

*public* | *stdlib/std/db/pool.lita:85*

| Field | Type | Description |
|-------|------|-------------|
| `name` | String |  |
| `connect` | [DbDriverFn](std_db_pool.md#typedef-dbdriverfn) |  |

---

<a id="struct-poolconfig"></a>

### struct PoolConfig

*public* | *stdlib/std/db/pool.lita:108*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `maxSize` | i32 |  |
| `minSize` | i32 |  |

---

<a id="struct-connectionpool"></a>

### struct ConnectionPool

*public* | *stdlib/std/db/pool.lita:114*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `uri` | \[\]char |  |
| `driver` | \[\]char |  |
| `path` | \[\]char |  |
| `params` | [UriParams](std_db_pool.md#struct-uriparams) |  |
| `config` | [PoolConfig](std_db_pool.md#struct-poolconfig) |  |
| `mutex` | [Mutex](std_thread_thread_win.md#struct-mutex) |  |
| `available` | [Cond](std_thread_thread_win.md#struct-cond) |  |
| `idle` | [Array](std_array.md#struct-array)\<[SqlConnection](std_db_db.md#trait-sqlconnection)\> |  |
| `totalSize` | i32 |  |
| `closed` | bool |  |

---

## Variables and Constants

<a id="const-max_uri_len"></a>

### const MAX_URI_LEN

*public* | *stdlib/std/db/pool.lita:12*

---

<a id="const-max_driver_len"></a>

### const MAX_DRIVER_LEN

*public* | *stdlib/std/db/pool.lita:13*

---

<a id="const-max_uri_params"></a>

### const MAX_URI_PARAMS

*public* | *stdlib/std/db/pool.lita:14*

---

<a id="const-max_param_key"></a>

### const MAX_PARAM_KEY

*public* | *stdlib/std/db/pool.lita:15*

---

<a id="const-max_param_val"></a>

### const MAX_PARAM_VAL

*public* | *stdlib/std/db/pool.lita:16*

---

<a id="const-max_drivers"></a>

### const MAX_DRIVERS

*public* | *stdlib/std/db/pool.lita:17*

---

