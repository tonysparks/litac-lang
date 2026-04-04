# std::system

## Functions

<a id="func-archasstr"></a>

### func ArchAsStr(type: [Arch](std_system.md#enum-arch)) : \*const char

*public* | *stdlib/std/system/system.lita:182*

---

<a id="func-archfromstr"></a>

### func ArchFromStr(str: \*const char, len: usize) : [Arch](std_system.md#enum-arch)

*public* | *stdlib/std/system/system.lita:194*

---

<a id="func-osasstr"></a>

### func OSAsStr(type: [OS](std_system.md#enum-os)) : \*const char

*public* | *stdlib/std/system/system.lita:259*

---

<a id="func-osfromstr"></a>

### func OSFromStr(str: \*const char, len: usize) : [OS](std_system.md#enum-os)

*public* | *stdlib/std/system/system.lita:272*

---

<a id="func-systeminit"></a>

### func SystemInit() : bool

*public* | *stdlib/std/system/system.lita:357*

---

<a id="func-getos"></a>

### func GetOS() : [OS](std_system.md#enum-os)

*public* | *stdlib/std/system/system.lita:361*

---

<a id="func-getarch"></a>

### func GetArch() : [Arch](std_system.md#enum-arch)

*public* | *stdlib/std/system/system.lita:365*

---

<a id="func-getenv"></a>

### func GetEnv(varName: \*const char) : \*char

*public* | *stdlib/std/system/system.lita:369*

---

<a id="func-setenv"></a>

### func SetEnv(varName: \*const char, value: \*const char) : void

*public* | *stdlib/std/system/system.lita:373*

---

<a id="func-currentworkingpath"></a>

### func CurrentWorkingPath() : \*const char

*public* | *stdlib/std/system/system.lita:379*

---

<a id="func-filetruncate"></a>

### func FileTruncate(filename: \*const char, newLength: usize) : bool

*public* | *stdlib/std/system/system.lita:383*

---

<a id="func-filetruncatefile"></a>

### func FileTruncateFile(file: \*[FILE](std_libc.md#struct-file), newLength: usize) : bool

*public* | *stdlib/std/system/system.lita:387*

---

<a id="func-filedelete"></a>

### func FileDelete(filename: \*const char) : bool

*public* | *stdlib/std/system/system.lita:391*

---

<a id="func-fileexists"></a>

### func FileExists(filename: \*const char) : bool

*public* | *stdlib/std/system/system.lita:395*

---

<a id="func-filemove"></a>

### func FileMove(srcFilename: \*const char, destFilename: \*const char) : bool

*public* | *stdlib/std/system/system.lita:400*

---

<a id="func-fileisdir"></a>

### func FileIsDir(filename: \*const char) : bool

*public* | *stdlib/std/system/system.lita:404*

---

<a id="func-mkdir"></a>

### func Mkdir(dir: \*const char) : bool

*public* | *stdlib/std/system/system.lita:408*

---

<a id="func-mkdirs"></a>

### func Mkdirs(dir: \*const char) : bool

*public* | *stdlib/std/system/system.lita:412*

---

<a id="func-filepath"></a>

### func FilePath(filename: \*const char, out: \[\]char) : \*char

*public* | *stdlib/std/system/system.lita:442*

---

<a id="func-fileparent"></a>

### func FileParent(filename: \*const char, out: \[\]char, length: \*i32) : \*char

*public* | *stdlib/std/system/system.lita:466*

---

<a id="func-pathnormalize"></a>

### func PathNormalize(filename: \*const char, out: \[\]char) : \*char

*public* | *stdlib/std/system/system.lita:497*

---

<a id="func-pathnative"></a>

### func PathNative(filename: \*const char, out: \[\]char) : \*char

*public* | *stdlib/std/system/system.lita:518*

---

<a id="func-getabsolutepath"></a>

### func GetAbsolutePath(pwd: \*const char, path: \*const char, output: \[\]char) : \*char

*public* | *stdlib/std/system/system.lita:572*

---

<a id="func-pathequals"></a>

### func PathEquals(a: \*const char, b: \*const char) : bool

*public* | *stdlib/std/system/system.lita:629*

---

<a id="func-filepathtouri"></a>

### func FilePathToUri(path: \*const char, output: \[\]char) : \*char

*public* | *stdlib/std/system/system.lita:657*

---

<a id="func-uritofilepath"></a>

### func UriToFilePath(uri: \*const char, output: \[\]char) : \*char

*public* | *stdlib/std/system/system.lita:680*

---

<a id="func-systemtimemsec"></a>

### func SystemTimeMSec() : f64

*public* | *stdlib/std/system/system.lita:802*

---

<a id="func-systemexec"></a>

### func SystemExec(command: \*const char) : [Process](std_system.md#struct-process)

*public* | *stdlib/std/system/system.lita:834*

---

<a id="func-readoutput"></a>

### func (this: \*[Process](std_system.md#struct-process)) readOutput(buffer: \*char, length: usize) : i64

*public* | *stdlib/std/system/system.lita:846*

---

<a id="func-writeinput"></a>

### func (this: \*[Process](std_system.md#struct-process)) writeInput(buffer: \*char, length: usize) : i64

*public* | *stdlib/std/system/system.lita:854*

---

<a id="func-close"></a>

### func (this: \*[Process](std_system.md#struct-process)) close() : i32

*public* | *stdlib/std/system/system.lita:862*

---

<a id="func-loadenv"></a>

### func LoadEnv(envFile: \*const char, allocator: \*const [Allocator](std_mem.md#struct-allocator)) : i32

*public* | *stdlib/std/system/system.lita:874*


    returns a negative number if there was an error, otherwise returns the
    number of environment variables loaded ( >= 0 )


---

## Types

<a id="enum-arch"></a>

### enum Arch

*public* | *stdlib/std/system/system.lita:156*

| Value | Description |
|-------|-------------|
| `Lita_ArchType_UNKNOWN` |  |
| `Lita_ArchType_ARM32` |  |
| `Lita_ArchType_ARM64` |  |
| `Lita_ArchType_X86` |  |
| `Lita_ArchType_X86_64` |  |
| `Lita_ArchType_SPARC` |  |

---

<a id="enum-os"></a>

### enum OS

*public* | *stdlib/std/system/system.lita:228*

| Value | Description |
|-------|-------------|
| `Lita_OSType_WINDOWS` |  |
| `Lita_OSType_ANDROID` |  |
| `Lita_OSType_LINUX` |  |
| `Lita_OSType_BSD` |  |
| `Lita_OSType_IOS` |  |
| `Lita_OSType_MAC` |  |
| `Lita_OSType_OTHER` |  |

---

<a id="struct-process"></a>

### struct Process

*public* | *stdlib/std/system/system.lita:842*

| Field | Type | Description |
|-------|------|-------------|
| `pipe` | \*[FILE](std_libc.md#struct-file) |  |

---

## Variables and Constants

<a id="const-path_separator"></a>

### const PATH_SEPARATOR

*public* | *stdlib/std/system/system.lita:348*

---

