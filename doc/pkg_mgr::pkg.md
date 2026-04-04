# pkg_mgr::pkg

## Functions

<a id="func-free"></a>

### func (this: \*[PackageDef](pkg_mgr::pkg.md#struct-packagedef)) free() : void

*public* | *src/pkg_mgr/pkg.lita:47*

---

<a id="func-repo"></a>

### func (this: \*[PackageId](pkg_mgr::pkg.md#struct-packageid)) repo() : String

*public* | *src/pkg_mgr/pkg.lita:70*

---

<a id="func-name"></a>

### func (this: \*[PackageId](pkg_mgr::pkg.md#struct-packageid)) name() : String

*public* | *src/pkg_mgr/pkg.lita:74*

---

<a id="func-version"></a>

### func (this: \*[PackageId](pkg_mgr::pkg.md#struct-packageid)) version() : String

*public* | *src/pkg_mgr/pkg.lita:78*

---

<a id="func-packageidfromstring"></a>

### func PackageIdFromString(id: \*const char, pkgId: \*[PackageId](pkg_mgr::pkg.md#struct-packageid)) : bool

*public* | *src/pkg_mgr/pkg.lita:82*

---

<a id="func-parsepackagefile"></a>

### func ParsePackageFile(pm: \*[PackageManager](pkg_mgr.md#struct-packagemanager), pkgFile: \*const char, result: \*\*[PackageDef](pkg_mgr::pkg.md#struct-packagedef)) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg.lita:109*

---

<a id="func-parsepackage"></a>

### func ParsePackage(pm: \*[PackageManager](pkg_mgr.md#struct-packagemanager), json: \*JsonNode, result: \*\*[PackageDef](pkg_mgr::pkg.md#struct-packagedef)) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg.lita:150*

---

<a id="func-parsepackageid"></a>

### func ParsePackageId(json: \*JsonNode, pkgId: \*[PackageId](pkg_mgr::pkg.md#struct-packageid), allocator: \*const Allocator) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg.lita:233*

---

## Types

<a id="enum-packagetype"></a>

### enum PackageType

*public* | *src/pkg_mgr/pkg.lita:19*

| Value | Description |
|-------|-------------|
| `EXECUTABLE` |  |
| `STATIC_LIBRARY` |  |
| `DYNAMIC_LIBRARY` |  |
| `SOURCE_LIBRARY` |  |

---

<a id="struct-packagedef"></a>

### struct PackageDef

*public* | *src/pkg_mgr/pkg.lita:26*

| Field | Type | Description |
|-------|------|-------------|
| `id` | [PackageId](pkg_mgr::pkg.md#struct-packageid) |  |
| `path` | \[\]char |  |
| `type` | [PackageType](pkg_mgr::pkg.md#enum-packagetype) |  |
| `dynamicLibraries` | Array\<\*const char\> |  |
| `dependencies` | Array\<[PackageDependency](pkg_mgr::pkg.md#struct-packagedependency)\> |  |
| `json` | \*JsonNode |  |

---

<a id="struct-packagedependency"></a>

### struct PackageDependency

*public* | *src/pkg_mgr/pkg.lita:42*

| Field | Type | Description |
|-------|------|-------------|
| `pkgId` | [PackageId](pkg_mgr::pkg.md#struct-packageid) |  |
| `link` | bool |  |

---

<a id="struct-packageid"></a>

### struct PackageId

*public* | *src/pkg_mgr/pkg.lita:57*

| Field | Type | Description |
|-------|------|-------------|
| `id` | \[\]char |  |
| `repoOffset` | i32 |  |
| `repoLength` | i32 |  |
| `nameOffset` | i32 |  |
| `nameLength` | i32 |  |
| `versionOffset` | i32 |  |
| `versionLength` | i32 |  |

---

## Variables and Constants

<a id="const-separator"></a>

### const SEPARATOR

*public* | *src/pkg_mgr/pkg.lita:17*

---

