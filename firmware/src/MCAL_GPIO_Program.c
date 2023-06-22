#include "../inc/BIT_MATH.h"
#include "../inc/MCAL_GPIO_Interface.h"
#include "../inc/MCAL_GPIO_Config.h"
#include "../inc/MCAL_GPIO_Private.h"
#include "../inc/MCAL_RCC_Interface.h"

void MCL_GPIO_vInitPort(GPIO_TypeDef *GPIOx, GPIO_CfgType *Cp_GPIO_Cfg) {
	/* Enable RCC GPIO port clock. */
	MCL_RCC_vEnablePeriphClk(AHB1_BUS, GPIO_xSelectPortIndex(GPIOx));

	/* 1. Configure the GPIO port. */
	for (u8 Local_u8PinId = GPIO_PIN0; Local_u8PinId <= GPIO_PIN15; Local_u8PinId++)
		ASSIGN_BITS(GPIOx->GPIO_MODER, (Local_u8PinId * TWO_BITS), TWO_BITS, Cp_GPIO_Cfg->GPIO_Mode);

	/* 2. Configure the GPIO pull-up/pull-down. */
	if (Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_IN_FLOAT || Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_IN_PU ||
	    Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_IN_PD || Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_AF_IN_PU ||
	    Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_AF_IN_PD) {
		for (u8 Local_u8PinId = GPIO_PIN0; Local_u8PinId <= GPIO_PIN15; Local_u8PinId++)
			ASSIGN_BITS(GPIOx->GPIO_PUPDR, (Local_u8PinId * TWO_BITS), TWO_BITS, Cp_GPIO_Cfg->GPIO_Mode >> THREE_BITS);
	}
		/* 3. Configure the GPIO output. */
		/* 4.  Configure the GPIO output speed. */
		/* Check mode is output */
	else if (Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_OUT_PP || Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_OUT_OD ||
	         Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_AF_OUT_OD || Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_AF_PP) {
		for (u8 Local_u8PinId = GPIO_PIN0; Local_u8PinId <= GPIO_PIN15; Local_u8PinId++) {
			ASSIGN_BITS(GPIOx->GPIO_OTYPER, Local_u8PinId, ONE_BIT, Cp_GPIO_Cfg->GPIO_Mode >> TWO_BITS);
			ASSIGN_BITS(GPIOx->GPIO_OSPEEDR, (Local_u8PinId * TWO_BITS), TWO_BITS, Cp_GPIO_Cfg->GPIO_Speed);
		}
	}
}

void MCL_GPIO_vSetPinMode(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_GPIO_Pin, GPIO_Mode_t Cp_GPIO_Mode,
                          GPIO_Speed_t Cp_GPIO_Speed) {

	MCL_RCC_vEnablePeriphClk(AHB1_BUS, GPIO_xSelectPortIndex(GPIOx));
	/* 1. Configure the GPIO port. */
	ASSIGN_BITS(GPIOx->GPIO_MODER, (Cp_GPIO_Pin * TWO_BITS), TWO_BITS, Cp_GPIO_Mode);
	/* 2. Configure the GPIO pull-up/pull-down. */
	if (Cp_GPIO_Mode == GPIO_MODE_IN_FLOAT || Cp_GPIO_Mode == GPIO_MODE_IN_PU || Cp_GPIO_Mode == GPIO_MODE_IN_PD ||
	    Cp_GPIO_Mode == GPIO_MODE_AF_IN_PU || Cp_GPIO_Mode == GPIO_MODE_AF_IN_PD) {
		ASSIGN_BITS(GPIOx->GPIO_PUPDR, (Cp_GPIO_Pin * TWO_BITS), TWO_BITS, Cp_GPIO_Mode >> THREE_BITS);
	}
		/* 3. Configure the GPIO output. */
		/* 4.  Configure the GPIO output speed. */
		/* Check mode is output */
	else if (Cp_GPIO_Mode == GPIO_MODE_OUT_PP || Cp_GPIO_Mode == GPIO_MODE_OUT_OD ||
	         Cp_GPIO_Mode == GPIO_MODE_AF_OUT_OD || Cp_GPIO_Mode == GPIO_MODE_AF_PP) {

		ASSIGN_BITS(GPIOx->GPIO_OTYPER, Cp_GPIO_Pin, ONE_BIT, Cp_GPIO_Mode >> TWO_BITS);
		ASSIGN_BITS(GPIOx->GPIO_OSPEEDR, (Cp_GPIO_Pin * TWO_BITS), TWO_BITS, Cp_GPIO_Speed);
	}
}

