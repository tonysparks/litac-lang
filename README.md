
<p align="center">
<img src="./extras/assets/litac_logo.png" width="256" height="256">
</p>

![Build CI](https://github.com/tonysparks/litac-lang/actions/workflows/main.yml/badge.svg)


LitaC (pronounced Lee-ta-see) is a C like language.  In fact, its main goal is to be C with some minor syntax sugar.  It compiles to ISO-C99 (C11 for some features) which has the benefits of being fairly easy to use existing C libraries and code, and can target any platform with a C99 compiler.

This is the self-hosted compiler implementation -- the original bootstrap implementation can be found [here.](https://github.com/tonysparks/litac).  This implementation is currently heavily in development and the bootstrap version is no longer supported and lacks current features.

# Goals & Purpose
First what's not a goal: LitaC is not meant to replace any existing languages.  It isn't trying to conquer the programming world.

With that disclaimer out of the way, what I'd like LitaC to do:
* A less cumbersome version of C; C is beautiful, but it is showing its age
* Make it easier for me to write video games in a native language
* Find enjoyment in programming

# Syntax
The syntax:

```C
import "std/libc"

func main(len:i32, args:**char):i32 {
    printf("Hello World")
}
```

# Features
* functions, structures, unions, enums, typedefs
* no headers, no need for forward declarations
* generics for structs, unions, traits and functions
* traits, with implicit implementations (like Go)
* `using` which allows for flattening field access in structs, unions and function arguments
* default parameters
* named argument parameters
* type inference
* generic type inference
* struct/union "methods"
* `defer` statement
* reflection (i.e., introspection of types) - WIP
* inline tests (enabled/run thru compiler command line argument) - WIP
* multi-line strings
* annotation notes for declarations, modules
* scripting the compiler (allows for reading declarations and emitting new declarations at different compilation stages) - WIP


# Types

**Primitive Types**
| Name | C Equivalent | Description |
|------|--------------|-------------|
| bool | int8_t       | boolean value, true or false (1 or 0) |
| u8   | uint8_t      | unsigned 8-bit integer |
| i8   | int8_t       | signed 8-bit integer |
| u16  | uint16_t     | unsigned 16-bit integer |
| i16  | int16_t      | signed 16-bit integer |
| u32  | uint32_t     | unsigned 32-bit integer |
| i32  | int32_t      | signed 32-bit integer |
| u64  | uint64_t     | unsigned 64-bit integer |
| i64  | int64_t      | signed 64-bit integer |
| f32  | float        | 32-bit floating point |
| f64  | double       | 64-bit floating point |
| usize| size_t       | unsigned pointer sized integer |
| void | void         | absence of a type |

**Pointers**

Pointers are defined slightly different than C:
```C
// in C this is char* str = (char[3]){'h','i','\0'}, a mutable pointer to mutable values
var str: *char = []char {'h', 'i', '\0'};

// in C this is const char* str2, a mutable pointer to an immutable value
var str2: *const char = "Hi";

// in C this is const char* const str3, an immutable pointer to an immutable value
var str3: const* const char = "Hi";
```
*NOTE: Currently, the LitaC compiler does not validate modifications to memory are valid (i.e., `const` in the context of `var s: *const char` is currently only for documentation purposes)*

**Arrays**

TODO documentation - array's are currently identical behavior as C

**String**

As of right now, strings still are null terminating and have all of the negative characteristics as normal C strings.  There is one syntactical advantage in LitaC -- verbatim (aka multi-line) strings.

```C
var myString = """
  "this" is a string
    that expands
  multiple lines
"""

printf("'%s'", myString) // will print out:
/*
'
"this" is a string
  that expands
multiple lines
'
*/
```

*TODO: Unicode support*

**Structures**

Definition
```C
struct Person {
    age: i32
    name: *const char
}
```

Initialization
```C
var brett: Person = Person {
    .age = 44,  // using .age field initializer
    .name = "Brett Favre"
}

printf("%s is %d old\n", brett.name, brett.age);

// using type inference
var donald = Person {
    41,             // using position initializer
    "Donald Driver"
}

printf("%s is %d old\n", donald.name, donald.age);
```

**Unions**

Unions behave exactly like in C; where members share the same memory space.

```C
union Value {
    strValue: *const char
    intValue: i64
    floatValue: f64
}

var val = Value {
    .intValue = 31
}
```

**Traits**

Traits allow for indirection of implementations.  Much like `Go`, in LitaC you define a trait
and a type is said to implement a trait if it implements all of the trait methods.

```C
// Create a graphics renderer trait, in which will allow a codebase to switch
// between implementations
trait Renderer {
    drawImage: func(*Image, f32, f32) : void
    drawRect: func(f32, f32, f32, f32) : void
}

struct OpenGLRenderer {
    // ...
}

func (this: *OpenGLRenderer) drawImage(image: *Image, x: f32, y: f32) : void {
    // ...
    printf("Drawing an OpenGL image\n")
}

func (this: *OpenGLRenderer) drawRect(x: f32, y: f32, width: f32, height: f32) : void {
    // ...
    printf("Drawing an OpenGL rectangle\n")
}


struct DX12Renderer {
    // ...
}

func (this: *DX12Renderer) drawImage(image: *Image, x: f32, y: f32) : void {
    // ...
    printf("Drawing a DirectX image\n")
}

func (this: *DX12Renderer) drawRect(x: f32, y: f32, width: f32, height: f32) : void {
    // ...
    printf("Drawing a DirectX rectangle\n")
}


func Draw(renderer: Renderer) {
    var image: *Image = ...
    renderer.drawImage(image, 24, 24)
    renderer.drawRect(2, 16, 32, 32)
}

func main(len: i32, args: **char) : i32 {
    // both OpenGLRenderer and DX12Renderer implement the Renderer trait because
    // it implements the trait methods
    var openGL = OpenGLRenderer {}
    var dx = DX12Renderer{}

    var useOpenGL: bool = ...

    // determine which trait implementation to use
    // at runtime.
    var renderer: Renderer;

    if(useOpenGL) {
        // notice we are taking the address of the openGL, we can only assign pointers to
        // trait types, and trait types themselves must be values
        renderer = &openGL
    }
    else {
        renderer = &dx
    }

    Draw(renderer)
}
```

**Trait Assignment**

Traits are special types in `LitaC` in that assignment to them behave slightly differently than other types.

```C
var renderer: Renderer = &openGL; // only pointers of implementation types are allowed to be assigned
var otherRenderer: *Renderer = &renderer; // only a pointer to trait can be assigned by addressing a trait type

// these are invalid assignments:
var renderer: Renderer = openGL; // INVALID: because openGL is a value and not a pointer
var renderer: *Renderer = openGL; // INVALID: because assigning to a trait pointer can only be done thru addressing a trait type
var renderer: *Renderer = otherRenderer; // INVALID: because assigning to a trait pointer can only be done thru addressing a trait type
```

**Trait Implementation**

When `traits` get compiled to `C` they use a [virtual table](https://en.wikipedia.org/wiki/Virtual_method_table) to store pointers to the actual implementation function.  There is a performance cost to using the dynamic nature of `traits`.

Rough `C` code translation:

```C
//LitaC:
trait List {
    fn: func() : i32
}

struct LinkedList {
    // ...
}

func (this: *LinkedList) fn() : i32 {
    // ...
}

//C:
// the trait itself becomes this structure
struct List {
    ListVirtualTable* vtable; // the virtual table containing the function pointers
    void* this;               // a pointer to the concrete implementation type
}

// generated Virtual table
struct ListVirtualTable {
    i32 (*fn)(void*);  // the function pointer, with void* this as the first parameter
}

// Wrapper function that basically just casts the void* to the concrete type and calls the
// concrete function
i32 LinkedList_fn_wrapper(void* this) {
    LinkedList* _this = (LinkedList*)this;
    return LinkedList_fn(_this); // calls the actual LinkedList.fn function
}

// global of all implementations mapping to their concrete functions for each type
static ListVirtualTable** ListVtables = {
    [0] = &(ListVirtualTable) {
        .fn = LinkedList_fn_wrapper
    },
    ...
}

// Create a casting function that converts the concrete type to the trait type.  In doing so, we must
// ensure the proper vtable implementation functions are populated
List LinkedList_to_List(LinkedList* list) {
    return List {
        .vtable = ListVtables[0], // uses the global virtual table, matches the index to the proper implementation
        .this = list              // sets the this pointer to the concrete type
    }
}

// Calling a trait method:
//////////////////////////////

//LitaC:
    list.fn()
//C:
    list->vtable->fn(list->this)   // we must convert the trait call to call the vtable and also pass in the 'this' pointer


// Assignment
//////////////////////////////

//LitaC:
    var ll = LinkedList {...}
    var list: List = &ll
//C:
    LinkedList ll {...}
    List list = LinkedList_to_List(&ll)   // Cast the LinkedList to List type
```

**Full Examples**
```C
// imports a module, namespace it with adding "as c", otherwise the public attributes
// will be placed in this modules scope
import "std/libc" as c


// Defines a structure
struct Vec2 {
    x: f32
    y: f32
}

// Defines a function
func Vec2Add(a:Vec2, b:Vec2, out:Vec2) : Vec2 {
    out.x = a.x + b.x
    out.y = a.y + b.y
    return out
}

// structure with union
struct X {
    union V {
        x: i32
        f: f32
    }
}

func main(len:i32, args:**char):i32 {
    // the c:: namespaces the function
    c::printf("Just because you are paranoid, don't mean their not after you\n")

    // numbers
    var b : bool = true // Boolean type, is an int8_t in C, 0 = false, 1 = true
    var i : i8 = 1_i8   // 8-bit integer, is an int8_t in C
    var j : i16 = 1_i16 // 16-bit integer, is an int16_t in C
    // ..i32, i64,
    var k : u16 = 1_u16 // 16-bit unsigned integer, is an uint16_t in C
    // ..u32, u64,
    var f : f32 = 0.5_f32 // 32-bit float
    var d : f64 = 0.5_f64 // 64-bit float
    var u = 0.5 // 64-bit float


    // types can be inferred:
    var age = 32   // age is a i32
    var n   = 32_i64   // is a i64

    // String and Arrays
    var s   = "Hello"  // a char* null terminated string. TODO, make strings include length
    var a   = [2]i32   // an array of i32 of size 2
    var a2  = []i32 { 1, 2, 3 }

    var index = a2[0] // '1'

    // initialize a structure on the stack, can optionally use initializer syntax
    var pos = Vec2 { .x: 0_f32,
                     .y: 0_f32 }

    var vel: Vec2 = Vec2{1.5f, 2.5f}

    // call a function
    Vec2Add(pos, vel, pos)

    // function pointer
    var fn : func(Vec2, Vec2, Vec2) : Vec2 = &Vec2Add;
    // or simply:
    var myAdd = &Vec2Add;

    // initialize the structure with union
    var x = X { V { 34 } }
}
```

# Modules

A module is a container for code, which can contain definitions for functions, structures, etc.  A module may be imported by other modules - importing a module allows the `public` functions and types defined in the imported module be available for use in the current module.  Any function or type not defined with `public` will be private to the module and not be visible to other modules.

Importing a module does not simply "copy" the code - but rather gives the type checker visibility to the imported module types.



Module's are confined to a single file.  If you define a file `packers.lita` you can import the module from another module by:
```C
import "packers"
```

You can compose modules from multiple other module files by extending them via `using` imports.  The `using` import will import the module into the scope of the current module, but the key difference is it will treat the imported module as if its part of the current module's definitions.

Let's look at an example.

Given these files:
```
/packers.lita
/brett.lita
/donald.lita
/main.lita
```

**packers.lita**
```C
// import the public members of brett and donald modules
import using "brett"
import using "donald"

public func getTeamName() :*const char {
    return "Green Bay Packers"
}
```


**brett.lita**
```C
public func getBestQB() : *const char {
    return "Brett Favre"
}

// this function will not be visible outside of the 'brett' module
func getNumberOfInterceptions() : i32 {
    return 0 // :|
}

```
**donald.lita**
```C
public func getBestWR() : *const char {
    return "Donald Driver"
}
```
**main.lita**
```C
import "std/libc"
import "packers" // we only need to include the 'packers' module and we will have full visibility to 'donald' and 'brett' modules

func main(n:i32, args:**char) {
    printf("%s\n", getBestQB())   // "Brett Favre"
    printf("%s\n", getBestWR())   // "Donald Driver"
    printf("%s\n", getTeamName()) // "Green Bay Packers"

    // would error, as 'getNumberOfInterceptions' is private to the 'brett' module
    // printf("%d\n", getNumberOfInterceptions())
}
```

# Control Statements


```C
import "std/libc" // place libc public types in this scope

func main(len:i32, args:**char):i32 {
    if (true) {
        defer printf(" there\n") // will execute at the end of this scope
        printf("Hi")
    }
    else {
        printf("Bye")
    }

    var i = 0
    while (i < 10) {
        if ((i % 2) == 0) {
            break
        }
        else {
            i += 1
            continue
        }
    }

    i = 0
    do {
        if ((i % 2) == 0) {
            break
        }
        else {
            i += 1
            continue
        }
    }
    while (i < 10);

    for(var j = 0; j < 10; j+=1) {
       printf("%d\n", j)
    }

    var x = 2
    switch(x) {
      case 0: printf("it's 0\n")
         break;
      case 1: printf("it's 1\n")
         break;
      default:
         printf("I give up!\n")

    }

    printf("The Packers are ")
    goto end;  // jump over this lie
    printf("not ")

end:
    printf("the best\n");
}
```


# Generics

```C
// Defines a generic structure
struct Vec2<T> {
    x: T
    y: T
}

// Defines a generic function
func Vec2Add<T>(a: Vec2<T>, b: Vec2<T>, out: Vec2<T>) : Vec2<T> {
    out.x = a.x + b.x
    out.y = a.y + b.y
    return out
}

// You alias this type
typedef Vec2<i32> as Vec2i


func main(len:i32, args:**char):i32 {
    //
    var origin = Vec2<f32> { 0.0f, 0.0f }  // using generics syntax
    var vel    = Vec2i { 0,0 }             // using the alias

    Vec2Add<i32>(vel, vel, vel)
    Vec2Add<f32>(origin, origin, origin)

    // generic types can also be infered:
    Vec2Add(vel, vel, vel) // infered as <i32>
}

```


# Methods
There is syntax to allow functions to masquerad around like methods.

```C
struct Vec2 {
    x: f32
    y: f32
}

// as a matter of convention, "methods" should be camelCase and freeform
// functions should be UpperCamelCase
func (v: Vec2) add(other: Vec2) : Vec2 {
    return Vec2 { v.x + other.x, v.y + other.y }
}

func main(len:i32, args:**char) : i32 {
    var origin = Vec2{0,0}

    // method syntax sugar
    origin.add(Vec2{3,4})
}

```

# Functions
Functions can define default parameters and function calls can include named arguments.

```C
// Non default parameters can't be defined after a default parameter,
// e.g.  func Test(a: i32 = 1, b: i32) { // INVALID because b: i32 which doesn't have a default parameter is defined after a: i32 = 1.
func Test(a: i32, b: i32 = 2) {
    // do stuff
}

Test(a) // will evaluate to Test(a, 2)
Test(.a = 1) // will evaluate to Test(1, 2)
Test(.b = 3, .a = 2) // will evaluate to Test(2, 3)
Test(.b = 1)  // INVALID, because no default parameter for 'a'
Test(.b = 1, 1)  // INVALID, because fixed parameters can't come after named parameters
```

# Tests
Write tests right along side your application code.  When compiling for library/executable, the test code will not be included in the
final binary.

```C
func Add(a: i32, b: i32) : i32 {
    return a + b
}

// This annotation denotes a test.
@test("test.Add My first test")
func testAdd() {
    assert(Add(4, 8) == 12)
}

@test("test.Add My second test")
func testAdd2() {
    assert(Add(4, -8) == -4)
}

```

Run tests with the `litac test` command. It recursively scans for `*_test.lita` files under `./test` and runs each one:

```
litac test
```

To run a single test file:

```
litac test -file ./test/mymodule_test.lita
```

To filter by regex:

```
litac test -regex "testAdd.*"
```


# Building
In order to build litaC compiler you will need:
* C compiler (tcc, clang and gcc should work -- I haven't tested Visual Studio's compiler)

_NOTE_: Currently, only tested and buildable for Windows x64, Linux (Ubuntu, Fedora 38) and MacOS

Admittedly, this process isn't as friendly right now as it should be.  At some point I will write more robust build scripts (also LitaC compiler is lacking some features to enable this).  For now, `clang` is hardcoded in the scripts - but should be easy enough to switch to another compiler (tcc or gcc).

### Configure the compiler

The file `src/config.lita` has some parameters to configure the compiler,
it is documented and should be easy to grasp.

### Build

Windows
```
git clone https://github.com/tonysparks/litac-lang.git
cd litac-lang
build_bootstrap.bat
build.bat
```

Linux/Mac
```
git clone https://github.com/tonysparks/litac-lang.git
cd litac-lang
build_bootstrap.sh
build.sh
```

The `build_bootstrap.bat` will compile the `bootstrap/litac.c` file creating a `litac.exe` (`litac` on Ubuntu).  The `build.bat` file will use the `bootstrap/litac.exe` to build the compiler from lita source (`src/`) and output a new binary in `bin/litac.exe`.

_NOTE_: For MacOS, `tcc` is a bit finicky to install, ideally `brew install tcc` would just work.  However, this doesn't appear to work on latest versions of MacOS.  As a work around, you can build tcc from (alternative) source:

```
git clone https://github.com/Alex2804/libtcc-cmake
cd libtcc-cmake
mkdir build
cd build
cmake ..
make
cd ../..
cp libtcc-cmake/build/libtcc.a lib/libtcc.a
```

# Using LitaC Compiler
Once you have built the `litac` executable (which will be located in the `/bin` folder after `build.bat`), you can verify the build is valid by:

```
litac -help
```

The CLI uses a **command-based** structure:

```
usage> litac [command] [options]
```

## Commands

### `build` — Compile a LitaC project

```
litac build [source file] [options]
```

The behaviour differs depending on whether a `pkg.json` exists in the current directory.

#### Without `pkg.json` — direct compilation

Supply a source file and all options on the command line. The compiler is invoked directly with no project configuration:

```
litac build ./src/main.lita -output "mini" -outputDir "./bin" \
  -buildCmd "clang -o %output% %input% -I../include -L../lib -lraylib"
```

If no source file and no `pkg.json` are found, the build fails with an error directing you to either supply a `.lita` file or create a `pkg.json` via `litac init`.

#### With `pkg.json` — package build

When a `pkg.json` is present, `litac build` reads the `build_command` section from it. All options defined there act as defaults; any flags passed on the command line take precedence.

The `build_command` section supports per-target, per-OS and per-architecture configuration:

```json
{
  "name": "myapp",
  "build_command": {
    "debug": {
      "linux": {
        "x64": {
          "cc": "clang",
          "cc_options": "-g -O0 -D_CRT_SECURE_NO_WARNINGS -L./lib -lm",
          "lita_options": ["-debug"]
        },
        "default": {
          "cc": "clang",
          "cc_options": "-g -O0"
        }
      },
      "windows": {
        "default": {
          "cc": "clang",
          "cc_options": "-g -O0 -D_CRT_SECURE_NO_WARNINGS"
        }
      },
      "default": {
        "default": {
          "cc": "clang",
          "cc_options": "-g -O0"
        }
      }
    },
    "release": {
      "default": {
        "default": {
          "cc": "clang",
          "cc_options": "-O2"
        }
      }
    }
  }
}
```

Resolution order (most specific wins, falls back to `default` at each level):
1. **Target**: `debug` (default) or `release` (when `-release` is passed)
2. **OS**: `linux`, `mac`, `windows`, or `default`
3. **Arch**: `x64`, `x86`, `arm64`, `arm32`, or `default`

Each leaf section may contain:

| Field | Description |
|-------|-------------|
| `cc` | C compiler executable (default: `clang`) |
| `cc_options` | Flags passed to the C compiler. Can be a string or array of strings |
| `lita_options` | Extra LitaC compiler flags. Can be a string or array of strings |
| `script` | Shell script to run instead of the standard build pipeline |

When using `pkg.json`, the following defaults are applied automatically unless overridden:

| Setting | Default |
|---------|---------|
| `-outputDir` | `./bin/` |
| `-output` | value of `name` in `pkg.json` |
| `-srcDir` | `./src/` |
| Main entry point | `./src/main.lita` |

**Pre/post build steps** can be defined in `pkg.json` as `pre_build_command` and `post_build_command`, using the same structure as `build_command`. They are only run when `-prebuild` / `-postbuild` flags are passed, and use `./src/pre_main.lita` / `./src/post_main.lita` as their entry points respectively.

#### Build options

| Option | Short | Description |
|--------|-------|-------------|
| `-run` | | Runs the program after a successful compile |
| `-lib <arg>` | | The LitaC library path |
| `-output <arg>` | `-o` | The name of the compiled binary |
| `-outputDir <arg>` | | The directory in which the C output files are stored |
| `-srcDir <arg>` | | Specifies the source code directory (defaults to parent folder of source file) |
| `-buildCmd <arg>` | `-b` | The underlying C compiler command. Substitution variables: `%output%` (executable name), `%input%` (generated C files), `%options%` (`@compiler_option` flags when `-strict` is set) |
| `-strict` | | Prevents the compiler from modifying `buildCmd`; stores generated `@compiler_option` flags in `%options%` instead |
| `-tcc` | | Use tcc to compile (ignores `-buildCmd`) |
| `-types <arg>` | `-t` | Include TypeInfo for reflection. `all` = all types, `tagged` = only types annotated with `@typeinfo` |
| `-debug` | | Enables debug mode |
| `-release` | | Selects the `release` build target in `pkg.json`; marks the build as a release build |
| `-checkerOnly` | | Only runs the type checker, does not compile |
| `-cOnly` | | Only generates the C output file, does not compile it |
| `-cFormat` | | Formats the C output |
| `-cPrefix <arg>` | | Symbol prefix to use in generated C code (default: `litaC_`) |
| `-profile` | | Reports profile metrics of the compiler |
| `-instrument` | | Enables profiling instrumentation for `@profile`-annotated functions |
| `-disableLine` | | Disables `#line` directives in C output |
| `-prebuild` | | Enables the prebuild step (runs `pre_build_command` from `pkg.json`) |
| `-postbuild` | | Enables the postbuild step (runs `post_build_command` from `pkg.json`) |

---

### `test` — Run tests

Recursively scans for `*_test.lita` files and runs each one. Optionally pass a directory to scan (default: current directory).

```
litac test [options]
```

| Option | Description |
|--------|-------------|
| `-file <arg>` | Run `@test`-annotated functions in a single source file only |
| `-package <arg>` | Run `@test`-annotated functions in a single package only |
| `-regex <arg>` | Filter tests by regex (can be combined with `-file` or `-package`) |
| `-testDir <arg>` | Specifies the test source directory (default: `./test`) |

The `test` command also accepts all `build` options (`-lib`, `-buildCmd`, `-debug`, `-release`, `-output`, `-outputDir`, `-types`, `-profile`, `-disableLine`, `-instrument`, `-srcDir`, `-tcc`, `-strict`, `-prebuild`, `-postbuild`).

Examples:

```
# run all tests discovered - anything ending in '_test.lita'
litac test

# run a single test file
litac test -file ./test/stdlib/std/time_test.lita

# run tests discovered in a specific folder
litac test -package "./tests/integratiion"

# run tests only matching the supplied regular expression - this
# can be used with -file and -package options
litac test -regex "testDate.*"

# Use the '-testDir' option to specify an additional
# search path to include to search for tests
litac test -testDir ./tests/integration
```

---

### `install` — Install packages

Scans for a `pkg.json` file and downloads/installs all packages listed in the `dependencies` section. Creates a `.build.json` used for subsequent builds.

```
litac install [options]
```

| Option | Description |
|--------|-------------|
| `-force` | Forces a full clean reinstall of all packages |

---

### `init <name>` — Initialise a new project

Creates a new LitaC project scaffold in the current directory.

```
litac init <project-name>
```

Creates:
```
.vscode/tasks.json
bin/
doc/
lib/
src/main.lita
test/main_test.lita
pkg.json
```

---

### `command <name>` — Run a pkg.json script

Runs a script defined in the `commands` section of `pkg.json`.

```
litac command <script-name>
```

---

### `doc` — Generate documentation

Generates documentation output. *(Not yet fully implemented.)*

```
litac doc [options]
```

| Option | Description |
|--------|-------------|
| `-docDir <arg>` | Output directory for generated docs (default: `./output`) |
| `-all` | Include non-public types in the generated documentation |

---

### `lsp` — Language server

Starts the LitaC language server (for IDE integrations).

```
litac lsp
```

---

## Global Options

These options apply to all commands:

| Option | Short | Description |
|--------|-------|-------------|
| `-version` | `-v` | Displays the LitaC version |
| `-help` | `-h` | Displays help |
| `-verbose` | | Enables verbose output |
| `-colors` | | Disables console colour output |
| `-proxy <arg>` | | Proxy server for network calls. Ex: `-proxy https://proxy.com:443` |
| `-maxMemory <arg>` | | Max memory for allocation (e.g. `300MB`, `1GB`). Temporary option |
| `--` | | Any arguments after `--` are forwarded to the compiled program when `-run` is used |

---

## Environment Variable

The LitaC compiler looks for the `LITAC_HOME` environment variable to locate the standard library when `-lib` is not set. Set it to the parent directory of the `stdlib` folder in the litac repo.

```
LITAC_HOME=/home/tony/projects/litac-lang
```

# LitaC Package Manager

A LitaC `package` is a bundle of LitaC modules and any other dependencies (such as DLLs, static libraries or C header files).

Packages are managed via the `litac install` and `litac init` commands. Only packages hosted on `github.com` are currently supported. Packages are defined by creating a `pkg.json` file in your project folder.

Example project structure:

```
bin/
lib/
src/
pkg.json
```

Here is an example `pkg.json` for using a third-party [test-pkg](https://github.com/tonysparks/test-pkg) package:

```
{
    "repo" : "https://github.com/tonysparks",
    "name" : "litac-lang",
    "version" : "0.1.2-alpha",
    "type": "executable",

    // here is where you define any packages you want to be used
    "dependencies": [
        {
            "repo" : "https://github.com/tonysparks",
            "name" : "test-pkg",
            "version" : "1.0",
        }
    ]
}
```

If you execute the command `litac install` this will download any defined packages in the `dependencies` section of your `pkg.json` and extract them to the `.pkgs/` directory.  It will also create a `.build.json` file which will be used by the `litac` compiler to resolve package module files.

After executing `litac install`:
```
.pkgs/
bin/
lib/
src/
pkg.json
.build.json
```

From your code, you can just `import` the package modules as if they were local.

```C
import "test"  // the 'test' module is defined in the 'test-pkg:1.0' third-party package

func doStuff() {
    Test(4)  // call functions/types defined the 'test' module
}
```
