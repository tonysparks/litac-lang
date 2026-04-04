# std::system::system_posix

## Functions

<a id="func-_systeminit"></a>

### func _SystemInit() : bool

*public* | *stdlib/std/system/system_posix.lita:48*

---

<a id="func-_currentworkingpath"></a>

### func _CurrentWorkingPath() : \*const char

*public* | *stdlib/std/system/system_posix.lita:56*

---

<a id="func-_mkdir"></a>

### func _Mkdir(dir: \*const char) : bool

*public* | *stdlib/std/system/system_posix.lita:84*

---

<a id="func-_fileisdir"></a>

### func _FileIsDir(filename: \*const char) : bool

*public* | *stdlib/std/system/system_posix.lita:102*

---

<a id="func-_filetruncate"></a>

### func _FileTruncate(filename: \*const char, newLength: usize) : bool

*public* | *stdlib/std/system/system_posix.lita:111*

---

<a id="func-_filetruncatefile"></a>

### func _FileTruncateFile(file: \*[FILE](std_libc.md#struct-file), newLength: usize) : bool

*public* | *stdlib/std/system/system_posix.lita:117*

---

<a id="func-_filedelete"></a>

### func _FileDelete(filename: \*const char) : bool

*public* | *stdlib/std/system/system_posix.lita:127*

---

<a id="func-_systemtimemsec"></a>

### func _SystemTimeMSec() : f64

*public* | *stdlib/std/system/system_posix.lita:147*

---

<a id="func-_setenv"></a>

### func _SetEnv(varName: \*const char, value: \*const char) : void

*public* | *stdlib/std/system/system_posix.lita:156*

---

## Variables and Constants

<a id="const-max_path"></a>

### const MAX_PATH: i32

*public* | *stdlib/std/system/system_posix.lita:36*

---

