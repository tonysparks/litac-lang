# std::thread::barrier_posix

## Functions

<a id="func-init"></a>

### func (this: \*[Barrier](std_thread_barrier_mac.md#struct-barrier)) init(threadCount: i32) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/barrier_posix.lita:49*

---

<a id="func-destroy"></a>

### func (this: \*[Barrier](std_thread_barrier_mac.md#struct-barrier)) destroy() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/barrier_posix.lita:54*

---

<a id="func-wait"></a>

### func (this: \*[Barrier](std_thread_barrier_mac.md#struct-barrier)) wait() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/barrier_posix.lita:59*

---

## Types

<a id="struct-barrier"></a>

### struct Barrier

*public* | *stdlib/std/thread/barrier_posix.lita:45*

| Field | Type | Description |
|-------|------|-------------|
| `_b` | pthread_barrier_t |  |

---

