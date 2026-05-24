# std/testcontainers

Spin up real Docker containers in your LitaC tests. Containers start before your test, wait until they are ready, and are stopped automatically when the process exits.

## Requirements

- Docker daemon running and accessible via the `docker` CLI
- LitaC stdlib (for `std/net`, `std/http`, `std/string`, etc.)

## Imports

```litac
import "std/testcontainers"           // Container, ContainerConfig, ContainerStatus
import "std/testcontainers/presets"   // RedisContainer, PostgresContainer, etc.
```

`import "std/testcontainers"` re-exports all public types from `std/testcontainers/types`, so you only need one import for the core API.

---

## Quick Start

```litac
import "std/assert"
import "std/testcontainers"
import "std/testcontainers/presets"

@test
func testRedis() {
    var cfg = RedisContainer()
    defer cfg.free()
    var c: Container
    assert(c.start(&cfg) == ContainerStatus.OK)
    defer c.stop()

    var port = c.getPort(6379)
    assert(port > 0)
    // connect to localhost:port ...
}
```

---

## API

### ContainerStatus

```litac
enum ContainerStatus {
    OK = 0,
    ERROR_DOCKER_RUN,     // daemon unreachable, bad image, or bad config
    ERROR_PORT_MAPPING,   // could not resolve a host port after the container started
    ERROR_WAIT_TIMEOUT,   // container started but readiness check timed out
}
```

### Container

```litac
struct Container { /* opaque */ }

// Start the container from config. Returns ContainerStatus.OK on success.
// The caller owns the Container (stack or heap). Registered for atexit cleanup.
func (c: *Container) start(config: *ContainerConfig, alloc: *const Allocator = defaultAllocator) : ContainerStatus

// Stop and remove the container. Deregisters from atexit cleanup.
func (c: *Container) stop() : bool

// Returns the container ID (short 64-char SHA).
func (c: *Container) id() : String

// Returns the host port mapped to containerPort, or -1 if not found.
func (c: *Container) getPort(containerPort: i32) : i32

// Appends stdout+stderr to out. Returns true on success.
func (c: *Container) logs(out: *StringBuilder) : bool

// Runs cmd inside the container via `sh -c`. Returns the exit code.
func (c: *Container) exec(cmd: String) : i32
```

### ContainerConfig

```litac
struct ContainerConfig {
    image: String            // e.g. $"redis"
    tag:   String            // e.g. $"7-alpine"  (empty → "latest")
    ports: Array<i32>        // container ports to expose (host ports assigned randomly)
    env:   Array<EnvVar>     // KEY=VALUE pairs
    cmd:   Array<String>     // optional command override
    wait:  WaitStrategy      // readiness check
}
```

Build a config manually or use a preset (see below).

### WaitStrategy

```litac
enum WaitStrategyKind { PORT, LOG, HTTP }

struct WaitStrategy {
    kind:      WaitStrategyKind
    port:      i32      // PORT / HTTP: container port to map
    path:      String   // HTTP only: e.g. $"/health"
    pattern:   String   // LOG only: substring to match in docker logs
    timeoutMs: i64      // 0 → 30 000 ms
    pollMs:    i64      // 0 → 500 ms
}
```

- **PORT** — polls TCP connect until the mapped host port accepts connections.
- **LOG** — polls `docker logs` until the output contains `pattern`.
- **HTTP** — polls `GET http://localhost:<hostPort><path>` until a 2xx response.

If no `WaitStrategy` is set (`kind` defaults to 0 = `PORT`), set a port you know is exposed; or zero-value the struct and skip the wait entirely by not setting any fields (kind=PORT with port=0 returns immediately).

---

## Presets

### Redis

```litac
import "std/testcontainers/presets"

var cfg = RedisContainer()                    // redis:7-alpine, port 6379
var cfg = RedisContainer(.tag = $"6-alpine")  // override tag
```

### PostgreSQL

```litac
var cfg = PostgresContainer(
    .password = $"secret",                    // required
    .db       = $"mydb",                      // default: "test"
    .user     = $"postgres",                  // default: "postgres"
    .tag      = $"16-alpine"                  // default: "16-alpine"
)
// port 5432, LOG wait for "database system is ready to accept connections"
```

### MySQL

```litac
var cfg = MySQLContainer(
    .password = $"secret",   // required
    .db       = $"mydb",     // default: "test"
    .user     = $"root",     // default: "root"
    .tag      = $"8"         // default: "8"
)
// port 3306, LOG wait for "ready for connections"
```

### HTTP service

```litac
var cfg = HttpContainer(
    .image      = $"myapp",
    .tag        = $"latest",
    .port       = 8080,
    .healthPath = $"/health"   // default: "/"
)
// HTTP wait on port 8080
```

---

## Custom Configuration

```litac
import "std/testcontainers"
import "std/array"

@test
func testCustomContainer() {
    var cfg = ContainerConfig{
        image = $"redis",
        tag   = $"7-alpine",
        ports = ArrayInit<i32>(1, defaultAllocator),
        env   = ArrayInit<EnvVar>(1, defaultAllocator),
        cmd   = ArrayInit<String>(0, defaultAllocator),
        wait  = WaitStrategy{
            kind      = WaitStrategyKind.PORT,
            port      = 6379,
            timeoutMs = 15_000_i64,
        }
    }
    cfg.ports.add(6379)
    cfg.env.add(EnvVar{$"MY_VAR", $"hello"})

    var c: Container
    assert(c.start(&cfg) == ContainerStatus.OK)
    defer cfg.free()
    defer c.stop()

    // use c.getPort(6379) to get the mapped host port
}
```

---

## Automatic Cleanup

`start()` registers the container in a global atexit list. If the test process exits without calling `stop()`, all registered containers are stopped. Use `defer c.stop()` for deterministic cleanup within a test.

---

## Docker Runtime Setup

### macOS

Docker Desktop and Colima are both supported.

**Option A — Docker Desktop**
Download and install from [docker.com](https://www.docker.com/products/docker-desktop/). Start the app; the `docker` CLI is placed on `PATH` automatically.

**Option B — Colima (lightweight, no GUI required)**
```sh
brew install colima docker
colima start          # default: 2 CPU, 2 GB RAM, VirtioFS
```

Add to your shell profile so `docker` uses Colima's socket:
```sh
export DOCKER_HOST="unix://${HOME}/.colima/default/docker.sock"
```

Verify:
```sh
docker version
docker run --rm hello-world
```

### Linux

Install Docker Engine via your distribution's package manager or the official script:

```sh
# Debian / Ubuntu
sudo apt-get update
sudo apt-get install -y docker.io
sudo systemctl enable --now docker

# Run without sudo (log out and back in after)
sudo usermod -aG docker $USER
```

Verify:
```sh
docker version
docker run --rm hello-world
```

### Windows

**Option A — Docker Desktop for Windows**
Requires WSL 2 or Hyper-V. Download from [docker.com](https://www.docker.com/products/docker-desktop/). The `docker` CLI is added to `PATH` automatically.

**Option B — Docker inside WSL 2**
Install Docker Engine inside your WSL 2 distro (same steps as Linux above). The `docker` CLI inside WSL can reach the daemon. `std/testcontainers` uses `popen`-based subprocess calls, which work in WSL 2 environments.

Verify from your build shell:
```sh
docker version
docker run --rm hello-world
```

---

## Running the Tests

From the `litac-lang` project root:

```sh
litac test -file test/std/testcontainers/testcontainers_test.lita
```

The tests require a running Docker daemon. They will fail (not skip) if Docker is unavailable.
