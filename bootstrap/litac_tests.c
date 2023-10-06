#ifndef _LITAC_HEADER_H
#define _LITAC_HEADER_H

// Generated on Thu Oct  5 20:02:07 2023

#include <stdint.h>
#include <stddef.h>
typedef int8_t    litaC_i8;
typedef int16_t   litaC_i16;
typedef int32_t   litaC_i32;
typedef int64_t   litaC_i64;
typedef uint8_t   litaC_u8;
typedef uint16_t  litaC_u16;
typedef uint32_t  litaC_u32;
typedef uint64_t  litaC_u64;
typedef float     litaC_f32;
typedef double    litaC_f64;
//typedef int8_t    litaC_bool;
typedef size_t    litaC_usize;

#if _MSC_VER
#define LITAC_THREADLOCAL __declspec(thread)
#define LITAC_INLINE static inline __forceinline
#define LITAC_NOINLINE __declspec(noinline)
#define LITAC_PACKED __pragma(pack(push, 1))
#define LITAC_PACKED_POP __pragma(pack(pop))
#define LITAC_EXPORT __declspec(dllexport)
#endif

#if __GNUC__
#define LITAC_THREADLOCAL __thread
#define LITAC_INLINE static inline __attribute__((always_inline))
#define LITAC_NOINLINE __attribute__((noinline))
#define LITAC_PACKED _Pragma("pack(push)")
#define LITAC_PACKED_POP _Pragma("pack(pop)")
#define LITAC_EXPORT __attribute__((visibility("default")))
#endif

#if __TINYC__
#define LITAC_THREADLOCAL
#define LITAC_INLINE
#define LITAC_NOINLINE
#define LITAC_PACKED __attribute__((packed))
#define LITAC_PACKED_POP
#define LITAC_EXPORT __attribute__((dllexport))
#endif

typedef int8_t litaC_bool;
#define litaC_true (1)
#define litaC_false (0)
#define litaC_void void
typedef char   litaC_char;

#line 14 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

#define litaC_mem__KiB (1024)

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

#define litaC_mem__MiB (1024 * litaC_mem__KiB)

#line 16 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

#define litaC_mem__GiB (1024 * litaC_mem__MiB)

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"

#define litaC_debug_allocator__MAX_PATH (256)

#line 232 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"

#define litaC_array__MAX_LEVELS (300)

#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"

#define litaC_string_buffer__MAX_BUFFER_SIZE (32)
#include "assert.h"

#include <stdarg.h>

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <ctype.h>

#include <limits.h>

#include <string.h>


#define MIN(x, y) ((x) <= (y) ? (x) : (y))
#define MAX(x, y) ((x) >= (y) ? (x) : (y))
#define ABS(x)    ((x < 0) ? (x) * -1 : (x))


#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN
#endif

#if !defined(OS_WIN) || defined(__TINYC__)
size_t strnlen(const char * s, size_t len) {
    size_t i = 0;
    for ( ; i < len && s[i] != '\0'; ++i);
    return i;
}
#endif



#define LITAC_DEFAULT_ALIGNMENT (2*sizeof(void*))


#line 5 "C:/Users/antho/git/litac-lang/src/common.lita"
typedef enum litaC_common__LogLevel {
    litaC_common__LogLevel_TRACE,
    litaC_common__LogLevel_INFO,
    litaC_common__LogLevel_DEBUG,
    litaC_common__LogLevel_ERROR,
    litaC_common__LogLevel_FATAL
} litaC_common__LogLevel;
typedef struct litaC_builtins__any litaC_builtins__any;
typedef struct litaC_mem__Allocator litaC_mem__Allocator;
typedef struct litaC_debug_allocator__Allocation litaC_debug_allocator__Allocation;
typedef struct litaC_debug_allocator__DebugAllocator litaC_debug_allocator__DebugAllocator;
typedef struct litaC_string_buffer__StringBuffer litaC_string_buffer__StringBuffer;
typedef struct litaC_io__File litaC_io__File;


#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
typedef enum litaC_io__FileStatus {
    litaC_io__FileStatus_Ok = 
    #line 23 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    0,
    litaC_io__FileStatus_FileNotFoundError,
    litaC_io__FileStatus_IOError
} litaC_io__FileStatus;

#line 28 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
typedef enum litaC_io__FileOpenOp {
    litaC_io__FileOpenOp_READ_ONLY,
    litaC_io__FileOpenOp_READ_ONLY_BINARY,
    litaC_io__FileOpenOp_WRITE,
    litaC_io__FileOpenOp_WRITE_BINARY,
    litaC_io__FileOpenOp_WRITE_APPEND,
    litaC_io__FileOpenOp_WRITE_APPEND_BINARY
} litaC_io__FileOpenOp;
typedef struct litaC_string_view__StringView litaC_string_view__StringView;
typedef struct litaC_array__Array_cb__ptr_Allocation_ce_ litaC_array__Array_cb__ptr_Allocation_ce_;

#line 15 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Log(litaC_common__LogLevel litaC_level,const litaC_char* litaC_format,...);

#line 22 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Logv(litaC_common__LogLevel litaC_level,const litaC_char* litaC_format,va_list litaC_args);

#line 47 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Info(const litaC_char* litaC_format,...);

#line 54 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Debug(const litaC_char* litaC_format,...);

#line 61 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Error(const litaC_char* litaC_format,...);

#line 68 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Panic(const litaC_char* litaC_format,...);

#line 76 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_char* litaC_common__EscapeName(const litaC_char* litaC_name,litaC_i32 litaC_len,litaC_string_buffer__StringBuffer* litaC_sb);


#line 116 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__EscapeTest();

#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__memduplicate(const litaC_void* litaC_p,litaC_usize litaC_len,const litaC_mem__Allocator* litaC_a);

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_bool litaC_mem__isPowerOfTwo(litaC_usize litaC_x);

#line 65 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_usize litaC_mem__alignForward(litaC_usize litaC_ptr,litaC_usize litaC_align);
LITAC_INLINE 

#line 94 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__Allocator_alloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);
LITAC_INLINE 

#line 101 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__Allocator_calloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_num,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);
LITAC_INLINE 

#line 109 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__Allocator_realloc(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr,litaC_usize litaC_oldsize,litaC_usize litaC_newsize,const litaC_char* litaC_file,litaC_u64 litaC_line);
LITAC_INLINE 

#line 118 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__Allocator_free(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr);


#line 254 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__ModuleInit();


#line 260 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__ModuleDestroy();


#line 279 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__testLineNumber();

#line 18 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
litaC_void* litaC_libc_allocator__cMalloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);

#line 25 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
litaC_void* litaC_libc_allocator__cCalloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_num,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);

#line 33 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
litaC_void* litaC_libc_allocator__cRealloc(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr,litaC_usize litaC_oldSize,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);

