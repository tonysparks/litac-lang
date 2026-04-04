# std::mem

## Functions

<a id="func-new"></a>

### func new\<T\>(a: \*const [Allocator](std_mem.md#struct-allocator)) : \*T

*public* | *stdlib/std/mem/mem.lita:36*

---

<a id="func-memduplicate"></a>

### func memduplicate(p: \*const void, len: usize, a: \*const [Allocator](std_mem.md#struct-allocator)) : \*void

*public* | *stdlib/std/mem/mem.lita:48*

---

<a id="func-ispoweroftwo"></a>

### func isPowerOfTwo(x: usize) : bool

*public* | *stdlib/std/mem/mem.lita:61*

---

<a id="func-alignforward"></a>

### func alignForward(ptr: usize, align: usize) : usize

*public* | *stdlib/std/mem/mem.lita:65*

---

<a id="func-alloc"></a>

### func alloc(a: \*const [Allocator](std_mem.md#struct-allocator), size: usize) : \*void

*public* | *stdlib/std/mem/mem.lita:132*

---

<a id="func-calloc"></a>

### func calloc(a: \*const [Allocator](std_mem.md#struct-allocator), num: usize, size: usize) : \*void

*public* | *stdlib/std/mem/mem.lita:137*

---

<a id="func-realloc"></a>

### func realloc(a: \*const [Allocator](std_mem.md#struct-allocator), ptr: \*void, oldsize: usize, newsize: usize) : \*void

*public* | *stdlib/std/mem/mem.lita:142*

---

<a id="func-free"></a>

### func free(a: \*const [Allocator](std_mem.md#struct-allocator), ptr: \*void) : void

*public* | *stdlib/std/mem/mem.lita:147*

---

<a id="func-genericmalloc"></a>

### func GenericMalloc\<T\>(alloc: \*const [Allocator](std_mem.md#struct-allocator), size: usize) : \*void

*public* | *stdlib/std/mem/mem.lita:200*

---

<a id="func-genericcalloc"></a>

### func GenericCalloc\<T\>(alloc: \*const [Allocator](std_mem.md#struct-allocator), num: usize, size: usize) : \*void

*public* | *stdlib/std/mem/mem.lita:206*

---

<a id="func-genericrealloc"></a>

### func GenericRealloc\<T\>(alloc: \*const [Allocator](std_mem.md#struct-allocator), ptr: \*void, oldSize: usize, size: usize) : \*void

*public* | *stdlib/std/mem/mem.lita:218*

---

## Types

<a id="struct-allocator"></a>

### struct Allocator

*public* | *stdlib/std/mem/mem.lita:124*

| Field | Type | Description |
|-------|------|-------------|
| `allocFn` | func(\*const [Allocator](std_mem.md#struct-allocator), usize) : \*void |  |
| `callocFn` | func(\*const [Allocator](std_mem.md#struct-allocator), usize, usize) : \*void |  |
| `reallocFn` | func(\*const [Allocator](std_mem.md#struct-allocator), \*void, usize, usize) : \*void |  |
| `freeFn` | func(\*const [Allocator](std_mem.md#struct-allocator), \*void) : void |  |

---

## Variables and Constants

<a id="const-litac_default_alignment"></a>

### const LITAC_DEFAULT_ALIGNMENT: usize

*public* | *stdlib/std/mem/mem.lita:12*

---

<a id="const-kib"></a>

### const KiB: usize

*public* | *stdlib/std/mem/mem.lita:14*

---

<a id="const-mib"></a>

### const MiB: usize

*public* | *stdlib/std/mem/mem.lita:15*

---

<a id="const-gib"></a>

### const GiB: usize

*public* | *stdlib/std/mem/mem.lita:16*

---

<a id="var-defaultallocator"></a>

### var defaultAllocator: \*const [Allocator](std_mem.md#struct-allocator)

*public* | *stdlib/std/mem/mem.lita:269*

---

