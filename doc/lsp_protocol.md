# lsp::protocol

> 
    Protocol specifications from: https://microsoft.github.io/language-server-protocol/specifications


## Functions

<a id="func-symbolkindfromsymbol"></a>

### func SymbolKindFromSymbol(sym: \*sym::Symbol) : [SymbolInfoKind](lsp_protocol.md#enum-symbolinfokind)

*public* | *src/lsp/protocol.lita:132*

---

<a id="func-symboltosymbolinformation"></a>

### func SymbolToSymbolInformation(sym: \*sym::Symbol, rootPath: \*const char, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/protocol.lita:203*

---

<a id="func-srcpostolocation"></a>

### func SrcPosToLocation(pos: [SrcPos](lex.md#struct-srcpos), rootPath: \*const char, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/protocol.lita:227*

---

<a id="func-srcposwithendtolocation"></a>

### func SrcPosWithEndToLocation(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), rootPath: \*const char, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/protocol.lita:243*

---

<a id="func-srcpostorange"></a>

### func SrcPosToRange(pos: [SrcPos](lex.md#struct-srcpos), alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/protocol.lita:258*

---

<a id="func-srcposwithendtorange"></a>

### func SrcPosWithEndToRange(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/protocol.lita:277*

---

<a id="func-srcpostolocations"></a>

### func SrcPosToLocations(rootPath: \*const char, results: \*Array\<[SrcPos](lex.md#struct-srcpos)\>, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/protocol.lita:297*

---

<a id="func-symboltocompletionitem"></a>

### func SymbolToCompletionItem(symbol: \*sym::Symbol, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/protocol.lita:312*

---

<a id="func-jsonnodetotextdocumentchangeevent"></a>

### func JsonNodeToTextDocumentChangeEvent(params: \*JsonNode, alloc: \*const Allocator) : \*[TextDocumentDidChange](lsp_protocol.md#struct-textdocumentdidchange)

*public* | *src/lsp/protocol.lita:327*

---

## Types

<a id="struct-position"></a>

### struct Position

*public* | *src/lsp/protocol.lita:16*

| Field | Type | Description |
|-------|------|-------------|
| `line` | i32 |  |
| `character` | i32 |  |

---

<a id="struct-range"></a>

### struct Range

*public* | *src/lsp/protocol.lita:21*

| Field | Type | Description |
|-------|------|-------------|
| `start` | [Position](lsp_protocol.md#struct-position) |  |
| `end` | [Position](lsp_protocol.md#struct-position) |  |

---

<a id="struct-location"></a>

### struct Location

*public* | *src/lsp/protocol.lita:26*

| Field | Type | Description |
|-------|------|-------------|
| `uri` | \*const char |  |
| `range` | [Range](lsp_protocol.md#struct-range) |  |

---

<a id="struct-textdocument"></a>

### struct TextDocument

*public* | *src/lsp/protocol.lita:31*

| Field | Type | Description |
|-------|------|-------------|
| `uri` | \*const char |  |
| `version` | u32 |  |

---

<a id="struct-textdocumentdidchange"></a>

### struct TextDocumentDidChange

*public* | *src/lsp/protocol.lita:36*

| Field | Type | Description |
|-------|------|-------------|
| `textDocument` | [TextDocument](lsp_protocol.md#struct-textdocument) |  |
| `contentChanges` | Array\<[TextDocumentChangeEvent](lsp_protocol.md#struct-textdocumentchangeevent)\> |  |

---

<a id="struct-textdocumentchangeevent"></a>

### struct TextDocumentChangeEvent

*public* | *src/lsp/protocol.lita:41*

| Field | Type | Description |
|-------|------|-------------|
| `hasRange` | bool |  |
| `range` | [Range](lsp_protocol.md#struct-range) |  |
| `rangeLength` | u32 |  |
| `text` | \*const char |  |

---

<a id="enum-errorcodes"></a>

### enum ErrorCodes

*public* | *src/lsp/protocol.lita:48*

| Value | Description |
|-------|-------------|
| `ParseError` |  |
| `InvalidRequest` |  |
| `MethodNotFound` |  |
| `InvalidParams` |  |
| `InternalError` |  |
| `jsonrpcReservedErrorRangeStart` |  |
| `serverErrorStart` |  |
| `ServerNotInitialized` |  |
| `UnknownErrorCode` |  |
| `jsonrpcReservedErrorRangeEnd` |  |
| `serverErrorEnd` |  |
| `lspReservedErrorRangeStart` |  |
| `ContentModified` |  |
| `RequestCancelled` |  |
| `lspReservedErrorRangeEnd` |  |

---

<a id="enum-symbolinfokind"></a>

### enum SymbolInfoKind

*public* | *src/lsp/protocol.lita:103*

| Value | Description |
|-------|-------------|
| `File` |  |
| `Module` |  |
| `Namespace` |  |
| `Package` |  |
| `Class` |  |
| `Method` |  |
| `Property` |  |
| `Field` |  |
| `Constructor` |  |
| `Enum` |  |
| `Interface` |  |
| `Function` |  |
| `Variable` |  |
| `Constant` |  |
| `String` |  |
| `Number` |  |
| `Boolean` |  |
| `Array` |  |
| `Object` |  |
| `Key` |  |
| `Null` |  |
| `EnumMember` |  |
| `Struct` |  |
| `Event` |  |
| `Operator` |  |
| `TypeParameter` |  |

---

