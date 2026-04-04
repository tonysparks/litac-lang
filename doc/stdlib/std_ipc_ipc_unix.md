# std::ipc::ipc_unix

## Functions

<a id="func-init"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) init() : void

*public* | *stdlib/std/ipc/ipc_unix.lita:85*

---

<a id="func-free"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) free() : void

*public* | *stdlib/std/ipc/ipc_unix.lita:90*

---

<a id="func-open"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) open() : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/ipc/ipc_unix.lita:102*

---

<a id="func-ischild"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) isChild() : bool

*public* | *stdlib/std/ipc/ipc_unix.lita:111*

---

<a id="func-closeread"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) closeRead() : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/ipc/ipc_unix.lita:115*

---

<a id="func-closewrite"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) closeWrite() : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/ipc/ipc_unix.lita:119*

---

<a id="func-wait"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) wait() : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/ipc/ipc_unix.lita:123*

---

<a id="func-write"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) write(str: String) : i32

*public* | *stdlib/std/ipc/ipc_unix.lita:127*

---

<a id="func-read"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) read(str: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : i32

*public* | *stdlib/std/ipc/ipc_unix.lita:133*

---

## Types

<a id="struct-ipc"></a>

### struct Ipc

*public* | *stdlib/std/ipc/ipc_unix.lita:79*

| Field | Type | Description |
|-------|------|-------------|
| `fds` | \[\]i32 |  |
| `pid` | pid_t |  |
| `status` | [FileStatus](std_io.md#enum-filestatus) |  |

---

