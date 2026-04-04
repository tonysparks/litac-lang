# std::http::http

## Functions

<a id="func-headersinit"></a>

### func HeadersInit(initialSize: i32, allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [Headers](std_http_http.md#typedef-headers)

*public* | *stdlib/std/http/http.lita:37*

---

<a id="func-init"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) init(options: \*[HttpOptions](std_http_http.md#struct-httpoptions), allocator: \*const [Allocator](std_mem.md#struct-allocator)) : bool

*public* | *stdlib/std/http/http.lita:82*

---

<a id="func-free"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) free() : void

*public* | *stdlib/std/http/http.lita:98*

---

<a id="func-setproxy"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) setProxy(proxy: \*const char) : void

*public* | *stdlib/std/http/http.lita:107*

---

<a id="func-get"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) get(url: \*const char, resp: \*[HttpResponse](std_http_http.md#struct-httpresponse)) : bool

*public* | *stdlib/std/http/http.lita:114*

---

<a id="func-head"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) head(url: \*const char, resp: \*[HttpResponse](std_http_http.md#struct-httpresponse)) : bool

*public* | *stdlib/std/http/http.lita:128*

---

<a id="func-delete"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) delete(url: \*const char, resp: \*[HttpResponse](std_http_http.md#struct-httpresponse)) : bool

*public* | *stdlib/std/http/http.lita:142*

---

<a id="func-post"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) post(url: \*const char, resp: \*[HttpResponse](std_http_http.md#struct-httpresponse), body: String, headers: \*[Headers](std_http_http.md#typedef-headers)) : bool

*public* | *stdlib/std/http/http.lita:156*

---

<a id="func-put"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) put(url: \*const char, resp: \*[HttpResponse](std_http_http.md#struct-httpresponse), body: String, headers: \*[Headers](std_http_http.md#typedef-headers)) : bool

*public* | *stdlib/std/http/http.lita:179*

---

<a id="func-makerequest"></a>

### func (this: \*[Http](std_http_http.md#struct-http)) makeRequest(req: \*[HttpRequest](std_http_http.md#struct-httprequest), resp: \*[HttpResponse](std_http_http.md#struct-httpresponse)) : bool

*public* | *stdlib/std/http/http.lita:196*

---

## Types

<a id="enum-httprequesttype"></a>

### enum HttpRequestType

*public* | *stdlib/std/http/http.lita:11*

| Value | Description |
|-------|-------------|
| `GET` |  |
| `POST` |  |
| `PUT` |  |
| `DELETE` |  |
| `PATCH` |  |
| `HEAD` |  |
| `OPTION` |  |
| `MAX_REQUEST_TYPE` |  |

---

<a id="typedef-httpresponsecallback"></a>

### typedef HttpResponseCallback = func(\*void, usize, usize, \*void) : usize

*public* | *stdlib/std/http/http.lita:33*

---

<a id="typedef-httpstreamcallback"></a>

### typedef HttpStreamCallback = func(\*void, usize, usize, \*void) : usize

*public* | *stdlib/std/http/http.lita:34*

---

<a id="typedef-headers"></a>

### typedef Headers = [Map](std_map.md#struct-map)\<String, String\>

*public* | *stdlib/std/http/http.lita:36*

---

<a id="enum-httpbodykind"></a>

### enum HttpBodyKind

*public* | *stdlib/std/http/http.lita:43*

| Value | Description |
|-------|-------------|
| `NONE` |  |
| `BODY` |  |
| `STREAM` |  |

---

<a id="struct-httpbody"></a>

### struct HttpBody

*public* | *stdlib/std/http/http.lita:48*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [HttpBodyKind](std_http_http.md#enum-httpbodykind) |  |

---

<a id="struct-httprequest"></a>

### struct HttpRequest

*public* | *stdlib/std/http/http.lita:56*

| Field | Type | Description |
|-------|------|-------------|
| `url` | \*const char |  |
| `headers` | [Headers](std_http_http.md#typedef-headers) |  |
| `type` | [HttpRequestType](std_http_http.md#enum-httprequesttype) |  |
| `body` | [HttpBody](std_http_http.md#struct-httpbody) |  |

---

<a id="struct-httpresponse"></a>

### struct HttpResponse

*public* | *stdlib/std/http/http.lita:63*

| Field | Type | Description |
|-------|------|-------------|
| `statusCode` | i32 |  |
| `headers` | [Headers](std_http_http.md#typedef-headers) |  |
| `body` | [StringBuilder](std_string_builder.md#struct-stringbuilder) |  |
| `userdata` | \*void |  |
| `bodyFn` | [HttpResponseCallback](std_http_http.md#typedef-httpresponsecallback) |  |

---

<a id="struct-httpoptions"></a>

### struct HttpOptions

*public* | *stdlib/std/http/http.lita:73*

| Field | Type | Description |
|-------|------|-------------|
| `proxy` | \*const char |  |

---

<a id="struct-http"></a>

### struct Http

*public* | *stdlib/std/http/http.lita:77*

| Field | Type | Description |
|-------|------|-------------|
| `options` | [HttpOptions](std_http_http.md#struct-httpoptions) |  |
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |

---

