# ape

## Functions

<a id="func-ape_make"></a>

### func ape_make() : \*[ape_t](ape.md#typedef-ape_t)

*public* | *src/ape/ape.lita:74*

---

<a id="func-ape_make_ex"></a>

### func ape_make_ex(malloc_fn: [ape_malloc_fn](ape.md#typedef-ape_malloc_fn), free_fn: [ape_free_fn](ape.md#typedef-ape_free_fn), ctx: \*void) : \*[ape_t](ape.md#typedef-ape_t)

*public* | *src/ape/ape.lita:77*

---

<a id="func-ape_destroy"></a>

### func ape_destroy(p0: \*[ape_t](ape.md#typedef-ape_t)) : void

*public* | *src/ape/ape.lita:80*

---

<a id="func-ape_set_repl_mode"></a>

### func ape_set_repl_mode(p0: \*[ape_t](ape.md#typedef-ape_t), p1: bool) : void

*public* | *src/ape/ape.lita:83*

---

<a id="func-ape_set_gc_interval"></a>

### func ape_set_gc_interval(p0: \*[ape_t](ape.md#typedef-ape_t), p1: i32) : void

*public* | *src/ape/ape.lita:86*

---

<a id="func-ape_set_stdout_write_function"></a>

### func ape_set_stdout_write_function(p0: \*[ape_t](ape.md#typedef-ape_t), p1: [ape_stdout_write_fn](ape.md#typedef-ape_stdout_write_fn), p2: \*void) : void

*public* | *src/ape/ape.lita:89*

---

<a id="func-ape_set_file_write_function"></a>

### func ape_set_file_write_function(p0: \*[ape_t](ape.md#typedef-ape_t), p1: [ape_write_file_fn](ape.md#typedef-ape_write_file_fn), p2: \*void) : void

*public* | *src/ape/ape.lita:92*

---

<a id="func-ape_set_file_read_function"></a>

### func ape_set_file_read_function(p0: \*[ape_t](ape.md#typedef-ape_t), p1: [ape_read_file_fn](ape.md#typedef-ape_read_file_fn), p2: \*void) : void

*public* | *src/ape/ape.lita:95*

---

<a id="func-ape_compile"></a>

### func ape_compile(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char) : \*[ape_program_t](ape.md#typedef-ape_program_t)

*public* | *src/ape/ape.lita:98*

---

<a id="func-ape_compile_file"></a>

### func ape_compile_file(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char) : \*[ape_program_t](ape.md#typedef-ape_program_t)

*public* | *src/ape/ape.lita:101*

---

<a id="func-ape_execute_program"></a>

### func ape_execute_program(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const [ape_program_t](ape.md#typedef-ape_program_t)) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:104*

---

<a id="func-ape_program_destroy"></a>

### func ape_program_destroy(p0: \*[ape_program_t](ape.md#typedef-ape_program_t)) : void

*public* | *src/ape/ape.lita:107*

---

<a id="func-ape_execute"></a>

### func ape_execute(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char, len: i32) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:110*

---

<a id="func-ape_execute_file"></a>

### func ape_execute_file(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:113*

---

<a id="func-ape_call"></a>

### func ape_call(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char, p2: i32, p3: \*[ape_object_t](ape.md#typedef-ape_object_t)) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:116*

---

<a id="func-ape_set_runtime_error"></a>

### func ape_set_runtime_error(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char) : void

*public* | *src/ape/ape.lita:119*

---

<a id="func-ape_set_runtime_errorf"></a>

### func ape_set_runtime_errorf(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char, ...) : void

*public* | *src/ape/ape.lita:122*

---

<a id="func-ape_has_errors"></a>

### func ape_has_errors(p0: \*const [ape_t](ape.md#typedef-ape_t)) : bool

*public* | *src/ape/ape.lita:125*

---

<a id="func-ape_errors_count"></a>

### func ape_errors_count(p0: \*const [ape_t](ape.md#typedef-ape_t)) : i32

