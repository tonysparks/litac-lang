# preprocessor

## Functions

<a id="func-preprocessorinit"></a>

### func PreprocessorInit(lita: \*[Lita](lita.md#struct-lita)) : [Preprocessor](preprocessor.md#struct-preprocessor)

*public* | *src/preprocessor/preprocessor.lita:87*

---

<a id="func-init"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) init(lita: \*[Lita](lita.md#struct-lita)) : void

*public* | *src/preprocessor/preprocessor.lita:94*

---

<a id="func-free"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) free() : void

*public* | *src/preprocessor/preprocessor.lita:112*

---

<a id="func-eval"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) eval(comp: \*[CompStmt](ast.md#struct-compstmt)) : bool

*public* | *src/preprocessor/preprocessor.lita:117*

---

<a id="func-evaluateformodule"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) evaluateForModule(module: \*[Module](module.md#struct-module), moduleStmt: \*[ModuleStmt](ast.md#struct-modulestmt), comp: \*[CompStmt](ast.md#struct-compstmt)) : void

*public* | *src/preprocessor/preprocessor.lita:145*

---

<a id="func-evaluateforfunction"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) evaluateForFunction(checker: \*[TypeChecker](checker.md#struct-typechecker), comp: \*[CompStmt](ast.md#struct-compstmt), isFirst: bool) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/preprocessor/preprocessor.lita:215*

---

<a id="func-preresolvesymbols"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) preResolveSymbols(checker: \*[TypeChecker](checker.md#struct-typechecker), isIncrementalBuild: bool) : void

*public* | *src/preprocessor/preprocessor.lita:269*

---

<a id="func-postresolvesymbols"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) postResolveSymbols(checker: \*[TypeChecker](checker.md#struct-typechecker), isIncrementalBuild: bool) : void

*public* | *src/preprocessor/preprocessor.lita:293*

---

<a id="func-drainqueue"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) drainQueue() : void

*public* | *src/preprocessor/preprocessor.lita:318*

---

## Types

<a id="struct-preprocessor"></a>

### struct Preprocessor

*public* | *src/preprocessor/preprocessor.lita:38*

| Field | Type | Description |
|-------|------|-------------|
| `lita` | \*[Lita](lita.md#struct-lita) |  |
| `runtime` | [ScriptRuntime](preprocessor::api.md#struct-scriptruntime) |  |
| `callContext` | [CallContext](preprocessor.md#struct-callcontext) |  |
| `preCheckers` | Array\<[CheckerContext](preprocessor.md#struct-checkercontext)\> |  |
| `postCheckers` | Array\<[CheckerContext](preprocessor.md#struct-checkercontext)\> |  |
| `declQueue` | Array\<[ScriptDecl](preprocessor.md#struct-scriptdecl)\> |  |

---

<a id="struct-callcontext"></a>

### struct CallContext

*public* | *src/preprocessor/preprocessor.lita:48*

| Field | Type | Description |
|-------|------|-------------|
| `pp` | \*[Preprocessor](preprocessor.md#struct-preprocessor) |  |
| `checker` | \*[TypeChecker](checker.md#struct-typechecker) |  |
| `comp` | \*[CompStmt](ast.md#struct-compstmt) |  |
| `buffer` | StringBuilder |  |
| `resolveSymbols` | bool |  |

---

<a id="struct-checkercontext"></a>

### struct CheckerContext

*public* | *src/preprocessor/preprocessor.lita:57*

| Field | Type | Description |
|-------|------|-------------|
| `module` | \*[Module](module.md#struct-module) |  |
| `stmt` | \*[CompStmt](ast.md#struct-compstmt) |  |

---

<a id="struct-declcontext"></a>

### struct DeclContext

*public* | *src/preprocessor/preprocessor.lita:62*

| Field | Type | Description |
|-------|------|-------------|
| `checker` | \*[TypeChecker](checker.md#struct-typechecker) |  |
| `comp` | \*[CompStmt](ast.md#struct-compstmt) |  |
| `resolveSymbols` | bool |  |

---

<a id="struct-scriptdecl"></a>

### struct ScriptDecl

*public* | *src/preprocessor/preprocessor.lita:72*

| Field | Type | Description |
|-------|------|-------------|
| `ctx` | [DeclContext](preprocessor.md#struct-declcontext) |  |
| `module` | \*[Module](module.md#struct-module) |  |
| `declarations` | \*[ModuleStmt](ast.md#struct-modulestmt) |  |
| `replacement` | bool |  |

---