#line 42 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
litaC_void litaC_libc_allocator__cFree(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void litaC_debug_allocator__DebugAllocator_init(litaC_debug_allocator__DebugAllocator* litaC_d,const litaC_mem__Allocator* litaC_alloc);

#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void litaC_debug_allocator__DebugAllocator_free(litaC_debug_allocator__DebugAllocator* litaC_d);

#line 53 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void litaC_debug_allocator__DebugAllocator_report(litaC_debug_allocator__DebugAllocator* litaC_d);

#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void* litaC_debug_allocator__DebugAllocator_malloc(litaC_debug_allocator__DebugAllocator* litaC_d,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);

#line 104 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void* litaC_debug_allocator__DebugMalloc(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);

#line 112 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void* litaC_debug_allocator__DebugCalloc(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_num,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);

#line 126 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void* litaC_debug_allocator__DebugRealloc(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr,litaC_usize litaC_oldSize,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);

#line 216 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void litaC_debug_allocator__DebugFree(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr);

#line 17 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_string_buffer__StringBuffer litaC_string_buffer__StringBufferInit(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 25 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_init(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 39 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_free(litaC_string_buffer__StringBuffer* litaC_b);

#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_appendStr(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str);

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_appendStrn(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendFloat(litaC_string_buffer__StringBuffer* litaC_b,litaC_f64 litaC_f);

#line 77 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendI32(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_i);

#line 81 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendI64(litaC_string_buffer__StringBuffer* litaC_b,litaC_i64 litaC_i);

#line 85 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendU32(litaC_string_buffer__StringBuffer* litaC_b,litaC_u32 litaC_i);

#line 89 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendU64(litaC_string_buffer__StringBuffer* litaC_b,litaC_u64 litaC_i);

#line 93 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendChar(litaC_string_buffer__StringBuffer* litaC_b,litaC_char litaC_c);

#line 104 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_append(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_format,...);

#line 126 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendArgs(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_format,va_list litaC_args);

#line 185 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_delete(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_start,litaC_i32 litaC_end);

#line 210 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_bool litaC_string_buffer__StringBuffer_contains(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 214 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_indexOf(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 218 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_indexOfAt(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex);

#line 223 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_replace(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_start,litaC_i32 litaC_end,const litaC_char* litaC_str);

#line 228 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_insert(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_index,const litaC_char* litaC_format,...);

#line 279 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_trim(litaC_string_buffer__StringBuffer* litaC_b);

#line 316 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_copyTo(litaC_string_buffer__StringBuffer* litaC_b,litaC_char* litaC_buf,litaC_i32 litaC_len,litaC_bool litaC_addZero);

#line 321 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_forEach(litaC_string_buffer__StringBuffer* litaC_b,litaC_bool (*litaC_fn)(litaC_char));
LITAC_INLINE 

#line 330 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_bool litaC_string_buffer__StringBuffer_empty(litaC_string_buffer__StringBuffer* litaC_b);
LITAC_INLINE 

#line 335 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_size(litaC_string_buffer__StringBuffer* litaC_b);
LITAC_INLINE 

#line 340 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_clear(litaC_string_buffer__StringBuffer* litaC_b);

#line 344 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
const litaC_char* litaC_string_buffer__StringBuffer_cStrConst(litaC_string_buffer__StringBuffer* litaC_b);

#line 348 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_char* litaC_string_buffer__StringBuffer_cStr(litaC_string_buffer__StringBuffer* litaC_b);
LITAC_INLINE 

#line 358 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_string_view__StringView litaC_string_buffer__StringBuffer_asStringView(litaC_string_buffer__StringBuffer* litaC_b);

#line 365 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_char litaC_string_buffer__StringBuffer_get(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_index);

#line 373 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_reserve(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_length);

#line 382 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__BufferGrow(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_increment);

#line 45 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_io__FileStatus litaC_io__File_open(litaC_io__File* litaC_file,const litaC_char* litaC_filename,litaC_io__FileOpenOp litaC_op);

#line 86 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_void litaC_io__File_close(litaC_io__File* litaC_file);

#line 97 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_i64 litaC_io__FileLength(const litaC_char* litaC_fileName);

#line 112 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_io__FileStatus litaC_io__ReadFile(const litaC_char* litaC_fileName,litaC_char** litaC_data,litaC_usize* litaC_length,const litaC_mem__Allocator* litaC_alloc);

#line 159 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_io__FileStatus litaC_io__WriteFile(const litaC_char* litaC_fileName,const litaC_char* litaC_buffer,litaC_usize litaC_len);

#line 174 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_io__FileStatus litaC_io__File_writeBytes(litaC_io__File* litaC_file,const litaC_char* litaC_buffer,litaC_usize litaC_len);

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_string_view__StringView litaC_string_view__StringViewInit(const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 24 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_u32 litaC_string_view__StringView_hash(litaC_string_view__StringView litaC_b);

#line 32 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_string_view__StringView litaC_string_view__StringView_substring(litaC_string_view__StringView litaC_b,litaC_i32 litaC_start,litaC_i32 litaC_end);

#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_startsWith(litaC_string_view__StringView litaC_b,const litaC_char* litaC_prefix,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex);

#line 71 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_endsWith(litaC_string_view__StringView litaC_b,const litaC_char* litaC_suffix,litaC_i32 litaC_len);

#line 78 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_equals(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 91 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_equalsStringView(litaC_string_view__StringView litaC_b,litaC_string_view__StringView litaC_other);

#line 95 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_contains(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 99 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_indexOf(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_indexOfAt(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex);

#line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_lastIndexOfAt(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex);

#line 199 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_copyTo(litaC_string_view__StringView litaC_b,litaC_char* litaC_buf,litaC_i32 litaC_len,litaC_bool litaC_addZero);

#line 216 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_string_view__StringView litaC_string_view__StringView_copy(litaC_string_view__StringView litaC_s,const litaC_mem__Allocator* litaC_allocator);

#line 235 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__StringView_forEach(litaC_string_view__StringView litaC_b,litaC_bool (*litaC_fn)(litaC_char));

#line 243 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_empty(litaC_string_view__StringView litaC_b);

#line 247 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_size(litaC_string_view__StringView litaC_b);

#line 251 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__StringView_clear(litaC_string_view__StringView litaC_b);

#line 255 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_char litaC_string_view__StringView_get(litaC_string_view__StringView litaC_b,litaC_i32 litaC_index);


#line 264 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__testEquals();


#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__testContains();


#line 295 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__testStartsWith();


#line 312 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__testEndsWith();


#line 325 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__testIndexOf();


#line 341 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__testLastIndexOf();

#line 13 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__char_isWhitespace(litaC_char litaC_this);

#line 17 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__char_isNumeric(litaC_char litaC_this);

#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__char_isAlphabetic(litaC_char litaC_this);

#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__char_isAlphanumeric(litaC_char litaC_this);


#line 31 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_void litaC_ascii__testWhitespace();

#line 1 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
const litaC_char* litaC_io__FileStatusAsStr(litaC_io__FileStatus litaC_enumType);

#line 2 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_i32 litaC_common____LitaTestMain(litaC_i32 litaC_len,litaC_char** litaC_args);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_free_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a);
LITAC_INLINE 

#line 193 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_debug_allocator__Allocation* litaC_array__Array_get_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_index);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_debug_allocator__Allocation* litaC_element);

#line 216 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_increment);

#line 128 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_debug_allocator__Allocation* litaC_array__Array_removeAt_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_index);


// Generated code for interfaces

#endif /* _LITAC_HEADER_H */


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// translated code begins
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



#line 3 "C:/Users/antho/git/litac-lang/stdlib/std/builtins.lita"
struct litaC_builtins__any {
    
    #line 4 "C:/Users/antho/git/litac-lang/stdlib/std/builtins.lita"
    litaC_void* value;
    
    #line 5 "C:/Users/antho/git/litac-lang/stdlib/std/builtins.lita"
    litaC_u64 id;
    
};


#line 86 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
struct litaC_mem__Allocator {
    
    #line 87 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_void* (*allocFn)(const litaC_mem__Allocator*,litaC_usize,const litaC_char*,litaC_u64);
    
    #line 88 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_void* (*callocFn)(const litaC_mem__Allocator*,litaC_usize,litaC_usize,const litaC_char*,litaC_u64);
    
    #line 89 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_void* (*reallocFn)(const litaC_mem__Allocator*,litaC_void*,litaC_usize,litaC_usize,const litaC_char*,litaC_u64);
    
    #line 90 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_void (*freeFn)(const litaC_mem__Allocator*,litaC_void*);
    
};


#line 13 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
struct litaC_debug_allocator__Allocation {
    
    #line 14 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_void* addr;
    
    #line 15 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_usize size;
    
    #line 16 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_u64 line;
    
    #line 17 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_char filename[256];
    
};


#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
struct litaC_string_buffer__StringBuffer {
    
    #line 11 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_char* buffer;
    
    #line 12 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 length;
    
    #line 13 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 capacity;
    
    #line 14 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    const litaC_mem__Allocator* alloc;
    
};


#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
struct litaC_io__File {
    
    #line 16 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    FILE* file;
    
};


#line 5 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
struct litaC_string_view__StringView {
    
    #line 6 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    const litaC_char* buffer;
    
    #line 7 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 length;
    
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_Allocation_ce_ {
    
    #line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_i32 length;
    
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_i32 capacity;
    
    #line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_debug_allocator__Allocation** elements;
    
    #line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    const litaC_mem__Allocator* alloc;
    
};


#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
struct litaC_debug_allocator__DebugAllocator {
    
    #line 27 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_mem__Allocator alloc;
    
    #line 28 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    const litaC_mem__Allocator* decorated;
    
    #line 29 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_array__Array_cb__ptr_Allocation_ce_ allocations;
    
    #line 30 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_u32 totalAllocations;
    
    #line 31 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_usize totalBytesAllocated;
    
    #line 32 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_usize totalBytesFreed;
    
};


#line 13 "C:/Users/antho/git/litac-lang/src/common.lita"
FILE* litaC_common__outputFile = NULL;

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
const litaC_mem__Allocator* litaC_mem__defaultAllocator = (const litaC_mem__Allocator*)(&((litaC_debug_allocator__DebugAllocator) {
    
}));

#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
const litaC_mem__Allocator* litaC_libc_allocator__cAllocator = (const litaC_mem__Allocator*)(&((litaC_mem__Allocator) {
    
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    .allocFn = &(litaC_libc_allocator__cMalloc),
    
    #line 11 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    .callocFn = &(litaC_libc_allocator__cCalloc),
    
    #line 12 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    .reallocFn = &(litaC_libc_allocator__cRealloc),
    
    #line 13 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    .freeFn = &(litaC_libc_allocator__cFree)
}));

#line 4 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__WHITESPACE[256] =  {
    
    #line 5 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    [9] = litaC_true,
    
    #line 6 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    [10] = litaC_true,
    
    #line 7 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    [11] = litaC_true,
    
    #line 8 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    [12] = litaC_true,
    
    #line 9 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    [13] = litaC_true,
    
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    [32] = litaC_true
};

#line 15 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Log(litaC_common__LogLevel litaC_level,const litaC_char* litaC_format,...) {
    
    #line 16 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_list litaC_args;
    
    #line 17 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_start(litaC_args, litaC_format);
    
    #line 18 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_common__Logv(litaC_level, litaC_format, litaC_args);
    
    #line 19 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_end(litaC_args);
    
}


#line 22 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Logv(litaC_common__LogLevel litaC_level,const litaC_char* litaC_format,va_list litaC_args) {
    
    #line 23 "C:/Users/antho/git/litac-lang/src/common.lita"
    if(!(litaC_common__outputFile)) {
        {
            
            #line 26 "C:/Users/antho/git/litac-lang/src/common.lita"
            litaC_common__outputFile = fopen("./litac.log", "w");
            
            #line 28 "C:/Users/antho/git/litac-lang/src/common.lita"
            if(!(litaC_common__outputFile)) {
                {
                    
                    #line 29 "C:/Users/antho/git/litac-lang/src/common.lita"
                    litaC_common__outputFile = stdout;
                    
                    
                }
                
            } 
            
            
            
        }
        
    } 
    
    
    #line 33 "C:/Users/antho/git/litac-lang/src/common.lita"
    if(litaC_level > litaC_common__LogLevel_DEBUG) {
        {
            
            #line 34 "C:/Users/antho/git/litac-lang/src/common.lita"
            vfprintf(stderr, litaC_format, litaC_args);
            
            #line 35 "C:/Users/antho/git/litac-lang/src/common.lita"
            fflush(stderr);
            
            
        }
        
    } else {
        
        #line 37 "C:/Users/antho/git/litac-lang/src/common.lita"
        {
            
            #line 38 "C:/Users/antho/git/litac-lang/src/common.lita"
            vfprintf(litaC_common__outputFile, litaC_format, litaC_args);
            
            #line 39 "C:/Users/antho/git/litac-lang/src/common.lita"
            fflush(litaC_common__outputFile);
            
            
        }
    } 
    
    
    #line 42 "C:/Users/antho/git/litac-lang/src/common.lita"
    if(litaC_level == litaC_common__LogLevel_FATAL) {
        {
            
            #line 43 "C:/Users/antho/git/litac-lang/src/common.lita"
            exit(2);
            
            
        }
        
    } 
    
    
}


#line 47 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Info(const litaC_char* litaC_format,...) {
    
    #line 48 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_list litaC_args;
    
    #line 49 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_start(litaC_args, litaC_format);
    
    #line 50 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_common__Logv(litaC_common__LogLevel_INFO, litaC_format, litaC_args);
    
    #line 51 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_end(litaC_args);
    
}


#line 54 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Debug(const litaC_char* litaC_format,...) {
    
    #line 55 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_list litaC_args;
    
    #line 56 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_start(litaC_args, litaC_format);
    
    #line 57 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_common__Logv(litaC_common__LogLevel_DEBUG, litaC_format, litaC_args);
    
    #line 58 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_end(litaC_args);
    
}


#line 61 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Error(const litaC_char* litaC_format,...) {
    
    #line 62 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_list litaC_args;
    
    #line 63 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_start(litaC_args, litaC_format);
    
    #line 64 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_common__Logv(litaC_common__LogLevel_ERROR, litaC_format, litaC_args);
    
    #line 65 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_end(litaC_args);
    
}


#line 68 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_void litaC_common__Panic(const litaC_char* litaC_format,...) {
    
    #line 69 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_list litaC_args;
    
    #line 70 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_start(litaC_args, litaC_format);
    
    #line 71 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_common__Logv(litaC_common__LogLevel_FATAL, litaC_format, litaC_args);
    
    #line 72 "C:/Users/antho/git/litac-lang/src/common.lita"
    va_end(litaC_args);
    
}


