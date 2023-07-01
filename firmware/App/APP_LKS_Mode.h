/**
 * @file MCAL_LKS_Interface.h
 * @brief This file contains the interface definitions for the LKS (Lane Keeping System) module.
 */

#ifndef MCAL_LKS_INTERFACE_H_
#define MCAL_LKS_INTERFACE_H_

/**
 * @headerfile STD_TYPES.h
 * @brief Header file - Standard Data Types.
 */
#include "../inc/STD_TYPES.h"

/**
 * @headerfile MCAL_RCC_Interface.h
 * @brief Header file - RCC Interface.
 */
#include "../inc/MCAL_RCC_Interface.h"

/**
 * @headerfile MCAL_RCC_Private.h
 * @brief Header file - RCC Private.
 */
#include "../inc/MCAL_RCC_Private.h"

/**
 * @headerfile
 * @brief Header file - RCC Configuration.
 */
#include "../inc/MCAL_RCC_Config.h"

/**
 * @headerfile MCAL_GPIO_Interface.h
 * @brief Header file - GPIO Interface.
 */
#include "../inc/MCAL_GPIO_Interface.h"

/**
 * @headerfile MCAL_GPIO_Config.h
 * @brief Header file - GPIO Configuration.
 */
#include "../inc/MCAL_GPIO_Config.h"

/**
 * @headerfile MCAL_EXTI_Interface.h
 * @brief Header file - EXTI Interface.
 */
#include "../inc/MCAL_EXTI_Interface.h"

/**
 * @headerfile MCAL_STK_Interface.h
 * @brief Header file - STK Interface.
 */
#include "../inc/MCAL_STK_Interface.h"

/**
 * @headerfile MotorDriver_Interface.h
 * @brief Header file - MotorDriver Interface.
 */
#include "../ECUAL/MotorDriver/MotorDriver_Interface.h"

/**
 * @headerfile HCSR04_Interface.h
 * @brief Header file - HCSR04 Interface.
 */
#include "../ECUAL/HCSR04/HCSR04_Interface.h"

/**
 * @headerfile IR_Interface.h
 * @brief Header file - IR Interface.
 */
#include "../ECUAL/IR_Sensor/IR_Interface.h"

/**
 * @def BRAKING_DISTANCE
 * @brief Braking distance threshold in centimeters.
 */
#define BRAKING_DISTANCE	  5 /**< Braking distance threshold in centimeters. */

/**
 * @brief Global variable to store the current distance measurement.
 */
extern u16 Current_Distance; /**< Global variable to store the current distance measurement. */

/**
 * @brief Braking callback function for the LKS module.
 */
void LKS_BrakingCallBack(void);

/**
 * @brief Initialization function for the LKS module.
 */
void APP_LKS_vInit();

/**
 * @brief LKS module task.
 */
void APP_LKS_vTask();

#endif /* MCAL_LKS_INTERFACE_H_ */