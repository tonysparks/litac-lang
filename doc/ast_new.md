# ast_new

## Functions

<a id="func-init"></a>

### func (this: \*[TypeSpecAllocator](ast_new.md#struct-typespecallocator)) init(allocator: \*const Allocator) : void

*public* | *src/ast_new.lita:22*

---

<a id="func-free"></a>

### func (this: \*[TypeSpecAllocator](ast_new.md#struct-typespecallocator)) free() : void

*public* | *src/ast_new.lita:27*

---

<a id="func-clear"></a>

### func (this: \*[TypeSpecAllocator](ast_new.md#struct-typespecallocator)) clear() : void

*public* | *src/ast_new.lita:31*

---

<a id="func-alloc"></a>

### func (this: \*[TypeSpecAllocator](ast_new.md#struct-typespecallocator)) alloc() : \*[TypeSpec](ast.md#struct-typespec)

*public* | *src/ast_new.lita:35*

---

<a id="func-newvoidtypespec"></a>

### func NewVoidTypeSpec(pos: [SrcPos](lex.md#struct-srcpos), typeAllocator: \*[TypeSpecAllocator](ast_new.md#struct-typespecallocator)) : \*[TypeSpec](ast.md#struct-typespec)

*public* | *src/ast_new.lita:41*

---

<a id="func-newnametypespecintern"></a>

### func NewNameTypeSpecIntern(pos: [SrcPos](lex.md#struct-srcpos), name: [InternedString](intern.md#union-internedstring), typeAllocator: \*[TypeSpecAllocator](ast_new.md#struct-typespecallocator)) : \*[TypeSpec](ast.md#struct-typespec)

*public* | *src/ast_new.lita:47*

---

<a id="func-newtypespec"></a>

### func NewTypeSpec(kind: [TypeSpecKind](ast.md#enum-typespeckind), pos: [SrcPos](lex.md#struct-srcpos), typeAllocator: \*[TypeSpecAllocator](ast_new.md#struct-typespecallocator)) : \*[TypeSpec](ast.md#struct-typespec)

*public* | *src/ast_new.lita:57*

---

<a id="func-newidentifier"></a>

### func NewIdentifier(name: \*const char, pos: [SrcPos](lex.md#struct-srcpos), strings: \*[Strings](intern.md#struct-strings)) : [Identifier](ast.md#struct-identifier)

*public* | *src/ast_new.lita:116*

---

<a id="func-newimportdecl"></a>

### func NewImportDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), alias: [Identifier](ast.md#struct-identifier), isUsing: bool, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:135*

---

<a id="func-newvardecl"></a>

### func NewVarDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), type: \*[TypeSpec](ast.md#struct-typespec), expr: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:152*

---

<a id="func-newfuncdecl"></a>

### func NewFuncDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), genericParams: Array\<[GenericParam](ast.md#struct-genericparam)\>, params: \*[ParametersStmt](ast.md#struct-parametersstmt), body: \*[Stmt](ast.md#struct-stmt), returnType: \*[TypeSpec](ast.md#struct-typespec), flags: i32, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:169*

---

<a id="func-newaggregatedecl"></a>

### func NewAggregateDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), kind: [StmtKind](ast.md#enum-stmtkind), name: [Identifier](ast.md#struct-identifier), genericParams: Array\<[GenericParam](ast.md#struct-genericparam)\>, fields: Array\<[FieldStmt](ast.md#struct-fieldstmt)\>, flags: i32, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:192*

---

<a id="func-newstructdecl"></a>

### func NewStructDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), genericParams: Array\<[GenericParam](ast.md#struct-genericparam)\>, fields: Array\<[FieldStmt](ast.md#struct-fieldstmt)\>, flags: i32, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:242*

---

<a id="func-newuniondecl"></a>

### func NewUnionDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), genericParams: Array\<[GenericParam](ast.md#struct-genericparam)\>, fields: Array\<[FieldStmt](ast.md#struct-fieldstmt)\>, flags: i32, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:253*

---

<a id="func-newtraitdecl"></a>

