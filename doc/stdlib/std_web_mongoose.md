# std::web::mongoose

## Functions

<a id="func-mg_mgr_init"></a>

### func mg_mgr_init(m: \*[mg_mgr](std_web_mongoose.md#struct-mg_mgr)) : void

*public* | *stdlib/std/web/mongoose.lita:47*

---

<a id="func-mg_mgr_free"></a>

### func mg_mgr_free(m: \*[mg_mgr](std_web_mongoose.md#struct-mg_mgr)) : void

*public* | *stdlib/std/web/mongoose.lita:50*

---

<a id="func-mg_mgr_poll"></a>

### func mg_mgr_poll(m: \*[mg_mgr](std_web_mongoose.md#struct-mg_mgr), sleep: i32) : void

*public* | *stdlib/std/web/mongoose.lita:53*

---

<a id="func-mg_http_listen"></a>

### func mg_http_listen(m: \*[mg_mgr](std_web_mongoose.md#struct-mg_mgr), addr: \*const char, fn: [MgConnectionCallback](std_web_mongoose.md#typedef-mgconnectioncallback), args: \*void) : \*[mg_connection](std_web_mongoose.md#struct-mg_connection)

*public* | *stdlib/std/web/mongoose.lita:56*

---

<a id="func-mg_http_match_uri"></a>

### func mg_http_match_uri(m: \*[mg_http_message](std_web_mongoose.md#struct-mg_http_message), uri: \*const char) : void

*public* | *stdlib/std/web/mongoose.lita:59*

---

<a id="func-mg_http_reply"></a>

### func mg_http_reply(c: \*[mg_connection](std_web_mongoose.md#struct-mg_connection), status: i32, headers: \*const char, body: \*const char, ...) : void

*public* | *stdlib/std/web/mongoose.lita:62*

---

<a id="func-mg_strx"></a>

### func mg_strx(str: \*const char) : [mg_str](std_web_mongoose.md#struct-mg_str)

*public* | *stdlib/std/web/mongoose.lita:88*

---

<a id="func-mg_vcmp"></a>

### func mg_vcmp(s1: \*const [mg_str](std_web_mongoose.md#struct-mg_str), s2: \*const char) : i32

*public* | *stdlib/std/web/mongoose.lita:91*

---

<a id="func-mg_match"></a>

### func mg_match(str: [mg_str](std_web_mongoose.md#struct-mg_str), pattern: [mg_str](std_web_mongoose.md#struct-mg_str), caps: \*[mg_str](std_web_mongoose.md#struct-mg_str)) : bool

*public* | *stdlib/std/web/mongoose.lita:94*

---

<a id="func-mg_http_get_header"></a>

### func mg_http_get_header(msg: \*[mg_http_message](std_web_mongoose.md#struct-mg_http_message), name: \*const char) : \*[mg_str](std_web_mongoose.md#struct-mg_str)

*public* | *stdlib/std/web/mongoose.lita:97*

---

<a id="func-mg_http_get_var"></a>

### func mg_http_get_var(buf: \*const [mg_str](std_web_mongoose.md#struct-mg_str), name: \*const char, dst: \*char, dst_len: usize) : i32

*public* | *stdlib/std/web/mongoose.lita:100*

---

## Types

<a id="typedef-mgconnectioncallback"></a>

### typedef MgConnectionCallback = func(\*[mg_connection](std_web_mongoose.md#struct-mg_connection), i32, \*void, \*void) : void

*public* | *stdlib/std/web/mongoose.lita:15*

---

<a id="struct-mg_connection"></a>

### struct mg_connection

*public* | *stdlib/std/web/mongoose.lita:18*

---

<a id="struct-mg_str"></a>

### struct mg_str

*public* | *stdlib/std/web/mongoose.lita:21*

| Field | Type | Description |
|-------|------|-------------|
| `ptr` | \*const char |  |
| `len` | usize |  |

---

<a id="struct-mg_http_header"></a>

### struct mg_http_header

*public* | *stdlib/std/web/mongoose.lita:27*

| Field | Type | Description |
|-------|------|-------------|
| `name` | [mg_str](std_web_mongoose.md#struct-mg_str) |  |
| `value` | [mg_str](std_web_mongoose.md#struct-mg_str) |  |

---

<a id="struct-mg_http_message"></a>

### struct mg_http_message

*public* | *stdlib/std/web/mongoose.lita:33*

| Field | Type | Description |
|-------|------|-------------|
| `method` | [mg_str](std_web_mongoose.md#struct-mg_str) |  |
| `uri` | [mg_str](std_web_mongoose.md#struct-mg_str) |  |
| `query` | [mg_str](std_web_mongoose.md#struct-mg_str) |  |
| `proto` | [mg_str](std_web_mongoose.md#struct-mg_str) |  |
| `headers` | \[\][mg_http_header](std_web_mongoose.md#struct-mg_http_header) |  |
| `body` | [mg_str](std_web_mongoose.md#struct-mg_str) |  |
| `message` | [mg_str](std_web_mongoose.md#struct-mg_str) |  |

---

<a id="struct-mg_mgr"></a>

### struct mg_mgr

*public* | *stdlib/std/web/mongoose.lita:44*

---

<a id="enum-mgevent"></a>

### enum MgEvent

*public* | *stdlib/std/web/mongoose.lita:65*

| Value | Description |
|-------|-------------|
| `MG_EV_ERROR` |  |
| `MG_EV_OPEN` |  |
| `MG_EV_POLL` |  |
| `MG_EV_RESOLVE` |  |
| `MG_EV_CONNECT` |  |
| `MG_EV_ACCEPT` |  |
| `MG_EV_READ` |  |
| `MG_EV_WRITE` |  |
| `MG_EV_CLOSE` |  |
| `MG_EV_HTTP_MSG` |  |
| `MG_EV_HTTP_CHUNK` |  |
| `MG_EV_WS_OPEN` |  |
| `MG_EV_WS_MSG` |  |
| `MG_EV_WS_CTL` |  |
| `MG_EV_MQTT_CMD` |  |
| `MG_EV_MQTT_MSG` |  |
| `MG_EV_MQTT_OPEN` |  |
| `MG_EV_SNTP_TIME` |  |
| `MG_EV_USER` |  |

---

## Variables and Constants

<a id="const-mg_max_http_headers"></a>

### const MG_MAX_HTTP_HEADERS: i32

*public* | *stdlib/std/web/mongoose.lita:12*

---

