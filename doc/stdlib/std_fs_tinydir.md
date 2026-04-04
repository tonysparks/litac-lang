# std::fs::tinydir

## Functions

<a id="func-tinydir_open"></a>

### func tinydir_open(dir: \*[tinydir_dir](std_fs_tinydir.md#struct-tinydir_dir), path: \*const char) : i32

*public* | *stdlib/std/fs/tinydir/tinydir.lita:17*

---

<a id="func-tinydir_readfile"></a>

### func tinydir_readfile(dir: \*[tinydir_dir](std_fs_tinydir.md#struct-tinydir_dir), file: \*[tinydir_file](std_fs_tinydir.md#struct-tinydir_file)) : i32

*public* | *stdlib/std/fs/tinydir/tinydir.lita:20*

---

<a id="func-tinydir_next"></a>

### func tinydir_next(dir: \*[tinydir_dir](std_fs_tinydir.md#struct-tinydir_dir)) : i32

*public* | *stdlib/std/fs/tinydir/tinydir.lita:23*

---

<a id="func-tinydir_close"></a>

### func tinydir_close(dir: \*[tinydir_dir](std_fs_tinydir.md#struct-tinydir_dir)) : i32

*public* | *stdlib/std/fs/tinydir/tinydir.lita:26*

---

## Types

<a id="struct-tinydir_dir"></a>

### struct tinydir_dir

*public* | *stdlib/std/fs/tinydir/tinydir.lita:4*

| Field | Type | Description |
|-------|------|-------------|
| `has_next` | bool |  |
| `path` | \*const char |  |

---

<a id="struct-tinydir_file"></a>

### struct tinydir_file

*public* | *stdlib/std/fs/tinydir/tinydir.lita:10*

| Field | Type | Description |
|-------|------|-------------|
| `is_dir` | bool |  |
| `is_reg` | bool |  |
| `name` | \*const char |  |

---

