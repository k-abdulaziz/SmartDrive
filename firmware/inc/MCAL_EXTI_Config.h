/**
 * @file MCAL_EXTI_Config.h
 * @brief This file contains the configuration for the EXTI peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_EXTI_CONFIG_H_
#define MCAL_EXTI_CONFIG_H_

/**
 * @headerfile "MCAL_GPIO_Interface.h"
 * @brief This header file contains the interface for the GPIO peripheral.
 */
#include "MCAL_GPIO_Interface.h"

/**
 * @headerfile "MCAL_EXTI_Interface.h"
 * @brief This header file contains the interface for the EXTI peripheral.
 */
#include "MCAL_EXTI_Interface.h"

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief This header file contains the definitions for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @def	NUMOF_CONFIG_EXTI_SOURCES
 * @brief The number of configurable EXTI sources.
 */
#define NUMOF_CONFIG_EXTI_SOURCES            48

#endif /* MCAL_EXTI_CONFIG_H_ */
