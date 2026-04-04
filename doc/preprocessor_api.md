# preprocessor::api

## Functions

<a id="func-registerapi"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) registerApi() : void

*public* | *src/preprocessor/api.lita:36*

---

<a id="func-deregisterapi"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) deregisterApi() : void

*public* | *src/preprocessor/api.lita:83*

---

<a id="func-execute"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) execute(comp: \*[CompStmt](ast.md#struct-compstmt), code: String) : bool

*public* | *src/preprocessor/api.lita:87*

---

<a id="func-postparse"></a>

### func (this: \*[CallContext](preprocessor.md#struct-callcontext)) postParse(module: \*[Module](module.md#struct-module), moduleStmt: \*[ModuleStmt](ast.md#struct-modulestmt), comp: \*[CompStmt](ast.md#struct-compstmt)) : void

*public* | *src/preprocessor/api.lita:522*


Parses out the #postparse compile time statement which will attempt to
generate or alter existing source.


---

<a id="func-loadscript"></a>

### func (this: \*[Preprocessor](preprocessor.md#struct-preprocessor)) loadScript(comp: \*[CompStmt](ast.md#struct-compstmt), filename: \*String, code: \*String) : bool

*public* | *src/preprocessor/api.lita:1036*

---

## Types

<a id="struct-scriptruntime"></a>

### struct ScriptRuntime

*public* | *src/preprocessor/api.lita:32*

| Field | Type | Description |
|-------|------|-------------|
| `ape` | \*[ape_t](ape.md#typedef-ape_t) |  |

---

