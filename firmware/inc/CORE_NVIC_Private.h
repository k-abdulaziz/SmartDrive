#ifndef CORE_NVIC_PRIVATE_H_
#define CORE_NVIC_PRIVATE_H_

#include "STM32F4xx_Device_Header.h"
#include "STD_TYPES.h"

typedef struct {

	vu32 NVIC_ISER[8];
	u32  resersed0[24];
	vu32 NVIC_ICER[8];
	u32  resersed1[24];
	vu32 NVIC_ISPR[8];

	u32  resersed2[24];
	vu32 NVIC_ICPR[8];
	u32  resersed3[24];
	vu32 NVIC_IABR[8];
	u32  resersed4[24];
	vu32 NVIC_IP[8];
	u32  resersed5[24];
	vu8  NVIC_IPR[240];
	vu32 NVIC_STIR;

} NVIC_Reg_t;


typedef struct {
	vu32 CPUID;
	vu32 ICSR;
	vu32 VTOR;
	vu32 AIRCR;
	vu32 SCR;
	vu32 CCR;
	vu32 SHPR1;
	vu32 SHPR2;
	vu32 SHPR3;
	vu32 SHCSR;
	vu32 CFSR;
	vu32 HFSR;
	vu32 DFSR;
	vu32 MMFAR;
	vu32 BFAR;
	vu32 AFSR;
} SCB_Reg_t;

#define VECTKEY            0x5FA
#define ACTLR_REG          ((volatile u32 *)CORTEX_M4_PERIPHERALS_BASE+0x008)
#define NVIC               ((volatile NVIC_Reg_t *)NVIC_BASE)
#define SCB                ((volatile SCB_Reg_t *)SCB_BASE)

#endif /* CORE_NVIC_PRIVATE_H_ */
