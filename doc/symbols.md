# symbols

## Functions

<a id="func-isaliased"></a>

### func (this: \*[Symbol](symbols.md#struct-symbol)) isAliased() : bool

*public* | *src/symbols.lita:97*

---

<a id="func-isgenericcapable"></a>

### func (this: \*[Symbol](symbols.md#struct-symbol)) isGenericCapable() : bool

*public* | *src/symbols.lita:112*

---

<a id="func-isvisibleto"></a>

### func (this: \*[Symbol](symbols.md#struct-symbol)) isVisibleTo(module: \*[Module](module.md#struct-module)) : bool

*public* | *src/symbols.lita:117*

---

<a id="func-hash"></a>

### func (this: \*[Symbol](symbols.md#struct-symbol)) hash() : u32

*public* | *src/symbols.lita:133*

---

<a id="func-equals"></a>

### func (this: \*[Symbol](symbols.md#struct-symbol)) equals(other: \*[Symbol](symbols.md#struct-symbol)) : bool

*public* | *src/symbols.lita:138*

---

<a id="func-newscope"></a>

### func NewScope(kind: [ScopeKind](symbols.md#enum-scopekind), parent: \*[Scope](symbols.md#struct-scope), result: \*[PhaseResult](phase_result.md#struct-phaseresult), module: \*[Module](module.md#struct-module), allocator: \*const Allocator) : \*[Scope](symbols.md#struct-scope)

*public* | *src/symbols.lita:168*

---

<a id="func-init"></a>

### func init(scope: \*[Scope](symbols.md#struct-scope), kind: [ScopeKind](symbols.md#enum-scopekind), parent: \*[Scope](symbols.md#struct-scope), result: \*[PhaseResult](phase_result.md#struct-phaseresult), module: \*[Module](module.md#struct-module), allocator: \*const Allocator) : void

*public* | *src/symbols.lita:180*

---

<a id="func-initincrementalbuild"></a>

### func initIncrementalBuild(scope: \*[Scope](symbols.md#struct-scope)) : void

*public* | *src/symbols.lita:204*

---

<a id="func-postincrementalbuild"></a>

### func postIncrementalBuild(scope: \*[Scope](symbols.md#struct-scope)) : void

*public* | *src/symbols.lita:210*

---

<a id="func-lookupfunc"></a>

### func lookupFunc(s: \*[Scope](symbols.md#struct-scope), name: [InternedString](intern.md#union-internedstring)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/symbols.lita:215*

---

<a id="func-lookupnote"></a>

### func lookupNote(s: \*[Scope](symbols.md#struct-scope), name: [InternedString](intern.md#union-internedstring)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/symbols.lita:228*

---

<a id="func-lookup"></a>

### func lookup(s: \*[Scope](symbols.md#struct-scope), name: [InternedString](intern.md#union-internedstring), includeFuncs: bool) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/symbols.lita:241*

---

<a id="func-importsymbolwithalias"></a>

### func (this: \*[Scope](symbols.md#struct-scope)) importSymbolWithAlias(importSrcPos: [SrcPos](lex.md#struct-srcpos), name: [InternedString](intern.md#union-internedstring), alias: [InternedString](intern.md#union-internedstring), symbol: \*[Symbol](symbols.md#struct-symbol)) : void

*public* | *src/symbols.lita:263*

---

<a id="func-importsymbol"></a>

### func (this: \*[Scope](symbols.md#struct-scope)) importSymbol(importSrcPos: [SrcPos](lex.md#struct-srcpos), name: [InternedString](intern.md#union-internedstring), symbol: \*[Symbol](symbols.md#struct-symbol)) : void

*public* | *src/symbols.lita:280*

---

<a id="func-removesymbol"></a>

### func (this: \*[Scope](symbols.md#struct-scope)) removeSymbol(symbol: \*[Symbol](symbols.md#struct-symbol)) : void

*public* | *src/symbols.lita:327*

---

<a id="func-addsymbol"></a>

### func (this: \*[Scope](symbols.md#struct-scope)) addSymbol(name: [InternedString](intern.md#union-internedstring), module: \*[Module](module.md#struct-module), decl: \*[Decl](ast.md#struct-decl), flags: i32) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/symbols.lita:347*

---

<a id="func-createqualifiedname"></a>

### func (this: \*[Scope](symbols.md#struct-scope)) createQualifiedName(name: [InternedString](intern.md#union-internedstring)) : [InternedString](intern.md#union-internedstring)

*public* | *src/symbols.lita:520*

---

<a id="func-print"></a>

### func (this: \*[Scope](symbols.md#struct-scope)) print(header: \*const char) : void

*public* | *src/symbols.lita:550*

---

<a id="func-symbolstateasstr"></a>

### func SymbolStateAsStr(enumType: [SymbolState](symbols.md#enum-symbolstate)) : \*const char

*public* | *src/symbols.lita:1*

---

<a id="func-symbolkindasstr"></a>

### func SymbolKindAsStr(enumType: [SymbolKind](symbols.md#enum-symbolkind)) : \*const char