### func NewTraitDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), genericParams: Array\<[GenericParam](ast.md#struct-genericparam)\>, fields: Array\<[FieldStmt](ast.md#struct-fieldstmt)\>, flags: i32, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:265*

---

<a id="func-newenumdecl"></a>

### func NewEnumDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), fields: Array\<\*[EnumFieldEntryDecl](ast.md#struct-enumfieldentrydecl)\>, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:277*

---

<a id="func-newtypedefdecl"></a>

### func NewTypedefDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), genericParams: Array\<[GenericParam](ast.md#struct-genericparam)\>, type: \*[TypeSpec](ast.md#struct-typespec), allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:292*

---

<a id="func-newnotedecl"></a>

### func NewNoteDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), fields: Array\<[FieldStmt](ast.md#struct-fieldstmt)\>, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:310*

---

<a id="func-newparameterdecl"></a>

### func NewParameterDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), name: [Identifier](ast.md#struct-identifier), type: \*[TypeSpec](ast.md#struct-typespec), defaultExpr: \*[Expr](ast.md#struct-expr), isUsing: bool, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:320*

---

<a id="func-newnotesdecl"></a>

### func NewNotesDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), notes: Array\<\*[NoteStmt](ast.md#struct-notestmt)\>, allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:339*

---

<a id="func-newbuiltindecl"></a>

### func NewBuiltinDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), type: \*[TypeInfo](types.md#struct-typeinfo), allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:351*

---

<a id="func-newpoisondecl"></a>

### func NewPoisonDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), allocator: \*const Allocator) : \*[Decl](ast.md#struct-decl)

*public* | *src/ast_new.lita:363*

---

<a id="func-newternaryexpr"></a>

### func NewTernaryExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), cond: \*[Expr](ast.md#struct-expr), then: \*[Expr](ast.md#struct-expr), other: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:373*

---

<a id="func-newbinaryexpr"></a>

### func NewBinaryExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), left: \*[Expr](ast.md#struct-expr), operator: [TokenType](lex.md#enum-tokentype), right: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:390*

---

<a id="func-newunaryexpr"></a>

### func NewUnaryExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), operator: [TokenType](lex.md#enum-tokentype), expr: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:407*

---

<a id="func-newinitexpr"></a>

### func NewInitExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), type: \*[TypeSpec](ast.md#struct-typespec), arguments: Array\<\*[InitArgExpr](ast.md#struct-initargexpr)\>, allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:422*

---

<a id="func-newfunccallexpr"></a>

### func NewFuncCallExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), object: \*[Expr](ast.md#struct-expr), arguments: Array\<[CallArg](ast.md#struct-callarg)\>, genericArgs: Array\<[GenericArg](ast.md#struct-genericarg)\>, allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:438*

---

<a id="func-newsubscriptgetexpr"></a>

### func NewSubscriptGetExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), object: \*[Expr](ast.md#struct-expr), index: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:457*

---

<a id="func-newsubscriptsetexpr"></a>

### func NewSubscriptSetExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), object: \*[Expr](ast.md#struct-expr), index: \*[Expr](ast.md#struct-expr), operator: [TokenType](lex.md#enum-tokentype), value: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:472*

---

<a id="func-newgetexpr"></a>

### func NewGetExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), object: \*[Expr](ast.md#struct-expr), field: \*[IdentifierExpr](ast.md#struct-identifierexpr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:491*

---

<a id="func-newsetexpr"></a>

### func NewSetExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), object: \*[Expr](ast.md#struct-expr), field: \*[IdentifierExpr](ast.md#struct-identifierexpr), operator: [TokenType](lex.md#enum-tokentype), value: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:506*

---

<a id="func-newidentifierexpr"></a>

### func NewIdentifierExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), type: \*[TypeSpec](ast.md#struct-typespec), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:525*

---

<a id="func-newtypeidentifierexpr"></a>

### func NewTypeIdentifierExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), type: \*[TypeSpec](ast.md#struct-typespec), isBased: bool, allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:538*

