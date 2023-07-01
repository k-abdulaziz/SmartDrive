/**
 * @file MotorDriver.c
 * @brief Source file for the motor driver.
 *
 * This file contains the implementation of the motor driver functions.
 *
 * @author Khaled Abdualziz
 * @date 2023-6-20
 */

/**
 * @headerfile STD_TYPES.h
 * @brief Header file that contains the standard data types.
 */
#include "../../inc/STD_TYPES.h"

/**
 * @headerfile BIT_MATH.h
 * @brief Header file that contains bit manipulation macros.
 */
#include "../../inc/BIT_MATH.h"

/**
 * @headerfile MCAL_GPIO_Interface.h
 * @brief Header file that contains the interface for GPIO operations.
 */
#include "../../inc/MCAL_GPIO_Interface.h"

/**
 * @headerfile MCAL_TIM_Interface.h
 * @brief Header file that contains the interface for timer operations.
 */
#include "../../inc/MCAL_TIM_Interface.h"

/**
 * @headerfile MotorDriver_Interface.h
 * @brief Header file that contains the interface for the motor driver.
 */
#include "MotorDriver_Interface.h"

/**
 * @headerfile MotorDriver_Private.h
 * @brief Header file that contains private definitions for the motor driver.
 */
#include "MotorDriver_Private.h"

/**
 * @headerfile MotorDriver_Config.h
 * @brief Header file that contains the configuration for the motor driver.
 */
#include "MotorDriver_Config.h"

void MotorDriver_voidInit(void) {
	// Configure Control Pins for direction control
	MCL_GPIO_vSetPinMode(MOTORDRIVER_PORT, MOTORDRIVER_IN1, GPIO_MODE_OUT_PP, GPIO_SPEED_MEDIUM);
	MCL_GPIO_vSetPinMode(MOTORDRIVER_PORT, MOTORDRIVER_IN2, GPIO_MODE_OUT_PP, GPIO_SPEED_MEDIUM);
	MCL_GPIO_vSetPinMode(MOTORDRIVER_PORT, MOTORDRIVER_IN3, GPIO_MODE_OUT_PP, GPIO_SPEED_MEDIUM);
	MCL_GPIO_vSetPinMode(MOTORDRIVER_PORT, MOTORDRIVER_IN4, GPIO_MODE_OUT_PP, GPIO_SPEED_MEDIUM);

	// Configure PWM channels for speed control
	TIM_PWM_vInit(&PWM_htim31, 1000);
	TIM_PWM_vInit(&PWM_htim32, 1000);
}

void MotorDriver_voidControlSpeed(u8 Cp_DutyCycle) {
	TIM_PWM_SetDutyCycle(&PWM_htim31, Cp_DutyCycle);
	TIM_PWM_SetDutyCycle(&PWM_htim32, Cp_DutyCycle);
}

void MotorDriver_voidControlSpeedRight(u8 Cp_DutyCycle) {
	TIM_PWM_SetDutyCycle(&PWM_htim31, Cp_DutyCycle);
}

void MotorDriver_voidControlSpeedLeft(u8 Cp_DutyCycle) {
	TIM_PWM_SetDutyCycle(&PWM_htim32, Cp_DutyCycle);
}

void MotorDriver_voidMoveForward(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_SET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_SET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_RESET);
}

void MotorDriver_voidMoveBackward(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_SET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_SET);
}

void MotorDriver_voidMoveRight(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_SET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_RESET);
}

void MotorDriver_voidMoveLeft(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_SET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_RESET);
}

void MotorDriver_voidMoveForRight(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_SET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_RESET);
}

void MotorDriver_voidMoveForLeft(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_SET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_RESET);
}

void MotorDriver_voidMoveBackRight(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_SET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_RESET);
}

void MotorDriver_voidMoveBackLeft(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_SET);
}

void MotorDriver_voidStop(void) {
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN1, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN2, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN3, PIN_RESET);
	MCL_GPIO_vAtomicSetPin(MOTORDRIVER_PORT, MOTORDRIVER_IN4, PIN_RESET);
}