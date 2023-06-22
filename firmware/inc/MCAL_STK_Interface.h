#ifndef MCAL_STK_INTERFACE_H_
#define MCAL_STK_INTERFACE_H_

#include "STD_TYPES.h"

typedef enum {
	AHB_8_DIVIDE,
	CPU_CLOCK_AHB
} STK_ClkSrc_t;

typedef enum {
	DISABLE_EXCEPTION = 0,
	ENABLE_SINGLE_EXCEPTION = 1,
	ENABLE_PERIODIC_EXCEPTION = 2
} STK_ExceptionMode_t;

typedef struct {
	STK_ClkSrc_t SysTick_ClkSrc;
	STK_ExceptionMode_t SysTick_Exception;

	void (*Systick_CallBackPtr)(void);
} STK_CfgType;

extern STK_CfgType STK_G_Config;

void MCL_STK_vInit(STK_CfgType *Cp_STK_Cfg);

void MCL_STK_vResetTimer(void);

void MCL_STK_vDelay_us(u32 Cp_u32Ticks);

void MCL_STK_vDelay_ms(u32 Cp_u32Ticks);

void MCL_STK_vSetIntervalSingle(u32 Cp_u32Ticks, void (*Copy_Ptr)(void));

void MCL_STK_vSetIntervalPeriodic(u32 Cp_u32Ticks, void (*Copy_Ptr)(void));

void MCL_STK_vStopInterval(void);

u32 MCL_STK_u32GetElapsed(void);

u32 MCL_STK_u32GetRemaining(void);

#endif /* MCAL_STK_INTERFACE_H_ */