*public* | *src/ape/ape.lita:128*

---

<a id="func-ape_get_error"></a>

### func ape_get_error(p0: \*const [ape_t](ape.md#typedef-ape_t), p1: i32) : \*const [ape_error_t](ape.md#typedef-ape_error_t)

*public* | *src/ape/ape.lita:131*

---

<a id="func-ape_set_native_function"></a>

### func ape_set_native_function(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char, p2: [ape_native_fn](ape.md#typedef-ape_native_fn), p3: \*void) : bool

*public* | *src/ape/ape.lita:134*

---

<a id="func-ape_set_global_constant"></a>

### func ape_set_global_constant(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char, p2: [ape_object_t](ape.md#typedef-ape_object_t)) : bool

*public* | *src/ape/ape.lita:137*

---

<a id="func-ape_get_object"></a>

### func ape_get_object(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:140*

---

<a id="func-ape_check_args"></a>

### func ape_check_args(p0: \*[ape_t](ape.md#typedef-ape_t), p1: bool, p2: i32, p3: \*[ape_object_t](ape.md#typedef-ape_object_t), p4: i32, p5: \*i32) : bool

*public* | *src/ape/ape.lita:143*

---

<a id="func-ape_object_make_number"></a>

### func ape_object_make_number(p0: f64) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:146*

---

<a id="func-ape_object_make_bool"></a>

### func ape_object_make_bool(p0: bool) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:149*

---

<a id="func-ape_object_make_null"></a>

### func ape_object_make_null() : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:152*

---

<a id="func-ape_object_make_string"></a>

### func ape_object_make_string(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:155*

---

<a id="func-ape_object_make_stringf"></a>

### func ape_object_make_stringf(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char, ...) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:158*

---

<a id="func-ape_object_make_array"></a>

### func ape_object_make_array(p0: \*[ape_t](ape.md#typedef-ape_t)) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:161*

---

<a id="func-ape_object_make_map"></a>

### func ape_object_make_map(p0: \*[ape_t](ape.md#typedef-ape_t)) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:164*

---

<a id="func-ape_object_make_native_function"></a>

### func ape_object_make_native_function(p0: \*[ape_t](ape.md#typedef-ape_t), p1: [ape_native_fn](ape.md#typedef-ape_native_fn), p2: \*void) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:167*

---

<a id="func-ape_object_make_error"></a>

### func ape_object_make_error(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:170*

---

<a id="func-ape_object_make_errorf"></a>

### func ape_object_make_errorf(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*const char, ...) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:173*

---

<a id="func-ape_object_make_external"></a>

### func ape_object_make_external(p0: \*[ape_t](ape.md#typedef-ape_t), p1: \*void) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:176*

---

<a id="func-ape_object_serialize"></a>

### func ape_object_serialize(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : \*char

*public* | *src/ape/ape.lita:179*

---

<a id="func-ape_object_disable_gc"></a>

### func ape_object_disable_gc(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : void

*public* | *src/ape/ape.lita:182*

---

<a id="func-ape_object_enable_gc"></a>

### func ape_object_enable_gc(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : void

*public* | *src/ape/ape.lita:185*

---

<a id="func-ape_object_equals"></a>

### func ape_object_equals(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: [ape_object_t](ape.md#typedef-ape_object_t)) : bool

*public* | *src/ape/ape.lita:188*

---

<a id="func-ape_object_copy"></a>

### func ape_object_copy(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:191*

---

<a id="func-ape_object_deep_copy"></a>

### func ape_object_deep_copy(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:194*

---

<a id="func-ape_object_get_type"></a>

### func ape_object_get_type(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : [ape_object_type_t](ape.md#typedef-ape_object_type_t)

*public* | *src/ape/ape.lita:197*

---

<a id="func-ape_object_get_type_string"></a>

### func ape_object_get_type_string(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : \*const char

*public* | *src/ape/ape.lita:200*

---

