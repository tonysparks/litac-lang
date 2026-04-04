# std::string

## Functions

<a id="func-stringinit"></a>

### func StringInit(buffer: \*const char, length: i32) : String

*public* | *stdlib/std/string/string.lita:12*

---

<a id="func-hash"></a>

### func hash(b: String) : u32

*public* | *stdlib/std/string/string.lita:26*

---

<a id="func-substring"></a>

### func substring(b: String, start: i32, end: i32) : String

*public* | *stdlib/std/string/string.lita:34*

---

<a id="func-substringof"></a>

### func substringOf(b: String, str: String) : String

*public* | *stdlib/std/string/string.lita:50*

---

<a id="func-substringofafter"></a>

### func substringOfAfter(b: String, str: String) : String

*public* | *stdlib/std/string/string.lita:59*

---

<a id="func-startswith"></a>

### func startsWith(b: String, prefix: String, fromIndex: i32) : bool

*public* | *stdlib/std/string/string.lita:68*

---

<a id="func-endswith"></a>

### func endsWith(b: String, suffix: String) : bool

*public* | *stdlib/std/string/string.lita:93*

---

<a id="func-equalsstring"></a>

### func equalsString(b: String, str: \*const char, len: i32) : bool

*public* | *stdlib/std/string/string.lita:97*

---

<a id="func-equals"></a>

### func equals(b: String, other: String) : bool

*public* | *stdlib/std/string/string.lita:110*

---

<a id="func-compare"></a>

### func compare(b: String, other: String) : i32

*public* | *stdlib/std/string/string.lita:114*

---

<a id="func-equalsignorecase"></a>

### func equalsIgnoreCase(b: String, str: String) : bool

*public* | *stdlib/std/string/string.lita:121*

---

<a id="func-contains"></a>

### func contains(b: String, str: String) : bool

*public* | *stdlib/std/string/string.lita:146*

---

<a id="func-endindexof"></a>

### func endIndexOf(b: String, str: String) : i32

*public* | *stdlib/std/string/string.lita:150*

---

<a id="func-endindexofat"></a>

### func endIndexOfAt(b: String, str: String, fromIndex: i32) : i32

*public* | *stdlib/std/string/string.lita:154*

---

<a id="func-indexof"></a>

### func indexOf(b: String, str: String) : i32

*public* | *stdlib/std/string/string.lita:160*

---

<a id="func-indexofat"></a>

### func indexOfAt(b: String, str: String, fromIndex: i32) : i32

*public* | *stdlib/std/string/string.lita:164*

---

<a id="func-lastindexofat"></a>

### func lastIndexOfAt(b: String, str: String, fromIndex: i32) : i32

*public* | *stdlib/std/string/string.lita:208*

---

<a id="func-hasnext"></a>

### func (this: \*[SplitIter](std_string.md#struct-splititer)) hasNext() : bool

*public* | *stdlib/std/string/string.lita:269*

---

<a id="func-next"></a>

### func (this: \*[SplitIter](std_string.md#struct-splititer)) next() : String

*public* | *stdlib/std/string/string.lita:274*

---

<a id="func-remaining"></a>

### func (this: \*[SplitIter](std_string.md#struct-splititer)) remaining() : String

*public* | *stdlib/std/string/string.lita:283*

---

<a id="func-split"></a>

### func (this: String) split(str: String) : [SplitIter](std_string.md#struct-splititer)

*public* | *stdlib/std/string/string.lita:295*

---

<a id="func-lefttrim"></a>

### func (this: String) leftTrim() : String

*public* | *stdlib/std/string/string.lita:304*

---

<a id="func-righttrim"></a>

### func (this: String) rightTrim() : String

*public* | *stdlib/std/string/string.lita:316*

---

<a id="func-trim"></a>

### func (this: String) trim() : String

*public* | *stdlib/std/string/string.lita:328*

---

<a id="func-copyto"></a>

### func copyTo(b: String, buf: \*char, len: i32, addZero: bool) : i32

*public* | *stdlib/std/string/string.lita:333*

---

<a id="func-copy"></a>

### func copy(s: String, allocator: \*const mem::Allocator) : String

*public* | *stdlib/std/string/string.lita:350*

---

<a id="func-foreach"></a>

### func forEach(b: String, fn: func(char) : bool) : void

*public* | *stdlib/std/string/string.lita:369*

---

<a id="func-empty"></a>

### func empty(b: String) : bool

*public* | *stdlib/std/string/string.lita:377*

---

<a id="func-size"></a>

### func size(b: String) : i32

*public* | *stdlib/std/string/string.lita:381*

---

<a id="func-get"></a>

### func get(b: String, index: i32) : char

*public* | *stdlib/std/string/string.lita:385*

---

<a id="func-tocstr"></a>

### func toCStr(b: String, allocator: \*const mem::Allocator) : \*char

*public* | *stdlib/std/string/string.lita:393*

---

<a id="func-stringclone"></a>

### func StringClone(original: \*const char, len: i32, allocator: \*const mem::Allocator) : \*char

*public* | *stdlib/std/string/string.lita:398*

---

<a id="func-stringcopy"></a>

### func StringCopy(src: \*const char, dest: \*char, size: usize) : \*char

*public* | *stdlib/std/string/string.lita:418*

---

<a id="func-stringhashlen"></a>

### func StringHashLen(str: \*const char, size: usize) : u32

*public* | *stdlib/std/string/string.lita:433*

---

<a id="func-stringhash"></a>

### func StringHash(str: \*const char) : u32

*public* | *stdlib/std/string/string.lita:445*

---

<a id="func-stringequallen"></a>

### func StringEqualLen(a: \*const char, b: \*const char, size: usize) : bool

*public* | *stdlib/std/string/string.lita:455*

---

<a id="func-stringequal"></a>

### func StringEqual(a: \*const char, b: \*const char) : bool

*public* | *stdlib/std/string/string.lita:462*

---

<a id="func-hash"></a>

### func hash(str: \*const char) : u32

*public* | *stdlib/std/string/string.lita:469*

---

<a id="func-equals"></a>

### func equals(str: \*const char, other: \*const char) : bool

*public* | *stdlib/std/string/string.lita:473*

---

<a id="func-equalsstring"></a>

### func equalsString(str: \*const char, other: String) : bool

*public* | *stdlib/std/string/string.lita:480*

---

<a id="func-length"></a>

### func length(str: \*const char) : i32

*public* | *stdlib/std/string/string.lita:484*

---

<a id="func-empty"></a>

### func empty(str: \*const char) : bool

*public* | *stdlib/std/string/string.lita:489*

---

<a id="func-tostring"></a>

### func toString(str: \*const char) : String

*public* | *stdlib/std/string/string.lita:493*

---

## Types

<a id="struct-splititer"></a>

### struct SplitIter

*public* | *stdlib/std/string/string.lita:261*

| Field | Type | Description |
|-------|------|-------------|
| `str` | String |  |
| `split` | String |  |
| `lastIndex` | i32 |  |
| `currentIndex` | i32 |  |

---

