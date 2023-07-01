/**
 * @file APP_ACC_Mode.c
 * @brief Source file for the ACC mode application.
 *
 * This file contains the implementation of the ACC mode application functions.
 */

/**
 * @headerfile APP_ACC_Mode.h
 * @brief Header file that contains the declarations for the ACC mode application.
 */
#include "APP_ACC_Mode.h"

/**
 * @headerfile APP_ADAS_Config.h
 * @brief Header file that contains the configuration for the ADAS application.
 */
#include "APP_ADAS_Config.h"

/**
 * @headerfile MCAL_USART_Interface.h
 * @brief Header file that contains the interface for USART operations.
 */
#include "../inc/MCAL_USART_Interface.h"

/**
 * @headerfile MotorDriver_Interface.h
 * @brief Header file that contains the interface for the motor driver.
 */
#include "../ECUAL/MotorDriver/MotorDriver_Interface.h"

/**
 * @headerfile HCSR04_Interface.h
 * @brief Header file that contains the interface for the HCSR04 sensor.
 */
#include "../ECUAL/HCSR04/HCSR04_Interface.h"

/**
 * @var TRIG_Ticks
 * @brief Global variable to store the number of ticks for triggering the sensor.
 */
u16 TRIG_Ticks;

/**
 * @var LCD_Ticks
 * @brief Global variable to store the number of ticks for LCD operations.
 */
u16 LCD_Ticks;

/**
 * @var Current_Distance
 * @brief Global variable to store the current distance measured by the sensor.
 */
u16 Current_Distance;

/**
 * @var Distance
 * @brief Global variable to store the calculated distance.
 */
u32 Distance = 0;

/**
 * @var TEXT
 * @brief Global variable to store the text data.
 */
u8 TEXT[16] = {0};

/**
 * @var GUI_u8SendMsg
 * @brief Global variable to store the message to be sent via USART.
 */
u16 GUI_u8SendMsg;

/**
 * @brief Callback function for ACC Button0.
 */
void ACC_Button0CallBack(void);

/**
 * @brief Callback function for ACC Button1.
 */
void ACC_Button1CallBack(void);

/**
 * @brief ACC mode task function.
 */
void APP_ACC_vTask() {
	static u8 Speed;
	static u8 MAX_Speed = 80;
	static u16 Default_Distance = 25;

	while (1) {

		TRIG_Ticks++;
		LCD_Ticks++;
		MotorDriver_voidControlSpeed(Speed);
		MotorDriver_voidMoveForward();

		Current_Distance = HAL_HCSR04_f32Read(HCSR04_SENSOR1);

		if (Current_Distance < Default_Distance && Current_Distance > 5) {
			Speed = ((((MAX_Speed - 60) * Current_Distance) - (5 * MAX_Speed) + 1500) / 20);
			MCL_USART_vTransmitData(USART1, &GUI_u8SendMsg, USART_POLLING_ENABLE);
		} else if (Current_Distance <= 5) {
			MotorDriver_voidStop();
			Speed = 0;
		} else if (Current_Distance >= Default_Distance) {
			Speed = 100;
		}

		if (TRIG_Ticks >= 70) {
			HAL_HCSR04_vTrigger(HCSR04_SENSOR1);
			TRIG_Ticks = 0;
		}

		if (!ACC_ModeFlag) {
			break;
		}
	}
}

/**
 * @brief Callback function for ACC Button0.
 */
void ACC_Button0CallBack(void) {

	MCL_GPIO_vTogglePin(GPIOB, GPIO_PIN0);
}

/**
 * @brief Callback function for ACC Button1.
 */
void ACC_Button1CallBack(void) {
	MCL_GPIO_vTogglePin(GPIOB, GPIO_PIN1);
	while (MCL_GPIO_u8GetPinVal(GPIOA, GPIO_PIN1));
}