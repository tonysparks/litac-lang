# std::fs

## Functions

<a id="func-listfiles"></a>

### func ListFiles(path: String, result: \*[Array](std_array.md#struct-array)\<String\>, flags: i32, allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [FileStatus](std_io.md#enum-filestatus)

*public* | *stdlib/std/fs/fs.lita:21*

---

<a id="func-open"></a>

### func (this: \*[FileHandle](std_fs.md#struct-filehandle)) open(path: String) : bool

*public* | *stdlib/std/fs/fs.lita:72*

---

<a id="func-isfile"></a>

### func (this: \*[FileHandle](std_fs.md#struct-filehandle)) isFile() : bool

*public* | *stdlib/std/fs/fs.lita:89*

---

<a id="func-isdirectory"></a>

### func (this: \*[FileHandle](std_fs.md#struct-filehandle)) isDirectory() : bool

*public* | *stdlib/std/fs/fs.lita:93*

---

<a id="func-name"></a>

### func (this: \*[FileHandle](std_fs.md#struct-filehandle)) name() : \*const char

*public* | *stdlib/std/fs/fs.lita:97*

---

<a id="func-hasnext"></a>

### func (this: \*[FileHandle](std_fs.md#struct-filehandle)) hasNext() : bool

*public* | *stdlib/std/fs/fs.lita:101*

---

<a id="func-next"></a>

### func (this: \*[FileHandle](std_fs.md#struct-filehandle)) next() : bool

*public* | *stdlib/std/fs/fs.lita:105*

---

<a id="func-close"></a>

### func (this: \*[FileHandle](std_fs.md#struct-filehandle)) close() : bool

*public* | *stdlib/std/fs/fs.lita:129*

---

## Types

<a id="enum-listfileflags"></a>

### enum ListFileFlags

*public* | *stdlib/std/fs/fs.lita:16*

| Value | Description |
|-------|-------------|
| `RECURSE_DIRECTORIES` |  |

---

<a id="struct-filehandle"></a>

### struct FileHandle

*public* | *stdlib/std/fs/fs.lita:67*

| Field | Type | Description |
|-------|------|-------------|
| `dir` | [tinydir_dir](std_fs_tinydir.md#struct-tinydir_dir) |  |
| `file` | [tinydir_file](std_fs_tinydir.md#struct-tinydir_file) |  |

---

