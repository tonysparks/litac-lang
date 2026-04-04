# common

## Functions

<a id="func-log"></a>

### func Log(level: [LogLevel](common.md#enum-loglevel), format: \*const char, ...) : void

*public* | *src/common.lita:15*

---

<a id="func-logv"></a>

### func Logv(level: [LogLevel](common.md#enum-loglevel), format: \*const char, args: va_list) : void

*public* | *src/common.lita:22*

---

<a id="func-info"></a>

### func Info(format: \*const char, ...) : void

*public* | *src/common.lita:47*

---

<a id="func-debug"></a>

### func Debug(format: \*const char, ...) : void

*public* | *src/common.lita:54*

---

<a id="func-error"></a>

### func Error(format: \*const char, ...) : void

*public* | *src/common.lita:61*

---

<a id="func-panic"></a>

### func Panic(format: \*const char, ...) : void

*public* | *src/common.lita:68*

---

<a id="func-escapename"></a>

### func EscapeName(name: \*const char, len: i32, sb: \*StringBuilder) : \*char

*public* | *src/common.lita:76*

---

## Types

<a id="enum-loglevel"></a>

### enum LogLevel

*public* | *src/common.lita:5*

| Value | Description |
|-------|-------------|
| `TRACE` |  |
| `INFO` |  |
| `DEBUG` |  |
| `ERROR` |  |
| `FATAL` |  |

---

