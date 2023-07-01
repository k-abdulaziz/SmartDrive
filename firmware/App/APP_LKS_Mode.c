/**
 * @file APP_LKS_Mode.c
 * @brief This file contains the implementation of the LKS (Lane Keeping System) mode.
 */

/**
 * @headerfile APP_AEB_Mode.h
 * @brief Header file - AEB Mode.
 */
#include "APP_AEB_Mode.h"

/**
 * @headerfile APP_ADAS_Config.h
 * @brief Header file - ADAS Configuration.
 */
#include "APP_ADAS_Config.h"

/**
 * @headerfile IR_Interface.h
 * @brief Header file - IR Sensor Interface.
 */
#include "../ECUAL/IR_Sensor/IR_Interface.h"

volatile u8 left_IR = 0, right_IR = 0;

/**
 * @brief LKS mode task.
 */
void APP_LKS_vTask() {
	// Read left and right IR sensor values
	left_IR = IR_u8Read_LeftIR();
	right_IR = IR_u8Read_RightIR();

	while (1) {
		/* If the car is inside the lane / No lane markings are detected on both sides */
		if (left_IR == BLACK && right_IR == BLACK) {
			// Move the car forward
			MotorDriver_voidMoveForward();
		}
			/* If the car drifts to the right / Lane markings are detected on the right side */
		else if (left_IR == BLACK && right_IR == WHITE) {
			// Steer the car to the left
			MotorDriver_voidMoveLeft();
		}
			/* If the car drifts to the left / Lane markings are detected on the left side */
		else if (left_IR == WHITE && right_IR == BLACK) {
			// Steer the car to the right
			MotorDriver_voidMoveRight();
		} else {
			// Stop the car
			MotorDriver_voidStop();
		}

		// Check if the LKS mode flag is disabled
		if (!LKS_ModeFlag) {
			break;
		}
	}
}