<a id="func-ape_object_get_type_name"></a>

### func ape_object_get_type_name(p0: [ape_object_type_t](ape.md#typedef-ape_object_type_t)) : \*const char

*public* | *src/ape/ape.lita:203*

---

<a id="func-ape_object_get_number"></a>

### func ape_object_get_number(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : f64

*public* | *src/ape/ape.lita:206*

---

<a id="func-ape_object_get_bool"></a>

### func ape_object_get_bool(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : bool

*public* | *src/ape/ape.lita:209*

---

<a id="func-ape_object_get_string"></a>

### func ape_object_get_string(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : \*const char

*public* | *src/ape/ape.lita:212*

---

<a id="func-ape_object_get_external"></a>

### func ape_object_get_external(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : \*void

*public* | *src/ape/ape.lita:215*

---

<a id="func-ape_object_get_error_message"></a>

### func ape_object_get_error_message(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : \*const char

*public* | *src/ape/ape.lita:218*

---

<a id="func-ape_object_get_error_traceback"></a>

### func ape_object_get_error_traceback(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : \*const [ape_traceback_t](ape.md#typedef-ape_traceback_t)

*public* | *src/ape/ape.lita:221*

---

<a id="func-ape_object_set_external_destroy_function"></a>

### func ape_object_set_external_destroy_function(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: [ape_data_destroy_fn](ape.md#typedef-ape_data_destroy_fn)) : bool

*public* | *src/ape/ape.lita:224*

---

<a id="func-ape_object_set_external_copy_function"></a>

### func ape_object_set_external_copy_function(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: [ape_data_copy_fn](ape.md#typedef-ape_data_copy_fn)) : bool

*public* | *src/ape/ape.lita:227*

---

<a id="func-ape_object_get_array_length"></a>

### func ape_object_get_array_length(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : i32

*public* | *src/ape/ape.lita:230*

---

<a id="func-ape_object_get_array_value"></a>

### func ape_object_get_array_value(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:233*

---

<a id="func-ape_object_get_array_string"></a>

### func ape_object_get_array_string(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32) : \*const char

*public* | *src/ape/ape.lita:236*

---

<a id="func-ape_object_get_array_number"></a>

### func ape_object_get_array_number(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32) : f64

*public* | *src/ape/ape.lita:239*

---

<a id="func-ape_object_get_array_bool"></a>

### func ape_object_get_array_bool(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32) : bool

*public* | *src/ape/ape.lita:242*

---

<a id="func-ape_object_set_array_value"></a>

### func ape_object_set_array_value(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32, p2: [ape_object_t](ape.md#typedef-ape_object_t)) : bool

*public* | *src/ape/ape.lita:245*

---

<a id="func-ape_object_set_array_string"></a>

### func ape_object_set_array_string(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32, p2: \*const char) : bool

*public* | *src/ape/ape.lita:248*

---

<a id="func-ape_object_set_array_number"></a>

### func ape_object_set_array_number(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32, p2: f64) : bool

*public* | *src/ape/ape.lita:251*

---

<a id="func-ape_object_set_array_bool"></a>

### func ape_object_set_array_bool(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32, p2: bool) : bool

*public* | *src/ape/ape.lita:254*

---

<a id="func-ape_object_add_array_value"></a>

### func ape_object_add_array_value(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: [ape_object_t](ape.md#typedef-ape_object_t)) : bool

*public* | *src/ape/ape.lita:257*

---

<a id="func-ape_object_add_array_string"></a>

### func ape_object_add_array_string(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char) : bool

*public* | *src/ape/ape.lita:260*

---

<a id="func-ape_object_add_array_number"></a>

### func ape_object_add_array_number(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: f64) : bool

*public* | *src/ape/ape.lita:263*

---

<a id="func-ape_object_add_array_bool"></a>

### func ape_object_add_array_bool(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: bool) : bool

*public* | *src/ape/ape.lita:266*

---

<a id="func-ape_object_get_map_length"></a>

