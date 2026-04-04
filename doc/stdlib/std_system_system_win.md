# std::system::system_win

## Functions

<a id="func-_systeminit"></a>

### func _SystemInit() : bool

*public* | *stdlib/std/system/system_win.lita:85*

---

<a id="func-_currentworkingpath"></a>

### func _CurrentWorkingPath() : \*const char

*public* | *stdlib/std/system/system_win.lita:105*

---

<a id="func-_getfullpathname"></a>

### func _GetFullPathName(fileName: \*const char, output: \[\]char) : \*char

*public* | *stdlib/std/system/system_win.lita:117*

---

<a id="func-_setenv"></a>

### func _SetEnv(varName: \*const char, value: \*const char) : void

*public* | *stdlib/std/system/system_win.lita:123*

---

<a id="func-_mkdir"></a>

### func _Mkdir(dir: \*const char) : bool

*public* | *stdlib/std/system/system_win.lita:128*

---

<a id="func-_fileisdir"></a>

### func _FileIsDir(filename: \*const char) : bool

*public* | *stdlib/std/system/system_win.lita:144*

---

<a id="func-_filetruncate"></a>

### func _FileTruncate(filename: \*const char, newLength: usize) : bool

*public* | *stdlib/std/system/system_win.lita:151*

---

<a id="func-_filetruncatefile"></a>

### func _FileTruncateFile(file: \*[FILE](std_libc.md#struct-file), newLength: usize) : bool

*public* | *stdlib/std/system/system_win.lita:157*

---

<a id="func-_filedelete"></a>

### func _FileDelete(filename: \*const char) : bool

*public* | *stdlib/std/system/system_win.lita:167*

---

<a id="func-_systemtimemsec"></a>

### func _SystemTimeMSec() : f64

*public* | *stdlib/std/system/system_win.lita:176*

---

## Variables and Constants

<a id="const-max_path"></a>

### const MAX_PATH: i32

*public* | *stdlib/std/system/system_win.lita:40*

---

