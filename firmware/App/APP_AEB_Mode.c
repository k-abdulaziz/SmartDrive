/**
 * @file APP_AEB_Mode.c
 * @brief This file contains the implementation of the AEB (Automatic Emergency Braking) mode.
 */

/**
 * @headerfile APP_AEB_Mode.h
 * @brief Header file - AEB Mode Application Interface.
 */
#include "APP_AEB_Mode.h"

/**
 * @headerfile MCAL_EXTI_Interface.h
 * @brief Header file - EXTI Driver Interface.
 */
#include "../inc/MCAL_EXTI_Interface.h"

/**
 * @headerfile MotorDriver_Interface.h
 * @brief Header file - Motor Driver Interface.
 */
#include "../ECUAL/MotorDriver/MotorDriver_Interface.h"

/**
 * @brief Initialization function for AEB mode.
 */
void APP_AEB_vInit() {
	MCL_EXTI_vInit(&EXTI_G_Cfg[EXTI3]); /**< Initialize EXTI3 interrupt for AEB mode. */
}

/**
 * @brief AEB mode task.
 */
_Noreturn void APP_AEB_vTask() {
	while (1) {
		if (Current_Distance <= BRAKING_DISTANCE) {
			MCL_GPIO_vAtomicSetPin(GPIOA, GPIO_PIN11, PIN_SET); /**< Activate AEB brake signal. */
			MotorDriver_voidControlSpeed(0); /**< Stop the motor. */
			APP_vDelay_ms(5000); /**< Delay for 5 seconds. */
			MCL_GPIO_vAtomicSetPin(GPIOA, GPIO_PIN11, PIN_RESET); /**< Deactivate AEB brake signal. */
		}
	}
}