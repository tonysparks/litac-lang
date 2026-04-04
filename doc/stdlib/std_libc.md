# std::libc

## Functions

<a id="func-malloc"></a>

### func malloc(size: usize) : \*void

*public* | *stdlib/std/libc/libc.lita:66*

---

<a id="func-realloc"></a>

### func realloc(ptr: \*void, size: usize) : \*void

*public* | *stdlib/std/libc/libc.lita:67*

---

<a id="func-calloc"></a>

### func calloc(num: usize, size: usize) : \*void

*public* | *stdlib/std/libc/libc.lita:68*

---

<a id="func-free"></a>

### func free(ptr: \*void) : void

*public* | *stdlib/std/libc/libc.lita:69*

---

<a id="func-memset"></a>

### func memset(ptr: \*void, value: i32, num: usize) : \*void

*public* | *stdlib/std/libc/libc.lita:71*

---

<a id="func-memcpy"></a>

### func memcpy(dest: \*void, src: \*const void, num: usize) : \*void

*public* | *stdlib/std/libc/libc.lita:72*

---

<a id="func-memmove"></a>

### func memmove(dest: \*void, src: \*const void, num: usize) : \*void

*public* | *stdlib/std/libc/libc.lita:73*

---

<a id="func-printf"></a>

### func printf(s: \*const char, ...) : void

*public* | *stdlib/std/libc/libc.lita:80*

---

<a id="func-fprintf"></a>

### func fprintf(stream: \*[FILE](std_libc.md#struct-file), s: \*const char, ...) : void

*public* | *stdlib/std/libc/libc.lita:81*

---

<a id="func-fflush"></a>

### func fflush(stream: \*[FILE](std_libc.md#struct-file)) : void

*public* | *stdlib/std/libc/libc.lita:82*

---

<a id="func-fopen"></a>

### func fopen(fileName: \*const char, openType: \*const char) : \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/libc/libc.lita:83*

---

<a id="func-fgets"></a>

### func fgets(buf: \*char, n: i64, stream: \*[FILE](std_libc.md#struct-file)) : \*char

*public* | *stdlib/std/libc/libc.lita:84*

---

<a id="func-fputc"></a>

### func fputc(c: i32, stream: \*[FILE](std_libc.md#struct-file)) : i32

*public* | *stdlib/std/libc/libc.lita:85*

---

<a id="func-fread"></a>

### func fread(buf: \*char, size: usize, n: usize, stream: \*[FILE](std_libc.md#struct-file)) : usize

*public* | *stdlib/std/libc/libc.lita:86*

---

<a id="func-fwrite"></a>

### func fwrite(buf: \*const void, sizeOfElements: usize, numOfElements: usize, stream: \*[FILE](std_libc.md#struct-file)) : usize

*public* | *stdlib/std/libc/libc.lita:87*

---

<a id="func-fclose"></a>

### func fclose(stream: \*[FILE](std_libc.md#struct-file)) : void

*public* | *stdlib/std/libc/libc.lita:88*

---

<a id="func-fseek"></a>

### func fseek(stream: \*[FILE](std_libc.md#struct-file), offset: i64, whence: i32) : i32

*public* | *stdlib/std/libc/libc.lita:89*

---

<a id="func-ftell"></a>

### func ftell(stream: \*[FILE](std_libc.md#struct-file)) : i64

*public* | *stdlib/std/libc/libc.lita:90*

---

<a id="func-ferror"></a>

### func ferror(stream: \*[FILE](std_libc.md#struct-file)) : i32

*public* | *stdlib/std/libc/libc.lita:91*

---

<a id="func-remove"></a>

### func remove(filename: \*const char) : i32

*public* | *stdlib/std/libc/libc.lita:92*

---

<a id="func-rename"></a>

### func rename(src: \*const char, dst: \*const char) : i32

*public* | *stdlib/std/libc/libc.lita:93*

---

<a id="func-scanf"></a>

### func scanf(format: \*const char, ...) : i32

*public* | *stdlib/std/libc/libc.lita:94*

---

<a id="func-fscanf"></a>

### func fscanf(stream: \*[FILE](std_libc.md#struct-file), format: \*const char, ...) : i32

*public* | *stdlib/std/libc/libc.lita:95*

---

<a id="func-getchar"></a>

### func getchar() : i32

*public* | *stdlib/std/libc/libc.lita:96*

---

<a id="func-fileno"></a>

### func fileno(stream: \*[FILE](std_libc.md#struct-file)) : i32

