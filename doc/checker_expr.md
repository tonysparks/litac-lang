# checker_expr

## Functions

<a id="func-resolveconstexpr"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) resolveConstExpr(expr: \*[Expr](ast.md#struct-expr)) : bool

*public* | *src/checker_expr.lita:27*

---

<a id="func-resolveexpr"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) resolveExpr(expr: \*[Expr](ast.md#struct-expr)) : bool

*public* | *src/checker_expr.lita:39*

---

<a id="func-coercetypewithusing"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) coerceTypeWithUsing(expr: \*[Expr](ast.md#struct-expr), sourceType: \*[TypeInfo](types.md#struct-typeinfo), targetType: \*[TypeInfo](types.md#struct-typeinfo)) : \*[Expr](ast.md#struct-expr)

*public* | *src/checker_expr.lita:192*

---

<a id="func-errornofield"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) errorNoField(expr: \*[Expr](ast.md#struct-expr), type: \*[TypeInfo](types.md#struct-typeinfo), field: [InternedString](intern.md#union-internedstring)) : void

*public* | *src/checker_expr.lita:2371*

---

<a id="func-checktruthyness"></a>

### func (this: \*[TypeChecker](checker.md#struct-typechecker)) checkTruthyness(expr: \*[Expr](ast.md#struct-expr), type: \*[TypeInfo](types.md#struct-typeinfo)) : bool

*internal* | *src/checker_expr.lita:2532*

---

