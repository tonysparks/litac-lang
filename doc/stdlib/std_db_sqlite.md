# std::db::sqlite

## Functions

<a id="func-sqlite3_libversion"></a>

### func sqlite3_libversion() : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:24*

---

<a id="func-sqlite3_sourceid"></a>

### func sqlite3_sourceid() : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:27*

---

<a id="func-sqlite3_libversion_number"></a>

### func sqlite3_libversion_number() : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:30*

---

<a id="func-sqlite3_compileoption_used"></a>

### func sqlite3_compileoption_used(p0: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:33*

---

<a id="func-sqlite3_compileoption_get"></a>

### func sqlite3_compileoption_get(p0: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:36*

---

<a id="func-sqlite3_threadsafe"></a>

### func sqlite3_threadsafe() : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:39*

---

<a id="func-sqlite3_close"></a>

### func sqlite3_close(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:50*

---

<a id="func-sqlite3_close_v2"></a>

### func sqlite3_close_v2(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:53*

---

<a id="func-sqlite3_exec"></a>

### func sqlite3_exec(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: func(\*void, i32, \*\*char, \*\*char) : i32, p3: \*void, p4: \*\*char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:57*

---

<a id="func-sqlite3_initialize"></a>

### func sqlite3_initialize() : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:125*

---

<a id="func-sqlite3_shutdown"></a>

### func sqlite3_shutdown() : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:128*

---

<a id="func-sqlite3_os_init"></a>

### func sqlite3_os_init() : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:131*

---

<a id="func-sqlite3_os_end"></a>

### func sqlite3_os_end() : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:134*

---

<a id="func-sqlite3_config"></a>

### func sqlite3_config(p0: i32, ...) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:137*

---

<a id="func-sqlite3_db_config"></a>

### func sqlite3_db_config(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32, ...) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:140*

---

<a id="func-sqlite3_extended_result_codes"></a>

### func sqlite3_extended_result_codes(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:155*

---

<a id="func-sqlite3_last_insert_rowid"></a>

### func sqlite3_last_insert_rowid(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:158*

---

<a id="func-sqlite3_set_last_insert_rowid"></a>

### func sqlite3_set_last_insert_rowid(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:161*

---

<a id="func-sqlite3_changes"></a>

### func sqlite3_changes(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:164*

---

<a id="func-sqlite3_changes64"></a>

### func sqlite3_changes64(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:167*

---

<a id="func-sqlite3_total_changes"></a>

### func sqlite3_total_changes(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:170*

---

<a id="func-sqlite3_total_changes64"></a>

### func sqlite3_total_changes64(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:173*

---

<a id="func-sqlite3_interrupt"></a>

### func sqlite3_interrupt(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:176*

---

<a id="func-sqlite3_is_interrupted"></a>

### func sqlite3_is_interrupted(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:179*

---

<a id="func-sqlite3_complete"></a>

### func sqlite3_complete(p0: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:182*

---

<a id="func-sqlite3_complete16"></a>

### func sqlite3_complete16(p0: \*const void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:185*

---

<a id="func-sqlite3_busy_handler"></a>

### func sqlite3_busy_handler(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void, i32) : i32, p2: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:188*

---

<a id="func-sqlite3_busy_timeout"></a>

### func sqlite3_busy_timeout(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:191*

---

<a id="func-sqlite3_setlk_timeout"></a>

### func sqlite3_setlk_timeout(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:194*

---

<a id="func-sqlite3_get_table"></a>

### func sqlite3_get_table(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*\*\*char, p3: \*i32, p4: \*i32, p5: \*\*char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:197*

---

<a id="func-sqlite3_free_table"></a>

### func sqlite3_free_table(p0: \*\*char) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:200*

---

<a id="func-sqlite3_mprintf"></a>

### func sqlite3_mprintf(p0: \*const char, ...) : \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:203*

---

<a id="func-sqlite3_vmprintf"></a>

### func sqlite3_vmprintf(p0: \*const char, p1: [va_list](std_libc.md#struct-va_list)) : \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:206*

---

<a id="func-sqlite3_snprintf"></a>

### func sqlite3_snprintf(p0: i32, p1: \*char, p2: \*const char, ...) : \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:209*

---

<a id="func-sqlite3_vsnprintf"></a>

### func sqlite3_vsnprintf(p0: i32, p1: \*char, p2: \*const char, p3: [va_list](std_libc.md#struct-va_list)) : \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:212*

---

<a id="func-sqlite3_malloc"></a>

### func sqlite3_malloc(p0: i32) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:215*

---

<a id="func-sqlite3_malloc64"></a>

### func sqlite3_malloc64(p0: [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64)) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:218*

---

<a id="func-sqlite3_realloc"></a>

### func sqlite3_realloc(p0: \*void, p1: i32) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:221*

---

<a id="func-sqlite3_realloc64"></a>

### func sqlite3_realloc64(p0: \*void, p1: [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64)) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:224*

---

<a id="func-sqlite3_free"></a>

### func sqlite3_free(p0: \*void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:227*

---

<a id="func-sqlite3_msize"></a>

### func sqlite3_msize(p0: \*void) : [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:230*

---

<a id="func-sqlite3_memory_used"></a>

### func sqlite3_memory_used() : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:233*

---

<a id="func-sqlite3_memory_highwater"></a>

### func sqlite3_memory_highwater(p0: i32) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:236*

---

<a id="func-sqlite3_randomness"></a>

### func sqlite3_randomness(p0: i32, p1: \*void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:239*

---

<a id="func-sqlite3_set_authorizer"></a>

### func sqlite3_set_authorizer(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void, i32, \*const char, \*const char, \*const char, \*const char) : i32, p2: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:242*

---

<a id="func-sqlite3_trace"></a>

### func sqlite3_trace(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void, \*const char) : void, p2: \*void) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:245*

---

<a id="func-sqlite3_profile"></a>

### func sqlite3_profile(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void, \*const char, [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64)) : void, p2: \*void) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:248*

---

<a id="func-sqlite3_trace_v2"></a>

### func sqlite3_trace_v2(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: u32, p2: func(u32, \*void, \*void, \*void) : i32, p3: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:251*

---

<a id="func-sqlite3_progress_handler"></a>

### func sqlite3_progress_handler(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32, p2: func(\*void) : i32, p3: \*void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:254*

---

<a id="func-sqlite3_open"></a>

### func sqlite3_open(p0: \*const char, p1: \*\*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:257*

---

<a id="func-sqlite3_open16"></a>

### func sqlite3_open16(p0: \*const void, p1: \*\*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:260*

---

<a id="func-sqlite3_open_v2"></a>

### func sqlite3_open_v2(p0: \*const char, p1: \*\*[sqlite3](std_db_sqlite.md#struct-sqlite3), p2: i32, p3: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:263*

---

<a id="func-sqlite3_uri_parameter"></a>

### func sqlite3_uri_parameter(p0: [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename), p1: \*const char) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:266*

---

<a id="func-sqlite3_uri_boolean"></a>

### func sqlite3_uri_boolean(p0: [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename), p1: \*const char, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:269*

---

<a id="func-sqlite3_uri_int64"></a>

### func sqlite3_uri_int64(p0: [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename), p1: \*const char, p2: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:272*

---

<a id="func-sqlite3_uri_key"></a>

### func sqlite3_uri_key(p0: [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:275*

---

<a id="func-sqlite3_filename_database"></a>

### func sqlite3_filename_database(p0: [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename)) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:278*

---

<a id="func-sqlite3_filename_journal"></a>

### func sqlite3_filename_journal(p0: [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename)) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:281*

---

<a id="func-sqlite3_filename_wal"></a>

### func sqlite3_filename_wal(p0: [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename)) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:284*

---

<a id="func-sqlite3_database_file_object"></a>

### func sqlite3_database_file_object(p0: \*const char) : \*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file)

*public* | *stdlib/std/db/sqlite/sqlite.lita:287*

---

<a id="func-sqlite3_create_filename"></a>

### func sqlite3_create_filename(p0: \*const char, p1: \*const char, p2: \*const char, p3: i32, p4: \*\*const char) : [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename)

*public* | *stdlib/std/db/sqlite/sqlite.lita:290*

---

<a id="func-sqlite3_free_filename"></a>

### func sqlite3_free_filename(p0: [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:293*

---

<a id="func-sqlite3_errcode"></a>

### func sqlite3_errcode(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:296*

---

<a id="func-sqlite3_extended_errcode"></a>

### func sqlite3_extended_errcode(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:299*

---

<a id="func-sqlite3_errmsg"></a>

### func sqlite3_errmsg(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:302*

---

<a id="func-sqlite3_errmsg16"></a>

### func sqlite3_errmsg16(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:305*

---

<a id="func-sqlite3_errstr"></a>

### func sqlite3_errstr(p0: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:308*

---

<a id="func-sqlite3_error_offset"></a>

### func sqlite3_error_offset(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:311*

---

<a id="func-sqlite3_limit"></a>

### func sqlite3_limit(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:318*

---

<a id="func-sqlite3_prepare"></a>

### func sqlite3_prepare(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: \*\*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p4: \*\*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:321*

---

<a id="func-sqlite3_prepare_v2"></a>

### func sqlite3_prepare_v2(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: \*\*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p4: \*\*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:324*

---

<a id="func-sqlite3_prepare_v3"></a>

### func sqlite3_prepare_v3(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: u32, p4: \*\*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p5: \*\*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:327*

---

<a id="func-sqlite3_prepare16"></a>

### func sqlite3_prepare16(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const void, p2: i32, p3: \*\*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p4: \*\*const void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:330*

---

<a id="func-sqlite3_prepare16_v2"></a>

### func sqlite3_prepare16_v2(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const void, p2: i32, p3: \*\*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p4: \*\*const void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:333*

---

<a id="func-sqlite3_prepare16_v3"></a>

### func sqlite3_prepare16_v3(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const void, p2: i32, p3: u32, p4: \*\*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p5: \*\*const void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:336*

---

<a id="func-sqlite3_sql"></a>

### func sqlite3_sql(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:339*

---

<a id="func-sqlite3_expanded_sql"></a>

### func sqlite3_expanded_sql(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:342*

---

<a id="func-sqlite3_stmt_readonly"></a>

### func sqlite3_stmt_readonly(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:345*

---

<a id="func-sqlite3_stmt_isexplain"></a>

### func sqlite3_stmt_isexplain(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:348*

---

<a id="func-sqlite3_stmt_explain"></a>

### func sqlite3_stmt_explain(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:351*

---

<a id="func-sqlite3_stmt_busy"></a>

### func sqlite3_stmt_busy(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:354*

---

<a id="func-sqlite3_bind_blob"></a>

### func sqlite3_bind_blob(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: \*const void, p3: i32, p4: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:365*

---

<a id="func-sqlite3_bind_blob64"></a>

### func sqlite3_bind_blob64(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: \*const void, p3: [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64), p4: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:368*

---

<a id="func-sqlite3_bind_double"></a>

### func sqlite3_bind_double(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: f64) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:371*

---

<a id="func-sqlite3_bind_int"></a>

### func sqlite3_bind_int(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:374*

---

<a id="func-sqlite3_bind_int64"></a>

### func sqlite3_bind_int64(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:377*

---

<a id="func-sqlite3_bind_null"></a>

### func sqlite3_bind_null(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:380*

---

<a id="func-sqlite3_bind_text"></a>

### func sqlite3_bind_text(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: \*const char, p3: i32, p4: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:383*

---

<a id="func-sqlite3_bind_text16"></a>

### func sqlite3_bind_text16(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: \*const void, p3: i32, p4: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:386*

---

<a id="func-sqlite3_bind_text64"></a>

### func sqlite3_bind_text64(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: \*const char, p3: [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64), p4: func(\*void) : void, p5: u8) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:389*

---

<a id="func-sqlite3_bind_value"></a>

### func sqlite3_bind_value(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: \*const [sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:392*

---

<a id="func-sqlite3_bind_pointer"></a>

### func sqlite3_bind_pointer(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: \*void, p3: \*const char, p4: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:395*

---

<a id="func-sqlite3_bind_zeroblob"></a>

### func sqlite3_bind_zeroblob(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:398*

---

<a id="func-sqlite3_bind_zeroblob64"></a>

### func sqlite3_bind_zeroblob64(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:401*

---

<a id="func-sqlite3_bind_parameter_count"></a>

### func sqlite3_bind_parameter_count(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:404*

---

<a id="func-sqlite3_bind_parameter_name"></a>

### func sqlite3_bind_parameter_name(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:407*

---

<a id="func-sqlite3_bind_parameter_index"></a>

### func sqlite3_bind_parameter_index(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:410*

---

<a id="func-sqlite3_clear_bindings"></a>

### func sqlite3_clear_bindings(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:413*

---

<a id="func-sqlite3_column_count"></a>

### func sqlite3_column_count(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:416*

---

<a id="func-sqlite3_column_name"></a>

### func sqlite3_column_name(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:419*

---

<a id="func-sqlite3_column_name16"></a>

### func sqlite3_column_name16(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:422*

---

<a id="func-sqlite3_column_database_name"></a>

### func sqlite3_column_database_name(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:425*

---

<a id="func-sqlite3_column_database_name16"></a>

### func sqlite3_column_database_name16(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:428*

---

<a id="func-sqlite3_column_table_name"></a>

### func sqlite3_column_table_name(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:431*

---

<a id="func-sqlite3_column_table_name16"></a>

### func sqlite3_column_table_name16(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:434*

---

<a id="func-sqlite3_column_origin_name"></a>

### func sqlite3_column_origin_name(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:437*

---

<a id="func-sqlite3_column_origin_name16"></a>

### func sqlite3_column_origin_name16(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:440*

---

<a id="func-sqlite3_column_decltype"></a>

### func sqlite3_column_decltype(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:443*

---

<a id="func-sqlite3_column_decltype16"></a>

### func sqlite3_column_decltype16(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:446*

---

<a id="func-sqlite3_step"></a>

### func sqlite3_step(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:449*

---

<a id="func-sqlite3_data_count"></a>

### func sqlite3_data_count(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:452*

---

<a id="func-sqlite3_column_blob"></a>

### func sqlite3_column_blob(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:455*

---

<a id="func-sqlite3_column_double"></a>

### func sqlite3_column_double(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : f64

*public* | *stdlib/std/db/sqlite/sqlite.lita:458*

---

<a id="func-sqlite3_column_int"></a>

### func sqlite3_column_int(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:461*

---

<a id="func-sqlite3_column_int64"></a>

### func sqlite3_column_int64(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:464*

---

<a id="func-sqlite3_column_text"></a>

### func sqlite3_column_text(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const u8

*public* | *stdlib/std/db/sqlite/sqlite.lita:467*

---

<a id="func-sqlite3_column_text16"></a>

### func sqlite3_column_text16(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:470*

---

<a id="func-sqlite3_column_value"></a>

### func sqlite3_column_value(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)

*public* | *stdlib/std/db/sqlite/sqlite.lita:473*

---

<a id="func-sqlite3_column_bytes"></a>

### func sqlite3_column_bytes(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:476*

---

<a id="func-sqlite3_column_bytes16"></a>

### func sqlite3_column_bytes16(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:479*

---

<a id="func-sqlite3_column_type"></a>

### func sqlite3_column_type(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:482*

---

<a id="func-sqlite3_finalize"></a>

### func sqlite3_finalize(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:485*

---

<a id="func-sqlite3_reset"></a>

### func sqlite3_reset(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:488*

---

<a id="func-sqlite3_create_function"></a>

### func sqlite3_create_function(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: i32, p4: \*void, p5: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, p6: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, p7: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:491*

---

<a id="func-sqlite3_create_function16"></a>

### func sqlite3_create_function16(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const void, p2: i32, p3: i32, p4: \*void, p5: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, p6: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, p7: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:494*

---

<a id="func-sqlite3_create_function_v2"></a>

### func sqlite3_create_function_v2(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: i32, p4: \*void, p5: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, p6: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, p7: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : void, p8: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:497*

