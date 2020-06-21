
// Generated on Sat Jun 20 21:39:37 2020

#include <stdint.h>
#include <stddef.h>
typedef int8_t    i8;
typedef int16_t   i16;
typedef int32_t   i32;
typedef int64_t   i64;
typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;
typedef float     f32;
typedef double    f64;
typedef int8_t    bool;
typedef size_t    usize;
#define true (1)
#define false (0)
#define void void

typedef struct Person;
typedef struct Email;
typedef struct Address;

i32 test__AnotherFunc(i32,char**,test__Address*);

i32 test__AnotherFunc1(i32,char**);

void test__FuncTest(i32,char**);


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// translated code begins
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


struct test__Address {
    const char* street;
    i32 zip;
    const char* city;
    
};

struct test__Email {
    const char* email;
    test__Address address;
    
};

struct test__Person {
    test__Email email;
    
};

i32 test__AnotherFunc(i32 n,char** args,test__Address* a) {
    
}

i32 test__AnotherFunc1(i32 n,char** args) {
    
}

void test__FuncTest(i32 len,char** args) {
    test__Address address = Address {
        .street = "tonysparks",
        54,
        .city = "MKE"
    };
    AnotherFunc(len, args, &address);
    
}


