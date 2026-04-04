# doc

## Functions

<a id="func-generatedocs"></a>

### func GenerateDocs(lita: \*[Lita](lita.md#struct-lita), options: \*[DocOptions](doc.md#struct-docoptions)) : bool

*public* | *src/doc.lita:58*

Entry point: generate all docs from a fully type-checked Lita instance.

---

## Types

<a id="enum-docformat"></a>

### enum DocFormat

*public* | *src/doc.lita:41*

| Value | Description |
|-------|-------------|
| `MARKDOWN` |  |
| `HTML` |  |

---

<a id="struct-docoptions"></a>

### struct DocOptions

*public* | *src/doc.lita:46*

| Field | Type | Description |
|-------|------|-------------|
| `docDir` | \*const char |  |
| `includeAll` | bool |  |
| `format` | [DocFormat](doc.md#enum-docformat) |  |
| `projectPath` | \*const char |  |
| `srcPath` | \*const char |  |
| `pkgName` | String |  |
| `pkgVersion` | String |  |

---

