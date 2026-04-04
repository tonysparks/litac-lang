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

<a id="func-equalsignorecase"></a>

### func equalsIgnoreCase(b: String, str: String) : bool

*public* | *stdlib/std/string/string.lita:114*

---

<a id="func-contains"></a>

### func contains(b: String, str: String) : bool

*public* | *stdlib/std/string/string.lita:139*

---

<a id="func-endindexof"></a>

### func endIndexOf(b: String, str: String) : i32

*public* | *stdlib/std/string/string.lita:143*

---

<a id="func-endindexofat"></a>

### func endIndexOfAt(b: String, str: String, fromIndex: i32) : i32

*public* | *stdlib/std/string/string.lita:147*

---

<a id="func-indexof"></a>

### func indexOf(b: String, str: String) : i32

*public* | *stdlib/std/string/string.lita:153*

---

<a id="func-indexofat"></a>

### func indexOfAt(b: String, str: String, fromIndex: i32) : i32

*public* | *stdlib/std/string/string.lita:157*

---

<a id="func-lastindexofat"></a>

### func lastIndexOfAt(b: String, str: String, fromIndex: i32) : i32

*public* | *stdlib/std/string/string.lita:201*

---

<a id="func-hasnext"></a>

### func (this: \*[SplitIter](std_string.md#struct-splititer)) hasNext() : bool

*public* | *stdlib/std/string/string.lita:262*

---

<a id="func-next"></a>

### func (this: \*[SplitIter](std_string.md#struct-splititer)) next() : String

*public* | *stdlib/std/string/string.lita:267*

---

<a id="func-remaining"></a>

### func (this: \*[SplitIter](std_string.md#struct-splititer)) remaining() : String

*public* | *stdlib/std/string/string.lita:276*

---

<a id="func-split"></a>

### func (this: String) split(str: String) : [SplitIter](std_string.md#struct-splititer)

*public* | *stdlib/std/string/string.lita:288*

---

<a id="func-lefttrim"></a>

### func (this: String) leftTrim() : String

*public* | *stdlib/std/string/string.lita:297*

---

<a id="func-righttrim"></a>

### func (this: String) rightTrim() : String

*public* | *stdlib/std/string/string.lita:309*

---

<a id="func-trim"></a>

### func (this: String) trim() : String

*public* | *stdlib/std/string/string.lita:321*

---

<a id="func-copyto"></a>

### func copyTo(b: String, buf: \*char, len: i32, addZero: bool) : i32

*public* | *stdlib/std/string/string.lita:326*

---

<a id="func-copy"></a>

### func copy(s: String, allocator: \*const mem::Allocator) : String

*public* | *stdlib/std/string/string.lita:343*

---

<a id="func-foreach"></a>

### func forEach(b: String, fn: func(char) : bool) : void

*public* | *stdlib/std/string/string.lita:362*

---

<a id="func-empty"></a>

### func empty(b: String) : bool

*public* | *stdlib/std/string/string.lita:370*

---

<a id="func-size"></a>

### func size(b: String) : i32

*public* | *stdlib/std/string/string.lita:374*

---

<a id="func-get"></a>

### func get(b: String, index: i32) : char

*public* | *stdlib/std/string/string.lita:378*

---

<a id="func-tocstr"></a>

### func toCStr(b: String, allocator: \*const mem::Allocator) : \*char

*public* | *stdlib/std/string/string.lita:386*

---

<a id="func-stringclone"></a>

### func StringClone(original: \*const char, len: i32, allocator: \*const mem::Allocator) : \*char

*public* | *stdlib/std/string/string.lita:391*

---

<a id="func-stringcopy"></a>

### func StringCopy(src: \*const char, dest: \*char, size: usize) : \*char

*public* | *stdlib/std/string/string.lita:411*

---

<a id="func-stringhashlen"></a>

### func StringHashLen(str: \*const char, size: usize) : u32

*public* | *stdlib/std/string/string.lita:426*

---

<a id="func-stringhash"></a>

### func StringHash(str: \*const char) : u32

*public* | *stdlib/std/string/string.lita:438*

---

<a id="func-stringequallen"></a>

### func StringEqualLen(a: \*const char, b: \*const char, size: usize) : bool

*public* | *stdlib/std/string/string.lita:448*

---

<a id="func-stringequal"></a>

### func StringEqual(a: \*const char, b: \*const char) : bool

*public* | *stdlib/std/string/string.lita:455*

---

<a id="func-hash"></a>

### func hash(str: \*const char) : u32

*public* | *stdlib/std/string/string.lita:462*

---

<a id="func-equals"></a>

### func equals(str: \*const char, other: \*const char) : bool

*public* | *stdlib/std/string/string.lita:466*

---

<a id="func-equalsstring"></a>

### func equalsString(str: \*const char, other: String) : bool

*public* | *stdlib/std/string/string.lita:473*

---

<a id="func-length"></a>

### func length(str: \*const char) : i32

*public* | *stdlib/std/string/string.lita:477*

---

<a id="func-empty"></a>

### func empty(str: \*const char) : bool

*public* | *stdlib/std/string/string.lita:482*

---

<a id="func-tostring"></a>

### func toString(str: \*const char) : String

*public* | *stdlib/std/string/string.lita:486*

---

## Types

<a id="struct-splititer"></a>

### struct SplitIter

*public* | *stdlib/std/string/string.lita:254*

| Field | Type | Description |
|-------|------|-------------|
| `str` | String |  |
| `split` | String |  |
| `lastIndex` | i32 |  |
| `currentIndex` | i32 |  |

---

