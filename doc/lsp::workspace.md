# lsp::workspace

## Functions

<a id="func-init"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) init(lsp: \*[LspServer](lsp::lsp.md#struct-lspserver), alloc: \*const Allocator) : void

*public* | *src/lsp/workspace.lita:43*

---

<a id="func-setup"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) setup(rootPath: \*const char, rootUri: \*const char) : void

*public* | *src/lsp/workspace.lita:51*

---

<a id="func-isdocumentopen"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) isDocumentOpen(uri: \*const char) : bool

*public* | *src/lsp/workspace.lita:95*

---

<a id="func-opendocument"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) openDocument(uri: \*const char, text: \*const char) : void

*public* | *src/lsp/workspace.lita:101*

---

<a id="func-closedocument"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) closeDocument(uri: \*const char) : void

*public* | *src/lsp/workspace.lita:120*

---

<a id="func-savedocument"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) saveDocument(uri: \*const char) : void

*public* | *src/lsp/workspace.lita:132*

---

<a id="func-changedocument"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) changeDocument(change: \*[TextDocumentDidChange](lsp::protocol.md#struct-textdocumentdidchange)) : void

*public* | *src/lsp/workspace.lita:137*

---

<a id="func-documentsymbols"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) documentSymbols(uri: \*const char, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/workspace.lita:156*

---

<a id="func-references"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) references(uri: \*const char, position: \*JsonNode, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/workspace.lita:207*

---

<a id="func-gotodefinition"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) goToDefinition(uri: \*const char, position: \*JsonNode, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/workspace.lita:469*

---

<a id="func-autocomplete"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) autoComplete(uri: \*const char, position: \*JsonNode, context: \*JsonNode, alloc: \*const Allocator) : \*JsonNode

*public* | *src/lsp/workspace.lita:753*

---

<a id="func-rundiagnostics"></a>

### func (this: \*[Workspace](lsp::workspace.md#struct-workspace)) runDiagnostics(docUri: \*const char, isFullBuild: bool) : \*[PhaseResult](phase_result.md#struct-phaseresult)

*public* | *src/lsp/workspace.lita:857*

---

## Types

<a id="struct-workspace"></a>

### struct Workspace

*public* | *src/lsp/workspace.lita:34*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `docAllocator` | TrackAllocator |  |
| `lsp` | \*[LspServer](lsp::lsp.md#struct-lspserver) |  |
| `rootPath` | \[\]char |  |
| `openedDocuments` | Map\<\*const char, \*[Document](lsp::document.md#struct-document)\> |  |

---

