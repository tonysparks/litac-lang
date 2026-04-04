# std::json

## Functions

<a id="func-defaultmakeptrfn"></a>

### func DefaultMakePtrFn(type: typeid, context: \*[JsonContext](std_json.md#struct-jsoncontext), json: \*[JsonNode](std_json.md#struct-jsonnode)) : \*void

*public* | *stdlib/std/json/json.lita:29*

---

<a id="func-defaultmakefn"></a>

### func DefaultMakeFn(type: typeid, context: \*[JsonContext](std_json.md#struct-jsoncontext), json: \*[JsonNode](std_json.md#struct-jsonnode), result: \*void) : void

*public* | *stdlib/std/json/json.lita:33*

---

<a id="func-jsoncontextinit"></a>

### func JsonContextInit(maker: [MakeFn](std_json.md#typedef-makefn), makerPtr: [MakePtrFn](std_json.md#typedef-makeptrfn), allocator: \*const mem::Allocator) : [JsonContext](std_json.md#struct-jsoncontext)

*public* | *stdlib/std/json/json.lita:45*

---

<a id="func-init"></a>

### func (this: \*[JsonContext](std_json.md#struct-jsoncontext)) init(maker: [MakeFn](std_json.md#typedef-makefn), makerPtr: [MakePtrFn](std_json.md#typedef-makeptrfn), allocator: \*const mem::Allocator) : void

*public* | *stdlib/std/json/json.lita:54*

---

<a id="func-isnull"></a>

### func isNull(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:104*

---

<a id="func-isbool"></a>

### func isBool(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:109*

---

<a id="func-istrue"></a>

### func isTrue(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:114*

---

<a id="func-isfalse"></a>

### func isFalse(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:119*

---

<a id="func-isnumber"></a>

### func isNumber(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:124*

---

<a id="func-isstring"></a>

### func isString(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:129*

---

<a id="func-isarray"></a>

### func isArray(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:134*

---

<a id="func-isobject"></a>

### func isObject(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:139*

---

<a id="func-asstring"></a>

### func asString(node: \*[JsonNode](std_json.md#struct-jsonnode)) : \*const char

*public* | *stdlib/std/json/json.lita:144*

---

<a id="func-asbool"></a>

### func asBool(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:149*

---

<a id="func-asnumber"></a>

### func asNumber(node: \*[JsonNode](std_json.md#struct-jsonnode)) : f64

*public* | *stdlib/std/json/json.lita:154*

---

<a id="func-asfloat"></a>

### func asFloat(node: \*[JsonNode](std_json.md#struct-jsonnode)) : f64

*public* | *stdlib/std/json/json.lita:159*

---

<a id="func-asint"></a>

### func asInt(node: \*[JsonNode](std_json.md#struct-jsonnode)) : i32

*public* | *stdlib/std/json/json.lita:164*

---

<a id="func-aslong"></a>

### func asLong(node: \*[JsonNode](std_json.md#struct-jsonnode)) : i64

*public* | *stdlib/std/json/json.lita:169*

---

<a id="func-asarray"></a>

### func asArray(node: \*[JsonNode](std_json.md#struct-jsonnode)) : \*[JsonArray](std_json.md#typedef-jsonarray)

*public* | *stdlib/std/json/json.lita:174*

---

<a id="func-asobject"></a>

### func asObject(node: \*[JsonNode](std_json.md#struct-jsonnode)) : \*[JsonObject](std_json.md#struct-jsonobject)

*public* | *stdlib/std/json/json.lita:179*

---

<a id="func-createjsonnumber"></a>

### func CreateJsonNumber(value: f64, alloc: \*const mem::Allocator) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:183*

---

<a id="func-createjsonintnumber"></a>

### func CreateJsonIntNumber(value: i64, alloc: \*const mem::Allocator) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:195*

---

<a id="func-createjsonfloatnumber"></a>

### func CreateJsonFloatNumber(value: f64, alloc: \*const mem::Allocator) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:207*