---

<a id="func-newcastexpr"></a>

### func NewCastExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), castExpr: \*[Expr](ast.md#struct-expr), castTo: \*[TypeSpec](ast.md#struct-typespec), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:553*

---

<a id="func-newarraydesignationexpr"></a>

### func NewArrayDesignationExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), index: \*[Expr](ast.md#struct-expr), value: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:568*

---

<a id="func-newinitargexpr"></a>

### func NewInitArgExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), fieldName: [Identifier](ast.md#struct-identifier), position: i32, value: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:583*

---

<a id="func-newbooleanexpr"></a>

### func NewBooleanExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), boolean: bool, allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:600*

---

<a id="func-newnullexpr"></a>

### func NewNullExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:612*

---

<a id="func-newnumberexpr"></a>

### func NewNumberExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), number: [Token](lex.md#struct-token), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:622*

---

<a id="func-newstringexpr"></a>

### func NewStringExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), string: [Token](lex.md#struct-token), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:634*

---

<a id="func-newnativestringexpr"></a>

### func NewNativeStringExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), string: [Token](lex.md#struct-token), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:646*

---

<a id="func-newcharexpr"></a>

### func NewCharExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), character: [Token](lex.md#struct-token), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:658*

---

<a id="func-newgroupexpr"></a>

### func NewGroupExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), groupedExpr: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:670*

---

<a id="func-newarrayinitexpr"></a>

### func NewArrayInitExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), type: \*[TypeSpec](ast.md#struct-typespec), values: Array\<\*[Expr](ast.md#struct-expr)\>, allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:683*

---

<a id="func-newsizeofexpr"></a>

### func NewSizeOfExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), sizeOfExpr: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:715*

---

<a id="func-newtypeofexpr"></a>

### func NewTypeOfExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), typeOfExpr: \*[Expr](ast.md#struct-expr), type: \*[TypeSpec](ast.md#struct-typespec), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:729*

---

<a id="func-newnameofexpr"></a>

### func NewNameOfExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), typeOfExpr: \*[Expr](ast.md#struct-expr), type: \*[TypeSpec](ast.md#struct-typespec), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:744*

---

<a id="func-newoffsetofexpr"></a>

### func NewOffsetOfExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), type: \*[TypeSpec](ast.md#struct-typespec), field: [Identifier](ast.md#struct-identifier), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:759*

---

<a id="func-newpoisonexpr"></a>

### func NewPoisonExpr(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), allocator: \*const Allocator) : \*[Expr](ast.md#struct-expr)

*public* | *src/ast_new.lita:774*

---

<a id="func-newmodulestmt"></a>

### func NewModuleStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), imports: Array\<\*[ImportDecl](ast.md#struct-importdecl)\>, notes: Array\<\*[NoteStmt](ast.md#struct-notestmt)\>, declarations: Array\<\*[Decl](ast.md#struct-decl)\>, allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:784*

---

<a id="func-newcompstmt"></a>

### func NewCompStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), type: [InternedString](intern.md#union-internedstring), expr: String, body: Array\<\*[Stmt](ast.md#struct-stmt)\>, end: \*[CompStmt](ast.md#struct-compstmt), isScriptLoad: bool, isStatic: bool, allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:800*

---

<a id="func-newfuncbodystmt"></a>

### func NewFuncBodyStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), stmts: Array\<\*[Stmt](ast.md#struct-stmt)\>, allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:823*

---

<a id="func-newblockstmt"></a>

### func NewBlockStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), stmts: Array\<\*[Stmt](ast.md#struct-stmt)\>, allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:836*

---

<a id="func-newifstmt"></a>

### func NewIfStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), cond: \*[Expr](ast.md#struct-expr), then: \*[Stmt](ast.md#struct-stmt), other: \*[Stmt](ast.md#struct-stmt), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:848*

---

<a id="func-newpostelsestmt"></a>

### func NewPostElseStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), cond: \*[Stmt](ast.md#struct-stmt), post: \*[Stmt](ast.md#struct-stmt), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:864*

