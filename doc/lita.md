# lita

## Functions

<a id="func-init"></a>

### func (this: \*[Lita](lita.md#struct-lita)) init(options: \*[LitaOptions](lita.md#struct-litaoptions)) : void

*public* | *src/lita.lita:181*

---

<a id="func-reset"></a>

### func (this: \*[Lita](lita.md#struct-lita)) reset() : void

*public* | *src/lita.lita:210*

Resets the state reading for another compile

---

<a id="func-free"></a>

### func free(lita: \*[Lita](lita.md#struct-lita)) : void

*public* | *src/lita.lita:250*

---

<a id="func-printf"></a>

### func printf(lita: \*[Lita](lita.md#struct-lita), format: \*const char, ...) : void

*public* | *src/lita.lita:255*

---

<a id="func-addmodule"></a>

### func addModule(lita: \*[Lita](lita.md#struct-lita), module: \*[Module](module.md#struct-module)) : void

*public* | *src/lita.lita:279*

---

<a id="func-getmodule"></a>

### func getModule(lita: \*[Lita](lita.md#struct-lita), filename: \*const char) : \*[Module](module.md#struct-module)

*public* | *src/lita.lita:283*

---

<a id="func-getmodulebyname"></a>

### func getModuleByName(lita: \*[Lita](lita.md#struct-lita), name: \*const char) : \*[Module](module.md#struct-module)

*public* | *src/lita.lita:291*

Extremely slow, this is a linear probe

---

<a id="func-startcapture"></a>

### func startCapture(lita: \*[Lita](lita.md#struct-lita), type: [MetricType](lita.md#enum-metrictype)) : void

*public* | *src/lita.lita:318*

---

<a id="func-endcapture"></a>

### func endCapture(lita: \*[Lita](lita.md#struct-lita), type: [MetricType](lita.md#enum-metrictype)) : void

*public* | *src/lita.lita:327*

---

<a id="func-incrementalbuild"></a>

### func (this: \*[Lita](lita.md#struct-lita)) incrementalBuild(module: \*[Module](module.md#struct-module)) : void

*public* | *src/lita.lita:337*

---

<a id="func-parse"></a>

### func (this: \*[Lita](lita.md#struct-lita)) parse() : \*[Module](module.md#struct-module)

*public* | *src/lita.lita:410*

---

<a id="func-typecheck"></a>

### func (this: \*[Lita](lita.md#struct-lita)) typeCheck(module: \*[Module](module.md#struct-module), flags: i32) : bool

*public* | *src/lita.lita:455*

---

<a id="func-transpile"></a>

### func (this: \*[Lita](lita.md#struct-lita)) transpile(module: \*[Module](module.md#struct-module)) : bool

*public* | *src/lita.lita:467*

---

<a id="func-compilewithlibtcc"></a>

### func (this: \*[Lita](lita.md#struct-lita)) compileWithLibtcc(module: \*[Module](module.md#struct-module), binaryFilename: \*const char) : bool

*public* | *src/lita.lita:530*

---

<a id="func-emitc"></a>

### func (this: \*[Lita](lita.md#struct-lita)) emitC(module: \*[Module](module.md#struct-module), cFilename: \*const char) : bool

*public* | *src/lita.lita:602*

---

<a id="func-compilec"></a>

### func (this: \*[Lita](lita.md#struct-lita)) compileC(module: \*[Module](module.md#struct-module), sourceFilename: \*const char, binaryFilename: \*const char) : bool

*public* | *src/lita.lita:619*

---

<a id="func-run"></a>

### func (this: \*[Lita](lita.md#struct-lita)) run() : i32

*public* | *src/lita.lita:704*

---

<a id="func-findmodulepath"></a>

### func FindModulePath(lita: \*[Lita](lita.md#struct-lita), moduleName: String, filename: \[\]char) : bool

*public* | *src/lita.lita:764*

---

<a id="func-loadmodule"></a>

### func LoadModule(lita: \*[Lita](lita.md#struct-lita), packageName: String, srcPos: [SrcPos](lex.md#struct-srcpos)) : \*[Module](module.md#struct-module)

*public* | *src/lita.lita:944*

---

<a id="func-getpackagename"></a>

### func GetPackageName(srcPath: \*const char, inputFile: \*const char) : String

*public* | *src/lita.lita:965*

---

<a id="func-typeinfooptionasstr"></a>

### func TypeInfoOptionAsStr(enumType: [TypeInfoOption](lita.md#enum-typeinfooption)) : \*const char

*public* | *src/lita.lita:1*

---

<a id="func-metrictypeasstr"></a>

### func MetricTypeAsStr(enumType: [MetricType](lita.md#enum-metrictype)) : \*const char

*public* | *src/lita.lita:1*

---

## Types

<a id="struct-lita"></a>

### struct Lita

