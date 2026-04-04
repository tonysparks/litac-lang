# types_new

## Functions

<a id="func-hash"></a>

### func (this: [ArrayEntry](types_new.md#struct-arrayentry)) hash() : u32

*public* | *src/types_new.lita:30*

---

<a id="func-equals"></a>

### func equals(a: [ArrayEntry](types_new.md#struct-arrayentry), b: [ArrayEntry](types_new.md#struct-arrayentry)) : bool

*public* | *src/types_new.lita:39*

---

<a id="func-init"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) init(allocator: \*const Allocator) : void

*public* | *src/types_new.lita:51*

---

<a id="func-newgenericparamtypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newGenericParamTypeInfo(name: [InternedString](intern.md#union-internedstring)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:70*

---

<a id="func-newfunctypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newFuncTypeInfo(sym: \*[Symbol](symbols.md#struct-symbol), funcDecl: \*[FuncDecl](ast.md#struct-funcdecl)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:83*

---

<a id="func-newarraytypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newArrayTypeInfo(arrayOf: \*[TypeInfo](types.md#struct-typeinfo), length: usize, numOfElements: \*[Expr](ast.md#struct-expr), isLengthDefined: bool) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:95*

---

<a id="func-newfuncptrtypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newFuncPtrTypeInfo(genericParams: Array\<[GenericParam](ast.md#struct-genericparam)\>, returnType: \*[TypeInfo](types.md#struct-typeinfo), paramDecls: Array\<\*[TypeInfo](types.md#struct-typeinfo)\>, hasVarargs: bool, hasNativeVarargs: bool) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:118*

---

<a id="func-newaggregatetypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newAggregateTypeInfo(sym: \*[Symbol](symbols.md#struct-symbol), decl: \*[AggregateDecl](ast.md#struct-aggregatedecl)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:136*

---

<a id="func-newenumtypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newEnumTypeInfo(sym: \*[Symbol](symbols.md#struct-symbol), enumDecl: \*[EnumDecl](ast.md#struct-enumdecl)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:165*

---

<a id="func-newforeigntypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newForeignTypeInfo(sym: \*[Symbol](symbols.md#struct-symbol)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:176*

---

<a id="func-newaliasedforeigntypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newAliasedForeignTypeInfo(sym: \*[Symbol](symbols.md#struct-symbol), alias: \*[TypeInfo](types.md#struct-typeinfo)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:185*

---

<a id="func-newconsttypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newConstTypeInfo(base: \*[TypeInfo](types.md#struct-typeinfo)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:196*

---

<a id="func-newptrtypeinfo"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) newPtrTypeInfo(base: \*[TypeInfo](types.md#struct-typeinfo)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:214*

---

<a id="func-typedecay"></a>

### func (this: \*[TypeCache](types_new.md#struct-typecache)) typeDecay(type: \*[TypeInfo](types.md#struct-typeinfo)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types_new.lita:227*

---

## Types

<a id="struct-typecache"></a>

### struct TypeCache

*public* | *src/types_new.lita:15*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `typeInfos` | BucketList\<[TypeInfo](types.md#struct-typeinfo)\> |  |
| `constCache` | Map\<i64, \*[TypeInfo](types.md#struct-typeinfo)\> |  |
| `ptrCache` | Map\<i64, \*[TypeInfo](types.md#struct-typeinfo)\> |  |
| `arrayCache` | Map\<[ArrayEntry](types_new.md#struct-arrayentry), \*[TypeInfo](types.md#struct-typeinfo)\> |  |
| `genericCache` | Map\<[InternedString](intern.md#union-internedstring), \*[TypeInfo](types.md#struct-typeinfo)\> |  |

---

<a id="struct-arrayentry"></a>

### struct ArrayEntry

*public* | *src/types_new.lita:24*

| Field | Type | Description |
|-------|------|-------------|
| `arrayOf` | \*[TypeInfo](types.md#struct-typeinfo) |  |
| `expr` | \*[Expr](ast.md#struct-expr) |  |
| `length` | usize |  |

---