#line 76 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_char* litaC_common__EscapeName(const litaC_char* litaC_name,litaC_i32 litaC_len,litaC_string_buffer__StringBuffer* litaC_sb) {
    
    #line 77 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_string_buffer__StringBuffer_appendStrn(litaC_sb, litaC_name, litaC_len);
    
    #line 78 "C:/Users/antho/git/litac-lang/src/common.lita"
    for(litaC_i32 litaC_i = 0;litaC_i < litaC_sb->length;) {
        {
            
            #line 79 "C:/Users/antho/git/litac-lang/src/common.lita"
            litaC_char litaC_c = litaC_sb->buffer[litaC_i];
            
            #line 81 "C:/Users/antho/git/litac-lang/src/common.lita"
            switch(litaC_c) {
                
                #line 82 "C:/Users/antho/git/litac-lang/src/common.lita"
                case '*': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_ptr_");
                    litaC_i += 5;
                    break;
                    
                    
                }
                
                #line 83 "C:/Users/antho/git/litac-lang/src/common.lita"
                case '<': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_cb_");
                    litaC_i += 4;
                    break;
                    
                    
                }
                
                #line 84 "C:/Users/antho/git/litac-lang/src/common.lita"
                case '>': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_ce_");
                    litaC_i += 4;
                    break;
                    
                    
                }
                
                #line 85 "C:/Users/antho/git/litac-lang/src/common.lita"
                case '[': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_bb_");
                    litaC_i += 4;
                    break;
                    
                    
                }
                
                #line 86 "C:/Users/antho/git/litac-lang/src/common.lita"
                case ']': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_be_");
                    litaC_i += 4;
                    break;
                    
                    
                }
                
                #line 87 "C:/Users/antho/git/litac-lang/src/common.lita"
                case '(': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_pb_");
                    litaC_i += 4;
                    break;
                    
                    
                }
                
                #line 88 "C:/Users/antho/git/litac-lang/src/common.lita"
                case ')': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_pe_");
                    litaC_i += 4;
                    break;
                    
                    
                }
                
                #line 89 "C:/Users/antho/git/litac-lang/src/common.lita"
                case ',': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_c_");
                    litaC_i += 3;
                    break;
                    
                    
                }
                
                #line 90 "C:/Users/antho/git/litac-lang/src/common.lita"
                case ' ': {
                    litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_");
                    litaC_i += 1;
                    break;
                    
                    
                }
                
                #line 91 "C:/Users/antho/git/litac-lang/src/common.lita"
                case ':': {
                    {
                        
                        #line 92 "C:/Users/antho/git/litac-lang/src/common.lita"
                        litaC_i32 litaC_n = litaC_i + 1;
                        
                        #line 93 "C:/Users/antho/git/litac-lang/src/common.lita"
                        if(litaC_n < litaC_sb->length) {
                            {
                                
                                #line 94 "C:/Users/antho/git/litac-lang/src/common.lita"
                                litaC_char litaC_nc = litaC_sb->buffer[litaC_n];
                                
                                #line 95 "C:/Users/antho/git/litac-lang/src/common.lita"
                                if(litaC_nc == ':') {
                                    {
                                        
                                        #line 96 "C:/Users/antho/git/litac-lang/src/common.lita"
                                        litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 2, "__");
                                        
                                        #line 97 "C:/Users/antho/git/litac-lang/src/common.lita"
                                        litaC_i += 2;
                                        
                                        #line 98 "C:/Users/antho/git/litac-lang/src/common.lita"
                                        break;
                                        
                                        
                                    }
                                    
                                } 
                                
                                
                                
                            }
                            
                        } 
                        
                        
                        #line 101 "C:/Users/antho/git/litac-lang/src/common.lita"
                        litaC_string_buffer__StringBuffer_replace(litaC_sb, litaC_i, litaC_i + 1, "_r_");
                        
                        #line 102 "C:/Users/antho/git/litac-lang/src/common.lita"
                        litaC_i += 3;
                        
                        #line 103 "C:/Users/antho/git/litac-lang/src/common.lita"
                        break;
                        
                        
                    }
                    
                    
                }
                default: 
                #line 105 "C:/Users/antho/git/litac-lang/src/common.lita"
                {
                    {
                        
                        #line 106 "C:/Users/antho/git/litac-lang/src/common.lita"
                        litaC_i += 1;
                        
                        #line 107 "C:/Users/antho/git/litac-lang/src/common.lita"
                        break;
                        
                        
                    }
                    
                    
                }
            }
            
            
        }
    }
    
    #line 112 "C:/Users/antho/git/litac-lang/src/common.lita"
    return litaC_string_buffer__StringBuffer_cStr(litaC_sb);
    
    
}


#line 116 "C:/Users/antho/git/litac-lang/src/common.lita"

litaC_void litaC_common__EscapeTest() {
    
    #line 117 "C:/Users/antho/git/litac-lang/src/common.lita"
    const char* litaC_x = "std::json::JsonNode";
    
    #line 118 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_string_buffer__StringBuffer litaC_sb = litaC_string_buffer__StringBufferInit(1024, NULL);
    
    #line 119 "C:/Users/antho/git/litac-lang/src/common.lita"
    printf("%s\n", litaC_common__EscapeName(litaC_x, strlen(litaC_x), &((litaC_sb))));
    
}


#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__memduplicate(const litaC_void* litaC_p,litaC_usize litaC_len,const litaC_mem__Allocator* litaC_a) {
    
    #line 50 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    
    #line 51 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_void* litaC_copy = litaC_mem__Allocator_alloc(litaC_a, litaC_len, __FILE__, __LINE__);
    
    #line 52 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    memcpy(litaC_copy, litaC_p, litaC_len);
    
    #line 54 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    return litaC_copy;
    
    
}


#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_bool litaC_mem__isPowerOfTwo(litaC_usize litaC_x) {
    
    #line 62 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    return (litaC_x & (litaC_x - 1)) == 0;
    
    
}


#line 65 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_usize litaC_mem__alignForward(litaC_usize litaC_ptr,litaC_usize litaC_align) {
    
    #line 66 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    assert(litaC_mem__isPowerOfTwo(litaC_align));
    
    #line 68 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_usize litaC_p = litaC_ptr;
    
    #line 69 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_usize litaC_a = litaC_align;
    
    #line 70 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_usize litaC_modulo = litaC_p & (litaC_a - 1);
    
    #line 72 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    if(litaC_modulo != 0) {
        {
            
            #line 73 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
            litaC_p += (litaC_a - litaC_modulo);
            
            
        }
        
    } 
    
    
    #line 76 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    return litaC_p;
    
    
}


#line 94 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
LITAC_INLINE 
litaC_void* litaC_mem__Allocator_alloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 96 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    
    #line 97 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    return litaC_a->allocFn(litaC_a, litaC_size, litaC_file, litaC_line);
    
    
}


#line 101 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
LITAC_INLINE 
litaC_void* litaC_mem__Allocator_calloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_num,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 104 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    
    #line 105 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    return litaC_a->callocFn(litaC_a, litaC_num, litaC_size, litaC_file, litaC_line);
    
    
}


#line 109 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
LITAC_INLINE 
litaC_void* litaC_mem__Allocator_realloc(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr,litaC_usize litaC_oldsize,litaC_usize litaC_newsize,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 113 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    
    #line 114 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    return litaC_a->reallocFn(litaC_a, litaC_ptr, litaC_oldsize, litaC_newsize, litaC_file, litaC_line);
    
    
}


#line 118 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
LITAC_INLINE 
litaC_void litaC_mem__Allocator_free(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr) {
    
    #line 119 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    return litaC_a->freeFn(litaC_a, litaC_ptr);
    
    
}


#line 254 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

litaC_void litaC_mem__ModuleInit() {
    
    #line 255 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_debug_allocator__DebugAllocator* litaC_debugAllocator = (litaC_debug_allocator__DebugAllocator*)litaC_mem__defaultAllocator;
    
    #line 256 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_debug_allocator__DebugAllocator_init(litaC_debugAllocator, litaC_libc_allocator__cAllocator);
    
}


#line 260 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

litaC_void litaC_mem__ModuleDestroy() {
    
    #line 261 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_debug_allocator__DebugAllocator* litaC_debugAllocator = (litaC_debug_allocator__DebugAllocator*)litaC_mem__defaultAllocator;
    
    #line 262 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_debug_allocator__DebugAllocator_report(litaC_debugAllocator);
    
    #line 263 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_debug_allocator__DebugAllocator_free(litaC_debugAllocator);
    
}


#line 279 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

litaC_void litaC_mem__testLineNumber() {
    
    #line 280 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
    litaC_void* litaC_mem = litaC_mem__Allocator_alloc(litaC_mem__defaultAllocator, 1024, __FILE__, __LINE__);
    
}


#line 18 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
litaC_void* litaC_libc_allocator__cMalloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 21 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    
    #line 22 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    return malloc(litaC_size);
    
    
}


#line 25 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
litaC_void* litaC_libc_allocator__cCalloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_num,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 29 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    
    #line 30 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    return calloc(litaC_num, litaC_size);
    
    
}


#line 33 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
litaC_void* litaC_libc_allocator__cRealloc(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr,litaC_usize litaC_oldSize,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 38 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    
    #line 39 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    return realloc(litaC_ptr, litaC_size);
    
    
}


#line 42 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
litaC_void litaC_libc_allocator__cFree(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr) {
    
    #line 43 "C:/Users/antho/git/litac-lang/stdlib/std/mem/libc_allocator.lita"
    return free(litaC_ptr);
    
    
}


#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void litaC_debug_allocator__DebugAllocator_init(litaC_debug_allocator__DebugAllocator* litaC_d,const litaC_mem__Allocator* litaC_alloc) {
    
    #line 36 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_d->alloc = (litaC_mem__Allocator) {
        
        #line 37 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
        .allocFn = &(litaC_debug_allocator__DebugMalloc),
        
        #line 38 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
        .callocFn = &(litaC_debug_allocator__DebugCalloc),
        
        #line 39 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
        .reallocFn = &(litaC_debug_allocator__DebugRealloc),
        
        #line 40 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
        .freeFn = &(litaC_debug_allocator__DebugFree)
    };
    
    #line 42 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_d->decorated = litaC_alloc;
    
    #line 43 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_array__Array_init_cb__ptr_Allocation_ce_(&((litaC_d->allocations)), 128, litaC_alloc);
    
    #line 44 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_d->totalBytesAllocated = 0;
    
    #line 45 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_d->totalAllocations = 0;
    
}


#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void litaC_debug_allocator__DebugAllocator_free(litaC_debug_allocator__DebugAllocator* litaC_d) {
    
    #line 49 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_array__Array_free_cb__ptr_Allocation_ce_(&((litaC_d->allocations)));
    
}


#line 53 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void litaC_debug_allocator__DebugAllocator_report(litaC_debug_allocator__DebugAllocator* litaC_d) {
    
    #line 54 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    printf("Leaked Allocations: {\n");
    
    #line 55 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    for(litaC_i32 litaC_i = 0;litaC_i < litaC_array__Array_size_cb__ptr_Allocation_ce_(&((litaC_d->allocations)));litaC_i += 1) {
        {
            
            #line 56 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            litaC_debug_allocator__Allocation* litaC_a = litaC_array__Array_get_cb__ptr_Allocation_ce_(&((litaC_d->allocations)), litaC_i);
            
            #line 57 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            if(litaC_a->line > 0) {
                {
                    
                    #line 58 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                    printf("   Leak at %p (%zu bytes) allocated in '%s' at line: %ju\n", litaC_a->addr, litaC_a->size, litaC_a->filename, litaC_a->line);
                    
                    
                }
                
            } else {
                
                #line 60 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                {
                    
                    #line 61 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                    printf("   Leak at %p (%zu bytes)\n", litaC_a->addr, litaC_a->size);
                    
                    
                }
            } 
            
            
            
        }
    }
    
    #line 64 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    printf("}\n");
    
}


#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void* litaC_debug_allocator__DebugAllocator_malloc(litaC_debug_allocator__DebugAllocator* litaC_d,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 69 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    
    #line 71 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_usize litaC_allocationSize = sizeof(litaC_debug_allocator__Allocation) + litaC_size;
    
    #line 72 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_void* litaC_mem = litaC_mem__Allocator_alloc(litaC_d->decorated, litaC_allocationSize, litaC_file, litaC_line);
    
    #line 73 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    if(!(litaC_mem)) {
        {
            
            #line 74 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            return NULL;
            
            
            
        }
        
    } 
    
    
    #line 77 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_debug_allocator__Allocation* litaC_allocation = (litaC_debug_allocator__Allocation*)litaC_mem;
    
    #line 78 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_allocation->addr = litaC_mem + sizeof(litaC_debug_allocator__Allocation);
    
    #line 79 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_allocation->size = litaC_size;
    
    #line 80 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_allocation->line = litaC_line;
    
    #line 81 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    strncpy(litaC_allocation->filename, litaC_file, litaC_debug_allocator__MAX_PATH);
    
    #line 83 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_array__Array_add_cb__ptr_Allocation_ce_(&((litaC_d->allocations)), litaC_allocation);
    
    #line 84 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_d->totalBytesAllocated += litaC_size;
    
    #line 85 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_d->totalAllocations += 1;
    
    #line 100 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    return litaC_allocation->addr;
    
    
}


