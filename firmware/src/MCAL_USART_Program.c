#include "../inc/BIT_MATH.h"
#include "../inc/MCAL_USART_Private.h"
#include "../inc/MCAL_USART_Config.h"
#include "../inc/MCAL_USART_Interface.h"
#include "../inc/CORE_NVIC_Interface.h"

USART_CfgType *Global_USART_Config[2] = {NULL, NULL};

void MCL_USART_vInit(USART_TypeDef *USARTx, USART_CfgType *Cp_USART_Cfg) {
	/* Set USART GPIO Pins */
	MCL_USART_vSetGPIOPins(USARTx);
	u32 Lc_Pclk, Lc_BRReg;
	//enable USART clock
	if (USARTx == USART1) {
		RCC_USART1_CLOCK_EN();
		Global_USART_Config[USART1_INDEX] = Cp_USART_Cfg;
	} else if (USARTx == USART2) {
		RCC_USART2_CLOCK_EN();
		Global_USART_Config[USART2_INDEX] = Cp_USART_Cfg;
	} else if (USARTx == USART3) {
		RCC_USART3_CLOCK_EN();
		Global_USART_Config[USART3_INDEX] = Cp_USART_Cfg;
	}

	//enable USART send and receive
	//Bit 3 TE: Transmitter enable
	//Bit 2 RE: Receiver enable
	ASSIGN_PARAM(USARTx->CR1, Cp_USART_Cfg->USART_Mode);
	//select number of Stop Bits
	ASSIGN_PARAM(USARTx->CR1, Cp_USART_Cfg->StopBits);
	//enable or disable HW flow control modes
	ASSIGN_PARAM(USARTx->CR1, Cp_USART_Cfg->HWFlowCTRL);

	//configure USART communication baud rate
	if (USARTx == USART1)
		Lc_Pclk = MCL_RCC_GetPCLK2Freq();
	else
		Lc_Pclk = MCL_RCC_GetPCLK1Freq();
	Lc_BRReg = USART_u32CalcBRR(Lc_Pclk, Cp_USART_Cfg->BaudRate);
	USARTx->BRR = Lc_BRReg;

	//enable NVIC for USART IRQ
	if (Cp_USART_Cfg->IRQ_State != USART_IRQ_DISABLE) {
		ASSIGN_PARAM(USARTx->CR1, Cp_USART_Cfg->IRQ_State);

		if (USARTx == USART1) { COR_NVIC_vEnableInterrupt(USART1_IRQn); }
		else if ((USARTx == USART2)) { COR_NVIC_vEnableInterrupt(USART2_IRQn); }
	}

	//enable USART Module
	//Bit 13 UE: USART enable
	//When this bit is cleared the USART prescalers and outputs are stopped
	SET_BITFIELD(USARTx->CR1_Bits.UE);
}

void MCL_USART_vDeinit(USART_TypeDef *USARTx) {
	//reset USART & disable USART clock
	if (USARTx == USART1) {
		RCC_USART1_CLOCK_DIS();
	} else if (USARTx == USART2) {
		RCC_USART2_CLOCK_DIS();
	} else if (USARTx == USART3) {
		RCC_USART3_CLOCK_DIS();
	}
}

