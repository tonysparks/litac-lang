# module

## Functions

<a id="func-builtinsinit"></a>

### func BuiltinsInit(lita: \*[Lita](lita.md#struct-lita)) : \*[Module](module.md#struct-module)

*public* | *src/module.lita:84*

---

<a id="func-assignbuiltinsymbols"></a>

### func AssignBuiltinSymbols(module: \*[Module](module.md#struct-module)) : void

*public* | *src/module.lita:125*

---

<a id="func-getbuiltinsymbol"></a>

### func GetBuiltinSymbol(typeid: Typeid) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/module.lita:146*

---

<a id="func-newmodule"></a>

### func NewModule(lita: \*[Lita](lita.md#struct-lita), packageName: String, filename: \*const char) : \*[Module](module.md#struct-module)

*public* | *src/module.lita:159*

---

<a id="func-init"></a>

### func (this: \*[Module](module.md#struct-module)) init(lita: \*[Lita](lita.md#struct-lita)) : void

*public* | *src/module.lita:169*

---

<a id="func-initincrementalbuild"></a>

### func (this: \*[Module](module.md#struct-module)) initIncrementalBuild() : void

*public* | *src/module.lita:197*

---

<a id="func-isbuiltin"></a>

### func (this: \*[Module](module.md#struct-module)) isBuiltin() : bool

*public* | *src/module.lita:216*

---

<a id="func-postincrementalbuild"></a>

### func (this: \*[Module](module.md#struct-module)) postIncrementalBuild() : void

*public* | *src/module.lita:220*

---

<a id="func-gettype"></a>

### func (this: \*[Module](module.md#struct-module)) getType(type: [InternedString](intern.md#union-internedstring)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/module.lita:225*

---

<a id="func-getfunctype"></a>

### func (this: \*[Module](module.md#struct-module)) getFuncType(type: [InternedString](intern.md#union-internedstring)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/module.lita:234*

---

<a id="func-getnotetype"></a>

### func (this: \*[Module](module.md#struct-module)) getNoteType(type: [InternedString](intern.md#union-internedstring)) : \*[Symbol](symbols.md#struct-symbol)

*public* | *src/module.lita:243*

---

<a id="func-getmethodsfortype"></a>

### func (this: \*[Module](module.md#struct-module)) getMethodsForType(type: \*[TypeInfo](types.md#struct-typeinfo), result: \[\]\*[Symbol](symbols.md#struct-symbol)) : i32

*public* | *src/module.lita:297*

---

<a id="func-getmethodsfortypewithname"></a>

### func (this: \*[Module](module.md#struct-module)) getMethodsForTypeWithName(type: \*[TypeInfo](types.md#struct-typeinfo), methodName: [InternedString](intern.md#union-internedstring), maxResults: i32, result: \[\]\*[Symbol](symbols.md#struct-symbol)) : i32

*public* | *src/module.lita:320*

---

<a id="func-getimportalias"></a>

### func (this: \*[Module](module.md#struct-module)) getImportAlias(module: \*[Module](module.md#struct-module)) : \*[InternedString](intern.md#union-internedstring)

*public* | *src/module.lita:361*


    Given the supplied module, return the alias name if and only if the supplied module
    is imported into this module with an alias.  Otherwise, returns an empty string.


---

<a id="func-getimportedmodulebyalias"></a>

### func (this: \*[Module](module.md#struct-module)) getImportedModuleByAlias(alias: [InternedString](intern.md#union-internedstring)) : \*[Module](module.md#struct-module)

*public* | *src/module.lita:370*

---

<a id="func-importmodule"></a>

### func (this: \*[Module](module.md#struct-module)) importModule(importDecl: \*[ImportDecl](ast.md#struct-importdecl), moduleToImport: \*[Module](module.md#struct-module)) : void

*public* | *src/module.lita:374*

---

<a id="func-importmodulesymbol"></a>

### func (this: \*[Module](module.md#struct-module)) importModuleSymbol(importSrcPos: [SrcPos](lex.md#struct-srcpos), moduleToImport: \*[Module](module.md#struct-module), moduleName: \*[InternedString](intern.md#union-internedstring), symbol: \*[Symbol](symbols.md#struct-symbol), symName: [InternedString](intern.md#union-internedstring), isUsing: bool) : void

*public* | *src/module.lita:426*

---

<a id="func-importpostgeneratedsymbol"></a>

### func (this: \*[Module](module.md#struct-module)) importPostGeneratedSymbol(sym: \*[Symbol](symbols.md#struct-symbol)) : void

