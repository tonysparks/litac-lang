# ast

## Functions

<a id="func-setsrcpos"></a>

### func setSrcPos(n: \*[Node](ast.md#struct-node), start: [SrcPos](lex.md#struct-srcpos), end: [SrcPos](lex.md#struct-srcpos)) : void

*public* | *src/ast.lita:194*

---

<a id="func-becomeparentof"></a>

### func becomeParentOf\<T\>(n: \*[Node](ast.md#struct-node), child: \*T) : \*T

*public* | *src/ast.lita:199*

---

<a id="func-becomeparentofchildren"></a>

### func becomeParentOfChildren\<T\>(n: \*[Node](ast.md#struct-node), children: \*Array\<T\>) : \*Array\<T\>

*public* | *src/ast.lita:206*

---

<a id="func-becomeparentofchildrencallargs"></a>

### func becomeParentOfChildrenCallArgs(n: \*[Node](ast.md#struct-node), children: \*Array\<[CallArg](ast.md#struct-callarg)\>) : \*Array\<[CallArg](ast.md#struct-callarg)\>

*public* | *src/ast.lita:218*

---

<a id="func-isexpr"></a>

### func IsExpr(node: \*[Node](ast.md#struct-node)) : bool

*public* | *src/ast.lita:645*

---

<a id="func-isdecl"></a>

### func IsDecl(node: \*[Node](ast.md#struct-node)) : bool

*public* | *src/ast.lita:683*

---

<a id="func-hasnotes"></a>

### func hasNotes(d: \*[Decl](ast.md#struct-decl)) : bool

*public* | *src/ast.lita:705*

---

<a id="func-hasnote"></a>

### func hasNote(d: \*[Decl](ast.md#struct-decl), name: \*const char) : bool

*public* | *src/ast.lita:710*

---

<a id="func-getnote"></a>

### func getNote(d: \*[Decl](ast.md#struct-decl), name: \*const char) : \*[NoteStmt](ast.md#struct-notestmt)

*public* | *src/ast.lita:715*

---

<a id="func-getnoteargument"></a>

### func getNoteArgument(d: \*[Decl](ast.md#struct-decl), name: \*const char, arg: \*const char) : \*[CallArg](ast.md#struct-callarg)

*public* | *src/ast.lita:731*

---

<a id="func-getbasetype"></a>

### func (this: \*[TypeSpec](ast.md#struct-typespec)) getBaseType() : \*[TypeSpec](ast.md#struct-typespec)

*public* | *src/ast.lita:750*

---

<a id="func-getname"></a>

### func getName(f: \*[FuncDecl](ast.md#struct-funcdecl), name: \[\]char) : bool

*public* | *src/ast.lita:776*

---

<a id="func-isidentifier"></a>

### func isIdentifier(expr: \*[Expr](ast.md#struct-expr)) : bool

*public* | *src/ast.lita:826*

---

<a id="func-isconstnumberexpr"></a>

### func isConstNumberExpr(expr: \*[Expr](ast.md#struct-expr)) : bool

*public* | *src/ast.lita:837*

---

<a id="func-isconstexpr"></a>

### func isConstExpr(expr: \*[Expr](ast.md#struct-expr)) : bool

*public* | *src/ast.lita:874*

---

<a id="func-callargsort"></a>

### func CallArgSort(a: [CallArg](ast.md#struct-callarg), b: [CallArg](ast.md#struct-callarg)) : i32

*public* | *src/ast.lita:913*

---

## Types

<a id="enum-stmtkind"></a>

### enum StmtKind

*public* | *src/ast.lita:16*