---

<a id="func-newwhilestmt"></a>

### func NewWhileStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), cond: \*[Expr](ast.md#struct-expr), body: \*[Stmt](ast.md#struct-stmt), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:881*

---

<a id="func-newdowhilestmt"></a>

### func NewDoWhileStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), cond: \*[Expr](ast.md#struct-expr), body: \*[Stmt](ast.md#struct-stmt), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:895*

---

<a id="func-newforstmt"></a>

### func NewForStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), init: \*[Stmt](ast.md#struct-stmt), cond: \*[Expr](ast.md#struct-expr), post: \*[Stmt](ast.md#struct-stmt), body: \*[Stmt](ast.md#struct-stmt), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:909*

---

<a id="func-newswitchcasestmt"></a>

### func NewSwitchCaseStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), cond: \*[Expr](ast.md#struct-expr), body: \*[Stmt](ast.md#struct-stmt), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:927*

---

<a id="func-newswitchstmt"></a>

### func NewSwitchStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), cond: \*[Expr](ast.md#struct-expr), cases: Array\<\*[SwitchCaseStmt](ast.md#struct-switchcasestmt)\>, defaultStmt: \*[Stmt](ast.md#struct-stmt), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:941*

---

<a id="func-newbreakstmt"></a>

### func NewBreakStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:957*

---

<a id="func-newcontinuestmt"></a>

### func NewContinueStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:967*

---

<a id="func-newreturnstmt"></a>

### func NewReturnStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), expr: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:977*

---

<a id="func-newdeferstmt"></a>

### func NewDeferStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), defered: \*[Stmt](ast.md#struct-stmt), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:989*

---

<a id="func-newgotostmt"></a>

### func NewGotoStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), label: [Identifier](ast.md#struct-identifier), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:1001*

---

<a id="func-newlabelstmt"></a>

### func NewLabelStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), label: [Identifier](ast.md#struct-identifier), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:1013*

---

<a id="func-newnotestmt"></a>

### func NewNoteStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), type: \*[TypeSpec](ast.md#struct-typespec), arguments: Array\<[CallArg](ast.md#struct-callarg)\>, allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:1025*

---

<a id="func-newemptystmt"></a>

### func NewEmptyStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:1039*

---

<a id="func-newparametersstmt"></a>

### func NewParametersStmt(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), params: Array\<\*[ParameterDecl](ast.md#struct-parameterdecl)\>, isVararg: bool, isNativeVararg: bool, allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:1049*

---

<a id="func-newvarfielddecl"></a>

### func NewVarFieldDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), fieldName: [Identifier](ast.md#struct-identifier), type: \*[TypeSpec](ast.md#struct-typespec), attributes: [Attributes](ast.md#struct-attributes), defaultExpr: \*[Expr](ast.md#struct-expr), bitFieldExpr: \*[Expr](ast.md#struct-expr), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:1066*

---

<a id="func-newtraitfielddecl"></a>

### func NewTraitFieldDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), fieldName: [Identifier](ast.md#struct-identifier), type: \*[TypeSpec](ast.md#struct-typespec), attributes: [Attributes](ast.md#struct-attributes), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:1086*

---

<a id="func-newenumfieldentrydecl"></a>

### func NewEnumFieldEntryDecl(startPos: [SrcPos](lex.md#struct-srcpos), endPos: [SrcPos](lex.md#struct-srcpos), fieldName: [Identifier](ast.md#struct-identifier), value: \*[Expr](ast.md#struct-expr), attributes: [Attributes](ast.md#struct-attributes), allocator: \*const Allocator) : \*[Stmt](ast.md#struct-stmt)

*public* | *src/ast_new.lita:1103*

---

## Types

<a id="struct-typespecallocator"></a>

### struct TypeSpecAllocator

*public* | *src/ast_new.lita:17*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `typeSpecs` | BucketList\<[TypeSpec](ast.md#struct-typespec)\> |  |

---

