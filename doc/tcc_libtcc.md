# tcc::libtcc

## Functions

<a id="func-islibtccavailable"></a>

### func IsLibtccAvailable() : bool

*public* | *src/tcc/libtcc.lita:46*

---

<a id="func-tcc_new"></a>

### func tcc_new() : \*[TCCState](tcc_libtcc.md#struct-tccstate)

*public* | *src/tcc/libtcc.lita:62*

---

<a id="func-tcc_delete"></a>

### func tcc_delete(s: \*[TCCState](tcc_libtcc.md#struct-tccstate)) : void

*public* | *src/tcc/libtcc.lita:66*

---

<a id="func-tcc_set_lib_path"></a>

### func tcc_set_lib_path(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), path: \*const char) : void

*public* | *src/tcc/libtcc.lita:70*

---

<a id="func-tcc_set_error_func"></a>

### func tcc_set_error_func(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), error_opaque: \*void, error_func: TCCErrorFunc) : void

*public* | *src/tcc/libtcc.lita:74*

---

<a id="func-tcc_get_error_func"></a>

### func tcc_get_error_func(s: \*[TCCState](tcc_libtcc.md#struct-tccstate)) : TCCErrorFunc

*public* | *src/tcc/libtcc.lita:78*

---

<a id="func-tcc_get_error_opaque"></a>

### func tcc_get_error_opaque(s: \*[TCCState](tcc_libtcc.md#struct-tccstate)) : \*void

*public* | *src/tcc/libtcc.lita:82*

---

<a id="func-tcc_set_options"></a>

### func tcc_set_options(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), str: \*const char) : void

*public* | *src/tcc/libtcc.lita:86*

---

<a id="func-tcc_add_include_path"></a>

### func tcc_add_include_path(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), pathname: \*const char) : i32

*public* | *src/tcc/libtcc.lita:93*

---

<a id="func-tcc_add_sysinclude_path"></a>

### func tcc_add_sysinclude_path(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), pathname: \*const char) : i32

*public* | *src/tcc/libtcc.lita:97*

---

<a id="func-tcc_define_symbol"></a>

### func tcc_define_symbol(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), sym: \*const char, value: \*const char) : void

*public* | *src/tcc/libtcc.lita:101*

---

<a id="func-tcc_undefine_symbol"></a>

### func tcc_undefine_symbol(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), sym: \*const char) : void

*public* | *src/tcc/libtcc.lita:105*

---

<a id="func-tcc_add_file"></a>

### func tcc_add_file(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), filename: \*const char) : i32

*public* | *src/tcc/libtcc.lita:112*

---

<a id="func-tcc_compile_string"></a>

### func tcc_compile_string(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), buf: \*const char) : i32

*public* | *src/tcc/libtcc.lita:116*

---

<a id="func-tcc_set_output_type"></a>

### func tcc_set_output_type(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), output_type: i32) : i32

*public* | *src/tcc/libtcc.lita:123*

---

<a id="func-tcc_add_library_path"></a>

### func tcc_add_library_path(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), pathname: \*const char) : i32

*public* | *src/tcc/libtcc.lita:138*

---

<a id="func-tcc_add_library"></a>

### func tcc_add_library(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), libraryname: \*const char) : i32

*public* | *src/tcc/libtcc.lita:142*

---

<a id="func-tcc_add_symbol"></a>

### func tcc_add_symbol(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), name: \*const char, val: \*const void) : i32

*public* | *src/tcc/libtcc.lita:146*

---

<a id="func-tcc_output_file"></a>

### func tcc_output_file(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), filename: \*const char) : i32

*public* | *src/tcc/libtcc.lita:151*

---

<a id="func-tcc_run"></a>

### func tcc_run(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), argc: i32, argv: \*\*char) : i32

*public* | *src/tcc/libtcc.lita:156*

---

<a id="func-tcc_relocate"></a>

### func tcc_relocate(s1: \*[TCCState](tcc_libtcc.md#struct-tccstate), tpr: \*void) : i32

*public* | *src/tcc/libtcc.lita:160*

---

<a id="func-tcc_get_symbol"></a>

### func tcc_get_symbol(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), name: \*const char) : \*void

*public* | *src/tcc/libtcc.lita:171*

---

<a id="func-tcc_list_symbols"></a>

### func tcc_list_symbols(s: \*[TCCState](tcc_libtcc.md#struct-tccstate), ctx: \*void, symbol_cb: func(\*void, \*const char, \*const void) : void) : void

*public* | *src/tcc/libtcc.lita:175*

---

## Types

<a id="struct-tccstate"></a>

### struct TCCState

*public* | *src/tcc/libtcc.lita:55*

---

<a id="typedef-tccerrorfunc"></a>

### typedef TCCErrorFunc = func(\*void, \*const char) : void

*public* | *src/tcc/libtcc.lita:58*

---

## Variables and Constants

<a id="const-tcc_output_memory"></a>

### const TCC_OUTPUT_MEMORY: i32

*public* | *src/tcc/libtcc.lita:126*

---

<a id="const-tcc_output_exe"></a>

### const TCC_OUTPUT_EXE

*public* | *src/tcc/libtcc.lita:128*

---

<a id="const-tcc_output_dll"></a>

### const TCC_OUTPUT_DLL

*public* | *src/tcc/libtcc.lita:130*

---

<a id="const-tcc_output_obj"></a>

### const TCC_OUTPUT_OBJ

*public* | *src/tcc/libtcc.lita:132*

---

<a id="const-tcc_output_preprocess"></a>

### const TCC_OUTPUT_PREPROCESS: i32

*public* | *src/tcc/libtcc.lita:134*

---

<a id="const-tcc_relocate_auto"></a>

### const TCC_RELOCATE_AUTO: \*void

*public* | *src/tcc/libtcc.lita:167*

---

