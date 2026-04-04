# std::zip::miniz::miniz

## Functions

<a id="func-mz_zip_get_last_error"></a>

### func mz_zip_get_last_error(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive)) : i32

*public* | *stdlib/std/zip/miniz/miniz.lita:84*

---

<a id="func-mz_zip_get_error_string"></a>

### func mz_zip_get_error_string(error: i32) : \*const char

*public* | *stdlib/std/zip/miniz/miniz.lita:87*

---

<a id="func-mz_zip_end"></a>

### func mz_zip_end(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive)) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:90*

---

<a id="func-mz_zip_validate_archive"></a>

### func mz_zip_validate_archive(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive), flags: u32) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:93*

---

<a id="func-mz_zip_reader_init_file"></a>

### func mz_zip_reader_init_file(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive), filename: \*const char, flags: i32) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:99*

---

<a id="func-mz_zip_extract_archive_file_to_path"></a>

### func mz_zip_extract_archive_file_to_path(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive), path: \*const char) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:102*

---

<a id="func-mz_zip_reader_get_num_files"></a>

### func mz_zip_reader_get_num_files(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive)) : i32

*public* | *stdlib/std/zip/miniz/miniz.lita:105*

---

<a id="func-mz_zip_reader_file_stat"></a>

### func mz_zip_reader_file_stat(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive), fileIndex: i32, fileStat: \*[mz_zip_archive_file_stat](std_zip_miniz_miniz.md#struct-mz_zip_archive_file_stat)) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:108*

---

<a id="func-mz_zip_reader_is_file_a_directory"></a>

### func mz_zip_reader_is_file_a_directory(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive), fileIndex: i32) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:111*

---

<a id="func-mz_zip_reader_extract_to_file"></a>

### func mz_zip_reader_extract_to_file(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive), fileIndex: i32, destFilename: \*const char, flags: u32) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:114*

---

<a id="func-mz_zip_writer_init_file"></a>

### func mz_zip_writer_init_file(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive), filename: \*const char, size_to_reserve_at_beginning: i32) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:121*

---

<a id="func-mz_zip_writer_add_file"></a>

### func mz_zip_writer_add_file(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive), archiveName: \*const char, filename: \*const char, comment: \*const void, commentSize: u16, levelAndFlags: u32) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:127*

---

<a id="func-mz_zip_writer_finalize_archive"></a>

### func mz_zip_writer_finalize_archive(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive)) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:139*

---

<a id="func-mz_zip_writer_end"></a>

### func mz_zip_writer_end(archive: \*[mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive)) : bool

*public* | *stdlib/std/zip/miniz/miniz.lita:142*

---

<a id="func-mz_compress"></a>

### func mz_compress(pDest: \*u8, pDest_len: \*[mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong), pSource: \*const u8, source_len: [mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong)) : i32

*public* | *stdlib/std/zip/miniz/miniz.lita:150*

---

<a id="func-mz_compress2"></a>

### func mz_compress2(pDest: \*u8, pDest_len: \*[mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong), pSource: \*const u8, source_len: [mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong), level: i32) : i32

*public* | *stdlib/std/zip/miniz/miniz.lita:153*

---

<a id="func-mz_compressbound"></a>

### func mz_compressBound(source_len: [mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong)) : [mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong)

*public* | *stdlib/std/zip/miniz/miniz.lita:157*

---

<a id="func-mz_uncompress"></a>

### func mz_uncompress(pDest: \*u8, pDest_len: \*[mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong), pSource: \*const u8, source_len: [mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong)) : i32

*public* | *stdlib/std/zip/miniz/miniz.lita:163*

---

<a id="func-mz_uncompress2"></a>

### func mz_uncompress2(pDest: \*u8, pDest_len: \*[mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong), pSource: \*const u8, source_len: \*[mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong)) : i32

*public* | *stdlib/std/zip/miniz/miniz.lita:165*

---

## Types

<a id="typedef-mz_ulong"></a>

### typedef mz_ulong = void

*public* | *stdlib/std/zip/miniz/miniz.lita:22*

---

<a id="enum-mz_zip_flags"></a>

### enum mz_zip_flags

*public* | *stdlib/std/zip/miniz/miniz.lita:25*