*public* | *src/symbols.lita:1*

---

## Types

<a id="enum-symbolkind"></a>

### enum SymbolKind

*public* | *src/symbols.lita:21*

| Value | Description |
|-------|-------------|
| `TYPE` |  |
| `VAR` |  |
| `FUNC` |  |

---

<a id="enum-symbolstate"></a>

### enum SymbolState

*public* | *src/symbols.lita:28*

| Value | Description |
|-------|-------------|
| `UNRESOLVED` |  |
| `RESOLVING` |  |
| `RESOLVED` |  |
| `ERROR` |  |

---

<a id="enum-symbolflags"></a>

### enum SymbolFlags

*public* | *src/symbols.lita:35*

| Value | Description |
|-------|-------------|
| `IS_LOCAL` |  |
| `IS_FOREIGN` |  |
| `IS_CONSTANT` |  |
| `IS_USING` |  |
| `IS_TYPE` |  |
| `IS_INCOMPLETE` |  |
| `IS_GENERIC_TEMPLATE` |  |
| `IS_BUILTIN` |  |
| `IS_FROM_GENERIC_TEMPLATE` |  |
| `IS_IMPORTED` |  |
| `IS_PUBLIC` |  |
| `IS_INTERNAL` |  |
| `IS_PRIVATE` |  |
| `IS_EMITTED` |  |
| `IS_TEST` |  |
| `IS_ALIAS` |  |
| `IS_MAIN` |  |
| `IS_METHOD` |  |
| `IS_TRAIT` |  |
| `IS_TRAIT_METHOD` |  |
| `IS_TRAIT_GENERATED` |  |
| `IS_GENERATED` |  |
| `IS_NOTE` |  |
| `IS_MARKED_RESET` |  |
| `IS_HIDDEN` |  |
| `IS_FROM_PREPROCESSOR` |  |

---

<a id="struct-symgenericarg"></a>

### struct SymGenericArg

*public* | *src/symbols.lita:68*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [GenericArgKind](ast.md#enum-genericargkind) |  |
| `type` | \*[TypeInfo](types.md#struct-typeinfo) |  |

---

<a id="struct-symbol"></a>

### struct Symbol

*public* | *src/symbols.lita:75*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [SymbolKind](symbols.md#enum-symbolkind) |  |
| `name` | [InternedString](intern.md#union-internedstring) |  |
| `qualifiedName` | [InternedString](intern.md#union-internedstring) |  |
| `state` | [SymbolState](symbols.md#enum-symbolstate) |  |
| `decl` | \*[Decl](ast.md#struct-decl) |  |
| `type` | \*[TypeInfo](types.md#struct-typeinfo) |  |
| `usingParent` | \*[Symbol](symbols.md#struct-symbol) |  |
| `declared` | \*[Module](module.md#struct-module) |  |
| `usingModule` | \*[Module](module.md#struct-module) |  |
| `flags` | i32 |  |
| `val` | [Value](lex.md#union-value) |  |
| `genericCallsiteModule` | \*[Module](module.md#struct-module) |  |
| `genericArgs` | Array\<[SymGenericArg](symbols.md#struct-symgenericarg)\> |  |
| `genericParams` | Array\<[GenericParam](ast.md#struct-genericparam)\> |  |

---

<a id="enum-scopekind"></a>

### enum ScopeKind

*public* | *src/symbols.lita:142*

| Value | Description |
|-------|-------------|
| `MODULE` |  |
| `FUNC` |  |

---

<a id="struct-programsymbols"></a>

### struct ProgramSymbols

*public* | *src/symbols.lita:147*

| Field | Type | Description |
|-------|------|-------------|
| `root` | \*[Module](module.md#struct-module) |  |
| `values` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `symbolTypes` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `symbolFuncs` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `mainEntry` | \*[Symbol](symbols.md#struct-symbol) |  |
| `interfaceImpls` | Map\<Typeid, Array\<Typeid\>\> |  |

---

<a id="struct-scope"></a>

### struct Scope

*public* | *src/symbols.lita:156*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [ScopeKind](symbols.md#enum-scopekind) |  |
| `allocator` | \*const Allocator |  |
| `result` | \*[PhaseResult](phase_result.md#struct-phaseresult) |  |
| `parent` | \*[Scope](symbols.md#struct-scope) |  |
| `symbolNotes` | Map\<[InternedString](intern.md#union-internedstring), \*[Symbol](symbols.md#struct-symbol)\> |  |
| `symbolTypes` | Map\<[InternedString](intern.md#union-internedstring), \*[Symbol](symbols.md#struct-symbol)\> |  |
| `symbolFuncs` | Map\<[InternedString](intern.md#union-internedstring), \*[Symbol](symbols.md#struct-symbol)\> |  |
| `module` | \*[Module](module.md#struct-module) |  |

---

## Variables and Constants

<a id="const-max_symbol_name"></a>

### const MAX_SYMBOL_NAME

*public* | *src/symbols.lita:73*

---

