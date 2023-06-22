#ifndef MCAL_EXTI_INTERFACE_H_
#define MCAL_EXTI_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MCAL_GPIO_Interface.h"
#include "MCAL_EXTI_Private.h"
#include "CORE_NVIC_Interface.h"

typedef enum {
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15,
} EXTI_Line_t;

typedef enum {
	EXTIRQ0_A0,
	EXTIRQ1_A1,
	EXTIRQ2_A2,
	EXTIRQ3_A3,
	EXTIRQ4_A4,
	EXTIRQ5_A5,
	EXTIRQ6_A6,
	EXTIRQ7_A7,
	EXTIRQ8_A8,
	EXTIRQ9_A9,
	EXTIRQ10_A10,
	EXTIRQ11_A11,
	EXTIRQ12_A12,
	EXTIRQ13_A13,
	EXTIRQ14_A14,
	EXTIRQ15_A15,

	EXTIRQ16_B0,
	EXTIRQ17_B1,
	EXTIRQ18_B2,
	EXTIRQ19_B3,
	EXTIRQ20_B4,
	EXTIRQ21_B5,
	EXTIRQ22_B6,
	EXTIRQ23_B7,
	EXTIRQ24_B8,
	EXTIRQ25_B9,
	EXTIRQ26_B10,
	EXTIRQ27_B11,
	EXTIRQ28_B12,
	EXTIRQ29_B13,
	EXTIRQ30_B14,
	EXTIRQ31_B15,

	EXTIRQ32_C0,
	EXTIRQ33_C1,
	EXTIRQ34_C2,
	EXTIRQ35_C3,
	EXTIRQ36_C4,

} EXTIRQ_Src_t;

typedef enum {
	EXTI_LOW_LEVEL = 0,
	EXTI_ON_CHANGE = 1,
	EXTI_FALLING_EDGE = 2,
	EXTI_RISING_EDGE = 3,

} EXTI_Sense_t;

typedef struct {
	EXTI_Line_t EXTI_LineNum;    //select EXTI input line number
	//this parameter can be a value of  @ref EXTI_LineNumber

	GPIO_TypeDef *GPIO_Port;        //select GPIO port to be used as EXTI port
	//this parameter can be a peripheral instant @ MCU DEVICE HEADER

	GPIO_Pin_t GPIO_Pin;            //select GPIO pin to be used as EXTI pin
	//this parameter can be a value of  @ref GPIO_Pins_define @ MCU GPIO Driver

	IRQ_Num_t IVT_IRQNumber;            //select Interrupt Vector Table request number
	//this parameter can be a value of @ref IVT_IRQNumber @ MCU DEVICE HEADER

} EXTI_GPIO_Mapping_t;

extern EXTI_GPIO_Mapping_t EXTI_Mapping[];

typedef struct {
	EXTI_GPIO_Mapping_t EXTI_PinMap;    //select EXTI input pin
	//this parameter can be a value of   @ref EXTI_define

	NVIC_CfgType EXTI_Priority;        //select IRQ Priority group and subgroup

	EXTI_Sense_t Trigger_State;        //select trigger state (edge trigger)
	//this parameter can be a value of

	bool IRQ_EN;            //select pending request register state
	//this parameter can be a value of  @ref EXTI_IRQ_EN_define (INT_MASK + NVIC Enable/Disable)

	void (*IRQ_pCallBack)(void);            //pointer to IRQ call back function

} EXTI_PinCfg_t;

extern EXTI_PinCfg_t EXTI_G_Cfg[];

void MCL_EXTI_vInit(EXTI_PinCfg_t *Cp_EXTI_Cfg);

void MCL_EXTI_vInitGPIO(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_EXTIPin);

void MCL_EXTI_vEnable(EXTI_PinCfg_t *Cp_EXTI_Cfg, void (*Lc_pCallBackFn)(void));

void MCL_EXTI_vDisable(EXTI_Line_t Cp_xLineNo);

#endif /* MCAL_EXTI_INTERFACE_H_ */







