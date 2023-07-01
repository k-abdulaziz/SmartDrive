/**
 * @file APP_LDW_Mode.c
 * @brief This file contains the implementation of the LDW (Lane Departure Warning) mode.
 */

/**
 * @headerfile "APP_ADAS_Config.h"
 * @brief Header file - ADAS Configuration.
 */
#include "APP_ADAS_Config.h"

/**
 * @headerfile "APP_LDW_Mode.h"
 * @brief Header file - LDW Mode.
 */
#include "APP_LDW_Mode.h"

/**
 * @brief Initialization function for LDW mode.
 */
void APP_LDW_vInit() {
	Buzzer_Init(); /**< Initialize the buzzer. */
	EXTI_G_Cfg[EXTI1].IRQ_pCallBack = LDW_LeftIRCallBack; /**< Set the callback function for the left IR interrupt. */
	MCL_EXTI_vInit(&EXTI_G_Cfg[EXTI1]); /**< Initialize the left IR interrupt. */
	EXTI_G_Cfg[EXTI2].IRQ_pCallBack = LDW_RightIRCallBack; /**< Set the callback function for the right IR interrupt. */
	MCL_EXTI_vInit(&EXTI_G_Cfg[EXTI2]); /**< Initialize the right IR interrupt. */
}

/**
 * @brief LDW mode task.
 */
_Noreturn void APP_LDW_vTask() {
	while (1) {
		/* Task implementation goes here */
	}
}

/**
 * @brief LDW Left IR Interrupt callback function.
 */
void LDW_LeftIRCallBack(void) {
	if (LDW_ModeFlag) {
		/* Get readings from left and right IRs */
		left_IR = IR_u8Read_LeftIR();
		right_IR = IR_u8Read_RightIR();

		while (right_IR | left_IR) {
			/* If the car is inside the lane / No lane markings are detected on both sides */
			if (left_IR == BLACK && right_IR == BLACK) {
				Buzzer_Off(); /**< Turn off the buzzer. */
			}
				/* If the car drifts to the right / Lane markings are detected on the right side */
			else if (left_IR == BLACK && right_IR == WHITE) {
				Buzzer_ON(); /**< Turn on the buzzer. */
			}
				/* If the car drifts to the left / Lane markings are detected on the left side */
			else if (left_IR == WHITE && right_IR == BLACK) {
				Buzzer_ON(); /**< Turn on the buzzer. */
			} else {
				// Stop the car
				Buzzer_Off(); /**< Turn off the buzzer. */
			}
		}
	}
}

/**
 * @brief LDW Right IR Interrupt callback function.
 */
void LDW_RightIRCallBack(void) {
	if (LDW_ModeFlag) {
		/* Get readings from left and right IRs */
		left_IR = IR_u8Read_LeftIR();
		right_IR = IR_u8Read_RightIR();

		while (right_IR | left_IR) {
			/* If the car is inside the lane / No lane markings are detected on both sides */
			if (left_IR == BLACK && right_IR == BLACK) {
				// Move the car forward
				Buzzer_Off(); /**< Turn off the buzzer. */
			}
				/* If the car drifts to the right / Lane markings are detected on the right side */
			else if (left_IR == BLACK && right_IR == WHITE) {
				Buzzer_ON(); /**< Turn on the buzzer. */
			}
				/* If the car drifts to the left / Lane markings are detected on the left side */
			else if (left_IR == WHITE && right_IR == BLACK) {
				Buzzer_ON(); /**< Turn on the buzzer. */
			} else {
				// Stop the car
				Buzzer_Off(); /**< Turn off the buzzer. */
			}
		}
	}
}