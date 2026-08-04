# std/ringhttp

A high-performance HTTP server for LitaC. Uses `io_uring` on Linux and `kqueue` on macOS (the kqueue implementation is not meant for performance, only implemented to use for local development purposes). Supports HTTP/1.1, WebSocket, Server-Sent Events, static file serving, and a middleware filter chain.

## Features/TODO

* ✅ Multi-part support
* ✅ Transfer-Encoding: Chunked
    * ✅ From Request
    * ✅ From Response
* ❌ Transfer-Encoding: Gzip
* ✅ Transfer-Encoding: Deflate
* ✅ Form URL Encoded bodies
* ✅ Path Values
* ✅ Path Templates
* ✅ Query Params
* ✅ Headers
* ✅ Serve static files
* ✅ Connection Keep-Alive (with timeouts)
* ✅ Configurable max request sizes
* ❌ Split into segments: static and dynamic to minimize overall memory footprint
    * Currently all requests are given max/equal amount of memory
* ❌ Clean handling of Out of Memory
    * ❌ OOM for a request
    * ❌ OOM for the server
* ✅ __~840K__ Request/Second on single instance (Request Kind: parse Query Params and echo back in JSON)
    * ✅ Support multi-threading
* ❌ Do performance tuning
    * ❌ SIMD for HTTP parsing
    * ❌ Explore batching opportunities
* 🔧 Client API
    * ✅ Register routes handlers
    * ✅ Register routes with path templates
    * ✅ Allow for global server error handler
    * ✅ Allow for global 404 handler
    * ✅ Allow for setting raw body contents
    * ✅ Allow for chunked replies (via `Stream`)
    * ✅ Allow for specifying headers
    * ❌ API for specifying content-type (`response.json(..)` `response.html(..)`, etc.)
    * 🔧 Template engine integration (mustache? custom?)
        * Use the `pre_build` litac feature to pre-compile template files
* ✅ WebSocket
* ✅ Server Sent Events (SSE)
* 🔧 Test Suite

## Import

```litac
import "std/ringhttp" as ring
```

This re-exports every public symbol from the package, so a single import is enough for normal use.

## Hello World

```litac
import "std/ringhttp" as ring

func helloHandler(ctx: *ring::RequestHandlerContext) : i32 {
    ctx.response.status = 200
    ctx.response.type = ring::ResponseType.BODY
    ctx.response.body.append("Hello, World!")
    return 1
}

func main(len: i32, args: **char) : i32 {
    var config = ring::HttpConfig {
        .allocator = defaultAllocator,
        .port      = 8080_u16,
        .numThreads = 4,
    }

    var server = ring::HttpServer{}
    server.init(&config)

    server.addHttpController(
        ring::HttpMethod.GET,
        "/hello",
        null,
        ring::HttpController { .callback = helloHandler }
    )

    var status = server.start()
    defer server.close()

    return 0
}
```

## Request Handlers

Every HTTP route callback has the signature:

```litac
func myHandler(ctx: *ring::RequestHandlerContext) : i32
```

`RequestHandlerContext` exposes:

| Field | Type | Description |
|---|---|---|
| `request` | `*HttpRequest` | Parsed incoming request |
| `response` | `*HttpResponse` | Response to populate |
| `userData` | `*void` | Pointer passed to `addHttpController` |
| `filterData` | `*void` | Data injected by a filter middleware |
| `match` | `*RouteMatch` | Matched route and path parameter values |
| `allocator` | `*const Allocator` | Per-request allocator; freed after the handler returns |

Return `1` to indicate success, `0` on error (triggers the error handler).

### Reading the Request

**Path parameters** — routes use `{name}` placeholders. The matched values are in `ctx.match.values.entries[]` in declaration order:

```litac
// Route: "/users/{user_id}/items/{item_id}"
var userId   = ctx.match.values.entries[0]  // String
var itemId   = ctx.match.values.entries[1]  // String
```