#line 104 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void* litaC_debug_allocator__DebugMalloc(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 107 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    
    #line 108 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_debug_allocator__DebugAllocator* litaC_debug = (litaC_debug_allocator__DebugAllocator*)litaC_alloc;
    
    #line 109 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    return litaC_debug_allocator__DebugAllocator_malloc(litaC_debug, litaC_size, litaC_file, litaC_line);
    
    
}


#line 112 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void* litaC_debug_allocator__DebugCalloc(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_num,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 116 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    
    #line 117 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_debug_allocator__DebugAllocator* litaC_debug = (litaC_debug_allocator__DebugAllocator*)litaC_alloc;
    
    #line 118 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_void* litaC_result = litaC_debug_allocator__DebugAllocator_malloc(litaC_debug, litaC_size * litaC_num, litaC_file, litaC_line);
    
    #line 119 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    if(litaC_result) {
        {
            
            #line 120 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            memset(litaC_result, 0, litaC_size * litaC_num);
            
            
        }
        
    } 
    
    
    #line 123 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    return litaC_result;
    
    
}


#line 126 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void* litaC_debug_allocator__DebugRealloc(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr,litaC_usize litaC_oldSize,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line) {
    
    #line 131 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    
    #line 132 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    if(litaC_ptr == NULL) {
        {
            
            #line 133 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            return litaC_debug_allocator__DebugMalloc(litaC_alloc, litaC_size, litaC_file, litaC_line);
            
            
            
        }
        
    } 
    
    
    #line 136 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_debug_allocator__DebugAllocator* litaC_debug = (litaC_debug_allocator__DebugAllocator*)litaC_alloc;
    
    #line 138 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_void* litaC_result = litaC_debug_allocator__DebugAllocator_malloc(litaC_debug, litaC_size, litaC_file, litaC_line);
    
    #line 139 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    if(litaC_result) {
        {
            
            #line 140 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            litaC_debug_allocator__Allocation* litaC_allocation = (litaC_debug_allocator__Allocation*)(litaC_ptr - sizeof(litaC_debug_allocator__Allocation));
            
            #line 141 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            litaC_usize litaC_len = MIN(litaC_allocation->size, litaC_size);
            
            #line 143 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            memcpy(litaC_result, litaC_ptr, litaC_len);
            
            #line 145 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            litaC_debug_allocator__DebugFree(litaC_alloc, litaC_ptr);
            
            
        }
        
    } 
    
    
    #line 148 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    return litaC_result;
    
    
}


#line 216 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
litaC_void litaC_debug_allocator__DebugFree(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr) {
    
    #line 217 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    if(litaC_ptr == NULL) {
        {
            
            #line 218 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            return;
            
            
            
        }
        
    } 
    
    
    #line 221 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_debug_allocator__DebugAllocator* litaC_debug = (litaC_debug_allocator__DebugAllocator*)litaC_alloc;
    
    #line 222 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_debug_allocator__Allocation* litaC_allocation = (litaC_debug_allocator__Allocation*)(litaC_ptr - sizeof(litaC_debug_allocator__Allocation));
    
    #line 224 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_void* litaC_addr = litaC_ptr;
    
    #line 226 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    litaC_bool litaC_found = litaC_false;
    
    #line 227 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    for(litaC_i32 litaC_i = 0;litaC_i < litaC_array__Array_size_cb__ptr_Allocation_ce_(&((litaC_debug->allocations)));) {
        {
            
            #line 228 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            litaC_debug_allocator__Allocation* litaC_allocation = litaC_array__Array_get_cb__ptr_Allocation_ce_(&((litaC_debug->allocations)), litaC_i);
            
            #line 229 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            if(litaC_allocation->addr == litaC_addr) {
                {
                    
                    #line 230 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                    litaC_debug->totalBytesFreed += litaC_allocation->size;
                    
                    #line 231 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                    litaC_array__Array_removeAt_cb__ptr_Allocation_ce_(&((litaC_debug->allocations)), litaC_i);
                    
                    #line 232 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                    litaC_mem__Allocator_free(litaC_debug->decorated, litaC_allocation);
                    
                    #line 233 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                    litaC_found = litaC_true;
                    
                    #line 234 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                    break;
                    
                    
                }
                
            } else {
                
                #line 236 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                {
                    
                    #line 237 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
                    litaC_i += 1;
                    
                    
                }
            } 
            
            
            
        }
    }
    
    #line 241 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
    if(!(litaC_found)) {
        {
            
            #line 242 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            printf("Allocation not found: %p\n", litaC_ptr);
            
            #line 243 "C:/Users/antho/git/litac-lang/stdlib/std/mem/debug_allocator.lita"
            litaC_mem__Allocator_free(litaC_debug->decorated, litaC_ptr);
            
            
        }
        
    } 
    
    
}


#line 17 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_string_buffer__StringBuffer litaC_string_buffer__StringBufferInit(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc) {
    
    #line 18 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    
    #line 19 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_string_buffer__StringBuffer litaC_sb =  {
        
    };
    
    #line 20 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_string_buffer__StringBuffer_init(&((litaC_sb)), litaC_initialSize, litaC_alloc);
    
    #line 22 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_sb;
    
    
}


#line 25 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_init(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc) {
    
    #line 26 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    
    #line 27 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(!(litaC_alloc)) {
        {
            
            #line 28 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_alloc = litaC_mem__defaultAllocator;
            
            
        }
        
    } 
    
    
    #line 31 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->alloc = litaC_alloc;
    
    #line 32 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->length = 0;
    
    #line 33 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->capacity = litaC_initialSize;
    
    #line 35 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_length = litaC_initialSize;
    
    #line 36 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->buffer = (litaC_char*)litaC_mem__Allocator_calloc(litaC_alloc, litaC_length, sizeof(litaC_char), __FILE__, __LINE__);
    
}


#line 39 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_free(litaC_string_buffer__StringBuffer* litaC_b) {
    
    #line 40 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_b && litaC_b->buffer) {
        {
            
            #line 41 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_mem__Allocator_free(litaC_b->alloc, (litaC_void*)litaC_b->buffer);
            
            #line 42 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_b->buffer = NULL;
            
            #line 43 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_b->length = 0;
            
            #line 44 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_b->capacity = 0;
            
            
        }
        
    } 
    
    
}


#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_appendStr(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str) {
    
    #line 49 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_str == NULL) {
        {
            
            #line 50 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return;
            
            
            
        }
        
    } 
    
    
    #line 52 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_len = strlen(litaC_str);
    
    #line 53 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_string_buffer__StringBuffer_appendStrn(litaC_b, litaC_str, litaC_len);
    
}


#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_appendStrn(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len) {
    
    #line 58 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_str == NULL || litaC_len < 1) {
        {
            
            #line 59 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return;
            
            
            
        }
        
    } 
    
    
    #line 62 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_b->length + litaC_len > litaC_b->capacity) {
        {
            
            #line 63 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_string_buffer__BufferGrow(litaC_b, litaC_len);
            
            
        }
        
    } 
    
    
    #line 66 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    memcpy((litaC_void*)(&(litaC_b->buffer[litaC_b->length])), 
    #line 67 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    (const litaC_void*)litaC_str, 
    #line 68 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_len * sizeof(litaC_char));
    
    #line 69 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->length += litaC_len;
    
}


#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendFloat(litaC_string_buffer__StringBuffer* litaC_b,litaC_f64 litaC_f) {
    
    #line 74 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_buffer__StringBuffer_append(litaC_b, "%f", litaC_f);
    
    
}


#line 77 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendI32(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_i) {
    
    #line 78 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_buffer__StringBuffer_append(litaC_b, "%d", litaC_i);
    
    
}


#line 81 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendI64(litaC_string_buffer__StringBuffer* litaC_b,litaC_i64 litaC_i) {
    
    #line 82 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_buffer__StringBuffer_append(litaC_b, "%ld", litaC_i);
    
    
}


#line 85 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendU32(litaC_string_buffer__StringBuffer* litaC_b,litaC_u32 litaC_i) {
    
    #line 86 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_buffer__StringBuffer_append(litaC_b, "%u", litaC_i);
    
    
}


#line 89 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendU64(litaC_string_buffer__StringBuffer* litaC_b,litaC_u64 litaC_i) {
    
    #line 90 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_buffer__StringBuffer_append(litaC_b, "%lu", litaC_i);
    
    
}


#line 93 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendChar(litaC_string_buffer__StringBuffer* litaC_b,litaC_char litaC_c) {
    
    #line 95 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_b->length + 1 >= litaC_b->capacity) {
        {
            
            #line 96 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_string_buffer__BufferGrow(litaC_b, 1);
            
            
        }
        
    } 
    
    
    #line 99 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->buffer[litaC_b->length] = litaC_c;
    
    #line 100 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->length += 1;
    
    #line 101 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return 1;
    
    
}


#line 104 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_append(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_format,...) {
    
    #line 106 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_list litaC_args1;
    
    #line 107 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_start(litaC_args1, litaC_format);
    
    #line 109 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_len = _vscprintf(litaC_format, litaC_args1);
    
    #line 110 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_b->length + litaC_len >= litaC_b->capacity) {
        {
            
            #line 111 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_i32 litaC_growBy = (litaC_b->length + litaC_len + 1) - litaC_b->capacity;
            
            #line 112 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_string_buffer__BufferGrow(litaC_b, litaC_growBy);
            
            
        }
        
    } 
    
    
    #line 115 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_len = vsnprintf(&(litaC_b->buffer[litaC_b->length]), litaC_len + 1, litaC_format, litaC_args1);
    
    #line 116 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_end(litaC_args1);
    
    #line 118 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_len < 0) {
        {
            
            #line 119 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return litaC_len;
            
            
            
        }
        
    } 
    
    
    #line 122 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->length += litaC_len;
    
    #line 123 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_len;
    
    
}


#line 126 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendArgs(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_format,va_list litaC_args) {
    
    #line 127 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_list litaC_copyArgs;
    
    #line 128 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_copy(litaC_copyArgs, litaC_args);
    
    #line 130 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_len = _vscprintf(litaC_format, litaC_copyArgs);
    
    #line 131 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_b->length + litaC_len >= litaC_b->capacity) {
        {
            
            #line 132 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_string_buffer__BufferGrow(litaC_b, (litaC_len + 1) - litaC_b->capacity);
            
            
        }
        
    } 
    
    
    #line 135 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_len = vsnprintf(&(litaC_b->buffer[litaC_b->length]), litaC_len + 1, litaC_format, litaC_copyArgs);
    
    #line 136 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_end(litaC_copyArgs);
    
    #line 161 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_len < 0) {
        {
            
            #line 162 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return litaC_len;
            
            
            
        }
        
    } 
    
    
    #line 165 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->length += litaC_len;
    
    #line 166 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_len;
    
    
}


