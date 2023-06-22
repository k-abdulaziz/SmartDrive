
#include "../inc/BIT_MATH.h"
#include "../inc/MCAL_RCC_Config.h"
#include "../inc/MCAL_RCC_Interface.h"
#include "../inc/MCAL_RCC_Private.h"

const u8 APBPrescTable[8U] = {0, 0, 0, 0, 1, 2, 3, 4}; //shift right by 1 = divide by 2;

const u8 AHBPrescTable[16U] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9}; //shift right by 1 = divide by 2;

void MCL_RCC_vInitSysClk(RCC_CfgType *Cp_xRCC_Cfg) {
	/********Enable All System Clocks***********/
	RCC->RCC_CR.HSION = 1;
	RCC->RCC_CR.HSEON = 1;
	RCC->RCC_CR.PLLON = 1;

	/************Select System Clock***********/
	RCC->RCC_CFGR_bits.SWn = Cp_xRCC_Cfg->System_ClkSelection;
	/************Select System Clock Type***********/
	RCC->RCC_CR.HSEBYP = Cp_xRCC_Cfg->System_ClkType;
	switch (Cp_xRCC_Cfg->System_ClkSelection) {
		case HSI_CLOCK:
			RCC->RCC_CFGR_bits.HPRE = Cp_xRCC_Cfg->System_ClkPrescaler;
			break;
		case HSE_CLOCK:
			RCC->RCC_CFGR_bits.RTCPRE = Cp_xRCC_Cfg->System_ClkPrescaler;
			break;
		case PLL_CLOCK:
			break;
	}
}

void MCL_RCC_vEnablePeriphClk(SysBus_t Cp_u8Bus, u8 Cp_u8Periph) {
	switch (Cp_u8Bus) {
		case AHB1_BUS  :
			SET_BIT(RCC->RCC_AHB1ENR, Cp_u8Periph);
			break;
		case AHB2_BUS  :
			SET_BIT(RCC->RCC_AHB2ENR, Cp_u8Periph);
			break;
		case APB1_BUS  :
			SET_BIT(RCC->RCC_APB1ENR, Cp_u8Periph);
			break;
		case APB2_BUS  :
			SET_BIT(RCC->RCC_APB2ENR, Cp_u8Periph);
			break;
		default    : /* ERROR*/         break;
	}
}

void MCL_RCC_vDisablePeriphClk(SysBus_t Cp_u8Bus, u8 Cp_u8Periph) {
	switch (Cp_u8Bus) {
		case AHB1_BUS  :
			CLEAR_BIT(RCC->RCC_AHB1ENR, Cp_u8Periph);
			break;
		case AHB2_BUS  :
			CLEAR_BIT(RCC->RCC_AHB2ENR, Cp_u8Periph);
			break;
		case APB1_BUS  :
			CLEAR_BIT(RCC->RCC_APB1ENR, Cp_u8Periph);
			break;
		case APB2_BUS  :
			CLEAR_BIT(RCC->RCC_APB2ENR, Cp_u8Periph);
			break;
		default: /* ERROR*/         break;
	}
}

u32 MCL_RCC_GetSYSCLKFreq(void) {
//Bits 3:2 SWS[1:0]: System clock switch status
//Set and cleared by hardware to indicate which clock source is used as system clock.
//00: HSI oscillator used as system clock
//01: HSE oscillator used as system clock
//10: PLL used as system clock
//11: Not applicable
	switch (RCC->RCC_CFGR >> 2 & 0b11) {
		case HSI_CLOCK:
			return 16000000UL;
			break;
		case HSE_CLOCK:
			return 25000000UL;
			break;
		case PLL_CLOCK:
			return 16000000UL;
			break;
	}
}

u32 MCL_RCC_GetHCLKFreq(void) {
	return (MCL_RCC_GetSYSCLKFreq() >> AHBPrescTable[(RCC->RCC_CFGR >> 4) & 0xF]);
}

u32 MCL_RCC_GetPCLK1Freq(void) {
	return (MCL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->RCC_CFGR >> 8) & 0b111]);
}

u32 MCL_RCC_GetPCLK2Freq(void) {
	return (MCL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->RCC_CFGR >> 11) & 0b111]);
}