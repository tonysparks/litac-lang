# std::io::io_win

## Functions

<a id="func-winreadfile"></a>

### func WinReadFile(fileName: \*const char, data: \*\*char, length: \*usize, allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io_win.lita:97*

---

<a id="func-winwritefile"></a>

### func WinWriteFile(fileName: \*const char, buffer: \*const char, len: usize) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io_win.lita:146*

---

<a id="func-winwritebytes"></a>

### func WinWriteBytes(file: \*[File](std_io.md#struct-file), buffer: \*const char, len: usize) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io_win.lita:184*

---

<a id="func-winfilelength"></a>

### func WinFileLength(file: \*[File](std_io.md#struct-file)) : i64

*public* | *stdlib/std/io/io_win.lita:198*

---

<a id="func-winfileopen"></a>

### func WinFileOpen(file: \*[File](std_io.md#struct-file), filename: \*const char, op: [FileOpenOp](std_io.md#enum-fileopenop)) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/io/io_win.lita:208*

---

<a id="func-winfileclose"></a>

### func WinFileClose(file: \*[File](std_io.md#struct-file)) : void

*public* | *stdlib/std/io/io_win.lita:252*

---

## Types

<a id="typedef-handle"></a>

### typedef HANDLE = \*void

*public* | *stdlib/std/io/io_win.lita:44*

---

