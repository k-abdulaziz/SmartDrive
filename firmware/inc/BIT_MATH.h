/**
 * @file bit_math.h
 * @brief Header file for bit manipulation functions.
 *
 * This header file defines a number of functions for manipulating bits in registers.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-22
 * @copyright Copyright (c) 2023 Bard. All rights reserved.
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/**
 * @def LOW_NIBBLE
 * @brief The value of the low nibble (4 least significant bits) of a byte.
 */
#define LOW_NIBBLE        0x0F

/**
 * @def HIGH_NIBBLE
 * @brief The value of the high nibble (4 most significant bits) of a byte.
 */
#define HIGH_NIBBLE       0xF0

/**
 * @enum BitsCount
 * @brief An enumeration of the number of bits.
 */
enum BitsCount {
	/**
	 * @brief One bit.
	 */
	ONE_BIT = 1,
	/**
	 * @brief Two bits.
	 */
	TWO_BITS,
	/**
	 * @brief Three bits.
	 */
	THREE_BITS,
	/**
	 * @brief Four bits.
	 */
	FOUR_BITS,
	/**
	 * @brief Five bits.
	 */
	FIVE_BITS,
	/**
	 * @brief Six bits.
	 */
	SIX_BITS,
	/**
	 * @brief Seven bits.
	 */
	SEVEN_BITS,
	/**
	 * @brief Eight bits.
	 */
	EIGHT_BITS,
	/**
	 * @brief Nine bits.
	 */
	NINE_BITS,
	/**
	 * @brief Ten bits.
	 */
	TEN_BITS,
	/**
	 * @brief Eleven bits.
	 */
	ELEVEN_BITS,
	/**
	 * @brief Twelve bits.
	 */
	TWELVE_BITS,
	/**
	 * @brief Thirteen bits.
	 */
	THIRTEEN_BITS,
	/**
	 * @brief Fourteen bits.
	 */
	FOURTEEN_BITS,
	/**
	 * @brief Fifteen bits.
	 */
	FIFTEEN_BITS,
	/**
	 * @brief Sixteen bits.
	 */
	SIXTEEN_BITS,
	/**
	 * @brief Seventeen bits.
	 */
	SEVENTEEN_BITS,
	/**
	 * @brief Eighteen bits.
	 */
	EIGHTEEN_BITS,
	/**
	 * @brief Nineteen bits.
	 */
	NINETEEN_BITS,
	/**
	 * @brief Twenty bits.
	 */
	TWENTY_BITS,
	/**
	 * @brief Twenty-one bits.
	 */
	TWENTYONE_BITS,
	/**
	 * @brief Twenty-two bits.
	 */
	TWENTYTWO_BITS,
	/**
	 * @brief Twenty-three bits.
	 */
	TWENTYTHREE_BITS,
	/**
	 * @brief Twenty-four bits.
	 */
	TWENTYFOUR_BITS,
	/**
	 * @brief Twenty-five bits.
	 */
	TWENTYFIVE_BITS,
	/**
	 * @brief Twenty-six bits.
	 */
	TWENTYSEVEN_BITS,
	/**
	 * @brief Twenty-eight bits.
	 */
	TWENTYEIGHT_BITS,
	/**
	 * @brief Twenty-nine bits.
	 */
	TWENTYNINE_BITS,
	/**
	 * @brief Thirty bits.
	 */
	THIRTY_BITS,
	/**
	 * @brief Thirty-one bits.
	 */
	THIRTYONE_BITS,
};

/**
 * @enum BitId
 * @brief An enumeration of the bit IDs.
 *
 * The `BitId` enum defines a number of constants that represent the bit IDs.
 *
 * For example, `BIT0` represents the first bit, `BIT1` represents the second bit, and so on.
 *
 * These constants can be used with the `SET_BIT()`, `CLEAR_BIT()`, `TOGGLE_BIT()`, and `GET_BIT()` macros to manipulate bits in registers.
 *
 */
