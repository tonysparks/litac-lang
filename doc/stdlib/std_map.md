# std::map

## Functions

<a id="func-strmap"></a>

### func StrMap\<V\>(emptyValue: V, initialSize: i32, allocator: \*const mem::Allocator) : [Map](std_map.md#struct-map)\<\*const char, V\>

*public* | *stdlib/std/map.lita:45*

---

<a id="func-stringmap"></a>

### func StringMap\<V\>(emptyValue: V, initialSize: i32, allocator: \*const mem::Allocator) : [Map](std_map.md#struct-map)\<String, V\>

*public* | *stdlib/std/map.lita:54*

---

<a id="func-init"></a>

### func init\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>, emptyValue: V, initialSize: i32, allocator: \*const mem::Allocator, emptyKey: K) : void

*public* | *stdlib/std/map.lita:65*

---

<a id="func-free"></a>

### func free\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>) : void

*public* | *stdlib/std/map.lita:84*

---

<a id="func-size"></a>

### func size\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>) : i32

*public* | *stdlib/std/map.lita:97*

---

<a id="func-empty"></a>

### func empty\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>) : bool

*public* | *stdlib/std/map.lita:101*

---

<a id="func-put"></a>

### func put\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>, key: K, value: V) : i32

*public* | *stdlib/std/map.lita:106*

---

<a id="func-get"></a>

### func get\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>, key: K) : V

*public* | *stdlib/std/map.lita:141*

---

<a id="func-getptr"></a>

### func getPtr\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>, key: K) : \*V

*public* | *stdlib/std/map.lita:166*

---

<a id="func-clear"></a>

### func clear\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>) : void

*public* | *stdlib/std/map.lita:191*

---

<a id="func-remove"></a>

### func remove\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>, key: K) : V

*public* | *stdlib/std/map.lita:202*

---

<a id="func-contains"></a>

### func contains\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>, key: K) : bool

*public* | *stdlib/std/map.lita:234*

---

<a id="func-iter"></a>

### func iter\<K, V\>(m: \*[Map](std_map.md#struct-map)\<K, V\>) : [MapIterator](std_map.md#struct-mapiterator)\<K, V\>

*public* | *stdlib/std/map.lita:296*

---

<a id="func-hasnext"></a>

### func hasNext\<K, V\>(iter: \*[MapIterator](std_map.md#struct-mapiterator)\<K, V\>) : bool

*public* | *stdlib/std/map.lita:305*

---

<a id="func-next"></a>

### func next\<K, V\>(iter: \*[MapIterator](std_map.md#struct-mapiterator)\<K, V\>) : [MapEntry](std_map.md#struct-mapentry)\<K, V\>

*public* | *stdlib/std/map.lita:309*

---

<a id="func-remove"></a>

### func remove\<K, V\>(iter: \*[MapIterator](std_map.md#struct-mapiterator)\<K, V\>) : void

*public* | *stdlib/std/map.lita:336*

---

## Types

<a id="struct-map"></a>

### struct Map\<K, V\>

*public* | *stdlib/std/map.lita:19*

| Field | Type | Description |
|-------|------|-------------|
| `length` | i32 |  |
| `capacity` | i32 |  |
| `allocator` | \*const mem::Allocator |  |
| `entries` | \*Entry\<K, V\> |  |
| `emptyValue` | V |  |
| `emptyKey` | K |  |

---

<a id="struct-mapiterator"></a>

### struct MapIterator\<K, V\>

*public* | *stdlib/std/map.lita:30*

| Field | Type | Description |
|-------|------|-------------|
| `m` | \*[Map](std_map.md#struct-map)\<K, V\> |  |
| `it` | i32 |  |
| `prevIt` | i32 |  |
| `count` | i32 |  |

---

<a id="struct-mapentry"></a>

### struct MapEntry\<K, V\>

*public* | *stdlib/std/map.lita:37*

| Field | Type | Description |
|-------|------|-------------|
| `key` | K |  |
| `value` | V |  |
| `valuePtr` | \*V |  |

---

