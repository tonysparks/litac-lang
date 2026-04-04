# lex

## Functions

<a id="func-nameequals"></a>

### func nameEquals(token: \*[Token](lex.md#struct-token), str: \*const char) : bool

*public* | *src/lex.lita:488*

---

<a id="func-getlinelength"></a>

### func getLineLength(p: \*[SrcPos](lex.md#struct-srcpos)) : i32

*public* | *src/lex.lita:496*

---

<a id="func-asstring"></a>

### func asString(t: \*[Token](lex.md#struct-token)) : \*const char

*public* | *src/lex.lita:515*


There be dragons -- Uses a static buffer internally; do
not free this memory and do not rely on the memory being
correct for very long


---

<a id="func-print"></a>

### func print(token: \*[Token](lex.md#struct-token)) : void

*public* | *src/lex.lita:525*

---

<a id="func-lexerinit"></a>

### func LexerInit(filename: \*const char, text: \*const char, length: i64, allocator: \*const Allocator) : [Lexer](lex.md#struct-lexer)

*public* | *src/lex.lita:559*

---

<a id="func-haserror"></a>

### func hasError(l: \*[Lexer](lex.md#struct-lexer)) : bool

*public* | *src/lex.lita:583*

---

<a id="func-eoftoken"></a>

### func eofToken(l: \*[Lexer](lex.md#struct-lexer)) : [Token](lex.md#struct-token)

*public* | *src/lex.lita:631*

---

<a id="func-eof"></a>

### func eof(l: \*[Lexer](lex.md#struct-lexer)) : bool

*public* | *src/lex.lita:1553*

---

<a id="func-nexttoken"></a>

### func nextToken(l: \*[Lexer](lex.md#struct-lexer)) : [Token](lex.md#struct-token)

*public* | *src/lex.lita:1558*

---

## Types

<a id="enum-tokentype"></a>

### enum TokenType

*public* | *src/lex.lita:17*

| Value | Description |
|-------|-------------|
| `IMPORT` |  |
| `STRUCT` |  |
| `UNION` |  |
| `TRAIT` |  |
| `ENUM` |  |
| `FUNC` |  |
| `TYPEDEF` |  |
| `NOTE` |  |
| `VAR` |  |
| `CONST` |  |
| `NULL` |  |
| `VOID` |  |
| `TRUE` |  |
| `FALSE` |  |
| `BOOL` |  |
| `CHAR` |  |
| `I8` |  |
| `U8` |  |
| `I16` |  |
| `U16` |  |
| `I32` |  |
| `U32` |  |
| `I64` |  |
| `U64` |  |
| `F32` |  |
| `F64` |  |
| `USIZE` |  |
| `FOR` |  |
| `WHILE` |  |
| `DO` |  |
| `IF` |  |
| `ELSE` |  |
| `SWITCH` |  |
| `CASE` |  |
| `DEFAULT` |  |
| `DEFER` |  |
| `BREAK` |  |
| `CONTINUE` |  |
| `RETURN` |  |
| `GOTO` |  |
| `SIZEOF` |  |
| `TYPEOF` |  |
| `NAMEOF` |  |
| `OFFSETOF` |  |
| `AS` |  |
| `PUBLIC` |  |
| `INTERNAL` |  |
| `USING` |  |
| `PLUS` |  |
| `MINUS` |  |
| `STAR` |  |
| `MOD` |  |
| `SLASH` |  |
| `BACK_SLASH` |  |
| `DOLLAR` |  |
| `HASH` |  |
| `DOT` |  |
| `VAR_ARGS` |  |
| `DOLLAR_VAR_ARGS` |  |
| `AT` |  |
| `QUESTION_MARK` |  |
| `COMMA` |  |
| `SEMICOLON` |  |
| `COLON` |  |
| `COLON_COLON` |  |
| `DOUBLE_QUOTE` |  |
| `DOLLAR_QUOTE` |  |
| `QUESTION_COLON` |  |
| `LESS_THAN` |  |
| `LESS_EQUALS` |  |
| `GREATER_THAN` |  |
| `GREATER_EQUALS` |  |
| `EQUALS_EQUALS` |  |
| `EQUALS` |  |
| `NOT_EQUALS` |  |
| `PLUS_EQ` |  |
| `MINUS_EQ` |  |
| `DIV_EQ` |  |
| `MUL_EQ` |  |
| `MOD_EQ` |  |
| `LSHIFT_EQ` |  |
| `RSHIFT_EQ` |  |
| `BNOT_EQ` |  |
| `XOR_EQ` |  |
| `BAND_EQ` |  |
| `BOR_EQ` |  |
| `LSHIFT` |  |
| `RSHIFT` |  |
| `BNOT` |  |
| `XOR` |  |
| `BAND` |  |
| `BOR` |  |
| `LEFT_PAREN` |  |
| `RIGHT_PAREN` |  |
| `LEFT_BRACKET` |  |
| `RIGHT_BRACKET` |  |
| `LEFT_BRACE` |  |
| `RIGHT_BRACE` |  |
| `NOT` |  |
| `OR` |  |
| `AND` |  |
| `STRING` |  |
| `IDENTIFIER` |  |
| `INT_NUMBER` |  |
| `FLOAT_NUMBER` |  |
| `ERROR` |  |
| `END_OF_FILE` |  |
| `MAX_TOKEN_TYPES` |  |

---

<a id="struct-srcpos"></a>

### struct SrcPos

*public* | *src/lex.lita:451*

| Field | Type | Description |
|-------|------|-------------|
| `filename` | \*const char |  |
| `lineStart` | \*const char |  |
| `start` | \*const char |  |
| `end` | \*const char |  |
| `lineNumber` | i32 |  |
| `position` | i32 |  |

---

<a id="union-value"></a>

### union Value

*public* | *src/lex.lita:467*

| Field | Type | Description |
|-------|------|-------------|
| `floatValue` | f64 |  |
| `intValue` | i64 |  |
| `uintValue` | u64 |  |
| `str` | String |  |

---

<a id="enum-mod"></a>

### enum Mod

*public* | *src/lex.lita:474*

| Value | Description |
|-------|-------------|
| `NONE` |  |
| `MULTISTR` |  |
| `NATIVE_STRING` |  |

---

<a id="struct-token"></a>

### struct Token

*public* | *src/lex.lita:480*

| Field | Type | Description |
|-------|------|-------------|
| `type` | [TokenType](lex.md#enum-tokentype) |  |
| `mod` | [Mod](lex.md#enum-mod) |  |
| `typeInfo` | \*[TypeInfo](types.md#struct-typeinfo) |  |
| `pos` | [SrcPos](lex.md#struct-srcpos) |  |
| `value` | [Value](lex.md#union-value) |  |

---

<a id="struct-lexer"></a>

### struct Lexer

*public* | *src/lex.lita:545*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const Allocator |  |
| `filename` | \*const char |  |
| `token` | [Token](lex.md#struct-token) |  |
| `stream` | \*const char |  |
| `length` | i64 |  |
| `lineStart` | \*const char |  |
| `lineNumber` | i32 |  |
| `position` | i32 |  |
| `errorMsg` | \*const char |  |

---

## Variables and Constants

<a id="const-tokentext"></a>

### const tokenText

*public* | *src/lex.lita:145*

---

