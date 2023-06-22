#ifndef MCAL_RCC_INTERFACE_H_
#define MCAL_RCC_INTERFACE_H_

#include "STD_TYPES.h"
#include "MCAL_RCC_Config.h"
#include "STM32F4xx_Device_Header.h"

typedef struct {
	SysClk_t System_ClkSelection;
	u32 System_ClkFreq;
	SysClk_Prescaler_t System_ClkPrescaler;
	ClkType_t System_ClkType;

} RCC_CfgType;

extern RCC_CfgType RCC_G_Config;

void MCL_RCC_vInitSysClk(RCC_CfgType *Cp_xRCC_Cfg);

void MCL_RCC_vEnablePeriphClk(SysBus_t Cp_u8SysBus, u8 Cp_u8Periph);

void MCL_RCC_vDisablePeriphClk(SysBus_t Cp_u8SysBus, u8 Cp_u8Periph);

u32 MCL_RCC_GetSYSCLKFreq(void);

u32 MCL_RCC_GetHCLKFreq(void);

u32 MCL_RCC_GetPCLK1Freq(void);

u32 MCL_RCC_GetPCLK2Freq(void);

#endif /* MCAL_RCC_INTERFACE_H_ */
