# std::mem::libc_allocator

## Functions

<a id="func-cmalloc"></a>

### func cMalloc(a: \*const [Allocator](std_mem.md#struct-allocator), size: usize) : \*void

*public* | *stdlib/std/mem/libc_allocator.lita:49*

---

<a id="func-ccalloc"></a>

### func cCalloc(a: \*const [Allocator](std_mem.md#struct-allocator), num: usize, size: usize) : \*void

*public* | *stdlib/std/mem/libc_allocator.lita:53*

---

<a id="func-crealloc"></a>

### func cRealloc(a: \*const [Allocator](std_mem.md#struct-allocator), ptr: \*void, oldSize: usize, size: usize) : \*void

*public* | *stdlib/std/mem/libc_allocator.lita:57*

---

<a id="func-cfree"></a>

### func cFree(a: \*const [Allocator](std_mem.md#struct-allocator), ptr: \*void) : void

*public* | *stdlib/std/mem/libc_allocator.lita:61*

---

## Variables and Constants

<a id="const-callocator"></a>

### const cAllocator: \*const [Allocator](std_mem.md#struct-allocator)

*public* | *stdlib/std/mem/libc_allocator.lita:9*

---

