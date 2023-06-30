/**
 * @file buzzer_sensor_interface.h
 * @brief Header file for the buzzer sensor interface.
 */

#ifndef BUZZER_SENSOR_INTERFACE_H_
#define BUZZER_SENSOR_INTERFACE_H_

/**
 * @brief Initializes the buzzer sensor.
 *
 * This function initializes the buzzer sensor and prepares it for use.
 */
void Buzzer_Init(void);

/**
 * @brief Turns the buzzer sensor ON.
 *
 * This function activates the buzzer sensor, causing it to produce sound.
 */
void Buzzer_ON(void);

/**
 * @brief Turns the buzzer sensor OFF.
 *
 * This function deactivates the buzzer sensor, stopping it from producing sound.
 */
void Buzzer_Off(void);

#endif /* BUZZER_SENSOR_INTERFACE_H_ */