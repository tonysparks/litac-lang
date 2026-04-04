# std::mem::virtual_mem_win

## Functions

<a id="func-getospagesize"></a>

### func GetOSPageSize() : i64

*public* | *stdlib/std/mem/virtual_mem_win.lita:82*

---

<a id="func-virtualalloc"></a>

### func VirtualAlloc(size: usize, large: bool) : \*void

*public* | *stdlib/std/mem/virtual_mem_win.lita:89*

---

<a id="func-virtualreserve"></a>

### func VirtualReserve(size: usize, large: bool) : \*void

*public* | *stdlib/std/mem/virtual_mem_win.lita:93*

---

<a id="func-virtualcommit"></a>

### func VirtualCommit(addr: \*void, size: usize) : i32

*public* | *stdlib/std/mem/virtual_mem_win.lita:97*

---

<a id="func-virtualuncommit"></a>

### func VirtualUncommit(addr: \*void, size: usize) : i32

*public* | *stdlib/std/mem/virtual_mem_win.lita:101*

---

<a id="func-virtualfree"></a>

### func VirtualFree(mem: \*void, size: usize) : i32

*public* | *stdlib/std/mem/virtual_mem_win.lita:105*

---

