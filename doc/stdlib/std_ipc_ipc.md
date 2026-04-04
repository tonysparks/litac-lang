# std::ipc::ipc

## Functions

<a id="func-init"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) init() : void

*public* | *stdlib/std/ipc/ipc.lita:14*

---

<a id="func-free"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) free() : void

*public* | *stdlib/std/ipc/ipc.lita:19*

---

<a id="func-open"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) open() : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/ipc/ipc.lita:24*

---

<a id="func-closeread"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) closeRead() : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/ipc/ipc.lita:28*

---

<a id="func-closewrite"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) closeWrite() : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/ipc/ipc.lita:32*

---

<a id="func-wait"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) wait() : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/ipc/ipc.lita:36*

---

<a id="func-write"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) write(str: String) : i32

*public* | *stdlib/std/ipc/ipc.lita:40*

---

<a id="func-read"></a>

### func (this: \*[Ipc](std_ipc_ipc_unix.md#struct-ipc)) read(str: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : i32

*public* | *stdlib/std/ipc/ipc.lita:44*

---

## Types

<a id="struct-ipc"></a>

### struct Ipc

*public* | *stdlib/std/ipc/ipc.lita:10*

| Field | Type | Description |
|-------|------|-------------|
| `ipc` | os::Ipc |  |

---

