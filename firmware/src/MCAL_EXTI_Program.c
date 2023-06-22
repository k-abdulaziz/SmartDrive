#include "../inc/CORE_NVIC_Interface.h"
#include "../inc/MCAL_GPIO_Interface.h"
#include "../inc/MCAL_EXTI_Config.h"
#include "../inc/MCAL_EXTI_Interface.h"
#include "../inc/MCAL_RCC_Private.h"
#include "../inc/MCAL_RCC_Interface.h"
#include "../inc/MCAL_EXTI_Private.h"

void (*EXTI_gpCallBackFn[15])(void);

void MCL_EXTI_vInit(EXTI_PinCfg_t *Cp_EXTI_Cfg) {
	//configure GPIO pin as AF input
	GPIO_CfgType Lc_GPIO_PinCfg;
	GPIO_Pin_t Lc_GPIO_Pin = Cp_EXTI_Cfg->EXTI_PinMap.GPIO_Pin;
	Lc_GPIO_PinCfg.GPIO_Mode = GPIO_MODE_AF_IN_PD;
	Lc_GPIO_PinCfg.GPIO_Pin = Lc_GPIO_Pin;
	MCL_GPIO_vSetPinCfg(Cp_EXTI_Cfg->EXTI_PinMap.GPIO_Port, &Lc_GPIO_PinCfg);

	// Enable System Configuration Controler (needed for EXTI)
	MCL_RCC_vEnablePeriphClk(APB2_BUS, RCC_APB2ENR_SYSCFGEN);

	/* Configure the external interrupt controller */
	//update routing to EXTI line with port A, B, C
	u8 SYSCFG_EXTICR_Index = (Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum) / 4;
	u8 SYSCFG_EXTICR_Position = ((Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum) % 4) * 4;

	//reset and set SYSCFG_EXTICR to select the source input for EXTIx external interrupt
	SYSCFG->EXTICR[SYSCFG_EXTICR_Index] &= ~(0xF << SYSCFG_EXTICR_Position);
	SYSCFG->EXTICR[SYSCFG_EXTICR_Index] |= ((GPIO_xSelectPortIndex(Cp_EXTI_Cfg->EXTI_PinMap.GPIO_Port))
			<< SYSCFG_EXTICR_Position);

	//reset edge trigger registers
	EXTI->RTSR &= ~(1 << Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);
	EXTI->FTSR &= ~(1 << Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);

	switch (Cp_EXTI_Cfg->Trigger_State) {
		case (EXTI_RISING_EDGE):

			SET_BIT(EXTI->RTSR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);
			CLEAR_BIT(EXTI->FTSR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);

			break;
		case (EXTI_FALLING_EDGE):

			SET_BIT(EXTI->FTSR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);
			CLEAR_BIT(EXTI->RTSR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);
			break;
		case (EXTI_ON_CHANGE):

			SET_BIT(EXTI->RTSR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);
			SET_BIT(EXTI->FTSR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);
			break;
	}

	if (Cp_EXTI_Cfg->IRQ_EN == NVIC_IRQ_ENABLE) {
		//Update IRQ Handling Callback
		EXTI_gpCallBackFn[Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum] = Cp_EXTI_Cfg->IRQ_pCallBack;

		SET_BIT(EXTI->IMR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);

		/* Configure the NVIC to handle the interrupt */
		COR_NVIC_vSetPriorityCfg(Cp_EXTI_Cfg->EXTI_Priority.NVIC_GroupBits);
		COR_NVIC_vSetPriority(Cp_EXTI_Cfg->EXTI_PinMap.IVT_IRQNumber, Cp_EXTI_Cfg->EXTI_Priority.NVIC_GroupID,
		                      Cp_EXTI_Cfg->EXTI_Priority.NVIC_SubGroupID);
		COR_NVIC_vEnableInterrupt(Cp_EXTI_Cfg->EXTI_PinMap.IVT_IRQNumber);
	} else {
		//Update IRQ Handling Callback
		EXTI_gpCallBackFn[Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum] = NULL_PTR;

		CLEAR_BIT(EXTI->IMR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);
		COR_NVIC_vDisableInterrupt(Cp_EXTI_Cfg->EXTI_PinMap.IVT_IRQNumber);
	}

}