#line 185 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_delete(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_start,litaC_i32 litaC_end) {
    
    #line 186 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_b->length == 0) {
        {
            
            #line 187 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return;
            
            
            
        }
        
    } 
    
    
    #line 190 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_start < 0) {
        {
            
            #line 191 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_start = 0;
            
            
        }
        
    } 
    
    
    #line 193 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_end > litaC_b->length) {
        {
            
            #line 194 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_end = litaC_b->length;
            
            
        }
        
    } 
    
    
    #line 197 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_start > litaC_end) {
        {
            
            #line 198 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return;
            
            
            
        }
        
    } 
    
    
    #line 203 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    memmove((litaC_void*)(&(litaC_b->buffer[litaC_start])), 
    #line 204 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    (const litaC_void*)(&(litaC_b->buffer[litaC_end])), 
    #line 205 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    (litaC_b->length - litaC_end) * sizeof(litaC_char));
    
    #line 207 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->length -= (litaC_end - litaC_start);
    
}


#line 210 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_bool litaC_string_buffer__StringBuffer_contains(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len) {
    
    #line 211 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_buffer__StringBuffer_indexOf(litaC_b, litaC_str, litaC_len) > -(1);
    
    
}


#line 214 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_indexOf(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len) {
    
    #line 215 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_buffer__StringBuffer_indexOfAt(litaC_b, litaC_str, litaC_len, 0);
    
    
}


#line 218 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_indexOfAt(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex) {
    
    #line 219 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_string_view__StringView litaC_view = litaC_string_buffer__StringBuffer_asStringView(litaC_b);
    
    #line 220 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_view__StringView_indexOfAt(litaC_view, litaC_str, litaC_len, litaC_fromIndex);
    
    
}


#line 223 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_replace(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_start,litaC_i32 litaC_end,const litaC_char* litaC_str) {
    
    #line 224 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_string_buffer__StringBuffer_delete(litaC_b, litaC_start, litaC_end);
    
    #line 225 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_buffer__StringBuffer_insert(litaC_b, litaC_start, "%s", litaC_str);
    
    
}


#line 228 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_insert(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_index,const litaC_char* litaC_format,...) {
    
    #line 230 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_index < 0) {
        {
            
            #line 231 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_index = 0;
            
            
        }
        
    } 
    
    
    #line 235 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_index > litaC_b->length) {
        {
            
            #line 236 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_index = litaC_b->length;
            
            
        }
        
    } 
    
    
    #line 240 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_list litaC_args;
    
    #line 241 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_start(litaC_args, litaC_format);
    
    #line 249 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_len = _vscprintf(litaC_format, litaC_args);
    
    #line 252 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_len < 0) {
        {
            
            #line 253 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return litaC_len;
            
            
            
        }
        
    } 
    
    
    #line 256 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_required = litaC_b->length + litaC_len + 1;
    
    #line 257 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_required >= litaC_b->capacity) {
        {
            
            #line 258 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_string_buffer__BufferGrow(litaC_b, litaC_required - litaC_b->capacity);
            
            
        }
        
    } 
    
    
    #line 261 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_char litaC_startChar = litaC_b->buffer[litaC_index];
    
    #line 262 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_moveLength = litaC_b->length - litaC_index;
    
    #line 263 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    memmove((litaC_void*)(&(litaC_b->buffer[litaC_index + litaC_len])), 
    #line 264 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    (const litaC_void*)(&(litaC_b->buffer[litaC_index])), 
    #line 265 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_moveLength * sizeof(litaC_char));
    
    #line 266 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_n = vsnprintf(&(litaC_b->buffer[litaC_index]), litaC_len + 1, litaC_format, litaC_args);
    
    #line 267 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    va_end(litaC_args);
    
    #line 269 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_n < 0) {
        {
            
            #line 270 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return litaC_n;
            
            
            
        }
        
    } 
    
    
    #line 273 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->buffer[litaC_index + litaC_len] = litaC_startChar;
    
    #line 274 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->length += litaC_n;
    
    #line 276 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_len;
    
    
}


#line 279 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_trim(litaC_string_buffer__StringBuffer* litaC_b) {
    
    #line 280 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_start = 0;
    
    #line 281 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_end = 0;
    
    #line 284 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    for(litaC_i32 litaC_i = 0;litaC_i < litaC_b->length;litaC_i += 1) {
        {
            
            #line 285 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_char litaC_c = litaC_b->buffer[litaC_i];
            
            #line 286 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            if(litaC_ascii__char_isWhitespace(litaC_c)) {
                {
                    
                    #line 287 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
                    litaC_end += 1;
                    
                    
                }
                
            } else {
                
                #line 289 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
                {
                    
                    #line 290 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
                    break;
                    
                    
                }
            } 
            
            
            
        }
    }
    
    #line 294 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_end > litaC_start) {
        {
            
            #line 295 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_string_buffer__StringBuffer_delete(litaC_b, litaC_start, litaC_end);
            
            
        }
        
    } 
    
    
    #line 299 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_start = litaC_b->length - 1;
    
    #line 300 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_end = litaC_b->length - 1;
    
    #line 301 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    for(litaC_i32 litaC_i = litaC_b->length - 1;litaC_i >= 0;litaC_i -= 1) {
        {
            
            #line 302 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_char litaC_c = litaC_b->buffer[litaC_i];
            
            #line 303 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            if(litaC_ascii__char_isWhitespace(litaC_c)) {
                {
                    
                    #line 304 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
                    litaC_start -= 1;
                    
                    
                }
                
            } else {
                
                #line 306 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
                {
                    
                    #line 307 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
                    break;
                    
                    
                }
            } 
            
            
            
        }
    }
    
    #line 311 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_end > litaC_start) {
        {
            
            #line 312 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_string_buffer__StringBuffer_delete(litaC_b, litaC_start, litaC_end);
            
            
        }
        
    } 
    
    
}


#line 316 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_copyTo(litaC_string_buffer__StringBuffer* litaC_b,litaC_char* litaC_buf,litaC_i32 litaC_len,litaC_bool litaC_addZero) {
    
    #line 317 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_string_view__StringView litaC_view = litaC_string_buffer__StringBuffer_asStringView(litaC_b);
    
    #line 318 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_string_view__StringView_copyTo(litaC_view, litaC_buf, litaC_len, litaC_addZero);
    
    
}


#line 321 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_forEach(litaC_string_buffer__StringBuffer* litaC_b,litaC_bool (*litaC_fn)(litaC_char)) {
    
    #line 322 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    for(litaC_i32 litaC_i = 0;litaC_i < litaC_b->length;litaC_i += 1) {
        {
            
            #line 323 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            if(litaC_fn(litaC_b->buffer[litaC_i])) {
                {
                    
                    #line 324 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
                    break;
                    
                    
                }
                
            } 
            
            
            
        }
    }
    
}


#line 330 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
LITAC_INLINE 
litaC_bool litaC_string_buffer__StringBuffer_empty(litaC_string_buffer__StringBuffer* litaC_b) {
    
    #line 331 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_b->length == 0;
    
    
}


#line 335 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
LITAC_INLINE 
litaC_i32 litaC_string_buffer__StringBuffer_size(litaC_string_buffer__StringBuffer* litaC_b) {
    
    #line 336 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_b->length;
    
    
}


#line 340 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
LITAC_INLINE 
litaC_void litaC_string_buffer__StringBuffer_clear(litaC_string_buffer__StringBuffer* litaC_b) {
    
    #line 341 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->length = 0;
    
}


#line 344 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
const litaC_char* litaC_string_buffer__StringBuffer_cStrConst(litaC_string_buffer__StringBuffer* litaC_b) {
    
    #line 345 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return (const litaC_char*)litaC_string_buffer__StringBuffer_cStr(litaC_b);
    
    
}


#line 348 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_char* litaC_string_buffer__StringBuffer_cStr(litaC_string_buffer__StringBuffer* litaC_b) {
    
    #line 349 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_b->length + 1 > litaC_b->capacity) {
        {
            
            #line 350 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_string_buffer__BufferGrow(litaC_b, 1);
            
            
        }
        
    } 
    
    
    #line 353 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->buffer[litaC_b->length] = '\0';
    
    #line 354 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_b->buffer;
    
    
}


#line 358 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
LITAC_INLINE 
litaC_string_view__StringView litaC_string_buffer__StringBuffer_asStringView(litaC_string_buffer__StringBuffer* litaC_b) {
    
    #line 359 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return (litaC_string_view__StringView) {
        
        #line 360 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
        .buffer = litaC_b->buffer,
        
        #line 361 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
        .length = litaC_b->length
    };
    
    
}


#line 365 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_char litaC_string_buffer__StringBuffer_get(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_index) {
    
    #line 366 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_index < 0 || litaC_index >= litaC_b->length) {
        {
            
            #line 367 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return '\0';
            
            
            
        }
        
    } 
    
    
    #line 370 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    return litaC_b->buffer[litaC_index];
    
    
}


#line 373 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_reserve(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_length) {
    
    #line 374 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_available = litaC_b->capacity - litaC_b->length;
    
    #line 375 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_available >= litaC_length) {
        {
            
            #line 376 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            return;
            
            
            
        }
        
    } 
    
    
    #line 379 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_string_buffer__BufferGrow(litaC_b, litaC_length - litaC_available);
    
}


#line 382 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__BufferGrow(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_increment) {
    
    #line 383 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_doubleCurrent = litaC_b->capacity * 2;
    
    #line 384 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_minReq = litaC_b->capacity + litaC_increment;
    
    #line 385 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_i32 litaC_n = litaC_minReq;
    
    #line 387 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    if(litaC_doubleCurrent > litaC_minReq) {
        {
            
            #line 388 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
            litaC_n = litaC_doubleCurrent;
            
            
        }
        
    } 
    
    
    #line 390 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_usize litaC_newlength = (sizeof(litaC_char) * (litaC_u64)litaC_n);
    
    #line 391 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_usize litaC_oldlength = (sizeof(litaC_char) * (litaC_u64)litaC_b->capacity);
    
    #line 392 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_char* litaC_newBuffer = (litaC_char*)litaC_mem__Allocator_realloc(litaC_b->alloc, (litaC_void*)litaC_b->buffer, litaC_oldlength, litaC_newlength, __FILE__, __LINE__);
    
    #line 393 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    assert(litaC_newBuffer);
    
    #line 395 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->buffer = litaC_newBuffer;
    
    #line 396 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
    litaC_b->capacity = litaC_n;
    
}


#line 45 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_io__FileStatus litaC_io__File_open(litaC_io__File* litaC_file,const litaC_char* litaC_filename,litaC_io__FileOpenOp litaC_op) {
    
    #line 46 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    
    #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    {
        
        #line 49 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        const char* litaC_opStr = "rb";
        
        #line 50 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        switch(litaC_op) {
            
            #line 51 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            case litaC_io__FileOpenOp_READ_ONLY_BINARY: {
                {
                    
                    #line 52 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    litaC_opStr = "rb";
                    
                    #line 53 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    break;
                    
                    
                }
                
                
            }
            
            #line 55 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            case litaC_io__FileOpenOp_READ_ONLY: 
            #line 56 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            {
                litaC_opStr = "r";
                
                #line 57 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                break;
                
                
            }
            
            #line 59 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            case litaC_io__FileOpenOp_WRITE_BINARY: {
                {
                    
                    #line 60 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    litaC_opStr = "wb";
                    
                    #line 61 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    break;
                    
                    
                }
                
                
            }
            
            #line 63 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            case litaC_io__FileOpenOp_WRITE: {
                {
                    
                    #line 64 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    litaC_opStr = "w";
                    
                    #line 65 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    break;
                    
                    
                }
                
                
            }
            
            #line 67 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            case litaC_io__FileOpenOp_WRITE_APPEND: {
                {
                    
                    #line 68 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    litaC_opStr = "a";
                    
                    #line 69 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    break;
                    
                    
                }
                
                
            }
            
            #line 71 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            case litaC_io__FileOpenOp_WRITE_APPEND_BINARY: {
                {
                    
                    #line 72 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    litaC_opStr = "ab";
                    
                    #line 73 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    break;
                    
                    
                }
                
                
            }
        }
        
        #line 77 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        litaC_file->file = fopen(litaC_filename, litaC_opStr);
        
        #line 78 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(litaC_file->file == NULL) {
            {
                
                #line 79 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                return litaC_io__FileStatus_FileNotFoundError;
                
                
                
            }
            
        } 
        
        
        #line 82 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        return litaC_io__FileStatus_Ok;
        
        
        
    }
    
}


