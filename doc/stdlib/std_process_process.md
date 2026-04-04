# std::process::process

## Functions

<a id="func-create"></a>

### func (this: \*[Process](std_system.md#struct-process)) create(commandLine: \*\*const char, cwd: \*const char, options: i32) : i32

*public* | *stdlib/std/process/process.lita:16*

---

<a id="func-destroy"></a>

### func (this: \*[Process](std_system.md#struct-process)) destroy() : i32

*public* | *stdlib/std/process/process.lita:41*

---

<a id="func-terminate"></a>

### func (this: \*[Process](std_system.md#struct-process)) terminate() : i32

*public* | *stdlib/std/process/process.lita:45*

---

<a id="func-stdin"></a>

### func (this: \*[Process](std_system.md#struct-process)) stdin() : \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/process/process.lita:49*

---

<a id="func-stdout"></a>

### func (this: \*[Process](std_system.md#struct-process)) stdout() : \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/process/process.lita:53*

---

<a id="func-stderr"></a>

### func (this: \*[Process](std_system.md#struct-process)) stderr() : \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/process/process.lita:57*

---

<a id="func-join"></a>

### func (this: \*[Process](std_system.md#struct-process)) join(result: \*i32) : i32

*public* | *stdlib/std/process/process.lita:61*

---

<a id="func-readstdout"></a>

### func (this: \*[Process](std_system.md#struct-process)) readStdout(buffer: \*char, size: u32) : u32

*public* | *stdlib/std/process/process.lita:87*

---

<a id="func-readstderr"></a>

### func (this: \*[Process](std_system.md#struct-process)) readStderr(buffer: \*char, size: u32) : u32

*public* | *stdlib/std/process/process.lita:92*

---

## Types

<a id="enum-processoption"></a>

### enum ProcessOption

*public* | *stdlib/std/process/process.lita:4*

| Value | Description |
|-------|-------------|
| `COMBINE_STDOUT_STDERR` |  |
| `INHERIT_ENVIRONMENT` |  |
| `ENABLE_ASYNC` |  |
| `INHERIT_IO` |  |

---

<a id="struct-process"></a>

### struct Process

*public* | *stdlib/std/process/process.lita:11*

| Field | Type | Description |
|-------|------|-------------|
| `sub` | [subprocess_s](std_process_subprocess.md#struct-subprocess_s) |  |
| `options` | i32 |  |

---