---

<a id="func-createjsonstring"></a>

### func CreateJsonString(str: \*const char, len: i32, alloc: \*const mem::Allocator) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:215*

---

<a id="func-jsonescapestring"></a>

### func JsonEscapeString(buf: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), string: \*const char, length: i32) : void

*public* | *stdlib/std/json/json.lita:256*

---

<a id="func-createjsonstringnodup"></a>

### func CreateJsonStringNoDup(str: \*const char, alloc: \*const mem::Allocator) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:295*

---

<a id="func-createjsonarray"></a>

### func CreateJsonArray(alloc: \*const mem::Allocator) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:307*

---

<a id="func-createjsonobject"></a>

### func CreateJsonObject(alloc: \*const mem::Allocator) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:320*

---

<a id="func-put"></a>

### func put(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, n: \*[JsonNode](std_json.md#struct-jsonnode)) : void

*public* | *stdlib/std/json/json.lita:334*

---

<a id="func-putnodup"></a>

### func putNoDup(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, n: \*[JsonNode](std_json.md#struct-jsonnode)) : void

*public* | *stdlib/std/json/json.lita:352*

---

<a id="func-putstr"></a>

### func putStr(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, str: \*const char, len: i32) : void

*public* | *stdlib/std/json/json.lita:369*

---

<a id="func-putnumber"></a>

### func putNumber(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, number: f64) : void

*public* | *stdlib/std/json/json.lita:384*

---

<a id="func-putintnumber"></a>

### func putIntNumber(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, number: i64) : void

*public* | *stdlib/std/json/json.lita:393*

---

<a id="func-putfloatnumber"></a>

### func putFloatNumber(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, number: f64) : void

*public* | *stdlib/std/json/json.lita:402*

---

<a id="func-putbool"></a>

### func putBool(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, b: bool) : void

*public* | *stdlib/std/json/json.lita:411*

---

<a id="func-contains"></a>

### func contains(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char) : bool

*public* | *stdlib/std/json/json.lita:420*

---

<a id="func-get"></a>

### func get(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:428*

---

<a id="func-getbool"></a>

### func getBool(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, defaultValue: bool) : bool

*public* | *stdlib/std/json/json.lita:441*

---

<a id="func-getint"></a>

### func getInt(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, defaultValue: i32) : i32

*public* | *stdlib/std/json/json.lita:450*

---

<a id="func-getlong"></a>

### func getLong(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, defaultValue: i64) : i64

*public* | *stdlib/std/json/json.lita:466*

---

<a id="func-getfloat"></a>

### func getFloat(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, defaultValue: f64) : f64

*public* | *stdlib/std/json/json.lita:482*

---

<a id="func-getstr"></a>

### func getStr(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, defaultValue: \*const char) : \*const char

*public* | *stdlib/std/json/json.lita:498*

---

<a id="func-getstrcopy"></a>

### func getStrCopy(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char, str: \*char, len: i32) : \*char

*public* | *stdlib/std/json/json.lita:507*

---

<a id="func-getarray"></a>

### func getArray(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:519*

---

<a id="func-getobject"></a>

### func getObject(node: \*[JsonNode](std_json.md#struct-jsonnode), key: \*const char) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:528*

---

<a id="func-add"></a>

### func add(node: \*[JsonNode](std_json.md#struct-jsonnode), n: \*[JsonNode](std_json.md#struct-jsonnode)) : void

*public* | *stdlib/std/json/json.lita:537*

---

<a id="func-at"></a>

### func at(node: \*[JsonNode](std_json.md#struct-jsonnode), index: i32) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:543*

---

<a id="func-size"></a>

### func size(node: \*[JsonNode](std_json.md#struct-jsonnode)) : i32

*public* | *stdlib/std/json/json.lita:551*

---

<a id="func-empty"></a>

### func empty(node: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:562*

---

<a id="func-iter"></a>

### func iter(node: \*[JsonNode](std_json.md#struct-jsonnode)) : [JsonIterator](std_json.md#struct-jsoniterator)