**Query string:**

```litac
var query = ring::HttpQueryInit(ctx.allocator)
ctx.request.parseQuery(&query)
var page = query.get($"page")   // returns String (empty if absent)
```

Use `query.getParam(name)` and `.getDecodedValue(out)` when the value is percent-encoded.

**Headers:**

```litac
var ct = ctx.request.getHeaderValue($"Content-Type")
```

**Body:**

```litac
// Raw body string
var body = ctx.request.body   // String

// Parsed JSON
if(ctx.request.bodyType == ring::BodyType.JSON) {
    var node = ctx.request.json   // *JsonNode
}

// URL-encoded form
if(ctx.request.bodyType == ring::BodyType.FORM_URLENCODED) {
    for(var i = 0; i < ctx.request.formParams.size(); i += 1) {
        var p = ctx.request.formParams.getPtr(i)
        // p.name, p.value  (String)
    }
}
```

**Cookies:**

```litac
var cookies = ring::HttpCookiesInit(ctx.allocator)
ctx.request.parseCookies(&cookies)
var session = cookies.get($"session_id")
```

### Writing the Response

```litac
ctx.response.status = 200
ctx.response.type   = ring::ResponseType.BODY
ctx.response.body.append("{ \"ok\": true }")
ctx.response.addHeaderStr("Content-Type", "application/json")
```

**Redirect:**

```litac
ctx.response.redirectTo("/login")
```

**Stream** — implement the `Stream` trait and assign it:

```litac
ctx.response.asStream(myStream)
```

**Serve a file** — set `fileServerPath` in `HttpConfig` and map a URI prefix with `publicServerPath`. The server handles `sendfile` automatically.

## Configuration

```litac
var config = ring::HttpConfig {
    .allocator    = defaultAllocator,
    .port         = 8080_u16,
    .numThreads   = 16,
    .maxPoolSize  = 128,

    // Body / header size limits
    .maxHttpBodySizeInBytes   = 2 * MiB,
    .maxHttpHeaderSizeInBytes = 8 * KiB,

    // Keep-alive
    .keepAliveTimeoutInSec = 5,

    // Static files
    .fileServerPath  = $"./public",     // filesystem path
    .publicServerPath = $"/static/",    // URI prefix

    // Templates
    .templatePath = $"./templates",

    // TLS (omit both fields for plain HTTP)
    .tlsCertFile = $"./certs/cert.pem",
    .tlsKeyFile  = $"./certs/key.pem",
}
```

When TLS is enabled, ALPN negotiates h2 or http/1.1 automatically. Omit both cert fields to run plain h1/h2c.

## Middleware

### Filter (pre-dispatch)

Implement `HttpFilterHandler` to intercept requests before the route handler. Return `1` to allow, `0` to block (the filter is responsible for populating the response when blocking).

```litac
struct AuthFilter {
    // ...
}

func (this: *AuthFilter) handleFilter(ctx: *ring::RequestHandlerContext) : i32 {
    if(!isAuthenticated(ctx)) {
        ctx.response.status = 401
        ctx.response.type   = ring::ResponseType.BODY
        ctx.response.body.append("Unauthorized")
        return 0
    }
    return 1
}

server.addFilterHandler(&myAuthFilter)
```

### Post-handler hook

Implement `PostHttpHandler` to run logic after every route handler (not called for WebSocket/SSE upgrades).

```litac
func (this: *MyLogger) postHandle(ctx: *ring::RequestHandlerContext) {
    // log status, timing, etc.
}

server.addPostHandler(&myLogger)
```

### Error and 404 handlers

```litac
server.setErrorHandler(&myApp)      // implements HttpHandler
server.setNotFoundHandler(&myApp)   // implements HttpHandler
```

`HttpHandler` has a single method:

```litac
handle: func(*RequestHandlerContext, ring::Status) : i32
```

## WebSocket

