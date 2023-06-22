#ifndef MCAL_TIM_CONFIG_H_
#define MCAL_TIM_CONFIG_H_

#include "MCAL_TIM_Interface.h"
#include "MCAL_RCC_Interface.h"
#include "STM32F4xx_Device_Header.h"

#define HCSR04_TIMEOUT          1000000
#define HCSR04_NUMBER           ((float)0.0171821)

#define TIM_MAX_PERIOD_VALUE        65535

#define TIM_CLOCK_ADVANCED        MCL_RCC_GetPCLK2Freq()
#define TIM_CLOCK_GENERAL        MCL_RCC_GetPCLK1Freq()

void TIM_IC_vSetCfg(void);

void TIM_PWM_OUT_vSetCfg(void);

#endif /* MCAL_TIM_CONFIG_H_ */
