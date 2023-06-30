/**
 * @file Timer_Delay.c
 * @brief Source file for timer delay functions.
 *
 * This source file provides the implementation of the timer delay functions declared in Timer_Delay.h.
 * It includes the necessary header files and defines the functions for initializing and using timer-based delays.
 */

#include "Timer_Delay.h"
#include "../inc/MCAL_TIM_Private.h"
#include "../inc/MCAL_TIM_Interface.h"
#include "../inc/MCAL_TIM_Config.h"

#define  TIMER  TIM4
volatile static u32 Gb_u32Ticks = 0;
TIM_HandleTypeDef HTIMx;

void TimerDelay_Init(void) {

	HTIMx.Instance = TIMER;
	HTIMx.Init.TIM_Prescaler = TIM_CLKPRESCALER_8;  // Set prescaler to provide 1 us timebase
	HTIMx.Init.TIM_Mode = TIM_MODE_TIMING;  // Set timer to basic mode
	HTIMx.Init.TIM_CounterMode = TIM_COUNTERMODE_UP;  // Set counter to count up
	HTIMx.Init.TIM_Period = TIM_MAX_PERIOD_VALUE;  // Set maximum period
	HTIMx.Init.TIM_INT = TIM_INT_DISABLE;
	HTIMx.Channel = TIM_CHANNEL_4;
	TIM_vInit(&HTIMx);  // Initialize TIM4
	TIM_vInitCounter(&HTIMx);
}

void TimerDelay_us(vu16 Cp_u16Delay_us) {
	HTIMx.Init.TIM_Period = Cp_u16Delay_us;
	TIM_vStart(&HTIMx);
	while (HTIMx.Instance->CNT < Cp_u16Delay_us);
	TIM_vStop(&HTIMx);
}

void TimerDelay_ms(vu16 Cp_u16Delay_ms) {
	u16 i;
	for (i = 0; i < Cp_u16Delay_ms; i++) {
		TimerDelay_us(2000);
	}
}