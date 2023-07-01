/**
 * @file APP_ADAS_Config.h
 * @brief This file contains the configuration for the ADAS (Advanced Driver Assistance System) application.
 */

#ifndef APP_ADAS_CONFIG_H_
#define APP_ADAS_CONFIG_H_

/**
 * @brief Header file - Standard Data Types.
 */
#include "../inc/STD_TYPES.h"

/**
 * @brief External variables for tick counters and messages.
 */
extern u16 TRIG_Ticks; /**< Global variable to hold tick count for triggering HCSR04 sensor. */
extern u16 LCD_Ticks; /**< Global variable to hold tick count for updating LCD display. */
extern u16 Current_Distance; /**< Global variable to hold the current distance measured by HCSR04 sensor. */
extern u16 GUI_u8ReceivedMsg; /**< Global variable to hold the received message from GUI. */
extern u16 GUI_u8SendMsg; /**< Global variable to hold the message to be sent to GUI. */

/**
 * @brief Flags for different modes of the ADAS application.
 */
extern volatile u8 ACC_ModeFlag; /**< Flag indicating ACC (Adaptive Cruise Control) mode. */
extern volatile u8 AEB_ModeFlag; /**< Flag indicating AEB (Automatic Emergency Braking) mode. */
extern volatile u8 LKS_ModeFlag; /**< Flag indicating LKS (Lane Keeping System) mode. */
extern volatile u8 LDW_ModeFlag; /**< Flag indicating LDW (Lane Departure Warning) mode. */

/**
 * @brief Flags for left and right infrared (IR) sensors.
 */
extern volatile u8 left_IR; /**< Flag indicating the status of the left infrared sensor. */
extern volatile u8 right_IR; /**< Flag indicating the status of the right infrared sensor. */

/**
 * @brief Global variable for speed control.
 */
extern volatile u8 Speed; /**< Global variable to hold the current speed value. */

/**
 * @brief Default speed value.
 */
#define DEFAULT_SPEED 80 /**< Default speed value for the application. */

/**
 * @brief Options for ACC mode and speed control.
 */
#define ACC_MODE_OPTION 'C' /**< Option for ACC mode. */
#define ACC_DEFAULT_SPEED 'F' /**< Option for setting ACC to default speed. */
#define ACC_SET_SPEED 'S' /**< Option for setting custom speed for ACC. */

/**
 * @brief Options for AEB, LKS, and LDW modes.
 */
#define AEB_MODE_OPTION 'E' /**< Option for AEB mode. */
#define LKS_MODE_OPTION 'K' /**< Option for LKS mode. */
#define LDW_MODE_OPTION 'D' /**< Option for LDW mode. */

/**
 * @brief Callback function for USART message reception.
 */
void USART_MsgCallBack(void);

#endif /* APP_ADAS_CONFIG_H_ */