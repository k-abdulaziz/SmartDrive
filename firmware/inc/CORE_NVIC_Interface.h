#ifndef CORE_NVIC_INTERFACE_H_
#define CORE_NVIC_INTERFACE_H_

#include "STD_TYPES.h"
#include "STM32F4xx_Device_Header.h"

typedef enum {

	Group16_NoneSub = 0b011,
	Group8_2Sub = 0b100,
	Group4_4Sub = 0b101,
	Group2_8Sub = 0b110,
	GroupNone_16SubGroup = 0b111
} NVIC_Grouping_t;

typedef enum {
	NVIC_IRQ_DISABLE = 0,
	NVIC_IRQ_ENABLE = 1
} IRQ_State_t;

typedef struct {
	NVIC_Grouping_t NVIC_GroupBits;
	u8 NVIC_GroupID;
	u8 NVIC_SubGroupID;
} NVIC_CfgType;

extern NVIC_CfgType NVIC_G_Config;


void COR_NVIC_vEnableInterrupt(IRQ_Num_t Cp_xIRQId);

void COR_NVIC_vDisableInterrupt(IRQ_Num_t Cp_xIRQId);

void COR_NVIC_vSetPendFlag(IRQ_Num_t Cp_xIRQId);

void COR_NVIC_vClrPendFlag(IRQ_Num_t Cp_xIRQId);

bool CR_NVIC_vGetActiveFlag(IRQ_Num_t Cp_xIRQId);

void COR_NVIC_vSetPriorityCfg(NVIC_Grouping_t Cp_u8PriorityOption);

void COR_NVIC_vSetPriority(IRQ_Num_t Cp_xIRQId, u8 Cp_u8GroupId, u8 Cp_u8SubGroupId);

void COR_NVIC_vSetSoftwareInt(IRQ_Num_t Cp_IntNum);

#endif /* CORE_NVIC_INTERFACE_H_ */