### func ape_object_get_map_length(p0: [ape_object_t](ape.md#typedef-ape_object_t)) : i32

*public* | *src/ape/ape.lita:269*

---

<a id="func-ape_object_get_map_key_at"></a>

### func ape_object_get_map_key_at(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:272*

---

<a id="func-ape_object_get_map_value_at"></a>

### func ape_object_get_map_value_at(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:275*

---

<a id="func-ape_object_set_map_value_at"></a>

### func ape_object_set_map_value_at(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: i32, p2: [ape_object_t](ape.md#typedef-ape_object_t)) : bool

*public* | *src/ape/ape.lita:278*

---

<a id="func-ape_object_set_map_value_with_value_key"></a>

### func ape_object_set_map_value_with_value_key(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: [ape_object_t](ape.md#typedef-ape_object_t), p2: [ape_object_t](ape.md#typedef-ape_object_t)) : bool

*public* | *src/ape/ape.lita:281*

---

<a id="func-ape_object_set_map_value"></a>

### func ape_object_set_map_value(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char, p2: [ape_object_t](ape.md#typedef-ape_object_t)) : bool

*public* | *src/ape/ape.lita:284*

---

<a id="func-ape_object_set_map_string"></a>

### func ape_object_set_map_string(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char, p2: \*const char) : bool

*public* | *src/ape/ape.lita:287*

---

<a id="func-ape_object_set_map_number"></a>

### func ape_object_set_map_number(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char, p2: f64) : bool

*public* | *src/ape/ape.lita:290*

---

<a id="func-ape_object_set_map_bool"></a>

### func ape_object_set_map_bool(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char, p2: bool) : bool

*public* | *src/ape/ape.lita:293*

---

<a id="func-ape_object_get_map_value_with_value_key"></a>

### func ape_object_get_map_value_with_value_key(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: [ape_object_t](ape.md#typedef-ape_object_t)) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:296*

---

<a id="func-ape_object_get_map_value"></a>

### func ape_object_get_map_value(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:299*

---

<a id="func-ape_object_get_map_string"></a>

### func ape_object_get_map_string(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char) : \*const char

*public* | *src/ape/ape.lita:302*

---

<a id="func-ape_object_get_map_number"></a>

### func ape_object_get_map_number(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char) : f64

*public* | *src/ape/ape.lita:305*

---

<a id="func-ape_object_get_map_bool"></a>

### func ape_object_get_map_bool(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char) : bool

*public* | *src/ape/ape.lita:308*

---

<a id="func-ape_object_map_has_key"></a>

### func ape_object_map_has_key(p0: [ape_object_t](ape.md#typedef-ape_object_t), p1: \*const char) : bool

*public* | *src/ape/ape.lita:311*

---

<a id="func-ape_error_get_message"></a>

### func ape_error_get_message(p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : \*const char

*public* | *src/ape/ape.lita:314*

---

<a id="func-ape_error_get_filepath"></a>

### func ape_error_get_filepath(p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : \*const char

*public* | *src/ape/ape.lita:317*

---

<a id="func-ape_error_get_line"></a>

### func ape_error_get_line(p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : \*const char

*public* | *src/ape/ape.lita:320*

---

<a id="func-ape_error_get_line_number"></a>

### func ape_error_get_line_number(p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : i32

*public* | *src/ape/ape.lita:323*

---

<a id="func-ape_error_get_column_number"></a>

### func ape_error_get_column_number(p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : i32

*public* | *src/ape/ape.lita:326*

---

<a id="func-ape_error_get_type"></a>

### func ape_error_get_type(p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : [ape_error_type_t](ape.md#typedef-ape_error_type_t)

*public* | *src/ape/ape.lita:329*

---

<a id="func-ape_error_get_type_string"></a>

### func ape_error_get_type_string(p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : \*const char

*public* | *src/ape/ape.lita:332*

---

<a id="func-ape_error_type_to_string"></a>