---

<a id="func-sqlite3_create_window_function"></a>

### func sqlite3_create_window_function(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: i32, p4: \*void, p5: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, p6: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : void, p7: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : void, p8: func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, p9: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:500*

---

<a id="func-sqlite3_aggregate_count"></a>

### func sqlite3_aggregate_count(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:503*

---

<a id="func-sqlite3_expired"></a>

### func sqlite3_expired(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:506*

---

<a id="func-sqlite3_transfer_bindings"></a>

### func sqlite3_transfer_bindings(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:509*

---

<a id="func-sqlite3_global_recover"></a>

### func sqlite3_global_recover() : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:512*

---

<a id="func-sqlite3_thread_cleanup"></a>

### func sqlite3_thread_cleanup() : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:515*

---

<a id="func-sqlite3_memory_alarm"></a>

### func sqlite3_memory_alarm(p0: func(\*void, [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), i32) : void, p1: \*void, p2: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:518*

---

<a id="func-sqlite3_value_blob"></a>

### func sqlite3_value_blob(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:521*

---

<a id="func-sqlite3_value_double"></a>

### func sqlite3_value_double(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : f64

*public* | *stdlib/std/db/sqlite/sqlite.lita:524*

---

<a id="func-sqlite3_value_int"></a>

### func sqlite3_value_int(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:527*

---

<a id="func-sqlite3_value_int64"></a>

### func sqlite3_value_int64(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:530*

---

<a id="func-sqlite3_value_pointer"></a>

### func sqlite3_value_pointer(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value), p1: \*const char) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:533*

---

<a id="func-sqlite3_value_text"></a>

### func sqlite3_value_text(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : \*const u8

*public* | *stdlib/std/db/sqlite/sqlite.lita:536*

---

<a id="func-sqlite3_value_text16"></a>

### func sqlite3_value_text16(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:539*

---

<a id="func-sqlite3_value_text16le"></a>

### func sqlite3_value_text16le(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:542*

---

<a id="func-sqlite3_value_text16be"></a>

### func sqlite3_value_text16be(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : \*const void

*public* | *stdlib/std/db/sqlite/sqlite.lita:545*

---

<a id="func-sqlite3_value_bytes"></a>

### func sqlite3_value_bytes(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:548*

---

<a id="func-sqlite3_value_bytes16"></a>

### func sqlite3_value_bytes16(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:551*

---

<a id="func-sqlite3_value_type"></a>

### func sqlite3_value_type(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:554*

---

<a id="func-sqlite3_value_numeric_type"></a>

### func sqlite3_value_numeric_type(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:557*

---

<a id="func-sqlite3_value_nochange"></a>

### func sqlite3_value_nochange(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:560*

---

<a id="func-sqlite3_value_frombind"></a>

### func sqlite3_value_frombind(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:563*

---

<a id="func-sqlite3_value_encoding"></a>

### func sqlite3_value_encoding(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:566*

---

<a id="func-sqlite3_value_subtype"></a>

### func sqlite3_value_subtype(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : u32

*public* | *stdlib/std/db/sqlite/sqlite.lita:569*

---

<a id="func-sqlite3_value_dup"></a>

### func sqlite3_value_dup(p0: \*const [sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)

*public* | *stdlib/std/db/sqlite/sqlite.lita:572*

---

<a id="func-sqlite3_value_free"></a>

### func sqlite3_value_free(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:575*

---

<a id="func-sqlite3_aggregate_context"></a>

### func sqlite3_aggregate_context(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: i32) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:578*

---

<a id="func-sqlite3_user_data"></a>

### func sqlite3_user_data(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:581*

---

<a id="func-sqlite3_context_db_handle"></a>

### func sqlite3_context_db_handle(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : \*[sqlite3](std_db_sqlite.md#struct-sqlite3)

*public* | *stdlib/std/db/sqlite/sqlite.lita:584*

---

<a id="func-sqlite3_get_auxdata"></a>

### func sqlite3_get_auxdata(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: i32) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:587*

---

<a id="func-sqlite3_set_auxdata"></a>

### func sqlite3_set_auxdata(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: i32, p2: \*void, p3: func(\*void) : void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:590*

---

<a id="func-sqlite3_get_clientdata"></a>

### func sqlite3_get_clientdata(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:593*

---

<a id="func-sqlite3_set_clientdata"></a>

### func sqlite3_set_clientdata(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*void, p3: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:596*

---

<a id="func-sqlite3_result_blob"></a>

### func sqlite3_result_blob(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const void, p2: i32, p3: func(\*void) : void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:600*

---

<a id="func-sqlite3_result_blob64"></a>

### func sqlite3_result_blob64(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const void, p2: [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64), p3: func(\*void) : void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:603*

---

<a id="func-sqlite3_result_double"></a>

### func sqlite3_result_double(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: f64) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:606*

---

<a id="func-sqlite3_result_error"></a>

### func sqlite3_result_error(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const char, p2: i32) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:609*

---

<a id="func-sqlite3_result_error16"></a>

### func sqlite3_result_error16(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const void, p2: i32) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:612*

---

<a id="func-sqlite3_result_error_toobig"></a>

### func sqlite3_result_error_toobig(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:615*

---

<a id="func-sqlite3_result_error_nomem"></a>

### func sqlite3_result_error_nomem(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:618*

---

<a id="func-sqlite3_result_error_code"></a>

### func sqlite3_result_error_code(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: i32) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:621*

---

<a id="func-sqlite3_result_int"></a>

### func sqlite3_result_int(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: i32) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:624*

---

<a id="func-sqlite3_result_int64"></a>

### func sqlite3_result_int64(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:627*

---

<a id="func-sqlite3_result_null"></a>

### func sqlite3_result_null(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:630*

---

<a id="func-sqlite3_result_text"></a>

### func sqlite3_result_text(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const char, p2: i32, p3: func(\*void) : void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:633*

---

<a id="func-sqlite3_result_text64"></a>

### func sqlite3_result_text64(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const char, p2: [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64), p3: func(\*void) : void, p4: u8) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:636*

---

<a id="func-sqlite3_result_text16"></a>

### func sqlite3_result_text16(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const void, p2: i32, p3: func(\*void) : void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:639*

---

<a id="func-sqlite3_result_text16le"></a>

### func sqlite3_result_text16le(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const void, p2: i32, p3: func(\*void) : void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:642*

---

<a id="func-sqlite3_result_text16be"></a>

### func sqlite3_result_text16be(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*const void, p2: i32, p3: func(\*void) : void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:645*

---

<a id="func-sqlite3_result_value"></a>

### func sqlite3_result_value(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:648*

---

<a id="func-sqlite3_result_pointer"></a>

### func sqlite3_result_pointer(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: \*void, p2: \*const char, p3: func(\*void) : void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:651*

---

<a id="func-sqlite3_result_zeroblob"></a>

### func sqlite3_result_zeroblob(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: i32) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:654*

---

<a id="func-sqlite3_result_zeroblob64"></a>

### func sqlite3_result_zeroblob64(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:657*

---

<a id="func-sqlite3_result_subtype"></a>

### func sqlite3_result_subtype(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), p1: u32) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:660*

---

<a id="func-sqlite3_create_collation"></a>

### func sqlite3_create_collation(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: \*void, p4: func(\*void, i32, \*const void, i32, \*const void) : i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:663*

---

<a id="func-sqlite3_create_collation_v2"></a>

### func sqlite3_create_collation_v2(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: \*void, p4: func(\*void, i32, \*const void, i32, \*const void) : i32, p5: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:666*

---

<a id="func-sqlite3_create_collation16"></a>

### func sqlite3_create_collation16(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const void, p2: i32, p3: \*void, p4: func(\*void, i32, \*const void, i32, \*const void) : i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:669*

---

<a id="func-sqlite3_collation_needed"></a>

### func sqlite3_collation_needed(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*void, p2: func(\*void, \*[sqlite3](std_db_sqlite.md#struct-sqlite3), i32, \*const char) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:672*

---

<a id="func-sqlite3_collation_needed16"></a>

### func sqlite3_collation_needed16(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*void, p2: func(\*void, \*[sqlite3](std_db_sqlite.md#struct-sqlite3), i32, \*const void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:675*

---

<a id="func-sqlite3_sleep"></a>

### func sqlite3_sleep(p0: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:678*

---

<a id="func-sqlite3_win32_set_directory"></a>

### func sqlite3_win32_set_directory(p0: u64, p1: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:683*

---

<a id="func-sqlite3_win32_set_directory8"></a>

### func sqlite3_win32_set_directory8(p0: u64, p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:686*

---

<a id="func-sqlite3_win32_set_directory16"></a>

### func sqlite3_win32_set_directory16(p0: u64, p1: \*const void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:689*

---

<a id="func-sqlite3_get_autocommit"></a>

### func sqlite3_get_autocommit(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:692*

---

<a id="func-sqlite3_db_handle"></a>

### func sqlite3_db_handle(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : \*[sqlite3](std_db_sqlite.md#struct-sqlite3)

*public* | *stdlib/std/db/sqlite/sqlite.lita:695*

---

<a id="func-sqlite3_db_name"></a>

### func sqlite3_db_name(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:698*

---

<a id="func-sqlite3_db_filename"></a>

### func sqlite3_db_filename(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char) : [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename)

*public* | *stdlib/std/db/sqlite/sqlite.lita:701*

---

<a id="func-sqlite3_db_readonly"></a>

### func sqlite3_db_readonly(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:704*

---

<a id="func-sqlite3_txn_state"></a>

### func sqlite3_txn_state(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:707*

---

<a id="func-sqlite3_next_stmt"></a>

### func sqlite3_next_stmt(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)

*public* | *stdlib/std/db/sqlite/sqlite.lita:710*

---

<a id="func-sqlite3_commit_hook"></a>

### func sqlite3_commit_hook(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void) : i32, p2: \*void) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:713*

---

<a id="func-sqlite3_rollback_hook"></a>

### func sqlite3_rollback_hook(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void) : void, p2: \*void) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:716*

---

<a id="func-sqlite3_autovacuum_pages"></a>

### func sqlite3_autovacuum_pages(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void, \*const char, u32, u32, u32) : u32, p2: \*void, p3: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:719*

---

<a id="func-sqlite3_update_hook"></a>

### func sqlite3_update_hook(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void, i32, \*const char, \*const char, [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : void, p2: \*void) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:722*

---

<a id="func-sqlite3_enable_shared_cache"></a>

### func sqlite3_enable_shared_cache(p0: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:725*

---

<a id="func-sqlite3_release_memory"></a>

### func sqlite3_release_memory(p0: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:728*

---

<a id="func-sqlite3_db_release_memory"></a>

### func sqlite3_db_release_memory(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:731*

---

<a id="func-sqlite3_soft_heap_limit64"></a>

### func sqlite3_soft_heap_limit64(p0: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:734*

---

<a id="func-sqlite3_hard_heap_limit64"></a>

### func sqlite3_hard_heap_limit64(p0: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)

*public* | *stdlib/std/db/sqlite/sqlite.lita:737*

---

<a id="func-sqlite3_soft_heap_limit"></a>

### func sqlite3_soft_heap_limit(p0: i32) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:740*

---

<a id="func-sqlite3_table_column_metadata"></a>

### func sqlite3_table_column_metadata(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*const char, p3: \*const char, p4: \*\*const char, p5: \*\*const char, p6: \*i32, p7: \*i32, p8: \*i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:743*

---

<a id="func-sqlite3_load_extension"></a>

### func sqlite3_load_extension(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*const char, p3: \*\*char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:746*

---

<a id="func-sqlite3_enable_load_extension"></a>

### func sqlite3_enable_load_extension(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:749*

---

<a id="func-sqlite3_auto_extension"></a>

### func sqlite3_auto_extension(p0: func() : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:752*

---

<a id="func-sqlite3_cancel_auto_extension"></a>

### func sqlite3_cancel_auto_extension(p0: func() : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:755*

---

<a id="func-sqlite3_reset_auto_extension"></a>

### func sqlite3_reset_auto_extension() : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:758*

---

<a id="func-sqlite3_create_module"></a>

### func sqlite3_create_module(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*const [sqlite3_module](std_db_sqlite.md#struct-sqlite3_module), p3: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:831*

---

<a id="func-sqlite3_create_module_v2"></a>

### func sqlite3_create_module_v2(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*const [sqlite3_module](std_db_sqlite.md#struct-sqlite3_module), p3: \*void, p4: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:834*

---

<a id="func-sqlite3_drop_modules"></a>

### func sqlite3_drop_modules(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*\*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:837*

---

<a id="func-sqlite3_declare_vtab"></a>

### func sqlite3_declare_vtab(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:852*

---

<a id="func-sqlite3_overload_function"></a>

### func sqlite3_overload_function(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:855*

---

<a id="func-sqlite3_blob_open"></a>

### func sqlite3_blob_open(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*const char, p3: \*const char, p4: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), p5: i32, p6: \*\*[sqlite3_blob](std_db_sqlite.md#struct-sqlite3_blob)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:862*

---

<a id="func-sqlite3_blob_reopen"></a>

### func sqlite3_blob_reopen(p0: \*[sqlite3_blob](std_db_sqlite.md#struct-sqlite3_blob), p1: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:865*

---

<a id="func-sqlite3_blob_close"></a>

### func sqlite3_blob_close(p0: \*[sqlite3_blob](std_db_sqlite.md#struct-sqlite3_blob)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:868*

---

<a id="func-sqlite3_blob_bytes"></a>

### func sqlite3_blob_bytes(p0: \*[sqlite3_blob](std_db_sqlite.md#struct-sqlite3_blob)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:871*

---

<a id="func-sqlite3_blob_read"></a>

### func sqlite3_blob_read(p0: \*[sqlite3_blob](std_db_sqlite.md#struct-sqlite3_blob), p1: \*void, p2: i32, p3: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:874*

---

<a id="func-sqlite3_blob_write"></a>

### func sqlite3_blob_write(p0: \*[sqlite3_blob](std_db_sqlite.md#struct-sqlite3_blob), p1: \*const void, p2: i32, p3: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:877*

---

<a id="func-sqlite3_vfs_find"></a>

### func sqlite3_vfs_find(p0: \*const char) : \*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs)

*public* | *stdlib/std/db/sqlite/sqlite.lita:880*

---

<a id="func-sqlite3_vfs_register"></a>

### func sqlite3_vfs_register(p0: \*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:883*

---

<a id="func-sqlite3_vfs_unregister"></a>

### func sqlite3_vfs_unregister(p0: \*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:886*

---

<a id="func-sqlite3_mutex_alloc"></a>

### func sqlite3_mutex_alloc(p0: i32) : \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)

*public* | *stdlib/std/db/sqlite/sqlite.lita:889*

---

<a id="func-sqlite3_mutex_free"></a>

### func sqlite3_mutex_free(p0: \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:892*

---

<a id="func-sqlite3_mutex_enter"></a>

### func sqlite3_mutex_enter(p0: \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:895*

---

<a id="func-sqlite3_mutex_try"></a>

### func sqlite3_mutex_try(p0: \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:898*

---

<a id="func-sqlite3_mutex_leave"></a>

### func sqlite3_mutex_leave(p0: \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:901*

---

<a id="func-sqlite3_mutex_held"></a>

### func sqlite3_mutex_held(p0: \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:917*

---

<a id="func-sqlite3_mutex_notheld"></a>

### func sqlite3_mutex_notheld(p0: \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:920*

---

<a id="func-sqlite3_db_mutex"></a>

### func sqlite3_db_mutex(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)

*public* | *stdlib/std/db/sqlite/sqlite.lita:923*

---

<a id="func-sqlite3_file_control"></a>

### func sqlite3_file_control(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:926*

---

<a id="func-sqlite3_test_control"></a>

### func sqlite3_test_control(p0: i32, ...) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:929*

---

<a id="func-sqlite3_keyword_count"></a>

### func sqlite3_keyword_count() : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:932*

---

<a id="func-sqlite3_keyword_name"></a>

