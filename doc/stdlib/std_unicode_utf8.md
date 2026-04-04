# std::unicode::utf8

## Functions

<a id="func-utf8decode"></a>

### func Utf8Decode(str: \*const u8, len: i32, codepoint: \*[rune](std_unicode_utf8.md#typedef-rune)) : i32

*public* | *stdlib/std/unicode/utf8/utf8.lita:29*


    Reads a single codepoint from the UTF-8 sequence being pointed to by `str`. The maximum number of bytes read is `len`,
    unless `len` is negative (in which case up to 4 bytes are read).

    If a valid codepoint could be read, it is stored in the variable pointed to by `codepoint`, otherwise that variable will be set to -1.
    In case of success, the number of bytes read is returned; otherwise, a negative error code is returned.


---

<a id="func-utf8hexdecode"></a>

### func Utf8HexDecode(str: \*const char, len: i32) : [rune](std_unicode_utf8.md#typedef-rune)

*public* | *stdlib/std/unicode/utf8/utf8.lita:35*

---

<a id="func-utf8encode"></a>

### func Utf8Encode(codepoint: [rune](std_unicode_utf8.md#typedef-rune), dst: \*u8) : i32

*public* | *stdlib/std/unicode/utf8/utf8.lita:54*


    Encodes the codepoint as an UTF-8 string in the byte array pointed to by dst. This array must be at least 4 bytes long.

    In case of success the number of bytes written is returned, and otherwise 0 is returned.

    This function does not check whether codepoint is valid Unicode.


---

<a id="func-utf8charwidth"></a>

### func Utf8CharWidth(codepoint: [rune](std_unicode_utf8.md#typedef-rune)) : i32

*public* | *stdlib/std/unicode/utf8/utf8.lita:289*


    Given a codepoint, return a character width.  Width of -1 is returned for
    non-printable codepoints.  Width of 0 is returned for combining/zero-width
    characters.  Width of 2 is returned for East Asian Wide/Full-width characters.
    All other printable characters return width 1.


---

<a id="func-utf8codepointvalid"></a>

### func Utf8CodepointValid(codepoint: [rune](std_unicode_utf8.md#typedef-rune)) : bool

*public* | *stdlib/std/unicode/utf8/utf8.lita:318*

---

## Types

<a id="typedef-rune"></a>

### typedef rune = i32

*public* | *stdlib/std/unicode/utf8/utf8.lita:11*


    A unicode codepoint


---

## Variables and Constants

<a id="const-invalid_rune"></a>

### const INVALID_RUNE: [rune](std_unicode_utf8.md#typedef-rune)

*public* | *stdlib/std/unicode/utf8/utf8.lita:14*

'error' rune, unicode codepoint 'Replacement Character'

---

<a id="const-max_rune"></a>

### const MAX_RUNE: [rune](std_unicode_utf8.md#typedef-rune)

*public* | *stdlib/std/unicode/utf8/utf8.lita:17*

Maximum valid unicode code point

---

<a id="const-max_rune_bytes"></a>

### const MAX_RUNE_BYTES

*public* | *stdlib/std/unicode/utf8/utf8.lita:20*

Maximum number of bytes for a UTF8 encoded unicode code point

---

