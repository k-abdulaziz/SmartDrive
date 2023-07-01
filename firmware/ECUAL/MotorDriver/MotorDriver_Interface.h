/**
 * @file MotorDriver_Interface.h
 * @brief Interface file for the motor driver.
 *
 * This file contains the function prototypes for controlling the motor driver.
 *
 * @author Khaled Abdualziz
 * @date 2023-6-20
 */

#ifndef HAL_MOTORDRIVER_MOTORDRIVER_INTERFACE_H_
#define HAL_MOTORDRIVER_MOTORDRIVER_INTERFACE_H_

/**
 * @brief Initializes the motor driver.
 *
 * This function initializes the motor driver.
 */
void MotorDriver_voidInit(void);

/**
 * @brief Controls the speed of both motors.
 *
 * @param Cp_DutyCycle The duty cycle value for controlling the speed (0-255).
 *
 * This function controls the speed of both motors connected to the motor driver.
 */
void MotorDriver_voidControlSpeed(u8 Cp_DutyCycle);

/**
 * @brief Controls the speed of the right motor.
 *
 * @param Cp_DutyCycle The duty cycle value for controlling the speed (0-255).
 *
 * This function controls the speed of the right motor connected to the motor driver.
 */
void MotorDriver_voidControlSpeedRight(u8 Cp_DutyCycle);

/**
 * @brief Controls the speed of the left motor.
 *
 * @param Cp_DutyCycle The duty cycle value for controlling the speed (0-255).
 *
 * This function controls the speed of the left motor connected to the motor driver.
 */
void MotorDriver_voidControlSpeedLeft(u8 Cp_DutyCycle);

/**
 * @brief Moves the motors forward.
 *
 * This function moves the motors forward.
 */
void MotorDriver_voidMoveForward(void);

/**
 * @brief Moves the motors backward.
 *
 * This function moves the motors backward.
 */
void MotorDriver_voidMoveBackward(void);

/**
 * @brief Turns the motors right.
 *
 * This function turns the motors right.
 */
void MotorDriver_voidMoveRight(void);

/**
 * @brief Turns the motors left.
 *
 * This function turns the motors left.
 */
void MotorDriver_voidMoveLeft(void);

/**
 * @brief Moves the motors forward to the right.
 *
 * This function moves the motors forward to the right.
 */
void MotorDriver_voidMoveForRight(void);

/**
 * @brief Moves the motors forward to the left.
 *
 * This function moves the motors forward to the left.
 */
void MotorDriver_voidMoveForLeft(void);

/**
 * @brief Moves the motors backward to the right.
 *
 * This function moves the motors backward to the right.
 */
void MotorDriver_voidMoveBackRight(void);

/**
 * @brief Moves the motors backward to the left.
 *
 * This function moves the motors backward to the left.
 */
void MotorDriver_voidMoveBackLeft(void);

/**
 * @brief Stops the motors.
 *
 * This function stops the motors.
 */
void MotorDriver_voidStop(void);

#endif /* HAL_MOTORDRIVER_MOTORDRIVER_INTERFACE_H_ */