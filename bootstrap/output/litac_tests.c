#ifndef _LITAC_HEADER_H
#define _LITAC_HEADER_H

// Generated on Mon Nov 22 20:21:19 2021

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




#define __PRFCHWINTRIN_H
#undef __attribute__
#include <intrin.h>
#include <emmintrin.h>
#include <immintrin.h>
//#include <immintrin.h>
//#include <x86intrin.h>

//#pragma intrinsic(__rdtsc)

typedef struct litaC_builtins__any litaC_builtins__any;


#line 111 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_void litaC_intrinsics__testCmp();

#line 205 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_void litaC_intrinsics__testIntrinsics();

#line 284 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_void litaC_intrinsics__testSlowTimed();

#line 311 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_void litaC_intrinsics__testIntrinsicsTimed();

#line 2 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_intrinsics____LitaTestMain(litaC_i32 litaC_len,litaC_char** litaC_args);


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


#line 111 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"

litaC_void litaC_intrinsics__testCmp() {
#line 126 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const char* litaC_str = "\nhello\nthere*/\nthis is it";

#line 140 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_len = strlen(litaC_str);

#line 142 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const char* litaC_needle = "*/1234567890123456";

#line 143 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_match = _mm_loadu_si128((__m128i*)litaC_needle);

#line 144 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_nl = _mm_set1_epi8('\n');

#line 146 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_startTime = _rdtsc();

#line 148 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const char* litaC_data = litaC_str;

#line 149 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_count = 0;

#line 150 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_end = litaC_len - 16;

#line 151 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_foundIndex = -(1);

#line 153 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_lineNumber = 0;

#line 154 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_position = 0;

#line 156 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
while(litaC_count < litaC_end) {{
#line 157 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_batch = _mm_loadu_si128((__m128i*)litaC_data);

#line 159 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_mask = _mm_cmpeq_epi8(litaC_batch, litaC_nl);

#line 160 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_count = _mm_movemask_epi8(litaC_mask);

#line 161 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_count) {{
#line 162 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_pcount = _mm_popcnt_u32(litaC_count);

#line 163 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_lineNumber += litaC_pcount;

#line 164 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_position = (litaC_i32)_lzcnt_u32(litaC_count) - 16;

#line 165 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("Position: %d\n", _lzcnt_u32(litaC_count));

}
} 


#line 168 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_result = _mm_cmpestri(litaC_match, 2, litaC_batch, 16, _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ORDERED | _SIDD_LEAST_SIGNIFICANT | _SIDD_BIT_MASK);

#line 169 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_result < 15 || (litaC_result == 15 && litaC_data[16] == '/')) {{
#line 170 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data = litaC_data + litaC_result + 2;

#line 171 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_position += litaC_result + 2;

#line 173 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto found;


}
} 


#line 176 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_count += 16;

#line 177 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data += 16;

#line 178 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_position += 16;

}}

#line 182 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
for(litaC_i32 litaC_i = litaC_count;litaC_i < litaC_len;litaC_i += 1) {{
#line 183 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_str[litaC_i] == '*' && litaC_str[litaC_i + 1] == '/') {{
#line 184 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data = litaC_str + litaC_i + 2;

#line 185 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto found;


}
} 


}}

#line 188 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto not_found;


#line 190 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
found:;


#line 191 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
{
#line 192 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_endTime = _rdtsc();

#line 193 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("Found: %s => %lld at: %d:%d \n", litaC_data, litaC_endTime - litaC_startTime, litaC_lineNumber, litaC_position);

#line 194 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
return;


}

#line 196 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
not_found:;


#line 197 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
{
#line 198 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_endTime = _rdtsc();

#line 199 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("NOT Found => %lld at: %d:%d\n", litaC_endTime - litaC_startTime, litaC_lineNumber, litaC_position);

#line 200 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
return;


}
}


#line 205 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_void litaC_intrinsics__testIntrinsics() {
#line 207 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const char* litaC_str = "/* this is a comment in whichyyyy*/x";

#line 209 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_star = _mm_set1_epi8('*');

#line 210 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_slash = _mm_set1_epi8('/');

#line 212 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const char* litaC_data = litaC_str;

#line 213 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_len = strlen(litaC_str);

#line 214 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_end = litaC_len - 16;

#line 215 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_count = 0;

#line 216 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
while(litaC_count < litaC_end) {{
#line 217 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_u8 litaC_value[16];

#line 218 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_batch = _mm_loadu_si128((__m128i*)litaC_data);

#line 220 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_testSlash = _mm_cmpeq_epi8(litaC_batch, litaC_slash);

#line 221 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_slashCheck = _mm_movemask_epi8(litaC_testSlash);

#line 222 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_slashCheck) {{
#line 223 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_u32 litaC_offset = _tzcnt_u32(litaC_slashCheck);

#line 225 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("OFFSET: %d %c  check: %d\n", litaC_offset, litaC_data[litaC_offset], litaC_slashCheck);

#line 226 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if((litaC_data + litaC_offset) != litaC_str && litaC_str[litaC_count + litaC_offset - 1] == '*') {{
#line 227 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data += litaC_offset + (litaC_i32)1;

#line 228 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto found;


}
} else {
#line 230 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
{
#line 231 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
for(litaC_u32 litaC_i = litaC_offset + 1;litaC_i < 16;litaC_i += 1) {{
#line 232 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_char litaC_c = litaC_data[litaC_i];

#line 233 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_c == '*' && litaC_data[litaC_i + 1] == '/') {{
#line 234 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("From loop\n");

#line 235 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data += litaC_i + 2;

#line 236 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto found;


}
} 


}}

}} 


}
} 


