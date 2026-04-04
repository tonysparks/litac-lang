# types

## Functions

<a id="func-typekindfromstring"></a>

### func TypeKindFromString(str: \*const char, len: i32) : [TypeKind](types.md#enum-typekind)

*public* | *src/types.lita:94*

---

<a id="func-isarray"></a>

### func IsArray(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:105*

---

<a id="func-isenum"></a>

### func IsEnum(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:118*

---

<a id="func-isptr"></a>

### func IsPtr(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:131*

---

<a id="func-isptrlike"></a>

### func IsPtrLike(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:144*

---

<a id="func-isptrof"></a>

### func IsPtrOf(type: \*[TypeInfo](types.md#struct-typeinfo), kind: [TypeKind](types.md#enum-typekind)) : bool

*public* | *src/types.lita:165*

---

<a id="func-isfunclike"></a>

### func IsFuncLike(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:193*

---

<a id="func-isprimitive"></a>

### func IsPrimitive(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:209*

---

<a id="func-isnumberlike"></a>

### func IsNumberLike(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:217*

---

<a id="func-isinteger"></a>

### func IsInteger(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:253*

---

<a id="func-isbitfield"></a>

### func IsBitField(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:284*

---

<a id="func-isbooleanable"></a>

### func IsBooleanable(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:312*

---

<a id="func-isstringlike"></a>

### func IsStringLike(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:349*

---

<a id="func-ischarlike"></a>

### func IsCharLike(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:370*

---

<a id="func-astraitfuncptr"></a>

### func AsTraitFuncPtr(type: \*[TypeInfo](types.md#struct-typeinfo), name: [InternedString](intern.md#union-internedstring), typeCache: \*[TypeCache](types_new.md#struct-typecache)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types.lita:395*

---

<a id="func-asaggregate"></a>

### func AsAggregate(type: \*[TypeInfo](types.md#struct-typeinfo)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types.lita:425*

---

<a id="func-isaggregatelike"></a>

### func IsAggregateLike(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:453*

---

<a id="func-isaggregate"></a>

### func IsAggregate(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:457*

---

<a id="func-isptraggregate"></a>

### func IsPtrAggregate(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:472*

---

<a id="func-istrait"></a>

### func IsTrait(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:487*

---

<a id="func-isptrtrait"></a>

### func IsPtrTrait(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:500*

---

<a id="func-istraitlike"></a>

### func IsTraitLike(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:516*

---

<a id="func-isfieldaccessible"></a>

### func IsFieldAccessible(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:520*

---

<a id="func-isgenericcapable"></a>

### func IsGenericCapable(type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:532*

---

<a id="func-getbasetype"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getBaseType() : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types.lita:549*

---

<a id="func-gettypeof"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getTypeOf() : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types.lita:577*

---

<a id="func-tostringdebug"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) toStringDebug() : \*const char

*public* | *src/types.lita:602*

---

<a id="func-tostring"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) toString(sb: \*StringBuilder, fullyQualify: bool) : void

*public* | *src/types.lita:608*

---