*public* | *src/lita.lita:45*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `globalAllocator` | BucketAllocator |  |
| `stringsAllocator` | BucketAllocator |  |
| `preprocessor` | [Preprocessor](preprocessor.md#struct-preprocessor) |  |
| `result` | [PhaseResult](phase_result.md#struct-phaseresult) |  |
| `modules` | Map\<\*const char, \*[Module](module.md#struct-module)\> |  |
| `metrics` | \[\][Metric](lita.md#struct-metric) |  |
| `totalSourceLines` | u32 |  |
| `totalAllocations` | u32 |  |
| `options` | \*[LitaOptions](lita.md#struct-litaoptions) |  |
| `binaryFilename` | \[\]char |  |
| `sourceFilename` | \[\]char |  |
| `buildFile` | [BuildFile](build.md#struct-buildfile) |  |
| `compilerOptions` | Array\<[CCompilerOption](lita.md#struct-ccompileroption)\> |  |
| `programSymbols` | [ProgramSymbols](symbols.md#struct-programsymbols) |  |
| `genericSymbols` | Map\<[InternedString](intern.md#union-internedstring), \*[Symbol](symbols.md#struct-symbol)\> |  |
| `typeCache` | [TypeCache](types_new.md#struct-typecache) |  |
| `strings` | [Strings](intern.md#struct-strings) |  |
| `builtins` | [Module](module.md#struct-module) |  |
| `references` | [ReferenceDatabase](lsp::references.md#struct-referencedatabase) |  |
| `workspace` | \*[Workspace](lsp::workspace.md#struct-workspace) |  |

---

<a id="enum-metrictype"></a>

### enum MetricType

*public* | *src/lita.lita:79*

| Value | Description |
|-------|-------------|
| `PARSING` |  |
| `TYPE_CHECKING` |  |
| `CGEN` |  |
| `CCOMPILE` |  |
| `MAX_METRIC_TYPES` |  |

---

<a id="struct-metric"></a>

### struct Metric

*public* | *src/lita.lita:88*

| Field | Type | Description |
|-------|------|-------------|
| `bytesAllocated` | usize |  |
| `allocationCount` | u32 |  |
| `executionTime` | f64 |  |
| `startTime` | f64 |  |

---

<a id="enum-typeinfooption"></a>

### enum TypeInfoOption

*public* | *src/lita.lita:97*

| Value | Description |
|-------|-------------|
| `NONE` |  |
| `TAGGED` |  |
| `ALL` |  |

---

<a id="struct-ccompileroption"></a>

### struct CCompilerOption

*public* | *src/lita.lita:103*

| Field | Type | Description |
|-------|------|-------------|
| `os` | OS |  |
| `arch` | Arch |  |
| `options` | String |  |

---

<a id="enum-pkgcommand"></a>

### enum PkgCommand

*public* | *src/lita.lita:109*

| Value | Description |
|-------|-------------|
| `PKG_NONE` |  |
| `PKG_INSTALL` |  |
| `PKG_RUN` |  |
| `PKG_INIT` |  |
| `PKG_BUILD` |  |
| `PKG_TEST` |  |
| `PKG_DOC` |  |

---

<a id="struct-pkgoptions"></a>

### struct PkgOptions

*public* | *src/lita.lita:119*

| Field | Type | Description |
|-------|------|-------------|
| `pkgCmd` | [PkgCommand](lita.md#enum-pkgcommand) |  |
| `pkgRunCmdArg` | \*const char |  |
| `forceClean` | bool |  |
| `isRelease` | bool |  |
| `pkgName` | \*const char |  |

---

<a id="struct-litaoptions"></a>

### struct LitaOptions

*public* | *src/lita.lita:128*

| Field | Type | Description |
|-------|------|-------------|
| `projectPath` | \[\]char |  |
| `srcPath` | \[\]char |  |
| `libPath` | \[\]char |  |
| `litaPath` | \[\]char |  |
| `inputFile` | \[\]char |  |
| `outputFile` | \[\]char |  |
| `outputPath` | \[\]char |  |
| `compileCmd` | \*const char |  |
| `isStrict` | bool |  |
| `isTcc` | bool |  |
| `checkerOnly` | bool |  |
| `cOutputOnly` | bool |  |
| `run` | bool |  |
| `showProfileInfo` | bool |  |
| `languageServer` | bool |  |
| `isDebug` | bool |  |
| `instrument` | bool |  |
| `isVerbose` | bool |  |
| `isColoredOutput` | bool |  |
| `isPreBuildEnabled` | bool |  |
| `isPostBuildEnabled` | bool |  |
| `args` | \*\*char |  |
| `nargs` | i32 |  |
| `testsOnly` | bool |  |
| `testsRegex` | \*const char |  |
| `testFileOnly` | bool |  |
| `testPackage` | \*const char |  |
| `testPath` | \[\]char |  |
| `isJsonFormat` | bool |  |
| `typeOption` | [TypeInfoOption](lita.md#enum-typeinfooption) |  |
| `cPrefix` | \[\]char |  |
| `cFormat` | bool |  |
| `disableLineSync` | bool |  |
| `maxMemory` | usize |  |
| `proxy` | \*const char |  |
| `pkgOptions` | [PkgOptions](lita.md#struct-pkgoptions) |  |
| `docDir` | \[\]char |  |
| `docAll` | bool |  |

---

## Variables and Constants

<a id="const-max_prefix_size"></a>

### const MAX_PREFIX_SIZE

*public* | *src/lita.lita:43*

---

