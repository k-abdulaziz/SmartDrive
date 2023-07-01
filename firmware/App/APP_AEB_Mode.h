/**
 * @file MCAL_AEB_Interface.h
 * @brief Header file - AEB (Automatic Emergency Braking) Microcontroller Abstraction Layer Interface.
 */

#ifndef MCAL_AEB_INTERFACE_H_
#define MCAL_AEB_INTERFACE_H_

/**
 * @headerfile STD_TYPES.h
 * @brief Header file - Standard Data Types.
 */
#include "../inc/STD_TYPES.h"

/**
 * @headerfile MCAL_RCC_Interface.h
 * @brief Header file - RCC Driver Interface.
 */
#include "../inc/MCAL_RCC_Interface.h"

/**
 * @headerfile MCAL_RCC_Private.h
 * @brief Header file - RCC Driver Private Definitions.
 */
#include "../inc/MCAL_RCC_Private.h"

/**
 * @headerfile MCAL_RCC_Config.h
 * @brief Header file - RCC Driver Configuration.
 */
#include "../inc/MCAL_RCC_Config.h"

/**
 * @headerfile MCAL_GPIO_Interface.h
 * @brief Header file - GPIO Driver Interface.
 */
#include "../inc/MCAL_GPIO_Interface.h"

/**
 * @headerfile MCAL_GPIO_Config.h
 * @brief Header file - GPIO Driver Configuration.
 */
#include "../inc/MCAL_GPIO_Config.h"

/**
 * @headerfile MCAL_EXTI_Interface.h
 * @brief Header file - EXTI Driver Interface.
 */
#include "../inc/MCAL_EXTI_Interface.h"

/**
 * @headerfile MCAL_STK_Interface.h
 * @brief Header file - STK Driver Interface.
 */
#include "../inc/MCAL_STK_Interface.h"

/**
 * @headerfile MotorDriver_Interface.h
 * @brief Header file - Motor Driver Interface.
 */
#include "../ECUAL/MotorDriver/MotorDriver_Interface.h"

/**
 * @headerfile HCSR04_Interface.h
 * @brief Header file - HCSR04 Ultrasonic Sensor Interface.
 */
#include "../ECUAL/HCSR04/HCSR04_Interface.h"

#define BRAKING_DISTANCE	  5

/**
 * @brief External variable for storing the current distance measured by the HCSR04 sensor.
 */
extern u16 Current_Distance;

/**
 * @brief AEB Braking Interrupt callback function.
 */
void AEB_BrakingCallBack(void);

/**
 * @brief Initialization function for AEB mode.
 */
void APP_AEB_vInit();

/**
 * @brief AEB mode task.
 */
_Noreturn void APP_AEB_vTask();

#endif /* MCAL_AEB_INTERFACE_H_ */