<a id="func-strictequals"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) strictEquals(other: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/types.lita:724*

---

<a id="func-isassignable"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) isAssignable(other: \*[TypeInfo](types.md#struct-typeinfo), checker: \*[TypeChecker](checker.md#struct-typechecker), allowDecay: bool, allowPtrArithmetic: bool) : bool

*public* | *src/types.lita:801*

---

<a id="func-isdeclarable"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) isDeclarable(other: \*[TypeInfo](types.md#struct-typeinfo), checker: \*[TypeChecker](checker.md#struct-typechecker)) : bool

*public* | *src/types.lita:1001*

---

<a id="func-cancastto"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) canCastTo(castTo: \*[TypeInfo](types.md#struct-typeinfo), checker: \*[TypeChecker](checker.md#struct-typechecker)) : bool

*public* | *src/types.lita:1325*

---

<a id="func-isfuncimpl"></a>

### func IsFuncImpl(traitFn: \*[TypeInfo](types.md#struct-typeinfo), fn: \*[TypeInfo](types.md#struct-typeinfo), checker: \*[TypeChecker](checker.md#struct-typechecker)) : bool

*public* | *src/types.lita:1440*

---

<a id="func-astypespec"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) asTypeSpec(module: \*[Module](module.md#struct-module), fullyQualify: bool) : \*[TypeSpec](ast.md#struct-typespec)

*public* | *src/types.lita:1485*

---

<a id="func-asptr"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) asPtr(typeCache: \*[TypeCache](types_new.md#struct-typecache)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/types.lita:1663*

---

<a id="func-getenumfield"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getEnumField(name: [InternedString](intern.md#union-internedstring)) : \*[EnumFieldEntryDecl](ast.md#struct-enumfieldentrydecl)

*public* | *src/types.lita:1685*

---

<a id="func-getenumfieldindex"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getEnumFieldIndex(name: [InternedString](intern.md#union-internedstring)) : i32

*public* | *src/types.lita:1697*

---

<a id="func-getbasename"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getBaseName(name: \[\]char, includePackage: bool, alias: \*[InternedString](intern.md#union-internedstring)) : \*const char

*public* | *src/types.lita:1710*

---

<a id="func-getbasenameview"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getBaseNameView() : String

*public* | *src/types.lita:1763*

---

<a id="func-getfieldbyposition"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getFieldByPosition(position: i32) : [FieldStmt](ast.md#struct-fieldstmt)

*public* | *src/types.lita:1780*

---

<a id="func-getfield"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getField(name: [InternedString](intern.md#union-internedstring)) : [FieldStmt](ast.md#struct-fieldstmt)

*public* | *src/types.lita:1791*

---

<a id="func-getfieldindex"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getFieldIndex(name: [InternedString](intern.md#union-internedstring)) : i32

*public* | *src/types.lita:1856*

Gets the field position in this aggregate type (including anonymous aggregates) only

---

<a id="func-getfieldposition"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getFieldPosition(name: [InternedString](intern.md#union-internedstring)) : [FieldPositionResult](types.md#struct-fieldpositionresult)

*public* | *src/types.lita:1931*

Gets the field position in this aggregate type and any using sub aggregates

---

<a id="func-getfieldbytype"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getFieldByType(type: \*[TypeInfo](types.md#struct-typeinfo), isParent: bool) : [FieldStmt](ast.md#struct-fieldstmt)

*public* | *src/types.lita:1966*


Gets the first field of the supplied type.  This should only be used for finding 'using'
fields to match against and the supplied type should be an aggregate (i.e., not a pointer)


---

<a id="func-getfieldwithusing"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getFieldWithUsing(name: [InternedString](intern.md#union-internedstring)) : [FieldStmt](ast.md#struct-fieldstmt)

*public* | *src/types.lita:2032*

---

<a id="func-getfieldpath"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getFieldPath(name: [InternedString](intern.md#union-internedstring), path: \*[FieldPath](types.md#struct-fieldpath)) : bool

*public* | *src/types.lita:2097*

---

<a id="func-getfieldpathbytype"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getFieldPathByType(type: \*[TypeInfo](types.md#struct-typeinfo), path: \*[FieldPath](types.md#struct-fieldpath)) : bool

*public* | *src/types.lita:2144*

---

<a id="func-getfunctionname"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getFunctionName(result: \[\]char, methodName: [InternedString](intern.md#union-internedstring), alias: \*[InternedString](intern.md#union-internedstring), includePackage: bool) : \*const char

*public* | *src/types.lita:2206*


Given a method name, this will return the function name equivalent, which is:
AggregateName_MethodName


---

<a id="func-getmethod"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) getMethod(strings: \*[Strings](intern.md#struct-strings), module: \*[Module](module.md#struct-module), methodName: [InternedString](intern.md#union-internedstring)) : [MethodResult](types.md#struct-methodresult)

*public* | *src/types.lita:2227*

---

<a id="func-implementstrait"></a>

### func (this: \*[TypeInfo](types.md#struct-typeinfo)) implementsTrait(iface: \*[TypeInfo](types.md#struct-typeinfo), checker: \*[TypeChecker](checker.md#struct-typechecker), missingMethods: \*Array\<[FieldStmt](ast.md#struct-fieldstmt)\>) : bool

*public* | *src/types.lita:2357*

---

<a id="func-nexttypeid"></a>

### func NextTypeId() : Typeid

*public* | *src/types.lita:2379*

---

<a id="func-typesinit"></a>

### func TypesInit(strings: \*[Strings](intern.md#struct-strings)) : void

*public* | *src/types.lita:2387*


The supplied `Strings` must be initialized and pre-populated with interned constants


---

<a id="func-typekindasstr"></a>

### func TypeKindAsStr(enumType: [TypeKind](types.md#enum-typekind)) : \*const char

*public* | *src/types.lita:1*

---

## Types

<a id="enum-typekind"></a>

### enum TypeKind

*public* | *src/types.lita:23*

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
| `MAX_TYPE_KINDS` |  |

---

<a id="struct-fieldpositionresult"></a>

### struct FieldPositionResult

*public* | *src/types.lita:1925*

| Field | Type | Description |
|-------|------|-------------|
| `aggInfo` | \*[TypeInfo](types.md#struct-typeinfo) |  |
| `position` | i32 |  |

---

<a id="struct-fieldpath"></a>

### struct FieldPath

*public* | *src/types.lita:2078*

| Field | Type | Description |
|-------|------|-------------|
| `fields` | \[\][FieldStmt](ast.md#struct-fieldstmt) |  |
| `numOfFields` | i32 |  |

---

<a id="struct-methodresult"></a>

### struct MethodResult

*public* | *src/types.lita:2222*

| Field | Type | Description |
|-------|------|-------------|
| `symbol` | \*[Symbol](symbols.md#struct-symbol) |  |
| `name` | [InternedString](intern.md#union-internedstring) |  |

---

<a id="typedef-typeid"></a>

### typedef Typeid = i64

*public* | *src/types.lita:2374*

---

<a id="struct-typeinfo"></a>

### struct TypeInfo

*public* | *src/types.lita:2408*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [TypeKind](types.md#enum-typekind) |  |
| `typeid` | Typeid |  |
| `name` | [InternedString](intern.md#union-internedstring) |  |
| `sym` | \*[Symbol](symbols.md#struct-symbol) |  |
| `genericTypeid` | Typeid |  |
| `returnType` | \*[TypeInfo](types.md#struct-typeinfo) |  |

---

## Variables and Constants

<a id="const-max_field_path"></a>

### const MAX_FIELD_PATH

*public* | *src/types.lita:2077*

---

<a id="const-bool_type"></a>

### const BOOL_TYPE

*public* | *src/types.lita:2456*

---

<a id="const-char_type"></a>

### const CHAR_TYPE

*public* | *src/types.lita:2462*

---

<a id="const-i8_type"></a>

### const I8_TYPE

*public* | *src/types.lita:2468*

---

<a id="const-u8_type"></a>

### const U8_TYPE

*public* | *src/types.lita:2474*

---

<a id="const-i16_type"></a>

### const I16_TYPE

*public* | *src/types.lita:2480*

---

<a id="const-u16_type"></a>

### const U16_TYPE

*public* | *src/types.lita:2486*

---

<a id="const-i32_type"></a>

### const I32_TYPE

*public* | *src/types.lita:2492*

---

<a id="const-u32_type"></a>

### const U32_TYPE

*public* | *src/types.lita:2498*

---

<a id="const-i64_type"></a>

### const I64_TYPE

*public* | *src/types.lita:2504*

---

<a id="const-u64_type"></a>

### const U64_TYPE

*public* | *src/types.lita:2510*

---

<a id="const-f32_type"></a>

### const F32_TYPE

*public* | *src/types.lita:2516*

---

<a id="const-f64_type"></a>

### const F64_TYPE

*public* | *src/types.lita:2522*

---

<a id="const-usize_type"></a>

### const USIZE_TYPE

*public* | *src/types.lita:2528*

---

<a id="const-null_type"></a>

### const NULL_TYPE

*public* | *src/types.lita:2534*

---

<a id="const-void_type"></a>

### const VOID_TYPE

*public* | *src/types.lita:2540*

---

<a id="const-str_type"></a>

### const STR_TYPE

*public* | *src/types.lita:2546*

---

<a id="const-poison_type"></a>

### const POISON_TYPE

*public* | *src/types.lita:2552*

---

<a id="const-builtin_types"></a>

### const BUILTIN_TYPES

*public* | *src/types.lita:2558*

---