#line 86 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_void litaC_io__File_close(litaC_io__File* litaC_file) {
    
    #line 87 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    
    #line 90 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    {
        
        #line 91 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(litaC_file && litaC_file->file) {
            {
                
                #line 92 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                fclose(litaC_file->file);
                
                
            }
            
        } 
        
        
        
    }
    
}


#line 97 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_i64 litaC_io__FileLength(const litaC_char* litaC_fileName) {
    
    #line 98 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    FILE* litaC_fp = fopen(litaC_fileName, "r");
    
    #line 99 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    if(litaC_fp == NULL) {
        {
            
            #line 100 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            return -(1);
            
            
            
        }
        
    } 
    
    
    #line 102 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    
    
    #line 104 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    if(fseek(litaC_fp, 0, SEEK_END)) {
        {
            
            #line 105 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            {
                litaC_i64 ___result = -(1);
                
                #line 102 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                fclose(litaC_fp);
                return ___result;
                
            }
            
            
            
        }
        
    } 
    
    
    #line 108 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    litaC_i64 litaC_len = ftell(litaC_fp);
    
    #line 109 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    {
        litaC_i64 ___result = litaC_len;
        
        #line 102 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        fclose(litaC_fp);
        return ___result;
        
    }
    
    fclose(litaC_fp);
    
}


#line 112 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_io__FileStatus litaC_io__ReadFile(const litaC_char* litaC_fileName,litaC_char** litaC_data,litaC_usize* litaC_length,const litaC_mem__Allocator* litaC_alloc) {
    
    #line 115 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    
    #line 116 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    
    #line 118 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    {
        
        #line 119 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        FILE* litaC_fp = fopen(litaC_fileName, "r");
        
        #line 120 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(litaC_fp == NULL) {
            {
                
                #line 121 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                *(litaC_length) = -(1);
                
                #line 122 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                return litaC_io__FileStatus_FileNotFoundError;
                
                
                
            }
            
        } 
        
        
        #line 124 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        
        
        #line 126 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(fseek(litaC_fp, 0, SEEK_END)) {
            {
                
                #line 127 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                *(litaC_length) = -(1);
                
                #line 128 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                {
                    litaC_io__FileStatus ___result = litaC_io__FileStatus_IOError;
                    
                    #line 124 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    fclose(litaC_fp);
                    return ___result;
                    
                }
                
                
                
            }
            
        } 
        
        
        #line 131 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        litaC_i64 litaC_len = ftell(litaC_fp);
        
        #line 132 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(litaC_len < 0L) {
            {
                
                #line 133 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                *(litaC_length) = -(1);
                
                #line 134 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                {
                    litaC_io__FileStatus ___result = litaC_io__FileStatus_IOError;
                    
                    #line 124 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    fclose(litaC_fp);
                    return ___result;
                    
                }
                
                
                
            }
            
        } 
        
        
        #line 137 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(fseek(litaC_fp, 0, SEEK_SET)) {
            {
                
                #line 138 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                *(litaC_length) = -(1);
                
                #line 139 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                {
                    litaC_io__FileStatus ___result = litaC_io__FileStatus_IOError;
                    
                    #line 124 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    fclose(litaC_fp);
                    return ___result;
                    
                }
                
                
                
            }
            
        } 
        
        
        #line 142 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        litaC_char* litaC_buf = (litaC_char*)litaC_mem__Allocator_alloc(litaC_alloc, sizeof(litaC_char) * ((litaC_u64)litaC_len + 1UL), __FILE__, __LINE__);
        
        #line 143 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        (*(litaC_data)) = litaC_buf;
        
        #line 146 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        litaC_i64 litaC_newLen = fread(litaC_buf, sizeof(litaC_char), litaC_len, litaC_fp);
        
        #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(ferror(litaC_fp)) {
            {
                
                #line 148 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                *(litaC_length) = -(1);
                
                #line 149 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                {
                    litaC_io__FileStatus ___result = litaC_io__FileStatus_IOError;
                    
                    #line 124 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                    fclose(litaC_fp);
                    return ___result;
                    
                }
                
                
                
            }
            
        } 
        
        
        #line 152 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        litaC_buf[litaC_newLen] = '\0';
        
        #line 153 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        *(litaC_length) = litaC_newLen;
        
        #line 155 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        {
            litaC_io__FileStatus ___result = litaC_io__FileStatus_Ok;
            
            #line 124 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            fclose(litaC_fp);
            return ___result;
            
        }
        
        fclose(litaC_fp);
        
        
    }
    
}


#line 159 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_io__FileStatus litaC_io__WriteFile(const litaC_char* litaC_fileName,const litaC_char* litaC_buffer,litaC_usize litaC_len) {
    
    #line 160 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    
    #line 162 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    {
        
        #line 163 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        FILE* litaC_fp = fopen(litaC_fileName, "w");
        
        #line 164 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(litaC_fp == NULL) {
            {
                
                #line 165 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                return litaC_io__FileStatus_FileNotFoundError;
                
                
                
            }
            
        } 
        
        
        #line 167 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        
        
        #line 169 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        litaC_io__File litaC_file =  {
            .file = litaC_fp
        };
        
        #line 170 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        {
            litaC_io__FileStatus ___result = litaC_io__File_writeBytes(&((litaC_file)), litaC_buffer, litaC_len);
            
            #line 167 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
            fclose(litaC_fp);
            return ___result;
            
        }
        
        fclose(litaC_fp);
        
        
    }
    
}


#line 174 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
litaC_io__FileStatus litaC_io__File_writeBytes(litaC_io__File* litaC_file,const litaC_char* litaC_buffer,litaC_usize litaC_len) {
    
    #line 175 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    
    #line 177 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    {
        
        #line 178 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        litaC_u64 litaC_bytesWritten = fwrite((const litaC_void*)litaC_buffer, sizeof(litaC_char), litaC_len, litaC_file->file);
        
        #line 179 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        if(litaC_bytesWritten != litaC_len) {
            {
                
                #line 180 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
                return litaC_io__FileStatus_IOError;
                
                
                
            }
            
        } 
        
        
        #line 183 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        return litaC_io__FileStatus_Ok;
        
        
        
    }
    
}


#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_string_view__StringView litaC_string_view__StringViewInit(const litaC_char* litaC_str,litaC_i32 litaC_len) {
    
    #line 11 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_str == NULL) {
        {
            
            #line 12 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return (litaC_string_view__StringView) {
                
                #line 13 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                .buffer = NULL,
                
                #line 14 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                .length = 0
            };
            
            
            
        }
        
    } 
    
    
    #line 18 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return (litaC_string_view__StringView) {
        
        #line 19 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
        .buffer = litaC_str,
        
        #line 20 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
        .length = ((litaC_len < 0)) ? strlen(litaC_str) : litaC_len
    };
    
    
}


#line 24 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_u32 litaC_string_view__StringView_hash(litaC_string_view__StringView litaC_b) {
    
    #line 25 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_u32 litaC_hash = 5381U;
    
    #line 26 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    for(litaC_i32 litaC_i = 0;litaC_i < litaC_b.length;litaC_i += 1) {
        {
            
            #line 27 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_hash = ((litaC_hash << 5U) + litaC_hash) + ((litaC_u32)(litaC_b.buffer[litaC_i]));
            
            
        }
    }
    
    #line 29 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_hash;
    
    
}


#line 32 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_string_view__StringView litaC_string_view__StringView_substring(litaC_string_view__StringView litaC_b,litaC_i32 litaC_start,litaC_i32 litaC_end) {
    
    #line 33 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_endIndex = (litaC_end < 0) ? litaC_b.length : litaC_end;
    
    #line 35 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_endIndex <= litaC_start || litaC_start < 0 || litaC_start >= litaC_b.length) {
        {
            
            #line 36 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return (litaC_string_view__StringView) {
                
                #line 37 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                .buffer = NULL,
                
                #line 38 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                .length = 0
            };
            
            
            
        }
        
    } 
    
    
    #line 42 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return (litaC_string_view__StringView) {
        
        #line 43 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
        .buffer = &(litaC_b.buffer[litaC_start]),
        
        #line 44 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
        .length = litaC_endIndex - litaC_start
    };
    
    
}


#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_startsWith(litaC_string_view__StringView litaC_b,const litaC_char* litaC_prefix,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex) {
    
    #line 49 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(!(litaC_prefix)) {
        return litaC_false;
        
        
    } 
    
    
    #line 51 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    const litaC_char* litaC_ta = litaC_b.buffer;
    
    #line 52 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_to = litaC_fromIndex;
    
    #line 53 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    const litaC_char* litaC_pa = litaC_prefix;
    
    #line 54 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_po = 0;
    
    #line 55 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_pc = ((litaC_len < 0)) ? strlen(litaC_prefix) : litaC_len;
    
    #line 57 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if((litaC_fromIndex < 0) || (litaC_fromIndex > litaC_b.length - litaC_pc)) {
        {
            
            #line 58 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return litaC_false;
            
            
            
        }
        
    } 
    
    
    #line 61 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    while((litaC_pc -= 1) >= 0) {
        {
            
            #line 62 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            if(litaC_ta[litaC_to] != litaC_pa[litaC_po]) {
                {
                    
                    #line 63 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    return litaC_false;
                    
                    
                    
                }
                
            } 
            
            
            #line 65 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_to += 1;
            
            #line 66 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_po += 1;
            
            
        }
    }
    
    #line 68 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_true;
    
    
}


#line 71 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_endsWith(litaC_string_view__StringView litaC_b,const litaC_char* litaC_suffix,litaC_i32 litaC_len) {
    
    #line 72 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(!(litaC_suffix)) {
        return litaC_false;
        
        
    } 
    
    
    #line 74 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_len = ((litaC_len < 0)) ? strlen(litaC_suffix) : litaC_len;
    
    #line 75 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_string_view__StringView_startsWith(litaC_b, litaC_suffix, litaC_len, litaC_b.length - litaC_len);
    
    
}


#line 78 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_equals(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len) {
    
    #line 79 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(!(litaC_str)) {
        {
            
            #line 80 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return litaC_b.buffer == NULL;
            
            
            
        }
        
    } 
    
    
    #line 83 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_len = ((litaC_len < 0)) ? strlen(litaC_str) : litaC_len;
    
    #line 84 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_b.length != litaC_len) {
        {
            
            #line 85 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return litaC_false;
            
            
            
        }
        
    } 
    
    
    #line 88 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return strncmp(litaC_b.buffer, litaC_str, litaC_len) == 0;
    
    
}


