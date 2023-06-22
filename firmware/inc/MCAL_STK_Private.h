#ifndef MCAL_STK_PRIVATE_H_
#define MCAL_STK_PRIVATE_H_

#include "STD_TYPES.h"
#include "STM32F4xx_Device_Header.h"

typedef struct {
	union {
		struct {
			vu32 ENABLE: 1;
			vu32 TICKINT: 1;
			vu32 CLKSOURCE: 1;
			u32 : 13;
			vu32 COUNTFLAG: 1;
			u32 : 15;
		} STK_CTRL_Bits;
		vu32 STK_CTRL;
	};

	vu32 STK_LOAD;
	vu32 STK_VAL;
	vu32 STK_CALIB;

} STK_TypeDef;

#define STK                ((volatile STK_TypeDef *)SYSTICK_BASE)

#endif /* MCAL_STK_PRIVATE_H_ */
