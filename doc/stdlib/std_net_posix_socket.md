# std::net::posix_socket

## Functions

<a id="func-strerror"></a>

### func strerror(errnum: i32) : \*const char

*public* | *stdlib/std/net/posix_socket.lita:104*

---

<a id="func-socket"></a>

### func socket(domain: i32, type: i32, protocol: i32) : i32

*public* | *stdlib/std/net/posix_socket.lita:107*

---

<a id="func-bind"></a>

### func bind(socket: i32, addr: \*[sockaddr](std_net_posix_socket.md#struct-sockaddr), addrlen: [socklen_t](std_net_posix_socket.md#typedef-socklen_t)) : i32

*public* | *stdlib/std/net/posix_socket.lita:110*

---

<a id="func-accept"></a>

### func accept(socket: i32, addr: \*[sockaddr](std_net_posix_socket.md#struct-sockaddr), addrlen: \*[socklen_t](std_net_posix_socket.md#typedef-socklen_t)) : i32

*public* | *stdlib/std/net/posix_socket.lita:113*

---

<a id="func-listen"></a>

### func listen(socket: i32, backlog: i32) : i32

*public* | *stdlib/std/net/posix_socket.lita:116*

---

<a id="func-recv"></a>

### func recv(socket: i32, buf: \*void, len: usize, flags: i32) : i64

*public* | *stdlib/std/net/posix_socket.lita:119*

---

<a id="func-send"></a>

### func send(socket: i32, buf: \*void, len: usize, flags: i32) : i64

*public* | *stdlib/std/net/posix_socket.lita:122*

---

<a id="func-setsockopt"></a>

### func setsockopt(socket: i32, level: i32, option_name: i32, option_value: \*const void, option_len: [socklen_t](std_net_posix_socket.md#typedef-socklen_t)) : i32

*public* | *stdlib/std/net/posix_socket.lita:125*

---

<a id="func-close"></a>

### func close(socket: i32) : i32

*public* | *stdlib/std/net/posix_socket.lita:128*

---

<a id="func-htonl"></a>

### func htonl(hostlong: u32) : u32

*public* | *stdlib/std/net/posix_socket.lita:152*

---

<a id="func-htons"></a>

### func htons(hostshort: u16) : u16

*public* | *stdlib/std/net/posix_socket.lita:155*

---

<a id="func-ntohl"></a>

### func ntohl(netlong: u32) : u32

*public* | *stdlib/std/net/posix_socket.lita:158*

---

<a id="func-ntohs"></a>

### func ntohs(netshort: u16) : u16

*public* | *stdlib/std/net/posix_socket.lita:161*

---

<a id="func-inet_pton"></a>

### func inet_pton(af: i32, src: \*const char, dst: \*void) : i32

*public* | *stdlib/std/net/posix_socket.lita:164*

---

<a id="func-inet_ntop"></a>

### func inet_ntop(af: i32, src: \*const void, dst: \*void, size: [socklen_t](std_net_posix_socket.md#typedef-socklen_t)) : \*const char

*public* | *stdlib/std/net/posix_socket.lita:167*

---

## Types

<a id="typedef-socklen_t"></a>

### typedef socklen_t = void

*public* | *stdlib/std/net/posix_socket.lita:15*

---

<a id="struct-sockaddr"></a>

### struct sockaddr

*public* | *stdlib/std/net/posix_socket.lita:18*

| Field | Type | Description |
|-------|------|-------------|
| `sa_family` | i32 |  |
| `sa_data` | \[\]char |  |

---

<a id="struct-sockaddr_in"></a>

### struct sockaddr_in

*public* | *stdlib/std/net/posix_socket.lita:24*

