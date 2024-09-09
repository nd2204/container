#ifndef TYPES_H
#define TYPES_H

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef signed char i8;

typedef signed short i16;

typedef signed int i32;

typedef signed long long i64;

typedef float f32;

typedef double f64;

typedef int b32;

typedef char b8;

#if defined(__clang__) || defined(__GNUC__)
/** @brief Static assertion */
#define STATIC_ASSERT _Static_assert
#else

/** @brief Static assertion */
#define STATIC_ASSERT static_assert
#endif

STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");

STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");

STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");

STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");

STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");

STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");

STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");

STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

/** @brief True.*/
#define true 1

/** @brief False. */
#define false 0

#define i64_MAX 9223372036854775807L

#define i64_MIN -9223372036854775808L

#define i32_MAX 2147483647

#define i32_MIN -2147483648

#define i16_MAX 32767

#define i16_MIN -32768

#define i8_MAX 127

#define i8_MIN -128

#define U64_MAX 18446744073709551615U

#define U32_MAX 429467295U

#define U16_MAX 65535U

#define U8_MAX 255

#endif