enum BitId {
	BIT0, /**< The first bit. */
	BIT1, /**< The second bit. */
	BIT2, /**< The third bit. */
	BIT3, /**< The fourth bit. */
	BIT4, /**< The fifth bit. */
	BIT5, /**< The sixth bit. */
	BIT6, /**< The seventh bit. */
	BIT7, /**< The eighth bit. */
	BIT8, /**< The ninth bit. */
	BIT9, /**< The tenth bit. */
	BIT10, /**< The eleventh bit. */
	BIT11, /**< The twelfth bit. */
	BIT12, /**< The thirteenth bit. */
	BIT13, /**< The fourteenth bit. */
	BIT14, /**< The fifteenth bit. */
	BIT15, /**< The sixteenth bit. */
	BIT16, /**< The seventeenth bit. */
	BIT17, /**< The eighteenth bit. */
	BIT18, /**< The nineteenth bit. */
	BIT19, /**< The twentieth bit. */
	BIT20, /**< The twenty-first bit. */
	BIT21, /**< The twenty-second bit. */
	BIT22, /**< The twenty-third bit. */
	BIT23, /**< The twenty-fourth bit. */
	BIT24, /**< The twenty-fifth bit. */
	BIT25, /**< The twenty-sixth bit. */
	BIT26, /**< The twenty-seventh bit. */
	BIT27, /**< The twenty-eighth bit. */
	BIT28, /**< The twenty-ninth bit. */
	BIT29, /**< The thirtieth bit. */
	BIT30, /**< The thirty-first bit. */
	BIT31, /**< The thirty-second bit. */
};

/**
 * @def SET_BIT(REG, BIT)
 * @brief Sets the specified bit in the register.
 *
 * @param REG The register to modify.
 * @param BIT The bit to set.
 *
 * @return The modified register.
 */
#define SET_BIT(REG, BIT)                   (REG |= (1<<BIT))

/**
 * @def CLEAR_BIT(REG, BIT)
 * @brief Clears the specified bit in the register.
 *
 * @param REG The register to modify.
 * @param BIT The bit to clear.
 *
 * @return The modified register.
 */
#define CLEAR_BIT(REG, BIT)                 (REG &=~ (1<<BIT))

/**
 * @def TOGGLE_BIT(REG, BIT)
 * @brief Toggles the specified bit in the register.
 *
 * @param REG The register to modify.
 * @param BIT The bit to toggle.
 *
 * @return The modified register.
 */
#define TOGGLE_BIT(REG, BIT)                (REG ^= (1<<BIT))

/**
 * @def GET_BIT(REG, BIT)
 * @brief Gets the value of the specified bit in the register.
 *
 * @param REG The register to read from.
 * @param BIT The bit to read.
 *
 * @return The value of the bit.
 */
#define GET_BIT(REG, BIT)                   ((REG >> BIT) & 1)

/**
 * @def SET_PIN(REG, PIN)
 * @brief Sets the specified pin in the register.
 *
 * @param REG The register to modify.
 * @param PIN The pin to set.
 *
 * @return The modified register.
 */
#define SET_PIN(REG, PIN)                   (REG |= PIN)

/**
 * @def CLEAR_PIN(REG, PIN)
 * @brief Clears the specified pin in the register.
 *
 * @param REG The register to modify.
 * @param PIN The pin to clear.
 *
 * @return The modified register.
 */
#define CLEAR_PIN(REG, PIN)                 (REG &=~ PIN)

/**
 * @def TOGGLE_PIN(REG, PIN)
 * @brief Toggles the specified pin in the register.
 *
 * @param REG The register to modify.
 * @param PIN The pin to toggle.
 *
 * @return The modified register.
 */
#define TOGGLE_PIN(REG, PIN)                (REG ^= PIN)

/**
 * @def SET_CONFIG(REG, CONFIG)
 * @brief Sets the specified configuration bit in the register.
 *
 * @param REG The register to modify.
 * @param CONFIG The configuration bit to set.
 *
 * @return The modified register.
 */
#define SET_CONFIG(REG, CONFIG)             SET_PIN(REG, CONFIG)

/**
 * @def CLEAR_CONFIG(REG, CONFIG)
 * @brief Clears the specified configuration bit in the register.
 *
 * @param REG The register to modify.
 * @param CONFIG The configuration bit to clear.
 *
 * @return The modified register.
 */
#define CLEAR_CONFIG(REG, CONFIG)           (REG &= CONFIG)

