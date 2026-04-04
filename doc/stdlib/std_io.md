# std::io

## Functions

<a id="func-open"></a>

### func open(file: \*[File](std_io.md#struct-file), filename: \*const char, op: [FileOpenOp](std_io.md#enum-fileopenop)) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io.lita:55*

---

<a id="func-length"></a>

### func length(file: \*[File](std_io.md#struct-file)) : i64

*public* | *stdlib/std/io/io.lita:98*

---

<a id="func-handle"></a>

### func handle(file: \*[File](std_io.md#struct-file)) : i32

*public* | *stdlib/std/io/io.lita:117*

---

<a id="func-position"></a>

### func position(file: \*[File](std_io.md#struct-file)) : i64

*public* | *stdlib/std/io/io.lita:126*

---

<a id="func-seek"></a>

### func (this: \*[File](std_io.md#struct-file)) seek(pos: i64) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io.lita:130*

---

<a id="func-close"></a>

### func close(file: \*[File](std_io.md#struct-file)) : void

*public* | *stdlib/std/io/io.lita:138*

---

<a id="func-readbytes"></a>

### func (this: \*[File](std_io.md#struct-file)) readBytes(buffer: \*char, length: usize) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io.lita:150*

---

<a id="func-writebytes"></a>

### func (this: \*[File](std_io.md#struct-file)) writeBytes(buffer: \*const char, len: usize) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io.lita:172*

---

<a id="func-filelength"></a>

### func FileLength(fileName: \*const char) : i64

*public* | *stdlib/std/io/io.lita:195*

---

<a id="func-readfilefullystr"></a>

### func ReadFileFullyStr(fileName: String, buffer: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io.lita:210*

---

<a id="func-readfilefully"></a>

### func ReadFileFully(fileName: \*const char, buffer: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io.lita:227*

---

<a id="func-readfile"></a>

### func ReadFile(fileName: \*const char, data: \*\*char, length: \*usize, alloc: \*const [Allocator](std_mem.md#struct-allocator)) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io.lita:275*

---

<a id="func-writefile"></a>

### func WriteFile(fileName: \*const char, buffer: \*const char, len: usize) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io.lita:324*

---

## Types

<a id="struct-file"></a>

### struct File

*public* | *stdlib/std/io/io.lita:21*

| Field | Type | Description |
|-------|------|-------------|
| `file` | \*[FILE](std_libc.md#struct-file) |  |
| `_position` | i64 |  |

---

<a id="enum-filestatus"></a>

### enum FileStatus

*public* | *stdlib/std/io/io.lita:29*

| Value | Description |
|-------|-------------|
| `Ok` |  |
| `FileNotFoundError` |  |
| `IOError` |  |
| `OutOfMemory` |  |
| `BufferOverflow` |  |
| `EndOfFile` |  |

---

<a id="enum-fileopenop"></a>

### enum FileOpenOp

*public* | *stdlib/std/io/io.lita:38*

| Value | Description |
|-------|-------------|
| `READ_ONLY` |  |
| `READ_ONLY_BINARY` |  |
| `WRITE` |  |
| `WRITE_BINARY` |  |
| `WRITE_APPEND` |  |
| `WRITE_APPEND_BINARY` |  |

---