void MCL_EXTI_vEnable(EXTI_PinCfg_t *Cp_EXTI_Cfg, void (*Lc_pCallBackFn)(void)) {
	if (Lc_pCallBackFn != NULL_PTR)
		EXTI_gpCallBackFn[Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum] = Lc_pCallBackFn;

	MCL_EXTI_vInitGPIO(Cp_EXTI_Cfg->EXTI_PinMap.GPIO_Port, Cp_EXTI_Cfg->EXTI_PinMap.GPIO_Pin);

	//enable external interrupt request

	SET_BIT(EXTI->IMR, Cp_EXTI_Cfg->EXTI_PinMap.EXTI_LineNum);

}

void MCL_EXTI_vDisable(EXTI_Line_t Cp_xLineNo) {


	EXTI_gpCallBackFn[Cp_xLineNo] = NULL_PTR;

	CLEAR_BIT(EXTI->IMR, Cp_xLineNo);

}


void MCL_EXTI_vInitGPIO(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_EXTIPin) {
	//configure GPIO pin as AF input
	GPIO_CfgType Lc_GPIO_PinCfg;
	Lc_GPIO_PinCfg.GPIO_Mode = GPIO_MODE_AF_IN_PD;
	Lc_GPIO_PinCfg.GPIO_Pin = Cp_EXTIPin;
	MCL_GPIO_vSetPinCfg(GPIOx, &Lc_GPIO_PinCfg);
}

void EXTI0_IRQHandler(void) {
	//Clear EXTI Pending Register by writing 1 to clear
	if (GET_BIT(EXTI->PR, EXTI0)) {
		EXTI->PR |= 1 << EXTI0;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI0]();
	}
}

void EXTI1_IRQHandler(void) {
	//Clear EXTI Pending Register by writing 1 to clear
	if (GET_BIT(EXTI->PR, EXTI1)) {
		EXTI->PR |= 1 << EXTI1;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI1]();
	}
}

void EXTI2_IRQHandler(void) {
	if (GET_BIT(EXTI->PR, EXTI2)) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI2;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI2]();
	}
}

void EXTI3_IRQHandler(void) {
	//Clear EXTI Pending Register by writing 1 to clear
	EXTI->PR |= 1 << EXTI3;
	//Call IRQ Call back function
	EXTI_gpCallBackFn[EXTI3]();
}

void EXTI4_IRQHandler(void) {
	//Clear EXTI Pending Register by writing 1 to clear
	EXTI->PR |= 1 << EXTI4;
	//Call IRQ Call back function
	EXTI_gpCallBackFn[EXTI4]();
}

void EXTI9_5_IRQHandler(void) {
	if (EXTI->PR & 1 << EXTI5) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI5;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI5]();
	}
	if (EXTI->PR & 1 << EXTI6) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI6;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI6]();
	}
	if (EXTI->PR & 1 << EXTI7) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI7;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI7]();
	}
	if (EXTI->PR & 1 << EXTI8) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI8;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI8]();
	}
	if (EXTI->PR & 1 << EXTI9) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI9;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI9]();
	}
}

void EXTI15_10_IRQHandler(void) {
	if (EXTI->PR & 1 << EXTI10) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI10;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI10]();
	}
	if (EXTI->PR & 1 << EXTI11) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI11;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI11]();
	}
	if (EXTI->PR & 1 << EXTI12) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI12;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI12]();
	}
	if (EXTI->PR & 1 << EXTI13) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI13;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI13]();
	}
	if (EXTI->PR & 1 << EXTI14) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI14;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI14]();
	}
	if (EXTI->PR & 1 << EXTI15) {
		//Clear EXTI Pending Register by writing 1 to clear
		EXTI->PR |= 1 << EXTI15;
		//Call IRQ Call back function
		EXTI_gpCallBackFn[EXTI15]();
	}
}