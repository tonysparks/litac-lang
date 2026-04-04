# std::string::buffer

## Functions

<a id="func-cstring"></a>

### func CString(str: \*char, len: i32) : [StringBuffer](std_string_buffer.md#struct-stringbuffer)

*public* | *stdlib/std/string/buffer.lita:13*

---

<a id="func-stringbufferinit"></a>

### func StringBufferInit(str: \*char, capacity: i32, len: i32) : [StringBuffer](std_string_buffer.md#struct-stringbuffer)

*public* | *stdlib/std/string/buffer.lita:33*

---

<a id="func-hash"></a>

### func hash(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : u32

*public* | *stdlib/std/string/buffer.lita:58*

---

<a id="func-equals"></a>

### func equals(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), other: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : bool

*public* | *stdlib/std/string/buffer.lita:62*

---

<a id="func-format"></a>

### func format(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), format: \*const char, ...) : i32

*public* | *stdlib/std/string/buffer.lita:73*

---

<a id="func-formatv"></a>

### func formatv(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : i32

*public* | *stdlib/std/string/buffer.lita:91*

---

<a id="func-append"></a>

### func append(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), format: \*const char, ...) : i32

*public* | *stdlib/std/string/buffer.lita:104*

---

<a id="func-appendv"></a>

### func appendv(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : i32

*public* | *stdlib/std/string/buffer.lita:125*

---

<a id="func-appendstr"></a>

### func appendStr(b: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), str: \*const char) : void

*public* | *stdlib/std/string/buffer.lita:142*

---

<a id="func-appendstrn"></a>

### func appendStrn(b: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), str: \*const char, len: i32) : void

*public* | *stdlib/std/string/buffer.lita:151*

---

<a id="func-setstrn"></a>

### func setStrn(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), str: \*const char, len: i32) : void

*public* | *stdlib/std/string/buffer.lita:167*

---

<a id="func-appendchar"></a>

### func appendChar(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer), c: char) : void

*public* | *stdlib/std/string/buffer.lita:182*

---

<a id="func-substring"></a>

### func substring(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer), start: i32, end: i32) : String

*public* | *stdlib/std/string/buffer.lita:191*

---

<a id="func-memset"></a>

### func memset(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer), value: i32) : void

*public* | *stdlib/std/string/buffer.lita:209*

---

<a id="func-tolower"></a>

### func toLower(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : void

*public* | *stdlib/std/string/buffer.lita:216*

---

<a id="func-toupper"></a>

### func toUpper(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : void

*public* | *stdlib/std/string/buffer.lita:222*

---

<a id="func-copy"></a>

### func copy(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer), allocator: \*const mem::Allocator) : [StringBuffer](std_string_buffer.md#struct-stringbuffer)

*public* | *stdlib/std/string/buffer.lita:228*

---

<a id="func-adjust"></a>

### func adjust(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : void

*public* | *stdlib/std/string/buffer.lita:249*

---

<a id="func-clear"></a>

### func clear(s: \*[StringBuffer](std_string_buffer.md#struct-stringbuffer)) : void

*public* | *stdlib/std/string/buffer.lita:253*

---

<a id="func-empty"></a>

### func empty(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : bool

*public* | *stdlib/std/string/buffer.lita:258*

---

<a id="func-size"></a>

### func size(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : i32

*public* | *stdlib/std/string/buffer.lita:262*

---

<a id="func-remaining"></a>

### func remaining(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : i32

*public* | *stdlib/std/string/buffer.lita:266*

---

<a id="func-cstr"></a>

### func cStr(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : \*char

*public* | *stdlib/std/string/buffer.lita:270*

---

<a id="func-cstrconst"></a>

### func cStrConst(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : \*const char

*public* | *stdlib/std/string/buffer.lita:277*

---

<a id="func-slice"></a>

### func slice(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : [StringBuffer](std_string_buffer.md#struct-stringbuffer)

*public* | *stdlib/std/string/buffer.lita:284*

---

<a id="func-tostring"></a>

### func toString(s: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : String

*public* | *stdlib/std/string/buffer.lita:297*

---

## Types

<a id="struct-stringbuffer"></a>

### struct StringBuffer

*public* | *stdlib/std/string/buffer.lita:7*

| Field | Type | Description |
|-------|------|-------------|
| `buffer` | \*char |  |
| `length` | i32 |  |
| `capacity` | i32 |  |

---

