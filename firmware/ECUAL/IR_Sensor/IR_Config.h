/**
 * @file IR_Sensor_IR_Config.h
 * @brief Configuration file for the IR sensor.
 *
 * This file contains the configuration settings for the IR sensor.
 *
 * @author Muhammed Al Kahwagy
 * @date 2023-06-20
 */

#ifndef IR_SENSOR_IR_CONFIG_H_
#define IR_SENSOR_IR_CONFIG_H_

/**
 * @def IR_PORT
 * @brief GPIO port to which the IR sensors are connected.
 *
 * Connect the IR sensors to this GPIO port.
 */
#define IR_PORT         GPIOB

/**
 * @def IR_RIGHT
 * @brief Pin number to which the right IR sensor is connected.
 *
 * Connect the right IR sensor to this pin.
 */
#define IR_RIGHT        GPIO_PIN0

/**
 * @def IR_LEFT
 * @brief Pin number to which the left IR sensor is connected.
 *
 * Connect the left IR sensor to this pin.
 */
#define IR_LEFT         GPIO_PIN1

#endif /* IR_SENSOR_IR_CONFIG_H_ */