*public* | *stdlib/std/json/json.lita:571*

---

<a id="func-hasnext"></a>

### func (this: \*[JsonIterator](std_json.md#struct-jsoniterator)) hasNext() : bool

*public* | *stdlib/std/json/json.lita:577*

---

<a id="func-next"></a>

### func (this: \*[JsonIterator](std_json.md#struct-jsoniterator)) next() : [JsonEntry](std_json.md#struct-jsonentry)

*public* | *stdlib/std/json/json.lita:581*

---

<a id="func-equals"></a>

### func equals(node: \*[JsonNode](std_json.md#struct-jsonnode), other: \*[JsonNode](std_json.md#struct-jsonnode)) : bool

*public* | *stdlib/std/json/json.lita:605*

---

<a id="func-print"></a>

### func print(node: \*[JsonNode](std_json.md#struct-jsonnode), buf: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : \*const char

*public* | *stdlib/std/json/json.lita:687*

---

<a id="func-prettyprint"></a>

### func prettyPrint(node: \*[JsonNode](std_json.md#struct-jsonnode), buf: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), tabSize: i32) : \*const char

*public* | *stdlib/std/json/json.lita:692*

---

<a id="func-free"></a>

### func free(node: \*[JsonNode](std_json.md#struct-jsonnode)) : void

*public* | *stdlib/std/json/json.lita:697*

---

<a id="func-jsonparserinit"></a>

### func JsonParserInit(alloc: \*const mem::Allocator) : [JsonParser](std_json.md#struct-jsonparser)

*public* | *stdlib/std/json/json.lita:878*

---

<a id="func-init"></a>

### func init(p: \*[JsonParser](std_json.md#struct-jsonparser), alloc: \*const mem::Allocator) : void

*public* | *stdlib/std/json/json.lita:884*

---

<a id="func-free"></a>

### func free(p: \*[JsonParser](std_json.md#struct-jsonparser)) : void

*public* | *stdlib/std/json/json.lita:896*

---

<a id="func-parsejson"></a>

### func parseJson(p: \*[JsonParser](std_json.md#struct-jsonparser), buffer: \*const char) : \*[JsonNode](std_json.md#struct-jsonnode)

*public* | *stdlib/std/json/json.lita:902*

---

<a id="func-haserror"></a>

### func hasError(p: \*[JsonParser](std_json.md#struct-jsonparser)) : bool

*public* | *stdlib/std/json/json.lita:921*

---

<a id="func-printjson"></a>

### func PrintJson(node: \*[JsonNode](std_json.md#struct-jsonnode), buf: \*[StringBuilder](std_string_builder.md#struct-stringbuilder)) : void

*public* | *stdlib/std/json/json.lita:925*

---

<a id="func-prettyprintjson"></a>

### func PrettyPrintJson(node: \*[JsonNode](std_json.md#struct-jsonnode), buf: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), offset: i32, tabSize: i32) : void

*public* | *stdlib/std/json/json.lita:983*

---

<a id="func-testparser"></a>

### func testParser() : void

*public* | *stdlib/std/json/json.lita:1558*

---

<a id="func-testprettyprinter"></a>

### func testPrettyPrinter() : void

*public* | *stdlib/std/json/json.lita:1593*

---

## Types

<a id="typedef-makeptrfn"></a>

### typedef MakePtrFn = func(typeid, \*[JsonContext](std_json.md#struct-jsoncontext), \*[JsonNode](std_json.md#struct-jsonnode)) : \*void

*public* | *stdlib/std/json/json.lita:36*

---

<a id="typedef-makefn"></a>

### typedef MakeFn = func(typeid, \*[JsonContext](std_json.md#struct-jsoncontext), \*[JsonNode](std_json.md#struct-jsonnode), \*void) : void

*public* | *stdlib/std/json/json.lita:37*

---

<a id="struct-jsoncontext"></a>

### struct JsonContext

