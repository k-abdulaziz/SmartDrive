/**
 * @file buzzer_interface.c
 * @brief Source file for the buzzer sensor interface.
 */

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "../../inc/STD_TYPES.h"

/**
 * @headerfile "BIT_MATH.h"
 * @brief This header file contains bit manipulation macros.
 */
#include "../../inc/BIT_MATH.h"

/**
 * @headerfile "MCAL_GPIO_Interface.h"
 * @brief This header file contains the GPIO interface functions.
 */
#include "../../inc/MCAL_GPIO_Interface.h"

/**
 * @headerfile "Buzzer_Interface.h"
 * @brief This header file defines the interface for the buzzer sensor.
 */
#include "Buzzer_Interface.h"

/**
 * @headerfile "Buzzer_Config.h"
 * @brief This header file contains the configuration for the buzzer sensor.
 */
#include "Buzzer_Config.h"

/**
 * @brief Initializes the buzzer sensor.
 *
 * This function initializes the buzzer sensor by setting its GPIO pin mode.
 */
void Buzzer_Init() {
	MCL_GPIO_vSetPinMode(BUZZER_CHANNEL, GPIO_MODE_OUT_PP, GPIO_SPEED_MEDIUM);
}

/**
 * @brief Turns the buzzer sensor ON.
 *
 * This function activates the buzzer sensor, causing it to produce sound.
 */
void Buzzer_ON(void) {
	MCL_GPIO_vAtomicSetPin(BUZZER_CHANNEL, PIN_SET);
}

/**
 * @brief Turns the buzzer sensor OFF.
 *
 * This function deactivates the buzzer sensor, stopping it from producing sound.
 */
void Buzzer_Off(void) {
	MCL_GPIO_vAtomicSetPin(BUZZER_CHANNEL, PIN_RESET);
}