# std::mem::stack_allocator

## Functions

<a id="func-init"></a>

### func (this: \*[StackAllocator](std_mem_stack_allocator.md#struct-stackallocator)) init(decorated: \*const [Allocator](std_mem.md#struct-allocator)) : void

*public* | *stdlib/std/mem/stack_allocator.lita:27*

---

<a id="func-free"></a>

### func (this: \*[StackAllocator](std_mem_stack_allocator.md#struct-stackallocator)) free() : void

*public* | *stdlib/std/mem/stack_allocator.lita:41*

---

<a id="func-empty"></a>

### func (this: \*[StackAllocator](std_mem_stack_allocator.md#struct-stackallocator)) empty() : bool

*public* | *stdlib/std/mem/stack_allocator.lita:57*

---

<a id="func-pop"></a>

### func (this: \*[StackAllocator](std_mem_stack_allocator.md#struct-stackallocator)) pop() : void

*public* | *stdlib/std/mem/stack_allocator.lita:61*

---

<a id="func-malloc"></a>

### func (this: \*[StackAllocator](std_mem_stack_allocator.md#struct-stackallocator)) malloc(size: usize) : \*void

*public* | *stdlib/std/mem/stack_allocator.lita:75*

---

## Types

<a id="struct-stackallocator"></a>

### struct StackAllocator

*public* | *stdlib/std/mem/stack_allocator.lita:16*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | [Allocator](std_mem.md#struct-allocator) |  |
| `decorated` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `stack` | \*StackEntry |  |
| `head` | \*StackEntry |  |
| `totalAllocations` | u32 |  |
| `totalBytesAllocated` | usize |  |

---

