/**
 * @file buzzer_sensor_config.h
 * @brief Header file for configuring the buzzer sensor.
 */

#ifndef BUZZER_SENSOR_CONFIG_H_
#define BUZZER_SENSOR_CONFIG_H_

/**
 * @def BUZZER_CHANNEL
 * @brief Macro to define the GPIO channel and pin for the buzzer.
 *
 * This macro specifies the GPIO port and pin number to which the buzzer sensor is connected.
 * For example, `BUZZER_CHANNEL` is set to `GPIOB, GPIO_PIN6`.
 */
#define BUZZER_CHANNEL    GPIOB, GPIO_PIN6

#endif /* BUZZER_SENSOR_CONFIG_H_ */