void MCL_USART_vSetGPIOPins(USART_TypeDef *USARTx) {

	GPIO_CfgType USART_PinConfig;

	USART_PinConfig.GPIO_Mode = GPIO_MODE_AF_PP;
	USART_PinConfig.GPIO_Speed = GPIO_SPEED_VERY_HIGH;

	if (USARTx == USART1) {
		//	USART1_TX  PA9
		USART_PinConfig.GPIO_Pin = GPIO_PIN9;
		MCL_GPIO_vSetPinCfg(GPIOA, &USART_PinConfig);
		//	USART1_RX  PA10
		USART_PinConfig.GPIO_Pin = GPIO_PIN10;

		MCL_GPIO_vSetPinCfg(GPIOA, &USART_PinConfig);
		if (Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS ||
		    Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS_RTS) {
			//	USART1_CTS PA11
			USART_PinConfig.GPIO_Pin = GPIO_PIN11;

			MCL_GPIO_vSetPinCfg(GPIOA, &USART_PinConfig);
		} else if (Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_RTS ||
		           Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS_RTS) {
			//	USART1_RTS PA12
			USART_PinConfig.GPIO_Pin = GPIO_PIN12;
			MCL_GPIO_vSetPinCfg(GPIOA, &USART_PinConfig);
		}
		MCL_GPIO_vSetPinAltFunc(GPIOA, USART_PinConfig.GPIO_Pin, GPIO_AF7_USART1_USART2_SPI1);

	}
	if (USARTx == USART2) {
		//	USART2_TX  PA2
		USART_PinConfig.GPIO_Pin = GPIO_PIN2;


		MCL_GPIO_vSetPinCfg(GPIOA, &USART_PinConfig);
		//	USART1_RX  PA3
		USART_PinConfig.GPIO_Pin = GPIO_PIN3;

		MCL_GPIO_vSetPinCfg(GPIOA, &USART_PinConfig);
		if (Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS ||
		    Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS_RTS) {
			//	USART2_CTS PA0
			USART_PinConfig.GPIO_Pin = GPIO_PIN0;
			MCL_GPIO_vSetPinCfg(GPIOA, &USART_PinConfig);
		} else if (Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_RTS ||
		           Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS_RTS) {
			//	USART2_RTS PA1
			USART_PinConfig.GPIO_Pin = GPIO_PIN1;
			MCL_GPIO_vSetPinCfg(GPIOA, &USART_PinConfig);
		}
		MCL_GPIO_vSetPinAltFunc(GPIOA, USART_PinConfig.GPIO_Pin, GPIO_AF7_USART1_USART2_SPI1);

	}
	if (USARTx == USART3) {
		//	USART3_TX  PB10
		USART_PinConfig.GPIO_Pin = GPIO_PIN10;


		MCL_GPIO_vSetPinCfg(GPIOB, &USART_PinConfig);
		//	USART3_RX  PA11
		USART_PinConfig.GPIO_Pin = GPIO_PIN11;

		MCL_GPIO_vSetPinCfg(GPIOB, &USART_PinConfig);
		if (Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS ||
		    Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS_RTS) {
			//	USART3_CTS PA13
			USART_PinConfig.GPIO_Pin = GPIO_PIN13;
			MCL_GPIO_vSetPinCfg(GPIOB, &USART_PinConfig);
		} else if (Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_RTS ||
		           Global_USART_Config[USART_xSelectIndex(USARTx)]->HWFlowCTRL == USART_HWFLOWCTRL_CTS_RTS) {
			//	USART3_RTS PA14
			USART_PinConfig.GPIO_Pin = GPIO_PIN14;
			MCL_GPIO_vSetPinCfg(GPIOB, &USART_PinConfig);
		}
		MCL_GPIO_vSetPinAltFunc(GPIOB, USART_PinConfig.GPIO_Pin, GPIO_AF8_USART6_SPI3_I2S3);

	}
}

void MCL_USART_vTransmitData(USART_TypeDef *USARTx, u16 *Cp_pTxBuffer, Polling_Mechanism_t Cp_PollingState) {
	//Bit 7 TXE: Transmit data register empty
	//wait until TXE Lc_EventFlag is set
	if (Cp_PollingState == USART_POLLING_ENABLE)
		while (!(USARTx->SR_Bits.TXE));

	if (Global_USART_Config[USART_xSelectIndex(USARTx)]->Payload_Length == USART_PAYLOAD_LENGTH_9B) {
		USARTx->DR = (*Cp_pTxBuffer & (u16) 0x1FF);
	} else {
		// USART_Payload_Length_8B
		USARTx->DR = (*Cp_pTxBuffer & (u8) 0xFF);
	}
}

void MCL_USART_vReceiveData(USART_TypeDef *USARTx, u16 *Cp_pRxBuffer, Polling_Mechanism_t Cp_PollingState) {

	//Bit 5 RXNE:  Read data register not empty
	//wait until RXNE Lc_EventFlag is set : Received data is ready to be read.
	if (Cp_PollingState == USART_POLLING_ENABLE)
		while (!(USARTx->SR_Bits.RXNE));

	if (Global_USART_Config[USART_xSelectIndex(USARTx)]->Payload_Length == USART_PAYLOAD_LENGTH_9B) {
		if (Global_USART_Config[USART_xSelectIndex(USARTx)]->Parity == USART_NONE_PARITY) {
			//no parity so all 9bit are considered data
			*((u16 *) Cp_pRxBuffer) = USARTx->DR;
		} else {
			//parity is used, 8bit is data bits and 1 bit is parity
			*((u16 *) Cp_pRxBuffer) = (USARTx->DR & (u8) 0xFF);
		}

	} else {
		//this is 8bit data
		if (Global_USART_Config[USART_xSelectIndex(USARTx)]->Parity == USART_NONE_PARITY) {
			*((u16 *) Cp_pRxBuffer) = (USARTx->DR & (u8) 0xFF);

		} else {
			//parity is used, 7 bits are only the data bits
			*((u16 *) Cp_pRxBuffer) = (USARTx->DR & (u8) 0x7F);
		}
	}
}


