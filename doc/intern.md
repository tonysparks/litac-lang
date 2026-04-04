# intern

## Functions

<a id="func-internmap"></a>

### func InternMap\<V\>(emptyValue: V, initialSize: i32, allocator: \*const Allocator) : Map\<[InternedString](intern.md#union-internedstring), V\>

*public* | *src/intern.lita:90*

---

<a id="func-init"></a>

### func (this: \*[Strings](intern.md#struct-strings)) init(allocator: \*const Allocator) : void

*public* | *src/intern.lita:110*

---

<a id="func-free"></a>

### func (this: \*[Strings](intern.md#struct-strings)) free() : void

*public* | *src/intern.lita:183*

---

<a id="func-internstring"></a>

### func (this: \*[Strings](intern.md#struct-strings)) internString(string: \*String) : [InternedString](intern.md#union-internedstring)

*public* | *src/intern.lita:196*

---

<a id="func-intern"></a>

### func (this: \*[Strings](intern.md#struct-strings)) intern(string: \*const char, length: i32) : [InternedString](intern.md#union-internedstring)

*public* | *src/intern.lita:204*


    The supplied `string` must be long-lived, as in for the duration of the lifetime of this
    `Strings`.  If you can't garauntee to the lifetime of the supplied `string`, use `Strings#internCopy`


---

<a id="func-interncopy"></a>

### func (this: \*[Strings](intern.md#struct-strings)) internCopy(string: \*const char, length: i32) : [InternedString](intern.md#union-internedstring)

*public* | *src/intern.lita:225*


    If this `string` has not been interned yet, a copy of the `string` is stored as the interned string.


---

<a id="func-put"></a>

### func (this: \*[Strings](intern.md#struct-strings)) put(key: String, value: [InternedString](intern.md#union-internedstring)) : void

*public* | *src/intern.lita:247*

---

<a id="func-size"></a>

### func (this: \*[Strings](intern.md#struct-strings)) size() : i32

*public* | *src/intern.lita:275*

---

<a id="func-equalsstr"></a>

### func (this: \*[InternedString](intern.md#union-internedstring)) equalsStr(other: \*const char) : bool

*public* | *src/intern.lita:327*

---

<a id="func-equals"></a>

### func (this: \*[InternedString](intern.md#union-internedstring)) equals(other: \*[InternedString](intern.md#union-internedstring)) : bool

*public* | *src/intern.lita:336*

---

<a id="func-hash"></a>

### func (this: \*[InternedString](intern.md#union-internedstring)) hash() : u32

*public* | *src/intern.lita:340*

---

<a id="func-empty"></a>

### func (this: \*[InternedString](intern.md#union-internedstring)) empty() : bool

*public* | *src/intern.lita:347*

---

<a id="func-asstring"></a>

### func (this: \*[InternedString](intern.md#union-internedstring)) asString() : String

*public* | *src/intern.lita:351*

---

## Types

<a id="union-internedstring"></a>

### union InternedString

*public* | *src/intern.lita:14*

| Field | Type | Description |
|-------|------|-------------|
| `view` | String |  |

---

<a id="struct-strings"></a>

### struct Strings

