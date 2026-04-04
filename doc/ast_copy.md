# ast_copy

## Functions

<a id="func-newtokennameintern"></a>

### func NewTokenNameIntern(token: [Token](lex.md#struct-token), strings: \*[Strings](intern.md#struct-strings)) : [InternedString](intern.md#union-internedstring)

*public* | *src/ast_copy.lita:21*

---

<a id="func-copygenericargs"></a>

### func CopyGenericArgs(args: Array\<[GenericArg](ast.md#struct-genericarg)\>, module: \*[Module](module.md#struct-module)) : Array\<[GenericArg](ast.md#struct-genericarg)\>

*public* | *src/ast_copy.lita:30*

---

<a id="func-copytypespecs"></a>

### func CopyTypeSpecs(specs: Array\<\*[TypeSpec](ast.md#struct-typespec)\>, module: \*[Module](module.md#struct-module)) : Array\<\*[TypeSpec](ast.md#struct-typespec)\>

*public* | *src/ast_copy.lita:55*

---

<a id="func-copytypespec"></a>

### func CopyTypeSpec(spec: \*[TypeSpec](ast.md#struct-typespec), module: \*[Module](module.md#struct-module)) : \*[TypeSpec](ast.md#struct-typespec)

*public* | *src/ast_copy.lita:73*

---

<a id="func-copydecl"></a>

### func CopyDecl(decl: \*[Decl](ast.md#struct-decl), module: \*[Module](module.md#struct-module)) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_copy.lita:126*

---

<a id="func-copycallargs"></a>

### func CopyCallArgs(args: \*Array\<[CallArg](ast.md#struct-callarg)\>, module: \*[Module](module.md#struct-module)) : Array\<[CallArg](ast.md#struct-callarg)\>

*public* | *src/ast_copy.lita:182*

---

<a id="func-copyexprs"></a>

### func CopyExprs(exprs: \*Array\<\*[Expr](ast.md#struct-expr)\>, module: \*[Module](module.md#struct-module)) : Array\<\*[Expr](ast.md#struct-expr)\>

*public* | *src/ast_copy.lita:199*

---

<a id="func-copystmts"></a>

### func CopyStmts(stmts: \*Array\<\*[Stmt](ast.md#struct-stmt)\>, module: \*[Module](module.md#struct-module)) : Array\<\*[Stmt](ast.md#struct-stmt)\>

*public* | *src/ast_copy.lita:212*

---

<a id="func-copyexpr"></a>

### func CopyExpr(expr: \*[Expr](ast.md#struct-expr), module: \*[Module](module.md#struct-module)) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_copy.lita:226*

---

<a id="func-copystmt"></a>

### func CopyStmt(stmt: \*[Stmt](ast.md#struct-stmt), module: \*[Module](module.md#struct-module)) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_copy.lita:460*

---

<a id="func-copyaggregatedecl"></a>

### func CopyAggregateDecl(decl: \*[AggregateDecl](ast.md#struct-aggregatedecl), module: \*[Module](module.md#struct-module)) : \*[AggregateDecl](ast.md#struct-aggregatedecl)

*public* | *src/ast_copy.lita:656*

---

<a id="func-copyfuncdecl"></a>

### func CopyFuncDecl(decl: \*[FuncDecl](ast.md#struct-funcdecl), module: \*[Module](module.md#struct-module)) : \*[FuncDecl](ast.md#struct-funcdecl)

*public* | *src/ast_copy.lita:740*

---

<a id="func-copyparameters"></a>

### func CopyParameters(params: [ParametersStmt](ast.md#struct-parametersstmt), module: \*[Module](module.md#struct-module)) : \*[ParametersStmt](ast.md#struct-parametersstmt)

*public* | *src/ast_copy.lita:754*

---

<a id="func-copytypedefdecl"></a>

### func CopyTypedefDecl(decl: \*[TypedefDecl](ast.md#struct-typedefdecl), module: \*[Module](module.md#struct-module)) : \*[TypedefDecl](ast.md#struct-typedefdecl)

*public* | *src/ast_copy.lita:781*

---

<a id="func-astinserttext"></a>

### func AstInsertText(node: \*[Node](ast.md#struct-node), text: \*const char, index: i32, module: \*[Module](module.md#struct-module), lita: \*[Lita](lita.md#struct-lita)) : void

*public* | *src/ast_copy.lita:792*

---

<a id="func-astinsert"></a>

### func AstInsert(node: \*[Node](ast.md#struct-node), stmt: \*[Stmt](ast.md#struct-stmt), index: i32, module: \*[Module](module.md#struct-module), lita: \*[Lita](lita.md#struct-lita)) : void

*public* | *src/ast_copy.lita:806*


    Inserts a stmt inside another AstNode.

    Right now only FuncDecl is supported.


---

<a id="func-astaddimport"></a>

### func AstAddImport(lita: \*[Lita](lita.md#struct-lita), checker: \*[TypeChecker](checker.md#struct-typechecker), module: \*[Module](module.md#struct-module), importModule: \*[Module](module.md#struct-module)) : \*const char

*public* | *src/ast_copy.lita:849*

---