*public* | *stdlib/std/libc/libc.lita:97*

---

<a id="func-ftruncate"></a>

### func ftruncate(fd: i32, size: usize) : bool

*public* | *stdlib/std/libc/libc.lita:98*

---

<a id="func-perror"></a>

### func perror(str: \*const char) : void

*public* | *stdlib/std/libc/libc.lita:105*

---

<a id="func-max"></a>

### func MAX\<T\>(a: T, b: T) : T

*public* | *stdlib/std/libc/libc.lita:108*

---

<a id="func-min"></a>

### func MIN\<T\>(a: T, b: T) : T

*public* | *stdlib/std/libc/libc.lita:109*

---

<a id="func-abs"></a>

### func ABS\<T\>(a: T) : T

*public* | *stdlib/std/libc/libc.lita:110*

---

<a id="func-sqrt"></a>

### func sqrt(v: f64) : f64

*public* | *stdlib/std/libc/libc.lita:111*

---

<a id="func-sqrtf"></a>

### func sqrtf(v: f32) : f32

*public* | *stdlib/std/libc/libc.lita:112*

---

<a id="func-cos"></a>

### func cos(v: f64) : f64

*public* | *stdlib/std/libc/libc.lita:113*

---

<a id="func-cosf"></a>

### func cosf(v: f32) : f32

*public* | *stdlib/std/libc/libc.lita:114*

---

<a id="func-sin"></a>

### func sin(v: f64) : f64

*public* | *stdlib/std/libc/libc.lita:115*

---

<a id="func-sinf"></a>

### func sinf(v: f32) : f32

*public* | *stdlib/std/libc/libc.lita:116*

---

<a id="func-asinf"></a>

### func asinf(v: f32) : f32

*public* | *stdlib/std/libc/libc.lita:117*

---

<a id="func-fabs"></a>

### func fabs(v: f32) : f32

*public* | *stdlib/std/libc/libc.lita:118*

---

<a id="func-tan"></a>

### func tan(v: f64) : f64

*public* | *stdlib/std/libc/libc.lita:119*

---

<a id="func-exp2"></a>

### func exp2(v: f64) : f64

*public* | *stdlib/std/libc/libc.lita:120*

---

<a id="func-pow"></a>

### func pow(base: f64, exponent: f64) : f64

*public* | *stdlib/std/libc/libc.lita:121*

---

<a id="func-rand"></a>

### func rand() : i32

*public* | *stdlib/std/libc/libc.lita:125*

---

<a id="func-srand"></a>

### func srand(seed: u32) : void

*public* | *stdlib/std/libc/libc.lita:126*

---

<a id="func-va_start"></a>

### func va_start\<T\>(args: [va_list](std_libc.md#struct-va_list), firstArg: T) : void

*public* | *stdlib/std/libc/libc.lita:130*

---

<a id="func-va_end"></a>

### func va_end(args: [va_list](std_libc.md#struct-va_list)) : void

*public* | *stdlib/std/libc/libc.lita:131*

---

<a id="func-va_copy"></a>

### func va_copy(a: [va_list](std_libc.md#struct-va_list), b: [va_list](std_libc.md#struct-va_list)) : void

*public* | *stdlib/std/libc/libc.lita:132*

---

<a id="func-native_va_arg"></a>

### func native_va_arg\<T\>(a: [va_list](std_libc.md#struct-va_list), type: typeid) : T

*public* | *stdlib/std/libc/libc.lita:133*

---

<a id="func-va_arg"></a>

### func va_arg\<T\>(args: \*[va_list](std_libc.md#struct-va_list)) : T

*public* | *stdlib/std/libc/libc.lita:134*

---

<a id="func-vprintf"></a>

### func vprintf(format: \*const char, ap: [va_list](std_libc.md#struct-va_list)) : i32

*public* | *stdlib/std/libc/libc.lita:137*

---

<a id="func-vfprintf"></a>

### func vfprintf(f: \*[FILE](std_libc.md#struct-file), format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : void

*public* | *stdlib/std/libc/libc.lita:138*

---

<a id="func-vsprintf_s"></a>

### func vsprintf_s(ptr: \*void, len: u64, format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : i32

*public* | *stdlib/std/libc/libc.lita:139*

---

<a id="func-vsnprintf"></a>

### func vsnprintf(buffer: \*char, len: u64, format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : i32

*public* | *stdlib/std/libc/libc.lita:140*

---