### func ape_error_type_to_string(p0: [ape_error_type_t](ape.md#typedef-ape_error_type_t)) : \*const char

*public* | *src/ape/ape.lita:335*

---

<a id="func-ape_error_serialize"></a>

### func ape_error_serialize(ape: \*[ape_t](ape.md#typedef-ape_t), p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : \*char

*public* | *src/ape/ape.lita:338*

---

<a id="func-ape_error_get_traceback"></a>

### func ape_error_get_traceback(p0: \*const [ape_error_t](ape.md#typedef-ape_error_t)) : \*const [ape_traceback_t](ape.md#typedef-ape_traceback_t)

*public* | *src/ape/ape.lita:341*

---

<a id="func-ape_traceback_get_depth"></a>

### func ape_traceback_get_depth(p0: \*const [ape_traceback_t](ape.md#typedef-ape_traceback_t)) : i32

*public* | *src/ape/ape.lita:344*

---

<a id="func-ape_traceback_get_filepath"></a>

### func ape_traceback_get_filepath(p0: \*const [ape_traceback_t](ape.md#typedef-ape_traceback_t), p1: i32) : \*const char

*public* | *src/ape/ape.lita:347*

---

<a id="func-ape_traceback_get_line"></a>

### func ape_traceback_get_line(p0: \*const [ape_traceback_t](ape.md#typedef-ape_traceback_t), p1: i32) : \*const char

*public* | *src/ape/ape.lita:350*

---

<a id="func-ape_traceback_get_line_number"></a>

### func ape_traceback_get_line_number(p0: \*const [ape_traceback_t](ape.md#typedef-ape_traceback_t), p1: i32) : i32

*public* | *src/ape/ape.lita:353*

---

<a id="func-ape_traceback_get_column_number"></a>

### func ape_traceback_get_column_number(p0: \*const [ape_traceback_t](ape.md#typedef-ape_traceback_t), p1: i32) : i32

*public* | *src/ape/ape.lita:356*

---

<a id="func-ape_traceback_get_function_name"></a>

### func ape_traceback_get_function_name(p0: \*const [ape_traceback_t](ape.md#typedef-ape_traceback_t), p1: i32) : \*const char

*public* | *src/ape/ape.lita:359*

---

<a id="func-ape_callx"></a>

### func ape_callx(ape: \*[ape_t](ape.md#typedef-ape_t), name: \*const char, ...) : bool

*public* | *src/ape/ape.lita:371*

---

<a id="func-ape_check_argsx"></a>

### func ape_check_argsx(ape: \*[ape_t](ape.md#typedef-ape_t), errors: bool, argc: i32, args: \*[ape_object_t](ape.md#typedef-ape_object_t), ...) : bool

*public* | *src/ape/ape.lita:375*

---

## Types

<a id="struct-ape"></a>

### struct ape

*public* | *src/ape/ape.lita:8*

---

<a id="typedef-ape_t"></a>

### typedef ape_t = void

*public* | *src/ape/ape.lita:10*

---

<a id="struct-ape_object"></a>

### struct ape_object

*public* | *src/ape/ape.lita:13*

| Field | Type | Description |
|-------|------|-------------|
| `_internal` | u64 |  |

---

<a id="typedef-ape_object_t"></a>

### typedef ape_object_t = void

*public* | *src/ape/ape.lita:16*

---

<a id="struct-ape_error"></a>

### struct ape_error

*public* | *src/ape/ape.lita:20*

---

<a id="typedef-ape_error_t"></a>

### typedef ape_error_t = void

*public* | *src/ape/ape.lita:22*

---

<a id="struct-ape_program"></a>

### struct ape_program

*public* | *src/ape/ape.lita:25*

---

<a id="typedef-ape_program_t"></a>

### typedef ape_program_t = void

*public* | *src/ape/ape.lita:27*

---

<a id="struct-ape_traceback"></a>

### struct ape_traceback

*public* | *src/ape/ape.lita:30*

