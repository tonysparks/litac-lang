/*
https://github.com/dnmfarrell/URI-Encode-C/tree/master


This software is Copyright (c) 2016 by David Farrell.

This is free software, licensed under:

  The (two-clause) FreeBSD License

The FreeBSD License

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the
     distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <stdlib.h>
#include <inttypes.h>

#define _______ "\0\0\0\0"
static const char litac_uri_encode_tbl[ sizeof(int32_t) * 0x100 ] = {
/*  0       1       2       3       4       5       6       7       8       9       a       b       c       d       e       f                        */
    "%00\0" "%01\0" "%02\0" "%03\0" "%04\0" "%05\0" "%06\0" "%07\0" "%08\0" "%09\0" "%0A\0" "%0B\0" "%0C\0" "%0D\0" "%0E\0" "%0F\0"  /* 0:   0 ~  15 */
    "%10\0" "%11\0" "%12\0" "%13\0" "%14\0" "%15\0" "%16\0" "%17\0" "%18\0" "%19\0" "%1A\0" "%1B\0" "%1C\0" "%1D\0" "%1E\0" "%1F\0"  /* 1:  16 ~  31 */
    "%20\0" "%21\0" "%22\0" "%23\0" "%24\0" "%25\0" "%26\0" "%27\0" "%28\0" "%29\0" "%2A\0" "%2B\0" "%2C\0" _______ _______ "%2F\0"  /* 2:  32 ~  47 */
    _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ "%3A\0" "%3B\0" "%3C\0" "%3D\0" "%3E\0" "%3F\0"  /* 3:  48 ~  63 */
    "%40\0" _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______  /* 4:  64 ~  79 */
    _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ "%5B\0" "%5C\0" "%5D\0" "%5E\0" _______  /* 5:  80 ~  95 */
    "%60\0" _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______  /* 6:  96 ~ 111 */
    _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ _______ "%7B\0" "%7C\0" "%7D\0" _______ "%7F\0"  /* 7: 112 ~ 127 */
    "%80\0" "%81\0" "%82\0" "%83\0" "%84\0" "%85\0" "%86\0" "%87\0" "%88\0" "%89\0" "%8A\0" "%8B\0" "%8C\0" "%8D\0" "%8E\0" "%8F\0"  /* 8: 128 ~ 143 */
    "%90\0" "%91\0" "%92\0" "%93\0" "%94\0" "%95\0" "%96\0" "%97\0" "%98\0" "%99\0" "%9A\0" "%9B\0" "%9C\0" "%9D\0" "%9E\0" "%9F\0"  /* 9: 144 ~ 159 */
    "%A0\0" "%A1\0" "%A2\0" "%A3\0" "%A4\0" "%A5\0" "%A6\0" "%A7\0" "%A8\0" "%A9\0" "%AA\0" "%AB\0" "%AC\0" "%AD\0" "%AE\0" "%AF\0"  /* A: 160 ~ 175 */
    "%B0\0" "%B1\0" "%B2\0" "%B3\0" "%B4\0" "%B5\0" "%B6\0" "%B7\0" "%B8\0" "%B9\0" "%BA\0" "%BB\0" "%BC\0" "%BD\0" "%BE\0" "%BF\0"  /* B: 176 ~ 191 */
    "%C0\0" "%C1\0" "%C2\0" "%C3\0" "%C4\0" "%C5\0" "%C6\0" "%C7\0" "%C8\0" "%C9\0" "%CA\0" "%CB\0" "%CC\0" "%CD\0" "%CE\0" "%CF\0"  /* C: 192 ~ 207 */
    "%D0\0" "%D1\0" "%D2\0" "%D3\0" "%D4\0" "%D5\0" "%D6\0" "%D7\0" "%D8\0" "%D9\0" "%DA\0" "%DB\0" "%DC\0" "%DD\0" "%DE\0" "%DF\0"  /* D: 208 ~ 223 */
    "%E0\0" "%E1\0" "%E2\0" "%E3\0" "%E4\0" "%E5\0" "%E6\0" "%E7\0" "%E8\0" "%E9\0" "%EA\0" "%EB\0" "%EC\0" "%ED\0" "%EE\0" "%EF\0"  /* E: 224 ~ 239 */
    "%F0\0" "%F1\0" "%F2\0" "%F3\0" "%F4\0" "%F5\0" "%F6\0" "%F7\0" "%F8\0" "%F9\0" "%FA\0" "%FB\0" "%FC\0" "%FD\0" "%FE\0" "%FF"    /* F: 240 ~ 255 */
};
#undef _______

#define __ 0xFF
static const unsigned char litac_hexval[0x100] = {
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* 00-0F */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* 10-1F */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* 20-2F */
   0, 1, 2, 3, 4, 5, 6, 7, 8, 9,__,__,__,__,__,__, /* 30-3F */
  __,10,11,12,13,14,15,__,__,__,__,__,__,__,__,__, /* 40-4F */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* 50-5F */
  __,10,11,12,13,14,15,__,__,__,__,__,__,__,__,__, /* 60-6F */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* 70-7F */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* 80-8F */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* 90-9F */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* A0-AF */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* B0-BF */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* C0-CF */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* D0-DF */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* E0-EF */
  __,__,__,__,__,__,__,__,__,__,__,__,__,__,__,__, /* F0-FF */
};
#undef __

size_t litac_uri_encode (const char *src, const size_t len, char *dst);
size_t litac_uri_decode (const char *src, const size_t len, char *dst);