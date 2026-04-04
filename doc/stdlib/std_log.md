# std::log

## Functions

<a id="func-loginit"></a>

### func LogInit(outputFileName: \*const char, level: [LogLevel](std_log.md#enum-loglevel)) : void

*public* | *stdlib/std/log.lita:26*

---

<a id="func-log"></a>

### func Log(level: [LogLevel](std_log.md#enum-loglevel), format: \*const char, ...) : void

*public* | *stdlib/std/log.lita:41*

---

<a id="func-logv"></a>

### func Logv(level: [LogLevel](std_log.md#enum-loglevel), format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : void

*public* | *stdlib/std/log.lita:48*

---

<a id="func-info"></a>

### func Info(format: \*const char, ...) : void

*public* | *stdlib/std/log.lita:69*

---

<a id="func-debug"></a>

### func Debug(format: \*const char, ...) : void

*public* | *stdlib/std/log.lita:76*

---

<a id="func-warn"></a>

### func Warn(format: \*const char, ...) : void

*public* | *stdlib/std/log.lita:83*

---

<a id="func-error"></a>

### func Error(format: \*const char, ...) : void

*public* | *stdlib/std/log.lita:90*

---

<a id="func-panic"></a>

### func Panic(format: \*const char, ...) : void

*public* | *stdlib/std/log.lita:97*

---

## Types

<a id="enum-loglevel"></a>

### enum LogLevel

*public* | *stdlib/std/log.lita:8*

| Value | Description |
|-------|-------------|
| `TRACE` |  |
| `DEBUG` |  |
| `INFO` |  |
| `WARN` |  |
| `ERROR` |  |
| `FATAL` |  |

---

