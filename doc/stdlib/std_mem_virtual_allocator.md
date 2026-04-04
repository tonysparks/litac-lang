# std::mem::virtual_allocator

## Functions

<a id="func-init"></a>

### func (this: \*[VirtualAllocator](std_mem_virtual_allocator.md#struct-virtualallocator)) init(commitSize: usize, reservedSize: usize, align: usize) : void

*public* | *stdlib/std/mem/virtual_allocator.lita:29*

---

<a id="func-clear"></a>

### func (this: \*[VirtualAllocator](std_mem_virtual_allocator.md#struct-virtualallocator)) clear() : void

*public* | *stdlib/std/mem/virtual_allocator.lita:55*

Zero out all allocated memory and reset current offset

---

<a id="func-free"></a>

### func (this: \*[VirtualAllocator](std_mem_virtual_allocator.md#struct-virtualallocator)) free() : void

*public* | *stdlib/std/mem/virtual_allocator.lita:64*

---

<a id="func-malloc"></a>

### func (this: \*[VirtualAllocator](std_mem_virtual_allocator.md#struct-virtualallocator)) malloc(size: usize) : \*void

*public* | *stdlib/std/mem/virtual_allocator.lita:69*

---

## Types

<a id="struct-virtualallocator"></a>

### struct VirtualAllocator

*public* | *stdlib/std/mem/virtual_allocator.lita:12*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | [Allocator](std_mem.md#struct-allocator) |  |
| `mem` | \*void |  |
| `commitSize` | usize |  |
| `reservedSize` | usize |  |
| `currentOffset` | usize |  |
| `committedPosition` | usize |  |
| `alignment` | usize |  |
| `pageSize` | usize |  |
| `totalAllocations` | u32 |  |
| `totalBytesAllocated` | usize |  |

---

