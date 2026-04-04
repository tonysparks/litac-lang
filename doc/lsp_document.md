# lsp::document

## Functions

<a id="func-free"></a>

### func (this: \*[Document](lsp_document.md#struct-document)) free() : void

*internal* | *src/lsp/document.lita:16*

---

<a id="func-refreshlinemap"></a>

### func (this: \*[Document](lsp_document.md#struct-document)) refreshLineMap() : void

*internal* | *src/lsp/document.lita:22*

---

<a id="func-getlinestart"></a>

### func (this: \*[Document](lsp_document.md#struct-document)) getLineStart(lineNumber: i32) : u32

*internal* | *src/lsp/document.lita:37*

---

<a id="func-insert"></a>

### func (this: \*[Document](lsp_document.md#struct-document)) insert(range: [Range](lsp_protocol.md#struct-range), text: \*const char) : void

*internal* | *src/lsp/document.lita:41*

---

<a id="func-settext"></a>

### func (this: \*[Document](lsp_document.md#struct-document)) setText(text: \*const char) : void

*internal* | *src/lsp/document.lita:49*

---

## Types

<a id="struct-document"></a>

### struct Document

*public* | *src/lsp/document.lita:9*

| Field | Type | Description |
|-------|------|-------------|
| `filename` | \[\]char |  |
| `text` | StringBuilder |  |
| `lineMap` | Array\<u32\> |  |

---

