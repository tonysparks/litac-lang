# std::mem::track_allocator

## Functions

<a id="func-init"></a>

### func init(d: \*[TrackAllocator](std_mem_track_allocator.md#struct-trackallocator), alloc: \*const [Allocator](std_mem.md#struct-allocator)) : void

*public* | *stdlib/std/mem/track_allocator.lita:24*

---

<a id="func-free"></a>

### func free(d: \*[TrackAllocator](std_mem_track_allocator.md#struct-trackallocator)) : void

*public* | *stdlib/std/mem/track_allocator.lita:35*

---

<a id="func-malloc"></a>

### func malloc(d: \*[TrackAllocator](std_mem_track_allocator.md#struct-trackallocator), size: usize) : \*void

*public* | *stdlib/std/mem/track_allocator.lita:109*

---

## Types

<a id="struct-allocation"></a>

### struct Allocation

*public* | *stdlib/std/mem/track_allocator.lita:12*

| Field | Type | Description |
|-------|------|-------------|
| `addr` | \*void |  |
| `size` | usize |  |

---

<a id="struct-trackallocator"></a>

### struct TrackAllocator

*public* | *stdlib/std/mem/track_allocator.lita:17*

| Field | Type | Description |
|-------|------|-------------|
| `alloc` | [Allocator](std_mem.md#struct-allocator) |  |
| `decorated` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `allocations` | [Array](std_array.md#struct-array)\<\*[Allocation](std_mem_debug_allocator.md#struct-allocation)\> |  |
| `totalAllocations` | usize |  |

---