```litac
func wsHandler(session: *ring::WebSocketSession, frame: *ring::Frame) : i32 {
    if(frame.opcode == ring::Opcode.TEXT) {
        var echo = ring::Frame {
            .opcode        = ring::Opcode.TEXT,
            .isFinal       = true,
            .payload       = frame.payload,
            .payloadLength = frame.payloadLength,
        }
        session.send(&echo)
    }
    return 1
}

server.addWebSocketController(
    "/ws",
    null,
    ring::WebSocketController { .callback = wsHandler }
)
```

## Server-Sent Events

```litac
func sseHandler(session: *ring::SseSession) : i32 {
    // Store `session` somewhere; push events from another thread later.
    // The session stays live until the client disconnects or session.close() is called.
    return 1
}

server.addSseController("/events", null, ring::SseController { .callback = sseHandler })

// Push an event:
var event = ring::SseEvent {
    .event = $"update",
    .data  = $"hello",
}
session.send(&event)
```

## Metrics Middleware

The built-in metrics filter records request counts, response counts, blocked counts, and latency histograms using `std/metrics`:

```litac
import "std/metrics"

var registry: Registry
var filter: ring::MetricsFilter

filter.init(&registry)
server.addMetricsMiddleware(&filter)
```

## Platform Notes

| Platform | I/O backend | HTTP/2 |
|---|---|---|
| Linux | `io_uring` | Yes |
| macOS | `kqueue` | Yes |

TLS requires OpenSSL (`-lssl -lcrypto`). The `@compiler_option` annotations in `http_tls.lita` add the linker flags automatically when the module is included.

## Performance

__Host machine__
AMD Ryzen 5 2600 (6 cores) with 16 GiB RAM

__Ring Configuration__
| Setting                | Value  |
|------------------------|--------|
| Threads               | 16     |
| IO_uring Queue Depth  | 64     |
| Max Pool Size         | 512    |
| Log                   | Disabled |


__Results__
| Threads | Connections | Requests Per Second | CPU                 |
|---------|------------|---------------------|----------------------|
| 2       | 20         | 151,978.76          | AMD Ryzen 5 2600     |
| 16      | 200        | 311,170.48          | AMD Ryzen 5 2600     |
| 16      | 200        | 844,053.43          | AMD Ryzen 7 8845HS   |


```
tony@tony-ubuntu:~/projects/ring-http$ wrk -t2 -c20 -d30s --timeout 1s http://localhost:8080/echo?hello=world
Running 30s test @ http://localhost:8080/echo?hello=world
  2 threads and 20 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    88.33us  104.06us   5.13ms   99.28%
    Req/Sec    76.39k     1.73k   80.87k    68.50%
  4559696 requests in 30.00s, 560.95MB read
Requests/sec: 151978.76
Transfer/sec:     18.70MB
tony@tony-ubuntu:~/projects/ring-http$ wrk -t16 -c200 -d30s --timeout 1s http://localhost:8080/echo?hello=world
Running 30s test @ http://localhost:8080/echo?hello=world
  16 threads and 200 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency   670.04us  725.95us  26.26ms   90.12%
    Req/Sec    19.55k     1.37k   36.09k    76.19%
  9341785 requests in 30.02s, 1.12GB read
Requests/sec: 311170.48
Transfer/sec:     38.28MB
```


On my new machine:
AMD Ryzen 7 8845HS w/ Radeon 780M Graphics (16) @ 5.102GHz with 32 GiB RAM

```
tony@mini:~$ wrk -t16 -c200 -d30s --timeout 1s http://localhost:8080/echo?hello=world
Running 30s test @ http://localhost:8080/echo?hello=world
  16 threads and 200 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     1.79ms    8.62ms 427.95ms   96.19%
    Req/Sec    53.11k    16.36k  137.52k    78.23%
  25401875 requests in 30.10s, 3.05GB read
Requests/sec: 844053.43
Transfer/sec:    103.84MB
```
