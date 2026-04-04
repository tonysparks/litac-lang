# lsp::references

## Functions

<a id="func-init"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) init(allocator: \*const Allocator) : void

*public* | *src/lsp/references.lita:47*

---

<a id="func-addsymbolreference"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) addSymbolReference(symbol: \*[Symbol](symbols.md#struct-symbol), pos: [SrcPos](lex.md#struct-srcpos)) : void

*public* | *src/lsp/references.lita:56*

---

<a id="func-addtypereference"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) addTypeReference(type: \*[TypeSpec](ast.md#struct-typespec)) : void

*public* | *src/lsp/references.lita:70*

---

<a id="func-addtypereferencebysymbol"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) addTypeReferenceBySymbol(srcPos: [SrcPos](lex.md#struct-srcpos), sym: \*[Symbol](symbols.md#struct-symbol)) : void

*public* | *src/lsp/references.lita:79*

---

<a id="func-addtypereferencebytypeinfo"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) addTypeReferenceByTypeInfo(srcPos: [SrcPos](lex.md#struct-srcpos), typeInfo: \*[TypeInfo](types.md#struct-typeinfo)) : void

*public* | *src/lsp/references.lita:85*

---

<a id="func-addfieldreference"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) addFieldReference(srcPos: [SrcPos](lex.md#struct-srcpos), parent: \*[TypeInfo](types.md#struct-typeinfo), offset: i32) : void

*public* | *src/lsp/references.lita:109*

---

<a id="func-getsymbolreferences"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) getSymbolReferences(symbol: \*[Symbol](symbols.md#struct-symbol)) : Array\<[SrcPos](lex.md#struct-srcpos)\>

*public* | *src/lsp/references.lita:119*

---

<a id="func-removelocalsymbolreferences"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) removeLocalSymbolReferences(module: \*[Module](module.md#struct-module)) : void

*public* | *src/lsp/references.lita:131*

---

<a id="func-gettypereferences"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) getTypeReferences(typeid: Typeid, results: \*Array\<[SrcPos](lex.md#struct-srcpos)\>) : void

*public* | *src/lsp/references.lita:144*

---

<a id="func-getfieldreferences"></a>

### func (this: \*[ReferenceDatabase](lsp_references.md#struct-referencedatabase)) getFieldReferences(typeid: Typeid, offset: i32, results: \*Array\<[SrcPos](lex.md#struct-srcpos)\>) : void

*public* | *src/lsp/references.lita:153*

---

## Types

<a id="struct-reference"></a>

### struct Reference

*public* | *src/lsp/references.lita:25*

| Field | Type | Description |
|-------|------|-------------|
| `type` | Typeid |  |
| `pos` | [SrcPos](lex.md#struct-srcpos) |  |

---

<a id="struct-referencedatabase"></a>

### struct ReferenceDatabase

*public* | *src/lsp/references.lita:39*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `typeReferences` | Array\<[Reference](lsp_references.md#struct-reference)\> |  |
| `fieldReferences` | Array\<FieldReference\> |  |
| `symbols` | Map\<usize, Array\<[SrcPos](lex.md#struct-srcpos)\>\> |  |

---