*public* | *src/intern.lita:101*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `length` | i32 |  |
| `capacity` | i32 |  |
| `keys` | \*String |  |
| `values` | \*[InternedString](intern.md#union-internedstring) |  |

---

## Variables and Constants

<a id="const-empty_str"></a>

### const EMPTY_STR

*public* | *src/intern.lita:26*

---

<a id="const-void"></a>

### const VOID

*public* | *src/intern.lita:30*

---

<a id="const-null"></a>

### const NULL

*public* | *src/intern.lita:31*

---

<a id="const-bool"></a>

### const BOOL

*public* | *src/intern.lita:32*

---

<a id="const-char"></a>

### const CHAR

*public* | *src/intern.lita:33*

---

<a id="const-i8"></a>

### const I8

*public* | *src/intern.lita:34*

---

<a id="const-u8"></a>

### const U8

*public* | *src/intern.lita:35*

---

<a id="const-i16"></a>

### const I16

*public* | *src/intern.lita:36*

---

<a id="const-u16"></a>

### const U16

*public* | *src/intern.lita:37*

---

<a id="const-i32"></a>

### const I32

*public* | *src/intern.lita:38*

---

<a id="const-u32"></a>

### const U32

*public* | *src/intern.lita:39*

---

<a id="const-i64"></a>

### const I64

*public* | *src/intern.lita:40*

---

<a id="const-u64"></a>

### const U64

*public* | *src/intern.lita:41*

---

<a id="const-f32"></a>

### const F32

*public* | *src/intern.lita:42*

---

<a id="const-f64"></a>

### const F64

*public* | *src/intern.lita:43*

---

<a id="const-usize"></a>

### const USIZE

*public* | *src/intern.lita:44*

---

<a id="const-const"></a>

### const CONST

*public* | *src/intern.lita:45*

---

<a id="const-string"></a>

### const STRING

*public* | *src/intern.lita:46*

---

<a id="const-generic_param"></a>

### const GENERIC_PARAM

*public* | *src/intern.lita:47*

---

<a id="const-poison"></a>

### const POISON

*public* | *src/intern.lita:48*

---

<a id="const-builtin"></a>

### const BUILTIN

*public* | *src/intern.lita:49*

---

<a id="const-main"></a>

### const MAIN

*public* | *src/intern.lita:50*

---

<a id="const-num_of_type_infos"></a>

### const NUM_OF_TYPE_INFOS

*public* | *src/intern.lita:51*

---

<a id="const-type_infos"></a>

### const TYPE_INFOS

*public* | *src/intern.lita:52*

---

<a id="const-profile_tag"></a>

### const PROFILE_TAG

*public* | *src/intern.lita:53*

---

<a id="const-profile_entries"></a>

### const PROFILE_ENTRIES

*public* | *src/intern.lita:54*

---

<a id="const-if"></a>

### const IF

*public* | *src/intern.lita:56*

---

<a id="const-static_if"></a>

### const STATIC_IF

*public* | *src/intern.lita:57*

---

<a id="const-else"></a>

### const ELSE

*public* | *src/intern.lita:58*

---

<a id="const-elseif"></a>

### const ELSEIF

*public* | *src/intern.lita:59*

---

<a id="const-precheck"></a>

### const PRECHECK

*public* | *src/intern.lita:60*

---

<a id="const-postcheck"></a>

### const POSTCHECK

*public* | *src/intern.lita:61*

---

<a id="const-postparse"></a>

### const POSTPARSE

*public* | *src/intern.lita:62*

---

<a id="const-end"></a>

### const END

*public* | *src/intern.lita:63*

---

<a id="const-else_error"></a>

### const ELSE_ERROR

*public* | *src/intern.lita:64*

---

<a id="const-include"></a>

### const INCLUDE

*public* | *src/intern.lita:67*

---

<a id="const-raw"></a>

### const RAW

*public* | *src/intern.lita:68*

---

<a id="const-inline"></a>

### const INLINE

*public* | *src/intern.lita:69*

---

<a id="const-noinline"></a>

### const NOINLINE

*public* | *src/intern.lita:70*

---

<a id="const-static"></a>

### const STATIC

*public* | *src/intern.lita:71*

---

<a id="const-atomic"></a>

### const ATOMIC

*public* | *src/intern.lita:72*

---

<a id="const-register"></a>

### const REGISTER

*public* | *src/intern.lita:73*

---

<a id="const-threadlocal"></a>

### const THREADLOCAL

*public* | *src/intern.lita:74*

---

<a id="const-export"></a>

### const EXPORT

*public* | *src/intern.lita:75*

---

<a id="const-packed"></a>

### const PACKED

*public* | *src/intern.lita:76*

---

<a id="const-cc"></a>

### const CC

*public* | *src/intern.lita:77*

---

<a id="const-cfile"></a>

### const CFILE

*public* | *src/intern.lita:78*

---

<a id="const-cinclude"></a>

### const CINCLUDE

*public* | *src/intern.lita:79*

---

<a id="const-foreign"></a>

### const FOREIGN

*public* | *src/intern.lita:80*

---

<a id="const-alias"></a>

### const ALIAS

*public* | *src/intern.lita:81*

---

<a id="const-asstr"></a>

### const ASSTR

*public* | *src/intern.lita:82*

---

<a id="const-tostr"></a>

### const TOSTR

*public* | *src/intern.lita:83*

---

<a id="const-compiler_option"></a>

### const COMPILER_OPTION

*public* | *src/intern.lita:84*

---

<a id="const-string_type"></a>

### const STRING_TYPE

*public* | *src/intern.lita:87*

---

<a id="const-any_type"></a>

### const ANY_TYPE

*public* | *src/intern.lita:88*

---