#line 260 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_count += 16;

#line 261 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data += 16;

}}

#line 264 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
for(litaC_i32 litaC_i = litaC_count;litaC_i < litaC_len;litaC_i += 1) {{
#line 265 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_char litaC_c = litaC_str[litaC_i];

#line 266 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_c == '*' && litaC_str[litaC_i + 1] == '/') {{
#line 267 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data = litaC_str + litaC_i + 2;

#line 268 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto found;


}
} 


}}

#line 272 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto end;


#line 274 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
found:;


#line 275 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("Found ending: %s\n", litaC_data);

#line 276 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
end:;

}


#line 284 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_void litaC_intrinsics__testSlowTimed() {
#line 285 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const char* litaC_str = "/* this is a comment in whichx*x/want to find the end ofxx */start of new";

#line 288 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_len = strlen(litaC_str);

#line 290 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_startTime = _rdtsc();

#line 291 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const litaC_char* litaC_data = NULL;

#line 293 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
for(litaC_i32 litaC_i = 0;litaC_i < litaC_len;litaC_i += 1) {{
#line 294 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_str[litaC_i] == '*' && litaC_str[litaC_i + 1] == '/') {{
#line 295 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data = litaC_str + litaC_i + 2;

#line 296 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
break;

}
} 


}}

#line 300 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_data) {{
#line 301 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_endTime = _rdtsc();

#line 302 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("Found: %s => %lld\n", litaC_data, litaC_endTime - litaC_startTime);

}
} else {
#line 304 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
{
#line 305 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_endTime = _rdtsc();

#line 306 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("NOT Found => %lld\n", litaC_endTime - litaC_startTime);

}} 

}


#line 311 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_void litaC_intrinsics__testIntrinsicsTimed() {
#line 312 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const char* litaC_str = "/* this is a comment in whichx*x/want to find the end ofxx */start of new";

#line 315 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_len = strlen(litaC_str);

#line 317 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_startTime = _rdtsc();

#line 318 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_slash = _mm_set1_epi8('/');

#line 320 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
const char* litaC_data = litaC_str;

#line 321 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_end = litaC_len - 16;

#line 322 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_count = 0;

#line 324 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
while(litaC_count < litaC_end) {{
#line 325 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_batch = _mm_loadu_si128((__m128i*)litaC_data);

#line 327 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
__m128i litaC_testSlash = _mm_cmpeq_epi8(litaC_batch, litaC_slash);

#line 328 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 litaC_slashCheck = _mm_movemask_epi8(litaC_testSlash);

#line 329 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_slashCheck) {{
#line 330 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_u32 litaC_offset = _tzcnt_u32(litaC_slashCheck);

#line 332 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if((litaC_data + litaC_offset) != litaC_str && litaC_str[litaC_count + litaC_offset - 1] == '*') {{
#line 333 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data += litaC_offset + (litaC_i32)1;

#line 334 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto found;


}
} else {
#line 336 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
{
#line 337 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
for(litaC_u32 litaC_i = litaC_offset + 1;litaC_i < 16;litaC_i += 1) {{
#line 338 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_char litaC_c = litaC_data[litaC_i];

#line 339 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_c == '*' && litaC_data[litaC_i + 1] == '/') {{
#line 340 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data += litaC_i + 2;

#line 341 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto found;


}
} 


}}

}} 


}
} 


#line 347 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_count += 16;

#line 348 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data += 16;

}}

#line 351 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
for(litaC_i32 litaC_i = litaC_count;litaC_i < litaC_len;litaC_i += 1) {{
#line 352 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_char litaC_c = litaC_str[litaC_i];

#line 353 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
if(litaC_c == '*' && litaC_str[litaC_i + 1] == '/') {{
#line 354 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_data = litaC_str + litaC_i + 2;

#line 355 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto found;


}
} 


}}

#line 359 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
goto end;


#line 361 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
found:;


#line 362 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_endTime = _rdtsc();

#line 363 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("Found ending: %s  => %lld\n", litaC_data, litaC_endTime - litaC_startTime);

#line 364 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
return;


#line 366 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
end:;


#line 367 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i64 litaC_endTime2 = _rdtsc();

#line 368 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("Ending not found => %lld\n", litaC_endTime2 - litaC_startTime);
}



#line 2 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_i32 main(litaC_i32 litaC_len,litaC_char** litaC_args) {
#line 3 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
printf("Testing 'testCmp'\n");

#line 4 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
litaC_intrinsics__testCmp();

#line 5 "c:/Users/antho/git/litac-lang/stdlib/std/intrinsics/intrinsics.lita"
return 0;

}