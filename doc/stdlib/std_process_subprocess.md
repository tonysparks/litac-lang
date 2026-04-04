# std::process::subprocess

## Functions

<a id="func-subprocess_create"></a>

### func subprocess_create(command_line: \*\*const char, options: i32, out_process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s)) : i32

*public* | *stdlib/std/process/subprocess.lita:33*

---

<a id="func-subprocess_create_ex"></a>

### func subprocess_create_ex(command_line: \*\*const char, options: i32, environment: \*\*const char, process_cwd: \*const char, out_process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s)) : i32

*public* | *stdlib/std/process/subprocess.lita:50*

---

<a id="func-subprocess_stdin"></a>

### func subprocess_stdin(process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s)) : \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/process/subprocess.lita:64*

---

<a id="func-subprocess_stdout"></a>

### func subprocess_stdout(process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s)) : \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/process/subprocess.lita:73*

---

<a id="func-subprocess_stderr"></a>

### func subprocess_stderr(process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s)) : \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/process/subprocess.lita:86*

---

<a id="func-subprocess_join"></a>

### func subprocess_join(process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s), out_return_code: \*const i32) : i32

*public* | *stdlib/std/process/subprocess.lita:96*

---

<a id="func-subprocess_destroy"></a>

### func subprocess_destroy(process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s)) : i32

*public* | *stdlib/std/process/subprocess.lita:105*

---

<a id="func-subprocess_terminate"></a>

### func subprocess_terminate(process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s)) : i32

*public* | *stdlib/std/process/subprocess.lita:114*

---

<a id="func-subprocess_read_stdout"></a>

### func subprocess_read_stdout(process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s), buffer: \*const char, size: u32) : u32

*public* | *stdlib/std/process/subprocess.lita:127*

---

<a id="func-subprocess_read_stderr"></a>

### func subprocess_read_stderr(process: \*const [subprocess_s](std_process_subprocess.md#struct-subprocess_s), buffer: \*const char, size: u32) : u32

*public* | *stdlib/std/process/subprocess.lita:140*

---

## Types

<a id="struct-subprocess_s"></a>

### struct subprocess_s

*public* | *stdlib/std/process/subprocess.lita:9*

---

<a id="enum-subprocess_option_e"></a>

### enum subprocess_option_e

*public* | *stdlib/std/process/subprocess.lita:13*

| Value | Description |
|-------|-------------|
| `subprocess_option_combined_stdout_stderr` |  |
| `subprocess_option_inherit_environment` |  |
| `subprocess_option_enable_async` |  |
| `subprocess_option_search_user_path` |  |

---

