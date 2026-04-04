# lsp::lsp

## Functions

<a id="func-init"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) init(lita: \*[Lita](lita.md#struct-lita)) : void

*public* | *src/lsp/lsp.lita:43*

---

<a id="func-requestalloc"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) requestAlloc() : \*const Allocator

*public* | *src/lsp/lsp.lita:70*

---

<a id="func-appalloc"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) appAlloc() : \*const Allocator

*public* | *src/lsp/lsp.lita:75*

---

<a id="func-free"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) free() : void

*public* | *src/lsp/lsp.lita:79*

---

<a id="func-start"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) start() : void

*public* | *src/lsp/lsp.lita:98*

---

<a id="func-log"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) log(format: \*const char, ...) : void

*public* | *src/lsp/lsp.lita:109*

---

<a id="func-readmessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) readMessage() : void

*public* | *src/lsp/lsp.lita:117*

---

<a id="func-handlemessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleMessage(msg: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:238*

---

<a id="func-handleinitializemessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleInitializeMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:301*

---

<a id="func-handletextdocumentopenmessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleTextDocumentOpenMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:344*

---

<a id="func-handletextdocumentclosemessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleTextDocumentCloseMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:355*

---

<a id="func-handletextdocumentsymbolmessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleTextDocumentSymbolMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:367*

---

<a id="func-handletextdocumentsavemessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleTextDocumentSaveMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:383*

---

<a id="func-handletextdocumentchangemessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleTextDocumentChangeMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:395*

---

<a id="func-handletextdocumentreferencesmessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleTextDocumentReferencesMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:403*

---

<a id="func-handletextdocumentdefinitionmessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleTextDocumentDefinitionMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:421*

---

<a id="func-handletextdocumentcompletionmessage"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) handleTextDocumentCompletionMessage(msg: \*JsonNode, params: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:438*

---

<a id="func-writediagnostic"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) writeDiagnostic(docUri: \*const char, fullBuild: bool) : void

*public* | *src/lsp/lsp.lita:456*

---

<a id="func-writeerrorresponse"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) writeErrorResponse(id: i64, code: i32, format: \*const char, ...) : void

*public* | *src/lsp/lsp.lita:503*

---

<a id="func-writeresponse"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) writeResponse(msg: \*JsonNode) : void

*public* | *src/lsp/lsp.lita:521*

---

<a id="func-createresponse"></a>

### func (this: \*[LspServer](lsp::lsp.md#struct-lspserver)) createResponse(id: i64) : \*JsonNode

*public* | *src/lsp/lsp.lita:546*

---

## Types

<a id="struct-lspserver"></a>

### struct LspServer

*public* | *src/lsp/lsp.lita:25*

| Field | Type | Description |
|-------|------|-------------|
| `requestAllocator` | BucketAllocator |  |
| `applicationAllocator` | BucketAllocator |  |
| `lita` | \*[Lita](lita.md#struct-lita) |  |
| `message` | StringBuilder |  |
| `output` | StringBuilder |  |
| `outbound` | StringBuilder |  |
| `isInitialized` | bool |  |
| `isRunning` | bool |  |
| `workspace` | [Workspace](lsp::workspace.md#struct-workspace) |  |
| `logFile` | \*FILE |  |

---