static USART_Index_t USART_xSelectIndex(USART_TypeDef *USARTx) {

	USART_Index_t Lc_UsartIndex;
	if (USARTx == USART1) { Lc_UsartIndex = USART1_INDEX; }
	else if (USARTx == USART2)
		Lc_UsartIndex = USART2_INDEX;
	else if (USARTx == USART3)
		Lc_UsartIndex = USART3_INDEX;
	else
		Lc_UsartIndex = USART1_INDEX;

	return ((USART_Index_t) (Lc_UsartIndex));

}

static u32 USART_u32CalcBRR(u32 Cp_Pclk, u32 Cp_BaudRate) {
	u32 Lc_DivisorFraction = 25U * Cp_Pclk / (2U * Cp_BaudRate);
	u32 Lc_Mantissa = (Lc_DivisorFraction / 100U);
	u32 Lc_Fraction = ((((Lc_DivisorFraction - (Lc_Mantissa * 100U)) * 8U) + 50U) / 100U);  // Round up fraction
	return (Lc_Mantissa << 4U) | (Lc_Fraction & 0xF);
}

void USART1_IRQHandler(void) {
	USART_IRQEvent_t Lc_EventFlag;
	//transmit data register empty
	if (USART1->SR & 1 << 7)
		Lc_EventFlag = USART_IRQ_TXE;
		//Transmission complete
	else if (USART1->SR & 1 << 6) {
		Lc_EventFlag = USART_IRQ_TC;
		USART1->SR = ~(1 << 6);
	}
		//received data ready to be read
	else if (USART1->SR & 1 << 5) {
		Lc_EventFlag = USART_IRQ_RXNE;
		USART1->SR = ~(1 << 5);
	}
		//overrun error detected
	else if (USART1->SR & 1 << 3) {
		Lc_EventFlag = USART_IRQ_ORE;
	}
		//Parity error
	else if (USART1->SR & 1 << 0) {
		Lc_EventFlag = USART_IRQ_PE;
	}
	Global_USART_Config[USART1_INDEX]->P_IRQ_CallBack(Lc_EventFlag);
}

void USART2_IRQHandler() {
	USART_IRQEvent_t Lc_EventFlag;
	//transmit data register empty
	if (USART2->SR & 1 << 7)
		Lc_EventFlag = USART_IRQ_TXE;
		//Transmission complete
	else if (USART2->SR & 1 << 6) {
		Lc_EventFlag = USART_IRQ_TC;
		USART2->SR = ~(1 << 6);
	}
		//received data ready to be read
	else if (USART2->SR & 1 << 5) {
		Lc_EventFlag = USART_IRQ_RXNE;
		USART2->SR = ~(1 << 5);
	}
		//overrun error detected
	else if (USART2->SR & 1 << 3) {
		Lc_EventFlag = USART_IRQ_ORE;
	}
		//Parity error
	else if (USART2->SR & 1 << 0) {
		Lc_EventFlag = USART_IRQ_PE;
	}
	Global_USART_Config[USART2_INDEX]->P_IRQ_CallBack(Lc_EventFlag);
}

void USART3_IRQHandler() {
	USART_IRQEvent_t Lc_EventFlag;
	//transmit data register empty
	if (USART3->SR & 1 << 7)
		Lc_EventFlag = USART_IRQ_TXE;
		//Transmission complete
	else if (USART3->SR & 1 << 6) {
		Lc_EventFlag = USART_IRQ_TC;
		USART3->SR = ~(1 << 6);
	}
		//received data ready to be read
	else if (USART3->SR & 1 << 5) {
		Lc_EventFlag = USART_IRQ_RXNE;
		USART3->SR = ~(1 << 5);
	}
		//overrun error detected
	else if (USART3->SR & 1 << 3) {
		Lc_EventFlag = USART_IRQ_ORE;
	}
		//Parity error
	else if (USART3->SR & 1 << 0) {
		Lc_EventFlag = USART_IRQ_PE;
	}
	Global_USART_Config[USART3_INDEX]->P_IRQ_CallBack(Lc_EventFlag);
}