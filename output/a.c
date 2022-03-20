#ifndef _LITAC_HEADER_H
#define _LITAC_HEADER_H

// Generated on Sun Oct 17 11:33:23 2021

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

#line 13 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

#define litaC_mem__KiB (1024)

#line 14 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

#define litaC_mem__MiB (1024 * litaC_mem__KiB)

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

#define litaC_mem__GiB (1024 * litaC_mem__MiB)

#line 314 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"

#define litaC_mem__MAX_PATH (256)

#line 211 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"

#define litaC_array__MAX_LEVELS (300)

#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"

#define litaC_cmdline__MAX_MESSAGE_SIZE (256)

#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"

#define litaC_string_buffer__MAX_BUFFER_SIZE (32)

#line 290 "src/lex.lita"

#define litaC_lex__MAX_KEYWORD_CACHE (9)


#line 13 "C:/Users/antho/git/litac-lang/stdlib/std/unicode/utf8/utf8.lita"

#define litaC_utf8__INVALID_RUNE (0xefbfbd)


#line 16 "C:/Users/antho/git/litac-lang/stdlib/std/unicode/utf8/utf8.lita"

#define litaC_utf8__MAX_RUNE (0x10ffff)


#line 19 "C:/Users/antho/git/litac-lang/stdlib/std/unicode/utf8/utf8.lita"

#define litaC_utf8__MAX_RUNE_BYTES (4)

#line 1839 "src/types.lita"

#define litaC_types__MAX_FIELD_PATH (256)

#line 53 "src/symbols.lita"

#define litaC_symbols__MAX_SYMBOL_NAME (256)

#line 136 "src/module.lita"

#define litaC_module__MAX_METHODS_FOR_TYPE (2048)

#line 32 "src/lita.lita"

#define litaC_lita__MAX_PREFIX_SIZE (32)

#line 35 "src/checker.lita"

#define litaC_checker__MAX_LABELS (256)

#line 36 "src/checker.lita"

#define litaC_checker__MAX_LABEL_NAME (32)

#line 19 "src/generics.lita"

#define litaC_generics__MAX_GENERIC_NAME (1024)

#line 21 "src/parser.lita"

#define litaC_parser__DECL_ADJUST_TOKENS_COUNT (11)

#line 55 "src/cgen.lita"

#define litaC_cgen__MAX_COMPILATION_UNITS (256)

#line 756 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"

#define litaC_json__MAX_MESSAGE_SIZE (256)

#line 17 "src/lsp/lsp.lita"

#define litaC_lsp__IN_BUFFER_SIZE (1024 * 1024 * 2)

#line 35 "src/lsp/protocol.lita"

#define litaC_protocol__MAX_DOCUMENT_CONTENT_CHANGES (16)

#include <libtcc.h>

#include "assert.h"


#include <stdlib.h>

#include <stdio.h>
#include <time.h>


typedef enum Lita_OSType {
    Lita_OSType_WINDOWS,
    Lita_OSType_ANDROID,
    Lita_OSType_LINUX,
    Lita_OSType_BSD,
    Lita_OSType_IOS,
    Lita_OSType_MAC,
    Lita_OSType_OTHER
} Lita_OSType;


#if defined(_WIN32)
    // Windows
    Lita_OSType litaOS = Lita_OSType_WINDOWS;
#elif defined(_WIN64)
    // Windows
    Lita_OSType litaOS = Lita_OSType_WINDOWS;
#elif defined(__CYGWIN__) && !defined(_WIN32)
    // Windows (Cygwin POSIX under Microsoft Window)
    Lita_OSType litaOS = Lita_OSType_WINDOWS;
#elif defined(__ANDROID__)
    // Android (implies Linux, so it must come first)
    Lita_OSType litaOS = Lita_OSType_ANDROID;
#elif defined(__linux__)
    // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
    Lita_OSType litaOS = Lita_OSType_LINUX;
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
        Lita_OSType litaOS = Lita_OSType_BSD;
    #endif
#elif defined(__hpux)
    // HP-UX
    Lita_OSType litaOS = Lita_OSType_OTHER;
#elif defined(_AIX)
    // IBM AIX
    Lita_OSType litaOS = Lita_OSType_OTHER;
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        // Apple iOS
        Lita_OSType litaOS = Lita_OSType_IOS;
    #elif TARGET_OS_IPHONE == 1
        // Apple iOS
        Lita_OSType litaOS = Lita_OSType_IOS;
    #elif TARGET_OS_MAC == 1
        // Apple OSX
        Lita_OSType litaOS = Lita_OSType_MAC;
    #endif
#elif defined(__sun) && defined(__SVR4)
    // Oracle Solaris, Open Indiana
    Lita_OSType litaOS = Lita_OSType_OTHER;
#else
    Lita_OSType litaOS = Lita_OSType_OTHER;
#endif


typedef struct tm tm;


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


/*
 *
 * Mini regex-module inspired by Rob Pike's regex code described in:
 *
 * http://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html
 *
 *
 *
 * Supports:
 * ---------
 *   '.'        Dot, matches any character
 *   '^'        Start anchor, matches beginning of string
 *   '$'        End anchor, matches end of string
 *   '*'        Asterisk, match zero or more (greedy)
 *   '+'        Plus, match one or more (greedy)
 *   '?'        Question, match zero or one (non-greedy)
 *   '[abc]'    Character class, match if one of {'a', 'b', 'c'}
 *   '[^abc]'   Inverted class, match if NOT one of {'a', 'b', 'c'} -- NOTE: feature is currently broken!
 *   '[a-zA-Z]' Character ranges, the character set of the ranges { a-z | A-Z }
 *   '\s'       Whitespace, \t \f \r \n \v and spaces
 *   '\S'       Non-whitespace
 *   '\w'       Alphanumeric, [a-zA-Z0-9_]
 *   '\W'       Non-alphanumeric
 *   '\d'       Digits, [0-9]
 *   '\D'       Non-digits
 *
 *
 */



/*
 *
 * Mini regex-module inspired by Rob Pike's regex code described in:
 *
 * http://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html
 *
 *
 *
 * Supports:
 * ---------
 *   '.'        Dot, matches any character
 *   '^'        Start anchor, matches beginning of string
 *   '$'        End anchor, matches end of string
 *   '*'        Asterisk, match zero or more (greedy)
 *   '+'        Plus, match one or more (greedy)
 *   '?'        Question, match zero or one (non-greedy)
 *   '[abc]'    Character class, match if one of {'a', 'b', 'c'}
 *   '[^abc]'   Inverted class, match if NOT one of {'a', 'b', 'c'} -- NOTE: feature is currently broken!
 *   '[a-zA-Z]' Character ranges, the character set of the ranges { a-z | A-Z }
 *   '\s'       Whitespace, \t \f \r \n \v and spaces
 *   '\S'       Non-whitespace
 *   '\w'       Alphanumeric, [a-zA-Z0-9_]
 *   '\W'       Non-alphanumeric
 *   '\d'       Digits, [0-9]
 *   '\D'       Non-digits
 *
 *
 */

#ifndef _TINY_REGEX_C
#define _TINY_REGEX_C


#ifndef RE_DOT_MATCHES_NEWLINE
/* Define to 0 if you DON'T want '.' to match '\r' + '\n' */
#define RE_DOT_MATCHES_NEWLINE 1
#endif

#ifdef __cplusplus
extern "C"{
#endif



/* Typedef'd pointer to get abstract datatype. */
typedef struct regex_t* re_t;


/* Compile regex string pattern to a regex_t-array. */
re_t re_compile(const char* pattern);


/* Find matches of the compiled pattern inside text. */
int  re_matchp(re_t pattern, const char* text, int* matchlength);


/* Find matches of the txt pattern inside text (will compile automatically first). */
int  re_match(const char* pattern, const char* text, int* matchlength);


#ifdef __cplusplus
}
#endif

#endif /* ifndef _TINY_REGEX_C */

#include <stdio.h>

/* Definitions: */

#define MAX_REGEXP_OBJECTS      30    /* Max number of regex symbols in expression. */
#define MAX_CHAR_CLASS_LEN      40    /* Max length of character-class buffer in.   */


enum { UNUSED, DOT, BEGIN, END, QUESTIONMARK, STAR, PLUS, RE_CHAR, CHAR_CLASS, INV_CHAR_CLASS, DIGIT, NOT_DIGIT, ALPHA, NOT_ALPHA, WHITESPACE, NOT_WHITESPACE, /* BRANCH */ };

typedef struct regex_t
{
  unsigned char  type;   /* CHAR, STAR, etc.                      */
  union
  {
    unsigned char  ch;   /*      the character itself             */
    unsigned char* ccl;  /*  OR  a pointer to characters in class */
  };
} regex_t;



/* Private function declarations: */
static int matchpattern(regex_t* pattern, const char* text, int* matchlength);
static int matchcharclass(char c, const char* str);
static int matchstar(regex_t p, regex_t* pattern, const char* text, int* matchlength);
static int matchplus(regex_t p, regex_t* pattern, const char* text, int* matchlength);
static int matchone(regex_t p, char c);
static int matchdigit(char c);
static int matchalpha(char c);
static int matchwhitespace(char c);
static int matchmetachar(char c, const char* str);
static int matchrange(char c, const char* str);
static int matchdot(char c);
static int ismetachar(char c);



/* Public functions: */
int re_match(const char* pattern, const char* text, int* matchlength)
{
  return re_matchp(re_compile(pattern), text, matchlength);
}

int re_matchp(re_t pattern, const char* text, int* matchlength)
{
  *matchlength = 0;
  if (pattern != 0)
  {
    if (pattern[0].type == BEGIN)
    {
      return ((matchpattern(&pattern[1], text, matchlength)) ? 0 : -1);
    }
    else
    {
      int idx = -1;

      do
      {
        idx += 1;

        if (matchpattern(pattern, text, matchlength))
        {
          if (text[0] == '\0')
            return -1;

          return idx;
        }
      }
      while (*text++ != '\0');
    }
  }
  return -1;
}

re_t re_compile(const char* pattern)
{
  /* The sizes of the two static arrays below substantiates the static RAM usage of this module.
     MAX_REGEXP_OBJECTS is the max number of symbols in the expression.
     MAX_CHAR_CLASS_LEN determines the size of buffer for chars in all char-classes in the expression. */
  static regex_t re_compiled[MAX_REGEXP_OBJECTS];
  static unsigned char ccl_buf[MAX_CHAR_CLASS_LEN];
  int ccl_bufidx = 1;

  char c;     /* current char in pattern   */
  int i = 0;  /* index into pattern        */
  int j = 0;  /* index into re_compiled    */

  while (pattern[i] != '\0' && (j+1 < MAX_REGEXP_OBJECTS))
  {
    c = pattern[i];

    switch (c)
    {
      /* Meta-characters: */
      case '^': {    re_compiled[j].type = BEGIN;           } break;
      case '$': {    re_compiled[j].type = END;             } break;
      case '.': {    re_compiled[j].type = DOT;             } break;
      case '*': {    re_compiled[j].type = STAR;            } break;
      case '+': {    re_compiled[j].type = PLUS;            } break;
      case '?': {    re_compiled[j].type = QUESTIONMARK;    } break;
/*    case '|': {    re_compiled[j].type = BRANCH;          } break; <-- not working properly */

      /* Escaped character-classes (\s \w ...): */
      case '\\':
      {
        if (pattern[i+1] != '\0')
        {
          /* Skip the escape-char '\\' */
          i += 1;
          /* ... and check the next */
          switch (pattern[i])
          {
            /* Meta-character: */
            case 'd': {    re_compiled[j].type = DIGIT;            } break;
            case 'D': {    re_compiled[j].type = NOT_DIGIT;        } break;
            case 'w': {    re_compiled[j].type = ALPHA;            } break;
            case 'W': {    re_compiled[j].type = NOT_ALPHA;        } break;
            case 's': {    re_compiled[j].type = WHITESPACE;       } break;
            case 'S': {    re_compiled[j].type = NOT_WHITESPACE;   } break;

            /* Escaped character, e.g. '.' or '$' */
            default:
            {
              re_compiled[j].type = RE_CHAR;
              re_compiled[j].ch = pattern[i];
            } break;
          }
        }
        /* '\\' as last char in pattern -> invalid regular expression. */
/*
        else
        {
          re_compiled[j].type = CHAR;
          re_compiled[j].ch = pattern[i];
        }
*/
      } break;

      /* Character class: */
      case '[':
      {
        /* Remember where the char-buffer starts. */
        int buf_begin = ccl_bufidx;

        /* Look-ahead to determine if negated */
        if (pattern[i+1] == '^')
        {
          re_compiled[j].type = INV_CHAR_CLASS;
          i += 1; /* Increment i to avoid including '^' in the char-buffer */
          if (pattern[i+1] == 0) /* incomplete pattern, missing non-zero char after '^' */
          {
            return 0;
          }
        }
        else
        {
          re_compiled[j].type = CHAR_CLASS;
        }

        /* Copy characters inside [..] to buffer */
        while (    (pattern[++i] != ']')
                && (pattern[i]   != '\0')) /* Missing ] */
        {
          if (pattern[i] == '\\')
          {
            if (ccl_bufidx >= MAX_CHAR_CLASS_LEN - 1)
            {
              //fputs("exceeded internal buffer!\n", stderr);
              return 0;
            }
            if (pattern[i+1] == 0) /* incomplete pattern, missing non-zero char after '\\' */
            {
              return 0;
            }
            ccl_buf[ccl_bufidx++] = pattern[i++];
          }
          else if (ccl_bufidx >= MAX_CHAR_CLASS_LEN)
          {
              //fputs("exceeded internal buffer!\n", stderr);
              return 0;
          }
          ccl_buf[ccl_bufidx++] = pattern[i];
        }
        if (ccl_bufidx >= MAX_CHAR_CLASS_LEN)
        {
            /* Catches cases such as [00000000000000000000000000000000000000][ */
            //fputs("exceeded internal buffer!\n", stderr);
            return 0;
        }
        /* Null-terminate string end */
        ccl_buf[ccl_bufidx++] = 0;
        re_compiled[j].ccl = &ccl_buf[buf_begin];
      } break;

      /* Other characters: */
      default:
      {
        re_compiled[j].type = RE_CHAR;
        re_compiled[j].ch = c;
      } break;
    }
    /* no buffer-out-of-bounds access on invalid patterns - see https://github.com/kokke/tiny-regex-c/commit/1a279e04014b70b0695fba559a7c05d55e6ee90b */
    if (pattern[i] == 0)
    {
      return 0;
    }

    i += 1;
    j += 1;
  }
  /* 'UNUSED' is a sentinel used to indicate end-of-pattern */
  re_compiled[j].type = UNUSED;

  return (re_t) re_compiled;
}

void re_print(regex_t* pattern)
{
  const char* types[] = { "UNUSED", "DOT", "BEGIN", "END", "QUESTIONMARK", "STAR", "PLUS", "CHAR", "CHAR_CLASS", "INV_CHAR_CLASS", "DIGIT", "NOT_DIGIT", "ALPHA", "NOT_ALPHA", "WHITESPACE", "NOT_WHITESPACE", "BRANCH" };

  int i;
  int j;
  char c;
  for (i = 0; i < MAX_REGEXP_OBJECTS; ++i)
  {
    if (pattern[i].type == UNUSED)
    {
      break;
    }

    printf("type: %s", types[pattern[i].type]);
    if (pattern[i].type == CHAR_CLASS || pattern[i].type == INV_CHAR_CLASS)
    {
      printf(" [");
      for (j = 0; j < MAX_CHAR_CLASS_LEN; ++j)
      {
        c = pattern[i].ccl[j];
        if ((c == '\0') || (c == ']'))
        {
          break;
        }
        printf("%c", c);
      }
      printf("]");
    }
    else if (pattern[i].type == RE_CHAR)
    {
      printf(" '%c'", pattern[i].ch);
    }
    printf("\n");
  }
}



/* Private functions: */
static int matchdigit(char c)
{
  return ((c >= '0') && (c <= '9'));
}
static int matchalpha(char c)
{
  return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}
static int matchwhitespace(char c)
{
  return ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r') || (c == '\f') || (c == '\v'));
}
static int matchalphanum(char c)
{
  return ((c == '_') || matchalpha(c) || matchdigit(c));
}
static int matchrange(char c, const char* str)
{
  return (    (c != '-')
           && (str[0] != '\0')
           && (str[0] != '-')
           && (str[1] == '-')
           && (str[2] != '\0')
           && (    (c >= str[0])
                && (c <= str[2])));
}
static int matchdot(char c)
{
#if defined(RE_DOT_MATCHES_NEWLINE) && (RE_DOT_MATCHES_NEWLINE == 1)
  (void)c;
  return 1;
#else
  return c != '\n' && c != '\r';
#endif
}
static int ismetachar(char c)
{
  return ((c == 's') || (c == 'S') || (c == 'w') || (c == 'W') || (c == 'd') || (c == 'D'));
}

static int matchmetachar(char c, const char* str)
{
  switch (str[0])
  {
    case 'd': return  matchdigit(c);
    case 'D': return !matchdigit(c);
    case 'w': return  matchalphanum(c);
    case 'W': return !matchalphanum(c);
    case 's': return  matchwhitespace(c);
    case 'S': return !matchwhitespace(c);
    default:  return (c == str[0]);
  }
}

static int matchcharclass(char c, const char* str)
{
  do
  {
    if (matchrange(c, str))
    {
      return 1;
    }
    else if (str[0] == '\\')
    {
      /* Escape-char: increment str-ptr and match on next char */
      str += 1;
      if (matchmetachar(c, str))
      {
        return 1;
      }
      else if ((c == str[0]) && !ismetachar(c))
      {
        return 1;
      }
    }
    else if (c == str[0])
    {
      if (c == '-')
      {
        return ((str[-1] == '\0') || (str[1] == '\0'));
      }
      else
      {
        return 1;
      }
    }
  }
  while (*str++ != '\0');

  return 0;
}

static int matchone(regex_t p, char c)
{
  switch (p.type)
  {
    case DOT:            return matchdot(c);
    case CHAR_CLASS:     return  matchcharclass(c, (const char*)p.ccl);
    case INV_CHAR_CLASS: return !matchcharclass(c, (const char*)p.ccl);
    case DIGIT:          return  matchdigit(c);
    case NOT_DIGIT:      return !matchdigit(c);
    case ALPHA:          return  matchalphanum(c);
    case NOT_ALPHA:      return !matchalphanum(c);
    case WHITESPACE:     return  matchwhitespace(c);
    case NOT_WHITESPACE: return !matchwhitespace(c);
    default:             return  (p.ch == c);
  }
}

static int matchstar(regex_t p, regex_t* pattern, const char* text, int* matchlength)
{
  int prelen = *matchlength;
  const char* prepoint = text;
  while ((text[0] != '\0') && matchone(p, *text))
  {
    text++;
    (*matchlength)++;
  }
  while (text >= prepoint)
  {
    if (matchpattern(pattern, text--, matchlength))
      return 1;
    (*matchlength)--;
  }

  *matchlength = prelen;
  return 0;
}

static int matchplus(regex_t p, regex_t* pattern, const char* text, int* matchlength)
{
  const char* prepoint = text;
  while ((text[0] != '\0') && matchone(p, *text))
  {
    text++;
    (*matchlength)++;
  }
  while (text > prepoint)
  {
    if (matchpattern(pattern, text--, matchlength))
      return 1;
    (*matchlength)--;
  }

  return 0;
}

static int matchquestion(regex_t p, regex_t* pattern, const char* text, int* matchlength)
{
  if (p.type == UNUSED)
    return 1;
  if (matchpattern(pattern, text, matchlength))
      return 1;
  if (*text && matchone(p, *text++))
  {
    if (matchpattern(pattern, text, matchlength))
    {
      (*matchlength)++;
      return 1;
    }
  }
  return 0;
}


#if 0

/* Recursive matching */
static int matchpattern(regex_t* pattern, const char* text, int *matchlength)
{
  int pre = *matchlength;
  if ((pattern[0].type == UNUSED) || (pattern[1].type == QUESTIONMARK))
  {
    return matchquestion(pattern[1], &pattern[2], text, matchlength);
  }
  else if (pattern[1].type == STAR)
  {
    return matchstar(pattern[0], &pattern[2], text, matchlength);
  }
  else if (pattern[1].type == PLUS)
  {
    return matchplus(pattern[0], &pattern[2], text, matchlength);
  }
  else if ((pattern[0].type == END) && pattern[1].type == UNUSED)
  {
    return text[0] == '\0';
  }
  else if ((text[0] != '\0') && matchone(pattern[0], text[0]))
  {
    (*matchlength)++;
    return matchpattern(&pattern[1], text+1);
  }
  else
  {
    *matchlength = pre;
    return 0;
  }
}

#else

/* Iterative matching */
static int matchpattern(regex_t* pattern, const char* text, int* matchlength)
{
  int pre = *matchlength;
  do
  {
    if ((pattern[0].type == UNUSED) || (pattern[1].type == QUESTIONMARK))
    {
      return matchquestion(pattern[0], &pattern[2], text, matchlength);
    }
    else if (pattern[1].type == STAR)
    {
      return matchstar(pattern[0], &pattern[2], text, matchlength);
    }
    else if (pattern[1].type == PLUS)
    {
      return matchplus(pattern[0], &pattern[2], text, matchlength);
    }
    else if ((pattern[0].type == END) && pattern[1].type == UNUSED)
    {
      return (text[0] == '\0');
    }
/*  Branching is not working properly
    else if (pattern[1].type == BRANCH)
    {
      return (matchpattern(pattern, text) || matchpattern(&pattern[2], text));
    }
*/
  (*matchlength)++;
  }
  while ((text[0] != '\0') && matchone(*pattern++, *text++));

  *matchlength = pre;
  return 0;
}

#endif


#include <ape.h>

/*
SPDX-License-Identifier: MIT

ape
https://github.com/kgabis/ape
Copyright (c) 2020 Krzysztof Gabis

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#define APE_AMALGAMATED

#include "ape.h"

//-----------------------------------------------------------------------------
// Headers
//-----------------------------------------------------------------------------
//FILE_START:common.h
#ifndef common_h
#define common_h

#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <float.h>

#ifndef APE_AMALGAMATED
#include "ape.h"
#endif

#define APE_STREQ(a, b) (strcmp((a), (b)) == 0)
#define APE_STRNEQ(a, b, n) (strncmp((a), (b), (n)) == 0)
#define APE_ARRAY_LEN(array) ((int)(sizeof(array) / sizeof(array[0])))
#define APE_DBLEQ(a, b) (fabs((a) - (b)) < DBL_EPSILON)

#ifdef APE_DEBUG
    #define APE_ASSERT(x) assert((x))
    #define APE_FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
    #define APE_LOG(...) ape_log(APE_FILENAME, __LINE__, __VA_ARGS__)
#else
    #define APE_ASSERT(x) ((void)0)
    #define APE_LOG(...) ((void)0)
#endif

#ifdef APE_AMALGAMATED
#define COLLECTIONS_AMALGAMATED
#define APE_INTERNAL static
#else
#define APE_INTERNAL
#endif

typedef struct compiled_file compiled_file_t;

typedef struct src_pos {
    const compiled_file_t *file;
    int line;
    int column;
} src_pos_t;

typedef void * (*ape_malloc_fn)(size_t size, void* mallocArg);
typedef void (*ape_free_fn)(void *ptr, void* freeArg);

typedef struct ape_config {
    struct {
        struct {
            ape_stdout_write_fn write;
            void *context;
        } write;
    } stdio;

    struct {
        struct {
            ape_read_file_fn read_file;
            void *context;
        } read_file;

        struct {
            ape_write_file_fn write_file;
            void *context;
        } write_file;
    } fileio;

    int gc_interval;

    bool repl_mode; // allows redefinition of symbols
} ape_config_t;

#ifndef APE_AMALGAMATED
extern const src_pos_t src_pos_invalid;
extern const src_pos_t src_pos_zero;
#endif

APE_INTERNAL src_pos_t src_pos_make(const compiled_file_t *file, int line, int column);
APE_INTERNAL char *ape_stringf(const char *format, ...);
APE_INTERNAL void ape_log(const char *file, int line, const char *format, ...);
APE_INTERNAL char* ape_strndup(const char *string, size_t n);
APE_INTERNAL char* ape_strdup(const char *string);

APE_INTERNAL uint64_t ape_double_to_uint64(double val);
APE_INTERNAL double ape_uint64_to_double(uint64_t val);

extern void* ape_mallocArg;
extern void* ape_freeArg;
extern ape_malloc_fn ape_malloc;
extern ape_free_fn ape_free;

#endif /* common_h */
//FILE_END
//FILE_START:collections.h
/*
Copyright (c) 2020 Krzysztof Gabis
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


/* To update:
 curl https://raw.githubusercontent.com/kgabis/cutils/master/collections.h > collections.h
 curl https://raw.githubusercontent.com/kgabis/cutils/master/collections.c > collections.c
 */

#ifndef collections_h
#define collections_h

#include <stdbool.h>
#include <stddef.h>

#ifdef COLLECTIONS_AMALGAMATED
#define COLLECTIONS_API static
#else
#define COLLECTIONS_API
#endif

//-----------------------------------------------------------------------------
// Collections
//-----------------------------------------------------------------------------

typedef void * (*collections_malloc_fn)(size_t size, void* mallocArg);
typedef void (*collections_free_fn)(void *ptr, void* freeArg);
typedef unsigned long (*collections_hash_fn)(const void* val);
typedef bool (*collections_equals_fn)(const void *a, const void *b);

COLLECTIONS_API void collections_set_memory_functions(collections_malloc_fn malloc_fn, collections_free_fn free_fn);

//-----------------------------------------------------------------------------
// Dictionary
//-----------------------------------------------------------------------------

typedef struct dict_ dict_t_;

#define dict(TYPE) dict_t_

typedef void (*dict_item_destroy_fn)(void* item);
#define dict_destroy_with_items(dict, fn) dict_destroy_with_items_(dict, (dict_item_destroy_fn)(fn))

typedef void* (*dict_item_copy_fn)(void* item);
#define dict_copy_with_items(dict, fn) dict_copy_with_items_(dict, (dict_item_copy_fn)(fn))

COLLECTIONS_API dict_t_*     dict_make(void);
COLLECTIONS_API void         dict_destroy(dict_t_ *dict);
COLLECTIONS_API void         dict_destroy_with_items_(dict_t_ *dict, dict_item_destroy_fn destroy_fn);
COLLECTIONS_API dict_t_*     dict_copy_with_items_(dict_t_ *dict, dict_item_copy_fn copy_fn);
COLLECTIONS_API bool         dict_set(dict_t_ *dict, const char *key, void *value);
COLLECTIONS_API void *       dict_get(const dict_t_ *dict, const char *key);
COLLECTIONS_API void *       dict_get_value_at(const dict_t_ *dict, unsigned int ix);
COLLECTIONS_API const char * dict_get_key_at(const dict_t_ *dict, unsigned int ix);
COLLECTIONS_API int          dict_count(const dict_t_ *dict);
COLLECTIONS_API bool         dict_remove(dict_t_ *dict, const char *key);
COLLECTIONS_API void         dict_clear(dict_t_ *dict);

//-----------------------------------------------------------------------------
// Value dictionary
//-----------------------------------------------------------------------------

typedef struct valdict_ valdict_t_;

#define valdict(KEY_TYPE, VALUE_TYPE) valdict_t_

#define valdict_make(key_type, val_type) valdict_make_(sizeof(key_type), sizeof(val_type))

COLLECTIONS_API valdict_t_* valdict_make_(size_t key_size, size_t val_size);
COLLECTIONS_API valdict_t_* valdict_make_with_capacity(unsigned int min_capacity, size_t key_size, size_t val_size);
COLLECTIONS_API void        valdict_destroy(valdict_t_ *dict);
COLLECTIONS_API void        valdict_set_hash_function(valdict_t_ *dict, collections_hash_fn hash_fn);
COLLECTIONS_API void        valdict_set_equals_function(valdict_t_ *dict, collections_equals_fn equals_fn);
COLLECTIONS_API bool        valdict_set(valdict_t_ *dict, void *key, void *value);
COLLECTIONS_API void *      valdict_get(const valdict_t_ *dict, const void *key);
COLLECTIONS_API void *      valdict_get_key_at(const valdict_t_ *dict, unsigned int ix);
COLLECTIONS_API void *      valdict_get_value_at(const valdict_t_ *dict, unsigned int ix);
COLLECTIONS_API bool        valdict_set_value_at(const valdict_t_ *dict, unsigned int ix, const void *value);
COLLECTIONS_API int         valdict_count(const valdict_t_ *dict);
COLLECTIONS_API bool        valdict_remove(valdict_t_ *dict, void *key);
COLLECTIONS_API void        valdict_clear(valdict_t_ *dict);

//-----------------------------------------------------------------------------
// Pointer dictionary
//-----------------------------------------------------------------------------

typedef struct ptrdict_ ptrdict_t_;

#define ptrdict(KEY_TYPE, VALUE_TYPE) ptrdict_t_

COLLECTIONS_API ptrdict_t_* ptrdict_make(void);
COLLECTIONS_API void        ptrdict_destroy(ptrdict_t_ *dict);
COLLECTIONS_API void        ptrdict_set_hash_function(ptrdict_t_ *dict, collections_hash_fn hash_fn);
COLLECTIONS_API void        ptrdict_set_equals_function(ptrdict_t_ *dict, collections_equals_fn equals_fn);
COLLECTIONS_API bool        ptrdict_set(ptrdict_t_ *dict, void *key, void *value);
COLLECTIONS_API void *      ptrdict_get(const ptrdict_t_ *dict, const void *key);
COLLECTIONS_API void *      ptrdict_get_value_at(const ptrdict_t_ *dict, unsigned int ix);
COLLECTIONS_API void *      ptrdict_get_key_at(const ptrdict_t_ *dict, unsigned int ix);
COLLECTIONS_API int         ptrdict_count(const ptrdict_t_ *dict);
COLLECTIONS_API bool        ptrdict_remove(ptrdict_t_ *dict, void *key);
COLLECTIONS_API void        ptrdict_clear(ptrdict_t_ *dict);

//-----------------------------------------------------------------------------
// Array
//-----------------------------------------------------------------------------

typedef struct array_ array_t_;

#define array(TYPE) array_t_

#define array_make(type) array_make_(sizeof(type))
typedef void (*array_item_deinit_fn)(void* item);
#define array_destroy_with_items(arr, fn) array_destroy_with_items_(arr, (array_item_deinit_fn)(fn))
#define array_clear_and_deinit_items(arr, fn) array_clear_and_deinit_items_(arr, (array_item_deinit_fn)(fn))

COLLECTIONS_API array_t_*   array_make_(size_t element_size);
COLLECTIONS_API array_t_*   array_make_with_capacity(unsigned int capacity, size_t element_size);
COLLECTIONS_API void        array_destroy(array_t_ *arr);
COLLECTIONS_API void        array_destroy_with_items_(array_t_ *arr, array_item_deinit_fn deinit_fn);
COLLECTIONS_API array_t_*   array_copy(const array_t_ *arr);
COLLECTIONS_API bool        array_add(array_t_ *arr, const void *value);
COLLECTIONS_API bool        array_addn(array_t_ *arr, const void *values, int n);
COLLECTIONS_API bool        array_add_array(array_t_ *dest, const array_t_ *source);
COLLECTIONS_API bool        array_push(array_t_ *arr, const void *value);
COLLECTIONS_API bool        array_pop(array_t_ *arr, void *out_value);
COLLECTIONS_API void *      array_top(array_t_ *arr);
COLLECTIONS_API bool        array_set(array_t_ *arr, unsigned int ix, void *value);
COLLECTIONS_API bool        array_setn(array_t_ *arr, unsigned int ix, void *values, int n);
COLLECTIONS_API void *      array_get(const array_t_ *arr, unsigned int ix);
COLLECTIONS_API void *      array_get_last(const array_t_ *arr);
COLLECTIONS_API int         array_count(const array_t_ *arr);
COLLECTIONS_API bool        array_remove_at(array_t_ *arr, unsigned int ix);
COLLECTIONS_API bool        array_remove_item(array_t_ *arr, void *ptr);
COLLECTIONS_API void        array_clear(array_t_ *arr);
COLLECTIONS_API void        array_clear_and_deinit_items_(array_t_ *arr, array_item_deinit_fn deinit_fn);
COLLECTIONS_API void        array_lock_capacity(array_t_ *arr);
COLLECTIONS_API int         array_get_index(const array_t_ *arr, void *ptr);
COLLECTIONS_API bool        array_contains(const array_t_ *arr, void *ptr);
COLLECTIONS_API void*       array_data(array_t_ *arr);
COLLECTIONS_API const void* array_const_data(const array_t_ *arr);
COLLECTIONS_API bool        array_orphan_data(array_t_ *arr);
COLLECTIONS_API void        array_reverse(array_t_ *arr);

//-----------------------------------------------------------------------------
// Pointer Array
//-----------------------------------------------------------------------------

typedef struct ptrarray_ ptrarray_t_;

#define ptrarray(TYPE) ptrarray_t_

typedef void (*ptrarray_item_destroy_fn)(void* item);
#define ptrarray_destroy_with_items(arr, fn) ptrarray_destroy_with_items_(arr, (ptrarray_item_destroy_fn)(fn))
#define ptrarray_clear_and_destroy_items(arr, fn) ptrarray_clear_and_destroy_items_(arr, (ptrarray_item_destroy_fn)(fn))

typedef void* (*ptrarray_item_copy_fn)(void* item);
#define ptrarray_copy_with_items(arr, fn) ptrarray_copy_with_items_(arr, (ptrarray_item_copy_fn)(fn))

COLLECTIONS_API ptrarray_t_* ptrarray_make(void);
COLLECTIONS_API ptrarray_t_* ptrarray_make_with_capacity(unsigned int capacity);
COLLECTIONS_API void         ptrarray_destroy(ptrarray_t_ *arr);
COLLECTIONS_API void         ptrarray_destroy_with_items_(ptrarray_t_ *arr, ptrarray_item_destroy_fn destroy_fn);
COLLECTIONS_API ptrarray_t_* ptrarray_copy(ptrarray_t_ *arr);
COLLECTIONS_API ptrarray_t_* ptrarray_copy_with_items_(ptrarray_t_ *arr, ptrarray_item_copy_fn copy_fn);
COLLECTIONS_API bool         ptrarray_add(ptrarray_t_ *arr, void *ptr);
COLLECTIONS_API bool         ptrarray_set(ptrarray_t_ *arr, unsigned int ix, void *ptr);
COLLECTIONS_API bool         ptrarray_add_array(ptrarray_t_ *dest, const ptrarray_t_ *source);
COLLECTIONS_API void *       ptrarray_get(ptrarray_t_ *arr, unsigned int ix);
COLLECTIONS_API bool         ptrarray_push(ptrarray_t_ *arr, void *ptr);
COLLECTIONS_API void *       ptrarray_pop(ptrarray_t_ *arr);
COLLECTIONS_API void *       ptrarray_top(ptrarray_t_ *arr);
COLLECTIONS_API int          ptrarray_count(const ptrarray_t_ *arr);
COLLECTIONS_API bool         ptrarray_remove_at(ptrarray_t_ *arr, unsigned int ix);
COLLECTIONS_API bool         ptrarray_remove_item(ptrarray_t_ *arr, void *item);
COLLECTIONS_API void         ptrarray_clear(ptrarray_t_ *arr);
COLLECTIONS_API void         ptrarray_clear_and_destroy_items_(ptrarray_t_ *arr, ptrarray_item_destroy_fn destroy_fn);
COLLECTIONS_API void         ptrarray_lock_capacity(ptrarray_t_ *arr);
COLLECTIONS_API int          ptrarray_get_index(ptrarray_t_ *arr, void *ptr);
COLLECTIONS_API bool         ptrarray_contains(ptrarray_t_ *arr, void *ptr);
COLLECTIONS_API void *       ptrarray_get_addr(ptrarray_t_ *arr, unsigned int ix);
COLLECTIONS_API void*        ptrarray_data(ptrarray_t_ *arr);
COLLECTIONS_API void         ptrarray_reverse(ptrarray_t_ *arr);

//-----------------------------------------------------------------------------
// String buffer
//-----------------------------------------------------------------------------

typedef struct strbuf strbuf_t;

COLLECTIONS_API strbuf_t* strbuf_make(void);
COLLECTIONS_API strbuf_t* strbuf_make_with_capacity(unsigned int capacity);
COLLECTIONS_API void strbuf_destroy(strbuf_t *buf);
COLLECTIONS_API void strbuf_clear(strbuf_t *buf);
COLLECTIONS_API bool strbuf_append(strbuf_t *buf, const char *str);
COLLECTIONS_API bool strbuf_appendf(strbuf_t *buf, const char *fmt, ...)  __attribute__((format(printf, 2, 3)));
COLLECTIONS_API const char * strbuf_get_string(const strbuf_t *buf);
COLLECTIONS_API size_t strbuf_get_length(const strbuf_t *buf);
COLLECTIONS_API char * strbuf_get_string_and_destroy(strbuf_t *buf);

//-----------------------------------------------------------------------------
// Utils
//-----------------------------------------------------------------------------

COLLECTIONS_API ptrarray(char)* kg_split_string(const char *str, const char *delimiter);
COLLECTIONS_API char* kg_join(ptrarray(char) *items, const char *with);
COLLECTIONS_API char* kg_canonicalise_path(const char *path);
COLLECTIONS_API bool  kg_is_path_absolute(const char *path);
COLLECTIONS_API bool  kg_streq(const char *a, const char *b);

#endif /* collections_h */
//FILE_END
//FILE_START:error.h
#ifndef error_h
#define error_h

#ifndef APE_AMALGAMATED
#include "common.h"
#include "token.h"
#endif

typedef struct traceback traceback_t;

typedef enum error_type {
    ERROR_NONE = 0,
    ERROR_PARSING,
    ERROR_COMPILATION,
    ERROR_RUNTIME,
    ERROR_USER,
} error_type_t;

typedef struct error {
    error_type_t type;
    char *message;
    src_pos_t pos;
    traceback_t *traceback;
} error_t;

APE_INTERNAL error_t* error_make_no_copy(error_type_t type, src_pos_t pos, char *message);
APE_INTERNAL error_t* error_make(error_type_t type, src_pos_t pos, const char *message);
APE_INTERNAL error_t* error_makef(error_type_t type, src_pos_t pos, const char *format, ...) __attribute__ ((format (printf, 3, 4)));
APE_INTERNAL void error_destroy(error_t *error);
APE_INTERNAL const char *error_type_to_string(error_type_t type);

#endif /* error_h */
//FILE_END
//FILE_START:token.h
#ifndef token_h
#define token_h

#ifndef APE_AMALGAMATED
#include "common.h"
#endif

typedef enum {
    TOKEN_ILLEGAL = 0,
    TOKEN_EOF,

    // Operators
    TOKEN_ASSIGN,

    TOKEN_PLUS_ASSIGN,
    TOKEN_MINUS_ASSIGN,
    TOKEN_ASTERISK_ASSIGN,
    TOKEN_SLASH_ASSIGN,
    TOKEN_PERCENT_ASSIGN,
    TOKEN_BIT_AND_ASSIGN,
    TOKEN_BIT_OR_ASSIGN,
    TOKEN_BIT_XOR_ASSIGN,
    TOKEN_LSHIFT_ASSIGN,
    TOKEN_RSHIFT_ASSIGN,

    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_BANG,
    TOKEN_ASTERISK,
    TOKEN_SLASH,

    TOKEN_LT,
    TOKEN_LTE,
    TOKEN_GT,
    TOKEN_GTE,

    TOKEN_EQ,
    TOKEN_NOT_EQ,

    TOKEN_AND,
    TOKEN_OR,

    TOKEN_BIT_AND,
    TOKEN_BIT_OR,
    TOKEN_BIT_XOR,
    TOKEN_LSHIFT,
    TOKEN_RSHIFT,

    // Delimiters
    TOKEN_COMMA,
    TOKEN_SEMICOLON,
    TOKEN_COLON,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_DOT,
    TOKEN_PERCENT,

    // Keywords
    TOKEN_FUNCTION,
    TOKEN_CONST,
    TOKEN_VAR,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_RETURN,
    TOKEN_WHILE,
    TOKEN_BREAK,
    TOKEN_FOR,
    TOKEN_IN,
    TOKEN_CONTINUE,
    TOKEN_NULL,
    TOKEN_IMPORT,
    TOKEN_RECOVER,

    // Identifiers and literals
    TOKEN_IDENT,
    TOKEN_NUMBER,
    TOKEN_STRING,

    TOKEN_TYPE_MAX
} token_type_t;

typedef struct token {
    token_type_t type;
    const char *literal;
    int len;
    src_pos_t pos;
} token_t;

APE_INTERNAL void token_make(token_t *tok, token_type_t type, const char *literal, int len); // no need to destroy
APE_INTERNAL char *token_duplicate_literal(const token_t *tok);
APE_INTERNAL const char *token_type_to_string(token_type_t type);

#endif /* token_h */
//FILE_END
//FILE_START:lexer.h
#ifndef lexer_h
#define lexer_h

#include <stdbool.h>
#include <stddef.h>

#ifndef APE_AMALGAMATED
#include "common.h"
#include "token.h"
#endif

typedef struct lexer {
    const char *input;
    int input_len;
    int position;
    int next_position;
    char ch;
    int line;
    int column;
    compiled_file_t *file;
} lexer_t;

APE_INTERNAL bool lexer_init(lexer_t *lex, const char *input, compiled_file_t *file); // no need to deinit

APE_INTERNAL token_t lexer_next_token(lexer_t *lex);

#endif /* lexer_h */
//FILE_END
//FILE_START:ast.h
#ifndef ast_h
#define ast_h

#ifndef APE_AMALGAMATED
#include "common.h"
#include "collections.h"
#include "token.h"
#endif

typedef struct code_block {
    ptrarray(statement_t) *statements;
} code_block_t;

typedef struct expression expression_t;
typedef struct statement statement_t;

typedef struct map_literal {
    ptrarray(expression_t) *keys;
    ptrarray(expression_t) *values;
} map_literal_t;

typedef enum {
    OPERATOR_NONE,
    OPERATOR_ASSIGN,
    OPERATOR_PLUS,
    OPERATOR_MINUS,
    OPERATOR_BANG,
    OPERATOR_ASTERISK,
    OPERATOR_SLASH,
    OPERATOR_LT,
    OPERATOR_LTE,
    OPERATOR_GT,
    OPERATOR_GTE,
    OPERATOR_EQ,
    OPERATOR_NOT_EQ,
    OPERATOR_MODULUS,
    OPERATOR_LOGICAL_AND,
    OPERATOR_LOGICAL_OR,
    OPERATOR_BIT_AND,
    OPERATOR_BIT_OR,
    OPERATOR_BIT_XOR,
    OPERATOR_LSHIFT,
    OPERATOR_RSHIFT,
} operator_t;

typedef struct prefix {
    operator_t op;
    expression_t *right;
} prefix_expression_t;

typedef struct infix {
    operator_t op;
    expression_t *left;
    expression_t *right;
} infix_expression_t;

typedef struct if_case {
    expression_t *test;
    code_block_t *consequence;
} if_case_t;

typedef struct fn_literal {
    char *name;
    array(ident_t) *params;
    code_block_t *body;
} fn_literal_t;

typedef struct call_expression {
    expression_t *function;
    ptrarray(expression_t) *args;
} call_expression_t;

typedef struct index_expression {
    expression_t *left;
    expression_t *index;
} index_expression_t;

typedef struct assign_expression {
    expression_t *dest;
    expression_t *source;
} assign_expression_t;

typedef struct logical_expression {
    operator_t op;
    expression_t *left;
    expression_t *right;
} logical_expression_t;

typedef enum expression_type {
    EXPRESSION_NONE,
    EXPRESSION_IDENT,
    EXPRESSION_NUMBER_LITERAL,
    EXPRESSION_BOOL_LITERAL,
    EXPRESSION_STRING_LITERAL,
    EXPRESSION_NULL_LITERAL,
    EXPRESSION_ARRAY_LITERAL,
    EXPRESSION_MAP_LITERAL,
    EXPRESSION_PREFIX,
    EXPRESSION_INFIX,
    EXPRESSION_FUNCTION_LITERAL,
    EXPRESSION_CALL,
    EXPRESSION_INDEX,
    EXPRESSION_ASSIGN,
    EXPRESSION_LOGICAL,
} expression_type_t;

typedef struct ident {
    char *value;
    src_pos_t pos;
} ident_t;

typedef struct expression {
    expression_type_t type;
    union {
        ident_t ident;
        double number_literal;
        bool bool_literal;
        char *string_literal;
        ptrarray(expression_t) *array;
        map_literal_t map;
        prefix_expression_t prefix;
        infix_expression_t infix;
        fn_literal_t fn_literal;
        call_expression_t call_expr;
        index_expression_t index_expr;
        assign_expression_t assign;
        logical_expression_t logical;
    };
    src_pos_t pos;
} expression_t;

typedef enum statement_type {
    STATEMENT_NONE,
    STATEMENT_DEFINE,
    STATEMENT_IF,
    STATEMENT_RETURN_VALUE,
    STATEMENT_EXPRESSION,
    STATEMENT_WHILE_LOOP,
    STATEMENT_BREAK,
    STATEMENT_CONTINUE,
    STATEMENT_FOREACH,
    STATEMENT_FOR_LOOP,
    STATEMENT_BLOCK,
    STATEMENT_IMPORT,
    STATEMENT_RECOVER,
} statement_type_t;

typedef struct define_statement {
    ident_t name;
    expression_t *value;
    bool assignable;
} define_statement_t;

typedef struct if_statement {
    ptrarray(if_case_t) *cases;
    code_block_t *alternative;
} if_statement_t;

typedef struct while_loop_statement {
    expression_t *test;
    code_block_t *body;
} while_loop_statement_t;

typedef struct foreach_statement {
    ident_t iterator;
    expression_t *source;
    code_block_t *body;
} foreach_statement_t;

typedef struct for_loop_statement {
    statement_t *init;
    expression_t *test;
    expression_t *update;
    code_block_t *body;
} for_loop_statement_t;

typedef struct import_statement {
    char *path;
} import_statement_t;

typedef struct recover_statement {
    ident_t error_ident;
    code_block_t *body;
} recover_statement_t;

typedef struct statement {
    statement_type_t type;
    union {
        define_statement_t define;
        if_statement_t if_statement;
        expression_t *return_value;
        expression_t *expression;
        while_loop_statement_t while_loop;
        foreach_statement_t foreach;
        for_loop_statement_t for_loop;
        code_block_t *block;
        import_statement_t import;
        recover_statement_t recover;
    };
    src_pos_t pos;
} statement_t;

APE_INTERNAL char* statements_to_string(ptrarray(statement_t) *statements);

APE_INTERNAL statement_t* statement_make_define(ident_t name, expression_t *value, bool assignable);
APE_INTERNAL statement_t* statement_make_if(ptrarray(if_case_t) *cases, code_block_t *alternative);
APE_INTERNAL statement_t* statement_make_return(expression_t *value);
APE_INTERNAL statement_t* statement_make_expression(expression_t *value);
APE_INTERNAL statement_t* statement_make_while_loop(expression_t *test, code_block_t *body);
APE_INTERNAL statement_t* statement_make_break(void);
APE_INTERNAL statement_t* statement_make_foreach(ident_t iterator, expression_t *source, code_block_t *body);
APE_INTERNAL statement_t* statement_make_for_loop(statement_t *init, expression_t *test, expression_t *update, code_block_t *body);
APE_INTERNAL statement_t* statement_make_continue(void);
APE_INTERNAL statement_t* statement_make_block(code_block_t *block);
APE_INTERNAL statement_t* statement_make_import(char *path);
APE_INTERNAL statement_t* statement_make_recover(ident_t error_ident, code_block_t *body);

APE_INTERNAL void statement_destroy(statement_t *stmt);

APE_INTERNAL statement_t* statement_copy(statement_t *stmt);

APE_INTERNAL code_block_t* code_block_make(ptrarray(statement_t) *statements);
APE_INTERNAL void code_block_destroy(code_block_t *stmt);
APE_INTERNAL code_block_t* code_block_copy(code_block_t *block);

APE_INTERNAL expression_t* expression_make_ident(ident_t ident);
APE_INTERNAL expression_t* expression_make_number_literal(double val);
APE_INTERNAL expression_t* expression_make_bool_literal(bool val);
APE_INTERNAL expression_t* expression_make_string_literal(char *value);
APE_INTERNAL expression_t* expression_make_null_literal(void);
APE_INTERNAL expression_t* expression_make_array_literal(ptrarray(expression_t) *values);
APE_INTERNAL expression_t* expression_make_map_literal(ptrarray(expression_t) *keys, ptrarray(expression_t) *values);
APE_INTERNAL expression_t* expression_make_prefix(operator_t op, expression_t *right);
APE_INTERNAL expression_t* expression_make_infix(operator_t op, expression_t *left, expression_t *right);
APE_INTERNAL expression_t* expression_make_fn_literal(array(ident_t) *params, code_block_t *body);
APE_INTERNAL expression_t* expression_make_call(expression_t *function, ptrarray(expression_t) *args);
APE_INTERNAL expression_t* expression_make_index(expression_t *left, expression_t *index);
APE_INTERNAL expression_t* expression_make_assign(expression_t *dest, expression_t *source);
APE_INTERNAL expression_t* expression_make_logical(operator_t op, expression_t *left, expression_t *right);

APE_INTERNAL void expression_destroy(expression_t *expr);

APE_INTERNAL expression_t* expression_copy(expression_t *expr);

APE_INTERNAL void statement_to_string(const statement_t *stmt, strbuf_t *buf);
APE_INTERNAL void expression_to_string(expression_t *expr, strbuf_t *buf);

APE_INTERNAL void code_block_to_string(const code_block_t *stmt, strbuf_t *buf);
APE_INTERNAL const char* operator_to_string(operator_t op);

APE_INTERNAL const char *expression_type_to_string(expression_type_t type);

APE_INTERNAL void fn_literal_deinit(fn_literal_t *fn);

APE_INTERNAL ident_t ident_make(token_t tok);
APE_INTERNAL ident_t ident_copy(ident_t ident);
APE_INTERNAL void ident_deinit(ident_t *ident);

APE_INTERNAL if_case_t *if_case_make(expression_t *test, code_block_t *consequence);
APE_INTERNAL void if_case_destroy(if_case_t *cond);

#endif /* ast_h */
//FILE_END
//FILE_START:parser.h
#ifndef parser_h
#define parser_h

#ifndef APE_AMALGAMATED
#include "common.h"
#include "lexer.h"
#include "token.h"
#include "ast.h"
#include "collections.h"
#endif

typedef struct parser parser_t;
typedef struct error error_t;

typedef expression_t* (*prefix_parse_fn)(parser_t *p);
typedef expression_t* (*infix_parse_fn)(parser_t *p, expression_t *expr);

typedef struct parser {
    const ape_config_t *config;
    lexer_t lexer;
    token_t cur_token;
    token_t peek_token;
    ptrarray(error_t) *errors;

    prefix_parse_fn prefix_parse_fns[TOKEN_TYPE_MAX];
    infix_parse_fn infix_parse_fns[TOKEN_TYPE_MAX];

    int depth;
} parser_t;

APE_INTERNAL parser_t* parser_make(const ape_config_t *config, ptrarray(error_t) *errors);
APE_INTERNAL void parser_destroy(parser_t *parser);

APE_INTERNAL ptrarray(statement_t)* parser_parse_all(parser_t *parser,  const char *input, compiled_file_t *file);

#endif /* parser_h */
//FILE_END
//FILE_START:symbol_table.h
#ifndef symbol_table_h
#define symbol_table_h

#ifndef APE_AMALGAMATED
#include "common.h"
#include "token.h"
#include "collections.h"
#endif

typedef enum symbol_type {
    SYMBOL_NONE = 0,
    SYMBOL_GLOBAL,
    SYMBOL_LOCAL,
    SYMBOL_NATIVE_FUNCTION,
    SYMBOL_FREE,
    SYMBOL_FUNCTION,
    SYMBOL_THIS,
} symbol_type_t;

typedef struct symbol {
    symbol_type_t type;
    char *name;
    int index;
    bool assignable;
} symbol_t;

typedef struct block_scope {
    dict(symbol_t) *store;
    int offset;
    int num_definitions;
} block_scope_t;

typedef struct symbol_table {
    struct symbol_table *outer;
    ptrarray(block_scope_t) *block_scopes;
    ptrarray(symbol_t) *free_symbols;
    int max_num_definitions;
} symbol_table_t;

APE_INTERNAL symbol_t *symbol_make(const char *name, symbol_type_t type, int index, bool assignable);
APE_INTERNAL void symbol_destroy(symbol_t *symbol);
APE_INTERNAL symbol_t* symbol_copy(const symbol_t *symbol);

APE_INTERNAL symbol_table_t *symbol_table_make(symbol_table_t *outer);
APE_INTERNAL void symbol_table_destroy(symbol_table_t *st);
APE_INTERNAL symbol_table_t* symbol_table_copy(symbol_table_t *st);
APE_INTERNAL void symbol_table_add_module_symbol(symbol_table_t *st, const symbol_t *symbol);
APE_INTERNAL symbol_t *symbol_table_define(symbol_table_t *st, const char *name, bool assignable);
APE_INTERNAL symbol_t *symbol_table_define_native_function(symbol_table_t *st, const char *name, int ix);
APE_INTERNAL symbol_t *symbol_table_define_free(symbol_table_t *st, symbol_t *original);
APE_INTERNAL symbol_t *symbol_table_define_function_name(symbol_table_t *st, const char *name, bool assignable);
APE_INTERNAL symbol_t *symbol_table_define_this(symbol_table_t *st);

APE_INTERNAL symbol_t *symbol_table_resolve(symbol_table_t *st, const char *name);

APE_INTERNAL bool symbol_table_symbol_is_defined(symbol_table_t *st, const char *name);
APE_INTERNAL void symbol_table_push_block_scope(symbol_table_t *table);
APE_INTERNAL void symbol_table_pop_block_scope(symbol_table_t *table);
APE_INTERNAL block_scope_t* symbol_table_get_block_scope(symbol_table_t *table);

APE_INTERNAL bool symbol_table_is_global_scope(symbol_table_t *table);
APE_INTERNAL bool symbol_table_is_top_block_scope(symbol_table_t *table);
APE_INTERNAL bool symbol_table_is_top_global_scope(symbol_table_t *table);

#endif /* symbol_table_h */
//FILE_END
//FILE_START:code.h
#ifndef code_h
#define code_h

#include <stdint.h>

#ifndef APE_AMALGAMATED
#include "common.h"
#include "collections.h"
#endif

typedef uint8_t opcode_t;

typedef enum opcode_val {
    OPCODE_NONE = 0,
    OPCODE_CONSTANT,
    OPCODE_ADD,
    OPCODE_POP,
    OPCODE_SUB,
    OPCODE_MUL,
    OPCODE_DIV,
    OPCODE_MOD,
    OPCODE_TRUE,
    OPCODE_FALSE,
    OPCODE_COMPARE,
    OPCODE_EQUAL,
    OPCODE_NOT_EQUAL,
    OPCODE_GREATER_THAN,
    OPCODE_GREATER_THAN_EQUAL,
    OPCODE_MINUS,
    OPCODE_BANG,
    OPCODE_JUMP,
    OPCODE_JUMP_IF_FALSE,
    OPCODE_JUMP_IF_TRUE,
    OPCODE_NULL,
    OPCODE_GET_GLOBAL,
    OPCODE_SET_GLOBAL,
    OPCODE_DEFINE_GLOBAL,
    OPCODE_ARRAY,
    OPCODE_MAP_START,
    OPCODE_MAP_END,
    OPCODE_GET_THIS,
    OPCODE_GET_INDEX,
    OPCODE_SET_INDEX,
    OPCODE_GET_VALUE_AT,
    OPCODE_CALL,
    OPCODE_RETURN_VALUE,
    OPCODE_RETURN,
    OPCODE_GET_LOCAL,
    OPCODE_DEFINE_LOCAL,
    OPCODE_SET_LOCAL,
    OPCODE_GET_NATIVE_FUNCTION,
    OPCODE_FUNCTION,
    OPCODE_GET_FREE,
    OPCODE_SET_FREE,
    OPCODE_CURRENT_FUNCTION,
    OPCODE_DUP,
    OPCODE_NUMBER,
    OPCODE_LEN,
    OPCODE_SET_RECOVER,
    OPCODE_OR,
    OPCODE_XOR,
    OPCODE_AND,
    OPCODE_LSHIFT,
    OPCODE_RSHIFT,
    OPCODE_MAX,
} opcode_val_t;

typedef struct opcode_definition {
    const char *name;
    int num_operands;
    int operand_widths[2];
} opcode_definition_t;

APE_INTERNAL opcode_definition_t* opcode_lookup(opcode_t op);
APE_INTERNAL const char *opcode_get_name(opcode_t op);
APE_INTERNAL int code_make(opcode_t op, int operands_count, uint64_t *operands, array(uint8_t) *res);
APE_INTERNAL void code_to_string(uint8_t *code, src_pos_t *source_positions, size_t code_size, strbuf_t *res);
APE_INTERNAL bool code_read_operands(opcode_definition_t *def, uint8_t *instr, uint64_t out_operands[2]);

#endif /* code_h */
//FILE_END
//FILE_START:compilation_scope.h
#ifndef compilation_scope_h
#define compilation_scope_h

#ifndef APE_AMALGAMATED
#include "symbol_table.h"
#include "code.h"
#include "gc.h"
#endif

typedef struct compilation_result {
    uint8_t *bytecode;
    src_pos_t *src_positions;
    int count;
} compilation_result_t;

typedef struct compilation_scope {
    struct compilation_scope *outer;
    array(uint8_t) *bytecode;
    array(src_pos_t) *src_positions;
    opcode_t last_opcode;
} compilation_scope_t;

APE_INTERNAL compilation_scope_t* compilation_scope_make(compilation_scope_t *outer);
APE_INTERNAL void compilation_scope_destroy(compilation_scope_t *scope);
APE_INTERNAL compilation_result_t *compilation_scope_orphan_result(compilation_scope_t *scope);

APE_INTERNAL compilation_result_t* compilation_result_make(uint8_t *bytecode, src_pos_t *src_positions, int count);
APE_INTERNAL void compilation_result_destroy(compilation_result_t* res);

#endif /* compilation_scope_h */
//FILE_END
//FILE_START:compiler.h
#ifndef compiler_h
#define compiler_h

#ifndef APE_AMALGAMATED
#include "collections.h"
#include "common.h"
#include "parser.h"
#include "code.h"
#include "token.h"
#include "compilation_scope.h"
#endif

typedef struct ape_config ape_config_t;
typedef struct gcmem gcmem_t;
typedef struct symbol_table symbol_table_t;

typedef struct module {
    char *name;
    ptrarray(symbol_t) *symbols;
} module_t;

typedef struct compiled_file {
    char *dir_path;
    char *path;
    ptrarray(char*) *lines;
} compiled_file_t;

typedef struct file_scope {
    parser_t *parser;
    symbol_table_t *symbol_table;
    module_t *module;
    compiled_file_t *file;
    ptrarray(char) *loaded_module_names;
} file_scope_t;

typedef struct compiler {
    const ape_config_t *config;
    gcmem_t *mem;
    compilation_scope_t *compilation_scope;
    ptrarray(file_scope_t) *file_scopes;
    array(object_t) *constants;
    ptrarray(error_t) *errors;
    array(src_pos_t) *src_positions_stack;
    array(int) *break_ip_stack;
    array(int) *continue_ip_stack;
    dict(module_t) *modules;
    ptrarray(compiled_file_t) *files;
} compiler_t;

APE_INTERNAL compiler_t *compiler_make(const ape_config_t *config, gcmem_t *mem, ptrarray(error_t) *errors);
APE_INTERNAL void compiler_destroy(compiler_t *comp);
APE_INTERNAL compilation_result_t* compiler_compile(compiler_t *comp, const char *code);
APE_INTERNAL compilation_result_t* compiler_compile_file(compiler_t *comp, const char *path);
APE_INTERNAL int compiler_emit(compiler_t *comp, opcode_t op, int operands_count, uint64_t *operands);
APE_INTERNAL compilation_scope_t* compiler_get_compilation_scope(compiler_t *comp);
APE_INTERNAL void compiler_push_compilation_scope(compiler_t *comp);
APE_INTERNAL void compiler_pop_compilation_scope(compiler_t *comp);
APE_INTERNAL void compiler_push_symbol_table(compiler_t *comp);
APE_INTERNAL void compiler_pop_symbol_table(compiler_t *comp);
APE_INTERNAL symbol_table_t* compiler_get_symbol_table(compiler_t *comp);
APE_INTERNAL void compiler_set_symbol_table(compiler_t *comp, symbol_table_t *table);
APE_INTERNAL opcode_t compiler_last_opcode(compiler_t *comp);

#endif /* compiler_h */
//FILE_END
//FILE_START:object.h
#ifndef object_h
#define object_h

#include <stdint.h>

#ifndef APE_AMALGAMATED
#include "common.h"
#include "collections.h"
#include "ast.h"
#endif

typedef struct compilation_result compilation_result_t;
typedef struct traceback traceback_t;
typedef struct vm vm_t;
typedef struct gcmem gcmem_t;

#define OBJECT_STRING_BUF_SIZE 32

typedef enum {
    OBJECT_NONE      = 0,
    OBJECT_ERROR     = 1 << 0,
    OBJECT_NUMBER    = 1 << 1,
    OBJECT_BOOL      = 1 << 2,
    OBJECT_STRING    = 1 << 3,
    OBJECT_NULL      = 1 << 4,
    OBJECT_NATIVE_FUNCTION   = 1 << 5,
    OBJECT_ARRAY     = 1 << 6,
    OBJECT_MAP       = 1 << 7,
    OBJECT_FUNCTION  = 1 << 8,
    OBJECT_EXTERNAL  = 1 << 9,
    OBJECT_FREED     = 1 << 10,
    OBJECT_ANY       = 0xffff,
} object_type_t;

typedef struct object {
    union {
        uint64_t handle;
        double number;
    };
} object_t;

typedef struct function {
    union {
        object_t *free_vals_allocated;
        object_t free_vals_buf[2];
    };
    union {
        char *name;
        const char *const_name;
    };
    compilation_result_t *comp_result;
    int num_locals;
    int num_args;
    int free_vals_count;
    bool owns_data;
} function_t;

typedef object_t (*native_fn)(vm_t *vm, void *data, int argc, object_t *args);

typedef struct native_function {
    char *name;
    native_fn fn;
    void *data;
} native_function_t;

typedef void  (*external_data_destroy_fn)(void* data);
typedef void* (*external_data_copy_fn)(void* data);

typedef struct external_data {
    void *data;
    external_data_destroy_fn data_destroy_fn;
    external_data_copy_fn    data_copy_fn;
} external_data_t;

typedef struct object_error {
    char *message;
    traceback_t *traceback;
} object_error_t;

typedef struct object_string {
    union {
        char *value_allocated;
        char value_buf[OBJECT_STRING_BUF_SIZE];
    };
    unsigned long hash;
    bool is_allocated;
} object_string_t;

typedef struct object_data {
    gcmem_t *mem;
    union {
        object_string_t string;
        object_error_t error;
        array(object_t) *array;
        valdict(object_t, object_t) *map;
        function_t function;
        native_function_t native_function;
        external_data_t external;
    };
    bool gcmark;
    object_type_t type;
} object_data_t;

APE_INTERNAL object_t object_make_number(double val);
APE_INTERNAL object_t object_make_bool(bool val);
APE_INTERNAL object_t object_make_null(void);
APE_INTERNAL object_t object_make_string(gcmem_t *mem, const char *string);
APE_INTERNAL object_t object_make_string_no_copy(gcmem_t *mem, char *string);
APE_INTERNAL object_t object_make_stringf(gcmem_t *mem, const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
APE_INTERNAL object_t object_make_native_function(gcmem_t *mem, const char *name, native_fn fn, void *data);
APE_INTERNAL object_t object_make_array(gcmem_t *mem);
APE_INTERNAL object_t object_make_array_with_capacity(gcmem_t *mem, unsigned capacity);
APE_INTERNAL object_t object_make_array_with_array(gcmem_t *mem, array(object_t) *array);
APE_INTERNAL object_t object_make_map(gcmem_t *mem);
APE_INTERNAL object_t object_make_map_with_capacity(gcmem_t *mem, unsigned capacity);
APE_INTERNAL object_t object_make_error(gcmem_t *mem, const char *message);
APE_INTERNAL object_t object_make_error_no_copy(gcmem_t *mem, char *message);
APE_INTERNAL object_t object_make_errorf(gcmem_t *mem, const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
APE_INTERNAL object_t object_make_function(gcmem_t *mem, const char *name, compilation_result_t *comp_res,
                                           bool owns_data, int num_locals, int num_args,
                                           int free_vals_count);
APE_INTERNAL object_t object_make_external(gcmem_t *mem, void *data);

APE_INTERNAL void object_deinit(object_t obj);
APE_INTERNAL void object_data_deinit(object_data_t *obj);

APE_INTERNAL bool        object_is_allocated(object_t obj);
APE_INTERNAL gcmem_t*    object_get_mem(object_t obj);
APE_INTERNAL bool        object_is_hashable(object_t obj);
APE_INTERNAL void        object_to_string(object_t obj, strbuf_t *buf, bool quote_str);
APE_INTERNAL const char* object_get_type_name(const object_type_t type);
APE_INTERNAL char*       object_serialize(object_t object);
APE_INTERNAL object_t    object_deep_copy(gcmem_t *mem, object_t object);
APE_INTERNAL object_t    object_copy(gcmem_t *mem, object_t obj);
APE_INTERNAL double      object_compare(object_t a, object_t b);
APE_INTERNAL bool        object_equals(object_t a, object_t b);

APE_INTERNAL object_data_t* object_get_allocated_data(object_t object);

APE_INTERNAL bool           object_get_bool(object_t obj);
APE_INTERNAL double         object_get_number(object_t obj);
APE_INTERNAL function_t*    object_get_function(object_t obj);
APE_INTERNAL const char*    object_get_string(object_t obj);
APE_INTERNAL native_function_t*     object_get_native_function(object_t obj);
APE_INTERNAL object_type_t  object_get_type(object_t obj);

APE_INTERNAL bool object_is_numeric(object_t obj);
APE_INTERNAL bool object_is_null(object_t obj);
APE_INTERNAL bool object_is_callable(object_t obj);

APE_INTERNAL const char* object_get_function_name(object_t obj);
APE_INTERNAL object_t    object_get_function_free_val(object_t obj, int ix);
APE_INTERNAL void        object_set_function_free_val(object_t obj, int ix, object_t val);
APE_INTERNAL object_t*   object_get_function_free_vals(object_t obj);

APE_INTERNAL const char*  object_get_error_message(object_t obj);
APE_INTERNAL void         object_set_error_traceback(object_t obj, traceback_t *traceback);
APE_INTERNAL traceback_t* object_get_error_traceback(object_t obj);

APE_INTERNAL external_data_t* object_get_external_data(object_t object);
APE_INTERNAL bool object_set_external_destroy_function(object_t object, external_data_destroy_fn destroy_fn);
APE_INTERNAL bool object_set_external_copy_function(object_t object, external_data_copy_fn copy_fn);

APE_INTERNAL array(object_t)* object_get_array(object_t array);
APE_INTERNAL object_t         object_get_array_value_at(object_t array, int ix);
APE_INTERNAL bool             object_set_array_value_at(object_t obj, int ix, object_t val);
APE_INTERNAL bool             object_add_array_value(object_t array, object_t val);
APE_INTERNAL int              object_get_array_length(object_t array);

APE_INTERNAL int      object_get_map_length(object_t obj);
APE_INTERNAL object_t object_get_map_key_at(object_t obj, int ix);
APE_INTERNAL object_t object_get_map_value_at(object_t obj, int ix);
APE_INTERNAL bool     object_set_map_value_at(object_t obj, int ix, object_t val);
APE_INTERNAL object_t object_get_kv_pair_at(gcmem_t *mem, object_t obj, int ix);
APE_INTERNAL bool     object_set_map_value(object_t obj, object_t key, object_t val);
APE_INTERNAL object_t object_get_map_value(object_t obj, object_t key);
APE_INTERNAL bool     object_map_has_key(object_t obj, object_t key);

#endif /* object_h */
//FILE_END
//FILE_START:gc.h
#ifndef gc_h
#define gc_h

#ifndef APE_AMALGAMATED
#include "common.h"
#include "collections.h"
#include "object.h"
#endif

typedef struct object_data object_data_t;
typedef struct env env_t;

typedef struct gcmem gcmem_t;

APE_INTERNAL gcmem_t *gcmem_make(void);
APE_INTERNAL void gcmem_destroy(gcmem_t *mem);

APE_INTERNAL object_data_t* gcmem_alloc_object_data(gcmem_t *mem, object_type_t type);

APE_INTERNAL void gc_unmark_all(gcmem_t *mem);
APE_INTERNAL void gc_mark_objects(object_t *objects, int count);
APE_INTERNAL void gc_mark_object(object_t object);
APE_INTERNAL void gc_mark_object_data(object_data_t *data);
APE_INTERNAL void gc_sweep(gcmem_t *mem);

APE_INTERNAL void gc_disable_on_object(object_t obj);
APE_INTERNAL void gc_enable_on_object(object_t obj);

#endif /* gc_h */
//FILE_END
//FILE_START:builtins.h
#ifndef builtins_h
#define builtins_h

#include <stdint.h>

#ifndef APE_AMALGAMATED
#include "common.h"
#include "object.h"
#endif

typedef struct vm vm_t;

APE_INTERNAL int builtins_count(void);
APE_INTERNAL native_fn builtins_get_fn(int ix);
APE_INTERNAL const char* builtins_get_name(int ix);

#endif /* builtins_h */
//FILE_END
//FILE_START:traceback.h
#ifndef traceback_h
#define traceback_h

#ifndef APE_AMALGAMATED
#include "common.h"
#include "collections.h"
#endif

typedef struct vm vm_t;

typedef struct traceback_item {
    char *function_name;
    src_pos_t pos;
} traceback_item_t;

typedef struct traceback {
    array(traceback_item_t)* items;
} traceback_t;

APE_INTERNAL traceback_t* traceback_make(void);
APE_INTERNAL void traceback_destroy(traceback_t *traceback);
APE_INTERNAL void traceback_append(traceback_t *traceback, const char *function_name, src_pos_t pos);
APE_INTERNAL void traceback_append_from_vm(traceback_t *traceback, vm_t *vm);
APE_INTERNAL void traceback_to_string(const traceback_t *traceback, strbuf_t *buf);
APE_INTERNAL const char* traceback_item_get_line(traceback_item_t *item);
APE_INTERNAL const char* traceback_item_get_filepath(traceback_item_t *item);

#endif /* traceback_h */
//FILE_END
//FILE_START:frame.h
#ifndef frame_h
#define frame_h

#include <stdint.h>

#ifndef APE_AMALGAMATED
#include "common.h"
#include "object.h"
#include "collections.h"
#include "code.h"
#endif

typedef struct {
    object_t function;
    int ip;
    int base_pointer;
    const src_pos_t *src_positions;
    uint8_t *bytecode;
    int src_ip;
    int bytecode_size;
    int recover_ip;
    bool is_recovering;
} frame_t;

APE_INTERNAL bool frame_init(frame_t* frame, object_t function, int base_pointer);

APE_INTERNAL opcode_val_t frame_read_opcode(frame_t* frame);
APE_INTERNAL uint64_t frame_read_uint64(frame_t* frame);
APE_INTERNAL uint16_t frame_read_uint16(frame_t* frame);
APE_INTERNAL uint8_t frame_read_uint8(frame_t* frame);
APE_INTERNAL src_pos_t frame_src_position(const frame_t *frame);

#endif /* frame_h */
//FILE_END
//FILE_START:vm.h
#ifndef vm_h
#define vm_h

#ifndef APE_AMALGAMATED
#include "ape.h"
#include "common.h"
#include "ast.h"
#include "object.h"
#include "frame.h"
#include "error.h"
#endif

#define VM_STACK_SIZE 2048
#define VM_MAX_GLOBALS 2048
#define VM_MAX_FRAMES 2048
#define VM_THIS_STACK_SIZE 2048

typedef struct ape_config ape_config_t;
typedef struct compilation_result compilation_result_t;

typedef struct vm {
    const ape_config_t *config;
    gcmem_t *mem;
    object_t globals[VM_MAX_GLOBALS];
    int globals_count;
    array(object_t) *native_functions;
    object_t stack[VM_STACK_SIZE];
    int sp;
    object_t this_stack[VM_THIS_STACK_SIZE];
    int this_sp;
    frame_t frames[VM_MAX_FRAMES];
    int frames_count;
    ptrarray(error_t) *errors;
    object_t last_popped;
    frame_t *current_frame;
    bool running;
    error_t *runtime_error;
    object_t operator_oveload_keys[OPCODE_MAX];
} vm_t;

APE_INTERNAL vm_t* vm_make(const ape_config_t *config, gcmem_t *mem, ptrarray(error_t) *errors); // ape can be null (for internal testing purposes)
APE_INTERNAL void  vm_destroy(vm_t *vm);

APE_INTERNAL void  vm_reset(vm_t *vm);

APE_INTERNAL bool vm_run(vm_t *vm, compilation_result_t *comp_res, array(object_t) *constants);
APE_INTERNAL object_t vm_call(vm_t *vm, array(object_t) *constants, object_t callee, int argc, object_t *args);
APE_INTERNAL bool vm_execute_function(vm_t *vm, object_t function, array(object_t) *constants);

APE_INTERNAL object_t vm_get_last_popped(vm_t *vm);
APE_INTERNAL bool vm_has_errors(vm_t *vm);

APE_INTERNAL void vm_set_global(vm_t *vm, int ix, object_t val);
APE_INTERNAL object_t vm_get_global(vm_t *vm, int ix);

APE_INTERNAL void vm_set_runtime_error(vm_t *vm, error_t *error); // only allowed when vm is running

#endif /* vm_h */
//FILE_END

//-----------------------------------------------------------------------------
// C files
//-----------------------------------------------------------------------------
//FILE_START:common.c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef APE_AMALGAMATED
#include "common.h"
#endif

APE_INTERNAL const src_pos_t src_pos_invalid = { NULL, -1, -1 };
APE_INTERNAL const src_pos_t src_pos_zero = { NULL, 0, 0 };

APE_INTERNAL src_pos_t src_pos_make(const compiled_file_t *file, int line, int column) {
    return (src_pos_t) {
        .file = file,
        .line = line,
        .column = column,
    };
}

char *ape_stringf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int to_write = vsnprintf(NULL, 0, format, args);
    va_end(args);
    va_start(args, format);
    char *res = (char*)ape_malloc(to_write + 1, ape_mallocArg);
    int written = vsprintf(res, format, args);
    (void)written;
    APE_ASSERT(written == to_write);
    va_end(args);
    return res;
}

void ape_log(const char *file, int line, const char *format, ...) {
    char msg[4096];
    int written = snprintf(msg, APE_ARRAY_LEN(msg), "%s:%d: ", file, line);
    (void)written;
    va_list args;
    va_start(args, format);
    int written_msg = vsnprintf(msg + written, APE_ARRAY_LEN(msg) - written, format, args);
    (void)written_msg;
    va_end(args);

    APE_ASSERT(written_msg <= (APE_ARRAY_LEN(msg) - written));

    printf("%s", msg);
}

char* ape_strndup(const char *string, size_t n) {
    char *output_string = (char*)ape_malloc(n + 1, ape_mallocArg);
    if (!output_string) {
        return NULL;
    }
    output_string[n] = '\0';
    memcpy(output_string, string, n);
    return output_string;
}

char* ape_strdup(const char *string) {
    return ape_strndup(string, strlen(string));
}

uint64_t ape_double_to_uint64(double val) {
    union {
        uint64_t val_uint64;
        double val_double;
    } temp = {
        .val_double = val
    };
    return temp.val_uint64;
}

double ape_uint64_to_double(uint64_t val) {
    union {
        uint64_t val_uint64;
        double val_double;
    } temp = {
        .val_uint64 = val
    };
    return temp.val_double;
}
//FILE_END
//FILE_START:collections.c
/*
Copyright (c) 2020 Krzysztof Gabis
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef COLLECTIONS_AMALGAMATED
#include "collections.h"
#endif

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

#ifdef COLLECTIONS_DEBUG
#include <assert.h>
#define COLLECTIONS_ASSERT(x) assert(x)
#else
#define COLLECTIONS_ASSERT(x)
#endif

//-----------------------------------------------------------------------------
// Collections
//-----------------------------------------------------------------------------

#undef malloc
#undef free


static void* apeMalloc(size_t size, void* allocArgs) {
    return malloc(size);
}

static void apeFree(void* mem, void* freeArgs) {
    free(mem);
}

static char* collections_strndup(const char *string, size_t n);
static char* collections_strdup(const char *string);
static unsigned long collections_hash(const void *ptr, size_t len); /* djb2 */
static unsigned int upper_power_of_two(unsigned int v);

static collections_malloc_fn collections_malloc = apeMalloc;
static collections_free_fn collections_free = apeFree;

void collections_set_memory_functions(collections_malloc_fn malloc_fn, collections_free_fn free_fn) {
    collections_malloc = malloc_fn;
    collections_free = free_fn;
}

static char* collections_strndup(const char *string, size_t n) {
    char *output_string = (char*)collections_malloc(n + 1, ape_mallocArg);
    if (!output_string) {
        return NULL;
    }
    output_string[n] = '\0';
    memcpy(output_string, string, n);
    return output_string;
}

static char* collections_strdup(const char *string) {
    return collections_strndup(string, strlen(string));
}

static unsigned long collections_hash(const void *ptr, size_t len) { /* djb2 */
    const uint8_t *ptr_u8 = (const uint8_t*)ptr;
    unsigned long hash = 5381;
    for (size_t i = 0; i < len; i++) {
        uint8_t val = ptr_u8[i];
        hash = ((hash << 5) + hash) + val;
    }
    return hash;
}

static unsigned int upper_power_of_two(unsigned int v) {
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

//-----------------------------------------------------------------------------
// Dictionary
//-----------------------------------------------------------------------------

#define DICT_INVALID_IX UINT_MAX
#define DICT_INITIAL_SIZE 32

typedef struct dict_ {
    unsigned int *cells;
    unsigned long *hashes;
    char **keys;
    void **values;
    unsigned int *cell_ixs;
    unsigned int count;
    unsigned int item_capacity;
    unsigned int cell_capacity;
} dict_t_;

// Private declarations
static bool dict_init(dict_t_ *dict, unsigned int initial_capacity);
static void dict_deinit(dict_t_ *dict, bool free_keys);
static unsigned int dict_get_cell_ix(const dict_t_ *dict,
                                     const char *key,
                                     unsigned long hash,
                                     bool *out_found);
static unsigned long hash_string(const char *str);
static bool dict_grow_and_rehash(dict_t_ *dict);
static bool dict_set_internal(dict_t_ *dict, const char *ckey, char *mkey, void *value);

// Public
dict_t_* dict_make(void) {
    dict_t_ *dict = collections_malloc(sizeof(dict_t_), ape_mallocArg);
    if (dict == NULL) {
        return NULL;
    }
    bool succeeded = dict_init(dict, DICT_INITIAL_SIZE);
    if (succeeded == false) {
        collections_free(dict, ape_freeArg);
        return NULL;
    }
    return dict;
}

void dict_destroy(dict_t_ *dict) {
    if (dict == NULL) {
        return;
    }
    dict_deinit(dict, true);
    collections_free(dict, ape_freeArg);
}

void dict_destroy_with_items_(dict_t_ *dict, dict_item_destroy_fn destroy_fn) {
    if (dict == NULL) {
        return;
    }

    if (destroy_fn) {
        for (unsigned int i = 0; i < dict->count; i++) {
            destroy_fn(dict->values[i]);
        }
    }

    dict_destroy(dict);
}

dict_t_* dict_copy_with_items_(dict_t_ *dict, dict_item_copy_fn copy_fn) {
    dict_t_ *dict_copy = dict_make();
    for (int i = 0; i < dict_count(dict); i++) {
        const char *key = dict_get_key_at(dict, i);
        void *item = dict_get_value_at(dict, i);
        void *item_copy = copy_fn(item);
        dict_set(dict_copy, key, item_copy);
    }
    return dict_copy;
}

bool dict_set(dict_t_ *dict, const char *key, void *value) {
    return dict_set_internal(dict, key, NULL, value);
}

void* dict_get(const dict_t_ *dict, const char *key) {
    unsigned long hash = hash_string(key);
    bool found = false;
    unsigned long cell_ix = dict_get_cell_ix(dict, key, hash, &found);
    if (found == false) {
        return NULL;
    }
    unsigned int item_ix = dict->cells[cell_ix];
    return dict->values[item_ix];
}

void *dict_get_value_at(const dict_t_ *dict, unsigned int ix) {
    if (ix >= dict->count) {
        return NULL;
    }
    return dict->values[ix];
}

const char *dict_get_key_at(const dict_t_ *dict, unsigned int ix) {
    if (ix >= dict->count) {
        return NULL;
    }
    return dict->keys[ix];
}

int dict_count(const dict_t_ *dict) {
    if (!dict) {
        return 0;
    }
    return dict->count;
}

bool dict_remove(dict_t_ *dict, const char *key) {
    unsigned long hash = hash_string(key);
    bool found = false;
    unsigned int cell = dict_get_cell_ix(dict, key, hash, &found);
    if (!found) {
        return false;
    }

    unsigned int item_ix = dict->cells[cell];
    collections_free(dict->keys[item_ix], ape_freeArg);
    unsigned int last_item_ix = dict->count - 1;
    if (item_ix < last_item_ix) {
        dict->keys[item_ix] = dict->keys[last_item_ix];
        dict->values[item_ix] = dict->values[last_item_ix];
        dict->cell_ixs[item_ix] = dict->cell_ixs[last_item_ix];
        dict->hashes[item_ix] = dict->hashes[last_item_ix];
        dict->cells[dict->cell_ixs[item_ix]] = item_ix;
    }
    dict->count--;

    unsigned int i = cell;
    unsigned int j = i;
    for (unsigned int x = 0; x < (dict->cell_capacity - 1); x++) {
        j = (j + 1) & (dict->cell_capacity - 1);
        if (dict->cells[j] == DICT_INVALID_IX) {
            break;
        }
        unsigned int k = dict->hashes[dict->cells[j]] & (dict->cell_capacity - 1);
        if ((j > i && (k <= i || k > j))
            || (j < i && (k <= i && k > j))) {
            dict->cell_ixs[dict->cells[j]] = i;
            dict->cells[i] = dict->cells[j];
            i = j;
        }
    }
    dict->cells[i] = DICT_INVALID_IX;
    return true;
}

void dict_clear(dict_t_ *dict) {
    for (unsigned int i = 0; i < dict->count; i++) {
        collections_free(dict->keys[i], ape_freeArg);
    }
    dict->count = 0;
    for (unsigned int i = 0; i < dict->cell_capacity; i++) {
        dict->cells[i] = DICT_INVALID_IX;
    }
}

// Private definitions
static bool dict_init(dict_t_ *dict, unsigned int initial_capacity) {
    dict->cells = NULL;
    dict->keys = NULL;
    dict->values = NULL;
    dict->cell_ixs = NULL;
    dict->hashes = NULL;

    dict->count = 0;
    dict->cell_capacity = initial_capacity;
    dict->item_capacity = (unsigned int)(initial_capacity * 0.7f);

    dict->cells = collections_malloc(dict->cell_capacity * sizeof(*dict->cells), ape_mallocArg);
    dict->keys = collections_malloc(dict->item_capacity * sizeof(*dict->keys), ape_mallocArg);
    dict->values = collections_malloc(dict->item_capacity * sizeof(*dict->values), ape_mallocArg);
    dict->cell_ixs = collections_malloc(dict->item_capacity * sizeof(*dict->cell_ixs), ape_mallocArg);
    dict->hashes = collections_malloc(dict->item_capacity * sizeof(*dict->hashes), ape_mallocArg);
    if (dict->cells == NULL
        || dict->keys == NULL
        || dict->values == NULL
        || dict->cell_ixs == NULL
        || dict->hashes == NULL) {
        goto error;
    }
    for (unsigned int i = 0; i < dict->cell_capacity; i++) {
        dict->cells[i] = DICT_INVALID_IX;
    }
    return true;
error:
    collections_free(dict->cells, ape_freeArg);
    collections_free(dict->keys, ape_freeArg);
    collections_free(dict->values, ape_freeArg);
    collections_free(dict->cell_ixs, ape_freeArg);
    collections_free(dict->hashes, ape_freeArg);
    return false;
}

static void dict_deinit(dict_t_ *dict, bool free_keys) {
    if (free_keys) {
        for (unsigned int i = 0; i < dict->count; i++) {
            collections_free(dict->keys[i], ape_freeArg);
        }
    }
    dict->count = 0;
    dict->item_capacity = 0;
    dict->cell_capacity = 0;

    collections_free(dict->cells, ape_freeArg);
    collections_free(dict->keys, ape_freeArg);
    collections_free(dict->values, ape_freeArg);
    collections_free(dict->cell_ixs, ape_freeArg);
    collections_free(dict->hashes, ape_freeArg);

    dict->cells = NULL;
    dict->keys = NULL;
    dict->values = NULL;
    dict->cell_ixs = NULL;
    dict->hashes = NULL;
}

static unsigned int dict_get_cell_ix(const dict_t_ *dict,
                                     const char *key,
                                     unsigned long hash,
                                     bool *out_found)
{
    *out_found = false;
    unsigned int cell_ix = hash & (dict->cell_capacity - 1);
    for (unsigned int i = 0; i < dict->cell_capacity; i++) {
        unsigned int ix = (cell_ix + i) & (dict->cell_capacity - 1);
        unsigned int cell = dict->cells[ix];
        if (cell == DICT_INVALID_IX) {
            return ix;
        }
        unsigned long hash_to_check = dict->hashes[cell];
        if (hash != hash_to_check) {
            continue;
        }
        const char *key_to_check = dict->keys[cell];
        if (strcmp(key, key_to_check) == 0) {
            *out_found = true;
            return ix;
        }
    }
    return DICT_INVALID_IX;
}

static unsigned long hash_string(const char *str) { /* djb2 */
    unsigned long hash = 5381;
    uint8_t c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

static bool dict_grow_and_rehash(dict_t_ *dict) {
    dict_t_ new_dict;
    bool succeeded = dict_init(&new_dict, dict->cell_capacity * 2);
    if (succeeded == false) {
        return false;
    }
    for (unsigned int i = 0; i < dict->count; i++) {
        char *key = dict->keys[i];
        void *value = dict->values[i];
        succeeded = dict_set_internal(&new_dict, key, key, value);
        if (succeeded == false) {
            dict_deinit(&new_dict, false);
            return false;
        }
    }
    dict_deinit(dict, false);
    *dict = new_dict;
    return true;
}

static bool dict_set_internal(dict_t_ *dict, const char *ckey, char *mkey, void *value) {
    unsigned long hash = hash_string(ckey);
    bool found = false;
    unsigned int cell_ix = dict_get_cell_ix(dict, ckey, hash, &found);
    if (found) {
        unsigned int item_ix = dict->cells[cell_ix];
        dict->values[item_ix] = value;
        return true;
    }
    if (dict->count >= dict->item_capacity) {
        bool succeeded = dict_grow_and_rehash(dict);
        if (succeeded == false) {
            return false;
        }
        cell_ix = dict_get_cell_ix(dict, ckey, hash, &found);
    }
    dict->cells[cell_ix] = dict->count;
    dict->keys[dict->count] = mkey != NULL ? mkey : collections_strdup(ckey);
    dict->values[dict->count] = value;
    dict->cell_ixs[dict->count] = cell_ix;
    dict->hashes[dict->count] = hash;
    dict->count++;
    return true;
}
//-----------------------------------------------------------------------------
// Value dictionary
//-----------------------------------------------------------------------------
#define VALDICT_INVALID_IX UINT_MAX

typedef struct valdict_ {
    size_t key_size;
    size_t val_size;
    unsigned int *cells;
    unsigned long *hashes;
    void *keys;
    void *values;
    unsigned int *cell_ixs;
    unsigned int count;
    unsigned int item_capacity;
    unsigned int cell_capacity;
    collections_hash_fn _hash_key;
    collections_equals_fn _keys_equals;
} valdict_t_;

// Private declarations
static bool valdict_init(valdict_t_ *dict, size_t key_size, size_t val_size, unsigned int initial_capacity);
static void valdict_deinit(valdict_t_ *dict);
static unsigned int valdict_get_cell_ix(const valdict_t_ *dict,
                                        const void *key,
                                        unsigned long hash,
                                        bool *out_found);
static bool valdict_grow_and_rehash(valdict_t_ *dict);
static bool valdict_set_key_at(valdict_t_ *dict, unsigned int ix, void *key);
static bool valdict_keys_are_equal(const valdict_t_ *dict, const void *a, const void *b);
static unsigned long valdict_hash_key(const valdict_t_ *dict, const void *key);

// Public
valdict_t_* valdict_make_(size_t key_size, size_t val_size) {
    return valdict_make_with_capacity(DICT_INITIAL_SIZE, key_size, val_size);
}

valdict_t_* valdict_make_with_capacity(unsigned int min_capacity, size_t key_size, size_t val_size) {
    unsigned int capacity = upper_power_of_two(min_capacity * 2);

    valdict_t_ *dict = collections_malloc(sizeof(valdict_t_), ape_mallocArg);
    if (dict == NULL) {
        return NULL;
    }
    bool succeeded = valdict_init(dict, key_size, val_size, capacity);
    if (succeeded == false) {
        collections_free(dict, ape_freeArg);
        return NULL;
    }
    return dict;
}

void valdict_destroy(valdict_t_ *dict) {
    if (dict == NULL) {
        return;
    }
    valdict_deinit(dict);
    collections_free(dict, ape_freeArg);
}

void  valdict_set_hash_function(valdict_t_ *dict, collections_hash_fn hash_fn) {
    dict->_hash_key = hash_fn;
}

void valdict_set_equals_function(valdict_t_ *dict, collections_equals_fn equals_fn) {
    dict->_keys_equals = equals_fn;
}

bool valdict_set(valdict_t_ *dict, void *key, void *value) {
    unsigned long hash = valdict_hash_key(dict, key);
    bool found = false;
    unsigned int cell_ix = valdict_get_cell_ix(dict, key, hash, &found);
    if (found) {
        unsigned int item_ix = dict->cells[cell_ix];
        valdict_set_value_at(dict, item_ix, value);
        return true;
    }
    if (dict->count >= dict->item_capacity) {
        bool succeeded = valdict_grow_and_rehash(dict);
        if (succeeded == false) {
            return false;
        }
        cell_ix = valdict_get_cell_ix(dict, key, hash, &found);
    }
    unsigned int last_ix = dict->count;
    dict->count++;
    dict->cells[cell_ix] = last_ix;
    valdict_set_key_at(dict, last_ix, key);
    valdict_set_value_at(dict, last_ix, value);
    dict->cell_ixs[last_ix] = cell_ix;
    dict->hashes[last_ix] = hash;
    return true;
}

void* valdict_get(const valdict_t_ *dict, const void *key) {
    unsigned long hash = valdict_hash_key(dict, key);
    bool found = false;
    unsigned long cell_ix = valdict_get_cell_ix(dict, key, hash, &found);
    if (found == false) {
        return NULL;
    }
    unsigned int item_ix = dict->cells[cell_ix];
    return valdict_get_value_at(dict, item_ix);
}

void* valdict_get_key_at(const valdict_t_ *dict, unsigned int ix) {
    if (ix >= dict->count) {
        return NULL;
    }
    return (char*)dict->keys + (dict->key_size * ix);
}

void *valdict_get_value_at(const valdict_t_ *dict, unsigned int ix) {
    if (ix >= dict->count) {
        return NULL;
    }
    return (char*)dict->values + (dict->val_size * ix);
}

bool valdict_set_value_at(const valdict_t_ *dict, unsigned int ix, const void *value) {
    if (ix >= dict->count) {
        return false;
    }
    size_t offset = ix * dict->val_size;
    memcpy((char*)dict->values + offset, value, dict->val_size);
    return true;
}

int valdict_count(const valdict_t_ *dict) {
    if (!dict) {
        return 0;
    }
    return dict->count;
}

bool valdict_remove(valdict_t_ *dict, void *key) {
    unsigned long hash = valdict_hash_key(dict, key);
    bool found = false;
    unsigned int cell = valdict_get_cell_ix(dict, key, hash, &found);
    if (!found) {
        return false;
    }

    unsigned int item_ix = dict->cells[cell];
    unsigned int last_item_ix = dict->count - 1;
    if (item_ix < last_item_ix) {
        void *last_key = valdict_get_key_at(dict, last_item_ix);
        valdict_set_key_at(dict, item_ix, last_key);
        void *last_value = valdict_get_key_at(dict, last_item_ix);
        valdict_set_value_at(dict, item_ix, last_value);
        dict->cell_ixs[item_ix] = dict->cell_ixs[last_item_ix];
        dict->hashes[item_ix] = dict->hashes[last_item_ix];
        dict->cells[dict->cell_ixs[item_ix]] = item_ix;
    }
    dict->count--;

    unsigned int i = cell;
    unsigned int j = i;
    for (unsigned int x = 0; x < (dict->cell_capacity - 1); x++) {
        j = (j + 1) & (dict->cell_capacity - 1);
        if (dict->cells[j] == VALDICT_INVALID_IX) {
            break;
        }
        unsigned int k = dict->hashes[dict->cells[j]] & (dict->cell_capacity - 1);
        if ((j > i && (k <= i || k > j))
            || (j < i && (k <= i && k > j))) {
            dict->cell_ixs[dict->cells[j]] = i;
            dict->cells[i] = dict->cells[j];
            i = j;
        }
    }
    dict->cells[i] = VALDICT_INVALID_IX;
    return true;
}

void valdict_clear(valdict_t_ *dict) {
    dict->count = 0;
    for (unsigned int i = 0; i < dict->cell_capacity; i++) {
        dict->cells[i] = VALDICT_INVALID_IX;
    }
}

// Private definitions
static bool valdict_init(valdict_t_ *dict, size_t key_size, size_t val_size, unsigned int initial_capacity) {
    dict->key_size = key_size;
    dict->val_size = val_size;
    dict->cells = NULL;
    dict->keys = NULL;
    dict->values = NULL;
    dict->cell_ixs = NULL;
    dict->hashes = NULL;

    dict->count = 0;
    dict->cell_capacity = initial_capacity;
    dict->item_capacity = (unsigned int)(initial_capacity * 0.7f);

    dict->_keys_equals = NULL;
    dict->_hash_key = NULL;

    dict->cells = collections_malloc(dict->cell_capacity * sizeof(*dict->cells), ape_mallocArg);
    dict->keys = collections_malloc(dict->item_capacity * key_size, ape_mallocArg);
    dict->values = collections_malloc(dict->item_capacity * val_size, ape_mallocArg);
    dict->cell_ixs = collections_malloc(dict->item_capacity * sizeof(*dict->cell_ixs), ape_mallocArg);
    dict->hashes = collections_malloc(dict->item_capacity * sizeof(*dict->hashes), ape_mallocArg);
    if (dict->cells == NULL
        || dict->keys == NULL
        || dict->values == NULL
        || dict->cell_ixs == NULL
        || dict->hashes == NULL) {
        goto error;
    }
    for (unsigned int i = 0; i < dict->cell_capacity; i++) {
        dict->cells[i] = VALDICT_INVALID_IX;
    }
    return true;
error:
    collections_free(dict->cells, ape_freeArg);
    collections_free(dict->keys, ape_freeArg);
    collections_free(dict->values, ape_freeArg);
    collections_free(dict->cell_ixs, ape_freeArg);
    collections_free(dict->hashes, ape_freeArg);
    return false;
}

static void valdict_deinit(valdict_t_ *dict) {
    dict->key_size = 0;
    dict->val_size = 0;
    dict->count = 0;
    dict->item_capacity = 0;
    dict->cell_capacity = 0;

    collections_free(dict->cells, ape_freeArg);
    collections_free(dict->keys, ape_freeArg);
    collections_free(dict->values, ape_freeArg);
    collections_free(dict->cell_ixs, ape_freeArg);
    collections_free(dict->hashes, ape_freeArg);

    dict->cells = NULL;
    dict->keys = NULL;
    dict->values = NULL;
    dict->cell_ixs = NULL;
    dict->hashes = NULL;
}

static unsigned int valdict_get_cell_ix(const valdict_t_ *dict,
                                        const void *key,
                                        unsigned long hash,
                                        bool *out_found)
{
    *out_found = false;
    unsigned int cell_ix = hash & (dict->cell_capacity - 1);
    for (unsigned int i = 0; i < dict->cell_capacity; i++) {
        unsigned int ix = (cell_ix + i) & (dict->cell_capacity - 1);
        unsigned int cell = dict->cells[ix];
        if (cell == VALDICT_INVALID_IX) {
            return ix;
        }
        unsigned long hash_to_check = dict->hashes[cell];
        if (hash != hash_to_check) {
            continue;
        }
        void *key_to_check = valdict_get_key_at(dict, cell);
        bool are_equal = valdict_keys_are_equal(dict, key, key_to_check);
        if (are_equal) {
            *out_found = true;
            return ix;
        }
    }
    return VALDICT_INVALID_IX;
}

static bool valdict_grow_and_rehash(valdict_t_ *dict) {
    valdict_t_ new_dict;
    unsigned new_capacity = dict->cell_capacity == 0 ? DICT_INITIAL_SIZE : dict->cell_capacity * 2;
    bool succeeded = valdict_init(&new_dict, dict->key_size, dict->val_size, new_capacity);
    if (succeeded == false) {
        return false;
    }
    new_dict._keys_equals = dict->_keys_equals;
    new_dict._hash_key = dict->_hash_key;
    for (unsigned int i = 0; i < dict->count; i++) {
        char *key = valdict_get_key_at(dict, i);
        void *value = valdict_get_value_at(dict, i);
        succeeded = valdict_set(&new_dict, key, value);
        if (succeeded == false) {
            valdict_deinit(&new_dict);
            return false;
        }
    }
    valdict_deinit(dict);
    *dict = new_dict;
    return true;
}

static bool valdict_set_key_at(valdict_t_ *dict, unsigned int ix, void *key) {
    if (ix >= dict->count) {
        return false;
    }
    size_t offset = ix * dict->key_size;
    memcpy((char*)dict->keys + offset, key, dict->key_size);
    return true;
}

static bool valdict_keys_are_equal(const valdict_t_ *dict, const void *a, const void *b) {
    if (dict->_keys_equals) {
        return dict->_keys_equals(a, b);
    } else {
        return memcmp(a, b, dict->key_size) == 0;
    }
}

static unsigned long valdict_hash_key(const valdict_t_ *dict, const void *key) {
    if (dict->_hash_key) {
        return dict->_hash_key(key);
    } else {
        return collections_hash(key, dict->key_size);
    }
}

//-----------------------------------------------------------------------------
// Pointer dictionary
//-----------------------------------------------------------------------------
typedef struct ptrdict_ {
    valdict_t_ vd;
} ptrdict_t_;

// Public
ptrdict_t_* ptrdict_make(void) {
    ptrdict_t_ *dict = collections_malloc(sizeof(ptrdict_t_), ape_mallocArg);
    if (dict == NULL) {
        return NULL;
    }
    bool succeeded = valdict_init(&dict->vd, sizeof(void*), sizeof(void*), DICT_INITIAL_SIZE);
    if (succeeded == false) {
        collections_free(dict, ape_freeArg);
        return NULL;
    }
    return dict;
}

void ptrdict_destroy(ptrdict_t_ *dict) {
    if (dict == NULL) {
        return;
    }
    valdict_deinit(&dict->vd);
    collections_free(dict, ape_freeArg);
}

void  ptrdict_set_hash_function(ptrdict_t_ *dict, collections_hash_fn hash_fn) {
    valdict_set_hash_function(&dict->vd, hash_fn);
}

void ptrdict_set_equals_function(ptrdict_t_ *dict, collections_equals_fn equals_fn) {
    valdict_set_equals_function(&dict->vd, equals_fn);
}

bool ptrdict_set(ptrdict_t_ *dict, void *key, void *value) {
    return valdict_set(&dict->vd, &key, &value);
}

void* ptrdict_get(const ptrdict_t_ *dict, const void *key) {
    void* res = valdict_get(&dict->vd, &key);
    if (!res) {
        return NULL;
    }
    return *(void**)res;
}

void* ptrdict_get_value_at(const ptrdict_t_ *dict, unsigned int ix) {
    void* res = valdict_get_value_at(&dict->vd, ix);
    if (!res) {
        return NULL;
    }
    return *(void**)res;
}

void* ptrdict_get_key_at(const ptrdict_t_ *dict, unsigned int ix) {
    void* res = valdict_get_key_at(&dict->vd, ix);
    if (!res) {
        return NULL;
    }
    return *(void**)res;
}

int ptrdict_count(const ptrdict_t_ *dict) {
    return valdict_count(&dict->vd);
}

bool ptrdict_remove(ptrdict_t_ *dict, void *key) {
    return valdict_remove(&dict->vd, &key);
}

void ptrdict_clear(ptrdict_t_ *dict) {
    valdict_clear(&dict->vd);
}

//-----------------------------------------------------------------------------
// Array
//-----------------------------------------------------------------------------

typedef struct array_ {
    unsigned char *data;
    unsigned int count;
    unsigned int capacity;
    size_t element_size;
    bool lock_capacity;
} array_t_;

static bool array_init_with_capacity(array_t_ *arr, unsigned int capacity, size_t element_size);
static void array_deinit(array_t_ *arr);

array_t_* array_make_(size_t element_size) {
    return array_make_with_capacity(32, element_size);
}

array_t_* array_make_with_capacity(unsigned int capacity, size_t element_size) {
    array_t_ *arr = collections_malloc(sizeof(array_t_), ape_mallocArg);
    if (arr == NULL) {
        return NULL;
    }
    bool succeeded = array_init_with_capacity(arr, capacity, element_size);
    if (succeeded == false) {
        collections_free(arr, ape_freeArg);
        return NULL;
    }
    return arr;
}

void array_destroy(array_t_ *arr) {
    if (arr == NULL) {
        return;
    }
    array_deinit(arr);
    collections_free(arr, ape_freeArg);
}

void array_destroy_with_items_(array_t_ *arr, array_item_deinit_fn deinit_fn) {
    for (int i = 0; i < array_count(arr); i++) {
        void *item = array_get(arr, i);
        deinit_fn(item);
    }
    array_destroy(arr);
}

array_t_* array_copy(const array_t_ *arr) {
    array_t_ *copy = collections_malloc(sizeof(array_t_), ape_mallocArg);
    if (!copy) {
        return NULL;
    }
    copy->capacity = arr->capacity;
    copy->count = arr->count;
    copy->element_size = arr->element_size;
    copy->lock_capacity = arr->lock_capacity;
    copy->data = collections_malloc(arr->capacity * arr->element_size, ape_mallocArg);
    memcpy(copy->data, arr->data, arr->capacity * arr->element_size);
    if (!copy->data) {
        collections_free(copy, ape_freeArg);
        return NULL;
    }
    return copy;
}


bool array_add(array_t_ *arr, const void *value) {
    if (arr->count >= arr->capacity) {
        COLLECTIONS_ASSERT(!arr->lock_capacity);
        if (arr->lock_capacity) {
            return false;
        }
        unsigned int new_capacity = arr->capacity > 0 ? arr->capacity * 2 : 1;
        unsigned char *new_data = collections_malloc(new_capacity * arr->element_size, ape_mallocArg);
        if (new_data == NULL) {
            return false;
        }
        memcpy(new_data, arr->data, arr->count * arr->element_size);
        collections_free(arr->data, ape_freeArg);
        arr->data = new_data;
        arr->capacity = new_capacity;
    }
    if (value) {
        memcpy(arr->data + (arr->count * arr->element_size), value, arr->element_size);
    }
    arr->count++;
    return true;
}

bool array_addn(array_t_ *arr, const void *values, int n) {
    for (int i = 0; i < n; i++) {
        const uint8_t *value = NULL;
        if (values) {
            value = (const uint8_t*)values + (i * arr->element_size);
        }
        bool ok = array_add(arr, value);
        if (!ok) {
            return false;
        }
    }
    return true;
}

bool array_add_array(array_t_ *dest, const array_t_ *source) {
    COLLECTIONS_ASSERT(dest->element_size == source->element_size);
    if (dest->element_size != source->element_size) {
        return false;
    }
    for (int i = 0; i < array_count(source); i++) {
        void *item = array_get(source, i);
        bool ok = array_add(dest, item);
        if (!ok) {
            return false;
        }
    }
    return true;
}

bool array_push(array_t_ *arr, const void *value) {
    return array_add(arr, value);
}

bool array_pop(array_t_ *arr, void *out_value) {
    if (arr->count <= 0) {
        return false;
    }
    if (out_value) {
        void *res = array_get(arr, arr->count - 1);
        memcpy(out_value, res, arr->element_size);
    }
    array_remove_at(arr, arr->count - 1);
    return true;
}

void* array_top(array_t_ *arr) {
    if (arr->count <= 0) {
        return NULL;
    }
    return array_get(arr, arr->count - 1);
}

bool array_set(array_t_ *arr, unsigned int ix, void *value) {
    if (ix >= arr->count) {
        COLLECTIONS_ASSERT(false);
        return false;
    }
    size_t offset = ix * arr->element_size;
    memmove(arr->data + offset, value, arr->element_size);
    return true;
}

bool array_setn(array_t_ *arr, unsigned int ix, void *values, int n) {
    for (int i = 0; i < n; i++) {
        int dest_ix = ix + i;
        unsigned char *value = (unsigned char*)values + (i * arr->element_size);
        if (dest_ix < array_count(arr)) {
            bool ok = array_set(arr, dest_ix, value);
            if (!ok) {
                return false;
            }
        } else {
            bool ok = array_add(arr, value);
            if (!ok) {
                return false;
            }
        }
    }
    return true;
}

void * array_get(const array_t_ *arr, unsigned int ix) {
    if (ix >= arr->count) {
        COLLECTIONS_ASSERT(false);
        return NULL;
    }
    size_t offset = ix * arr->element_size;
    return arr->data + offset;
}

void * array_get_last(const array_t_ *arr) {
    if (arr->count <= 0) {
        return NULL;
    }
    return array_get(arr, arr->count - 1);
}

int array_count(const array_t_ *arr) {
    if (!arr) {
        return 0;
    }
    return arr->count;
}

bool array_remove_at(array_t_ *arr, unsigned int ix) {
    if (ix >= arr->count) {
        return false;
    }
    if (ix == (arr->count - 1)) {
        arr->count--;
        return true;
    }
    size_t to_move_bytes = (arr->count - 1 - ix) * arr->element_size;
    void *dest = arr->data + (ix * arr->element_size);
    void *src = arr->data + ((ix + 1) * arr->element_size);
    memmove(dest, src, to_move_bytes);
    arr->count--;
    return true;
}

bool array_remove_item(array_t_ *arr, void *ptr) {
    int ix = array_get_index(arr, ptr);
    if (ix < 0) {
        return false;
    }
    return array_remove_at(arr, ix);
}

void array_clear(array_t_ *arr) {
    arr->count = 0;
}

void array_clear_and_deinit_items_(array_t_ *arr, array_item_deinit_fn deinit_fn) {
    for (int i = 0; i < array_count(arr); i++) {
        void *item = array_get(arr, i);
        deinit_fn(item);
    }
    arr->count = 0;
}

void array_lock_capacity(array_t_ *arr) {
    arr->lock_capacity = true;
}

int array_get_index(const array_t_ *arr, void *ptr) {
    for (int i = 0; i < array_count(arr); i++) {
        if (array_get(arr, i) == ptr) {
            return i;
        }
    }
    return -1;
}

bool array_contains(const array_t_ *arr, void *ptr) {
    return array_get_index(arr, ptr) >= 0;
}

void* array_data(array_t_ *arr) {
    return arr->data;
}

const void*  array_const_data(const array_t_ *arr) {
    return arr->data;
}

bool array_orphan_data(array_t_ *arr) {
    return array_init_with_capacity(arr, 0, arr->element_size);
}

void array_reverse(array_t_ *arr) {
    int count = array_count(arr);
    if (count < 2) {
        return;
    }
    void *temp = collections_malloc(arr->element_size, ape_mallocArg);
    for (int a_ix = 0; a_ix < (count / 2); a_ix++) {
        int b_ix = count - a_ix - 1;
        void *a = array_get(arr, a_ix);
        void *b = array_get(arr, b_ix);
        memcpy(temp, a, arr->element_size);
        array_set(arr, a_ix, b);
        array_set(arr, b_ix, temp);
    }
    collections_free(temp, ape_freeArg);
}

static bool array_init_with_capacity(array_t_ *arr, unsigned int capacity, size_t element_size) {
    if (capacity > 0) {
        arr->data = collections_malloc(capacity * element_size, ape_mallocArg);
        if (arr->data == NULL) {
            return false;
        }
    } else {
        arr->data = NULL;
    }
    arr->capacity = capacity;
    arr->count = 0;
    arr->element_size = element_size;
    arr->lock_capacity = false;
    return true;
}

static void array_deinit(array_t_ *arr) {
    collections_free(arr->data, ape_freeArg);
}

//-----------------------------------------------------------------------------
// Pointer Array
//-----------------------------------------------------------------------------

typedef struct ptrarray_ {
    array_t_ arr;
} ptrarray_t_;

ptrarray_t_* ptrarray_make(void) {
    return ptrarray_make_with_capacity(0);
}

ptrarray_t_* ptrarray_make_with_capacity(unsigned int capacity) {
    ptrarray_t_ *ptrarr = collections_malloc(sizeof(ptrarray_t_), ape_mallocArg);
    if (ptrarr == NULL) {
        return NULL;
    }
    bool succeeded = array_init_with_capacity(&ptrarr->arr, capacity, sizeof(void*));
    if (succeeded == false) {
        collections_free(ptrarr, ape_freeArg);
        return NULL;
    }
    return ptrarr;
}

void ptrarray_destroy(ptrarray_t_ *arr) {
    if (arr == NULL) {
        return;
    }
    array_deinit(&arr->arr);
    collections_free(arr, ape_freeArg);
}

void ptrarray_destroy_with_items_(ptrarray_t_ *arr, ptrarray_item_destroy_fn destroy_fn){
    if (arr == NULL) {
        return;
    }

    if (destroy_fn) {
        ptrarray_clear_and_destroy_items_(arr, destroy_fn);
    }

    ptrarray_destroy(arr);
}

ptrarray_t_* ptrarray_copy(ptrarray_t_ *arr) {
    ptrarray_t_ *arr_copy = ptrarray_make_with_capacity(arr->arr.capacity);
    for (int i = 0; i < ptrarray_count(arr); i++) {
        void *item = ptrarray_get(arr, i);
        ptrarray_add(arr_copy, item);
    }
    return arr_copy;
}

ptrarray_t_* ptrarray_copy_with_items_(ptrarray_t_ *arr, ptrarray_item_copy_fn copy_fn) {
    ptrarray_t_ *arr_copy = ptrarray_make_with_capacity(arr->arr.capacity);
    for (int i = 0; i < ptrarray_count(arr); i++) {
        void *item = ptrarray_get(arr, i);
        void *item_copy = copy_fn(item);
        ptrarray_add(arr_copy, item_copy);
    }
    return arr_copy;
}

bool ptrarray_add(ptrarray_t_ *arr, void *ptr) {
    return array_add(&arr->arr, &ptr);
}

bool ptrarray_set(ptrarray_t_ *arr, unsigned int ix, void *ptr) {
    return array_set(&arr->arr, ix, &ptr);
}

bool ptrarray_add_array(ptrarray_t_ *dest, const ptrarray_t_ *source) {
    return array_add_array(&dest->arr, &source->arr);
}

void * ptrarray_get(ptrarray_t_ *arr, unsigned int ix) {
    void* res = array_get(&arr->arr, ix);
    if (!res) {
        return NULL;
    }
    return *(void**)res;
}

bool ptrarray_push(ptrarray_t_ *arr, void *ptr) {
    return ptrarray_add(arr, ptr);
}

void *ptrarray_pop(ptrarray_t_ *arr) {
    int ix = ptrarray_count(arr) - 1;
    void *res = ptrarray_get(arr, ix);
    ptrarray_remove_at(arr, ix);
    return res;
}

void *ptrarray_top(ptrarray_t_ *arr) {
    int count = ptrarray_count(arr);
    return ptrarray_get(arr, count - 1);
}

int ptrarray_count(const ptrarray_t_ *arr) {
    if (!arr) {
        return 0;
    }
    return array_count(&arr->arr);
}

bool ptrarray_remove_at(ptrarray_t_ *arr, unsigned int ix) {
    return array_remove_at(&arr->arr, ix);
}

bool ptrarray_remove_item(ptrarray_t_ *arr, void *item) {
    for (int i = 0; i < ptrarray_count(arr); i++) {
        if (item == ptrarray_get(arr, i)) {
            ptrarray_remove_at(arr, i);
            return true;
        }
    }
    COLLECTIONS_ASSERT(false);
    return false;
}

void ptrarray_clear(ptrarray_t_ *arr) {
    array_clear(&arr->arr);
}

void ptrarray_clear_and_destroy_items_(ptrarray_t_ *arr, ptrarray_item_destroy_fn destroy_fn) {
    for (int i = 0; i < ptrarray_count(arr); i++) {
        void *item = ptrarray_get(arr, i);
        destroy_fn(item);
    }
    ptrarray_clear(arr);
}

void ptrarray_lock_capacity(ptrarray_t_ *arr) {
    array_lock_capacity(&arr->arr);
}

int ptrarray_get_index(ptrarray_t_ *arr, void *ptr) {
    for (int i = 0; i < ptrarray_count(arr); i++) {
        if (ptrarray_get(arr, i) == ptr) {
            return i;
        }
    }
    return -1;
}

bool ptrarray_contains(ptrarray_t_ *arr, void *item) {
    return ptrarray_get_index(arr, item) >= 0;
}

void * ptrarray_get_addr(ptrarray_t_ *arr, unsigned int ix) {
    void* res = array_get(&arr->arr, ix);
    if (res == NULL) {
        return NULL;
    }
    return res;
}

void* ptrarray_data(ptrarray_t_ *arr) {
    return array_data(&arr->arr);
}

void ptrarray_reverse(ptrarray_t_ *arr) {
    array_reverse(&arr->arr);
}

//-----------------------------------------------------------------------------
// String buffer
//-----------------------------------------------------------------------------

typedef struct strbuf {
    char *data;
    size_t capacity;
    size_t len;
} strbuf_t;

static bool strbuf_grow(strbuf_t *buf, size_t new_capacity);

strbuf_t* strbuf_make(void) {
    strbuf_t *res = strbuf_make_with_capacity(1);
    return res;
}

strbuf_t* strbuf_make_with_capacity(unsigned int capacity) {
    strbuf_t *buf = collections_malloc(sizeof(strbuf_t), ape_mallocArg);
    if (buf == NULL) {
        return NULL;
    }
    memset(buf, 0, sizeof(strbuf_t));
    buf->data = collections_malloc(capacity, ape_mallocArg);
    if (buf->data == NULL) {
        collections_free(buf, ape_freeArg);
        return NULL;
    }
    buf->capacity = capacity;
    buf->len = 0;
    buf->data[0] = '\0';
    return buf;
}

void strbuf_destroy(strbuf_t *buf) {
    if (buf == NULL) {
        return;
    }
    collections_free(buf->data, ape_freeArg);
    collections_free(buf, ape_freeArg);
}

void strbuf_clear(strbuf_t *buf) {
    buf->len = 0;
    buf->data[0] = '\0';
}

bool strbuf_append(strbuf_t *buf, const char *str) {
    size_t str_len = strlen(str);
    if (str_len == 0) {
        return true;
    }
    size_t required_capacity = buf->len + str_len + 1;
    if (required_capacity > buf->capacity) {
        bool ok = strbuf_grow(buf, required_capacity * 2);
        if (!ok) {
            return false;
        }
    }
    memcpy(buf->data + buf->len, str, str_len);
    buf->len = buf->len + str_len;
    buf->data[buf->len] = '\0';
    return true;
}

bool strbuf_appendf(strbuf_t *buf, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int to_write = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    if (to_write == 0) {
        return true;
    }
    size_t required_capacity = buf->len + to_write + 1;
    if (required_capacity > buf->capacity) {
        bool ok = strbuf_grow(buf, required_capacity * 2);
        if (!ok) {
            return false;
        }
    }
    va_start(args, fmt);
    int written = vsprintf(buf->data + buf->len, fmt, args);
    (void)written;
    va_end(args);
    if (written != to_write) {
        return false;
    }
    buf->len = buf->len + to_write;
    buf->data[buf->len] = '\0';
    return true;
}

const char * strbuf_get_string(const strbuf_t *buf) {
    return buf->data;
}

size_t strbuf_get_length(const strbuf_t *buf) {
    return buf->len;
}

char * strbuf_get_string_and_destroy(strbuf_t *buf) {
    char *res = buf->data;
    buf->data = NULL;
    strbuf_destroy(buf);
    return res;
}

static bool strbuf_grow(strbuf_t *buf, size_t new_capacity) {
    char *new_data = collections_malloc(new_capacity, ape_mallocArg);
    if (new_data == NULL) {
        return false;
    }
    memcpy(new_data, buf->data, buf->len);
    new_data[buf->len] = '\0';
    collections_free(buf->data, ape_freeArg);
    buf->data = new_data;
    buf->capacity = new_capacity;
    return true;
}

//-----------------------------------------------------------------------------
// Utils
//-----------------------------------------------------------------------------

ptrarray(char)* kg_split_string(const char *str, const char *delimiter) {
    ptrarray(char)* res = ptrarray_make();
    if (!str) {
        return res;
    }
    const char *line_start = str;
    const char *line_end = strstr(line_start, delimiter);
    while (line_end != NULL) {
        long len = line_end - line_start;
        char *line = collections_strndup(line_start, len);
        ptrarray_add(res, line);
        line_start = line_end + 1;
        line_end = strstr(line_start, delimiter);
    }
    char *rest = collections_strdup(line_start);
    ptrarray_add(res, rest);
    return res;
}

char* kg_join(ptrarray(char) *items, const char *with) {
    strbuf_t *res = strbuf_make();
    for (int i = 0; i < ptrarray_count(items); i++) {
        char *item = ptrarray_get(items, i);
        strbuf_append(res, item);
        if (i < (ptrarray_count(items) - 1)) {
            strbuf_append(res, with);
        }
    }
    return strbuf_get_string_and_destroy(res);
}

char* kg_canonicalise_path(const char *path) {
    if (!strchr(path, '/') || (!strstr(path, "/../") && !strstr(path, "./"))) {
        return collections_strdup(path);
    }

    ptrarray(char) *split = kg_split_string(path, "/");

    for (int i = 0; i < ptrarray_count(split) - 1; i++) {
        char *item = ptrarray_get(split, i);
        char *next_item = ptrarray_get(split, i + 1);
        if (kg_streq(item, ".")) {
            collections_free(item, ape_freeArg);
            ptrarray_remove_at(split, i);
            i = -1;
            continue;
        }
        if (kg_streq(next_item, "..")) {
            collections_free(item, ape_freeArg);
            collections_free(next_item, ape_freeArg);
            ptrarray_remove_at(split, i);
            ptrarray_remove_at(split, i);
            i = -1;
            continue;
        }
    }

    char *joined = kg_join(split, "/");
    ptrarray_destroy_with_items(split, collections_free);
    return joined;
}

bool kg_is_path_absolute(const char *path) {
    return path[0] == '/';
}

bool kg_streq(const char *a, const char *b) {
    return strcmp(a, b) == 0;
}
//FILE_END
//FILE_START:error.c
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef APE_AMALGAMATED
#include "error.h"
#include "traceback.h"
#endif

error_t* error_make_no_copy(error_type_t type, src_pos_t pos, char *message) {
    error_t *err = ape_malloc(sizeof(error_t), ape_mallocArg);
    memset(err, 0, sizeof(error_t));
    err->type = type;
    err->message = message;
    err->pos = pos;
    err->traceback = NULL;
    return err;
}

error_t* error_make(error_type_t type, src_pos_t pos, const char *message) {
    return error_make_no_copy(type, pos, ape_strdup(message));
}

error_t* error_makef(error_type_t type, src_pos_t pos, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int to_write = vsnprintf(NULL, 0, format, args);
    va_end(args);
    va_start(args, format);
    char *res = (char*)ape_malloc(to_write + 1, ape_mallocArg);
    vsprintf(res, format, args);
    va_end(args);
    return error_make_no_copy(type, pos, res);
}

void error_destroy(error_t *error) {
    if (!error) {
        return;
    }
    traceback_destroy(error->traceback);
    ape_free(error->message, ape_freeArg);
    ape_free(error, ape_freeArg);
}

const char *error_type_to_string(error_type_t type) {
    switch (type) {
        case ERROR_PARSING: return "PARSING";
        case ERROR_COMPILATION: return "COMPILATION";
        case ERROR_RUNTIME: return "RUNTIME";
        case ERROR_USER: return "USER";
        default: return "INVALID";
    }
}
//FILE_END
//FILE_START:token.c
#include <string.h>
#include <stdlib.h>

#ifndef APE_AMALGAMATED
#include "token.h"
#endif

static const char *g_type_names[] = {
    "ILLEGAL",
    "EOF",
    "=",
    "+=",
    "-=",
    "*=",
    "/=",
    "%=",
    "&=",
    "|=",
    "^=",
    "<<=",
    ">>=",
    "+",
    "-",
    "!",
    "*",
    "/",
    "<",
    "<=",
    ">",
    ">=",
    "==",
    "!=",
    "&&",
    "||",
    "&",
    "|",
    "^",
    "<<",
    ">>",
    ",",
    ";",
    ":",
    "(",
    ")",
    "{",
    "}",
    "[",
    "]",
    ".",
    "%",
    "FUNCTION",
    "CONST",
    "VAR",
    "TRUE",
    "FALSE",
    "IF",
    "ELSE",
    "RETURN",
    "WHILE",
    "BREAK",
    "FOR",
    "IN",
    "CONTINUE",
    "NULL",
    "IMPORT",
    "RECOVER",
    "IDENT",
    "NUMBER",
    "STRING",
};

void token_make(token_t *tok, token_type_t type, const char *literal, int len) {
    tok->type = type;
    tok->literal = literal;
    tok->len = len;
}

char* token_duplicate_literal(const token_t *tok) {
    return ape_strndup(tok->literal, tok->len);
}

const char* token_type_to_string(token_type_t type) {
    return g_type_names[type];
}
//FILE_END
//FILE_START:lexer.c
#include <stdlib.h>
#include <string.h>

#ifndef APE_AMALGAMATED
#include "lexer.h"
#include "collections.h"
#include "compiler.h"
#endif

static void read_char(lexer_t *lex);
static char peek_char(lexer_t *lex);
static bool is_letter(char ch);
static bool is_digit(char ch);
static bool is_one_of(char ch, const char* allowed, int allowed_len);
static const char* read_identifier(lexer_t *lex, int *out_len);
static const char* read_number(lexer_t *lex, int *out_len);
static const char* read_string(lexer_t *lex, char delimiter, int *out_len);
static token_type_t lookup_identifier(const char *ident, int len);
static void skip_whitespace(lexer_t *lex);
static void add_line(lexer_t *lex, int offset);

bool lexer_init(lexer_t *lex, const char *input, compiled_file_t *file) {
    lex->input = input;
    lex->input_len = (int)strlen(input);
    lex->position = 0;
    lex->next_position = 0;
    lex->ch = '\0';
    if (file) {
        lex->line = ptrarray_count(file->lines);
    } else {
        lex->line = 0;
    }
    lex->column = -1;
    lex->file = file;
    add_line(lex, 0);
    read_char(lex);
    return true;
}

token_t lexer_next_token(lexer_t *lex) {
    while (true) {
        skip_whitespace(lex);

        token_t out_tok;
        out_tok.type = TOKEN_ILLEGAL;
        out_tok.literal = lex->input + lex->position;
        out_tok.len = 1;
        out_tok.pos = src_pos_make(lex->file, lex->line, lex->column);

        switch (lex->ch) {
            case '\0': token_make(&out_tok, TOKEN_EOF, "EOF", 3); break;
            case '=': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_EQ, "==", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_ASSIGN, "=", 1);
                }
                break;
            }
            case '&': {
                if (peek_char(lex) == '&') {
                    token_make(&out_tok, TOKEN_AND, "&&", 2);
                    read_char(lex);
                } else if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_BIT_AND_ASSIGN, "&=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_BIT_AND, "&", 1);
                }
                break;
            }
            case '|': {
                if (peek_char(lex) == '|') {
                    token_make(&out_tok, TOKEN_OR, "||", 2);
                    read_char(lex);
                } else if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_BIT_OR_ASSIGN, "|=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_BIT_OR, "|", 1);
                }
                break;
            }
            case '^': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_BIT_XOR_ASSIGN, "^=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_BIT_XOR, "^", 1); break;
                }
                break;
            }
            case '+': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_PLUS_ASSIGN, "+=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_PLUS, "+", 1); break;
                }
                break;
            }
            case '-': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_MINUS_ASSIGN, "-=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_MINUS, "-", 1); break;
                }
                break;
            }
            case '!': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_NOT_EQ, "!=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_BANG, "!", 1);
                }
                break;
            }
            case '*': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_ASTERISK_ASSIGN, "*=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_ASTERISK, "*", 1); break;
                }
                break;
            }
            case '/': {
                if (peek_char(lex) == '/') {
                    read_char(lex);
                    while (lex->ch != '\n' && lex->ch != '\0') {
                        read_char(lex);
                    }
                    continue;
                } else if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_SLASH_ASSIGN, "/=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_SLASH, "/", 1); break;
                }
                break;
            }
            case '<': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_LTE, "<=", 2);
                    read_char(lex);
                } else if (peek_char(lex) == '<') {
                    read_char(lex);
                    if (peek_char(lex) == '=') {
                        token_make(&out_tok, TOKEN_LSHIFT_ASSIGN, "<<=", 3);
                        read_char(lex);
                    } else {
                        token_make(&out_tok, TOKEN_LSHIFT, "<<", 2);
                    }
                } else {
                    token_make(&out_tok, TOKEN_LT, "<", 1); break;
                }
                break;
            }
            case '>': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_GTE, ">=", 2);
                    read_char(lex);
                } else if (peek_char(lex) == '>') {
                    read_char(lex);
                    if (peek_char(lex) == '=') {
                        token_make(&out_tok, TOKEN_RSHIFT_ASSIGN, ">>=", 3);
                        read_char(lex);
                    } else {
                        token_make(&out_tok, TOKEN_RSHIFT, ">>", 2);
                    }
                } else {
                    token_make(&out_tok, TOKEN_GT, ">", 1);
                }
                break;
            }
            case ',': token_make(&out_tok, TOKEN_COMMA, ",", 1); break;
            case ';': token_make(&out_tok, TOKEN_SEMICOLON, ";", 1); break;
            case ':': token_make(&out_tok, TOKEN_COLON, ":", 1); break;
            case '(': token_make(&out_tok, TOKEN_LPAREN, "(", 1); break;
            case ')': token_make(&out_tok, TOKEN_RPAREN, ")", 1); break;
            case '{': token_make(&out_tok, TOKEN_LBRACE, "{", 1); break;
            case '}': token_make(&out_tok, TOKEN_RBRACE, "}", 1); break;
            case '[': token_make(&out_tok, TOKEN_LBRACKET, "[", 1); break;
            case ']': token_make(&out_tok, TOKEN_RBRACKET, "]", 1); break;
            case '.': token_make(&out_tok, TOKEN_DOT, ".", 1); break;
            case '%': {
                if (peek_char(lex) == '=') {
                    token_make(&out_tok, TOKEN_PERCENT_ASSIGN, "%=", 2);
                    read_char(lex);
                } else {
                    token_make(&out_tok, TOKEN_PERCENT, "%", 1); break;
                }
                break;
            }
            case '"': {
                int len;
                const char *str = read_string(lex, '"', &len);
                if (str) {
                    token_make(&out_tok, TOKEN_STRING, str, len);
                } else {
                    token_make(&out_tok, TOKEN_ILLEGAL, NULL, 0);
                }
                break;
            }
            case '\'': {
                int len;
                const char *str = read_string(lex, '\'', &len);
                if (str) {
                    token_make(&out_tok, TOKEN_STRING, str, len);
                } else {
                    token_make(&out_tok, TOKEN_ILLEGAL, NULL, 0);
                }
                break;
            }
            default: {
                if (is_letter(lex->ch)) {
                    int ident_len = 0;
                    const char *ident = read_identifier(lex, &ident_len);
                    token_type_t type = lookup_identifier(ident, ident_len);
                    token_make(&out_tok, type, ident, ident_len);
                    return out_tok;
                } else if (is_digit(lex->ch)) {
                    int number_len = 0;
                    const char *number = read_number(lex, &number_len);
                    token_make(&out_tok, TOKEN_NUMBER, number, number_len);
                    return out_tok;
                }
                break;
            }
        }
        read_char(lex);
        return out_tok;
    }
}

// INTERNAL
static void read_char(lexer_t *lex) {
    if (lex->next_position >= lex->input_len) {
        lex->ch = '\0';
    } else {
        lex->ch = lex->input[lex->next_position];
    }
    lex->position = lex->next_position;
    lex->next_position++;

    if (lex->ch == '\n') {
        lex->line++;
        lex->column = -1;
        add_line(lex, lex->next_position);
    } else {
        lex->column++;
    }
}

static char peek_char(lexer_t *lex) {
    if (lex->next_position >= lex->input_len) {
        return '\0';
    } else {
        return lex->input[lex->next_position];
    }
}

static bool is_letter(char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
}

static bool is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

static bool is_one_of(char ch, const char* allowed, int allowed_len) {
    for (int i = 0; i < allowed_len; i++) {
        if (ch == allowed[i]) {
            return true;
        }
    }
    return false;
}

static const char* read_identifier(lexer_t *lex, int *out_len) {
    int position = lex->position;
    int len = 0;
    while (is_digit(lex->ch) || is_letter(lex->ch) || lex->ch == ':') {
        if (lex->ch == ':') {
            if (peek_char(lex) != ':') {
                goto end;
            }
            read_char(lex);
        }
        read_char(lex);
    }
end:
    len = lex->position - position;
    *out_len = len;
    return lex->input + position;
}

static const char* read_number(lexer_t *lex, int *out_len) {
    char allowed[] = ".xXaAbBcCdDeEfF";
    int position = lex->position;
    while (is_digit(lex->ch) || is_one_of(lex->ch, allowed, APE_ARRAY_LEN(allowed) - 1)) {
        read_char(lex);
    }
    int len = lex->position - position;
    *out_len = len;
    return lex->input + position;
}

static const char* read_string(lexer_t *lex, char delimiter, int *out_len) {
    *out_len = 0;

    bool escaped = false;
    int position = lex->position + 1;
    while (true) {
        read_char(lex);
        if (lex->ch == '\0') {
            return NULL;
        }
        if (lex->ch == delimiter && !escaped) {
            break;
        }
        escaped = false;
        if (lex->ch == '\\') {
            escaped = true;
        }
    }
    int len = lex->position - position;
    *out_len = len;
    return lex->input + position;
}

static token_type_t lookup_identifier(const char *ident, int len) {
    struct {
        const char *value;
        int len;
        token_type_t type;
    } keywords[] = {
        {"fn", 2, TOKEN_FUNCTION},
        {"const", 5, TOKEN_CONST},
        {"var", 3, TOKEN_VAR},
        {"true", 4, TOKEN_TRUE},
        {"false", 5, TOKEN_FALSE},
        {"if", 2, TOKEN_IF},
        {"else", 4, TOKEN_ELSE},
        {"return", 6, TOKEN_RETURN},
        {"while", 5, TOKEN_WHILE},
        {"break", 5, TOKEN_BREAK},
        {"for", 3, TOKEN_FOR},
        {"in", 2, TOKEN_IN},
        {"continue", 8, TOKEN_CONTINUE},
        {"null", 4, TOKEN_NULL},
        {"import", 6, TOKEN_IMPORT},
        {"recover", 7, TOKEN_RECOVER},
    };

    for (int i = 0; i < APE_ARRAY_LEN(keywords); i++) {
        if (keywords[i].len == len && APE_STRNEQ(ident, keywords[i].value, len)) {
            return keywords[i].type;
        }
    }

    return TOKEN_IDENT;
}

static void skip_whitespace(lexer_t *lex) {
    char ch = lex->ch;
    while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
        read_char(lex);
        ch = lex->ch;
    }
}

static void add_line(lexer_t *lex, int offset) {
    if (!lex->file) {
        return;
    }
    const char *line_start = lex->input + offset;
    const char *new_line_ptr = strchr(line_start, '\n');
    char *line = NULL;
    if (!new_line_ptr) {
        line = ape_strdup(line_start);
    } else {
        size_t line_len = new_line_ptr - line_start;
        line = ape_strndup(line_start, line_len);
    }
    ptrarray_add(lex->file->lines, line);
}
//FILE_END
//FILE_START:ast.c
#include <stdlib.h>
#include <string.h>

#ifndef APE_AMALGAMATED
#include "ast.h"
#include "common.h"
#endif

static expression_t* expression_make(expression_type_t type);
static statement_t* statement_make(statement_type_t type);

expression_t* expression_make_ident(ident_t ident) {
    expression_t *res = expression_make(EXPRESSION_IDENT);
    res->ident = ident;
    return res;
}

expression_t* expression_make_number_literal(double val) {
    expression_t *res = expression_make(EXPRESSION_NUMBER_LITERAL);
    res->number_literal = val;
    return res;
}

expression_t* expression_make_bool_literal(bool val) {
    expression_t *res = expression_make(EXPRESSION_BOOL_LITERAL);
    res->bool_literal = val;
    return res;
}

expression_t* expression_make_string_literal(char *value) {
    expression_t *res = expression_make(EXPRESSION_STRING_LITERAL);
    res->string_literal = value;
    return res;
}

expression_t* expression_make_null_literal() {
    expression_t *res = expression_make(EXPRESSION_NULL_LITERAL);
    return res;
}

expression_t* expression_make_array_literal(ptrarray(expression_t) *values) {
    expression_t *res = expression_make(EXPRESSION_ARRAY_LITERAL);
    res->array = values;
    return res;
}

expression_t* expression_make_map_literal(ptrarray(expression_t) *keys, ptrarray(expression_t) *values) {
    expression_t *res = expression_make(EXPRESSION_MAP_LITERAL);
    res->map.keys = keys;
    res->map.values = values;
    return res;
}

expression_t* expression_make_prefix(operator_t op, expression_t *right) {
    expression_t *res = expression_make(EXPRESSION_PREFIX);
    res->prefix.op = op;
    res->prefix.right = right;
    return res;
}

expression_t* expression_make_infix(operator_t op, expression_t *left, expression_t *right) {
    expression_t *res = expression_make(EXPRESSION_INFIX);
    res->infix.op = op;
    res->infix.left = left;
    res->infix.right = right;
    return res;
}

expression_t* expression_make_fn_literal(array(ident_t) *params, code_block_t *body) {
    expression_t *res = expression_make(EXPRESSION_FUNCTION_LITERAL);
    res->fn_literal.name = NULL;
    res->fn_literal.params = params;
    res->fn_literal.body = body;
    return res;
}

expression_t* expression_make_call(expression_t *function, ptrarray(expression_t) *args) {
    expression_t *res = expression_make(EXPRESSION_CALL);
    res->call_expr.function = function;
    res->call_expr.args = args;
    return res;
}

expression_t* expression_make_index(expression_t *left, expression_t *index) {
    expression_t *res = expression_make(EXPRESSION_INDEX);
    res->index_expr.left = left;
    res->index_expr.index = index;
    return res;
}

expression_t* expression_make_assign(expression_t *dest, expression_t *source) {
    expression_t *res = expression_make(EXPRESSION_ASSIGN);
    res->assign.dest = dest;
    res->assign.source = source;
    return res;
}

expression_t* expression_make_logical(operator_t op, expression_t *left, expression_t *right) {
    expression_t *res = expression_make(EXPRESSION_LOGICAL);
    res->logical.op = op;
    res->logical.left = left;
    res->logical.right = right;
    return res;
}

void expression_destroy(expression_t *expr) {
    if (!expr) {
        return;
    }

    switch (expr->type) {
        case EXPRESSION_NONE: {
            APE_ASSERT(false);
            break;
        }
        case EXPRESSION_IDENT: {
            ident_deinit(&expr->ident);
            break;
        }
        case EXPRESSION_NUMBER_LITERAL:
        case EXPRESSION_BOOL_LITERAL: {
            break;
        }
        case EXPRESSION_STRING_LITERAL: {
            ape_free(expr->string_literal, ape_freeArg);
            break;
        }
        case EXPRESSION_NULL_LITERAL: {
            break;
        }
        case EXPRESSION_ARRAY_LITERAL: {
            ptrarray_destroy_with_items(expr->array, expression_destroy);
            break;
        }
        case EXPRESSION_MAP_LITERAL: {
            ptrarray_destroy_with_items(expr->map.keys, expression_destroy);
            ptrarray_destroy_with_items(expr->map.values, expression_destroy);
            break;
        }
        case EXPRESSION_PREFIX: {
            expression_destroy(expr->prefix.right);
            break;
        }
        case EXPRESSION_INFIX: {
            expression_destroy(expr->infix.left);
            expression_destroy(expr->infix.right);
            break;
        }
        case EXPRESSION_FUNCTION_LITERAL: {
            fn_literal_deinit(&expr->fn_literal);
            break;
        }
        case EXPRESSION_CALL: {
            ptrarray_destroy_with_items(expr->call_expr.args, expression_destroy);
            expression_destroy(expr->call_expr.function);
            break;
        }
        case EXPRESSION_INDEX: {
            expression_destroy(expr->index_expr.left);
            expression_destroy(expr->index_expr.index);
            break;
        }
        case EXPRESSION_ASSIGN: {
            expression_destroy(expr->assign.dest);
            expression_destroy(expr->assign.source);
            break;
        }
        case EXPRESSION_LOGICAL: {
            expression_destroy(expr->logical.left);
            expression_destroy(expr->logical.right);
            break;
        }
    }
    ape_free(expr, ape_freeArg);
}

expression_t* expression_copy(expression_t *expr) {
    APE_ASSERT(expr);
    if (!expr) {
        return NULL;
    }
    expression_t *res = NULL;
    switch (expr->type) {
        case EXPRESSION_NONE: {
            APE_ASSERT(false);
            break;
        }
        case EXPRESSION_IDENT: {
            ident_t ident = ident_copy(expr->ident);
            res = expression_make_ident(ident);
            break;
        }
        case EXPRESSION_NUMBER_LITERAL: {
            res = expression_make_number_literal(expr->number_literal);
            break;
        }
        case EXPRESSION_BOOL_LITERAL: {
            res = expression_make_bool_literal(expr->bool_literal);
            break;
        }
        case EXPRESSION_STRING_LITERAL: {
            res = expression_make_string_literal(ape_strdup(expr->string_literal));
            break;
        }
        case EXPRESSION_NULL_LITERAL: {
            res = expression_make_null_literal();
            break;
        }
        case EXPRESSION_ARRAY_LITERAL: {
            ptrarray(expression_t) *values_copy = ptrarray_copy_with_items(expr->array, expression_copy);
            res = expression_make_array_literal(values_copy);
            break;
        }
        case EXPRESSION_MAP_LITERAL: {
            ptrarray(expression_t) *keys_copy = ptrarray_copy_with_items(expr->map.keys, expression_copy);
            ptrarray(expression_t) *values_copy = ptrarray_copy_with_items(expr->map.values, expression_copy);
            res = expression_make_map_literal(keys_copy, values_copy);
            break;
        }
        case EXPRESSION_PREFIX: {
            expression_t *right_copy = expression_copy(expr->prefix.right);
            res = expression_make_prefix(expr->prefix.op, right_copy);
            break;
        }
        case EXPRESSION_INFIX: {
            expression_t *left_copy = expression_copy(expr->infix.left);
            expression_t *right_copy = expression_copy(expr->infix.right);
            res = expression_make_infix(expr->infix.op, left_copy, right_copy);
            break;
        }
        case EXPRESSION_FUNCTION_LITERAL: {
            array(ident_t) *params_copy = array_make(ident_t);
            for (int i = 0; i < array_count(expr->fn_literal.params); i++) {
                ident_t *param = array_get(expr->fn_literal.params, i);
                ident_t copy = ident_copy(*param);
                array_add(params_copy, &copy);
            }
            code_block_t *body_copy = code_block_copy(expr->fn_literal.body);
            res = expression_make_fn_literal(params_copy, body_copy);
            res->fn_literal.name = ape_strdup(expr->fn_literal.name);
            break;
        }
        case EXPRESSION_CALL: {
            expression_t *function_copy = expression_copy(expr->call_expr.function);
            ptrarray(expression_t) *args_copy = ptrarray_copy_with_items(expr->call_expr.args, expression_copy);
            res = expression_make_call(function_copy, args_copy);
            break;
        }
        case EXPRESSION_INDEX: {
            expression_t *left_copy = expression_copy(expr->index_expr.left);
            expression_t *index_copy = expression_copy(expr->index_expr.index);
            res = expression_make_index(left_copy, index_copy);
            break;
        }
        case EXPRESSION_ASSIGN: {
            expression_t *dest_copy = expression_copy(expr->assign.dest);
            expression_t *source_copy = expression_copy(expr->assign.source);
            res = expression_make_assign(dest_copy, source_copy);
            break;
        }
        case EXPRESSION_LOGICAL: {
            expression_t *left_copy = expression_copy(expr->logical.left);
            expression_t *right_copy = expression_copy(expr->logical.right);
            res = expression_make_logical(expr->logical.op, left_copy, right_copy);
            break;
        }
    }
    res->pos = expr->pos;
    return res;
}

statement_t* statement_make_define(ident_t name, expression_t *value, bool assignable) {
    statement_t *res = statement_make(STATEMENT_DEFINE);
    res->define.name = name;
    res->define.value = value;
    res->define.assignable = assignable;
    return res;
}

statement_t* statement_make_if(ptrarray(if_case_t) *cases, code_block_t *alternative) {
    statement_t *res = statement_make(STATEMENT_IF);
    res->if_statement.cases = cases;
    res->if_statement.alternative = alternative;
    return res;
}

statement_t* statement_make_return(expression_t *value) {
    statement_t *res = statement_make(STATEMENT_RETURN_VALUE);
    res->return_value = value;
    return res;
}

statement_t* statement_make_expression(expression_t *value) {
    statement_t *res = statement_make(STATEMENT_EXPRESSION);
    res->expression = value;
    return res;
}

statement_t* statement_make_while_loop(expression_t *test, code_block_t *body) {
    statement_t *res = statement_make(STATEMENT_WHILE_LOOP);
    res->while_loop.test = test;
    res->while_loop.body = body;
    return res;
}

statement_t* statement_make_break() {
    statement_t *res = statement_make(STATEMENT_BREAK);
    return res;
}

statement_t* statement_make_foreach(ident_t iterator, expression_t *source, code_block_t *body) {
    statement_t *res = statement_make(STATEMENT_FOREACH);
    res->foreach.iterator = iterator;
    res->foreach.source = source;
    res->foreach.body = body;
    return res;
}

statement_t* statement_make_for_loop(statement_t *init, expression_t *test, expression_t *update, code_block_t *body) {
    statement_t *res = statement_make(STATEMENT_FOR_LOOP);
    res->for_loop.init = init;
    res->for_loop.test = test;
    res->for_loop.update = update;
    res->for_loop.body = body;
    return res;
}

statement_t* statement_make_continue() {
    statement_t *res = statement_make(STATEMENT_CONTINUE);
    return res;
}

statement_t* statement_make_block(code_block_t *block) {
    statement_t *res = statement_make(STATEMENT_BLOCK);
    res->block = block;
    return res;
}

statement_t* statement_make_import(char *path) {
    statement_t *res = statement_make(STATEMENT_IMPORT);
    res->import.path = path;
    return res;
}

statement_t* statement_make_recover(ident_t error_ident, code_block_t *body) {
    statement_t *res = statement_make(STATEMENT_RECOVER);
    res->recover.error_ident = error_ident;
    res->recover.body = body;
    return res;
}

void statement_destroy(statement_t *stmt) {
    if (!stmt) {
        return;
    }
    switch (stmt->type) {
        case STATEMENT_NONE: {
            APE_ASSERT(false);
            break;
        }
        case STATEMENT_DEFINE: {
            ident_deinit(&stmt->define.name);
            expression_destroy(stmt->define.value);
            break;
        }
        case STATEMENT_IF: {
            ptrarray_destroy_with_items(stmt->if_statement.cases, if_case_destroy);
            code_block_destroy(stmt->if_statement.alternative);
            break;
        }
        case STATEMENT_RETURN_VALUE: {
            expression_destroy(stmt->return_value);
            break;
        }
        case STATEMENT_EXPRESSION: {
            expression_destroy(stmt->expression);
            break;
        }
        case STATEMENT_WHILE_LOOP: {
            expression_destroy(stmt->while_loop.test);
            code_block_destroy(stmt->while_loop.body);
            break;
        }
        case STATEMENT_BREAK: {
            break;
        }
        case STATEMENT_CONTINUE: {
            break;
        }
        case STATEMENT_FOREACH: {
            ident_deinit(&stmt->foreach.iterator);
            expression_destroy(stmt->foreach.source);
            code_block_destroy(stmt->foreach.body);
            break;
        }
        case STATEMENT_FOR_LOOP: {
            statement_destroy(stmt->for_loop.init);
            expression_destroy(stmt->for_loop.test);
            expression_destroy(stmt->for_loop.update);
            code_block_destroy(stmt->for_loop.body);
            break;
        }
        case STATEMENT_BLOCK: {
            code_block_destroy(stmt->block);
            break;
        }
        case STATEMENT_IMPORT: {
            ape_free(stmt->import.path, ape_freeArg);
            break;
        }
        case STATEMENT_RECOVER: {
            code_block_destroy(stmt->recover.body);
            ident_deinit(&stmt->recover.error_ident);
            break;
        }
    }
    ape_free(stmt, ape_freeArg);
}

statement_t* statement_copy(statement_t *stmt) {
    APE_ASSERT(stmt);
    if (!stmt) {
        return NULL;
    }
    statement_t *res = NULL;
    switch (stmt->type) {
        case STATEMENT_NONE: {
            APE_ASSERT(false);
            break;
        }
        case STATEMENT_DEFINE: {
            expression_t *value_copy = expression_copy(stmt->define.value);
            res = statement_make_define(ident_copy(stmt->define.name), value_copy, stmt->define.assignable);
            break;
        }
        case STATEMENT_IF: {
            ptrarray(expression_t) *cases_copy = ptrarray_copy_with_items(stmt->if_statement.cases, expression_copy);
            code_block_t *alternative_copy = code_block_copy(stmt->if_statement.alternative);
            res = statement_make_if(cases_copy, alternative_copy);
            break;
        }
        case STATEMENT_RETURN_VALUE: {
            expression_t *value_copy = expression_copy(stmt->return_value);
            res = statement_make_return(value_copy);
            break;
        }
        case STATEMENT_EXPRESSION: {
            expression_t *value_copy = expression_copy(stmt->expression);
            res = statement_make_expression(value_copy);
            break;
        }
        case STATEMENT_WHILE_LOOP: {
            expression_t *test_copy = expression_copy(stmt->while_loop.test);
            code_block_t *body_copy = code_block_copy(stmt->while_loop.body);
            res = statement_make_while_loop(test_copy, body_copy);
            break;
        }
        case STATEMENT_BREAK: {
            res = statement_make_break();
            break;
        }
        case STATEMENT_CONTINUE: {
            res = statement_make_continue();
            break;
        }
        case STATEMENT_FOREACH: {
            expression_t *source_copy = expression_copy(stmt->foreach.source);
            code_block_t *body_copy = code_block_copy(stmt->foreach.body);
            res = statement_make_foreach(ident_copy(stmt->foreach.iterator), source_copy, body_copy);
            break;
        }
        case STATEMENT_FOR_LOOP: {
            statement_t *init_copy = statement_copy(stmt->for_loop.init);
            expression_t *test_copy = expression_copy(stmt->for_loop.test);
            expression_t *update_copy = expression_copy(stmt->for_loop.update);
            code_block_t *body_copy = code_block_copy(stmt->for_loop.body);
            res = statement_make_for_loop(init_copy, test_copy, update_copy, body_copy);
            break;
        }
        case STATEMENT_BLOCK: {
            code_block_t *block_copy = code_block_copy(stmt->block);
            res = statement_make_block(block_copy);
            break;
        }
        case STATEMENT_IMPORT: {
            res = statement_make_import(ape_strdup(stmt->import.path));
            break;
        }
        case STATEMENT_RECOVER: {
            code_block_t *body_copy = code_block_copy(stmt->recover.body);
            res = statement_make_recover(ident_copy(stmt->recover.error_ident), body_copy);
            break;
        }
    }
    res->pos = stmt->pos;
    return NULL;
}

code_block_t* code_block_make(ptrarray(statement_t) *statements) {
    code_block_t *stmt = ape_malloc(sizeof(code_block_t), ape_mallocArg);
    stmt->statements = statements;
    return stmt;
}

void code_block_destroy(code_block_t *block) {
    if (!block) {
        return;
    }
    ptrarray_destroy_with_items(block->statements, statement_destroy);
    ape_free(block, ape_freeArg);
}

code_block_t* code_block_copy(code_block_t *block) {
    ptrarray(statement_t) *statements_copy = ptrarray_make();
    for (int i = 0; i < ptrarray_count(block->statements); i++) {
        statement_t *statement = ptrarray_get(block->statements, i);
        statement_t *copy = statement_copy(statement);
        ptrarray_add(statements_copy, copy);
    }
    return code_block_make(statements_copy);
}

char* statements_to_string(ptrarray(statement_t) *statements) {
    strbuf_t *buf = strbuf_make();
    int count =  ptrarray_count(statements);
    for (int i = 0; i < count; i++) {
        const statement_t *stmt = ptrarray_get(statements, i);
        statement_to_string(stmt, buf);
        if (i < (count - 1)) {
            strbuf_append(buf, "\n");
        }
    }
    return strbuf_get_string_and_destroy(buf);
}

void statement_to_string(const statement_t *stmt, strbuf_t *buf) {
    switch (stmt->type) {
        case STATEMENT_DEFINE: {
            const define_statement_t *def_stmt = &stmt->define;
            if (stmt->define.assignable) {
                strbuf_append(buf, "var ");
            } else {
                strbuf_append(buf, "const ");
            }
            strbuf_append(buf, def_stmt->name.value);
            strbuf_append(buf, " = ");

            if (def_stmt->value) {
                expression_to_string(def_stmt->value, buf);
            }

            break;
        }
        case STATEMENT_IF: {
            if_case_t *if_case = ptrarray_get(stmt->if_statement.cases, 0);
            strbuf_append(buf, "if (");
            expression_to_string(if_case->test, buf);
            strbuf_append(buf, ") ");
            code_block_to_string(if_case->consequence, buf);
            for (int i = 1; i < ptrarray_count(stmt->if_statement.cases); i++) {
                if_case_t *elif_case = ptrarray_get(stmt->if_statement.cases, i);
                strbuf_append(buf, " elif (");
                expression_to_string(elif_case->test, buf);
                strbuf_append(buf, ") ");
                code_block_to_string(elif_case->consequence, buf);
            }
            if (stmt->if_statement.alternative) {
                strbuf_append(buf, " else ");
                code_block_to_string(stmt->if_statement.alternative, buf);
            }
            break;
        }
        case STATEMENT_RETURN_VALUE: {
            strbuf_append(buf, "return ");
            if (stmt->return_value) {
                expression_to_string(stmt->return_value, buf);
            }
            break;
        }
        case STATEMENT_EXPRESSION: {
            if (stmt->expression) {
                expression_to_string(stmt->expression, buf);
            }
            break;
        }
        case STATEMENT_WHILE_LOOP: {
            strbuf_append(buf, "while (");
            expression_to_string(stmt->while_loop.test, buf);
            strbuf_append(buf, ")");
            code_block_to_string(stmt->while_loop.body, buf);
            break;
        }
        case STATEMENT_FOR_LOOP: {
            strbuf_append(buf, "for (");
            if (stmt->for_loop.init) {
                statement_to_string(stmt->for_loop.init, buf);
                strbuf_append(buf, " ");
            } else {
                strbuf_append(buf, ";");
            }
            if (stmt->for_loop.test) {
                expression_to_string(stmt->for_loop.test, buf);
                strbuf_append(buf, "; ");
            } else {
                strbuf_append(buf, ";");
            }
            if (stmt->for_loop.update) {
                expression_to_string(stmt->for_loop.test, buf);
            }
            strbuf_append(buf, ")");
            code_block_to_string(stmt->for_loop.body, buf);
            break;
        }
        case STATEMENT_FOREACH: {
            strbuf_append(buf, "for (");
            strbuf_appendf(buf, "%s", stmt->foreach.iterator.value);
            strbuf_append(buf, " in ");
            expression_to_string(stmt->foreach.source, buf);
            strbuf_append(buf, ")");
            code_block_to_string(stmt->foreach.body, buf);
            break;
        }
        case STATEMENT_BLOCK: {
            code_block_to_string(stmt->block, buf);
            break;
        }
        case STATEMENT_BREAK: {
            strbuf_append(buf, "break");
            break;
        }
        case STATEMENT_CONTINUE: {
            strbuf_append(buf, "continue");
            break;
        }
        case STATEMENT_IMPORT: {
            strbuf_appendf(buf, "import \"%s\"", stmt->import.path);
            break;
        }
        case STATEMENT_NONE: {
            strbuf_append(buf, "STATEMENT_NONE");
            break;
        }
        case STATEMENT_RECOVER: {
            strbuf_appendf(buf, "recover (%s)", stmt->recover.error_ident.value);
            code_block_to_string(stmt->recover.body, buf);
            break;
        }
    }
}

void expression_to_string(expression_t *expr, strbuf_t *buf) {
    switch (expr->type) {
        case EXPRESSION_IDENT: {
            strbuf_append(buf, expr->ident.value);
            break;
        }
        case EXPRESSION_NUMBER_LITERAL: {
            strbuf_appendf(buf, "%1.17g", expr->number_literal);
            break;
        }
        case EXPRESSION_BOOL_LITERAL: {
            strbuf_appendf(buf, "%s", expr->bool_literal ? "true" : "false");
            break;
        }
        case EXPRESSION_STRING_LITERAL: {
            strbuf_appendf(buf, "\"%s\"", expr->string_literal);
            break;
        }
        case EXPRESSION_NULL_LITERAL: {
            strbuf_append(buf, "null");
            break;
        }
        case EXPRESSION_ARRAY_LITERAL: {
            strbuf_append(buf, "[");
            for (int i = 0; i < ptrarray_count(expr->array); i++) {
                expression_t *arr_expr = ptrarray_get(expr->array, i);
                expression_to_string(arr_expr, buf);
                if (i < (ptrarray_count(expr->array) - 1)) {
                    strbuf_append(buf, ", ");
                }
            }
            strbuf_append(buf, "]");
            break;
        }
        case EXPRESSION_MAP_LITERAL: {
            map_literal_t *map = &expr->map;

            strbuf_append(buf, "{");
            for (int i = 0; i < ptrarray_count(map->keys); i++) {
                expression_t *key_expr = ptrarray_get(map->keys, i);
                expression_t *val_expr = ptrarray_get(map->values, i);

                expression_to_string(key_expr, buf);
                strbuf_append(buf, " : ");
                expression_to_string(val_expr, buf);

                if (i < (ptrarray_count(map->keys) - 1)) {
                    strbuf_append(buf, ", ");
                }
            }
            strbuf_append(buf, "}");
            break;
        }
        case EXPRESSION_PREFIX: {
            strbuf_append(buf, "(");
            strbuf_append(buf, operator_to_string(expr->infix.op));
            expression_to_string(expr->prefix.right, buf);
            strbuf_append(buf, ")");
            break;
        }
        case EXPRESSION_INFIX: {
            strbuf_append(buf, "(");
            expression_to_string(expr->infix.left, buf);
            strbuf_append(buf, " ");
            strbuf_append(buf, operator_to_string(expr->infix.op));
            strbuf_append(buf, " ");
            expression_to_string(expr->infix.right, buf);
            strbuf_append(buf, ")");
            break;
        }
        case EXPRESSION_FUNCTION_LITERAL: {
            fn_literal_t *fn = &expr->fn_literal;

            strbuf_append(buf, "fn");

            strbuf_append(buf, "(");
            for (int i = 0; i < array_count(fn->params); i++) {
                ident_t *param = array_get(fn->params, i);
                strbuf_append(buf, param->value);
                if (i < (array_count(fn->params) - 1)) {
                    strbuf_append(buf, ", ");
                }
            }
            strbuf_append(buf, ") ");

            code_block_to_string(fn->body, buf);

            break;
        }
        case EXPRESSION_CALL: {
            call_expression_t *call_expr = &expr->call_expr;

            expression_to_string(call_expr->function, buf);

            strbuf_append(buf, "(");
            for (int i = 0; i < ptrarray_count(call_expr->args); i++) {
                expression_t *arg = ptrarray_get(call_expr->args, i);
                expression_to_string(arg, buf);
                if (i < (ptrarray_count(call_expr->args) - 1)) {
                    strbuf_append(buf, ", ");
                }
            }
            strbuf_append(buf, ")");

            break;
        }
        case EXPRESSION_INDEX: {
            strbuf_append(buf, "(");
            expression_to_string(expr->index_expr.left, buf);
            strbuf_append(buf, "[");
            expression_to_string(expr->index_expr.index, buf);
            strbuf_append(buf, "])");
            break;
        }
        case EXPRESSION_ASSIGN: {
            expression_to_string(expr->assign.dest, buf);
            strbuf_append(buf, " = ");
            expression_to_string(expr->assign.source, buf);
            break;
        }
        case EXPRESSION_LOGICAL: {
            expression_to_string(expr->logical.left, buf);
            strbuf_append(buf, " ");
            strbuf_append(buf, operator_to_string(expr->infix.op));
            strbuf_append(buf, " ");
            expression_to_string(expr->logical.right, buf);
            break;
        }
        case EXPRESSION_NONE: {
            strbuf_append(buf, "EXPRESSION_NONE");
            break;
        }
    }
}

void code_block_to_string(const code_block_t *stmt, strbuf_t *buf) {
    strbuf_append(buf, "{ ");
    for (int i = 0; i < ptrarray_count(stmt->statements); i++) {
        statement_t *istmt = ptrarray_get(stmt->statements, i);
        statement_to_string(istmt, buf);
        strbuf_append(buf, "\n");
    }
    strbuf_append(buf, " }");
}

const char* operator_to_string(operator_t op) {
    switch (op) {
        case OPERATOR_NONE:        return "OPERATOR_NONE";
        case OPERATOR_ASSIGN:      return "=";
        case OPERATOR_PLUS:        return "+";
        case OPERATOR_MINUS:       return "-";
        case OPERATOR_BANG:        return "!";
        case OPERATOR_ASTERISK:    return "*";
        case OPERATOR_SLASH:       return "/";
        case OPERATOR_LT:          return "<";
        case OPERATOR_GT:          return ">";
        case OPERATOR_EQ:          return "==";
        case OPERATOR_NOT_EQ:      return "!=";
        case OPERATOR_MODULUS:     return "%";
        case OPERATOR_LOGICAL_AND: return "&&";
        case OPERATOR_LOGICAL_OR:  return "||";
        case OPERATOR_BIT_AND:     return "&";
        case OPERATOR_BIT_OR:      return "|";
        case OPERATOR_BIT_XOR:     return "^";
        case OPERATOR_LSHIFT:      return "<<";
        case OPERATOR_RSHIFT:      return ">>";
        default:                   return "OPERATOR_UNKNOWN";
    }
}

const char *expression_type_to_string(expression_type_t type) {
    switch (type) {
        case EXPRESSION_NONE:             return "NONE";
        case EXPRESSION_IDENT:            return "IDENT";
        case EXPRESSION_NUMBER_LITERAL:   return "INT_LITERAL";
        case EXPRESSION_BOOL_LITERAL:     return "BOOL_LITERAL";
        case EXPRESSION_STRING_LITERAL:   return "STRING_LITERAL";
        case EXPRESSION_ARRAY_LITERAL:    return "ARRAY_LITERAL";
        case EXPRESSION_MAP_LITERAL:      return "MAP_LITERAL";
        case EXPRESSION_PREFIX:           return "PREFIX";
        case EXPRESSION_INFIX:            return "INFIX";
        case EXPRESSION_FUNCTION_LITERAL: return "FN_LITERAL";
        case EXPRESSION_CALL:             return "CALL";
        case EXPRESSION_INDEX:            return "INDEX";
        case EXPRESSION_ASSIGN:           return "ASSIGN";
        case EXPRESSION_LOGICAL:          return "LOGICAL";
        default:                          return "UNKNOWN";
    }
}

void fn_literal_deinit(fn_literal_t *fn) {
    ape_free(fn->name, ape_freeArg);
    array_destroy_with_items(fn->params, ident_deinit);
    code_block_destroy(fn->body);
}

ident_t ident_make(token_t tok) {
    ident_t res;
    res.value = token_duplicate_literal(&tok);
    res.pos = tok.pos;
    return res;
}

ident_t ident_copy(ident_t ident) {
    ident_t res;
    res.value = ape_strdup(ident.value);
    res.pos = ident.pos;
    return res;
}

void ident_deinit(ident_t *ident) {
    ape_free(ident->value, ape_freeArg);
    ident->value = NULL;
    ident->pos = src_pos_invalid;
}

if_case_t *if_case_make(expression_t *test, code_block_t *consequence) {
    if_case_t *res = ape_malloc(sizeof(if_case_t), ape_mallocArg);
    res->test = test;
    res->consequence = consequence;
    return res;
}

void if_case_destroy(if_case_t *cond) {
    if (!cond) {
        return;
    }

    expression_destroy(cond->test);
    code_block_destroy(cond->consequence);
    ape_free(cond, ape_freeArg);
}

// INTERNAL
static expression_t *expression_make(expression_type_t type) {
    expression_t *res = ape_malloc(sizeof(expression_t), ape_mallocArg);
    res->type = type;
    res->pos = src_pos_invalid;
    return res;
}

static statement_t* statement_make(statement_type_t type) {
    statement_t *res = ape_malloc(sizeof(statement_t), ape_mallocArg);
    res->type = type;
    res->pos = src_pos_invalid;
    return res;
}
//FILE_END
//FILE_START:parser.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#ifndef APE_AMALGAMATED
#include "parser.h"
#include "error.h"
#endif

typedef enum precedence {
    PRECEDENCE_LOWEST = 0,
    PRECEDENCE_ASSIGN,      // a = b
    PRECEDENCE_LOGICAL_OR,  // ||
    PRECEDENCE_LOGICAL_AND, // &&
    PRECEDENCE_BIT_OR,      // |
    PRECEDENCE_BIT_XOR,     // ^
    PRECEDENCE_BIT_AND,     // &
    PRECEDENCE_EQUALS,      // == !=
    PRECEDENCE_LESSGREATER, // >, >=, <, <=
    PRECEDENCE_SHIFT,       // << >>
    PRECEDENCE_SUM,         // + -
    PRECEDENCE_PRODUCT,     // * / %
    PRECEDENCE_PREFIX,      // -X or !X
    PRECEDENCE_CALL,        // myFunction(X)
    PRECEDENCE_INDEX,       // arr[x]
    PRECEDENCE_DOT,         // obj.foo
} precedence_t;

static void next_token(parser_t *parser);
static statement_t* parse_statement(parser_t *p);
static statement_t* parse_define_statement(parser_t *p);
static statement_t* parse_if_statement(parser_t *p);
static statement_t* parse_return_statement(parser_t *p);
static statement_t* parse_expression_statement(parser_t *p);
static statement_t* parse_while_loop_statement(parser_t *p);
static statement_t* parse_break_statement(parser_t *p);
static statement_t* parse_continue_statement(parser_t *p);
static statement_t* parse_for_loop_statement(parser_t *p);
static statement_t* parse_foreach(parser_t *p);
static statement_t* parse_classic_for_loop(parser_t *p);
static statement_t* parse_function_statement(parser_t *p);
static statement_t* parse_block_statement(parser_t *p);
static statement_t* parse_import_statement(parser_t *p);
static statement_t* parse_recover_statement(parser_t *p);

static code_block_t* parse_code_block(parser_t *p);

static expression_t* parse_expression(parser_t *p, precedence_t prec);
static expression_t* parse_identifier(parser_t *p);
static expression_t* parse_number_literal(parser_t *p);
static expression_t* parse_bool_literal(parser_t *p);
static expression_t* parse_string_literal(parser_t *p);
static expression_t* parse_null_literal(parser_t *p);
static expression_t* parse_array_literal(parser_t *p);
static expression_t* parse_map_literal(parser_t *p);
static expression_t* parse_prefix_expression(parser_t *p);
static expression_t* parse_infix_expression(parser_t *p, expression_t *left);
static expression_t* parse_grouped_expression(parser_t *p);
static expression_t* parse_function_literal(parser_t *p);
static bool parse_function_parameters(parser_t *p, array(ident_t) *out_params);
static expression_t* parse_call_expression(parser_t *p, expression_t *left);
static ptrarray(expression_t)* parse_expression_list(parser_t *p, token_type_t start_token, token_type_t end_token, bool trailing_comma_allowed);
static expression_t* parse_index_expression(parser_t *p, expression_t *left);
static expression_t* parse_dot_expression(parser_t *p, expression_t *left);
static expression_t* parse_assign_expression(parser_t *p, expression_t *left);
static expression_t* parse_logical_expression(parser_t *p, expression_t *left);

static precedence_t get_precedence(token_type_t tk);
static operator_t token_to_operator(token_type_t tk);

static bool cur_token_is(parser_t *p, token_type_t type);
static bool peek_token_is(parser_t *p, token_type_t type);
static bool expect_current(parser_t *p, token_type_t type);

static char escape_char(const char c);
static char* process_and_copy_string(const char *input, size_t len);

parser_t* parser_make(const ape_config_t *config, ptrarray(error_t) *errors) {
    parser_t *parser = ape_malloc(sizeof(parser_t), ape_mallocArg);
    memset(parser, 0, sizeof(parser_t));
    APE_ASSERT(config);

    parser->config = config;
    parser->errors = errors;

    parser->prefix_parse_fns[TOKEN_IDENT] = parse_identifier;
    parser->prefix_parse_fns[TOKEN_NUMBER] = parse_number_literal;
    parser->prefix_parse_fns[TOKEN_TRUE] = parse_bool_literal;
    parser->prefix_parse_fns[TOKEN_FALSE] = parse_bool_literal;
    parser->prefix_parse_fns[TOKEN_STRING] = parse_string_literal;
    parser->prefix_parse_fns[TOKEN_NULL] = parse_null_literal;
    parser->prefix_parse_fns[TOKEN_BANG] = parse_prefix_expression;
    parser->prefix_parse_fns[TOKEN_MINUS] = parse_prefix_expression;
    parser->prefix_parse_fns[TOKEN_LPAREN] = parse_grouped_expression;
    parser->prefix_parse_fns[TOKEN_FUNCTION] = parse_function_literal;
    parser->prefix_parse_fns[TOKEN_LBRACKET] = parse_array_literal;
    parser->prefix_parse_fns[TOKEN_LBRACE] = parse_map_literal;

    parser->infix_parse_fns[TOKEN_PLUS] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_MINUS] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_SLASH] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_ASTERISK] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_PERCENT] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_EQ] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_NOT_EQ] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_LT] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_LTE] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_GT] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_GTE] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_LPAREN] = parse_call_expression;
    parser->infix_parse_fns[TOKEN_LBRACKET] = parse_index_expression;
    parser->infix_parse_fns[TOKEN_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_PLUS_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_MINUS_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_SLASH_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_ASTERISK_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_PERCENT_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_BIT_AND_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_BIT_OR_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_BIT_XOR_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_LSHIFT_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_RSHIFT_ASSIGN] = parse_assign_expression;
    parser->infix_parse_fns[TOKEN_DOT] = parse_dot_expression;
    parser->infix_parse_fns[TOKEN_AND] = parse_logical_expression;
    parser->infix_parse_fns[TOKEN_OR] = parse_logical_expression;
    parser->infix_parse_fns[TOKEN_BIT_AND] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_BIT_OR] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_BIT_XOR] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_LSHIFT] = parse_infix_expression;
    parser->infix_parse_fns[TOKEN_RSHIFT] = parse_infix_expression;

    parser->depth = 0;

    return parser;
}

void parser_destroy(parser_t *parser) {
    if (!parser) {
        return;
    }
    memset(parser, 0, sizeof(parser_t));
    ape_free(parser, ape_freeArg);
}

ptrarray(statement_t)* parser_parse_all(parser_t *parser,  const char *input, compiled_file_t *file) {
    parser->depth = 0;

    lexer_init(&parser->lexer, input, file);

    next_token(parser);
    next_token(parser);

    ptrarray(statement_t)* statements = ptrarray_make();

    while (!cur_token_is(parser, TOKEN_EOF)) {
        if (cur_token_is(parser, TOKEN_SEMICOLON)) {
            next_token(parser);
            continue;
        }
        statement_t *stmt = parse_statement(parser);
        if (stmt) {
            ptrarray_add(statements, stmt);
        } else {
            goto err;
        }
    }

    if (ptrarray_count(parser->errors) > 0) {
        goto err;
    }

    return statements;
err:
    ptrarray_destroy_with_items(statements, statement_destroy);
    return NULL;
}

// INTERNAL
static void next_token(parser_t *p) {
    p->cur_token = p->peek_token;
    p->peek_token = lexer_next_token(&p->lexer);
}

static statement_t* parse_statement(parser_t *p) {
    src_pos_t pos = p->cur_token.pos;

    statement_t *res = NULL;
    switch (p->cur_token.type) {
        case TOKEN_VAR:
        case TOKEN_CONST: {
            res = parse_define_statement(p);
            break;
        }
        case TOKEN_IF: {
            res = parse_if_statement(p);
            break;
        }
        case TOKEN_RETURN: {
            res = parse_return_statement(p);
            break;
        }
        case TOKEN_WHILE: {
            res = parse_while_loop_statement(p);
            break;
        }
        case TOKEN_BREAK: {
            res = parse_break_statement(p);
            break;
        }
        case TOKEN_FOR: {
            res = parse_for_loop_statement(p);
            break;
        }
        case TOKEN_FUNCTION: {
            if (peek_token_is(p, TOKEN_IDENT)) {
                res = parse_function_statement(p);
            } else {
                res = parse_expression_statement(p);
            }
            break;
        }
        case TOKEN_LBRACE: {
            if (p->config->repl_mode && p->depth == 0) {
                res = parse_expression_statement(p);
            } else {
                res = parse_block_statement(p);
            }
            break;
        }
        case TOKEN_CONTINUE: {
            res = parse_continue_statement(p);
            break;
        }
        case TOKEN_IMPORT: {
            res = parse_import_statement(p);
            break;
        }
        case TOKEN_RECOVER: {
            res = parse_recover_statement(p);
            break;
        }
        default: {
            res = parse_expression_statement(p);
            break;
        }
    }
    if (res) {
        res->pos = pos;
    }
    return res;
}

static statement_t* parse_define_statement(parser_t *p) {
    ident_t name_ident;
    expression_t *value = NULL;

    bool assignable = cur_token_is(p, TOKEN_VAR);

    next_token(p);

    if (!expect_current(p, TOKEN_IDENT)) {
        goto err;
    }

    name_ident = ident_make(p->cur_token);

    next_token(p);

    if (!expect_current(p, TOKEN_ASSIGN)) {
        goto err;
    }

    next_token(p);

    value = parse_expression(p, PRECEDENCE_LOWEST);
    if (!value) {
        goto err;
    }

    if (value->type == EXPRESSION_FUNCTION_LITERAL) {
        value->fn_literal.name = ape_strdup(name_ident.value);
    }

    return statement_make_define(name_ident, value, assignable);
err:
    expression_destroy(value);
    ident_deinit(&name_ident);
    return NULL;
}

static statement_t* parse_if_statement(parser_t *p) {
    ptrarray(if_case_t) *cases = ptrarray_make();
    code_block_t *alternative = NULL;

    next_token(p);

    if (!expect_current(p, TOKEN_LPAREN)) {
        goto err;
    }

    next_token(p);

    if_case_t *cond = if_case_make(NULL, NULL);
    ptrarray_add(cases, cond);

    cond->test = parse_expression(p, PRECEDENCE_LOWEST);
    if (!cond->test) {
        goto err;
    }

    if (!expect_current(p, TOKEN_RPAREN)) {
        goto err;
    }

    next_token(p);

    cond->consequence = parse_code_block(p);
    if (!cond->consequence) {
        goto err;
    }

    while (cur_token_is(p, TOKEN_ELSE)) {
        next_token(p);

        if (cur_token_is(p, TOKEN_IF)) {
            next_token(p);

            if (!expect_current(p, TOKEN_LPAREN)) {
                goto err;
            }

            next_token(p);

            if_case_t *elif = if_case_make(NULL, NULL);
            ptrarray_add(cases, elif);

            elif->test = parse_expression(p, PRECEDENCE_LOWEST);
            if (!cond->test) {
                goto err;
            }

            if (!expect_current(p, TOKEN_RPAREN)) {
                goto err;
            }

            next_token(p);

            elif->consequence = parse_code_block(p);
            if (!cond->consequence) {
                goto err;
            }
        } else {
            alternative = parse_code_block(p);
            if (!alternative) {
                goto err;
            }
        }
    }

    return statement_make_if(cases, alternative);
err:
    ptrarray_destroy_with_items(cases, if_case_destroy);
    code_block_destroy(alternative);
    return NULL;
}

static statement_t* parse_return_statement(parser_t *p) {
    expression_t *expr = NULL;

    next_token(p);

    if (!cur_token_is(p, TOKEN_SEMICOLON) && !cur_token_is(p, TOKEN_RBRACE) && !cur_token_is(p, TOKEN_EOF)) {
        expr = parse_expression(p, PRECEDENCE_LOWEST);
        if (!expr) {
            return NULL;
        }
    }

    return statement_make_return(expr);
}

static statement_t* parse_expression_statement(parser_t *p) {
    expression_t *expr = parse_expression(p, PRECEDENCE_LOWEST);
    if (!expr) {
        return NULL;
    }

    if (expr && (!p->config->repl_mode || p->depth > 0)) {
        if (expr->type != EXPRESSION_ASSIGN && expr->type != EXPRESSION_CALL) {
            error_t *err = error_makef(ERROR_PARSING, expr->pos,
                                       "Only assignments and function calls can be expression statements");
            ptrarray_add(p->errors, err);
            expression_destroy(expr);
            return NULL;
        }
    }

    return statement_make_expression(expr);
}

static statement_t* parse_while_loop_statement(parser_t *p) {
    expression_t *test = NULL;

    next_token(p);

    if (!expect_current(p, TOKEN_LPAREN)) {
        goto err;
    }

    next_token(p);

    test = parse_expression(p, PRECEDENCE_LOWEST);
    if (!test) {
        goto err;
    }

    if (!expect_current(p, TOKEN_RPAREN)) {
        goto err;
    }

    next_token(p);

    code_block_t *body = parse_code_block(p);
    if (!body) {
        goto err;
    }

    return statement_make_while_loop(test, body);
err:
    expression_destroy(test);
    return NULL;
}

static statement_t* parse_break_statement(parser_t *p) {
    next_token(p);
    return statement_make_break();
}

static statement_t* parse_continue_statement(parser_t *p) {
    next_token(p);
    return statement_make_continue();
}

static statement_t* parse_block_statement(parser_t *p) {
    code_block_t *block = parse_code_block(p);
    if (!block) {
        return NULL;
    }
    return statement_make_block(block);
}

static statement_t* parse_import_statement(parser_t *p) {
    next_token(p);

    if (!expect_current(p, TOKEN_STRING)) {
        return NULL;
    }

    char *processed_name = process_and_copy_string(p->cur_token.literal, p->cur_token.len);
    if (!processed_name) {
        error_t *err = error_make(ERROR_PARSING, p->cur_token.pos, "Error when parsing module name");
        ptrarray_add(p->errors, err);
        return NULL;
    }
    next_token(p);
    statement_t *result = statement_make_import(processed_name);
    return result;
}

static statement_t* parse_recover_statement(parser_t *p) {
    next_token(p);

    if (!expect_current(p, TOKEN_LPAREN)) {
        return NULL;
    }
    next_token(p);


    if (!expect_current(p, TOKEN_IDENT)) {
        return NULL;
    }

    ident_t error_ident = ident_make(p->cur_token);
    next_token(p);

    if (!expect_current(p, TOKEN_RPAREN)) {
        goto err;
    }
    next_token(p);

    code_block_t *body = parse_code_block(p);
    if (!body) {
        goto err;
    }

    return statement_make_recover(error_ident, body);
err:
    ident_deinit(&error_ident);
    return NULL;

}

static statement_t* parse_for_loop_statement(parser_t *p) {
    next_token(p);

    if (!expect_current(p, TOKEN_LPAREN)) {
        return NULL;
    }

    next_token(p);

    if (cur_token_is(p, TOKEN_IDENT) && peek_token_is(p, TOKEN_IN)) {
        return parse_foreach(p);
    } else {
        return parse_classic_for_loop(p);
    }
}

static statement_t* parse_foreach(parser_t *p) {
    expression_t *source = NULL;
    ident_t iterator_ident = ident_make(p->cur_token);

    next_token(p);

    if (!expect_current(p, TOKEN_IN)) {
        goto err;
    }

    next_token(p);

    source = parse_expression(p, PRECEDENCE_LOWEST);
    if (!source) {
        goto err;
    }

    if (!expect_current(p, TOKEN_RPAREN)) {
        goto err;
    }

    next_token(p);

    code_block_t *body = parse_code_block(p);
    if (!body) {
        goto err;
    }

    return statement_make_foreach(iterator_ident, source, body);
err:
    ident_deinit(&iterator_ident);
    expression_destroy(source);
    return NULL;
}

static statement_t* parse_classic_for_loop(parser_t *p) {
    statement_t *init = NULL;
    expression_t *test = NULL;
    expression_t *update = NULL;
    code_block_t *body = NULL;

    if (!cur_token_is(p, TOKEN_SEMICOLON)) {
        init = parse_statement(p);
        if (!init) {
            goto err;
        }
        if (init->type != STATEMENT_DEFINE && init->type != STATEMENT_EXPRESSION) {
            error_t *err = error_makef(ERROR_PARSING, init->pos,
                                       "for loop's init clause should be a define statement or an expression");
            ptrarray_add(p->errors, err);
            goto err;
        }
        if (!expect_current(p, TOKEN_SEMICOLON)) {
            goto err;
        }
    }

    next_token(p);

    if (!cur_token_is(p, TOKEN_SEMICOLON)) {
        test = parse_expression(p, PRECEDENCE_LOWEST);
        if (!test) {
            goto err;
        }
        if (!expect_current(p, TOKEN_SEMICOLON)) {
            goto err;
        }
    }

    next_token(p);

    if (!cur_token_is(p, TOKEN_RPAREN)) {
        update = parse_expression(p, PRECEDENCE_LOWEST);
        if (!update) {
            goto err;
        }
        if (!expect_current(p, TOKEN_RPAREN)) {
            goto err;
        }
    }

    next_token(p);

    body = parse_code_block(p);
    if (!body) {
        goto err;
    }

    return statement_make_for_loop(init, test, update, body);
err:
    statement_destroy(init);
    expression_destroy(test);
    expression_destroy(update);
    code_block_destroy(body);
    return NULL;
}

static statement_t* parse_function_statement(parser_t *p) {
    ident_t name_ident;

    expression_t* value = NULL;

    src_pos_t pos = p->cur_token.pos;

    next_token(p);

    if (!expect_current(p, TOKEN_IDENT)) {
        goto err;
    }

    name_ident = ident_make(p->cur_token);

    next_token(p);

    value = parse_function_literal(p);
    if (!value) {
        goto err;
    }

    value->pos = pos;
    value->fn_literal.name = ape_strdup(name_ident.value);

    return statement_make_define(name_ident, value, false);
err:
    expression_destroy(value);
    ident_deinit(&name_ident);
    return NULL;
}

static code_block_t* parse_code_block(parser_t *p) {
    if (!expect_current(p, TOKEN_LBRACE)) {
        return NULL;
    }

    next_token(p);
    p->depth++;

    ptrarray(statement_t)* statements = ptrarray_make();

    while (!cur_token_is(p, TOKEN_RBRACE)) {
        if (cur_token_is(p, TOKEN_EOF)) {
            error_t *err = error_make(ERROR_PARSING, p->cur_token.pos, "Unexpected EOF");
            ptrarray_add(p->errors, err);
            goto err;
        }
        if (cur_token_is(p, TOKEN_SEMICOLON)) {
            next_token(p);
            continue;
        }
        statement_t *stmt = parse_statement(p);
        if (stmt) {
            ptrarray_add(statements, stmt);
        } else {
            goto err;
        }
    }

    next_token(p);

    p->depth--;

    return code_block_make(statements);

err:
    p->depth--;
    ptrarray_destroy_with_items(statements, statement_destroy);
    return NULL;
}

static expression_t* parse_expression(parser_t *p, precedence_t prec) {
    src_pos_t pos = p->cur_token.pos;

    if (p->cur_token.type == TOKEN_ILLEGAL) {
        error_t *err = error_make(ERROR_PARSING, p->cur_token.pos, "Illegal token");
        ptrarray_add(p->errors, err);
        return NULL;
    }

    prefix_parse_fn prefix = p->prefix_parse_fns[p->cur_token.type];
    if (!prefix) {
        char *literal = token_duplicate_literal(&p->cur_token);
        error_t *err = error_makef(ERROR_PARSING, p->cur_token.pos,
                                  "No prefix parse function for \"%s\" found", literal);
        ptrarray_add(p->errors, err);
        ape_free(literal, ape_freeArg);
        return NULL;
    }

    expression_t *left_expr = prefix(p);
    if (!left_expr) {
        return NULL;
    }
    left_expr->pos = pos;

    while (!cur_token_is(p, TOKEN_SEMICOLON) && prec < get_precedence(p->cur_token.type)) {
        infix_parse_fn infix = p->infix_parse_fns[p->cur_token.type];
        if (!infix) {
            return left_expr;
        }
        pos = p->cur_token.pos;
        expression_t *new_left_expr = infix(p, left_expr);
        if (!new_left_expr) {
            expression_destroy(left_expr);
            return NULL;
        }
        new_left_expr->pos = pos;
        left_expr = new_left_expr;
    }

    return left_expr;
}

static expression_t* parse_identifier(parser_t *p) {
    ident_t ident = ident_make(p->cur_token);
    expression_t *res = expression_make_ident(ident);
    next_token(p);
    return res;
}

static expression_t* parse_number_literal(parser_t *p) {
    char *end;
    double number = 0;
    errno = 0;
    number = strtod(p->cur_token.literal, &end);
    long parsed_len = end - p->cur_token.literal;
    if (errno || parsed_len != p->cur_token.len) {
        char *literal = token_duplicate_literal(&p->cur_token);
        error_t *err = error_makef(ERROR_PARSING, p->cur_token.pos,
                                  "Parsing number literal \"%s\" failed", literal);
        ptrarray_add(p->errors, err);
        ape_free(literal, ape_freeArg);
        return NULL;
    }
    next_token(p);
    return expression_make_number_literal(number);
}

static expression_t* parse_bool_literal(parser_t *p) {
    expression_t *res = expression_make_bool_literal(p->cur_token.type == TOKEN_TRUE);
    next_token(p);
    return res;
}

static expression_t* parse_string_literal(parser_t *p) {
    char *processed_literal = process_and_copy_string(p->cur_token.literal, p->cur_token.len);
    if (!processed_literal) {
        error_t *err = error_make(ERROR_PARSING, p->cur_token.pos, "Error when parsing string literal");
        ptrarray_add(p->errors, err);
        return NULL;
    }
    next_token(p);
    return expression_make_string_literal(processed_literal);
}

static expression_t* parse_null_literal(parser_t *p) {
    next_token(p);
    return expression_make_null_literal();
}

static expression_t* parse_array_literal(parser_t *p) {
    ptrarray(expression_t) *array = parse_expression_list(p, TOKEN_LBRACKET, TOKEN_RBRACKET, true);
    if (!array) {
        return NULL;
    }
    return expression_make_array_literal(array);
}

static expression_t* parse_map_literal(parser_t *p) {
    ptrarray(expression_t) *keys = ptrarray_make();
    ptrarray(expression_t) *values = ptrarray_make();

    next_token(p);

    while (!cur_token_is(p, TOKEN_RBRACE)) {
        expression_t *key = NULL;
        if (cur_token_is(p, TOKEN_IDENT)) {
            key = expression_make_string_literal(token_duplicate_literal(&p->cur_token));
            key->pos = p->cur_token.pos;
            next_token(p);
        } else {
            key = parse_expression(p, PRECEDENCE_LOWEST);
            if (!key) {
                goto err;
            }
            switch (key->type) {
                case EXPRESSION_STRING_LITERAL:
                case EXPRESSION_NUMBER_LITERAL:
                case EXPRESSION_BOOL_LITERAL: {
                    break;
                }
                default: {
                    error_t *err = error_makef(ERROR_PARSING, key->pos, "Invalid map literal key type");
                    ptrarray_add(p->errors, err);
                    expression_destroy(key);
                    goto err;
                }
            }
        }

        if (!key) {
            goto err;
        }

        ptrarray_add(keys, key);

        if (!expect_current(p, TOKEN_COLON)) {
            goto err;
        }

        next_token(p);

        expression_t *value = parse_expression(p, PRECEDENCE_LOWEST);
        if (!value) {
            goto err;
        }
        ptrarray_add(values, value);

        if (cur_token_is(p, TOKEN_RBRACE)) {
            break;
        }

        if (!expect_current(p, TOKEN_COMMA)) {
            goto err;
        }

        next_token(p);
    }

    next_token(p);

    return expression_make_map_literal(keys, values);
err:
    ptrarray_destroy_with_items(keys, expression_destroy);
    ptrarray_destroy_with_items(values, expression_destroy);
    return NULL;
}

static expression_t* parse_prefix_expression(parser_t *p) {
    operator_t op = token_to_operator(p->cur_token.type);
    next_token(p);
    expression_t *right = parse_expression(p, PRECEDENCE_PREFIX);
    if (!right) {
        return NULL;
    }
    return expression_make_prefix(op, right);
}

static expression_t* parse_infix_expression(parser_t *p, expression_t *left) {
    operator_t op = token_to_operator(p->cur_token.type);
    precedence_t prec = get_precedence(p->cur_token.type);
    next_token(p);
    expression_t *right = parse_expression(p, prec);
    if (!right) {
        return NULL;
    }
    return expression_make_infix(op, left, right);
}

static expression_t* parse_grouped_expression(parser_t *p) {
    next_token(p);
    expression_t *expr = parse_expression(p, PRECEDENCE_LOWEST);
    if (!expr || !expect_current(p, TOKEN_RPAREN)) {
        expression_destroy(expr);
        return NULL;
    }
    next_token(p);
    return expr;
}

static expression_t* parse_function_literal(parser_t *p) {
    p->depth += 1;
    array(ident) *params = NULL;
    code_block_t *body = NULL;

    if (cur_token_is(p, TOKEN_FUNCTION)) {
        next_token(p);
    }

    params = array_make(ident_t);

    bool ok = parse_function_parameters(p, params);

    if (!ok) {
        goto err;
    }

    body = parse_code_block(p);
    if (!body) {
        goto err;
    }

    p->depth -= 1;

    return expression_make_fn_literal(params, body);
err:
    array_destroy_with_items(params, ident_deinit);
    p->depth -= 1;
    return NULL;
}

static bool parse_function_parameters(parser_t *p, array(ident_t) *out_params) {
    if (!expect_current(p, TOKEN_LPAREN)) {
        return false;
    }

    next_token(p);

    if (cur_token_is(p, TOKEN_RPAREN)) {
        next_token(p);
        return true;
    }

    if (!expect_current(p, TOKEN_IDENT)) {
        return false;
    }

    ident_t ident = ident_make(p->cur_token);
    array_add(out_params, &ident);

    next_token(p);

    while (cur_token_is(p, TOKEN_COMMA)) {
        next_token(p);

        if (!expect_current(p, TOKEN_IDENT)) {
            return false;
        }

        ident_t ident = ident_make(p->cur_token);
        array_add(out_params, &ident);

        next_token(p);
    }

    if (!expect_current(p, TOKEN_RPAREN)) {
        return false;
    }

    next_token(p);

    return true;
}

static expression_t* parse_call_expression(parser_t *p, expression_t *left) {
    expression_t *function = left;
    ptrarray(expression_t) *args = parse_expression_list(p, TOKEN_LPAREN, TOKEN_RPAREN, false);
    if (!args) {
        return NULL;
    }
    return expression_make_call(function, args);
}

static ptrarray(expression_t)* parse_expression_list(parser_t *p, token_type_t start_token, token_type_t end_token, bool trailing_comma_allowed) {
    if (!expect_current(p, start_token)) {
        return NULL;
    }

    next_token(p);

    ptrarray(expression_t)* res = ptrarray_make();

    if (cur_token_is(p, end_token)) {
        next_token(p);
        return res;
    }

    expression_t *arg_expr = parse_expression(p, PRECEDENCE_LOWEST);
    if (!arg_expr) {
        goto err;
    }
    ptrarray_add(res, arg_expr);

    while (cur_token_is(p, TOKEN_COMMA)) {
        next_token(p);

        if (cur_token_is(p, end_token)) {
            break;
        }
        arg_expr = parse_expression(p, PRECEDENCE_LOWEST);
        if (!arg_expr) {
            goto err;
        }
        ptrarray_add(res, arg_expr);
    }

    if (!expect_current(p, end_token)) {
        goto err;
    }

    next_token(p);

    return res;
err:
    ptrarray_destroy_with_items(res, expression_destroy);
    return NULL;
}

static expression_t* parse_index_expression(parser_t *p, expression_t *left) {
    next_token(p);

    expression_t *index = parse_expression(p, PRECEDENCE_LOWEST);
    if (!index) {
        return NULL;
    }

    if (!expect_current(p, TOKEN_RBRACKET)) {
        expression_destroy(index);
        return NULL;
    }

    next_token(p);

    return expression_make_index(left, index);
}

static expression_t* parse_assign_expression(parser_t *p, expression_t *left) {
    expression_t *source = NULL;
    expression_t *left_copy = NULL;
    token_type_t assign_type = p->cur_token.type;

    next_token(p);

    source = parse_expression(p, PRECEDENCE_LOWEST);
    if (!source) {
        goto err;
    }

    switch (assign_type) {
        case TOKEN_PLUS_ASSIGN:
        case TOKEN_MINUS_ASSIGN:
        case TOKEN_SLASH_ASSIGN:
        case TOKEN_ASTERISK_ASSIGN:
        case TOKEN_PERCENT_ASSIGN:
        case TOKEN_BIT_AND_ASSIGN:
        case TOKEN_BIT_OR_ASSIGN:
        case TOKEN_BIT_XOR_ASSIGN:
        case TOKEN_LSHIFT_ASSIGN:
        case TOKEN_RSHIFT_ASSIGN:
        {
            operator_t op = token_to_operator(assign_type);
            expression_t *left_copy = expression_copy(left);
            if (!left_copy) {
                goto err;
            }
            src_pos_t pos = source->pos;
            expression_t *new_source = expression_make_infix(op, left_copy, source);
            if (!new_source) {
                goto err;
            }
            new_source->pos = pos;
            source = new_source;
            break;
        }
        case TOKEN_ASSIGN: break;
        default: APE_ASSERT(false); break;
    }

    return expression_make_assign(left, source);
err:
    expression_destroy(left_copy);
    expression_destroy(source);
    return NULL;
}

static expression_t* parse_logical_expression(parser_t *p, expression_t *left) {
    operator_t op = token_to_operator(p->cur_token.type);
    precedence_t prec = get_precedence(p->cur_token.type);
    next_token(p);
    expression_t *right = parse_expression(p, prec);
    if (!right) {
        return NULL;
    }
    return expression_make_logical(op, left, right);
}

static expression_t* parse_dot_expression(parser_t *p, expression_t *left) {
    next_token(p);

    if (!expect_current(p, TOKEN_IDENT)) {
        return NULL;
    }

    expression_t *index = expression_make_string_literal(token_duplicate_literal(&p->cur_token));
    if (!index) {
        return NULL;
    }
    index->pos = p->cur_token.pos;

    next_token(p);

    return expression_make_index(left, index);
}

static precedence_t get_precedence(token_type_t tk) {
    switch (tk) {
        case TOKEN_EQ:              return PRECEDENCE_EQUALS;
        case TOKEN_NOT_EQ:          return PRECEDENCE_EQUALS;
        case TOKEN_LT:              return PRECEDENCE_LESSGREATER;
        case TOKEN_LTE:             return PRECEDENCE_LESSGREATER;
        case TOKEN_GT:              return PRECEDENCE_LESSGREATER;
        case TOKEN_GTE:             return PRECEDENCE_LESSGREATER;
        case TOKEN_PLUS:            return PRECEDENCE_SUM;
        case TOKEN_MINUS:           return PRECEDENCE_SUM;
        case TOKEN_SLASH:           return PRECEDENCE_PRODUCT;
        case TOKEN_ASTERISK:        return PRECEDENCE_PRODUCT;
        case TOKEN_PERCENT:         return PRECEDENCE_PRODUCT;
        case TOKEN_LPAREN:          return PRECEDENCE_CALL;
        case TOKEN_LBRACKET:        return PRECEDENCE_INDEX;
        case TOKEN_ASSIGN:          return PRECEDENCE_ASSIGN;
        case TOKEN_PLUS_ASSIGN:     return PRECEDENCE_ASSIGN;
        case TOKEN_MINUS_ASSIGN:    return PRECEDENCE_ASSIGN;
        case TOKEN_ASTERISK_ASSIGN: return PRECEDENCE_ASSIGN;
        case TOKEN_SLASH_ASSIGN:    return PRECEDENCE_ASSIGN;
        case TOKEN_PERCENT_ASSIGN:  return PRECEDENCE_ASSIGN;
        case TOKEN_BIT_AND_ASSIGN:  return PRECEDENCE_ASSIGN;
        case TOKEN_BIT_OR_ASSIGN:   return PRECEDENCE_ASSIGN;
        case TOKEN_BIT_XOR_ASSIGN:  return PRECEDENCE_ASSIGN;
        case TOKEN_LSHIFT_ASSIGN:   return PRECEDENCE_ASSIGN;
        case TOKEN_RSHIFT_ASSIGN:   return PRECEDENCE_ASSIGN;
        case TOKEN_DOT:             return PRECEDENCE_DOT;
        case TOKEN_AND:             return PRECEDENCE_LOGICAL_AND;
        case TOKEN_OR:              return PRECEDENCE_LOGICAL_OR;
        case TOKEN_BIT_OR:          return PRECEDENCE_BIT_OR;
        case TOKEN_BIT_XOR:         return PRECEDENCE_BIT_XOR;
        case TOKEN_BIT_AND:         return PRECEDENCE_BIT_AND;
        case TOKEN_LSHIFT:          return PRECEDENCE_SHIFT;
        case TOKEN_RSHIFT:          return PRECEDENCE_SHIFT;
        default:                    return PRECEDENCE_LOWEST;
    }
}

static operator_t token_to_operator(token_type_t tk) {
    switch (tk) {
        case TOKEN_ASSIGN:          return OPERATOR_ASSIGN;
        case TOKEN_PLUS:            return OPERATOR_PLUS;
        case TOKEN_MINUS:           return OPERATOR_MINUS;
        case TOKEN_BANG:            return OPERATOR_BANG;
        case TOKEN_ASTERISK:        return OPERATOR_ASTERISK;
        case TOKEN_SLASH:           return OPERATOR_SLASH;
        case TOKEN_LT:              return OPERATOR_LT;
        case TOKEN_LTE:             return OPERATOR_LTE;
        case TOKEN_GT:              return OPERATOR_GT;
        case TOKEN_GTE:             return OPERATOR_GTE;
        case TOKEN_EQ:              return OPERATOR_EQ;
        case TOKEN_NOT_EQ:          return OPERATOR_NOT_EQ;
        case TOKEN_PERCENT:         return OPERATOR_MODULUS;
        case TOKEN_AND:             return OPERATOR_LOGICAL_AND;
        case TOKEN_OR:              return OPERATOR_LOGICAL_OR;
        case TOKEN_PLUS_ASSIGN:     return OPERATOR_PLUS;
        case TOKEN_MINUS_ASSIGN:    return OPERATOR_MINUS;
        case TOKEN_ASTERISK_ASSIGN: return OPERATOR_ASTERISK;
        case TOKEN_SLASH_ASSIGN:    return OPERATOR_SLASH;
        case TOKEN_PERCENT_ASSIGN:  return OPERATOR_MODULUS;
        case TOKEN_BIT_AND_ASSIGN:  return OPERATOR_BIT_AND;
        case TOKEN_BIT_OR_ASSIGN:   return OPERATOR_BIT_OR;
        case TOKEN_BIT_XOR_ASSIGN:  return OPERATOR_BIT_XOR;
        case TOKEN_LSHIFT_ASSIGN:   return OPERATOR_LSHIFT;
        case TOKEN_RSHIFT_ASSIGN:   return OPERATOR_RSHIFT;
        case TOKEN_BIT_AND:         return OPERATOR_BIT_AND;
        case TOKEN_BIT_OR:          return OPERATOR_BIT_OR;
        case TOKEN_BIT_XOR:         return OPERATOR_BIT_XOR;
        case TOKEN_LSHIFT:          return OPERATOR_LSHIFT;
        case TOKEN_RSHIFT:          return OPERATOR_RSHIFT;
        default: {
            APE_ASSERT(false);
            return OPERATOR_NONE;
        }
    }
}

static bool cur_token_is(parser_t *p, token_type_t type) {
    return p->cur_token.type == type;
}

static bool peek_token_is(parser_t *p, token_type_t type) {
    return p->peek_token.type == type;
}

static bool expect_current(parser_t *p, token_type_t type) {
    if (!cur_token_is(p, type)) {
        const char *expected_type_str = token_type_to_string(type);
        const char *actual_type_str = token_type_to_string(p->cur_token.type);
        error_t *err = error_makef(ERROR_PARSING, p->cur_token.pos,
                                   "Expected current token to be \"%s\", got \"%s\" instead",
                                   expected_type_str, actual_type_str);
        ptrarray_add(p->errors, err);
        return false;
    }
    return true;
}

static char escape_char(const char c) {
    switch (c) {
        case '\"': return '\"';
        case '\\': return '\\';
        case '/':  return '/';
        case 'b':  return '\b';
        case 'f':  return '\f';
        case 'n':  return '\n';
        case 'r':  return '\r';
        case 't':  return '\t';
        case '0':  return '\0';
        default: {
            APE_ASSERT(false);
            return -1;
        }
    }
}

static char* process_and_copy_string(const char *input, size_t len) {
    char *output = ape_malloc(len + 1, ape_mallocArg);

    size_t in_i = 0;
    size_t out_i = 0;

    while (input[in_i] != '\0' && in_i < len) {
        if (input[in_i] == '\\') {
            in_i++;
            output[out_i] = escape_char(input[in_i]);
            if (output[out_i] < 0) {
                goto error;
            }
        } else {
            output[out_i] = input[in_i];
        }
        out_i++;
        in_i++;
    }
    output[out_i] = '\0';
    return output;
error:
    ape_free(output, ape_freeArg);
    return NULL;
}
//FILE_END
//FILE_START:symbol_table.c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef APE_AMALGAMATED
#include "symbol_table.h"
#include "builtins.h"
#endif

static block_scope_t* block_scope_copy(block_scope_t *scope);
static void set_symbol(symbol_table_t *table, symbol_t *symbol);
static int next_symbol_index(symbol_table_t *table);
static int count_num_definitions(symbol_table_t *table);

symbol_t *symbol_make(const char *name, symbol_type_t type, int index, bool assignable) {
    symbol_t *symbol = ape_malloc(sizeof(symbol_t), ape_mallocArg);
    symbol->name = ape_strdup(name);
    symbol->type = type;
    symbol->index = index;
    symbol->assignable = assignable;
    return symbol;
}

void symbol_destroy(symbol_t *symbol) {
    if (!symbol) {
        return;
    }
    ape_free(symbol->name, ape_freeArg);
    ape_free(symbol, ape_freeArg);
}

symbol_t* symbol_copy(const symbol_t *symbol) {
    return symbol_make(symbol->name, symbol->type, symbol->index, symbol->assignable);
}

symbol_table_t *symbol_table_make(symbol_table_t *outer) {
    symbol_table_t *table = ape_malloc(sizeof(symbol_table_t), ape_mallocArg);
    memset(table, 0, sizeof(symbol_table_t));
    table->max_num_definitions = 0;
    table->outer = outer;
    table->block_scopes = ptrarray_make();
    symbol_table_push_block_scope(table);
    table->free_symbols = ptrarray_make();
    if (!outer) {
        for (int i = 0; i < builtins_count(); i++) {
            const char *name = builtins_get_name(i);
            symbol_table_define_native_function(table, name, i);
        }
    }
    return table;
}

void symbol_table_destroy(symbol_table_t *table) {
    if (!table) {
        return;
    }

    while (ptrarray_count(table->block_scopes) > 0) {
        symbol_table_pop_block_scope(table);
    }
    ptrarray_destroy(table->block_scopes);
    ptrarray_destroy_with_items(table->free_symbols, symbol_destroy);
    ape_free(table, ape_freeArg);
}

symbol_table_t* symbol_table_copy(symbol_table_t *table) {
    symbol_table_t *copy = ape_malloc(sizeof(symbol_table_t), ape_mallocArg);
    memset(copy, 0, sizeof(symbol_table_t));
    copy->outer = table->outer;
    copy->block_scopes = ptrarray_copy_with_items(table->block_scopes, block_scope_copy);
    copy->free_symbols = ptrarray_copy_with_items(table->free_symbols, symbol_copy);
    copy->max_num_definitions = table->max_num_definitions;
    return copy;
}

void symbol_table_add_module_symbol(symbol_table_t *st, const symbol_t *symbol) {
    if (symbol->type != SYMBOL_GLOBAL) {
        APE_ASSERT(false);
        return;
    }
    if (symbol_table_symbol_is_defined(st, symbol->name)) {
        return;
    }
    symbol_t *copy = symbol_copy(symbol);
    set_symbol(st, copy);
}

symbol_t *symbol_table_define(symbol_table_t *table, const char *name, bool assignable) {
    if (strchr(name, ':')) {
        return NULL; // module symbol
    }
    if (APE_STREQ(name, "this")) {
        return NULL; // this is reserved
    }
    symbol_type_t symbol_type = table->outer == NULL ? SYMBOL_GLOBAL : SYMBOL_LOCAL;
    int ix = next_symbol_index(table);
    symbol_t *symbol = symbol_make(name, symbol_type, ix, assignable);
    set_symbol(table, symbol);
    block_scope_t *top_scope = ptrarray_top(table->block_scopes);
    top_scope->num_definitions++;
    int definitions_count = count_num_definitions(table);
    if (definitions_count > table->max_num_definitions) {
        table->max_num_definitions = definitions_count;
    }
    return symbol;
}

symbol_t *symbol_table_define_native_function(symbol_table_t *st, const char *name, int ix) {
    symbol_t *symbol = symbol_make(name, SYMBOL_NATIVE_FUNCTION, ix, false);
    set_symbol(st, symbol);
    return symbol;
}

symbol_t *symbol_table_define_free(symbol_table_t *st, symbol_t *original) {
    symbol_t *copy = symbol_make(original->name, original->type, original->index, original->assignable);
    ptrarray_add(st->free_symbols, copy);

    symbol_t *symbol = symbol_make(original->name, SYMBOL_FREE, ptrarray_count(st->free_symbols) - 1, original->assignable);
    set_symbol(st, symbol);

    return symbol;
}

symbol_t * symbol_table_define_function_name(symbol_table_t *st, const char *name, bool assignable) {
    if (strchr(name, ':')) {
        return NULL; // module symbol
    }
    symbol_t *symbol = symbol_make(name, SYMBOL_FUNCTION, 0, assignable);
    set_symbol(st, symbol);
    return symbol;
}

symbol_t *symbol_table_define_this(symbol_table_t *st) {
    symbol_t *symbol = symbol_make("this", SYMBOL_THIS, 0, false);
    set_symbol(st, symbol);
    return symbol;
}

symbol_t *symbol_table_resolve(symbol_table_t *table, const char *name) {
    symbol_t *symbol = NULL;
    block_scope_t *scope = NULL;
    for (int i = ptrarray_count(table->block_scopes) - 1; i >= 0; i--) {
        scope = ptrarray_get(table->block_scopes, i);
        symbol = dict_get(scope->store, name);
        if (symbol) {
            break;
        }
    }

    if (symbol && symbol->type == SYMBOL_THIS) {
        symbol = symbol_table_define_free(table, symbol);
    }

    if (!symbol && table->outer) {
        symbol = symbol_table_resolve(table->outer, name);
        if (!symbol || symbol->type == SYMBOL_GLOBAL || symbol->type == SYMBOL_NATIVE_FUNCTION) {
            return symbol;
        }
        symbol = symbol_table_define_free(table, symbol);
    }
    return symbol;
}

bool symbol_table_symbol_is_defined(symbol_table_t *table, const char *name) { // todo: rename to something more obvious
    block_scope_t *top_scope = ptrarray_top(table->block_scopes);
    symbol_t *existing = dict_get(top_scope->store, name);
    if (existing) {
        return true;
    }
    return false;
}

void symbol_table_push_block_scope(symbol_table_t *table) {
    block_scope_t *new_scope = ape_malloc(sizeof(block_scope_t), ape_mallocArg);
    new_scope->store = dict_make();
    new_scope->num_definitions = 0;
    new_scope->offset = count_num_definitions(table);
    ptrarray_push(table->block_scopes, new_scope);
}

void symbol_table_pop_block_scope(symbol_table_t *table) {
    block_scope_t *top_scope = ptrarray_top(table->block_scopes);
    ptrarray_pop(table->block_scopes);
    dict_destroy_with_items(top_scope->store, symbol_destroy);
    ape_free(top_scope, ape_freeArg);
}

block_scope_t* symbol_table_get_block_scope(symbol_table_t *table) {
    block_scope_t *top_scope = ptrarray_top(table->block_scopes);
    return top_scope;
}


bool symbol_table_is_global_scope(symbol_table_t *table) {
    return table->outer == NULL;
}

bool symbol_table_is_top_block_scope(symbol_table_t *table) {
    return ptrarray_count(table->block_scopes) == 1;
}

bool symbol_table_is_top_global_scope(symbol_table_t *table) {
    return symbol_table_is_global_scope(table) && symbol_table_is_top_block_scope(table);
}

// INTERNAL
static block_scope_t* block_scope_copy(block_scope_t *scope) {
    block_scope_t *copy = ape_malloc(sizeof(block_scope_t), ape_mallocArg);
    copy->num_definitions = scope->num_definitions;
    copy->offset = scope->offset;
    copy->store = dict_copy_with_items(scope->store, symbol_copy);
    return copy;
}

static void set_symbol(symbol_table_t *table, symbol_t *symbol) {
    block_scope_t *top_scope = ptrarray_top(table->block_scopes);
    symbol_t *existing = dict_get(top_scope->store, symbol->name);
    if (existing) {
        symbol_destroy(existing);
    }
    dict_set(top_scope->store, symbol->name, symbol);
}

static int next_symbol_index(symbol_table_t *table) {
    block_scope_t *top_scope = ptrarray_top(table->block_scopes);
    int ix = top_scope->offset + top_scope->num_definitions;
    return ix;
}

static int count_num_definitions(symbol_table_t *table) {
    int count = 0;
    for (int i = ptrarray_count(table->block_scopes) - 1; i >= 0; i--) {
        block_scope_t *scope = ptrarray_get(table->block_scopes, i);
        count += scope->num_definitions;
    }
    return count;
}
//FILE_END
//FILE_START:code.c
#include <stdlib.h>

#ifndef APE_AMALGAMATED
#include "code.h"

#include "common.h"
#include "collections.h"
#endif

static opcode_definition_t g_definitions[OPCODE_MAX + 1] = {
    {"NONE", 0, {0}},
    {"CONSTANT", 1, {2}},
    {"ADD", 0, {0}},
    {"POP", 0, {0}},
    {"SUB", 0, {0}},
    {"MUL", 0, {0}},
    {"DIV", 0, {0}},
    {"MOD", 0, {0}},
    {"TRUE", 0, {0}},
    {"FALSE", 0, {0}},
    {"COMPARE", 0, {0}},
    {"EQUAL", 0, {0}},
    {"NOT_EQUAL", 0, {0}},
    {"GREATER_THAN", 0, {0}},
    {"GREATER_THAN_EQUAL", 0, {0}},
    {"MINUS", 0, {0}},
    {"BANG", 0, {0}},
    {"JUMP", 1, {2}},
    {"JUMP_IF_FALSE", 1, {2}},
    {"JUMP_IF_TRUE", 1, {2}},
    {"NULL", 0, {0}},
    {"GET_GLOBAL", 1, {2}},
    {"SET_GLOBAL", 1, {2}},
    {"DEFINE_GLOBAL", 1, {2}},
    {"ARRAY", 1, {2}},
    {"MAP_START", 1, {2}},
    {"MAP_END", 1, {2}},
    {"GET_THIS", 0, {0}},
    {"GET_INDEX", 0, {0}},
    {"SET_INDEX", 0, {0}},
    {"GET_VALUE_AT", 0, {0}},
    {"CALL", 1, {1}},
    {"RETURN_VALUE", 0, {0}},
    {"RETURN", 0, {0}},
    {"GET_LOCAL", 1, {1}},
    {"DEFINE_LOCAL", 1, {1}},
    {"SET_LOCAL", 1, {1}},
    {"GET_NATIVE_FUNCTION", 1, {2}},
    {"FUNCTION", 2, {2, 1}},
    {"GET_FREE", 1, {1}},
    {"SET_FREE", 1, {1}},
    {"CURRENT_FUNCTION", 0, {0}},
    {"DUP", 0, {0}},
    {"NUMBER", 1, {8}},
    {"LEN", 0, {0}},
    {"SET_RECOVER", 1, {2}},
    {"OR", 0, {0}},
    {"XOR", 0, {0}},
    {"AND", 0, {0}},
    {"LSHIFT", 0, {0}},
    {"RSHIFT", 0, {0}},
    {"INVALID_MAX", 0, {0}},
};

opcode_definition_t* opcode_lookup(opcode_t op) {
    if (op <= OPCODE_NONE || op >= OPCODE_MAX) {
        return NULL;
    }
    return &g_definitions[op];
}

const char *opcode_get_name(opcode_t op) {
    if (op <= OPCODE_NONE || op >= OPCODE_MAX) {
        return NULL;
    }
    return g_definitions[op].name;
}

int code_make(opcode_t op, int operands_count, uint64_t *operands, array(uint8_t) *res) {
    opcode_definition_t *def = opcode_lookup(op);
    if (!def) {
        return 0;
    }

    int instr_len = 1;
    for (int i = 0; i < def->num_operands; i++) {
        instr_len += def->operand_widths[i];
    }

    uint8_t val = op;
    array_add(res, &val);

    for (int i = 0; i < operands_count; i++) {
        int width = def->operand_widths[i];
        switch (width) {
            case 1: {
                val = operands[i];
                array_add(res, &val);
                break;
            }
            case 2: {
                val = operands[i] >> 8;
                array_add(res, &val);
                val = operands[i] >> 0;
                array_add(res, &val);
                break;
            }
            case 4: {
                val = operands[i] >> 24;
                array_add(res, &val);
                val = operands[i] >> 16;
                array_add(res, &val);
                val = operands[i] >> 8;
                array_add(res, &val);
                val = operands[i] >> 0;
                array_add(res, &val);
                break;
            }
            case 8: {
                val = operands[i] >> 56;
                array_add(res, &val);
                val = operands[i] >> 48;
                array_add(res, &val);
                val = operands[i] >> 40;
                array_add(res, &val);
                val = operands[i] >> 32;
                array_add(res, &val);
                val = operands[i] >> 24;
                array_add(res, &val);
                val = operands[i] >> 16;
                array_add(res, &val);
                val = operands[i] >> 8;
                array_add(res, &val);
                val = operands[i] >> 0;
                array_add(res, &val);
                break;
            }
            default: {
                APE_ASSERT(false);
                break;
            }
        }
    }

    return instr_len;
}

void code_to_string(uint8_t *code, src_pos_t *source_positions, size_t code_size, strbuf_t *res) {
    unsigned pos = 0;
    while (pos < code_size) {
        uint8_t op = code[pos];
        opcode_definition_t *def = opcode_lookup(op);
        APE_ASSERT(def);
        if (source_positions) {
            src_pos_t src_pos = source_positions[pos];
            strbuf_appendf(res, "%d:%-4d\t%04d\t%s", src_pos.line, src_pos.column, pos, def->name);
        } else {
            strbuf_appendf(res, "%04d %s", pos, def->name);
        }
        pos += 1;

        uint64_t operands[2];
        code_read_operands(def, code + pos, operands);
        for (int i = 0; i < def->num_operands; i++) {
            if (op == OPCODE_NUMBER) {
                double val_double = ape_uint64_to_double(operands[i]);
                strbuf_appendf(res, " %1.17g", val_double);
            } else {
                strbuf_appendf(res, " %lu", operands[i]);
            }
            pos += def->operand_widths[i];
        }
        strbuf_append(res, "\n");

    }
    return;
}

bool code_read_operands(opcode_definition_t *def, uint8_t *instr, uint64_t out_operands[2]) {
    int offset = 0;
    for (int i = 0; i < def->num_operands; i++) {
        int operand_width = def->operand_widths[i];
        switch (operand_width) {
            case 1: {
                out_operands[i] = instr[offset];
                break;
            }
            case 2: {
                uint64_t operand = 0;
                operand = operand | (instr[offset] << 8);
                operand = operand | (instr[offset + 1]);
                out_operands[i] = operand;
                break;
            }
            case 4: {
                uint64_t operand = 0;
                operand = operand | (instr[offset + 0] << 24);
                operand = operand | (instr[offset + 1] << 16);
                operand = operand | (instr[offset + 2] << 8);
                operand = operand | (instr[offset + 3]);
                out_operands[i] = operand;
                break;
            }
            case 8: {
                uint64_t operand = 0;
                operand = operand | ((uint64_t)instr[offset + 0] << 56);
                operand = operand | ((uint64_t)instr[offset + 1] << 48);
                operand = operand | ((uint64_t)instr[offset + 2] << 40);
                operand = operand | ((uint64_t)instr[offset + 3] << 32);
                operand = operand | ((uint64_t)instr[offset + 4] << 24);
                operand = operand | ((uint64_t)instr[offset + 5] << 16);
                operand = operand | ((uint64_t)instr[offset + 6] << 8);
                operand = operand | ((uint64_t)instr[offset + 7]);
                out_operands[i] = operand;
                break;
            }
            default: {
                APE_ASSERT(false);
                return false;
            }
        }
        offset += operand_width;
    }
    return true;;
}
//FILE_END
//FILE_START:compilation_scope.c
#ifndef APE_AMALGAMATED
#include "compilation_scope.h"
#endif

compilation_scope_t *compilation_scope_make(compilation_scope_t *outer) {
    compilation_scope_t *scope = ape_malloc(sizeof(compilation_scope_t), ape_mallocArg);
    memset(scope, 0, sizeof(compilation_scope_t));
    scope->outer = outer;
    scope->bytecode = array_make(uint8_t);
    scope->src_positions = array_make(src_pos_t);
    return scope;
}

void compilation_scope_destroy(compilation_scope_t *scope) {
    array_destroy(scope->bytecode);
    array_destroy(scope->src_positions);
    ape_free(scope, ape_freeArg);
}

compilation_result_t* compilation_scope_orphan_result(compilation_scope_t *scope) {
    compilation_result_t *res = compilation_result_make(array_data(scope->bytecode),
                                                        array_data(scope->src_positions),
                                                        array_count(scope->bytecode));
    array_orphan_data(scope->bytecode);
    array_orphan_data(scope->src_positions);
    return res;
}

compilation_result_t* compilation_result_make(uint8_t *bytecode, src_pos_t *src_positions, int count) {
    compilation_result_t *res = ape_malloc(sizeof(compilation_result_t), ape_mallocArg);
    memset(res, 0, sizeof(compilation_result_t));
    res->bytecode = bytecode;
    res->src_positions = src_positions;
    res->count = count;
    return res;
}

void compilation_result_destroy(compilation_result_t *res) {
    if (!res) {
        return;
    }
    ape_free(res->bytecode, ape_freeArg);
    ape_free(res->src_positions, ape_freeArg);
    ape_free(res, ape_freeArg);
}
//FILE_END
//FILE_START:compiler.c
#include <stdlib.h>
#include <math.h>

#ifndef APE_AMALGAMATED
#include "compiler.h"

#include "ape.h"
#include "ast.h"
#include "object.h"
#include "gc.h"
#include "code.h"
#include "symbol_table.h"
#include "error.h"
#endif

static bool compile_code(compiler_t *comp, const char *code);
static bool compile_statements(compiler_t *comp, ptrarray(statement_t) *statements);
static bool import_module(compiler_t *comp, const statement_t *import_stmt);
static bool compile_statement(compiler_t *comp, const statement_t *stmt);
static bool compile_expression(compiler_t *comp, const expression_t *expr);
static bool compile_code_block(compiler_t *comp, const code_block_t *block);
static int  add_constant(compiler_t *comp, object_t obj);
static void change_uint16_operand(compiler_t *comp, int ip, uint16_t operand);
static bool last_opcode_is(compiler_t *comp, opcode_t op);
static void read_symbol(compiler_t *comp, symbol_t *symbol);
static void write_symbol(compiler_t *comp, symbol_t *symbol, bool define);

static void push_break_ip(compiler_t *comp, int ip);
static void pop_break_ip(compiler_t *comp);
static int  get_break_ip(compiler_t *comp);

static void push_continue_ip(compiler_t *comp, int ip);
static void pop_continue_ip(compiler_t *comp);
static int  get_continue_ip(compiler_t *comp);

static int  get_ip(compiler_t *comp);

static array(src_pos_t)* get_src_positions(compiler_t *comp);
static array(uint8_t)*   get_bytecode(compiler_t *comp);

static void push_file_scope(compiler_t *comp, const char *filepath, module_t *module);
static void pop_file_scope(compiler_t *comp);

static void set_compilation_scope(compiler_t *comp, compilation_scope_t *scope);

static module_t* get_current_module(compiler_t *comp);
static module_t* module_make(const char *name);
static void module_destroy(module_t *module);
static void module_add_symbol(module_t *module, const symbol_t *symbol);

static compiled_file_t* compiled_file_make(const char *path);
static void compiled_file_destroy(compiled_file_t *file);

static const char* get_module_name(const char *path);
static symbol_t* define_symbol(compiler_t *comp, src_pos_t pos, const char *name, bool assignable, bool can_shadow);

static bool is_comparison(operator_t op);

compiler_t *compiler_make(const ape_config_t *config, gcmem_t *mem, ptrarray(error_t) *errors) {
    compiler_t *comp = ape_malloc(sizeof(compiler_t), ape_mallocArg);
    memset(comp, 0, sizeof(compiler_t));
    APE_ASSERT(config);
    comp->config = config;
    comp->mem = mem;
    comp->file_scopes = ptrarray_make();
    comp->constants = array_make(object_t);
    comp->errors = errors;
    comp->break_ip_stack = array_make(int);
    comp->continue_ip_stack = array_make(int);
    comp->src_positions_stack = array_make(src_pos_t);
    comp->modules = dict_make();
    comp->files = ptrarray_make();
    compiler_push_compilation_scope(comp);
    push_file_scope(comp, "none", NULL);
    return comp;
}

void compiler_destroy(compiler_t *comp) {
    if (!comp) {
        return;
    }
    array_destroy(comp->constants);
    array_destroy(comp->continue_ip_stack);
    array_destroy(comp->break_ip_stack);
    array_destroy(comp->src_positions_stack);
    while (compiler_get_compilation_scope(comp)) {
        compiler_pop_compilation_scope(comp);
    }
    while (ptrarray_count(comp->file_scopes) > 0) {
        pop_file_scope(comp);
    }
    ptrarray_destroy(comp->file_scopes);
    ptrarray_destroy_with_items(comp->files, compiled_file_destroy);
    dict_destroy_with_items(comp->modules, module_destroy);
    ape_free(comp, ape_freeArg);
}

compilation_result_t* compiler_compile(compiler_t *comp, const char *code) {
    // todo: make compiler_reset function
    array_clear(comp->src_positions_stack);
    array_clear(comp->break_ip_stack);
    array_clear(comp->continue_ip_stack);

    compilation_scope_t *compilation_scope = compiler_get_compilation_scope(comp);
    array_clear(compilation_scope->bytecode);
    array_clear(compilation_scope->src_positions);

    symbol_table_t *global_table_copy = symbol_table_copy(compiler_get_symbol_table(comp));

    bool ok = compile_code(comp, code);

    compilation_scope = compiler_get_compilation_scope(comp);

    while (compilation_scope->outer != NULL) {
        compiler_pop_compilation_scope(comp);
        compilation_scope = compiler_get_compilation_scope(comp);
    }

    if (!ok) {
        while (compiler_get_symbol_table(comp) != NULL) {
            compiler_pop_symbol_table(comp);
        }
        compiler_set_symbol_table(comp, global_table_copy);
        return NULL;
    }

    symbol_table_destroy(global_table_copy);

    compilation_scope = compiler_get_compilation_scope(comp);
    return compilation_scope_orphan_result(compilation_scope);
}

compilation_result_t* compiler_compile_file(compiler_t *comp, const char *path) {
    if (!comp->config->fileio.read_file.read_file) {
        error_t *err = error_make(ERROR_COMPILATION, src_pos_invalid, "File read function not configured");
        ptrarray_add(comp->errors, err);
        return NULL;
    }

    char *code = comp->config->fileio.read_file.read_file(comp->config->fileio.read_file.context, path);
    if (!code) {
        error_t *err = error_makef(ERROR_COMPILATION, src_pos_invalid, "Reading file \"%s\" failed", path);
        ptrarray_add(comp->errors, err);
        return NULL;
    }

    compiled_file_t *file = compiled_file_make(path);
    ptrarray_add(comp->files, file);

    APE_ASSERT(ptrarray_count(comp->file_scopes) == 1);
    file_scope_t *file_scope = ptrarray_top(comp->file_scopes);
    if (!file_scope) {
        APE_ASSERT(false);
        ape_free(code, ape_freeArg);
        return NULL;
    }
    compiled_file_t *prev_file = file_scope->file;
    file_scope->file = file;

    compilation_result_t *res = compiler_compile(comp, code);

    file_scope->file = prev_file;
    ape_free(code, ape_freeArg);
    return res;
}

compilation_scope_t* compiler_get_compilation_scope(compiler_t *comp) {
    return comp->compilation_scope;
}

void compiler_push_compilation_scope(compiler_t *comp) {
    compilation_scope_t *current_scope = compiler_get_compilation_scope(comp);
    compilation_scope_t *new_scope = compilation_scope_make(current_scope);
    set_compilation_scope(comp, new_scope);
}

void compiler_pop_compilation_scope(compiler_t *comp) {
    compilation_scope_t *current_scope = compiler_get_compilation_scope(comp);
    APE_ASSERT(current_scope);
    set_compilation_scope(comp, current_scope->outer);
    compilation_scope_destroy(current_scope);
}

void compiler_push_symbol_table(compiler_t *comp) {
    file_scope_t *file_scope = ptrarray_top(comp->file_scopes);
    if (!file_scope) {
        APE_ASSERT(false);
        return;
    }
    symbol_table_t *current_table = file_scope->symbol_table;
    file_scope->symbol_table = symbol_table_make(current_table);
}

void compiler_pop_symbol_table(compiler_t *comp) {
    file_scope_t *file_scope = ptrarray_top(comp->file_scopes);
    if (!file_scope) {
        APE_ASSERT(false);
        return;
    }
    symbol_table_t *current_table = file_scope->symbol_table;
    if (!current_table) {
        APE_ASSERT(false);
        return;
    }
    file_scope->symbol_table = current_table->outer;
    symbol_table_destroy(current_table);
}

symbol_table_t* compiler_get_symbol_table(compiler_t *comp) {
    file_scope_t *file_scope = ptrarray_top(comp->file_scopes);
    if (!file_scope) {
        APE_ASSERT(false);
        return NULL;
    }
    symbol_table_t *current_table = file_scope->symbol_table;
    if (!current_table) {
        return NULL;
    }
    return current_table;
}

void compiler_set_symbol_table(compiler_t *comp, symbol_table_t *table) {
    file_scope_t *file_scope = ptrarray_top(comp->file_scopes);
    if (!file_scope) {
        APE_ASSERT(false);
        return;
    }
    file_scope->symbol_table = table;
}

opcode_t compiler_last_opcode(compiler_t *comp) {
    compilation_scope_t *current_scope = compiler_get_compilation_scope(comp);
    return current_scope->last_opcode;
}

// INTERNAL
static bool compile_code(compiler_t *comp, const char *code) {
    file_scope_t *file_scope = ptrarray_top(comp->file_scopes);
    APE_ASSERT(file_scope);

    ptrarray(statement_t) *statements = parser_parse_all(file_scope->parser, code, file_scope->file);
    if (!statements) {
        // errors are added by parser
        return false;
    }

    bool ok = compile_statements(comp, statements);

    ptrarray_destroy_with_items(statements, statement_destroy);

    return ok;
}

static bool compile_statements(compiler_t *comp, ptrarray(statement_t) *statements) {
    bool ok = true;
    for (int i = 0; i < ptrarray_count(statements); i++) {
        const statement_t *stmt = ptrarray_get(statements, i);
        ok = compile_statement(comp, stmt);
        if (!ok) {
            break;
        }
    }
    return ok;
}

static bool import_module(compiler_t *comp, const statement_t *import_stmt) {
    bool result = false;
    char *filepath = NULL;

    file_scope_t *file_scope = ptrarray_top(comp->file_scopes);

    const char *module_path = import_stmt->import.path;
    const char *module_name = get_module_name(module_path);

    for (int i = 0; i < ptrarray_count(file_scope->loaded_module_names); i++) {
        const char *loaded_name = ptrarray_get(file_scope->loaded_module_names, i);
        if (kg_streq(loaded_name, module_name)) {
            error_t *err = error_makef(ERROR_COMPILATION, import_stmt->pos, "Module \"%s\" was already imported", module_name);
            ptrarray_add(comp->errors, err);
            result = false;
            goto end;
        }
    }

    strbuf_t *filepath_buf = strbuf_make();
    if (kg_is_path_absolute(module_path)) {
        strbuf_appendf(filepath_buf, "%s.bn", module_path);
    } else {
        strbuf_appendf(filepath_buf, "%s%s.bn", file_scope->file->dir_path, module_path);
    }
    const char *filepath_non_canonicalised = strbuf_get_string(filepath_buf);
    filepath = kg_canonicalise_path(filepath_non_canonicalised);
    strbuf_destroy(filepath_buf);

    symbol_table_t *symbol_table = compiler_get_symbol_table(comp);
    if (symbol_table->outer != NULL || ptrarray_count(symbol_table->block_scopes) > 1) {
        error_t *err = error_make(ERROR_COMPILATION, import_stmt->pos, "Modules can only be imported in global scope");
        ptrarray_add(comp->errors, err);
        result = false;
        goto end;
    }

    for (int i = 0; i < ptrarray_count(comp->file_scopes); i++) {
        file_scope_t *fs = ptrarray_get(comp->file_scopes, i);
        if (APE_STREQ(fs->file->path, filepath)) {
            error_t *err = error_makef(ERROR_COMPILATION, import_stmt->pos, "Cyclic reference of file \"%s\"", filepath);
            ptrarray_add(comp->errors, err);
            result = false;
            goto end;
        }
    }

    module_t *module = dict_get(comp->modules, filepath);
    if (!module) {
        if (!comp->config->fileio.read_file.read_file) {
            error_t *err = error_makef(ERROR_COMPILATION, import_stmt->pos, "Cannot import module \"%s\", file read function not configured", filepath);
            ptrarray_add(comp->errors, err);
            result = false;
            goto end;
        }

        char *code = comp->config->fileio.read_file.read_file(comp->config->fileio.read_file.context, filepath);
        if (!code) {
            error_t *err = error_makef(ERROR_COMPILATION, import_stmt->pos, "Reading module file \"%s\" failed", filepath);
            ptrarray_add(comp->errors, err);
            result = false;
            goto end;
        }

        module = module_make(module_name);
        push_file_scope(comp, filepath, module);
        bool ok = compile_code(comp, code);
        pop_file_scope(comp);
        ape_free(code, ape_freeArg);

        if (!ok) {
            module_destroy(module);
            result = false;
            goto end;
        }

        dict_set(comp->modules, filepath, module);
    }

    for (int i = 0; i < ptrarray_count(module->symbols); i++) {
        symbol_t *symbol = ptrarray_get(module->symbols, i);
        symbol_table_add_module_symbol(symbol_table, symbol);
    }

    ptrarray_add(file_scope->loaded_module_names, ape_strdup(module_name));

    result = true;

end:
    ape_free(filepath, ape_freeArg);
    return result;
}

static bool compile_statement(compiler_t *comp, const statement_t *stmt) {
    bool ok = false;
    array_push(comp->src_positions_stack, &stmt->pos);
    compilation_scope_t *compilation_scope = compiler_get_compilation_scope(comp);
    symbol_table_t *symbol_table = compiler_get_symbol_table(comp);
    switch (stmt->type) {
        case STATEMENT_EXPRESSION: {
            ok = compile_expression(comp, stmt->expression);
            if (!ok) {
                return false;
            }
            compiler_emit(comp, OPCODE_POP, 0, NULL);
            break;
        }
        case STATEMENT_DEFINE: {
            ok = compile_expression(comp, stmt->define.value);
            if (!ok) {
                return false;
            }

            symbol_t *symbol = define_symbol(comp, stmt->define.name.pos, stmt->define.name.value, stmt->define.assignable, false);
            if (!symbol) {
                return false;
            }

            if (symbol->type == SYMBOL_GLOBAL) {
                module_t *module = get_current_module(comp);
                if (module) {
                    module_add_symbol(module, symbol);
                }
            }

            write_symbol(comp, symbol, true);

            break;
        }
        case STATEMENT_IF: {
            const if_statement_t *if_stmt = &stmt->if_statement;

            array(int) *jump_to_end_ips = array_make(int);
            for (int i = 0; i < ptrarray_count(if_stmt->cases); i++) {
                if_case_t *if_case = ptrarray_get(if_stmt->cases, i);

                ok = compile_expression(comp, if_case->test);
                if (!ok) {
                    array_destroy(jump_to_end_ips);
                    return false;
                }

                int next_case_jump_ip = compiler_emit(comp, OPCODE_JUMP_IF_FALSE, 1, (uint64_t[]){0xbeef});

                ok = compile_code_block(comp, if_case->consequence);
                if (!ok) {
                    array_destroy(jump_to_end_ips);
                    return false;
                }

                int jump_to_end_ip = compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){0xbeef});
                array_add(jump_to_end_ips, &jump_to_end_ip);

                int after_elif_ip = get_ip(comp);
                change_uint16_operand(comp, next_case_jump_ip + 1, after_elif_ip);
            }

            if (if_stmt->alternative) {
                ok = compile_code_block(comp, if_stmt->alternative);
                if (!ok) {
                    array_destroy(jump_to_end_ips);
                    return false;
                }
            }

            int after_alt_ip = get_ip(comp);

            for (int i = 0; i < array_count(jump_to_end_ips); i++) {
                int *pos = array_get(jump_to_end_ips, i);
                change_uint16_operand(comp, *pos + 1, after_alt_ip);
            }

            array_destroy(jump_to_end_ips);

            break;
        }
        case STATEMENT_RETURN_VALUE: {
            if (compilation_scope->outer == NULL) {
                error_t *err = error_makef(ERROR_COMPILATION, stmt->pos, "Nothing to return from");
                ptrarray_add(comp->errors, err);
                return false;
            }
            if (stmt->return_value) {
                ok = compile_expression(comp, stmt->return_value);
                if (!ok) {
                    return false;
                }
                compiler_emit(comp, OPCODE_RETURN_VALUE, 0, NULL);
            } else {
                compiler_emit(comp, OPCODE_RETURN, 0, NULL);
            }
            break;
        }
        case STATEMENT_WHILE_LOOP: {
            const while_loop_statement_t *loop = &stmt->while_loop;

            int before_test_ip = get_ip(comp);

            ok = compile_expression(comp, loop->test);
            if (!ok) {
                return false;
            }

            int after_test_ip = get_ip(comp);
            compiler_emit(comp, OPCODE_JUMP_IF_TRUE, 1, (uint64_t[]){after_test_ip + 6});
            int jump_to_after_body_ip = compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){0xdead});

            push_continue_ip(comp, before_test_ip);
            push_break_ip(comp, jump_to_after_body_ip);
            ok = compile_code_block(comp, loop->body);
            if (!ok) {
                return false;
            }
            pop_break_ip(comp);
            pop_continue_ip(comp);

            compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){before_test_ip});

            int after_body_ip = get_ip(comp);
            change_uint16_operand(comp, jump_to_after_body_ip + 1, after_body_ip);

            break;
        }
        case STATEMENT_BREAK: {
            int break_ip = get_break_ip(comp);
            if (break_ip < 0) {
                error_t *err = error_makef(ERROR_COMPILATION, stmt->pos, "Nothing to break from.");
                ptrarray_add(comp->errors, err);
                return false;
            }
            compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){break_ip});
            break;
        }
        case STATEMENT_CONTINUE: {
            int continue_ip = get_continue_ip(comp);
            if (continue_ip < 0) {
                error_t *err = error_makef(ERROR_COMPILATION, stmt->pos, "Nothing to continue from.");
                ptrarray_add(comp->errors, err);
                return false;
            }
            compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){continue_ip});
            break;
        }
        case STATEMENT_FOREACH: {
            const foreach_statement_t *foreach = &stmt->foreach;
            symbol_table_push_block_scope(symbol_table);

            // Init
            symbol_t *index_symbol = define_symbol(comp, stmt->pos, "@i", false, true);
            if (!index_symbol) {
                APE_ASSERT(false);
                return false;
            }

            compiler_emit(comp, OPCODE_NUMBER, 1, (uint64_t[]){0});
            write_symbol(comp, index_symbol, true);
            symbol_t *source_symbol = NULL;
            if (foreach->source->type == EXPRESSION_IDENT) {
                source_symbol = symbol_table_resolve(symbol_table, foreach->source->ident.value);
                if (!source_symbol) {
                    error_t *err = error_makef(ERROR_COMPILATION, foreach->source->pos,
                                              "Symbol \"%s\" could not be resolved", foreach->source->ident.value);
                    ptrarray_add(comp->errors, err);
                    return false;
                }
            } else {
                ok = compile_expression(comp, foreach->source);
                if (!ok) {
                    return false;
                }
                source_symbol = define_symbol(comp, foreach->source->pos, "@source", false, true);
                if (!source_symbol) {
                    APE_ASSERT(false);
                    return false;
                }
                write_symbol(comp, source_symbol, true);
            }

            // Update
            int jump_to_after_update_ip = compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){0xbeef});
            int update_ip = get_ip(comp);
            read_symbol(comp, index_symbol);
            compiler_emit(comp, OPCODE_NUMBER, 1, (uint64_t[]){ape_double_to_uint64(1)});
            compiler_emit(comp, OPCODE_ADD, 0, NULL);
            write_symbol(comp, index_symbol, false);
            int after_update_ip = get_ip(comp);
            change_uint16_operand(comp, jump_to_after_update_ip + 1, after_update_ip);

            // Test
            array_push(comp->src_positions_stack, &foreach->source->pos);
            read_symbol(comp, source_symbol);
            compiler_emit(comp, OPCODE_LEN, 0, NULL);
            array_pop(comp->src_positions_stack, NULL);
            read_symbol(comp, index_symbol);
            compiler_emit(comp, OPCODE_COMPARE, 0, NULL);
            compiler_emit(comp, OPCODE_EQUAL, 0, NULL);

            int after_test_ip = get_ip(comp);
            compiler_emit(comp, OPCODE_JUMP_IF_FALSE, 1, (uint64_t[]){after_test_ip + 6});
            int jump_to_after_body_ip = compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){0xdead});

            read_symbol(comp, source_symbol);
            read_symbol(comp, index_symbol);
            compiler_emit(comp, OPCODE_GET_VALUE_AT, 0, NULL);

            symbol_t *iter_symbol  = define_symbol(comp, foreach->iterator.pos, foreach->iterator.value, false, false);
            if (!iter_symbol) {
                return false;
            }

            write_symbol(comp, iter_symbol, true);

            // Body
            push_continue_ip(comp, update_ip);
            push_break_ip(comp, jump_to_after_body_ip);
            ok = compile_code_block(comp, foreach->body);
            if (!ok) {
                return false;
            }
            pop_break_ip(comp);
            pop_continue_ip(comp);
            compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){update_ip});

            int after_body_ip = get_ip(comp);
            change_uint16_operand(comp, jump_to_after_body_ip + 1, after_body_ip);

            symbol_table_pop_block_scope(symbol_table);
            break;
        }
        case STATEMENT_FOR_LOOP: {
            const for_loop_statement_t *loop = &stmt->for_loop;

            symbol_table_push_block_scope(symbol_table);

            // Init
            bool ok = false;
            if (loop->init) {
                ok = compile_statement(comp, loop->init);
                if (!ok) {
                    return false;
                }
            }
            int jump_to_after_update_ip = compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){0xbeef});

            // Update
            int update_ip = get_ip(comp);
            if (loop->update) {
                ok = compile_expression(comp, loop->update);
                if (!ok) {
                    return false;
                }
                compiler_emit(comp, OPCODE_POP, 0, NULL);
            }
            int after_update_ip = get_ip(comp);
            change_uint16_operand(comp, jump_to_after_update_ip + 1, after_update_ip);

            // Test
            if (loop->test) {
                ok = compile_expression(comp, loop->test);
                if (!ok) {
                    return false;
                }
            } else {
                compiler_emit(comp, OPCODE_TRUE, 0, NULL);
            }
            int after_test_ip = get_ip(comp);

            compiler_emit(comp, OPCODE_JUMP_IF_TRUE, 1, (uint64_t[]){after_test_ip + 6});
            int jmp_to_after_body_ip = compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){0xdead});

            // Body
            push_continue_ip(comp, update_ip);
            push_break_ip(comp, jmp_to_after_body_ip);
            ok = compile_code_block(comp, loop->body);
            if (!ok) {
                return false;
            }
            pop_break_ip(comp);
            pop_continue_ip(comp);
            compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){update_ip});

            int after_body_ip = get_ip(comp);
            change_uint16_operand(comp, jmp_to_after_body_ip + 1, after_body_ip);

            symbol_table_pop_block_scope(symbol_table);
            break;
        }
        case STATEMENT_BLOCK: {
            ok = compile_code_block(comp, stmt->block);
            if (!ok) {
                return false;
            }
            break;
        }
        case STATEMENT_IMPORT: {
            ok = import_module(comp, stmt);
            if (!ok) {
                return false;
            }
            break;
        }
        case STATEMENT_RECOVER: {
            const recover_statement_t *recover = &stmt->recover;

            if (symbol_table_is_global_scope(symbol_table)) {
                error_t *err = error_make(ERROR_COMPILATION, stmt->pos,
                                          "Recover statement cannot be defined in global scope");
                ptrarray_add(comp->errors, err);
                return false;
            }

            if (!symbol_table_is_top_block_scope(symbol_table)) {
                error_t *err = error_make(ERROR_COMPILATION, stmt->pos,
                                          "Recover statement cannot be defined within other statements");
                ptrarray_add(comp->errors, err);
                return false;
            }

            int recover_ip = compiler_emit(comp, OPCODE_SET_RECOVER, 1, (uint64_t[]){0xbeef});
            int jump_to_after_recover_ip = compiler_emit(comp, OPCODE_JUMP, 1, (uint64_t[]){0xbeef});
            int after_jump_to_recover_ip = get_ip(comp);
            change_uint16_operand(comp, recover_ip + 1, after_jump_to_recover_ip);

            symbol_table_push_block_scope(symbol_table);

            symbol_t *error_symbol = define_symbol(comp, recover->error_ident.pos, recover->error_ident.value, false, false);
            if (!error_symbol) {
                return false;
            }

            write_symbol(comp, error_symbol, true);

            ok = compile_code_block(comp, recover->body);
            if (!ok) {
                return false;
            }

            if (!last_opcode_is(comp, OPCODE_RETURN) && !last_opcode_is(comp, OPCODE_RETURN_VALUE)) {
                error_t *err = error_make(ERROR_COMPILATION, stmt->pos,
                                          "Recover body must end with a return statement");
                ptrarray_add(comp->errors, err);
                return false;
            }

            symbol_table_pop_block_scope(symbol_table);

            int after_recover_ip = get_ip(comp);
            change_uint16_operand(comp, jump_to_after_recover_ip + 1, after_recover_ip);

            break;
        }
        default: {
            APE_ASSERT(false);
            return false;
        }
    }
    array_pop(comp->src_positions_stack, NULL);
    return true;
}

static bool compile_expression(compiler_t *comp, const expression_t *expr) {
    bool ok = false;
    array_push(comp->src_positions_stack, &expr->pos);
    compilation_scope_t *compilation_scope = compiler_get_compilation_scope(comp);
    symbol_table_t *symbol_table = compiler_get_symbol_table(comp);

    switch (expr->type) {
        case EXPRESSION_INFIX: {
            bool rearrange = false;

            opcode_t op = OPCODE_NONE;
            switch (expr->infix.op) {
                case OPERATOR_PLUS:        op = OPCODE_ADD; break;
                case OPERATOR_MINUS:       op = OPCODE_SUB; break;
                case OPERATOR_ASTERISK:    op = OPCODE_MUL; break;
                case OPERATOR_SLASH:       op = OPCODE_DIV; break;
                case OPERATOR_MODULUS:     op = OPCODE_MOD; break;
                case OPERATOR_EQ:          op = OPCODE_EQUAL; break;
                case OPERATOR_NOT_EQ:      op = OPCODE_NOT_EQUAL; break;
                case OPERATOR_GT:          op = OPCODE_GREATER_THAN; break;
                case OPERATOR_GTE:         op = OPCODE_GREATER_THAN_EQUAL; break;
                case OPERATOR_LT:          op = OPCODE_GREATER_THAN; rearrange = true; break;
                case OPERATOR_LTE:         op = OPCODE_GREATER_THAN_EQUAL; rearrange = true; break;
                case OPERATOR_BIT_OR:      op = OPCODE_OR; break;
                case OPERATOR_BIT_XOR:     op = OPCODE_XOR; break;
                case OPERATOR_BIT_AND:     op = OPCODE_AND; break;
                case OPERATOR_LSHIFT:      op = OPCODE_LSHIFT; break;
                case OPERATOR_RSHIFT:      op = OPCODE_RSHIFT; break;
                default: {
                    error_t *err = error_makef(ERROR_COMPILATION, expr->pos, "Unknown infix operator");
                    ptrarray_add(comp->errors, err);
                    return false;
                }
            }

            const expression_t *left = rearrange ? expr->infix.right : expr->infix.left;
            const expression_t *right = rearrange ? expr->infix.left : expr->infix.right;

            ok = compile_expression(comp, left);
            if (!ok) {
                return false;
            }

            ok = compile_expression(comp, right);
            if (!ok) {
                return false;
            }

            if (is_comparison(expr->infix.op)) {
                compiler_emit(comp, OPCODE_COMPARE, 0, NULL);
            }

            compiler_emit(comp, op, 0, NULL);

            break;
        }
        case EXPRESSION_NUMBER_LITERAL: {
            double number = expr->number_literal;
            compiler_emit(comp, OPCODE_NUMBER, 1, (uint64_t[]){ape_double_to_uint64(number)});
            break;
        }
        case EXPRESSION_STRING_LITERAL: {
            object_t obj = object_make_string(comp->mem, expr->string_literal);
            int pos = add_constant(comp, obj);
            compiler_emit(comp, OPCODE_CONSTANT, 1, (uint64_t[]){pos});
            break;
        }
        case EXPRESSION_NULL_LITERAL: {
            compiler_emit(comp, OPCODE_NULL, 0, NULL);
            break;
        }
        case EXPRESSION_BOOL_LITERAL: {
            compiler_emit(comp, expr->bool_literal ? OPCODE_TRUE : OPCODE_FALSE, 0, NULL);
            break;
        }
        case EXPRESSION_ARRAY_LITERAL: {
            for (int i = 0; i < ptrarray_count(expr->array); i++) {
                ok = compile_expression(comp, ptrarray_get(expr->array, i));
                if (!ok) {
                    return false;
                }
            }
            compiler_emit(comp, OPCODE_ARRAY, 1, (uint64_t[]){ptrarray_count(expr->array)});
            break;
        }
        case EXPRESSION_MAP_LITERAL: {
            const map_literal_t *map = &expr->map;
            int len = ptrarray_count(map->keys);
            compiler_emit(comp, OPCODE_MAP_START, 1, (uint64_t[]){len * 2});
            for (int i = 0; i < len; i++) {
                const expression_t *key = ptrarray_get(map->keys, i);
                const expression_t *val = ptrarray_get(map->values, i);

                ok = compile_expression(comp, key);
                if (!ok) {
                    return false;
                }

                ok = compile_expression(comp, val);
                if (!ok) {
                    return false;
                }
            }
            compiler_emit(comp, OPCODE_MAP_END, 1, (uint64_t[]){len * 2});
            break;
        }
        case EXPRESSION_PREFIX: {
            ok = compile_expression(comp, expr->prefix.right);
            if (!ok) {
                return false;
            }
            opcode_t op = OPCODE_NONE;
            switch (expr->prefix.op) {
                case OPERATOR_MINUS: op = OPCODE_MINUS; break;
                case OPERATOR_BANG: op = OPCODE_BANG; break;
                default: {
                    error_t *err = error_makef(ERROR_COMPILATION, expr->pos, "Unknown prefix operator.");
                    ptrarray_add(comp->errors, err);
                    return false;
                }
            }
            compiler_emit(comp, op, 0, NULL);
            break;
        }
        case EXPRESSION_IDENT: {
            const ident_t *ident = &expr->ident;
            symbol_t *symbol = symbol_table_resolve(symbol_table, ident->value);
            if (!symbol) {
                error_t *err = error_makef(ERROR_COMPILATION, ident->pos,
                                           "Symbol \"%s\" could not be resolved", ident->value);
                ptrarray_add(comp->errors, err);
                return false;
            }
            read_symbol(comp, symbol);
            break;
        }
        case EXPRESSION_INDEX: {
            const index_expression_t *index = &expr->index_expr;
            ok = compile_expression(comp, index->left);
            if (!ok) {
                return false;
            }
            ok = compile_expression(comp, index->index);
            if (!ok) {
                return false;
            }
            compiler_emit(comp, OPCODE_GET_INDEX, 0, NULL);
            break;
        }
        case EXPRESSION_FUNCTION_LITERAL: {
            const fn_literal_t *fn = &expr->fn_literal;

            compiler_push_compilation_scope(comp);
            compiler_push_symbol_table(comp);
            compilation_scope = compiler_get_compilation_scope(comp);
            symbol_table = compiler_get_symbol_table(comp);

            if (fn->name) {
                symbol_t *fn_symbol = symbol_table_define_function_name(symbol_table, fn->name, false);
                if (!fn_symbol) {
                    error_t *err = error_makef(ERROR_COMPILATION, expr->pos,
                                               "Cannot define symbol \"%s\"", fn->name);
                    ptrarray_add(comp->errors, err);
                    return false;
                }
            }

            symbol_t *this_symbol = symbol_table_define_this(symbol_table);
            if (!this_symbol) {
                error_t *err = error_make(ERROR_COMPILATION, expr->pos, "Cannot define \"this\" symbol");
                ptrarray_add(comp->errors, err);
                return false;
            }

            for (int i = 0; i < array_count(expr->fn_literal.params); i++) {
                ident_t *param = array_get(expr->fn_literal.params, i);
                symbol_t *param_symbol = define_symbol(comp, param->pos, param->value, true, false);
                if (!param_symbol) {
                    return false;
                }
            }

            ok = compile_statements(comp, fn->body->statements);
            if (!ok) {
                return false;
            }

            if (!last_opcode_is(comp, OPCODE_RETURN_VALUE) && !last_opcode_is(comp, OPCODE_RETURN)) {
                compiler_emit(comp, OPCODE_RETURN, 0, NULL);
            }

            ptrarray(symbol_t) *free_symbols = symbol_table->free_symbols;
            symbol_table->free_symbols = NULL; // because it gets destroyed with compiler_pop_compilation_scope()

            int num_locals = symbol_table->max_num_definitions;

            compilation_result_t *comp_res = compilation_scope_orphan_result(compilation_scope);
            compiler_pop_symbol_table(comp);
            compiler_pop_compilation_scope(comp);
            compilation_scope = compiler_get_compilation_scope(comp);
            symbol_table = compiler_get_symbol_table(comp);

            object_t obj = object_make_function(comp->mem, fn->name, comp_res, true,
                                                num_locals, array_count(fn->params), 0);

            for (int i = 0; i < ptrarray_count(free_symbols); i++) {
                symbol_t *symbol = ptrarray_get(free_symbols, i);
                read_symbol(comp, symbol);
            }

            int pos = add_constant(comp, obj);
            compiler_emit(comp, OPCODE_FUNCTION, 2, (uint64_t[]){pos, ptrarray_count(free_symbols)});

            ptrarray_destroy_with_items(free_symbols, symbol_destroy);

            break;
        }
        case EXPRESSION_CALL: {
            ok = compile_expression(comp, expr->call_expr.function);
            if (!ok) {
                return false;
            }

            for (int i = 0; i < ptrarray_count(expr->call_expr.args); i++) {
                const expression_t *arg_expr = ptrarray_get(expr->call_expr.args, i);
                ok = compile_expression(comp, arg_expr);
                if (!ok) {
                    return false;
                }
            }

            compiler_emit(comp, OPCODE_CALL, 1, (uint64_t[]){ptrarray_count(expr->call_expr.args)});
            break;
        }
        case EXPRESSION_ASSIGN: {
            const assign_expression_t *assign = &expr->assign;
            if (assign->dest->type != EXPRESSION_IDENT && assign->dest->type != EXPRESSION_INDEX) {
                error_t *err = error_makef(ERROR_COMPILATION, assign->dest->pos,
                                          "Expression is not assignable.");
                ptrarray_add(comp->errors, err);
                return false;
            }

            ok = compile_expression(comp, assign->source);
            if (!ok) {
                return false;
            }

            compiler_emit(comp, OPCODE_DUP, 0, NULL);

            array_push(comp->src_positions_stack, &assign->dest->pos);
            if (assign->dest->type == EXPRESSION_IDENT) {
                const ident_t *ident = &assign->dest->ident;
                symbol_t *symbol = symbol_table_resolve(symbol_table, ident->value);
                if (!symbol) {
                    error_t *err = error_makef(ERROR_COMPILATION, assign->dest->pos,
                                              "Symbol \"%s\" could not be resolved", ident->value);
                    ptrarray_add(comp->errors, err);
                    return false;
                }
                if (!symbol->assignable) {
                    error_t *err = error_makef(ERROR_COMPILATION, assign->dest->pos,
                                              "Symbol \"%s\" is not assignable", ident->value);
                    ptrarray_add(comp->errors, err);
                    return false;
                }
                write_symbol(comp, symbol, false);
            } else if (assign->dest->type == EXPRESSION_INDEX) {
                const index_expression_t *index = &assign->dest->index_expr;
                ok = compile_expression(comp, index->left);
                if (!ok) {
                    return false;
                }
                ok = compile_expression(comp, index->index);
                if (!ok) {
                    return false;
                }
                compiler_emit(comp, OPCODE_SET_INDEX, 0, NULL);
            }
            array_pop(comp->src_positions_stack, NULL);
            break;
        }
        case EXPRESSION_LOGICAL: {
            const logical_expression_t* logi = &expr->logical;

            ok = compile_expression(comp, logi->left);
            if (!ok) {
                return false;
            }

            compiler_emit(comp, OPCODE_DUP, 0, NULL);

            int after_left_jump_ip = 0;
            if (logi->op == OPERATOR_LOGICAL_AND) {
                after_left_jump_ip = compiler_emit(comp, OPCODE_JUMP_IF_FALSE, 1, (uint64_t[]){0xbeef});
            } else {
                after_left_jump_ip = compiler_emit(comp, OPCODE_JUMP_IF_TRUE, 1, (uint64_t[]){0xbeef});
            }

            compiler_emit(comp, OPCODE_POP, 0, NULL);

            ok = compile_expression(comp, logi->right);
            if (!ok) {
                return false;
            }

            int after_right_ip = get_ip(comp);
            change_uint16_operand(comp, after_left_jump_ip + 1, after_right_ip);

            break;
        }
        default: {
            APE_ASSERT(false);
            break;
        }
    }
    array_pop(comp->src_positions_stack, NULL);
    return true;
}

static bool compile_code_block(compiler_t *comp, const code_block_t *block) {
    symbol_table_t *symbol_table = compiler_get_symbol_table(comp);
    symbol_table_push_block_scope(symbol_table);
    if (ptrarray_count(block->statements) == 0) {
        compiler_emit(comp, OPCODE_NULL, 0, NULL);
        compiler_emit(comp, OPCODE_POP, 0, NULL);
    }
    for (int i = 0; i < ptrarray_count(block->statements); i++) {
        const statement_t *stmt = ptrarray_get(block->statements, i);
        bool ok = compile_statement(comp, stmt);
        if (!ok) {
            return false;
        }
    }
    symbol_table_pop_block_scope(symbol_table);
    return true;
}

static int add_constant(compiler_t *comp, object_t obj) {
    array_add(comp->constants, &obj);
    int pos = array_count(comp->constants) - 1;
    return pos;
}

int compiler_emit(compiler_t *comp, opcode_t op, int operands_count, uint64_t *operands) {
    int ip = get_ip(comp);
    int len = code_make(op, operands_count, operands, get_bytecode(comp));
    for (int i = 0; i < len; i++) {
        src_pos_t *src_pos = array_top(comp->src_positions_stack);
        APE_ASSERT(src_pos->line >= 0);
        APE_ASSERT(src_pos->column >= 0);
        array_add(get_src_positions(comp), src_pos);
    }
    compilation_scope_t *compilation_scope = compiler_get_compilation_scope(comp);
    compilation_scope->last_opcode = op;
    return ip;
}

static void change_uint16_operand(compiler_t *comp, int ip, uint16_t operand) {
    array(uint8_t) *bytecode = get_bytecode(comp);
    if ((ip + 1) >= array_count(bytecode)) {
        APE_ASSERT(false);
        return;
    }
    uint8_t hi = operand >> 8;
    array_set(bytecode, ip, &hi);
    uint8_t lo = operand;
    array_set(bytecode, ip + 1, &lo);
}

static bool last_opcode_is(compiler_t *comp, opcode_t op) {
    opcode_t last_opcode = compiler_last_opcode(comp);
    return last_opcode == op;
}

static void read_symbol(compiler_t *comp, symbol_t *symbol) {
    if (symbol->type == SYMBOL_GLOBAL) {
        compiler_emit(comp, OPCODE_GET_GLOBAL, 1, (uint64_t[]){symbol->index});
    } else if (symbol->type == SYMBOL_NATIVE_FUNCTION) {
        compiler_emit(comp, OPCODE_GET_NATIVE_FUNCTION, 1, (uint64_t[]){symbol->index});
    } else if (symbol->type == SYMBOL_LOCAL) {
        compiler_emit(comp, OPCODE_GET_LOCAL, 1, (uint64_t[]){symbol->index});
    } else if (symbol->type == SYMBOL_FREE) {
        compiler_emit(comp, OPCODE_GET_FREE, 1, (uint64_t[]){symbol->index});
    } else if (symbol->type == SYMBOL_FUNCTION) {
        compiler_emit(comp, OPCODE_CURRENT_FUNCTION, 0, NULL);
    } else if (symbol->type == SYMBOL_THIS) {
        compiler_emit(comp, OPCODE_GET_THIS, 0, NULL);
    }
}

static void write_symbol(compiler_t *comp, symbol_t *symbol, bool define) {
    if (symbol->type == SYMBOL_GLOBAL) {
        if (define) {
            compiler_emit(comp, OPCODE_DEFINE_GLOBAL, 1, (uint64_t[]){symbol->index});
        } else {
            compiler_emit(comp, OPCODE_SET_GLOBAL, 1, (uint64_t[]){symbol->index});
        }
    } else if (symbol->type == SYMBOL_LOCAL) {
        if (define) {
            compiler_emit(comp, OPCODE_DEFINE_LOCAL, 1, (uint64_t[]){symbol->index});
        } else {
            compiler_emit(comp, OPCODE_SET_LOCAL, 1, (uint64_t[]){symbol->index});
        }
    } else if (symbol->type == SYMBOL_FREE) {
        compiler_emit(comp, OPCODE_SET_FREE, 1, (uint64_t[]){symbol->index});
    }
}

static void push_break_ip(compiler_t *comp, int ip) {
    array_push(comp->break_ip_stack, &ip);
}

static void pop_break_ip(compiler_t *comp) {
    if (array_count(comp->break_ip_stack) == 0) {
        APE_ASSERT(false);
        return;
    }
    array_pop(comp->break_ip_stack, NULL);
}

static int get_break_ip(compiler_t *comp) {
    if (array_count(comp->break_ip_stack) == 0) {
        APE_ASSERT(false);
        return -1;
    }
    int *res = array_top(comp->break_ip_stack);
    return *res;
}

static void push_continue_ip(compiler_t *comp, int ip) {
    array_push(comp->continue_ip_stack, &ip);
}

static void pop_continue_ip(compiler_t *comp) {
    if (array_count(comp->continue_ip_stack) == 0) {
        APE_ASSERT(false);
        return;
    }
    array_pop(comp->continue_ip_stack, NULL);
}

static int get_continue_ip(compiler_t *comp) {
    if (array_count(comp->continue_ip_stack) == 0) {
        return -1;
    }
    int *res = array_top(comp->continue_ip_stack);
    return *res;
}

static int get_ip(compiler_t *comp) {
    compilation_scope_t *compilation_scope = compiler_get_compilation_scope(comp);
    return array_count(compilation_scope->bytecode);
}

static array(src_pos_t)* get_src_positions(compiler_t *comp) {
    compilation_scope_t *compilation_scope = compiler_get_compilation_scope(comp);
    return compilation_scope->src_positions;
}

static array(uint8_t)* get_bytecode(compiler_t *comp) {
    compilation_scope_t *compilation_scope = compiler_get_compilation_scope(comp);
    return compilation_scope->bytecode;
}

static void push_file_scope(compiler_t *comp, const char *filepath, module_t *module) {
    symbol_table_t *prev_st = NULL;
    if (ptrarray_count(comp->file_scopes) > 0) {
        prev_st = compiler_get_symbol_table(comp);
    }
    file_scope_t *file_scope = ape_malloc(sizeof(file_scope_t), ape_mallocArg);
    memset(file_scope, 0, sizeof(file_scope_t));
    file_scope->parser = parser_make(comp->config, comp->errors);
    file_scope->symbol_table = NULL;
    file_scope->module = module;
    file_scope->file = compiled_file_make(filepath);
    ptrarray_add(comp->files, file_scope->file);
    file_scope->loaded_module_names = ptrarray_make();

    ptrarray_push(comp->file_scopes, file_scope);
    compiler_push_symbol_table(comp);

    if (prev_st) {
        block_scope_t *prev_st_top_scope = symbol_table_get_block_scope(prev_st);
        symbol_table_t *new_st = compiler_get_symbol_table(comp);
        block_scope_t *new_st_top_scope = symbol_table_get_block_scope(new_st);
        new_st_top_scope->offset = prev_st_top_scope->offset + prev_st_top_scope->num_definitions;
    }
}

static void pop_file_scope(compiler_t *comp) {
    symbol_table_t *popped_st = compiler_get_symbol_table(comp);
    block_scope_t *popped_st_top_scope = symbol_table_get_block_scope(popped_st);
    int popped_num_defs = popped_st_top_scope->num_definitions;

    file_scope_t *scope = ptrarray_top(comp->file_scopes);
    if (!scope) {
        APE_ASSERT(false);
        return;
    }
    while (compiler_get_symbol_table(comp)) {
        compiler_pop_symbol_table(comp);
    }
    ptrarray_destroy_with_items(scope->loaded_module_names, ape_free);
    scope->loaded_module_names = NULL;

    parser_destroy(scope->parser);

    ape_free(scope, ape_freeArg);
    ptrarray_pop(comp->file_scopes);

    if (ptrarray_count(comp->file_scopes) > 0) {
        symbol_table_t *current_st = compiler_get_symbol_table(comp);
        block_scope_t *current_st_top_scope = symbol_table_get_block_scope(current_st);
        current_st_top_scope->num_definitions += popped_num_defs;
    }
}

static void set_compilation_scope(compiler_t *comp, compilation_scope_t *scope) {
    comp->compilation_scope = scope;
}

static module_t* get_current_module(compiler_t *comp) {
    file_scope_t *scope = ptrarray_top(comp->file_scopes);
    return scope->module;
}

static module_t* module_make(const char *name) {
    module_t *module = ape_malloc(sizeof(module_t), ape_mallocArg);
    module->name = ape_strdup(name);
    module->symbols = ptrarray_make();
    return module;
}

static void module_destroy(module_t *module) {
    ape_free(module->name, ape_freeArg);
    ptrarray_destroy_with_items(module->symbols, symbol_destroy);
    ape_free(module, ape_freeArg);
}

static void module_add_symbol(module_t *module, const symbol_t *symbol) {
    strbuf_t *name_buf = strbuf_make();
    strbuf_appendf(name_buf, "%s::%s", module->name, symbol->name);
    symbol_t *module_symbol = symbol_make(strbuf_get_string(name_buf), SYMBOL_GLOBAL, symbol->index, false);
    strbuf_destroy(name_buf);
    ptrarray_add(module->symbols, module_symbol);
}

static compiled_file_t* compiled_file_make(const char *path) {
    compiled_file_t *file = ape_malloc(sizeof(compiled_file_t), ape_mallocArg);
    const char *last_slash_pos = strrchr(path, '/');
    if (last_slash_pos) {
        size_t len = last_slash_pos - path + 1;
        file->dir_path = ape_strndup(path, len);
    } else {
        file->dir_path = ape_strdup("");
    }
    file->path = ape_strdup(path);
    file->lines = ptrarray_make();
    return file;
}

static void compiled_file_destroy(compiled_file_t *file) {
    if (!file) {
        return;
    }
    ptrarray_destroy_with_items(file->lines, ape_free);
    ape_free(file->dir_path, ape_freeArg);
    ape_free(file->path, ape_freeArg);
    ape_free(file, ape_freeArg);
}

static const char* get_module_name(const char *path) {
    const char *last_slash_pos = strrchr(path, '/');
    if (last_slash_pos) {
        return last_slash_pos + 1;
    }
    return path;
}

static symbol_t* define_symbol(compiler_t *comp, src_pos_t pos, const char *name, bool assignable, bool can_shadow) {
    symbol_table_t *symbol_table = compiler_get_symbol_table(comp);
    if (!can_shadow && !symbol_table_is_top_global_scope(symbol_table)) {
        symbol_t *current_symbol = symbol_table_resolve(symbol_table, name);
        if (current_symbol) {
            error_t *err = error_makef(ERROR_COMPILATION, pos, "Symbol \"%s\" is already defined", name);
            ptrarray_add(comp->errors, err);
            return NULL;
        }
    }

    symbol_t *symbol = symbol_table_define(symbol_table, name, assignable);
    if (!symbol) {
        error_t *err = error_makef(ERROR_COMPILATION, pos, "Cannot define symbol \"%s\"", name);
        ptrarray_add(comp->errors, err);
        return false;
    }

    return symbol;
}

static bool is_comparison(operator_t op) {
    switch (op) {
        case OPERATOR_EQ:
        case OPERATOR_NOT_EQ:
        case OPERATOR_GT:
        case OPERATOR_GTE:
        case OPERATOR_LT:
        case OPERATOR_LTE:
            return true;
        default:
            return false;
    }
    return false;
}
//FILE_END
//FILE_START:object.c
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <float.h>
#include <math.h>

#ifndef APE_AMALGAMATED
#include "object.h"
#include "code.h"
#include "compiler.h"
#include "traceback.h"
#include "gc.h"
#endif

#define OBJECT_PATTERN          0xfff8000000000000
#define OBJECT_HEADER_MASK      0xffff000000000000
#define OBJECT_ALLOCATED_HEADER 0xfffc000000000000
#define OBJECT_BOOL_HEADER      0xfff9000000000000
#define OBJECT_NULL_PATTERN     0xfffa000000000000

static object_t object_make(object_type_t type, object_data_t *data);
static object_t object_deep_copy_internal(gcmem_t *mem, object_t obj, valdict(object_t, object_t) *copies);
static bool object_equals_wrapped(const object_t *a, const object_t *b);
static unsigned long object_hash(object_t *obj_ptr);
static unsigned long object_hash_string(const char *str);
static unsigned long object_hash_double(double val);
static bool object_is_number(object_t obj);
static uint64_t get_type_tag(object_type_t type);
static bool freevals_are_allocated(function_t *fun);

object_t object_make_number(double val) {
    object_t o = { .number = val };
    if ((o.handle & OBJECT_PATTERN) == OBJECT_PATTERN) {
        o.handle = 0x7ff8000000000000;
    }
    return o;
}

object_t object_make_bool(bool val) {
    return (object_t) { .handle = OBJECT_BOOL_HEADER | val };
}

object_t object_make_null() {
    return (object_t) { .handle = OBJECT_NULL_PATTERN };
}

object_t object_make_string(gcmem_t *mem, const char *string) {
    object_data_t *obj = gcmem_alloc_object_data(mem, OBJECT_STRING);
    int len = (int)strlen(string);
    if ((len + 1) < OBJECT_STRING_BUF_SIZE) {
        memcpy(obj->string.value_buf, string, len + 1);
        obj->string.is_allocated = false;
    } else {
        obj->string.value_allocated = ape_strdup(string);
        obj->string.is_allocated = true;
    }
    obj->string.hash = object_hash_string(string);
    return object_make(OBJECT_STRING, obj);
}

object_t object_make_string_no_copy(gcmem_t *mem, char *string) {
    object_data_t *obj = gcmem_alloc_object_data(mem, OBJECT_STRING);
    int len = (int)strlen(string);
    if ((len + 1) < OBJECT_STRING_BUF_SIZE) {
        memcpy(obj->string.value_buf, string, len + 1);
        obj->string.hash = object_hash_string(string);
        ape_free(string, ape_freeArg);
        obj->string.is_allocated = false;
    } else {
        obj->string.hash = object_hash_string(string);
        obj->string.value_allocated = string;
        obj->string.is_allocated = true;
    }

    return object_make(OBJECT_STRING, obj);
}

object_t object_make_stringf(gcmem_t *mem, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int to_write = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    va_start(args, fmt);
    char *res = (char*)ape_malloc(to_write + 1, ape_mallocArg);
    int written = vsprintf(res, fmt, args);
    (void)written;
    APE_ASSERT(written == to_write);
    va_end(args);
    return object_make_string_no_copy(mem, res);
}

object_t object_make_native_function(gcmem_t *mem, const char *name, native_fn fn, void *data) {
    object_data_t *obj = gcmem_alloc_object_data(mem, OBJECT_NATIVE_FUNCTION);
    obj->native_function.name = ape_strdup(name);
    obj->native_function.fn = fn;
    obj->native_function.data = data;
    return object_make(OBJECT_NATIVE_FUNCTION, obj);
}

object_t object_make_array(gcmem_t *mem) {
    return object_make_array_with_capacity(mem, 8);
}

object_t object_make_array_with_capacity(gcmem_t *mem, unsigned capacity) {
    array(object_t) *arr = array_make_with_capacity(capacity, sizeof(object_t));
    return object_make_array_with_array(mem, arr);
}

object_t object_make_array_with_array(gcmem_t *mem, array(object_t) *array) {
    object_data_t *data = gcmem_alloc_object_data(mem, OBJECT_ARRAY);
    data->array = array;
    return object_make(OBJECT_ARRAY, data);
}

object_t object_make_map(gcmem_t *mem) {
    return object_make_map_with_capacity(mem, 32);
}

object_t object_make_map_with_capacity(gcmem_t *mem, unsigned capacity) {
    object_data_t *data = gcmem_alloc_object_data(mem, OBJECT_MAP);
    data->map = valdict_make_with_capacity(capacity, sizeof(object_t), sizeof(object_t));
    valdict_set_hash_function(data->map, (collections_hash_fn)object_hash);
    valdict_set_equals_function(data->map, (collections_equals_fn)object_equals_wrapped);
    return object_make(OBJECT_MAP, data);
}

object_t object_make_error(gcmem_t *mem, const char *error) {
    return object_make_error_no_copy(mem, ape_strdup(error));
}

object_t object_make_error_no_copy(gcmem_t *mem, char *error) {
    object_data_t *data = gcmem_alloc_object_data(mem, OBJECT_ERROR);
    data->error.message = error;
    data->error.traceback = NULL;
    return object_make(OBJECT_ERROR, data);
}

object_t object_make_errorf(gcmem_t *mem, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int to_write = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    va_start(args, fmt);
    char *res = (char*)ape_malloc(to_write + 1, ape_mallocArg);
    int written = vsprintf(res, fmt, args);
    (void)written;
    APE_ASSERT(written == to_write);
    va_end(args);
    return object_make_error_no_copy(mem, res);
}

object_t object_make_function(gcmem_t *mem, const char *name, compilation_result_t *comp_res, bool owns_data,
                              int num_locals, int num_args,
                              int free_vals_count) {
    object_data_t *obj = gcmem_alloc_object_data(mem, OBJECT_FUNCTION);
    if (owns_data) {
        obj->function.name = name ? ape_strdup(name) : ape_strdup("anonymous");
    } else {
        obj->function.const_name = name ? name : "anonymous";
    }
    obj->function.comp_result = comp_res;
    obj->function.owns_data = owns_data;
    obj->function.num_locals = num_locals;
    obj->function.num_args = num_args;
    obj->function.free_vals_count = free_vals_count;
    if (free_vals_count >= APE_ARRAY_LEN(obj->function.free_vals_buf)) {
        obj->function.free_vals_allocated = ape_malloc(sizeof(object_t) * free_vals_count, ape_mallocArg);
    }
    return object_make(OBJECT_FUNCTION, obj);
}

object_t object_make_external(gcmem_t *mem, void *data) {
    object_data_t *obj = gcmem_alloc_object_data(mem, OBJECT_EXTERNAL);
    obj->external.data = data;
    obj->external.data_destroy_fn = NULL;
    obj->external.data_copy_fn = NULL;
    return object_make(OBJECT_EXTERNAL, obj);
}

void object_deinit(object_t obj) {
    if (object_is_allocated(obj)) {
        object_data_t *data = object_get_allocated_data(obj);
        object_data_deinit(data);
    }
}

void object_data_deinit(object_data_t *data) {
    switch (data->type) {
        case OBJECT_FREED: {
            APE_ASSERT(false);
            return;
        }
        case OBJECT_STRING: {
            if (data->string.is_allocated) {
                ape_free(data->string.value_allocated, ape_freeArg);
            }
            break;
        }
        case OBJECT_FUNCTION: {
            if (data->function.owns_data) {
                ape_free(data->function.name, ape_freeArg);
                compilation_result_destroy(data->function.comp_result);
            }
            if (freevals_are_allocated(&data->function)) {
                ape_free(data->function.free_vals_allocated, ape_freeArg);
            }
            break;
        }
        case OBJECT_ARRAY: {
            array_destroy(data->array);
            break;
        }
        case OBJECT_MAP: {
            valdict_destroy(data->map);
            break;
        }
        case OBJECT_NATIVE_FUNCTION: {
            ape_free(data->native_function.name, ape_freeArg);
            break;
        }
        case OBJECT_EXTERNAL: {
            if (data->external.data_destroy_fn) {
                data->external.data_destroy_fn(data->external.data);
            }
            break;
        }
        case OBJECT_ERROR: {
            ape_free(data->error.message, ape_freeArg);
            traceback_destroy(data->error.traceback);
            break;
        }
        default: {
            break;
        }
    }
    data->type = OBJECT_FREED;
}

bool object_is_allocated(object_t object) {
    return (object.handle & OBJECT_ALLOCATED_HEADER) == OBJECT_ALLOCATED_HEADER;
}

gcmem_t* object_get_mem(object_t obj) {
    object_data_t *data = object_get_allocated_data(obj);
    return data->mem;
}

bool object_is_hashable(object_t obj) {
    object_type_t type = object_get_type(obj);
    switch (type) {
        case OBJECT_STRING: return true;
        case OBJECT_NUMBER: return true;
        case OBJECT_BOOL: return true;
        default: return false;
    }
}

void object_to_string(object_t obj, strbuf_t *buf, bool quote_str) {
    object_type_t type = object_get_type(obj);
    switch (type) {
        case OBJECT_FREED: {
            strbuf_append(buf, "FREED");
            break;
        }
        case OBJECT_NONE: {
            strbuf_append(buf, "NONE");
            break;
        }
        case OBJECT_NUMBER: {
            double number = object_get_number(obj);
            strbuf_appendf(buf, "%1.10g", number);
            break;
        }
        case OBJECT_BOOL: {
            strbuf_append(buf, object_get_bool(obj) ? "true" : "false");
            break;
        }
        case OBJECT_STRING: {
            const char *string = object_get_string(obj);
            if (quote_str) {
                strbuf_appendf(buf, "\"%s\"", string);
            } else {
                strbuf_append(buf, string);
            }
            break;
        }
        case OBJECT_NULL: {
            strbuf_append(buf, "null");
            break;
        }
        case OBJECT_FUNCTION: {
            const function_t *function = object_get_function(obj);
            strbuf_appendf(buf, "CompiledFunction: %s\n", object_get_function_name(obj));
            code_to_string(function->comp_result->bytecode, function->comp_result->src_positions, function->comp_result->count, buf);
            break;
        }
        case OBJECT_ARRAY: {
            strbuf_append(buf, "[");
            for (int i = 0; i < object_get_array_length(obj); i++) {
                object_t iobj = object_get_array_value_at(obj, i);
                object_to_string(iobj, buf, true);
                if (i < (object_get_array_length(obj) - 1)) {
                    strbuf_append(buf, ", ");
                }
            }
            strbuf_append(buf, "]");
            break;
        }
        case OBJECT_MAP: {
            strbuf_append(buf, "{");
            for (int i = 0; i < object_get_map_length(obj); i++) {
                object_t key = object_get_map_key_at(obj, i);
                object_t val = object_get_map_value_at(obj, i);
                object_to_string(key, buf, true);
                strbuf_append(buf, ": ");
                object_to_string(val, buf, true);
                if (i < (object_get_map_length(obj) - 1)) {
                    strbuf_append(buf, ", ");
                }
            }
            strbuf_append(buf, "}");
            break;
        }
        case OBJECT_NATIVE_FUNCTION: {
            strbuf_append(buf, "NATIVE_FUNCTION");
            break;
        }
        case OBJECT_EXTERNAL: {
            strbuf_append(buf, "EXTERNAL");
            break;
        }
        case OBJECT_ERROR: {
            strbuf_appendf(buf, "ERROR: %s\n", object_get_error_message(obj));
            traceback_t *traceback = object_get_error_traceback(obj);
            APE_ASSERT(traceback);
            if (traceback) {
                strbuf_append(buf, "Traceback:\n");
                traceback_to_string(traceback, buf);
            }
            break;
        }
        case OBJECT_ANY: {
            APE_ASSERT(false);
        }
    }
}

const char *object_get_type_name(const object_type_t type) {
    switch (type) {
        case OBJECT_NONE:            return "NONE";
        case OBJECT_FREED:           return "NONE";
        case OBJECT_NUMBER:          return "NUMBER";
        case OBJECT_BOOL:            return "BOOL";
        case OBJECT_STRING:          return "STRING";
        case OBJECT_NULL:            return "NULL";
        case OBJECT_NATIVE_FUNCTION: return "NATIVE_FUNCTION";
        case OBJECT_ARRAY:           return "ARRAY";
        case OBJECT_MAP:             return "MAP";
        case OBJECT_FUNCTION:        return "FUNCTION";
        case OBJECT_EXTERNAL:        return "EXTERNAL";
        case OBJECT_ERROR:           return "ERROR";
        case OBJECT_ANY:             return "ANY";
    }
    return "NONE";
}

char* object_serialize(object_t object) {
    strbuf_t *buf = strbuf_make();
    object_to_string(object, buf, true);
    char *string = strbuf_get_string_and_destroy(buf);
    return string;
}

object_t object_deep_copy(gcmem_t *mem, object_t obj) {
    valdict(object_t, object_t) *copies = valdict_make(object_t, object_t);
    object_t res = object_deep_copy_internal(mem, obj, copies);
    valdict_destroy(copies);
    return res;
}

object_t object_copy(gcmem_t *mem, object_t obj) {
    object_t copy = object_make_null();
    object_type_t type = object_get_type(obj);
    switch (type) {
        case OBJECT_ANY:
        case OBJECT_FREED:
        case OBJECT_NONE: {
            APE_ASSERT(false);
            copy = object_make_null();
            break;
        }
        case OBJECT_NUMBER:
        case OBJECT_BOOL:
        case OBJECT_NULL:
        case OBJECT_FUNCTION:
        case OBJECT_NATIVE_FUNCTION:
        case OBJECT_ERROR: {
            copy = obj;
            break;
        }
        case OBJECT_STRING: {
            const char *str = object_get_string(obj);
            copy = object_make_string(mem, str);
            break;
        }
        case OBJECT_ARRAY: {
            array(object_t) *array = object_get_array(obj);
            array(object_t) *res_array = array_make(object_t);
            for (int i = 0; i < array_count(array); i++) {
                object_t *array_obj = array_get(array, i);
                array_add(res_array, array_obj);
            }
            copy = object_make_array_with_array(mem, res_array);
            break;
        }
        case OBJECT_MAP: {
            copy = object_make_map(mem);
            for (int i = 0; i < object_get_map_length(obj); i++) {
                object_t key = object_get_map_key_at(obj, i);
                object_t val = object_get_map_value_at(obj, i);
                object_set_map_value(copy, key, val);
            }
            break;
        }
        case OBJECT_EXTERNAL: {
            external_data_t *external = object_get_external_data(obj);
            void *data_copy = NULL;
            if (external->data_copy_fn) {
                data_copy = external->data_copy_fn(external->data);
            } else {
                data_copy = external->data;
            }
            copy = object_make_external(mem, data_copy);
            object_set_external_destroy_function(copy, external->data_destroy_fn);
            object_set_external_copy_function(copy, external->data_copy_fn);
            break;
        }
    }
    return copy;
}

double object_compare(object_t a, object_t b) {
    if (a.handle == b.handle) {
        return 0;
    }

    object_type_t a_type = object_get_type(a);
    object_type_t b_type = object_get_type(b);

    if ((a_type == OBJECT_NUMBER || a_type == OBJECT_BOOL || a_type == OBJECT_NULL)
        && (b_type == OBJECT_NUMBER || b_type == OBJECT_BOOL || b_type == OBJECT_NULL)) {
        double left_val = object_get_number(a);
        double right_val = object_get_number(b);
        return left_val - right_val;
    } else if (a_type == b_type && a_type == OBJECT_STRING) {
        const char *left_string = object_get_string(a);
        const char *right_string = object_get_string(b);
        return strcmp(left_string, right_string);
    } else {
        intptr_t a_data_val = (intptr_t)object_get_allocated_data(a);
        intptr_t b_data_val = (intptr_t)object_get_allocated_data(b);
        return (double)(a_data_val - b_data_val);
    }
}

bool object_equals(object_t a, object_t b) {
    object_type_t a_type = object_get_type(a);
    object_type_t b_type = object_get_type(b);

    if (a_type != b_type) {
        return false;
    }
    double res = object_compare(a, b);
    return APE_DBLEQ(res, 0);
}

external_data_t* object_get_external_data(object_t object) {
    APE_ASSERT(object_get_type(object) == OBJECT_EXTERNAL);
    object_data_t *data = object_get_allocated_data(object);
    return &data->external;
}

bool object_set_external_destroy_function(object_t object, external_data_destroy_fn destroy_fn) {
    APE_ASSERT(object_get_type(object) == OBJECT_EXTERNAL);
    external_data_t* data = object_get_external_data(object);
    if (!data) {
        return false;
    }
    data->data_destroy_fn = destroy_fn;
    return true;
}

object_data_t* object_get_allocated_data(object_t object) {
    APE_ASSERT(object_is_allocated(object) || object_get_type(object) == OBJECT_NULL);
    return (object_data_t*)(object.handle & ~OBJECT_HEADER_MASK);
}

bool object_get_bool(object_t obj) {
    if (object_is_number(obj)) {
        return obj.handle;
    }
    return obj.handle & (~OBJECT_HEADER_MASK);
}

double object_get_number(object_t obj) {
    if (object_is_number(obj)) { // todo: optimise? always return number?
        return obj.number;
    }
    return obj.handle & (~OBJECT_HEADER_MASK);
}

const char * object_get_string(object_t object) {
    APE_ASSERT(object_get_type(object) == OBJECT_STRING);
    object_data_t *data = object_get_allocated_data(object);
    if (data->string.is_allocated) {
        return data->string.value_allocated;
    } else {
        return data->string.value_buf;
    }
}

function_t* object_get_function(object_t object) {
    APE_ASSERT(object_get_type(object) == OBJECT_FUNCTION);
    object_data_t *data = object_get_allocated_data(object);
    return &data->function;
}

native_function_t* object_get_native_function(object_t obj) {
    object_data_t *data = object_get_allocated_data(obj);
    return &data->native_function;
}

object_type_t object_get_type(object_t obj) {
    if (object_is_number(obj)) {
        return OBJECT_NUMBER;
    }
    uint64_t tag = (obj.handle >> 48) & 0x7;
    switch (tag) {
        case 0: return OBJECT_NONE;
        case 1: return OBJECT_BOOL;
        case 2: return OBJECT_NULL;
        case 4: {
            object_data_t *data = object_get_allocated_data(obj);
            return data->type;
        }
        default: return OBJECT_NONE;
    }
}

bool object_is_numeric(object_t obj) {
    object_type_t type = object_get_type(obj);
    return type == OBJECT_NUMBER || type == OBJECT_BOOL;
}

bool object_is_null(object_t obj) {
    return object_get_type(obj) == OBJECT_NULL;
}

bool object_is_callable(object_t obj) {
    object_type_t type = object_get_type(obj);
    return type == OBJECT_NATIVE_FUNCTION || type == OBJECT_FUNCTION;
}

const char* object_get_function_name(object_t obj) {
    APE_ASSERT(object_get_type(obj) == OBJECT_FUNCTION);
    object_data_t *data = object_get_allocated_data(obj);
    APE_ASSERT(data);
    if (!data) {
        return NULL;
    }

    if (data->function.owns_data) {
        return data->function.name;
    } else {
        return data->function.const_name;
    }
}

object_t object_get_function_free_val(object_t obj, int ix) {
    APE_ASSERT(object_get_type(obj) == OBJECT_FUNCTION);
    object_data_t *data = object_get_allocated_data(obj);
    APE_ASSERT(data);
    if (!data) {
        return object_make_null();
    }
    function_t *fun = &data->function;
    APE_ASSERT(ix >= 0 && ix < fun->free_vals_count);
    if (ix < 0 || ix >= fun->free_vals_count) {
        return object_make_null();
    }
    if (freevals_are_allocated(fun)) {
        return fun->free_vals_allocated[ix];
    } else {
        return fun->free_vals_buf[ix];
    }
}

void object_set_function_free_val(object_t obj, int ix, object_t val) {
    APE_ASSERT(object_get_type(obj) == OBJECT_FUNCTION);
    object_data_t *data = object_get_allocated_data(obj);
    APE_ASSERT(data);
    if (!data) {
        return;
    }
    function_t *fun = &data->function;
    APE_ASSERT(ix >= 0 && ix < fun->free_vals_count);
    if (ix < 0 || ix >= fun->free_vals_count) {
        return;
    }
    if (freevals_are_allocated(fun)) {
        fun->free_vals_allocated[ix] = val;
    } else {
        fun->free_vals_buf[ix] = val;
    }
}

object_t* object_get_function_free_vals(object_t obj) {
    APE_ASSERT(object_get_type(obj) == OBJECT_FUNCTION);
    object_data_t *data = object_get_allocated_data(obj);
    APE_ASSERT(data);
    if (!data) {
        return NULL;
    }
    function_t *fun = &data->function;
    if (freevals_are_allocated(fun)) {
        return fun->free_vals_allocated;
    } else {
        return fun->free_vals_buf;
    }
}

const char* object_get_error_message(object_t object) {
    APE_ASSERT(object_get_type(object) == OBJECT_ERROR);
    object_data_t *data = object_get_allocated_data(object);
    return data->error.message;
}

void object_set_error_traceback(object_t object, traceback_t *traceback) {
    APE_ASSERT(object_get_type(object) == OBJECT_ERROR);
    object_data_t *data = object_get_allocated_data(object);
    APE_ASSERT(data->error.traceback == NULL);
    data->error.traceback = traceback;
}

traceback_t* object_get_error_traceback(object_t object) {
    APE_ASSERT(object_get_type(object) == OBJECT_ERROR);
    object_data_t *data = object_get_allocated_data(object);
    return data->error.traceback;
}

bool object_set_external_copy_function(object_t object, external_data_copy_fn copy_fn) {
    APE_ASSERT(object_get_type(object) == OBJECT_EXTERNAL);
    external_data_t* data = object_get_external_data(object);
    if (!data) {
        return false;
    }
    data->data_copy_fn = copy_fn;
    return true;
}

array(object_t)* object_get_array(object_t object) {
    APE_ASSERT(object_get_type(object) == OBJECT_ARRAY);
    object_data_t *data = object_get_allocated_data(object);
    return data->array;
}

object_t object_get_array_value_at(object_t object, int ix) {
    APE_ASSERT(object_get_type(object) == OBJECT_ARRAY);
    array(object_t)* array = object_get_array(object);
    if (ix < 0 || ix >= array_count(array)) {
        return object_make_null();
    }
    object_t *res = array_get(array, ix);
    if (!res) {
        return object_make_null();
    }
    return *res;
}

bool object_set_array_value_at(object_t object, int ix, object_t val) {
    APE_ASSERT(object_get_type(object) == OBJECT_ARRAY);
    array(object_t)* array = object_get_array(object);
    if (ix < 0 || ix >= array_count(array)) {
        return false;
    }
    return array_set(array, ix, &val);
}

bool object_add_array_value(object_t object, object_t val) {
    APE_ASSERT(object_get_type(object) == OBJECT_ARRAY);
    array(object_t)* array = object_get_array(object);
    return array_add(array, &val);
}

int object_get_array_length(object_t object) {
    APE_ASSERT(object_get_type(object) == OBJECT_ARRAY);
    array(object_t)* array = object_get_array(object);
    return array_count(array);
}

int object_get_map_length(object_t object) {
    APE_ASSERT(object_get_type(object) == OBJECT_MAP);
    object_data_t *data = object_get_allocated_data(object);
    return valdict_count(data->map);
}

object_t object_get_map_key_at(object_t object, int ix) {
    APE_ASSERT(object_get_type(object) == OBJECT_MAP);
    object_data_t *data = object_get_allocated_data(object);
    object_t *res = valdict_get_key_at(data->map, ix);
    if (!res) {
        return object_make_null();
    }
    return *res;
}

object_t object_get_map_value_at(object_t object, int ix) {
    APE_ASSERT(object_get_type(object) == OBJECT_MAP);
    object_data_t *data = object_get_allocated_data(object);
    object_t *res = valdict_get_value_at(data->map, ix);
    if (!res) {
        return object_make_null();
    }
    return *res;
}

bool object_set_map_value_at(object_t object, int ix, object_t val) {
    APE_ASSERT(object_get_type(object) == OBJECT_MAP);
    if (ix >= object_get_map_length(object)) {
        return false;
    }
    object_data_t *data = object_get_allocated_data(object);
    bool res = valdict_set_value_at(data->map, ix, &val);
    return res;
}

object_t object_get_kv_pair_at(gcmem_t *mem, object_t object, int ix) {
    APE_ASSERT(object_get_type(object) == OBJECT_MAP);
    object_data_t *data = object_get_allocated_data(object);
    if (ix >= valdict_count(data->map)) {
        return object_make_null();
    }
    object_t key = object_get_map_key_at(object, ix);
    object_t val = object_get_map_value_at(object, ix);
    object_t res = object_make_map(mem);
    object_set_map_value(res, object_make_string(mem, "key"), key);
    object_set_map_value(res, object_make_string(mem, "value"), val);
    return res;
}

bool object_set_map_value(object_t object, object_t key, object_t val) {
    APE_ASSERT(object_get_type(object) == OBJECT_MAP);
    object_data_t *data = object_get_allocated_data(object);
    return valdict_set(data->map, &key, &val);
}

object_t object_get_map_value(object_t object, object_t key) {
    APE_ASSERT(object_get_type(object) == OBJECT_MAP);
    object_data_t *data = object_get_allocated_data(object);
    object_t *res = valdict_get(data->map, &key);
    if (!res) {
        return object_make_null();
    }
    return *res;
}

bool object_map_has_key(object_t object, object_t key) {
    APE_ASSERT(object_get_type(object) == OBJECT_MAP);
    object_data_t *data = object_get_allocated_data(object);
    object_t *res = valdict_get(data->map, &key);
    return res != NULL;
}

// INTERNAL
static object_t object_make(object_type_t type, object_data_t *data) {
    object_t object;
    object.handle = OBJECT_PATTERN;
    uint64_t type_tag = get_type_tag(type) & 0x7;
    object.handle |= (type_tag << 48);
    object.handle |= (uintptr_t)data; // assumes no pointer exceeds 48 bits
    return object;
}

static object_t object_deep_copy_internal(gcmem_t *mem, object_t obj, valdict(object_t, object_t) *copies) {
    object_t *copy_ptr = valdict_get(copies, &obj);
    if (copy_ptr) {
        return *copy_ptr;
    }

    object_t copy = object_make_null()  ;

    object_type_t type = object_get_type(obj);
    switch (type) {
        case OBJECT_FREED:
        case OBJECT_ANY:
        case OBJECT_NONE: {
            APE_ASSERT(false);
            copy = object_make_null();
            break;
        }
        case OBJECT_NUMBER:
        case OBJECT_BOOL:
        case OBJECT_NULL:
        case OBJECT_NATIVE_FUNCTION: {
            copy = obj;
            break;
        }
        case OBJECT_STRING: {
            const char *str = object_get_string(obj);
            copy = object_make_string(mem, str);
            break;
        }
        case OBJECT_FUNCTION: {
            function_t *function = object_get_function(obj);
            uint8_t *bytecode_copy = ape_malloc(sizeof(uint8_t) * function->comp_result->count, ape_mallocArg);
            memcpy(bytecode_copy, function->comp_result->bytecode, sizeof(uint8_t) * function->comp_result->count);
            src_pos_t *src_positions_copy = ape_malloc(sizeof(src_pos_t) * function->comp_result->count, ape_mallocArg);
            memcpy(src_positions_copy, function->comp_result->src_positions, sizeof(src_pos_t) * function->comp_result->count);
            compilation_result_t *comp_res_copy = compilation_result_make(bytecode_copy, src_positions_copy, function->comp_result->count);
            copy = object_make_function(mem, object_get_function_name(obj), comp_res_copy, true,
                                        function->num_locals, function->num_args, 0);
            valdict_set(copies, &obj, &copy);
            function_t *function_copy = object_get_function(copy);
            if (freevals_are_allocated(function)) {
                function_copy->free_vals_allocated = ape_malloc(sizeof(object_t) * function->free_vals_count, ape_mallocArg);
            }
            function_copy->free_vals_count = function->free_vals_count;
            for (int i = 0; i < function->free_vals_count; i++) {
                object_t free_val = object_get_function_free_val(obj, i);
                object_t free_val_copy = object_deep_copy_internal(mem, free_val, copies);
                object_set_function_free_val(copy, i, free_val_copy);
            }
            break;
        }
        case OBJECT_ARRAY: {
            array(object_t) *res_array = array_make(object_t);
            for (int i = 0; i < object_get_array_length(obj); i++) {
                object_t array_obj = object_get_array_value_at(obj, i);
                object_t copy = object_deep_copy_internal(mem, array_obj, copies);
                array_add(res_array, &copy);
            }
            copy = object_make_array_with_array(mem, res_array);
            valdict_set(copies, &obj, &copy);
            break;
        }
        case OBJECT_MAP: {
            copy = object_make_map(mem);
            valdict_set(copies, &obj, &copy);
            for (int i = 0; i < object_get_map_length(obj); i++) {
                object_t key = object_get_map_key_at(obj, i);
                object_t val = object_get_map_value_at(obj, i);
                object_t key_copy = object_deep_copy_internal(mem, key, copies);
                object_t val_copy = object_deep_copy_internal(mem, val, copies);
                object_set_map_value(copy, key_copy, val_copy);
            }
            break;
        }
        case OBJECT_EXTERNAL: {
            copy = object_copy(mem, obj);
            break;
        }
        case OBJECT_ERROR: {
            copy = obj;
            break;
        }
    }
    return copy;
}

static bool object_equals_wrapped(const object_t *a_ptr, const object_t *b_ptr) {
    object_t a = *a_ptr;
    object_t b = *b_ptr;
    return object_equals(a, b);
}

static unsigned long object_hash(object_t *obj_ptr) {
    object_t obj = *obj_ptr;
    object_type_t type = object_get_type(obj);

    switch (type) {
        case OBJECT_NUMBER: {
            double val = object_get_number(obj);
            return object_hash_double(val);
        }
        case OBJECT_BOOL: {
            bool val = object_get_bool(obj);
            return val;
        }
        case OBJECT_STRING: {
            object_data_t *data = object_get_allocated_data(obj);
            return data->string.hash;
        }
        default: {
            return 0;
        }
    }
}

static unsigned long object_hash_string(const char *str) { /* djb2 */
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

static unsigned long object_hash_double(double val) { /* djb2 */
    uint32_t *val_ptr = (uint32_t*)&val;
    unsigned long hash = 5381;
    hash = ((hash << 5) + hash) + val_ptr[0];
    hash = ((hash << 5) + hash) + val_ptr[1];
    return hash;
}

static bool object_is_number(object_t o) {
    return (o.handle & OBJECT_PATTERN) != OBJECT_PATTERN;
}

static uint64_t get_type_tag(object_type_t type) {
    switch (type) {
        case OBJECT_NONE: return 0;
        case OBJECT_BOOL: return 1;
        case OBJECT_NULL: return 2;
        default:          return 4;
    }
}

static bool freevals_are_allocated(function_t *fun) {
    return fun->free_vals_count >= APE_ARRAY_LEN(fun->free_vals_buf);
}
//FILE_END
//FILE_START:gc.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef APE_AMALGAMATED
#include "gc.h"
#include "object.h"
#endif

#define GCMEM_POOL_SIZE 1024

typedef struct gcmem {
    ptrarray(object_data_t) *objects;
    ptrarray(object_data_t) *objects_back;

    array(object_t) *objects_not_gced;

    object_data_t *pool[GCMEM_POOL_SIZE];
    int pool_index;
} gcmem_t;

gcmem_t *gcmem_make() {
    gcmem_t *mem = ape_malloc(sizeof(gcmem_t), ape_mallocArg);
    memset(mem, 0, sizeof(gcmem_t));
    mem->objects = ptrarray_make();
    mem->objects_back = ptrarray_make();
    mem->objects_not_gced = array_make(object_t);
    mem->pool_index = -1;
    return mem;
}

void gcmem_destroy(gcmem_t *mem) {
    if (!mem) {
        return;
    }
    for (int i = 0; i < ptrarray_count(mem->objects); i++) {
        object_data_t *obj = ptrarray_get(mem->objects, i);
        object_data_deinit(obj);
        ape_free(obj, ape_freeArg);
    }
    ptrarray_destroy(mem->objects);
    ptrarray_destroy(mem->objects_back);
    array_destroy(mem->objects_not_gced);
    for (int i = 0; i <= mem->pool_index; i++) {
        ape_free(mem->pool[i], ape_freeArg);
    }
    memset(mem, 0, sizeof(gcmem_t));
    ape_free(mem, ape_freeArg);
}

object_data_t* gcmem_alloc_object_data(gcmem_t *mem, object_type_t type) {
    object_data_t *data = NULL;
    if (mem->pool_index >= 0) {
        data = mem->pool[mem->pool_index];
        mem->pool_index--;
    } else {
        data = ape_malloc(sizeof(object_data_t), ape_mallocArg);
    }
    memset(data, 0, sizeof(object_data_t));
    ptrarray_add(mem->objects, data);
    data->mem = mem;
    data->type = type;
    return data;
}

void gc_unmark_all(gcmem_t *mem) {
    for (int i = 0; i < ptrarray_count(mem->objects); i++) {
        object_data_t *data = ptrarray_get(mem->objects, i);
        data->gcmark = false;
    }
}

void gc_mark_objects(object_t *objects, int count) {
    for (int i = 0; i < count; i++) {
        object_t obj = objects[i];
        gc_mark_object(obj);
    }
}

void gc_mark_object(object_t obj) {
    if (!object_is_allocated(obj)) {
        return;
    }
    object_data_t *data = object_get_allocated_data(obj);
    if (data->gcmark) {
        return;
    }

    data->gcmark = true;
    switch (data->type) {
        case OBJECT_MAP: {
            int len = object_get_map_length(obj);
            for (int i = 0; i < len; i++) {
                object_t key = object_get_map_key_at(obj, i);
                object_t val = object_get_map_value_at(obj, i);
                gc_mark_object(key);
                gc_mark_object(val);
            }
            break;
        }
        case OBJECT_ARRAY: {
            int len = object_get_array_length(obj);
            for (int i = 0; i < len; i++) {
                object_t val = object_get_array_value_at(obj, i);
                gc_mark_object(val);
            }
            break;
        }
        case OBJECT_FUNCTION: {
            function_t *function = object_get_function(obj);
            for (int i = 0; i < function->free_vals_count; i++) {
                object_t free_val = object_get_function_free_val(obj, i);
                gc_mark_object(free_val);
            }
            break;
        }
        default: {
            break;
        }
    }
}

void gc_sweep(gcmem_t *mem) {
    gc_mark_objects(array_data(mem->objects_not_gced), array_count(mem->objects_not_gced));

    ptrarray_clear(mem->objects_back);
    for (int i = 0; i < ptrarray_count(mem->objects); i++) {
        object_data_t *data = ptrarray_get(mem->objects, i);
        if (data->gcmark) {
            ptrarray_add(mem->objects_back, data);
        } else {
            object_data_deinit(data);
            if (mem->pool_index < (GCMEM_POOL_SIZE - 1)) {
                mem->pool_index++;
                mem->pool[mem->pool_index] = data;
            } else {
                ape_free(data, ape_freeArg);
            }
        }
    }
    ptrarray(object_t) *objs_temp = mem->objects;
    mem->objects = mem->objects_back;
    mem->objects_back = objs_temp;
}

void gc_disable_on_object(object_t obj) {
    if (!object_is_allocated(obj)) {
        return;
    }
    object_data_t *data = object_get_allocated_data(obj);
    if (array_contains(data->mem->objects_not_gced, &obj)) {
        return;
    }
    array_add(data->mem->objects_not_gced, &obj);
}

void gc_enable_on_object(object_t obj) {
    if (!object_is_allocated(obj)) {
        return;
    }
    object_data_t *data = object_get_allocated_data(obj);
    array_remove_item(data->mem->objects_not_gced, &obj);
}
//FILE_END
//FILE_START:builtins.c
#include <stdlib.h>
#include <stdio.h>

#ifndef APE_AMALGAMATED
#include "builtins.h"

#include "common.h"
#include "object.h"
#include "vm.h"
#endif

static object_t len_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t first_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t last_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t rest_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t reverse_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t array_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t append_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t remove_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t remove_at_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t println_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t print_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t read_file_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t write_file_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t to_str_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t char_to_str_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t range_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t keys_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t values_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t copy_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t deep_copy_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t concat_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t error_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t crash_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t assert_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t random_fn(vm_t *vm, void *data, int argc, object_t *args);

// Type checks
static object_t is_string_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_array_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_map_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_number_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_bool_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_null_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_function_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_external_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_error_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t is_native_function_fn(vm_t *vm, void *data, int argc, object_t *args);

// Math
static object_t sqrt_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t pow_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t sin_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t cos_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t tan_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t log_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t ceil_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t floor_fn(vm_t *vm, void *data, int argc, object_t *args);
static object_t abs_fn(vm_t *vm, void *data, int argc, object_t *args);

static bool check_args(vm_t *vm, bool generate_error, int argc, object_t *args, int expected_argc, object_type_t *expected_types);
#define CHECK_ARGS(vm, generate_error, argc, args, ...) \
    check_args(\
        (vm),\
        (generate_error),\
        (argc),\
        (args),\
        sizeof((object_type_t[]){__VA_ARGS__}) / sizeof(object_type_t),\
        (object_type_t[]){__VA_ARGS__})

static struct {
    const char *name;
    native_fn fn;
} g_native_functions[] = {
    {"len",         len_fn},
    {"println",     println_fn},
    {"print",       print_fn},
    {"read_file",   read_file_fn},
    {"write_file",  write_file_fn},
    {"first",       first_fn},
    {"last",        last_fn},
    {"rest",        rest_fn},
    {"append",      append_fn},
    {"remove",      remove_fn},
    {"remove_at",   remove_at_fn},
    {"to_str",      to_str_fn},
    {"range",       range_fn},
    {"keys",        keys_fn},
    {"values",      values_fn},
    {"copy",        copy_fn},
    {"deep_copy",   deep_copy_fn},
    {"concat",      concat_fn},
    {"char_to_str", char_to_str_fn},
    {"reverse",     reverse_fn},
    {"array",       array_fn},
    {"error",       error_fn},
    {"crash",       crash_fn},
    {"assert",      assert_fn},
    {"random",      random_fn},

    // Type checks
    {"is_string",   is_string_fn},
    {"is_array",    is_array_fn},
    {"is_map",      is_map_fn},
    {"is_number",   is_number_fn},
    {"is_bool",     is_bool_fn},
    {"is_null",     is_null_fn},
    {"is_function", is_function_fn},
    {"is_external", is_external_fn},
    {"is_error",    is_error_fn},
    {"is_native_function", is_native_function_fn},

    // Math
    {"sqrt",  sqrt_fn},
    {"pow",   pow_fn},
    {"sin",   sin_fn},
    {"cos",   cos_fn},
    {"tan",   tan_fn},
    {"log",   log_fn},
    {"ceil",  ceil_fn},
    {"floor", floor_fn},
    {"abs",   abs_fn},
};

int builtins_count() {
    return APE_ARRAY_LEN(g_native_functions);
}

native_fn builtins_get_fn(int ix) {
    return g_native_functions[ix].fn;
}

const char* builtins_get_name(int ix) {
    return g_native_functions[ix].name;
}

// INTERNAL
static object_t len_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_STRING | OBJECT_ARRAY | OBJECT_MAP)) {
        return object_make_null();
    }

    object_t arg = args[0];
    object_type_t type = object_get_type(arg);
    if (type == OBJECT_STRING) {
        const char *str = object_get_string(arg);
        int len = (int)strlen(str);
        return object_make_number(len);
    } else if (type == OBJECT_ARRAY) {
        int len = object_get_array_length(arg);
        return object_make_number(len);
    } else if (type == OBJECT_MAP) {
        int len = object_get_map_length(arg);
        return object_make_number(len);
    }

    return object_make_null();
}

static object_t first_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ARRAY)) {
        return object_make_null();
    }
     object_t arg = args[0];
    return object_get_array_value_at(arg, 0);
}

static object_t last_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ARRAY)) {
        return object_make_null();
    }
    object_t arg = args[0];
    return object_get_array_value_at(arg, object_get_array_length(arg) - 1);
}

static object_t rest_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ARRAY)) {
        return object_make_null();
    }
    object_t arg = args[0];
    int len = object_get_array_length(arg);
    if (len == 0) {
        return object_make_null();
    }

    object_t res = object_make_array(vm->mem);
    for (int i = 1; i < len; i++) {
        object_t item = object_get_array_value_at(arg, i);
        object_add_array_value(res, item);
    }

    return res;
}

static object_t reverse_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ARRAY | OBJECT_STRING)) {
        return object_make_null();
    }
    object_t arg = args[0];
    object_type_t type = object_get_type(arg);
    if (type == OBJECT_ARRAY) {
        array(object_t) *array = object_get_array(arg);
        array_reverse(array);
        return object_make_array_with_array(vm->mem, array);
    } else if (type == OBJECT_STRING) {
        const char *str = object_get_string(arg);
        int len = (int)strlen(str);
        char *res_buf = ape_malloc(len + 1, ape_mallocArg);
        for (int i = 0; i < len; i++) {
            res_buf[len - i - 1] = str[i];
        }
        res_buf[len] = '\0';
        return object_make_string_no_copy(vm->mem, res_buf);
    }
    return object_make_null();
}

static object_t array_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (argc == 1) {
        if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
            return object_make_null();
        }
        int capacity = (int)object_get_number(args[0]);
        array(object_t) *res_arr = array_make_with_capacity(capacity, sizeof(object_t));
        object_t obj_null = object_make_null();
        for (int i = 0; i < capacity; i++) {
            array_add(res_arr, &obj_null);
        }
        return object_make_array_with_array(vm->mem, res_arr);
    } else if (argc == 2) {
        if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER, OBJECT_ANY)) {
            return object_make_null();
        }
        int capacity = (int)object_get_number(args[0]);
        array(object_t) *res_arr = array_make_with_capacity(capacity, sizeof(object_t));
        for (int i = 0; i < capacity; i++) {
            array_add(res_arr, &args[1]);
        }
        return object_make_array_with_array(vm->mem, res_arr);
    }
    CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER);
    return object_make_null();
}

static object_t append_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ARRAY, OBJECT_ANY)) {
        return object_make_null();
    }
    object_add_array_value(args[0], args[1]);
    int len = object_get_array_length(args[0]);
    return object_make_number(len);
}

static object_t println_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;

    const ape_config_t *config = vm->config;

    if (!config->stdio.write.write) {
        return object_make_null(); // todo: runtime error?
    }

    strbuf_t *buf = strbuf_make();
    for (int i = 0; i < argc; i++) {
        object_t arg = args[i];
        object_to_string(arg, buf, false);
    }
    strbuf_append(buf, "\n");
    config->stdio.write.write(config->stdio.write.context, strbuf_get_string(buf), strbuf_get_length(buf));
    strbuf_destroy(buf);
    return object_make_null();
}

static object_t print_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    const ape_config_t *config = vm->config;

    if (!config->stdio.write.write) {
        return object_make_null(); // todo: runtime error?
    }

    strbuf_t *buf = strbuf_make();
    for (int i = 0; i < argc; i++) {
        object_t arg = args[i];
        object_to_string(arg, buf, false);
    }
    config->stdio.write.write(config->stdio.write.context, strbuf_get_string(buf), strbuf_get_length(buf));
    strbuf_destroy(buf);
    return object_make_null();
}

static object_t write_file_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_STRING, OBJECT_STRING)) {
        return object_make_null();
    }

    const ape_config_t *config = vm->config;

    if (!config->fileio.write_file.write_file) {
        return object_make_null();
    }

    const char *path = object_get_string(args[0]);
    const char *string = object_get_string(args[1]);
    int string_size = (int)strlen(string) + 1;

    int written = (int)config->fileio.write_file.write_file(config->fileio.write_file.context, path, string, string_size);

    return object_make_number(written);
}

static object_t read_file_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_STRING)) {
        return object_make_null();
    }

    const ape_config_t *config = vm->config;

    if (!config->fileio.read_file.read_file) {
        return object_make_null();
    }

    const char *path = object_get_string(args[0]);

    const char *contents = config->fileio.read_file.read_file(config->fileio.read_file.context, path);
    if (!contents) {
        return object_make_null();
    }

    return object_make_string(vm->mem, contents);
}

static object_t to_str_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_STRING | OBJECT_NUMBER | OBJECT_BOOL | OBJECT_NULL | OBJECT_MAP | OBJECT_ARRAY)) {
        return object_make_null();
    }
    object_t arg = args[0];
    strbuf_t *buf = strbuf_make();
    object_to_string(arg, buf, false);
    object_t res = object_make_string(vm->mem, strbuf_get_string(buf));
    strbuf_destroy(buf);
    return res;
}

static object_t char_to_str_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }

    double val = object_get_number(args[0]);

    char c = (char)val;
    char str[2] = {c, '\0'};
    return object_make_string(vm->mem, str);
}

static object_t range_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    for (int i = 0; i < argc; i++) {
        object_type_t type = object_get_type(args[i]);
        if (type != OBJECT_NUMBER) {
            const char *type_str = object_get_type_name(type);
            const char *expected_str = object_get_type_name(OBJECT_NUMBER);
            error_t *err = error_makef(ERROR_RUNTIME, src_pos_invalid,
                                       "Invalid argument %d passed to range, got %s instead of %s",
                                       i, type_str, expected_str);
            vm_set_runtime_error(vm, err);
            return object_make_null();
        }
    }

    int start = 0;
    int end = 0;
    int step = 1;

    if (argc == 1) {
        end = object_get_number(args[0]);
    } else if (argc == 2) {
        start = object_get_number(args[0]);
        end = object_get_number(args[1]);
    } else if (argc == 3) {
        start = object_get_number(args[0]);
        end = object_get_number(args[1]);
        step = object_get_number(args[2]);
    } else {
        error_t *err = error_makef(ERROR_RUNTIME, src_pos_invalid, "Invalid number of arguments passed to range, got %d", argc);
        vm_set_runtime_error(vm, err);
        return object_make_null();
    }

    if (step == 0) {
        error_t *err = error_make(ERROR_RUNTIME, src_pos_invalid, "range step cannot be 0");
        vm_set_runtime_error(vm, err);
        return object_make_null();
    }

    object_t res = object_make_array(vm->mem);
    for (int i = start; i < end; i += step) {
        object_t item = object_make_number(i);
        object_add_array_value(res, item);
    }
    return res;
}

static object_t keys_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_MAP)) {
        return object_make_null();
    }
    object_t arg = args[0];
    object_t res = object_make_array(vm->mem);
    int len = object_get_map_length(arg);
    for (int i = 0; i < len; i++) {
        object_t key = object_get_map_key_at(arg, i);
        object_add_array_value(res, key);
    }
    return res;
}

static object_t values_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_MAP)) {
        return object_make_null();
    }
    object_t arg = args[0];
    object_t res = object_make_array(vm->mem);
    int len = object_get_map_length(arg);
    for (int i = 0; i < len; i++) {
        object_t key = object_get_map_value_at(arg, i);
        object_add_array_value(res, key);
    }
    return res;
}

static object_t copy_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_copy(vm->mem, args[0]);
}

static object_t deep_copy_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_deep_copy(vm->mem, args[0]);
}

static object_t concat_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ARRAY | OBJECT_STRING, OBJECT_ANY)) {
        return object_make_null();
    }
    object_type_t type = object_get_type(args[0]);
    object_type_t item_type = object_get_type(args[1]);
    if (type == OBJECT_ARRAY) {
        if (item_type != OBJECT_ARRAY) {
            const char *item_type_str = object_get_type_name(item_type);
            error_t *err = error_makef(ERROR_RUNTIME, src_pos_invalid,
                                       "Invalid argument 2 passed to concat, got %s",
                                       item_type_str);
            vm_set_runtime_error(vm, err);
            return object_make_null();
        }
        array(object_t) *arr = object_get_array(args[0]);
        array(object_t) *item_arr = object_get_array(args[1]);
        array_add_array(arr, item_arr);
        return object_make_number(array_count(arr));
    } else if (type == OBJECT_STRING) {
        if (!CHECK_ARGS(vm, true, argc, args, OBJECT_STRING, OBJECT_STRING)) {
            return object_make_null();
        }
        const char *str = object_get_string(args[0]);
        int len = (int)strlen(str);
        const char *arg_str = object_get_string(args[1]);
        int arg_str_len = (int)strlen(arg_str);
        char *res_buf = ape_malloc(len + arg_str_len + 1, ape_mallocArg);
        for (int i = 0; i < len; i++) {
            res_buf[i] = str[i];
        }
        for (int i = 0; i < arg_str_len; i++) {
            res_buf[len + i] = arg_str[i];
        }
        res_buf[len + arg_str_len] = '\0';
        return object_make_string_no_copy(vm->mem, res_buf);
    }
    return object_make_null();
}

static object_t assert_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_BOOL)) {
        return object_make_null();
    }

    if (!object_get_bool(args[0])) {
        error_t *err = error_make(ERROR_RUNTIME, src_pos_invalid, "assertion failed");
        vm_set_runtime_error(vm, err);
        return object_make_null();
    }

    return object_make_bool(true);
}

static object_t remove_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ARRAY, OBJECT_ANY)) {
        return object_make_null();
    }

    int ix = -1;
    for (int i = 0; i < object_get_array_length(args[0]); i++) {
        object_t obj = object_get_array_value_at(args[0], i);
        if (object_equals(obj, args[1])) {
            ix = i;
            break;
        }
    }

    if (ix == -1) {
        return object_make_bool(false);
    }

    array(object_t) *arr = object_get_array(args[0]);
    bool res = array_remove_at(arr, ix);
    return object_make_bool(res);
}

static object_t remove_at_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ARRAY, OBJECT_NUMBER)) {
        return object_make_null();
    }

    object_type_t type = object_get_type(args[0]);
    int ix = object_get_number(args[1]);

    switch (type) {
        case OBJECT_ARRAY: {
            array(object_t) *arr = object_get_array(args[0]);
            bool res = array_remove_at(arr, ix);
            return object_make_bool(res);
        }
        default:
            break;
    }

    return object_make_bool(true);
}


static object_t error_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (argc == 1 && object_get_type(args[0]) == OBJECT_STRING) {
        return object_make_error(vm->mem, object_get_string(args[0]));
    } else {
        return object_make_error(vm->mem, "");
    }
}

static object_t crash_fn(vm_t *vm, void *data, int argc, object_t *args) {
    error_t *err = NULL;
    if (argc == 1 && object_get_type(args[0]) == OBJECT_STRING) {
        err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), object_get_string(args[0]));
    } else {
        err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), "");
    }
    vm_set_runtime_error(vm, err);
    return object_make_null();
}

static object_t random_fn(vm_t *vm, void *data, int argc, object_t *args) {
    double res = (double)rand() / RAND_MAX;
    if (argc == 0) {
        return object_make_number(res);
    } else if (argc == 2) {
        if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER, OBJECT_NUMBER)) {
            return object_make_null();
        }
        double min = object_get_number(args[0]);
        double max = object_get_number(args[1]);
        if (min >= max) {
            error_t *err = error_make(ERROR_RUNTIME, src_pos_invalid, "max is bigger than min");
            vm_set_runtime_error(vm, err);
            return object_make_null();
        }
        double range = max - min;
        res = min + (res * range);
        return object_make_number(res);
    } else {
        error_t *err = error_make(ERROR_RUNTIME, src_pos_invalid, "Invalid number or arguments");
        vm_set_runtime_error(vm, err);
        return object_make_null();
    }
}

//-----------------------------------------------------------------------------
// Type checks
//-----------------------------------------------------------------------------

static object_t is_string_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_STRING);
}

static object_t is_array_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_ARRAY);
}

static object_t is_map_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_MAP);
}

static object_t is_number_fn(vm_t *vm, void *data, int argc, object_t *args){
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_NUMBER);
}

static object_t is_bool_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_BOOL);
}

static object_t is_null_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_NULL);
}

static object_t is_function_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_FUNCTION);
}

static object_t is_external_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_EXTERNAL);
}

static object_t is_error_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_ERROR);
}

static object_t is_native_function_fn(vm_t *vm, void *data, int argc, object_t *args) {
    (void)data;
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_ANY)) {
        return object_make_null();
    }
    return object_make_bool(object_get_type(args[0]) == OBJECT_NATIVE_FUNCTION);
}

//-----------------------------------------------------------------------------
// Math
//-----------------------------------------------------------------------------

static object_t sqrt_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg = object_get_number(args[0]);
    double res = sqrt(arg);
    return object_make_number(res);
}

static object_t pow_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg1 = object_get_number(args[0]);
    double arg2 = object_get_number(args[1]);
    double res = pow(arg1, arg2);
    return object_make_number(res);
}

static object_t sin_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg = object_get_number(args[0]);
    double res = sin(arg);
    return object_make_number(res);
}

static object_t cos_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg = object_get_number(args[0]);
    double res = cos(arg);
    return object_make_number(res);
}

static object_t tan_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg = object_get_number(args[0]);
    double res = tan(arg);
    return object_make_number(res);
}

static object_t log_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg = object_get_number(args[0]);
    double res = log(arg);
    return object_make_number(res);
}

static object_t ceil_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg = object_get_number(args[0]);
    double res = ceil(arg);
    return object_make_number(res);
}

static object_t floor_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg = object_get_number(args[0]);
    double res = floor(arg);
    return object_make_number(res);
}

static object_t abs_fn(vm_t *vm, void *data, int argc, object_t *args) {
    if (!CHECK_ARGS(vm, true, argc, args, OBJECT_NUMBER)) {
        return object_make_null();
    }
    double arg = object_get_number(args[0]);
    double res = fabs(arg);
    return object_make_number(res);
}


static bool check_args(vm_t *vm, bool generate_error, int argc, object_t *args, int expected_argc, object_type_t *expected_types) {
    if (argc != expected_argc) {
        if (generate_error) {
            error_t *err = error_makef(ERROR_RUNTIME, src_pos_invalid,
                                       "Invalid number or arguments, got %d instead of %d",
                                       argc, expected_argc);
            vm_set_runtime_error(vm, err);
        }
        return false;
    }

    for (int i = 0; i < argc; i++) {
       object_t arg = args[i];
        object_type_t type = object_get_type(arg);
        object_type_t expected_type = expected_types[i];
        if (!(type & expected_type)) {
            if (generate_error) {
                const char *type_str = object_get_type_name(type);
                const char *expected_type_str = object_get_type_name(expected_type);
                error_t *err = error_makef(ERROR_RUNTIME, src_pos_invalid,
                                           "Invalid argument %d type, got %s, expected %s",
                                           i, type_str, expected_type_str);
                vm_set_runtime_error(vm, err);
            }
            return false;
        }
    }
    return true;
}
//FILE_END
//FILE_START:traceback.c
#ifndef APE_AMALGAMATED
#include "traceback.h"
#include "vm.h"
#include "compiler.h"
#endif

traceback_t* traceback_make(void) {
    traceback_t *traceback = ape_malloc(sizeof(traceback_t), ape_mallocArg);
    traceback->items = array_make(traceback_item_t);
    return traceback;
}

void traceback_destroy(traceback_t *traceback) {
    if (!traceback) {
        return;
    }
    for (int i = 0; i < array_count(traceback->items); i++) {
        traceback_item_t *item = array_get(traceback->items, i);
        ape_free(item->function_name, ape_freeArg);
    }
    array_destroy(traceback->items);
    ape_free(traceback, ape_freeArg);
}

void traceback_append(traceback_t *traceback, const char *function_name, src_pos_t pos) {
    traceback_item_t item;
    item.function_name = ape_strdup(function_name);
    item.pos = pos;
    array_add(traceback->items, &item);
}

void traceback_append_from_vm(traceback_t *traceback, vm_t *vm) {
    for (int i = vm->frames_count - 1; i >= 0; i--) {
        frame_t *frame = &vm->frames[i];
        traceback_append(traceback, object_get_function_name(frame->function), frame_src_position(frame));
    }
}

void traceback_to_string(const traceback_t *traceback, strbuf_t *buf) {
    int depth  = array_count(traceback->items);
    for (int i = 0; i < depth; i++) {
        traceback_item_t *item = array_get(traceback->items, i);
        const char *filename = traceback_item_get_filepath(item);
        if (item->pos.line >= 0 && item->pos.column >= 0) {
            strbuf_appendf(buf, "%s in %s on %d:%d\n", item->function_name, filename, item->pos.line, item->pos.column);
        } else {
            strbuf_appendf(buf, "%s\n", item->function_name);
        }
    }
}

const char* traceback_item_get_line(traceback_item_t *item) {
    if (!item->pos.file) {
        return NULL;
    }
    ptrarray(char*) *lines = item->pos.file->lines;
    if (item->pos.line >= ptrarray_count(lines)) {
        return NULL;
    }
    const char *line = ptrarray_get(lines, item->pos.line);
    return line;
}

const char* traceback_item_get_filepath(traceback_item_t *item) {
    if (!item->pos.file) {
        return NULL;
    }
    return item->pos.file->path;
}
//FILE_END
//FILE_START:frame.c
#include <stdlib.h>

#ifndef APE_AMALGAMATED
#include "frame.h"
#include "compiler.h"
#endif

bool frame_init(frame_t* frame, object_t function_obj, int base_pointer) {
    if (object_get_type(function_obj) != OBJECT_FUNCTION) {
        return false;
    }
    function_t* function = object_get_function(function_obj);
    frame->function = function_obj;
    frame->ip = 0;
    frame->base_pointer = base_pointer;
    frame->src_ip = 0;
    frame->bytecode = function->comp_result->bytecode;
    frame->src_positions = function->comp_result->src_positions;
    frame->bytecode_size = function->comp_result->count;
    frame->recover_ip = -1;
    frame->is_recovering = false;
    return true;
}

opcode_val_t frame_read_opcode(frame_t* frame){
    frame->src_ip = frame->ip;
    return frame_read_uint8(frame);
}

uint64_t frame_read_uint64(frame_t* frame) {
    const uint8_t *data = frame->bytecode + frame->ip;
    frame->ip += 8;
    uint64_t res = 0;
    res |= (uint64_t)data[7];
    res |= (uint64_t)data[6] << 8;
    res |= (uint64_t)data[5] << 16;
    res |= (uint64_t)data[4] << 24;
    res |= (uint64_t)data[3] << 32;
    res |= (uint64_t)data[2] << 40;
    res |= (uint64_t)data[1] << 48;
    res |= (uint64_t)data[0] << 56;
    return res;
}

uint16_t frame_read_uint16(frame_t* frame) {
    const uint8_t *data = frame->bytecode + frame->ip;
    frame->ip += 2;
    return (data[0] << 8) | data[1];
}

uint8_t frame_read_uint8(frame_t* frame) {
    const uint8_t *data = frame->bytecode + frame->ip;
    frame->ip += 1;
    return data[0];
}

src_pos_t frame_src_position(const frame_t *frame) {
    if (frame->src_positions) {
        return frame->src_positions[frame->src_ip];
    }
    return src_pos_invalid;
}
//FILE_END
//FILE_START:vm.c
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#ifndef APE_AMALGAMATED
#include "vm.h"

#include "code.h"
#include "compiler.h"
#include "traceback.h"
#include "builtins.h"
#include "gc.h"
#endif

static void set_sp(vm_t *vm, int new_sp);
static void stack_push(vm_t *vm, object_t obj);
static object_t stack_pop(vm_t *vm);
static object_t stack_get(vm_t *vm, int nth_item);

static void this_stack_push(vm_t *vm, object_t obj);
static object_t this_stack_pop(vm_t *vm);
static object_t this_stack_get(vm_t *vm, int nth_item);

static bool push_frame(vm_t *vm, frame_t frame);
static bool pop_frame(vm_t *vm);
static void run_gc(vm_t *vm, array(object_t) *constants);
static bool call_object(vm_t *vm, object_t callee, int num_args);
static object_t call_native_function(vm_t *vm, object_t callee, src_pos_t src_pos, int argc, object_t *args);
static bool check_assign(vm_t *vm, object_t old_value, object_t new_value);
static bool try_overload_operator(vm_t *vm, object_t left, object_t right, opcode_t op, bool *out_overload_found);

vm_t *vm_make(const ape_config_t *config, gcmem_t *mem, ptrarray(error_t) *errors) {
    vm_t *vm = ape_malloc(sizeof(vm_t), ape_mallocArg);
    memset(vm, 0, sizeof(vm_t));
    vm->config = config;
    vm->mem = mem;
    vm->globals_count = 0;
    vm->sp = 0;
    vm->this_sp = 0;
    vm->frames_count = 0;
    vm->native_functions = array_make(object_t);
    vm->errors = errors;
    vm->runtime_error = NULL;
    vm->last_popped = object_make_null();
    vm->running = false;

    for (int i = 0; i < builtins_count(); i++) {
        object_t builtin = object_make_native_function(vm->mem, builtins_get_name(i), builtins_get_fn(i), vm);
        array_add(vm->native_functions, &builtin);
    }

    for (int i = 0; i < OPCODE_MAX; i++) {
        vm->operator_oveload_keys[i] = object_make_null();
    }
#define SET_OPERATOR_OVERLOAD_KEY(op, key) do {\
    object_t key_obj = object_make_string(vm->mem, key);\
    vm->operator_oveload_keys[op] = key_obj;\
} while (0)
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_ADD,     "__operator_add__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_SUB,     "__operator_sub__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_MUL,     "__operator_mul__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_DIV,     "__operator_div__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_MOD,     "__operator_mod__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_OR,      "__operator_or__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_XOR,     "__operator_xor__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_AND,     "__operator_and__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_LSHIFT,  "__operator_lshift__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_RSHIFT,  "__operator_rshift__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_MINUS,   "__operator_minus__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_BANG,    "__operator_bang__");
    SET_OPERATOR_OVERLOAD_KEY(OPCODE_COMPARE, "__cmp__");
#undef SET_OPERATOR_OVERLOAD_KEY

    return vm;
}

void vm_destroy(vm_t *vm) {
    if (!vm) {
        return;
    }
    array_destroy(vm->native_functions);
    ape_free(vm, ape_freeArg);
}

void vm_reset(vm_t *vm) {
    vm->sp = 0;
    vm->this_sp = 0;
    while (vm->frames_count > 0) {
        pop_frame(vm);
    }
}

bool vm_run(vm_t *vm, compilation_result_t *comp_res, array(object_t) *constants) {
    int old_sp = vm->sp;
    int old_this_sp = vm->this_sp;
    int old_frames_count = vm->frames_count;
    object_t main_fn = object_make_function(vm->mem, "main", comp_res, false, 0, 0, 0);
    stack_push(vm, main_fn);
    bool res = vm_execute_function(vm, main_fn, constants);
    while (vm->frames_count > old_frames_count) {
        pop_frame(vm);
    }
    APE_ASSERT(vm->sp == old_sp);
    vm->this_sp = old_this_sp;
    return res;
}

object_t vm_call(vm_t *vm, array(object_t) *constants, object_t callee, int argc, object_t *args) {
    object_type_t type = object_get_type(callee);
    if (type == OBJECT_FUNCTION) {
        int old_sp = vm->sp;
        int old_this_sp = vm->this_sp;
        int old_frames_count = vm->frames_count;
        stack_push(vm, callee);
        for (int i = 0; i < argc; i++) {
            stack_push(vm, args[i]);
        }
        bool ok = vm_execute_function(vm, callee, constants);
        if (!ok) {
            return object_make_null();
        }
        while (vm->frames_count > old_frames_count) {
            pop_frame(vm);
        }
        APE_ASSERT(vm->sp == old_sp);
        vm->this_sp = old_this_sp;
        return vm_get_last_popped(vm);
    } else if (type == OBJECT_NATIVE_FUNCTION) {
        return call_native_function(vm, callee, src_pos_invalid, argc, args);
    } else {
        error_t *err = error_make(ERROR_USER, src_pos_invalid, "Object is not callable");
        ptrarray_add(vm->errors, err);
        return object_make_null();
    }
}

bool vm_execute_function(vm_t *vm, object_t function, array(object_t) *constants) {
    if (vm->running) {
        error_t *err = error_make(ERROR_USER, src_pos_invalid, "VM is already executing code");
        ptrarray_add(vm->errors, err);
        return false;
    }

    function_t *function_function = object_get_function(function); // naming is hard
    frame_t new_frame;
    frame_init(&new_frame, function, vm->sp - function_function->num_args);
    bool ok = push_frame(vm, new_frame);
    if (!ok) {
        error_t *err = error_make(ERROR_USER, src_pos_invalid, "Pushing frame failed");
        ptrarray_add(vm->errors, err);
        return false;
    }

    vm->running = true;
    vm->last_popped = object_make_null();

    int ticks_between_gc = 0;
    if (vm->config) {
        ticks_between_gc = vm->config->gc_interval;
    };

    int ticks_since_gc = 0;

    while (vm->current_frame->ip < vm->current_frame->bytecode_size) {
        opcode_val_t opcode = frame_read_opcode(vm->current_frame);
        switch (opcode) {
            case OPCODE_CONSTANT: {
                uint16_t constant_ix = frame_read_uint16(vm->current_frame);
                object_t *constant = array_get(constants, constant_ix);
                if (!constant) {
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                              "Constant at %d not found", constant_ix);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }
                stack_push(vm, *constant);
                break;
            }
            case OPCODE_ADD:
            case OPCODE_SUB:
            case OPCODE_MUL:
            case OPCODE_DIV:
            case OPCODE_MOD:
            case OPCODE_OR:
            case OPCODE_XOR:
            case OPCODE_AND:
            case OPCODE_LSHIFT:
            case OPCODE_RSHIFT:
            {
                object_t right = stack_pop(vm);
                object_t left = stack_pop(vm);
                object_type_t left_type = object_get_type(left);
                object_type_t right_type = object_get_type(right);
                if (object_is_numeric(left) && object_is_numeric(right)) {
                    double right_val = object_get_number(right);
                    double left_val = object_get_number(left);

                    int64_t left_val_int = left_val;
                    int64_t right_val_int = right_val;

                    double res = 0;
                    switch (opcode) {
                        case OPCODE_ADD:    res = left_val + right_val; break;
                        case OPCODE_SUB:    res = left_val - right_val; break;
                        case OPCODE_MUL:    res = left_val * right_val; break;
                        case OPCODE_DIV:    res = left_val / right_val; break;
                        case OPCODE_MOD:    res = fmod(left_val, right_val); break;
                        case OPCODE_OR:     res = left_val_int | right_val_int; break;
                        case OPCODE_XOR:    res = left_val_int ^ right_val_int; break;
                        case OPCODE_AND:    res = left_val_int & right_val_int; break;
                        case OPCODE_LSHIFT: res = left_val_int << right_val_int; break;
                        case OPCODE_RSHIFT: res = left_val_int >> right_val_int; break;
                        default: APE_ASSERT(false); break;
                    }
                    stack_push(vm, object_make_number(res));
                } else if (left_type == OBJECT_STRING  && right_type == OBJECT_STRING && opcode == OPCODE_ADD) {
                    const char* right_val = object_get_string(right);
                    const char* left_val = object_get_string(left);
                    object_t res_obj = object_make_stringf(vm->mem, "%s%s", left_val, right_val);
                    stack_push(vm, res_obj);
                } else {
                    bool overload_found = false;
                    bool ok = try_overload_operator(vm, left, right, opcode, &overload_found);
                    if (!ok) {
                        goto err;
                    }
                    if (!overload_found) {
                        const char *opcode_name = opcode_get_name(opcode);
                        const char *left_type_name = object_get_type_name(left_type);
                        const char *right_type_name = object_get_type_name(right_type);
                        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                                   "Invalid operand types for %s, got %s and %s",
                                                   opcode_name, left_type_name, right_type_name);
                        vm_set_runtime_error(vm, err);
                        goto err;
                    }
                }
                break;
            }
            case OPCODE_POP: {
                stack_pop(vm);
                break;
            }
            case OPCODE_TRUE: {
                stack_push(vm, object_make_bool(true));
                break;
            }
            case OPCODE_FALSE: {
                stack_push(vm, object_make_bool(false));
                break;
            }
            case OPCODE_COMPARE: {
                object_t right = stack_pop(vm);
                object_t left = stack_pop(vm);
                bool is_overloaded = false;
                bool ok = try_overload_operator(vm, left, right, OPCODE_COMPARE, &is_overloaded);
                if (!ok) {
                    goto err;
                }
                if (!is_overloaded) {
                    double comparison_res = object_compare(left, right);
                    object_t res = object_make_number(comparison_res);
                    stack_push(vm, res);
                }
                break;
            }
            case OPCODE_EQUAL:
            case OPCODE_NOT_EQUAL:
            case OPCODE_GREATER_THAN:
            case OPCODE_GREATER_THAN_EQUAL:
            {
                object_t value = stack_pop(vm);
                double comparison_res = object_get_number(value);
                bool res_val = false;
                switch (opcode) {
                    case OPCODE_EQUAL: res_val = APE_DBLEQ(comparison_res, 0); break;
                    case OPCODE_NOT_EQUAL: res_val = !APE_DBLEQ(comparison_res, 0); break;
                    case OPCODE_GREATER_THAN: res_val = comparison_res > 0; break;
                    case OPCODE_GREATER_THAN_EQUAL: {
                        res_val = comparison_res > 0 || APE_DBLEQ(comparison_res, 0);
                        break;
                    }
                    default: APE_ASSERT(false); break;
                }
                object_t res = object_make_bool(res_val);
                stack_push(vm, res);
                break;
            }
            case OPCODE_MINUS:
            {
                object_t operand = stack_pop(vm);
                object_type_t operand_type = object_get_type(operand);
                if (operand_type == OBJECT_NUMBER) {
                    double val = object_get_number(operand);
                    object_t res = object_make_number(-val);
                    stack_push(vm, res);
                } else {
                    bool overload_found = false;
                    bool ok = try_overload_operator(vm, operand, object_make_null(), OPCODE_MINUS, &overload_found);
                    if (!ok) {
                        goto err;
                    }
                    if (!overload_found) {
                        const char *operand_type_string = object_get_type_name(operand_type);
                        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                                   "Invalid operand type for MINUS, got %s",
                                                   operand_type_string);
                        vm_set_runtime_error(vm, err);
                        goto err;
                    }
                }
                break;
            }
            case OPCODE_BANG: {
                object_t operand = stack_pop(vm);
                object_type_t type = object_get_type(operand);
                if (type == OBJECT_BOOL) {
                    object_t res = object_make_bool(!object_get_bool(operand));
                    stack_push(vm, res);
                } else if (type == OBJECT_NULL) {
                    object_t res = object_make_bool(true);
                    stack_push(vm, res);
                } else {
                    bool overload_found = false;
                    bool ok = try_overload_operator(vm, operand, object_make_null(), OPCODE_BANG, &overload_found);
                    if (!ok) {
                        goto err;
                    }
                    if (!overload_found) {
                        object_t res = object_make_bool(false);
                        stack_push(vm, res);
                    }
                }
                break;
            }
            case OPCODE_JUMP: {
                uint16_t pos = frame_read_uint16(vm->current_frame);
                vm->current_frame->ip = pos;
                break;
            }
            case OPCODE_JUMP_IF_FALSE: {
                uint16_t pos = frame_read_uint16(vm->current_frame);
                object_t test = stack_pop(vm);
                if (!object_get_bool(test)) {
                    vm->current_frame->ip = pos;
                }
                break;
            }
            case OPCODE_JUMP_IF_TRUE: {
                uint16_t pos = frame_read_uint16(vm->current_frame);
                object_t test = stack_pop(vm);
                if (object_get_bool(test)) {
                    vm->current_frame->ip = pos;
                }
                break;
            }
            case OPCODE_NULL: {
                stack_push(vm, object_make_null());
                break;
            }
            case OPCODE_DEFINE_GLOBAL: {
                uint16_t ix = frame_read_uint16(vm->current_frame);
                object_t value = stack_pop(vm);
                vm_set_global(vm, ix, value);
                break;
            }
            case OPCODE_SET_GLOBAL: {
                uint16_t ix = frame_read_uint16(vm->current_frame);
                object_t new_value = stack_pop(vm);
                object_t old_value = vm_get_global(vm, ix);
                if (!check_assign(vm, old_value, new_value)) {
                    goto err;
                }
                vm_set_global(vm, ix, new_value);
                break;
            }
            case OPCODE_GET_GLOBAL: {
                uint16_t ix = frame_read_uint16(vm->current_frame);
                object_t global = vm->globals[ix];
                stack_push(vm, global);
                break;
            }
            case OPCODE_ARRAY: {
                uint16_t count = frame_read_uint16(vm->current_frame);
                object_t array_obj = object_make_array_with_capacity(vm->mem, count);
                object_t *items = vm->stack + vm->sp - count;
                for (int i = 0; i < count; i++) {
                    object_t item = items[i];
                    object_add_array_value(array_obj, item);
                }
                set_sp(vm, vm->sp - count);
                stack_push(vm, array_obj);
                break;
            }
            case OPCODE_MAP_START: {
                uint16_t count = frame_read_uint16(vm->current_frame);
                object_t map_obj = object_make_map_with_capacity(vm->mem, count);
                this_stack_push(vm, map_obj);
                break;
            }
            case OPCODE_MAP_END: {
                uint16_t count = frame_read_uint16(vm->current_frame);
                object_t map_obj = this_stack_pop(vm);
                object_t *kvpairs = vm->stack + vm->sp - count;
                for (int i = 0; i < count; i += 2) {
                    object_t key = kvpairs[i];
                    if (!object_is_hashable(key)) {
                        object_type_t key_type = object_get_type(key);
                        const char *key_type_name = object_get_type_name(key_type);
                        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                                   "Key of type %s is not hashable", key_type_name);
                        vm_set_runtime_error(vm, err);
                        goto err;
                    }

                    object_t val = kvpairs[i + 1];
                    object_set_map_value(map_obj, key, val);
                }
                set_sp(vm, vm->sp - count);
                stack_push(vm, map_obj);
                break;
            }
            case OPCODE_GET_THIS: {
                object_t obj = this_stack_get(vm, 0);
                stack_push(vm, obj);
                break;
            }
            case OPCODE_GET_INDEX: {
                object_t index = stack_pop(vm);
                object_t left = stack_pop(vm);
                object_type_t left_type = object_get_type(left);
                object_type_t index_type = object_get_type(index);
                const char *left_type_name = object_get_type_name(left_type);
                const char *index_type_name = object_get_type_name(index_type);

                if (left_type != OBJECT_ARRAY && left_type != OBJECT_MAP && left_type != OBJECT_STRING) {
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                              "Type %s is not indexable", left_type_name);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }

                object_t res = object_make_null();

                if (left_type == OBJECT_ARRAY) {
                    if (index_type != OBJECT_NUMBER) {
                        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                                  "Cannot index %s with %s", left_type_name, index_type_name);
                        vm_set_runtime_error(vm, err);
                        goto err;
                    }
                    int ix = (int)object_get_number(index);
                    if (ix < 0) {
                        ix = object_get_array_length(left) + ix;
                    }
                    if (ix >= 0 && ix < object_get_array_length(left)) {
                        res = object_get_array_value_at(left, ix);
                    }
                } else if (left_type == OBJECT_MAP) {
                    res = object_get_map_value(left, index);
                } else if (left_type == OBJECT_STRING) {
                    const char *str = object_get_string(left);
                    int ix = (int)object_get_number(index);
                    if (ix >= 0 && ix < (int)strlen(str)) {
                        char res_str[2] = {str[ix], '\0'};
                        res = object_make_string(vm->mem, res_str);
                    }
                }
                stack_push(vm, res);
                break;
            }
            case OPCODE_GET_VALUE_AT: {
                object_t index = stack_pop(vm);
                object_t left = stack_pop(vm);
                object_type_t left_type = object_get_type(left);
                object_type_t index_type = object_get_type(index);
                const char *left_type_name = object_get_type_name(left_type);
                const char *index_type_name = object_get_type_name(index_type);

                if (left_type != OBJECT_ARRAY && left_type != OBJECT_MAP && left_type != OBJECT_STRING) {
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                               "Type %s is not indexable", left_type_name);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }

                object_t res = object_make_null();
                if (index_type != OBJECT_NUMBER) {
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                               "Cannot index %s with %s", left_type_name, index_type_name);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }
                int ix = (int)object_get_number(index);

                if (left_type == OBJECT_ARRAY) {
                    res = object_get_array_value_at(left, ix);
                } else if (left_type == OBJECT_MAP) {
                    res = object_get_kv_pair_at(vm->mem, left, ix);
                } else if (left_type == OBJECT_STRING) {
                    const char *str = object_get_string(left);
                    int ix = (int)object_get_number(index);
                    if (ix >= 0 && ix < (int)strlen(str)) {
                        char res_str[2] = {str[ix], '\0'};
                        res = object_make_string(vm->mem, res_str);
                    }
                }
                stack_push(vm, res);
                break;
            }
            case OPCODE_CALL: {
                uint8_t num_args = frame_read_uint8(vm->current_frame);
                object_t callee = stack_get(vm, num_args);
                bool ok = call_object(vm, callee, num_args);
                if (!ok) {
                    goto err;
                }
                break;
            }
            case OPCODE_RETURN_VALUE: {
                object_t res = stack_pop(vm);
                bool ok = pop_frame(vm);
                if (!ok) {
                    goto end;
                }
                stack_push(vm, res);
                break;
            }
            case OPCODE_RETURN: {
                bool ok = pop_frame(vm);
                stack_push(vm, object_make_null());
                if (!ok) {
                    stack_pop(vm);
                    goto end;
                }
                break;
            }
            case OPCODE_DEFINE_LOCAL: {
                uint8_t pos = frame_read_uint8(vm->current_frame);
                vm->stack[vm->current_frame->base_pointer + pos] = stack_pop(vm);
                break;
            }
            case OPCODE_SET_LOCAL: {
                uint8_t pos = frame_read_uint8(vm->current_frame);
                object_t new_value = stack_pop(vm);
                object_t old_value = vm->stack[vm->current_frame->base_pointer + pos];
                if (!check_assign(vm, old_value, new_value)) {
                    goto err;
                }
                vm->stack[vm->current_frame->base_pointer + pos] = new_value;
                break;
            }
            case OPCODE_GET_LOCAL: {
                uint8_t pos = frame_read_uint8(vm->current_frame);
                object_t val = vm->stack[vm->current_frame->base_pointer + pos];
                stack_push(vm, val);
                break;
            }
            case OPCODE_GET_NATIVE_FUNCTION: {
                uint16_t ix = frame_read_uint16(vm->current_frame);
                object_t *val = array_get(vm->native_functions, ix);
                if (!val) {
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Native function %d not found", ix);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }
                stack_push(vm, *val);
                break;
            }
            case OPCODE_FUNCTION: {
                uint16_t constant_ix = frame_read_uint16(vm->current_frame);
                uint8_t num_free = frame_read_uint8(vm->current_frame);
                object_t *constant = array_get(constants, constant_ix);
                if (!constant) {
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Constant %d not found", constant_ix);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }
                object_type_t constant_type = object_get_type(*constant);
                if (constant_type != OBJECT_FUNCTION) {
                    const char *type_name = object_get_type_name(constant_type);
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame), "%s is not a function", type_name);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }

                const function_t *constant_function = object_get_function(*constant);
                object_t function_obj = object_make_function(vm->mem, object_get_function_name(*constant),
                                                            constant_function->comp_result, false,
                                                            constant_function->num_locals, constant_function->num_args,
                                                            num_free);
                for (int i = 0; i < num_free; i++) {
                    object_t free_val = vm->stack[vm->sp - num_free + i];
                    object_set_function_free_val(function_obj, i, free_val);
                }
                set_sp(vm, vm->sp - num_free);
                stack_push(vm, function_obj);
                break;
            }
            case OPCODE_GET_FREE: {
                uint8_t free_ix = frame_read_uint8(vm->current_frame);
                object_t val = object_get_function_free_val(vm->current_frame->function, free_ix);
                stack_push(vm, val);
                break;
            }
            case OPCODE_SET_FREE: {
                uint8_t free_ix = frame_read_uint8(vm->current_frame);
                object_t val = stack_pop(vm);
                object_set_function_free_val(vm->current_frame->function, free_ix, val);
                break;
            }
            case OPCODE_CURRENT_FUNCTION: {
                object_t current_function = vm->current_frame->function;
                stack_push(vm, current_function);
                break;
            }
            case OPCODE_SET_INDEX: {
                object_t index = stack_pop(vm);
                object_t left = stack_pop(vm);
                object_t new_value = stack_pop(vm);
                object_type_t left_type = object_get_type(left);
                object_type_t index_type = object_get_type(index);
                const char *left_type_name = object_get_type_name(left_type);
                const char *index_type_name = object_get_type_name(index_type);

                if (left_type != OBJECT_ARRAY && left_type != OBJECT_MAP) {
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                              "Type %s is not indexable", left_type_name);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }

                if (left_type == OBJECT_ARRAY) {
                    if (index_type != OBJECT_NUMBER) {
                        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                                  "Cannot index %s with %s", left_type_name, index_type_name);
                        vm_set_runtime_error(vm, err);
                        goto err;
                    }
                    int ix = (int)object_get_number(index);
                    bool ok = object_set_array_value_at(left, ix, new_value);
                    if (!ok) {
                        error_t *err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Setting array item failed (out of bounds?)");
                        vm_set_runtime_error(vm, err);
                        goto err;
                    }
                } else if (left_type == OBJECT_MAP) {
                    object_t old_value = object_get_map_value(left, index);
                    if (!check_assign(vm, old_value, new_value)) {
                        goto err;
                    }
                    object_set_map_value(left, index, new_value);
                }
                break;
            }
            case OPCODE_DUP: {
                object_t val = stack_get(vm, 0);
                stack_push(vm, val);
                break;
            }
            case OPCODE_LEN: {
                object_t val = stack_pop(vm);
                int len = 0;
                object_type_t type = object_get_type(val);
                if (type == OBJECT_ARRAY) {
                    len = object_get_array_length(val);
                } else if (type == OBJECT_MAP) {
                    len = object_get_map_length(val);
                } else if (type == OBJECT_STRING) {
                    const char *str = object_get_string(val);
                    len = (int)strlen(str);
                } else {
                    const char *type_name = object_get_type_name(type);
                    error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Cannot get length of %s", type_name);
                    vm_set_runtime_error(vm, err);
                    goto err;
                }
                stack_push(vm, object_make_number(len));
                break;
            }
            case OPCODE_NUMBER: {
                uint64_t val = frame_read_uint64(vm->current_frame);
                double val_double = ape_uint64_to_double(val);
                object_t obj = object_make_number(val_double);
                stack_push(vm, obj);
                break;
            }
            case OPCODE_SET_RECOVER: {
                uint16_t recover_ip = frame_read_uint16(vm->current_frame);
                vm->current_frame->recover_ip = recover_ip;
                break;
            }
            default: {
                APE_ASSERT(false);
                error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Unknown opcode: 0x%x", opcode);
                vm_set_runtime_error(vm, err);
                goto err;
            }
        }
    err:
        if (vm->runtime_error != NULL) {
            int recover_frame_ix = -1;
            for (int i = vm->frames_count - 1; i >= 0; i--) {
                frame_t *frame = &vm->frames[i];
                if (frame->recover_ip >= 0 && !frame->is_recovering) {
                    recover_frame_ix = i;
                    break;
                }
            }
            if (recover_frame_ix < 0) {
                goto end;
            } else {
                error_t *err = vm->runtime_error;
                if (!err->traceback) {
                    err->traceback = traceback_make();
                }
                traceback_append_from_vm(err->traceback, vm);
                while (vm->frames_count > (recover_frame_ix + 1)) {
                    pop_frame(vm);
                }
                object_t err_obj = object_make_error(vm->mem, err->message);
                object_set_error_traceback(err_obj, err->traceback);
                err->traceback = NULL;
                stack_push(vm, err_obj);
                vm->current_frame->ip = vm->current_frame->recover_ip;
                vm->current_frame->is_recovering = true;
                error_destroy(vm->runtime_error);
                vm->runtime_error = NULL;
            }
        }
        if (ticks_between_gc >= 0 && ticks_since_gc >= ticks_between_gc) {
            run_gc(vm, constants);
            ticks_since_gc = 0;
        } else {
            ticks_since_gc++;
        }
    }

end:
    if (vm->runtime_error) {
        error_t *err = vm->runtime_error;
        if (!err->traceback) {
            err->traceback = traceback_make();
        }
        traceback_append_from_vm(err->traceback, vm);
        ptrarray_add(vm->errors, vm->runtime_error);
        vm->runtime_error = NULL;
    }

    run_gc(vm, constants);

    vm->running = false;
    return ptrarray_count(vm->errors) == 0;
}

object_t vm_get_last_popped(vm_t *vm) {
    return vm->last_popped;
}

bool vm_has_errors(vm_t *vm) {
    return vm->runtime_error != NULL || ptrarray_count(vm->errors) > 0;
}

void vm_set_global(vm_t *vm, int ix, object_t val) {
#ifdef APE_DEBUG
    if (ix >= VM_MAX_GLOBALS) {
        APE_ASSERT(false);
        error_t *err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Global write out of range");
        vm_set_runtime_error(vm, err);
        return;
    }
#endif
    vm->globals[ix] = val;
    if (ix >= vm->globals_count) {
        vm->globals_count = ix + 1;
    }
}

object_t vm_get_global(vm_t *vm, int ix) {
#ifdef APE_DEBUG
    if (ix >= VM_MAX_GLOBALS) {
        APE_ASSERT(false);
        error_t *err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Global read out of range");
        vm_set_runtime_error(vm, err);
        return object_make_null();
    }
#endif
    return vm->globals[ix];
}

void vm_set_runtime_error(vm_t *vm, error_t *error) {
    APE_ASSERT(vm->running);
    if (error) {
        APE_ASSERT(vm->runtime_error == NULL);
    }
    vm->runtime_error = error;
}

// INTERNAL
static void set_sp(vm_t *vm, int new_sp) {
    if (new_sp > vm->sp) { // to avoid gcing freed objects
        int count = new_sp - vm->sp;
        size_t bytes_count = count * sizeof(object_t);
        memset(vm->stack + vm->sp, 0, bytes_count);
    }
    vm->sp = new_sp;
}

static void stack_push(vm_t *vm, object_t obj) {
#ifdef APE_DEBUG
    if (vm->sp >= VM_STACK_SIZE) {
        APE_ASSERT(false);
        error_t *err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Stack overflow");
        vm_set_runtime_error(vm, err);
        return;
    }
    if (vm->current_frame) {
        frame_t *frame = vm->current_frame;
        function_t *current_function = object_get_function(frame->function);
        int num_locals = current_function->num_locals;
        APE_ASSERT(vm->sp >= (frame->base_pointer + num_locals));
    }
#endif
    vm->stack[vm->sp] = obj;
    vm->sp++;
}

static object_t stack_pop(vm_t *vm) {
#ifdef APE_DEBUG
    if (vm->sp == 0) {
        error_t *err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), "Stack underflow");
        vm_set_runtime_error(vm, err);
        APE_ASSERT(false);
        return object_make_null();
    }
    if (vm->current_frame) {
        frame_t *frame = vm->current_frame;
        function_t *current_function = object_get_function(frame->function);
        int num_locals = current_function->num_locals;
        APE_ASSERT((vm->sp - 1) >= (frame->base_pointer + num_locals));
    }
#endif
    vm->sp--;
    object_t res = vm->stack[vm->sp];
    vm->last_popped = res;
    return res;
}

static object_t stack_get(vm_t *vm, int nth_item) {
    int ix = vm->sp - 1 - nth_item;
#ifdef APE_DEBUG
    if (ix < 0 || ix >= VM_STACK_SIZE) {
        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                  "Invalid stack index: %d", nth_item);
        vm_set_runtime_error(vm, err);
        APE_ASSERT(false);
        return object_make_null();
    }
#endif
    return vm->stack[ix];
}

static void this_stack_push(vm_t *vm, object_t obj) {
#ifdef APE_DEBUG
    if (vm->this_sp >= VM_THIS_STACK_SIZE) {
        APE_ASSERT(false);
        error_t *err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), "this stack overflow");
        vm_set_runtime_error(vm, err);
        return;
    }
#endif
    vm->this_stack[vm->this_sp] = obj;
    vm->this_sp++;
}

static object_t this_stack_pop(vm_t *vm) {
#ifdef APE_DEBUG
    if (vm->this_sp == 0) {
        error_t *err = error_make(ERROR_RUNTIME, frame_src_position(vm->current_frame), "this stack underflow");
        vm_set_runtime_error(vm, err);
        APE_ASSERT(false);
        return object_make_null();
    }
#endif
    vm->this_sp--;
    return vm->this_stack[vm->this_sp];
}

static object_t this_stack_get(vm_t *vm, int nth_item) {
    int ix = vm->this_sp - 1 - nth_item;
#ifdef APE_DEBUG
    if (ix < 0 || ix >= VM_THIS_STACK_SIZE) {
        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                   "Invalid this stack index: %d", nth_item);
        vm_set_runtime_error(vm, err);
        APE_ASSERT(false);
        return object_make_null();
    }
#endif
    return vm->this_stack[ix];
}

static bool push_frame(vm_t *vm, frame_t frame) {
    if (vm->frames_count >= VM_MAX_FRAMES) {
        APE_ASSERT(false);
        return false;
    }
    vm->frames[vm->frames_count] = frame;
    vm->current_frame = &vm->frames[vm->frames_count];
    vm->frames_count++;
    function_t *frame_function = object_get_function(frame.function);
    set_sp(vm, frame.base_pointer + frame_function->num_locals);
    return true;
}

static bool pop_frame(vm_t *vm) {
    set_sp(vm, vm->current_frame->base_pointer - 1);
    if (vm->frames_count <= 0) {
        APE_ASSERT(false);
        vm->current_frame = NULL;
        return false;
    }
    vm->frames_count--;
    if (vm->frames_count == 0) {
        vm->current_frame = NULL;
        return false;
    }
    vm->current_frame = &vm->frames[vm->frames_count - 1];
    return true;
}

static void run_gc(vm_t *vm, array(object_t) *constants) {
    gc_unmark_all(vm->mem);
    gc_mark_objects(array_data(vm->native_functions), array_count(vm->native_functions));
    gc_mark_objects(array_data(constants), array_count(constants));
    gc_mark_objects(vm->globals, vm->globals_count);
    for (int i = 0; i < vm->frames_count; i++) {
        frame_t *frame = &vm->frames[i];
        gc_mark_object(frame->function);
    }
    gc_mark_objects(vm->stack, vm->sp);
    gc_mark_objects(vm->this_stack, vm->this_sp);
    gc_mark_object(vm->last_popped);
    gc_mark_objects(vm->operator_oveload_keys, OPCODE_MAX);
    gc_sweep(vm->mem);
}

static bool call_object(vm_t *vm, object_t callee, int num_args) {
    object_type_t callee_type = object_get_type(callee);
    if (callee_type == OBJECT_FUNCTION) {
        function_t *callee_function = object_get_function(callee);
        if (num_args != callee_function->num_args) {
            error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                       "Invalid number of arguments to \"%s\", expected %d, got %d",
                                       object_get_function_name(callee), callee_function->num_args, num_args);
            vm_set_runtime_error(vm, err);
            return false;
        }
        frame_t callee_frame;
        frame_init(&callee_frame, callee, vm->sp - num_args);
        bool ok = push_frame(vm, callee_frame);
        if (!ok) {
            error_t *err = error_make(ERROR_RUNTIME, src_pos_invalid, "Pushing frame failed in call_object");
            vm_set_runtime_error(vm, err);
            return false;
        }
    } else if (callee_type == OBJECT_NATIVE_FUNCTION) {
        object_t *stack_pos = vm->stack + vm->sp - num_args;
        object_t res = call_native_function(vm, callee, frame_src_position(vm->current_frame), num_args, stack_pos);
        if (vm_has_errors(vm)) {
            return false;
        }
        set_sp(vm, vm->sp - num_args - 1);
        stack_push(vm, res);
    } else {
        const char *callee_type_name = object_get_type_name(callee_type);
        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                   "%s object is not callable", callee_type_name);
        vm_set_runtime_error(vm, err);
        return false;
    }
    return true;
}

static object_t call_native_function(vm_t *vm, object_t callee, src_pos_t src_pos, int argc, object_t *args) {
    native_function_t *bn = object_get_native_function(callee);
    object_t res = bn->fn(vm, bn->data, argc, args);
    if (vm->runtime_error != NULL && !APE_STREQ(bn->name, "crash")) {
        error_t *err = vm->runtime_error;
        err->pos = src_pos;
        err->traceback = traceback_make();
        traceback_append(err->traceback, bn->name, src_pos_invalid);
        return object_make_null();
    }
    object_type_t res_type = object_get_type(res);
    if (res_type == OBJECT_ERROR) {
        traceback_t *traceback = traceback_make();
         // error builtin is treated in a special way
        if (!APE_STREQ(bn->name, "error")) {
            traceback_append(traceback, bn->name, src_pos_invalid);
        }
        traceback_append_from_vm(traceback, vm);
        object_set_error_traceback(res, traceback);
    }
    return res;
}

static bool check_assign(vm_t *vm, object_t old_value, object_t new_value) {
    object_type_t old_value_type = object_get_type(old_value);
    object_type_t new_value_type = object_get_type(new_value);
    if (old_value_type == OBJECT_NULL || new_value_type == OBJECT_NULL) {
        return true;
    }
    if (old_value_type != new_value_type) {
        error_t *err = error_makef(ERROR_RUNTIME, frame_src_position(vm->current_frame),
                                   "Trying to assign variable of type %s to %s",
                                   object_get_type_name(new_value_type),
                                   object_get_type_name(old_value_type)
                                   );
        vm_set_runtime_error(vm, err);
        return false;
    }
    return true;
}

static bool try_overload_operator(vm_t *vm, object_t left, object_t right, opcode_t op, bool *out_overload_found) {
    *out_overload_found = false;
    object_type_t left_type = object_get_type(left);
    object_type_t right_type = object_get_type(right);
    if (left_type != OBJECT_MAP && right_type != OBJECT_MAP) {
        *out_overload_found = false;
        return true;
    }

    int num_operands = 2;
    if (op == OPCODE_MINUS || op == OPCODE_BANG) {
        num_operands = 1;
    }

    object_t key = vm->operator_oveload_keys[op];
    object_t callee = object_make_null();
    if (left_type == OBJECT_MAP) {
        callee = object_get_map_value(left, key);
    }
    if (!object_is_callable(callee)) {
        if (right_type == OBJECT_MAP) {
            callee = object_get_map_value(right, key);
        }

        if (!object_is_callable(callee)) {
            *out_overload_found = false;
            return true;
        }
    }

    *out_overload_found = true;

    stack_push(vm, callee);
    stack_push(vm, left);
    if (num_operands == 2) {
        stack_push(vm, right);
    }
    bool ok = call_object(vm, callee, num_operands);
    return ok;
}

//FILE_END
//FILE_START:ape.c
#include "ape.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#define APE_IMPL_VERSION_MAJOR 0
#define APE_IMPL_VERSION_MINOR 5
#define APE_IMPL_VERSION_PATCH 0

#if (APE_VERSION_MAJOR != APE_IMPL_VERSION_MAJOR)\
 || (APE_VERSION_MINOR != APE_IMPL_VERSION_MINOR)\
 || (APE_VERSION_PATCH != APE_IMPL_VERSION_PATCH)
    #error "Version mismatch"
#endif

#ifndef APE_AMALGAMATED
#include "ape.h"
#include "gc.h"
#include "compiler.h"
#include "lexer.h"
#include "parser.h"
#include "vm.h"
#include "error.h"
#include "symbol_table.h"
#include "traceback.h"
#endif

typedef struct native_fn_wrapper {
    ape_native_fn fn;
    ape_t *ape;
    void *data;
} native_fn_wrapper_t;

typedef struct ape_program {
    ape_t *ape;
    compilation_result_t *comp_res;
} ape_program_t;

typedef struct ape {
    gcmem_t *mem;
    compiler_t *compiler;
    vm_t *vm;
    ptrarray(ape_error_t) *errors;
    ptrarray(native_fn_wrapper_t) *native_fn_wrappers;
    ape_config_t config;
} ape_t;

static object_t ape_native_fn_wrapper(vm_t *vm, void *data, int argc, object_t *args);
static object_t ape_object_to_object(ape_object_t obj);
static ape_object_t object_to_ape_object(object_t obj);

static void reset_state(ape_t *ape);
static void set_default_config(ape_t *ape);
static char* read_file_default(void *ctx, const char *filename);
static size_t write_file_default(void* context, const char *path, const char *string, size_t string_size);
static size_t stdout_write_default(void* context, const void *data, size_t size);

#undef malloc
#undef free


void* ape_mallocArg = NULL;
void* ape_freeArg = NULL;
ape_malloc_fn ape_malloc = apeMalloc;
ape_free_fn ape_free = apeFree;

//-----------------------------------------------------------------------------
// Ape
//-----------------------------------------------------------------------------

void ape_set_memory_functions(void* mallocArg, ape_malloc_fn malloc_fn, void* freeArg, ape_free_fn free_fn) {
    ape_mallocArg = mallocArg;
    ape_malloc = malloc_fn;
    ape_freeArg = freeArg;
    ape_free = free_fn;
    collections_set_memory_functions(malloc_fn, free_fn);
}

ape_t *ape_make(void) {
    ape_t *ape = ape_malloc(sizeof(ape_t), ape_mallocArg);
    memset(ape, 0, sizeof(ape_t));

    set_default_config(ape);

    ape->mem = gcmem_make();
    ape->errors = ptrarray_make();
    if (!ape->errors) {
        goto err;
    }
    if (!ape->mem) {
        goto err;
    }
    ape->compiler = compiler_make(&ape->config, ape->mem, ape->errors);
    if (!ape->compiler) {
        goto err;
    }
    ape->vm = vm_make(&ape->config, ape->mem, ape->errors);
    if (!ape->vm) {
        goto err;
    }
    ape->native_fn_wrappers = ptrarray_make();
    if (!ape->native_fn_wrappers) {
        goto err;
    }
    return ape;
err:
    gcmem_destroy(ape->mem);
    compiler_destroy(ape->compiler);
    vm_destroy(ape->vm);
    ptrarray_destroy(ape->errors);
    return NULL;
}

void ape_destroy(ape_t *ape) {
    if (!ape) {
        return;
    }
    ptrarray_destroy_with_items(ape->native_fn_wrappers, ape_free);
    ptrarray_destroy_with_items(ape->errors, error_destroy);
    vm_destroy(ape->vm);
    compiler_destroy(ape->compiler);
    gcmem_destroy(ape->mem);
    ape_free(ape, ape_freeArg);
}

void ape_set_repl_mode(ape_t *ape, bool enabled) {
    ape->config.repl_mode = enabled;
}

void ape_set_gc_interval(ape_t *ape, int interval) {
    ape->config.gc_interval = interval;
}

void ape_set_stdout_write_function(ape_t *ape, ape_stdout_write_fn stdout_write, void *context) {
    ape->config.stdio.write.write = stdout_write;
    ape->config.stdio.write.context = context;
}

void ape_set_file_write_function(ape_t *ape, ape_write_file_fn file_write, void *context) {
    ape->config.fileio.write_file.write_file = file_write;
    ape->config.fileio.write_file.context = context;
}

void ape_set_file_read_function(ape_t *ape, ape_read_file_fn file_read, void *context) {
    ape->config.fileio.read_file.read_file = file_read;
    ape->config.fileio.read_file.context = context;
}

ape_program_t* ape_compile(ape_t *ape, const char *code) {
    ptrarray_clear_and_destroy_items(ape->errors, error_destroy);

    compilation_result_t *comp_res = NULL;

    comp_res = compiler_compile(ape->compiler, code);
    if (!comp_res || ptrarray_count(ape->errors) > 0) {
        goto err;
    }

    ape_program_t *program = ape_malloc(sizeof(ape_program_t), ape_mallocArg);
    program->ape = ape;
    program->comp_res = comp_res;
    return program;

err:
    compilation_result_destroy(comp_res);
    return NULL;
}

ape_program_t* ape_compile_file(ape_t *ape, const char *path) {
    ptrarray_clear_and_destroy_items(ape->errors, error_destroy);

    compilation_result_t *comp_res = NULL;

    comp_res = compiler_compile_file(ape->compiler, path);
    if (!comp_res || ptrarray_count(ape->errors) > 0) {
        goto err;
    }

    ape_program_t *program = ape_malloc(sizeof(ape_program_t), ape_mallocArg);
    program->ape = ape;
    program->comp_res = comp_res;
    return program;

err:
    compilation_result_destroy(comp_res);
    return NULL;
}

ape_object_t ape_execute_program(ape_t *ape, const ape_program_t *program) {
    reset_state(ape);

    if (ape != program->ape) {
        error_t *err = error_make(ERROR_USER, src_pos_invalid, "ape program was compiled with a different ape instance");
        ptrarray_add(ape->errors, err);
        return ape_object_make_null();
    }

    bool ok = vm_run(ape->vm, program->comp_res, ape->compiler->constants);
    if (!ok || ptrarray_count(ape->errors)) {
        return ape_object_make_null();
    }

    APE_ASSERT(ape->vm->sp == 0);

    object_t res = vm_get_last_popped(ape->vm);
    if (object_get_type(res) == OBJECT_NONE) {
        return ape_object_make_null();
    }

    return object_to_ape_object(res);
}

void ape_program_destroy(ape_program_t *program) {
    if (!program) {
        return;
    }
    compilation_result_destroy(program->comp_res);
    ape_free(program, ape_freeArg);
}

ape_object_t ape_execute(ape_t *ape, const char *code) {
    reset_state(ape);

    compilation_result_t *comp_res = NULL;

    comp_res = compiler_compile(ape->compiler, code);
    if (!comp_res || ptrarray_count(ape->errors) > 0) {
        goto err;
    }

    bool ok = vm_run(ape->vm, comp_res, ape->compiler->constants);
    if (!ok || ptrarray_count(ape->errors)) {
        goto err;
    }

    APE_ASSERT(ape->vm->sp == 0);

    object_t res = vm_get_last_popped(ape->vm);
    if (object_get_type(res) == OBJECT_NONE) {
        goto err;
    }

    compilation_result_destroy(comp_res);

    return object_to_ape_object(res);

err:
    compilation_result_destroy(comp_res);
    return ape_object_make_null();
}

ape_object_t ape_execute_file(ape_t *ape, const char *path) {
    reset_state(ape);

    compilation_result_t *comp_res = NULL;

    comp_res = compiler_compile_file(ape->compiler, path);
    if (!comp_res || ptrarray_count(ape->errors) > 0) {
        goto err;
    }

    bool ok = vm_run(ape->vm, comp_res, ape->compiler->constants);
    if (!ok || ptrarray_count(ape->errors)) {
        goto err;
    }

    APE_ASSERT(ape->vm->sp == 0);

    object_t res = vm_get_last_popped(ape->vm);
    if (object_get_type(res) == OBJECT_NONE) {
        goto err;
    }

    compilation_result_destroy(comp_res);

    return object_to_ape_object(res);

err:
    compilation_result_destroy(comp_res);
    return ape_object_make_null();
}

ape_object_t ape_call(ape_t *ape, const char *function_name, int argc, ape_object_t *args) {
    reset_state(ape);

    object_t callee = ape_object_to_object(ape_get_object(ape, function_name));
    if (object_get_type(callee) == OBJECT_NULL) {
        return ape_object_make_null();
    }
    object_t res = vm_call(ape->vm, ape->compiler->constants, callee, argc, (object_t*)args);
    if (ptrarray_count(ape->errors) > 0) {
        return ape_object_make_null();
    }
    return object_to_ape_object(res);
}

bool ape_has_errors(const ape_t *ape) {
    return ptrarray_count(ape->errors) > 0;
}

int ape_errors_count(const ape_t *ape) {
    return ptrarray_count(ape->errors);
}

const ape_error_t* ape_get_error(const ape_t *ape, int index) {
    return ptrarray_get(ape->errors, index);
}

bool ape_set_native_function(ape_t *ape, const char *name, ape_native_fn fn, void *data) {
    native_fn_wrapper_t *wrapper = ape_malloc(sizeof(native_fn_wrapper_t), ape_mallocArg);
    memset(wrapper, 0, sizeof(native_fn_wrapper_t));
    wrapper->fn = fn;
    wrapper->ape = ape;
    wrapper->data = data;
    object_t wrapper_native_function = object_make_native_function(ape->mem, name, ape_native_fn_wrapper, wrapper);
    int ix = array_count(ape->vm->native_functions);
    array_add(ape->vm->native_functions, &wrapper_native_function);
    symbol_table_t *symbol_table = compiler_get_symbol_table(ape->compiler);
    symbol_table_define_native_function(symbol_table, name, ix);
    ptrarray_add(ape->native_fn_wrappers, wrapper);
    return true;
}

bool ape_set_global_constant(ape_t *ape, const char *name, ape_object_t obj) {
    symbol_table_t *symbol_table = compiler_get_symbol_table(ape->compiler);
    symbol_t *symbol = NULL;
    if (symbol_table_symbol_is_defined(symbol_table, name)) {
        symbol = symbol_table_resolve(symbol_table, name);
        if (symbol->type != SYMBOL_GLOBAL) {
            error_t *err = error_makef(ERROR_USER, src_pos_invalid,
                                       "Symbol \"%s\" already defined outside global scope", name);
            ptrarray_add(ape->errors, err);
            return false;
        }
    } else {
        symbol = symbol_table_define(symbol_table, name, false);
    }
    vm_set_global(ape->vm, symbol->index, ape_object_to_object(obj));
    return true;
}

ape_object_t ape_get_object(ape_t *ape, const char *name) {
    symbol_table_t *st = compiler_get_symbol_table(ape->compiler);
    symbol_t *symbol = symbol_table_resolve(st, name);
    if (!symbol) {
        error_t *err = error_makef(ERROR_USER, src_pos_invalid,
                                   "Symbol \"%s\" is not defined", name);
        ptrarray_add(ape->errors, err);
        return ape_object_make_null();
    }
    object_t res = object_make_null();
    if (symbol->type == SYMBOL_GLOBAL) {
        res = vm_get_global(ape->vm, symbol->index);
    } else if (symbol->type == SYMBOL_NATIVE_FUNCTION) {
        object_t *res_ptr = array_get(ape->vm->native_functions, symbol->index);
        res = *res_ptr;
    } else {
        error_t *err = error_makef(ERROR_USER, src_pos_invalid,
                                   "Value associated with symbol \"%s\" could not be loaded", name);
        ptrarray_add(ape->errors, err);
        return ape_object_make_null();
    }
    return object_to_ape_object(res);
}

bool ape_check_args(ape_t *ape, bool generate_error, int argc, ape_object_t *args, int expected_argc, int *expected_types) {
    if (argc != expected_argc) {
        if (generate_error) {
            ape_set_runtime_errorf(ape, "Invalid number or arguments, got %d instead of %d", argc, expected_argc);
        }
        return false;
    }

    for(int i = 0; i < argc; i++) {
        ape_object_t arg = args[i];
        ape_object_type_t type = ape_object_get_type(arg);
        ape_object_type_t expected_type = expected_types[i];
        if (!(type & expected_type)) {
            if (generate_error) {
                const char *type_str = ape_object_get_type_name(type);
                const char *expected_type_str = ape_object_get_type_name(expected_type);
                ape_set_runtime_errorf(ape, "Invalid argument type, got %s, expected %s", type_str, expected_type_str);
            }
            return false;
        }
    }
    return true;
}

//-----------------------------------------------------------------------------
// Ape object
//-----------------------------------------------------------------------------

ape_object_t ape_object_make_number(double val) {
    return object_to_ape_object(object_make_number(val));
}

ape_object_t ape_object_make_bool(bool val) {
    return object_to_ape_object(object_make_bool(val));
}

ape_object_t ape_object_make_string(ape_t *ape, const char *str) {
    return object_to_ape_object(object_make_string(ape->mem, str));
}

ape_object_t ape_object_make_stringf(ape_t *ape, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int to_write = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    va_start(args, fmt);
    char *res = (char*)ape_malloc(to_write + 1, ape_mallocArg);
    int written = vsprintf(res, fmt, args);
    (void)written;
    APE_ASSERT(written == to_write);
    va_end(args);
    return object_to_ape_object(object_make_string_no_copy(ape->mem, res));
}

ape_object_t ape_object_make_null() {
    return object_to_ape_object(object_make_null());
}

ape_object_t ape_object_make_array(ape_t *ape) {
    return object_to_ape_object(object_make_array(ape->mem));
}

ape_object_t ape_object_make_map(ape_t *ape) {
    return object_to_ape_object(object_make_map(ape->mem));
}

ape_object_t ape_object_make_native_function(ape_t *ape, ape_native_fn fn, void *data) {
    native_fn_wrapper_t *wrapper = ape_malloc(sizeof(native_fn_wrapper_t), ape_mallocArg);
    memset(wrapper, 0, sizeof(native_fn_wrapper_t));
    wrapper->fn = fn;
    wrapper->ape = ape;
    wrapper->data = data;
    object_t wrapper_native_function = object_make_native_function(ape->mem, "", ape_native_fn_wrapper, wrapper);
    ptrarray_add(ape->native_fn_wrappers, wrapper);
    return object_to_ape_object(wrapper_native_function);
}

ape_object_t ape_object_make_error(ape_t *ape, const char *msg) {
    return object_to_ape_object(object_make_error(ape->mem, msg));
}

ape_object_t ape_object_make_errorf(ape_t *ape, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int to_write = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    va_start(args, fmt);
    char *res = (char*)ape_malloc(to_write + 1, ape_mallocArg);
    int written = vsprintf(res, fmt, args);
    (void)written;
    APE_ASSERT(written == to_write);
    va_end(args);
    return object_to_ape_object(object_make_error_no_copy(ape->mem, res));
}

ape_object_t ape_object_make_external(ape_t *ape, void *data) {
    object_t res = object_make_external(ape->mem, data);
    return object_to_ape_object(res);
}

char *ape_object_serialize(ape_object_t obj) {
    return object_serialize(ape_object_to_object(obj));
}

void ape_object_disable_gc(ape_object_t ape_obj) {
    object_t obj = ape_object_to_object(ape_obj);
    gc_disable_on_object(obj);
}

void ape_object_enable_gc(ape_object_t ape_obj) {
    object_t obj = ape_object_to_object(ape_obj);
    gc_enable_on_object(obj);
}

bool ape_object_equals(ape_object_t ape_a, ape_object_t ape_b){
    object_t a = ape_object_to_object(ape_a);
    object_t b = ape_object_to_object(ape_b);
    return object_equals(a, b);
}

ape_object_t ape_object_copy(ape_object_t ape_obj) {
    object_t obj = ape_object_to_object(ape_obj);
    gcmem_t *mem = object_get_mem(obj);
    object_t res = object_copy(mem, obj);
    return object_to_ape_object(res);
}

ape_object_t ape_object_deep_copy(ape_object_t ape_obj) {
    object_t obj = ape_object_to_object(ape_obj);
    gcmem_t *mem = object_get_mem(obj);
    object_t res = object_deep_copy(mem, obj);
    return object_to_ape_object(res);
}

void ape_set_runtime_error(ape_t *ape, const char *message) {
    error_t *err = error_make(ERROR_RUNTIME, src_pos_invalid, message);
    ptrarray_add(ape->errors, err);
}

void ape_set_runtime_errorf(ape_t *ape, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int to_write = vsnprintf(NULL, 0, fmt, args);
    va_end(args);
    va_start(args, fmt);
    char *message = (char*)ape_malloc(to_write + 1, ape_mallocArg);
    vsprintf(message, fmt, args);
    va_end(args);

    error_t *err = error_make_no_copy(ERROR_RUNTIME, src_pos_invalid, message);

    ptrarray_add(ape->errors, err);
}

ape_object_type_t ape_object_get_type(ape_object_t ape_obj) {
    object_t obj = ape_object_to_object(ape_obj);
    switch (object_get_type(obj)) {
        case OBJECT_NONE:            return APE_OBJECT_NONE;
        case OBJECT_ERROR:           return APE_OBJECT_ERROR;
        case OBJECT_NUMBER:          return APE_OBJECT_NUMBER;
        case OBJECT_BOOL:            return APE_OBJECT_BOOL;
        case OBJECT_STRING:          return APE_OBJECT_STRING;
        case OBJECT_NULL:            return APE_OBJECT_NULL;
        case OBJECT_NATIVE_FUNCTION: return APE_OBJECT_NATIVE_FUNCTION;
        case OBJECT_ARRAY:           return APE_OBJECT_ARRAY;
        case OBJECT_MAP:             return APE_OBJECT_MAP;
        case OBJECT_FUNCTION:        return APE_OBJECT_FUNCTION;
        case OBJECT_EXTERNAL:        return APE_OBJECT_EXTERNAL;
        case OBJECT_FREED:           return APE_OBJECT_FREED;
        case OBJECT_ANY:             return APE_OBJECT_ANY;
        default:                     return APE_OBJECT_NONE;
    }
}

const char* ape_object_get_type_string(ape_object_t obj) {
    return ape_object_get_type_name(ape_object_get_type(obj));
}

const char* ape_object_get_type_name(ape_object_type_t type) {
    switch (type) {
        case APE_OBJECT_NONE:            return "NONE";
        case APE_OBJECT_ERROR:           return "ERROR";
        case APE_OBJECT_NUMBER:          return "NUMBER";
        case APE_OBJECT_BOOL:            return "BOOL";
        case APE_OBJECT_STRING:          return "STRING";
        case APE_OBJECT_NULL:            return "NULL";
        case APE_OBJECT_NATIVE_FUNCTION: return "NATIVE_FUNCTION";
        case APE_OBJECT_ARRAY:           return "ARRAY";
        case APE_OBJECT_MAP:             return "MAP";
        case APE_OBJECT_FUNCTION:        return "FUNCTION";
        case APE_OBJECT_EXTERNAL:        return "EXTERNAL";
        case APE_OBJECT_FREED:           return "FREED";
        case APE_OBJECT_ANY:             return "ANY";
        default:                         return "NONE";
    }
}

double ape_object_get_number(ape_object_t obj) {
    return object_get_number(ape_object_to_object(obj));
}

bool ape_object_get_bool(ape_object_t obj) {
    return object_get_bool(ape_object_to_object(obj));
}

const char *ape_object_get_string(ape_object_t obj) {
    return object_get_string(ape_object_to_object(obj));
}

void *ape_object_get_external(ape_object_t obj) {
    external_data_t* data = object_get_external_data(ape_object_to_object(obj));
    if(!data) return NULL;
    return data->data;
}

const char *ape_object_get_error_message(ape_object_t obj) {
    return object_get_error_message(ape_object_to_object(obj));
}

const ape_traceback_t* ape_object_get_error_traceback(ape_object_t ape_obj) {
    object_t obj = ape_object_to_object(ape_obj);
    return (const ape_traceback_t*)object_get_error_traceback(obj);
}

bool ape_object_set_external_destroy_function(ape_object_t object, ape_data_destroy_fn destroy_fn) {
    return object_set_external_destroy_function(ape_object_to_object(object), (external_data_destroy_fn)destroy_fn);
}

bool ape_object_set_external_copy_function(ape_object_t object, ape_data_copy_fn copy_fn) {
    return object_set_external_copy_function(ape_object_to_object(object), (external_data_copy_fn)copy_fn);
}

//-----------------------------------------------------------------------------
// Ape object array
//-----------------------------------------------------------------------------

int ape_object_get_array_length(ape_object_t obj) {
    return object_get_array_length(ape_object_to_object(obj));
}

ape_object_t ape_object_get_array_value(ape_object_t obj, int ix) {
    object_t res = object_get_array_value_at(ape_object_to_object(obj), ix);
    return object_to_ape_object(res);
}

const char* ape_object_get_array_string(ape_object_t obj, int ix) {
    ape_object_t object = ape_object_get_array_value(obj, ix);
    if (ape_object_get_type(object) != APE_OBJECT_STRING) {
        return NULL;
    }
    return ape_object_get_string(object);
}

double ape_object_get_array_number(ape_object_t obj, int ix) {
    ape_object_t object = ape_object_get_array_value(obj, ix);
    if (ape_object_get_type(object) != APE_OBJECT_NUMBER) {
        return 0;
    }
    return ape_object_get_number(object);
}

bool ape_object_get_array_bool(ape_object_t obj, int ix) {
    ape_object_t object = ape_object_get_array_value(obj, ix);
    if (ape_object_get_type(object) != APE_OBJECT_BOOL) {
        return 0;
    }
    return ape_object_get_bool(object);
}

bool ape_object_set_array_value(ape_object_t ape_obj, int ix, ape_object_t ape_value) {
    object_t obj = ape_object_to_object(ape_obj);
    object_t value = ape_object_to_object(ape_value);
    return object_set_array_value_at(obj, ix, value);
}

bool ape_object_set_array_string(ape_object_t obj, int ix, const char *string) {
    gcmem_t *mem = object_get_mem(ape_object_to_object(obj));
    if (!mem) {
        return false;
    }
    object_t new_value = object_make_string(mem, string);
    return ape_object_set_array_value(obj, ix, object_to_ape_object(new_value));
}

bool ape_object_set_array_number(ape_object_t obj, int ix, double number) {
    object_t new_value = object_make_number(number);
    return ape_object_set_array_value(obj, ix, object_to_ape_object(new_value));
}

bool ape_object_set_array_bool(ape_object_t obj, int ix, bool value) {
    object_t new_value = object_make_bool(value);
    return ape_object_set_array_value(obj, ix, object_to_ape_object(new_value));
}

bool ape_object_add_array_value(ape_object_t ape_obj, ape_object_t ape_value) {
    object_t obj = ape_object_to_object(ape_obj);
    object_t value = ape_object_to_object(ape_value);
    return object_add_array_value(obj, value);
}

bool ape_object_add_array_string(ape_object_t obj, const char *string) {
    gcmem_t *mem = object_get_mem(ape_object_to_object(obj));
    if (!mem) {
        return false;
    }
    object_t new_value = object_make_string(mem, string);
    return ape_object_add_array_value(obj, object_to_ape_object(new_value));
}

bool ape_object_add_array_number(ape_object_t obj, double number) {
    object_t new_value = object_make_number(number);
    return ape_object_add_array_value(obj, object_to_ape_object(new_value));
}

bool ape_object_add_array_bool(ape_object_t obj, bool value) {
    object_t new_value = object_make_bool(value);
    return ape_object_add_array_value(obj, object_to_ape_object(new_value));
}

//-----------------------------------------------------------------------------
// Ape object map
//-----------------------------------------------------------------------------

int ape_object_get_map_length(ape_object_t obj) {
    return object_get_map_length(ape_object_to_object(obj));
}

ape_object_t ape_object_get_map_key_at(ape_object_t ape_obj, int ix) {
    object_t obj = ape_object_to_object(ape_obj);
    return object_to_ape_object(object_get_map_key_at(obj, ix));
}

ape_object_t ape_object_get_map_value_at(ape_object_t ape_obj, int ix) {
    object_t obj = ape_object_to_object(ape_obj);
    object_t res = object_get_map_value_at(obj, ix);
    return object_to_ape_object(res);
}

bool ape_object_set_map_value_at(ape_object_t ape_obj, int ix, ape_object_t ape_val) {
    object_t obj = ape_object_to_object(ape_obj);
    object_t val = ape_object_to_object(ape_val);
    return object_set_map_value_at(obj, ix, val);
}

bool ape_object_set_map_value_with_value_key(ape_object_t obj, ape_object_t key, ape_object_t val) {
    return object_set_map_value(ape_object_to_object(obj), ape_object_to_object(key), ape_object_to_object(val));
}

bool ape_object_set_map_value(ape_object_t obj, const char *key, ape_object_t value) {
    gcmem_t *mem = object_get_mem(ape_object_to_object(obj));
    object_t key_object = object_make_string(mem, key);
    return ape_object_set_map_value_with_value_key(obj, object_to_ape_object(key_object), value);
}

bool ape_object_set_map_string(ape_object_t obj, const char *key, const char *string) {
    gcmem_t *mem = object_get_mem(ape_object_to_object(obj));
    object_t string_object = object_make_string(mem, string);
    return ape_object_set_map_value(obj, key, object_to_ape_object(string_object));
}

bool ape_object_set_map_number(ape_object_t obj, const char *key, double number) {
    object_t number_object = object_make_number(number);
    return ape_object_set_map_value(obj, key, object_to_ape_object(number_object));
}

bool ape_object_set_map_bool(ape_object_t obj, const char *key, bool value) {
    object_t bool_object = object_make_bool(value);
    return ape_object_set_map_value(obj, key, object_to_ape_object(bool_object));
}

ape_object_t ape_object_get_map_value_with_value_key(ape_object_t obj, ape_object_t key) {
    return object_to_ape_object(object_get_map_value(ape_object_to_object(obj), ape_object_to_object(key)));
}

ape_object_t ape_object_get_map_value(ape_object_t object, const char *key) {
    gcmem_t *mem = object_get_mem(ape_object_to_object(object));
    if (!mem) {
        return ape_object_make_null();
    }
    object_t key_object = object_make_string(mem, key);
    ape_object_t res = ape_object_get_map_value_with_value_key(object, object_to_ape_object(key_object));
    return res;
}

const char* ape_object_get_map_string(ape_object_t object, const char *key) {
    ape_object_t res = ape_object_get_map_value(object, key);
    return ape_object_get_string(res);
}

double ape_object_get_map_number(ape_object_t object, const char *key) {
    ape_object_t res = ape_object_get_map_value(object, key);
    return ape_object_get_number(res);
}

bool ape_object_get_map_bool(ape_object_t object, const char *key) {
    ape_object_t res = ape_object_get_map_value(object, key);
    return ape_object_get_bool(res);
}

bool ape_object_map_has_key(ape_object_t ape_object, const char *key) {
    object_t object = ape_object_to_object(ape_object);
    gcmem_t *mem = object_get_mem(object);
    if (!mem) {
        return false;
    }
    object_t key_object = object_make_string(mem, key);
    return object_map_has_key(object, key_object);
}

//-----------------------------------------------------------------------------
// Ape error
//-----------------------------------------------------------------------------

const char* ape_error_get_message(const ape_error_t *ape_error) {
    const error_t *error = (const error_t*)ape_error;
    return error->message;
}

const char* ape_error_get_filepath(const ape_error_t *ape_error) {
    const error_t *error = (const error_t*)ape_error;
    if (!error->pos.file) {
        return NULL;
    }
    return error->pos.file->path;
}

const char* ape_error_get_line(const ape_error_t *ape_error) {
    const error_t *error = (const error_t*)ape_error;
    if (!error->pos.file) {
        return NULL;
    }
    ptrarray(char*) *lines = error->pos.file->lines;
    if (error->pos.line >= ptrarray_count(lines)) {
        return NULL;
    }
    const char *line = ptrarray_get(lines, error->pos.line);
    return line;
}

int ape_error_get_line_number(const ape_error_t *ape_error) {
    const error_t *error = (const error_t*)ape_error;
    return error->pos.line + 1;
}

int ape_error_get_column_number(const ape_error_t *ape_error) {
    const error_t *error = (const error_t*)ape_error;
    return error->pos.column + 1;
}

ape_error_type_t ape_error_get_type(const ape_error_t *ape_error) {
    const error_t *error = (const error_t*)ape_error;
    switch (error->type) {
        case ERROR_NONE: return APE_ERROR_NONE;
        case ERROR_PARSING: return APE_ERROR_PARSING;
        case ERROR_COMPILATION: return APE_ERROR_COMPILATION;
        case ERROR_RUNTIME: return APE_ERROR_RUNTIME;
        case ERROR_USER: return APE_ERROR_USER;
        default: return APE_ERROR_NONE;
    }
}

const char* ape_error_get_type_string(const ape_error_t *error) {
    return ape_error_type_to_string(ape_error_get_type(error));
}

const char* ape_error_type_to_string(ape_error_type_t type) {
    switch (type) {
        case APE_ERROR_PARSING: return "PARSING";
        case APE_ERROR_COMPILATION: return "COMPILATION";
        case APE_ERROR_RUNTIME: return "RUNTIME";
        case APE_ERROR_USER: return "USER";
        default: return "NONE";
    }
}

char* ape_error_serialize(const ape_error_t *err) {
    const char *type_str = ape_error_get_type_string(err);
    const char *filename = ape_error_get_filepath(err);
    const char *line = ape_error_get_line(err);
    int line_num = ape_error_get_line_number(err);
    int col_num = ape_error_get_column_number(err);
    strbuf_t *buf = strbuf_make();
    if (line) {
        strbuf_append(buf, line);
        strbuf_append(buf, "\n");
        if (col_num >= 0) {
            for (int j = 0; j < (col_num - 1); j++) {
                strbuf_append(buf, " ");
            }
            strbuf_append(buf, "^\n");
        }
    }
    strbuf_appendf(buf, "%s ERROR in \"%s\" on %d:%d: %s\n", type_str,
           filename, line_num, col_num, ape_error_get_message(err));
    const ape_traceback_t *traceback = ape_error_get_traceback(err);
    if (traceback) {
        strbuf_appendf(buf, "Traceback:\n");
        traceback_to_string((const traceback_t*)ape_error_get_traceback(err), buf);
    }
    return strbuf_get_string_and_destroy(buf);
}

const ape_traceback_t* ape_error_get_traceback(const ape_error_t *ape_error) {
    const error_t *error = (const error_t*)ape_error;
    return (const ape_traceback_t*)error->traceback;
}

//-----------------------------------------------------------------------------
// Ape traceback
//-----------------------------------------------------------------------------

int ape_traceback_get_depth(const ape_traceback_t *ape_traceback) {
    const traceback_t *traceback = (const traceback_t*)ape_traceback;
    return array_count(traceback->items);
}

const char* ape_traceback_get_filepath(const ape_traceback_t *ape_traceback, int depth) {
    const traceback_t *traceback = (const traceback_t*)ape_traceback;
    traceback_item_t *item = array_get(traceback->items, depth);
    if (!item) {
        return NULL;
    }
    return traceback_item_get_filepath(item);
}

const char* ape_traceback_get_line(const ape_traceback_t *ape_traceback, int depth) {
    const traceback_t *traceback = (const traceback_t*)ape_traceback;
    traceback_item_t *item = array_get(traceback->items, depth);
    if (!item) {
        return NULL;
    }
    return traceback_item_get_line(item);
}

int ape_traceback_get_line_number(const ape_traceback_t *ape_traceback, int depth) {
    const traceback_t *traceback = (const traceback_t*)ape_traceback;
    traceback_item_t *item = array_get(traceback->items, depth);
    if (!item) {
        return -1;
    }
    return item->pos.line;
}

int ape_traceback_get_column_number(const ape_traceback_t *ape_traceback, int depth) {
    const traceback_t *traceback = (const traceback_t*)ape_traceback;
    traceback_item_t *item = array_get(traceback->items, depth);
    if (!item) {
        return -1;
    }
    return item->pos.column;
}

const char* ape_traceback_get_function_name(const ape_traceback_t *ape_traceback, int depth) {
    const traceback_t *traceback = (const traceback_t*)ape_traceback;
    traceback_item_t *item = array_get(traceback->items, depth);
    if (!item) {
        return "";
    }
    return item->function_name;
}

//-----------------------------------------------------------------------------
// Ape internal
//-----------------------------------------------------------------------------

static object_t ape_native_fn_wrapper(vm_t *vm, void *data, int argc, object_t *args) {
    native_fn_wrapper_t *wrapper = (native_fn_wrapper_t*)data;
    APE_ASSERT(vm == wrapper->ape->vm);
    ape_object_t res = wrapper->fn(wrapper->ape, wrapper->data, argc, (ape_object_t*)args);
    if (ape_has_errors(wrapper->ape)) {
        return object_make_null();
    }
    return ape_object_to_object(res);
}

static object_t ape_object_to_object(ape_object_t obj) {
    return (object_t){ .handle = obj._internal };
}

static ape_object_t object_to_ape_object(object_t obj) {
    return (ape_object_t){ ._internal = obj.handle };
}

static void reset_state(ape_t *ape) {
    ptrarray_clear_and_destroy_items(ape->errors, error_destroy);
    vm_reset(ape->vm);
}

static void set_default_config(ape_t *ape) {
    memset(&ape->config, 0, sizeof(ape_config_t));
    ape_set_repl_mode(ape, false);
    ape_set_file_read_function(ape, read_file_default, NULL);
    ape_set_file_write_function(ape, write_file_default, NULL);
    ape_set_stdout_write_function(ape, stdout_write_default, NULL);
    ape_set_gc_interval(ape, 10000);
}

static char* read_file_default(void *ctx, const char *filename){
    FILE *fp = fopen(filename, "r");
    size_t size_to_read = 0;
    size_t size_read = 0;
    long pos;
    char *file_contents;
    if (!fp) {
        return NULL;
    }
    fseek(fp, 0L, SEEK_END);
    pos = ftell(fp);
    if (pos < 0) {
        fclose(fp);
        return NULL;
    }
    size_to_read = pos;
    rewind(fp);
    file_contents = (char*)ape_malloc(sizeof(char) * (size_to_read + 1), ape_mallocArg);
    if (!file_contents) {
        fclose(fp);
        return NULL;
    }
    size_read = fread(file_contents, 1, size_to_read, fp);
    if (size_read == 0 || ferror(fp)) {
        fclose(fp);
        free(file_contents);
        return NULL;
    }
    fclose(fp);
    file_contents[size_read] = '\0';
    return file_contents;
}

static size_t write_file_default(void* context, const char *path, const char *string, size_t string_size) {
    FILE *fp = fopen(path, "w");
    if (!fp) {
        return 0;
    }
    size_t written = fwrite(string, 1, string_size, fp);
    fclose(fp);
    return written;
}

static size_t stdout_write_default(void* context, const void *data, size_t size) {
    return fwrite(data, 1, size, stdout);
}
//FILE_END


// The latest version of this library is available on GitHub;
// https://github.com/sheredom/utf8.h

// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <http://unlicense.org/>

#ifndef SHEREDOM_UTF8_H_INCLUDED
#define SHEREDOM_UTF8_H_INCLUDED

#if defined(_MSC_VER)
#pragma warning(push)

/* disable warning: no function prototype given: converting '()' to '(void)' */
#pragma warning(disable : 4255)

/* disable warning: '__cplusplus' is not defined as a preprocessor macro,
 * replacing with '0' for '#if/#elif' */
#pragma warning(disable : 4668)

/* disable warning: bytes padding added after construct */
#pragma warning(disable : 4820)
#endif

#include <stddef.h>
#include <stdlib.h>

#if defined(_MSC_VER)
#pragma warning(pop)
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1920)
typedef __int32 utf8_int32_t;
#else
#include <stdint.h>
typedef int32_t utf8_int32_t;
#endif

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wcast-qual"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
#define utf8_nonnull
#define utf8_pure
#define utf8_restrict __restrict
#define utf8_weak __inline
#elif defined(__clang__) || defined(__GNUC__) || defined(__TINYC__)
#define utf8_nonnull __attribute__((nonnull))
#define utf8_pure __attribute__((pure))
#define utf8_restrict __restrict__
#define utf8_weak __attribute__((weak))
#else
#error Non clang, non gcc, non MSVC, non TinyCC compiler found!
#endif

#ifdef __cplusplus
#define utf8_null NULL
#else
#define utf8_null 0
#endif

// Return less than 0, 0, greater than 0 if src1 < src2, src1 == src2, src1 >
// src2 respectively, case insensitive.
utf8_nonnull utf8_pure utf8_weak int utf8casecmp(const void *src1,
                                                 const void *src2);

// Append the utf8 string src onto the utf8 string dst.
utf8_nonnull utf8_weak void *utf8cat(void *utf8_restrict dst,
                                     const void *utf8_restrict src);

// Find the first match of the utf8 codepoint chr in the utf8 string src.
utf8_nonnull utf8_pure utf8_weak void *utf8chr(const void *src,
                                               utf8_int32_t chr);

// Return less than 0, 0, greater than 0 if src1 < src2,
// src1 == src2, src1 > src2 respectively.
utf8_nonnull utf8_pure utf8_weak int utf8cmp(const void *src1,
                                             const void *src2);

// Copy the utf8 string src onto the memory allocated in dst.
utf8_nonnull utf8_weak void *utf8cpy(void *utf8_restrict dst,
                                     const void *utf8_restrict src);

// Number of utf8 codepoints in the utf8 string src that consists entirely
// of utf8 codepoints not from the utf8 string reject.
utf8_nonnull utf8_pure utf8_weak size_t utf8cspn(const void *src,
                                                 const void *reject);

// Duplicate the utf8 string src by getting its size, malloc'ing a new buffer
// copying over the data, and returning that. Or 0 if malloc failed.
utf8_weak void *utf8dup(const void *src);

// Number of utf8 codepoints in the utf8 string str,
// excluding the null terminating byte.
utf8_nonnull utf8_pure utf8_weak size_t utf8len(const void *str);

// Similar to utf8len, except that only at most n bytes of src are looked.
utf8_nonnull utf8_pure utf8_weak size_t utf8nlen(const void *str, size_t n);

// Return less than 0, 0, greater than 0 if src1 < src2, src1 == src2, src1 >
// src2 respectively, case insensitive. Checking at most n bytes of each utf8
// string.
utf8_nonnull utf8_pure utf8_weak int utf8ncasecmp(const void *src1,
                                                  const void *src2, size_t n);

// Append the utf8 string src onto the utf8 string dst,
// writing at most n+1 bytes. Can produce an invalid utf8
// string if n falls partway through a utf8 codepoint.
utf8_nonnull utf8_weak void *utf8ncat(void *utf8_restrict dst,
                                      const void *utf8_restrict src, size_t n);

// Return less than 0, 0, greater than 0 if src1 < src2,
// src1 == src2, src1 > src2 respectively. Checking at most n
// bytes of each utf8 string.
utf8_nonnull utf8_pure utf8_weak int utf8ncmp(const void *src1,
                                              const void *src2, size_t n);

// Copy the utf8 string src onto the memory allocated in dst.
// Copies at most n bytes. If n falls partway through a utf8
// codepoint, or if dst doesn't have enough room for a null
// terminator, the final string will be cut short to preserve
// utf8 validity.

utf8_nonnull utf8_weak void *utf8ncpy(void *utf8_restrict dst,
                                      const void *utf8_restrict src, size_t n);

// Similar to utf8dup, except that at most n bytes of src are copied. If src is
// longer than n, only n bytes are copied and a null byte is added.
//
// Returns a new string if successful, 0 otherwise
utf8_weak void *utf8ndup(const void *src, size_t n);

// Locates the first occurrence in the utf8 string str of any byte in the
// utf8 string accept, or 0 if no match was found.
utf8_nonnull utf8_pure utf8_weak void *utf8pbrk(const void *str,
                                                const void *accept);

// Find the last match of the utf8 codepoint chr in the utf8 string src.
utf8_nonnull utf8_pure utf8_weak void *utf8rchr(const void *src, int chr);

// Number of bytes in the utf8 string str,
// including the null terminating byte.
utf8_nonnull utf8_pure utf8_weak size_t utf8size(const void *str);

// Similar to utf8size, except that the null terminating byte is excluded.
utf8_nonnull utf8_pure utf8_weak size_t utf8size_lazy(const void *str);

// Similar to utf8size, except that only at most n bytes of src are looked and
// the null terminating byte is excluded.
utf8_nonnull utf8_pure utf8_weak size_t utf8nsize_lazy(const void *str, size_t n);

// Number of utf8 codepoints in the utf8 string src that consists entirely
// of utf8 codepoints from the utf8 string accept.
utf8_nonnull utf8_pure utf8_weak size_t utf8spn(const void *src,
                                                const void *accept);

// The position of the utf8 string needle in the utf8 string haystack.
utf8_nonnull utf8_pure utf8_weak void *utf8str(const void *haystack,
                                               const void *needle);

// The position of the utf8 string needle in the utf8 string haystack, case
// insensitive.
utf8_nonnull utf8_pure utf8_weak void *utf8casestr(const void *haystack,
                                                   const void *needle);

// Return 0 on success, or the position of the invalid
// utf8 codepoint on failure.
utf8_nonnull utf8_pure utf8_weak void *utf8valid(const void *str);

// Similar to utf8valid, except that only at most n bytes of src are looked.
utf8_nonnull utf8_pure utf8_weak void *utf8nvalid(const void *str, size_t n);

// Given a null-terminated string, makes the string valid by replacing invalid
// codepoints with a 1-byte replacement. Returns 0 on success.
utf8_nonnull utf8_weak int utf8makevalid(void *str,
                                         const utf8_int32_t replacement);

// Sets out_codepoint to the current utf8 codepoint in str, and returns the
// address of the next utf8 codepoint after the current one in str.
utf8_nonnull utf8_weak void *
utf8codepoint(const void *utf8_restrict str,
              utf8_int32_t *utf8_restrict out_codepoint);

// Calculates the size of the next utf8 codepoint in str.
utf8_nonnull utf8_weak size_t utf8codepointcalcsize(const void *str);

// Returns the size of the given codepoint in bytes.
utf8_weak size_t utf8codepointsize(utf8_int32_t chr);

// Write a codepoint to the given string, and return the address to the next
// place after the written codepoint. Pass how many bytes left in the buffer to
// n. If there is not enough space for the codepoint, this function returns
// null.
utf8_nonnull utf8_weak void *utf8catcodepoint(void *str, utf8_int32_t chr,
                                              size_t n);

// Returns 1 if the given character is lowercase, or 0 if it is not.
utf8_weak int utf8islower(utf8_int32_t chr);

// Returns 1 if the given character is uppercase, or 0 if it is not.
utf8_weak int utf8isupper(utf8_int32_t chr);

// Transform the given string into all lowercase codepoints.
utf8_nonnull utf8_weak void utf8lwr(void *utf8_restrict str);

// Transform the given string into all uppercase codepoints.
utf8_nonnull utf8_weak void utf8upr(void *utf8_restrict str);

// Make a codepoint lower case if possible.
utf8_weak utf8_int32_t utf8lwrcodepoint(utf8_int32_t cp);

// Make a codepoint upper case if possible.
utf8_weak utf8_int32_t utf8uprcodepoint(utf8_int32_t cp);

// Sets out_codepoint to the current utf8 codepoint in str, and returns the
// address of the previous utf8 codepoint before the current one in str.
utf8_nonnull utf8_weak void *
utf8rcodepoint(const void *utf8_restrict str,
               utf8_int32_t *utf8_restrict out_codepoint);

// Duplicate the utf8 string src by getting its size, calling alloc_func_ptr to
// copy over data to a new buffer, and returning that. Or 0 if alloc_func_ptr
// returned null.
utf8_weak void *utf8dup_ex(const void *src,
                           void *(*alloc_func_ptr)(void *, size_t),
                           void *user_data);

// Similar to utf8dup, except that at most n bytes of src are copied. If src is
// longer than n, only n bytes are copied and a null byte is added.
//
// Returns a new string if successful, 0 otherwise.
utf8_weak void *utf8ndup_ex(const void *src, size_t n,
                            void *(*alloc_func_ptr)(void *, size_t),
                            void *user_data);

#undef utf8_weak
#undef utf8_pure
#undef utf8_nonnull

int utf8casecmp(const void *src1, const void *src2) {
  utf8_int32_t src1_lwr_cp, src2_lwr_cp, src1_upr_cp, src2_upr_cp, src1_orig_cp,
      src2_orig_cp;

  for (;;) {
    src1 = utf8codepoint(src1, &src1_orig_cp);
    src2 = utf8codepoint(src2, &src2_orig_cp);

    // lower the srcs if required
    src1_lwr_cp = utf8lwrcodepoint(src1_orig_cp);
    src2_lwr_cp = utf8lwrcodepoint(src2_orig_cp);

    // lower the srcs if required
    src1_upr_cp = utf8uprcodepoint(src1_orig_cp);
    src2_upr_cp = utf8uprcodepoint(src2_orig_cp);

    // check if the lowered codepoints match
    if ((0 == src1_orig_cp) && (0 == src2_orig_cp)) {
      return 0;
    } else if ((src1_lwr_cp == src2_lwr_cp) || (src1_upr_cp == src2_upr_cp)) {
      continue;
    }

    // if they don't match, then we return the difference between the characters
    return src1_lwr_cp - src2_lwr_cp;
  }
}

void *utf8cat(void *utf8_restrict dst, const void *utf8_restrict src) {
  char *d = (char *)dst;
  const char *s = (const char *)src;

  // find the null terminating byte in dst
  while ('\0' != *d) {
    d++;
  }

  // overwriting the null terminating byte in dst, append src byte-by-byte
  while ('\0' != *s) {
    *d++ = *s++;
  }

  // write out a new null terminating byte into dst
  *d = '\0';

  return dst;
}

void *utf8chr(const void *src, utf8_int32_t chr) {
  char c[5] = {'\0', '\0', '\0', '\0', '\0'};

  if (0 == chr) {
    // being asked to return position of null terminating byte, so
    // just run s to the end, and return!
    const char *s = (const char *)src;
    while ('\0' != *s) {
      s++;
    }
    return (void *)s;
  } else if (0 == ((utf8_int32_t)0xffffff80 & chr)) {
    // 1-byte/7-bit ascii
    // (0b0xxxxxxx)
    c[0] = (char)chr;
  } else if (0 == ((utf8_int32_t)0xfffff800 & chr)) {
    // 2-byte/11-bit utf8 code point
    // (0b110xxxxx 0b10xxxxxx)
    c[0] = (char) (0xc0 | (char)(chr >> 6));
    c[1] = (char) (0x80 | (char)(chr & 0x3f));
  } else if (0 == ((utf8_int32_t)0xffff0000 & chr)) {
    // 3-byte/16-bit utf8 code point
    // (0b1110xxxx 0b10xxxxxx 0b10xxxxxx)
    c[0] = (char) (0xe0 | (char)(chr >> 12));
    c[1] = (char) (0x80 | (char)((chr >> 6) & 0x3f));
    c[2] = (char) (0x80 | (char)(chr & 0x3f));
  } else { // if (0 == ((int)0xffe00000 & chr)) {
    // 4-byte/21-bit utf8 code point
    // (0b11110xxx 0b10xxxxxx 0b10xxxxxx 0b10xxxxxx)
    c[0] = (char) (0xf0 | (char)(chr >> 18));
    c[1] = (char) (0x80 | (char)((chr >> 12) & 0x3f));
    c[2] = (char) (0x80 | (char)((chr >> 6) & 0x3f));
    c[3] = (char) (0x80 | (char)(chr & 0x3f));
  }

  // we've made c into a 2 utf8 codepoint string, one for the chr we are
  // seeking, another for the null terminating byte. Now use utf8str to
  // search
  return utf8str(src, c);
}

int utf8cmp(const void *src1, const void *src2) {
  const unsigned char *s1 = (const unsigned char *)src1;
  const unsigned char *s2 = (const unsigned char *)src2;

  while (('\0' != *s1) || ('\0' != *s2)) {
    if (*s1 < *s2) {
      return -1;
    } else if (*s1 > *s2) {
      return 1;
    }

    s1++;
    s2++;
  }

  // both utf8 strings matched
  return 0;
}

int utf8coll(const void *src1, const void *src2);

void *utf8cpy(void *utf8_restrict dst, const void *utf8_restrict src) {
  char *d = (char *)dst;
  const char *s = (const char *)src;

  // overwriting anything previously in dst, write byte-by-byte
  // from src
  while ('\0' != *s) {
    *d++ = *s++;
  }

  // append null terminating byte
  *d = '\0';

  return dst;
}

size_t utf8cspn(const void *src, const void *reject) {
  const char *s = (const char *)src;
  size_t chars = 0;

  while ('\0' != *s) {
    const char *r = (const char *)reject;
    size_t offset = 0;

    while ('\0' != *r) {
      // checking that if *r is the start of a utf8 codepoint
      // (it is not 0b10xxxxxx) and we have successfully matched
      // a previous character (0 < offset) - we found a match
      if ((0x80 != (0xc0 & *r)) && (0 < offset)) {
        return chars;
      } else {
        if (*r == s[offset]) {
          // part of a utf8 codepoint matched, so move our checking
          // onwards to the next byte
          offset++;
          r++;
        } else {
          // r could be in the middle of an unmatching utf8 code point,
          // so we need to march it on to the next character beginning,

          do {
            r++;
          } while (0x80 == (0xc0 & *r));

          // reset offset too as we found a mismatch
          offset = 0;
        }
      }
    }

    // found a match at the end of *r, so didn't get a chance to test it
    if (0 < offset) {
      return chars;
    }

    // the current utf8 codepoint in src did not match reject, but src
    // could have been partway through a utf8 codepoint, so we need to
    // march it onto the next utf8 codepoint starting byte
    do {
      s++;
    } while ((0x80 == (0xc0 & *s)));
    chars++;
  }

  return chars;
}

void *utf8dup(const void *src) { return utf8dup_ex(src, utf8_null, utf8_null); }

void *utf8dup_ex(const void *src, void *(*alloc_func_ptr)(void *, size_t),
                 void *user_data) {
  const char *s = (const char *)src;
  char *n = utf8_null;

  // figure out how many bytes (including the terminator) we need to copy first
  size_t bytes = utf8size(src);

  if (alloc_func_ptr) {
    n = (char *)alloc_func_ptr(user_data, bytes);
  } else {
    n = (char *)malloc(bytes);
  }

  if (utf8_null == n) {
    // out of memory so we bail
    return utf8_null;
  } else {
    bytes = 0;

    // copy src byte-by-byte into our new utf8 string
    while ('\0' != s[bytes]) {
      n[bytes] = s[bytes];
      bytes++;
    }

    // append null terminating byte
    n[bytes] = '\0';
    return n;
  }
}

void *utf8fry(const void *str);

size_t utf8len(const void *str) {
  return utf8nlen(str, SIZE_MAX);
}

size_t utf8nlen(const void *str, size_t n) {
  const unsigned char *s = (const unsigned char *)str;
  const unsigned char *t = s;
  size_t length = 0;

  while ((size_t) (s-t) < n && '\0' != *s) {
    if (0xf0 == (0xf8 & *s)) {
      // 4-byte utf8 code point (began with 0b11110xxx)
      s += 4;
    } else if (0xe0 == (0xf0 & *s)) {
      // 3-byte utf8 code point (began with 0b1110xxxx)
      s += 3;
    } else if (0xc0 == (0xe0 & *s)) {
      // 2-byte utf8 code point (began with 0b110xxxxx)
      s += 2;
    } else { // if (0x00 == (0x80 & *s)) {
      // 1-byte ascii (began with 0b0xxxxxxx)
      s += 1;
    }

    // no matter the bytes we marched s forward by, it was
    // only 1 utf8 codepoint
    length++;
  }

  if ((size_t) (s-t) > n) {
    length--;
  }
  return length;
}

int utf8ncasecmp(const void *src1, const void *src2, size_t n) {
  utf8_int32_t src1_lwr_cp, src2_lwr_cp, src1_upr_cp, src2_upr_cp, src1_orig_cp,
      src2_orig_cp;

  do {
    const unsigned char *const s1 = (const unsigned char *)src1;
    const unsigned char *const s2 = (const unsigned char *)src2;

    // first check that we have enough bytes left in n to contain an entire
    // codepoint
    if (0 == n) {
      return 0;
    }

    if ((1 == n) && ((0xc0 == (0xe0 & *s1)) || (0xc0 == (0xe0 & *s2)))) {
      const utf8_int32_t c1 = (0xe0 & *s1);
      const utf8_int32_t c2 = (0xe0 & *s2);

      if (c1 < c2) {
        return c1 - c2;
      } else {
        return 0;
      }
    }

    if ((2 >= n) && ((0xe0 == (0xf0 & *s1)) || (0xe0 == (0xf0 & *s2)))) {
      const utf8_int32_t c1 = (0xf0 & *s1);
      const utf8_int32_t c2 = (0xf0 & *s2);

      if (c1 < c2) {
        return c1 - c2;
      } else {
        return 0;
      }
    }

    if ((3 >= n) && ((0xf0 == (0xf8 & *s1)) || (0xf0 == (0xf8 & *s2)))) {
      const utf8_int32_t c1 = (0xf8 & *s1);
      const utf8_int32_t c2 = (0xf8 & *s2);

      if (c1 < c2) {
        return c1 - c2;
      } else {
        return 0;
      }
    }

    src1 = utf8codepoint(src1, &src1_orig_cp);
    src2 = utf8codepoint(src2, &src2_orig_cp);
    n -= utf8codepointsize(src1_orig_cp);

    src1_lwr_cp = utf8lwrcodepoint(src1_orig_cp);
    src2_lwr_cp = utf8lwrcodepoint(src2_orig_cp);

    src1_upr_cp = utf8uprcodepoint(src1_orig_cp);
    src2_upr_cp = utf8uprcodepoint(src2_orig_cp);

    // check if the lowered codepoints match
    if ((0 == src1_orig_cp) && (0 == src2_orig_cp)) {
      return 0;
    } else if ((src1_lwr_cp == src2_lwr_cp) || (src1_upr_cp == src2_upr_cp)) {
      continue;
    }

    // if they don't match, then we return the difference between the characters
    return src1_lwr_cp - src2_lwr_cp;
  } while (0 < n);

  // both utf8 strings matched
  return 0;
}

void *utf8ncat(void *utf8_restrict dst, const void *utf8_restrict src,
               size_t n) {
  char *d = (char *)dst;
  const char *s = (const char *)src;

  // find the null terminating byte in dst
  while ('\0' != *d) {
    d++;
  }

  // overwriting the null terminating byte in dst, append src byte-by-byte
  // stopping if we run out of space
  do {
    *d++ = *s++;
  } while (('\0' != *s) && (0 != --n));

  // write out a new null terminating byte into dst
  *d = '\0';

  return dst;
}

int utf8ncmp(const void *src1, const void *src2, size_t n) {
  const unsigned char *s1 = (const unsigned char *)src1;
  const unsigned char *s2 = (const unsigned char *)src2;

  while ((0 != n--) && (('\0' != *s1) || ('\0' != *s2))) {
    if (*s1 < *s2) {
      return -1;
    } else if (*s1 > *s2) {
      return 1;
    }

    s1++;
    s2++;
  }

  // both utf8 strings matched
  return 0;
}

void *utf8ncpy(void *utf8_restrict dst, const void *utf8_restrict src,
               size_t n) {
  char *d = (char *)dst;
  const char *s = (const char *)src;
  size_t index, check_index;

  if (n == 0) {
    return dst;
  }

  // overwriting anything previously in dst, write byte-by-byte
  // from src
  for (index = 0; index < n; index++) {
    d[index] = s[index];
    if ('\0' == s[index]) {
      break;
    }
  }

  for ( check_index = index - 1; check_index > 0 && 0x80 == (0xc0 & d[check_index]); check_index--) {
    // just moving the index
  }

  if (check_index < index && (index - check_index) < utf8codepointsize(d[check_index])) {
    index = check_index;
  }

  // append null terminating byte
  for (; index < n; index++) {
    d[index] = 0;
  }

  return dst;
}

void *utf8ndup(const void *src, size_t n) {
  return utf8ndup_ex(src, n, utf8_null, utf8_null);
}

void *utf8ndup_ex(const void *src, size_t n,
                  void *(*alloc_func_ptr)(void *, size_t), void *user_data) {
  const char *s = (const char *)src;
  char *c = utf8_null;
  size_t bytes = 0;

  // Find the end of the string or stop when n is reached
  while ('\0' != s[bytes] && bytes < n) {
    bytes++;
  }

  // In case bytes is actually less than n, we need to set it
  // to be used later in the copy byte by byte.
  n = bytes;

  if (alloc_func_ptr) {
    c = (char *)alloc_func_ptr(user_data, bytes + 1);
  } else {
    c = (char *)malloc(bytes + 1);
  }

  if (utf8_null == c) {
    // out of memory so we bail
    return utf8_null;
  }

  bytes = 0;

  // copy src byte-by-byte into our new utf8 string
  while ('\0' != s[bytes] && bytes < n) {
    c[bytes] = s[bytes];
    bytes++;
  }

  // append null terminating byte
  c[bytes] = '\0';
  return c;
}

void *utf8rchr(const void *src, int chr) {
  const char *s = (const char *)src;
  const char *match = utf8_null;
  char c[5] = {'\0', '\0', '\0', '\0', '\0'};

  if (0 == chr) {
    // being asked to return position of null terminating byte, so
    // just run s to the end, and return!
    while ('\0' != *s) {
      s++;
    }
    return (void *)s;
  } else if (0 == ((int)0xffffff80 & chr)) {
    // 1-byte/7-bit ascii
    // (0b0xxxxxxx)
    c[0] = (char)chr;
  } else if (0 == ((int)0xfffff800 & chr)) {
    // 2-byte/11-bit utf8 code point
    // (0b110xxxxx 0b10xxxxxx)
    c[0] = (char) (0xc0 | (char)(chr >> 6));
    c[1] = (char) (0x80 | (char)(chr & 0x3f));
  } else if (0 == ((int)0xffff0000 & chr)) {
    // 3-byte/16-bit utf8 code point
    // (0b1110xxxx 0b10xxxxxx 0b10xxxxxx)
    c[0] = (char) (0xe0 | (char)(chr >> 12));
    c[1] = (char) (0x80 | (char)((chr >> 6) & 0x3f));
    c[2] = (char) (0x80 | (char)(chr & 0x3f));
  } else { // if (0 == ((int)0xffe00000 & chr)) {
    // 4-byte/21-bit utf8 code point
    // (0b11110xxx 0b10xxxxxx 0b10xxxxxx 0b10xxxxxx)
    c[0] = (char) (0xf0 | (char)(chr >> 18));
    c[1] = (char) (0x80 | (char)((chr >> 12) & 0x3f));
    c[2] = (char) (0x80 | (char)((chr >> 6) & 0x3f));
    c[3] = (char) (0x80 | (char)(chr & 0x3f));
  }

  // we've created a 2 utf8 codepoint string in c that is
  // the utf8 character asked for by chr, and a null
  // terminating byte

  while ('\0' != *s) {
    size_t offset = 0;

    while (s[offset] == c[offset]) {
      offset++;
    }

    if ('\0' == c[offset]) {
      // we found a matching utf8 code point
      match = s;
      s += offset;
    } else {
      s += offset;

      // need to march s along to next utf8 codepoint start
      // (the next byte that doesn't match 0b10xxxxxx)
      if ('\0' != *s) {
        do {
          s++;
        } while (0x80 == (0xc0 & *s));
      }
    }
  }

  // return the last match we found (or 0 if no match was found)
  return (void *)match;
}

void *utf8pbrk(const void *str, const void *accept) {
  const char *s = (const char *)str;

  while ('\0' != *s) {
    const char *a = (const char *)accept;
    size_t offset = 0;

    while ('\0' != *a) {
      // checking that if *a is the start of a utf8 codepoint
      // (it is not 0b10xxxxxx) and we have successfully matched
      // a previous character (0 < offset) - we found a match
      if ((0x80 != (0xc0 & *a)) && (0 < offset)) {
        return (void *)s;
      } else {
        if (*a == s[offset]) {
          // part of a utf8 codepoint matched, so move our checking
          // onwards to the next byte
          offset++;
          a++;
        } else {
          // r could be in the middle of an unmatching utf8 code point,
          // so we need to march it on to the next character beginning,

          do {
            a++;
          } while (0x80 == (0xc0 & *a));

          // reset offset too as we found a mismatch
          offset = 0;
        }
      }
    }

    // we found a match on the last utf8 codepoint
    if (0 < offset) {
      return (void *)s;
    }

    // the current utf8 codepoint in src did not match accept, but src
    // could have been partway through a utf8 codepoint, so we need to
    // march it onto the next utf8 codepoint starting byte
    do {
      s++;
    } while ((0x80 == (0xc0 & *s)));
  }

  return utf8_null;
}

size_t utf8size(const void *str) {
  return utf8size_lazy(str) + 1;
}

size_t utf8size_lazy(const void *str) {
  return utf8nsize_lazy(str, SIZE_MAX);
}

size_t utf8nsize_lazy(const void *str, size_t n) {
  const char *s = (const char *)str;
  size_t size = 0;
  while (size < n && '\0' != s[size]) {
    size++;
  }
  return size;
}

size_t utf8spn(const void *src, const void *accept) {
  const char *s = (const char *)src;
  size_t chars = 0;

  while ('\0' != *s) {
    const char *a = (const char *)accept;
    size_t offset = 0;

    while ('\0' != *a) {
      // checking that if *r is the start of a utf8 codepoint
      // (it is not 0b10xxxxxx) and we have successfully matched
      // a previous character (0 < offset) - we found a match
      if ((0x80 != (0xc0 & *a)) && (0 < offset)) {
        // found a match, so increment the number of utf8 codepoints
        // that have matched and stop checking whether any other utf8
        // codepoints in a match
        chars++;
        s += offset;
        offset = 0;
        break;
      } else {
        if (*a == s[offset]) {
          offset++;
          a++;
        } else {
          // a could be in the middle of an unmatching utf8 codepoint,
          // so we need to march it on to the next character beginning,
          do {
            a++;
          } while (0x80 == (0xc0 & *a));

          // reset offset too as we found a mismatch
          offset = 0;
        }
      }
    }

    // found a match at the end of *a, so didn't get a chance to test it
    if (0 < offset) {
      chars++;
      s += offset;
      continue;
    }

    // if a got to its terminating null byte, then we didn't find a match.
    // Return the current number of matched utf8 codepoints
    if ('\0' == *a) {
      return chars;
    }
  }

  return chars;
}

void *utf8str(const void *haystack, const void *needle) {
  const char *h = (const char *)haystack;
  utf8_int32_t throwaway_codepoint;

  // if needle has no utf8 codepoints before the null terminating
  // byte then return haystack
  if ('\0' == *((const char *)needle)) {
    return (void *)haystack;
  }

  while ('\0' != *h) {
    const char *maybeMatch = h;
    const char *n = (const char *)needle;

    while (*h == *n && (*h != '\0' && *n != '\0')) {
      n++;
      h++;
    }

    if ('\0' == *n) {
      // we found the whole utf8 string for needle in haystack at
      // maybeMatch, so return it
      return (void *)maybeMatch;
    } else {
      // h could be in the middle of an unmatching utf8 codepoint,
      // so we need to march it on to the next character beginning
      // starting from the current character
      h = (const char *)utf8codepoint(maybeMatch, &throwaway_codepoint);
    }
  }

  // no match
  return utf8_null;
}

void *utf8casestr(const void *haystack, const void *needle) {
  const void *h = haystack;

  // if needle has no utf8 codepoints before the null terminating
  // byte then return haystack
  if ('\0' == *((const char *)needle)) {
    return (void *)haystack;
  }

  for (;;) {
    const void *maybeMatch = h;
    const void *n = needle;
    utf8_int32_t h_cp, n_cp;

    // Get the next code point and track it
    const void *nextH = h = utf8codepoint(h, &h_cp);
    n = utf8codepoint(n, &n_cp);

    while ((0 != h_cp) && (0 != n_cp)) {
      h_cp = utf8lwrcodepoint(h_cp);
      n_cp = utf8lwrcodepoint(n_cp);

      // if we find a mismatch, bail out!
      if (h_cp != n_cp) {
        break;
      }

      h = utf8codepoint(h, &h_cp);
      n = utf8codepoint(n, &n_cp);
    }

    if (0 == n_cp) {
      // we found the whole utf8 string for needle in haystack at
      // maybeMatch, so return it
      return (void *)maybeMatch;
    }

    if (0 == h_cp) {
      // no match
      return utf8_null;
    }

    // Roll back to the next code point in the haystack to test
    h = nextH;
  }
}

void *utf8valid(const void *str) {
  return utf8nvalid(str, SIZE_MAX);
}

void *utf8nvalid(const void *str, size_t n) {
  const char *s = (const char *)str;
  const char *t = s;
  size_t consumed, remained;

  while ((void) (consumed = (size_t) (s-t)), consumed < n && '\0' != *s) {
    remained = n - consumed;

    if (0xf0 == (0xf8 & *s)) {
      // ensure that there's 4 bytes or more remained
      if (remained < 4) {
        return (void *)s;
      }

      // ensure each of the 3 following bytes in this 4-byte
      // utf8 codepoint began with 0b10xxxxxx
      if ((0x80 != (0xc0 & s[1])) || (0x80 != (0xc0 & s[2])) ||
          (0x80 != (0xc0 & s[3]))) {
        return (void *)s;
      }

      // ensure that our utf8 codepoint ended after 4 bytes
      if (0x80 == (0xc0 & s[4])) {
        return (void *)s;
      }

      // ensure that the top 5 bits of this 4-byte utf8
      // codepoint were not 0, as then we could have used
      // one of the smaller encodings
      if ((0 == (0x07 & s[0])) && (0 == (0x30 & s[1]))) {
        return (void *)s;
      }

      // 4-byte utf8 code point (began with 0b11110xxx)
      s += 4;
    } else if (0xe0 == (0xf0 & *s)) {
      // ensure that there's 3 bytes or more remained
      if (remained < 3) {
        return (void *)s;
      }

      // ensure each of the 2 following bytes in this 3-byte
      // utf8 codepoint began with 0b10xxxxxx
      if ((0x80 != (0xc0 & s[1])) || (0x80 != (0xc0 & s[2]))) {
        return (void *)s;
      }

      // ensure that our utf8 codepoint ended after 3 bytes
      if (0x80 == (0xc0 & s[3])) {
        return (void *)s;
      }

      // ensure that the top 5 bits of this 3-byte utf8
      // codepoint were not 0, as then we could have used
      // one of the smaller encodings
      if ((0 == (0x0f & s[0])) && (0 == (0x20 & s[1]))) {
        return (void *)s;
      }

      // 3-byte utf8 code point (began with 0b1110xxxx)
      s += 3;
    } else if (0xc0 == (0xe0 & *s)) {
      // ensure that there's 2 bytes or more remained
      if (remained < 2) {
        return (void *)s;
      }

      // ensure the 1 following byte in this 2-byte
      // utf8 codepoint began with 0b10xxxxxx
      if (0x80 != (0xc0 & s[1])) {
        return (void *)s;
      }

      // ensure that our utf8 codepoint ended after 2 bytes
      if (0x80 == (0xc0 & s[2])) {
        return (void *)s;
      }

      // ensure that the top 4 bits of this 2-byte utf8
      // codepoint were not 0, as then we could have used
      // one of the smaller encodings
      if (0 == (0x1e & s[0])) {
        return (void *)s;
      }

      // 2-byte utf8 code point (began with 0b110xxxxx)
      s += 2;
    } else if (0x00 == (0x80 & *s)) {
      // 1-byte ascii (began with 0b0xxxxxxx)
      s += 1;
    } else {
      // we have an invalid 0b1xxxxxxx utf8 code point entry
      return (void *)s;
    }
  }

  return utf8_null;
}

int utf8makevalid(void *str, const utf8_int32_t replacement) {
  char *read = (char *)str;
  char *write = read;
  const char r = (char)replacement;
  utf8_int32_t codepoint;

  if (replacement > 0x7f) {
    return -1;
  }

  while ('\0' != *read) {
    if (0xf0 == (0xf8 & *read)) {
      // ensure each of the 3 following bytes in this 4-byte
      // utf8 codepoint began with 0b10xxxxxx
      if ((0x80 != (0xc0 & read[1])) || (0x80 != (0xc0 & read[2])) ||
          (0x80 != (0xc0 & read[3]))) {
        *write++ = r;
        read++;
        continue;
      }

      // 4-byte utf8 code point (began with 0b11110xxx)
      read = (char *)utf8codepoint(read, &codepoint);
      write = (char *)utf8catcodepoint(write, codepoint, 4);
    } else if (0xe0 == (0xf0 & *read)) {
      // ensure each of the 2 following bytes in this 3-byte
      // utf8 codepoint began with 0b10xxxxxx
      if ((0x80 != (0xc0 & read[1])) || (0x80 != (0xc0 & read[2]))) {
        *write++ = r;
        read++;
        continue;
      }

      // 3-byte utf8 code point (began with 0b1110xxxx)
      read = (char *)utf8codepoint(read, &codepoint);
      write = (char *)utf8catcodepoint(write, codepoint, 3);
    } else if (0xc0 == (0xe0 & *read)) {
      // ensure the 1 following byte in this 2-byte
      // utf8 codepoint began with 0b10xxxxxx
      if (0x80 != (0xc0 & read[1])) {
        *write++ = r;
        read++;
        continue;
      }

      // 2-byte utf8 code point (began with 0b110xxxxx)
      read = (char *)utf8codepoint(read, &codepoint);
      write = (char *)utf8catcodepoint(write, codepoint, 2);
    } else if (0x00 == (0x80 & *read)) {
      // 1-byte ascii (began with 0b0xxxxxxx)
      read = (char *)utf8codepoint(read, &codepoint);
      write = (char *)utf8catcodepoint(write, codepoint, 1);
    } else {
      // if we got here then we've got a dangling continuation (0b10xxxxxx)
      *write++ = r;
      read++;
      continue;
    }
  }

  *write = '\0';

  return 0;
}

void *utf8codepoint(const void *utf8_restrict str,
                    utf8_int32_t *utf8_restrict out_codepoint) {
  const char *s = (const char *)str;

  if (0xf0 == (0xf8 & s[0])) {
    // 4 byte utf8 codepoint
    *out_codepoint = ((0x07 & s[0]) << 18) | ((0x3f & s[1]) << 12) |
                     ((0x3f & s[2]) << 6) | (0x3f & s[3]);
    s += 4;
  } else if (0xe0 == (0xf0 & s[0])) {
    // 3 byte utf8 codepoint
    *out_codepoint =
        ((0x0f & s[0]) << 12) | ((0x3f & s[1]) << 6) | (0x3f & s[2]);
    s += 3;
  } else if (0xc0 == (0xe0 & s[0])) {
    // 2 byte utf8 codepoint
    *out_codepoint = ((0x1f & s[0]) << 6) | (0x3f & s[1]);
    s += 2;
  } else {
    // 1 byte utf8 codepoint otherwise
    *out_codepoint = s[0];
    s += 1;
  }

  return (void *)s;
}

size_t utf8codepointcalcsize(const void *str) {
  const char *s = (const char *)str;

  if (0xf0 == (0xf8 & s[0])) {
    // 4 byte utf8 codepoint
    return 4;
  } else if (0xe0 == (0xf0 & s[0])) {
    // 3 byte utf8 codepoint
    return 3;
  } else if (0xc0 == (0xe0 & s[0])) {
    // 2 byte utf8 codepoint
    return 2;
  }

  // 1 byte utf8 codepoint otherwise
  return 1;
}

size_t utf8codepointsize(utf8_int32_t chr) {
  if (0 == ((utf8_int32_t)0xffffff80 & chr)) {
    return 1;
  } else if (0 == ((utf8_int32_t)0xfffff800 & chr)) {
    return 2;
  } else if (0 == ((utf8_int32_t)0xffff0000 & chr)) {
    return 3;
  } else { // if (0 == ((int)0xffe00000 & chr)) {
    return 4;
  }
}

void *utf8catcodepoint(void *str, utf8_int32_t chr, size_t n) {
  char *s = (char *)str;

  if (0 == ((utf8_int32_t)0xffffff80 & chr)) {
    // 1-byte/7-bit ascii
    // (0b0xxxxxxx)
    if (n < 1) {
      return utf8_null;
    }
    s[0] = (char)chr;
    s += 1;
  } else if (0 == ((utf8_int32_t)0xfffff800 & chr)) {
    // 2-byte/11-bit utf8 code point
    // (0b110xxxxx 0b10xxxxxx)
    if (n < 2) {
      return utf8_null;
    }
    s[0] = (char) (0xc0 | (char)((chr >> 6) & 0x1f));
    s[1] = (char) (0x80 | (char)(chr & 0x3f));
    s += 2;
  } else if (0 == ((utf8_int32_t)0xffff0000 & chr)) {
    // 3-byte/16-bit utf8 code point
    // (0b1110xxxx 0b10xxxxxx 0b10xxxxxx)
    if (n < 3) {
      return utf8_null;
    }
    s[0] = (char) (0xe0 | (char)((chr >> 12) & 0x0f));
    s[1] = (char) (0x80 | (char)((chr >> 6) & 0x3f));
    s[2] = (char) (0x80 | (char)(chr & 0x3f));
    s += 3;
  } else { // if (0 == ((int)0xffe00000 & chr)) {
    // 4-byte/21-bit utf8 code point
    // (0b11110xxx 0b10xxxxxx 0b10xxxxxx 0b10xxxxxx)
    if (n < 4) {
      return utf8_null;
    }
    s[0] = (char) (0xf0 | (char)((chr >> 18) & 0x07));
    s[1] = (char) (0x80 | (char)((chr >> 12) & 0x3f));
    s[2] = (char) (0x80 | (char)((chr >> 6) & 0x3f));
    s[3] = (char) (0x80 | (char)(chr & 0x3f));
    s += 4;
  }

  return s;
}

int utf8islower(utf8_int32_t chr) { return chr != utf8uprcodepoint(chr); }

int utf8isupper(utf8_int32_t chr) { return chr != utf8lwrcodepoint(chr); }

void utf8lwr(void *utf8_restrict str) {
  void *p, *pn;
  utf8_int32_t cp;

  p = (char *)str;
  pn = utf8codepoint(p, &cp);

  while (cp != 0) {
    const utf8_int32_t lwr_cp = utf8lwrcodepoint(cp);
    const size_t size = utf8codepointsize(lwr_cp);

    if (lwr_cp != cp) {
      utf8catcodepoint(p, lwr_cp, size);
    }

    p = pn;
    pn = utf8codepoint(p, &cp);
  }
}

void utf8upr(void *utf8_restrict str) {
  void *p, *pn;
  utf8_int32_t cp;

  p = (char *)str;
  pn = utf8codepoint(p, &cp);

  while (cp != 0) {
    const utf8_int32_t lwr_cp = utf8uprcodepoint(cp);
    const size_t size = utf8codepointsize(lwr_cp);

    if (lwr_cp != cp) {
      utf8catcodepoint(p, lwr_cp, size);
    }

    p = pn;
    pn = utf8codepoint(p, &cp);
  }
}

utf8_int32_t utf8lwrcodepoint(utf8_int32_t cp) {
  if (((0x0041 <= cp) && (0x005a >= cp)) ||
      ((0x00c0 <= cp) && (0x00d6 >= cp)) ||
      ((0x00d8 <= cp) && (0x00de >= cp)) ||
      ((0x0391 <= cp) && (0x03a1 >= cp)) ||
      ((0x03a3 <= cp) && (0x03ab >= cp)) ||
      ((0x0410 <= cp) && (0x042f >= cp))) {
    cp += 32;
  } else if ((0x0400 <= cp) && (0x040f >= cp)) {
    cp += 80;
  } else if (((0x0100 <= cp) && (0x012f >= cp)) ||
             ((0x0132 <= cp) && (0x0137 >= cp)) ||
             ((0x014a <= cp) && (0x0177 >= cp)) ||
             ((0x0182 <= cp) && (0x0185 >= cp)) ||
             ((0x01a0 <= cp) && (0x01a5 >= cp)) ||
             ((0x01de <= cp) && (0x01ef >= cp)) ||
             ((0x01f8 <= cp) && (0x021f >= cp)) ||
             ((0x0222 <= cp) && (0x0233 >= cp)) ||
             ((0x0246 <= cp) && (0x024f >= cp)) ||
             ((0x03d8 <= cp) && (0x03ef >= cp)) ||
             ((0x0460 <= cp) && (0x0481 >= cp)) ||
             ((0x048a <= cp) && (0x04ff >= cp))) {
    cp |= 0x1;
  } else if (((0x0139 <= cp) && (0x0148 >= cp)) ||
             ((0x0179 <= cp) && (0x017e >= cp)) ||
             ((0x01af <= cp) && (0x01b0 >= cp)) ||
             ((0x01b3 <= cp) && (0x01b6 >= cp)) ||
             ((0x01cd <= cp) && (0x01dc >= cp))) {
    cp += 1;
    cp &= ~0x1;
  } else {
    switch (cp) {
    default:
      break;
    case 0x0178:
      cp = 0x00ff;
      break;
    case 0x0243:
      cp = 0x0180;
      break;
    case 0x018e:
      cp = 0x01dd;
      break;
    case 0x023d:
      cp = 0x019a;
      break;
    case 0x0220:
      cp = 0x019e;
      break;
    case 0x01b7:
      cp = 0x0292;
      break;
    case 0x01c4:
      cp = 0x01c6;
      break;
    case 0x01c7:
      cp = 0x01c9;
      break;
    case 0x01ca:
      cp = 0x01cc;
      break;
    case 0x01f1:
      cp = 0x01f3;
      break;
    case 0x01f7:
      cp = 0x01bf;
      break;
    case 0x0187:
      cp = 0x0188;
      break;
    case 0x018b:
      cp = 0x018c;
      break;
    case 0x0191:
      cp = 0x0192;
      break;
    case 0x0198:
      cp = 0x0199;
      break;
    case 0x01a7:
      cp = 0x01a8;
      break;
    case 0x01ac:
      cp = 0x01ad;
      break;
    case 0x01af:
      cp = 0x01b0;
      break;
    case 0x01b8:
      cp = 0x01b9;
      break;
    case 0x01bc:
      cp = 0x01bd;
      break;
    case 0x01f4:
      cp = 0x01f5;
      break;
    case 0x023b:
      cp = 0x023c;
      break;
    case 0x0241:
      cp = 0x0242;
      break;
    case 0x03fd:
      cp = 0x037b;
      break;
    case 0x03fe:
      cp = 0x037c;
      break;
    case 0x03ff:
      cp = 0x037d;
      break;
    case 0x037f:
      cp = 0x03f3;
      break;
    case 0x0386:
      cp = 0x03ac;
      break;
    case 0x0388:
      cp = 0x03ad;
      break;
    case 0x0389:
      cp = 0x03ae;
      break;
    case 0x038a:
      cp = 0x03af;
      break;
    case 0x038c:
      cp = 0x03cc;
      break;
    case 0x038e:
      cp = 0x03cd;
      break;
    case 0x038f:
      cp = 0x03ce;
      break;
    case 0x0370:
      cp = 0x0371;
      break;
    case 0x0372:
      cp = 0x0373;
      break;
    case 0x0376:
      cp = 0x0377;
      break;
    case 0x03f4:
      cp = 0x03b8;
      break;
    case 0x03cf:
      cp = 0x03d7;
      break;
    case 0x03f9:
      cp = 0x03f2;
      break;
    case 0x03f7:
      cp = 0x03f8;
      break;
    case 0x03fa:
      cp = 0x03fb;
      break;
    }
  }

  return cp;
}

utf8_int32_t utf8uprcodepoint(utf8_int32_t cp) {
  if (((0x0061 <= cp) && (0x007a >= cp)) ||
      ((0x00e0 <= cp) && (0x00f6 >= cp)) ||
      ((0x00f8 <= cp) && (0x00fe >= cp)) ||
      ((0x03b1 <= cp) && (0x03c1 >= cp)) ||
      ((0x03c3 <= cp) && (0x03cb >= cp)) ||
      ((0x0430 <= cp) && (0x044f >= cp))) {
    cp -= 32;
  } else if ((0x0450 <= cp) && (0x045f >= cp)) {
    cp -= 80;
  } else if (((0x0100 <= cp) && (0x012f >= cp)) ||
             ((0x0132 <= cp) && (0x0137 >= cp)) ||
             ((0x014a <= cp) && (0x0177 >= cp)) ||
             ((0x0182 <= cp) && (0x0185 >= cp)) ||
             ((0x01a0 <= cp) && (0x01a5 >= cp)) ||
             ((0x01de <= cp) && (0x01ef >= cp)) ||
             ((0x01f8 <= cp) && (0x021f >= cp)) ||
             ((0x0222 <= cp) && (0x0233 >= cp)) ||
             ((0x0246 <= cp) && (0x024f >= cp)) ||
             ((0x03d8 <= cp) && (0x03ef >= cp)) ||
             ((0x0460 <= cp) && (0x0481 >= cp)) ||
             ((0x048a <= cp) && (0x04ff >= cp))) {
    cp &= ~0x1;
  } else if (((0x0139 <= cp) && (0x0148 >= cp)) ||
             ((0x0179 <= cp) && (0x017e >= cp)) ||
             ((0x01af <= cp) && (0x01b0 >= cp)) ||
             ((0x01b3 <= cp) && (0x01b6 >= cp)) ||
             ((0x01cd <= cp) && (0x01dc >= cp))) {
    cp -= 1;
    cp |= 0x1;
  } else {
    switch (cp) {
    default:
      break;
    case 0x00ff:
      cp = 0x0178;
      break;
    case 0x0180:
      cp = 0x0243;
      break;
    case 0x01dd:
      cp = 0x018e;
      break;
    case 0x019a:
      cp = 0x023d;
      break;
    case 0x019e:
      cp = 0x0220;
      break;
    case 0x0292:
      cp = 0x01b7;
      break;
    case 0x01c6:
      cp = 0x01c4;
      break;
    case 0x01c9:
      cp = 0x01c7;
      break;
    case 0x01cc:
      cp = 0x01ca;
      break;
    case 0x01f3:
      cp = 0x01f1;
      break;
    case 0x01bf:
      cp = 0x01f7;
      break;
    case 0x0188:
      cp = 0x0187;
      break;
    case 0x018c:
      cp = 0x018b;
      break;
    case 0x0192:
      cp = 0x0191;
      break;
    case 0x0199:
      cp = 0x0198;
      break;
    case 0x01a8:
      cp = 0x01a7;
      break;
    case 0x01ad:
      cp = 0x01ac;
      break;
    case 0x01b0:
      cp = 0x01af;
      break;
    case 0x01b9:
      cp = 0x01b8;
      break;
    case 0x01bd:
      cp = 0x01bc;
      break;
    case 0x01f5:
      cp = 0x01f4;
      break;
    case 0x023c:
      cp = 0x023b;
      break;
    case 0x0242:
      cp = 0x0241;
      break;
    case 0x037b:
      cp = 0x03fd;
      break;
    case 0x037c:
      cp = 0x03fe;
      break;
    case 0x037d:
      cp = 0x03ff;
      break;
    case 0x03f3:
      cp = 0x037f;
      break;
    case 0x03ac:
      cp = 0x0386;
      break;
    case 0x03ad:
      cp = 0x0388;
      break;
    case 0x03ae:
      cp = 0x0389;
      break;
    case 0x03af:
      cp = 0x038a;
      break;
    case 0x03cc:
      cp = 0x038c;
      break;
    case 0x03cd:
      cp = 0x038e;
      break;
    case 0x03ce:
      cp = 0x038f;
      break;
    case 0x0371:
      cp = 0x0370;
      break;
    case 0x0373:
      cp = 0x0372;
      break;
    case 0x0377:
      cp = 0x0376;
      break;
    case 0x03d1:
      cp = 0x0398;
      break;
    case 0x03d7:
      cp = 0x03cf;
      break;
    case 0x03f2:
      cp = 0x03f9;
      break;
    case 0x03f8:
      cp = 0x03f7;
      break;
    case 0x03fb:
      cp = 0x03fa;
      break;
    }
  }

  return cp;
}

void *utf8rcodepoint(const void *utf8_restrict str,
                     utf8_int32_t *utf8_restrict out_codepoint) {
  const char *s = (const char *)str;

  if (0xf0 == (0xf8 & s[0])) {
    // 4 byte utf8 codepoint
    *out_codepoint = ((0x07 & s[0]) << 18) | ((0x3f & s[1]) << 12) |
                     ((0x3f & s[2]) << 6) | (0x3f & s[3]);
  } else if (0xe0 == (0xf0 & s[0])) {
    // 3 byte utf8 codepoint
    *out_codepoint =
        ((0x0f & s[0]) << 12) | ((0x3f & s[1]) << 6) | (0x3f & s[2]);
  } else if (0xc0 == (0xe0 & s[0])) {
    // 2 byte utf8 codepoint
    *out_codepoint = ((0x1f & s[0]) << 6) | (0x3f & s[1]);
  } else {
    // 1 byte utf8 codepoint otherwise
    *out_codepoint = s[0];
  }

  do {
    s--;
  } while ((0 != (0x80 & s[0])) && (0x80 == (0xc0 & s[0])));

  return (void *)s;
}

#undef utf8_restrict
#undef utf8_null

#ifdef __cplusplus
} // extern "C"
#endif

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // SHEREDOM_UTF8_H_INCLUDED



#include <stdlib.h>

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN
#endif

#if defined(OS_WIN) && !defined(__TINYC__)
#include <windows.h>
#include <libloaderapi.h>
#endif

#if defined(__TINYC__)
#include <winapi/windows.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>

typedef struct _stat FileStat;

//#if defined(__TINYC__)
//#include <sys/unistd.h>
//size_t __cdecl strnlen(const char *_Str,size_t _MaxCount);
//#endif

#include <errno.h>


#define LITAC_DEFAULT_ALIGNMENT (2*sizeof(void*))


#line 117 "src/main.lita"
typedef enum litaC_main__ParseStatus {litaC_main__ParseStatus_OK,
litaC_main__ParseStatus_ERROR,
litaC_main__ParseStatus_TERMINATE} litaC_main__ParseStatus;
typedef struct litaC_mem__Allocator litaC_mem__Allocator;
typedef struct litaC_mem__Allocation litaC_mem__Allocation;
typedef struct litaC_mem__DebugAllocator litaC_mem__DebugAllocator;
typedef struct litaC_linear_allocator__LinearAllocator litaC_linear_allocator__LinearAllocator;


#line 5 "C:/Users/antho/git/litac-lang/stdlib/std/io.lita"
typedef enum litaC_io__FileStatus {litaC_io__FileStatus_Ok = 
#line 6 "C:/Users/antho/git/litac-lang/stdlib/std/io.lita"
0,
litaC_io__FileStatus_FileNotFoundError,
litaC_io__FileStatus_IOError} litaC_io__FileStatus;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
typedef enum litaC_cmdline__CmdParserStatus {litaC_cmdline__CmdParserStatus_OK,
litaC_cmdline__CmdParserStatus_MISSING_ARGUMENT,
litaC_cmdline__CmdParserStatus_MISSING_REQUIRED} litaC_cmdline__CmdParserStatus;

#line 16 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
typedef enum litaC_cmdline__OptionFlag {litaC_cmdline__OptionFlag_HAS_ARGUMENT = 
#line 17 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
(1 << 0),
litaC_cmdline__OptionFlag_IS_REQUIRED = 
#line 18 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
(1 << 1),
litaC_cmdline__OptionFlag_IS_USED = 
#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
(1 << 2)} litaC_cmdline__OptionFlag;
typedef struct litaC_cmdline__Option litaC_cmdline__Option;
typedef struct litaC_cmdline__CmdParser litaC_cmdline__CmdParser;
typedef struct litaC_string_buffer__StringBuffer litaC_string_buffer__StringBuffer;
typedef struct litaC_string_view__StringView litaC_string_view__StringView;
typedef struct litaC_string__String litaC_string__String;
typedef struct litaC_system__Process litaC_system__Process;


#line 7 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
typedef enum litaC_profile__ProfileTag {litaC_profile__ProfileTag_MAX_PROFILE_TAGS} litaC_profile__ProfileTag;
typedef struct litaC_profile__ProfileEntry litaC_profile__ProfileEntry;


#line 13 "src/lex.lita"
typedef enum litaC_lex__TokenType {litaC_lex__TokenType_IMPORT,
litaC_lex__TokenType_STRUCT,
litaC_lex__TokenType_UNION,
litaC_lex__TokenType_TRAIT,
litaC_lex__TokenType_ENUM,
litaC_lex__TokenType_FUNC,
litaC_lex__TokenType_TYPEDEF,
litaC_lex__TokenType_VAR,
litaC_lex__TokenType_CONST,
litaC_lex__TokenType_NULL,
litaC_lex__TokenType_VOID,
litaC_lex__TokenType_TRUE,
litaC_lex__TokenType_FALSE,
litaC_lex__TokenType_BOOL,
litaC_lex__TokenType_CHAR,
litaC_lex__TokenType_I8,
litaC_lex__TokenType_U8,
litaC_lex__TokenType_I16,
litaC_lex__TokenType_U16,
litaC_lex__TokenType_I32,
litaC_lex__TokenType_U32,
litaC_lex__TokenType_I64,
litaC_lex__TokenType_U64,
litaC_lex__TokenType_F32,
litaC_lex__TokenType_F64,
litaC_lex__TokenType_USIZE,
litaC_lex__TokenType_FOR,
litaC_lex__TokenType_WHILE,
litaC_lex__TokenType_DO,
litaC_lex__TokenType_IF,
litaC_lex__TokenType_ELSE,
litaC_lex__TokenType_SWITCH,
litaC_lex__TokenType_CASE,
litaC_lex__TokenType_DEFAULT,
litaC_lex__TokenType_DEFER,
litaC_lex__TokenType_BREAK,
litaC_lex__TokenType_CONTINUE,
litaC_lex__TokenType_RETURN,
litaC_lex__TokenType_GOTO,
litaC_lex__TokenType_SIZEOF,
litaC_lex__TokenType_TYPEOF,
litaC_lex__TokenType_OFFSETOF,
litaC_lex__TokenType_AS,
litaC_lex__TokenType_PUBLIC,
litaC_lex__TokenType_USING,
litaC_lex__TokenType_PLUS,
litaC_lex__TokenType_MINUS,
litaC_lex__TokenType_STAR,
litaC_lex__TokenType_MOD,
litaC_lex__TokenType_SLASH,
litaC_lex__TokenType_BACK_SLASH,
litaC_lex__TokenType_DOLLAR,
litaC_lex__TokenType_HASH,
litaC_lex__TokenType_DOT,
litaC_lex__TokenType_VAR_ARGS,
litaC_lex__TokenType_AT,
litaC_lex__TokenType_QUESTION_MARK,
litaC_lex__TokenType_COMMA,
litaC_lex__TokenType_SEMICOLON,
litaC_lex__TokenType_COLON,
litaC_lex__TokenType_COLON_COLON,
litaC_lex__TokenType_DOUBLE_QUOTE,
litaC_lex__TokenType_LESS_THAN,
litaC_lex__TokenType_LESS_EQUALS,
litaC_lex__TokenType_GREATER_THAN,
litaC_lex__TokenType_GREATER_EQUALS,
litaC_lex__TokenType_EQUALS_EQUALS,
litaC_lex__TokenType_EQUALS,
litaC_lex__TokenType_NOT_EQUALS,
litaC_lex__TokenType_PLUS_EQ,
litaC_lex__TokenType_MINUS_EQ,
litaC_lex__TokenType_DIV_EQ,
litaC_lex__TokenType_MUL_EQ,
litaC_lex__TokenType_MOD_EQ,
litaC_lex__TokenType_LSHIFT_EQ,
litaC_lex__TokenType_RSHIFT_EQ,
litaC_lex__TokenType_BNOT_EQ,
litaC_lex__TokenType_XOR_EQ,
litaC_lex__TokenType_BAND_EQ,
litaC_lex__TokenType_BOR_EQ,
litaC_lex__TokenType_LSHIFT,
litaC_lex__TokenType_RSHIFT,
litaC_lex__TokenType_BNOT,
litaC_lex__TokenType_XOR,
litaC_lex__TokenType_BAND,
litaC_lex__TokenType_BOR,
litaC_lex__TokenType_LEFT_PAREN,
litaC_lex__TokenType_RIGHT_PAREN,
litaC_lex__TokenType_LEFT_BRACKET,
litaC_lex__TokenType_RIGHT_BRACKET,
litaC_lex__TokenType_LEFT_BRACE,
litaC_lex__TokenType_RIGHT_BRACE,
litaC_lex__TokenType_NOT,
litaC_lex__TokenType_OR,
litaC_lex__TokenType_AND,
litaC_lex__TokenType_STRING,
litaC_lex__TokenType_IDENTIFIER,
litaC_lex__TokenType_INT_NUMBER,
litaC_lex__TokenType_FLOAT_NUMBER,
litaC_lex__TokenType_ERROR,
litaC_lex__TokenType_END_OF_FILE,
litaC_lex__TokenType_MAX_TOKEN_TYPES} litaC_lex__TokenType;
typedef struct litaC_lex__SrcPos litaC_lex__SrcPos;
typedef union litaC_lex__Value litaC_lex__Value;

#line 445 "src/lex.lita"
typedef enum litaC_lex__Mod {litaC_lex__Mod_NONE = 
#line 446 "src/lex.lita"
0,
litaC_lex__Mod_MULTISTR} litaC_lex__Mod;
typedef struct litaC_lex__Token litaC_lex__Token;
typedef struct litaC_lex__Lexer litaC_lex__Lexer;


#line 20 "src/types.lita"
typedef enum litaC_types__TypeKind {litaC_types__TypeKind_BOOL = 
#line 21 "src/types.lita"
1,
litaC_types__TypeKind_CHAR,
litaC_types__TypeKind_I8,
litaC_types__TypeKind_U8,
litaC_types__TypeKind_I16,
litaC_types__TypeKind_U16,
litaC_types__TypeKind_I32,
litaC_types__TypeKind_U32,
litaC_types__TypeKind_I64,
litaC_types__TypeKind_U64,
litaC_types__TypeKind_F32,
litaC_types__TypeKind_F64,
litaC_types__TypeKind_USIZE,
litaC_types__TypeKind_NULL,
litaC_types__TypeKind_VOID,
litaC_types__TypeKind_STR,
litaC_types__TypeKind_ARRAY,
litaC_types__TypeKind_PTR,
litaC_types__TypeKind_FUNC_PTR,
litaC_types__TypeKind_STRUCT,
litaC_types__TypeKind_UNION,
litaC_types__TypeKind_TRAIT,
litaC_types__TypeKind_ENUM,
litaC_types__TypeKind_FUNC,
litaC_types__TypeKind_CONST,
litaC_types__TypeKind_GENERIC_PARAM,
litaC_types__TypeKind_POISON,
litaC_types__TypeKind_MAX_TYPE_KINDS} litaC_types__TypeKind;
typedef struct litaC_types__FieldPositionResult litaC_types__FieldPositionResult;
typedef struct litaC_types__FieldPath litaC_types__FieldPath;
typedef struct litaC_types__TypeInfo litaC_types__TypeInfo;
typedef struct litaC_types__GenericTypeInfo litaC_types__GenericTypeInfo;
typedef struct litaC_types__FuncTypeInfo litaC_types__FuncTypeInfo;
typedef struct litaC_types__ConstTypeInfo litaC_types__ConstTypeInfo;
typedef struct litaC_types__PtrTypeInfo litaC_types__PtrTypeInfo;
typedef struct litaC_types__ArrayTypeInfo litaC_types__ArrayTypeInfo;
typedef struct litaC_types__FuncPtrTypeInfo litaC_types__FuncPtrTypeInfo;
typedef struct litaC_types__EnumTypeInfo litaC_types__EnumTypeInfo;
typedef struct litaC_types__AggregateTypeInfo litaC_types__AggregateTypeInfo;


#line 16 "src/ast.lita"
typedef enum litaC_ast__StmtKind {litaC_ast__StmtKind_IMPORT_DECL,
litaC_ast__StmtKind_CONST_DECL,
litaC_ast__StmtKind_VAR_DECL,
litaC_ast__StmtKind_STRUCT_DECL,
litaC_ast__StmtKind_UNION_DECL,
litaC_ast__StmtKind_TRAIT_DECL,
litaC_ast__StmtKind_ENUM_DECL,
litaC_ast__StmtKind_FUNC_DECL,
litaC_ast__StmtKind_TYPEDEF_DECL,
litaC_ast__StmtKind_PARAM_DECL,
litaC_ast__StmtKind_NATIVE_DECL,
litaC_ast__StmtKind_NOTES_DECL,
litaC_ast__StmtKind_VAR_FIELD_DECL,
litaC_ast__StmtKind_ENUM_FIELD_ENTRY_DECL,
litaC_ast__StmtKind_ENUM_FIELD_DECL,
litaC_ast__StmtKind_STRUCT_FIELD_DECL,
litaC_ast__StmtKind_UNION_FIELD_DECL,
litaC_ast__StmtKind_TRAIT_FIELD_DECL,
litaC_ast__StmtKind_POISON_DECL,
litaC_ast__StmtKind_BLOCK_STMT,
litaC_ast__StmtKind_BREAK_STMT,
litaC_ast__StmtKind_COMP_STMT,
litaC_ast__StmtKind_CONTINUE_STMT,
litaC_ast__StmtKind_DEFER_STMT,
litaC_ast__StmtKind_DO_WHILE_STMT,
litaC_ast__StmtKind_EMPTY_STMT,
litaC_ast__StmtKind_FOR_STMT,
litaC_ast__StmtKind_FUNC_BODY_STMT,
litaC_ast__StmtKind_GOTO_STMT,
litaC_ast__StmtKind_IF_STMT,
litaC_ast__StmtKind_LABEL_STMT,
litaC_ast__StmtKind_MODULE_STMT,
litaC_ast__StmtKind_NOTE_STMT,
litaC_ast__StmtKind_PARAMETERS_STMT,
litaC_ast__StmtKind_RETURN_STMT,
litaC_ast__StmtKind_SWITCH_CASE_STMT,
litaC_ast__StmtKind_SWITCH_STMT,
litaC_ast__StmtKind_WHILE_STMT,
litaC_ast__StmtKind_ARRAY_DESIGNATION_EXPR,
litaC_ast__StmtKind_ARRAY_INIT_EXPR,
litaC_ast__StmtKind_BINARY_EXPR,
litaC_ast__StmtKind_BOOLEAN_EXPR,
litaC_ast__StmtKind_CAST_EXPR,
litaC_ast__StmtKind_CHAR_EXPR,
litaC_ast__StmtKind_FUNC_CALL_EXPR,
litaC_ast__StmtKind_FUNC_IDENTIFIER_EXPR,
litaC_ast__StmtKind_GET_EXPR,
litaC_ast__StmtKind_GROUP_EXPR,
litaC_ast__StmtKind_IDENTIFIER_EXPR,
litaC_ast__StmtKind_INIT_EXPR,
litaC_ast__StmtKind_INIT_ARG_EXPR,
litaC_ast__StmtKind_NULL_EXPR,
litaC_ast__StmtKind_NUMBER_EXPR,
litaC_ast__StmtKind_OFFSET_OF_EXPR,
litaC_ast__StmtKind_SET_EXPR,
litaC_ast__StmtKind_SIZE_OF_EXPR,
litaC_ast__StmtKind_STRING_EXPR,
litaC_ast__StmtKind_SUBSCRIPT_GET_EXPR,
litaC_ast__StmtKind_SUBSCRIPT_SET_EXPR,
litaC_ast__StmtKind_TERNARY_EXPR,
litaC_ast__StmtKind_TYPE_IDENTIFIER_EXPR,
litaC_ast__StmtKind_TYPE_OF_EXPR,
litaC_ast__StmtKind_UNARY_EXPR,
litaC_ast__StmtKind_POISON_EXPR,
litaC_ast__StmtKind_MAX_STMT_KINDS} litaC_ast__StmtKind;


#line 89 "src/ast.lita"
typedef enum litaC_ast__TypeSpecKind {litaC_ast__TypeSpecKind_NONE,
litaC_ast__TypeSpecKind_ARRAY,
litaC_ast__TypeSpecKind_PTR,
litaC_ast__TypeSpecKind_CONST,
litaC_ast__TypeSpecKind_NAME,
litaC_ast__TypeSpecKind_FUNC_PTR,
litaC_ast__TypeSpecKind_MAX_TYPESPEC_KINDS} litaC_ast__TypeSpecKind;

#line 100 "src/ast.lita"
typedef enum litaC_ast__FuncFlags {litaC_ast__FuncFlags_HAS_VARARGS = 
#line 101 "src/ast.lita"
(1 << 0),
litaC_ast__FuncFlags_IS_METHOD = 
#line 102 "src/ast.lita"
(1 << 1)} litaC_ast__FuncFlags;

#line 105 "src/ast.lita"
typedef enum litaC_ast__AggregateFlags {litaC_ast__AggregateFlags_IS_EMBEDDED = 
#line 106 "src/ast.lita"
(1 << 0),
litaC_ast__AggregateFlags_IS_ANONYMOUS = 
#line 107 "src/ast.lita"
(1 << 1)} litaC_ast__AggregateFlags;
typedef struct litaC_ast__TypeSpec litaC_ast__TypeSpec;
typedef struct litaC_ast__NameTypeSpec litaC_ast__NameTypeSpec;
typedef struct litaC_ast__ArrayTypeSpec litaC_ast__ArrayTypeSpec;
typedef struct litaC_ast__PtrTypeSpec litaC_ast__PtrTypeSpec;
typedef struct litaC_ast__ConstTypeSpec litaC_ast__ConstTypeSpec;
typedef struct litaC_ast__FuncPtrTypeSpec litaC_ast__FuncPtrTypeSpec;
typedef struct litaC_ast__GenericParam litaC_ast__GenericParam;
typedef struct litaC_ast__Attributes litaC_ast__Attributes;
typedef struct litaC_ast__Node litaC_ast__Node;
typedef struct litaC_ast__Decl litaC_ast__Decl;
typedef struct litaC_ast__GenericDecl litaC_ast__GenericDecl;
typedef struct litaC_ast__ImportDecl litaC_ast__ImportDecl;
typedef struct litaC_ast__VarDecl litaC_ast__VarDecl;
typedef struct litaC_ast__ParameterDecl litaC_ast__ParameterDecl;
typedef struct litaC_ast__FuncDecl litaC_ast__FuncDecl;
typedef struct litaC_ast__AggregateDecl litaC_ast__AggregateDecl;
typedef struct litaC_ast__EnumDecl litaC_ast__EnumDecl;
typedef struct litaC_ast__TypedefDecl litaC_ast__TypedefDecl;
typedef struct litaC_ast__NativeDecl litaC_ast__NativeDecl;
typedef struct litaC_ast__NotesDecl litaC_ast__NotesDecl;
typedef struct litaC_ast__PoisonDecl litaC_ast__PoisonDecl;
typedef struct litaC_ast__BlockStmt litaC_ast__BlockStmt;
typedef struct litaC_ast__BreakStmt litaC_ast__BreakStmt;
typedef struct litaC_ast__CompStmt litaC_ast__CompStmt;
typedef struct litaC_ast__ContinueStmt litaC_ast__ContinueStmt;
typedef struct litaC_ast__DeferStmt litaC_ast__DeferStmt;
typedef struct litaC_ast__DoWhileStmt litaC_ast__DoWhileStmt;
typedef struct litaC_ast__EmptyStmt litaC_ast__EmptyStmt;
typedef struct litaC_ast__EnumFieldEntryDecl litaC_ast__EnumFieldEntryDecl;
typedef struct litaC_ast__ForStmt litaC_ast__ForStmt;
typedef struct litaC_ast__FuncBodyStmt litaC_ast__FuncBodyStmt;
typedef struct litaC_ast__GotoStmt litaC_ast__GotoStmt;
typedef struct litaC_ast__IfStmt litaC_ast__IfStmt;
typedef struct litaC_ast__LabelStmt litaC_ast__LabelStmt;
typedef struct litaC_ast__ModuleStmt litaC_ast__ModuleStmt;
typedef struct litaC_ast__NoteStmt litaC_ast__NoteStmt;
typedef struct litaC_ast__ParametersStmt litaC_ast__ParametersStmt;
typedef struct litaC_ast__ReturnStmt litaC_ast__ReturnStmt;
typedef struct litaC_ast__SwitchCaseStmt litaC_ast__SwitchCaseStmt;
typedef struct litaC_ast__SwitchStmt litaC_ast__SwitchStmt;
typedef struct litaC_ast__VarFieldDecl litaC_ast__VarFieldDecl;
typedef struct litaC_ast__TraitFieldDecl litaC_ast__TraitFieldDecl;
typedef union litaC_ast__anon_0 litaC_ast__anon_0;
typedef struct litaC_ast__FieldStmt litaC_ast__FieldStmt;
typedef struct litaC_ast__WhileStmt litaC_ast__WhileStmt;
typedef struct litaC_ast__Stmt litaC_ast__Stmt;
typedef struct litaC_ast__ArrayDesignationExpr litaC_ast__ArrayDesignationExpr;
typedef struct litaC_ast__ArrayInitExpr litaC_ast__ArrayInitExpr;
typedef struct litaC_ast__BinaryExpr litaC_ast__BinaryExpr;
typedef struct litaC_ast__BooleanExpr litaC_ast__BooleanExpr;
typedef struct litaC_ast__CastExpr litaC_ast__CastExpr;
typedef struct litaC_ast__CharExpr litaC_ast__CharExpr;
typedef struct litaC_ast__CallArg litaC_ast__CallArg;
typedef struct litaC_ast__FuncCallExpr litaC_ast__FuncCallExpr;

#line 467 "src/ast.lita"
typedef enum litaC_ast__GetExprFlags {litaC_ast__GetExprFlags_IS_NORMAL = 
#line 468 "src/ast.lita"
0,
litaC_ast__GetExprFlags_IS_METHOD_CALL = 
#line 469 "src/ast.lita"
(1 << 0),
litaC_ast__GetExprFlags_IS_ENUM = 
#line 470 "src/ast.lita"
(1 << 1),
litaC_ast__GetExprFlags_IS_USING = 
#line 471 "src/ast.lita"
(1 << 2),
litaC_ast__GetExprFlags_IS_METHOD_ARG = 
#line 472 "src/ast.lita"
(1 << 3)} litaC_ast__GetExprFlags;
typedef struct litaC_ast__GetExpr litaC_ast__GetExpr;
typedef struct litaC_ast__GroupExpr litaC_ast__GroupExpr;
typedef struct litaC_ast__IdentifierExpr litaC_ast__IdentifierExpr;
typedef struct litaC_ast__InitArgExpr litaC_ast__InitArgExpr;
typedef struct litaC_ast__InitExpr litaC_ast__InitExpr;
typedef struct litaC_ast__NullExpr litaC_ast__NullExpr;
typedef struct litaC_ast__NumberExpr litaC_ast__NumberExpr;
typedef struct litaC_ast__OffsetOfExpr litaC_ast__OffsetOfExpr;
typedef struct litaC_ast__SetExpr litaC_ast__SetExpr;
typedef struct litaC_ast__SizeOfExpr litaC_ast__SizeOfExpr;
typedef struct litaC_ast__StringExpr litaC_ast__StringExpr;
typedef struct litaC_ast__SubscriptGetExpr litaC_ast__SubscriptGetExpr;
typedef struct litaC_ast__SubscriptSetExpr litaC_ast__SubscriptSetExpr;
typedef struct litaC_ast__TernaryExpr litaC_ast__TernaryExpr;
typedef struct litaC_ast__TypeIdentifierExpr litaC_ast__TypeIdentifierExpr;
typedef struct litaC_ast__TypeOfExpr litaC_ast__TypeOfExpr;
typedef struct litaC_ast__UnaryExpr litaC_ast__UnaryExpr;
typedef struct litaC_ast__PoisonExpr litaC_ast__PoisonExpr;
typedef struct litaC_ast__Expr litaC_ast__Expr;
typedef struct litaC_ast__Operand litaC_ast__Operand;


#line 15 "src/symbols.lita"
typedef enum litaC_symbols__SymbolKind {litaC_symbols__SymbolKind_TYPE,
litaC_symbols__SymbolKind_VAR,
litaC_symbols__SymbolKind_CONST,
litaC_symbols__SymbolKind_FUNC} litaC_symbols__SymbolKind;


#line 23 "src/symbols.lita"
typedef enum litaC_symbols__SymbolState {litaC_symbols__SymbolState_UNRESOLVED = 
#line 24 "src/symbols.lita"
0,
litaC_symbols__SymbolState_RESOLVING,
litaC_symbols__SymbolState_RESOLVED,
litaC_symbols__SymbolState_ERROR} litaC_symbols__SymbolState;

#line 30 "src/symbols.lita"
typedef enum litaC_symbols__SymbolFlags {litaC_symbols__SymbolFlags_IS_LOCAL = 
#line 31 "src/symbols.lita"
(1 << 1),
litaC_symbols__SymbolFlags_IS_FOREIGN = 
#line 32 "src/symbols.lita"
(1 << 2),
litaC_symbols__SymbolFlags_IS_CONSTANT = 
#line 33 "src/symbols.lita"
(1 << 3),
litaC_symbols__SymbolFlags_IS_USING = 
#line 34 "src/symbols.lita"
(1 << 4),
litaC_symbols__SymbolFlags_IS_TYPE = 
#line 35 "src/symbols.lita"
(1 << 5),
litaC_symbols__SymbolFlags_IS_INCOMPLETE = 
#line 36 "src/symbols.lita"
(1 << 6),
litaC_symbols__SymbolFlags_IS_GENERIC_TEMPLATE = 
#line 37 "src/symbols.lita"
(1 << 7),
litaC_symbols__SymbolFlags_IS_BUILTIN = 
#line 38 "src/symbols.lita"
(1 << 8),
litaC_symbols__SymbolFlags_IS_FROM_GENERIC_TEMPLATE = 
#line 39 "src/symbols.lita"
(1 << 9),
litaC_symbols__SymbolFlags_IS_IMPORTED = 
#line 40 "src/symbols.lita"
(1 << 10),
litaC_symbols__SymbolFlags_IS_PUBLIC = 
#line 41 "src/symbols.lita"
(1 << 11),
litaC_symbols__SymbolFlags_IS_EMITTED = 
#line 42 "src/symbols.lita"
(1 << 12),
litaC_symbols__SymbolFlags_IS_TEST = 
#line 43 "src/symbols.lita"
(1 << 13),
litaC_symbols__SymbolFlags_IS_ALIAS = 
#line 44 "src/symbols.lita"
(1 << 14),
litaC_symbols__SymbolFlags_IS_MAIN = 
#line 45 "src/symbols.lita"
(1 << 15),
litaC_symbols__SymbolFlags_IS_METHOD = 
#line 46 "src/symbols.lita"
(1 << 16),
litaC_symbols__SymbolFlags_IS_TRAIT = 
#line 47 "src/symbols.lita"
(1 << 17),
litaC_symbols__SymbolFlags_IS_TRAIT_METHOD = 
#line 48 "src/symbols.lita"
(1 << 18),
litaC_symbols__SymbolFlags_IS_TRAIT_GENERATED = 
#line 49 "src/symbols.lita"
(1 << 19),
litaC_symbols__SymbolFlags_IS_GENERATED = 
#line 50 "src/symbols.lita"
(1 << 20)} litaC_symbols__SymbolFlags;
typedef struct litaC_symbols__Symbol litaC_symbols__Symbol;

#line 79 "src/symbols.lita"
typedef enum litaC_symbols__ScopeKind {litaC_symbols__ScopeKind_MODULE,
litaC_symbols__ScopeKind_FUNC} litaC_symbols__ScopeKind;
typedef struct litaC_symbols__ProgramSymbols litaC_symbols__ProgramSymbols;
typedef struct litaC_symbols__Scope litaC_symbols__Scope;

#line 19 "src/module.lita"
typedef enum litaC_module__ModuleFlags {litaC_module__ModuleFlags_TYPE_CHECKED = 
#line 20 "src/module.lita"
(1 << 0),
litaC_module__ModuleFlags_TYPE_RESOLVED = 
#line 21 "src/module.lita"
(1 << 1),
litaC_module__ModuleFlags_TYPE_IMPORTED = 
#line 22 "src/module.lita"
(1 << 2)} litaC_module__ModuleFlags;
typedef struct litaC_module__ModuleId litaC_module__ModuleId;
typedef struct litaC_module__ModuleImport litaC_module__ModuleImport;
typedef struct litaC_module__Module litaC_module__Module;

#line 9 "src/phase_result.lita"
typedef enum litaC_phase_result__ErrorType {litaC_phase_result__ErrorType_WARN,
litaC_phase_result__ErrorType_ERROR} litaC_phase_result__ErrorType;
typedef struct litaC_phase_result__PhaseError litaC_phase_result__PhaseError;
typedef struct litaC_phase_result__PhaseResult litaC_phase_result__PhaseResult;

#line 5 "src/common.lita"
typedef enum litaC_common__LogLevel {litaC_common__LogLevel_TRACE,
litaC_common__LogLevel_INFO,
litaC_common__LogLevel_DEBUG,
litaC_common__LogLevel_ERROR,
litaC_common__LogLevel_FATAL} litaC_common__LogLevel;
typedef struct litaC_lita__Lita litaC_lita__Lita;


#line 63 "src/lita.lita"
typedef enum litaC_lita__MetricType {litaC_lita__MetricType_PARSING,
litaC_lita__MetricType_TYPE_CHECKING,
litaC_lita__MetricType_CGEN,
litaC_lita__MetricType_CCOMPILE,
litaC_lita__MetricType_MAX_METRIC_TYPES} litaC_lita__MetricType;
typedef struct litaC_lita__Metric litaC_lita__Metric;


#line 81 "src/lita.lita"
typedef enum litaC_lita__TypeInfoOption {litaC_lita__TypeInfoOption_NONE,
litaC_lita__TypeInfoOption_TAGGED,
litaC_lita__TypeInfoOption_ALL} litaC_lita__TypeInfoOption;
typedef struct litaC_lita__LitaOptions litaC_lita__LitaOptions;
typedef struct litaC_bucket_allocator__Bucket litaC_bucket_allocator__Bucket;
typedef struct litaC_bucket_allocator__BucketAllocator litaC_bucket_allocator__BucketAllocator;
typedef struct litaC_preprocessor__Preprocessor litaC_preprocessor__Preprocessor;
typedef struct litaC_preprocessor__CallContext litaC_preprocessor__CallContext;
typedef struct litaC_regex__Regex litaC_regex__Regex;
typedef struct litaC_checker__LabelInfo litaC_checker__LabelInfo;
typedef struct litaC_checker__GenericContext litaC_checker__GenericContext;
typedef struct litaC_checker__TypeChecker litaC_checker__TypeChecker;
typedef struct litaC_types_new__TypeCache litaC_types_new__TypeCache;
typedef struct litaC_types_new__ArrayEntry litaC_types_new__ArrayEntry;
typedef struct litaC_intern__anon_1 litaC_intern__anon_1;
typedef struct litaC_intern__anon_2 litaC_intern__anon_2;
typedef union litaC_intern__InternedString litaC_intern__InternedString;
typedef struct litaC_intern__Strings litaC_intern__Strings;
typedef struct litaC_generics__Template litaC_generics__Template;
typedef struct litaC_introspection__Introspect litaC_introspection__Introspect;

#line 6 "src/error_codes.lita"
typedef enum litaC_error_codes__ErrorCode {litaC_error_codes__ErrorCode_INVALID_ASSIGNMENT,
litaC_error_codes__ErrorCode_INVALID_CONST_EXPR,
litaC_error_codes__ErrorCode_INVALID_ARRAY_DIMENSION_EXPR,
litaC_error_codes__ErrorCode_INVALID_CHARACTER,
litaC_error_codes__ErrorCode_INVALID_NUMBER,
litaC_error_codes__ErrorCode_INVALID_FIELD,
litaC_error_codes__ErrorCode_INVALID_IMPORT_ACCESS,
litaC_error_codes__ErrorCode_INVALID_CONTINUE,
litaC_error_codes__ErrorCode_INVALID_BREAK,
litaC_error_codes__ErrorCode_INVALID_OBJECT_INIT,
litaC_error_codes__ErrorCode_INVALID_MODULE_ACCESS,
litaC_error_codes__ErrorCode_INVALID_VARARG_POSITION,
litaC_error_codes__ErrorCode_INVALID_NOTE_DECL,
litaC_error_codes__ErrorCode_INVALID_LABEL_STMT,
litaC_error_codes__ErrorCode_INVALID_COMP_STMT,
litaC_error_codes__ErrorCode_INVALID_DEFAULT_ASSIGNMENT,
litaC_error_codes__ErrorCode_INVALID_TRAIT_MEMBER,
litaC_error_codes__ErrorCode_MISSING_COMMA,
litaC_error_codes__ErrorCode_MISSING_SEMICOLON,
litaC_error_codes__ErrorCode_MISSING_RIGHT_BRACE,
litaC_error_codes__ErrorCode_MISSING_EQUALS,
litaC_error_codes__ErrorCode_MISSING_IDENTIFIER,
litaC_error_codes__ErrorCode_MISSING_RIGHT_BRACKET,
litaC_error_codes__ErrorCode_MISSING_RIGHT_PAREN,
litaC_error_codes__ErrorCode_MISSING_LEFT_PAREN,
litaC_error_codes__ErrorCode_MISSING_LEFT_BRACE,
litaC_error_codes__ErrorCode_MISSING_ARRAY_BRACKETS,
litaC_error_codes__ErrorCode_MISSING_COLON,
litaC_error_codes__ErrorCode_MISSING_WHILE,
litaC_error_codes__ErrorCode_MISSING_AS,
litaC_error_codes__ErrorCode_MISSING_GENERIC_END,
litaC_error_codes__ErrorCode_MISSING_COMP_STMT_END,
litaC_error_codes__ErrorCode_RANGE_INTEGER,
litaC_error_codes__ErrorCode_RANGE_LONG,
litaC_error_codes__ErrorCode_RANGE_REAL,
litaC_error_codes__ErrorCode_UNEXPECTED_EOF,
litaC_error_codes__ErrorCode_UNEXPECTED_TOKEN,
litaC_error_codes__ErrorCode_UNIMPLEMENTED,
litaC_error_codes__ErrorCode_UNKNOWN_ERROR,
litaC_error_codes__ErrorCode_TOO_MANY_ERRORS,
litaC_error_codes__ErrorCode_MAX_NUM_ERROR_CODES} litaC_error_codes__ErrorCode;
typedef struct litaC_parser__Parser litaC_parser__Parser;
typedef struct litaC_cgen__CGen litaC_cgen__CGen;
typedef struct litaC_cgen__CGenScope litaC_cgen__CGenScope;
typedef struct litaC_cgen__CompilationUnit litaC_cgen__CompilationUnit;
typedef struct litaC_dependency_graph__DependencyGraph litaC_dependency_graph__DependencyGraph;

#line 39 "src/dependency_graph.lita"
typedef enum litaC_dependency_graph__State {litaC_dependency_graph__State_EMPTY = 
#line 40 "src/dependency_graph.lita"
0,
litaC_dependency_graph__State_PENDING = 
#line 41 "src/dependency_graph.lita"
1,
litaC_dependency_graph__State_RESOLVED = 
#line 42 "src/dependency_graph.lita"
2} litaC_dependency_graph__State;
typedef struct litaC_dependency_graph__Dependency litaC_dependency_graph__Dependency;
typedef struct litaC_references__Reference litaC_references__Reference;
typedef struct litaC_references__FieldReference litaC_references__FieldReference;
typedef struct litaC_references__ReferenceDatabase litaC_references__ReferenceDatabase;


#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
typedef enum litaC_json__JsonType {litaC_json__JsonType_NULL,
litaC_json__JsonType_BOOLEAN,
litaC_json__JsonType_INT_NUMBER,
litaC_json__JsonType_FLOAT_NUMBER,
litaC_json__JsonType_STRING,
litaC_json__JsonType_OBJECT,
litaC_json__JsonType_ARRAY} litaC_json__JsonType;
typedef struct litaC_json__Entry litaC_json__Entry;
typedef struct litaC_json__JsonObject litaC_json__JsonObject;
typedef union litaC_json__JsonValue litaC_json__JsonValue;
typedef struct litaC_json__JsonNode litaC_json__JsonNode;

#line 662 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
typedef enum litaC_json__TokenKind {litaC_json__TokenKind_EOF,
litaC_json__TokenKind_ERROR,
litaC_json__TokenKind_COMMA,
litaC_json__TokenKind_COLON,
litaC_json__TokenKind_LEFT_BRACE,
litaC_json__TokenKind_RIGHT_BRACE,
litaC_json__TokenKind_LEFT_BRACKET,
litaC_json__TokenKind_RIGHT_BRACKET,
litaC_json__TokenKind_NULL,
litaC_json__TokenKind_INT_NUMBER,
litaC_json__TokenKind_REAL_NUMBER,
litaC_json__TokenKind_TRUE,
litaC_json__TokenKind_FALSE,
litaC_json__TokenKind_STRING} litaC_json__TokenKind;
typedef struct litaC_json__SrcPos litaC_json__SrcPos;
typedef union litaC_json__anon_3 litaC_json__anon_3;
typedef struct litaC_json__Token litaC_json__Token;

#line 750 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
typedef enum litaC_json__JsonParserStatus {litaC_json__JsonParserStatus_OK = 
#line 751 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
0,
litaC_json__JsonParserStatus_WARNING,
litaC_json__JsonParserStatus_ERROR} litaC_json__JsonParserStatus;
typedef struct litaC_json__JsonParser litaC_json__JsonParser;
typedef struct litaC_workspace__Workspace litaC_workspace__Workspace;
typedef struct litaC_workspace__Document litaC_workspace__Document;
typedef struct litaC_lsp__LspServer litaC_lsp__LspServer;
typedef struct litaC_protocol__Position litaC_protocol__Position;
typedef struct litaC_protocol__Range litaC_protocol__Range;
typedef struct litaC_protocol__Location litaC_protocol__Location;
typedef struct litaC_protocol__TextDocument litaC_protocol__TextDocument;
typedef struct litaC_protocol__TextDocumentDidChange litaC_protocol__TextDocumentDidChange;
typedef struct litaC_protocol__TextDocumentChangeEvent litaC_protocol__TextDocumentChangeEvent;

#line 51 "src/lsp/protocol.lita"
typedef enum litaC_protocol__ErrorCodes {litaC_protocol__ErrorCodes_ParseError = 
#line 53 "src/lsp/protocol.lita"
-(32700),
litaC_protocol__ErrorCodes_InvalidRequest = 
#line 54 "src/lsp/protocol.lita"
-(32600),
litaC_protocol__ErrorCodes_MethodNotFound = 
#line 55 "src/lsp/protocol.lita"
-(32601),
litaC_protocol__ErrorCodes_InvalidParams = 
#line 56 "src/lsp/protocol.lita"
-(32602),
litaC_protocol__ErrorCodes_InternalError = 
#line 57 "src/lsp/protocol.lita"
-(32603),
litaC_protocol__ErrorCodes_jsonrpcReservedErrorRangeStart = 
#line 68 "src/lsp/protocol.lita"
-(32099),
litaC_protocol__ErrorCodes_serverErrorStart = 
#line 70 "src/lsp/protocol.lita"
litaC_protocol__ErrorCodes_jsonrpcReservedErrorRangeStart,
litaC_protocol__ErrorCodes_ServerNotInitialized = 
#line 72 "src/lsp/protocol.lita"
-(32002),
litaC_protocol__ErrorCodes_UnknownErrorCode = 
#line 73 "src/lsp/protocol.lita"
-(32001),
litaC_protocol__ErrorCodes_jsonrpcReservedErrorRangeEnd = 
#line 81 "src/lsp/protocol.lita"
-(32000),
litaC_protocol__ErrorCodes_serverErrorEnd = 
#line 83 "src/lsp/protocol.lita"
litaC_protocol__ErrorCodes_jsonrpcReservedErrorRangeEnd,
litaC_protocol__ErrorCodes_lspReservedErrorRangeStart = 
#line 91 "src/lsp/protocol.lita"
-(32899),
litaC_protocol__ErrorCodes_ContentModified = 
#line 93 "src/lsp/protocol.lita"
-(32801),
litaC_protocol__ErrorCodes_RequestCancelled = 
#line 94 "src/lsp/protocol.lita"
-(32800),
litaC_protocol__ErrorCodes_lspReservedErrorRangeEnd = 
#line 102 "src/lsp/protocol.lita"
-(32800)} litaC_protocol__ErrorCodes;


#line 106 "src/lsp/protocol.lita"
typedef enum litaC_protocol__SymbolInfoKind {litaC_protocol__SymbolInfoKind_File = 
#line 107 "src/lsp/protocol.lita"
1,
litaC_protocol__SymbolInfoKind_Module = 
#line 108 "src/lsp/protocol.lita"
2,
litaC_protocol__SymbolInfoKind_Namespace = 
#line 109 "src/lsp/protocol.lita"
3,
litaC_protocol__SymbolInfoKind_Package = 
#line 110 "src/lsp/protocol.lita"
4,
litaC_protocol__SymbolInfoKind_Class = 
#line 111 "src/lsp/protocol.lita"
5,
litaC_protocol__SymbolInfoKind_Method = 
#line 112 "src/lsp/protocol.lita"
6,
litaC_protocol__SymbolInfoKind_Property = 
#line 113 "src/lsp/protocol.lita"
7,
litaC_protocol__SymbolInfoKind_Field = 
#line 114 "src/lsp/protocol.lita"
8,
litaC_protocol__SymbolInfoKind_Constructor = 
#line 115 "src/lsp/protocol.lita"
9,
litaC_protocol__SymbolInfoKind_Enum = 
#line 116 "src/lsp/protocol.lita"
10,
litaC_protocol__SymbolInfoKind_Interface = 
#line 117 "src/lsp/protocol.lita"
11,
litaC_protocol__SymbolInfoKind_Function = 
#line 118 "src/lsp/protocol.lita"
12,
litaC_protocol__SymbolInfoKind_Variable = 
#line 119 "src/lsp/protocol.lita"
13,
litaC_protocol__SymbolInfoKind_Constant = 
#line 120 "src/lsp/protocol.lita"
14,
litaC_protocol__SymbolInfoKind_String = 
#line 121 "src/lsp/protocol.lita"
15,
litaC_protocol__SymbolInfoKind_Number = 
#line 122 "src/lsp/protocol.lita"
16,
litaC_protocol__SymbolInfoKind_Boolean = 
#line 123 "src/lsp/protocol.lita"
17,
litaC_protocol__SymbolInfoKind_Array = 
#line 124 "src/lsp/protocol.lita"
18,
litaC_protocol__SymbolInfoKind_Object = 
#line 125 "src/lsp/protocol.lita"
19,
litaC_protocol__SymbolInfoKind_Key = 
#line 126 "src/lsp/protocol.lita"
20,
litaC_protocol__SymbolInfoKind_Null = 
#line 127 "src/lsp/protocol.lita"
21,
litaC_protocol__SymbolInfoKind_EnumMember = 
#line 128 "src/lsp/protocol.lita"
22,
litaC_protocol__SymbolInfoKind_Struct = 
#line 129 "src/lsp/protocol.lita"
23,
litaC_protocol__SymbolInfoKind_Event = 
#line 130 "src/lsp/protocol.lita"
24,
litaC_protocol__SymbolInfoKind_Operator = 
#line 131 "src/lsp/protocol.lita"
25,
litaC_protocol__SymbolInfoKind_TypeParameter = 
#line 132 "src/lsp/protocol.lita"
26} litaC_protocol__SymbolInfoKind;

#line 16 "src/lsp/util.lita"
typedef enum litaC_util__SourceLocationKind {litaC_util__SourceLocationKind_NONE,
litaC_util__SourceLocationKind_AST,
litaC_util__SourceLocationKind_TYPE} litaC_util__SourceLocationKind;
typedef union litaC_util__anon_4 litaC_util__anon_4;
typedef struct litaC_util__SourceLocation litaC_util__SourceLocation;
typedef struct litaC_util__SourceLookup litaC_util__SourceLookup;
typedef struct litaC_builtins__any litaC_builtins__any;
typedef struct litaC_array__Array_cb__ptr_JsonNode_ce_ litaC_array__Array_cb__ptr_JsonNode_ce_;
typedef struct litaC_array__Array_cb__ptr_Allocation_ce_ litaC_array__Array_cb__ptr_Allocation_ce_;
typedef struct litaC_array__Array_cb_Option_ce_ litaC_array__Array_cb_Option_ce_;
typedef struct litaC_array__Array_cb__ptr_const_char_ce_ litaC_array__Array_cb__ptr_const_char_ce_;
typedef struct litaC_array__Array_cb_GenericParam_ce_ litaC_array__Array_cb_GenericParam_ce_;
typedef struct litaC_array__Array_cb__ptr_TypeInfo_ce_ litaC_array__Array_cb__ptr_TypeInfo_ce_;
typedef struct litaC_array__Array_cb__ptr_TypeSpec_ce_ litaC_array__Array_cb__ptr_TypeSpec_ce_;
typedef struct litaC_array__Array_cb__ptr_NoteStmt_ce_ litaC_array__Array_cb__ptr_NoteStmt_ce_;
typedef struct litaC_array__Array_cb_FieldStmt_ce_ litaC_array__Array_cb_FieldStmt_ce_;
typedef struct litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_ litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_;
typedef struct litaC_array__Array_cb__ptr_Stmt_ce_ litaC_array__Array_cb__ptr_Stmt_ce_;
typedef struct litaC_array__Array_cb__ptr_ImportDecl_ce_ litaC_array__Array_cb__ptr_ImportDecl_ce_;
typedef struct litaC_array__Array_cb__ptr_Decl_ce_ litaC_array__Array_cb__ptr_Decl_ce_;
typedef struct litaC_array__Array_cb_Token_ce_ litaC_array__Array_cb_Token_ce_;
typedef struct litaC_array__Array_cb__ptr_ParameterDecl_ce_ litaC_array__Array_cb__ptr_ParameterDecl_ce_;
typedef struct litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_ litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_;
typedef struct litaC_array__Array_cb__ptr_Expr_ce_ litaC_array__Array_cb__ptr_Expr_ce_;
typedef struct litaC_array__Array_cb_CallArg_ce_ litaC_array__Array_cb_CallArg_ce_;
typedef struct litaC_array__Array_cb__ptr_InitArgExpr_ce_ litaC_array__Array_cb__ptr_InitArgExpr_ce_;
typedef struct litaC_array__Array_cb__ptr_Symbol_ce_ litaC_array__Array_cb__ptr_Symbol_ce_;
typedef struct litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_ litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_;
typedef struct litaC_array__Array_cb_i64_ce_ litaC_array__Array_cb_i64_ce_;
typedef struct litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_ litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_;
typedef struct litaC_array__Array_cb_ModuleImport_ce_ litaC_array__Array_cb_ModuleImport_ce_;
typedef struct litaC_array__Array_cb_PhaseError_ce_ litaC_array__Array_cb_PhaseError_ce_;
typedef struct litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_ litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_;
typedef struct litaC_array__Array_cb__ptr_CompStmt_ce_ litaC_array__Array_cb__ptr_CompStmt_ce_;
typedef struct litaC_array__Array_cb__ptr_Module_ce_ litaC_array__Array_cb__ptr_Module_ce_;
typedef struct litaC_array__Array_cb__ptr_FuncTypeInfo_ce_ litaC_array__Array_cb__ptr_FuncTypeInfo_ce_;
typedef struct litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_ litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_;
typedef struct litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_ litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_;
typedef struct litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_ litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_;
typedef struct litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_;
typedef struct litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_ litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_;
typedef struct litaC_map__Map_cb_StringView_c_InternedString_ce_ litaC_map__Map_cb_StringView_c_InternedString_ce_;
typedef struct litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_ litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_;
typedef struct litaC_array__Array_cb__ptr_Dependency_ce_ litaC_array__Array_cb__ptr_Dependency_ce_;
typedef struct litaC_array__Array_cb_Reference_ce_ litaC_array__Array_cb_Reference_ce_;
typedef struct litaC_array__Array_cb_FieldReference_ce_ litaC_array__Array_cb_FieldReference_ce_;
typedef struct litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_ litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_;
typedef struct litaC_array__Array_cb_SrcPos_ce_ litaC_array__Array_cb_SrcPos_ce_;
typedef struct litaC_map__Map_cb__ptr_const_char_c_i32_ce_ litaC_map__Map_cb__ptr_const_char_c_i32_ce_;
typedef struct litaC_array__Array_cb_Entry_ce_ litaC_array__Array_cb_Entry_ce_;
typedef struct litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_ litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_;
typedef struct litaC_array__Array_cb_u32_ce_ litaC_array__Array_cb_u32_ce_;
typedef struct litaC_map__MapIterator_cb_InternedString_c__ptr_Symbol_ce_ litaC_map__MapIterator_cb_InternedString_c__ptr_Symbol_ce_;
typedef struct litaC_map__MapEntry_cb_InternedString_c__ptr_Symbol_ce_ litaC_map__MapEntry_cb_InternedString_c__ptr_Symbol_ce_;
typedef struct litaC_map__MapIterator_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ litaC_map__MapIterator_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_;
typedef struct litaC_map__MapEntry_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ litaC_map__MapEntry_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_;
typedef struct litaC_map__MapIterator_cb_i64_c__ptr_PtrTypeInfo_ce_ litaC_map__MapIterator_cb_i64_c__ptr_PtrTypeInfo_ce_;
typedef struct litaC_map__MapEntry_cb_i64_c__ptr_PtrTypeInfo_ce_ litaC_map__MapEntry_cb_i64_c__ptr_PtrTypeInfo_ce_;
typedef struct litaC_map__MapIterator_cb_i64_c__ptr_ConstTypeInfo_ce_ litaC_map__MapIterator_cb_i64_c__ptr_ConstTypeInfo_ce_;
typedef struct litaC_map__MapEntry_cb_i64_c__ptr_ConstTypeInfo_ce_ litaC_map__MapEntry_cb_i64_c__ptr_ConstTypeInfo_ce_;
typedef struct litaC_map__MapIterator_cb_i64_c_Array_cb_i64_ce__ce_ litaC_map__MapIterator_cb_i64_c_Array_cb_i64_ce__ce_;
typedef struct litaC_map__MapEntry_cb_i64_c_Array_cb_i64_ce__ce_ litaC_map__MapEntry_cb_i64_c_Array_cb_i64_ce__ce_;
typedef struct litaC_map__MapIterator_cb__ptr_const_char_c__ptr_Module_ce_ litaC_map__MapIterator_cb__ptr_const_char_c__ptr_Module_ce_;
typedef struct litaC_map__MapEntry_cb__ptr_const_char_c__ptr_Module_ce_ litaC_map__MapEntry_cb__ptr_const_char_c__ptr_Module_ce_;
typedef struct litaC_map__MapIterator_cb__ptr_Symbol_c_Dependency_ce_ litaC_map__MapIterator_cb__ptr_Symbol_c_Dependency_ce_;
typedef struct litaC_map__MapEntry_cb__ptr_Symbol_c_Dependency_ce_ litaC_map__MapEntry_cb__ptr_Symbol_c_Dependency_ce_;

#line 28 "src/main.lita"
litaC_i32 litaC_main__main(litaC_i32 litaC_len,litaC_char** litaC_args);

#line 123 "src/main.lita"
litaC_main__ParseStatus litaC_main__ParseArgs(litaC_i32 litaC_n,litaC_char** litaC_args,litaC_lita__LitaOptions* litaC_options);

#line 47 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__memduplicate(const litaC_void* litaC_p,litaC_usize litaC_len,const litaC_mem__Allocator* litaC_a);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_bool litaC_mem__isPowerOfTwo(litaC_usize litaC_x);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_usize litaC_mem__alignForward(litaC_usize litaC_ptr,litaC_usize litaC_align);
LITAC_INLINE 

#line 131 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__Allocator_alloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_size);
LITAC_INLINE 

#line 136 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__Allocator_calloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_num,litaC_usize litaC_size);
LITAC_INLINE 

#line 141 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__Allocator_realloc(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr,litaC_usize litaC_oldsize,litaC_usize litaC_newsize);
LITAC_INLINE 

#line 146 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__Allocator_free(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr);

#line 198 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__cMalloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_size);

#line 202 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__cCalloc(const litaC_mem__Allocator* litaC_a,litaC_usize litaC_num,litaC_usize litaC_size);

#line 206 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__cRealloc(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr,litaC_usize litaC_oldSize,litaC_usize litaC_size);

#line 210 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__cFree(const litaC_mem__Allocator* litaC_a,litaC_void* litaC_ptr);

#line 334 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__DebugAllocator_init(litaC_mem__DebugAllocator* litaC_d,const litaC_mem__Allocator* litaC_alloc);

#line 347 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__DebugAllocator_free(litaC_mem__DebugAllocator* litaC_d);

#line 351 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__DebugAllocator_report(litaC_mem__DebugAllocator* litaC_d);

#line 365 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__DebugAllocator_malloc(litaC_mem__DebugAllocator* litaC_d,litaC_usize litaC_size,const litaC_char* litaC_file,litaC_u64 litaC_line);

#line 432 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__DebugMalloc(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_size);

#line 437 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__DebugCalloc(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_num,litaC_usize litaC_size);

#line 447 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__DebugRealloc(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr,litaC_usize litaC_oldSize,litaC_usize litaC_size);

#line 467 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void litaC_mem__DebugFree(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr);

#line 20 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_void litaC_linear_allocator__LinearAllocator_init(litaC_linear_allocator__LinearAllocator* litaC_this,litaC_void* litaC_mem,litaC_usize litaC_size);


#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_void litaC_linear_allocator__LinearAllocator_clear(litaC_linear_allocator__LinearAllocator* litaC_this);

#line 44 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_void* litaC_linear_allocator__LinearAllocator_malloc(litaC_linear_allocator__LinearAllocator* litaC_this,litaC_usize litaC_size);

#line 110 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_void* litaC_linear_allocator__LinearMalloc(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_size);

#line 116 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_void* litaC_linear_allocator__LinearCalloc(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_num,litaC_usize litaC_size);

#line 128 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_void* litaC_linear_allocator__LinearRealloc(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr,litaC_usize litaC_oldSize,litaC_usize litaC_size);

#line 148 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_void litaC_linear_allocator__LinearFree(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr);

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/io.lita"
litaC_i64 litaC_io__FileLength(const litaC_char* litaC_fileName);

#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/io.lita"
litaC_io__FileStatus litaC_io__ReadFile(const litaC_char* litaC_fileName,litaC_char** litaC_data,const litaC_mem__Allocator* litaC_alloc);

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/io.lita"
litaC_io__FileStatus litaC_io__WriteFile(const litaC_char* litaC_fileName,const litaC_char* litaC_buffer,litaC_usize litaC_len);

#line 71 "C:/Users/antho/git/litac-lang/stdlib/std/io.lita"
litaC_io__FileStatus litaC_io__WriteBytes(FILE* litaC_fp,const litaC_char* litaC_buffer,litaC_usize litaC_len);

#line 41 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_cmdline__CmdParser litaC_cmdline__CmdParserInit(const litaC_mem__Allocator* litaC_allocator);

#line 48 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_void litaC_cmdline__CmdParser_init(litaC_cmdline__CmdParser* litaC_p,const litaC_mem__Allocator* litaC_allocator);

#line 54 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_void litaC_cmdline__CmdParser_free(litaC_cmdline__CmdParser* litaC_p);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_void litaC_cmdline__CmdParser_addOption(litaC_cmdline__CmdParser* litaC_p,const litaC_char* litaC_longName,litaC_char litaC_shortName,const litaC_char* litaC_description,litaC_i32 litaC_flags,const litaC_char* litaC_defaultValue);

#line 75 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_cmdline__Option* litaC_cmdline__CmdParser_getOption(litaC_cmdline__CmdParser* litaC_p,const litaC_char* litaC_longName);

#line 86 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_cmdline__Option* litaC_cmdline__CmdParser_getOptionShort(litaC_cmdline__CmdParser* litaC_p,litaC_char litaC_shortName);

#line 97 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_bool litaC_cmdline__CmdParser_hasOption(litaC_cmdline__CmdParser* litaC_p,const litaC_char* litaC_longName);

#line 106 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_bool litaC_cmdline__CmdParser_hasOptionShort(litaC_cmdline__CmdParser* litaC_p,litaC_char litaC_shortName);

#line 115 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_cmdline__CmdParserStatus litaC_cmdline__CmdParser_parse(litaC_cmdline__CmdParser* litaC_p,litaC_i32 litaC_argc,litaC_char** litaC_argv);

#line 149 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_void litaC_cmdline__CmdParser_printHelp(litaC_cmdline__CmdParser* litaC_p,litaC_string_buffer__StringBuffer* litaC_sb);

#line 29 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_string_buffer__StringBuffer litaC_string_buffer__StringBufferInit(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_init(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 51 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_free(litaC_string_buffer__StringBuffer* litaC_b);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_appendStr(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str);

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_appendStrn(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 85 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendFloat(litaC_string_buffer__StringBuffer* litaC_b,litaC_f64 litaC_f);

#line 89 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendI32(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_i);

#line 93 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendI64(litaC_string_buffer__StringBuffer* litaC_b,litaC_i64 litaC_i);

#line 97 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendU32(litaC_string_buffer__StringBuffer* litaC_b,litaC_u32 litaC_i);

#line 101 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendU64(litaC_string_buffer__StringBuffer* litaC_b,litaC_u64 litaC_i);

#line 105 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendChar(litaC_string_buffer__StringBuffer* litaC_b,litaC_char litaC_c);

#line 116 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_append(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_format,...);

#line 162 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_appendArgs(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_format,va_list litaC_args);

#line 221 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_void litaC_string_buffer__StringBuffer_delete(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_start,litaC_i32 litaC_end);

#line 246 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_bool litaC_string_buffer__StringBuffer_contains(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_indexOf(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 254 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_indexOfAt(litaC_string_buffer__StringBuffer* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len,litaC_i32 litaC_fromIndex);

#line 259 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_replace(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_start,litaC_i32 litaC_end,const litaC_char* litaC_str);

#line 264 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 litaC_string_buffer__StringBuffer_insert(litaC_string_buffer__StringBuffer* litaC_b,litaC_i32 litaC_index,const litaC_char* litaC_format,...);

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

#line 13 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_string__String litaC_string__StringInit(litaC_char* litaC_str,litaC_i32 litaC_capacity,litaC_i32 litaC_len);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_i32 litaC_string__String_format(litaC_string__String* litaC_s,const litaC_char* litaC_format,...);

#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_i32 litaC_string__String_append(litaC_string__String* litaC_s,const litaC_char* litaC_format,...);

#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_appendStr(litaC_string__String* litaC_b,const litaC_char* litaC_str);

#line 82 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_appendStrn(litaC_string__String* litaC_b,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 98 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_setStrn(litaC_string__String* litaC_s,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 113 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_appendChar(litaC_string__String* litaC_s,litaC_char litaC_c);

#line 122 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_string_view__StringView litaC_string__String_substring(litaC_string__String litaC_s,litaC_i32 litaC_start,litaC_i32 litaC_end);

#line 137 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_string_view__StringView litaC_string__String_asView(litaC_string__String litaC_s);

#line 144 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_memset(litaC_string__String litaC_s,litaC_i32 litaC_value);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_toLower(litaC_string__String litaC_s);

#line 157 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_toUpper(litaC_string__String litaC_s);

#line 163 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_string__String litaC_string__String_copy(litaC_string__String litaC_s,const litaC_mem__Allocator* litaC_allocator);

#line 184 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_adjust(litaC_string__String* litaC_s);

#line 188 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_void litaC_string__String_clear(litaC_string__String* litaC_s);

#line 193 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_bool litaC_string__String_empty(litaC_string__String litaC_s);

#line 197 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_i32 litaC_string__String_size(litaC_string__String litaC_s);

#line 201 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_char* litaC_string__String_cStr(litaC_string__String litaC_s);

#line 206 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
const litaC_char* litaC_string__String_cStrConst(litaC_string__String litaC_s);

#line 211 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_char* litaC_string__StringCopy(const litaC_char* litaC_original,litaC_i32 litaC_len,const litaC_mem__Allocator* litaC_allocator);

#line 121 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
const litaC_char* litaC_system__OSAsStr(Lita_OSType litaC_type);



#line 177 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_bool litaC_system__SystemInit();

#line 181 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
Lita_OSType litaC_system__GetOS();

#line 185 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_char* litaC_system__GetEnv(const litaC_char* litaC_varName);

#line 189 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
const litaC_char* litaC_system__CurrentWorkingPath();

#line 193 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_bool litaC_system__FileExists(const litaC_char* litaC_filename);

#line 198 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_bool litaC_system__Mkdir(const litaC_char* litaC_dir);

#line 202 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_char* litaC_system__FilePath(const litaC_char* litaC_filename,litaC_char* litaC_out);

#line 227 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_char* litaC_system__PathNormalize(const litaC_char* litaC_filename,litaC_char* litaC_out);

#line 249 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_i32 litaC_system__strcicmp(const litaC_char* litaC_a,const litaC_char* litaC_b);

#line 272 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_char* litaC_system__GetAbsolutePath(const litaC_char* litaC_pwd,const litaC_char* litaC_path,litaC_char* litaC_output);

#line 330 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_bool litaC_system__PathEquals(const litaC_char* litaC_a,const litaC_char* litaC_b);

#line 358 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_char* litaC_system__FilePathToUri(const litaC_char* litaC_path,litaC_char* litaC_output);

#line 377 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_char* litaC_system__UriToFilePath(const litaC_char* litaC_uri,litaC_char* litaC_output);


#line 496 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_f64 litaC_system__SystemTimeMSec();

#line 516 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
const litaC_char* litaC_system__CurrentDateTime();

#line 527 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_system__Process litaC_system__SystemExec(const litaC_char* litaC_command);

#line 539 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_i64 litaC_system__Process_readOutput(litaC_system__Process* litaC_this,litaC_char* litaC_buffer,litaC_usize litaC_length);

#line 547 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_u64 litaC_system__Process_writeInput(litaC_system__Process* litaC_this,litaC_char* litaC_buffer,litaC_usize litaC_length);

#line 555 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
litaC_void litaC_system__Process_close(litaC_system__Process* litaC_this);

LITAC_INLINE 

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/system/system_win.lita"
litaC_bool litaC_system_win___SystemInit();
LITAC_INLINE 

#line 82 "C:/Users/antho/git/litac-lang/stdlib/std/system/system_win.lita"
const litaC_char* litaC_system_win___CurrentWorkingPath();
LITAC_INLINE 

#line 94 "C:/Users/antho/git/litac-lang/stdlib/std/system/system_win.lita"
litaC_bool litaC_system_win___Mkdir(const litaC_char* litaC_dir);
LITAC_INLINE 


#line 111 "C:/Users/antho/git/litac-lang/stdlib/std/system/system_win.lita"
litaC_f64 litaC_system_win___SystemTimeMSec();

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 litaC_map__StrHashFn(const litaC_char* litaC_str);

#line 30 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__StrEqualFn(const litaC_char* litaC_a,const litaC_char* litaC_b);

#line 317 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 litaC_map__nextPowerOf2(litaC_u32 litaC_n);


#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
litaC_void litaC_profile__StartWatch(litaC_profile__ProfileTag litaC_tag);


#line 33 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
litaC_void litaC_profile__StopWatch(litaC_profile__ProfileTag litaC_tag);


#line 40 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
litaC_void litaC_profile__ExportTimings(const litaC_char* litaC_filename);

#line 458 "src/lex.lita"
litaC_bool litaC_lex__Token_nameEquals(litaC_lex__Token* litaC_token,const litaC_char* litaC_str);

#line 466 "src/lex.lita"
litaC_i32 litaC_lex__SrcPos_getLineLength(litaC_lex__SrcPos* litaC_p);


#line 485 "src/lex.lita"
const litaC_char* litaC_lex__Token_asString(litaC_lex__Token* litaC_t);

#line 495 "src/lex.lita"
litaC_void litaC_lex__Token_print(litaC_lex__Token* litaC_token);

#line 529 "src/lex.lita"
litaC_lex__Lexer litaC_lex__LexerInit(const litaC_char* litaC_filename,const litaC_char* litaC_text,const litaC_mem__Allocator* litaC_allocator,litaC_intern__Strings* litaC_strings);

#line 553 "src/lex.lita"
litaC_bool litaC_lex__Lexer_hasError(litaC_lex__Lexer* litaC_l);

#line 557 "src/lex.lita"
litaC_void litaC_lex__Lexer_error(litaC_lex__Lexer* litaC_l,const litaC_char* litaC_format,...);

#line 569 "src/lex.lita"
litaC_i32 litaC_lex__Lexer_nextChar(litaC_lex__Lexer* litaC_l);

#line 601 "src/lex.lita"
litaC_lex__Token litaC_lex__Lexer_eofToken(litaC_lex__Lexer* litaC_l);

#line 609 "src/lex.lita"
litaC_lex__Token litaC_lex__Lexer_errorToken(litaC_lex__Lexer* litaC_l);

#line 617 "src/lex.lita"
litaC_void litaC_lex__Lexer_skipWhitespace(litaC_lex__Lexer* litaC_l);

#line 623 "src/lex.lita"
litaC_void litaC_lex__Lexer_skipComments(litaC_lex__Lexer* litaC_l);

#line 650 "src/lex.lita"
litaC_bool litaC_lex__Lexer_isValidIdentifierStart(litaC_lex__Lexer* litaC_l,litaC_char litaC_c);

#line 656 "src/lex.lita"
litaC_bool litaC_lex__Lexer_isValidIdentifierChar(litaC_lex__Lexer* litaC_l,litaC_char litaC_c);

#line 662 "src/lex.lita"
litaC_bool litaC_lex__Lexer_isSymbolStart(litaC_lex__Lexer* litaC_l,litaC_char litaC_c);

#line 669 "src/lex.lita"
litaC_bool litaC_lex__Lexer_checkKeyword(litaC_lex__Lexer* litaC_l);

#line 688 "src/lex.lita"
litaC_lex__Token litaC_lex__Lexer_scanWord(litaC_lex__Lexer* litaC_l);

#line 706 "src/lex.lita"
litaC_void litaC_lex__Lexer_scanInt(litaC_lex__Lexer* litaC_l,litaC_char* litaC_stream);

#line 759 "src/lex.lita"
litaC_void litaC_lex__Lexer_scanFloat(litaC_lex__Lexer* litaC_l,litaC_char* litaC_stream);

#line 796 "src/lex.lita"
litaC_void litaC_lex__Lexer_scanTypeInfo(litaC_lex__Lexer* litaC_l);

#line 894 "src/lex.lita"
litaC_bool litaC_lex__IsHex(litaC_i32 litaC_c);

#line 898 "src/lex.lita"
litaC_bool litaC_lex__IsHexChar(litaC_char litaC_c);

#line 908 "src/lex.lita"
litaC_lex__Token litaC_lex__Lexer_scanNumber(litaC_lex__Lexer* litaC_l);

#line 983 "src/lex.lita"
litaC_lex__Token litaC_lex__Lexer_scanChar(litaC_lex__Lexer* litaC_l);

#line 1070 "src/lex.lita"
litaC_bool litaC_lex__Lexer_validateCodepoint(litaC_lex__Lexer* litaC_l,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 1095 "src/lex.lita"
litaC_lex__Token litaC_lex__Lexer_scanString(litaC_lex__Lexer* litaC_l);

#line 1210 "src/lex.lita"
litaC_lex__Token litaC_lex__Lexer_scanSymbol(litaC_lex__Lexer* litaC_l);

#line 1426 "src/lex.lita"
litaC_bool litaC_lex__Lexer_eof(litaC_lex__Lexer* litaC_l);

#line 1431 "src/lex.lita"
litaC_lex__Token litaC_lex__Lexer_nextToken(litaC_lex__Lexer* litaC_l);


#line 28 "C:/Users/antho/git/litac-lang/stdlib/std/unicode/utf8/utf8.lita"
litaC_i32 litaC_utf8__Utf8Decode(const litaC_u8* litaC_str,litaC_i32 litaC_len,litaC_i32* litaC_codepoint);

#line 34 "C:/Users/antho/git/litac-lang/stdlib/std/unicode/utf8/utf8.lita"
litaC_i32 litaC_utf8__Utf8HexDecode(const litaC_char* litaC_str,litaC_i32 litaC_len);


#line 53 "C:/Users/antho/git/litac-lang/stdlib/std/unicode/utf8/utf8.lita"
litaC_i32 litaC_utf8__Utf8Encode(litaC_i32 litaC_codepoint,litaC_u8* litaC_dst);


#line 86 "C:/Users/antho/git/litac-lang/stdlib/std/unicode/utf8/utf8.lita"
litaC_i32 litaC_utf8__Utf8CharWidth(litaC_i32 litaC_codepoint);

#line 136 "C:/Users/antho/git/litac-lang/stdlib/std/unicode/utf8/utf8.lita"
litaC_bool litaC_utf8__Utf8CodepointValid(litaC_i32 litaC_codepoint);

#line 91 "src/types.lita"
litaC_types__TypeKind litaC_types__TypeKindFromString(const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 102 "src/types.lita"
litaC_bool litaC_types__IsPtr(litaC_types__TypeInfo* litaC_type);

#line 115 "src/types.lita"
litaC_bool litaC_types__IsPtrLike(litaC_types__TypeInfo* litaC_type);

#line 136 "src/types.lita"
litaC_bool litaC_types__IsPtrOf(litaC_types__TypeInfo* litaC_type,litaC_types__TypeKind litaC_kind);

#line 164 "src/types.lita"
litaC_bool litaC_types__IsFuncLike(litaC_types__TypeInfo* litaC_type);

#line 180 "src/types.lita"
litaC_bool litaC_types__IsPrimitive(litaC_types__TypeInfo* litaC_type);

#line 188 "src/types.lita"
litaC_bool litaC_types__IsNumberLike(litaC_types__TypeInfo* litaC_type);

#line 224 "src/types.lita"
litaC_bool litaC_types__IsInteger(litaC_types__TypeInfo* litaC_type);

#line 254 "src/types.lita"
litaC_bool litaC_types__IsBooleanable(litaC_types__TypeInfo* litaC_type);

#line 295 "src/types.lita"
litaC_types__FuncPtrTypeInfo* litaC_types__AsTraitFuncPtr(litaC_types__TypeInfo* litaC_type,litaC_intern__InternedString litaC_name,litaC_types_new__TypeCache* litaC_typeCache);

#line 322 "src/types.lita"
litaC_types__AggregateTypeInfo* litaC_types__AsAggregate(litaC_types__TypeInfo* litaC_type);

#line 350 "src/types.lita"
litaC_bool litaC_types__IsAggregateLike(litaC_types__TypeInfo* litaC_type);

#line 354 "src/types.lita"
litaC_bool litaC_types__IsAggregate(litaC_types__TypeInfo* litaC_type);

#line 369 "src/types.lita"
litaC_bool litaC_types__IsPtrAggregate(litaC_types__TypeInfo* litaC_type);

#line 384 "src/types.lita"
litaC_bool litaC_types__IsTrait(litaC_types__TypeInfo* litaC_type);

#line 397 "src/types.lita"
litaC_bool litaC_types__IsPtrTrait(litaC_types__TypeInfo* litaC_type);

#line 413 "src/types.lita"
litaC_bool litaC_types__IsTraitLike(litaC_types__TypeInfo* litaC_type);

#line 417 "src/types.lita"
litaC_bool litaC_types__IsFieldAccessible(litaC_types__TypeInfo* litaC_type);

#line 429 "src/types.lita"
litaC_bool litaC_types__IsGenericCapable(litaC_types__TypeInfo* litaC_type);

#line 446 "src/types.lita"
litaC_types__TypeInfo* litaC_types__TypeInfo_getBaseType(litaC_types__TypeInfo* litaC_this);

#line 473 "src/types.lita"
litaC_types__TypeInfo* litaC_types__TypeInfo_getTypeOf(litaC_types__TypeInfo* litaC_this);

#line 498 "src/types.lita"
const litaC_char* litaC_types__TypeInfo_toStringDebug(litaC_types__TypeInfo* litaC_this);

#line 504 "src/types.lita"
litaC_void litaC_types__TypeInfo_toString(litaC_types__TypeInfo* litaC_this,litaC_string_buffer__StringBuffer* litaC_sb);

#line 611 "src/types.lita"
litaC_bool litaC_types__TypeInfo_strictEquals(litaC_types__TypeInfo* litaC_this,litaC_types__TypeInfo* litaC_other);

#line 688 "src/types.lita"
litaC_bool litaC_types__TypeInfo_isAssignable(litaC_types__TypeInfo* litaC_this,litaC_types__TypeInfo* litaC_other,litaC_checker__TypeChecker* litaC_checker);

#line 873 "src/types.lita"
litaC_bool litaC_types__TypeInfo_isDeclarable(litaC_types__TypeInfo* litaC_this,litaC_types__TypeInfo* litaC_other,litaC_checker__TypeChecker* litaC_checker);

#line 1192 "src/types.lita"
litaC_bool litaC_types__TypeInfo_canCastTo(litaC_types__TypeInfo* litaC_this,litaC_types__TypeInfo* litaC_castTo,litaC_checker__TypeChecker* litaC_checker);

#line 1304 "src/types.lita"
litaC_bool litaC_types__IsFuncImpl(litaC_types__FuncPtrTypeInfo* litaC_traitFn,litaC_types__TypeInfo* litaC_fn,litaC_checker__TypeChecker* litaC_checker);

#line 1349 "src/types.lita"
litaC_ast__TypeSpec* litaC_types__TypeInfo_asTypeSpec(litaC_types__TypeInfo* litaC_this,litaC_lita__Lita* litaC_lita);

#line 1475 "src/types.lita"
litaC_types__FuncPtrTypeInfo* litaC_types__FuncTypeInfo_asPtr(litaC_types__FuncTypeInfo* litaC_this,litaC_types_new__TypeCache* litaC_typeCache);

#line 1490 "src/types.lita"
litaC_ast__EnumFieldEntryDecl* litaC_types__EnumTypeInfo_getField(litaC_types__EnumTypeInfo* litaC_this,litaC_intern__InternedString litaC_name);

#line 1502 "src/types.lita"
litaC_i32 litaC_types__EnumTypeInfo_getFieldIndex(litaC_types__EnumTypeInfo* litaC_this,litaC_intern__InternedString litaC_name);

#line 1515 "src/types.lita"
const litaC_char* litaC_types__AggregateTypeInfo_getBaseName(litaC_types__AggregateTypeInfo* litaC_this,litaC_char* litaC_name);

#line 1541 "src/types.lita"
litaC_ast__FieldStmt litaC_types__AggregateTypeInfo_getFieldByPosition(litaC_types__AggregateTypeInfo* litaC_this,litaC_i32 litaC_position);

#line 1552 "src/types.lita"
litaC_ast__FieldStmt litaC_types__AggregateTypeInfo_getField(litaC_types__AggregateTypeInfo* litaC_this,litaC_intern__InternedString litaC_name);


#line 1617 "src/types.lita"
litaC_i32 litaC_types__AggregateTypeInfo_getFieldIndex(litaC_types__AggregateTypeInfo* litaC_this,litaC_intern__InternedString litaC_name);


#line 1692 "src/types.lita"
litaC_types__FieldPositionResult litaC_types__AggregateTypeInfo_getFieldPosition(litaC_types__AggregateTypeInfo* litaC_this,litaC_intern__InternedString litaC_name);


#line 1727 "src/types.lita"
litaC_ast__FieldStmt litaC_types__AggregateTypeInfo_getFieldByType(litaC_types__AggregateTypeInfo* litaC_this,litaC_types__AggregateTypeInfo* litaC_type,litaC_bool litaC_isParent);

#line 1793 "src/types.lita"
litaC_ast__FieldStmt litaC_types__AggregateTypeInfo_getFieldWithUsing(litaC_types__AggregateTypeInfo* litaC_this,litaC_intern__InternedString litaC_name);

#line 1845 "src/types.lita"
litaC_void litaC_types__FieldPath_add(litaC_types__FieldPath* litaC_this,litaC_ast__FieldStmt litaC_field);

#line 1851 "src/types.lita"
litaC_void litaC_types__FieldPath_pop(litaC_types__FieldPath* litaC_this);

#line 1859 "src/types.lita"
litaC_bool litaC_types__AggregateTypeInfo_getFieldPath(litaC_types__AggregateTypeInfo* litaC_this,litaC_intern__InternedString litaC_name,litaC_types__FieldPath* litaC_path);

#line 1906 "src/types.lita"
litaC_bool litaC_types__AggregateTypeInfo_getFieldPathByType(litaC_types__AggregateTypeInfo* litaC_this,litaC_types__AggregateTypeInfo* litaC_type,litaC_types__FieldPath* litaC_path);


#line 1963 "src/types.lita"
const litaC_char* litaC_types__AggregateTypeInfo_getFunctionName(litaC_types__AggregateTypeInfo* litaC_this,litaC_char* litaC_result,litaC_intern__InternedString litaC_methodName);

#line 1973 "src/types.lita"
litaC_symbols__Symbol* litaC_types__AggregateTypeInfo_getMethod(litaC_types__AggregateTypeInfo* litaC_this,litaC_intern__Strings* litaC_strings,litaC_module__Module* litaC_module,litaC_intern__InternedString litaC_methodName);

#line 2026 "src/types.lita"
litaC_bool litaC_types__AggregateTypeInfo_implementsTrait(litaC_types__AggregateTypeInfo* litaC_this,litaC_types__TypeInfo* litaC_iface,litaC_checker__TypeChecker* litaC_checker);

#line 2045 "src/types.lita"
litaC_i64 litaC_types__NextTypeId();


#line 2053 "src/types.lita"
litaC_void litaC_types__TypesInit(litaC_intern__Strings* litaC_strings);

#line 14 "src/ast_new.lita"
litaC_ast__TypeSpec* litaC_ast_new__NewVoidTypeSpec(litaC_lex__SrcPos litaC_pos,litaC_lita__Lita* litaC_lita);

#line 20 "src/ast_new.lita"
litaC_ast__NameTypeSpec* litaC_ast_new__NewNameTypeSpecIntern(litaC_lex__SrcPos litaC_pos,litaC_intern__InternedString litaC_name,litaC_lita__Lita* litaC_lita);

#line 30 "src/ast_new.lita"
litaC_ast__NameTypeSpec* litaC_ast_new__NewNameTypeSpec(litaC_lex__SrcPos litaC_pos,const litaC_char* litaC_name,litaC_lita__Lita* litaC_lita);

#line 34 "src/ast_new.lita"
litaC_ast__TypeSpec* litaC_ast_new__NewTypeSpec(litaC_ast__TypeSpecKind litaC_kind,litaC_lex__SrcPos litaC_pos,litaC_lita__Lita* litaC_lita);

#line 93 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewImportDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_lex__Token litaC_alias,litaC_bool litaC_isUsing,const litaC_mem__Allocator* litaC_allocator);

#line 110 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewVarDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_ast__TypeSpec* litaC_type,litaC_ast__Expr* litaC_expr,const litaC_mem__Allocator* litaC_allocator);

#line 127 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewFuncDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_array__Array_cb_GenericParam_ce_ litaC_genericParams,litaC_ast__ParametersStmt* litaC_params,litaC_ast__Stmt* litaC_body,litaC_ast__TypeSpec* litaC_returnType,litaC_i32 litaC_flags,const litaC_mem__Allocator* litaC_allocator);

#line 150 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewAggregateDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__StmtKind litaC_kind,litaC_lex__Token litaC_name,litaC_array__Array_cb_GenericParam_ce_ litaC_genericParams,litaC_array__Array_cb_FieldStmt_ce_ litaC_fields,litaC_i32 litaC_flags,const litaC_mem__Allocator* litaC_allocator);

#line 200 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewStructDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_array__Array_cb_GenericParam_ce_ litaC_genericParams,litaC_array__Array_cb_FieldStmt_ce_ litaC_fields,litaC_i32 litaC_flags,const litaC_mem__Allocator* litaC_allocator);

#line 211 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewUnionDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_array__Array_cb_GenericParam_ce_ litaC_genericParams,litaC_array__Array_cb_FieldStmt_ce_ litaC_fields,litaC_i32 litaC_flags,const litaC_mem__Allocator* litaC_allocator);

#line 223 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewTraitDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_array__Array_cb_GenericParam_ce_ litaC_genericParams,litaC_array__Array_cb_FieldStmt_ce_ litaC_fields,litaC_i32 litaC_flags,const litaC_mem__Allocator* litaC_allocator);

#line 235 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewEnumDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_ litaC_fields,const litaC_mem__Allocator* litaC_allocator);

#line 250 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewTypedefDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_array__Array_cb_GenericParam_ce_ litaC_genericParams,litaC_ast__TypeSpec* litaC_type,const litaC_mem__Allocator* litaC_allocator);

#line 267 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewParameterDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_ast__TypeSpec* litaC_type,litaC_ast__Expr* litaC_defaultExpr,litaC_bool litaC_isUsing,const litaC_mem__Allocator* litaC_allocator);

#line 286 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewNotesDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_array__Array_cb__ptr_NoteStmt_ce_ litaC_notes,const litaC_mem__Allocator* litaC_allocator);

#line 298 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewBuiltinDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_types__TypeInfo* litaC_type,const litaC_mem__Allocator* litaC_allocator);

#line 310 "src/ast_new.lita"
litaC_ast__Decl* litaC_ast_new__NewPoisonDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_mem__Allocator* litaC_allocator);

#line 320 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewTernaryExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_cond,litaC_ast__Expr* litaC_then,litaC_ast__Expr* litaC_other,const litaC_mem__Allocator* litaC_allocator);

#line 337 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewBinaryExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_left,litaC_lex__TokenType litaC_operator,litaC_ast__Expr* litaC_right,const litaC_mem__Allocator* litaC_allocator);

#line 354 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewUnaryExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__TokenType litaC_operator,litaC_ast__Expr* litaC_expr,const litaC_mem__Allocator* litaC_allocator);

#line 369 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewInitExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__NameTypeSpec* litaC_type,litaC_array__Array_cb__ptr_InitArgExpr_ce_ litaC_arguments,const litaC_mem__Allocator* litaC_allocator);

#line 385 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewFuncCallExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_object,litaC_array__Array_cb_CallArg_ce_ litaC_arguments,litaC_array__Array_cb__ptr_TypeSpec_ce_ litaC_genericArgs,const litaC_mem__Allocator* litaC_allocator);

#line 404 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewSubscriptGetExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_object,litaC_ast__Expr* litaC_index,const litaC_mem__Allocator* litaC_allocator);

#line 419 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewSubscriptSetExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_object,litaC_ast__Expr* litaC_index,litaC_lex__TokenType litaC_operator,litaC_ast__Expr* litaC_value,const litaC_mem__Allocator* litaC_allocator);

#line 438 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewGetExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_object,litaC_ast__IdentifierExpr* litaC_field,const litaC_mem__Allocator* litaC_allocator);

#line 453 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewSetExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_object,litaC_ast__IdentifierExpr* litaC_field,litaC_lex__TokenType litaC_operator,litaC_ast__Expr* litaC_value,const litaC_mem__Allocator* litaC_allocator);

#line 472 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewIdentifierExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__NameTypeSpec* litaC_type,const litaC_mem__Allocator* litaC_allocator);

#line 485 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewTypeIdentifierExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__TypeSpec* litaC_type,const litaC_mem__Allocator* litaC_allocator);

#line 498 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewCastExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_castExpr,litaC_ast__TypeSpec* litaC_castTo,const litaC_mem__Allocator* litaC_allocator);

#line 513 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewArrayDesignationExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_index,litaC_ast__Expr* litaC_value,const litaC_mem__Allocator* litaC_allocator);

#line 528 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewInitArgExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_fieldName,litaC_i32 litaC_position,litaC_ast__Expr* litaC_value,const litaC_mem__Allocator* litaC_allocator);

#line 545 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewBooleanExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_bool litaC_boolean,const litaC_mem__Allocator* litaC_allocator);

#line 557 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewNullExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_mem__Allocator* litaC_allocator);

#line 567 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewNumberExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_number,const litaC_mem__Allocator* litaC_allocator);

#line 579 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewStringExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_string,const litaC_mem__Allocator* litaC_allocator);

#line 592 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewCharExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_character,const litaC_mem__Allocator* litaC_allocator);

#line 604 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewGroupExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_groupedExpr,const litaC_mem__Allocator* litaC_allocator);

#line 617 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewArrayInitExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__TypeSpec* litaC_type,litaC_array__Array_cb__ptr_Expr_ce_ litaC_values,const litaC_mem__Allocator* litaC_allocator);

#line 649 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewSizeOfExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_sizeOfExpr,const litaC_mem__Allocator* litaC_allocator);

#line 663 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewTypeOfExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_typeOfExpr,litaC_ast__TypeSpec* litaC_type,const litaC_mem__Allocator* litaC_allocator);

#line 678 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewOffsetOfExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__TypeSpec* litaC_type,litaC_lex__Token litaC_field,const litaC_mem__Allocator* litaC_allocator);

#line 693 "src/ast_new.lita"
litaC_ast__Expr* litaC_ast_new__NewPoisonExpr(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_mem__Allocator* litaC_allocator);

#line 703 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewModuleStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_array__Array_cb__ptr_ImportDecl_ce_ litaC_imports,litaC_array__Array_cb__ptr_NoteStmt_ce_ litaC_notes,litaC_array__Array_cb__ptr_Decl_ce_ litaC_declarations,const litaC_mem__Allocator* litaC_allocator);

#line 719 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewCompStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_char* litaC_type,const litaC_char* litaC_expr,litaC_array__Array_cb__ptr_Stmt_ce_ litaC_body,litaC_ast__CompStmt* litaC_end,const litaC_mem__Allocator* litaC_allocator);

#line 738 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewFuncBodyStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_array__Array_cb__ptr_Stmt_ce_ litaC_stmts,const litaC_mem__Allocator* litaC_allocator);

#line 751 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewBlockStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_array__Array_cb__ptr_Stmt_ce_ litaC_stmts,const litaC_mem__Allocator* litaC_allocator);

#line 763 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewIfStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_cond,litaC_ast__Stmt* litaC_then,litaC_ast__Stmt* litaC_other,const litaC_mem__Allocator* litaC_allocator);

#line 780 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewWhileStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_cond,litaC_ast__Stmt* litaC_body,const litaC_mem__Allocator* litaC_allocator);

#line 794 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewDoWhileStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_cond,litaC_ast__Stmt* litaC_body,const litaC_mem__Allocator* litaC_allocator);

#line 808 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewForStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Stmt* litaC_init,litaC_ast__Expr* litaC_cond,litaC_ast__Stmt* litaC_post,litaC_ast__Stmt* litaC_body,const litaC_mem__Allocator* litaC_allocator);

#line 826 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewSwitchCaseStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_cond,litaC_ast__Stmt* litaC_body,const litaC_mem__Allocator* litaC_allocator);

#line 840 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewSwitchStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_cond,litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_ litaC_cases,litaC_ast__Stmt* litaC_defaultStmt,const litaC_mem__Allocator* litaC_allocator);

#line 856 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewBreakStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_mem__Allocator* litaC_allocator);

#line 866 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewContinueStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_mem__Allocator* litaC_allocator);

#line 876 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewReturnStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Expr* litaC_expr,const litaC_mem__Allocator* litaC_allocator);

#line 888 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewDeferStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_ast__Stmt* litaC_defered,const litaC_mem__Allocator* litaC_allocator);

#line 900 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewGotoStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_label,const litaC_mem__Allocator* litaC_allocator);

#line 912 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewLabelStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_label,const litaC_mem__Allocator* litaC_allocator);

#line 924 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewNoteStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_name,litaC_array__Array_cb_Token_ce_ litaC_attributes,const litaC_mem__Allocator* litaC_allocator);

#line 938 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewEmptyStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_mem__Allocator* litaC_allocator);

#line 948 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewParametersStmt(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_array__Array_cb__ptr_ParameterDecl_ce_ litaC_params,litaC_bool litaC_isVararg,const litaC_mem__Allocator* litaC_allocator);

#line 963 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewVarFieldDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_fieldName,litaC_ast__TypeSpec* litaC_type,litaC_ast__Attributes litaC_attributes,litaC_ast__Expr* litaC_defaultExpr,const litaC_mem__Allocator* litaC_allocator);

#line 981 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewTraitFieldDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_fieldName,litaC_ast__TypeSpec* litaC_type,litaC_ast__Attributes litaC_attributes,const litaC_mem__Allocator* litaC_allocator);

#line 998 "src/ast_new.lita"
litaC_ast__Stmt* litaC_ast_new__NewEnumFieldEntryDecl(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,litaC_lex__Token litaC_fieldName,litaC_ast__Expr* litaC_value,litaC_ast__Attributes litaC_attributes,const litaC_mem__Allocator* litaC_allocator);

#line 164 "src/ast.lita"
litaC_void litaC_ast__Node_setSrcPos(litaC_ast__Node* litaC_n,litaC_lex__SrcPos litaC_start,litaC_lex__SrcPos litaC_end);

#line 188 "src/ast.lita"
litaC_array__Array_cb_CallArg_ce_* litaC_ast__Node_becomeParentOfChildrenCallArgs(litaC_ast__Node* litaC_n,litaC_array__Array_cb_CallArg_ce_* litaC_children);

#line 599 "src/ast.lita"
litaC_bool litaC_ast__IsExpr(litaC_ast__Node* litaC_node);

#line 635 "src/ast.lita"
litaC_bool litaC_ast__IsDecl(litaC_ast__Node* litaC_node);

#line 657 "src/ast.lita"
litaC_bool litaC_ast__Decl_hasNote(litaC_ast__Decl* litaC_d,const litaC_char* litaC_name);

#line 662 "src/ast.lita"
litaC_ast__NoteStmt* litaC_ast__Decl_getNote(litaC_ast__Decl* litaC_d,const litaC_char* litaC_name);

#line 678 "src/ast.lita"
litaC_ast__TypeSpec* litaC_ast__TypeSpec_getBaseType(litaC_ast__TypeSpec* litaC_this);

#line 704 "src/ast.lita"
litaC_bool litaC_ast__FuncDecl_getName(litaC_ast__FuncDecl* litaC_f,litaC_char* litaC_name);

#line 751 "src/ast.lita"
litaC_bool litaC_ast__Expr_isIdentifier(litaC_ast__Expr* litaC_expr);

#line 762 "src/ast.lita"
litaC_bool litaC_ast__Expr_isConstNumberExpr(litaC_ast__Expr* litaC_expr);

#line 799 "src/ast.lita"
litaC_bool litaC_ast__Expr_isConstExpr(litaC_ast__Expr* litaC_expr);

#line 837 "src/ast.lita"
litaC_i32 litaC_ast__CallArgSort(litaC_ast__CallArg litaC_a,litaC_ast__CallArg litaC_b);

#line 74 "src/symbols.lita"
litaC_bool litaC_symbols__Symbol_isGenericCapable(litaC_symbols__Symbol* litaC_this);

#line 103 "src/symbols.lita"
litaC_symbols__Scope* litaC_symbols__NewScope(litaC_symbols__ScopeKind litaC_kind,litaC_symbols__Scope* litaC_parent,litaC_phase_result__PhaseResult* litaC_result,const litaC_mem__Allocator* litaC_allocator);

#line 109 "src/symbols.lita"
litaC_void litaC_symbols__Scope_init(litaC_symbols__Scope* litaC_scope,litaC_symbols__ScopeKind litaC_kind,litaC_symbols__Scope* litaC_parent,litaC_phase_result__PhaseResult* litaC_result,const litaC_mem__Allocator* litaC_allocator);

#line 132 "src/symbols.lita"
litaC_symbols__Symbol* litaC_symbols__Scope_lookup(litaC_symbols__Scope* litaC_s,litaC_intern__InternedString litaC_name);

#line 145 "src/symbols.lita"
litaC_symbols__Symbol* litaC_symbols__Scope_lookupByToken(litaC_symbols__Scope* litaC_s,litaC_lex__Token litaC_name);

#line 153 "src/symbols.lita"
litaC_void litaC_symbols__Scope_importSymbol(litaC_symbols__Scope* litaC_this,litaC_intern__InternedString litaC_name,litaC_symbols__Symbol* litaC_symbol);

#line 167 "src/symbols.lita"
litaC_symbols__Symbol* litaC_symbols__Scope_addSymbol(litaC_symbols__Scope* litaC_this,litaC_intern__InternedString litaC_name,litaC_module__Module* litaC_module,litaC_ast__Decl* litaC_decl,litaC_i32 litaC_flags);

#line 262 "src/symbols.lita"
litaC_void litaC_symbols__Scope_print(litaC_symbols__Scope* litaC_this,const litaC_char* litaC_header);

#line 59 "src/module.lita"
litaC_module__Module* litaC_module__BuiltinsInit(litaC_lita__Lita* litaC_lita);

#line 93 "src/module.lita"
litaC_void litaC_module__AddBuiltin(litaC_lita__Lita* litaC_lita,litaC_types__TypeInfo* litaC_type);

#line 104 "src/module.lita"
litaC_module__Module* litaC_module__NewModule(litaC_lita__Lita* litaC_lita,const litaC_char* litaC_filename);

#line 113 "src/module.lita"
litaC_void litaC_module__Module_init(litaC_module__Module* litaC_this,litaC_lita__Lita* litaC_lita);

#line 127 "src/module.lita"
litaC_symbols__Symbol* litaC_module__Module_getType(litaC_module__Module* litaC_this,litaC_intern__InternedString litaC_type);

#line 138 "src/module.lita"
litaC_bool litaC_module__Module_isMethodForType(litaC_module__Module* litaC_this,litaC_types__TypeInfo* litaC_type,litaC_symbols__Symbol* litaC_sym);

#line 176 "src/module.lita"
litaC_i32 litaC_module__Module_getMethodsForType(litaC_module__Module* litaC_this,litaC_types__TypeInfo* litaC_type,litaC_symbols__Symbol** litaC_result);

#line 212 "src/module.lita"
litaC_void litaC_module__Module_importModule(litaC_module__Module* litaC_this,litaC_ast__ImportDecl* litaC_importDecl,litaC_module__Module* litaC_moduleToImport);

#line 223 "src/module.lita"
litaC_void litaC_module__Module_importModuleSymbols(litaC_module__Module* litaC_this,litaC_module__Module* litaC_moduleToImport,litaC_intern__InternedString* litaC_moduleName,litaC_bool litaC_isUsing);

#line 237 "src/module.lita"
litaC_void litaC_module__Module_importModuleSymbol(litaC_module__Module* litaC_this,litaC_module__Module* litaC_moduleToImport,litaC_intern__InternedString* litaC_moduleName,litaC_symbols__Symbol* litaC_symbol,litaC_intern__InternedString litaC_symName,litaC_bool litaC_isUsing);
LITAC_INLINE 

#line 279 "src/module.lita"
litaC_bool litaC_module__Module_equals(litaC_module__Module* litaC_this,litaC_module__Module* litaC_other);

#line 288 "src/module.lita"
litaC_void litaC_module__Module_print(litaC_module__Module* litaC_this,const litaC_char* litaC_header);

#line 302 "src/module.lita"
litaC_void litaC_module__ModuleId_fromFile(litaC_module__ModuleId* litaC_moduleId,litaC_lita__Lita* litaC_lita,const litaC_char* litaC_filename);

#line 312 "src/module.lita"
litaC_string_view__StringView litaC_module__GetModuleName(litaC_string_view__StringView litaC_pathStr);

#line 27 "src/phase_result.lita"
litaC_phase_result__PhaseResult litaC_phase_result__PhaseResultInit(const litaC_mem__Allocator* litaC_allocator);

#line 38 "src/phase_result.lita"
litaC_void litaC_phase_result__PhaseResult_addError(litaC_phase_result__PhaseResult* litaC_r,litaC_lex__SrcPos litaC_pos,const litaC_char* litaC_format,...);

#line 48 "src/phase_result.lita"
litaC_void litaC_phase_result__PhaseResult_addErrorStr(litaC_phase_result__PhaseResult* litaC_r,litaC_lex__SrcPos litaC_pos,litaC_string_buffer__StringBuffer* litaC_sb);

#line 60 "src/phase_result.lita"
litaC_bool litaC_phase_result__PhaseResult_hasErrors(litaC_phase_result__PhaseResult* litaC_r);

#line 15 "src/common.lita"
litaC_void litaC_common__Log(litaC_common__LogLevel litaC_level,const litaC_char* litaC_format,...);

#line 22 "src/common.lita"
litaC_void litaC_common__Logv(litaC_common__LogLevel litaC_level,const litaC_char* litaC_format,va_list litaC_args);

#line 47 "src/common.lita"
litaC_void litaC_common__Info(const litaC_char* litaC_format,...);

#line 54 "src/common.lita"
litaC_void litaC_common__Debug(const litaC_char* litaC_format,...);

#line 61 "src/common.lita"
litaC_void litaC_common__Error(const litaC_char* litaC_format,...);

#line 68 "src/common.lita"
litaC_void litaC_common__Panic(const litaC_char* litaC_format,...);

#line 76 "src/common.lita"
litaC_char* litaC_common__EscapeName(const litaC_char* litaC_name,litaC_i32 litaC_len,litaC_string_buffer__StringBuffer* litaC_sb);

#line 120 "src/lita.lita"
litaC_void litaC_lita__Lita_init(litaC_lita__Lita* litaC_this,litaC_lita__LitaOptions* litaC_options);


#line 134 "src/lita.lita"
litaC_void litaC_lita__Lita_reset(litaC_lita__Lita* litaC_this);

#line 154 "src/lita.lita"
litaC_void litaC_lita__Lita_free(litaC_lita__Lita* litaC_lita);

#line 160 "src/lita.lita"
litaC_void litaC_lita__Lita_addModule(litaC_lita__Lita* litaC_lita,litaC_module__Module* litaC_module);

#line 164 "src/lita.lita"
litaC_void litaC_lita__Lita_startCapture(litaC_lita__Lita* litaC_lita,litaC_lita__MetricType litaC_type);

#line 173 "src/lita.lita"
litaC_void litaC_lita__Lita_endCapture(litaC_lita__Lita* litaC_lita,litaC_lita__MetricType litaC_type);

#line 184 "src/lita.lita"
litaC_module__Module* litaC_lita__Lita_parse(litaC_lita__Lita* litaC_this);

#line 215 "src/lita.lita"
litaC_bool litaC_lita__Lita_typeCheck(litaC_lita__Lita* litaC_this,litaC_module__Module* litaC_module);

#line 227 "src/lita.lita"
litaC_bool litaC_lita__Lita_transpile(litaC_lita__Lita* litaC_this,litaC_module__Module* litaC_module);

#line 278 "src/lita.lita"
litaC_void litaC_lita__LibtccErrorFunc(litaC_void* litaC_data,const litaC_char* litaC_msg);

#line 282 "src/lita.lita"
litaC_bool litaC_lita__Lita_compileWithLibtcc(litaC_lita__Lita* litaC_this,litaC_module__Module* litaC_module,const litaC_char* litaC_binaryFilename);

#line 308 "src/lita.lita"
litaC_bool litaC_lita__Lita_emitC(litaC_lita__Lita* litaC_this,litaC_module__Module* litaC_module,const litaC_char* litaC_cFilename);

#line 324 "src/lita.lita"
litaC_bool litaC_lita__Lita_compileC(litaC_lita__Lita* litaC_this,litaC_module__Module* litaC_module,const litaC_char* litaC_sourceFilename,const litaC_char* litaC_binaryFilename);

#line 350 "src/lita.lita"
litaC_void litaC_lita__Lita_run(litaC_lita__Lita* litaC_this);

#line 367 "src/lita.lita"
litaC_bool litaC_lita__FindModulePath(litaC_lita__Lita* litaC_lita,litaC_string_view__StringView litaC_moduleName,litaC_char* litaC_filename);

#line 421 "src/lita.lita"
litaC_bool litaC_lita__ParseModule(litaC_lita__Lita* litaC_lita,litaC_module__Module* litaC_module,litaC_lex__SrcPos litaC_pos);

#line 33 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_void litaC_bucket_allocator__BucketAllocator_init(litaC_bucket_allocator__BucketAllocator* litaC_this,const litaC_mem__Allocator* litaC_decorated,litaC_usize litaC_bucketSize);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_void litaC_bucket_allocator__BucketAllocator_clear(litaC_bucket_allocator__BucketAllocator* litaC_this);


#line 80 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_void litaC_bucket_allocator__BucketAllocator_free(litaC_bucket_allocator__BucketAllocator* litaC_this);

#line 97 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_void* litaC_bucket_allocator__BucketAllocator_malloc(litaC_bucket_allocator__BucketAllocator* litaC_this,litaC_usize litaC_size);

#line 145 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_void litaC_bucket_allocator__BucketFree(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr);

#line 32 "src/preprocessor.lita"
litaC_void litaC_preprocessor__noOpFree(litaC_void* litaC_mem,litaC_void* litaC_freeArg);

#line 37 "src/preprocessor.lita"
litaC_void* litaC_preprocessor__litaMalloc(litaC_u64 litaC_len,litaC_void* litaC_arg);

#line 56 "src/preprocessor.lita"
litaC_preprocessor__Preprocessor litaC_preprocessor__PreprocessorInit(litaC_lita__Lita* litaC_lita);

#line 63 "src/preprocessor.lita"
litaC_void litaC_preprocessor__Preprocessor_init(litaC_preprocessor__Preprocessor* litaC_this,litaC_lita__Lita* litaC_lita);


#line 104 "src/preprocessor.lita"
litaC_bool litaC_preprocessor__Preprocessor_eval(litaC_preprocessor__Preprocessor* litaC_this,litaC_ast__CompStmt* litaC_comp);


#line 130 "src/preprocessor.lita"
litaC_void litaC_preprocessor__Preprocessor_evaluateForModule(litaC_preprocessor__Preprocessor* litaC_this,litaC_ast__ModuleStmt* litaC_moduleStmt,litaC_ast__CompStmt* litaC_comp);


#line 188 "src/preprocessor.lita"
litaC_ast__Stmt* litaC_preprocessor__Preprocessor_evaluateForFunction(litaC_preprocessor__Preprocessor* litaC_this,litaC_checker__TypeChecker* litaC_checker,litaC_ast__CompStmt* litaC_comp);

#line 218 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeGetTypeKind(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 241 "src/preprocessor.lita"
litaC_bool litaC_preprocessor__CallContext_logErrors(litaC_preprocessor__CallContext* litaC_this);

#line 261 "src/preprocessor.lita"
litaC_void litaC_preprocessor__Preprocessor_preResolveSymbols(litaC_preprocessor__Preprocessor* litaC_this,litaC_checker__TypeChecker* litaC_checker);

#line 271 "src/preprocessor.lita"
litaC_void litaC_preprocessor__Preprocessor_addNotes(litaC_preprocessor__Preprocessor* litaC_this,ape_object_t litaC_obj,litaC_ast__Attributes* litaC_attributes);

#line 299 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__Preprocessor_declToApe(litaC_preprocessor__Preprocessor* litaC_this,litaC_symbols__Symbol* litaC_sym);


#line 420 "src/preprocessor.lita"
litaC_void litaC_preprocessor__CallContext_preprocessCall(litaC_preprocessor__CallContext* litaC_this,litaC_ast__ModuleStmt* litaC_moduleStmt,litaC_ast__CompStmt* litaC_comp);

#line 443 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeEmit(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 510 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeEmitClear(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 516 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeEmitStr(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 522 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeGetSymbolsWithNote(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 554 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeAddDeclaration(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 619 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeReplaceDeclaration(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 678 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeGetInputModuleFilename(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 690 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeGetCurrentModuleFilename(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 703 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeGetMainSymbol(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 714 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeAstInsert(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 746 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeAddImport(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 795 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeSetMainSymbol(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 838 "src/preprocessor.lita"
ape_object_t litaC_preprocessor__ApeGetSymbolsToTest(ape_t* litaC_ape,litaC_void* litaC_data,litaC_i32 litaC_argc,ape_object_t* litaC_args);

#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/regex/regex.lita"
litaC_regex__Regex litaC_regex__RegexCompile(const litaC_char* litaC_pattern);

#line 16 "C:/Users/antho/git/litac-lang/stdlib/std/regex/regex.lita"
litaC_i32 litaC_regex__Regex_match(litaC_regex__Regex* litaC_this,const litaC_char* litaC_text,litaC_i32* litaC_matchlength);

#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/regex/regex.lita"
litaC_i32 litaC_regex__RegexMatch(const litaC_char* litaC_pattern,const litaC_char* litaC_text,litaC_i32* litaC_matchlength);

#line 21 "src/ast_copy.lita"
const litaC_char* litaC_ast_copy__NewTokenName(litaC_lex__Token litaC_token,litaC_intern__Strings* litaC_strings);

#line 30 "src/ast_copy.lita"
litaC_intern__InternedString litaC_ast_copy__NewTokenNameIntern(litaC_lex__Token litaC_token,litaC_intern__Strings* litaC_strings);

#line 38 "src/ast_copy.lita"
litaC_array__Array_cb__ptr_TypeSpec_ce_ litaC_ast_copy__CopyTypeSpecs(litaC_array__Array_cb__ptr_TypeSpec_ce_ litaC_specs,litaC_lita__Lita* litaC_lita);

#line 56 "src/ast_copy.lita"
litaC_ast__TypeSpec* litaC_ast_copy__CopyTypeSpec(litaC_ast__TypeSpec* litaC_spec,litaC_lita__Lita* litaC_lita);

#line 108 "src/ast_copy.lita"
litaC_ast__Decl* litaC_ast_copy__CopyDecl(litaC_ast__Decl* litaC_decl,litaC_lita__Lita* litaC_lita);

#line 164 "src/ast_copy.lita"
litaC_array__Array_cb_CallArg_ce_ litaC_ast_copy__CopyCallArgs(litaC_array__Array_cb_CallArg_ce_* litaC_args,litaC_lita__Lita* litaC_lita);

#line 181 "src/ast_copy.lita"
litaC_array__Array_cb__ptr_Expr_ce_ litaC_ast_copy__CopyExprs(litaC_array__Array_cb__ptr_Expr_ce_* litaC_exprs,litaC_lita__Lita* litaC_lita);

#line 194 "src/ast_copy.lita"
litaC_array__Array_cb__ptr_Stmt_ce_ litaC_ast_copy__CopyStmts(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_stmts,litaC_lita__Lita* litaC_lita);

#line 208 "src/ast_copy.lita"
litaC_ast__Expr* litaC_ast_copy__CopyExpr(litaC_ast__Expr* litaC_expr,litaC_lita__Lita* litaC_lita);

#line 431 "src/ast_copy.lita"
litaC_ast__Stmt* litaC_ast_copy__CopyStmt(litaC_ast__Stmt* litaC_stmt,litaC_lita__Lita* litaC_lita);

#line 613 "src/ast_copy.lita"
litaC_ast__AggregateDecl* litaC_ast_copy__CopyAggregateDecl(litaC_ast__AggregateDecl* litaC_decl,litaC_lita__Lita* litaC_lita);

#line 696 "src/ast_copy.lita"
litaC_ast__FuncDecl* litaC_ast_copy__CopyFuncDecl(litaC_ast__FuncDecl* litaC_decl,litaC_lita__Lita* litaC_lita);

#line 710 "src/ast_copy.lita"
litaC_ast__ParametersStmt* litaC_ast_copy__CopyParameters(litaC_ast__ParametersStmt litaC_params,litaC_lita__Lita* litaC_lita);

#line 736 "src/ast_copy.lita"
litaC_ast__TypedefDecl* litaC_ast_copy__CopyTypedefDecl(litaC_ast__TypedefDecl* litaC_decl,litaC_lita__Lita* litaC_lita);

#line 747 "src/ast_copy.lita"
litaC_void litaC_ast_copy__AstInsertText(litaC_ast__Node* litaC_node,const litaC_char* litaC_text,litaC_i32 litaC_index,litaC_lita__Lita* litaC_lita);


#line 760 "src/ast_copy.lita"
litaC_void litaC_ast_copy__AstInsert(litaC_ast__Node* litaC_node,litaC_ast__Stmt* litaC_stmt,litaC_i32 litaC_index,litaC_lita__Lita* litaC_lita);

#line 803 "src/ast_copy.lita"
const litaC_char* litaC_ast_copy__AstAddImport(litaC_lita__Lita* litaC_lita,litaC_checker__TypeChecker* litaC_checker,litaC_module__Module* litaC_module,litaC_module__Module* litaC_importModule);

#line 77 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_init(litaC_checker__TypeChecker* litaC_this,litaC_lita__Lita* litaC_lita);


#line 102 "src/checker.lita"
litaC_symbols__ProgramSymbols litaC_checker__TypeChecker_typeCheck(litaC_checker__TypeChecker* litaC_this,litaC_module__Module* litaC_root);
LITAC_INLINE 

#line 170 "src/checker.lita"
litaC_i32 litaC_checker__TypeChecker_errors(litaC_checker__TypeChecker* litaC_this);

#line 174 "src/checker.lita"
litaC_bool litaC_checker__TypeChecker_checkTrait(litaC_checker__TypeChecker* litaC_this,litaC_string_buffer__StringBuffer* litaC_sb,litaC_types__TypeInfo* litaC_a,litaC_types__TypeInfo* litaC_b,const litaC_char* litaC_description);

#line 236 "src/checker.lita"
litaC_bool litaC_checker__TypeChecker_checkCastability(litaC_checker__TypeChecker* litaC_this,litaC_lex__SrcPos litaC_src,litaC_types__TypeInfo* litaC_a,litaC_types__TypeInfo* litaC_b);

#line 264 "src/checker.lita"
litaC_bool litaC_checker__TypeChecker_checkAssignability(litaC_checker__TypeChecker* litaC_this,litaC_lex__SrcPos litaC_src,litaC_types__TypeInfo* litaC_a,litaC_types__TypeInfo* litaC_b);

#line 307 "src/checker.lita"
litaC_bool litaC_checker__TypeChecker_checkDeclarability(litaC_checker__TypeChecker* litaC_this,litaC_lex__SrcPos litaC_src,litaC_types__TypeInfo* litaC_a,litaC_types__TypeInfo* litaC_b);

#line 333 "src/checker.lita"
litaC_bool litaC_checker__TypeChecker_checkTypeCompatibility(litaC_checker__TypeChecker* litaC_this,litaC_lex__SrcPos litaC_src,litaC_types__TypeInfo* litaC_a,litaC_types__TypeInfo* litaC_b);

#line 358 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_createModuleSymbols(litaC_checker__TypeChecker* litaC_this,litaC_module__Module* litaC_module);

#line 396 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_enterModule(litaC_checker__TypeChecker* litaC_this,litaC_module__Module* litaC_module);

#line 401 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_leaveModule(litaC_checker__TypeChecker* litaC_this);

#line 412 "src/checker.lita"
litaC_symbols__Scope* litaC_checker__TypeChecker_currentScope(litaC_checker__TypeChecker* litaC_this);

#line 416 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_pushScope(litaC_checker__TypeChecker* litaC_this,litaC_symbols__Scope* litaC_scope);

#line 422 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_popScope(litaC_checker__TypeChecker* litaC_this);

#line 428 "src/checker.lita"
litaC_bool litaC_checker__TypeChecker_isGenericParamType(litaC_checker__TypeChecker* litaC_this,litaC_ast__NameTypeSpec* litaC_name);

#line 446 "src/checker.lita"
litaC_symbols__Symbol* litaC_checker__TypeChecker_createDeclSymbol(litaC_checker__TypeChecker* litaC_this,litaC_ast__Decl* litaC_decl);

#line 601 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_createImportSymbols(litaC_checker__TypeChecker* litaC_this,litaC_ast__ImportDecl* litaC_imp);

#line 642 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_resolveSymbols(litaC_checker__TypeChecker* litaC_this);

#line 681 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_resolveSymbol(litaC_checker__TypeChecker* litaC_this,litaC_symbols__Symbol* litaC_sym);

#line 805 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_finishResolveSymbol(litaC_checker__TypeChecker* litaC_this,litaC_symbols__Symbol* litaC_sym);

#line 865 "src/checker.lita"
litaC_symbols__Symbol* litaC_checker__TypeChecker_getType(litaC_checker__TypeChecker* litaC_this,litaC_ast__NameTypeSpec* litaC_spec);

#line 870 "src/checker.lita"
litaC_symbols__Symbol* litaC_checker__TypeChecker_getTypeByName(litaC_checker__TypeChecker* litaC_this,litaC_intern__InternedString litaC_typeName);

#line 904 "src/checker.lita"
litaC_bool litaC_checker__TypeChecker_implementsTrait(litaC_checker__TypeChecker* litaC_this,litaC_types__AggregateTypeInfo* litaC_agg,litaC_types__AggregateTypeInfo* litaC_iface);

#line 982 "src/checker.lita"
litaC_types__TypeInfo* litaC_checker__TypeChecker_resolveTypeSpec(litaC_checker__TypeChecker* litaC_this,litaC_ast__TypeSpec* litaC_spec);

#line 1106 "src/checker.lita"
litaC_symbols__Symbol* litaC_checker__TypeChecker_addSymbol(litaC_checker__TypeChecker* litaC_this,litaC_ast__Decl* litaC_decl,litaC_types__TypeInfo* litaC_typeInfo);

#line 1120 "src/checker.lita"
litaC_void litaC_checker__TypeChecker_addTypeToScope(litaC_checker__TypeChecker* litaC_this,litaC_ast__Decl* litaC_decl,litaC_symbols__Scope* litaC_scope,litaC_types__TypeInfo* litaC_baseType,litaC_types__AggregateTypeInfo* litaC_currentType);

#line 1162 "src/checker.lita"
litaC_bool litaC_checker__TypeChecker_resolveStmt(litaC_checker__TypeChecker* litaC_this,litaC_ast__Stmt* litaC_stmt);

#line 27 "src/types_new.lita"
litaC_u32 litaC_types_new__Hash(litaC_types_new__ArrayEntry litaC_a);

#line 36 "src/types_new.lita"
litaC_bool litaC_types_new__Equals(litaC_types_new__ArrayEntry litaC_a,litaC_types_new__ArrayEntry litaC_b);

#line 48 "src/types_new.lita"
litaC_void litaC_types_new__TypeCache_init(litaC_types_new__TypeCache* litaC_this,const litaC_mem__Allocator* litaC_allocator);

#line 57 "src/types_new.lita"
litaC_types__TypeInfo* litaC_types_new__TypeCache_newGenericParamTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_intern__InternedString litaC_name);

#line 71 "src/types_new.lita"
litaC_types__FuncTypeInfo* litaC_types_new__TypeCache_newFuncTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_symbols__Symbol* litaC_sym,litaC_ast__FuncDecl* litaC_funcDecl);

#line 84 "src/types_new.lita"
litaC_types__ArrayTypeInfo* litaC_types_new__TypeCache_newArrayTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_types__TypeInfo* litaC_arrayOf,litaC_usize litaC_length,litaC_ast__Expr* litaC_numOfElements,litaC_bool litaC_isLengthDefined);

#line 107 "src/types_new.lita"
litaC_types__FuncPtrTypeInfo* litaC_types_new__TypeCache_newFuncPtrTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_array__Array_cb_GenericParam_ce_ litaC_genericParams,litaC_types__TypeInfo* litaC_returnType,litaC_array__Array_cb__ptr_TypeInfo_ce_ litaC_paramDecls,litaC_bool litaC_hasVarargs);

#line 122 "src/types_new.lita"
litaC_types__AggregateTypeInfo* litaC_types_new__TypeCache_newAggregateTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_symbols__Symbol* litaC_sym,litaC_ast__AggregateDecl* litaC_aggregateDecl);

#line 151 "src/types_new.lita"
litaC_types__EnumTypeInfo* litaC_types_new__TypeCache_newEnumTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_symbols__Symbol* litaC_sym,litaC_ast__EnumDecl* litaC_enumDecl);

#line 163 "src/types_new.lita"
litaC_types__TypeInfo* litaC_types_new__TypeCache_newForeignTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_symbols__Symbol* litaC_sym);

#line 173 "src/types_new.lita"
litaC_types__ConstTypeInfo* litaC_types_new__TypeCache_newConstTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_types__TypeInfo* litaC_base);

#line 192 "src/types_new.lita"
litaC_types__PtrTypeInfo* litaC_types_new__TypeCache_newPtrTypeInfo(litaC_types_new__TypeCache* litaC_this,litaC_types__TypeInfo* litaC_base);

#line 206 "src/types_new.lita"
litaC_types__TypeInfo* litaC_types_new__TypeCache_typeDecay(litaC_types_new__TypeCache* litaC_this,litaC_types__TypeInfo* litaC_type);

#line 49 "src/intern.lita"
litaC_u32 litaC_intern__InternHashFn(litaC_intern__InternedString litaC_a);

#line 54 "src/intern.lita"
litaC_bool litaC_intern__InternEqualFn(litaC_intern__InternedString litaC_a,litaC_intern__InternedString litaC_b);

#line 75 "src/intern.lita"
litaC_void litaC_intern__Strings_init(litaC_intern__Strings* litaC_this,const litaC_mem__Allocator* litaC_allocator);

#line 106 "src/intern.lita"
litaC_void litaC_intern__Strings_internConstant(litaC_intern__Strings* litaC_this,const litaC_char* litaC_string,litaC_i32 litaC_length,litaC_intern__InternedString* litaC_intern);


#line 116 "src/intern.lita"
litaC_intern__InternedString litaC_intern__Strings_intern(litaC_intern__Strings* litaC_this,const litaC_char* litaC_string,litaC_i32 litaC_length);


#line 137 "src/intern.lita"
litaC_intern__InternedString litaC_intern__Strings_internCopy(litaC_intern__Strings* litaC_this,const litaC_char* litaC_string,litaC_i32 litaC_length);
LITAC_INLINE 

#line 158 "src/intern.lita"
litaC_bool litaC_intern__InternedString_equals(litaC_intern__InternedString* litaC_this,litaC_intern__InternedString* litaC_other);
LITAC_INLINE 

#line 163 "src/intern.lita"
litaC_bool litaC_intern__InternedString_empty(litaC_intern__InternedString* litaC_this);

#line 9 "src/ast_print.lita"
litaC_void litaC_ast_print__PrintTypeSpec(litaC_ast__TypeSpec* litaC_spec);

#line 81 "src/ast_print.lita"
litaC_void litaC_ast_print__PrintName(litaC_lex__Token litaC_tok);

#line 87 "src/ast_print.lita"
litaC_void litaC_ast_print__Printf(litaC_i32 litaC_indent,const litaC_char* litaC_format,...);

#line 98 "src/ast_print.lita"
litaC_void litaC_ast_print__PrintStmt(litaC_ast__Stmt* litaC_s,litaC_i32 litaC_indent);

#line 21 "src/generics.lita"
litaC_void litaC_generics__GetGenericName(litaC_checker__TypeChecker* litaC_checker,litaC_ast__TypeSpec* litaC_type,litaC_string__String* litaC_str);

#line 90 "src/generics.lita"
litaC_symbols__Symbol* litaC_generics__CreateTypeFromGenericTemplate(litaC_checker__TypeChecker* litaC_checker,litaC_symbols__Symbol* litaC_sym,litaC_ast__NameTypeSpec* litaC_name);

#line 234 "src/generics.lita"
litaC_ast__GenericDecl* litaC_generics__CreateAggregateDecl(litaC_ast__AggregateDecl* litaC_aggDecl,litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_genericArgs,litaC_lita__Lita* litaC_lita);

#line 250 "src/generics.lita"
litaC_ast__GenericDecl* litaC_generics__CreateFuncDecl(litaC_ast__FuncDecl* litaC_funcDecl,litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_genericArgs,litaC_lita__Lita* litaC_lita);

#line 265 "src/generics.lita"
litaC_ast__GenericDecl* litaC_generics__CreateTypedefDecl(litaC_ast__TypedefDecl* litaC_typedefDecl,litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_genericArgs,litaC_lita__Lita* litaC_lita);

#line 286 "src/generics.lita"
litaC_ast__TypeSpec* litaC_generics__Template_replaceTypeSpec(litaC_generics__Template* litaC_this,litaC_ast__TypeSpec* litaC_type);

#line 361 "src/generics.lita"
litaC_bool litaC_generics__ReplaceTypes(litaC_generics__Template* litaC_template,litaC_ast__Node* litaC_ast);

#line 745 "src/generics.lita"
litaC_bool litaC_generics__HasGenericParam(litaC_checker__TypeChecker* litaC_checker,litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_genericArgs);

#line 27 "src/introspection.lita"
litaC_void litaC_introspection__Introspect_generate(litaC_introspection__Introspect* litaC_this,litaC_checker__TypeChecker* litaC_checker);

#line 193 "src/introspection.lita"
litaC_void litaC_introspection__Introspect_emitFunc(litaC_introspection__Introspect* litaC_this,litaC_string_buffer__StringBuffer* litaC_sb,litaC_string_buffer__StringBuffer* litaC_scratch,litaC_symbols__Symbol* litaC_sym);

#line 239 "src/introspection.lita"
litaC_void litaC_introspection__Introspect_emitType(litaC_introspection__Introspect* litaC_this,litaC_string_buffer__StringBuffer* litaC_sb,litaC_string_buffer__StringBuffer* litaC_scratch,litaC_symbols__Symbol* litaC_sym);

#line 432 "src/introspection.lita"
litaC_void litaC_introspection__Introspect_emitPrimitiveType(litaC_introspection__Introspect* litaC_this,litaC_string_buffer__StringBuffer* litaC_sb,litaC_types__TypeInfo* litaC_type);

#line 25 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_resolveDecl(litaC_checker__TypeChecker* litaC_this,litaC_ast__Decl* litaC_decl);

#line 76 "src/checker_decl.lita"
litaC_types__TypeInfo* litaC_checker_decl__TypeChecker_resolveValueDecl(litaC_checker__TypeChecker* litaC_this,litaC_ast__VarDecl* litaC_decl);

#line 127 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_checkAnonAggregateFieldDuplicate(litaC_checker__TypeChecker* litaC_this,litaC_ast__AggregateDecl* litaC_aggDecl,litaC_ast__FieldStmt litaC_field,litaC_i32 litaC_index);

#line 182 "src/checker_decl.lita"
litaC_void litaC_checker_decl__TypeChecker_errorInvalidMemberForTrait(litaC_checker__TypeChecker* litaC_this,litaC_ast__AggregateDecl* litaC_aggDecl,litaC_intern__InternedString litaC_fieldName,litaC_lex__SrcPos litaC_pos);

#line 187 "src/checker_decl.lita"
litaC_void litaC_checker_decl__TypeChecker_errorUsingMember(litaC_checker__TypeChecker* litaC_this,litaC_ast__AggregateDecl* litaC_aggDecl,litaC_intern__InternedString litaC_fieldName,litaC_lex__SrcPos litaC_pos);

#line 199 "src/checker_decl.lita"
litaC_void litaC_checker_decl__TypeChecker_errorUsingParameter(litaC_checker__TypeChecker* litaC_this,litaC_ast__ParameterDecl* litaC_paramDecl);

#line 205 "src/checker_decl.lita"
litaC_void litaC_checker_decl__TypeChecker_errorDuplicateMember(litaC_checker__TypeChecker* litaC_this,litaC_ast__AggregateDecl* litaC_aggDecl,litaC_intern__InternedString litaC_fieldName,litaC_lex__SrcPos litaC_pos);

#line 217 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_checkAggregateFieldDuplicate(litaC_checker__TypeChecker* litaC_this,litaC_ast__AggregateDecl* litaC_aggDecl,litaC_intern__InternedString litaC_fieldName,litaC_i32 litaC_index);

#line 288 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_resolveAggregateDecl(litaC_checker__TypeChecker* litaC_this,litaC_ast__AggregateDecl* litaC_aggDecl);

#line 459 "src/checker_decl.lita"
litaC_i32 litaC_checker_decl__TypeChecker_addFieldReferences(litaC_checker__TypeChecker* litaC_this,litaC_ast__AggregateDecl* litaC_aggDecl,litaC_types__TypeInfo* litaC_parentTypeInfo,litaC_i32 litaC_position);

#line 516 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_checkEnumFieldDuplicate(litaC_checker__TypeChecker* litaC_this,litaC_ast__EnumDecl* litaC_enumDecl,litaC_ast__EnumFieldEntryDecl* litaC_field,litaC_i32 litaC_index);

#line 532 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_resolveEnumDecl(litaC_checker__TypeChecker* litaC_this,litaC_ast__EnumDecl* litaC_enumDecl);

#line 555 "src/checker_decl.lita"
litaC_void litaC_checker_decl__TypeChecker_checkLabels(litaC_checker__TypeChecker* litaC_this);

#line 565 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_resolveFuncDecl(litaC_checker__TypeChecker* litaC_this,litaC_ast__FuncDecl* litaC_funcDecl);

#line 605 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_resolveParamDecl(litaC_checker__TypeChecker* litaC_this,litaC_ast__ParameterDecl* litaC_paramDecl);

#line 640 "src/checker_decl.lita"
litaC_bool litaC_checker_decl__TypeChecker_resolveTypedefDecl(litaC_checker__TypeChecker* litaC_this,litaC_ast__TypedefDecl* litaC_typedefDecl);

#line 25 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveConstExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr);

#line 37 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr);

#line 134 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveFuncIdentifierExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__IdentifierExpr* litaC_expr);

#line 164 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_isMethodSyntax(litaC_checker__TypeChecker* litaC_this,litaC_ast__FuncCallExpr* litaC_expr,litaC_array__Array_cb_CallArg_ce_* litaC_suppliedArgs);

#line 184 "src/checker_expr.lita"
litaC_ast__Expr* litaC_checker_expr__TypeChecker_coerceTypeWithUsing(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_sourceType,litaC_types__TypeInfo* litaC_targetType);

#line 243 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_coerceFuncArgs(litaC_checker__TypeChecker* litaC_this,litaC_ast__FuncCallExpr* litaC_expr,litaC_types__TypeInfo* litaC_funcType,litaC_array__Array_cb_CallArg_ce_* litaC_suppliedArgs);

#line 275 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_coerceFuncArg(litaC_checker__TypeChecker* litaC_this,litaC_ast__FuncCallExpr* litaC_expr,litaC_i32 litaC_index,litaC_ast__Expr* litaC_argExpr,litaC_types__TypeInfo* litaC_paramInfo,litaC_array__Array_cb_CallArg_ce_* litaC_suppliedArgs);

#line 328 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_checkNumberOfArgs(litaC_checker__TypeChecker* litaC_this,litaC_ast__FuncCallExpr* litaC_expr,litaC_intern__InternedString litaC_funcName,litaC_i32 litaC_maxNumOfArgs,litaC_bool litaC_hasVarargs,litaC_i32 litaC_numberOfSuppliedArgs,litaC_i32 litaC_numberOfDefaultArgs);

#line 361 "src/checker_expr.lita"
litaC_types__TypeInfo* litaC_checker_expr__TypeChecker_inferredType(litaC_checker__TypeChecker* litaC_this,litaC_lex__Token litaC_name,litaC_types__TypeInfo* litaC_paramType,litaC_types__TypeInfo* litaC_expectedType);

#line 513 "src/checker_expr.lita"
litaC_types__TypeInfo* litaC_checker_expr__TypeChecker_inferFuncCallExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__FuncCallExpr* litaC_expr,litaC_types__TypeInfo* litaC_funcType,litaC_array__Array_cb_CallArg_ce_* litaC_suppliedArgs,litaC_bool litaC_isMethodCall);

#line 632 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_checkFuncCallArgs(litaC_checker__TypeChecker* litaC_this,litaC_ast__FuncCallExpr* litaC_expr,litaC_types__TypeInfo* litaC_funcType,litaC_array__Array_cb_CallArg_ce_* litaC_suppliedArgs);

#line 748 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveFuncCallExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__FuncCallExpr* litaC_expr);

#line 873 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveBooleanExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__BooleanExpr* litaC_expr);

#line 882 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveCharExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__CharExpr* litaC_expr);

#line 891 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveNullExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__NullExpr* litaC_expr);

#line 899 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveNumberExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__NumberExpr* litaC_expr);

#line 908 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveStringExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__StringExpr* litaC_expr);

#line 917 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveSubscriptSetExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__SubscriptSetExpr* litaC_expr);

#line 976 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveSubscriptGetExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__SubscriptGetExpr* litaC_expr);

#line 1029 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveInitArgExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__InitArgExpr* litaC_expr);

#line 1042 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_addDefaultArguments(litaC_checker__TypeChecker* litaC_this,litaC_types__TypeInfo* litaC_type,litaC_ast__InitExpr* litaC_expr);

#line 1097 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_addInitArgumentsReferences(litaC_checker__TypeChecker* litaC_this,litaC_types__TypeInfo* litaC_type,litaC_ast__InitExpr* litaC_expr);

#line 1124 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_checkInitArguments(litaC_checker__TypeChecker* litaC_this,litaC_types__TypeInfo* litaC_type,litaC_ast__InitExpr* litaC_expr);

#line 1171 "src/checker_expr.lita"
litaC_types__TypeInfo* litaC_checker_expr__TypeChecker_inferInitExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__InitExpr* litaC_expr,litaC_types__AggregateTypeInfo* litaC_aggInfo);

#line 1231 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveInitExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__InitExpr* litaC_expr);

#line 1278 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveSetExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__SetExpr* litaC_expr);

#line 1333 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveTernaryExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__TernaryExpr* litaC_expr);

#line 1361 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveTypeIdentifierExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__TypeIdentifierExpr* litaC_expr);

#line 1376 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveTypeOfExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__TypeOfExpr* litaC_expr);

#line 1399 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveOffsetOfExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__OffsetOfExpr* litaC_expr);

#line 1428 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveSizeOfExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__SizeOfExpr* litaC_expr);

#line 1440 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_checkMethodExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__GetExpr* litaC_expr,litaC_types__AggregateTypeInfo* litaC_aggInfo);

#line 1517 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveGetExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__GetExpr* litaC_expr);

#line 1610 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveGroupExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__GroupExpr* litaC_expr);

#line 1621 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveUnaryExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__UnaryExpr* litaC_expr);

#line 1710 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveCastExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__CastExpr* litaC_expr);

#line 1732 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveArrayDesignationExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__ArrayDesignationExpr* litaC_expr);

#line 1764 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveArrayInitExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__ArrayInitExpr* litaC_expr);

#line 1806 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveBinaryExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__BinaryExpr* litaC_expr);

#line 1924 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorNonIndexableType(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type);

#line 1936 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorSetIndexingConstType(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type);

#line 1948 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorIndexType(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type);

#line 1961 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorNonAggregateType(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type);

#line 1974 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorNonFuncType(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type);

#line 1987 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorOperand(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type,const litaC_char* litaC_side);

#line 1999 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorEnumFieldSet(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type,litaC_intern__InternedString litaC_field);

#line 2011 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorNoField(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type,litaC_intern__InternedString litaC_field);

#line 2024 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorNoFieldAt(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type,litaC_i32 litaC_position);

#line 2037 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorNoFieldAccess(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type,litaC_intern__InternedString litaC_field);

#line 2050 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorInferGenericParameter(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_ast__GenericParam* litaC_param);

#line 2056 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorInferGenericParameters(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_array__Array_cb_GenericParam_ce_* litaC_params);

#line 2073 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorMissingGenericArguments(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_intern__InternedString litaC_typeName,litaC_array__Array_cb_GenericParam_ce_* litaC_genericParams);

#line 2091 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorFixedArgumentAfterNamed(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_arg);

#line 2101 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorNamedArgumentsForFuncPtr(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr);

#line 2110 "src/checker_expr.lita"
litaC_void litaC_checker_expr__TypeChecker_errorInvalidNamedArgument(litaC_checker__TypeChecker* litaC_this,litaC_lex__SrcPos litaC_pos,litaC_intern__InternedString* litaC_name,litaC_types__FuncTypeInfo* litaC_funcInfo);

#line 2131 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_checkConstant(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr);

#line 2167 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_checkTruthyness(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr,litaC_types__TypeInfo* litaC_type);

#line 2183 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_checkRightValue(litaC_checker__TypeChecker* litaC_this,litaC_ast__Expr* litaC_expr);

#line 2192 "src/checker_expr.lita"
litaC_bool litaC_checker_expr__TypeChecker_resolveIdentiferExpr(litaC_checker__TypeChecker* litaC_this,litaC_ast__IdentifierExpr* litaC_expr);

#line 108 "src/error_codes.lita"
litaC_void litaC_error_codes__PrintError(litaC_string_buffer__StringBuffer* litaC_sb,litaC_phase_result__PhaseError litaC_error);

#line 70 "src/parser.lita"
litaC_parser__Parser litaC_parser__ParserInit(const litaC_char* litaC_filename,const litaC_char* litaC_text,litaC_lita__Lita* litaC_lita);

#line 112 "src/parser.lita"
litaC_ast__ModuleStmt* litaC_parser__Parser_parseModule(litaC_parser__Parser* litaC_p);

#line 143 "src/parser.lita"
litaC_void litaC_parser__Parser_parseModuleDeclaration(litaC_parser__Parser* litaC_p,litaC_ast__ModuleStmt* litaC_moduleStmt);

#line 220 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_parseCompileTimeBody(litaC_parser__Parser* litaC_p);

#line 291 "src/parser.lita"
litaC_ast__ImportDecl* litaC_parser__Parser_importDeclaration(litaC_parser__Parser* litaC_p);

#line 320 "src/parser.lita"
litaC_bool litaC_parser__Parser_notes(litaC_parser__Parser* litaC_p,litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_notes);

#line 362 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_varDeclaration(litaC_parser__Parser* litaC_p);

#line 398 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_constDeclaration(litaC_parser__Parser* litaC_p);

#line 406 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_funcDeclaration(litaC_parser__Parser* litaC_p);

#line 491 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_structDeclaration(litaC_parser__Parser* litaC_p);

#line 495 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_unionDeclaration(litaC_parser__Parser* litaC_p);

#line 499 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_traitDeclaration(litaC_parser__Parser* litaC_p);

#line 503 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_aggregateDeclaration(litaC_parser__Parser* litaC_p,litaC_ast__StmtKind litaC_kind);

#line 565 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_enumDeclaration(litaC_parser__Parser* litaC_p);

#line 605 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_typedefDeclaration(litaC_parser__Parser* litaC_p);

#line 633 "src/parser.lita"
litaC_ast__ParameterDecl* litaC_parser__Parser_paramDeclaration(litaC_parser__Parser* litaC_p);

#line 670 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_expression(litaC_parser__Parser* litaC_p);

#line 691 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_constExpression(litaC_parser__Parser* litaC_p);

#line 698 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_group(litaC_parser__Parser* litaC_p);

#line 705 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_arrayInit(litaC_parser__Parser* litaC_p);

#line 730 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_aggregateInit(litaC_parser__Parser* litaC_p);

#line 738 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_sizeOf(litaC_parser__Parser* litaC_p);

#line 783 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_typeOf(litaC_parser__Parser* litaC_p);

#line 827 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_offsetOf(litaC_parser__Parser* litaC_p);

#line 858 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_assignment(litaC_parser__Parser* litaC_p);

#line 900 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_ternary(litaC_parser__Parser* litaC_p);

#line 921 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_or(litaC_parser__Parser* litaC_p);

#line 935 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_and(litaC_parser__Parser* litaC_p);

#line 949 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_bitOr(litaC_parser__Parser* litaC_p);

#line 963 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_bitXor(litaC_parser__Parser* litaC_p);

#line 977 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_bitAnd(litaC_parser__Parser* litaC_p);

#line 991 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_equality(litaC_parser__Parser* litaC_p);

#line 1010 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_comparison(litaC_parser__Parser* litaC_p);

#line 1031 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_bitShift(litaC_parser__Parser* litaC_p);

#line 1055 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_term(litaC_parser__Parser* litaC_p);

#line 1074 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_factor(litaC_parser__Parser* litaC_p);

#line 1094 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_unary(litaC_parser__Parser* litaC_p);

#line 1115 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_functionCall(litaC_parser__Parser* litaC_p);

#line 1175 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_primary(litaC_parser__Parser* litaC_p);

#line 1243 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_finishFunctionCall(litaC_parser__Parser* litaC_p,litaC_ast__Expr* litaC_expr);

#line 1269 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_cast(litaC_parser__Parser* litaC_p,litaC_ast__Expr* litaC_expr);

#line 1293 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_statement(litaC_parser__Parser* litaC_p);

#line 1313 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_tryStatement(litaC_parser__Parser* litaC_p);

#line 1413 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_compStatement(litaC_parser__Parser* litaC_p);

#line 1568 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_blockStatement(litaC_parser__Parser* litaC_p);

#line 1600 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_ifStatement(litaC_parser__Parser* litaC_p);

#line 1626 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_whileStatement(litaC_parser__Parser* litaC_p);

#line 1650 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_doWhileStatement(litaC_parser__Parser* litaC_p);

#line 1678 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_forStatement(litaC_parser__Parser* litaC_p);

#line 1709 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_switchCaseStatement(litaC_parser__Parser* litaC_p);

#line 1745 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_switchDefaultStatement(litaC_parser__Parser* litaC_p);

#line 1773 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_switchStatement(litaC_parser__Parser* litaC_p);

#line 1829 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_breakStatement(litaC_parser__Parser* litaC_p);

#line 1847 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_continueStatement(litaC_parser__Parser* litaC_p);

#line 1861 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_returnStatement(litaC_parser__Parser* litaC_p);

#line 1871 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_deferStatement(litaC_parser__Parser* litaC_p);

#line 1877 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_gotoStatement(litaC_parser__Parser* litaC_p);

#line 1890 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_tryLabelStatement(litaC_parser__Parser* litaC_p);

#line 1916 "src/parser.lita"
litaC_ast__TypeSpec* litaC_parser__Parser_type(litaC_parser__Parser* litaC_p,litaC_bool litaC_disambiguate);

#line 1982 "src/parser.lita"
litaC_ast__NameTypeSpec* litaC_parser__Parser_identifierType(litaC_parser__Parser* litaC_p,litaC_bool litaC_disambiguate);

#line 2015 "src/parser.lita"
litaC_ast__ArrayTypeSpec* litaC_parser__Parser_arrayType(litaC_parser__Parser* litaC_p);

#line 2036 "src/parser.lita"
litaC_ast__FuncPtrTypeSpec* litaC_parser__Parser_funcPtrType(litaC_parser__Parser* litaC_p);

#line 2090 "src/parser.lita"
litaC_ast__ParametersStmt* litaC_parser__Parser_parametersStatement(litaC_parser__Parser* litaC_p);

#line 2137 "src/parser.lita"
litaC_bool litaC_parser__Parser_structArguments(litaC_parser__Parser* litaC_p,litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_arguments);

#line 2184 "src/parser.lita"
litaC_bool litaC_parser__Parser_arguments(litaC_parser__Parser* litaC_p,litaC_array__Array_cb_CallArg_ce_* litaC_arguments);

#line 2227 "src/parser.lita"
litaC_bool litaC_parser__Parser_genericParameters(litaC_parser__Parser* litaC_p,litaC_array__Array_cb_GenericParam_ce_* litaC_arguments);

#line 2254 "src/parser.lita"
litaC_array__Array_cb__ptr_TypeSpec_ce_ litaC_parser__Parser_genericArguments(litaC_parser__Parser* litaC_p);

#line 2276 "src/parser.lita"
litaC_array__Array_cb__ptr_TypeSpec_ce_ litaC_parser__Parser_tryGenericArguments(litaC_parser__Parser* litaC_p,litaC_bool litaC_disambiguate);

#line 2333 "src/parser.lita"
litaC_bool litaC_parser__Parser_arrayArguments(litaC_parser__Parser* litaC_p,litaC_array__Array_cb__ptr_Expr_ce_* litaC_arguments);

#line 2363 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_tryArrayDesignationExpr(litaC_parser__Parser* litaC_p);

#line 2394 "src/parser.lita"
litaC_ast__FieldStmt litaC_parser__Parser_fieldStatement(litaC_parser__Parser* litaC_p,litaC_ast__StmtKind litaC_aggKind);

#line 2516 "src/parser.lita"
litaC_ast__EnumFieldEntryDecl* litaC_parser__Parser_enumFieldEntryDecl(litaC_parser__Parser* litaC_p);

#line 2544 "src/parser.lita"
litaC_void litaC_parser__Parser_rewindTo(litaC_parser__Parser* litaC_p,litaC_i32 litaC_backtrack,litaC_u64 litaC_numOfErrors);

#line 2561 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_tryBitShiftRight(litaC_parser__Parser* litaC_p,litaC_ast__Expr* litaC_expr);

#line 2585 "src/parser.lita"
litaC_void litaC_parser__Parser_eatSemicolon(litaC_parser__Parser* litaC_p);

#line 2589 "src/parser.lita"
litaC_lex__Token litaC_parser__Parser_identifier(litaC_parser__Parser* litaC_p);

#line 2601 "src/parser.lita"
litaC_bool litaC_parser__Parser_checkConstExpr(litaC_parser__Parser* litaC_p,litaC_ast__Expr* litaC_expr);

#line 2636 "src/parser.lita"
litaC_ast__Stmt* litaC_parser__Parser_poisonStatement(litaC_parser__Parser* litaC_p,litaC_lex__SrcPos litaC_pos);

#line 2640 "src/parser.lita"
litaC_ast__Expr* litaC_parser__Parser_poisonExpr(litaC_parser__Parser* litaC_p,litaC_lex__SrcPos litaC_pos);

#line 2644 "src/parser.lita"
litaC_ast__Decl* litaC_parser__Parser_poisonDecl(litaC_parser__Parser* litaC_p,litaC_lex__SrcPos litaC_pos);

#line 2648 "src/parser.lita"
litaC_lex__SrcPos litaC_parser__Parser_pos(litaC_parser__Parser* litaC_p);

#line 2660 "src/parser.lita"
litaC_lex__SrcPos litaC_parser__Parser_prevPos(litaC_parser__Parser* litaC_p);

#line 2665 "src/parser.lita"
litaC_lex__Token* litaC_parser__Parser_peek(litaC_parser__Parser* litaC_p);

#line 2673 "src/parser.lita"
litaC_void litaC_parser__Parser_rewind(litaC_parser__Parser* litaC_p);

#line 2680 "src/parser.lita"
litaC_lex__Token* litaC_parser__Parser_previous(litaC_parser__Parser* litaC_p);

#line 2686 "src/parser.lita"
litaC_bool litaC_parser__Parser_atEnd(litaC_parser__Parser* litaC_p);

#line 2698 "src/parser.lita"
litaC_lex__Token* litaC_parser__Parser_advance(litaC_parser__Parser* litaC_p);
LITAC_INLINE 

#line 2706 "src/parser.lita"
litaC_bool litaC_parser__Parser_check(litaC_parser__Parser* litaC_p,litaC_lex__TokenType litaC_type);

#line 2713 "src/parser.lita"
litaC_bool litaC_parser__Parser_match(litaC_parser__Parser* litaC_p,litaC_lex__TokenType litaC_type);

#line 2721 "src/parser.lita"
litaC_bool litaC_parser__Parser_matches(litaC_parser__Parser* litaC_p,litaC_lex__TokenType* litaC_types,litaC_i32 litaC_len);

#line 2732 "src/parser.lita"
litaC_lex__Token* litaC_parser__Parser_consume(litaC_parser__Parser* litaC_p,litaC_lex__TokenType litaC_type,litaC_error_codes__ErrorCode litaC_errorCode);

#line 2741 "src/parser.lita"
litaC_void litaC_parser__Parser_adjust(litaC_parser__Parser* litaC_p,litaC_lex__TokenType* litaC_types,litaC_i32 litaC_len);

#line 2761 "src/parser.lita"
litaC_void litaC_parser__Parser_errorAtToken(litaC_parser__Parser* litaC_p,litaC_lex__Token* litaC_token,litaC_error_codes__ErrorCode litaC_errorCode);

#line 2772 "src/parser.lita"
litaC_void litaC_parser__Parser_errorAtPos(litaC_parser__Parser* litaC_p,litaC_lex__SrcPos litaC_pos,litaC_error_codes__ErrorCode litaC_errorCode);

#line 2788 "src/parser.lita"
litaC_void litaC_parser__Parser_errorUnexpectedToken(litaC_parser__Parser* litaC_p,litaC_lex__Token* litaC_token,litaC_error_codes__ErrorCode litaC_errorCode);

#line 2810 "src/parser.lita"
litaC_i32 litaC_parser__Parser_numOfErrors(litaC_parser__Parser* litaC_p);

#line 23 "src/instrument.lita"
litaC_void litaC_instrument__Instrument(litaC_lita__Lita* litaC_lita,litaC_checker__TypeChecker* litaC_checker);

#line 91 "src/traits.lita"
litaC_array__Array_cb__ptr_Decl_ce_ litaC_traits__CreateTraitWrappers(litaC_checker__TypeChecker* litaC_checker);

#line 248 "src/traits.lita"
litaC_void litaC_traits__PrintGenerics(litaC_array__Array_cb_GenericParam_ce_* litaC_genericParams,litaC_string_buffer__StringBuffer* litaC_sb);

#line 264 "src/traits.lita"
litaC_void litaC_traits__PrintGenericArgs(litaC_array__Array_cb__ptr_TypeInfo_ce_* litaC_genericArgs,litaC_string_buffer__StringBuffer* litaC_sb);

#line 282 "src/traits.lita"
litaC_symbols__Symbol* litaC_traits__FindSymbolByTypeid(litaC_array__Array_cb__ptr_Symbol_ce_ litaC_symbols,litaC_i64 litaC_id);

#line 293 "src/traits.lita"
litaC_string_view__StringView litaC_traits__GetTraitName(litaC_symbols__Symbol* litaC_traitSym,litaC_string_buffer__StringBuffer* litaC_sb);

#line 311 "src/traits.lita"
litaC_void litaC_traits__Parse(litaC_string_buffer__StringBuffer* litaC_sb,litaC_checker__TypeChecker* litaC_checker,litaC_array__Array_cb__ptr_Decl_ce_* litaC_decls);

#line 87 "src/cgen.lita"
litaC_void litaC_cgen__CGen_init(litaC_cgen__CGen* litaC_this,litaC_lita__Lita* litaC_lita,FILE* litaC_output);

#line 104 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitProgram(litaC_cgen__CGen* litaC_this,litaC_module__Module* litaC_module);

#line 176 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitMain(litaC_cgen__CGen* litaC_this,litaC_symbols__Symbol* litaC_sym);

#line 189 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitForward(litaC_cgen__CGen* litaC_this);

#line 270 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitPrimitiveConstDecls(litaC_cgen__CGen* litaC_this);

#line 292 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitModuleNotes(litaC_cgen__CGen* litaC_this);

#line 307 "src/cgen.lita"
litaC_symbols__Symbol* litaC_cgen__CGen_findSymbolByTypeid(litaC_cgen__CGen* litaC_this,litaC_i64 litaC_id);

#line 320 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitTraitForwardDecls(litaC_cgen__CGen* litaC_this);

#line 351 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitTraitDecls(litaC_cgen__CGen* litaC_this);

#line 393 "src/cgen.lita"
litaC_bool litaC_cgen__CGen_emitTraitCast(litaC_cgen__CGen* litaC_this,litaC_ast__Expr* litaC_expr);

#line 421 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitForwardDecls(litaC_cgen__CGen* litaC_this);

#line 434 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitTypeForwardDecl(litaC_cgen__CGen* litaC_this,litaC_symbols__Symbol* litaC_sym);

#line 481 "src/cgen.lita"
const litaC_char* litaC_cgen__CGen_allocTemp(litaC_cgen__CGen* litaC_this,litaC_types__TypeInfo* litaC_type,litaC_char* litaC_buffer);

#line 492 "src/cgen.lita"
litaC_string_view__StringView litaC_cgen__CGen_escapeNameStr(litaC_cgen__CGen* litaC_this,litaC_intern__InternedString litaC_name);

#line 501 "src/cgen.lita"
litaC_string_view__StringView litaC_cgen__CGen_escapeNameChars(litaC_cgen__CGen* litaC_this,const litaC_char* litaC_name);

#line 510 "src/cgen.lita"
litaC_string_view__StringView litaC_cgen__CGen_escapeName(litaC_cgen__CGen* litaC_this,litaC_types__TypeInfo* litaC_type);

#line 537 "src/cgen.lita"
litaC_string_view__StringView litaC_cgen__CGen_baseTypeName(litaC_cgen__CGen* litaC_this,litaC_string_view__StringView litaC_name);

#line 553 "src/cgen.lita"
litaC_void litaC_cgen__CGen_pushScope(litaC_cgen__CGen* litaC_this,litaC_cgen__CGenScope* litaC_scope);

#line 558 "src/cgen.lita"
litaC_cgen__CGenScope* litaC_cgen__CGen_popScope(litaC_cgen__CGen* litaC_this);

#line 569 "src/cgen.lita"
litaC_void litaC_cgen__CGen_popLoopScope(litaC_cgen__CGen* litaC_this,litaC_bool litaC_checkSwitch);

#line 585 "src/cgen.lita"
litaC_void litaC_cgen__CGen_leaveScope(litaC_cgen__CGen* litaC_this,litaC_cgen__CGenScope* litaC_scope);

#line 604 "src/cgen.lita"
litaC_bool litaC_cgen__CGen_hasPendingDefers(litaC_cgen__CGen* litaC_this);

#line 617 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitDefers(litaC_cgen__CGen* litaC_this);

#line 628 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitLineInfo(litaC_cgen__CGen* litaC_this,litaC_ast__Stmt* litaC_stmt);

#line 667 "src/cgen.lita"
const litaC_char* litaC_cgen__CGen_cType(litaC_cgen__CGen* litaC_this,litaC_types__TypeInfo* litaC_type,litaC_bool litaC_isCast,litaC_bool litaC_decay);

#line 783 "src/cgen.lita"
const litaC_char* litaC_cgen__CGen_cTypeDecl(litaC_cgen__CGen* litaC_this,litaC_types__TypeInfo* litaC_type,const litaC_char* litaC_name,litaC_bool litaC_decay);

#line 915 "src/cgen.lita"
litaC_string_view__StringView litaC_cgen__CGen_foreignName(litaC_cgen__CGen* litaC_this,litaC_ast__Decl* litaC_decl,litaC_string_view__StringView litaC_defaultName);

#line 936 "src/cgen.lita"
const litaC_char* litaC_cgen__CGen_cName(litaC_cgen__CGen* litaC_this,litaC_symbols__Symbol* litaC_sym);

#line 971 "src/cgen.lita"
const litaC_char* litaC_cgen__CGen_cTypeName(litaC_cgen__CGen* litaC_this,litaC_types__TypeInfo* litaC_type);

#line 983 "src/cgen.lita"
const litaC_char* litaC_cgen__CGen_prefix(litaC_cgen__CGen* litaC_this,litaC_string_view__StringView litaC_name,litaC_string_buffer__StringBuffer* litaC_sb);

#line 989 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitTypeSpec(litaC_cgen__CGen* litaC_this,litaC_ast__TypeSpec* litaC_spec);

#line 1057 "src/cgen.lita"
litaC_void litaC_cgen__CGen_flush(litaC_cgen__CGen* litaC_this);

#line 1064 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitName(litaC_cgen__CGen* litaC_this,litaC_lex__Token litaC_tok);

#line 1070 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitln(litaC_cgen__CGen* litaC_this);

#line 1077 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emit(litaC_cgen__CGen* litaC_this,const litaC_char* litaC_strFormat,...);

#line 1120 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitStr(litaC_cgen__CGen* litaC_this,const litaC_char* litaC_str);

#line 1125 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitStrn(litaC_cgen__CGen* litaC_this,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 1159 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitNotes(litaC_cgen__CGen* litaC_this,litaC_ast__Attributes* litaC_attributes,litaC_bool litaC_isPrelude);

#line 1179 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitPreludeNote(litaC_cgen__CGen* litaC_this,litaC_ast__NoteStmt* litaC_note);

#line 1300 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitPostludeNote(litaC_cgen__CGen* litaC_this,litaC_ast__NoteStmt* litaC_note);

#line 1306 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitFieldName(litaC_cgen__CGen* litaC_this,litaC_ast__FieldStmt litaC_field);

#line 1319 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitSymbol(litaC_cgen__CGen* litaC_this,litaC_symbols__Symbol* litaC_sym);

#line 1353 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitTraitFuncCall(litaC_cgen__CGen* litaC_this,litaC_ast__FuncCallExpr* litaC_expr);

#line 1441 "src/cgen.lita"
litaC_void litaC_cgen__CGen_emitStmt(litaC_cgen__CGen* litaC_this,litaC_ast__Stmt* litaC_s);

#line 55 "src/dependency_graph.lita"
litaC_void litaC_dependency_graph__DependencyGraph_init(litaC_dependency_graph__DependencyGraph* litaC_this,litaC_lita__Lita* litaC_lita);

#line 78 "src/dependency_graph.lita"
litaC_void litaC_dependency_graph__DependencyGraph_markDependencies(litaC_dependency_graph__DependencyGraph* litaC_this,litaC_dependency_graph__Dependency* litaC_dependency);

#line 115 "src/dependency_graph.lita"
litaC_void litaC_dependency_graph__DependencyGraph_buildGraph(litaC_dependency_graph__DependencyGraph* litaC_this,litaC_symbols__ProgramSymbols* litaC_program);

#line 158 "src/dependency_graph.lita"
litaC_dependency_graph__Dependency* litaC_dependency_graph__DependencyGraph_resolveDependency(litaC_dependency_graph__DependencyGraph* litaC_this,litaC_dependency_graph__Dependency* litaC_dependency);

#line 175 "src/dependency_graph.lita"
litaC_void litaC_dependency_graph__DependencyGraph_sortAggregates(litaC_dependency_graph__DependencyGraph* litaC_this);

#line 201 "src/dependency_graph.lita"
litaC_array__Array_cb__ptr_Dependency_ce_ litaC_dependency_graph__DependencyGraph_sortAggregatesDependencies(litaC_dependency_graph__DependencyGraph* litaC_this,litaC_array__Array_cb__ptr_Dependency_ce_* litaC_deps);

#line 231 "src/dependency_graph.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ litaC_dependency_graph__DependencyGraph_sort(litaC_dependency_graph__DependencyGraph* litaC_this);

#line 17 "src/cgen_decl.lita"
litaC_void litaC_cgen_decl__CGen_emitVarDecl(litaC_cgen__CGen* litaC_this,litaC_ast__VarDecl* litaC_decl);

#line 63 "src/cgen_decl.lita"
litaC_void litaC_cgen_decl__CGen_emitFuncDeclSignature(litaC_cgen__CGen* litaC_this,litaC_ast__FuncDecl* litaC_decl,const litaC_char* litaC_name);

#line 126 "src/cgen_decl.lita"
litaC_void litaC_cgen_decl__CGen_emitFuncDecl(litaC_cgen__CGen* litaC_this,litaC_ast__FuncDecl* litaC_decl);

#line 151 "src/cgen_decl.lita"
litaC_void litaC_cgen_decl__CGen_emitAggregateDecl(litaC_cgen__CGen* litaC_this,litaC_ast__AggregateDecl* litaC_decl);

#line 235 "src/cgen_decl.lita"
litaC_void litaC_cgen_decl__CGen_emitEnumDecl(litaC_cgen__CGen* litaC_this,litaC_ast__EnumDecl* litaC_decl);

#line 21 "src/lsp/references.lita"
litaC_lex__Token litaC_references__FindTokenByPosition(litaC_lsp__LspServer* litaC_lsp,const litaC_mem__Allocator* litaC_alloc,litaC_workspace__Document* litaC_doc,litaC_protocol__Position litaC_pos);

#line 69 "src/lsp/references.lita"
litaC_void litaC_references__ReferenceDatabase_init(litaC_references__ReferenceDatabase* litaC_this,const litaC_mem__Allocator* litaC_allocator);

#line 76 "src/lsp/references.lita"
litaC_void litaC_references__ReferenceDatabase_addSymbolReference(litaC_references__ReferenceDatabase* litaC_this,litaC_symbols__Symbol* litaC_symbol,litaC_lex__SrcPos litaC_pos);

#line 90 "src/lsp/references.lita"
litaC_void litaC_references__ReferenceDatabase_addTypeReference(litaC_references__ReferenceDatabase* litaC_this,litaC_ast__TypeSpec* litaC_type);

#line 99 "src/lsp/references.lita"
litaC_void litaC_references__ReferenceDatabase_addTypeReferenceBySymbol(litaC_references__ReferenceDatabase* litaC_this,litaC_lex__SrcPos litaC_srcPos,litaC_symbols__Symbol* litaC_sym);

#line 105 "src/lsp/references.lita"
litaC_void litaC_references__ReferenceDatabase_addTypeReferenceByTypeInfo(litaC_references__ReferenceDatabase* litaC_this,litaC_lex__SrcPos litaC_srcPos,litaC_types__TypeInfo* litaC_typeInfo);

#line 129 "src/lsp/references.lita"
litaC_void litaC_references__ReferenceDatabase_addFieldReference(litaC_references__ReferenceDatabase* litaC_this,litaC_lex__SrcPos litaC_srcPos,litaC_types__TypeInfo* litaC_parent,litaC_i32 litaC_offset);

#line 139 "src/lsp/references.lita"
litaC_array__Array_cb_SrcPos_ce_ litaC_references__ReferenceDatabase_getSymbolReferences(litaC_references__ReferenceDatabase* litaC_this,litaC_symbols__Symbol* litaC_symbol);

#line 152 "src/lsp/references.lita"
litaC_void litaC_references__ReferenceDatabase_getTypeReferences(litaC_references__ReferenceDatabase* litaC_this,litaC_i64 litaC_typeid,litaC_array__Array_cb_SrcPos_ce_* litaC_results);

#line 161 "src/lsp/references.lita"
litaC_void litaC_references__ReferenceDatabase_getFieldReferences(litaC_references__ReferenceDatabase* litaC_this,litaC_i64 litaC_typeid,litaC_i32 litaC_offset,litaC_array__Array_cb_SrcPos_ce_* litaC_results);
LITAC_INLINE 

#line 49 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_isNull(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 54 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_isBool(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_isTrue(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_isFalse(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_isNumber(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 74 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_isString(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_isArray(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 84 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_isObject(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 89 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* litaC_json__JsonNode_asString(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 94 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_asBool(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 99 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_f64 litaC_json__JsonNode_asNumber(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 104 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_f64 litaC_json__JsonNode_asFloat(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 109 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_i32 litaC_json__JsonNode_asInt(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 114 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_i64 litaC_json__JsonNode_asLong(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 119 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_array__Array_cb__ptr_JsonNode_ce_* litaC_json__JsonNode_asArray(litaC_json__JsonNode* litaC_node);
LITAC_INLINE 

#line 124 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonObject* litaC_json__JsonNode_asObject(litaC_json__JsonNode* litaC_node);

#line 128 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__CreateJsonNumber(litaC_f64 litaC_value,const litaC_mem__Allocator* litaC_alloc);

#line 140 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__CreateJsonIntNumber(litaC_i64 litaC_value,const litaC_mem__Allocator* litaC_alloc);

#line 152 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__CreateJsonFloatNumber(litaC_f64 litaC_value,const litaC_mem__Allocator* litaC_alloc);

#line 160 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__CreateJsonString(const litaC_char* litaC_str,litaC_i32 litaC_len,const litaC_mem__Allocator* litaC_alloc);

#line 197 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__EscapeString(litaC_string_buffer__StringBuffer* litaC_buf,const litaC_char* litaC_string,litaC_i32 litaC_length);

#line 231 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__CreateJsonStringNoDup(const litaC_char* litaC_str,const litaC_mem__Allocator* litaC_alloc);

#line 243 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__CreateJsonArray(const litaC_mem__Allocator* litaC_alloc);

#line 256 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__CreateJsonObject(const litaC_mem__Allocator* litaC_alloc);

#line 270 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_put(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_json__JsonNode* litaC_n,litaC_i32 litaC_len);

#line 290 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_putNoDup(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_json__JsonNode* litaC_n,litaC_i32 litaC_len);

#line 307 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_putStr(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,const litaC_char* litaC_str,litaC_i32 litaC_len);

#line 317 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_putNumber(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_f64 litaC_number,litaC_i32 litaC_len);

#line 326 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_putIntNumber(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_i64 litaC_number,litaC_i32 litaC_len);

#line 335 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_putFloatNumber(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_f64 litaC_number,litaC_i32 litaC_len);

#line 344 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_putBool(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_bool litaC_b,litaC_i32 litaC_len);

#line 353 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_contains(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key);

#line 361 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonNode_get(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key);

#line 374 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_getBool(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_bool litaC_defaultValue);

#line 383 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_i32 litaC_json__JsonNode_getInt(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_i32 litaC_defaultValue);

#line 399 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_i64 litaC_json__JsonNode_getLong(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_i64 litaC_defaultValue);

#line 415 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_f64 litaC_json__JsonNode_getFloat(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_f64 litaC_defaultValue);

#line 431 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* litaC_json__JsonNode_getStr(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,const litaC_char* litaC_defaultValue);

#line 440 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_char* litaC_json__JsonNode_getStrCopy(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key,litaC_char* litaC_str,litaC_i32 litaC_len);

#line 452 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonNode_getArray(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key);

#line 461 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonNode_getObject(litaC_json__JsonNode* litaC_node,const litaC_char* litaC_key);

#line 470 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_add(litaC_json__JsonNode* litaC_node,litaC_json__JsonNode* litaC_n);

#line 476 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonNode_at(litaC_json__JsonNode* litaC_node,litaC_i32 litaC_index);

#line 484 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_i32 litaC_json__JsonNode_size(litaC_json__JsonNode* litaC_node);

#line 495 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_empty(litaC_json__JsonNode* litaC_node);

#line 500 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonNode_equals(litaC_json__JsonNode* litaC_node,litaC_json__JsonNode* litaC_other);

#line 583 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* litaC_json__JsonNode_print(litaC_json__JsonNode* litaC_node,litaC_string_buffer__StringBuffer* litaC_buf);

#line 588 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonNode_free(litaC_json__JsonNode* litaC_node);

#line 769 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonParser litaC_json__JsonParserInit(const litaC_mem__Allocator* litaC_alloc);

#line 775 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_init(litaC_json__JsonParser* litaC_p,const litaC_mem__Allocator* litaC_alloc);

#line 787 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_free(litaC_json__JsonParser* litaC_p);

#line 793 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonParser_parseJson(litaC_json__JsonParser* litaC_p,const litaC_char* litaC_buffer);

#line 811 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonParser_hasError(litaC_json__JsonParser* litaC_p);

#line 815 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__PrintJson(litaC_json__JsonNode* litaC_node,litaC_string_buffer__StringBuffer* litaC_buf);

#line 874 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonParser_parseJsonNode(litaC_json__JsonParser* litaC_p);

#line 913 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonParser_parseJsonIntNumber(litaC_json__JsonParser* litaC_p);

#line 917 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonParser_parseJsonRealNumber(litaC_json__JsonParser* litaC_p);

#line 921 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonParser_parseJsonStr(litaC_json__JsonParser* litaC_p);

#line 925 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonParser_parseJsonArray(litaC_json__JsonParser* litaC_p);

#line 940 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* litaC_json__JsonParser_parseJsonObject(litaC_json__JsonParser* litaC_p);

#line 967 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* litaC_json__TokenName(litaC_json__TokenKind litaC_t);

#line 972 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_error(litaC_json__JsonParser* litaC_p,const litaC_char* litaC_format,...);

#line 983 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_scanInt(litaC_json__JsonParser* litaC_p);

#line 1038 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_scanFloat(litaC_json__JsonParser* litaC_p);

#line 1075 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_scanStr(litaC_json__JsonParser* litaC_p);

#line 1133 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_scanMultiStr(litaC_json__JsonParser* litaC_p);

#line 1187 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_skipComments(litaC_json__JsonParser* litaC_l);

#line 1214 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_void litaC_json__JsonParser_nextToken(litaC_json__JsonParser* litaC_p);

#line 1338 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonParser_check(litaC_json__JsonParser* litaC_p,litaC_json__TokenKind litaC_kind);

#line 1342 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonParser_match(litaC_json__JsonParser* litaC_p,litaC_json__TokenKind litaC_kind);

#line 1351 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool litaC_json__JsonParser_expect(litaC_json__JsonParser* litaC_p,litaC_json__TokenKind litaC_kind);

#line 40 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Workspace_init(litaC_workspace__Workspace* litaC_this,litaC_lsp__LspServer* litaC_lsp,const litaC_mem__Allocator* litaC_alloc);

#line 46 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Workspace_setup(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_rootPath,const litaC_char* litaC_rootUri);

#line 81 "src/lsp/workspace.lita"
litaC_bool litaC_workspace__Workspace_isDocumentOpen(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_uri);

#line 87 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Workspace_openDocument(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_uri,const litaC_char* litaC_text);

#line 103 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Workspace_closeDocument(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_uri);

#line 112 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Workspace_saveDocument(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_uri);

#line 117 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Workspace_changeDocument(litaC_workspace__Workspace* litaC_this,litaC_protocol__TextDocumentDidChange* litaC_change);

#line 139 "src/lsp/workspace.lita"
litaC_json__JsonNode* litaC_workspace__Workspace_documentSymbols(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_uri,const litaC_mem__Allocator* litaC_alloc);

#line 191 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Workspace_addDocumentSymbol(litaC_workspace__Workspace* litaC_this,litaC_json__JsonNode* litaC_results,litaC_symbols__Symbol* litaC_sym,const litaC_char* litaC_docFilename,const litaC_mem__Allocator* litaC_alloc);

#line 202 "src/lsp/workspace.lita"
litaC_json__JsonNode* litaC_workspace__Workspace_references(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_uri,litaC_json__JsonNode* litaC_position,const litaC_mem__Allocator* litaC_alloc);

#line 416 "src/lsp/workspace.lita"
litaC_json__JsonNode* litaC_workspace__Workspace_findTypeReferences(litaC_workspace__Workspace* litaC_this,litaC_i64 litaC_typeid,const litaC_mem__Allocator* litaC_alloc);

#line 424 "src/lsp/workspace.lita"
litaC_json__JsonNode* litaC_workspace__Workspace_findFieldReferences(litaC_workspace__Workspace* litaC_this,litaC_i64 litaC_typeid,litaC_i32 litaC_offset,const litaC_mem__Allocator* litaC_alloc);

#line 431 "src/lsp/workspace.lita"
litaC_util__SourceLocation litaC_workspace__Workspace_getNodeAtSourcePos(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_uri,litaC_json__JsonNode* litaC_position);

#line 468 "src/lsp/workspace.lita"
litaC_json__JsonNode* litaC_workspace__Workspace_goToDefinition(litaC_workspace__Workspace* litaC_this,const litaC_char* litaC_uri,litaC_json__JsonNode* litaC_position,const litaC_mem__Allocator* litaC_alloc);

#line 754 "src/lsp/workspace.lita"
litaC_phase_result__PhaseResult* litaC_workspace__Workspace_runDiagnostics(litaC_workspace__Workspace* litaC_this,const litaC_mem__Allocator* litaC_alloc,const litaC_char* litaC_docUri);

#line 793 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Document_refreshLineMap(litaC_workspace__Document* litaC_this);
LITAC_INLINE 

#line 808 "src/lsp/workspace.lita"
litaC_u32 litaC_workspace__Document_getLineStart(litaC_workspace__Document* litaC_this,litaC_i32 litaC_lineNumber);

#line 812 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Document_insert(litaC_workspace__Document* litaC_this,litaC_protocol__Range litaC_range,const litaC_char* litaC_text);

#line 820 "src/lsp/workspace.lita"
litaC_void litaC_workspace__Document_setText(litaC_workspace__Document* litaC_this,const litaC_char* litaC_text);

#line 38 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_init(litaC_lsp__LspServer* litaC_this,litaC_lita__Lita* litaC_lita);

#line 62 "src/lsp/lsp.lita"
const litaC_mem__Allocator* litaC_lsp__LspServer_requestAlloc(litaC_lsp__LspServer* litaC_this);

#line 67 "src/lsp/lsp.lita"
const litaC_mem__Allocator* litaC_lsp__LspServer_appAlloc(litaC_lsp__LspServer* litaC_this);

#line 71 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_free(litaC_lsp__LspServer* litaC_this);

#line 87 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_start(litaC_lsp__LspServer* litaC_this);

#line 98 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_log(litaC_lsp__LspServer* litaC_this,const litaC_char* litaC_format,...);

#line 106 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_readMessage(litaC_lsp__LspServer* litaC_this);

#line 151 "src/lsp/lsp.lita"
litaC_i32 litaC_lsp__LspServer_readHeader(litaC_lsp__LspServer* litaC_this);

#line 192 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg);

#line 252 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleInitializeMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg,litaC_json__JsonNode* litaC_params);

#line 291 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleTextDocumentOpenMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg,litaC_json__JsonNode* litaC_params);

#line 302 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleTextDocumentCloseMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg,litaC_json__JsonNode* litaC_params);

#line 312 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleTextDocumentSymbolMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg,litaC_json__JsonNode* litaC_params);

#line 328 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleTextDocumentSaveMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg,litaC_json__JsonNode* litaC_params);

#line 339 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleTextDocumentChangeMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg,litaC_json__JsonNode* litaC_params);

#line 347 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleTextDocumentReferencesMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg,litaC_json__JsonNode* litaC_params);

#line 365 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_handleTextDocumentDefinitionMessage(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg,litaC_json__JsonNode* litaC_params);

#line 382 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_writeDiagnostic(litaC_lsp__LspServer* litaC_this,const litaC_char* litaC_docUri);

#line 429 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_writeErrorResponse(litaC_lsp__LspServer* litaC_this,litaC_i64 litaC_id,litaC_i32 litaC_code,const litaC_char* litaC_format,...);

#line 447 "src/lsp/lsp.lita"
litaC_void litaC_lsp__LspServer_writeResponse(litaC_lsp__LspServer* litaC_this,litaC_json__JsonNode* litaC_msg);

#line 472 "src/lsp/lsp.lita"
litaC_json__JsonNode* litaC_lsp__LspServer_createResponse(litaC_lsp__LspServer* litaC_this,litaC_i64 litaC_id);

#line 135 "src/lsp/protocol.lita"
litaC_protocol__SymbolInfoKind litaC_protocol__SymbolKindFromSymbol(litaC_symbols__Symbol* litaC_sym);

#line 206 "src/lsp/protocol.lita"
litaC_json__JsonNode* litaC_protocol__SymbolToSymbolInformation(litaC_symbols__Symbol* litaC_sym,const litaC_char* litaC_rootPath,const litaC_mem__Allocator* litaC_alloc);

#line 223 "src/lsp/protocol.lita"
litaC_json__JsonNode* litaC_protocol__SrcPosToLocation(litaC_lex__SrcPos litaC_pos,const litaC_char* litaC_rootPath,const litaC_mem__Allocator* litaC_alloc);

#line 239 "src/lsp/protocol.lita"
litaC_json__JsonNode* litaC_protocol__SrcPosWithEndToLocation(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_char* litaC_rootPath,const litaC_mem__Allocator* litaC_alloc);

#line 254 "src/lsp/protocol.lita"
litaC_json__JsonNode* litaC_protocol__SrcPosToRange(litaC_lex__SrcPos litaC_pos,const litaC_mem__Allocator* litaC_alloc);

#line 273 "src/lsp/protocol.lita"
litaC_json__JsonNode* litaC_protocol__SrcPosWithEndToRange(litaC_lex__SrcPos litaC_startPos,litaC_lex__SrcPos litaC_endPos,const litaC_mem__Allocator* litaC_alloc);

#line 293 "src/lsp/protocol.lita"
litaC_json__JsonNode* litaC_protocol__SrcPosToLocations(const litaC_char* litaC_rootPath,litaC_array__Array_cb_SrcPos_ce_* litaC_results,const litaC_mem__Allocator* litaC_alloc);

#line 308 "src/lsp/protocol.lita"
litaC_protocol__TextDocumentDidChange* litaC_protocol__JsonNodeToTextDocumentChangeEvent(litaC_json__JsonNode* litaC_params,const litaC_mem__Allocator* litaC_alloc);

#line 33 "src/lsp/util.lita"
litaC_void litaC_util__PosToRange(litaC_lex__SrcPos litaC_srcPos,litaC_protocol__Range* litaC_range);

#line 45 "src/lsp/util.lita"
litaC_bool litaC_util__IsSrcPosAtPosition(litaC_lex__SrcPos* litaC_srcPos,litaC_protocol__Position litaC_pos);

#line 72 "src/lsp/util.lita"
litaC_util__SourceLocation litaC_util__SourceLookup_findAstNodeByPosition(litaC_util__SourceLookup* litaC_this,litaC_ast__ModuleStmt* litaC_moduleAst,litaC_protocol__Position litaC_pos);

#line 82 "src/lsp/util.lita"
litaC_bool litaC_util__SourceLookup_isNodeAtPos(litaC_util__SourceLookup* litaC_this,litaC_ast__Node* litaC_node);

#line 98 "src/lsp/util.lita"
litaC_bool litaC_util__SourceLookup_isSrcAtPos(litaC_util__SourceLookup* litaC_this,litaC_lex__SrcPos* litaC_srcPos);

#line 111 "src/lsp/util.lita"
litaC_bool litaC_util__SourceLookup_isTokenAtPos(litaC_util__SourceLookup* litaC_this,litaC_lex__Token litaC_token);

#line 120 "src/lsp/util.lita"
litaC_bool litaC_util__SourceLookup_isTypeAtPos(litaC_util__SourceLookup* litaC_this,litaC_ast__TypeSpec* litaC_type);

#line 200 "src/lsp/util.lita"
litaC_bool litaC_util__SourceLookup_isDeclAtPos(litaC_util__SourceLookup* litaC_this,litaC_ast__Decl* litaC_decl);

#line 215 "src/lsp/util.lita"
litaC_bool litaC_util__SourceLookup_visitDecl(litaC_util__SourceLookup* litaC_this,litaC_ast__Decl* litaC_node);

#line 423 "src/lsp/util.lita"
litaC_bool litaC_util__SourceLookup_visitStmt(litaC_util__SourceLookup* litaC_this,litaC_ast__Stmt* litaC_node);

#line 610 "src/lsp/util.lita"
litaC_bool litaC_util__SourceLookup_visitExpr(litaC_util__SourceLookup* litaC_this,litaC_ast__Expr* litaC_node);

#line 1 "C:/Users/antho/git/litac-lang/stdlib/std/io.lita"
const litaC_char* litaC_io__FileStatusAsStr(litaC_io__FileStatus litaC_enumType);

#line 1 "src/lex.lita"
const litaC_char* litaC_lex__TokenTypeAsStr(litaC_lex__TokenType litaC_enumType);

#line 1 "src/types.lita"
const litaC_char* litaC_types__TypeKindAsStr(litaC_types__TypeKind litaC_enumType);

#line 1 "src/ast.lita"
const litaC_char* litaC_ast__StmtKindAsStr(litaC_ast__StmtKind litaC_enumType);
const litaC_char* litaC_ast__TypeSpecKindAsStr(litaC_ast__TypeSpecKind litaC_enumType);

#line 1 "src/symbols.lita"
const litaC_char* litaC_symbols__SymbolKindAsStr(litaC_symbols__SymbolKind litaC_enumType);
const litaC_char* litaC_symbols__SymbolStateAsStr(litaC_symbols__SymbolState litaC_enumType);

#line 1 "src/lita.lita"
const litaC_char* litaC_lita__MetricTypeAsStr(litaC_lita__MetricType litaC_enumType);
const litaC_char* litaC_lita__TypeInfoOptionAsStr(litaC_lita__TypeInfoOption litaC_enumType);

#line 1 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* litaC_json__JsonTypeAsStr(litaC_json__JsonType litaC_enumType);

#line 1 "src/lsp/protocol.lita"
const litaC_char* litaC_protocol__SymbolInfoKindAsStr(litaC_protocol__SymbolInfoKind litaC_enumType);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb_PhaseError_ce_(litaC_array__Array_cb_PhaseError_ce_* litaC_a);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_PhaseError_ce_(litaC_array__Array_cb_PhaseError_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_phase_result__PhaseError litaC_array__Array_get_cb_PhaseError_ce_(litaC_array__Array_cb_PhaseError_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_const_char_ce_(litaC_array__Array_cb__ptr_const_char_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_char* litaC_array__Array_get_cb__ptr_const_char_ce_(litaC_array__Array_cb__ptr_const_char_ce_* litaC_a,litaC_i32 litaC_index);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_free_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_mem__Allocation* litaC_array__Array_get_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_index);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_mem__Allocation* litaC_mem__new_cb_Allocation_ce_(const litaC_mem__Allocator* litaC_a);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_mem__Allocation* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_increment);

#line 107 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_mem__Allocation* litaC_array__Array_removeAt_cb__ptr_Allocation_ce_(litaC_array__Array_cb__ptr_Allocation_ce_* litaC_a,litaC_i32 litaC_index);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_Option_ce_ litaC_array__ArrayInit_cb_Option_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_Option_ce_(litaC_array__Array_cb_Option_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb__ptr_const_char_ce_ litaC_array__ArrayInit_cb__ptr_const_char_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_const_char_ce_(litaC_array__Array_cb__ptr_const_char_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_free_cb_Option_ce_(litaC_array__Array_cb_Option_ce_* litaC_a);
litaC_void litaC_array__Array_free_cb__ptr_const_char_ce_(litaC_array__Array_cb__ptr_const_char_ce_* litaC_a);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_Option_ce_(litaC_array__Array_cb_Option_ce_* litaC_a,litaC_cmdline__Option litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_Option_ce_(litaC_array__Array_cb_Option_ce_* litaC_a,litaC_i32 litaC_increment);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_Option_ce_(litaC_array__Array_cb_Option_ce_* litaC_a);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_const_char_ce_(litaC_array__Array_cb__ptr_const_char_ce_* litaC_a,const litaC_char* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_const_char_ce_(litaC_array__Array_cb__ptr_const_char_ce_* litaC_a,litaC_i32 litaC_increment);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb__ptr_TypeInfo_ce_ litaC_array__ArrayInit_cb__ptr_TypeInfo_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_TypeInfo_ce_(litaC_array__Array_cb__ptr_TypeInfo_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_TypeInfo_ce_(litaC_array__Array_cb__ptr_TypeInfo_ce_* litaC_a);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_TypeInfo_ce_(litaC_array__Array_cb__ptr_TypeInfo_ce_* litaC_a,litaC_types__TypeInfo* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_TypeInfo_ce_(litaC_array__Array_cb__ptr_TypeInfo_ce_* litaC_a,litaC_i32 litaC_increment);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_types__TypeInfo* litaC_array__Array_get_cb__ptr_TypeInfo_ce_(litaC_array__Array_cb__ptr_TypeInfo_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__GenericParam litaC_array__Array_get_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__ParameterDecl* litaC_array__Array_get_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb_FieldStmt_ce_(litaC_array__Array_cb_FieldStmt_ce_* litaC_a);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a,litaC_ast__TypeSpec* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a,litaC_i32 litaC_increment);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_GenericParam_ce_ litaC_array__ArrayInit_cb_GenericParam_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 143 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_addAll_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a,litaC_array__Array_cb_GenericParam_ce_* litaC_other);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a,litaC_i32 litaC_increment);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_EnumFieldEntryDecl_ce_(litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__EnumFieldEntryDecl* litaC_array__Array_get_cb__ptr_EnumFieldEntryDecl_ce_(litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_FieldStmt_ce_(litaC_array__Array_cb_FieldStmt_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__FieldStmt litaC_array__Array_get_cb_FieldStmt_ce_(litaC_array__Array_cb_FieldStmt_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a);

#line 86 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__ParameterDecl* litaC_array__Array_first_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__NameTypeSpec* litaC_mem__new_cb_NameTypeSpec_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__TypeSpec* litaC_mem__new_cb_TypeSpec_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ArrayTypeSpec* litaC_mem__new_cb_ArrayTypeSpec_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__PtrTypeSpec* litaC_mem__new_cb_PtrTypeSpec_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ConstTypeSpec* litaC_mem__new_cb_ConstTypeSpec_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__FuncPtrTypeSpec* litaC_mem__new_cb_FuncPtrTypeSpec_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ImportDecl* litaC_mem__new_cb_ImportDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__VarDecl* litaC_mem__new_cb_VarDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__FuncDecl* litaC_mem__new_cb_FuncDecl_ce_(const litaC_mem__Allocator* litaC_a);

#line 169 "src/ast.lita"
litaC_ast__ParametersStmt* litaC_ast__Node_becomeParentOf_cb_ParametersStmt_ce_(litaC_ast__Node* litaC_n,litaC_ast__ParametersStmt* litaC_child);
litaC_ast__Stmt* litaC_ast__Node_becomeParentOf_cb_Stmt_ce_(litaC_ast__Node* litaC_n,litaC_ast__Stmt* litaC_child);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__AggregateDecl* litaC_mem__new_cb_AggregateDecl_ce_(const litaC_mem__Allocator* litaC_a);

#line 169 "src/ast.lita"
litaC_ast__EnumDecl* litaC_ast__Node_becomeParentOf_cb_EnumDecl_ce_(litaC_ast__Node* litaC_n,litaC_ast__EnumDecl* litaC_child);
litaC_ast__AggregateDecl* litaC_ast__Node_becomeParentOf_cb_AggregateDecl_ce_(litaC_ast__Node* litaC_n,litaC_ast__AggregateDecl* litaC_child);
litaC_ast__TraitFieldDecl* litaC_ast__Node_becomeParentOf_cb_TraitFieldDecl_ce_(litaC_ast__Node* litaC_n,litaC_ast__TraitFieldDecl* litaC_child);
litaC_ast__VarFieldDecl* litaC_ast__Node_becomeParentOf_cb_VarFieldDecl_ce_(litaC_ast__Node* litaC_n,litaC_ast__VarFieldDecl* litaC_child);
litaC_ast__Expr* litaC_ast__Node_becomeParentOf_cb_Expr_ce_(litaC_ast__Node* litaC_n,litaC_ast__Expr* litaC_child);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__EnumDecl* litaC_mem__new_cb_EnumDecl_ce_(const litaC_mem__Allocator* litaC_a);

#line 176 "src/ast.lita"
litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_* litaC_ast__Node_becomeParentOfChildren_cb__ptr_EnumFieldEntryDecl_ce_(litaC_ast__Node* litaC_n,litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_* litaC_children);

#line 169 "src/ast.lita"
litaC_ast__EnumFieldEntryDecl* litaC_ast__Node_becomeParentOf_cb_EnumFieldEntryDecl_ce_(litaC_ast__Node* litaC_n,litaC_ast__EnumFieldEntryDecl* litaC_child);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__TypedefDecl* litaC_mem__new_cb_TypedefDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ParameterDecl* litaC_mem__new_cb_ParameterDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__NotesDecl* litaC_mem__new_cb_NotesDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__NativeDecl* litaC_mem__new_cb_NativeDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__PoisonDecl* litaC_mem__new_cb_PoisonDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__TernaryExpr* litaC_mem__new_cb_TernaryExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__BinaryExpr* litaC_mem__new_cb_BinaryExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__UnaryExpr* litaC_mem__new_cb_UnaryExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__InitExpr* litaC_mem__new_cb_InitExpr_ce_(const litaC_mem__Allocator* litaC_a);

#line 176 "src/ast.lita"
litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_ast__Node_becomeParentOfChildren_cb__ptr_InitArgExpr_ce_(litaC_ast__Node* litaC_n,litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_children);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_InitArgExpr_ce_(litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__InitArgExpr* litaC_array__Array_get_cb__ptr_InitArgExpr_ce_(litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_a,litaC_i32 litaC_index);

#line 169 "src/ast.lita"
litaC_ast__InitArgExpr* litaC_ast__Node_becomeParentOf_cb_InitArgExpr_ce_(litaC_ast__Node* litaC_n,litaC_ast__InitArgExpr* litaC_child);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__FuncCallExpr* litaC_mem__new_cb_FuncCallExpr_ce_(const litaC_mem__Allocator* litaC_a);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__CallArg litaC_array__Array_get_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_i32 litaC_index);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__SubscriptGetExpr* litaC_mem__new_cb_SubscriptGetExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__SubscriptSetExpr* litaC_mem__new_cb_SubscriptSetExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__GetExpr* litaC_mem__new_cb_GetExpr_ce_(const litaC_mem__Allocator* litaC_a);

#line 169 "src/ast.lita"
litaC_ast__IdentifierExpr* litaC_ast__Node_becomeParentOf_cb_IdentifierExpr_ce_(litaC_ast__Node* litaC_n,litaC_ast__IdentifierExpr* litaC_child);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__SetExpr* litaC_mem__new_cb_SetExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__IdentifierExpr* litaC_mem__new_cb_IdentifierExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__TypeIdentifierExpr* litaC_mem__new_cb_TypeIdentifierExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__CastExpr* litaC_mem__new_cb_CastExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ArrayDesignationExpr* litaC_mem__new_cb_ArrayDesignationExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__InitArgExpr* litaC_mem__new_cb_InitArgExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__BooleanExpr* litaC_mem__new_cb_BooleanExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__NullExpr* litaC_mem__new_cb_NullExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__NumberExpr* litaC_mem__new_cb_NumberExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__StringExpr* litaC_mem__new_cb_StringExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__CharExpr* litaC_mem__new_cb_CharExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__GroupExpr* litaC_mem__new_cb_GroupExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ArrayInitExpr* litaC_mem__new_cb_ArrayInitExpr_ce_(const litaC_mem__Allocator* litaC_a);

#line 176 "src/ast.lita"
litaC_array__Array_cb__ptr_Expr_ce_* litaC_ast__Node_becomeParentOfChildren_cb__ptr_Expr_ce_(litaC_ast__Node* litaC_n,litaC_array__Array_cb__ptr_Expr_ce_* litaC_children);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_Expr_ce_(litaC_array__Array_cb__ptr_Expr_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__Expr* litaC_array__Array_get_cb__ptr_Expr_ce_(litaC_array__Array_cb__ptr_Expr_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_Expr_ce_(litaC_array__Array_cb__ptr_Expr_ce_* litaC_a);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__SizeOfExpr* litaC_mem__new_cb_SizeOfExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__TypeOfExpr* litaC_mem__new_cb_TypeOfExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__OffsetOfExpr* litaC_mem__new_cb_OffsetOfExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__PoisonExpr* litaC_mem__new_cb_PoisonExpr_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ModuleStmt* litaC_mem__new_cb_ModuleStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__CompStmt* litaC_mem__new_cb_CompStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__BlockStmt* litaC_mem__new_cb_BlockStmt_ce_(const litaC_mem__Allocator* litaC_a);

#line 176 "src/ast.lita"
litaC_array__Array_cb__ptr_Stmt_ce_* litaC_ast__Node_becomeParentOfChildren_cb__ptr_Stmt_ce_(litaC_ast__Node* litaC_n,litaC_array__Array_cb__ptr_Stmt_ce_* litaC_children);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_Stmt_ce_(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__Stmt* litaC_array__Array_get_cb__ptr_Stmt_ce_(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_a,litaC_i32 litaC_index);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__IfStmt* litaC_mem__new_cb_IfStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__WhileStmt* litaC_mem__new_cb_WhileStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__DoWhileStmt* litaC_mem__new_cb_DoWhileStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ForStmt* litaC_mem__new_cb_ForStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__SwitchCaseStmt* litaC_mem__new_cb_SwitchCaseStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__SwitchStmt* litaC_mem__new_cb_SwitchStmt_ce_(const litaC_mem__Allocator* litaC_a);

#line 176 "src/ast.lita"
litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_* litaC_ast__Node_becomeParentOfChildren_cb__ptr_SwitchCaseStmt_ce_(litaC_ast__Node* litaC_n,litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_* litaC_children);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_SwitchCaseStmt_ce_(litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__SwitchCaseStmt* litaC_array__Array_get_cb__ptr_SwitchCaseStmt_ce_(litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_* litaC_a,litaC_i32 litaC_index);

#line 169 "src/ast.lita"
litaC_ast__SwitchCaseStmt* litaC_ast__Node_becomeParentOf_cb_SwitchCaseStmt_ce_(litaC_ast__Node* litaC_n,litaC_ast__SwitchCaseStmt* litaC_child);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__BreakStmt* litaC_mem__new_cb_BreakStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ContinueStmt* litaC_mem__new_cb_ContinueStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ReturnStmt* litaC_mem__new_cb_ReturnStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__DeferStmt* litaC_mem__new_cb_DeferStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__GotoStmt* litaC_mem__new_cb_GotoStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__LabelStmt* litaC_mem__new_cb_LabelStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__NoteStmt* litaC_mem__new_cb_NoteStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__EmptyStmt* litaC_mem__new_cb_EmptyStmt_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__ParametersStmt* litaC_mem__new_cb_ParametersStmt_ce_(const litaC_mem__Allocator* litaC_a);

#line 176 "src/ast.lita"
litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_ast__Node_becomeParentOfChildren_cb__ptr_ParameterDecl_ce_(litaC_ast__Node* litaC_n,litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_children);

#line 169 "src/ast.lita"
litaC_ast__ParameterDecl* litaC_ast__Node_becomeParentOf_cb_ParameterDecl_ce_(litaC_ast__Node* litaC_n,litaC_ast__ParameterDecl* litaC_child);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_ast__VarFieldDecl* litaC_mem__new_cb_VarFieldDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__TraitFieldDecl* litaC_mem__new_cb_TraitFieldDecl_ce_(const litaC_mem__Allocator* litaC_a);
litaC_ast__EnumFieldEntryDecl* litaC_mem__new_cb_EnumFieldEntryDecl_ce_(const litaC_mem__Allocator* litaC_a);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_NoteStmt_ce_(litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_a);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_NoteStmt_ce_(litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__NoteStmt* litaC_array__Array_get_cb__ptr_NoteStmt_ce_(litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_a,litaC_i32 litaC_index);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_symbols__Scope* litaC_mem__new_cb_Scope_ce_(const litaC_mem__Allocator* litaC_a);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* litaC_m,litaC_symbols__Symbol* litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_intern__InternedString),litaC_bool (*litaC_equalFn)(litaC_intern__InternedString,litaC_intern__InternedString),const litaC_mem__Allocator* litaC_alloc,litaC_intern__InternedString litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* litaC_m,litaC_intern__InternedString litaC_key,litaC_symbols__Symbol* litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* litaC_m);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_symbols__Symbol* litaC_map__Map_get_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* litaC_m,litaC_intern__InternedString litaC_key);

#line 228 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__Map_contains_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* litaC_m,litaC_intern__InternedString litaC_key);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_symbols__Symbol* litaC_mem__new_cb_Symbol_ce_(const litaC_mem__Allocator* litaC_a);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_ModuleImport_ce_(litaC_array__Array_cb_ModuleImport_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_module__Module* litaC_mem__new_cb_Module_ce_(const litaC_mem__Allocator* litaC_a);

#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapIterator_cb_InternedString_c__ptr_Symbol_ce_ litaC_map__Map_iter_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* litaC_m);

#line 290 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__MapIterator_hasNext_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__MapIterator_cb_InternedString_c__ptr_Symbol_ce_* litaC_iter);

#line 294 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapEntry_cb_InternedString_c__ptr_Symbol_ce_ litaC_map__MapIterator_next_cb_InternedString_c__ptr_Symbol_ce_(litaC_map__MapIterator_cb_InternedString_c__ptr_Symbol_ce_* litaC_iter);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_ModuleImport_ce_(litaC_array__Array_cb_ModuleImport_ce_* litaC_a,litaC_module__ModuleImport litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_ModuleImport_ce_(litaC_array__Array_cb_ModuleImport_ce_* litaC_a,litaC_i32 litaC_increment);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_PhaseError_ce_(litaC_array__Array_cb_PhaseError_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_PhaseError_ce_(litaC_array__Array_cb_PhaseError_ce_* litaC_a,litaC_phase_result__PhaseError litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_PhaseError_ce_(litaC_array__Array_cb_PhaseError_ce_* litaC_a,litaC_i32 litaC_increment);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_ litaC_map__StrMap_cb__ptr_Module_ce_(litaC_module__Module* litaC_emptyValue,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb__ptr_const_char_c__ptr_Module_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_* litaC_m,litaC_module__Module* litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(const litaC_char*),litaC_bool (*litaC_equalFn)(const litaC_char*,const litaC_char*),const litaC_mem__Allocator* litaC_alloc,const litaC_char* litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb__ptr_const_char_c__ptr_Module_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb__ptr_const_char_c__ptr_Module_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_* litaC_m,const litaC_char* litaC_key,litaC_module__Module* litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb__ptr_const_char_c__ptr_Module_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_* litaC_m);

#line 58 "src/intern.lita"
litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_ litaC_intern__InternMap_cb__ptr_Symbol_ce_(litaC_symbols__Symbol* litaC_emptyValue,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_allocator);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_workspace__Document* litaC_map__Map_get_cb__ptr_const_char_c__ptr_Document_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_* litaC_m,const litaC_char* litaC_key);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_ImportDecl_ce_(litaC_array__Array_cb__ptr_ImportDecl_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__ImportDecl* litaC_array__Array_get_cb__ptr_ImportDecl_ce_(litaC_array__Array_cb__ptr_ImportDecl_ce_* litaC_a,litaC_i32 litaC_index);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_module__Module* litaC_map__Map_get_cb__ptr_const_char_c__ptr_Module_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_* litaC_m,const litaC_char* litaC_key);

#line 271 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__GenericMalloc_cb_BucketAllocator_ce_(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_size);

#line 277 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__GenericCalloc_cb_BucketAllocator_ce_(const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_num,litaC_usize litaC_size);

#line 289 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* litaC_mem__GenericRealloc_cb_BucketAllocator_ce_(const litaC_mem__Allocator* litaC_alloc,litaC_void* litaC_ptr,litaC_usize litaC_oldSize,litaC_usize litaC_size);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_CompStmt_ce_(litaC_array__Array_cb__ptr_CompStmt_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_CompStmt_ce_(litaC_array__Array_cb__ptr_CompStmt_ce_* litaC_a,litaC_ast__CompStmt* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_CompStmt_ce_(litaC_array__Array_cb__ptr_CompStmt_ce_* litaC_a,litaC_i32 litaC_increment);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_ImportDecl_ce_(litaC_array__Array_cb__ptr_ImportDecl_ce_* litaC_a,litaC_ast__ImportDecl* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_ImportDecl_ce_(litaC_array__Array_cb__ptr_ImportDecl_ce_* litaC_a,litaC_i32 litaC_increment);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_NoteStmt_ce_(litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_a,litaC_ast__NoteStmt* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_NoteStmt_ce_(litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_a,litaC_i32 litaC_increment);

#line 143 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_addAll_cb__ptr_NoteStmt_ce_(litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_a,litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_other);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Decl_ce_(litaC_array__Array_cb__ptr_Decl_ce_* litaC_a,litaC_ast__Decl* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Decl_ce_(litaC_array__Array_cb__ptr_Decl_ce_* litaC_a,litaC_i32 litaC_increment);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_CompStmt_ce_(litaC_array__Array_cb__ptr_CompStmt_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__CompStmt* litaC_array__Array_get_cb__ptr_CompStmt_ce_(litaC_array__Array_cb__ptr_CompStmt_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_Token_ce_(litaC_array__Array_cb_Token_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_lex__Token litaC_array__Array_get_cb_Token_ce_(litaC_array__Array_cb_Token_ce_* litaC_a,litaC_i32 litaC_index);

#line 143 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_addAll_cb__ptr_ImportDecl_ce_(litaC_array__Array_cb__ptr_ImportDecl_ce_* litaC_a,litaC_array__Array_cb__ptr_ImportDecl_ce_* litaC_other);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_Decl_ce_(litaC_array__Array_cb__ptr_Decl_ce_* litaC_a);

#line 143 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_addAll_cb__ptr_Decl_ce_(litaC_array__Array_cb__ptr_Decl_ce_* litaC_a,litaC_array__Array_cb__ptr_Decl_ce_* litaC_other);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_Symbol_ce_(litaC_array__Array_cb__ptr_Symbol_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_symbols__Symbol* litaC_array__Array_get_cb__ptr_Symbol_ce_(litaC_array__Array_cb__ptr_Symbol_ce_* litaC_a,litaC_i32 litaC_index);
litaC_ast__Decl* litaC_array__Array_get_cb__ptr_Decl_ce_(litaC_array__Array_cb__ptr_Decl_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_ModuleImport_ce_(litaC_array__Array_cb_ModuleImport_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_module__ModuleImport litaC_array__Array_get_cb_ModuleImport_ce_(litaC_array__Array_cb_ModuleImport_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__TypeSpec* litaC_array__Array_get_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a,litaC_i32 litaC_index);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a,litaC_ast__GenericParam litaC_element);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_CallArg_ce_ litaC_array__ArrayInit_cb_CallArg_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_ast__CallArg litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_i32 litaC_increment);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb__ptr_Expr_ce_ litaC_array__ArrayInit_cb__ptr_Expr_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_Expr_ce_(litaC_array__Array_cb__ptr_Expr_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Expr_ce_(litaC_array__Array_cb__ptr_Expr_ce_* litaC_a,litaC_ast__Expr* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Expr_ce_(litaC_array__Array_cb__ptr_Expr_ce_* litaC_a,litaC_i32 litaC_increment);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_Stmt_ce_(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_a);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb__ptr_Stmt_ce_ litaC_array__ArrayInit_cb__ptr_Stmt_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_Stmt_ce_(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Stmt_ce_(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_a,litaC_ast__Stmt* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Stmt_ce_(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_a,litaC_i32 litaC_increment);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_InitArgExpr_ce_(litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_a);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_InitArgExpr_ce_(litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_InitArgExpr_ce_(litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_a,litaC_ast__InitArgExpr* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_InitArgExpr_ce_(litaC_array__Array_cb__ptr_InitArgExpr_ce_* litaC_a,litaC_i32 litaC_increment);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a,litaC_ast__ParameterDecl* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a,litaC_i32 litaC_increment);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_SwitchCaseStmt_ce_(litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_* litaC_a);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_SwitchCaseStmt_ce_(litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_SwitchCaseStmt_ce_(litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_* litaC_a,litaC_ast__SwitchCaseStmt* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_SwitchCaseStmt_ce_(litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_* litaC_a,litaC_i32 litaC_increment);

#line 188 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_GenericParam_ce_ litaC_array__Array_copy_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a,const litaC_mem__Allocator* litaC_allocator);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_FieldStmt_ce_ litaC_array__ArrayInit_cb_FieldStmt_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_FieldStmt_ce_(litaC_array__Array_cb_FieldStmt_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_FieldStmt_ce_(litaC_array__Array_cb_FieldStmt_ce_* litaC_a,litaC_ast__FieldStmt litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_FieldStmt_ce_(litaC_array__Array_cb_FieldStmt_ce_* litaC_a,litaC_i32 litaC_increment);

#line 121 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_insertAt_cb__ptr_Stmt_ce_(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_a,litaC_i32 litaC_index,litaC_ast__Stmt* litaC_element);

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_set_cb__ptr_Stmt_ce_(litaC_array__Array_cb__ptr_Stmt_ce_* litaC_a,litaC_i32 litaC_index,litaC_ast__Stmt* litaC_element);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_Module_ce_(litaC_array__Array_cb__ptr_Module_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);
litaC_void litaC_array__Array_init_cb__ptr_FuncTypeInfo_ce_(litaC_array__Array_cb__ptr_FuncTypeInfo_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);
litaC_void litaC_array__Array_init_cb__ptr_Symbol_ce_(litaC_array__Array_cb__ptr_Symbol_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);
litaC_void litaC_array__Array_init_cb_Array_cb_GenericParam_ce__ce_(litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 litaC_map__PtrHashFn_cb_i64_ce_(litaC_i64 litaC_a);

#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__PtrEqualFn_cb_i64_ce_(litaC_i64 litaC_a,litaC_i64 litaC_b);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* litaC_m,litaC_array__Array_cb_i64_ce_ litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_i64),litaC_bool (*litaC_equalFn)(litaC_i64,litaC_i64),const litaC_mem__Allocator* litaC_alloc,litaC_i64 litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* litaC_m,litaC_i64 litaC_key,litaC_array__Array_cb_i64_ce_ litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* litaC_m);

#line 107 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__Decl* litaC_array__Array_removeAt_cb__ptr_Decl_ce_(litaC_array__Array_cb__ptr_Decl_ce_* litaC_a,litaC_i32 litaC_index);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_push_cb__ptr_Module_ce_(litaC_array__Array_cb__ptr_Module_ce_* litaC_a,litaC_module__Module* litaC_element);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Module_ce_(litaC_array__Array_cb__ptr_Module_ce_* litaC_a,litaC_module__Module* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Module_ce_(litaC_array__Array_cb__ptr_Module_ce_* litaC_a,litaC_i32 litaC_increment);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_Module_ce_(litaC_array__Array_cb__ptr_Module_ce_* litaC_a);

#line 98 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_module__Module* litaC_array__Array_pop_cb__ptr_Module_ce_(litaC_array__Array_cb__ptr_Module_ce_* litaC_a);

#line 92 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_module__Module* litaC_array__Array_last_cb__ptr_Module_ce_(litaC_array__Array_cb__ptr_Module_ce_* litaC_a);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_Array_cb_GenericParam_ce__ce_(litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_* litaC_a);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Symbol_ce_(litaC_array__Array_cb__ptr_Symbol_ce_* litaC_a,litaC_symbols__Symbol* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Symbol_ce_(litaC_array__Array_cb__ptr_Symbol_ce_* litaC_a,litaC_i32 litaC_increment);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_Array_cb_GenericParam_ce__ce_(litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_* litaC_a,litaC_array__Array_cb_GenericParam_ce_ litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_Array_cb_GenericParam_ce__ce_(litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_* litaC_a,litaC_i32 litaC_increment);

#line 98 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_GenericParam_ce_ litaC_array__Array_pop_cb_Array_cb_GenericParam_ce__ce_(litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_* litaC_a);

#line 228 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__Map_contains_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* litaC_m,litaC_i64 litaC_key);

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_i64_ce_* litaC_map__Map_getPtr_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* litaC_m,litaC_i64 litaC_key);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_i64_ce_(litaC_array__Array_cb_i64_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i64 litaC_array__Array_get_cb_i64_ce_(litaC_array__Array_cb_i64_ce_* litaC_a,litaC_i32 litaC_index);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_i64_ce_ litaC_array__ArrayInit_cb_i64_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_i64_ce_(litaC_array__Array_cb_i64_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_i64_ce_(litaC_array__Array_cb_i64_ce_* litaC_a,litaC_i64 litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_i64_ce_(litaC_array__Array_cb_i64_ce_* litaC_a,litaC_i32 litaC_increment);

#line 92 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_types__FuncTypeInfo* litaC_array__Array_last_cb__ptr_FuncTypeInfo_ce_(litaC_array__Array_cb__ptr_FuncTypeInfo_ce_* litaC_a);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb_i64_c__ptr_ConstTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_* litaC_m,litaC_types__ConstTypeInfo* litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_i64),litaC_bool (*litaC_equalFn)(litaC_i64,litaC_i64),const litaC_mem__Allocator* litaC_alloc,litaC_i64 litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb_i64_c__ptr_ConstTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb_i64_c__ptr_ConstTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_* litaC_m,litaC_i64 litaC_key,litaC_types__ConstTypeInfo* litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb_i64_c__ptr_ConstTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_* litaC_m);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb_i64_c__ptr_PtrTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_* litaC_m,litaC_types__PtrTypeInfo* litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_i64),litaC_bool (*litaC_equalFn)(litaC_i64,litaC_i64),const litaC_mem__Allocator* litaC_alloc,litaC_i64 litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb_i64_c__ptr_PtrTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb_i64_c__ptr_PtrTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_* litaC_m,litaC_i64 litaC_key,litaC_types__PtrTypeInfo* litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb_i64_c__ptr_PtrTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_* litaC_m);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_(litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* litaC_m,litaC_types__ArrayTypeInfo* litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_types_new__ArrayEntry),litaC_bool (*litaC_equalFn)(litaC_types_new__ArrayEntry,litaC_types_new__ArrayEntry),const litaC_mem__Allocator* litaC_alloc,litaC_types_new__ArrayEntry litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_(litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_(litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* litaC_m,litaC_types_new__ArrayEntry litaC_key,litaC_types__ArrayTypeInfo* litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_(litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* litaC_m);

#line 58 "src/intern.lita"
litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_ litaC_intern__InternMap_cb__ptr_TypeInfo_ce_(litaC_types__TypeInfo* litaC_emptyValue,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_allocator);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb_InternedString_c__ptr_TypeInfo_ce_(litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_* litaC_m,litaC_types__TypeInfo* litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_intern__InternedString),litaC_bool (*litaC_equalFn)(litaC_intern__InternedString,litaC_intern__InternedString),const litaC_mem__Allocator* litaC_alloc,litaC_intern__InternedString litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb_InternedString_c__ptr_TypeInfo_ce_(litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb_InternedString_c__ptr_TypeInfo_ce_(litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_* litaC_m,litaC_intern__InternedString litaC_key,litaC_types__TypeInfo* litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb_InternedString_c__ptr_TypeInfo_ce_(litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_* litaC_m);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__TypeInfo* litaC_map__Map_get_cb_InternedString_c__ptr_TypeInfo_ce_(litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_* litaC_m,litaC_intern__InternedString litaC_key);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_types__TypeInfo* litaC_mem__new_cb_TypeInfo_ce_(const litaC_mem__Allocator* litaC_a);
litaC_types__FuncTypeInfo* litaC_mem__new_cb_FuncTypeInfo_ce_(const litaC_mem__Allocator* litaC_a);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ArrayTypeInfo* litaC_map__Map_get_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_(litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* litaC_m,litaC_types_new__ArrayEntry litaC_key);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_types__ArrayTypeInfo* litaC_mem__new_cb_ArrayTypeInfo_ce_(const litaC_mem__Allocator* litaC_a);
litaC_types__FuncPtrTypeInfo* litaC_mem__new_cb_FuncPtrTypeInfo_ce_(const litaC_mem__Allocator* litaC_a);
litaC_types__AggregateTypeInfo* litaC_mem__new_cb_AggregateTypeInfo_ce_(const litaC_mem__Allocator* litaC_a);
litaC_types__EnumTypeInfo* litaC_mem__new_cb_EnumTypeInfo_ce_(const litaC_mem__Allocator* litaC_a);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ConstTypeInfo* litaC_map__Map_get_cb_i64_c__ptr_ConstTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_* litaC_m,litaC_i64 litaC_key);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_types__ConstTypeInfo* litaC_mem__new_cb_ConstTypeInfo_ce_(const litaC_mem__Allocator* litaC_a);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__PtrTypeInfo* litaC_map__Map_get_cb_i64_c__ptr_PtrTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_* litaC_m,litaC_i64 litaC_key);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_types__PtrTypeInfo* litaC_mem__new_cb_PtrTypeInfo_ce_(const litaC_mem__Allocator* litaC_a);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb_StringView_c_InternedString_ce_ litaC_map__StringViewMap_cb_InternedString_ce_(litaC_intern__InternedString litaC_emptyValue,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb_StringView_c_InternedString_ce_(litaC_map__Map_cb_StringView_c_InternedString_ce_* litaC_m,litaC_intern__InternedString litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_string_view__StringView),litaC_bool (*litaC_equalFn)(litaC_string_view__StringView,litaC_string_view__StringView),const litaC_mem__Allocator* litaC_alloc,litaC_string_view__StringView litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb_StringView_c_InternedString_ce_(litaC_map__Map_cb_StringView_c_InternedString_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb_StringView_c_InternedString_ce_(litaC_map__Map_cb_StringView_c_InternedString_ce_* litaC_m,litaC_string_view__StringView litaC_key,litaC_intern__InternedString litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb_StringView_c_InternedString_ce_(litaC_map__Map_cb_StringView_c_InternedString_ce_* litaC_m);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_intern__InternedString litaC_map__Map_get_cb_StringView_c_InternedString_ce_(litaC_map__Map_cb_StringView_c_InternedString_ce_* litaC_m,litaC_string_view__StringView litaC_key);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb_Token_ce_(litaC_array__Array_cb_Token_ce_* litaC_a);

#line 107 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__GenericParam litaC_array__Array_removeAt_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a,litaC_i32 litaC_index);

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_set_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a,litaC_i32 litaC_index,litaC_ast__TypeSpec* litaC_element);

#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapIterator_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ litaC_map__Map_iter_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_(litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* litaC_m);

#line 290 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__MapIterator_hasNext_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_(litaC_map__MapIterator_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* litaC_iter);

#line 294 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapEntry_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ litaC_map__MapIterator_next_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_(litaC_map__MapIterator_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* litaC_iter);

#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapIterator_cb_i64_c__ptr_PtrTypeInfo_ce_ litaC_map__Map_iter_cb_i64_c__ptr_PtrTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_* litaC_m);

#line 290 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__MapIterator_hasNext_cb_i64_c__ptr_PtrTypeInfo_ce_(litaC_map__MapIterator_cb_i64_c__ptr_PtrTypeInfo_ce_* litaC_iter);

#line 294 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapEntry_cb_i64_c__ptr_PtrTypeInfo_ce_ litaC_map__MapIterator_next_cb_i64_c__ptr_PtrTypeInfo_ce_(litaC_map__MapIterator_cb_i64_c__ptr_PtrTypeInfo_ce_* litaC_iter);

#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapIterator_cb_i64_c__ptr_ConstTypeInfo_ce_ litaC_map__Map_iter_cb_i64_c__ptr_ConstTypeInfo_ce_(litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_* litaC_m);

#line 290 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__MapIterator_hasNext_cb_i64_c__ptr_ConstTypeInfo_ce_(litaC_map__MapIterator_cb_i64_c__ptr_ConstTypeInfo_ce_* litaC_iter);

#line 294 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapEntry_cb_i64_c__ptr_ConstTypeInfo_ce_ litaC_map__MapIterator_next_cb_i64_c__ptr_ConstTypeInfo_ce_(litaC_map__MapIterator_cb_i64_c__ptr_ConstTypeInfo_ce_* litaC_iter);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_FuncTypeInfo_ce_(litaC_array__Array_cb__ptr_FuncTypeInfo_ce_* litaC_a,litaC_types__FuncTypeInfo* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_FuncTypeInfo_ce_(litaC_array__Array_cb__ptr_FuncTypeInfo_ce_* litaC_a,litaC_i32 litaC_increment);

#line 98 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_types__FuncTypeInfo* litaC_array__Array_pop_cb__ptr_FuncTypeInfo_ce_(litaC_array__Array_cb__ptr_FuncTypeInfo_ce_* litaC_a);

#line 121 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_insertAt_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_i32 litaC_index,litaC_ast__CallArg litaC_element);

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_set_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_i32 litaC_index,litaC_ast__CallArg litaC_element);

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__CallArg* litaC_array__Array_getPtr_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_i32 litaC_index);

#line 143 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_addAll_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_array__Array_cb_CallArg_ce_* litaC_other);

#line 184 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_sort_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_a,litaC_i32 (*litaC_sorter)(litaC_ast__CallArg,litaC_ast__CallArg));

#line 212 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__QuickSort_cb_CallArg_ce_(litaC_array__Array_cb_CallArg_ce_* litaC_array,litaC_i32 (*litaC_comp)(litaC_ast__CallArg,litaC_ast__CallArg));

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_Token_ce_(litaC_array__Array_cb_Token_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_Token_ce_(litaC_array__Array_cb_Token_ce_* litaC_a,litaC_lex__Token litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_Token_ce_(litaC_array__Array_cb_Token_ce_* litaC_a,litaC_i32 litaC_increment);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_ImportDecl_ce_(litaC_array__Array_cb__ptr_ImportDecl_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);
litaC_void litaC_array__Array_init_cb__ptr_NoteStmt_ce_(litaC_array__Array_cb__ptr_NoteStmt_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);
litaC_void litaC_array__Array_init_cb__ptr_Decl_ce_(litaC_array__Array_cb__ptr_Decl_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 92 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__Decl* litaC_array__Array_last_cb__ptr_Decl_ce_(litaC_array__Array_cb__ptr_Decl_ce_* litaC_a);

#line 121 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_insertAt_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a,litaC_i32 litaC_index,litaC_ast__ParameterDecl* litaC_element);

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_set_cb__ptr_ParameterDecl_ce_(litaC_array__Array_cb__ptr_ParameterDecl_ce_* litaC_a,litaC_i32 litaC_index,litaC_ast__ParameterDecl* litaC_element);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_EnumFieldEntryDecl_ce_(litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_EnumFieldEntryDecl_ce_(litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_* litaC_a,litaC_ast__EnumFieldEntryDecl* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_EnumFieldEntryDecl_ce_(litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_* litaC_a,litaC_i32 litaC_increment);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_free_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a);
LITAC_INLINE 

#line 177 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_clear_cb__ptr_TypeSpec_ce_(litaC_array__Array_cb__ptr_TypeSpec_ce_* litaC_a);

#line 92 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_lex__Token litaC_array__Array_last_cb_Token_ce_(litaC_array__Array_cb_Token_ce_* litaC_a);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb__ptr_Decl_ce_ litaC_array__ArrayInit_cb__ptr_Decl_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);
LITAC_INLINE 

#line 116 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 litaC_map__Map_size_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* litaC_m);

#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapIterator_cb_i64_c_Array_cb_i64_ce__ce_ litaC_map__Map_iter_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* litaC_m);

#line 290 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__MapIterator_hasNext_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__MapIterator_cb_i64_c_Array_cb_i64_ce__ce_* litaC_iter);

#line 294 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapEntry_cb_i64_c_Array_cb_i64_ce__ce_ litaC_map__MapIterator_next_cb_i64_c_Array_cb_i64_ce__ce_(litaC_map__MapIterator_cb_i64_c_Array_cb_i64_ce__ce_* litaC_iter);

#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapIterator_cb__ptr_const_char_c__ptr_Module_ce_ litaC_map__Map_iter_cb__ptr_const_char_c__ptr_Module_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_* litaC_m);

#line 290 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__MapIterator_hasNext_cb__ptr_const_char_c__ptr_Module_ce_(litaC_map__MapIterator_cb__ptr_const_char_c__ptr_Module_ce_* litaC_iter);

#line 294 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapEntry_cb__ptr_const_char_c__ptr_Module_ce_ litaC_map__MapIterator_next_cb__ptr_const_char_c__ptr_Module_ce_(litaC_map__MapIterator_cb__ptr_const_char_c__ptr_Module_ce_* litaC_iter);

#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 litaC_map__PtrHashFn_cb__ptr_Symbol_ce_(litaC_symbols__Symbol* litaC_a);

#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__PtrEqualFn_cb__ptr_Symbol_ce_(litaC_symbols__Symbol* litaC_a,litaC_symbols__Symbol* litaC_b);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_* litaC_m,litaC_dependency_graph__Dependency litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_symbols__Symbol*),litaC_bool (*litaC_equalFn)(litaC_symbols__Symbol*,litaC_symbols__Symbol*),const litaC_mem__Allocator* litaC_alloc,litaC_symbols__Symbol* litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_* litaC_m,litaC_symbols__Symbol* litaC_key,litaC_dependency_graph__Dependency litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_* litaC_m);

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_dependency_graph__Dependency* litaC_map__Map_getPtr_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_* litaC_m,litaC_symbols__Symbol* litaC_key);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_Dependency_ce_(litaC_array__Array_cb__ptr_Dependency_ce_* litaC_a,litaC_dependency_graph__Dependency* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_Dependency_ce_(litaC_array__Array_cb__ptr_Dependency_ce_* litaC_a,litaC_i32 litaC_increment);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_Dependency_ce_(litaC_array__Array_cb__ptr_Dependency_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 282 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapIterator_cb__ptr_Symbol_c_Dependency_ce_ litaC_map__Map_iter_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_* litaC_m);

#line 290 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__MapIterator_hasNext_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__MapIterator_cb__ptr_Symbol_c_Dependency_ce_* litaC_iter);

#line 294 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__MapEntry_cb__ptr_Symbol_c_Dependency_ce_ litaC_map__MapIterator_next_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__MapIterator_cb__ptr_Symbol_c_Dependency_ce_* litaC_iter);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_Dependency_ce_(litaC_array__Array_cb__ptr_Dependency_ce_* litaC_a);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_dependency_graph__Dependency* litaC_array__Array_get_cb__ptr_Dependency_ce_(litaC_array__Array_cb__ptr_Dependency_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 116 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 litaC_map__Map_size_cb__ptr_Symbol_c_Dependency_ce_(litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_* litaC_m);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_Dependency_ce_(litaC_array__Array_cb__ptr_Dependency_ce_* litaC_a);

#line 143 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_addAll_cb__ptr_Dependency_ce_(litaC_array__Array_cb__ptr_Dependency_ce_* litaC_a,litaC_array__Array_cb__ptr_Dependency_ce_* litaC_other);
LITAC_INLINE 

#line 177 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_clear_cb__ptr_Symbol_ce_(litaC_array__Array_cb__ptr_Symbol_ce_* litaC_a);

#line 143 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_addAll_cb__ptr_Symbol_ce_(litaC_array__Array_cb__ptr_Symbol_ce_* litaC_a,litaC_array__Array_cb__ptr_Symbol_ce_* litaC_other);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb__ptr_const_char_ce_(litaC_array__Array_cb__ptr_const_char_ce_* litaC_a);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_Reference_ce_(litaC_array__Array_cb_Reference_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);
litaC_void litaC_array__Array_init_cb_FieldReference_ce_(litaC_array__Array_cb_FieldReference_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 litaC_map__PtrHashFn_cb_usize_ce_(litaC_usize litaC_a);

#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__PtrEqualFn_cb_usize_ce_(litaC_usize litaC_a,litaC_usize litaC_b);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb_usize_c_Array_cb_SrcPos_ce__ce_(litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_* litaC_m,litaC_array__Array_cb_SrcPos_ce_ litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(litaC_usize),litaC_bool (*litaC_equalFn)(litaC_usize,litaC_usize),const litaC_mem__Allocator* litaC_alloc,litaC_usize litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb_usize_c_Array_cb_SrcPos_ce__ce_(litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb_usize_c_Array_cb_SrcPos_ce__ce_(litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_* litaC_m,litaC_usize litaC_key,litaC_array__Array_cb_SrcPos_ce_ litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb_usize_c_Array_cb_SrcPos_ce__ce_(litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_* litaC_m);

#line 228 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__Map_contains_cb_usize_c_Array_cb_SrcPos_ce__ce_(litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_* litaC_m,litaC_usize litaC_key);

#line 15 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_SrcPos_ce_ litaC_array__ArrayInit_cb_SrcPos_ce_(litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_SrcPos_ce_(litaC_array__Array_cb_SrcPos_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_SrcPos_ce_* litaC_map__Map_getPtr_cb_usize_c_Array_cb_SrcPos_ce__ce_(litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_* litaC_m,litaC_usize litaC_key);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_SrcPos_ce_(litaC_array__Array_cb_SrcPos_ce_* litaC_a,litaC_lex__SrcPos litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_SrcPos_ce_(litaC_array__Array_cb_SrcPos_ce_* litaC_a,litaC_i32 litaC_increment);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_Reference_ce_(litaC_array__Array_cb_Reference_ce_* litaC_a,litaC_references__Reference litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_Reference_ce_(litaC_array__Array_cb_Reference_ce_* litaC_a,litaC_i32 litaC_increment);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_FieldReference_ce_(litaC_array__Array_cb_FieldReference_ce_* litaC_a,litaC_references__FieldReference litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_FieldReference_ce_(litaC_array__Array_cb_FieldReference_ce_* litaC_a,litaC_i32 litaC_increment);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_SrcPos_ce_ litaC_map__Map_get_cb_usize_c_Array_cb_SrcPos_ce__ce_(litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_* litaC_m,litaC_usize litaC_key);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_Reference_ce_(litaC_array__Array_cb_Reference_ce_* litaC_a);

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_references__Reference* litaC_array__Array_getPtr_cb_Reference_ce_(litaC_array__Array_cb_Reference_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_FieldReference_ce_(litaC_array__Array_cb_FieldReference_ce_* litaC_a);

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_references__FieldReference* litaC_array__Array_getPtr_cb_FieldReference_ce_(litaC_array__Array_cb_FieldReference_ce_* litaC_a,litaC_i32 litaC_index);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_json__JsonNode* litaC_mem__new_cb_JsonNode_ce_(const litaC_mem__Allocator* litaC_a);
litaC_array__Array_cb__ptr_JsonNode_ce_* litaC_mem__new_cb_Array_cb__ptr_JsonNode_ce__ce_(const litaC_mem__Allocator* litaC_a);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb__ptr_JsonNode_ce_(litaC_array__Array_cb__ptr_JsonNode_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_json__JsonObject* litaC_mem__new_cb_JsonObject_ce_(const litaC_mem__Allocator* litaC_a);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb__ptr_const_char_c_i32_ce_(litaC_map__Map_cb__ptr_const_char_c_i32_ce_* litaC_m,litaC_i32 litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(const litaC_char*),litaC_bool (*litaC_equalFn)(const litaC_char*,const litaC_char*),const litaC_mem__Allocator* litaC_alloc,const litaC_char* litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb__ptr_const_char_c_i32_ce_(litaC_map__Map_cb__ptr_const_char_c_i32_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb__ptr_const_char_c_i32_ce_(litaC_map__Map_cb__ptr_const_char_c_i32_ce_* litaC_m,const litaC_char* litaC_key,litaC_i32 litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb__ptr_const_char_c_i32_ce_(litaC_map__Map_cb__ptr_const_char_c_i32_ce_* litaC_m);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_Entry_ce_(litaC_array__Array_cb_Entry_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_Entry_ce_(litaC_array__Array_cb_Entry_ce_* litaC_a,litaC_json__Entry litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_Entry_ce_(litaC_array__Array_cb_Entry_ce_* litaC_a,litaC_i32 litaC_increment);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_Entry_ce_(litaC_array__Array_cb_Entry_ce_* litaC_a);

#line 228 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__Map_contains_cb__ptr_const_char_c_i32_ce_(litaC_map__Map_cb__ptr_const_char_c_i32_ce_* litaC_m,const litaC_char* litaC_key);

#line 151 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 litaC_map__Map_get_cb__ptr_const_char_c_i32_ce_(litaC_map__Map_cb__ptr_const_char_c_i32_ce_* litaC_m,const litaC_char* litaC_key);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_json__Entry litaC_array__Array_get_cb_Entry_ce_(litaC_array__Array_cb_Entry_ce_* litaC_a,litaC_i32 litaC_index);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb__ptr_JsonNode_ce_(litaC_array__Array_cb__ptr_JsonNode_ce_* litaC_a,litaC_json__JsonNode* litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb__ptr_JsonNode_ce_(litaC_array__Array_cb__ptr_JsonNode_ce_* litaC_a,litaC_i32 litaC_increment);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_json__JsonNode* litaC_array__Array_get_cb__ptr_JsonNode_ce_(litaC_array__Array_cb__ptr_JsonNode_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb__ptr_JsonNode_ce_(litaC_array__Array_cb__ptr_JsonNode_ce_* litaC_a);
LITAC_INLINE 

#line 116 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 litaC_map__Map_size_cb__ptr_const_char_c_i32_ce_(litaC_map__Map_cb__ptr_const_char_c_i32_ce_* litaC_m);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_free_cb__ptr_JsonNode_ce_(litaC_array__Array_cb__ptr_JsonNode_ce_* litaC_a);
litaC_void litaC_array__Array_free_cb_Entry_ce_(litaC_array__Array_cb_Entry_ce_* litaC_a);

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_ litaC_map__StrMap_cb__ptr_Document_ce_(litaC_workspace__Document* litaC_emptyValue,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_init_cb__ptr_const_char_c__ptr_Document_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_* litaC_m,litaC_workspace__Document* litaC_emptyValue,litaC_i32 litaC_initialSize,litaC_u32 (*litaC_hashFn)(const litaC_char*),litaC_bool (*litaC_equalFn)(const litaC_char*,const litaC_char*),const litaC_mem__Allocator* litaC_alloc,const litaC_char* litaC_emptyKey);

#line 250 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__MapGrow_cb__ptr_const_char_c__ptr_Document_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_* litaC_m,litaC_i32 litaC_newlength);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_put_cb__ptr_const_char_c__ptr_Document_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_* litaC_m,const litaC_char* litaC_key,litaC_workspace__Document* litaC_value);

#line 103 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_void litaC_map__Map_free_cb__ptr_const_char_c__ptr_Document_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_* litaC_m);

#line 228 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool litaC_map__Map_contains_cb__ptr_const_char_c__ptr_Document_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_* litaC_m,const litaC_char* litaC_key);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_workspace__Document* litaC_mem__new_cb_Document_ce_(const litaC_mem__Allocator* litaC_a);

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_init_cb_u32_ce_(litaC_array__Array_cb_u32_ce_* litaC_a,litaC_i32 litaC_initialSize,const litaC_mem__Allocator* litaC_alloc);

#line 203 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_workspace__Document* litaC_map__Map_remove_cb__ptr_const_char_c__ptr_Document_ce_(litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_* litaC_m,const litaC_char* litaC_key);
LITAC_INLINE 

#line 177 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_clear_cb_u32_ce_(litaC_array__Array_cb_u32_ce_* litaC_a);

#line 46 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__Array_add_cb_u32_ce_(litaC_array__Array_cb_u32_ce_* litaC_a,litaC_u32 litaC_element);

#line 195 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_void litaC_array__ArrayGrow_cb_u32_ce_(litaC_array__Array_cb_u32_ce_* litaC_a,litaC_i32 litaC_increment);

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_u32 litaC_array__Array_get_cb_u32_ce_(litaC_array__Array_cb_u32_ce_* litaC_a,litaC_i32 litaC_index);
LITAC_INLINE 

#line 167 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_bool litaC_array__Array_empty_cb_SrcPos_ce_(litaC_array__Array_cb_SrcPos_ce_* litaC_a);
LITAC_INLINE 

#line 172 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 litaC_array__Array_size_cb_SrcPos_ce_(litaC_array__Array_cb_SrcPos_ce_* litaC_a);

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_lex__SrcPos* litaC_array__Array_getPtr_cb_SrcPos_ce_(litaC_array__Array_cb_SrcPos_ce_* litaC_a,litaC_i32 litaC_index);

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_protocol__TextDocumentDidChange* litaC_mem__new_cb_TextDocumentDidChange_ce_(const litaC_mem__Allocator* litaC_a);

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__GenericParam* litaC_array__Array_getPtr_cb_GenericParam_ce_(litaC_array__Array_cb_GenericParam_ce_* litaC_a,litaC_i32 litaC_index);
litaC_ast__FieldStmt* litaC_array__Array_getPtr_cb_FieldStmt_ce_(litaC_array__Array_cb_FieldStmt_ce_* litaC_a,litaC_i32 litaC_index);


// Generated code for interfaces

#endif /* _LITAC_HEADER_H */


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// translated code begins
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



#line 30 "src/lsp/protocol.lita"
struct litaC_protocol__TextDocument {
#line 31 "src/lsp/protocol.lita"
const litaC_char* uri;

#line 32 "src/lsp/protocol.lita"
litaC_u32 version;
};


#line 27 "src/lsp/util.lita"


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_Dependency_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_dependency_graph__Dependency** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 535 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
struct litaC_system__Process {
#line 536 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
FILE* pipe;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_GenericParam_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__GenericParam* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_i64);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_i64,litaC_i64);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64* keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__PtrTypeInfo** values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__PtrTypeInfo* emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64 emptyKey;
};


#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapIterator_cb_i64_c_Array_cb_i64_ce__ce_ {
#line 68 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_* m;

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 it;

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 count;
};


#line 5 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
struct litaC_string_view__StringView {
#line 6 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
const litaC_char* buffer;

#line 7 "C:/Users/antho/git/litac-lang/stdlib/std/string_view.lita"
litaC_i32 length;
};


#line 7 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
struct litaC_string__String {
#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_char* buffer;

#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/string.lita"
litaC_i32 capacity;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_TypeSpec_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__TypeSpec** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(const litaC_char*);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(const litaC_char*,const litaC_char*);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_char** keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_workspace__Document** values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_workspace__Document* emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_char* emptyKey;
};


#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
struct litaC_bucket_allocator__Bucket {
#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_bucket_allocator__Bucket* prev;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_u8* mem;

#line 13 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_usize size;

#line 16 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_void* padding;
};


#line 13 "src/intern.lita"


#line 56 "src/cgen.lita"
struct litaC_cgen__CompilationUnit {
#line 57 "src/cgen.lita"
litaC_module__Module* module;

#line 58 "src/cgen.lita"
litaC_char filename[
#line 58 "src/cgen.lita"
_MAX_PATH];

#line 59 "src/cgen.lita"
FILE* file;
};


#line 20 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_Allocation_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_mem__Allocation** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapIterator_cb_i64_c__ptr_ConstTypeInfo_ce_ {
#line 68 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_* m;

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 it;

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 count;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_const_char_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_char** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_ParameterDecl_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__ParameterDecl** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_array__Array_cb_GenericParam_ce_* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapIterator_cb__ptr_const_char_c__ptr_Module_ce_ {
#line 68 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_* m;

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 it;

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 count;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_Stmt_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__Stmt** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapIterator_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ {
#line 68 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_* m;

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 it;

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 count;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_Decl_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__Decl** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb__ptr_const_char_c_i32_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(const litaC_char*);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(const litaC_char*,const litaC_char*);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_char** keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32* values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_char* emptyKey;
};


#line 87 "src/lita.lita"
struct litaC_lita__LitaOptions {
#line 88 "src/lita.lita"
litaC_char srcPath[
#line 88 "src/lita.lita"
_MAX_PATH];

#line 89 "src/lita.lita"
litaC_char libPath[
#line 89 "src/lita.lita"
_MAX_PATH];

#line 90 "src/lita.lita"
litaC_char litaPath[
#line 90 "src/lita.lita"
_MAX_PATH];

#line 92 "src/lita.lita"
litaC_char inputFile[
#line 92 "src/lita.lita"
_MAX_PATH];

#line 93 "src/lita.lita"
litaC_char outputFile[
#line 93 "src/lita.lita"
_MAX_PATH];

#line 94 "src/lita.lita"
litaC_char outputPath[
#line 94 "src/lita.lita"
_MAX_PATH];

#line 96 "src/lita.lita"
const litaC_char* compileCmd;

#line 98 "src/lita.lita"
litaC_bool checkerOnly;

#line 99 "src/lita.lita"
litaC_bool cOutputOnly;

#line 100 "src/lita.lita"
litaC_bool run;

#line 101 "src/lita.lita"
litaC_bool showProfileInfo;

#line 102 "src/lita.lita"
litaC_bool languageServer;

#line 103 "src/lita.lita"
litaC_bool isDebug;

#line 104 "src/lita.lita"
litaC_bool instrument;

#line 106 "src/lita.lita"
litaC_bool testsOnly;

#line 107 "src/lita.lita"
const litaC_char* testsRegex;

#line 108 "src/lita.lita"
litaC_bool testFileOnly;

#line 110 "src/lita.lita"
litaC_lita__TypeInfoOption typeOption;

#line 112 "src/lita.lita"
litaC_char cPrefix[32];

#line 113 "src/lita.lita"
litaC_bool cFormat;

#line 114 "src/lita.lita"
litaC_bool disableLineSync;

#line 116 "src/lita.lita"
litaC_usize maxMemory;
};


#line 32 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
union litaC_json__JsonValue {
#line 33 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_bool boolValue;

#line 34 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_f64 doubleValue;

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_i64 intValue;

#line 36 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* strValue;

#line 38 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonObject* objValue;

#line 39 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_array__Array_cb__ptr_JsonNode_ce_* arrayValue;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_FieldStmt_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__FieldStmt* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 123 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
struct litaC_mem__Allocator {
#line 124 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* (*allocFn)(const litaC_mem__Allocator*,litaC_usize);

#line 125 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* (*callocFn)(const litaC_mem__Allocator*,litaC_usize,litaC_usize);

#line 126 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* (*reallocFn)(const litaC_mem__Allocator*,litaC_void*,litaC_usize,litaC_usize);

#line 127 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void (*freeFn)(const litaC_mem__Allocator*,litaC_void*);
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_Module_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_module__Module** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapIterator_cb__ptr_Symbol_c_Dependency_ce_ {
#line 68 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_* m;

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 it;

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 count;
};


#line 428 "src/lex.lita"
struct litaC_lex__SrcPos {
#line 429 "src/lex.lita"
const litaC_char* filename;

#line 430 "src/lex.lita"
const litaC_char* lineStart;

#line 432 "src/lex.lita"
const litaC_char* start;

#line 433 "src/lex.lita"
const litaC_char* end;

#line 434 "src/lex.lita"
litaC_i32 lineNumber;

#line 435 "src/lex.lita"
litaC_i32 position;
};


#line 110 "src/ast.lita"
struct litaC_ast__TypeSpec {
#line 111 "src/ast.lita"
litaC_ast__TypeSpecKind kind;

#line 112 "src/ast.lita"
litaC_lex__SrcPos pos;

#line 113 "src/ast.lita"
litaC_ast__TypeSpec* base;

#line 114 "src/ast.lita"
litaC_types__TypeInfo* typeInfo;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_Expr_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__Expr** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapEntry_cb_i64_c__ptr_ConstTypeInfo_ce_ {
#line 74 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64 key;

#line 75 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ConstTypeInfo* value;

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ConstTypeInfo** valuePtr;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_InitArgExpr_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__InitArgExpr** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_ModuleImport_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_module__ModuleImport* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(const litaC_char*);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(const litaC_char*,const litaC_char*);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_char** keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_module__Module** values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_module__Module* emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_char* emptyKey;
};


#line 44 "src/checker.lita"
struct litaC_checker__GenericContext {
#line 45 "src/checker.lita"
litaC_module__Module* callsite;
};


#line 47 "src/cgen.lita"
struct litaC_cgen__CGenScope {
#line 48 "src/cgen.lita"
litaC_cgen__CGenScope* parent;

#line 49 "src/cgen.lita"
litaC_array__Array_cb__ptr_Stmt_ce_ defers;

#line 50 "src/cgen.lita"
litaC_array__Array_cb__ptr_const_char_ce_ constDefs;

#line 51 "src/cgen.lita"
litaC_bool isLoop;

#line 52 "src/cgen.lita"
litaC_bool isSwitch;
};


#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
struct litaC_linear_allocator__LinearAllocator {
#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_mem__Allocator allocator;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_void* mem;

#line 13 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_usize size;

#line 14 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_usize currentOffset;

#line 16 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_u32 totalAllocations;

#line 17 "C:/Users/antho/git/litac-lang/stdlib/std/mem/linear_allocator.lita"
litaC_usize totalBytesAllocated;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_i64);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_i64,litaC_i64);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64* keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ConstTypeInfo** values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ConstTypeInfo* emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64 emptyKey;
};


#line 1686 "src/types.lita"
struct litaC_types__FieldPositionResult {
#line 1687 "src/types.lita"
litaC_types__AggregateTypeInfo* aggInfo;

#line 1688 "src/types.lita"
litaC_i32 position;
};


#line 129 "src/ast.lita"
struct litaC_ast__PtrTypeSpec {
#line 130 "src/ast.lita"
litaC_ast__TypeSpec spec;
};


#line 26 "src/lsp/workspace.lita"
struct litaC_workspace__Workspace {
#line 27 "src/lsp/workspace.lita"
const litaC_mem__Allocator* allocator;

#line 28 "src/lsp/workspace.lita"
litaC_lsp__LspServer* lsp;

#line 29 "src/lsp/workspace.lita"
const litaC_char* rootPath;

#line 30 "src/lsp/workspace.lita"
litaC_map__Map_cb__ptr_const_char_c__ptr_Document_ce_ openedDocuments;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_Reference_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_references__Reference* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_TypeInfo_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_types__TypeInfo** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 18 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
struct litaC_profile__ProfileEntry {
#line 19 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
const litaC_char* functionName;

#line 20 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
litaC_u64 count;

#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
litaC_f64 startTime;

#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"
litaC_f64 totalTime;
};


#line 72 "src/lita.lita"
struct litaC_lita__Metric {
#line 73 "src/lita.lita"
litaC_usize bytesAllocated;

#line 74 "src/lita.lita"
litaC_u32 allocationCount;

#line 75 "src/lita.lita"
litaC_f64 executionTime;

#line 77 "src/lita.lita"
litaC_f64 startTime;
};


#line 19 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
struct litaC_bucket_allocator__BucketAllocator {
#line 20 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_mem__Allocator allocator;

#line 21 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
const litaC_mem__Allocator* decorated;

#line 23 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_bucket_allocator__Bucket* buckets;

#line 24 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_bucket_allocator__Bucket* head;

#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_usize bucketSize;

#line 27 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_usize currentOffset;

#line 28 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_u32 totalAllocations;

#line 29 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_usize totalBytesAllocated;

#line 30 "C:/Users/antho/git/litac-lang/stdlib/std/mem/bucket_allocator.lita"
litaC_u32 totalBuckets;
};


#line 281 "src/generics.lita"
struct litaC_generics__Template {
#line 282 "src/generics.lita"
litaC_array__Array_cb_GenericParam_ce_* genericParams;

#line 283 "src/generics.lita"
litaC_array__Array_cb__ptr_TypeSpec_ce_* genericArgs;
};


#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
struct litaC_json__Entry {
#line 23 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* key;

#line 24 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonNode* value;
};


#line 3 "C:/Users/antho/git/litac-lang/stdlib/std/builtins.lita"
struct litaC_builtins__any {
#line 4 "C:/Users/antho/git/litac-lang/stdlib/std/builtins.lita"
litaC_void* value;

#line 5 "C:/Users/antho/git/litac-lang/stdlib/std/builtins.lita"
litaC_u64 id;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_NoteStmt_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__NoteStmt** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 52 "src/lsp/references.lita"
struct litaC_references__FieldReference {
#line 54 "src/lsp/references.lita"
litaC_i64 parent;

#line 56 "src/lsp/references.lita"
litaC_i32 offset;

#line 58 "src/lsp/references.lita"
litaC_lex__SrcPos pos;
};


#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapIterator_cb_InternedString_c__ptr_Symbol_ce_ {
#line 68 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* m;

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 it;

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 count;
};


#line 42 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
struct litaC_json__JsonNode {
#line 43 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_mem__Allocator* alloc;

#line 44 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonType type;

#line 45 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonValue value;
};


#line 742 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"


#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapEntry_cb__ptr_const_char_c__ptr_Module_ce_ {
#line 74 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_char* key;

#line 75 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_module__Module* value;

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_module__Module** valuePtr;
};


#line 137 "src/ast.lita"
struct litaC_ast__FuncPtrTypeSpec {
#line 138 "src/ast.lita"
litaC_ast__TypeSpec spec;

#line 139 "src/ast.lita"
litaC_array__Array_cb__ptr_TypeSpec_ce_ args;

#line 140 "src/ast.lita"
litaC_ast__TypeSpec* ret;

#line 141 "src/ast.lita"
litaC_bool hasVarargs;

#line 142 "src/ast.lita"
litaC_array__Array_cb_GenericParam_ce_ genericParams;
};


#line 399 "src/ast.lita"


#line 14 "src/phase_result.lita"
struct litaC_phase_result__PhaseError {
#line 15 "src/phase_result.lita"
litaC_phase_result__ErrorType type;

#line 16 "src/phase_result.lita"
const litaC_char* message;

#line 17 "src/phase_result.lita"
litaC_lex__SrcPos pos;
};


#line 315 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
struct litaC_mem__Allocation {
#line 316 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_void* addr;

#line 317 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_usize size;

#line 318 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_u64 line;

#line 319 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_char filename[256];
};


#line 23 "src/introspection.lita"
struct litaC_introspection__Introspect {
#line 24 "src/introspection.lita"
litaC_lita__Lita* lita;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_Option_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_cmdline__Option* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_FuncTypeInfo_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_types__FuncTypeInfo** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_u32_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_u32* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 67 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapIterator_cb_i64_c__ptr_PtrTypeInfo_ce_ {
#line 68 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_* m;

#line 69 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 it;

#line 70 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 count;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__EnumFieldEntryDecl** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__SwitchCaseStmt** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_CompStmt_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__CompStmt** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_ImportDecl_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__ImportDecl** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_Token_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_lex__Token* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 9 "src/intern.lita"


#line 45 "src/dependency_graph.lita"
struct litaC_dependency_graph__Dependency {
#line 46 "src/dependency_graph.lita"
litaC_dependency_graph__State state;

#line 47 "src/dependency_graph.lita"
litaC_symbols__Symbol* sym;

#line 48 "src/dependency_graph.lita"
litaC_array__Array_cb__ptr_Dependency_ce_ dependsOn;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_Entry_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_json__Entry* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_CallArg_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_ast__CallArg* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_i64_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i64* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 133 "src/ast.lita"
struct litaC_ast__ConstTypeSpec {
#line 134 "src/ast.lita"
litaC_ast__TypeSpec spec;
};


#line 157 "src/ast.lita"
struct litaC_ast__Node {
#line 158 "src/ast.lita"
litaC_ast__StmtKind kind;

#line 159 "src/ast.lita"
litaC_ast__Node* parent;

#line 160 "src/ast.lita"
litaC_lex__SrcPos startPos;

#line 161 "src/ast.lita"
litaC_lex__SrcPos endPos;
};


#line 31 "src/module.lita"
struct litaC_module__ModuleImport {
#line 32 "src/module.lita"
litaC_module__Module* module;

#line 33 "src/module.lita"
litaC_intern__InternedString* alias;

#line 34 "src/module.lita"
litaC_bool isUsing;
};


#line 21 "src/types_new.lita"
struct litaC_types_new__ArrayEntry {
#line 22 "src/types_new.lita"
litaC_types__TypeInfo* arrayOf;

#line 23 "src/types_new.lita"
litaC_ast__Expr* expr;

#line 24 "src/types_new.lita"
litaC_usize length;
};


#line 24 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
struct litaC_cmdline__Option {
#line 25 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
const litaC_char* name;

#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_char shortName;

#line 27 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
const litaC_char* description;

#line 28 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
const litaC_char* value;

#line 29 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
const litaC_char* defaultValue;

#line 30 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_i32 flags;
};


#line 22 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
struct litaC_string_buffer__StringBuffer {
#line 23 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_char* buffer;

#line 24 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 length;

#line 25 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
litaC_i32 capacity;

#line 26 "C:/Users/antho/git/litac-lang/stdlib/std/string_buffer.lita"
const litaC_mem__Allocator* alloc;
};


#line 15 "src/lsp/protocol.lita"
struct litaC_protocol__Position {
#line 16 "src/lsp/protocol.lita"
litaC_i32 line;

#line 17 "src/lsp/protocol.lita"
litaC_i32 character;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_PhaseError_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_phase_result__PhaseError* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_SrcPos_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_lex__SrcPos* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapEntry_cb_i64_c__ptr_PtrTypeInfo_ce_ {
#line 74 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64 key;

#line 75 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__PtrTypeInfo* value;

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__PtrTypeInfo** valuePtr;
};


#line 27 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
struct litaC_json__JsonObject {
#line 28 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_map__Map_cb__ptr_const_char_c_i32_ce_ indexes;

#line 29 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_array__Array_cb_Entry_ce_ values;
};


#line 731 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
struct litaC_json__SrcPos {
#line 732 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* name;

#line 733 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_i32 line;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_Symbol_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_symbols__Symbol** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb__ptr_JsonNode_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_json__JsonNode** elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
struct litaC_array__Array_cb_FieldReference_ce_ {
#line 9 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 length;

#line 10 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_i32 capacity;

#line 11 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
litaC_references__FieldReference* elements;

#line 12 "C:/Users/antho/git/litac-lang/stdlib/std/array.lita"
const litaC_mem__Allocator* alloc;
};


#line 8 "src/intern.lita"
union litaC_intern__InternedString {
#line 9 "src/intern.lita"
struct  {
#line 10 "src/intern.lita"
const litaC_char* buffer;

#line 11 "src/intern.lita"
litaC_i32 length;
};

#line 13 "src/intern.lita"
struct  {
#line 14 "src/intern.lita"
litaC_usize addr;

#line 15 "src/intern.lita"
litaC_i32 size;
};

#line 17 "src/intern.lita"
litaC_string_view__StringView view;
};


#line 2074 "src/types.lita"
struct litaC_types__TypeInfo {
#line 2075 "src/types.lita"
litaC_types__TypeKind kind;

#line 2076 "src/types.lita"
litaC_i64 typeid;

#line 2077 "src/types.lita"
litaC_intern__InternedString name;

#line 2078 "src/types.lita"
litaC_symbols__Symbol* sym;
};


#line 2081 "src/types.lita"
struct litaC_types__GenericTypeInfo {
#line 2082 "src/types.lita"
litaC_types__TypeInfo typeInfo;

#line 2083 "src/types.lita"
litaC_i64 genericTypeid;
};


#line 415 "src/ast.lita"
struct litaC_ast__Stmt {
#line 416 "src/ast.lita"
litaC_ast__Node node;
};


#line 438 "src/lex.lita"
union litaC_lex__Value {
#line 439 "src/lex.lita"
litaC_f64 floatValue;

#line 440 "src/lex.lita"
litaC_i64 intValue;

#line 441 "src/lex.lita"
litaC_u64 uintValue;

#line 442 "src/lex.lita"
litaC_intern__InternedString str;
};


#line 450 "src/lex.lita"
struct litaC_lex__Token {
#line 451 "src/lex.lita"
litaC_lex__TokenType type;

#line 452 "src/lex.lita"
litaC_lex__Mod mod;

#line 453 "src/lex.lita"
litaC_types__TypeInfo* typeInfo;

#line 454 "src/lex.lita"
litaC_lex__SrcPos pos;

#line 455 "src/lex.lita"
litaC_lex__Value value;
};


#line 149 "src/ast.lita"
struct litaC_ast__Attributes {
#line 150 "src/ast.lita"
litaC_bool isPublic;

#line 151 "src/ast.lita"
litaC_bool isGlobal;

#line 152 "src/ast.lita"
litaC_bool isUsing;

#line 153 "src/ast.lita"
litaC_array__Array_cb__ptr_NoteStmt_ce_ notes;
};


#line 200 "src/ast.lita"
struct litaC_ast__Decl {
#line 201 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 202 "src/ast.lita"
litaC_symbols__Symbol* sym;

#line 203 "src/ast.lita"
litaC_lex__Token name;

#line 204 "src/ast.lita"
litaC_ast__Attributes attributes;
};


#line 207 "src/ast.lita"
struct litaC_ast__GenericDecl {
#line 208 "src/ast.lita"
litaC_ast__Decl declaration;

#line 209 "src/ast.lita"
litaC_array__Array_cb_GenericParam_ce_ genericParams;
};


#line 254 "src/ast.lita"
struct litaC_ast__TypedefDecl {
#line 255 "src/ast.lita"
litaC_ast__GenericDecl decl;

#line 256 "src/ast.lita"
litaC_ast__TypeSpec* type;
};


#line 295 "src/ast.lita"
struct litaC_ast__DeferStmt {
#line 296 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 297 "src/ast.lita"
litaC_ast__Stmt* deferedStmt;
};


#line 341 "src/ast.lita"
struct litaC_ast__LabelStmt {
#line 342 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 343 "src/ast.lita"
litaC_lex__Token label;
};


#line 391 "src/ast.lita"
struct litaC_ast__TraitFieldDecl {
#line 392 "src/ast.lita"
litaC_ast__Decl decl;

#line 393 "src/ast.lita"
litaC_ast__TypeSpec* type;
};


#line 592 "src/ast.lita"
struct litaC_ast__Operand {
#line 593 "src/ast.lita"
litaC_types__TypeInfo* typeInfo;

#line 594 "src/ast.lita"
litaC_bool isRightValue;

#line 595 "src/ast.lita"
litaC_bool isConst;

#line 596 "src/ast.lita"
litaC_lex__Value val;
};


#line 586 "src/ast.lita"
struct litaC_ast__Expr {
#line 587 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 588 "src/ast.lita"
litaC_ast__Operand operand;

#line 589 "src/ast.lita"
litaC_types__TypeInfo* expectedType;
};


#line 438 "src/ast.lita"
struct litaC_ast__BooleanExpr {
#line 439 "src/ast.lita"
litaC_ast__Expr expr;

#line 440 "src/ast.lita"
litaC_bool boolean;
};


#line 487 "src/ast.lita"
struct litaC_ast__IdentifierExpr {
#line 488 "src/ast.lita"
litaC_ast__Expr expr;

#line 490 "src/ast.lita"
litaC_ast__NameTypeSpec* type;

#line 491 "src/ast.lita"
litaC_symbols__Symbol* sym;
};


#line 537 "src/ast.lita"
struct litaC_ast__StringExpr {
#line 538 "src/ast.lita"
litaC_ast__Expr expr;

#line 539 "src/ast.lita"
litaC_lex__Token string;
};


#line 4 "C:/Users/antho/git/litac-lang/stdlib/std/regex/regex.lita"
struct litaC_regex__Regex {
#line 5 "C:/Users/antho/git/litac-lang/stdlib/std/regex/regex.lita"
re_t reg;
};


#line 50 "src/parser.lita"
struct litaC_parser__Parser {
#line 51 "src/parser.lita"
const litaC_mem__Allocator* allocator;

#line 52 "src/parser.lita"
litaC_phase_result__PhaseResult* result;

#line 53 "src/parser.lita"
litaC_lita__Lita* lita;

#line 54 "src/parser.lita"
const litaC_char* filename;

#line 56 "src/parser.lita"
litaC_i32 totalLines;

#line 57 "src/parser.lita"
litaC_array__Array_cb_Token_ce_ tokens;

#line 58 "src/parser.lita"
litaC_i32 current;

#line 59 "src/parser.lita"
litaC_lex__SrcPos currentPos;

#line 60 "src/parser.lita"
litaC_i32 breakLevel;

#line 61 "src/parser.lita"
litaC_i32 loopLevel;

#line 62 "src/parser.lita"
litaC_i32 switchLevel;

#line 63 "src/parser.lita"
litaC_i32 funcLevel;

#line 64 "src/parser.lita"
litaC_i32 aggregateLevel;

#line 65 "src/parser.lita"
litaC_u32 tryLevel;

#line 66 "src/parser.lita"
litaC_u64 tryErrorCounter;

#line 67 "src/parser.lita"
litaC_bool panicMode;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_usize);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_usize,litaC_usize);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_usize* keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_SrcPos_ce_* values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_SrcPos_ce_ emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_usize emptyKey;
};


#line 61 "src/lsp/references.lita"
struct litaC_references__ReferenceDatabase {
#line 62 "src/lsp/references.lita"
const litaC_mem__Allocator* allocator;

#line 63 "src/lsp/references.lita"
litaC_array__Array_cb_Reference_ce_ typeReferences;

#line 64 "src/lsp/references.lita"
litaC_array__Array_cb_FieldReference_ce_ fieldReferences;

#line 65 "src/lsp/references.lita"
litaC_map__Map_cb_usize_c_Array_cb_SrcPos_ce__ce_ symbols;
};


#line 38 "src/checker.lita"
struct litaC_checker__LabelInfo {
#line 39 "src/checker.lita"
litaC_intern__InternedString name;

#line 40 "src/checker.lita"
litaC_bool defined;

#line 41 "src/checker.lita"
litaC_ast__Stmt* stmt;
};


#line 25 "src/cgen.lita"
struct litaC_cgen__CGen {
#line 26 "src/cgen.lita"
litaC_lita__Lita* lita;

#line 27 "src/cgen.lita"
litaC_string_buffer__StringBuffer buf;

#line 28 "src/cgen.lita"
litaC_string_buffer__StringBuffer line;

#line 29 "src/cgen.lita"
litaC_bool format;

#line 30 "src/cgen.lita"
litaC_i32 indent;

#line 31 "src/cgen.lita"
litaC_i32 aggregateLevel;

#line 33 "src/cgen.lita"
litaC_i32 currentLine;

#line 34 "src/cgen.lita"
const litaC_char* currentFile;

#line 36 "src/cgen.lita"
litaC_bool bufferFlush;

#line 37 "src/cgen.lita"
litaC_i32 funcIndex;

#line 38 "src/cgen.lita"
litaC_i32 tmpVar;

#line 39 "src/cgen.lita"
litaC_i32 deferStack;

#line 41 "src/cgen.lita"
litaC_types__FuncTypeInfo* currentFunc;

#line 42 "src/cgen.lita"
litaC_cgen__CGenScope* currentScope;

#line 44 "src/cgen.lita"
FILE* output;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_symbols__Symbol*);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_symbols__Symbol*,litaC_symbols__Symbol*);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_symbols__Symbol** keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_dependency_graph__Dependency* values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_dependency_graph__Dependency emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_symbols__Symbol* emptyKey;
};


#line 28 "src/dependency_graph.lita"

struct litaC_dependency_graph__DependencyGraph {
#line 29 "src/dependency_graph.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ sortedPrimitives;

#line 30 "src/dependency_graph.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ sortedGlobals;

#line 31 "src/dependency_graph.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ sortedAggregates;

#line 32 "src/dependency_graph.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ sortedFuncs;

#line 34 "src/dependency_graph.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ sortedSymbols;

#line 35 "src/dependency_graph.lita"
litaC_map__Map_cb__ptr_Symbol_c_Dependency_ce_ dependencies;

#line 36 "src/dependency_graph.lita"
litaC_lita__Lita* lita;
};



#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_intern__InternedString);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_intern__InternedString,litaC_intern__InternedString);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_intern__InternedString* keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__TypeInfo** values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__TypeInfo* emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_intern__InternedString emptyKey;
};


#line 515 "src/lex.lita"
struct litaC_lex__Lexer {
#line 516 "src/lex.lita"
const litaC_mem__Allocator* allocator;

#line 517 "src/lex.lita"
litaC_intern__Strings* strings;

#line 518 "src/lex.lita"
const litaC_char* filename;

#line 519 "src/lex.lita"
litaC_lex__Token token;

#line 520 "src/lex.lita"
const litaC_char* stream;

#line 522 "src/lex.lita"
const litaC_char* lineStart;

#line 523 "src/lex.lita"
litaC_i32 lineNumber;

#line 524 "src/lex.lita"
litaC_i32 position;

#line 526 "src/lex.lita"
const litaC_char* errorMsg;
};


#line 2097 "src/types.lita"
struct litaC_types__PtrTypeInfo {
#line 2098 "src/types.lita"
litaC_types__TypeInfo info;

#line 2099 "src/types.lita"
litaC_types__TypeInfo* ptrOf;
};


#line 124 "src/ast.lita"
struct litaC_ast__ArrayTypeSpec {
#line 125 "src/ast.lita"
litaC_ast__TypeSpec spec;

#line 126 "src/ast.lita"
litaC_ast__Expr* numElements;
};


#line 145 "src/ast.lita"
struct litaC_ast__GenericParam {
#line 146 "src/ast.lita"
litaC_lex__Token name;
};


#line 221 "src/ast.lita"
struct litaC_ast__VarDecl {
#line 222 "src/ast.lita"
litaC_ast__Decl decl;

#line 223 "src/ast.lita"
litaC_ast__TypeSpec* typeSpec;

#line 224 "src/ast.lita"
litaC_ast__Expr* expr;
};


#line 269 "src/ast.lita"
struct litaC_ast__PoisonDecl {
#line 270 "src/ast.lita"
litaC_ast__Decl decl;
};


#line 310 "src/ast.lita"
struct litaC_ast__EnumFieldEntryDecl {
#line 311 "src/ast.lita"
litaC_ast__Decl decl;

#line 312 "src/ast.lita"
litaC_ast__Expr* value;
};


#line 361 "src/ast.lita"
struct litaC_ast__ParametersStmt {
#line 362 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 363 "src/ast.lita"
litaC_array__Array_cb__ptr_ParameterDecl_ce_ params;

#line 364 "src/ast.lita"
litaC_bool isVararg;
};


#line 408 "src/ast.lita"
struct litaC_ast__WhileStmt {
#line 409 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 410 "src/ast.lita"
litaC_ast__Expr* cond;

#line 411 "src/ast.lita"
litaC_ast__Stmt* body;
};


#line 454 "src/ast.lita"
struct litaC_ast__CallArg {
#line 455 "src/ast.lita"
litaC_ast__Expr* argExpr;

#line 456 "src/ast.lita"
litaC_lex__Token argName;

#line 457 "src/ast.lita"
litaC_i32 index;
};


#line 508 "src/ast.lita"
struct litaC_ast__NullExpr {
#line 509 "src/ast.lita"
litaC_ast__Expr expr;
};


#line 556 "src/ast.lita"
struct litaC_ast__TernaryExpr {
#line 557 "src/ast.lita"
litaC_ast__Expr expr;

#line 558 "src/ast.lita"
litaC_ast__Expr* cond;

#line 559 "src/ast.lita"
litaC_ast__Expr* then;

#line 560 "src/ast.lita"
litaC_ast__Expr* other;
};


#line 322 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
struct litaC_mem__DebugAllocator {
#line 323 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_mem__Allocator alloc;

#line 324 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
const litaC_mem__Allocator* decorated;

#line 325 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_array__Array_cb__ptr_Allocation_ce_ allocations;

#line 326 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_u32 totalAllocations;

#line 327 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_usize totalBytesAllocated;

#line 328 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_usize totalBytesFreed;
};


#line 20 "src/phase_result.lita"
struct litaC_phase_result__PhaseResult {
#line 21 "src/phase_result.lita"
const litaC_mem__Allocator* allocator;

#line 22 "src/phase_result.lita"
litaC_array__Array_cb_PhaseError_ce_ errors;

#line 23 "src/phase_result.lita"
litaC_bool enabled;

#line 24 "src/phase_result.lita"
litaC_bool isReadable;
};


#line 20 "src/lsp/protocol.lita"
struct litaC_protocol__Range {
#line 21 "src/lsp/protocol.lita"
litaC_protocol__Position start;

#line 22 "src/lsp/protocol.lita"
litaC_protocol__Position end;
};


#line 44 "src/lsp/protocol.lita"
struct litaC_protocol__TextDocumentChangeEvent {
#line 45 "src/lsp/protocol.lita"
litaC_bool hasRange;

#line 46 "src/lsp/protocol.lita"
litaC_protocol__Range range;

#line 47 "src/lsp/protocol.lita"
litaC_u32 rangeLength;

#line 48 "src/lsp/protocol.lita"
const litaC_char* text;
};


#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapEntry_cb_i64_c_Array_cb_i64_ce__ce_ {
#line 74 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64 key;

#line 75 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_i64_ce_ value;

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_i64_ce_* valuePtr;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_intern__InternedString);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_intern__InternedString,litaC_intern__InternedString);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_intern__InternedString* keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_symbols__Symbol** values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_symbols__Symbol* emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_intern__InternedString emptyKey;
};


#line 93 "src/symbols.lita"
struct litaC_symbols__Scope {
#line 94 "src/symbols.lita"
litaC_symbols__ScopeKind kind;

#line 95 "src/symbols.lita"
const litaC_mem__Allocator* allocator;

#line 96 "src/symbols.lita"
litaC_phase_result__PhaseResult* result;

#line 97 "src/symbols.lita"
litaC_symbols__Scope* parent;

#line 98 "src/symbols.lita"
litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_ symbols;

#line 100 "src/symbols.lita"
litaC_module__Module* module;
};


#line 2119 "src/types.lita"
struct litaC_types__EnumTypeInfo {
#line 2120 "src/types.lita"
litaC_types__TypeInfo info;

#line 2121 "src/types.lita"
litaC_ast__EnumDecl* decl;
};


#line 243 "src/ast.lita"
struct litaC_ast__AggregateDecl {
#line 244 "src/ast.lita"
litaC_ast__GenericDecl decl;

#line 245 "src/ast.lita"
litaC_array__Array_cb_FieldStmt_ce_ fields;

#line 246 "src/ast.lita"
litaC_i32 flags;
};


#line 282 "src/ast.lita"
struct litaC_ast__CompStmt {
#line 283 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 284 "src/ast.lita"
const litaC_char* type;

#line 285 "src/ast.lita"
const litaC_char* expr;

#line 286 "src/ast.lita"
litaC_ast__CompStmt* end;

#line 287 "src/ast.lita"
litaC_ast__Stmt* evaluatedStmt;

#line 288 "src/ast.lita"
litaC_array__Array_cb__ptr_Stmt_ce_ body;
};


#line 328 "src/ast.lita"
struct litaC_ast__GotoStmt {
#line 329 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 330 "src/ast.lita"
litaC_lex__Token label;
};


#line 378 "src/ast.lita"
struct litaC_ast__SwitchStmt {
#line 379 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 380 "src/ast.lita"
litaC_ast__Expr* cond;

#line 381 "src/ast.lita"
litaC_array__Array_cb__ptr_SwitchCaseStmt_ce_ cases;

#line 382 "src/ast.lita"
litaC_ast__Stmt* defaultStmt;
};


#line 425 "src/ast.lita"
struct litaC_ast__ArrayInitExpr {
#line 426 "src/ast.lita"
litaC_ast__Expr expr;

#line 427 "src/ast.lita"
litaC_ast__TypeSpec* type;

#line 428 "src/ast.lita"
litaC_array__Array_cb__ptr_Expr_ce_ values;
};


#line 475 "src/ast.lita"
struct litaC_ast__GetExpr {
#line 476 "src/ast.lita"
litaC_ast__Expr expr;

#line 477 "src/ast.lita"
litaC_ast__Expr* object;

#line 478 "src/ast.lita"
litaC_ast__IdentifierExpr* field;

#line 479 "src/ast.lita"
litaC_i32 flags;
};


#line 523 "src/ast.lita"
struct litaC_ast__SetExpr {
#line 524 "src/ast.lita"
litaC_ast__Expr expr;

#line 525 "src/ast.lita"
litaC_ast__Expr* object;

#line 526 "src/ast.lita"
litaC_ast__IdentifierExpr* field;

#line 527 "src/ast.lita"
litaC_lex__TokenType operator;

#line 528 "src/ast.lita"
litaC_ast__Expr* value;

#line 529 "src/ast.lita"
litaC_i32 flags;
};


#line 576 "src/ast.lita"
struct litaC_ast__UnaryExpr {
#line 577 "src/ast.lita"
litaC_ast__Expr expr;

#line 578 "src/ast.lita"
litaC_lex__TokenType operator;

#line 579 "src/ast.lita"
litaC_ast__Expr* unaryExpr;
};


#line 25 "src/module.lita"
struct litaC_module__ModuleId {
#line 26 "src/module.lita"
litaC_char filename[
#line 26 "src/module.lita"
_MAX_PATH];

#line 27 "src/module.lita"
litaC_string_view__StringView packageName;

#line 28 "src/module.lita"
litaC_intern__InternedString name;
};


#line 37 "src/module.lita"
struct litaC_module__Module {
#line 38 "src/module.lita"
litaC_module__ModuleId id;

#line 39 "src/module.lita"
litaC_char* text;

#line 40 "src/module.lita"
litaC_ast__ModuleStmt* ast;

#line 41 "src/module.lita"
litaC_symbols__Scope symbols;

#line 42 "src/module.lita"
litaC_symbols__Scope* currentScope;

#line 43 "src/module.lita"
litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_* genericSymbols;

#line 44 "src/module.lita"
litaC_i32 flags;

#line 46 "src/module.lita"
litaC_array__Array_cb_ModuleImport_ce_ importedBy;

#line 48 "src/module.lita"
const litaC_mem__Allocator* allocator;

#line 49 "src/module.lita"
litaC_lita__Lita* lita;
};


#line 49 "src/preprocessor.lita"
struct litaC_preprocessor__CallContext {
#line 50 "src/preprocessor.lita"
litaC_preprocessor__Preprocessor* pp;

#line 51 "src/preprocessor.lita"
litaC_checker__TypeChecker* checker;

#line 52 "src/preprocessor.lita"
litaC_ast__CompStmt* comp;

#line 53 "src/preprocessor.lita"
litaC_string_buffer__StringBuffer buffer;
};


#line 42 "src/preprocessor.lita"
struct litaC_preprocessor__Preprocessor {
#line 43 "src/preprocessor.lita"
litaC_lita__Lita* lita;

#line 44 "src/preprocessor.lita"
ape_t* ape;

#line 45 "src/preprocessor.lita"
litaC_preprocessor__CallContext callContext;

#line 46 "src/preprocessor.lita"
litaC_array__Array_cb__ptr_CompStmt_ce_ preCheckers;
};


#line 47 "src/lsp/references.lita"
struct litaC_references__Reference {
#line 48 "src/lsp/references.lita"
litaC_i64 type;

#line 49 "src/lsp/references.lita"
litaC_lex__SrcPos pos;
};


#line 33 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
struct litaC_cmdline__CmdParser {
#line 34 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_array__Array_cb_Option_ce_ options;

#line 35 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_array__Array_cb__ptr_const_char_ce_ args;

#line 36 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_char errors[256];

#line 37 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
litaC_cmdline__CmdParserStatus status;

#line 38 "C:/Users/antho/git/litac-lang/stdlib/std/cmdline.lita"
const litaC_char* header;
};


#line 25 "src/lsp/protocol.lita"
struct litaC_protocol__Location {
#line 26 "src/lsp/protocol.lita"
const litaC_char* uri;

#line 27 "src/lsp/protocol.lita"
litaC_protocol__Range range;
};


#line 23 "src/lsp/util.lita"

struct litaC_util__SourceLocation {
#line 24 "src/lsp/util.lita"
litaC_util__SourceLocationKind kind;

#line 25 "src/lsp/util.lita"
litaC_module__Module* module;

#line 26 "src/lsp/util.lita"
litaC_protocol__Location location;

#line 27 "src/lsp/util.lita"
union  {
#line 28 "src/lsp/util.lita"
litaC_ast__Node* node;

#line 29 "src/lsp/util.lita"
litaC_ast__TypeSpec* type;
};
};



#line 66 "src/lsp/util.lita"
struct litaC_util__SourceLookup {
#line 67 "src/lsp/util.lita"
litaC_lsp__LspServer* lsp;

#line 68 "src/lsp/util.lita"
litaC_protocol__Position lookupPos;

#line 69 "src/lsp/util.lita"
litaC_util__SourceLocation result;
};


#line 736 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
struct litaC_json__Token {
#line 737 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__TokenKind kind;

#line 738 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__SrcPos pos;

#line 739 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* start;

#line 740 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* end;

#line 742 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
union  {
#line 743 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_i64 intNumValue;

#line 744 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_f64 realNumValue;

#line 745 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* strValue;

#line 746 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* name;
};
};


#line 2086 "src/types.lita"
struct litaC_types__FuncTypeInfo {
#line 2087 "src/types.lita"
litaC_types__GenericTypeInfo info;

#line 2088 "src/types.lita"
litaC_types__TypeInfo* returnType;

#line 2089 "src/types.lita"
litaC_ast__FuncDecl* decl;
};


#line 259 "src/ast.lita"
struct litaC_ast__NativeDecl {
#line 260 "src/ast.lita"
litaC_ast__Decl decl;

#line 261 "src/ast.lita"
litaC_types__TypeInfo* typeInfo;
};


#line 300 "src/ast.lita"
struct litaC_ast__DoWhileStmt {
#line 301 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 302 "src/ast.lita"
litaC_ast__Expr* cond;

#line 303 "src/ast.lita"
litaC_ast__Stmt* body;
};


#line 347 "src/ast.lita"
struct litaC_ast__ModuleStmt {
#line 348 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 349 "src/ast.lita"
litaC_array__Array_cb__ptr_ImportDecl_ce_ imports;

#line 350 "src/ast.lita"
litaC_array__Array_cb__ptr_NoteStmt_ce_ notes;

#line 351 "src/ast.lita"
litaC_array__Array_cb__ptr_Decl_ce_ declarations;
};


#line 396 "src/ast.lita"
struct litaC_ast__FieldStmt {
#line 397 "src/ast.lita"
litaC_ast__StmtKind kind;

#line 398 "src/ast.lita"
litaC_types__TypeInfo* typeInfo;

#line 399 "src/ast.lita"
union  {
#line 400 "src/ast.lita"
litaC_ast__EnumDecl* enumField;

#line 401 "src/ast.lita"
litaC_ast__AggregateDecl* aggregateField;

#line 402 "src/ast.lita"
litaC_ast__VarFieldDecl* varField;

#line 403 "src/ast.lita"
litaC_ast__TraitFieldDecl* traitField;

#line 404 "src/ast.lita"
litaC_ast__Expr* poisonField;
};
};


#line 443 "src/ast.lita"
struct litaC_ast__CastExpr {
#line 444 "src/ast.lita"
litaC_ast__Expr expr;

#line 445 "src/ast.lita"
litaC_ast__TypeSpec* castTo;

#line 446 "src/ast.lita"
litaC_ast__Expr* exprToCast;
};


#line 494 "src/ast.lita"
struct litaC_ast__InitArgExpr {
#line 495 "src/ast.lita"
litaC_ast__Expr expr;

#line 496 "src/ast.lita"
litaC_lex__Token fieldName;

#line 497 "src/ast.lita"
litaC_i32 argPosition;

#line 498 "src/ast.lita"
litaC_ast__Expr* value;
};


#line 542 "src/ast.lita"
struct litaC_ast__SubscriptGetExpr {
#line 543 "src/ast.lita"
litaC_ast__Expr expr;

#line 544 "src/ast.lita"
litaC_ast__Expr* object;

#line 545 "src/ast.lita"
litaC_ast__Expr* index;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_i64);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_i64,litaC_i64);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64* keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_i64_ce_* values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_array__Array_cb_i64_ce_ emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i64 emptyKey;
};


#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapEntry_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ {
#line 74 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types_new__ArrayEntry key;

#line 75 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ArrayTypeInfo* value;

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ArrayTypeInfo** valuePtr;
};


#line 2102 "src/types.lita"
struct litaC_types__ArrayTypeInfo {
#line 2103 "src/types.lita"
litaC_types__TypeInfo info;

#line 2104 "src/types.lita"
litaC_types__TypeInfo* arrayOf;

#line 2105 "src/types.lita"
litaC_usize length;

#line 2106 "src/types.lita"
litaC_ast__Expr* numOfElements;

#line 2107 "src/types.lita"
litaC_bool isLengthDefined;
};


#line 227 "src/ast.lita"
struct litaC_ast__ParameterDecl {
#line 228 "src/ast.lita"
litaC_ast__Decl decl;

#line 229 "src/ast.lita"
litaC_ast__TypeSpec* type;

#line 230 "src/ast.lita"
litaC_ast__Expr* defaultExpr;

#line 231 "src/ast.lita"
litaC_types__TypeInfo* typeInfo;
};


#line 273 "src/ast.lita"
struct litaC_ast__BlockStmt {
#line 274 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 275 "src/ast.lita"
litaC_array__Array_cb__ptr_Stmt_ce_ stmts;
};


#line 315 "src/ast.lita"
struct litaC_ast__ForStmt {
#line 316 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 317 "src/ast.lita"
litaC_ast__Stmt* init;

#line 318 "src/ast.lita"
litaC_ast__Expr* cond;

#line 319 "src/ast.lita"
litaC_ast__Stmt* post;

#line 320 "src/ast.lita"
litaC_ast__Stmt* body;
};


#line 367 "src/ast.lita"
struct litaC_ast__ReturnStmt {
#line 368 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 369 "src/ast.lita"
litaC_ast__Expr* expr;
};


#line 460 "src/ast.lita"
struct litaC_ast__FuncCallExpr {
#line 461 "src/ast.lita"
litaC_ast__Expr expr;

#line 462 "src/ast.lita"
litaC_ast__Expr* object;

#line 463 "src/ast.lita"
litaC_array__Array_cb__ptr_TypeSpec_ce_ genericArgs;

#line 464 "src/ast.lita"
litaC_array__Array_cb_CallArg_ce_ arguments;
};


#line 512 "src/ast.lita"
struct litaC_ast__NumberExpr {
#line 513 "src/ast.lita"
litaC_ast__Expr expr;

#line 514 "src/ast.lita"
litaC_lex__Token number;
};


#line 563 "src/ast.lita"
struct litaC_ast__TypeIdentifierExpr {
#line 564 "src/ast.lita"
litaC_ast__Expr expr;

#line 566 "src/ast.lita"
litaC_ast__TypeSpec* type;

#line 567 "src/ast.lita"
litaC_symbols__Symbol* sym;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_types_new__ArrayEntry);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_types_new__ArrayEntry,litaC_types_new__ArrayEntry);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types_new__ArrayEntry* keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ArrayTypeInfo** values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types__ArrayTypeInfo* emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_types_new__ArrayEntry emptyKey;
};


#line 13 "src/types_new.lita"
struct litaC_types_new__TypeCache {
#line 14 "src/types_new.lita"
const litaC_mem__Allocator* allocator;

#line 15 "src/types_new.lita"
litaC_map__Map_cb_i64_c__ptr_ConstTypeInfo_ce_ constCache;

#line 16 "src/types_new.lita"
litaC_map__Map_cb_i64_c__ptr_PtrTypeInfo_ce_ ptrCache;

#line 17 "src/types_new.lita"
litaC_map__Map_cb_ArrayEntry_c__ptr_ArrayTypeInfo_ce_ arrayCache;

#line 18 "src/types_new.lita"
litaC_map__Map_cb_InternedString_c__ptr_TypeInfo_ce_ genericCache;
};


#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapEntry_cb__ptr_Symbol_c_Dependency_ce_ {
#line 74 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_symbols__Symbol* key;

#line 75 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_dependency_graph__Dependency value;

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_dependency_graph__Dependency* valuePtr;
};


#line 1840 "src/types.lita"
struct litaC_types__FieldPath {
#line 1841 "src/types.lita"
litaC_ast__FieldStmt fields[256];

#line 1842 "src/types.lita"
litaC_i32 numOfFields;
};


#line 2124 "src/types.lita"
struct litaC_types__AggregateTypeInfo {
#line 2125 "src/types.lita"
litaC_types__GenericTypeInfo info;

#line 2126 "src/types.lita"
litaC_ast__AggregateDecl* decl;
};


#line 249 "src/ast.lita"
struct litaC_ast__EnumDecl {
#line 250 "src/ast.lita"
litaC_ast__Decl decl;

#line 251 "src/ast.lita"
litaC_array__Array_cb__ptr_EnumFieldEntryDecl_ce_ fields;
};


#line 291 "src/ast.lita"
struct litaC_ast__ContinueStmt {
#line 292 "src/ast.lita"
litaC_ast__Stmt stmt;
};


#line 333 "src/ast.lita"
struct litaC_ast__IfStmt {
#line 334 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 335 "src/ast.lita"
litaC_ast__Expr* cond;

#line 336 "src/ast.lita"
litaC_ast__Stmt* then;

#line 337 "src/ast.lita"
litaC_ast__Stmt* elseStmt;
};


#line 385 "src/ast.lita"
struct litaC_ast__VarFieldDecl {
#line 386 "src/ast.lita"
litaC_ast__Decl decl;

#line 387 "src/ast.lita"
litaC_ast__TypeSpec* type;

#line 388 "src/ast.lita"
litaC_ast__Expr* defaultExpr;
};


#line 431 "src/ast.lita"
struct litaC_ast__BinaryExpr {
#line 432 "src/ast.lita"
litaC_ast__Expr expr;

#line 433 "src/ast.lita"
litaC_ast__Expr* left;

#line 434 "src/ast.lita"
litaC_lex__TokenType operator;

#line 435 "src/ast.lita"
litaC_ast__Expr* right;
};


#line 482 "src/ast.lita"
struct litaC_ast__GroupExpr {
#line 483 "src/ast.lita"
litaC_ast__Expr expr;

#line 484 "src/ast.lita"
litaC_ast__Expr* groupedExpr;
};


#line 532 "src/ast.lita"
struct litaC_ast__SizeOfExpr {
#line 533 "src/ast.lita"
litaC_ast__Expr expr;

#line 534 "src/ast.lita"
litaC_ast__Expr* sizeOfExpr;
};


#line 582 "src/ast.lita"
struct litaC_ast__PoisonExpr {
#line 583 "src/ast.lita"
litaC_ast__Expr expr;
};


#line 55 "src/symbols.lita"
struct litaC_symbols__Symbol {
#line 56 "src/symbols.lita"
litaC_symbols__SymbolKind kind;

#line 57 "src/symbols.lita"
litaC_intern__InternedString name;

#line 58 "src/symbols.lita"
litaC_symbols__SymbolState state;

#line 59 "src/symbols.lita"
litaC_ast__Decl* decl;

#line 60 "src/symbols.lita"
litaC_types__TypeInfo* type;

#line 62 "src/symbols.lita"
litaC_symbols__Symbol* usingParent;

#line 63 "src/symbols.lita"
litaC_module__Module* declared;

#line 64 "src/symbols.lita"
litaC_module__Module* usingModule;

#line 65 "src/symbols.lita"
litaC_i32 flags;

#line 66 "src/symbols.lita"
litaC_lex__Value val;

#line 69 "src/symbols.lita"
litaC_module__Module* genericCallsiteModule;

#line 70 "src/symbols.lita"
litaC_array__Array_cb__ptr_TypeInfo_ce_ genericArgs;

#line 71 "src/symbols.lita"
litaC_array__Array_cb_GenericParam_ce_ genericParams;
};


#line 55 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__Map_cb_StringView_c_InternedString_ce_ {
#line 56 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 length;

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_i32 capacity;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_u32 (*hashFn)(litaC_string_view__StringView);

#line 59 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_bool (*equalFn)(litaC_string_view__StringView,litaC_string_view__StringView);

#line 60 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
const litaC_mem__Allocator* alloc;

#line 61 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_string_view__StringView* keys;

#line 62 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_intern__InternedString* values;

#line 63 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_intern__InternedString emptyValue;

#line 64 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_string_view__StringView emptyKey;
};


#line 2092 "src/types.lita"
struct litaC_types__ConstTypeInfo {
#line 2093 "src/types.lita"
litaC_types__TypeInfo info;

#line 2094 "src/types.lita"
litaC_types__TypeInfo* constOf;
};


#line 117 "src/ast.lita"
struct litaC_ast__NameTypeSpec {
#line 118 "src/ast.lita"
litaC_ast__TypeSpec spec;

#line 120 "src/ast.lita"
litaC_intern__InternedString name;

#line 121 "src/ast.lita"
litaC_array__Array_cb__ptr_TypeSpec_ce_ genericArgs;
};


#line 212 "src/ast.lita"
struct litaC_ast__ImportDecl {
#line 213 "src/ast.lita"
litaC_ast__Decl decl;

#line 214 "src/ast.lita"
litaC_lex__Token alias;

#line 215 "src/ast.lita"
litaC_bool isUsing;

#line 217 "src/ast.lita"
litaC_module__ModuleId* moduleId;
};


#line 264 "src/ast.lita"
struct litaC_ast__NotesDecl {
#line 265 "src/ast.lita"
litaC_ast__Decl decl;

#line 266 "src/ast.lita"
litaC_array__Array_cb__ptr_NoteStmt_ce_ notes;
};


#line 306 "src/ast.lita"
struct litaC_ast__EmptyStmt {
#line 307 "src/ast.lita"
litaC_ast__Stmt stmt;
};


#line 355 "src/ast.lita"
struct litaC_ast__NoteStmt {
#line 356 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 357 "src/ast.lita"
litaC_lex__Token name;

#line 358 "src/ast.lita"
litaC_array__Array_cb_Token_ce_ attributes;
};


#line 449 "src/ast.lita"
struct litaC_ast__CharExpr {
#line 450 "src/ast.lita"
litaC_ast__Expr expr;

#line 451 "src/ast.lita"
litaC_lex__Token character;
};


#line 501 "src/ast.lita"
struct litaC_ast__InitExpr {
#line 502 "src/ast.lita"
litaC_ast__Expr expr;

#line 503 "src/ast.lita"
litaC_array__Array_cb__ptr_TypeSpec_ce_ genericArgs;

#line 504 "src/ast.lita"
litaC_ast__NameTypeSpec* type;

#line 505 "src/ast.lita"
litaC_array__Array_cb__ptr_InitArgExpr_ce_ arguments;
};


#line 548 "src/ast.lita"
struct litaC_ast__SubscriptSetExpr {
#line 549 "src/ast.lita"
litaC_ast__Expr expr;

#line 550 "src/ast.lita"
litaC_ast__Expr* object;

#line 551 "src/ast.lita"
litaC_ast__Expr* index;

#line 552 "src/ast.lita"
litaC_lex__TokenType operator;

#line 553 "src/ast.lita"
litaC_ast__Expr* value;
};


#line 70 "src/intern.lita"
struct litaC_intern__Strings {
#line 71 "src/intern.lita"
const litaC_mem__Allocator* allocator;

#line 72 "src/intern.lita"
litaC_map__Map_cb_StringView_c_InternedString_ce_ strings;
};


#line 37 "src/lsp/protocol.lita"
struct litaC_protocol__TextDocumentDidChange {
#line 38 "src/lsp/protocol.lita"
litaC_protocol__TextDocument textDocument;

#line 40 "src/lsp/protocol.lita"
litaC_protocol__TextDocumentChangeEvent contentChanges[16];

#line 41 "src/lsp/protocol.lita"
litaC_i32 numOfContentChanges;
};


#line 84 "src/symbols.lita"
struct litaC_symbols__ProgramSymbols {
#line 85 "src/symbols.lita"
litaC_module__Module* root;

#line 86 "src/symbols.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ values;

#line 87 "src/symbols.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ symbolTypes;

#line 88 "src/symbols.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ symbolFuncs;

#line 89 "src/symbols.lita"
litaC_symbols__Symbol* mainEntry;

#line 90 "src/symbols.lita"
litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_ interfaceImpls;
};


#line 35 "src/lita.lita"
struct litaC_lita__Lita {
#line 36 "src/lita.lita"
const litaC_mem__Allocator* allocator;

#line 37 "src/lita.lita"
litaC_linear_allocator__LinearAllocator linearAllocator;

#line 38 "src/lita.lita"
litaC_bucket_allocator__BucketAllocator stringsAllocator;

#line 40 "src/lita.lita"
litaC_preprocessor__Preprocessor preprocessor;

#line 41 "src/lita.lita"
litaC_phase_result__PhaseResult result;

#line 42 "src/lita.lita"
litaC_map__Map_cb__ptr_const_char_c__ptr_Module_ce_ modules;

#line 43 "src/lita.lita"
litaC_lita__Metric metrics[
#line 43 "src/lita.lita"
litaC_lita__MetricType_MAX_METRIC_TYPES];

#line 45 "src/lita.lita"
litaC_u32 totalSourceLines;

#line 46 "src/lita.lita"
litaC_u32 totalAllocations;

#line 48 "src/lita.lita"
litaC_lita__LitaOptions* options;

#line 49 "src/lita.lita"
litaC_char binaryFilename[
#line 49 "src/lita.lita"
_MAX_PATH];

#line 50 "src/lita.lita"
litaC_char sourceFilename[
#line 50 "src/lita.lita"
_MAX_PATH];

#line 52 "src/lita.lita"
litaC_symbols__ProgramSymbols programSymbols;

#line 53 "src/lita.lita"
litaC_map__Map_cb_InternedString_c__ptr_Symbol_ce_ genericSymbols;

#line 55 "src/lita.lita"
litaC_intern__Strings strings;

#line 58 "src/lita.lita"
litaC_references__ReferenceDatabase references;

#line 59 "src/lita.lita"
litaC_workspace__Workspace* workspace;
};


#line 48 "src/checker.lita"
struct litaC_checker__TypeChecker {
#line 49 "src/checker.lita"
litaC_lita__Lita* lita;

#line 51 "src/checker.lita"
litaC_module__Module* current;

#line 52 "src/checker.lita"
litaC_array__Array_cb__ptr_Module_ce_ moduleStack;

#line 54 "src/checker.lita"
litaC_array__Array_cb__ptr_FuncTypeInfo_ce_ funcDeclStack;

#line 56 "src/checker.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ pendingValues;

#line 57 "src/checker.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ symbolTypes;

#line 58 "src/checker.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ symbolFuncs;

#line 59 "src/checker.lita"
litaC_symbols__Symbol* mainEntry;

#line 61 "src/checker.lita"
litaC_checker__GenericContext genericContext;

#line 62 "src/checker.lita"
litaC_array__Array_cb_Array_cb_GenericParam_ce__ce_ genericParamStack;

#line 63 "src/checker.lita"
litaC_array__Array_cb__ptr_Symbol_ce_ genericTemplates;

#line 65 "src/checker.lita"
litaC_map__Map_cb_i64_c_Array_cb_i64_ce__ce_ interfaceImpls;

#line 67 "src/checker.lita"
litaC_checker__LabelInfo labels[256];

#line 68 "src/checker.lita"
litaC_i32 numOfLabels;

#line 70 "src/checker.lita"
litaC_types_new__TypeCache typeCache;

#line 72 "src/checker.lita"
litaC_u32 randomNameIndex;

#line 74 "src/checker.lita"
litaC_bool bypassing;
};


#line 758 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
struct litaC_json__JsonParser {
#line 759 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_mem__Allocator* alloc;

#line 760 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__JsonParserStatus status;

#line 761 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_char errorMsg[256];

#line 763 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_json__Token token;

#line 764 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
litaC_string_buffer__StringBuffer buffer;

#line 765 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* stream;

#line 766 "C:/Users/antho/git/litac-lang/stdlib/std/json.lita"
const litaC_char* lineStart;
};


#line 20 "src/lsp/lsp.lita"
struct litaC_lsp__LspServer {
#line 21 "src/lsp/lsp.lita"
litaC_linear_allocator__LinearAllocator requestAllocator;

#line 22 "src/lsp/lsp.lita"
litaC_linear_allocator__LinearAllocator applicationAllocator;

#line 24 "src/lsp/lsp.lita"
litaC_lita__Lita* lita;

#line 26 "src/lsp/lsp.lita"
litaC_string_buffer__StringBuffer message;

#line 27 "src/lsp/lsp.lita"
litaC_string_buffer__StringBuffer output;

#line 28 "src/lsp/lsp.lita"
litaC_string_buffer__StringBuffer outbound;

#line 30 "src/lsp/lsp.lita"
litaC_bool isInitialized;

#line 31 "src/lsp/lsp.lita"
litaC_bool isRunning;

#line 33 "src/lsp/lsp.lita"
litaC_workspace__Workspace workspace;

#line 35 "src/lsp/lsp.lita"
FILE* logFile;
};


#line 73 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
struct litaC_map__MapEntry_cb_InternedString_c__ptr_Symbol_ce_ {
#line 74 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_intern__InternedString key;

#line 75 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_symbols__Symbol* value;

#line 76 "C:/Users/antho/git/litac-lang/stdlib/std/map.lita"
litaC_symbols__Symbol** valuePtr;
};


#line 2110 "src/types.lita"
struct litaC_types__FuncPtrTypeInfo {
#line 2111 "src/types.lita"
litaC_types__GenericTypeInfo info;

#line 2112 "src/types.lita"
litaC_array__Array_cb_GenericParam_ce_ genericParams;

#line 2113 "src/types.lita"
litaC_types__TypeInfo* returnType;

#line 2114 "src/types.lita"
litaC_array__Array_cb__ptr_TypeInfo_ce_ paramDecls;

#line 2115 "src/types.lita"
litaC_bool hasVarargs;

#line 2116 "src/types.lita"
litaC_bool isTrait;
};


#line 235 "src/ast.lita"
struct litaC_ast__FuncDecl {
#line 236 "src/ast.lita"
litaC_ast__GenericDecl decl;

#line 237 "src/ast.lita"
litaC_ast__ParametersStmt* params;

#line 238 "src/ast.lita"
litaC_ast__Stmt* body;

#line 239 "src/ast.lita"
litaC_ast__TypeSpec* returnType;

#line 240 "src/ast.lita"
litaC_i32 flags;
};


#line 278 "src/ast.lita"
struct litaC_ast__BreakStmt {
#line 279 "src/ast.lita"
litaC_ast__Stmt stmt;
};


#line 323 "src/ast.lita"
struct litaC_ast__FuncBodyStmt {
#line 324 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 325 "src/ast.lita"
litaC_array__Array_cb__ptr_Stmt_ce_ stmts;
};


#line 372 "src/ast.lita"
struct litaC_ast__SwitchCaseStmt {
#line 373 "src/ast.lita"
litaC_ast__Stmt stmt;

#line 374 "src/ast.lita"
litaC_ast__Expr* cond;

#line 375 "src/ast.lita"
litaC_ast__Stmt* body;
};


#line 419 "src/ast.lita"
struct litaC_ast__ArrayDesignationExpr {
#line 420 "src/ast.lita"
litaC_ast__Expr expr;

#line 421 "src/ast.lita"
litaC_ast__Expr* index;

#line 422 "src/ast.lita"
litaC_ast__Expr* value;
};


#line 517 "src/ast.lita"
struct litaC_ast__OffsetOfExpr {
#line 518 "src/ast.lita"
litaC_ast__Expr expr;

#line 519 "src/ast.lita"
litaC_ast__TypeSpec* type;

#line 520 "src/ast.lita"
litaC_lex__Token field;
};


#line 570 "src/ast.lita"
struct litaC_ast__TypeOfExpr {
#line 571 "src/ast.lita"
litaC_ast__Expr expr;

#line 572 "src/ast.lita"
litaC_ast__Expr* typeOfExpr;

#line 573 "src/ast.lita"
litaC_ast__TypeSpec* type;
};


#line 33 "src/lsp/workspace.lita"
struct litaC_workspace__Document {
#line 34 "src/lsp/workspace.lita"
litaC_char filename[
#line 34 "src/lsp/workspace.lita"
_MAX_PATH];

#line 35 "src/lsp/workspace.lita"
litaC_string_buffer__StringBuffer text;

#line 37 "src/lsp/workspace.lita"
litaC_array__Array_cb_u32_ce_ lineMap;
};


#line 158 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
const litaC_mem__Allocator* litaC_mem__cAllocator = (const litaC_mem__Allocator*)(&((litaC_mem__Allocator) {
#line 159 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
.allocFn = &(litaC_mem__cMalloc),

#line 160 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
.callocFn = &(litaC_mem__cCalloc),

#line 161 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
.reallocFn = &(litaC_mem__cRealloc),

#line 162 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
.freeFn = &(litaC_mem__cFree)}));

#line 331 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
litaC_mem__DebugAllocator* litaC_mem__debugAllocator = (&((litaC_mem__DebugAllocator) {}));

#line 529 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
LITAC_THREADLOCAL 
const litaC_mem__Allocator* litaC_mem__defaultAllocator = (const litaC_mem__Allocator*)(&((litaC_mem__Allocator) {
#line 530 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
.allocFn = &(litaC_mem__cMalloc),

#line 531 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
.callocFn = &(litaC_mem__cCalloc),

#line 532 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
.reallocFn = &(litaC_mem__cRealloc),

#line 533 "C:/Users/antho/git/litac-lang/stdlib/std/mem/mem.lita"
.freeFn = &(litaC_mem__cFree)}));

#line 141 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"

#define litaC_system__OPEN_MODE ("rt")

#line 154 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"

#define litaC_system__PATH_SEPARATOR ("\\")

#line 335 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
const litaC_char* litaC_system__uriEscapeChars[256] =  {
#line 336 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
[' '] = "%20",

#line 337 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['!'] = "%21",

#line 338 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['#'] = "%23",

#line 339 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['$'] = "%24",

#line 340 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['%'] = "%25",

#line 341 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['&'] = "%26",

#line 342 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['\''] = "%27",

#line 343 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['('] = "%28",

#line 344 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
[')'] = "%29",

#line 345 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['*'] = "%2A",

#line 346 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['+'] = "%2B",

#line 347 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
[','] = "%2C",

#line 349 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
[':'] = "%3A",

#line 350 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
[';'] = "%3B",

#line 351 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['='] = "%3D",

#line 352 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['?'] = "%3F",

#line 353 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['@'] = "%40",

#line 354 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
['['] = "%5B",

#line 355 "C:/Users/antho/git/litac-lang/stdlib/std/system/system.lita"
[']'] = "%5D"};

#line 57 "C:/Users/antho/git/litac-lang/stdlib/std/system/system_win.lita"
litaC_f64 litaC_system_win__systemFreq;

#line 58 "C:/Users/antho/git/litac-lang/stdlib/std/system/system_win.lita"
litaC_u64 litaC_system_win__systemStart = 0;

#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/system/system_win.lita"
litaC_char litaC_system_win__pwd[
#line 79 "C:/Users/antho/git/litac-lang/stdlib/std/system/system_win.lita"
_MAX_PATH] =  {0};

#line 14 "C:/Users/antho/git/litac-lang/stdlib/std/profile.lita"

litaC_profile__ProfileEntry litaC_profile__profileEntries[1] =  {};

#line 135 "src/lex.lita"
const litaC_char* litaC_lex__tokenText[
#line 135 "src/lex.lita"
litaC_lex__TokenType_MAX_TOKEN_TYPES] =  {
#line 136 "src/lex.lita"
[litaC_lex__TokenType_IMPORT] = "import",

#line 138 "src/lex.lita"
[litaC_lex__TokenType_STRUCT] = "struct",

#line 139 "src/lex.lita"
[litaC_lex__TokenType_UNION] = "union",

#line 140 "src/lex.lita"
[litaC_lex__TokenType_TRAIT] = "trait",

#line 141 "src/lex.lita"
[litaC_lex__TokenType_ENUM] = "enum",

#line 142 "src/lex.lita"
[litaC_lex__TokenType_FUNC] = "func",

#line 143 "src/lex.lita"
[litaC_lex__TokenType_TYPEDEF] = "typedef",

#line 144 "src/lex.lita"
[litaC_lex__TokenType_VAR] = "var",

#line 145 "src/lex.lita"
[litaC_lex__TokenType_CONST] = "const",

#line 147 "src/lex.lita"
[litaC_lex__TokenType_NULL] = "null",

#line 148 "src/lex.lita"
[litaC_lex__TokenType_VOID] = "void",

#line 149 "src/lex.lita"
[litaC_lex__TokenType_TRUE] = "true",

#line 150 "src/lex.lita"
[litaC_lex__TokenType_FALSE] = "false",

#line 151 "src/lex.lita"
[litaC_lex__TokenType_BOOL] = "bool",

#line 152 "src/lex.lita"
[litaC_lex__TokenType_CHAR] = "char",

#line 153 "src/lex.lita"
[litaC_lex__TokenType_I8] = "i8",

#line 154 "src/lex.lita"
[litaC_lex__TokenType_U8] = "u8",

#line 155 "src/lex.lita"
[litaC_lex__TokenType_I16] = "i16",

#line 156 "src/lex.lita"
[litaC_lex__TokenType_U16] = "u16",

#line 157 "src/lex.lita"
[litaC_lex__TokenType_I32] = "i32",

#line 158 "src/lex.lita"
[litaC_lex__TokenType_U32] = "u32",

#line 159 "src/lex.lita"
[litaC_lex__TokenType_I64] = "i64",

#line 160 "src/lex.lita"
[litaC_lex__TokenType_U64] = "u64",

#line 161 "src/lex.lita"
[litaC_lex__TokenType_F32] = "f32",

#line 162 "src/lex.lita"
[litaC_lex__TokenType_F64] = "f64",

#line 163 "src/lex.lita"
[litaC_lex__TokenType_USIZE] = "usize",

#line 165 "src/lex.lita"
[litaC_lex__TokenType_FOR] = "for",

#line 166 "src/lex.lita"
[litaC_lex__TokenType_WHILE] = "while",

#line 167 "src/lex.lita"
[litaC_lex__TokenType_DO] = "do",

#line 168 "src/lex.lita"
[litaC_lex__TokenType_IF] = "if",

#line 169 "src/lex.lita"
[litaC_lex__TokenType_ELSE] = "else",

#line 170 "src/lex.lita"
[litaC_lex__TokenType_SWITCH] = "switch",

#line 171 "src/lex.lita"
[litaC_lex__TokenType_CASE] = "case",

#line 172 "src/lex.lita"
[litaC_lex__TokenType_DEFAULT] = "default",

#line 173 "src/lex.lita"
[litaC_lex__TokenType_DEFER] = "defer",

#line 175 "src/lex.lita"
[litaC_lex__TokenType_BREAK] = "break",

#line 176 "src/lex.lita"
[litaC_lex__TokenType_CONTINUE] = "continue",

#line 177 "src/lex.lita"
[litaC_lex__TokenType_RETURN] = "return",

#line 178 "src/lex.lita"
[litaC_lex__TokenType_GOTO] = "goto",

#line 180 "src/lex.lita"
[litaC_lex__TokenType_SIZEOF] = "sizeof",

#line 181 "src/lex.lita"
[litaC_lex__TokenType_TYPEOF] = "typeof",

#line 182 "src/lex.lita"
[litaC_lex__TokenType_OFFSETOF] = "offsetof",

#line 184 "src/lex.lita"
[litaC_lex__TokenType_AS] = "as",

#line 185 "src/lex.lita"
[litaC_lex__TokenType_PUBLIC] = "public",

#line 186 "src/lex.lita"
[litaC_lex__TokenType_USING] = "using",

#line 191 "src/lex.lita"
[litaC_lex__TokenType_PLUS] = "+",

#line 192 "src/lex.lita"
[litaC_lex__TokenType_MINUS] = "-",

#line 193 "src/lex.lita"
[litaC_lex__TokenType_STAR] = "*",

#line 194 "src/lex.lita"
[litaC_lex__TokenType_MOD] = "%",

#line 195 "src/lex.lita"
[litaC_lex__TokenType_SLASH] = "/",

#line 196 "src/lex.lita"
[litaC_lex__TokenType_BACK_SLASH] = "\\",

#line 197 "src/lex.lita"
[litaC_lex__TokenType_DOLLAR] = "$",

#line 198 "src/lex.lita"
[litaC_lex__TokenType_HASH] = "#",

#line 199 "src/lex.lita"
[litaC_lex__TokenType_DOT] = ".",

#line 200 "src/lex.lita"
[litaC_lex__TokenType_VAR_ARGS] = "...",

#line 201 "src/lex.lita"
[litaC_lex__TokenType_AT] = "@",

#line 202 "src/lex.lita"
[litaC_lex__TokenType_QUESTION_MARK] = "?",

#line 203 "src/lex.lita"
[litaC_lex__TokenType_COMMA] = ",",

#line 204 "src/lex.lita"
[litaC_lex__TokenType_SEMICOLON] = ";",

#line 205 "src/lex.lita"
[litaC_lex__TokenType_COLON] = ":",

#line 206 "src/lex.lita"
[litaC_lex__TokenType_COLON_COLON] = "::",

#line 207 "src/lex.lita"
[litaC_lex__TokenType_DOUBLE_QUOTE] = "\"",

#line 209 "src/lex.lita"
[litaC_lex__TokenType_LESS_THAN] = "<",

#line 210 "src/lex.lita"
[litaC_lex__TokenType_LESS_EQUALS] = "<=",

#line 211 "src/lex.lita"
[litaC_lex__TokenType_GREATER_THAN] = ">",

#line 212 "src/lex.lita"
[litaC_lex__TokenType_GREATER_EQUALS] = ">=",

#line 213 "src/lex.lita"
[litaC_lex__TokenType_EQUALS_EQUALS] = "==",

#line 214 "src/lex.lita"
[litaC_lex__TokenType_EQUALS] = "=",

#line 215 "src/lex.lita"
[litaC_lex__TokenType_NOT_EQUALS] = "!=",

#line 216 "src/lex.lita"
[litaC_lex__TokenType_PLUS_EQ] = "+=",

#line 217 "src/lex.lita"
[litaC_lex__TokenType_MINUS_EQ] = "-=",

#line 218 "src/lex.lita"
[litaC_lex__TokenType_DIV_EQ] = "/=",

#line 219 "src/lex.lita"
[litaC_lex__TokenType_MUL_EQ] = "*=",

#line 220 "src/lex.lita"
[litaC_lex__TokenType_MOD_EQ] = "%=",

#line 221 "src/lex.lita"
[litaC_lex__TokenType_LSHIFT_EQ] = "<<=",

#line 222 "src/lex.lita"
[litaC_lex__TokenType_RSHIFT_EQ] = ">>=",

#line 223 "src/lex.lita"
[litaC_lex__TokenType_BNOT_EQ] = "~=",

#line 224 "src/lex.lita"
[litaC_lex__TokenType_XOR_EQ] = "^=",

#line 225 "src/lex.lita"
[litaC_lex__TokenType_BAND_EQ] = "&=",

#line 226 "src/lex.lita"
[litaC_lex__TokenType_BOR_EQ] = "|=",

#line 228 "src/lex.lita"
[litaC_lex__TokenType_LSHIFT] = "<<",

#line 229 "src/lex.lita"
[litaC_lex__TokenType_RSHIFT] = ">>",

#line 230 "src/lex.lita"
[litaC_lex__TokenType_BNOT] = "~",

#line 231 "src/lex.lita"
[litaC_lex__TokenType_XOR] = "^",

#line 232 "src/lex.lita"
[litaC_lex__TokenType_BAND] = "&",

#line 233 "src/lex.lita"
[litaC_lex__TokenType_BOR] = "|",

#line 235 "src/lex.lita"
[litaC_lex__TokenType_LEFT_PAREN] = "(",

#line 236 "src/lex.lita"
[litaC_lex__TokenType_RIGHT_PAREN] = ")",

#line 237 "src/lex.lita"
[litaC_lex__TokenType_LEFT_BRACKET] = "[",

#line 238 "src/lex.lita"
[litaC_lex__TokenType_RIGHT_BRACKET] = "]",

#line 239 "src/lex.lita"
[litaC_lex__TokenType_LEFT_BRACE] = "{",

#line 240 "src/lex.lita"
[litaC_lex__TokenType_RIGHT_BRACE] = "}",

#line 242 "src/lex.lita"
[litaC_lex__TokenType_NOT] = "!",

#line 243 "src/lex.lita"
[litaC_lex__TokenType_OR] = "||",

#line 244 "src/lex.lita"
[litaC_lex__TokenType_AND] = "&&",

#line 246 "src/lex.lita"
[litaC_lex__TokenType_STRING] = "STRING",

#line 247 "src/lex.lita"
[litaC_lex__TokenType_IDENTIFIER] = "IDENTIFER",

#line 248 "src/lex.lita"
[litaC_lex__TokenType_INT_NUMBER] = "INT_NUMBER",

#line 249 "src/lex.lita"
[litaC_lex__TokenType_FLOAT_NUMBER] = "FLOAT_NUMBER",

#line 250 "src/lex.lita"
[litaC_lex__TokenType_ERROR] = "ERROR",

#line 251 "src/lex.lita"
[litaC_lex__TokenType_END_OF_FILE] = "EOF"};

#line 254 "src/lex.lita"
litaC_i32 litaC_lex__charToDigit[256] =  {
#line 255 "src/lex.lita"
['0'] = 0,

#line 256 "src/lex.lita"
['1'] = 1,

#line 257 "src/lex.lita"
['2'] = 2,

#line 258 "src/lex.lita"
['3'] = 3,

#line 259 "src/lex.lita"
['4'] = 4,

#line 260 "src/lex.lita"
['5'] = 5,

#line 261 "src/lex.lita"
['6'] = 6,

#line 262 "src/lex.lita"
['7'] = 7,

#line 263 "src/lex.lita"
['8'] = 8,

#line 264 "src/lex.lita"
['9'] = 9,

#line 265 "src/lex.lita"
['a'] = 10,
['A'] = 10,

#line 266 "src/lex.lita"
['b'] = 11,
['B'] = 11,

#line 267 "src/lex.lita"
['c'] = 12,
['C'] = 12,

#line 268 "src/lex.lita"
['d'] = 13,
['D'] = 13,

#line 269 "src/lex.lita"
['e'] = 14,
['E'] = 14,

#line 270 "src/lex.lita"
['f'] = 15,
['F'] = 15};

#line 273 "src/lex.lita"
litaC_char litaC_lex__escapeToChar[256] =  {
#line 274 "src/lex.lita"
['b'] = '\b',

#line 275 "src/lex.lita"
['f'] = '\f',

#line 276 "src/lex.lita"
['n'] = '\n',

#line 277 "src/lex.lita"
['r'] = '\r',

#line 278 "src/lex.lita"
['t'] = '\t',

#line 279 "src/lex.lita"
['\\'] = '\\',

#line 280 "src/lex.lita"
['\''] = '\'',

#line 281 "src/lex.lita"
['"'] = '"',

#line 282 "src/lex.lita"
['0'] = '\0',

#line 284 "src/lex.lita"
['/'] = '/'};

#line 291 "src/lex.lita"
const litaC_char** litaC_lex__keywordCache[9] =  {
#line 292 "src/lex.lita"
[0] = (const litaC_char*[1]) {
#line 293 "src/lex.lita"
NULL},

#line 295 "src/lex.lita"
[1] = (const litaC_char*[1]) {
#line 296 "src/lex.lita"
NULL},

#line 298 "src/lex.lita"
[2] = (const litaC_char*[6]) {
#line 299 "src/lex.lita"
"i8",

#line 300 "src/lex.lita"
"u8",

#line 301 "src/lex.lita"
"do",

#line 302 "src/lex.lita"
"if",

#line 303 "src/lex.lita"
"as",

#line 304 "src/lex.lita"
NULL},

#line 306 "src/lex.lita"
[3] = (const litaC_char*[11]) {
#line 307 "src/lex.lita"
"var",

#line 308 "src/lex.lita"
"i16",

#line 309 "src/lex.lita"
"u16",

#line 310 "src/lex.lita"
"i32",

#line 311 "src/lex.lita"
"u32",

#line 312 "src/lex.lita"
"i64",

#line 313 "src/lex.lita"
"u64",

#line 314 "src/lex.lita"
"f32",

#line 315 "src/lex.lita"
"f64",

#line 316 "src/lex.lita"
"for",

#line 317 "src/lex.lita"
NULL},

#line 319 "src/lex.lita"
[4] = (const litaC_char*[11]) {
#line 320 "src/lex.lita"
"enum",

#line 321 "src/lex.lita"
"func",

#line 322 "src/lex.lita"
"null",

#line 323 "src/lex.lita"
"void",

#line 324 "src/lex.lita"
"true",

#line 325 "src/lex.lita"
"bool",

#line 326 "src/lex.lita"
"char",

#line 327 "src/lex.lita"
"else",

#line 328 "src/lex.lita"
"case",

#line 329 "src/lex.lita"
"goto",

#line 330 "src/lex.lita"
NULL},

#line 332 "src/lex.lita"
[5] = (const litaC_char*[10]) {
#line 333 "src/lex.lita"
"trait",

#line 334 "src/lex.lita"
"union",

#line 335 "src/lex.lita"
"const",

#line 336 "src/lex.lita"
"false",

#line 337 "src/lex.lita"
"usize",

#line 338 "src/lex.lita"
"defer",

#line 339 "src/lex.lita"
"while",

#line 340 "src/lex.lita"
"break",

#line 341 "src/lex.lita"
"using",

#line 342 "src/lex.lita"
NULL},

#line 344 "src/lex.lita"
[6] = (const litaC_char*[8]) {
#line 345 "src/lex.lita"
"import",

#line 346 "src/lex.lita"
"struct",

#line 347 "src/lex.lita"
"switch",

#line 348 "src/lex.lita"
"return",

#line 349 "src/lex.lita"
"sizeof",

#line 350 "src/lex.lita"
"typeof",

#line 351 "src/lex.lita"
"public",

#line 352 "src/lex.lita"
NULL},

#line 354 "src/lex.lita"
[7] = (const litaC_char*[3]) {
#line 355 "src/lex.lita"
"typedef",

#line 356 "src/lex.lita"
"default",

#line 357 "src/lex.lita"
NULL},

#line 359 "src/lex.lita"
[8] = (const litaC_char*[3]) {
#line 360 "src/lex.lita"
"continue",

#line 361 "src/lex.lita"
"offsetof",

#line 362 "src/lex.lita"
NULL}};

#line 366 "src/lex.lita"
litaC_lex__TokenType* litaC_lex__keywordCacheIndex[9] =  {
#line 367 "src/lex.lita"
[2] = (litaC_lex__TokenType[5]) {
#line 368 "src/lex.lita"
litaC_lex__TokenType_I8,

#line 369 "src/lex.lita"
litaC_lex__TokenType_U8,

#line 370 "src/lex.lita"
litaC_lex__TokenType_DO,

#line 371 "src/lex.lita"
litaC_lex__TokenType_IF,

#line 372 "src/lex.lita"
litaC_lex__TokenType_AS},

#line 374 "src/lex.lita"
[3] = (litaC_lex__TokenType[10]) {
#line 375 "src/lex.lita"
litaC_lex__TokenType_VAR,

#line 376 "src/lex.lita"
litaC_lex__TokenType_I16,

#line 377 "src/lex.lita"
litaC_lex__TokenType_U16,

#line 378 "src/lex.lita"
litaC_lex__TokenType_I32,

#line 379 "src/lex.lita"
litaC_lex__TokenType_U32,

#line 380 "src/lex.lita"
litaC_lex__TokenType_I64,

#line 381 "src/lex.lita"
litaC_lex__TokenType_U64,

#line 382 "src/lex.lita"
litaC_lex__TokenType_F32,

#line 383 "src/lex.lita"
litaC_lex__TokenType_F64,

#line 384 "src/lex.lita"
litaC_lex__TokenType_FOR},

#line 386 "src/lex.lita"
[4] = (litaC_lex__TokenType[10]) {
#line 387 "src/lex.lita"
litaC_lex__TokenType_ENUM,

#line 388 "src/lex.lita"
litaC_lex__TokenType_FUNC,

#line 389 "src/lex.lita"
litaC_lex__TokenType_NULL,

#line 390 "src/lex.lita"
litaC_lex__TokenType_VOID,

#line 391 "src/lex.lita"
litaC_lex__TokenType_TRUE,

#line 392 "src/lex.lita"
litaC_lex__TokenType_BOOL,

#line 393 "src/lex.lita"
litaC_lex__TokenType_CHAR,

#line 394 "src/lex.lita"
litaC_lex__TokenType_ELSE,

#line 395 "src/lex.lita"
litaC_lex__TokenType_CASE,

#line 396 "src/lex.lita"
litaC_lex__TokenType_GOTO},

#line 398 "src/lex.lita"
[5] = (litaC_lex__TokenType[9]) {
#line 399 "src/lex.lita"
litaC_lex__TokenType_TRAIT,

#line 400 "src/lex.lita"
litaC_lex__TokenType_UNION,

#line 401 "src/lex.lita"
litaC_lex__TokenType_CONST,

#line 402 "src/lex.lita"
litaC_lex__TokenType_FALSE,

#line 403 "src/lex.lita"
litaC_lex__TokenType_USIZE,

#line 404 "src/lex.lita"
litaC_lex__TokenType_DEFER,

#line 405 "src/lex.lita"
litaC_lex__TokenType_WHILE,

#line 406 "src/lex.lita"
litaC_lex__TokenType_BREAK,

#line 407 "src/lex.lita"
litaC_lex__TokenType_USING},

#line 409 "src/lex.lita"
[6] = (litaC_lex__TokenType[7]) {
#line 410 "src/lex.lita"
litaC_lex__TokenType_IMPORT,

#line 411 "src/lex.lita"
litaC_lex__TokenType_STRUCT,

#line 412 "src/lex.lita"
litaC_lex__TokenType_SWITCH,

#line 413 "src/lex.lita"
litaC_lex__TokenType_RETURN,

#line 414 "src/lex.lita"
litaC_lex__TokenType_SIZEOF,

#line 415 "src/lex.lita"
litaC_lex__TokenType_TYPEOF,

#line 416 "src/lex.lita"
litaC_lex__TokenType_PUBLIC},

#line 418 "src/lex.lita"
[7] = (litaC_lex__TokenType[2]) {
#line 419 "src/lex.lita"
litaC_lex__TokenType_TYPEDEF,

#line 420 "src/lex.lita"
litaC_lex__TokenType_DEFAULT},

#line 422 "src/lex.lita"
[8] = (litaC_lex__TokenType[2]) {
#line 423 "src/lex.lita"
litaC_lex__TokenType_CONTINUE,

#line 424 "src/lex.lita"
litaC_lex__TokenType_OFFSETOF}};

#line 56 "src/types.lita"
const litaC_char* litaC_types__typeKindText[
#line 56 "src/types.lita"
litaC_types__TypeKind_MAX_TYPE_KINDS + 1] =  {
#line 57 "src/types.lita"
[litaC_types__TypeKind_BOOL] = "bool",

#line 58 "src/types.lita"
[litaC_types__TypeKind_CHAR] = "char",

#line 59 "src/types.lita"
[litaC_types__TypeKind_I8] = "i8",

#line 60 "src/types.lita"
[litaC_types__TypeKind_U8] = "u8",

#line 61 "src/types.lita"
[litaC_types__TypeKind_I16] = "i16",

#line 62 "src/types.lita"
[litaC_types__TypeKind_U16] = "u16",

#line 63 "src/types.lita"
[litaC_types__TypeKind_I32] = "i32",

#line 64 "src/types.lita"
[litaC_types__TypeKind_U32] = "u32",

#line 65 "src/types.lita"
[litaC_types__TypeKind_I64] = "i64",

#line 66 "src/types.lita"
[litaC_types__TypeKind_U64] = "u64",

#line 67 "src/types.lita"
[litaC_types__TypeKind_F32] = "f32",

#line 68 "src/types.lita"
[litaC_types__TypeKind_F64] = "f64",

#line 69 "src/types.lita"
[litaC_types__TypeKind_USIZE] = "usize",

#line 70 "src/types.lita"
[litaC_types__TypeKind_NULL] = "null",

#line 71 "src/types.lita"
[litaC_types__TypeKind_VOID] = "void",

#line 73 "src/types.lita"
[litaC_types__TypeKind_STR] = "string",

#line 74 "src/types.lita"
[litaC_types__TypeKind_ARRAY] = "array",

#line 75 "src/types.lita"
[litaC_types__TypeKind_PTR] = "pointer",

#line 76 "src/types.lita"
[litaC_types__TypeKind_FUNC_PTR] = "func_pointer",

#line 78 "src/types.lita"
[litaC_types__TypeKind_STRUCT] = "struct",

#line 79 "src/types.lita"
[litaC_types__TypeKind_UNION] = "union",

#line 80 "src/types.lita"
[litaC_types__TypeKind_TRAIT] = "trait",

#line 81 "src/types.lita"
[litaC_types__TypeKind_ENUM] = "enum",

#line 82 "src/types.lita"
[litaC_types__TypeKind_FUNC] = "func",

#line 84 "src/types.lita"
[litaC_types__TypeKind_CONST] = "const",

#line 85 "src/types.lita"
[litaC_types__TypeKind_GENERIC_PARAM] = "generic_param",

#line 86 "src/types.lita"
[litaC_types__TypeKind_POISON] = "poison",

#line 88 "src/types.lita"
[litaC_types__TypeKind_MAX_TYPE_KINDS] = ""};

#line 2043 "src/types.lita"
litaC_i64 litaC_types__idGen = (litaC_i64)litaC_types__TypeKind_MAX_TYPE_KINDS;

#line 2129 "src/types.lita"
litaC_types__TypeInfo litaC_types__BOOL_TYPE =  {
#line 2130 "src/types.lita"
.kind = litaC_types__TypeKind_BOOL,

#line 2131 "src/types.lita"
.typeid = (litaC_i64)litaC_types__TypeKind_BOOL,

#line 2132 "src/types.lita"
.sym = NULL};

#line 2135 "src/types.lita"
litaC_types__TypeInfo litaC_types__CHAR_TYPE =  {
#line 2136 "src/types.lita"
.kind = litaC_types__TypeKind_CHAR,

#line 2137 "src/types.lita"
.typeid = (litaC_i64)litaC_types__TypeKind_CHAR,

#line 2138 "src/types.lita"
.sym = NULL};

#line 2141 "src/types.lita"
litaC_types__TypeInfo litaC_types__I8_TYPE =  {
#line 2142 "src/types.lita"
.kind = litaC_types__TypeKind_I8,

#line 2143 "src/types.lita"
.typeid = (litaC_i64)litaC_types__TypeKind_I8,

#line 2144 "src/types.lita"
.sym = NULL};

#line 2147 "src/types.lita"
litaC_types__TypeInfo litaC_types__U8_TYPE =  {
#line 2148 "src/types.lita"
.kind = litaC_types__TypeKind_U8,

#line 2149 "src/types.lita"
.typeid = (litaC_i64)litaC_types__TypeKind_U8,

#line 2150 "src/types.lita"
.sym = NULL};

#line 2153 "src/types.lita"
litaC_types__TypeIn