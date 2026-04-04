# std::thread::thread_win

## Functions

<a id="func-sleep"></a>

### func Sleep(msec: i64) : void

*public* | *stdlib/std/thread/thread_win.lita:389*

---

<a id="func-get"></a>

### func get(ts: \*[TimeSpec](std_thread_thread_win.md#struct-timespec), base: i32) : i32

*public* | *stdlib/std/thread/thread_win.lita:441*

---

<a id="func-init"></a>

### func init(mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex), type: i32) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:472*

---

<a id="func-destroy"></a>

### func destroy(mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex)) : void

*public* | *stdlib/std/thread/thread_win.lita:489*

---

<a id="func-lock"></a>

### func lock(mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:498*

---

<a id="func-trylock"></a>

### func tryLock(mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:519*

---

<a id="func-unlock"></a>

### func unlock(mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:543*

---

<a id="func-timedlock"></a>

### func timedLock(mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex), durationMs: i64) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:556*

---

<a id="func-init"></a>

### func init(cond: \*[Cond](std_thread_thread_win.md#struct-cond)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:593*

---

<a id="func-destroy"></a>

### func destroy(cond: \*[Cond](std_thread_thread_win.md#struct-cond)) : void

*public* | *stdlib/std/thread/thread_win.lita:616*

---

<a id="func-signal"></a>

### func signal(cond: \*[Cond](std_thread_thread_win.md#struct-cond)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:627*

---

<a id="func-broadcast"></a>

### func broadcast(cond: \*[Cond](std_thread_thread_win.md#struct-cond)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:645*

---

<a id="func-wait"></a>

### func wait(cond: \*[Cond](std_thread_thread_win.md#struct-cond), mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:713*

---

<a id="func-timedwait"></a>

### func timedWait(cond: \*[Cond](std_thread_thread_win.md#struct-cond), mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex), durationMs: i64) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:717*

---

<a id="func-create"></a>

### func create(thr: \*[Thread](std_thread_thread_win.md#struct-thread), fun: [ThreadStartFn](std_thread_thread_win.md#typedef-threadstartfn), arg: \*void, allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:760*

---

<a id="func-resume"></a>

### func resume(thr: \*[Thread](std_thread_thread_win.md#struct-thread)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:787*

---

<a id="func-suspend"></a>

### func suspend(thr: \*[Thread](std_thread_thread_win.md#struct-thread)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:792*

---

<a id="func-detach"></a>

### func detach(thr: [Thread](std_thread_thread_win.md#struct-thread)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:797*

---

<a id="func-id"></a>

### func id(thr: [Thread](std_thread_thread_win.md#struct-thread)) : i64

*public* | *stdlib/std/thread/thread_win.lita:801*

---

<a id="func-equal"></a>

### func equal(thr: [Thread](std_thread_thread_win.md#struct-thread), other: [Thread](std_thread_thread_win.md#struct-thread)) : bool

*public* | *stdlib/std/thread/thread_win.lita:805*

---

<a id="func-join"></a>

### func join(thr: [Thread](std_thread_thread_win.md#struct-thread), res: \*i32) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_win.lita:809*

---

<a id="func-yield"></a>

### func yield(thr: [Thread](std_thread_thread_win.md#struct-thread)) : void

*public* | *stdlib/std/thread/thread_win.lita:828*

---

<a id="func-threadcurrent"></a>

### func ThreadCurrent() : [Thread](std_thread_thread_win.md#struct-thread)

*public* | *stdlib/std/thread/thread_win.lita:833*

---

<a id="func-threadexit"></a>

### func ThreadExit(res: i32) : void

*public* | *stdlib/std/thread/thread_win.lita:839*

---

<a id="func-threadsleepmsec"></a>

### func ThreadSleepMSec(msec: i64) : i32

*public* | *stdlib/std/thread/thread_win.lita:847*

---

<a id="func-threadsleep"></a>

### func ThreadSleep(duration: \*[TimeSpec](std_thread_thread_win.md#struct-timespec), remaining: \*[TimeSpec](std_thread_thread_win.md#struct-timespec)) : i32

*public* | *stdlib/std/thread/thread_win.lita:857*

---

<a id="func-getnumberofsystemthreads"></a>

### func GetNumberOfSystemThreads() : u32

*public* | *stdlib/std/thread/thread_win.lita:884*

---

## Types

<a id="enum-threadstatus"></a>

### enum ThreadStatus

*public* | *stdlib/std/thread/thread_win.lita:248*

| Value | Description |
|-------|-------------|
| `ERROR` |  |
| `SUCCESS` |  |
| `TIMEDOUT` |  |
| `BUSY` |  |
| `NOMEM` |  |

---

<a id="enum-mutextype"></a>

### enum MutexType

*public* | *stdlib/std/thread/thread_win.lita:257*

| Value | Description |
|-------|-------------|
| `PLAIN` |  |
| `TIMED` |  |
| `RECURSIVE` |  |

---

<a id="struct-timespec"></a>

### struct TimeSpec

*public* | *stdlib/std/thread/thread_win.lita:435*

| Field | Type | Description |
|-------|------|-------------|
| `sec` | time_t |  |
| `nsec` | i64 |  |

---

<a id="struct-mutex"></a>

### struct Mutex

*public* | *stdlib/std/thread/thread_win.lita:462*

| Field | Type | Description |
|-------|------|-------------|
| `mAlreadyLocked` | bool |  |
| `mRecursive` | bool |  |
| `mTimed` | bool |  |

---

<a id="struct-cond"></a>

### struct Cond

*public* | *stdlib/std/thread/thread_win.lita:587*

| Field | Type | Description |
|-------|------|-------------|
| `mEvents` | \[\][HANDLE](std_io_io_win.md#typedef-handle) |  |
| `mWaitersCount` | u32 |  |
| `mWaitersCountLock` | CRITICAL_SECTION |  |

---

<a id="typedef-threadstartfn"></a>

### typedef ThreadStartFn = func(\*void) : i32

*public* | *stdlib/std/thread/thread_win.lita:726*

---

<a id="struct-thread"></a>

### struct Thread

*public* | *stdlib/std/thread/thread_win.lita:727*

| Field | Type | Description |
|-------|------|-------------|
| `hnd` | [HANDLE](std_io_io_win.md#typedef-handle) |  |

---

<a id="struct-threadstartinfo"></a>

### struct ThreadStartInfo

*public* | *stdlib/std/thread/thread_win.lita:732*

| Field | Type | Description |
|-------|------|-------------|
| `mFunction` | [ThreadStartFn](std_thread_thread_win.md#typedef-threadstartfn) |  |
| `mArg` | \*void |  |
| `allocator` | \*const [Allocator](std_mem.md#struct-allocator) |  |

---

