# std::thread::thread_posix

## Functions

<a id="func-init"></a>

### func (this: \*[Mutex](std_thread_thread_win.md#struct-mutex)) init(type: i32) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:306*

---

<a id="func-destroy"></a>

### func (this: \*[Mutex](std_thread_thread_win.md#struct-mutex)) destroy() : void

*public* | *stdlib/std/thread/thread_posix.lita:319*

---

<a id="func-lock"></a>

### func (this: \*[Mutex](std_thread_thread_win.md#struct-mutex)) lock() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:323*

---

<a id="func-trylock"></a>

### func (this: \*[Mutex](std_thread_thread_win.md#struct-mutex)) tryLock() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:328*

---

<a id="func-unlock"></a>

### func (this: \*[Mutex](std_thread_thread_win.md#struct-mutex)) unlock() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:333*

---

<a id="func-timedlock"></a>

### func (this: \*[Mutex](std_thread_thread_win.md#struct-mutex)) timedLock(durationMs: i64) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:338*

---

<a id="func-init"></a>

### func (this: \*[Cond](std_thread_thread_win.md#struct-cond)) init() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:402*

---

<a id="func-destroy"></a>

### func (this: \*[Cond](std_thread_thread_win.md#struct-cond)) destroy() : void

*public* | *stdlib/std/thread/thread_posix.lita:407*

---

<a id="func-signal"></a>

### func (this: \*[Cond](std_thread_thread_win.md#struct-cond)) signal() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:412*

---

<a id="func-broadcast"></a>

### func (this: \*[Cond](std_thread_thread_win.md#struct-cond)) broadcast() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:417*

---

<a id="func-wait"></a>

### func (this: \*[Cond](std_thread_thread_win.md#struct-cond)) wait(mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:423*

---

<a id="func-timedwait"></a>

### func (this: \*[Cond](std_thread_thread_win.md#struct-cond)) timedWait(mtx: \*[Mutex](std_thread_thread_win.md#struct-mutex), durationMs: i64) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:428*

---

<a id="func-create"></a>

### func (this: \*[Thread](std_thread_thread_win.md#struct-thread)) create(fun: [ThreadStartFn](std_thread_thread_win.md#typedef-threadstartfn), arg: \*void, allocator: \*const [Allocator](std_mem.md#struct-allocator)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:476*

---

<a id="func-resume"></a>

### func resume(thr: \*[Thread](std_thread_thread_win.md#struct-thread)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:510*

---

<a id="func-suspend"></a>

### func suspend(thr: \*[Thread](std_thread_thread_win.md#struct-thread)) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:515*

---

<a id="func-detach"></a>

### func (this: [Thread](std_thread_thread_win.md#struct-thread)) detach() : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:520*

---

<a id="func-id"></a>

### func (this: [Thread](std_thread_thread_win.md#struct-thread)) id() : i64

*public* | *stdlib/std/thread/thread_posix.lita:525*

---

<a id="func-equal"></a>

### func (this: [Thread](std_thread_thread_win.md#struct-thread)) equal(other: [Thread](std_thread_thread_win.md#struct-thread)) : bool

*public* | *stdlib/std/thread/thread_posix.lita:529*

---

<a id="func-join"></a>

### func (this: [Thread](std_thread_thread_win.md#struct-thread)) join(res: \*i32) : [ThreadStatus](std_thread_thread_win.md#enum-threadstatus)

*public* | *stdlib/std/thread/thread_posix.lita:533*

---

<a id="func-destroy"></a>

### func (this: [Thread](std_thread_thread_win.md#struct-thread)) destroy() : void

*public* | *stdlib/std/thread/thread_posix.lita:545*

---

<a id="func-yield"></a>

### func (this: [Thread](std_thread_thread_win.md#struct-thread)) yield() : void

*public* | *stdlib/std/thread/thread_posix.lita:549*

---

<a id="func-threadcurrent"></a>

### func ThreadCurrent() : [Thread](std_thread_thread_win.md#struct-thread)

*public* | *stdlib/std/thread/thread_posix.lita:553*

---

<a id="func-threadexit"></a>

### func ThreadExit(res: i32) : void

*public* | *stdlib/std/thread/thread_posix.lita:561*

---

<a id="func-threadsleepmsec"></a>

### func ThreadSleepMSec(msec: i64) : i32

*public* | *stdlib/std/thread/thread_posix.lita:565*

---

<a id="func-threadsleep"></a>

### func ThreadSleep(duration: \*[TimeSpec](std_thread_thread_win.md#struct-timespec), remaining: \*[TimeSpec](std_thread_thread_win.md#struct-timespec)) : i32

*public* | *stdlib/std/thread/thread_posix.lita:582*

---

<a id="func-getnumberofsystemthreads"></a>

### func GetNumberOfSystemThreads() : u32

*public* | *stdlib/std/thread/thread_posix.lita:593*

---

<a id="func-threadprintstacktrace"></a>

### func ThreadPrintStackTrace(fd: \*[FILE](std_libc.md#struct-file)) : void

*public* | *stdlib/std/thread/thread_posix.lita:603*

---

## Types

<a id="enum-threadstatus"></a>

### enum ThreadStatus

*public* | *stdlib/std/thread/thread_posix.lita:282*

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

*public* | *stdlib/std/thread/thread_posix.lita:291*

| Value | Description |
|-------|-------------|
| `PLAIN` |  |
| `TIMED` |  |
| `RECURSIVE` |  |

---

<a id="struct-mutex"></a>

### struct Mutex

*public* | *stdlib/std/thread/thread_posix.lita:302*

| Field | Type | Description |
|-------|------|-------------|
| `mtx` | pthread_mutex_t |  |

---

<a id="struct-cond"></a>

### struct Cond

*public* | *stdlib/std/thread/thread_posix.lita:398*

| Field | Type | Description |
|-------|------|-------------|
| `cond` | pthread_cond_t |  |

---

<a id="typedef-threadstartfn"></a>

### typedef ThreadStartFn = func(\*void) : i32

*public* | *stdlib/std/thread/thread_posix.lita:460*

---

<a id="struct-thread"></a>

### struct Thread

*public* | *stdlib/std/thread/thread_posix.lita:461*

| Field | Type | Description |
|-------|------|-------------|
| `thrd` | pthread_t |  |

---

