# pkg_mgr

## Functions

<a id="func-init"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) init(options: [PackageOptions](pkg_mgr.md#struct-packageoptions), allocator: \*const Allocator) : void

*public* | *src/pkg_mgr/pkg_mgr.lita:187*

---

<a id="func-free"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) free() : void

*public* | *src/pkg_mgr/pkg_mgr.lita:199*

---

<a id="func-isverbose"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) isVerbose() : bool

*internal* | *src/pkg_mgr/pkg_mgr.lita:214*

---

<a id="func-initcommand"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) initCommand(options: [PackageInitOptions](pkg_mgr.md#struct-packageinitoptions)) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg_mgr.lita:240*


    Initializes a new LitaC project, writing out scaffolding files


---

<a id="func-buildcommand"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) buildCommand(options: [PackageBuildOptions](pkg_mgr.md#struct-packagebuildoptions)) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg_mgr.lita:248*


    Initializes a new LitaC project, writing out scaffolding files


---

<a id="func-installcommand"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) installCommand(options: [PackageInstallOptions](pkg_mgr.md#struct-packageinstalloptions)) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg_mgr.lita:284*


    Installs all packages defined the pkg.json to the file system.


---

<a id="func-createbuildfile"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) createBuildFile(buildFile: \*[BuildFile](build.md#struct-buildfile)) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg_mgr.lita:318*


    Updates the build.json file with any dependent package information.  This
    should be called after a sync is made.


---

<a id="func-writebuildfile"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) writeBuildFile() : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg_mgr.lita:338*

---

<a id="func-runcommand"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) runCommand(cmd: \*const char) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg_mgr.lita:375*


    Run a command from the pkg.json:commands[{argument}]


---

<a id="func-testcommand"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) testCommand(options: \*[LitaOptions](lita.md#struct-litaoptions)) : i32

*public* | *src/pkg_mgr/pkg_mgr.lita:389*


    Recursively scan directory for *_test.lita files and run each test file.


---

<a id="func-doccommand"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) docCommand(options: \*[LitaOptions](lita.md#struct-litaoptions)) : [PkgStatus](pkg_mgr.md#enum-pkgstatus)

*public* | *src/pkg_mgr/pkg_mgr.lita:397*


    Generates Markdown documentation for the project's public and internal declarations.


---

<a id="func-hasprojectpkg"></a>

### func (this: \*[PackageManager](pkg_mgr.md#struct-packagemanager)) hasProjectPkg() : bool

*public* | *src/pkg_mgr/pkg_mgr.lita:418*

---

## Types

<a id="struct-packageoptions"></a>

### struct PackageOptions

*public* | *src/pkg_mgr/pkg_mgr.lita:116*

| Field | Type | Description |
|-------|------|-------------|
| `projectPath` | \*const char |  |
| `pkgDir` | \*const char |  |
| `litaOptions` | \*[LitaOptions](lita.md#struct-litaoptions) |  |
| `cmdArgCount` | i32 |  |
| `cmdArgs` | \*\*char |  |

---

<a id="struct-packageinitoptions"></a>

### struct PackageInitOptions

*public* | *src/pkg_mgr/pkg_mgr.lita:127*

| Field | Type | Description |
|-------|------|-------------|
| `name` | \*const char |  |
| `version` | \*const char |  |
| `type` | \*const char |  |
| `repo` | \*const char |  |

---

<a id="struct-packagebuildoptions"></a>

### struct PackageBuildOptions

*public* | *src/pkg_mgr/pkg_mgr.lita:134*

| Field | Type | Description |
|-------|------|-------------|
| `isRelease` | bool |  |
| `isTest` | bool |  |

---

<a id="struct-packageinstalloptions"></a>

### struct PackageInstallOptions

*public* | *src/pkg_mgr/pkg_mgr.lita:139*

| Field | Type | Description |
|-------|------|-------------|
| `fullSync` | bool |  |
| `httpOptions` | HttpOptions |  |

---

<a id="enum-pkgstatus"></a>

### enum PkgStatus

*public* | *src/pkg_mgr/pkg_mgr.lita:145*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `ERROR_NO_PROJECT_PKG_FOUND` |  |
| `ERROR_COMMAND_NOT_DEFINED` |  |
| `ERROR_RUNNING_COMMAND` |  |
| `ERROR_CREATING_PKG_DIR` |  |
| `ERROR_CLEANING_PKG` |  |
| `ERROR_UNABLE_TO_OPEN_FILE` |  |
| `ERROR_UNABLE_TO_OPEN_PKG_FILE` |  |
| `ERROR_UNABLE_TO_EXTRACT_PKG_FILE` |  |
| `ERROR_UNABLE_TO_PROCESS_PKG_FILE` |  |
| `ERROR_OPENING_LOCAL_FILE_PKG` |  |
| `ERROR_READING_LOCAL_FILE_PKG` |  |
| `ERROR_WRITING_LOCAL_FILE_PKG` |  |
| `ERROR_OPENING_BUILD_FILE` |  |
| `ERROR_WRITING_BUILD_FILE` |  |
| `ERROR_FINALIZING_LOCAL_FILE_PKG` |  |
| `ERROR_PARSING_PKG_JSON` |  |
| `ERROR_READING_PKG_FILE` |  |
| `ERROR_HTTP_STATUS` |  |
| `ERROR_INVALID_DIRECTORY` |  |
| `ERROR_INVALID_REPO` |  |
| `ERROR_INIT_PACKAGE` |  |
| `ERROR_PARSING_BUILD_OPTIONS` |  |
| `ERROR_INVALID_BUILD_TARGET` |  |
| `ERROR_INVALID_BUILD_OS` |  |
| `ERROR_INVALID_BUILD_ARCH` |  |
| `ERROR_TEST_SUITE_FAILED` |  |

---

<a id="struct-packagemanager"></a>

### struct PackageManager

*public* | *src/pkg_mgr/pkg_mgr.lita:176*

| Field | Type | Description |
|-------|------|-------------|
| `options` | [PackageOptions](pkg_mgr.md#struct-packageoptions) |  |
| `allocator` | \*const Allocator |  |
| `packages` | Map\<\*const char, \*[PackageDef](pkg_mgr_pkg.md#struct-packagedef)\> |  |
| `pkg` | \*[PackageDef](pkg_mgr_pkg.md#struct-packagedef) |  |
| `errors` | StringBuilder |  |
| `warnings` | StringBuilder |  |

---

