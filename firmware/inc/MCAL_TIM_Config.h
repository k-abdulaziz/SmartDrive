/**
 * @file MCAL_TIM_CONFIG_H_
 * @brief This file contains the configuration of the MCAL_TIM driver.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_TIM_CONFIG_H_
#define MCAL_TIM_CONFIG_H_

/**
 * @headerfile "MCAL_TIM_Interface.h"
 * @brief Include the header file for the TIM interface.
 */
#include "MCAL_TIM_Interface.h"

/**
 * @headerfile "MCAL_RCC_Interface.h"
 * @brief Include the header file for the RCC interface.
 */
#include "MCAL_RCC_Interface.h"

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief Include the header file for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @def HCSR04_TIMEOUT
 * @brief Timeout value for the Ultrasonic sensor in microseconds.
 */
#define HCSR04_TIMEOUT          1000000

/**
 * @def HCSR04_NUMBER
 * @brief Speed of sound in air in meters per microsecond.
 */
#define HCSR04_NUMBER           ((float)0.0171821)

/**
 * @def TIM_MAX_PERIOD_VALUE
 * @brief Maximum value for the timer period register.
 */
#define TIM_MAX_PERIOD_VALUE        65535

/**
 * @brief Clock frequency for the advanced timers.
 */
#define TIM_CLOCK_ADVANCED        MCL_RCC_GetPCLK2Freq()

/**
 * @brief Clock frequency for the general purpose timers.
 */
#define TIM_CLOCK_GENERAL        MCL_RCC_GetPCLK1Freq()

/**
 * @brief This function is used to configure the timers for Input Capture.
 *
 * @param None
 *
 * @return None
 */
void TIM_IC_vSetCfg(void);

/**
 * @brief This function is used to configure the timers for Pulse Width Modulation Output.
 *
 * @param None
 *
 * @return None
 */
void TIM_PWM_OUT_vSetCfg(void);

#endif /* MCAL_TIM_CONFIG_H_ */
