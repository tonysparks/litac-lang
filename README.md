# LitaC
LitaC (pronounced Lee-ta-see) is a C like language.  In fact, its main goal is to be C with some minor syntax sugar.  It compiles to ISO-C99 (C11 for some features) which has the benefits of being fairly easy to use existing C libraries and code, and can target any platform with a C99 compiler.

This is the self-hosted compiler implementation -- the original bootstrap implementation can be found [here.](https://github.com/tonysparks/litac).  This implementation is currently heavily in development and lacks features available in the bootstrap version.

# Goals & Purpose
First what's not a goal: LitaC is not meant to replace any existing languages.  It isn't trying to conquer the programming world.

With that disclaimer out of the way, what I'd like LitaC to do:
* A less cumbersome version of C; C is beautiful, but it is showing its age
* Make it easier for me to write video games in a native language
* Find enjoyment in programming

# Syntax
The syntax:

```C
import "libc"

func main(len:i32, args:**char):i32 {
    printf("Hello World")
}
```

# Features
* functions, structures, unions, enums, typedefs
* no headers, no need for forward declarations
* generics for structs, unions and functions
* `using` which allows for flattening field access in structs, unions and function arguments
* default parameters
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

TODO

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

TODO

**Full Examples**
```C
// imports a module, namespace it with adding "as c", otherwise the public attributes
// will be placed in this modules scope
import "libc" as c


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

    var vel: Vec2 = Vec2{1.5, 2.5}

    // call a function
    Vec2Add(pos, vel, pos)

    // function pointer
    var f : func(Vec2, Vec2, Vec2) : Vec2 = &Vec2Add;
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
import "libc"
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
import "libc" // place libc public types in this scope

func main(len:i32, args:**char):i32 {
    if (true) {
        defer printf("there\n") // will execute at the end of this scope
        printf("Hi")
    }
    else {
        printf("Bye")
    }

    var i = 0
    while (i < 10) {
        if i % 2 == 0 {
            break
        }
        else {
            i += 1
            continue
        }
    }

    i = 0
    do {
        if i % 2 == 0 {
            break
        }
        else {
            i += 1
            continue
        }
    }
    while (i < 10)

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
    prinf("not ")

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
    var origin = Vec2<f32> { 0.0, 0.0 }  // using generics syntax
    var vel    = Vec2i { 0,0 }           // using the alias

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

If you include the following command line option to the litaC compiler, this will run all the tests.

```
litac -test ".*" ...
```

If you only want to run a subset of unit tests, you can define a Regular Expression to pick up the test names you want to run.  It is recommended to name your tests with a prefix standard (such as `appName.module.testName`, which would allow you to run full application tests via `appName.*` or module specific tests via `appName.module.*`).


# Building
In order to build litaC compiler you will need:
* A LitaC compiler - either a binary from this repository or the [bootstrap](https://github.com/tonysparks/litac) implementation
* C compiler (I have only tested using Clang v6.0.1)

Once you have those dependencies installed, to build the litaC compiler, simply do:

```
git clone https://github.com/tonysparks/litac-lang.git
cd litac-lang
build.bat
```


# Using LitaC Compiler
Once you have built the `litac` executable (which will be located in the `/bin` folder after `build.bat`), you can verify the build is valid by:

```
litac -help
```

Which will print out the command line help contents.

```
usage> litac [options] [source file to compile]
OPTIONS:
  -languageServer      Start the LitaC language server
  -lib <arg>           The LitaC library path
  -cPrefix <arg>       The symbol prefix to use on the generated C code output
  -run                 Runs the program after a successful compile
  -checkerOnly         Only runs the type checker, does not compile
  -cOnly               Only creates the C output file, does not compile the generated C code
  -profile             Reports profile metrics of the compiler
  -disableLine         Disables #line directive in C output
  -debug               Enables debug mode
  -verbose             Enables verbose output
  -srcDir              Specifies the source code directory, defaults to the parent folder of the supplied source file
  -doc                 Generates document output
  -docDir <arg>        Directory where the generated documents are written to; defaults to './output'
  -docAll              Includes non-public types in the documentation generation; defaults to false
  -o, -output <arg>    The name of the compiled binary
  -outpuDir <arg>      The directory in which the C output files are stored
  -v, -version         Displays the LitaC version
  -h, -help            Displays this help
  -t, -types <arg>     Includes TypeInfo for reflection
                       <arg> can be:
                         all         Means all types will have reflection values
                         tagged      Means only basic types and types annoted with @typeinfo will have reflection values
  -test <arg>          Runs functions annotated with @test.  <arg> is a regex of which tests should be run
  -testFile            Runs functions annotated with @test in the supplied source file only
  -buildCmd            The underlying C compiler build and compile command.  Variables will
                       be substituted if found:
                          %output%         The executable name
                          %input%          The C file(s) generated
```

Here is an example command line options:

```
set LITAC_PATH=C:\Users\antho\eclipse-workspace\litac\lib
litac -run -lib "%LITAC_PATH%" -buildCmd "clang.exe -o %%output%% %%input%% -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -lraylib.lib" -outputDir "./bin" -output "mini" "./src/main.lita"
```

This example, builds an executable named `mini` from the `./src/main.lita` source file.  It will run the executable after it compiles (only if there are no errors).  It uses clang to compile the generated C code, I also set some clang compiler options such as an include directory and static libraries to use in my project.  This also specifies where the litac standard library exists (which is the `lib` folder in the litac project source.

Environment Variable
==


The LitaC compiler will also look at the `LITAC_HOME` environment variable to search for the standard library files if the `-lib` is not set.  When setting the `LITAC_HOME` environment variable, there is no need to set the `-lib` command line option, the `LITAC_HOME` variable should be set to the parent directory of the `lib` folder of the `litac` git project.

Ex.

```
LITAC_HOME=/home/tony/projects/litac
```
