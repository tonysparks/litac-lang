# std::web

> 

A hello world web application:

```litac

import "std/libc"
import "std/web"
import "std/string/buffer"
import "std/json"
import "std/json/to_json"
import "std/json/from_json"
import "std/string/builder"

@json
public struct EchoResponse {
    text: *const char
    errors: *const char
}

@get_request(.uri = "/echo")
public func Echo(ctx: *WebContext) : i32 {
    var param = ctx.request.getQueryValueCopy("say")

    var response = EchoResponse{
        .text = param.cStr()
    }
    response.toJson(ctx.response.body)

    return 200
}

func main(len: i32, args: **char) : i32 {
    var server: WebServer;
    var config = WebConfig{}
    printf("Starting http server: %s\n", config.addr)

    server.init(&config)

    server.start()

    printf("Terminated http server")
    return 0
}

```



## Functions

<a id="func-init"></a>

### func (this: \*[WebServer](std_web.md#struct-webserver)) init(config: \*[WebConfig](std_web.md#struct-webconfig), allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [WebStatus](std_web.md#enum-webstatus)

*public* | *stdlib/std/web/web.lita:134*


    Initializes the web server


---

<a id="func-start"></a>

### func (this: \*[WebServer](std_web.md#struct-webserver)) start() : void

*public* | *stdlib/std/web/web.lita:165*


    Starts the web server, blocks indefinetly


---

## Types

<a id="typedef-webcontroller"></a>

### typedef WebController = func(\*[WebContext](std_web.md#struct-webcontext)) : i32

*public* | *stdlib/std/web/web.lita:69*

Callback function from a web request annotation

---

<a id="struct-webcontext"></a>

### struct WebContext

*public* | *stdlib/std/web/web.lita:86*

| Field | Type | Description |
|-------|------|-------------|
| `conn` | \*[mg_connection](std_web_mongoose.md#struct-mg_connection) |  |
| `request` | \*[WebRequest](std_web_web_request.md#struct-webrequest) |  |
| `response` | \*[WebResponse](std_web.md#struct-webresponse) |  |
| `userdata` | \*void |  |
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |

---

<a id="struct-webresponse"></a>

### struct WebResponse

*public* | *stdlib/std/web/web.lita:97*

| Field | Type | Description |
|-------|------|-------------|
| `status` | i32 |  |
| `headers` | [Map](std_map.md#struct-map)\<\*const char, \*const char\> |  |
| `body` | [StringBuilder](std_string_builder.md#struct-stringbuilder) |  |

---

<a id="struct-webconfig"></a>

### struct WebConfig

*public* | *stdlib/std/web/web.lita:103*

| Field | Type | Description |
|-------|------|-------------|
| `addr` | \*const char |  |
| `poll` | i32 |  |
| `userdata` | \*void |  |
| `disableSignals` | bool |  |
| `memBucketSizeInBytes` | usize |  |

---

<a id="enum-webstatus"></a>

### enum WebStatus

*public* | *stdlib/std/web/web.lita:112*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `ERROR` |  |

---

<a id="struct-webserver"></a>

### struct WebServer

*public* | *stdlib/std/web/web.lita:117*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `config` | \*[WebConfig](std_web.md#struct-webconfig) |  |
| `mg` | [mg_mgr](std_web_mongoose.md#struct-mg_mgr) |  |
| `poll` | i32 |  |
| `scratch` | [StringBuilder](std_string_builder.md#struct-stringbuilder) |  |
| `connection` | \*[mg_connection](std_web_mongoose.md#struct-mg_connection) |  |
| `bucketAllocator` | \*[BucketAllocator](std_mem_bucket_allocator.md#struct-bucketallocator) |  |

---

## Variables and Constants

<a id="const-max_http_headers"></a>

### const MAX_HTTP_HEADERS

*public* | *stdlib/std/web/web.lita:95*

---

