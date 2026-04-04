# std::mem::linear_allocator

## Functions

<a id="func-init"></a>

### func (this: \*[LinearAllocator](std_mem_linear_allocator.md#struct-linearallocator)) init(mem: \*void, size: usize, align: usize, expandInfo: [ExpandInfo](std_mem_linear_allocator.md#struct-expandinfo)) : void

*public* | *stdlib/std/mem/linear_allocator.lita:44*

---

<a id="func-clear"></a>

### func (this: \*[LinearAllocator](std_mem_linear_allocator.md#struct-linearallocator)) clear() : void

*public* | *stdlib/std/mem/linear_allocator.lita:66*

Zero out all allocated memory and reset current offset

---

<a id="func-malloc"></a>

### func (this: \*[LinearAllocator](std_mem_linear_allocator.md#struct-linearallocator)) malloc(size: usize) : \*void

*public* | *stdlib/std/mem/linear_allocator.lita:75*

---

## Types

<a id="enum-expandstrategy"></a>

### enum ExpandStrategy

*public* | *stdlib/std/mem/linear_allocator.lita:5*

| Value | Description |
|-------|-------------|
| `NO_ALLOC_MEMORY` |  |
| `DOUBLE_MEMORY` |  |

---

<a id="struct-expandinfo"></a>

### struct ExpandInfo

*public* | *stdlib/std/mem/linear_allocator.lita:13*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `strategy` | [ExpandStrategy](std_mem_linear_allocator.md#enum-expandstrategy) |  |

---

<a id="struct-linearallocator"></a>

### struct LinearAllocator

*public* | *stdlib/std/mem/linear_allocator.lita:28*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | [Allocator](std_mem.md#struct-allocator) |  |
| `mem` | \*void |  |
| `size` | usize |  |
| `currentOffset` | usize |  |
| `alignment` | usize |  |
| `totalAllocations` | u32 |  |
| `totalBytesAllocated` | usize |  |
| `expandInfo` | [ExpandInfo](std_mem_linear_allocator.md#struct-expandinfo) |  |

---

## Variables and Constants

<a id="const-default_expand_info"></a>

### const DEFAULT_EXPAND_INFO

*public* | *stdlib/std/mem/linear_allocator.lita:18*

---