| Value | Description |
|-------|-------------|
| `IMPORT_DECL` |  |
| `CONST_DECL` |  |
| `VAR_DECL` |  |
| `STRUCT_DECL` |  |
| `UNION_DECL` |  |
| `TRAIT_DECL` |  |
| `ENUM_DECL` |  |
| `FUNC_DECL` |  |
| `TYPEDEF_DECL` |  |
| `NOTE_DECL` |  |
| `PARAM_DECL` |  |
| `NATIVE_DECL` |  |
| `NOTES_DECL` |  |
| `VAR_FIELD_DECL` |  |
| `ENUM_FIELD_ENTRY_DECL` |  |
| `ENUM_FIELD_DECL` |  |
| `STRUCT_FIELD_DECL` |  |
| `UNION_FIELD_DECL` |  |
| `TRAIT_FIELD_DECL` |  |
| `POISON_DECL` |  |
| `BLOCK_STMT` |  |
| `BREAK_STMT` |  |
| `COMP_STMT` |  |
| `CONTINUE_STMT` |  |
| `DEFER_STMT` |  |
| `DO_WHILE_STMT` |  |
| `EMPTY_STMT` |  |
| `FOR_STMT` |  |
| `FUNC_BODY_STMT` |  |
| `GOTO_STMT` |  |
| `IF_STMT` |  |
| `POST_ELSE_STMT` |  |
| `LABEL_STMT` |  |
| `MODULE_STMT` |  |
| `NOTE_STMT` |  |
| `PARAMETERS_STMT` |  |
| `RETURN_STMT` |  |
| `SWITCH_CASE_STMT` |  |
| `SWITCH_STMT` |  |
| `WHILE_STMT` |  |
| `ARRAY_DESIGNATION_EXPR` |  |
| `ARRAY_INIT_EXPR` |  |
| `BINARY_EXPR` |  |
| `BOOLEAN_EXPR` |  |
| `CAST_EXPR` |  |
| `CHAR_EXPR` |  |
| `FUNC_CALL_EXPR` |  |
| `FUNC_IDENTIFIER_EXPR` |  |
| `GET_EXPR` |  |
| `GROUP_EXPR` |  |
| `IDENTIFIER_EXPR` |  |
| `INIT_EXPR` |  |
| `INIT_ARG_EXPR` |  |
| `NULL_EXPR` |  |
| `NUMBER_EXPR` |  |
| `OFFSET_OF_EXPR` |  |
| `SET_EXPR` |  |
| `SIZE_OF_EXPR` |  |
| `STRING_EXPR` |  |
| `NATIVE_STRING_EXPR` |  |
| `SUBSCRIPT_GET_EXPR` |  |
| `SUBSCRIPT_SET_EXPR` |  |
| `TERNARY_EXPR` |  |
| `TYPE_IDENTIFIER_EXPR` |  |
| `TYPE_OF_EXPR` |  |
| `NAME_OF_EXPR` |  |
| `UNARY_EXPR` |  |
| `POISON_EXPR` |  |
| `MAX_STMT_KINDS` |  |

---

<a id="enum-typespeckind"></a>

### enum TypeSpecKind

*public* | *src/ast.lita:93*

| Value | Description |
|-------|-------------|
| `NONE` |  |
| `ARRAY` |  |
| `PTR` |  |
| `CONST` |  |
| `NAME` |  |
| `FUNC_PTR` |  |
| `MAX_TYPESPEC_KINDS` |  |

---

<a id="enum-funcflags"></a>

### enum FuncFlags

*public* | *src/ast.lita:104*

| Value | Description |
|-------|-------------|
| `HAS_VARARGS` |  |
| `IS_METHOD` |  |
| `HAS_NATIVE_VARARGS` |  |

---

<a id="enum-aggregateflags"></a>

### enum AggregateFlags

*public* | *src/ast.lita:110*

| Value | Description |
|-------|-------------|
| `IS_EMBEDDED` |  |
| `IS_ANONYMOUS` |  |

---

<a id="struct-typespec"></a>

### struct TypeSpec

