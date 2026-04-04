# cgen

## Functions

<a id="func-init"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) init(lita: \*[Lita](lita.md#struct-lita), output: \*File) : void

*public* | *src/cgen.lita:92*

---

<a id="func-emitprogram"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitProgram(module: \*[Module](module.md#struct-module)) : void

*public* | *src/cgen.lita:109*

---

<a id="func-getvtablename"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) getVTableName(sym: \*[Symbol](symbols.md#struct-symbol)) : String

*public* | *src/cgen.lita:403*

---

<a id="func-emittraitcast"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitTraitCast(expr: \*[Expr](ast.md#struct-expr)) : bool

*public* | *src/cgen.lita:425*

---

<a id="func-escapenamestr"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) escapeNameStr(name: [InternedString](intern.md#union-internedstring)) : String

*public* | *src/cgen.lita:527*

---

<a id="func-escapenamechars"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) escapeNameChars(name: \*const char) : String

*internal* | *src/cgen.lita:536*

---

<a id="func-emitlineinfo"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitLineInfo(stmt: \*[Stmt](ast.md#struct-stmt)) : void

*public* | *src/cgen.lita:665*

---

<a id="func-ctype"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) cType(type: \*[TypeInfo](types.md#struct-typeinfo), isCast: bool, decay: bool) : \*const char

*public* | *src/cgen.lita:704*

---

<a id="func-ctypedecl"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) cTypeDecl(type: \*[TypeInfo](types.md#struct-typeinfo), name: \*const char, decay: bool) : \*const char

*public* | *src/cgen.lita:831*

---

<a id="func-cname"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) cName(sym: \*[Symbol](symbols.md#struct-symbol)) : \*const char

*public* | *src/cgen.lita:1013*

---

<a id="func-ctypename"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) cTypeName(type: \*[TypeInfo](types.md#struct-typeinfo)) : \*const char

*public* | *src/cgen.lita:1050*

---

<a id="func-prefix"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) prefix(name: String, sb: \*StringBuilder) : \*const char

*public* | *src/cgen.lita:1062*

---

<a id="func-flush"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) flush() : void

*public* | *src/cgen.lita:1136*

---

<a id="func-emitnamestr"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitNameStr(name: String) : void

*public* | *src/cgen.lita:1143*

---

<a id="func-emitname"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitName(id: [Identifier](ast.md#struct-identifier)) : void

*public* | *src/cgen.lita:1147*

---

<a id="func-emitln"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitln() : void

*public* | *src/cgen.lita:1154*

---

<a id="func-emit"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emit(strFormat: \*const char, ...) : void

*public* | *src/cgen.lita:1161*

---

<a id="func-emitstr"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitStr(str: \*const char) : void

*public* | *src/cgen.lita:1204*

---

<a id="func-emitstrn"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitStrn(str: \*const char, len: i32) : void

*public* | *src/cgen.lita:1209*

---

<a id="func-emitnotes"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitNotes(attributes: \*[Attributes](ast.md#struct-attributes), isPrelude: bool) : void

*public* | *src/cgen.lita:1243*

---

<a id="func-emitstmt"></a>

### func (this: \*[CGen](cgen.md#struct-cgen)) emitStmt(s: \*[Stmt](ast.md#struct-stmt)) : void

*public* | *src/cgen.lita:1662*

---

## Types

<a id="struct-cgen"></a>

### struct CGen

*public* | *src/cgen.lita:28*

| Field | Type | Description |
|-------|------|-------------|
| `lita` | \*[Lita](lita.md#struct-lita) |  |
| `buf` | StringBuilder |  |
| `line` | StringBuilder |  |
| `format` | bool |  |
| `indent` | i32 |  |
| `aggregateLevel` | i32 |  |
| `currentLine` | i32 |  |
| `currentFile` | \*const char |  |
| `bufferFlush` | bool |  |
| `funcIndex` | i32 |  |
| `tmpVar` | i32 |  |
| `deferStack` | i32 |  |
| `inTextBlock` | bool |  |
| `currentFunc` | \*[TypeInfo](types.md#struct-typeinfo) |  |
| `currentScope` | \*CGenScope |  |
| `output` | \*File |  |

---

## Variables and Constants

<a id="const-max_compilation_units"></a>

### const MAX_COMPILATION_UNITS

*public* | *src/cgen.lita:60*

---

