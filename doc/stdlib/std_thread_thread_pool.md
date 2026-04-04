# std::thread::thread_pool

## Functions

<a id="func-init"></a>

### func (this: \*[ThreadPool](std_thread_thread_pool.md#struct-threadpool)) init(minThreads: i32, maxThreads: i32, createThread: [CreateThread](std_thread_thread_pool.md#struct-createthread), allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_pool.lita:49*

---

<a id="func-destroy"></a>

### func (this: \*[ThreadPool](std_thread_thread_pool.md#struct-threadpool)) destroy() : void

*public* | *stdlib/std/thread/thread_pool.lita:80*

---

<a id="func-submit"></a>

### func (this: \*[ThreadPool](std_thread_thread_pool.md#struct-threadpool)) submit(task: [TaskFn](std_thread_thread_pool.md#typedef-taskfn), arg: \*void) : void

*public* | *stdlib/std/thread/thread_pool.lita:137*


    The current design gives each TaskThread a queue of Tasks.  As of right now, there is
    no task stealing and tasks get assigned in a round-robin fashion


---

<a id="func-start"></a>

### func (this: \*[ThreadPool](std_thread_thread_pool.md#struct-threadpool)) start(daemonThread: bool) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_pool.lita:178*

---

<a id="func-stop"></a>

### func (this: \*[ThreadPool](std_thread_thread_pool.md#struct-threadpool)) stop(forceStop: bool) : void

*public* | *stdlib/std/thread/thread_pool.lita:198*

---

## Types

<a id="typedef-taskfn"></a>

### typedef TaskFn = func([ThreadContext](std_thread_thread_pool.md#typedef-threadcontext), [TaskContext](std_thread_thread_pool.md#typedef-taskcontext)) : [TaskStatus](std_thread_thread_pool.md#enum-taskstatus)

*public* | *stdlib/std/thread/thread_pool.lita:11*

---

<a id="typedef-createthreadcontextfn"></a>

### typedef CreateThreadContextFn = func(\*void) : [ThreadContext](std_thread_thread_pool.md#typedef-threadcontext)

*public* | *stdlib/std/thread/thread_pool.lita:15*

---

<a id="typedef-taskcontext"></a>

### typedef TaskContext = \*void

*public* | *stdlib/std/thread/thread_pool.lita:18*

---

<a id="typedef-threadcontext"></a>

### typedef ThreadContext = \*void

*public* | *stdlib/std/thread/thread_pool.lita:22*

---

<a id="struct-createthread"></a>

### struct CreateThread

*public* | *stdlib/std/thread/thread_pool.lita:25*

| Field | Type | Description |
|-------|------|-------------|
| `callback` | [CreateThreadContextFn](std_thread_thread_pool.md#typedef-createthreadcontextfn) |  |
| `arg` | \*void |  |

---

<a id="enum-taskstatus"></a>

### enum TaskStatus

*public* | *stdlib/std/thread/thread_pool.lita:30*

| Value | Description |
|-------|-------------|
| `OK` |  |
| `ERROR` |  |

---

<a id="struct-threadpool"></a>

### struct ThreadPool

*public* | *stdlib/std/thread/thread_pool.lita:35*

| Field | Type | Description |
|-------|------|-------------|
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |
| `started` | [Atomic](std_atomic.md#struct-atomic)\<bool\> |  |
| `minThreads` | i32 |  |
| `maxThreads` | i32 |  |
| `threadMutex` | [Mutex](std_thread_thread_win.md#struct-mutex) |  |
| `threads` | [Array](std_array.md#struct-array)\<TaskThread\> |  |
| `distribution` | u64 |  |
| `createThread` | [CreateThread](std_thread_thread_pool.md#struct-createthread) |  |

---