#line 91 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_equalsStringView(litaC_string_view__StringView litaC_b,litaC_string_view__StringView litaC_other) {
    
    #line 92 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_string_view__StringView_equals(litaC_b, litaC_other.buffer, litaC_other.length);
    
    
}


#line 95 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_contains(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len) {
    
    #line 96 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_string_view__StringView_indexOf(litaC_b, litaC_str, litaC_len) > -(1);
    
    
}


#line 99 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_indexOf(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len) {
    
    #line 100 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_string_view__StringView_indexOfAt(litaC_b, litaC_str, litaC_len, 0);
    
    
}


#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_indexOfAt(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex) {
    
    #line 104 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(!(litaC_str)) {
        return -(1);
        
        
    } 
    
    
    #line 106 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    const litaC_char* litaC_target = litaC_str;
    
    #line 107 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    const litaC_char* litaC_source = litaC_b.buffer;
    
    #line 109 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_targetOffset = 0;
    
    #line 110 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_sourceOffset = 0;
    
    #line 112 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_char litaC_first = litaC_target[0];
    
    #line 114 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_targetCount = litaC_len;
    
    #line 115 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_len < 0) {
        {
            
            #line 116 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_targetCount = strlen(litaC_str);
            
            
        }
        
    } 
    
    
    #line 119 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_max = litaC_sourceOffset + (litaC_b.length - litaC_targetCount);
    
    #line 121 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    for(litaC_i32 litaC_i = litaC_sourceOffset + litaC_fromIndex;litaC_i <= litaC_max;litaC_i += 1) {
        {
            
            #line 123 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            if(litaC_source[litaC_i] != litaC_first) {
                {
                    
                    #line 124 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    while(litaC_i <= litaC_max && litaC_source[litaC_i] != litaC_first) {
                        {
                            
                            #line 125 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                            litaC_i += 1;
                            
                            
                        }
                    }
                    
                    
                }
                
            } 
            
            
            #line 130 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            if(litaC_i <= litaC_max) {
                {
                    
                    #line 131 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    litaC_i32 litaC_j = litaC_i + 1;
                    
                    #line 132 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    litaC_i32 litaC_end = litaC_j + litaC_targetCount - 1;
                    
                    #line 133 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    for(litaC_i32 litaC_k = litaC_targetOffset + 1;litaC_j < litaC_end && litaC_source[litaC_j] == litaC_target[litaC_k];) {
                        {
                            
                            #line 134 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                            litaC_j += 1;
                            
                            #line 135 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                            litaC_k += 1;
                            
                            
                        }
                    }
                    
                    #line 138 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    if(litaC_j == litaC_end) {
                        {
                            
                            #line 140 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                            return litaC_i - litaC_sourceOffset;
                            
                            
                            
                        }
                        
                    } 
                    
                    
                    
                }
                
            } 
            
            
            
        }
    }
    
    #line 144 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return -(1);
    
    
}


#line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_lastIndexOfAt(litaC_string_view__StringView litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex) {
    
    #line 148 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_sourceCount = litaC_b.length;
    
    #line 149 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_targetCount = (litaC_len < 0) ? strlen(litaC_str) : litaC_len;
    
    #line 151 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_targetOffset = 0;
    
    #line 152 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_sourceOffset = 0;
    
    #line 154 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    const litaC_char* litaC_source = litaC_b.buffer;
    
    #line 155 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    const litaC_char* litaC_target = litaC_str;
    
    #line 157 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_rightIndex = litaC_sourceCount - litaC_targetCount;
    
    #line 158 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_fromIndex < 0) {
        {
            
            #line 159 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_fromIndex = litaC_sourceCount;
            
            
        }
        
    } 
    
    
    #line 161 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_fromIndex > litaC_rightIndex) {
        {
            
            #line 162 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_fromIndex = litaC_rightIndex;
            
            
        }
        
    } 
    
    
    #line 165 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_targetCount == 0) {
        {
            
            #line 166 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return litaC_fromIndex;
            
            
            
        }
        
    } 
    
    
    #line 169 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_strLastIndex = litaC_targetOffset + litaC_targetCount - 1;
    
    #line 170 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_char litaC_strLastChar = litaC_target[litaC_strLastIndex];
    
    #line 171 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_min = litaC_sourceOffset + litaC_targetCount - 1;
    
    #line 172 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_i = litaC_min + litaC_fromIndex;
    
    #line 174 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    startSearchForLastChar:;
    
    
    #line 175 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    while(litaC_true) {
        {
            
            #line 176 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            while(litaC_i >= litaC_min && litaC_source[litaC_i] != litaC_strLastChar) {
                {
                    
                    #line 177 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    litaC_i -= 1;
                    
                    
                }
            }
            
            #line 179 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            if(litaC_i < litaC_min) {
                {
                    
                    #line 180 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    return -(1);
                    
                    
                    
                }
                
            } 
            
            
            #line 182 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_i32 litaC_j = litaC_i - 1;
            
            #line 183 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_i32 litaC_start = litaC_j - (litaC_targetCount - 1);
            
            #line 184 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_i32 litaC_k = litaC_strLastIndex - 1;
            
            #line 186 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            while(litaC_j > litaC_start) {
                {
                    
                    #line 187 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    if(litaC_source[litaC_j] != litaC_target[litaC_k]) {
                        {
                            
                            #line 188 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                            litaC_i -= 1;
                            
                            #line 189 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                            goto startSearchForLastChar;
                            
                            
                            
                        }
                        
                    } 
                    
                    
                    #line 191 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    litaC_j -= 1;
                    
                    #line 192 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    litaC_k -= 1;
                    
                    
                }
            }
            
            #line 194 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return litaC_start - litaC_sourceOffset + 1;
            
            
            
        }
    }
    
}


#line 199 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_copyTo(litaC_string_view__StringView litaC_b,litaC_char* litaC_buf,litaC_i32 litaC_len,litaC_bool litaC_addZero) {
    
    #line 200 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(!(litaC_buf) || litaC_len == 0) {
        return 0;
        
        
    } 
    
    
    #line 202 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_i32 litaC_bytesCopied = litaC_len;
    
    #line 203 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_b.length < litaC_len) {
        {
            
            #line 204 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            litaC_bytesCopied = litaC_b.length;
            
            
        }
        
    } 
    
    
    #line 207 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    memcpy((litaC_void*)litaC_buf, 
    #line 208 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    (const litaC_void*)(&(litaC_b.buffer[0])), 
    #line 209 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_bytesCopied * sizeof(litaC_char));
    
    #line 211 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_addZero) {
        litaC_buf[litaC_bytesCopied] = '\0';
        
    } 
    
    
    #line 213 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return (litaC_bytesCopied);
    
    
}


#line 216 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_string_view__StringView litaC_string_view__StringView_copy(litaC_string_view__StringView litaC_s,const litaC_mem__Allocator* litaC_allocator) {
    
    #line 217 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_s.length < 1) {
        {
            
            #line 218 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return (litaC_string_view__StringView) {
                
                #line 219 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                .buffer = NULL,
                
                #line 220 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                .length = 0
            };
            
            
            
        }
        
    } 
    
    
    #line 224 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_char* litaC_copiedStr = (litaC_char*)litaC_mem__Allocator_alloc(litaC_allocator, (litaC_s.length + 1) * sizeof(litaC_char), __FILE__, __LINE__);
    
    #line 225 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    memcpy(litaC_copiedStr, litaC_s.buffer, litaC_s.length);
    
    #line 227 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_copiedStr[litaC_s.length] = '\0';
    
    #line 229 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return (litaC_string_view__StringView) {
        
        #line 230 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
        .buffer = litaC_copiedStr,
        
        #line 231 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
        .length = litaC_s.length
    };
    
    
}


#line 235 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__StringView_forEach(litaC_string_view__StringView litaC_b,litaC_bool (*litaC_fn)(litaC_char)) {
    
    #line 236 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    for(litaC_i32 litaC_i = 0;litaC_i < litaC_b.length;litaC_i += 1) {
        {
            
            #line 237 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            if(litaC_fn(litaC_b.buffer[litaC_i])) {
                {
                    
                    #line 238 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
                    break;
                    
                    
                }
                
            } 
            
            
            
        }
    }
    
}


#line 243 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_bool litaC_string_view__StringView_empty(litaC_string_view__StringView litaC_b) {
    
    #line 244 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_b.length == 0;
    
    
}


#line 247 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 litaC_string_view__StringView_size(litaC_string_view__StringView litaC_b) {
    
    #line 248 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_b.length;
    
    
}


#line 251 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_void litaC_string_view__StringView_clear(litaC_string_view__StringView litaC_b) {
    
    #line 252 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_b.length = 0;
    
}


#line 255 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_char litaC_string_view__StringView_get(litaC_string_view__StringView litaC_b,litaC_i32 litaC_index) {
    
    #line 256 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    if(litaC_index < 0 || litaC_index >= litaC_b.length) {
        {
            
            #line 257 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
            return '\0';
            
            
            
        }
        
    } 
    
    
    #line 260 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    return litaC_b.buffer[litaC_index];
    
    
}


#line 264 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"

litaC_void litaC_string_view__testEquals() {
    
    #line 265 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_a = litaC_string_view__StringViewInit("Hello World", -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 266 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_b = litaC_string_view__StringViewInit("Bye World", -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 267 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_c = litaC_a;
    
    #line 268 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_d = litaC_string_view__StringViewInit("HelloWorld", -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 269 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_e = litaC_string_view__StringViewInit(NULL, -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 271 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_equals(litaC_a, litaC_c.buffer, litaC_c.length) == litaC_true);
    
    #line 272 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_equals(litaC_a, "Hell", -(
    #line 78 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 272 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_false);
    
    #line 273 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_equals(litaC_a, "Hello World", -(
    #line 78 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 273 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_true);
    
    #line 274 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_equals(litaC_a, litaC_b.buffer, litaC_b.length) == litaC_false);
    
    #line 275 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_equals(litaC_a, litaC_d.buffer, litaC_d.length) == litaC_false);
    
    #line 276 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_equals(litaC_e, litaC_d.buffer, litaC_d.length) == litaC_false);
    
    #line 277 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_equals(litaC_a, litaC_e.buffer, litaC_e.length) == litaC_false);
    
}


#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"

litaC_void litaC_string_view__testContains() {
    
    #line 283 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_a = litaC_string_view__StringViewInit("Hello World", -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 284 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_e = litaC_string_view__StringViewInit(NULL, -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 286 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_contains(litaC_a, "World", -(
    #line 95 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 286 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_true);
    
    #line 287 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_contains(litaC_a, "d", -(
    #line 95 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 287 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_true);
    
    #line 288 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_contains(litaC_a, "H", -(
    #line 95 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 288 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_true);
    
    #line 289 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_contains(litaC_a, "Which", 1) == litaC_true);
    
    #line 290 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_contains(litaC_e, "World", -(
    #line 95 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 290 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_false);
    
    #line 291 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_contains(litaC_a, litaC_e.buffer, litaC_e.length) == litaC_false);
    
}


#line 295 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"

