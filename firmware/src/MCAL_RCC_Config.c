#include "../inc/STM32F4xx_Device_Header.h"
#include "../inc/MCAL_RCC_Interface.h"

RCC_CfgType RCC_G_Config = {
		.System_ClkSelection = HSI_CLOCK,
		.System_ClkFreq = 8000000UL,
		.System_ClkPrescaler = SYSCLK_PRESCALER_BY2,
		.System_ClkType = RC_CLOCK,
};