# litac-lang `0.1.2-alpha`

## Modules

- [std::unicode::utf8](std_unicode_utf8.md)
- [std::mem::bucket_allocator](std_mem_bucket_allocator.md)
- [std::web::web_request](std_web_web_request.md)
- [std::cmdline](std_cmdline.md)
- [std::thread::thread_posix](std_thread_thread_posix.md)
- [std::mem](std_mem.md)
- [std::regex::regex](std_regex_regex.md)
- [std::ipc::ipc](std_ipc_ipc.md)
- [std::uri::uri](std_uri_uri.md)
- [std::mem::thread_safe_allocator](std_mem_thread_safe_allocator.md)
- [std::process::process](std_process_process.md)
- [std::type](std_type.md)
- [std::string::builder](std_string_builder.md)
- [std::map](std_map.md)
- [std::encoding::base64::base64](std_encoding_base64_base64.md)
- [std::limits](std_limits.md)
- [std::db::sqlite](std_db_sqlite.md)
- [std::thread](std_thread.md)
- [std::intrinsics::intrinsics](std_intrinsics_intrinsics.md)
- [std::mem::virtual_mem](std_mem_virtual_mem.md)
- [std::mem::stack_allocator](std_mem_stack_allocator.md)
- [std::crypto::random::random_posix](std_crypto_random_random_posix.md)
- [std::thread::thread_win](std_thread_thread_win.md)
- [std::log](std_log.md)
- [std::db::migrations::migrations](std_db_migrations_migrations.md)
- [std::web](std_web.md) — 

A hello world web application:

```litac

import "std/libc"
import "std/web"
import "std/string/buffer"
import "std/json"
import "std/json/to_json"
import "std/json/from_json"
import "std/string/builder"

@json
public struct EchoResponse {
    text: *const char
    errors: *const char
}

@get_request(.uri = "/echo")
public func Echo(ctx: *WebContext) : i32 {
    var param = ctx.request.getQueryValueCopy("say")

    var response = EchoResponse{
        .text = param.cStr()
    }
    response.toJson(ctx.response.body)

    return 200
}

func main(len: i32, args: **char) : i32 {
    var server: WebServer;
    var config = WebConfig{}
    printf("Starting http server: %s\n", config.addr)

    server.init(&config)

    server.start()

    printf("Terminated http server")
    return 0
}

```


- [std::fs](std_fs.md)
- [std::thread::barrier_win](std_thread_barrier_win.md)
- [std::libc::signal](std_libc_signal.md)
- [std::mem::virtual_mem_win](std_mem_virtual_mem_win.md)
- [std::system::system_win](std_system_system_win.md)
- [std::crypto::random::random](std_crypto_random_random.md)
- [std::zip::miniz::miniz](std_zip_miniz_miniz.md)
- [std::mem::arena_allocator](std_mem_arena_allocator.md)
- [std::net::net_posix](std_net_net_posix.md)
- [std::thread::thread_pool](std_thread_thread_pool.md)
- [std::libc](std_libc.md)
- [std::test::test](std_test_test.md)
- [std::db::db](std_db_db.md)
- [std::fs::tinydir](std_fs_tinydir.md)
- [std::array](std_array.md)
- [std::string::buffer](std_string_buffer.md)
- [std::db::sqlite::sqlite_db](std_db_sqlite_sqlite_db.md)
- [std::db::sqlite::db_test](std_db_sqlite_db_test.md)
- [std::assert](std_assert.md)
- [std::terminal](std_terminal.md)
- [std::json::to_json](std_json_to_json.md)
- [std::profile](std_profile.md)
- [std::regex::re::re](std_regex_re_re.md)
- [std::crypto::random::random_win](std_crypto_random_random_win.md)
- [std::ascii](std_ascii.md)
- [std::crypto::random::random_macos](std_crypto_random_random_macos.md)
- [std::net](std_net.md)
- [std::zip::zip](std_zip_zip.md)
- [std::mem::virtual_mem_posix](std_mem_virtual_mem_posix.md)
- [std::db::pool_test](std_db_pool_test.md)
- [std::mem::track_allocator](std_mem_track_allocator.md)
- [std::json::from_json](std_json_from_json.md)
- [std::thread::thread_test](std_thread_thread_test.md)
- [std::system::system_posix](std_system_system_posix.md)
- [std::uuid](std_uuid.md)
- [std::io](std_io.md)
- [std::json](std_json.md)
- [std::mem::libc_allocator](std_mem_libc_allocator.md)
- [std::db::orm](std_db_orm.md)
- [std::io::io_win](std_io_io_win.md)
- [std::process::subprocess](std_process_subprocess.md)
- [std::string](std_string.md)
- [std::time](std_time.md)
- [std::system](std_system.md)
- [std::db::pool](std_db_pool.md)
- [std::net::posix_socket](std_net_posix_socket.md)
- [std::http::libcurl](std_http_libcurl.md)
- [std::atomic](std_atomic.md)
- [std::thread::barrier_posix](std_thread_barrier_posix.md)
- [std::mem::debug_allocator](std_mem_debug_allocator.md)
- [std::crypto::sha1::sha1](std_crypto_sha1_sha1.md)
- [std::web::mongoose](std_web_mongoose.md)
- [std::mem::linear_allocator](std_mem_linear_allocator.md)
- [std::thread::barrier_mac](std_thread_barrier_mac.md)
- [std::hash](std_hash.md)
- [std::http::http](std_http_http.md)
- [std::mem::virtual_allocator](std_mem_virtual_allocator.md)
- [std::bucket_list](std_bucket_list.md)
- [std::ipc::ipc_unix](std_ipc_ipc_unix.md)
- [std::thread::barrier](std_thread_barrier.md)
