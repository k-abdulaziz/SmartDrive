/**
 * @file MCAL_LDW_Interface.h
 * @brief Header file - LDW (Lane Departure Warning) Microcontroller Abstraction Layer Interface.
 */

#ifndef MCAL_LDW_INTERFACE_H_
#define MCAL_LDW_INTERFACE_H_

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
 * @headerfile IR_Interface.h
 * @brief Header file - IR Sensor Interface.
 */
#include "../ECUAL/IR_Sensor/IR_Interface.h"

/**
 * @headerfile Buzzer_Interface.h
 * @brief Header file - Buzzer Interface.
 */
#include "../ECUAL/Buzzer/Buzzer_Interface.h"

/**
 * @brief LDW Left IR Interrupt callback function.
 */
void LDW_LeftIRCallBack(void);

/**
 * @brief LDW Right IR Interrupt callback function.
 */
void LDW_RightIRCallBack(void);

/**
 * @brief Initialization function for LDW mode.
 */
void APP_LDW_vInit();

/**
 * @brief LDW mode task.
 */
_Noreturn void APP_LDW_vTask();

#endif /* MCAL_LDW_INTERFACE_H_ */