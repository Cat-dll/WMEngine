#ifndef _WM_UTILS_H_
#define _WM_UTILS_H_

#include <stdint.h>

#if __STDC_VERSION__ >= 201112
    #include <stdbool.h>
#endif

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;
typedef bool b32;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !! TODO: ONLY FOR ACTUAL DEVELOPMENT STATE !!
// !! TODO: REMOVE THIS LINE                  !! 
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#undef _UNICODE

#ifdef _UNICODE
    typedef wchar_t* string;
#else
    typedef char* string;
#endif

#define NameOf(x) #x
#define Text(str) L ## str

#define KiloBytes(x) (1024 * x)
#define MegaBytes(x) (KiloBytes(x) * 1024) 
#define GigaBytes(x) (MegaBytes(x) * 1024)
#define TeraBytes(x) (GigaBytes(x) * 1024)

#define ArrayCount(arr) (sizeof(arr) / sizeof(arr[0]))

#endif 