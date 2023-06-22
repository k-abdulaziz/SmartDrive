#include "../inc/CORE_NVIC_Private.h"
#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"
#include "../inc/CORE_NVIC_Interface.h"

void (*Global_NVICCallBackPtr)(void) = NULL;

void COR_NVIC_vEnableInterrupt(IRQ_Num_t Cp_xIRQId) {
	if (Cp_xIRQId < 240) {
		NVIC->NVIC_ISER[Cp_xIRQId / 32] = (1 << (Cp_xIRQId % 32));
	}
}

void COR_NVIC_vDisableInterrupt(IRQ_Num_t Cp_xIRQId) {
	if (Cp_xIRQId < 240) {
		NVIC->NVIC_ICER[Cp_xIRQId / 32] = (1 << (Cp_xIRQId % 32));
	}
}

void COR_NVIC_vSetPendFlag(IRQ_Num_t Cp_xIRQId) {
	NVIC->NVIC_ISPR[Cp_xIRQId / 32] = (1 << (Cp_xIRQId % 32));
}

void COR_NVIC_vClrPendFlag(IRQ_Num_t Cp_xIRQId) {
	NVIC->NVIC_ICPR[Cp_xIRQId / 32] = (1 << (Cp_xIRQId % 32));

}

bool COR_NVIC_vGetActiveFlag(IRQ_Num_t Cp_xIRQId) {
	return (GET_BIT(NVIC->NVIC_IABR[Cp_xIRQId / 32], Cp_xIRQId % 32));
}


void COR_NVIC_vSetPriorityCfg(NVIC_Grouping_t Cp_u8PriorityOption) {
	SCB->AIRCR = (VECTKEY << 16) | (Cp_u8PriorityOption << 8);
}

void COR_NVIC_vSetPriority(IRQ_Num_t Cp_xIRQId, u8 Cp_u8GroupId, u8 Cp_u8SubGroupId) {

	u8 Cp_u8PriorityId = (Cp_u8SubGroupId |
	                      (Cp_u8GroupId << ((READ_BITS(SCB->AIRCR, BIT8, THREE_BITS) + 1) - Group4_4Sub)));
	NVIC->NVIC_IPR[Cp_xIRQId] = (Cp_u8PriorityId << 4);
}


void COR_NVIC_vSetSoftwareInt(IRQ_Num_t Cp_IntNum) {

	// Enable the PendSV interrupt by setting its bit in the NVIC_ISER register
	COR_NVIC_vEnableInterrupt(PendSV_IRQn);

	// Set the priority of the PendSV interrupt to the desired level
	COR_NVIC_vSetPriority(Cp_IntNum, 0, 0);

	// Trigger the software interrupt by setting the PendSV bit in the NVIC_ISPR register
	COR_NVIC_vSetPendFlag(PendSV_IRQn);
}