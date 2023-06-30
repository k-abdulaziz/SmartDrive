/**
 * @file MCAL_USART_CONFIG_H_
 * @brief This file contains the configuration of the USART peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_USART_CONFIG_H_
#define MCAL_USART_CONFIG_H_

/**
 * @headerfile "MCAL_GPIO_Interface.h"
 * @brief This header file contains the interface for the GPIO peripheral.
 */
#include "MCAL_GPIO_Interface.h"

/**
 * @file MCAL_USART_CONFIG_H_
 * @brief This file contains the configuration of the USART peripheral.
 *
 * @headerfile "MCAL_GPIO_Interface.h"
 * @brief This header file contains the interface for the GPIO peripheral.
 */

/**
 * @def USART1_PORT
 * @brief Defines the GPIO port for USART1.
 */
#define USART1_PORT            GPIOA

/**
 * @def USART1_TX_PIN
 * @brief Defines the GPIO pin for USART1 TX.
 */
#define USART1_TX_PIN        GPIO_PIN9

/**
 * @def USART1_RX_PIN
 * @brief Defines the GPIO pin for USART1 RX.
 */
#define USART1_RX_PIN        GPIO_PIN10

/**
 * @def USART2_PORT
 * @brief Defines the GPIO port for USART2.
 */
#define USART2_PORT            GPIOB

/**
 * @def USART2_TX_PIN
 * @brief Defines the GPIO pin for USART2 TX.
 */
#define USART2_TX_PIN        GPIO_PIN12

/**
 * @def USART2_RX_PIN
 * @brief Defines the GPIO pin for USART2 RX.
 */
#define USART2_RX_PIN        GPIO_PIN13

#endif /* MCAL_USART_CONFIG_H_ */