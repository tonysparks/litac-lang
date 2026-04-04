# std::bucket_list

## Functions

<a id="func-bucketlistinit"></a>

### func BucketListInit\<T\>(bucketSize: i32, alloc: \*const [Allocator](std_mem.md#struct-allocator)) : [BucketList](std_bucket_list.md#struct-bucketlist)\<T\>

*public* | *stdlib/std/bucket_list.lita:29*

---

<a id="func-init"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) init\<T\>(bucketSize: i32, alloc: \*const [Allocator](std_mem.md#struct-allocator)) : void

*public* | *stdlib/std/bucket_list.lita:36*

---

<a id="func-free"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) free\<T\>() : void

*public* | *stdlib/std/bucket_list.lita:60*

---

<a id="func-clear"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) clear\<T\>() : void

*public* | *stdlib/std/bucket_list.lita:72*

---

<a id="func-add"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) add\<T\>(element: T) : i32

*public* | *stdlib/std/bucket_list.lita:86*

---

<a id="func-push"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) push\<T\>(element: T) : i32

*public* | *stdlib/std/bucket_list.lita:142*

---

<a id="func-get"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) get\<T\>(index: usize) : T

*public* | *stdlib/std/bucket_list.lita:146*

---

<a id="func-getptr"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) getPtr\<T\>(index: i32) : \*T

*public* | *stdlib/std/bucket_list.lita:156*

---

<a id="func-set"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) set\<T\>(index: i32, element: T) : void

*public* | *stdlib/std/bucket_list.lita:166*

---

<a id="func-first"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) first\<T\>() : T

*public* | *stdlib/std/bucket_list.lita:180*

---

<a id="func-firstptr"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) firstPtr\<T\>() : \*T

*public* | *stdlib/std/bucket_list.lita:186*

---

<a id="func-last"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) last\<T\>() : T

*public* | *stdlib/std/bucket_list.lita:192*

---

<a id="func-lastptr"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) lastPtr\<T\>() : \*T

*public* | *stdlib/std/bucket_list.lita:205*

---

<a id="func-pop"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) pop\<T\>() : T

*public* | *stdlib/std/bucket_list.lita:218*

---

<a id="func-popptr"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) popPtr\<T\>() : \*T

*public* | *stdlib/std/bucket_list.lita:235*

---

<a id="func-swap"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) swap\<T\>(aIndex: usize, bIndex: usize) : void

*public* | *stdlib/std/bucket_list.lita:252*

---

<a id="func-empty"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) empty\<T\>() : bool

*public* | *stdlib/std/bucket_list.lita:271*

---

<a id="func-size"></a>

### func (this: \*[BucketList](std_bucket_list.md#struct-bucketlist)\<T\>) size\<T\>() : usize

*public* | *stdlib/std/bucket_list.lita:276*

---

## Types

<a id="struct-bucketlist"></a>

### struct BucketList\<T\>

*public* | *stdlib/std/bucket_list.lita:13*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `bucketSize` | i32 |  |
| `length` | usize |  |
| `buckets` | \*Bucket\<T\> |  |
| `top` | \*Bucket\<T\> |  |

---

