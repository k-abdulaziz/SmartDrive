/**
 * @file MotorDriver_Config.h
 * @brief Configuration file for the motor driver.
 *
 * This file contains the configuration settings for the motor driver.
 *
 * @author Khaled Abdualziz
 * @date 2023-6-20
 */

#ifndef HAL_MOTORDRIVER_MOTORDRIVER_CONFIG_H_
#define HAL_MOTORDRIVER_MOTORDRIVER_CONFIG_H_

/**
 * @headerfile "MCAL_GPIO_Interface.h"
 * @brief This header file contains the interface for GPIO operations.
 */
#include "../../inc/MCAL_GPIO_Interface.h"

/**
 * @def MOTORDRIVER_PORT
 * @brief GPIO port for the motor driver.
 *
 * This macro defines the GPIO port to which the motor driver is connected.
 */
#define MOTORDRIVER_PORT  GPIOA

/**
 * @def MOTORDRIVER_IN1
 * @brief GPIO pin for IN1 of the motor driver.
 *
 * This macro defines the GPIO pin for IN1 of the motor driver.
 */
#define MOTORDRIVER_IN1   GPIO_PIN0

/**
 * @def MOTORDRIVER_IN2
 * @brief GPIO pin for IN2 of the motor driver.
 *
 * This macro defines the GPIO pin for IN2 of the motor driver.
 */
#define MOTORDRIVER_IN2   GPIO_PIN1

/**
 * @def MOTORDRIVER_IN3
 * @brief GPIO pin for IN3 of the motor driver.
 *
 * This macro defines the GPIO pin for IN3 of the motor driver.
 */
#define MOTORDRIVER_IN3   GPIO_PIN2

/**
 * @def MOTORDRIVER_IN4
 * @brief GPIO pin for IN4 of the motor driver.
 *
 * This macro defines the GPIO pin for IN4 of the motor driver.
 */
#define MOTORDRIVER_IN4   GPIO_PIN3

/**
 * @brief TIM_HandleTypeDef structure for PWM output channel 1.
 *
 * This structure defines the configuration parameters for the timer used for PWM output channel 1.
 */
TIM_HandleTypeDef PWM_htim31 = {
		.Instance =  TIM3,
		.Channel = TIM_CHANNEL_1,
};

/**
 * @brief TIM_HandleTypeDef structure for PWM output channel 2.
 *
 * This structure defines the configuration parameters for the timer used for PWM output channel 2.
 */
TIM_HandleTypeDef PWM_htim32 = {
		.Instance =  TIM3,
		.Channel = TIM_CHANNEL_2,
};

#endif /* HAL_MOTORDRIVER_MOTORDRIVER_CONFIG_H_ */