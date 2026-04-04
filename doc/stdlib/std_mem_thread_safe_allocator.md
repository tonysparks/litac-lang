# std::mem::thread_safe_allocator

## Functions

<a id="func-init"></a>

### func (this: \*[ThreadSafeAllocator](std_mem_thread_safe_allocator.md#struct-threadsafeallocator)) init(decorated: \*const [Allocator](std_mem.md#struct-allocator)) : void

*public* | *stdlib/std/mem/thread_safe_allocator.lita:19*

---

<a id="func-free"></a>

### func (this: \*[ThreadSafeAllocator](std_mem_thread_safe_allocator.md#struct-threadsafeallocator)) free() : void

*public* | *stdlib/std/mem/thread_safe_allocator.lita:32*

Free all memory associated with this allocator.

---

<a id="func-malloc"></a>

### func (this: \*[ThreadSafeAllocator](std_mem_thread_safe_allocator.md#struct-threadsafeallocator)) malloc(size: usize) : \*void

*public* | *stdlib/std/mem/thread_safe_allocator.lita:36*

---

## Types

<a id="struct-threadsafeallocator"></a>

### struct ThreadSafeAllocator

*public* | *stdlib/std/mem/thread_safe_allocator.lita:12*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | [Allocator](std_mem.md#struct-allocator) |  |
| `decorated` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `mtx` | [Mutex](std_thread_thread_win.md#struct-mutex) |  |

---