litaC_void litaC_string_view__testStartsWith() {
    
    #line 296 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_a = litaC_string_view__StringViewInit("Hello World", -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 297 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_e = litaC_string_view__StringViewInit(NULL, -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 299 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, "World", -(
    #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 299 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == litaC_false);
    
    #line 300 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, "d", -(
    #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 300 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == litaC_false);
    
    #line 301 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, "H", -(
    #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 301 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == litaC_true);
    
    #line 302 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, "Hell", -(
    #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 302 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == litaC_true);
    
    #line 303 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, "Hello World", -(
    #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 303 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == litaC_true);
    
    #line 304 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, "Hello World!", -(
    #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 304 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == litaC_false);
    
    #line 305 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, "Which", 1, 0) == litaC_false);
    
    #line 306 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, "Hhich", 1, 0) == litaC_true);
    
    #line 307 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_e, "World", -(
    #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 307 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == litaC_false);
    
    #line 308 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_startsWith(litaC_a, litaC_e.buffer, litaC_e.length, 0) == litaC_false);
    
}


#line 312 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"

litaC_void litaC_string_view__testEndsWith() {
    
    #line 313 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_a = litaC_string_view__StringViewInit("Hello World", -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 314 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_e = litaC_string_view__StringViewInit(NULL, -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 316 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_endsWith(litaC_a, "World", -(
    #line 71 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 316 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_true);
    
    #line 317 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_endsWith(litaC_a, "d", -(
    #line 71 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 317 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_true);
    
    #line 318 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_endsWith(litaC_a, "H", -(
    #line 71 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 318 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_false);
    
    #line 319 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_endsWith(litaC_a, "Hell", -(
    #line 71 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 319 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_false);
    
    #line 320 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_endsWith(litaC_a, "Hello World", -(
    #line 71 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 320 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_true);
    
    #line 321 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_endsWith(litaC_a, "Hello World!", -(
    #line 71 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 321 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_false);
    
}


#line 325 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"

litaC_void litaC_string_view__testIndexOf() {
    
    #line 326 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_a = litaC_string_view__StringViewInit("Hello World", -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 327 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_e = litaC_string_view__StringViewInit(NULL, -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 329 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_indexOfAt(litaC_a, "World", 2, 0) == 6);
    
    #line 330 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_indexOfAt(litaC_a, "World", 7, 0) == -(1));
    
    #line 331 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_indexOfAt(litaC_a, "d", -(
    #line 103 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 331 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == 10);
    
    #line 332 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_indexOfAt(litaC_a, "H", -(
    #line 103 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 332 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == 0);
    
    #line 333 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_indexOfAt(litaC_a, "H", 2, 0) == -(1));
    
    #line 335 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_indexOfAt(litaC_e, "World", -(
    #line 103 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 335 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    0) == -(1));
    
    #line 336 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_indexOfAt(litaC_a, litaC_e.buffer, litaC_e.length, 0) == -(1));
    
}


#line 341 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"

litaC_void litaC_string_view__testLastIndexOf() {
    
    #line 342 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_a = litaC_string_view__StringViewInit("Hello World", -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 343 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    litaC_string_view__StringView litaC_e = litaC_string_view__StringViewInit(NULL, -(
    #line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1));
    
    #line 345 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_lastIndexOfAt(litaC_a, "World", -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 345 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 345 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    6);
    
    #line 346 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_lastIndexOfAt(litaC_a, "World", -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 346 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    5) == -(1));
    
    #line 347 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_lastIndexOfAt(litaC_a, "World", -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 347 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    7) == 6);
    
    #line 348 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_lastIndexOfAt(litaC_a, "l", -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 348 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 348 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    9);
    
    #line 349 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_lastIndexOfAt(litaC_a, "o", -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 349 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 349 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    7);
    
    #line 350 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_lastIndexOfAt(litaC_a, "z", -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 350 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 350 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    -(1));
    
    #line 352 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    assert(litaC_string_view__StringView_lastIndexOfAt(litaC_e, "World", -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1), 
    #line 352 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    -(
    #line 147 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    1)) == 
    #line 352 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
    -(1));
    
}


#line 13 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__char_isWhitespace(litaC_char litaC_this) {
    
    #line 14 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    return litaC_ascii__WHITESPACE[litaC_this & 0xFF];
    
    
}


#line 17 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__char_isNumeric(litaC_char litaC_this) {
    
    #line 18 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    return litaC_this > 47 && litaC_this < 58;
    
    
}


#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__char_isAlphabetic(litaC_char litaC_this) {
    
    #line 22 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    return (litaC_this > 64 && litaC_this < 91) || 
    #line 23 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    (litaC_this > 96 && litaC_this < 123);
    
    
}


#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
litaC_bool litaC_ascii__char_isAlphanumeric(litaC_char litaC_this) {
    
    #line 27 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    return litaC_ascii__char_isNumeric(litaC_this) || litaC_ascii__char_isAlphabetic(litaC_this);
    
    
}


#line 31 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"

litaC_void litaC_ascii__testWhitespace() {
    
    #line 32 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    assert(litaC_ascii__char_isWhitespace(' ') == litaC_true);
    
    #line 33 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    assert(litaC_ascii__char_isWhitespace('\t') == litaC_true);
    
    #line 34 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    assert(litaC_ascii__char_isWhitespace('\n') == litaC_true);
    
    #line 35 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    assert(litaC_ascii__char_isWhitespace('\r') == litaC_true);
    
    #line 38 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    litaC_char litaC_c = (litaC_char)(-(1));
    
    #line 39 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    assert(litaC_ascii__char_isWhitespace(litaC_c) == litaC_false);
    
    #line 41 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    litaC_char litaC_m = (litaC_char)(300);
    
    #line 42 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    assert(litaC_ascii__char_isWhitespace(litaC_m) == litaC_false);
    
    #line 44 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    assert(litaC_ascii__char_isWhitespace('x') == litaC_false);
    
    #line 45 "C:/Users/antho/git/litac-lang/stdlib/std/ascii/ascii.lita"
    assert(litaC_ascii__char_isWhitespace(' ') == litaC_true);
    
}


#line 1 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
const litaC_char* litaC_io__FileStatusAsStr(litaC_io__FileStatus litaC_enumType) {
    
    #line 2 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
    switch(litaC_enumType) {
        
        #line 3 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        case litaC_io__FileStatus_Ok: {
            return "Ok";
            
            
            
        }
        
        #line 4 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        case litaC_io__FileStatus_FileNotFoundError: {
            return "FileNotFoundError";
            
            
            
        }
        
        #line 5 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        case litaC_io__FileStatus_IOError: {
            return "IOError";
            
            
            
        }
        default: 
        #line 6 "C:/Users/antho/git/litac-lang/stdlib/std/io/io.lita"
        {
            return NULL;
            
            
            
        }
    }
    
}


#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc) {
    
    #line 23 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    
    #line 24 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_a->alloc = litaC_alloc;
    
    #line 25 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_a->length = 0;
    
    #line 26 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_a->capacity = litaC_initialSize;
    
    #line 28 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_usize litaC_length = (sizeof(litaC_debug_allocator__Allocation*) * (litaC_u64)litaC_initialSize);
    
    #line 29 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    if(litaC_initialSize > 0) {
        {
            
            #line 30 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            litaC_a->elements = (litaC_debug_allocator__Allocation**)litaC_mem__Allocator_alloc(litaC_alloc, litaC_length, __FILE__, __LINE__);
            
            
        }
        
    } else {
        
        #line 32 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
        {
            
            #line 33 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            litaC_a->elements = NULL;
            
            
        }
    } 
    
    
}


#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_free_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a) {
    
    #line 38 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    if(litaC_a && litaC_a->elements) {
        {
            
            #line 39 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            litaC_mem__Allocator_free(litaC_a->alloc, (litaC_void*)litaC_a->elements);
            
            #line 40 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            litaC_a->elements = NULL;
            
            #line 41 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            litaC_a->length = 0;
            
            #line 42 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            litaC_a->capacity = 0;
            
            
        }
        
    } 
    
    
}


#line 193 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
LITAC_INLINE 
litaC_i32 litaC_array__Array_size_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a) {
    
    #line 194 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    return litaC_a->length;
    
    
}


#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_debug_allocator__Allocation* litaC_array__Array_get_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_index) {
    
    #line 65 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    assert(litaC_index >= 0 && litaC_index < litaC_a->length);
    
    #line 67 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    return litaC_a->elements[litaC_index];
    
    
}


#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_debug_allocator__Allocation* litaC_element) {
    
    #line 47 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    if(litaC_a->length + 1 > litaC_a->capacity) {
        {
            
            #line 48 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            litaC_array__ArrayGrow_cb__ptr_Allocation_ce_(litaC_a, 1);
            
            
        }
        
    } 
    
    
    #line 51 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    
    #line 53 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    {
        
        #line 54 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
        litaC_a->elements[litaC_a->length] = litaC_element;
        
        
    }
    
    #line 57 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_a->length += 1;
    
}


#line 216 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_increment) {
    
    #line 217 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_i32 litaC_doubleCurrent = litaC_a->capacity * 2;
    
    #line 218 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_i32 litaC_minReq = litaC_a->length + litaC_increment;
    
    #line 219 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_i32 litaC_n = litaC_minReq;
    
    #line 221 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    if(litaC_doubleCurrent > litaC_minReq) {
        {
            
            #line 222 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            litaC_n = litaC_doubleCurrent;
            
            
        }
        
    } 
    
    
    #line 225 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_usize litaC_newlength = (sizeof(litaC_debug_allocator__Allocation*) * (litaC_usize)litaC_n);
    
    #line 226 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_usize litaC_oldlength = (sizeof(litaC_debug_allocator__Allocation*) * (litaC_usize)litaC_a->capacity);
    
    #line 227 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_a->elements = (litaC_debug_allocator__Allocation**)litaC_mem__Allocator_realloc(litaC_a->alloc, (litaC_void*)litaC_a->elements, litaC_oldlength, litaC_newlength, __FILE__, __LINE__);
    
    #line 228 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_a->capacity = litaC_n;
    
}


#line 128 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_debug_allocator__Allocation* litaC_array__Array_removeAt_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_index) {
    
    #line 129 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    assert(litaC_index >= 0 && litaC_index < litaC_a->length);
    
    #line 131 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_debug_allocator__Allocation* litaC_r = litaC_a->elements[litaC_index];
    
    #line 132 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    if(litaC_index < litaC_a->length - 1) {
        {
            
            #line 133 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            memmove((litaC_void*)(&(litaC_a->elements[litaC_index])), 
            #line 134 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            (const litaC_void*)(&(litaC_a->elements[litaC_index + 1])), 
            #line 135 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
            ((litaC_a->length - 1) - litaC_index) * sizeof(litaC_debug_allocator__Allocation*));
            
            
        }
        
    } 
    
    
    #line 138 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    litaC_a->length -= 1;
    
    #line 139 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
    return litaC_r;
    
    
}



#line 2 "C:/Users/antho/git/litac-lang/src/common.lita"
litaC_i32 main(litaC_i32 litaC_len,litaC_char** litaC_args) {
    
    #line 1 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_mem__ModuleInit();
    
    
    #line 3 "C:/Users/antho/git/litac-lang/src/common.lita"
    printf("Testing 'EscapeTest'\n");
    
    #line 4 "C:/Users/antho/git/litac-lang/src/common.lita"
    litaC_common__EscapeTest();
    
    #line 5 "C:/Users/antho/git/litac-lang/src/common.lita"
    {
        litaC_i32 ___result = 0;
        
        #line 1 "C:/Users/antho/git/litac-lang/src/common.lita"
        litaC_mem__ModuleDestroy();
        return ___result;
        
    }
    
    litaC_mem__ModuleDestroy();
    
}