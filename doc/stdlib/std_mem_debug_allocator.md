# std::mem::debug_allocator

## Functions

<a id="func-init"></a>

### func init(d: \*[DebugAllocator](std_mem_debug_allocator.md#struct-debugallocator), alloc: \*const [Allocator](std_mem.md#struct-allocator)) : void

*public* | *stdlib/std/mem/debug_allocator.lita:36*

---

<a id="func-free"></a>

### func free(d: \*[DebugAllocator](std_mem_debug_allocator.md#struct-debugallocator)) : void

*public* | *stdlib/std/mem/debug_allocator.lita:49*

---

<a id="func-report"></a>

### func report(d: \*[DebugAllocator](std_mem_debug_allocator.md#struct-debugallocator)) : void

*public* | *stdlib/std/mem/debug_allocator.lita:153*

---

<a id="func-malloc"></a>

### func malloc(d: \*[DebugAllocator](std_mem_debug_allocator.md#struct-debugallocator), size: usize) : \*void

*public* | *stdlib/std/mem/debug_allocator.lita:162*

---

## Types

<a id="struct-allocation"></a>

### struct Allocation

*public* | *stdlib/std/mem/debug_allocator.lita:21*

| Field | Type | Description |
|-------|------|-------------|
| `addr` | \*void |  |
| `size` | usize |  |

---

<a id="struct-debugallocator"></a>

### struct DebugAllocator

*public* | *stdlib/std/mem/debug_allocator.lita:27*

| Field | Type | Description |
|-------|------|-------------|
| `alloc` | [Allocator](std_mem.md#struct-allocator) |  |
| `decorated` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `allocations` | [Array](std_array.md#struct-array)\<\*[Allocation](std_mem_debug_allocator.md#struct-allocation)\> |  |
| `totalAllocations` | u32 |  |
| `totalBytesAllocated` | usize |  |
| `totalBytesFreed` | usize |  |

---