| Value | Description |
|-------|-------------|
| `MZ_ZIP_FLAG_CASE_SENSITIVE` |  |
| `MZ_ZIP_FLAG_IGNORE_PATH` |  |
| `MZ_ZIP_FLAG_COMPRESSED_DATA` |  |
| `MZ_ZIP_FLAG_DO_NOT_SORT_CENTRAL_DIRECTORY` |  |
| `MZ_ZIP_FLAG_VALIDATE_LOCATE_FILE_FLAG` |  |
| `MZ_ZIP_FLAG_VALIDATE_HEADERS_ONLY` |  |
| `MZ_ZIP_FLAG_WRITE_ZIP64` |  |
| `MZ_ZIP_FLAG_WRITE_ALLOW_READING` |  |
| `MZ_ZIP_FLAG_ASCII_FILENAME` |  |
| `MZ_ZIP_FLAG_WRITE_HEADER_SET_SIZE` |  |

---

<a id="enum-compressionstrategy"></a>

### enum CompressionStrategy

*public* | *stdlib/std/zip/miniz/miniz.lita:41*

| Value | Description |
|-------|-------------|
| `MZ_DEFAULT_STRATEGY` |  |
| `MZ_FILTERED` |  |
| `MZ_HUFFMAN_ONLY` |  |
| `MZ_RLE` |  |
| `MZ_FIXED` |  |

---

<a id="enum-compressionlevel"></a>

### enum CompressionLevel

*public* | *stdlib/std/zip/miniz/miniz.lita:52*

| Value | Description |
|-------|-------------|
| `MZ_NO_COMPRESSION` |  |
| `MZ_BEST_SPEED` |  |
| `MZ_BEST_COMPRESSION` |  |
| `MZ_UBER_COMPRESSION` |  |
| `MZ_DEFAULT_LEVEL` |  |
| `MZ_DEFAULT_COMPRESSION` |  |

---

<a id="struct-mz_zip_archive"></a>

### struct mz_zip_archive

*public* | *stdlib/std/zip/miniz/miniz.lita:63*

| Field | Type | Description |
|-------|------|-------------|
| `m_pAlloc` | func(\*void, usize, usize) : \*void |  |
| `m_pFree` | func(\*void, \*void) : void |  |
| `m_pRealloc` | func(\*void, \*void, usize, usize, usize, usize) : \*void |  |
| `m_pAlloc_opaque` | \*void |  |
| `m_last_error` | i32 |  |
| `m_pState` | \*[mz_zip_internal_state_tag](std_zip_miniz_miniz.md#struct-mz_zip_internal_state_tag) |  |
| `m_archive_size` | [mz_ulong](std_zip_miniz_miniz.md#typedef-mz_ulong) |  |

---

<a id="struct-mz_zip_internal_state_tag"></a>

### struct mz_zip_internal_state_tag

*public* | *stdlib/std/zip/miniz/miniz.lita:74*

| Field | Type | Description |
|-------|------|-------------|
| `m_pFile` | \*[FILE](std_libc.md#struct-file) |  |

---

<a id="struct-mz_zip_archive_file_stat"></a>

### struct mz_zip_archive_file_stat

*public* | *stdlib/std/zip/miniz/miniz.lita:79*

| Field | Type | Description |
|-------|------|-------------|
| `m_filename` | \*char |  |

---

## Variables and Constants

<a id="const-mz_zip_max_archive_filename_size"></a>

### const MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE: i32

*public* | *stdlib/std/zip/miniz/miniz.lita:7*

---

<a id="const-mz_zip_max_io_buf_size"></a>

### const MZ_ZIP_MAX_IO_BUF_SIZE: i32

*public* | *stdlib/std/zip/miniz/miniz.lita:10*

---

<a id="const-mz_ok"></a>

### const MZ_OK: i32

*public* | *stdlib/std/zip/miniz/miniz.lita:14*

---

<a id="const-z_mem_error"></a>

### const Z_MEM_ERROR: i32

*public* | *stdlib/std/zip/miniz/miniz.lita:16*

---

<a id="const-mz_buf_error"></a>

### const MZ_BUF_ERROR: i32

*public* | *stdlib/std/zip/miniz/miniz.lita:19*

---