*public* | *src/ast.lita:116*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [TypeSpecKind](ast.md#enum-typespeckind) |  |
| `pos` | [SrcPos](lex.md#struct-srcpos) |  |
| `base` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `typeInfo` | \*[TypeInfo](types.md#struct-typeinfo) |  |

---

<a id="struct-identifier"></a>

### struct Identifier

*public* | *src/ast.lita:144*

| Field | Type | Description |
|-------|------|-------------|
| `str` | [InternedString](intern.md#union-internedstring) |  |
| `token` | [Token](lex.md#struct-token) |  |

---

<a id="struct-genericparam"></a>

### struct GenericParam

*public* | *src/ast.lita:149*

| Field | Type | Description |
|-------|------|-------------|
| `name` | [Identifier](ast.md#struct-identifier) |  |
| `typeConstraint` | \*[TypeSpec](ast.md#struct-typespec) |  |

---

<a id="enum-genericargkind"></a>

### enum GenericArgKind

*public* | *src/ast.lita:154*

| Value | Description |
|-------|-------------|
| `TYPE` |  |

---

<a id="struct-genericarg"></a>

### struct GenericArg

*public* | *src/ast.lita:158*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [GenericArgKind](ast.md#enum-genericargkind) |  |

---

<a id="enum-visibility"></a>

### enum Visibility

*public* | *src/ast.lita:167*

| Value | Description |
|-------|-------------|
| `PRIVATE` |  |
| `INTERNAL` |  |
| `PUBLIC` |  |

---

<a id="struct-attributes"></a>

### struct Attributes

*public* | *src/ast.lita:178*

| Field | Type | Description |
|-------|------|-------------|
| `visibility` | [Visibility](ast.md#enum-visibility) |  |
| `isGlobal` | bool |  |
| `isUsing` | bool |  |
| `isGenerated` | bool |  |
| `notes` | Array\<\*[NoteStmt](ast.md#struct-notestmt)\> |  |

---

<a id="struct-node"></a>

### struct Node

*public* | *src/ast.lita:187*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [StmtKind](ast.md#enum-stmtkind) |  |
| `parent` | \*[Node](ast.md#struct-node) |  |
| `startPos` | [SrcPos](lex.md#struct-srcpos) |  |
| `endPos` | [SrcPos](lex.md#struct-srcpos) |  |

---

<a id="struct-decl"></a>

### struct Decl

*public* | *src/ast.lita:230*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `sym` | \*[Symbol](symbols.md#struct-symbol) |  |
| `name` | [Identifier](ast.md#struct-identifier) |  |
| `attributes` | [Attributes](ast.md#struct-attributes) |  |

---

<a id="struct-genericdecl"></a>

### struct GenericDecl

*public* | *src/ast.lita:237*

| Field | Type | Description |
|-------|------|-------------|
| `declaration` | [Decl](ast.md#struct-decl) |  |
| `genericParams` | Array\<[GenericParam](ast.md#struct-genericparam)\> |  |

---

<a id="struct-importdecl"></a>

### struct ImportDecl

*public* | *src/ast.lita:242*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `alias` | [Identifier](ast.md#struct-identifier) |  |
| `isUsing` | bool |  |
| `moduleId` | \*[ModuleId](module.md#struct-moduleid) |  |

---

<a id="struct-vardecl"></a>

### struct VarDecl

*public* | *src/ast.lita:251*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `typeSpec` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `expr` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-parameterdecl"></a>

### struct ParameterDecl

*public* | *src/ast.lita:257*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `defaultExpr` | \*[Expr](ast.md#struct-expr) |  |
| `typeInfo` | \*[TypeInfo](types.md#struct-typeinfo) |  |

---

<a id="struct-funcdecl"></a>

### struct FuncDecl

*public* | *src/ast.lita:265*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [GenericDecl](ast.md#struct-genericdecl) |  |
| `params` | \*[ParametersStmt](ast.md#struct-parametersstmt) |  |
| `body` | \*[Stmt](ast.md#struct-stmt) |  |
| `returnType` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `flags` | i32 |  |

---

<a id="struct-aggregatedecl"></a>

### struct AggregateDecl

*public* | *src/ast.lita:273*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [GenericDecl](ast.md#struct-genericdecl) |  |
| `fields` | Array\<[FieldStmt](ast.md#struct-fieldstmt)\> |  |
| `flags` | i32 |  |

---

<a id="struct-enumdecl"></a>

### struct EnumDecl

*public* | *src/ast.lita:279*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `fields` | Array\<\*[EnumFieldEntryDecl](ast.md#struct-enumfieldentrydecl)\> |  |

---

<a id="struct-typedefdecl"></a>

### struct TypedefDecl

*public* | *src/ast.lita:284*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [GenericDecl](ast.md#struct-genericdecl) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |

---

<a id="struct-nativedecl"></a>

### struct NativeDecl

*public* | *src/ast.lita:289*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `typeInfo` | \*[TypeInfo](types.md#struct-typeinfo) |  |

---

<a id="struct-notesdecl"></a>

### struct NotesDecl

*public* | *src/ast.lita:294*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `notes` | Array\<\*[NoteStmt](ast.md#struct-notestmt)\> |  |

---

<a id="struct-poisondecl"></a>

### struct PoisonDecl

*public* | *src/ast.lita:299*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |

---

<a id="struct-blockstmt"></a>

### struct BlockStmt

*public* | *src/ast.lita:303*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `stmts` | Array\<\*[Stmt](ast.md#struct-stmt)\> |  |

---

<a id="struct-breakstmt"></a>

### struct BreakStmt

*public* | *src/ast.lita:308*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-compstmt"></a>

### struct CompStmt

*public* | *src/ast.lita:312*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `type` | [InternedString](intern.md#union-internedstring) |  |
| `expr` | String |  |
| `end` | \*[CompStmt](ast.md#struct-compstmt) |  |
| `evaluatedStmt` | \*[Stmt](ast.md#struct-stmt) |  |
| `body` | Array\<\*[Stmt](ast.md#struct-stmt)\> |  |
| `isScriptLoad` | bool |  |
| `isStatic` | bool |  |

---

<a id="struct-continuestmt"></a>

### struct ContinueStmt

*public* | *src/ast.lita:323*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-deferstmt"></a>

### struct DeferStmt

*public* | *src/ast.lita:327*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `deferedStmt` | \*[Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-dowhilestmt"></a>

### struct DoWhileStmt

*public* | *src/ast.lita:332*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `cond` | \*[Expr](ast.md#struct-expr) |  |
| `body` | \*[Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-emptystmt"></a>

### struct EmptyStmt

*public* | *src/ast.lita:338*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-enumfieldentrydecl"></a>

### struct EnumFieldEntryDecl

*public* | *src/ast.lita:342*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `value` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-forstmt"></a>

### struct ForStmt

*public* | *src/ast.lita:347*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `init` | \*[Stmt](ast.md#struct-stmt) |  |
| `cond` | \*[Expr](ast.md#struct-expr) |  |
| `post` | \*[Stmt](ast.md#struct-stmt) |  |
| `body` | \*[Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-funcbodystmt"></a>

### struct FuncBodyStmt

*public* | *src/ast.lita:355*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `stmts` | Array\<\*[Stmt](ast.md#struct-stmt)\> |  |

---

<a id="struct-gotostmt"></a>

### struct GotoStmt

*public* | *src/ast.lita:360*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `label` | [Identifier](ast.md#struct-identifier) |  |

---

<a id="struct-ifstmt"></a>

### struct IfStmt

*public* | *src/ast.lita:365*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `cond` | \*[Expr](ast.md#struct-expr) |  |
| `then` | \*[Stmt](ast.md#struct-stmt) |  |
| `elseStmt` | \*[Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-postelsestmt"></a>

### struct PostElseStmt

*public* | *src/ast.lita:372*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `cond` | \*[Stmt](ast.md#struct-stmt) |  |
| `post` | \*[Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-labelstmt"></a>

### struct LabelStmt

*public* | *src/ast.lita:378*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `label` | [Identifier](ast.md#struct-identifier) |  |

---

<a id="struct-modulestmt"></a>

### struct ModuleStmt

*public* | *src/ast.lita:384*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `imports` | Array\<\*[ImportDecl](ast.md#struct-importdecl)\> |  |
| `notes` | Array\<\*[NoteStmt](ast.md#struct-notestmt)\> |  |
| `declarations` | Array\<\*[Decl](ast.md#struct-decl)\> |  |

---

<a id="struct-notestmt"></a>

### struct NoteStmt

*public* | *src/ast.lita:392*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `arguments` | Array\<[CallArg](ast.md#struct-callarg)\> |  |

---

<a id="struct-parametersstmt"></a>

### struct ParametersStmt

*public* | *src/ast.lita:398*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `params` | Array\<\*[ParameterDecl](ast.md#struct-parameterdecl)\> |  |
| `isVararg` | bool |  |
| `isNativeVararg` | bool |  |

---

<a id="struct-returnstmt"></a>

### struct ReturnStmt

*public* | *src/ast.lita:405*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `expr` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-switchcasestmt"></a>

### struct SwitchCaseStmt

*public* | *src/ast.lita:410*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `cond` | \*[Expr](ast.md#struct-expr) |  |
| `body` | \*[Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-switchstmt"></a>

### struct SwitchStmt

*public* | *src/ast.lita:416*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `cond` | \*[Expr](ast.md#struct-expr) |  |
| `cases` | Array\<\*[SwitchCaseStmt](ast.md#struct-switchcasestmt)\> |  |
| `defaultStmt` | \*[Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-varfielddecl"></a>

### struct VarFieldDecl

*public* | *src/ast.lita:423*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `defaultExpr` | \*[Expr](ast.md#struct-expr) |  |
| `bitFieldExpr` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-traitfielddecl"></a>

### struct TraitFieldDecl

*public* | *src/ast.lita:430*

| Field | Type | Description |
|-------|------|-------------|
| `decl` | [Decl](ast.md#struct-decl) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |

---

<a id="struct-fieldstmt"></a>

### struct FieldStmt

*public* | *src/ast.lita:435*

| Field | Type | Description |
|-------|------|-------------|
| `kind` | [StmtKind](ast.md#enum-stmtkind) |  |
| `typeInfo` | \*[TypeInfo](types.md#struct-typeinfo) |  |

---

<a id="struct-whilestmt"></a>

### struct WhileStmt

*public* | *src/ast.lita:447*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `cond` | \*[Expr](ast.md#struct-expr) |  |
| `body` | \*[Stmt](ast.md#struct-stmt) |  |

---

<a id="struct-stmt"></a>

### struct Stmt

*public* | *src/ast.lita:454*

| Field | Type | Description |
|-------|------|-------------|
| `node` | [Node](ast.md#struct-node) |  |

---

<a id="struct-arraydesignationexpr"></a>

### struct ArrayDesignationExpr

*public* | *src/ast.lita:458*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `index` | \*[Expr](ast.md#struct-expr) |  |
| `value` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-arrayinitexpr"></a>

### struct ArrayInitExpr

*public* | *src/ast.lita:464*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `values` | Array\<\*[Expr](ast.md#struct-expr)\> |  |

---

<a id="struct-binaryexpr"></a>

### struct BinaryExpr

*public* | *src/ast.lita:470*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `left` | \*[Expr](ast.md#struct-expr) |  |
| `operator` | [TokenType](lex.md#enum-tokentype) |  |
| `right` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-booleanexpr"></a>

### struct BooleanExpr

*public* | *src/ast.lita:477*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `boolean` | bool |  |

---

<a id="struct-castexpr"></a>

### struct CastExpr

*public* | *src/ast.lita:482*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `castTo` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `exprToCast` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-charexpr"></a>

### struct CharExpr

*public* | *src/ast.lita:488*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `character` | [Token](lex.md#struct-token) |  |

---

<a id="struct-callarg"></a>

### struct CallArg

*public* | *src/ast.lita:493*

| Field | Type | Description |
|-------|------|-------------|
| `argExpr` | \*[Expr](ast.md#struct-expr) |  |
| `argName` | [Identifier](ast.md#struct-identifier) |  |
| `index` | i32 |  |
| `isDefault` | bool |  |

---

<a id="struct-funccallexpr"></a>

### struct FuncCallExpr

*public* | *src/ast.lita:500*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `object` | \*[Expr](ast.md#struct-expr) |  |
| `genericArgs` | Array\<[GenericArg](ast.md#struct-genericarg)\> |  |
| `arguments` | Array\<[CallArg](ast.md#struct-callarg)\> |  |
| `flags` | i32 |  |

---

<a id="enum-funccallexprflags"></a>

### enum FuncCallExprFlags

*public* | *src/ast.lita:508*

| Value | Description |
|-------|-------------|
| `HAS_NATIVE_VARARG` |  |

---

<a id="enum-getexprflags"></a>

### enum GetExprFlags

*public* | *src/ast.lita:512*

| Value | Description |
|-------|-------------|
| `IS_NORMAL` |  |
| `IS_METHOD_CALL` |  |
| `IS_ENUM` |  |
| `IS_USING` |  |
| `IS_METHOD_ARG` |  |

---

<a id="struct-getexpr"></a>

### struct GetExpr

*public* | *src/ast.lita:520*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `object` | \*[Expr](ast.md#struct-expr) |  |
| `field` | \*[IdentifierExpr](ast.md#struct-identifierexpr) |  |
| `flags` | i32 |  |

---

<a id="struct-groupexpr"></a>

### struct GroupExpr

*public* | *src/ast.lita:527*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `groupedExpr` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-identifierexpr"></a>

### struct IdentifierExpr

*public* | *src/ast.lita:532*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `sym` | \*[Symbol](symbols.md#struct-symbol) |  |

---

<a id="struct-initargexpr"></a>

### struct InitArgExpr

*public* | *src/ast.lita:539*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `fieldName` | [Identifier](ast.md#struct-identifier) |  |
| `argPosition` | i32 |  |
| `value` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-initexpr"></a>

### struct InitExpr

*public* | *src/ast.lita:546*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `genericArgs` | Array\<[GenericArg](ast.md#struct-genericarg)\> |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `arguments` | Array\<\*[InitArgExpr](ast.md#struct-initargexpr)\> |  |

---

<a id="struct-nullexpr"></a>

### struct NullExpr

*public* | *src/ast.lita:553*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |

---

<a id="struct-numberexpr"></a>

### struct NumberExpr

*public* | *src/ast.lita:557*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `number` | [Token](lex.md#struct-token) |  |

---

<a id="struct-offsetofexpr"></a>

### struct OffsetOfExpr

*public* | *src/ast.lita:562*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `field` | [Identifier](ast.md#struct-identifier) |  |

---

<a id="struct-setexpr"></a>

### struct SetExpr

*public* | *src/ast.lita:568*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `object` | \*[Expr](ast.md#struct-expr) |  |
| `field` | \*[IdentifierExpr](ast.md#struct-identifierexpr) |  |
| `operator` | [TokenType](lex.md#enum-tokentype) |  |
| `value` | \*[Expr](ast.md#struct-expr) |  |
| `flags` | i32 |  |

---

<a id="struct-sizeofexpr"></a>

### struct SizeOfExpr

*public* | *src/ast.lita:577*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `sizeOfExpr` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-stringexpr"></a>

### struct StringExpr

*public* | *src/ast.lita:582*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `string` | [Token](lex.md#struct-token) |  |

---

<a id="struct-subscriptgetexpr"></a>

### struct SubscriptGetExpr

*public* | *src/ast.lita:587*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `object` | \*[Expr](ast.md#struct-expr) |  |
| `index` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-subscriptsetexpr"></a>

### struct SubscriptSetExpr

*public* | *src/ast.lita:593*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `object` | \*[Expr](ast.md#struct-expr) |  |
| `index` | \*[Expr](ast.md#struct-expr) |  |
| `operator` | [TokenType](lex.md#enum-tokentype) |  |
| `value` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-ternaryexpr"></a>

### struct TernaryExpr

*public* | *src/ast.lita:601*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `cond` | \*[Expr](ast.md#struct-expr) |  |
| `then` | \*[Expr](ast.md#struct-expr) |  |
| `other` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-typeidentifierexpr"></a>

### struct TypeIdentifierExpr

*public* | *src/ast.lita:608*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |
| `sym` | \*[Symbol](symbols.md#struct-symbol) |  |
| `isBased` | bool |  |

---

<a id="struct-typeofexpr"></a>

### struct TypeOfExpr

*public* | *src/ast.lita:616*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `typeOfExpr` | \*[Expr](ast.md#struct-expr) |  |
| `type` | \*[TypeSpec](ast.md#struct-typespec) |  |

---

<a id="struct-unaryexpr"></a>

### struct UnaryExpr

*public* | *src/ast.lita:622*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |
| `operator` | [TokenType](lex.md#enum-tokentype) |  |
| `unaryExpr` | \*[Expr](ast.md#struct-expr) |  |

---

<a id="struct-poisonexpr"></a>

### struct PoisonExpr

*public* | *src/ast.lita:628*

| Field | Type | Description |
|-------|------|-------------|
| `expr` | [Expr](ast.md#struct-expr) |  |

---

<a id="struct-expr"></a>

### struct Expr

*public* | *src/ast.lita:632*

| Field | Type | Description |
|-------|------|-------------|
| `stmt` | [Stmt](ast.md#struct-stmt) |  |
| `operand` | [Operand](ast.md#struct-operand) |  |
| `expectedType` | \*[TypeInfo](types.md#struct-typeinfo) |  |

---

<a id="struct-operand"></a>

### struct Operand

*public* | *src/ast.lita:638*

| Field | Type | Description |
|-------|------|-------------|
| `typeInfo` | \*[TypeInfo](types.md#struct-typeinfo) |  |
| `isRightValue` | bool |  |
| `isConst` | bool |  |
| `val` | [Value](lex.md#union-value) |  |

---

