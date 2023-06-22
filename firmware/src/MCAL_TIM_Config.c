#include "../inc/STM32F4xx_Device_Header.h"
#include "../inc/MCAL_TIM_Interface.h"
#include "../inc/MCAL_TIM_Config.h"

TIM_IC_CfgType TIM_IC_Config = {
		// Initialize the input capture configuration
		.IC_Channel = TIM_CHANNEL_1,
		.IC_Prescaler = TIM_CLKPRESCALER_16, // set the prescaler to 16
		.IC_Period = TIM_MAX_PERIOD_VALUE, // set the period to the maximum value
		.IC_Selection = TIM_ICSELECTION_DIRECTTI, // use direct input capture mode
		.IC_TriggerSource = TIM_TS_TI2FP2, // use TI2 as trigger source
};