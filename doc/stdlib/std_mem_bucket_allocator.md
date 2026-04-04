# std::mem::bucket_allocator

## Functions

<a id="func-init"></a>

### func (this: \*[BucketAllocator](std_mem_bucket_allocator.md#struct-bucketallocator)) init(decorated: \*const [Allocator](std_mem.md#struct-allocator), bucketSize: usize) : void

*public* | *stdlib/std/mem/bucket_allocator.lita:34*

---

<a id="func-clear"></a>

### func (this: \*[BucketAllocator](std_mem_bucket_allocator.md#struct-bucketallocator)) clear() : void

*public* | *stdlib/std/mem/bucket_allocator.lita:66*

---

<a id="func-free"></a>

### func (this: \*[BucketAllocator](std_mem_bucket_allocator.md#struct-bucketallocator)) free() : void

*public* | *stdlib/std/mem/bucket_allocator.lita:86*

Free all memory associated with this allocator.

---

<a id="func-malloc"></a>

### func (this: \*[BucketAllocator](std_mem_bucket_allocator.md#struct-bucketallocator)) malloc(size: usize) : \*void

*public* | *stdlib/std/mem/bucket_allocator.lita:104*

---

## Types

<a id="struct-bucketallocator"></a>

### struct BucketAllocator

*public* | *stdlib/std/mem/bucket_allocator.lita:19*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | [Allocator](std_mem.md#struct-allocator) |  |
| `decorated` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `buckets` | \*Bucket |  |
| `head` | \*Bucket |  |
| `bucketSize` | usize |  |
| `currentOffset` | usize |  |
| `totalAllocations` | u32 |  |
| `totalBytesAllocated` | usize |  |
| `totalGrossBytesAllocated` | usize |  |
| `totalBuckets` | u32 |  |

---

