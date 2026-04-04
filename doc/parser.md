# parser

## Functions

<a id="func-parserinit"></a>

### func ParserInit(filename: \*const char, text: \*const char, length: i64, module: \*[Module](module.md#struct-module), lita: \*[Lita](lita.md#struct-lita)) : [Parser](parser.md#struct-parser)

*public* | *src/parser.lita:80*

---

<a id="func-parsemodule"></a>

### func parseModule(p: \*[Parser](parser.md#struct-parser)) : \*[ModuleStmt](ast.md#struct-modulestmt)

*public* | *src/parser.lita:131*

---

<a id="func-expression"></a>

### func expression(p: \*[Parser](parser.md#struct-parser)) : \*[Expr](ast.md#struct-expr)

*public* | *src/parser.lita:801*

---

<a id="func-statement"></a>

### func statement(p: \*[Parser](parser.md#struct-parser)) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/parser.lita:1457*

---

## Types

<a id="struct-parser"></a>

### struct Parser

*public* | *src/parser.lita:55*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `typeAllocator` | \*[TypeSpecAllocator](ast_new.md#struct-typespecallocator) |  |
| `module` | \*[Module](module.md#struct-module) |  |
| `result` | \*[PhaseResult](phase_result.md#struct-phaseresult) |  |
| `lita` | \*[Lita](lita.md#struct-lita) |  |
| `strings` | \*[Strings](intern.md#struct-strings) |  |
| `filename` | \*const char |  |
| `totalLines` | i32 |  |
| `tokens` | Array\<[Token](lex.md#struct-token)\> |  |
| `current` | i32 |  |
| `currentPos` | [SrcPos](lex.md#struct-srcpos) |  |
| `breakLevel` | i32 |  |
| `loopLevel` | i32 |  |
| `switchLevel` | i32 |  |
| `funcLevel` | i32 |  |
| `aggregateLevel` | i32 |  |
| `tryLevel` | u32 |  |
| `tryErrorCounter` | u64 |  |
| `panicMode` | bool |  |
| `preprocessorLevel` | i32 |  |

---

