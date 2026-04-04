# std::mem::virtual_mem_posix

## Functions

<a id="func-getospagesize"></a>

### func GetOSPageSize() : i64

*public* | *stdlib/std/mem/virtual_mem_posix.lita:84*

---

<a id="func-virtualalloc"></a>

### func VirtualAlloc(size: usize, large: bool) : \*void

*public* | *stdlib/std/mem/virtual_mem_posix.lita:88*

---

<a id="func-virtualreserve"></a>

### func VirtualReserve(size: usize, large: bool) : \*void

*public* | *stdlib/std/mem/virtual_mem_posix.lita:92*

---

<a id="func-virtualcommit"></a>

### func VirtualCommit(addr: \*void, size: usize) : i32

*public* | *stdlib/std/mem/virtual_mem_posix.lita:96*

---

<a id="func-virtualuncommit"></a>

### func VirtualUncommit(addr: \*void, size: usize) : i32

*public* | *stdlib/std/mem/virtual_mem_posix.lita:100*

---

<a id="func-virtualfree"></a>

### func VirtualFree(mem: \*void, size: usize) : i32

*public* | *stdlib/std/mem/virtual_mem_posix.lita:104*

---