### func sqlite3_keyword_name(p0: i32, p1: \*\*const char, p2: \*i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:935*

---

<a id="func-sqlite3_keyword_check"></a>

### func sqlite3_keyword_check(p0: \*const char, p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:938*

---

<a id="func-sqlite3_str_new"></a>

### func sqlite3_str_new(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str)

*public* | *stdlib/std/db/sqlite/sqlite.lita:945*

---

<a id="func-sqlite3_str_finish"></a>

### func sqlite3_str_finish(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str)) : \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:948*

---

<a id="func-sqlite3_str_appendf"></a>

### func sqlite3_str_appendf(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str), p1: \*const char, ...) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:951*

---

<a id="func-sqlite3_str_vappendf"></a>

### func sqlite3_str_vappendf(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str), p1: \*const char, p2: [va_list](std_libc.md#struct-va_list)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:954*

---

<a id="func-sqlite3_str_append"></a>

### func sqlite3_str_append(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str), p1: \*const char, p2: i32) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:957*

---

<a id="func-sqlite3_str_appendall"></a>

### func sqlite3_str_appendall(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str), p1: \*const char) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:960*

---

<a id="func-sqlite3_str_appendchar"></a>

### func sqlite3_str_appendchar(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str), p1: i32, p2: char) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:963*

---

<a id="func-sqlite3_str_reset"></a>

### func sqlite3_str_reset(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:966*

---

<a id="func-sqlite3_str_errcode"></a>

### func sqlite3_str_errcode(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:969*

---

<a id="func-sqlite3_str_length"></a>

### func sqlite3_str_length(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:972*

---

<a id="func-sqlite3_str_value"></a>

### func sqlite3_str_value(p0: \*[sqlite3_str](std_db_sqlite.md#struct-sqlite3_str)) : \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:975*

---

<a id="func-sqlite3_status"></a>

### func sqlite3_status(p0: i32, p1: \*i32, p2: \*i32, p3: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:978*

---

<a id="func-sqlite3_status64"></a>

### func sqlite3_status64(p0: i32, p1: \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), p2: \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), p3: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:981*

---

<a id="func-sqlite3_db_status"></a>

### func sqlite3_db_status(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32, p2: \*i32, p3: \*i32, p4: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:984*

---

<a id="func-sqlite3_stmt_status"></a>

### func sqlite3_stmt_status(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:987*

---

<a id="func-sqlite3_backup_init"></a>

### func sqlite3_backup_init(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p3: \*const char) : \*[sqlite3_backup](std_db_sqlite.md#struct-sqlite3_backup)

*public* | *stdlib/std/db/sqlite/sqlite.lita:1038*

---

<a id="func-sqlite3_backup_step"></a>

### func sqlite3_backup_step(p0: \*[sqlite3_backup](std_db_sqlite.md#struct-sqlite3_backup), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1041*

---

<a id="func-sqlite3_backup_finish"></a>

### func sqlite3_backup_finish(p0: \*[sqlite3_backup](std_db_sqlite.md#struct-sqlite3_backup)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1044*

---

<a id="func-sqlite3_backup_remaining"></a>

### func sqlite3_backup_remaining(p0: \*[sqlite3_backup](std_db_sqlite.md#struct-sqlite3_backup)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1047*

---

<a id="func-sqlite3_backup_pagecount"></a>

### func sqlite3_backup_pagecount(p0: \*[sqlite3_backup](std_db_sqlite.md#struct-sqlite3_backup)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1050*

---

<a id="func-sqlite3_unlock_notify"></a>

### func sqlite3_unlock_notify(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*\*void, i32) : void, p2: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1053*

---

<a id="func-sqlite3_stricmp"></a>

### func sqlite3_stricmp(p0: \*const char, p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1056*

---

<a id="func-sqlite3_strnicmp"></a>

### func sqlite3_strnicmp(p0: \*const char, p1: \*const char, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1059*

---

<a id="func-sqlite3_strglob"></a>

### func sqlite3_strglob(p0: \*const char, p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1062*

---

<a id="func-sqlite3_strlike"></a>

### func sqlite3_strlike(p0: \*const char, p1: \*const char, p2: u32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1065*

---

<a id="func-sqlite3_log"></a>

### func sqlite3_log(p0: i32, p1: \*const char, ...) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:1068*

---

<a id="func-sqlite3_wal_hook"></a>

### func sqlite3_wal_hook(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: func(\*void, \*[sqlite3](std_db_sqlite.md#struct-sqlite3), \*const char, i32) : i32, p2: \*void) : \*void

*public* | *stdlib/std/db/sqlite/sqlite.lita:1071*

---

<a id="func-sqlite3_wal_autocheckpoint"></a>

### func sqlite3_wal_autocheckpoint(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1074*

---

<a id="func-sqlite3_wal_checkpoint"></a>

### func sqlite3_wal_checkpoint(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1077*

---

<a id="func-sqlite3_wal_checkpoint_v2"></a>

### func sqlite3_wal_checkpoint_v2(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: i32, p3: \*i32, p4: \*i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1080*

---

<a id="func-sqlite3_vtab_config"></a>

### func sqlite3_vtab_config(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: i32, ...) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1083*

---

<a id="func-sqlite3_vtab_on_conflict"></a>

### func sqlite3_vtab_on_conflict(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1086*

---

<a id="func-sqlite3_vtab_nochange"></a>

### func sqlite3_vtab_nochange(p0: \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1089*

---

<a id="func-sqlite3_vtab_collation"></a>

### func sqlite3_vtab_collation(p0: \*[sqlite3_index_info](std_db_sqlite.md#struct-sqlite3_index_info), p1: i32) : \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:1092*

---

<a id="func-sqlite3_vtab_distinct"></a>

### func sqlite3_vtab_distinct(p0: \*[sqlite3_index_info](std_db_sqlite.md#struct-sqlite3_index_info)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1095*

---

<a id="func-sqlite3_vtab_in"></a>

### func sqlite3_vtab_in(p0: \*[sqlite3_index_info](std_db_sqlite.md#struct-sqlite3_index_info), p1: i32, p2: i32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1098*

---

<a id="func-sqlite3_vtab_in_first"></a>

### func sqlite3_vtab_in_first(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value), p1: \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1101*

---

<a id="func-sqlite3_vtab_in_next"></a>

### func sqlite3_vtab_in_next(p0: \*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value), p1: \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1104*

---

<a id="func-sqlite3_vtab_rhs_value"></a>

### func sqlite3_vtab_rhs_value(p0: \*[sqlite3_index_info](std_db_sqlite.md#struct-sqlite3_index_info), p1: i32, p2: \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1107*

---

<a id="func-sqlite3_stmt_scanstatus"></a>

### func sqlite3_stmt_scanstatus(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: i32, p3: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1110*

---

<a id="func-sqlite3_stmt_scanstatus_v2"></a>

### func sqlite3_stmt_scanstatus_v2(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt), p1: i32, p2: i32, p3: i32, p4: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1113*

---

<a id="func-sqlite3_stmt_scanstatus_reset"></a>

### func sqlite3_stmt_scanstatus_reset(p0: \*[sqlite3_stmt](std_db_sqlite.md#struct-sqlite3_stmt)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:1116*

---

<a id="func-sqlite3_db_cacheflush"></a>

### func sqlite3_db_cacheflush(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1119*

---

<a id="func-sqlite3_system_errno"></a>

### func sqlite3_system_errno(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1122*

---

<a id="func-sqlite3_snapshot_get"></a>

### func sqlite3_snapshot_get(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*\*[sqlite3_snapshot](std_db_sqlite.md#struct-sqlite3_snapshot)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1130*

---

<a id="func-sqlite3_snapshot_open"></a>

### func sqlite3_snapshot_open(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*[sqlite3_snapshot](std_db_sqlite.md#struct-sqlite3_snapshot)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1133*

---

<a id="func-sqlite3_snapshot_free"></a>

### func sqlite3_snapshot_free(p0: \*[sqlite3_snapshot](std_db_sqlite.md#struct-sqlite3_snapshot)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:1136*

---

<a id="func-sqlite3_snapshot_cmp"></a>

### func sqlite3_snapshot_cmp(p0: \*[sqlite3_snapshot](std_db_sqlite.md#struct-sqlite3_snapshot), p1: \*[sqlite3_snapshot](std_db_sqlite.md#struct-sqlite3_snapshot)) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1139*

---

<a id="func-sqlite3_snapshot_recover"></a>

### func sqlite3_snapshot_recover(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1142*

---

<a id="func-sqlite3_serialize"></a>

### func sqlite3_serialize(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), p3: u32) : \*u8

*public* | *stdlib/std/db/sqlite/sqlite.lita:1145*

---

<a id="func-sqlite3_deserialize"></a>

### func sqlite3_deserialize(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: \*u8, p3: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), p4: [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), p5: u32) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1148*

---

<a id="func-sqlite3_rtree_geometry_callback"></a>

### func sqlite3_rtree_geometry_callback(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: func(\*[sqlite3_rtree_geometry](std_db_sqlite.md#struct-sqlite3_rtree_geometry), i32, \*[sqlite3_rtree_dbl](std_db_sqlite.md#typedef-sqlite3_rtree_dbl), \*i32) : i32, p3: \*void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1153*

---

<a id="func-sqlite3_rtree_query_callback"></a>

### func sqlite3_rtree_query_callback(p0: \*[sqlite3](std_db_sqlite.md#struct-sqlite3), p1: \*const char, p2: func(\*[sqlite3_rtree_query_info](std_db_sqlite.md#struct-sqlite3_rtree_query_info)) : i32, p3: \*void, p4: func(\*void) : void) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1165*

---

## Types

<a id="struct-sqlite3"></a>

### struct sqlite3

*public* | *stdlib/std/db/sqlite/sqlite.lita:42*

---

<a id="typedef-sqlite_int64"></a>

### typedef sqlite_int64 = i64

*public* | *stdlib/std/db/sqlite/sqlite.lita:44*

---

<a id="typedef-sqlite_uint64"></a>

### typedef sqlite_uint64 = u64

*public* | *stdlib/std/db/sqlite/sqlite.lita:45*

---

<a id="typedef-sqlite3_int64"></a>

### typedef sqlite3_int64 = i64

*public* | *stdlib/std/db/sqlite/sqlite.lita:46*

---

<a id="typedef-sqlite3_uint64"></a>

### typedef sqlite3_uint64 = u64

*public* | *stdlib/std/db/sqlite/sqlite.lita:47*

---

<a id="typedef-sqlite3_callback"></a>

### typedef sqlite3_callback = func(\*void, i32, \*\*char, \*\*char) : i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:54*

---

<a id="struct-sqlite3_file"></a>

### struct sqlite3_file

*public* | *stdlib/std/db/sqlite/sqlite.lita:60*

| Field | Type | Description |
|-------|------|-------------|
| `pMethods` | \*const [sqlite3_io_methods](std_db_sqlite.md#struct-sqlite3_io_methods) |  |

---

<a id="struct-sqlite3_io_methods"></a>

### struct sqlite3_io_methods

*public* | *stdlib/std/db/sqlite/sqlite.lita:65*

| Field | Type | Description |
|-------|------|-------------|
| `iVersion` | i32 |  |
| `xClose` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file)) : i32 |  |
| `xRead` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), \*void, i32, [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xWrite` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), \*const void, i32, [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xTruncate` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xSync` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), i32) : i32 |  |
| `xFileSize` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xLock` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), i32) : i32 |  |
| `xUnlock` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), i32) : i32 |  |
| `xCheckReservedLock` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), \*i32) : i32 |  |
| `xFileControl` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), i32, \*void) : i32 |  |
| `xSectorSize` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file)) : i32 |  |
| `xDeviceCharacteristics` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file)) : i32 |  |
| `xShmMap` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), i32, i32, i32, \*\*void) : i32 |  |
| `xShmLock` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), i32, i32, i32) : i32 |  |
| `xShmBarrier` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file)) : void |  |
| `xShmUnmap` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), i32) : i32 |  |
| `xFetch` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), i32, \*\*void) : i32 |  |
| `xUnfetch` | func(\*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64), \*void) : i32 |  |

---

<a id="struct-sqlite3_mutex"></a>

### struct sqlite3_mutex

*public* | *stdlib/std/db/sqlite/sqlite.lita:88*

---

<a id="struct-sqlite3_api_routines"></a>

### struct sqlite3_api_routines

*public* | *stdlib/std/db/sqlite/sqlite.lita:92*

---

<a id="typedef-sqlite3_filename"></a>

### typedef sqlite3_filename = void

*public* | *stdlib/std/db/sqlite/sqlite.lita:94*

---

<a id="typedef-sqlite3_syscall_ptr"></a>

### typedef sqlite3_syscall_ptr = func() : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:96*

---

<a id="struct-sqlite3_vfs"></a>

### struct sqlite3_vfs

*public* | *stdlib/std/db/sqlite/sqlite.lita:99*