*public* | *src/module.lita:481*

---

<a id="func-getfilenamekey"></a>

### func GetFilenameKey(filename: \*const char, output: \[\]char) : \*char

*public* | *src/module.lita:523*

---

<a id="func-equals"></a>

### func (this: \*[Module](module.md#struct-module)) equals(other: \*[Module](module.md#struct-module)) : bool

*public* | *src/module.lita:534*

---

<a id="func-isinpackage"></a>

### func (this: \*[Module](module.md#struct-module)) isInPackage(other: \*[Module](module.md#struct-module)) : bool

*public* | *src/module.lita:546*


    Checks to see if the supplied module is within this package


---

<a id="func-print"></a>

### func (this: \*[Module](module.md#struct-module)) print(header: \*const char) : void

*public* | *src/module.lita:585*

---

<a id="func-fromfile"></a>

### func fromFile(moduleId: \*[ModuleId](module.md#struct-moduleid), lita: \*[Lita](lita.md#struct-lita), packageName: String, filename: \*const char) : void

*public* | *src/module.lita:619*

---

<a id="func-tomodulepath"></a>

### func ToModulePath(moduleName: String) : String

*public* | *src/module.lita:631*

---

<a id="func-tomodulename"></a>

### func ToModuleName(modulePath: String) : String

*public* | *src/module.lita:653*

---

<a id="func-getmodulename"></a>

### func GetModuleName(pathStr: String) : String

*public* | *src/module.lita:679*

---

## Types

<a id="enum-moduleflags"></a>

### enum ModuleFlags

*public* | *src/module.lita:23*

| Value | Description |
|-------|-------------|
| `TYPE_CHECKED` |  |
| `TYPE_RESOLVED` |  |
| `TYPE_IMPORTED` |  |
| `INCREMENTAL_COMPILATION` |  |
| `IS_BUILTIN` |  |

---

<a id="struct-moduleid"></a>

### struct ModuleId

*public* | *src/module.lita:32*

| Field | Type | Description |
|-------|------|-------------|
| `filename` | \[\]char |  |
| `filenameKey` | \[\]char |  |
| `packageName` | [InternedString](intern.md#union-internedstring) |  |
| `name` | [InternedString](intern.md#union-internedstring) |  |

---

<a id="struct-moduleimport"></a>

### struct ModuleImport

*public* | *src/module.lita:42*

| Field | Type | Description |
|-------|------|-------------|
| `module` | \*[Module](module.md#struct-module) |  |
| `alias` | \*[InternedString](intern.md#union-internedstring) |  |
| `isUsing` | bool |  |

---

<a id="struct-module"></a>

### struct Module

*public* | *src/module.lita:48*

| Field | Type | Description |
|-------|------|-------------|
| `id` | [ModuleId](module.md#struct-moduleid) |  |
| `text` | StringBuffer |  |
| `ast` | \*[ModuleStmt](ast.md#struct-modulestmt) |  |
| `symbols` | [Scope](symbols.md#struct-scope) |  |
| `currentScope` | \*[Scope](symbols.md#struct-scope) |  |
| `genericSymbols` | \*Map\<[InternedString](intern.md#union-internedstring), \*[Symbol](symbols.md#struct-symbol)\> |  |
| `flags` | i32 |  |
| `importedBy` | Map\<\*const char, [ModuleImport](module.md#struct-moduleimport)\> |  |
| `importAliases` | Map\<[InternedString](intern.md#union-internedstring), \*[Module](module.md#struct-module)\> |  |
| `usingModules` | Map\<u64, \*[Module](module.md#struct-module)\> |  |
| `typeSpecAllocator` | [TypeSpecAllocator](ast_new.md#struct-typespecallocator) |  |
| `arena` | ArenaAllocator |  |
| `allocator` | \*const Allocator |  |
| `lita` | \*[Lita](lita.md#struct-lita) |  |
| `anyBuiltin` | \*[Symbol](symbols.md#struct-symbol) |  |
| `stringBuiltin` | \*[Symbol](symbols.md#struct-symbol) |  |

---

## Variables and Constants

<a id="const-builtin_import_ident"></a>

### const BUILTIN_IMPORT_IDENT

*public* | *src/module.lita:71*

---

<a id="const-builtin_import_token"></a>

### const BUILTIN_IMPORT_TOKEN

*public* | *src/module.lita:74*

---

<a id="const-max_methods_for_type"></a>

### const MAX_METHODS_FOR_TYPE

*public* | *src/module.lita:252*

---

