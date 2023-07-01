/**
 * @file IR_Interface.c
 * @brief Source file for the IR sensor interface.
 *
 * This file contains the implementations of the functions declared in IR_Interface.h.
 *
 * @author Muhammed Al Kahwagy
 * @date 2023-06-20
 */

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "../../inc/STD_TYPES.h"

/**
 * @headerfile "BIT_MATH.h"
 * @brief This header file contains the bit manipulation macros.
 */
#include "../../inc/BIT_MATH.h"

/**
 * @headerfile "MCAL_GPIO_Interface.h"
 * @brief This header file contains the interface for GPIO operations.
 */
#include "../../inc/MCAL_GPIO_Interface.h"

/**
 * @headerfile "MCAL_TIM_Interface.h"
 * @brief This header file contains the interface for timer operations.
 */
#include "../../inc/MCAL_TIM_Interface.h"

/**
 * @headerfile "IR_Config.h"
 * @brief This header file contains the configuration settings for the IR sensor.
 */
#include "IR_Config.h"

/**
 * @headerfile "IR_Interface.h"
 * @brief This header file contains the interface for the IR sensor.
 */
#include "IR_Interface.h"

/**
 * @brief Initializes the IR sensors.
 *
 * This function initializes the IR sensors by setting their GPIO pin modes.
 */
void IR_Init(void) {
	MCL_GPIO_vSetPinMode(IR_PORT, IR_LEFT, GPIO_MODE_IN_PD, GPIO_SPEED_MEDIUM);  // Set the pin mode for the left IR sensor
	MCL_GPIO_vSetPinMode(IR_PORT, IR_RIGHT, GPIO_MODE_IN_PD, GPIO_SPEED_MEDIUM); // Set the pin mode for the right IR sensor
}

/**
 * @brief Reads the value of the right IR sensor.
 *
 * @return The value of the right IR sensor (either HIGH or LOW).
 */
u8 IR_u8Read_RightIR(void) {
	return MCL_GPIO_u8GetPinVal(IR_PORT, IR_RIGHT); // Return the value of the right IR sensor
}

/**
 * @brief Reads the value of the left IR sensor.
 *
 * @return The value of the left IR sensor (either HIGH or LOW).
 */
u8 IR_u8Read_LeftIR(void) {
	return MCL_GPIO_u8GetPinVal(IR_PORT, IR_LEFT); // Return the value of the left IR sensor
}