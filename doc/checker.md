# checker

## Functions

<a id="func-init"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) init(lita: \*[Lita](lita.md#struct-lita), allocator: \*const Allocator) : void

*public* | *src/checker.lita:89*

---

<a id="func-typecheck"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) typeCheck(root: \*[Module](module.md#struct-module), flags: i32) : [ProgramSymbols](symbols.md#struct-programsymbols)

*public* | *src/checker.lita:116*

---

<a id="func-errors"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) errors() : i32

*public* | *src/checker.lita:184*

---

<a id="func-checkcastability"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) checkCastability(src: [SrcPos](lex.md#struct-srcpos), a: \*[TypeInfo](types.md#struct-typeinfo), b: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/checker.lita:242*

---

<a id="func-checkassignability"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) checkAssignability(src: [SrcPos](lex.md#struct-srcpos), a: \*[TypeInfo](types.md#struct-typeinfo), b: \*[TypeInfo](types.md#struct-typeinfo), allowDecay: bool) : bool

*public* | *src/checker.lita:270*

---

<a id="func-checkdeclarability"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) checkDeclarability(src: [SrcPos](lex.md#struct-srcpos), a: \*[TypeInfo](types.md#struct-typeinfo), b: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*public* | *src/checker.lita:352*

---

<a id="func-checktypecompatibility"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) checkTypeCompatibility(src: [SrcPos](lex.md#struct-srcpos), a: \*[TypeInfo](types.md#struct-typeinfo), b: \*[TypeInfo](types.md#struct-typeinfo), allowPtrArithmetic: bool) : bool

*public* | *src/checker.lita:378*

---

<a id="func-checktypeconstraint"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) checkTypeConstraint(src: [SrcPos](lex.md#struct-srcpos), a: \*[TypeInfo](types.md#struct-typeinfo), b: \*[TypeInfo](types.md#struct-typeinfo), sym: \*[Symbol](symbols.md#struct-symbol), index: i32) : bool

*public* | *src/checker.lita:413*

---

<a id="func-createdeclsymbol"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) createDeclSymbol(decl: \*[Decl](ast.md#struct-decl)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/checker.lita:506*

---

<a id="func-entermodule"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) enterModule(module: \*[Module](module.md#struct-module)) : void

*public* | *src/checker.lita:691*

---

<a id="func-leavemodule"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) leaveModule() : void

*public* | *src/checker.lita:696*

---

<a id="func-currentscope"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) currentScope() : \*[Scope](symbols.md#struct-scope)

*public* | *src/checker.lita:705*

---

<a id="func-pushscope"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) pushScope(scope: \*[Scope](symbols.md#struct-scope)) : void

*public* | *src/checker.lita:709*

---

<a id="func-popscope"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) popScope() : void

*public* | *src/checker.lita:714*

---

<a id="func-isgenericparamtype"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) isGenericParamType(name: \*[TypeSpec](ast.md#struct-typespec)) : bool

*public* | *src/checker.lita:720*

---

<a id="func-createimportsymbols"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) createImportSymbols(imp: \*[ImportDecl](ast.md#struct-importdecl)) : void

*public* | *src/checker.lita:739*

---

<a id="func-resolvesymbol"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) resolveSymbol(sym: \*[Symbol](symbols.md#struct-symbol)) : void

*public* | *src/checker.lita:830*

---

<a id="func-finishresolvesymbol"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) finishResolveSymbol(sym: \*[Symbol](symbols.md#struct-symbol)) : void

*public* | *src/checker.lita:974*

---

<a id="func-gettype"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) getType(spec: \*[TypeSpec](ast.md#struct-typespec), searchType: [SearchType](checker.md#enum-searchtype)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/checker.lita:1046*

---

<a id="func-gettypebyname"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) getTypeByName(typeName: [InternedString](intern.md#union-internedstring), searchType: [SearchType](checker.md#enum-searchtype)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/checker.lita:1051*

---

<a id="func-implementstrait"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) implementsTrait(agg: \*[TypeInfo](types.md#struct-typeinfo), iface: \*[TypeInfo](types.md#struct-typeinfo), missingMethods: \*Array\<[FieldStmt](ast.md#struct-fieldstmt)\>) : bool

*public* | *src/checker.lita:1146*

---

<a id="func-resolvetypespec"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) resolveTypeSpec(spec: \*[TypeSpec](ast.md#struct-typespec), searchType: [SearchType](checker.md#enum-searchtype)) : \*[TypeInfo](types.md#struct-typeinfo)

*public* | *src/checker.lita:1270*

---

<a id="func-addsymbol"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) addSymbol(decl: \*[Decl](ast.md#struct-decl), typeInfo: \*[TypeInfo](types.md#struct-typeinfo)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/checker.lita:1403*

---

<a id="func-addtypetoscope"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) addTypeToScope(decl: \*[Decl](ast.md#struct-decl), scope: \*[Scope](symbols.md#struct-scope), baseType: \*[TypeInfo](types.md#struct-typeinfo), currentType: \*[TypeInfo](types.md#struct-typeinfo)) : void

*public* | *src/checker.lita:1417*

---

<a id="func-resolvenotes"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) resolveNotes(notes: \*Array\<\*[NoteStmt](ast.md#struct-notestmt)\>) : bool

*public* | *src/checker.lita:1462*

---

<a id="func-resolvestmt"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) resolveStmt(stmt: \*[Stmt](ast.md#struct-stmt)) : bool

*public* | *src/checker.lita:1527*

---

## Types

<a id="enum-typecheckerflags"></a>

### enum TypeCheckerFlags

*public* | *src/checker.lita:53*

| Value | Description |
|-------|-------------|
| `DISABLE_TRAIT_WRAPPERS` |  |

---

<a id="struct-typechecker"></a>

### struct TypeChecker

*public* | *src/checker.lita:57*

| Field | Type | Description |
|-------|------|-------------|
| `lita` | \*[Lita](lita.md#struct-lita) |  |
| `current` | \*[Module](module.md#struct-module) |  |
| `moduleStack` | Array\<\*[Module](module.md#struct-module)\> |  |
| `funcDeclStack` | Array\<\*[TypeInfo](types.md#struct-typeinfo)\> |  |
| `pendingValues` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `symbolTypes` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `symbolFuncs` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `symbolTraits` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `mainEntry` | \*[Symbol](symbols.md#struct-symbol) |  |
| `symbolNotes` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `genericContext` | GenericContext |  |
| `genericParamStack` | Array\<Array\<[GenericParam](ast.md#struct-genericparam)\>\> |  |
| `genericTemplates` | Array\<\*[Symbol](symbols.md#struct-symbol)\> |  |
| `interfaceImpls` | Map\<Typeid, Array\<Typeid\>\> |  |
| `labels` | \[\]LabelInfo |  |
| `numOfLabels` | i32 |  |
| `typeCache` | \*[TypeCache](types_new.md#struct-typecache) |  |
| `randomNameIndex` | u32 |  |
| `bypassing` | bool |  |

---

<a id="enum-searchtype"></a>

### enum SearchType

*public* | *src/checker.lita:1040*

| Value | Description |
|-------|-------------|
| `TYPE` |  |
| `FUNC` |  |
| `NOTE` |  |

---

