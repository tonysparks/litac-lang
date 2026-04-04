# std::thread::barrier_mac

## Functions

<a id="func-init"></a>

### func (this: \*[Barrier](std_thread_barrier_mac.md#struct-barrier)) init(threadCount: i32) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/barrier_mac.lita:15*

---

<a id="func-destroy"></a>

### func (this: \*[Barrier](std_thread_barrier_mac.md#struct-barrier)) destroy() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/barrier_mac.lita:33*

---

<a id="func-wait"></a>

### func (this: \*[Barrier](std_thread_barrier_mac.md#struct-barrier)) wait() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/barrier_mac.lita:39*

---

## Types

<a id="struct-barrier"></a>

### struct Barrier

*public* | *stdlib/std/thread/barrier_mac.lita:7*

| Field | Type | Description |
|-------|------|-------------|
| `mtx` | [Mutex](std_thread_thread_win.md#struct-mutex) |  |
| `cond` | [Cond](std_thread_thread_win.md#struct-cond) |  |
| `count` | i32 |  |
| `waiting` | i32 |  |
| `phase` | i32 |  |

---

