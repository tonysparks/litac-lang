# std::type

## Functions

<a id="func-gettypename"></a>

### func GetTypeName\<T\>() : \*const char

*public* | *stdlib/std/type.lita:62*

---

<a id="func-gettypeinfo"></a>

### func getTypeInfo(id: typeid) : \*[TypeInfo](std_type.md#struct-typeinfo)

*public* | *stdlib/std/type.lita:137*

---

<a id="func-getfieldvalue"></a>

### func getFieldValue(agg: any, fieldName: \*const char) : any

*public* | *stdlib/std/type.lita:145*

---

## Types

<a id="enum-typekind"></a>

### enum TypeKind

*public* | *stdlib/std/type.lita:14*

| Value | Description |
|-------|-------------|
| `BOOL` |  |
| `CHAR` |  |
| `I8` |  |
| `U8` |  |
| `I16` |  |
| `U16` |  |
| `I32` |  |
| `U32` |  |
| `I64` |  |
| `U64` |  |
| `F32` |  |
| `F64` |  |
| `USIZE` |  |
| `NULL` |  |
| `VOID` |  |
| `STR` |  |
| `ARRAY` |  |
| `PTR` |  |
| `FUNC_PTR` |  |
| `STRUCT` |  |
| `UNION` |  |
| `TRAIT` |  |
| `ENUM` |  |
| `FUNC` |  |
| `CONST` |  |
| `GENERIC_PARAM` |  |
| `POISON` |  |
| `MAX_TYPE_KIND` |  |

---

<a id="enum-fieldinfokind"></a>

### enum FieldInfoKind

*public* | *stdlib/std/type.lita:45*

| Value | Description |
|-------|-------------|
| `VAR_FIELD` |  |
| `TRAIT_FIELD` |  |
| `ENUM_FIELD` |  |
| `STRUCT_FIELD` |  |
| `UNION_FIELD` |  |

---

<a id="enum-modifiers"></a>

### enum Modifiers

*public* | *stdlib/std/type.lita:66*

| Value | Description |
|-------|-------------|
| `None` |  |
| `Using` |  |

---

<a id="struct-genericinfo"></a>

### struct GenericInfo

*public* | *stdlib/std/type.lita:71*

| Field | Type | Description |
|-------|------|-------------|
| `args` | \*\*const char |  |
| `numOfArgs` | i32 |  |

---

<a id="struct-paraminfo"></a>

### struct ParamInfo

*public* | *stdlib/std/type.lita:76*

| Field | Type | Description |
|-------|------|-------------|
| `genInfo` | [GenericInfo](std_type.md#struct-genericinfo) |  |
| `name` | \*const char |  |
| `type` | typeid |  |
| `modifiers` | [Modifiers](std_type.md#enum-modifiers) |  |

---

<a id="struct-fieldinfo"></a>

### struct FieldInfo

*public* | *stdlib/std/type.lita:83*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [FieldInfoKind](std_type.md#enum-fieldinfokind) |  |
| `name` | \*const char |  |
| `type` | typeid |  |
| `modifiers` | [Modifiers](std_type.md#enum-modifiers) |  |
| `offset` | usize |  |

---

<a id="struct-enumfieldinfo"></a>

### struct EnumFieldInfo

*public* | *stdlib/std/type.lita:91*

| Field | Type | Description |
|-------|------|-------------|
| `name` | \*const char |  |
| `value` | i32 |  |

---

<a id="struct-typeinfo"></a>

### struct TypeInfo

*public* | *stdlib/std/type.lita:96*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [TypeKind](std_type.md#enum-typekind) |  |
| `name` | \*const char |  |
| `id` | typeid |  |

---

## Variables and Constants

<a id="const-typeinfos"></a>

### const typeInfos: \*\*[TypeInfo](std_type.md#struct-typeinfo)

*public* | *stdlib/std/type.lita:9*

---

<a id="const-numoftypeinfos"></a>

### const numOfTypeInfos: usize

*public* | *stdlib/std/type.lita:10*

---