void MCL_GPIO_vSetPinCfg(GPIO_TypeDef *GPIOx, GPIO_CfgType *Cp_GPIO_Cfg) {

	MCL_RCC_vEnablePeriphClk(AHB1_BUS, GPIO_xSelectPortIndex(GPIOx));
	/* 1. Configure the GPIO port. */
	ASSIGN_BITS(GPIOx->GPIO_MODER, (Cp_GPIO_Cfg->GPIO_Pin * TWO_BITS), TWO_BITS, Cp_GPIO_Cfg->GPIO_Mode);
	/* 2. Configure the GPIO pull-up/pull-down. */
	if (Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_IN_FLOAT || Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_IN_PU ||
	    Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_IN_PD || Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_AF_IN_PU ||
	    Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_AF_IN_PD) {
		ASSIGN_BITS(GPIOx->GPIO_PUPDR, (Cp_GPIO_Cfg->GPIO_Pin * TWO_BITS), TWO_BITS,
		            Cp_GPIO_Cfg->GPIO_Mode >> THREE_BITS);
	}
		/* 3. Configure the GPIO output. */
		/* 4.  Configure the GPIO output speed. */
		/* Check mode is output */
	else if (Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_OUT_PP || Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_OUT_OD ||
	         Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_AF_OUT_OD || Cp_GPIO_Cfg->GPIO_Mode == GPIO_MODE_AF_PP) {

		ASSIGN_BITS(GPIOx->GPIO_OTYPER, Cp_GPIO_Cfg->GPIO_Pin, ONE_BIT, Cp_GPIO_Cfg->GPIO_Mode >> TWO_BITS);
		ASSIGN_BITS(GPIOx->GPIO_OSPEEDR, (Cp_GPIO_Cfg->GPIO_Pin * TWO_BITS), TWO_BITS, Cp_GPIO_Cfg->GPIO_Speed);
	}
}

void MCL_GPIO_vSetPinAltFunc(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId, GPIO_AF_TypeDef Cp_AltFunc) {
	// AFR[0] - Alternate function Low register
	// AFR[1] - Alternate function High register
	if (Cp_PinId <= 7) {
		GPIOx->GPIO_AFR[0] |= (Cp_AltFunc << (4 * Cp_PinId));
	} else {
		GPIOx->GPIO_AFR[1] |= (Cp_AltFunc << (4 * (Cp_PinId % 8)));
	}
}

void MCL_GPIO_vAtomicSetPin(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId, Pin_State_t Cp_xPinVal) {
	if (Cp_PinId < GPIO_PIN0 && Cp_PinId > GPIO_PIN15) {
		/* Do nothing */
	} else {
		switch (Cp_xPinVal) {
			case PIN_SET:
				ASSIGN_BIT(GPIOx->GPIO_BSRR_Bits.BS, Cp_PinId, PIN_SET);
				break;
			case PIN_RESET:
				ASSIGN_BIT(GPIOx->GPIO_BSRR_Bits.BR, Cp_PinId, PIN_SET);
				break;
			default:
				break;
		}
	}
}

void MCL_GPIO_vWritePins(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_u8StPin, u8 Cp_u8Length, u8 Cp_u8Value) {

	/* input validation */
	if (GPIOx > GPIOC) {
		// Do nothing input is not valid
	} else {

		ASSIGN_BITS(GPIOx->GPIO_ODR, Cp_u8StPin, Cp_u8Length, Cp_u8Value);
	}
}

void MCL_GPIO_vTogglePin(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId) {
	if (Cp_PinId < GPIO_PIN0 && Cp_PinId > GPIO_PIN15) {
		/* Do nothing */
	} else {
		TOGGLE_BIT(GPIOx->GPIO_ODR, Cp_PinId);
	}
}

u8 MCL_GPIO_u8GetPinVal(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId) {
	if (Cp_PinId < GPIO_PIN0 && Cp_PinId > GPIO_PIN15) {
		return -1;
	} else {
		return (GET_BIT(GPIOx->GPIO_IDR, Cp_PinId));
	}
}

void MCL_GPIO_vWritePort(GPIO_TypeDef *GPIOx, u32 Cp_u32PortVal) {
	WRITE_REG(GPIOx->GPIO_ODR, Cp_u32PortVal);
}

u32 MCL_GPIO_u32ReadPort(GPIO_TypeDef *GPIOx) {
	return READ_REG(GPIOx->GPIO_IDR);
}

GPIO_Port_t GPIO_xSelectPortIndex(GPIO_TypeDef *GPIOx) {
	u32 Local_PortOffset = 0;
	Local_PortOffset = (u32) ((u32) GPIOx - (u32) GPIOA);
	return ((GPIO_Port_t) (Local_PortOffset / 0x400));
}

GPIO_TypeDef *GPIO_xSelectReg(GPIO_Port_t GPIO_PortIndex) {
	GPIO_TypeDef *Local_PortReg;
	switch (GPIO_PortIndex) {
		case GPIO_PORTA:
			Local_PortReg = GPIOA;
			break;
		case GPIO_PORTB:
			Local_PortReg = GPIOB;
			break;
		case GPIO_PORTC:
			Local_PortReg = GPIOC;
			break;
		default:
			Local_PortReg = GPIOA;
			break;
	}
	return (GPIO_TypeDef *) (Local_PortReg);
}