---

<a id="typedef-ape_traceback_t"></a>

### typedef ape_traceback_t = void

*public* | *src/ape/ape.lita:32*

---

<a id="enum-ape_error_type"></a>

### enum ape_error_type

*public* | *src/ape/ape.lita:35*

| Value | Description |
|-------|-------------|
| `APE_ERROR_NONE` |  |
| `APE_ERROR_PARSING` |  |
| `APE_ERROR_COMPILATION` |  |
| `APE_ERROR_RUNTIME` |  |
| `APE_ERROR_USER` |  |

---

<a id="typedef-ape_error_type_t"></a>

### typedef ape_error_type_t = void

*public* | *src/ape/ape.lita:42*

---

<a id="enum-ape_object_type"></a>

### enum ape_object_type

*public* | *src/ape/ape.lita:45*

| Value | Description |
|-------|-------------|
| `APE_OBJECT_NONE` |  |
| `APE_OBJECT_ERROR` |  |
| `APE_OBJECT_NUMBER` |  |
| `APE_OBJECT_BOOL` |  |
| `APE_OBJECT_STRING` |  |
| `APE_OBJECT_NULL` |  |
| `APE_OBJECT_NATIVE_FUNCTION` |  |
| `APE_OBJECT_ARRAY` |  |
| `APE_OBJECT_MAP` |  |
| `APE_OBJECT_FUNCTION` |  |
| `APE_OBJECT_EXTERNAL` |  |
| `APE_OBJECT_FREED` |  |
| `APE_OBJECT_ANY` |  |

---

<a id="typedef-ape_object_type_t"></a>

### typedef ape_object_type_t = void

*public* | *src/ape/ape.lita:60*

---

<a id="typedef-ape_native_fn"></a>

### typedef ape_native_fn = func(\*[ape_t](ape.md#typedef-ape_t), \*void, i32, \*[ape_object_t](ape.md#typedef-ape_object_t)) : [ape_object_t](ape.md#typedef-ape_object_t)

*public* | *src/ape/ape.lita:62*

---

<a id="typedef-ape_malloc_fn"></a>

### typedef ape_malloc_fn = func(\*void, usize) : \*void

*public* | *src/ape/ape.lita:63*

---

<a id="typedef-ape_free_fn"></a>

### typedef ape_free_fn = func(\*void, \*void) : void

*public* | *src/ape/ape.lita:64*

---

<a id="typedef-ape_data_destroy_fn"></a>

### typedef ape_data_destroy_fn = func(\*void) : void

*public* | *src/ape/ape.lita:65*

---

<a id="typedef-ape_data_copy_fn"></a>

### typedef ape_data_copy_fn = func(\*void) : \*void

*public* | *src/ape/ape.lita:66*

---

<a id="typedef-ape_stdout_write_fn"></a>

### typedef ape_stdout_write_fn = func(\*void, \*const void, u64) : u64

*public* | *src/ape/ape.lita:68*

---

<a id="typedef-ape_read_file_fn"></a>

### typedef ape_read_file_fn = func(\*void, \*const char) : \*char

*public* | *src/ape/ape.lita:69*

---

<a id="typedef-ape_write_file_fn"></a>

### typedef ape_write_file_fn = func(\*void, \*const char, \*const char, u64) : u64

*public* | *src/ape/ape.lita:70*

---

## Variables and Constants

<a id="const-ape_version_major"></a>

### const APE_VERSION_MAJOR: i32

*public* | *src/ape/ape.lita:362*

---

<a id="const-ape_version_minor"></a>

### const APE_VERSION_MINOR: i32

*public* | *src/ape/ape.lita:363*

---

<a id="const-ape_version_patch"></a>

### const APE_VERSION_PATCH: i32

*public* | *src/ape/ape.lita:364*

---

<a id="const-ape_version_string"></a>

### const APE_VERSION_STRING: i32

*public* | *src/ape/ape.lita:365*

---

