/**
 * @file std_types.h
 * @brief Standard data types header file.
 *
 * This header file defines a number of standard data types, such as `boolean`, `u8`, `u16`, `u32`, and `f32`.
 *
 * It also defines a number of enumerations, such as `STD_Status` and `Functional_State`.
 *
 * Finally, it defines a number of macros, such as `NULL_PTR` and `APP_vDelay_ms()`.
 *
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

/**
 * @headerfile <stdlib.h>
 */
#include <stdlib.h>

/**
 * @headerfile <stdint.h>
 */
#include <stdint.h>

/**
 * @def WORD_LENGTH_BITS
 * @brief The number of bits in a word.
 */
#define WORD_LENGTH_BITS      32u

/**
 * @def WORD_LENGTH_BYTES
 * @brief The number of bytes in a word.
 */
#define WORD_LENGTH_BYTES     4u

/**
 * @def CPU_BIT_ORDER
 * @brief The bit ordering of the CPU.
 */
#define CPU_BIT_ORDER    LSB_FIRST       ///< The bit ordering of the CPU.

/**
 * @typedef CPU_BYTE_ORDER
 * @brief The byte ordering of the CPU.
 */
#define CPU_BYTE_ORDER   LOW_BYTE_FIRST   ///< The byte ordering of the CPU.

/**
 * @typedef boolean
 * @brief A boolean data type.
 *
 * This data type can have two values: `TRUE` and `FALSE`.
 */
typedef unsigned char boolean;

/**
 * @typedef s8
 * @brief An 8-bit signed integer data type.
 *
 * This data type can store values from -128 to 127.
 */
typedef signed char s8;

/**
 * @typedef u8
 * @brief An 8-bit unsigned integer data type.
 *
 * This data type can store values from 0 to 255.
 */
typedef unsigned char u8;

/**
 * @typedef s16
 * @brief A 16-bit signed integer data type.
 *
 * This data type can store values from -32768 to 32767.
 */
typedef signed short s16;

/**
 * @typedef u16
 * @brief A 16-bit unsigned integer data type.
 *
 * This data type can store values from 0 to 65535.
 */
typedef unsigned short u16;

/**
 * @typedef s32
 * @brief A 32-bit signed integer data type.
 *
 * This data type can store values from -2147483648 to 2147483647.
 */
typedef signed long s32;

/**
 * @typedef u32
 * @brief A 32-bit unsigned integer data type.
 *
 * This data type can store values from 0 to 4294967295.
 */
typedef unsigned long u32;

/**
 * @typedef s64
 * @brief A 64-bit signed integer data type.
 *
 * This data type can store values from -9223372036854775808 to 9223372036854775807.
 */
typedef signed long long s64;

/**
 * @typedef u64
 * @brief A 64-bit unsigned integer data type.
 *
 * This data type can store values from 0 to 18446744073709551615.
 */
typedef unsigned long long u64;

/**
 * @typedef vu16
 * @brief A 16-bit volatile unsigned integer data type.
 *
 * This data type can store values from 0 to 65535.
 */
typedef volatile u16     vu16;

/**
 * @typedef vu32
 * @brief A 32-bit volatile unsigned integer data type.
 *
 * This data type can store values from 0 to 4294967295.
 */
typedef volatile u32     vu32;

/**
 * @typedef f32
 * @brief A floating-point data type with 32 bits.
 */
typedef float f32;

/**
 * @typedef f64
 * @brief A floating-point data type with 64 bits.
 */
typedef double f64;

/**
 * @def NULL_PTR
 * @brief A macro for NULL pointer.
 */
#define NULL_PTR        (void*)0

/**
 * @enum boolean
 * @brief A boolean data type.
 *
 * This data type can have two values: `TRUE` and `FALSE`.
 */
enum boolean {
	FALSE,
	TRUE,
};

/**
 * @enum STD_Status
 * @brief A status enumeration.
 *
 * This enumeration can have two values: `RESET` and `SET`.
 */
enum STD_Status {
	RESET,
	SET,
};

/**
 * @enum Functional_State
 * @brief A functional state enumeration.
 *
 * This enumeration can have two values: `DISABLE_STATE` and `ENABLE_STATE`.
 */
enum Functional_State {
	DISABLE_STATE,
	ENABLE_STATE,
};

/**
 * @brief A function for delaying in milliseconds.
 *
 * @param Copy_32Delay The number of milliseconds to delay.
 */
void APP_vDelay_ms(u32 Copy_32Delay);

/**
 * @brief A function for delaying in microseconds.
 *
 * @param Copy_32Delay The number of microseconds to delay.
 */
void APP_vDelay_us(u32 Copy_32Delay);

#endif  /* STD_TYPES_H */