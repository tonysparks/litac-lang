# std::net

## Functions

<a id="func-address"></a>

### func (this: \*[SocketAddress](std_net.md#struct-socketaddress)) address() : \*const char

*public* | *stdlib/std/net/net.lita:30*

---

<a id="func-port"></a>

### func (this: \*[SocketAddress](std_net.md#struct-socketaddress)) port() : u16

*public* | *stdlib/std/net/net.lita:35*

---

<a id="func-fromipaddress"></a>

### func FromIPAddress(ip: \*const char, port: u16, result: \*[SocketAddress](std_net.md#struct-socketaddress)) : \*[SocketAddress](std_net.md#struct-socketaddress)

*public* | *stdlib/std/net/net.lita:40*

---

<a id="func-fromport"></a>

### func FromPort(port: u16, result: \*[SocketAddress](std_net.md#struct-socketaddress)) : \*[SocketAddress](std_net.md#struct-socketaddress)

*public* | *stdlib/std/net/net.lita:45*

---

<a id="func-create"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) create(type: [SocketType](std_net.md#enum-sockettype)) : bool

*public* | *stdlib/std/net/net.lita:88*

---

<a id="func-socketaddress"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) socketAddress() : \*[SocketAddress](std_net.md#struct-socketaddress)

*public* | *stdlib/std/net/net.lita:93*

---

<a id="func-bind"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) bind() : bool

*public* | *stdlib/std/net/net.lita:98*

---

<a id="func-listen"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) listen(backlog: i32) : bool

*public* | *stdlib/std/net/net.lita:104*

---

<a id="func-accept"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) accept(clientSocket: \*[Socket](std_net.md#struct-socket)) : \*[Socket](std_net.md#struct-socket)

*public* | *stdlib/std/net/net.lita:109*

---

<a id="func-read"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) read(buffer: \*void, len: usize) : i64

*public* | *stdlib/std/net/net.lita:114*

---

<a id="func-write"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) write(buffer: \*void, len: usize, flags: i32) : i64

*public* | *stdlib/std/net/net.lita:119*

---

<a id="func-setsocketopt"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) setSocketOpt(option: [SocketOption](std_net.md#enum-socketoption), value: \*const void, len: usize) : i32

*public* | *stdlib/std/net/net.lita:124*

---

<a id="func-handle"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) handle() : i32

*public* | *stdlib/std/net/net.lita:129*

---

<a id="func-close"></a>

### func (this: \*[Socket](std_net.md#struct-socket)) close() : void

*public* | *stdlib/std/net/net.lita:134*

---

<a id="func-testgenerated"></a>

### func testGenerated() : void

*public* | *stdlib/std/net/net.lita:141*

---

## Types

<a id="enum-addresstype"></a>

### enum AddressType

*public* | *stdlib/std/net/net.lita:11*

| Value | Description |
|-------|-------------|
| `IPV4` |  |
| `IPV6` |  |

---

<a id="enum-sockettype"></a>

### enum SocketType

*public* | *stdlib/std/net/net.lita:16*

| Value | Description |
|-------|-------------|
| `DATAGRAM` |  |
| `STREAM` |  |

---

<a id="struct-socketaddress"></a>

### struct SocketAddress

*public* | *stdlib/std/net/net.lita:26*

---

<a id="enum-socketoption"></a>

### enum SocketOption

*public* | *stdlib/std/net/net.lita:56*

| Value | Description |
|-------|-------------|
| `SO_DEBUG` |  |
| `SO_BROADCAST` |  |
| `SO_REUSEADDR` |  |
| `SO_KEEPALIVE` |  |
| `SO_LINGER` |  |
| `SO_OOBINLINE` |  |
| `SO_SNDBUF` |  |
| `SO_RCVBUF` |  |
| `SO_DONTROUTE` |  |
| `SO_RCVLOWAT` |  |
| `SO_RCVTIMEO` |  |
| `SO_SNDLOWAT` |  |
| `SO_SNDTIMEO` |  |

---

<a id="enum-socketflags"></a>

### enum SocketFlags

*public* | *stdlib/std/net/net.lita:73*

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

<a id="struct-socket"></a>

### struct Socket

*public* | *stdlib/std/net/net.lita:85*

---

## Variables and Constants

<a id="const-max_address_size"></a>

### const MAX_ADDRESS_SIZE: u32

*public* | *stdlib/std/net/net.lita:22*

---

