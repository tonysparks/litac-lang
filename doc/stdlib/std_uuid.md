# std::uuid

## Functions

<a id="func-newrandom"></a>

### func NewRandom() : [UUID](std_uuid.md#union-uuid)

*public* | *stdlib/std/uuid.lita:15*

---

<a id="func-equals"></a>

### func (this: \*[UUID](std_uuid.md#union-uuid)) equals(other: \*[UUID](std_uuid.md#union-uuid)) : bool

*public* | *stdlib/std/uuid.lita:31*

---

<a id="func-version"></a>

### func (this: \*[UUID](std_uuid.md#union-uuid)) version() : i32

*public* | *stdlib/std/uuid.lita:35*

---

<a id="func-tostring"></a>

### func (this: \*[UUID](std_uuid.md#union-uuid)) toString(sb: [StringBuffer](std_string_buffer.md#struct-stringbuffer)) : String

*public* | *stdlib/std/uuid.lita:40*

---

<a id="func-fromstring"></a>

### func FromString(str: String) : [UUID](std_uuid.md#union-uuid)

*public* | *stdlib/std/uuid.lita:59*

---

## Types

<a id="union-uuid"></a>

### union UUID

*public* | *stdlib/std/uuid.lita:7*

| Field | Type | Description |
|-------|------|-------------|
| `bytes` | \[\]u8 |  |

---

