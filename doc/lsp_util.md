# lsp::util

## Functions

<a id="func-issrcposatposition"></a>

### func IsSrcPosAtPosition(srcPos: \*[SrcPos](lex.md#struct-srcpos), pos: [Position](lsp_protocol.md#struct-position)) : bool

*public* | *src/lsp/util.lita:46*

---

<a id="func-findastnodebyposition"></a>

### func (this: \*[SourceLookup](lsp_util.md#struct-sourcelookup)) findAstNodeByPosition(moduleAst: \*[ModuleStmt](ast.md#struct-modulestmt), pos: [Position](lsp_protocol.md#struct-position)) : [SourceLocation](lsp_util.md#struct-sourcelocation)

*public* | *src/lsp/util.lita:73*

---

## Types

<a id="enum-sourcelocationkind"></a>

### enum SourceLocationKind

*public* | *src/lsp/util.lita:17*

| Value | Description |
|-------|-------------|
| `NONE` |  |
| `AST` |  |
| `TYPE` |  |

---

<a id="struct-sourcelocation"></a>

### struct SourceLocation

*public* | *src/lsp/util.lita:24*

The ast node at a particular location in the source code

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [SourceLocationKind](lsp_util.md#enum-sourcelocationkind) |  |
| `module` | \*[Module](module.md#struct-module) |  |
| `location` | [Location](lsp_protocol.md#struct-location) |  |

---

<a id="struct-sourcelookup"></a>

### struct SourceLookup

*public* | *src/lsp/util.lita:67*

| Field | Type | Description |
|-------|------|-------------|
| `lsp` | \*[LspServer](lsp_lsp.md#struct-lspserver) |  |
| `lookupPos` | [Position](lsp_protocol.md#struct-position) |  |
| `result` | [SourceLocation](lsp_util.md#struct-sourcelocation) |  |

---