| Field | Type | Description |
|-------|------|-------------|
| `iVersion` | i32 |  |
| `szOsFile` | i32 |  |
| `mxPathname` | i32 |  |
| `pNext` | \*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs) |  |
| `zName` | \*const char |  |
| `pAppData` | \*void |  |
| `xOpen` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), [sqlite3_filename](std_db_sqlite.md#typedef-sqlite3_filename), \*[sqlite3_file](std_db_sqlite.md#struct-sqlite3_file), i32, \*i32) : i32 |  |
| `xDelete` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*const char, i32) : i32 |  |
| `xAccess` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*const char, i32, \*i32) : i32 |  |
| `xFullPathname` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*const char, i32, \*char) : i32 |  |
| `xDlOpen` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*const char) : \*void |  |
| `xDlError` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), i32, \*char) : void |  |
| `xDlSym` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*void, \*const char) : func() : void |  |
| `xDlClose` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*void) : void |  |
| `xRandomness` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), i32, \*char) : i32 |  |
| `xSleep` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), i32) : i32 |  |
| `xCurrentTime` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*f64) : i32 |  |
| `xGetLastError` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), i32, \*char) : i32 |  |
| `xCurrentTimeInt64` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xSetSystemCall` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*const char, [sqlite3_syscall_ptr](std_db_sqlite.md#typedef-sqlite3_syscall_ptr)) : i32 |  |
| `xGetSystemCall` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*const char) : [sqlite3_syscall_ptr](std_db_sqlite.md#typedef-sqlite3_syscall_ptr) |  |
| `xNextSystemCall` | func(\*[sqlite3_vfs](std_db_sqlite.md#struct-sqlite3_vfs), \*const char) : \*const char |  |

---

<a id="struct-sqlite3_mem_methods"></a>

### struct sqlite3_mem_methods

*public* | *stdlib/std/db/sqlite/sqlite.lita:143*

| Field | Type | Description |
|-------|------|-------------|
| `xMalloc` | func(i32) : \*void |  |
| `xFree` | func(\*void) : void |  |
| `xRealloc` | func(\*void, i32) : \*void |  |
| `xSize` | func(\*void) : i32 |  |
| `xRoundup` | func(i32) : i32 |  |
| `xInit` | func(\*void) : i32 |  |
| `xShutdown` | func(\*void) : void |  |
| `pAppData` | \*void |  |

---

<a id="struct-sqlite3_stmt"></a>

### struct sqlite3_stmt

*public* | *stdlib/std/db/sqlite/sqlite.lita:314*

---

<a id="struct-sqlite3_value"></a>

### struct sqlite3_value

*public* | *stdlib/std/db/sqlite/sqlite.lita:357*

---

<a id="struct-sqlite3_context"></a>

### struct sqlite3_context

*public* | *stdlib/std/db/sqlite/sqlite.lita:361*

---

<a id="typedef-sqlite3_destructor_type"></a>

### typedef sqlite3_destructor_type = func(\*void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:597*

---

<a id="struct-sqlite3_module"></a>

### struct sqlite3_module

*public* | *stdlib/std/db/sqlite/sqlite.lita:762*

| Field | Type | Description |
|-------|------|-------------|
| `iVersion` | i32 |  |
| `xCreate` | func(\*[sqlite3](std_db_sqlite.md#struct-sqlite3), \*void, i32, \*const \*const char, \*\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), \*\*char) : i32 |  |
| `xConnect` | func(\*[sqlite3](std_db_sqlite.md#struct-sqlite3), \*void, i32, \*const \*const char, \*\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), \*\*char) : i32 |  |
| `xBestIndex` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), \*[sqlite3_index_info](std_db_sqlite.md#struct-sqlite3_index_info)) : i32 |  |
| `xDisconnect` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab)) : i32 |  |
| `xDestroy` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab)) : i32 |  |
| `xOpen` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), \*\*[sqlite3_vtab_cursor](std_db_sqlite.md#struct-sqlite3_vtab_cursor)) : i32 |  |
| `xClose` | func(\*[sqlite3_vtab_cursor](std_db_sqlite.md#struct-sqlite3_vtab_cursor)) : i32 |  |
| `xFilter` | func(\*[sqlite3_vtab_cursor](std_db_sqlite.md#struct-sqlite3_vtab_cursor), i32, \*const char, i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : i32 |  |
| `xNext` | func(\*[sqlite3_vtab_cursor](std_db_sqlite.md#struct-sqlite3_vtab_cursor)) : i32 |  |
| `xEof` | func(\*[sqlite3_vtab_cursor](std_db_sqlite.md#struct-sqlite3_vtab_cursor)) : i32 |  |
| `xColumn` | func(\*[sqlite3_vtab_cursor](std_db_sqlite.md#struct-sqlite3_vtab_cursor), \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32) : i32 |  |
| `xRowid` | func(\*[sqlite3_vtab_cursor](std_db_sqlite.md#struct-sqlite3_vtab_cursor), \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xUpdate` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value), \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xBegin` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab)) : i32 |  |
| `xSync` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab)) : i32 |  |
| `xCommit` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab)) : i32 |  |
| `xRollback` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab)) : i32 |  |
| `xFindFunction` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), i32, \*const char, \*func(\*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void, \*\*void) : i32 |  |
| `xRename` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), \*const char) : i32 |  |
| `xSavepoint` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), i32) : i32 |  |
| `xRelease` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), i32) : i32 |  |
| `xRollbackTo` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), i32) : i32 |  |
| `xShadowName` | func(\*const char) : i32 |  |
| `xIntegrity` | func(\*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab), \*const char, \*const char, i32, \*\*char) : i32 |  |

---

<a id="struct-sqlite3_index_info"></a>

### struct sqlite3_index_info

*public* | *stdlib/std/db/sqlite/sqlite.lita:791*

| Field | Type | Description |
|-------|------|-------------|
| `nConstraint` | i32 |  |
| `aConstraint` | \*[sqlite3_index_constraint](std_db_sqlite.md#struct-sqlite3_index_constraint) |  |
| `nOrderBy` | i32 |  |
| `aOrderBy` | \*[sqlite3_index_orderby](std_db_sqlite.md#struct-sqlite3_index_orderby) |  |
| `aConstraintUsage` | \*[sqlite3_index_constraint_usage](std_db_sqlite.md#struct-sqlite3_index_constraint_usage) |  |
| `idxNum` | i32 |  |
| `idxStr` | \*char |  |
| `needToFreeIdxStr` | i32 |  |
| `orderByConsumed` | i32 |  |
| `estimatedCost` | f64 |  |
| `estimatedRows` | [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64) |  |
| `idxFlags` | i32 |  |
| `colUsed` | [sqlite3_uint64](std_db_sqlite.md#typedef-sqlite3_uint64) |  |

---

<a id="struct-sqlite3_index_constraint"></a>

### struct sqlite3_index_constraint

*public* | *stdlib/std/db/sqlite/sqlite.lita:811*

| Field | Type | Description |
|-------|------|-------------|
| `iColumn` | i32 |  |
| `op` | u8 |  |
| `usable` | u8 |  |
| `iTermOffset` | i32 |  |

---

<a id="struct-sqlite3_index_orderby"></a>

### struct sqlite3_index_orderby

*public* | *stdlib/std/db/sqlite/sqlite.lita:819*

| Field | Type | Description |
|-------|------|-------------|
| `iColumn` | i32 |  |
| `desc` | u8 |  |

---

<a id="struct-sqlite3_index_constraint_usage"></a>

### struct sqlite3_index_constraint_usage

*public* | *stdlib/std/db/sqlite/sqlite.lita:825*

| Field | Type | Description |
|-------|------|-------------|
| `argvIndex` | i32 |  |
| `omit` | u8 |  |

---

<a id="struct-sqlite3_vtab"></a>

### struct sqlite3_vtab

*public* | *stdlib/std/db/sqlite/sqlite.lita:840*

| Field | Type | Description |
|-------|------|-------------|
| `pModule` | \*const [sqlite3_module](std_db_sqlite.md#struct-sqlite3_module) |  |
| `nRef` | i32 |  |
| `zErrMsg` | \*char |  |

---

<a id="struct-sqlite3_vtab_cursor"></a>

### struct sqlite3_vtab_cursor

*public* | *stdlib/std/db/sqlite/sqlite.lita:847*

| Field | Type | Description |
|-------|------|-------------|
| `pVtab` | \*[sqlite3_vtab](std_db_sqlite.md#struct-sqlite3_vtab) |  |

---

<a id="struct-sqlite3_blob"></a>

### struct sqlite3_blob

*public* | *stdlib/std/db/sqlite/sqlite.lita:858*

---

<a id="struct-sqlite3_mutex_methods"></a>

### struct sqlite3_mutex_methods

*public* | *stdlib/std/db/sqlite/sqlite.lita:904*

| Field | Type | Description |
|-------|------|-------------|
| `xMutexInit` | func() : i32 |  |
| `xMutexEnd` | func() : i32 |  |
| `xMutexAlloc` | func(i32) : \*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex) |  |
| `xMutexFree` | func(\*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : void |  |
| `xMutexEnter` | func(\*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : void |  |
| `xMutexTry` | func(\*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : i32 |  |
| `xMutexLeave` | func(\*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : void |  |
| `xMutexHeld` | func(\*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : i32 |  |
| `xMutexNotheld` | func(\*[sqlite3_mutex](std_db_sqlite.md#struct-sqlite3_mutex)) : i32 |  |

---

<a id="struct-sqlite3_str"></a>

### struct sqlite3_str

*public* | *stdlib/std/db/sqlite/sqlite.lita:941*

---

<a id="struct-sqlite3_pcache"></a>

### struct sqlite3_pcache

*public* | *stdlib/std/db/sqlite/sqlite.lita:990*

---

<a id="struct-sqlite3_pcache_page"></a>

### struct sqlite3_pcache_page

*public* | *stdlib/std/db/sqlite/sqlite.lita:994*

| Field | Type | Description |
|-------|------|-------------|
| `pBuf` | \*void |  |
| `pExtra` | \*void |  |

---

<a id="struct-sqlite3_pcache_methods2"></a>

### struct sqlite3_pcache_methods2

*public* | *stdlib/std/db/sqlite/sqlite.lita:1001*

| Field | Type | Description |
|-------|------|-------------|
| `iVersion` | i32 |  |
| `pArg` | \*void |  |
| `xInit` | func(\*void) : i32 |  |
| `xShutdown` | func(\*void) : void |  |
| `xCreate` | func(i32, i32, i32) : \*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache) |  |
| `xCachesize` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), i32) : void |  |
| `xPagecount` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache)) : i32 |  |
| `xFetch` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), u32, i32) : \*[sqlite3_pcache_page](std_db_sqlite.md#struct-sqlite3_pcache_page) |  |
| `xUnpin` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), \*[sqlite3_pcache_page](std_db_sqlite.md#struct-sqlite3_pcache_page), i32) : void |  |
| `xRekey` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), \*[sqlite3_pcache_page](std_db_sqlite.md#struct-sqlite3_pcache_page), u32, u32) : void |  |
| `xTruncate` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), u32) : void |  |
| `xDestroy` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache)) : void |  |
| `xShrink` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache)) : void |  |

---

<a id="struct-sqlite3_pcache_methods"></a>

### struct sqlite3_pcache_methods

*public* | *stdlib/std/db/sqlite/sqlite.lita:1019*

| Field | Type | Description |
|-------|------|-------------|
| `pArg` | \*void |  |
| `xInit` | func(\*void) : i32 |  |
| `xShutdown` | func(\*void) : void |  |
| `xCreate` | func(i32, i32) : \*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache) |  |
| `xCachesize` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), i32) : void |  |
| `xPagecount` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache)) : i32 |  |
| `xFetch` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), u32, i32) : \*void |  |
| `xUnpin` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), \*void, i32) : void |  |
| `xRekey` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), \*void, u32, u32) : void |  |
| `xTruncate` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache), u32) : void |  |
| `xDestroy` | func(\*[sqlite3_pcache](std_db_sqlite.md#struct-sqlite3_pcache)) : void |  |

---

<a id="struct-sqlite3_backup"></a>

### struct sqlite3_backup

*public* | *stdlib/std/db/sqlite/sqlite.lita:1034*

---

<a id="struct-sqlite3_snapshot"></a>

### struct sqlite3_snapshot

*public* | *stdlib/std/db/sqlite/sqlite.lita:1125*

| Field | Type | Description |
|-------|------|-------------|
| `hidden` | \[\]u8 |  |

---

<a id="typedef-sqlite3_rtree_dbl"></a>

### typedef sqlite3_rtree_dbl = void

*public* | *stdlib/std/db/sqlite/sqlite.lita:1150*

---

<a id="struct-sqlite3_rtree_geometry"></a>

### struct sqlite3_rtree_geometry

*public* | *stdlib/std/db/sqlite/sqlite.lita:1156*

| Field | Type | Description |
|-------|------|-------------|
| `pContext` | \*void |  |
| `nParam` | i32 |  |
| `aParam` | \*[sqlite3_rtree_dbl](std_db_sqlite.md#typedef-sqlite3_rtree_dbl) |  |
| `pUser` | \*void |  |
| `xDelUser` | func(\*void) : void |  |

---

<a id="struct-sqlite3_rtree_query_info"></a>

### struct sqlite3_rtree_query_info

*public* | *stdlib/std/db/sqlite/sqlite.lita:1168*

| Field | Type | Description |
|-------|------|-------------|
| `pContext` | \*void |  |
| `nParam` | i32 |  |
| `aParam` | \*[sqlite3_rtree_dbl](std_db_sqlite.md#typedef-sqlite3_rtree_dbl) |  |
| `pUser` | \*void |  |
| `xDelUser` | func(\*void) : void |  |
| `aCoord` | \*[sqlite3_rtree_dbl](std_db_sqlite.md#typedef-sqlite3_rtree_dbl) |  |
| `anQueue` | \*u32 |  |
| `nCoord` | i32 |  |
| `iLevel` | i32 |  |
| `mxLevel` | i32 |  |
| `iRowid` | [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64) |  |
| `rParentScore` | [sqlite3_rtree_dbl](std_db_sqlite.md#typedef-sqlite3_rtree_dbl) |  |
| `eParentWithin` | i32 |  |
| `eWithin` | i32 |  |
| `rScore` | [sqlite3_rtree_dbl](std_db_sqlite.md#typedef-sqlite3_rtree_dbl) |  |
| `apSqlParam` | \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value) |  |

---

<a id="struct-fts5context"></a>

### struct Fts5Context

*public* | *stdlib/std/db/sqlite/sqlite.lita:1188*

---

<a id="typedef-fts5_extension_function"></a>

### typedef fts5_extension_function = func(\*const [Fts5ExtensionApi](std_db_sqlite.md#struct-fts5extensionapi), \*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*[sqlite3_context](std_db_sqlite.md#struct-sqlite3_context), i32, \*\*[sqlite3_value](std_db_sqlite.md#struct-sqlite3_value)) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:1191*

---

<a id="struct-fts5phraseiter"></a>

### struct Fts5PhraseIter

*public* | *stdlib/std/db/sqlite/sqlite.lita:1194*

| Field | Type | Description |
|-------|------|-------------|
| `a` | \*const u8 |  |
| `b` | \*const u8 |  |

---

<a id="struct-fts5extensionapi"></a>

### struct Fts5ExtensionApi

*public* | *stdlib/std/db/sqlite/sqlite.lita:1200*

| Field | Type | Description |
|-------|------|-------------|
| `iVersion` | i32 |  |
| `xUserData` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context)) : \*void |  |
| `xColumnCount` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context)) : i32 |  |
| `xRowCount` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xColumnTotalSize` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, \*[sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64)) : i32 |  |
| `xTokenize` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*const char, i32, \*void, func(\*void, i32, \*const char, i32, i32, i32) : i32) : i32 |  |
| `xPhraseCount` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context)) : i32 |  |
| `xPhraseSize` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32) : i32 |  |
| `xInstCount` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*i32) : i32 |  |
| `xInst` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, \*i32, \*i32, \*i32) : i32 |  |
| `xRowid` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context)) : [sqlite3_int64](std_db_sqlite.md#typedef-sqlite3_int64) |  |
| `xColumnText` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, \*\*const char, \*i32) : i32 |  |
| `xColumnSize` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, \*i32) : i32 |  |
| `xQueryPhrase` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, \*void, func(\*const [Fts5ExtensionApi](std_db_sqlite.md#struct-fts5extensionapi), \*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*void) : i32) : i32 |  |
| `xSetAuxdata` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*void, func(\*void) : void) : i32 |  |
| `xGetAuxdata` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32) : \*void |  |
| `xPhraseFirst` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, \*[Fts5PhraseIter](std_db_sqlite.md#struct-fts5phraseiter), \*i32, \*i32) : i32 |  |
| `xPhraseNext` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*[Fts5PhraseIter](std_db_sqlite.md#struct-fts5phraseiter), \*i32, \*i32) : void |  |
| `xPhraseFirstColumn` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, \*[Fts5PhraseIter](std_db_sqlite.md#struct-fts5phraseiter), \*i32) : i32 |  |
| `xPhraseNextColumn` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*[Fts5PhraseIter](std_db_sqlite.md#struct-fts5phraseiter), \*i32) : void |  |
| `xQueryToken` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, i32, \*\*const char, \*i32) : i32 |  |
| `xInstToken` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, i32, \*\*const char, \*i32) : i32 |  |
| `xColumnLocale` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), i32, \*\*const char, \*i32) : i32 |  |
| `xTokenize_v2` | func(\*[Fts5Context](std_db_sqlite.md#struct-fts5context), \*const char, i32, \*const char, i32, \*void, func(\*void, i32, \*const char, i32, i32, i32) : i32) : i32 |  |

---

<a id="struct-fts5tokenizer"></a>

### struct Fts5Tokenizer

*public* | *stdlib/std/db/sqlite/sqlite.lita:1228*

---

<a id="struct-fts5_tokenizer_v2"></a>

### struct fts5_tokenizer_v2

*public* | *stdlib/std/db/sqlite/sqlite.lita:1232*

| Field | Type | Description |
|-------|------|-------------|
| `iVersion` | i32 |  |
| `xCreate` | func(\*void, \*\*const char, i32, \*\*[Fts5Tokenizer](std_db_sqlite.md#struct-fts5tokenizer)) : i32 |  |
| `xDelete` | func(\*[Fts5Tokenizer](std_db_sqlite.md#struct-fts5tokenizer)) : void |  |
| `xTokenize` | func(\*[Fts5Tokenizer](std_db_sqlite.md#struct-fts5tokenizer), \*void, i32, \*const char, i32, \*const char, i32, func(\*void, i32, \*const char, i32, i32, i32) : i32) : i32 |  |

---

<a id="struct-fts5_tokenizer"></a>

### struct fts5_tokenizer

*public* | *stdlib/std/db/sqlite/sqlite.lita:1241*

| Field | Type | Description |
|-------|------|-------------|
| `xCreate` | func(\*void, \*\*const char, i32, \*\*[Fts5Tokenizer](std_db_sqlite.md#struct-fts5tokenizer)) : i32 |  |
| `xDelete` | func(\*[Fts5Tokenizer](std_db_sqlite.md#struct-fts5tokenizer)) : void |  |
| `xTokenize` | func(\*[Fts5Tokenizer](std_db_sqlite.md#struct-fts5tokenizer), \*void, i32, \*const char, i32, func(\*void, i32, \*const char, i32, i32, i32) : i32) : i32 |  |

---

<a id="struct-fts5_api"></a>

### struct fts5_api

*public* | *stdlib/std/db/sqlite/sqlite.lita:1248*

| Field | Type | Description |
|-------|------|-------------|
| `iVersion` | i32 |  |
| `xCreateTokenizer` | func(\*[fts5_api](std_db_sqlite.md#struct-fts5_api), \*const char, \*void, \*[fts5_tokenizer](std_db_sqlite.md#struct-fts5_tokenizer), func(\*void) : void) : i32 |  |
| `xFindTokenizer` | func(\*[fts5_api](std_db_sqlite.md#struct-fts5_api), \*const char, \*\*void, \*[fts5_tokenizer](std_db_sqlite.md#struct-fts5_tokenizer)) : i32 |  |
| `xCreateFunction` | func(\*[fts5_api](std_db_sqlite.md#struct-fts5_api), \*const char, \*void, [fts5_extension_function](std_db_sqlite.md#typedef-fts5_extension_function), func(\*void) : void) : i32 |  |
| `xCreateTokenizer_v2` | func(\*[fts5_api](std_db_sqlite.md#struct-fts5_api), \*const char, \*void, \*[fts5_tokenizer_v2](std_db_sqlite.md#struct-fts5_tokenizer_v2), func(\*void) : void) : i32 |  |
| `xFindTokenizer_v2` | func(\*[fts5_api](std_db_sqlite.md#struct-fts5_api), \*const char, \*\*void, \*\*[fts5_tokenizer_v2](std_db_sqlite.md#struct-fts5_tokenizer_v2)) : i32 |  |

---

## Variables and Constants

<a id="var-sqlite3_version"></a>

### var sqlite3_version: \*const char

*public* | *stdlib/std/db/sqlite/sqlite.lita:21*

---

<a id="var-sqlite3_temp_directory"></a>

### var sqlite3_temp_directory: \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:679*

---

<a id="var-sqlite3_data_directory"></a>

### var sqlite3_data_directory: \*char

*public* | *stdlib/std/db/sqlite/sqlite.lita:680*

---

<a id="const-sqlite_extern"></a>

### const SQLITE_EXTERN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1257*

---

<a id="const-sqlite_stdcall"></a>

### const SQLITE_STDCALL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1261*

---

<a id="const-sqlite_version"></a>

### const SQLITE_VERSION: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1266*

---

<a id="const-sqlite_version_number"></a>

### const SQLITE_VERSION_NUMBER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1267*

---

<a id="const-sqlite_source_id"></a>

### const SQLITE_SOURCE_ID: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1268*

---

<a id="const-sqlite_ok"></a>

### const SQLITE_OK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1269*

---

<a id="const-sqlite_error"></a>

### const SQLITE_ERROR: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1270*

---

<a id="const-sqlite_internal"></a>

### const SQLITE_INTERNAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1271*

---

<a id="const-sqlite_perm"></a>

### const SQLITE_PERM: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1272*

---

<a id="const-sqlite_abort"></a>

### const SQLITE_ABORT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1273*

---

<a id="const-sqlite_busy"></a>

### const SQLITE_BUSY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1274*

---

<a id="const-sqlite_locked"></a>

### const SQLITE_LOCKED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1275*

---

<a id="const-sqlite_nomem"></a>

### const SQLITE_NOMEM: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1276*

---

<a id="const-sqlite_readonly"></a>

### const SQLITE_READONLY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1277*

---

<a id="const-sqlite_interrupt"></a>

### const SQLITE_INTERRUPT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1278*

---

<a id="const-sqlite_ioerr"></a>

### const SQLITE_IOERR: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1279*

---

<a id="const-sqlite_corrupt"></a>

### const SQLITE_CORRUPT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1280*

---

<a id="const-sqlite_notfound"></a>

### const SQLITE_NOTFOUND: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1281*

---

<a id="const-sqlite_full"></a>

### const SQLITE_FULL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1282*

---

<a id="const-sqlite_cantopen"></a>

### const SQLITE_CANTOPEN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1283*

---

<a id="const-sqlite_protocol"></a>

### const SQLITE_PROTOCOL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1284*

---

<a id="const-sqlite_empty"></a>

### const SQLITE_EMPTY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1285*

---

<a id="const-sqlite_schema"></a>

### const SQLITE_SCHEMA: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1286*

---

<a id="const-sqlite_toobig"></a>

### const SQLITE_TOOBIG: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1287*

---

<a id="const-sqlite_constraint"></a>

### const SQLITE_CONSTRAINT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1288*

---

<a id="const-sqlite_mismatch"></a>

### const SQLITE_MISMATCH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1289*

---

<a id="const-sqlite_misuse"></a>

### const SQLITE_MISUSE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1290*

---

<a id="const-sqlite_nolfs"></a>

### const SQLITE_NOLFS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1291*

---

<a id="const-sqlite_auth"></a>

### const SQLITE_AUTH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1292*

---

<a id="const-sqlite_format"></a>

### const SQLITE_FORMAT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1293*

---

<a id="const-sqlite_range"></a>

### const SQLITE_RANGE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1294*

---

<a id="const-sqlite_notadb"></a>

### const SQLITE_NOTADB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1295*

---

<a id="const-sqlite_notice"></a>

### const SQLITE_NOTICE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1296*

---

<a id="const-sqlite_warning"></a>

### const SQLITE_WARNING: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1297*

---

<a id="const-sqlite_row"></a>

### const SQLITE_ROW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1298*

---

<a id="const-sqlite_done"></a>

### const SQLITE_DONE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1299*

---

<a id="const-sqlite_error_missing_collseq"></a>

### const SQLITE_ERROR_MISSING_COLLSEQ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1300*

---

<a id="const-sqlite_error_retry"></a>

### const SQLITE_ERROR_RETRY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1301*

---

<a id="const-sqlite_error_snapshot"></a>

### const SQLITE_ERROR_SNAPSHOT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1302*

---

<a id="const-sqlite_ioerr_read"></a>

### const SQLITE_IOERR_READ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1303*

---

<a id="const-sqlite_ioerr_short_read"></a>

### const SQLITE_IOERR_SHORT_READ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1304*

---

<a id="const-sqlite_ioerr_write"></a>

### const SQLITE_IOERR_WRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1305*

---

<a id="const-sqlite_ioerr_fsync"></a>

### const SQLITE_IOERR_FSYNC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1306*

---

<a id="const-sqlite_ioerr_dir_fsync"></a>

### const SQLITE_IOERR_DIR_FSYNC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1307*

---

<a id="const-sqlite_ioerr_truncate"></a>

### const SQLITE_IOERR_TRUNCATE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1308*

---

<a id="const-sqlite_ioerr_fstat"></a>

### const SQLITE_IOERR_FSTAT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1309*

---

<a id="const-sqlite_ioerr_unlock"></a>

### const SQLITE_IOERR_UNLOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1310*

---

<a id="const-sqlite_ioerr_rdlock"></a>

### const SQLITE_IOERR_RDLOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1311*

---

<a id="const-sqlite_ioerr_delete"></a>

### const SQLITE_IOERR_DELETE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1312*

---

<a id="const-sqlite_ioerr_blocked"></a>

### const SQLITE_IOERR_BLOCKED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1313*

---

<a id="const-sqlite_ioerr_nomem"></a>

### const SQLITE_IOERR_NOMEM: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1314*

---

<a id="const-sqlite_ioerr_access"></a>

### const SQLITE_IOERR_ACCESS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1315*

---

<a id="const-sqlite_ioerr_checkreservedlock"></a>

### const SQLITE_IOERR_CHECKRESERVEDLOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1316*

---

<a id="const-sqlite_ioerr_lock"></a>

### const SQLITE_IOERR_LOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1317*

---

<a id="const-sqlite_ioerr_close"></a>

### const SQLITE_IOERR_CLOSE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1318*

---

<a id="const-sqlite_ioerr_dir_close"></a>

### const SQLITE_IOERR_DIR_CLOSE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1319*

---

<a id="const-sqlite_ioerr_shmopen"></a>

### const SQLITE_IOERR_SHMOPEN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1320*

---

<a id="const-sqlite_ioerr_shmsize"></a>

### const SQLITE_IOERR_SHMSIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1321*

---

<a id="const-sqlite_ioerr_shmlock"></a>

### const SQLITE_IOERR_SHMLOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1322*

---

<a id="const-sqlite_ioerr_shmmap"></a>

### const SQLITE_IOERR_SHMMAP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1323*

---

<a id="const-sqlite_ioerr_seek"></a>

### const SQLITE_IOERR_SEEK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1324*

---

<a id="const-sqlite_ioerr_delete_noent"></a>

### const SQLITE_IOERR_DELETE_NOENT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1325*

---

<a id="const-sqlite_ioerr_mmap"></a>

### const SQLITE_IOERR_MMAP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1326*

---

<a id="const-sqlite_ioerr_gettemppath"></a>

### const SQLITE_IOERR_GETTEMPPATH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1327*

---

<a id="const-sqlite_ioerr_convpath"></a>

### const SQLITE_IOERR_CONVPATH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1328*

---

<a id="const-sqlite_ioerr_vnode"></a>

### const SQLITE_IOERR_VNODE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1329*

---

<a id="const-sqlite_ioerr_auth"></a>

### const SQLITE_IOERR_AUTH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1330*

---

<a id="const-sqlite_ioerr_begin_atomic"></a>

### const SQLITE_IOERR_BEGIN_ATOMIC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1331*

---

<a id="const-sqlite_ioerr_commit_atomic"></a>

### const SQLITE_IOERR_COMMIT_ATOMIC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1332*

---

<a id="const-sqlite_ioerr_rollback_atomic"></a>

### const SQLITE_IOERR_ROLLBACK_ATOMIC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1333*

---

<a id="const-sqlite_ioerr_data"></a>

### const SQLITE_IOERR_DATA: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1334*

---

<a id="const-sqlite_ioerr_corruptfs"></a>

### const SQLITE_IOERR_CORRUPTFS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1335*

---

<a id="const-sqlite_ioerr_in_page"></a>

### const SQLITE_IOERR_IN_PAGE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1336*

---

<a id="const-sqlite_locked_sharedcache"></a>

### const SQLITE_LOCKED_SHAREDCACHE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1337*

---

<a id="const-sqlite_locked_vtab"></a>

### const SQLITE_LOCKED_VTAB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1338*

---

<a id="const-sqlite_busy_recovery"></a>

### const SQLITE_BUSY_RECOVERY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1339*

---

<a id="const-sqlite_busy_snapshot"></a>

### const SQLITE_BUSY_SNAPSHOT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1340*

---

<a id="const-sqlite_busy_timeout"></a>

### const SQLITE_BUSY_TIMEOUT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1341*

---

<a id="const-sqlite_cantopen_notempdir"></a>

### const SQLITE_CANTOPEN_NOTEMPDIR: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1342*

---

<a id="const-sqlite_cantopen_isdir"></a>

### const SQLITE_CANTOPEN_ISDIR: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1343*

---

<a id="const-sqlite_cantopen_fullpath"></a>

### const SQLITE_CANTOPEN_FULLPATH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1344*

---

<a id="const-sqlite_cantopen_convpath"></a>

### const SQLITE_CANTOPEN_CONVPATH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1345*

---

<a id="const-sqlite_cantopen_dirtywal"></a>

### const SQLITE_CANTOPEN_DIRTYWAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1346*

---

<a id="const-sqlite_cantopen_symlink"></a>

### const SQLITE_CANTOPEN_SYMLINK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1347*

---

<a id="const-sqlite_corrupt_vtab"></a>

### const SQLITE_CORRUPT_VTAB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1348*

---

<a id="const-sqlite_corrupt_sequence"></a>

### const SQLITE_CORRUPT_SEQUENCE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1349*

---

<a id="const-sqlite_corrupt_index"></a>

### const SQLITE_CORRUPT_INDEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1350*

---

<a id="const-sqlite_readonly_recovery"></a>

### const SQLITE_READONLY_RECOVERY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1351*

---

<a id="const-sqlite_readonly_cantlock"></a>

### const SQLITE_READONLY_CANTLOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1352*

---

<a id="const-sqlite_readonly_rollback"></a>

### const SQLITE_READONLY_ROLLBACK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1353*

---

<a id="const-sqlite_readonly_dbmoved"></a>

### const SQLITE_READONLY_DBMOVED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1354*

---

<a id="const-sqlite_readonly_cantinit"></a>

### const SQLITE_READONLY_CANTINIT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1355*

---

<a id="const-sqlite_readonly_directory"></a>

### const SQLITE_READONLY_DIRECTORY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1356*

---

<a id="const-sqlite_abort_rollback"></a>

### const SQLITE_ABORT_ROLLBACK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1357*

---

<a id="const-sqlite_constraint_check"></a>

### const SQLITE_CONSTRAINT_CHECK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1358*

---

<a id="const-sqlite_constraint_commithook"></a>

### const SQLITE_CONSTRAINT_COMMITHOOK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1359*

---

<a id="const-sqlite_constraint_foreignkey"></a>

### const SQLITE_CONSTRAINT_FOREIGNKEY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1360*

---

<a id="const-sqlite_constraint_function"></a>

### const SQLITE_CONSTRAINT_FUNCTION: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1361*

---

<a id="const-sqlite_constraint_notnull"></a>

### const SQLITE_CONSTRAINT_NOTNULL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1362*

---

<a id="const-sqlite_constraint_primarykey"></a>

### const SQLITE_CONSTRAINT_PRIMARYKEY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1363*

---

<a id="const-sqlite_constraint_trigger"></a>

### const SQLITE_CONSTRAINT_TRIGGER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1364*

---

<a id="const-sqlite_constraint_unique"></a>

### const SQLITE_CONSTRAINT_UNIQUE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1365*

---

<a id="const-sqlite_constraint_vtab"></a>

### const SQLITE_CONSTRAINT_VTAB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1366*

---

<a id="const-sqlite_constraint_rowid"></a>

### const SQLITE_CONSTRAINT_ROWID: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1367*

---

<a id="const-sqlite_constraint_pinned"></a>

### const SQLITE_CONSTRAINT_PINNED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1368*

---

<a id="const-sqlite_constraint_datatype"></a>

### const SQLITE_CONSTRAINT_DATATYPE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1369*

---

<a id="const-sqlite_notice_recover_wal"></a>

### const SQLITE_NOTICE_RECOVER_WAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1370*

---

<a id="const-sqlite_notice_recover_rollback"></a>

### const SQLITE_NOTICE_RECOVER_ROLLBACK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1371*

---

<a id="const-sqlite_notice_rbu"></a>

### const SQLITE_NOTICE_RBU: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1372*

---

<a id="const-sqlite_warning_autoindex"></a>

### const SQLITE_WARNING_AUTOINDEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1373*

---

<a id="const-sqlite_auth_user"></a>

### const SQLITE_AUTH_USER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1374*

---

<a id="const-sqlite_ok_load_permanently"></a>

### const SQLITE_OK_LOAD_PERMANENTLY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1375*

---

<a id="const-sqlite_ok_symlink"></a>

### const SQLITE_OK_SYMLINK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1376*

---

<a id="const-sqlite_open_readonly"></a>

### const SQLITE_OPEN_READONLY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1377*

---

<a id="const-sqlite_open_readwrite"></a>

### const SQLITE_OPEN_READWRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1378*

---

<a id="const-sqlite_open_create"></a>

### const SQLITE_OPEN_CREATE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1379*

---

<a id="const-sqlite_open_deleteonclose"></a>

### const SQLITE_OPEN_DELETEONCLOSE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1380*

---

<a id="const-sqlite_open_exclusive"></a>

### const SQLITE_OPEN_EXCLUSIVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1381*

---

<a id="const-sqlite_open_autoproxy"></a>

### const SQLITE_OPEN_AUTOPROXY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1382*

---

<a id="const-sqlite_open_uri"></a>

### const SQLITE_OPEN_URI: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1383*

---

<a id="const-sqlite_open_memory"></a>

### const SQLITE_OPEN_MEMORY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1384*

---

<a id="const-sqlite_open_main_db"></a>

### const SQLITE_OPEN_MAIN_DB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1385*

---

<a id="const-sqlite_open_temp_db"></a>

### const SQLITE_OPEN_TEMP_DB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1386*

---

<a id="const-sqlite_open_transient_db"></a>

### const SQLITE_OPEN_TRANSIENT_DB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1387*

---

<a id="const-sqlite_open_main_journal"></a>

### const SQLITE_OPEN_MAIN_JOURNAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1388*

---

<a id="const-sqlite_open_temp_journal"></a>

### const SQLITE_OPEN_TEMP_JOURNAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1389*

---

<a id="const-sqlite_open_subjournal"></a>

### const SQLITE_OPEN_SUBJOURNAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1390*

---

<a id="const-sqlite_open_super_journal"></a>

### const SQLITE_OPEN_SUPER_JOURNAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1391*

---

<a id="const-sqlite_open_nomutex"></a>

### const SQLITE_OPEN_NOMUTEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1392*

---

<a id="const-sqlite_open_fullmutex"></a>

### const SQLITE_OPEN_FULLMUTEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1393*

---

<a id="const-sqlite_open_sharedcache"></a>

### const SQLITE_OPEN_SHAREDCACHE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1394*

---

<a id="const-sqlite_open_privatecache"></a>

### const SQLITE_OPEN_PRIVATECACHE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1395*

---

<a id="const-sqlite_open_wal"></a>

### const SQLITE_OPEN_WAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1396*

---

<a id="const-sqlite_open_nofollow"></a>

### const SQLITE_OPEN_NOFOLLOW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1397*

---

<a id="const-sqlite_open_exrescode"></a>

### const SQLITE_OPEN_EXRESCODE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1398*

---

<a id="const-sqlite_open_master_journal"></a>

### const SQLITE_OPEN_MASTER_JOURNAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1399*

---

<a id="const-sqlite_iocap_atomic"></a>

### const SQLITE_IOCAP_ATOMIC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1400*

---

<a id="const-sqlite_iocap_atomic512"></a>

### const SQLITE_IOCAP_ATOMIC512: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1401*

---

<a id="const-sqlite_iocap_atomic1k"></a>

### const SQLITE_IOCAP_ATOMIC1K: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1402*

---

<a id="const-sqlite_iocap_atomic2k"></a>

### const SQLITE_IOCAP_ATOMIC2K: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1403*

---

<a id="const-sqlite_iocap_atomic4k"></a>

### const SQLITE_IOCAP_ATOMIC4K: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1404*

---

<a id="const-sqlite_iocap_atomic8k"></a>

### const SQLITE_IOCAP_ATOMIC8K: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1405*

---

<a id="const-sqlite_iocap_atomic16k"></a>

### const SQLITE_IOCAP_ATOMIC16K: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1406*

---

<a id="const-sqlite_iocap_atomic32k"></a>

### const SQLITE_IOCAP_ATOMIC32K: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1407*

---

<a id="const-sqlite_iocap_atomic64k"></a>

### const SQLITE_IOCAP_ATOMIC64K: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1408*

---

<a id="const-sqlite_iocap_safe_append"></a>

### const SQLITE_IOCAP_SAFE_APPEND: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1409*

---

<a id="const-sqlite_iocap_sequential"></a>

### const SQLITE_IOCAP_SEQUENTIAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1410*

---

<a id="const-sqlite_iocap_undeletable_when_open"></a>

### const SQLITE_IOCAP_UNDELETABLE_WHEN_OPEN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1411*

---

<a id="const-sqlite_iocap_powersafe_overwrite"></a>

### const SQLITE_IOCAP_POWERSAFE_OVERWRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1412*

---

<a id="const-sqlite_iocap_immutable"></a>

### const SQLITE_IOCAP_IMMUTABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1413*

---

<a id="const-sqlite_iocap_batch_atomic"></a>

### const SQLITE_IOCAP_BATCH_ATOMIC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1414*

---

<a id="const-sqlite_iocap_subpage_read"></a>

### const SQLITE_IOCAP_SUBPAGE_READ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1415*

---

<a id="const-sqlite_lock_none"></a>

### const SQLITE_LOCK_NONE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1416*

---

<a id="const-sqlite_lock_shared"></a>

### const SQLITE_LOCK_SHARED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1417*

---

<a id="const-sqlite_lock_reserved"></a>

### const SQLITE_LOCK_RESERVED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1418*

---

<a id="const-sqlite_lock_pending"></a>

### const SQLITE_LOCK_PENDING: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1419*

---

<a id="const-sqlite_lock_exclusive"></a>

### const SQLITE_LOCK_EXCLUSIVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1420*

---

<a id="const-sqlite_sync_normal"></a>

### const SQLITE_SYNC_NORMAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1421*

---

<a id="const-sqlite_sync_full"></a>

### const SQLITE_SYNC_FULL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1422*

---

<a id="const-sqlite_sync_dataonly"></a>

### const SQLITE_SYNC_DATAONLY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1423*

---

<a id="const-sqlite_fcntl_lockstate"></a>

### const SQLITE_FCNTL_LOCKSTATE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1424*

---

<a id="const-sqlite_fcntl_get_lockproxyfile"></a>

### const SQLITE_FCNTL_GET_LOCKPROXYFILE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1425*

---

<a id="const-sqlite_fcntl_set_lockproxyfile"></a>

### const SQLITE_FCNTL_SET_LOCKPROXYFILE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1426*

---

<a id="const-sqlite_fcntl_last_errno"></a>

### const SQLITE_FCNTL_LAST_ERRNO: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1427*

---

<a id="const-sqlite_fcntl_size_hint"></a>

### const SQLITE_FCNTL_SIZE_HINT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1428*

---

<a id="const-sqlite_fcntl_chunk_size"></a>

### const SQLITE_FCNTL_CHUNK_SIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1429*

---

<a id="const-sqlite_fcntl_file_pointer"></a>

### const SQLITE_FCNTL_FILE_POINTER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1430*

---

<a id="const-sqlite_fcntl_sync_omitted"></a>

### const SQLITE_FCNTL_SYNC_OMITTED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1431*

---

<a id="const-sqlite_fcntl_win32_av_retry"></a>

### const SQLITE_FCNTL_WIN32_AV_RETRY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1432*

---

<a id="const-sqlite_fcntl_persist_wal"></a>

### const SQLITE_FCNTL_PERSIST_WAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1433*

---

<a id="const-sqlite_fcntl_overwrite"></a>

### const SQLITE_FCNTL_OVERWRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1434*

---

<a id="const-sqlite_fcntl_vfsname"></a>

### const SQLITE_FCNTL_VFSNAME: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1435*

---

<a id="const-sqlite_fcntl_powersafe_overwrite"></a>

### const SQLITE_FCNTL_POWERSAFE_OVERWRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1436*

---

<a id="const-sqlite_fcntl_pragma"></a>

### const SQLITE_FCNTL_PRAGMA: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1437*

---

<a id="const-sqlite_fcntl_busyhandler"></a>

### const SQLITE_FCNTL_BUSYHANDLER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1438*

---

<a id="const-sqlite_fcntl_tempfilename"></a>

### const SQLITE_FCNTL_TEMPFILENAME: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1439*

---

<a id="const-sqlite_fcntl_mmap_size"></a>

### const SQLITE_FCNTL_MMAP_SIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1440*

---

<a id="const-sqlite_fcntl_trace"></a>

### const SQLITE_FCNTL_TRACE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1441*

---

<a id="const-sqlite_fcntl_has_moved"></a>

### const SQLITE_FCNTL_HAS_MOVED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1442*

---

<a id="const-sqlite_fcntl_sync"></a>

### const SQLITE_FCNTL_SYNC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1443*

---

<a id="const-sqlite_fcntl_commit_phasetwo"></a>

### const SQLITE_FCNTL_COMMIT_PHASETWO: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1444*

---

<a id="const-sqlite_fcntl_win32_set_handle"></a>

### const SQLITE_FCNTL_WIN32_SET_HANDLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1445*

---

<a id="const-sqlite_fcntl_wal_block"></a>

### const SQLITE_FCNTL_WAL_BLOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1446*

---

<a id="const-sqlite_fcntl_zipvfs"></a>

### const SQLITE_FCNTL_ZIPVFS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1447*

---

<a id="const-sqlite_fcntl_rbu"></a>

### const SQLITE_FCNTL_RBU: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1448*

---

<a id="const-sqlite_fcntl_vfs_pointer"></a>

### const SQLITE_FCNTL_VFS_POINTER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1449*

---

<a id="const-sqlite_fcntl_journal_pointer"></a>

### const SQLITE_FCNTL_JOURNAL_POINTER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1450*

---

<a id="const-sqlite_fcntl_win32_get_handle"></a>

### const SQLITE_FCNTL_WIN32_GET_HANDLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1451*

---

<a id="const-sqlite_fcntl_pdb"></a>

### const SQLITE_FCNTL_PDB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1452*

---

<a id="const-sqlite_fcntl_begin_atomic_write"></a>

### const SQLITE_FCNTL_BEGIN_ATOMIC_WRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1453*

---

<a id="const-sqlite_fcntl_commit_atomic_write"></a>

### const SQLITE_FCNTL_COMMIT_ATOMIC_WRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1454*

---

<a id="const-sqlite_fcntl_rollback_atomic_write"></a>

### const SQLITE_FCNTL_ROLLBACK_ATOMIC_WRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1455*

---

<a id="const-sqlite_fcntl_lock_timeout"></a>

### const SQLITE_FCNTL_LOCK_TIMEOUT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1456*

---

<a id="const-sqlite_fcntl_data_version"></a>

### const SQLITE_FCNTL_DATA_VERSION: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1457*

---

<a id="const-sqlite_fcntl_size_limit"></a>

### const SQLITE_FCNTL_SIZE_LIMIT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1458*

---

<a id="const-sqlite_fcntl_ckpt_done"></a>

### const SQLITE_FCNTL_CKPT_DONE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1459*

---

<a id="const-sqlite_fcntl_reserve_bytes"></a>

### const SQLITE_FCNTL_RESERVE_BYTES: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1460*

---

<a id="const-sqlite_fcntl_ckpt_start"></a>

### const SQLITE_FCNTL_CKPT_START: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1461*

---

<a id="const-sqlite_fcntl_external_reader"></a>

### const SQLITE_FCNTL_EXTERNAL_READER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1462*

---

<a id="const-sqlite_fcntl_cksm_file"></a>

### const SQLITE_FCNTL_CKSM_FILE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1463*

---

<a id="const-sqlite_fcntl_reset_cache"></a>

### const SQLITE_FCNTL_RESET_CACHE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1464*

---

<a id="const-sqlite_fcntl_null_io"></a>

### const SQLITE_FCNTL_NULL_IO: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1465*

---

<a id="const-sqlite_fcntl_block_on_connect"></a>

### const SQLITE_FCNTL_BLOCK_ON_CONNECT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1466*

---

<a id="const-sqlite_get_lockproxyfile"></a>

### const SQLITE_GET_LOCKPROXYFILE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1467*

---

<a id="const-sqlite_set_lockproxyfile"></a>

### const SQLITE_SET_LOCKPROXYFILE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1468*

---

<a id="const-sqlite_last_errno"></a>

### const SQLITE_LAST_ERRNO: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1469*

---

<a id="const-sqlite_access_exists"></a>

### const SQLITE_ACCESS_EXISTS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1470*

---

<a id="const-sqlite_access_readwrite"></a>

### const SQLITE_ACCESS_READWRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1471*

---

<a id="const-sqlite_access_read"></a>

### const SQLITE_ACCESS_READ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1472*

---

<a id="const-sqlite_shm_unlock"></a>

### const SQLITE_SHM_UNLOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1473*

---

<a id="const-sqlite_shm_lock"></a>

### const SQLITE_SHM_LOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1474*

---

<a id="const-sqlite_shm_shared"></a>

### const SQLITE_SHM_SHARED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1475*

---

<a id="const-sqlite_shm_exclusive"></a>

### const SQLITE_SHM_EXCLUSIVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1476*

---

<a id="const-sqlite_shm_nlock"></a>

### const SQLITE_SHM_NLOCK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1477*

---

<a id="const-sqlite_config_singlethread"></a>

### const SQLITE_CONFIG_SINGLETHREAD: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1478*

---

<a id="const-sqlite_config_multithread"></a>

### const SQLITE_CONFIG_MULTITHREAD: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1479*

---

<a id="const-sqlite_config_serialized"></a>

### const SQLITE_CONFIG_SERIALIZED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1480*

---

<a id="const-sqlite_config_malloc"></a>

### const SQLITE_CONFIG_MALLOC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1481*

---

<a id="const-sqlite_config_getmalloc"></a>

### const SQLITE_CONFIG_GETMALLOC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1482*

---

<a id="const-sqlite_config_scratch"></a>

### const SQLITE_CONFIG_SCRATCH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1483*

---

<a id="const-sqlite_config_pagecache"></a>

### const SQLITE_CONFIG_PAGECACHE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1484*

---

<a id="const-sqlite_config_heap"></a>

### const SQLITE_CONFIG_HEAP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1485*

---

<a id="const-sqlite_config_memstatus"></a>

### const SQLITE_CONFIG_MEMSTATUS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1486*

---

<a id="const-sqlite_config_mutex"></a>

### const SQLITE_CONFIG_MUTEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1487*

---

<a id="const-sqlite_config_getmutex"></a>

### const SQLITE_CONFIG_GETMUTEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1488*

---

<a id="const-sqlite_config_lookaside"></a>

### const SQLITE_CONFIG_LOOKASIDE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1489*

---

<a id="const-sqlite_config_pcache"></a>

### const SQLITE_CONFIG_PCACHE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1490*

---

<a id="const-sqlite_config_getpcache"></a>

### const SQLITE_CONFIG_GETPCACHE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1491*

---

<a id="const-sqlite_config_log"></a>

### const SQLITE_CONFIG_LOG: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1492*

---

<a id="const-sqlite_config_uri"></a>

### const SQLITE_CONFIG_URI: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1493*

---

<a id="const-sqlite_config_pcache2"></a>

### const SQLITE_CONFIG_PCACHE2: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1494*

---

<a id="const-sqlite_config_getpcache2"></a>

### const SQLITE_CONFIG_GETPCACHE2: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1495*

---

<a id="const-sqlite_config_covering_index_scan"></a>

### const SQLITE_CONFIG_COVERING_INDEX_SCAN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1496*

---

<a id="const-sqlite_config_sqllog"></a>

### const SQLITE_CONFIG_SQLLOG: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1497*

---

<a id="const-sqlite_config_mmap_size"></a>

### const SQLITE_CONFIG_MMAP_SIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1498*

---

<a id="const-sqlite_config_win32_heapsize"></a>

### const SQLITE_CONFIG_WIN32_HEAPSIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1499*

---

<a id="const-sqlite_config_pcache_hdrsz"></a>

### const SQLITE_CONFIG_PCACHE_HDRSZ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1500*

---

<a id="const-sqlite_config_pmasz"></a>

### const SQLITE_CONFIG_PMASZ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1501*

---

<a id="const-sqlite_config_stmtjrnl_spill"></a>

### const SQLITE_CONFIG_STMTJRNL_SPILL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1502*

---

<a id="const-sqlite_config_small_malloc"></a>

### const SQLITE_CONFIG_SMALL_MALLOC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1503*

---

<a id="const-sqlite_config_sorterref_size"></a>

### const SQLITE_CONFIG_SORTERREF_SIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1504*

---

<a id="const-sqlite_config_memdb_maxsize"></a>

### const SQLITE_CONFIG_MEMDB_MAXSIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1505*

---

<a id="const-sqlite_config_rowid_in_view"></a>

### const SQLITE_CONFIG_ROWID_IN_VIEW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1506*

---

<a id="const-sqlite_dbconfig_maindbname"></a>

### const SQLITE_DBCONFIG_MAINDBNAME: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1507*

---

<a id="const-sqlite_dbconfig_lookaside"></a>

### const SQLITE_DBCONFIG_LOOKASIDE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1508*

---

<a id="const-sqlite_dbconfig_enable_fkey"></a>

### const SQLITE_DBCONFIG_ENABLE_FKEY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1509*

---

<a id="const-sqlite_dbconfig_enable_trigger"></a>

### const SQLITE_DBCONFIG_ENABLE_TRIGGER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1510*

---

<a id="const-sqlite_dbconfig_enable_fts3_tokenizer"></a>

### const SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1511*

---

<a id="const-sqlite_dbconfig_enable_load_extension"></a>

### const SQLITE_DBCONFIG_ENABLE_LOAD_EXTENSION: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1512*

---

<a id="const-sqlite_dbconfig_no_ckpt_on_close"></a>

### const SQLITE_DBCONFIG_NO_CKPT_ON_CLOSE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1513*

---

<a id="const-sqlite_dbconfig_enable_qpsg"></a>

### const SQLITE_DBCONFIG_ENABLE_QPSG: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1514*

---

<a id="const-sqlite_dbconfig_trigger_eqp"></a>

### const SQLITE_DBCONFIG_TRIGGER_EQP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1515*

---

<a id="const-sqlite_dbconfig_reset_database"></a>

### const SQLITE_DBCONFIG_RESET_DATABASE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1516*

---

<a id="const-sqlite_dbconfig_defensive"></a>

### const SQLITE_DBCONFIG_DEFENSIVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1517*

---

<a id="const-sqlite_dbconfig_writable_schema"></a>

### const SQLITE_DBCONFIG_WRITABLE_SCHEMA: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1518*

---

<a id="const-sqlite_dbconfig_legacy_alter_table"></a>

### const SQLITE_DBCONFIG_LEGACY_ALTER_TABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1519*

---

<a id="const-sqlite_dbconfig_dqs_dml"></a>

### const SQLITE_DBCONFIG_DQS_DML: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1520*

---

<a id="const-sqlite_dbconfig_dqs_ddl"></a>

### const SQLITE_DBCONFIG_DQS_DDL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1521*

---

<a id="const-sqlite_dbconfig_enable_view"></a>

### const SQLITE_DBCONFIG_ENABLE_VIEW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1522*

---

<a id="const-sqlite_dbconfig_legacy_file_format"></a>

### const SQLITE_DBCONFIG_LEGACY_FILE_FORMAT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1523*

---

<a id="const-sqlite_dbconfig_trusted_schema"></a>

### const SQLITE_DBCONFIG_TRUSTED_SCHEMA: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1524*

---

<a id="const-sqlite_dbconfig_stmt_scanstatus"></a>

### const SQLITE_DBCONFIG_STMT_SCANSTATUS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1525*

---

<a id="const-sqlite_dbconfig_reverse_scanorder"></a>

### const SQLITE_DBCONFIG_REVERSE_SCANORDER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1526*

---

<a id="const-sqlite_dbconfig_enable_attach_create"></a>

### const SQLITE_DBCONFIG_ENABLE_ATTACH_CREATE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1527*

---

<a id="const-sqlite_dbconfig_enable_attach_write"></a>

### const SQLITE_DBCONFIG_ENABLE_ATTACH_WRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1528*

---

<a id="const-sqlite_dbconfig_enable_comments"></a>

### const SQLITE_DBCONFIG_ENABLE_COMMENTS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1529*

---

<a id="const-sqlite_dbconfig_max"></a>

### const SQLITE_DBCONFIG_MAX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1530*

---

<a id="const-sqlite_setlk_block_on_connect"></a>

### const SQLITE_SETLK_BLOCK_ON_CONNECT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1531*

---

<a id="const-sqlite_deny"></a>

### const SQLITE_DENY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1532*

---

<a id="const-sqlite_ignore"></a>

### const SQLITE_IGNORE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1533*

---

<a id="const-sqlite_create_index"></a>

### const SQLITE_CREATE_INDEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1534*

---

<a id="const-sqlite_create_table"></a>

### const SQLITE_CREATE_TABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1535*

---

<a id="const-sqlite_create_temp_index"></a>

### const SQLITE_CREATE_TEMP_INDEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1536*

---

<a id="const-sqlite_create_temp_table"></a>

### const SQLITE_CREATE_TEMP_TABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1537*

---

<a id="const-sqlite_create_temp_trigger"></a>

### const SQLITE_CREATE_TEMP_TRIGGER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1538*

---

<a id="const-sqlite_create_temp_view"></a>

### const SQLITE_CREATE_TEMP_VIEW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1539*

---

<a id="const-sqlite_create_trigger"></a>

### const SQLITE_CREATE_TRIGGER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1540*

---

<a id="const-sqlite_create_view"></a>

### const SQLITE_CREATE_VIEW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1541*

---

<a id="const-sqlite_delete"></a>

### const SQLITE_DELETE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1542*

---

<a id="const-sqlite_drop_index"></a>

### const SQLITE_DROP_INDEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1543*

---

<a id="const-sqlite_drop_table"></a>

### const SQLITE_DROP_TABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1544*

---

<a id="const-sqlite_drop_temp_index"></a>

### const SQLITE_DROP_TEMP_INDEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1545*

---

<a id="const-sqlite_drop_temp_table"></a>

### const SQLITE_DROP_TEMP_TABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1546*

---

<a id="const-sqlite_drop_temp_trigger"></a>

### const SQLITE_DROP_TEMP_TRIGGER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1547*

---

<a id="const-sqlite_drop_temp_view"></a>

### const SQLITE_DROP_TEMP_VIEW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1548*

---

<a id="const-sqlite_drop_trigger"></a>

### const SQLITE_DROP_TRIGGER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1549*

---

<a id="const-sqlite_drop_view"></a>

### const SQLITE_DROP_VIEW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1550*

---

<a id="const-sqlite_insert"></a>

### const SQLITE_INSERT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1551*

---

<a id="const-sqlite_pragma"></a>

### const SQLITE_PRAGMA: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1552*

---

<a id="const-sqlite_read"></a>

### const SQLITE_READ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1553*

---

<a id="const-sqlite_select"></a>

### const SQLITE_SELECT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1554*

---

<a id="const-sqlite_transaction"></a>

### const SQLITE_TRANSACTION: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1555*

---

<a id="const-sqlite_update"></a>

### const SQLITE_UPDATE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1556*

---

<a id="const-sqlite_attach"></a>

### const SQLITE_ATTACH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1557*

---

<a id="const-sqlite_detach"></a>

### const SQLITE_DETACH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1558*

---

<a id="const-sqlite_alter_table"></a>

### const SQLITE_ALTER_TABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1559*

---

<a id="const-sqlite_reindex"></a>

### const SQLITE_REINDEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1560*

---

<a id="const-sqlite_analyze"></a>

### const SQLITE_ANALYZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1561*

---

<a id="const-sqlite_create_vtable"></a>

### const SQLITE_CREATE_VTABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1562*

---

<a id="const-sqlite_drop_vtable"></a>

### const SQLITE_DROP_VTABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1563*

---

<a id="const-sqlite_function"></a>

### const SQLITE_FUNCTION: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1564*

---

<a id="const-sqlite_savepoint"></a>

### const SQLITE_SAVEPOINT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1565*

---

<a id="const-sqlite_copy"></a>

### const SQLITE_COPY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1566*

---

<a id="const-sqlite_recursive"></a>

### const SQLITE_RECURSIVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1567*

---

<a id="const-sqlite_trace_stmt"></a>

### const SQLITE_TRACE_STMT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1568*

---

<a id="const-sqlite_trace_profile"></a>

### const SQLITE_TRACE_PROFILE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1569*

---

<a id="const-sqlite_trace_row"></a>

### const SQLITE_TRACE_ROW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1570*

---

<a id="const-sqlite_trace_close"></a>

### const SQLITE_TRACE_CLOSE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1571*

---

<a id="const-sqlite_limit_length"></a>

### const SQLITE_LIMIT_LENGTH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1572*

---

<a id="const-sqlite_limit_sql_length"></a>

### const SQLITE_LIMIT_SQL_LENGTH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1573*

---

<a id="const-sqlite_limit_column"></a>

### const SQLITE_LIMIT_COLUMN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1574*

---

<a id="const-sqlite_limit_expr_depth"></a>

### const SQLITE_LIMIT_EXPR_DEPTH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1575*

---

<a id="const-sqlite_limit_compound_select"></a>

### const SQLITE_LIMIT_COMPOUND_SELECT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1576*

---

<a id="const-sqlite_limit_vdbe_op"></a>

### const SQLITE_LIMIT_VDBE_OP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1577*

---

<a id="const-sqlite_limit_function_arg"></a>

### const SQLITE_LIMIT_FUNCTION_ARG: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1578*

---

<a id="const-sqlite_limit_attached"></a>

### const SQLITE_LIMIT_ATTACHED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1579*

---

<a id="const-sqlite_limit_like_pattern_length"></a>

### const SQLITE_LIMIT_LIKE_PATTERN_LENGTH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1580*

---

<a id="const-sqlite_limit_variable_number"></a>

### const SQLITE_LIMIT_VARIABLE_NUMBER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1581*

---

<a id="const-sqlite_limit_trigger_depth"></a>

### const SQLITE_LIMIT_TRIGGER_DEPTH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1582*

---

<a id="const-sqlite_limit_worker_threads"></a>

### const SQLITE_LIMIT_WORKER_THREADS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1583*

---

<a id="const-sqlite_prepare_persistent"></a>

### const SQLITE_PREPARE_PERSISTENT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1584*

---

<a id="const-sqlite_prepare_normalize"></a>

### const SQLITE_PREPARE_NORMALIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1585*

---

<a id="const-sqlite_prepare_no_vtab"></a>

### const SQLITE_PREPARE_NO_VTAB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1586*

---

<a id="const-sqlite_prepare_dont_log"></a>

### const SQLITE_PREPARE_DONT_LOG: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1587*

---

<a id="const-sqlite_integer"></a>

### const SQLITE_INTEGER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1588*

---

<a id="const-sqlite_float"></a>

### const SQLITE_FLOAT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1589*

---

<a id="const-sqlite_blob"></a>

### const SQLITE_BLOB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1590*

---

<a id="const-sqlite_null"></a>

### const SQLITE_NULL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1591*

---

<a id="const-sqlite_text"></a>

### const SQLITE_TEXT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1592*

---

<a id="const-sqlite3_text"></a>

### const SQLITE3_TEXT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1593*

---

<a id="const-sqlite_utf8"></a>

### const SQLITE_UTF8: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1594*

---

<a id="const-sqlite_utf16le"></a>

### const SQLITE_UTF16LE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1595*

---

<a id="const-sqlite_utf16be"></a>

### const SQLITE_UTF16BE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1596*

---

<a id="const-sqlite_utf16"></a>

### const SQLITE_UTF16: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1597*

---

<a id="const-sqlite_any"></a>

### const SQLITE_ANY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1598*

---

<a id="const-sqlite_utf16_aligned"></a>

### const SQLITE_UTF16_ALIGNED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1599*

---

<a id="const-sqlite_deterministic"></a>

### const SQLITE_DETERMINISTIC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1600*

---

<a id="const-sqlite_directonly"></a>

### const SQLITE_DIRECTONLY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1601*

---

<a id="const-sqlite_subtype"></a>

### const SQLITE_SUBTYPE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1602*

---

<a id="const-sqlite_innocuous"></a>

### const SQLITE_INNOCUOUS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1603*

---

<a id="const-sqlite_result_subtype"></a>

### const SQLITE_RESULT_SUBTYPE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1604*

---

<a id="const-sqlite_selforder1"></a>

### const SQLITE_SELFORDER1: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1605*

---

<a id="const-sqlite_static"></a>

### const SQLITE_STATIC: func(\*void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:1606*

---

<a id="const-sqlite_transient"></a>

### const SQLITE_TRANSIENT: func(\*void) : void

*public* | *stdlib/std/db/sqlite/sqlite.lita:1607*

---

<a id="const-sqlite_win32_data_directory_type"></a>

### const SQLITE_WIN32_DATA_DIRECTORY_TYPE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1608*

---

<a id="const-sqlite_win32_temp_directory_type"></a>

### const SQLITE_WIN32_TEMP_DIRECTORY_TYPE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1609*

---

<a id="const-sqlite_txn_none"></a>

### const SQLITE_TXN_NONE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1610*

---

<a id="const-sqlite_txn_read"></a>

### const SQLITE_TXN_READ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1611*

---

<a id="const-sqlite_txn_write"></a>

### const SQLITE_TXN_WRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1612*

---

<a id="const-sqlite_index_scan_unique"></a>

### const SQLITE_INDEX_SCAN_UNIQUE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1613*

---

<a id="const-sqlite_index_scan_hex"></a>

### const SQLITE_INDEX_SCAN_HEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1614*

---

<a id="const-sqlite_index_constraint_eq"></a>

### const SQLITE_INDEX_CONSTRAINT_EQ: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1615*

---

<a id="const-sqlite_index_constraint_gt"></a>

### const SQLITE_INDEX_CONSTRAINT_GT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1616*

---

<a id="const-sqlite_index_constraint_le"></a>

### const SQLITE_INDEX_CONSTRAINT_LE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1617*

---

<a id="const-sqlite_index_constraint_lt"></a>

### const SQLITE_INDEX_CONSTRAINT_LT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1618*

---

<a id="const-sqlite_index_constraint_ge"></a>

### const SQLITE_INDEX_CONSTRAINT_GE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1619*

---

<a id="const-sqlite_index_constraint_match"></a>

### const SQLITE_INDEX_CONSTRAINT_MATCH: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1620*

---

<a id="const-sqlite_index_constraint_like"></a>

### const SQLITE_INDEX_CONSTRAINT_LIKE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1621*

---

<a id="const-sqlite_index_constraint_glob"></a>

### const SQLITE_INDEX_CONSTRAINT_GLOB: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1622*

---

<a id="const-sqlite_index_constraint_regexp"></a>

### const SQLITE_INDEX_CONSTRAINT_REGEXP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1623*

---

<a id="const-sqlite_index_constraint_ne"></a>

### const SQLITE_INDEX_CONSTRAINT_NE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1624*

---

<a id="const-sqlite_index_constraint_isnot"></a>

### const SQLITE_INDEX_CONSTRAINT_ISNOT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1625*

---

<a id="const-sqlite_index_constraint_isnotnull"></a>

### const SQLITE_INDEX_CONSTRAINT_ISNOTNULL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1626*

---

<a id="const-sqlite_index_constraint_isnull"></a>

### const SQLITE_INDEX_CONSTRAINT_ISNULL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1627*

---

<a id="const-sqlite_index_constraint_is"></a>

### const SQLITE_INDEX_CONSTRAINT_IS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1628*

---

<a id="const-sqlite_index_constraint_limit"></a>

### const SQLITE_INDEX_CONSTRAINT_LIMIT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1629*

---

<a id="const-sqlite_index_constraint_offset"></a>

### const SQLITE_INDEX_CONSTRAINT_OFFSET: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1630*

---

<a id="const-sqlite_index_constraint_function"></a>

### const SQLITE_INDEX_CONSTRAINT_FUNCTION: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1631*

---

<a id="const-sqlite_mutex_fast"></a>

### const SQLITE_MUTEX_FAST: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1632*

---

<a id="const-sqlite_mutex_recursive"></a>

### const SQLITE_MUTEX_RECURSIVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1633*

---

<a id="const-sqlite_mutex_static_main"></a>

### const SQLITE_MUTEX_STATIC_MAIN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1634*

---

<a id="const-sqlite_mutex_static_mem"></a>

### const SQLITE_MUTEX_STATIC_MEM: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1635*

---

<a id="const-sqlite_mutex_static_mem2"></a>

### const SQLITE_MUTEX_STATIC_MEM2: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1636*

---

<a id="const-sqlite_mutex_static_open"></a>

### const SQLITE_MUTEX_STATIC_OPEN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1637*

---

<a id="const-sqlite_mutex_static_prng"></a>

### const SQLITE_MUTEX_STATIC_PRNG: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1638*

---

<a id="const-sqlite_mutex_static_lru"></a>

### const SQLITE_MUTEX_STATIC_LRU: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1639*

---

<a id="const-sqlite_mutex_static_lru2"></a>

### const SQLITE_MUTEX_STATIC_LRU2: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1640*

---

<a id="const-sqlite_mutex_static_pmem"></a>

### const SQLITE_MUTEX_STATIC_PMEM: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1641*

---

<a id="const-sqlite_mutex_static_app1"></a>

### const SQLITE_MUTEX_STATIC_APP1: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1642*

---

<a id="const-sqlite_mutex_static_app2"></a>

### const SQLITE_MUTEX_STATIC_APP2: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1643*

---

<a id="const-sqlite_mutex_static_app3"></a>

### const SQLITE_MUTEX_STATIC_APP3: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1644*

---

<a id="const-sqlite_mutex_static_vfs1"></a>

### const SQLITE_MUTEX_STATIC_VFS1: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1645*

---

<a id="const-sqlite_mutex_static_vfs2"></a>

### const SQLITE_MUTEX_STATIC_VFS2: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1646*

---

<a id="const-sqlite_mutex_static_vfs3"></a>

### const SQLITE_MUTEX_STATIC_VFS3: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1647*

---

<a id="const-sqlite_mutex_static_master"></a>

### const SQLITE_MUTEX_STATIC_MASTER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1648*

---

<a id="const-sqlite_testctrl_first"></a>

### const SQLITE_TESTCTRL_FIRST: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1649*

---

<a id="const-sqlite_testctrl_prng_save"></a>

### const SQLITE_TESTCTRL_PRNG_SAVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1650*

---

<a id="const-sqlite_testctrl_prng_restore"></a>

### const SQLITE_TESTCTRL_PRNG_RESTORE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1651*

---

<a id="const-sqlite_testctrl_prng_reset"></a>

### const SQLITE_TESTCTRL_PRNG_RESET: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1652*

---

<a id="const-sqlite_testctrl_fk_no_action"></a>

### const SQLITE_TESTCTRL_FK_NO_ACTION: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1653*

---

<a id="const-sqlite_testctrl_bitvec_test"></a>

### const SQLITE_TESTCTRL_BITVEC_TEST: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1654*

---

<a id="const-sqlite_testctrl_fault_install"></a>

### const SQLITE_TESTCTRL_FAULT_INSTALL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1655*

---

<a id="const-sqlite_testctrl_benign_malloc_hooks"></a>

### const SQLITE_TESTCTRL_BENIGN_MALLOC_HOOKS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1656*

---

<a id="const-sqlite_testctrl_pending_byte"></a>

### const SQLITE_TESTCTRL_PENDING_BYTE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1657*

---

<a id="const-sqlite_testctrl_assert"></a>

### const SQLITE_TESTCTRL_ASSERT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1658*

---

<a id="const-sqlite_testctrl_always"></a>

### const SQLITE_TESTCTRL_ALWAYS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1659*

---

<a id="const-sqlite_testctrl_reserve"></a>

### const SQLITE_TESTCTRL_RESERVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1660*

---

<a id="const-sqlite_testctrl_json_selfcheck"></a>

### const SQLITE_TESTCTRL_JSON_SELFCHECK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1661*

---

<a id="const-sqlite_testctrl_optimizations"></a>

### const SQLITE_TESTCTRL_OPTIMIZATIONS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1662*

---

<a id="const-sqlite_testctrl_iskeyword"></a>

### const SQLITE_TESTCTRL_ISKEYWORD: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1663*

---

<a id="const-sqlite_testctrl_getopt"></a>

### const SQLITE_TESTCTRL_GETOPT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1664*

---

<a id="const-sqlite_testctrl_scratchmalloc"></a>

### const SQLITE_TESTCTRL_SCRATCHMALLOC: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1665*

---

<a id="const-sqlite_testctrl_internal_functions"></a>

### const SQLITE_TESTCTRL_INTERNAL_FUNCTIONS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1666*

---

<a id="const-sqlite_testctrl_localtime_fault"></a>

### const SQLITE_TESTCTRL_LOCALTIME_FAULT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1667*

---

<a id="const-sqlite_testctrl_explain_stmt"></a>

### const SQLITE_TESTCTRL_EXPLAIN_STMT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1668*

---

<a id="const-sqlite_testctrl_once_reset_threshold"></a>

### const SQLITE_TESTCTRL_ONCE_RESET_THRESHOLD: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1669*

---

<a id="const-sqlite_testctrl_never_corrupt"></a>

### const SQLITE_TESTCTRL_NEVER_CORRUPT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1670*

---

<a id="const-sqlite_testctrl_vdbe_coverage"></a>

### const SQLITE_TESTCTRL_VDBE_COVERAGE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1671*

---

<a id="const-sqlite_testctrl_byteorder"></a>

### const SQLITE_TESTCTRL_BYTEORDER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1672*

---

<a id="const-sqlite_testctrl_isinit"></a>

### const SQLITE_TESTCTRL_ISINIT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1673*

---

<a id="const-sqlite_testctrl_sorter_mmap"></a>

### const SQLITE_TESTCTRL_SORTER_MMAP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1674*

---

<a id="const-sqlite_testctrl_imposter"></a>

### const SQLITE_TESTCTRL_IMPOSTER: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1675*

---

<a id="const-sqlite_testctrl_parser_coverage"></a>

### const SQLITE_TESTCTRL_PARSER_COVERAGE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1676*

---

<a id="const-sqlite_testctrl_result_intreal"></a>

### const SQLITE_TESTCTRL_RESULT_INTREAL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1677*

---

<a id="const-sqlite_testctrl_prng_seed"></a>

### const SQLITE_TESTCTRL_PRNG_SEED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1678*

---

<a id="const-sqlite_testctrl_extra_schema_checks"></a>

### const SQLITE_TESTCTRL_EXTRA_SCHEMA_CHECKS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1679*

---

<a id="const-sqlite_testctrl_seek_count"></a>

### const SQLITE_TESTCTRL_SEEK_COUNT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1680*

---

<a id="const-sqlite_testctrl_traceflags"></a>

### const SQLITE_TESTCTRL_TRACEFLAGS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1681*

---

<a id="const-sqlite_testctrl_tune"></a>

### const SQLITE_TESTCTRL_TUNE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1682*

---

<a id="const-sqlite_testctrl_logest"></a>

### const SQLITE_TESTCTRL_LOGEST: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1683*

---

<a id="const-sqlite_testctrl_uselongdouble"></a>

### const SQLITE_TESTCTRL_USELONGDOUBLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1684*

---

<a id="const-sqlite_testctrl_last"></a>

### const SQLITE_TESTCTRL_LAST: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1685*

---

<a id="const-sqlite_status_memory_used"></a>

### const SQLITE_STATUS_MEMORY_USED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1686*

---

<a id="const-sqlite_status_pagecache_used"></a>

### const SQLITE_STATUS_PAGECACHE_USED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1687*

---

<a id="const-sqlite_status_pagecache_overflow"></a>

### const SQLITE_STATUS_PAGECACHE_OVERFLOW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1688*

---

<a id="const-sqlite_status_scratch_used"></a>

### const SQLITE_STATUS_SCRATCH_USED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1689*

---

<a id="const-sqlite_status_scratch_overflow"></a>

### const SQLITE_STATUS_SCRATCH_OVERFLOW: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1690*

---

<a id="const-sqlite_status_malloc_size"></a>

### const SQLITE_STATUS_MALLOC_SIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1691*

---

<a id="const-sqlite_status_parser_stack"></a>

### const SQLITE_STATUS_PARSER_STACK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1692*

---

<a id="const-sqlite_status_pagecache_size"></a>

### const SQLITE_STATUS_PAGECACHE_SIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1693*

---

<a id="const-sqlite_status_scratch_size"></a>

### const SQLITE_STATUS_SCRATCH_SIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1694*

---

<a id="const-sqlite_status_malloc_count"></a>

### const SQLITE_STATUS_MALLOC_COUNT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1695*

---

<a id="const-sqlite_dbstatus_lookaside_used"></a>

### const SQLITE_DBSTATUS_LOOKASIDE_USED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1696*

---

<a id="const-sqlite_dbstatus_cache_used"></a>

### const SQLITE_DBSTATUS_CACHE_USED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1697*

---

<a id="const-sqlite_dbstatus_schema_used"></a>

### const SQLITE_DBSTATUS_SCHEMA_USED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1698*

---

<a id="const-sqlite_dbstatus_stmt_used"></a>

### const SQLITE_DBSTATUS_STMT_USED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1699*

---

<a id="const-sqlite_dbstatus_lookaside_hit"></a>

### const SQLITE_DBSTATUS_LOOKASIDE_HIT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1700*

---

<a id="const-sqlite_dbstatus_lookaside_miss_size"></a>

### const SQLITE_DBSTATUS_LOOKASIDE_MISS_SIZE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1701*

---

<a id="const-sqlite_dbstatus_lookaside_miss_full"></a>

### const SQLITE_DBSTATUS_LOOKASIDE_MISS_FULL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1702*

---

<a id="const-sqlite_dbstatus_cache_hit"></a>

### const SQLITE_DBSTATUS_CACHE_HIT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1703*

---

<a id="const-sqlite_dbstatus_cache_miss"></a>

### const SQLITE_DBSTATUS_CACHE_MISS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1704*

---

<a id="const-sqlite_dbstatus_cache_write"></a>

### const SQLITE_DBSTATUS_CACHE_WRITE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1705*

---

<a id="const-sqlite_dbstatus_deferred_fks"></a>

### const SQLITE_DBSTATUS_DEFERRED_FKS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1706*

---

<a id="const-sqlite_dbstatus_cache_used_shared"></a>

### const SQLITE_DBSTATUS_CACHE_USED_SHARED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1707*

---

<a id="const-sqlite_dbstatus_cache_spill"></a>

### const SQLITE_DBSTATUS_CACHE_SPILL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1708*

---

<a id="const-sqlite_dbstatus_max"></a>

### const SQLITE_DBSTATUS_MAX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1709*

---

<a id="const-sqlite_stmtstatus_fullscan_step"></a>

### const SQLITE_STMTSTATUS_FULLSCAN_STEP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1710*

---

<a id="const-sqlite_stmtstatus_sort"></a>

### const SQLITE_STMTSTATUS_SORT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1711*

---

<a id="const-sqlite_stmtstatus_autoindex"></a>

### const SQLITE_STMTSTATUS_AUTOINDEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1712*

---

<a id="const-sqlite_stmtstatus_vm_step"></a>

### const SQLITE_STMTSTATUS_VM_STEP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1713*

---

<a id="const-sqlite_stmtstatus_reprepare"></a>

### const SQLITE_STMTSTATUS_REPREPARE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1714*

---

<a id="const-sqlite_stmtstatus_run"></a>

### const SQLITE_STMTSTATUS_RUN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1715*

---

<a id="const-sqlite_stmtstatus_filter_miss"></a>

### const SQLITE_STMTSTATUS_FILTER_MISS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1716*

---

<a id="const-sqlite_stmtstatus_filter_hit"></a>

### const SQLITE_STMTSTATUS_FILTER_HIT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1717*

---

<a id="const-sqlite_stmtstatus_memused"></a>

### const SQLITE_STMTSTATUS_MEMUSED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1718*

---

<a id="const-sqlite_checkpoint_passive"></a>

### const SQLITE_CHECKPOINT_PASSIVE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1719*

---

<a id="const-sqlite_checkpoint_full"></a>

### const SQLITE_CHECKPOINT_FULL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1720*

---

<a id="const-sqlite_checkpoint_restart"></a>

### const SQLITE_CHECKPOINT_RESTART: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1721*

---

<a id="const-sqlite_checkpoint_truncate"></a>

### const SQLITE_CHECKPOINT_TRUNCATE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1722*

---

<a id="const-sqlite_vtab_constraint_support"></a>

### const SQLITE_VTAB_CONSTRAINT_SUPPORT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1723*

---

<a id="const-sqlite_vtab_innocuous"></a>

### const SQLITE_VTAB_INNOCUOUS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1724*

---

<a id="const-sqlite_vtab_directonly"></a>

### const SQLITE_VTAB_DIRECTONLY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1725*

---

<a id="const-sqlite_vtab_uses_all_schemas"></a>

### const SQLITE_VTAB_USES_ALL_SCHEMAS: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1726*

---

<a id="const-sqlite_rollback"></a>

### const SQLITE_ROLLBACK: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1727*

---

<a id="const-sqlite_fail"></a>

### const SQLITE_FAIL: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1728*

---

<a id="const-sqlite_replace"></a>

### const SQLITE_REPLACE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1729*

---

<a id="const-sqlite_scanstat_nloop"></a>

### const SQLITE_SCANSTAT_NLOOP: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1730*

---

<a id="const-sqlite_scanstat_nvisit"></a>

### const SQLITE_SCANSTAT_NVISIT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1731*

---

<a id="const-sqlite_scanstat_est"></a>

### const SQLITE_SCANSTAT_EST: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1732*

---

<a id="const-sqlite_scanstat_name"></a>

### const SQLITE_SCANSTAT_NAME: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1733*

---

<a id="const-sqlite_scanstat_explain"></a>

### const SQLITE_SCANSTAT_EXPLAIN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1734*

---

<a id="const-sqlite_scanstat_selectid"></a>

### const SQLITE_SCANSTAT_SELECTID: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1735*

---

<a id="const-sqlite_scanstat_parentid"></a>

### const SQLITE_SCANSTAT_PARENTID: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1736*

---

<a id="const-sqlite_scanstat_ncycle"></a>

### const SQLITE_SCANSTAT_NCYCLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1737*

---

<a id="const-sqlite_scanstat_complex"></a>

### const SQLITE_SCANSTAT_COMPLEX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1738*

---

<a id="const-sqlite_serialize_nocopy"></a>

### const SQLITE_SERIALIZE_NOCOPY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1739*

---

<a id="const-sqlite_deserialize_freeonclose"></a>

### const SQLITE_DESERIALIZE_FREEONCLOSE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1740*

---

<a id="const-sqlite_deserialize_resizeable"></a>

### const SQLITE_DESERIALIZE_RESIZEABLE: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1741*

---

<a id="const-sqlite_deserialize_readonly"></a>

### const SQLITE_DESERIALIZE_READONLY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1742*

---

<a id="const-not_within"></a>

### const NOT_WITHIN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1744*

---

<a id="const-partly_within"></a>

### const PARTLY_WITHIN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1745*

---

<a id="const-fully_within"></a>

### const FULLY_WITHIN: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1746*

---

<a id="const-fts5_tokenize_query"></a>

### const FTS5_TOKENIZE_QUERY: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1748*

---

<a id="const-fts5_tokenize_prefix"></a>

### const FTS5_TOKENIZE_PREFIX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1749*

---

<a id="const-fts5_tokenize_document"></a>

### const FTS5_TOKENIZE_DOCUMENT: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1750*

---

<a id="const-fts5_tokenize_aux"></a>

### const FTS5_TOKENIZE_AUX: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1751*

---

<a id="const-fts5_token_colocated"></a>

### const FTS5_TOKEN_COLOCATED: i32

*public* | *stdlib/std/db/sqlite/sqlite.lita:1752*

---

