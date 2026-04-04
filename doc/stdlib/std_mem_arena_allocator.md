# std::mem::arena_allocator

## Functions

<a id="func-init"></a>

### func (this: \*[ArenaAllocator](std_mem_arena_allocator.md#struct-arenaallocator)) init(size: usize, alloc: \*const [Allocator](std_mem.md#struct-allocator)) : void

*public* | *stdlib/std/mem/arena_allocator.lita:32*

---

<a id="func-free"></a>

### func (this: \*[ArenaAllocator](std_mem_arena_allocator.md#struct-arenaallocator)) free() : void

*public* | *stdlib/std/mem/arena_allocator.lita:56*

---

<a id="func-clear"></a>

### func (this: \*[ArenaAllocator](std_mem_arena_allocator.md#struct-arenaallocator)) clear() : void

*public* | *stdlib/std/mem/arena_allocator.lita:79*

---

<a id="func-unusedbytes"></a>

### func (this: \*[ArenaAllocator](std_mem_arena_allocator.md#struct-arenaallocator)) unusedBytes() : usize

*public* | *stdlib/std/mem/arena_allocator.lita:90*

---

<a id="func-malloc"></a>

### func (this: \*[ArenaAllocator](std_mem_arena_allocator.md#struct-arenaallocator)) malloc(size: usize) : \*void

*public* | *stdlib/std/mem/arena_allocator.lita:189*

---

## Types

<a id="struct-arenaallocator"></a>

### struct ArenaAllocator

*public* | *stdlib/std/mem/arena_allocator.lita:11*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | [Allocator](std_mem.md#struct-allocator) |  |
| `decorated` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `arena` | \*Arena |  |
| `pageSize` | usize |  |
| `numberOfArenas` | u32 |  |
| `numberOfBytesAllocated` | usize |  |
| `numberOfAllocations` | u32 |  |

---

