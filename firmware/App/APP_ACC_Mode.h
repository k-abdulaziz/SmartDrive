/**
 * @file APP_ACC_Interface.h
 * @brief This file contains the interface of the ACC (Adaptive Cruise Control) application.
 */

#ifndef APP_ACC_INTERFACE_H_
#define APP_ACC_INTERFACE_H_

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
 * @headerfile HCSR04_Interface.h
 * @brief Header file - HCSR04 Interface.
 */
#include "../ECUAL/HCSR04/HCSR04_Interface.h"

/**
 * @headerfile MotorDriver_Interface.h
 * @brief Header file - Motor Driver Interface.
 */
#include "../ECUAL/MotorDriver/MotorDriver_Interface.h"

/**
 * @brief Disable the ACC (Adaptive Cruise Control) feature.
 */
void ACC_Disable(void);

/**
 * @def MAX_SPEED
 * @brief The maximum speed value for the ACC.
 */
#define MAX_SPEED  80

/**
 * @brief ACC Task function.
 */
void APP_ACC_vTask();

#endif /* APP_ACC_INTERFACE_H_ */