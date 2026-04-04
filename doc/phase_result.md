# phase_result

## Functions

<a id="func-phaseresultinit"></a>

### func PhaseResultInit(allocator: \*const Allocator) : [PhaseResult](phase_result.md#struct-phaseresult)

*public* | *src/phase_result.lita:40*

---

<a id="func-adderror"></a>

### func addError(r: \*[PhaseResult](phase_result.md#struct-phaseresult), pos: [SrcPos](lex.md#struct-srcpos), format: \*const char, ...) : void

*public* | *src/phase_result.lita:51*

---

<a id="func-adderrorstr"></a>

### func addErrorStr(r: \*[PhaseResult](phase_result.md#struct-phaseresult), pos: [SrcPos](lex.md#struct-srcpos), sb: \*StringBuilder) : void

*public* | *src/phase_result.lita:61*

---

<a id="func-haserrors"></a>

### func hasErrors(r: \*[PhaseResult](phase_result.md#struct-phaseresult)) : bool

*public* | *src/phase_result.lita:73*

---

<a id="func-clear"></a>

### func clear(r: \*[PhaseResult](phase_result.md#struct-phaseresult)) : void

*public* | *src/phase_result.lita:77*

---

<a id="func-fromjson"></a>

### func (this: \*[PhaseResult](phase_result.md#struct-phaseresult)) fromJson(context: \*JsonContext, json: \*JsonNode) : bool

*public* | *src/phase_result.lita:1*

---

<a id="func-tojson"></a>

### func (this: \*[PhaseResult](phase_result.md#struct-phaseresult)) toJson(sb: \*StringBuilder) : bool

*public* | *src/phase_result.lita:1*

---

<a id="func-fromjson"></a>

### func (this: \*[PhaseError](phase_result.md#struct-phaseerror)) fromJson(context: \*JsonContext, json: \*JsonNode) : bool

*public* | *src/phase_result.lita:1*

---

<a id="func-tojson"></a>

### func (this: \*[PhaseError](phase_result.md#struct-phaseerror)) toJson(sb: \*StringBuilder) : bool

*public* | *src/phase_result.lita:1*

---

<a id="func-fromjson"></a>

### func (this: \*[ErrorType](phase_result.md#enum-errortype)) fromJson(context: \*JsonContext, json: \*JsonNode) : bool

*public* | *src/phase_result.lita:1*

---

<a id="func-tojson"></a>

### func (this: \*[ErrorType](phase_result.md#enum-errortype)) toJson(sb: \*StringBuilder) : bool

*public* | *src/phase_result.lita:1*

---

## Types

<a id="enum-errortype"></a>

### enum ErrorType

*public* | *src/phase_result.lita:14*

| Value | Description |
|-------|-------------|
| `WARN` |  |
| `ERROR` |  |

---

<a id="struct-phaseerror"></a>

### struct PhaseError

*public* | *src/phase_result.lita:20*

| Field | Type | Description |
|-------|------|-------------|
| `type` | [ErrorType](phase_result.md#enum-errortype) |  |
| `message` | \*const char |  |
| `pos` | [SrcPos](lex.md#struct-srcpos) |  |

---

<a id="struct-phaseresult"></a>

### struct PhaseResult

*public* | *src/phase_result.lita:27*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `errors` | Array\<[PhaseError](phase_result.md#struct-phaseerror)\> |  |
| `enabled` | bool |  |
| `isReadable` | bool |  |

---