/**
 * @def SET_REG(REG)
 * @brief Sets the value of the register to 0xFFFFFFFF.
 *
 * @param REG The register to modify.
 *
 * @return The modified register.
 */
#define SET_REG(REG)                        (REG = ~0x00)

/**
 * @def CLEAR_REG(REG)
 * @brief Sets the value of the register to 0x00000000.
 *
 * @param REG The register to modify.
 *
 * @return The modified register.
 */
#define CLEAR_REG(REG)                      (REG = 0X00)

/**
 * @def WRITE_REG(REG, VALUE)
 * @brief Writes the specified value to the register.
 *
 * @param REG The register to modify.
 * @param VALUE The value to write to the register.
 *
 * @return The modified register.
 */
#define WRITE_REG(REG, VALUE)               (REG = VALUE)

/**
 * @def READ_REG(REG)
 * @brief Reads the value of the register.
 *
 * @param REG The register to read from.
 *
 * @return The value of the register.
 */
#define READ_REG(REG)                       (REG)

/**
 * @def MASK(LEN)
 * @brief Returns a mask of the specified length.
 *
 * @param LEN The length of the mask.
 *
 * @return A mask of the specified length.
 */
#define MASK(LEN)                           (( 1<<(LEN))-1)

/**
 * @def BITS_MASK(START, LEN)
 * @brief Returns a mask of the specified length, starting at the specified bit position.
 *
 * @param START The bit position to start at.
 * @param LEN The length of the mask.
 *
 * @return A mask of the specified length, starting at the specified bit position.
 */
#define BITS_MASK(START, LEN)               (MASK(LEN)<<(START))

/**
 * @def WRITE_BITS(REG, MASK, VALUE)
 * @brief Sets or clears bits in a register, according to a mask and a value.
 *
 * @param REG The register to modify.
 * @param MASK The mask of the bits to modify.
 * @param VALUE The value to set or clear the bits to.
 *
 * @return The modified register.
 */
#define WRITE_BITS(REG, MASK, VALUE)        (REG = ((REG & ~(MASK)) | ((VALUE) & (MASK))))

/**
 * @def READ_BITS(VAR, START, LEN)
 * @brief Reads a number of bits from a variable, starting at the specified bit position.
 *
 * @param VAR The variable to read from.
 * @param START The bit position to start reading from.
 * @param LEN The number of bits to read.
 *
 * @return The value of the bits read.
 */
#define READ_BITS(VAR, START, LEN)          ((VAR & (BITS_MASK(START,LEN)) )>>START)

/**
 * @def ASSIGN_BITS(VAR, START, LEN, VAL)
 * @brief Assigns a number of bits in a variable, starting at the specified bit position, to a specified value.
 *
 * @param VAR The variable to modify.
 * @param START The bit position to start assigning to.
 * @param LEN The number of bits to assign.
 * @param VAL The value to assign the bits to.
 *
 * @return The modified variable.
 */
#define ASSIGN_BITS(VAR, START, LEN, VAL)   (VAR =    (VAR & (~( (BITS_MASK(START,LEN)) ))) | ( ((VAL<<START)&BITS_MASK(START,LEN))))

/**
 * @def ASSIGN_BIT(VAR, START, VAL)
 * @brief Assigns a single bit in a variable to a specified value.
 *
 * @param VAR The variable to modify.
 * @param START The bit position to assign to.
 * @param VAL The value to assign the bit to.
 *
 * @return The modified variable.
 */
#define ASSIGN_BIT(VAR, START, VAL)         ASSIGN_BITS(VAR,START,ONE_BIT,VAL)

/**
 * @def SET_BITFIELD(BITFIELD)
 * @brief Sets a bitfield to 1.
 *
 * @param BITFIELD The bitfield to set.
 *
 * @return The modified bitfield.
 */
#define SET_BITFIELD(BITFIELD)              (BITFIELD = 1)

/**
 * @def CLEAR_BITFIELD(BITFIELD)
 * @brief Clears a bitfield to 0.
 *
 * @param BITFIELD The bitfield to clear.
 *
 * @return The modified bitfield.
 */
#define CLEAR_BITFIELD(BITFIELD)            (BITFIELD = 0)

#endif /* BIT_MATH_H_ */