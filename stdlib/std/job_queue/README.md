# std/job_queue

A durable, SQLite-backed job queue for background task processing. Jobs survive process crashes and are retried automatically with exponential backoff. Multiple named queues can share a single database, and a pool of worker threads polls and processes jobs concurrently.

## Features

- **Durable** — jobs are persisted in SQLite before the caller returns; nothing is lost if the process crashes
- **Automatic retry** — failed jobs are re-queued with exponential backoff (1 s → 5 s → 30 s); handlers control success/failure/retry via `JobResult`
- **Group ordering** — an optional `groupKey` serializes jobs within a group: the next job in the group is not claimed until the running one finishes (other groups run concurrently)
- **Delayed execution** — supply a future unix timestamp via `runAt` to schedule jobs ahead of time
- **Worker pool** — `WorkerPoolOpen` starts background threads that poll and dispatch jobs automatically
- **Crash recovery** — call `recover()` at startup to reset any jobs left in `running` state by a prior crash

## Quick start

```litac
import "std/job_queue"
import "std/db/sqlite/sqlite_db"
import "std/db"

// 1. Open a SQLite connection (caller owns it).
var conn: SqliteConnection
Connect($"app.db", &conn)

// 2. Open a named queue in that database.
var q: JobQueue
JobQueueOpen(conn.connection, "email", &q) ?: {
    // handle error
    return;
}
defer q.close()  // closes the mutex; caller closes conn

// 3. Submit a job. submit() returns the job id (i64), or -1 on error.
var id = q.submit($"hello world")

// 4. Process manually (single-threaded):
var job: Job
if(q.poll(&job)) {
    // do work with job.payloadStr(), job.groupKeyStr(), etc.
    q.complete(job.id)  // or q.fail / q.retry
    job.free()
}
```

## Worker pool (background threads)

```litac
func myHandler(job: *Job, ctx: *void) : JobResult {
    var payload = job.payloadStr()
    // ... process ...
    return JobResult.JOB_OK   // or JOB_FAIL / JOB_RETRY
}

var pool: WorkerPool
WorkerPoolOpen(&q, 4, myHandler, &pool) ?: {
    // handle error
    return;
}
defer pool.shutdown()  // stops all threads and waits for them to finish
```

### Per-worker context

Pass a factory function to give each worker thread its own resources (e.g. a dedicated database connection):

```litac
func makeCtx(arg: *void) : *void {
    // allocate and return a worker-specific context
    return myAllocate()
}

WorkerPoolOpen(&q, 4, myHandler, &pool, makeCtx, myArg)
```

## Tracking job status

`submit()` returns an `i64` job ID. Pass it to `getStatus()` at any point:

```litac
var id = q.submit($"payload")

// later...
var s = q.getStatus(id)
if(s == JobStatus.DONE) {
    // job completed successfully
} else if(s == JobStatus.FAILED) {
    // exhausted all retries
}
```

## Group keys

Jobs with the same `groupKey` are serialized: only one runs at a time per group. Jobs in different groups (or with no group key) are independent.

```litac
q.submit($"step 1", .groupKey = $"user:42")
q.submit($"step 2", .groupKey = $"user:42")
// step 2 will not be claimed until step 1 completes

q.submit($"other",  .groupKey = $"user:99")
// runs concurrently with user:42
```

## Delayed jobs

```litac
var inFiveMinutes = Now() as (i64) + 300
q.submit($"reminder", .runAt = inFiveMinutes)
```

## Crash recovery

Call `recover()` before starting workers to reset any jobs that were left in `running` state by a prior crash:

```litac
q.recover()  // default: reset jobs locked more than 60 s ago
WorkerPoolOpen(&q, 4, myHandler, &pool)
```

## API reference

### Opening and closing

| Function | Returns | Description |
|---|---|---|
| `JobQueueOpen(conn, name, queue, allocator)` | `JobStatus` | Open a named queue in an existing SQLite connection |
| `q.close()` | — | Destroy the queue mutex; caller must close the connection |

### Submitting

| Function | Returns | Description |
|---|---|---|
| `q.submit(payload, groupKey, runAt, maxAttempts)` | `i64` | Enqueue a job; returns the job id or -1 on error |

### Single-threaded polling

| Function | Returns | Description |
|---|---|---|
| `q.poll(job)` | `bool` | Claim the next eligible job; returns false when the queue is empty |
| `q.complete(id)` | `JobStatus` | Mark a running job as successfully done |
| `q.fail(id, errorMsg)` | `JobStatus` | Report failure; retries with backoff or marks 'failed' when attempts exhausted |
| `q.retry(id)` | `JobStatus` | Immediately requeue, ignoring the attempt count |

### Maintenance

| Function | Returns | Description |
|---|---|---|
| `q.recover(staleSec)` | `JobStatus` | Reset running jobs older than `staleSec` seconds back to pending |
| `q.stats()` | `JobStats` | Snapshot of pending / running / failed / completed counts |
| `q.getStatus(id)` | `JobStatus` | Current state of a specific job by id |

### Worker pool

| Function | Returns | Description |
|---|---|---|
| `WorkerPoolOpen(queue, count, handler, pool, createCtx, createCtxArg, pollIntervalMs, allocator)` | `JobStatus` | Start `count` background worker threads |
| `pool.shutdown()` | — | Signal all workers to stop and join their threads |

### `JobStatus` enum

`OK = 0` so the `?:` operator fires on any non-zero (error) return.

| Value | Meaning |
|---|---|
| `OK` | Operation succeeded |
| `PENDING` | Job is queued, waiting to run (`getStatus`) |
| `RUNNING` | Job is being processed (`getStatus`) |
| `DONE` | Job completed successfully (`getStatus`) |
| `FAILED` | Job exhausted all retries (`getStatus`) |
| `NOT_FOUND` | No job with that id in this queue |
| `ERROR_DB` | A database prepare, step, or execute call failed |
| `ERROR_ARGS` | Invalid arguments (e.g. queue name too long, worker count ≤ 0) |
| `ERROR_ALLOC` | Memory allocation failed |
| `ERROR_THREAD` | Thread creation failed (`WorkerPoolOpen`) |

### `JobResult` enum (handler return value)

| Value | Meaning |
|---|---|
| `JOB_OK` | Mark the job as done |
| `JOB_FAIL` | Trigger retry backoff (or final failure when attempts exhausted) |
| `JOB_RETRY` | Requeue immediately, regardless of attempt count |

## Database schema

All queues share a single `jobs` table. Each queue is scoped by its name so multiple queues can coexist in the same database without interfering. The schema is created automatically on `JobQueueOpen`.