| Field | Type | Description |
|-------|------|-------------|
| `sin_family` | i32 |  |
| `sin_port` | u16 |  |
| `sin_addr` | [in_addr](std_net_posix_socket.md#struct-in_addr) |  |

---

<a id="struct-in_addr"></a>

### struct in_addr

*public* | *stdlib/std/net/posix_socket.lita:31*

| Field | Type | Description |
|-------|------|-------------|
| `s_addr` | u64 |  |

---

<a id="struct-iovec"></a>

### struct iovec

*public* | *stdlib/std/net/posix_socket.lita:36*

| Field | Type | Description |
|-------|------|-------------|
| `iov_base` | \*void |  |
| `iov_len` | usize |  |

---

<a id="struct-msghdr"></a>

### struct msghdr

*public* | *stdlib/std/net/posix_socket.lita:42*

| Field | Type | Description |
|-------|------|-------------|
| `msg_iov` | \*[iovec](std_net_posix_socket.md#struct-iovec) |  |
| `msg_iovlen` | i32 |  |

---

## Variables and Constants

<a id="const-so_debug"></a>

### const SO_DEBUG: i32

*public* | *stdlib/std/net/posix_socket.lita:48*

---

<a id="const-so_broadcast"></a>

### const SO_BROADCAST: i32

*public* | *stdlib/std/net/posix_socket.lita:50*

---

<a id="const-so_reuseaddr"></a>

### const SO_REUSEADDR: i32

*public* | *stdlib/std/net/posix_socket.lita:52*

---

<a id="const-so_keepalive"></a>

### const SO_KEEPALIVE: i32

*public* | *stdlib/std/net/posix_socket.lita:54*

---

<a id="const-so_linger"></a>

### const SO_LINGER: i32

*public* | *stdlib/std/net/posix_socket.lita:56*

---

<a id="const-so_oobinline"></a>

### const SO_OOBINLINE: i32

*public* | *stdlib/std/net/posix_socket.lita:58*

---

<a id="const-so_sndbuf"></a>

### const SO_SNDBUF: i32

*public* | *stdlib/std/net/posix_socket.lita:60*

---

<a id="const-so_rcvbuf"></a>

### const SO_RCVBUF: i32

*public* | *stdlib/std/net/posix_socket.lita:62*

---

<a id="const-so_dontroute"></a>

### const SO_DONTROUTE: i32

*public* | *stdlib/std/net/posix_socket.lita:64*

---

<a id="const-so_rcvlowat"></a>

### const SO_RCVLOWAT: i32

*public* | *stdlib/std/net/posix_socket.lita:66*

---

<a id="const-so_rcvtimeo"></a>

### const SO_RCVTIMEO: i32

*public* | *stdlib/std/net/posix_socket.lita:68*

---

<a id="const-so_sndlowat"></a>

### const SO_SNDLOWAT: i32

*public* | *stdlib/std/net/posix_socket.lita:70*

---

<a id="const-so_sndtimeo"></a>

### const SO_SNDTIMEO: i32

*public* | *stdlib/std/net/posix_socket.lita:72*

---

<a id="const-sol_socket"></a>

### const SOL_SOCKET: i32

*public* | *stdlib/std/net/posix_socket.lita:75*

---

<a id="const-msg_confirm"></a>

### const MSG_CONFIRM: i32

*public* | *stdlib/std/net/posix_socket.lita:91*

---

<a id="const-msg_dontwait"></a>

### const MSG_DONTWAIT: i32

*public* | *stdlib/std/net/posix_socket.lita:92*

---

<a id="const-msg_eor"></a>

### const MSG_EOR: i32

*public* | *stdlib/std/net/posix_socket.lita:93*

---

<a id="const-msg_more"></a>

### const MSG_MORE: i32

*public* | *stdlib/std/net/posix_socket.lita:94*

---

<a id="const-msg_nosignal"></a>

### const MSG_NOSIGNAL: i32

*public* | *stdlib/std/net/posix_socket.lita:95*

---

<a id="const-msg_fastopen"></a>

### const MSG_FASTOPEN: i32

*public* | *stdlib/std/net/posix_socket.lita:96*

---

<a id="const-msg_oob"></a>

### const MSG_OOB: i32

*public* | *stdlib/std/net/posix_socket.lita:99*

---

<a id="const-msg_dontroute"></a>

### const MSG_DONTROUTE: i32

*public* | *stdlib/std/net/posix_socket.lita:101*

---

<a id="const-af_inet"></a>

### const AF_INET: i32

*public* | *stdlib/std/net/posix_socket.lita:131*

---

<a id="const-af_inet6"></a>

### const AF_INET6: i32

*public* | *stdlib/std/net/posix_socket.lita:134*

---

<a id="const-sock_stream"></a>

### const SOCK_STREAM: i32

*public* | *stdlib/std/net/posix_socket.lita:137*

---

<a id="const-sock_dgram"></a>

### const SOCK_DGRAM: i32

*public* | *stdlib/std/net/posix_socket.lita:140*

---

<a id="const-sock_nonblock"></a>

### const SOCK_NONBLOCK: i32

*public* | *stdlib/std/net/posix_socket.lita:143*

---

<a id="const-inet_addrstrlen"></a>

### const INET_ADDRSTRLEN: i32

*public* | *stdlib/std/net/posix_socket.lita:146*

---

<a id="const-inaddr_any"></a>

### const INADDR_ANY: i32

*public* | *stdlib/std/net/posix_socket.lita:149*

---

