/**
 * @file main.c
 * @brief Main file for the application.
 */

#include <stdio.h>

#include "../inc/MCAL_RCC_Interface.h"
#include "../inc/MCAL_STK_Interface.h"
#include "../inc/MCAL_TIM_Interface.h"
#include "../inc/CORE_NVIC_Interface.h"
#include "../inc/MCAL_USART_Interface.h"
#include "../util/Timer_Delay.h"
#include "../ECUAL/HCSR04/HCSR04_Interface.h"
#include "../ECUAL/IR_Sensor/IR_Interface.h"
#include "../ECUAL/MotorDriver/MotorDriver_Interface.h"
#include "../App/APP_ADAS_Config.h"
#include "../App/APP_ACC_Mode.h"
#include "../App/APP_AEB_Mode.h"
#include "../App/APP_LDW_Mode.h"
#include "../App/APP_LKS_Mode.h"

/**
 * @def HCSR04_SENSOR1
 * @brief HCSR04 sensor number.
 */
#define HCSR04_SENSOR1  0

/**
 * @brief Current speed value.
 */
volatile u8 Speed;

/**
 * @brief Flag for ACC mode.
 */
volatile u8 ACC_ModeFlag = 0;

/**
 * @brief Flag for AEB mode.
 */
volatile u8 AEB_ModeFlag = 0;

/**
 * @brief Flag for LKS mode.
 */
volatile u8 LKS_ModeFlag = 0;

/**
 * @brief Flag for LDW mode.
 */
volatile u8 LDW_ModeFlag = 0;

void SysTick_CallBack();

/**
 * @brief Received message from the GUI.
 */
u16 GUI_u8ReceivedMsg = 0;

/**
 * @def AVG_SPEED_FWD
 * @brief Average forward speed.
 */
#define AVG_SPEED_FWD    70

/**
 * @def AVG_SPEED_LEFT
 * @brief Average speed for left movement.
 */
#define AVG_SPEED_LEFT    60,AVG_SPEED_FWD

/**
 * @def AVG_SPEED_RIGHT
 * @brief Average speed for right movement.
 */
#define AVG_SPEED_RIGHT    AVG_SPEED_FWD,60

/**
 * @brief Main function of the application.
 * @return Returns 0 upon successful execution.
 */
int main(void) {
	MCL_RCC_vInitSysClk(&RCC_G_Config); // Initialize the system clock
	MCL_STK_vInit(&STK_G_Config); // Initialize the SysTick timer

	TimerDelay_Init(); // Initialize the timer delay

	HAL_HCSR04_vInit(&HCSR04_CfgParam[HCSR04_SENSOR1], &US_htim2); // Initialize the HCSR04 sensor

	MotorDriver_voidInit(); // Initialize the motor driver

	IR_Init(); // Initialize the IR sensor

	USART_G_Config.P_IRQ_CallBack = (void (*)(USART_IRQEvent_t)) USART_MsgCallBack; // Set the USART IRQ callback

	MCL_USART_vInit(USART1, &USART_G_Config); // Initialize USART1

	while (1) {
		if (ACC_ModeFlag) {
			APP_ACC_vTask(); // Execute ACC mode task
		} else if (AEB_ModeFlag) {
			APP_AEB_vTask(); // Execute AEB mode task
		} else if (LKS_ModeFlag) {
			APP_LKS_vTask(); // Execute LKS mode task
		} else if (LDW_ModeFlag) {
			APP_LDW_vTask(); // Execute LDW mode task
		}
	}

	return 0;
}

/**
 * @brief Delay in milliseconds.
 * @param Copy_32Delay Delay value in milliseconds.
 */
void APP_vDelay_ms(u32 Copy_32Delay) {
	for (u32 i = 0; i < Copy_32Delay * 300; i++) {
		asm("NOP");
	}
}

/**
 * @brief Delay in microseconds.
 * @param Copy_32Delay Delay value in microseconds.
 */
void APP_vDelay_us(u32 Copy_32Delay) {
	for (u32 i = 0; i < Copy_32Delay * 30; i++) {
		asm("NOP");
	}
}

/**
 * @brief Callback function for receiving USART messages.
 */
void USART_MsgCallBack(void) {
	MCL_USART_vReceiveData(USART1, &GUI_u8ReceivedMsg, USART_POLLING_DIASBLE);
	switch (GUI_u8ReceivedMsg) {
		case ACC_MODE_OPTION:
			TOGGLE_BIT(ACC_ModeFlag, BIT0);
			MCL_USART_vReceiveData(USART1, &GUI_u8ReceivedMsg, USART_POLLING_ENABLE);
			if (GUI_u8ReceivedMsg == 'F') {
				Speed = DEFAULT_SPEED;
			} else if (GUI_u8ReceivedMsg == 'S') {
				MCL_USART_vReceiveData(USART1, &GUI_u8ReceivedMsg, USART_POLLING_ENABLE);
				Speed = GUI_u8ReceivedMsg;
			}
			break;
		case AEB_MODE_OPTION:
			TOGGLE_BIT(AEB_ModeFlag, BIT0);
			break;
		case LKS_MODE_OPTION:
			TOGGLE_BIT(LKS_ModeFlag, BIT0);
			break;
		case LDW_MODE_OPTION:
			TOGGLE_BIT(LDW_ModeFlag, BIT0);
			break;
	}
}