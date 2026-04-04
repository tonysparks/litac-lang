# std::zip::zip

## Functions

<a id="func-zipcompress"></a>

### func ZipCompress(buffer: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), source: String, level: [ZipCompressionLevel](std_zip_zip.md#enum-zipcompressionlevel)) : [ZipStatus](std_zip_zip.md#enum-zipstatus)

*public* | *stdlib/std/zip/zip.lita:51*

---

<a id="func-zipuncompress"></a>

### func ZipUncompress(buffer: \*[StringBuilder](std_string_builder.md#struct-stringbuilder), source: String) : [ZipStatus](std_zip_zip.md#enum-zipstatus)

*public* | *stdlib/std/zip/zip.lita:80*

---

<a id="func-open"></a>

### func (this: \*[ZipFile](std_zip_zip.md#struct-zipfile)) open(filename: \*const char, type: [ZipOpen](std_zip_zip.md#enum-zipopen), allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [ZipStatus](std_zip_zip.md#enum-zipstatus)

*public* | *stdlib/std/zip/zip.lita:155*

---

<a id="func-close"></a>

### func (this: \*[ZipFile](std_zip_zip.md#struct-zipfile)) close() : [ZipStatus](std_zip_zip.md#enum-zipstatus)

*public* | *stdlib/std/zip/zip.lita:186*

---

<a id="func-finalize"></a>

### func (this: \*[ZipFile](std_zip_zip.md#struct-zipfile)) finalize() : [ZipStatus](std_zip_zip.md#enum-zipstatus)

*public* | *stdlib/std/zip/zip.lita:205*


    When writing to the zip file, finalize must be called to mark
    the completion of writing.


---

<a id="func-isvalid"></a>

### func (this: \*[ZipFile](std_zip_zip.md#struct-zipfile)) isValid() : bool

*public* | *stdlib/std/zip/zip.lita:212*

---

<a id="func-getlasterror"></a>

### func (this: \*[ZipFile](std_zip_zip.md#struct-zipfile)) getLastError() : \*const char

*public* | *stdlib/std/zip/zip.lita:216*

---

<a id="func-zipdir"></a>

### func (this: \*[ZipFile](std_zip_zip.md#struct-zipfile)) zipDir(pathToZip: \*const char, len: i32, baseName: \*const char, level: [ZipCompressionLevel](std_zip_zip.md#enum-zipcompressionlevel)) : [ZipStatus](std_zip_zip.md#enum-zipstatus)

*public* | *stdlib/std/zip/zip.lita:220*

---

<a id="func-addfile"></a>

### func (this: \*[ZipFile](std_zip_zip.md#struct-zipfile)) addFile(archiveName: \*const char, filename: \*const char, level: [ZipCompressionLevel](std_zip_zip.md#enum-zipcompressionlevel)) : [ZipStatus](std_zip_zip.md#enum-zipstatus)

*public* | *stdlib/std/zip/zip.lita:285*

---

<a id="func-unzip"></a>

### func (this: \*[ZipFile](std_zip_zip.md#struct-zipfile)) unzip(dest: \*const char, extractedFiles: \*[Array](std_array.md#struct-array)\<\*const char\>, flags: i32) : [ZipStatus](std_zip_zip.md#enum-zipstatus)

*public* | *stdlib/std/zip/zip.lita:310*


    dest - the destination folder to write the zipped files to
    extractedFiles - optional parameter to store the unzipped file names, if this is supplied
        than a copy of the string is stored in this Array.  It is up to the caller of this function
        to manage the memory.  The allocation uses the allocator used in ZipFile.open.
    flags - optional parameter, @see ZipFlags


---

## Types

<a id="enum-zipopen"></a>

### enum ZipOpen

*public* | *stdlib/std/zip/zip.lita:17*


    Open for either writing or reading


| Value | Description |
|-------|-------------|
| `READ` |  |
| `WRITE` |  |

---

<a id="enum-zipflags"></a>

### enum ZipFlags

*public* | *stdlib/std/zip/zip.lita:22*

| Value | Description |
|-------|-------------|
| `INCLUDE_ZIPFILE_NAME_ON_UNZIP` |  |

---

<a id="enum-zipstatus"></a>

### enum ZipStatus

*public* | *stdlib/std/zip/zip.lita:27*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `ERROR_UNABLE_TO_OPEN_FILE` |  |
| `ERROR_UNABLE_TO_STAT` |  |
| `ERROR_UNABLE_CREATE_DIR` |  |
| `ERROR_UNABLE_WRITE_FILE` |  |
| `ERROR_ADDING_FILE` |  |
| `ERROR_CLOSING` |  |
| `ERROR_FINALIZING` |  |
| `ERROR_OUT_OF_MEMORY` |  |
| `ERROR_COMPRESSING` |  |
| `ERROR_DECOMPRESSING` |  |

---

<a id="enum-zipcompressionlevel"></a>

### enum ZipCompressionLevel

*public* | *stdlib/std/zip/zip.lita:42*

| Value | Description |
|-------|-------------|
| `NO_COMPRESSION` |  |
| `BEST_SPEED` |  |
| `BEST_COMPRESSION` |  |
| `UBER_COMPRESSION` |  |
| `DEFAULT_LEVEL` |  |

---

<a id="struct-zipfile"></a>

### struct ZipFile

*public* | *stdlib/std/zip/zip.lita:122*

| Field | Type | Description |
|-------|------|-------------|
| `archive` | [mz_zip_archive](std_zip_miniz_miniz.md#struct-mz_zip_archive) |  |
| `type` | [ZipOpen](std_zip_zip.md#enum-zipopen) |  |
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |

---