<a id="func-vsnprintf_s"></a>

### func vsnprintf_s(ptr: \*void, len: u64, max: u64, format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : i32

*public* | *stdlib/std/libc/libc.lita:141*

---

<a id="func-fputs"></a>

### func fputs(format: \*const char, f: \*[FILE](std_libc.md#struct-file)) : void

*public* | *stdlib/std/libc/libc.lita:142*

---

<a id="func-qsort"></a>

### func qsort\<T\>(ptr: \*void, count: usize, size: usize, comp: func(T, T) : i32) : void

*public* | *stdlib/std/libc/libc.lita:145*

---

<a id="func-exit"></a>

### func exit(code: i32) : void

*public* | *stdlib/std/libc/libc.lita:148*

---

<a id="func-system"></a>

### func system(cmd: \*const char) : i32

*public* | *stdlib/std/libc/libc.lita:149*

---

<a id="func-abort"></a>

### func abort() : void

*public* | *stdlib/std/libc/libc.lita:150*

---

<a id="func-strcat"></a>

### func strcat(dest: \*char, src: \*const char) : \*char

*public* | *stdlib/std/libc/libc.lita:153*

---

<a id="func-strncat"></a>

### func strncat(dest: \*char, src: \*const char, num: usize) : \*char

*public* | *stdlib/std/libc/libc.lita:154*

---

<a id="func-strncpy"></a>

### func strncpy(dest: \*char, src: \*const char, num: usize) : \*char

*public* | *stdlib/std/libc/libc.lita:155*

---

<a id="func-strcpy"></a>

### func strcpy(dest: \*char, src: \*const char) : \*char

*public* | *stdlib/std/libc/libc.lita:156*

---

<a id="func-strlen"></a>

### func strlen(str: \*const char) : i32

*public* | *stdlib/std/libc/libc.lita:157*

---

<a id="func-strnlen"></a>

### func strnlen(str: \*const char, len: usize) : i32

*public* | *stdlib/std/libc/libc.lita:158*

---

<a id="func-strncmp"></a>

### func strncmp(a: \*const char, b: \*const char, num: usize) : i32

*public* | *stdlib/std/libc/libc.lita:159*

---

<a id="func-strcmp"></a>

### func strcmp(a: \*const char, b: \*const char) : i32

*public* | *stdlib/std/libc/libc.lita:160*

---

<a id="func-snprintf"></a>

### func snprintf(s: \*char, n: usize, format: \*const char, ...) : i32

*public* | *stdlib/std/libc/libc.lita:161*

---

<a id="func-sprintf"></a>

### func sprintf(b: \*char, format: \*const char, ...) : i32

*public* | *stdlib/std/libc/libc.lita:162*

---

<a id="func-strtok"></a>

### func strtok(str: \*char, delim: \*const char) : \*char

*public* | *stdlib/std/libc/libc.lita:163*

---

<a id="func-strtol"></a>

### func strtol(str: \*const char, end: \*\*char, base: i32) : i64

*public* | *stdlib/std/libc/libc.lita:164*

---

<a id="func-strtoul"></a>

### func strtoul(str: \*const char, end: \*\*char, base: i32) : u64

*public* | *stdlib/std/libc/libc.lita:165*

---

<a id="func-strtod"></a>

### func strtod(str: \*const char, end: \*\*char) : f64

*public* | *stdlib/std/libc/libc.lita:166*

---

<a id="func-sscanf"></a>

### func sscanf(str: \*const char, format: \*const char, ...) : i32

*public* | *stdlib/std/libc/libc.lita:167*

---

<a id="func-isdigit"></a>

### func isdigit(arg: i32) : i32

*public* | *stdlib/std/libc/libc.lita:168*

---

<a id="func-isxdigit"></a>

### func isxdigit(arg: i32) : i32

*public* | *stdlib/std/libc/libc.lita:169*

---

<a id="func-tolower"></a>

### func tolower(arg: i32) : i32

*public* | *stdlib/std/libc/libc.lita:170*

---

<a id="func-toupper"></a>

### func toupper(arg: i32) : i32

*public* | *stdlib/std/libc/libc.lita:171*

---

<a id="func-isalnum"></a>

### func isalnum(arg: i32) : i32

*public* | *stdlib/std/libc/libc.lita:172*

---

<a id="func-isspace"></a>

### func isspace(arg: i32) : i32

*public* | *stdlib/std/libc/libc.lita:173*

---

<a id="func-isalpha"></a>

