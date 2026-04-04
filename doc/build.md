# build

## Functions

<a id="func-init"></a>

### func (this: \*[BuildFile](build.md#struct-buildfile)) init(allocator: \*const Allocator) : void

*public* | *src/build.lita:36*

---

<a id="func-free"></a>

### func (this: \*[BuildFile](build.md#struct-buildfile)) free() : void

*public* | *src/build.lita:48*

---

<a id="func-writeto"></a>

### func (this: \*[BuildFile](build.md#struct-buildfile)) writeTo(file: \*File) : bool

*public* | *src/build.lita:72*

---

<a id="func-buildfilefromfile"></a>

### func BuildFileFromFile(filename: \*const char, buildFile: \*[BuildFile](build.md#struct-buildfile), allocator: \*const Allocator) : bool

*public* | *src/build.lita:93*

---

<a id="func-buildfilefromjson"></a>

### func BuildFileFromJson(json: \*JsonNode, buildFile: \*[BuildFile](build.md#struct-buildfile), allocator: \*const Allocator) : bool

*public* | *src/build.lita:119*

---

## Types

<a id="struct-buildfile"></a>

### struct BuildFile

*public* | *src/build.lita:24*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `compileCmdTemplate` | \*const char |  |
| `projectSrcDir` | \*const char |  |
| `pkgPaths` | Array\<\*const char\> |  |
| `includePaths` | Array\<\*const char\> |  |
| `libraryPaths` | Array\<\*const char\> |  |
| `staticLibs` | Array\<\*const char\> |  |

---

