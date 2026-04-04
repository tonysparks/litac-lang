# std::string::builder

## Functions

<a id="func-stringbuilderinit"></a>

### func StringBuilderInit(initialSize: i32, alloc: \*const mem::Allocator) : [StringBuilder](std_string_builder.md#struct-stringbuilder)

*public* | *stdlib/std/string/builder.lita:16*

---

<a id="func-init"></a>

### func init(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), initialSize: i32, alloc: \*const mem::Allocator) : void

*public* | *stdlib/std/string/builder.lita:24*

---

<a id="func-free"></a>

### func free(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : void

*public* | *stdlib/std/string/builder.lita:42*

---

<a id="func-appendstring"></a>

### func appendString(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), str: String) : i32

*public* | *stdlib/std/string/builder.lita:51*

---

<a id="func-appendstr"></a>

### func appendStr(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), str: \*const char) : i32

*public* | *stdlib/std/string/builder.lita:55*

---

<a id="func-appendstrn"></a>

### func appendStrn(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), str: \*const char, len: i32) : i32

*public* | *stdlib/std/string/builder.lita:64*

---

<a id="func-appendfloat"></a>

### func appendFloat(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), f: f64) : i32

*public* | *stdlib/std/string/builder.lita:83*

---

<a id="func-appendi32"></a>

### func appendI32(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), i: i32) : i32

*public* | *stdlib/std/string/builder.lita:87*

---

<a id="func-appendi64"></a>

### func appendI64(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), i: i64) : i32

*public* | *stdlib/std/string/builder.lita:91*

---

<a id="func-appendu32"></a>

### func appendU32(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), i: u32) : i32

*public* | *stdlib/std/string/builder.lita:95*

---

<a id="func-appendu64"></a>

### func appendU64(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), i: u64) : i32

*public* | *stdlib/std/string/builder.lita:99*

---

<a id="func-appendchar"></a>

### func appendChar(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), c: char) : i32

*public* | *stdlib/std/string/builder.lita:103*

---

<a id="func-append"></a>

### func append(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), format: \*const char, ...) : i32

*public* | *stdlib/std/string/builder.lita:116*

---

<a id="func-appendargs"></a>

### func appendArgs(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : i32

*public* | *stdlib/std/string/builder.lita:140*

---

<a id="func-format"></a>

### func format(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), format: \*const char, ...) : i32

*public* | *stdlib/std/string/builder.lita:204*

---

<a id="func-delete"></a>

### func delete(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), start: i32, end: i32) : void

*public* | *stdlib/std/string/builder.lita:215*

---

<a id="func-contains"></a>

### func contains(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), str: String) : bool

*public* | *stdlib/std/string/builder.lita:240*

---

<a id="func-indexof"></a>

### func indexOf(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), str: String) : i32

*public* | *stdlib/std/string/builder.lita:244*

---

<a id="func-indexofat"></a>

### func indexOfAt(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), str: String, fromIndex: i32) : i32

*public* | *stdlib/std/string/builder.lita:248*

---

<a id="func-replace"></a>

### func replace(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), start: i32, end: i32, str: String) : i32

*public* | *stdlib/std/string/builder.lita:253*

---

<a id="func-insert"></a>

### func insert(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), index: i32, format: \*const char, ...) : i32

*public* | *stdlib/std/string/builder.lita:258*

---

<a id="func-trim"></a>

### func trim(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : \*[StringBuilder](std_string_builder.md#struct-stringbuilder)

*public* | *stdlib/std/string/builder.lita:303*

---

<a id="func-copyto"></a>

### func copyTo(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), buf: \*char, len: i32, addZero: bool) : i32

*public* | *stdlib/std/string/builder.lita:342*

---

<a id="func-foreach"></a>

### func forEach(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), fn: func(char) : bool) : void

*public* | *stdlib/std/string/builder.lita:347*

---

<a id="func-slice"></a>

### func slice(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : [StringBuilder](std_string_builder.md#struct-stringbuilder)

*public* | *stdlib/std/string/builder.lita:362*


Takes the current StringBuilder length and capacity and creates a
new StringBuffer with length 0.

Use this with caution, as all backing
buffers are shared between this StringBuffer and the sliced StringBuffer


---

<a id="func-remaining"></a>

### func remaining(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : i32

*public* | *stdlib/std/string/builder.lita:370*

---

<a id="func-empty"></a>

### func empty(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : bool

*public* | *stdlib/std/string/builder.lita:375*

---

<a id="func-size"></a>

### func size(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : i32

*public* | *stdlib/std/string/builder.lita:380*

---

<a id="func-clear"></a>

### func clear(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : \*[StringBuilder](std_string_builder.md#struct-stringbuilder)

*public* | *stdlib/std/string/builder.lita:385*

---

<a id="func-cstrconst"></a>

### func cStrConst(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : \*const char

*public* | *stdlib/std/string/builder.lita:390*

---

<a id="func-cstr"></a>

### func cStr(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : \*char

*public* | *stdlib/std/string/builder.lita:394*

---

<a id="func-tobuffer"></a>

### func toBuffer(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : [StringBuffer](std_string_buffer.md#struct-stringbuffer)

*public* | *stdlib/std/string/builder.lita:407*

---

<a id="func-get"></a>

### func get(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), index: i32) : char

*public* | *stdlib/std/string/builder.lita:411*

---

<a id="func-reserve"></a>

### func reserve(b: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), length: i32) : bool

*public* | *stdlib/std/string/builder.lita:419*

---

## Types

<a id="struct-stringbuilder"></a>

### struct StringBuilder

*public* | *stdlib/std/string/builder.lita:11*

| Field | Type | Description |
|-------|------|-------------|
| `asBuffer` | [StringBuffer](std_string_buffer.md#struct-stringbuffer) |  |
| `alloc` | \*const mem::Allocator |  |

---

