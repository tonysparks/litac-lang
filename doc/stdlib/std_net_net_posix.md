# std::net::net_posix

## Functions

<a id="func-fromipaddress"></a>

### func FromIPAddress(ip: \*const char, port: u16, result: \*[SocketAddress](std_net.md#struct-socketaddress)) : \*[SocketAddress](std_net.md#struct-socketaddress)

*public* | *stdlib/std/net/net_posix.lita:41*

---

<a id="func-fromport"></a>

### func FromPort(port: u16, result: \*[SocketAddress](std_net.md#struct-socketaddress)) : \*[SocketAddress](std_net.md#struct-socketaddress)

*public* | *stdlib/std/net/net_posix.lita:58*

---

<a id="func-address"></a>

### func (this: \*[SocketAddress](std_net.md#struct-socketaddress)) address() : \*const char

*public* | *stdlib/std/net/net_posix.lita:72*

---

<a id="func-port"></a>

### func (this: \*[SocketAddress](std_net.md#struct-socketaddress)) port() : u16

*public* | *stdlib/std/net/net_posix.lita:77*

---

<a id="func-tostring"></a>

### func (this: \*[SocketAddress](std_net.md#struct-socketaddress)) toString() : \*const char

*public* | *stdlib/std/net/net_posix.lita:81*

---

<a id="func-create"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) create(type: [SocketType](std_net.md#enum-sockettype)) : bool

*public* | *stdlib/std/net/net_posix.lita:100*

---

<a id="func-socketaddress"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) socketAddress() : \*[SocketAddress](std_net.md#struct-socketaddress)

*public* | *stdlib/std/net/net_posix.lita:108*

---

<a id="func-bind"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) bind() : bool

*public* | *stdlib/std/net/net_posix.lita:113*

---

<a id="func-listen"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) listen(backlog: i32) : bool

*public* | *stdlib/std/net/net_posix.lita:120*

---

<a id="func-accept"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) accept(clientSocket: \*[Socket](std_net.md#struct-socket)) : \*[Socket](std_net.md#struct-socket)

*public* | *stdlib/std/net/net_posix.lita:125*

---

<a id="func-setsocketopt"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) setSocketOpt(option: [SocketOption](std_net.md#enum-socketoption), value: \*const void, len: usize) : i32

*public* | *stdlib/std/net/net_posix.lita:142*

---

<a id="func-read"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) read(buffer: \*void, len: usize) : i64

*public* | *stdlib/std/net/net_posix.lita:164*

---

<a id="func-write"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) write(buffer: \*void, len: usize, flags: i32) : i64

*public* | *stdlib/std/net/net_posix.lita:169*

---

<a id="func-handle"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) handle() : i32

*public* | *stdlib/std/net/net_posix.lita:174*

---

<a id="func-close"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) close() : void

*public* | *stdlib/std/net/net_posix.lita:179*

---

## Types

<a id="enum-socketflags"></a>

### enum SocketFlags

*public* | *stdlib/std/net/net_posix.lita:9*

| Value | Description |
|-------|-------------|
| `MSG_CONFIRM` |  |
| `MSG_DONTROUTE` |  |
| `MSG_DONTWAIT` |  |
| `MSG_EOR` |  |
| `MSG_MORE` |  |
| `MSG_NOSIGNAL` |  |
| `MSG_OOB` |  |
| `MSG_FASTOPEN` |  |

---

<a id="struct-socketaddress"></a>

### struct SocketAddress

*public* | *stdlib/std/net/net_posix.lita:31*

| Field | Type | Description |
|-------|------|-------------|
| `type` | [AddressType](std_net.md#enum-addresstype) |  |
| `_address` | \[\]char |  |
| `_port` | u16 |  |
| `addr` | [sockaddr_in](std_net_posix_socket.md#struct-sockaddr_in) |  |

---

<a id="struct-socket"></a>

### struct Socket

*public* | *stdlib/std/net/net_posix.lita:94*

| Field | Type | Description |
|-------|------|-------------|
| `socket` | i32 |  |
| `address` | [SocketAddress](std_net.md#struct-socketaddress) |  |

---

## Variables and Constants

<a id="const-max_address_size"></a>

### const MAX_ADDRESS_SIZE

*public* | *stdlib/std/net/net_posix.lita:28*

---

