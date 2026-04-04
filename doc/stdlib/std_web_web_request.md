# std::web::web_request

## Functions

<a id="func-getbody"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getBody() : String

*public* | *stdlib/std/web/web_request.lita:44*

---

<a id="func-getmethod"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getMethod() : String

*public* | *stdlib/std/web/web_request.lita:52*

---

<a id="func-geturi"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getUri() : String

*public* | *stdlib/std/web/web_request.lita:59*

---

<a id="func-getquery"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getQuery() : String

*public* | *stdlib/std/web/web_request.lita:66*

---

<a id="func-getproto"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getProto() : String

*public* | *stdlib/std/web/web_request.lita:73*

---

<a id="func-getmessage"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getMessage() : String

*public* | *stdlib/std/web/web_request.lita:80*

---

<a id="func-getheader"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getHeader(header: \*const char) : String

*public* | *stdlib/std/web/web_request.lita:87*

---

<a id="func-getqueryvalue"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getQueryValue(key: \*const char, result: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : bool

*public* | *stdlib/std/web/web_request.lita:99*

---

<a id="func-getqueryvaluecopy"></a>

### func (this: \*[WebRequest](std_web_web_request.md#struct-webrequest)) getQueryValueCopy(key: \*const char, length: u32) : [StringBuffer](std_string_buffer.md#struct-stringbuffer)

*public* | *stdlib/std/web/web_request.lita:109*

---

<a id="func-webrequestmatches"></a>

### func WebRequestMatches(msg: \*[mg_http_message](std_web_mongoose.md#struct-mg_http_message), note_method: \*const char, note_uri: \*const char, consumes: \[\]\*const char, consumesLength: u32) : bool

*public* | *stdlib/std/web/web_request.lita:120*

---

## Types

<a id="struct-webrequest"></a>

### struct WebRequest

*public* | *stdlib/std/web/web_request.lita:38*

| Field | Type | Description |
|-------|------|-------------|
| `context` | \*[WebContext](std_web.md#struct-webcontext) |  |
| `msg` | \*[mg_http_message](std_web_mongoose.md#struct-mg_http_message) |  |

---

