# doc

## Functions

<a id="func-generatedocs"></a>

### func GenerateDocs(lita: \*[Lita](lita.md#struct-lita), options: \*[DocOptions](doc.md#struct-docoptions)) : bool

*public* | *src/doc.lita:54*

Entry point: generate all docs from a fully type-checked Lita instance.

---

## Types

<a id="struct-docoptions"></a>

### struct DocOptions

*public* | *src/doc.lita:41*

| Field | Type | Description |
|-------|------|-------------|
| `docDir` | \*const char |  |
| `includeAll` | bool |  |
| `projectPath` | \*const char |  |
| `srcPath` | \*const char |  |
| `pkgName` | \*const char |  |
| `pkgNameLen` | i32 |  |
| `pkgVersion` | \*const char |  |
| `pkgVersionLen` | i32 |  |

---