*public* | *stdlib/std/json/json.lita:39*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const mem::Allocator |  |
| `maker` | [MakeFn](std_json.md#typedef-makefn) |  |
| `makerPtr` | [MakePtrFn](std_json.md#typedef-makeptrfn) |  |

---

<a id="enum-jsontype"></a>

### enum JsonType

*public* | *stdlib/std/json/json.lita:65*

| Value | Description |
|-------|-------------|
| `NULL` |  |
| `BOOLEAN` |  |
| `INT_NUMBER` |  |
| `FLOAT_NUMBER` |  |
| `STRING` |  |
| `OBJECT` |  |
| `ARRAY` |  |

---

<a id="typedef-jsonarray"></a>

### typedef JsonArray = [Array](std_array.md#struct-array)\<\*[JsonNode](std_json.md#struct-jsonnode)\>

*public* | *stdlib/std/json/json.lita:75*

---

<a id="struct-jsonentry"></a>

### struct JsonEntry

*public* | *stdlib/std/json/json.lita:77*

| Field | Type | Description |
|-------|------|-------------|
| `key` | \*const char |  |
| `value` | \*[JsonNode](std_json.md#struct-jsonnode) |  |

---

<a id="struct-jsonobject"></a>

### struct JsonObject

*public* | *stdlib/std/json/json.lita:82*

| Field | Type | Description |
|-------|------|-------------|
| `indexes` | [Map](std_map.md#struct-map)\<\*const char, i32\> |  |
| `values` | [Array](std_array.md#struct-array)\<[JsonEntry](std_json.md#struct-jsonentry)\> |  |

---

<a id="union-jsonvalue"></a>

### union JsonValue

*public* | *stdlib/std/json/json.lita:87*

| Field | Type | Description |
|-------|------|-------------|
| `boolValue` | bool |  |
| `doubleValue` | f64 |  |
| `intValue` | i64 |  |
| `strValue` | \*const char |  |
| `objValue` | \*[JsonObject](std_json.md#struct-jsonobject) |  |
| `arrayValue` | \*[JsonArray](std_json.md#typedef-jsonarray) |  |

---

<a id="struct-jsonnode"></a>

### struct JsonNode

*public* | *stdlib/std/json/json.lita:97*

| Field | Type | Description |
|-------|------|-------------|
| `alloc` | \*const mem::Allocator |  |
| `type` | [JsonType](std_json.md#enum-jsontype) |  |
| `value` | [JsonValue](std_json.md#union-jsonvalue) |  |

---

<a id="struct-jsoniterator"></a>

### struct JsonIterator

*public* | *stdlib/std/json/json.lita:566*

| Field | Type | Description |
|-------|------|-------------|
| `index` | i32 |  |
| `json` | \*[JsonNode](std_json.md#struct-jsonnode) |  |

---

<a id="enum-jsonparserstatus"></a>

### enum JsonParserStatus

*public* | *stdlib/std/json/json.lita:859*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `WARNING` |  |
| `ERROR` |  |

---

<a id="struct-jsonparser"></a>

### struct JsonParser

*public* | *stdlib/std/json/json.lita:867*

| Field | Type | Description |
|-------|------|-------------|
| `alloc` | \*const mem::Allocator |  |
| `status` | [JsonParserStatus](std_json.md#enum-jsonparserstatus) |  |
| `errorMsg` | \[\]char |  |
| `token` | Token |  |
| `buffer` | [StringBuilder](std_string_builder.md#struct-stringbuilder) |  |
| `stream` | \*const char |  |
| `lineStart` | \*const char |  |

---

## Variables and Constants

<a id="const-json_null"></a>

### const JSON_NULL

*public* | *stdlib/std/json/json.lita:752*

---

<a id="const-json_true"></a>

### const JSON_TRUE

*public* | *stdlib/std/json/json.lita:758*

---

<a id="const-json_false"></a>

### const JSON_FALSE

*public* | *stdlib/std/json/json.lita:764*

---

