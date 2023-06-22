#include "../inc/STD_TYPES.h"
#include "../inc/MCAL_TIM_Interface.h"
#include "../ECUAL/HCSR04/HCSR04_Interface.h"
#include "../inc/STM32F4xx_ISR.h"

extern TIM_HandleTypeDef htim2;

void NMI_Handler(void) {}

void HardFault_Handler(void) {}

void MemManage_Handler(void) {}

void BusFault_Handler(void) {}

void UsageFault_Handler(void) {}

void DebugMon_Handler(void) {}

void TIM2_IRQHandler(void) {
	if (TIM_xCheckINTFlag(&US_htim2, TIM_INT_UPDATE) != RESET) {
		if (TIM_xCheckINTSrc(&US_htim2, TIM_INT_UPDATE) != RESET) {
			TIM_vClearFlag(&US_htim2, TIM_INT_UPDATE);
			HAL_HCSR04_TMR_OVF_ISR(&US_htim2);
		}
	}

	if (TIM_xCheckINTFlag(&US_htim2, TIM_INT_CC1) != RESET) {
		if (TIM_xCheckINTSrc(&US_htim2, TIM_INT_CC1) != RESET) {
			TIM_vClearFlag(&US_htim2, TIM_INT_CC1);
			HAL_HCSR04_TMR_IC_ISR(&US_htim2);
		}
	}
}
