# main

## Functions

<a id="func-runlitac"></a>

### func RunLitac(options: \*[LitaOptions](lita.md#struct-litaoptions)) : i32

*public* | *src/main.lita:57*

---

<a id="func-parseargs"></a>

### func ParseArgs(n: i32, args: \*\*char, options: \*[LitaOptions](lita.md#struct-litaoptions)) : [ParseStatus](main.md#enum-parsestatus)

*public* | *src/main.lita:161*

---

<a id="func-buildargs"></a>

### func BuildArgs(parser: \*CmdParser) : void

*public* | *src/main.lita:180*

---

<a id="func-applyargs"></a>

### func ApplyArgs(parser: \*CmdParser, options: \*[LitaOptions](lita.md#struct-litaoptions)) : [ParseStatus](main.md#enum-parsestatus)

*public* | *src/main.lita:260*

---

## Types

<a id="enum-parsestatus"></a>

### enum ParseStatus

*public* | *src/main.lita:155*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `ERROR` |  |
| `TERMINATE` |  |

---