### func isalpha(c: char) : i32

*public* | *stdlib/std/libc/libc.lita:174*

---

<a id="func-atoi"></a>

### func atoi(str: \*const char) : i32

*public* | *stdlib/std/libc/libc.lita:175*

---

<a id="func-_vscprintf"></a>

### func _vscprintf(format: \*const char, args: [va_list](std_libc.md#struct-va_list)) : i32

*public* | *stdlib/std/libc/libc.lita:211*

---

## Types

<a id="struct-file"></a>

### struct FILE

*public* | *stdlib/std/libc/libc.lita:76*

---

<a id="struct-va_list"></a>

### struct va_list

*public* | *stdlib/std/libc/libc.lita:129*

---

## Variables and Constants

<a id="const-stderr"></a>

### const stderr: \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/libc/libc.lita:77*

---

<a id="const-stdout"></a>

### const stdout: \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/libc/libc.lita:78*

---

<a id="const-stdin"></a>

### const stdin: \*[FILE](std_libc.md#struct-file)

*public* | *stdlib/std/libc/libc.lita:79*

---

<a id="const-seek_set"></a>

### const SEEK_SET: i32

*public* | *stdlib/std/libc/libc.lita:99*

---

<a id="const-seek_cur"></a>

### const SEEK_CUR: i32

*public* | *stdlib/std/libc/libc.lita:100*

---

<a id="const-seek_end"></a>

### const SEEK_END: i32

*public* | *stdlib/std/libc/libc.lita:101*

---

<a id="var-errno"></a>

### var errno: i32

*public* | *stdlib/std/libc/libc.lita:104*

---

<a id="const-m_pi"></a>

### const M_PI: f64

*public* | *stdlib/std/libc/libc.lita:122*

---

<a id="const-rand_max"></a>

### const RAND_MAX: i64

*public* | *stdlib/std/libc/libc.lita:124*

---

<a id="const-eof"></a>

### const EOF: i32

*public* | *stdlib/std/libc/libc.lita:178*

---

<a id="const-char_bit"></a>

### const CHAR_BIT: i32

*public* | *stdlib/std/libc/libc.lita:179*

---

<a id="const-schar_min"></a>

### const SCHAR_MIN: i32

*public* | *stdlib/std/libc/libc.lita:180*

---

<a id="const-schar_max"></a>

### const SCHAR_MAX: i32

*public* | *stdlib/std/libc/libc.lita:181*

---

<a id="const-char_min"></a>

### const CHAR_MIN: i32

*public* | *stdlib/std/libc/libc.lita:182*

---

<a id="const-char_max"></a>

### const CHAR_MAX: i32

*public* | *stdlib/std/libc/libc.lita:183*

---

<a id="const-shrt_min"></a>

### const SHRT_MIN: i32

*public* | *stdlib/std/libc/libc.lita:184*

---

<a id="const-shrt_max"></a>

### const SHRT_MAX: i32

*public* | *stdlib/std/libc/libc.lita:185*

---

<a id="const-ushrt_max"></a>

### const USHRT_MAX: i32

*public* | *stdlib/std/libc/libc.lita:186*

---

<a id="const-int_min"></a>

### const INT_MIN: i32

*public* | *stdlib/std/libc/libc.lita:187*

---

<a id="const-int_max"></a>

### const INT_MAX: i32

*public* | *stdlib/std/libc/libc.lita:188*

---

<a id="const-uint_max"></a>

### const UINT_MAX: i32

*public* | *stdlib/std/libc/libc.lita:189*

---

<a id="const-long_min"></a>

### const LONG_MIN: i32

*public* | *stdlib/std/libc/libc.lita:190*

---

<a id="const-long_max"></a>

### const LONG_MAX: i32

*public* | *stdlib/std/libc/libc.lita:191*

---

<a id="const-ullong_max"></a>

### const ULLONG_MAX: i64

*public* | *stdlib/std/libc/libc.lita:192*

---

<a id="const-huge_val"></a>

### const HUGE_VAL: f64

*public* | *stdlib/std/libc/libc.lita:193*

---

<a id="const-__file__"></a>

### const __FILE__: \*const char

*public* | *stdlib/std/libc/libc.lita:197*

---

<a id="const-__function__"></a>

### const __FUNCTION__: \*const char

*public* | *stdlib/std/libc/libc.lita:200*

---

<a id="const-__line__"></a>

### const __LINE__: usize

*public* | *stdlib/std/libc/libc.lita:203*

---

