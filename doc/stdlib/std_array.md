# std::array

## Functions

<a id="func-arrayinit"></a>

### func ArrayInit\<T\>(initialSize: i32, alloc: \*const mem::Allocator) : [Array](std_array.md#struct-array)\<T\>

*public* | *stdlib/std/array.lita:15*

---

<a id="func-init"></a>

### func init\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, initialSize: i32, alloc: \*const mem::Allocator) : void

*public* | *stdlib/std/array.lita:22*

---

<a id="func-free"></a>

### func free\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : void

*public* | *stdlib/std/array.lita:41*

---

<a id="func-add"></a>

### func add\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, element: T) : i32

*public* | *stdlib/std/array.lita:50*

---

<a id="func-push"></a>

### func push\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, element: T) : i32

*public* | *stdlib/std/array.lita:71*

---

<a id="func-get"></a>

### func get\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, index: i32) : T

*public* | *stdlib/std/array.lita:75*

---

<a id="func-getptr"></a>

### func getPtr\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, index: i32) : \*T

*public* | *stdlib/std/array.lita:81*

---

<a id="func-set"></a>

### func set\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, index: i32, element: T) : void

*public* | *stdlib/std/array.lita:87*

---

<a id="func-setall"></a>

### func setAll\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, index: i32, other: \*[Array](std_array.md#struct-array)\<T\>) : i32

*public* | *stdlib/std/array.lita:98*

---

<a id="func-first"></a>

### func first\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : T

*public* | *stdlib/std/array.lita:121*

---

<a id="func-firstptr"></a>

### func firstPtr\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : \*T

*public* | *stdlib/std/array.lita:127*

---

<a id="func-last"></a>

### func last\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : T

*public* | *stdlib/std/array.lita:133*

---

<a id="func-lastptr"></a>

### func lastPtr\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : \*T

*public* | *stdlib/std/array.lita:139*

---

<a id="func-pop"></a>

### func pop\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : T

*public* | *stdlib/std/array.lita:145*

---

<a id="func-reserve"></a>

### func reserve\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, newSize: i32) : i32

*public* | *stdlib/std/array.lita:154*

---

<a id="func-swap"></a>

### func swap\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, aIndex: i32, bIndex: i32) : void

*public* | *stdlib/std/array.lita:172*

---

<a id="func-removeat"></a>

### func removeAt\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, index: i32) : T

*public* | *stdlib/std/array.lita:181*

---

<a id="func-insertat"></a>

### func insertAt\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, index: i32, element: T) : i32

*public* | *stdlib/std/array.lita:195*

---

<a id="func-insertallat"></a>

### func insertAllAt\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, index: i32, elements: \*[Array](std_array.md#struct-array)\<T\>) : i32

*public* | *stdlib/std/array.lita:218*

---

<a id="func-addall"></a>

### func addAll\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, other: \*[Array](std_array.md#struct-array)\<T\>) : i32

*public* | *stdlib/std/array.lita:240*

---

<a id="func-foreach"></a>

### func forEach\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, fn: func(T) : bool) : void

*public* | *stdlib/std/array.lita:258*

---

<a id="func-empty"></a>

### func empty\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : bool

*public* | *stdlib/std/array.lita:267*

---

<a id="func-size"></a>

### func size\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : i32

*public* | *stdlib/std/array.lita:272*

---

<a id="func-clear"></a>

### func clear\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>) : void

*public* | *stdlib/std/array.lita:277*

---

<a id="func-sort"></a>

### func sort\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, sorter: [SortFunc](std_array.md#typedef-sortfunc)\<T\>) : void

*public* | *stdlib/std/array.lita:284*

---

<a id="func-copy"></a>

### func copy\<T\>(a: \*[Array](std_array.md#struct-array)\<T\>, allocator: \*const mem::Allocator) : [Array](std_array.md#struct-array)\<T\>

*public* | *stdlib/std/array.lita:288*

---

## Types

<a id="struct-array"></a>

### struct Array\<T\>

*public* | *stdlib/std/array.lita:8*

| Field | Type | Description |
|-------|------|-------------|
| `length` | i32 |  |
| `capacity` | i32 |  |
| `elements` | \*T |  |
| `alloc` | \*const mem::Allocator |  |

---

<a id="typedef-sortfunc"></a>

### typedef SortFunc\<T\> = func(T, T) : i32

*public* | *stdlib/std/array.lita:282*

---

