#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"
#include "../inc/MCAL_TIM_Interface.h"
#include "../inc/MCAL_TIM_Config.h"
#include "../inc/MCAL_TIM_Private.h"
#include "../inc/CORE_NVIC_Interface.h"
#include "../inc/MCAL_GPIO_Interface.h"

void (*Global_TIMCallBackPtr[2])(void) = {NULL_PTR, NULL_PTR};

void TIM_vInit(TIM_HandleTypeDef *htim) {
	u32 tmpcr1 = htim->Instance->CR1;
	u32 tmpccmr1 = htim->Instance->CCMR1;
	u32 tmpccer = htim->Instance->CCER;
	u32 tmpdier = htim->Instance->DIER;
	// Enable timer clock
	if (htim->Instance == TIM1) {
		RCC_TIM1_CLOCK_EN();
	} else if (htim->Instance == TIM2) {
		RCC_TIM2_CLOCK_EN();
	} else if (htim->Instance == TIM3) {
		RCC_TIM3_CLOCK_EN();
	} else if (htim->Instance == TIM4) {
		RCC_TIM4_CLOCK_EN();
	}
	// Clear timer mode and clock division ratio bits
	tmpcr1 &= ~(TIM_CR1_CMS_Msk | TIM_CR1_CKD_Msk);

	// Set timer mode and clock division ratio
	tmpcr1 |= (htim->Init.TIM_ClockDiv << TIM_CR1_CKD_Pos) | TIM_CR1_CEN;


	// Set timer prescaler
	htim->Instance->PSC = htim->Init.TIM_Prescaler;
	// Set timer period
	htim->Instance->ARR = htim->Init.TIM_Period;

	// Set timer IRQ
	if (htim->Init.TIM_INT != TIM_INT_DISABLE) {
		tmpdier |= htim->Init.TIM_INT;
		if (htim->Instance == TIM2) {
			COR_NVIC_vSetPriority(TIM2_IRQn, 0, 0);
			COR_NVIC_vEnableInterrupt(TIM2_IRQn);
		} else if (htim->Instance == TIM3) {
			COR_NVIC_vSetPriority(TIM3_IRQn, 1, 0);
			COR_NVIC_vEnableInterrupt(TIM3_IRQn);
		} else if (htim->Instance == TIM4) {
			COR_NVIC_vSetPriority(TIM4_IRQn, 2, 0);
			COR_NVIC_vEnableInterrupt(TIM4_IRQn);
		}
	}

	// Apply the configuration
	htim->Instance->CR1 = tmpcr1;
	htim->Instance->CCMR1 = tmpccmr1;
	htim->Instance->CCER = tmpccer;
	htim->Instance->DIER = tmpdier;
}

void TIM_IC_vInit(TIM_HandleTypeDef *htim, TIM_IC_CfgType *ic_config) {
	GPIO_CfgType GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_SPEED_LOW;

	if (htim->Instance == TIM1) {
	} else if (htim->Instance == TIM2) {

		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PA0 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN0;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			/* Configure PA1 as an alternate function output for channel 2*/
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN1;
		}
		MCL_GPIO_vSetPinCfg(GPIOA, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOA, GPIO_InitStruct.GPIO_Pin, GPIO_AF1_TIM1_TIM2);
	} else if (htim->Instance == TIM3) {

		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PA6 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN6;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			/* Configure PA7 as an alternate function output for channel 2*/
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN7;
		}
		MCL_GPIO_vSetPinCfg(GPIOA, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOA, GPIO_InitStruct.GPIO_Pin, GPIO_AF2_TIM3_TIM4);

	} else if (htim->Instance == TIM4) {
		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PB6 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN6;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			// Configure PB7 as an alternate function output for channel 2
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN7;
		}
		MCL_GPIO_vSetPinCfg(GPIOB, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOB, GPIO_InitStruct.GPIO_Pin, GPIO_AF2_TIM3_TIM4);

	}
	//htim->Instance->CR1 = TIM_CR1_ARPE;              /*!< TIMx_ARR register is buffered */
	u8 ccmr_offset = (ic_config->IC_Channel - 1) * 8;
	// Configure the timer peripheral for input capture mode
	htim->Instance->CCMR1 &= ~(TIM_CCMR1_CC1S_Msk << (TIM_CCMR1_CC1S_Pos << ccmr_offset));
	htim->Instance->CCMR1 |= ic_config->IC_Selection << (TIM_CCMR1_CC1S_Pos << ccmr_offset);
	htim->Instance->CCER |=
			TIM_CCER_CC1P | (TIM_CCER_CC1E << ((ic_config->IC_Channel - 1) * 4)); // Capture on falling edge

	// Configure the timer peripheral prescaler and period
	htim->Instance->PSC = ic_config->IC_Prescaler - 1;
	htim->Instance->ARR = ic_config->IC_Period - 1;
}

void TIM_PWM_vInit(TIM_HandleTypeDef *htim, u32 Cp_Period) {
	GPIO_CfgType GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_SPEED_HIGH;

	if (htim->Instance == TIM1) {
		RCC_TIM1_CLOCK_EN();
	} else if (htim->Instance == TIM2) {
		RCC_TIM2_CLOCK_EN();
		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PA0 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN0;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			/* Configure PA1 as an alternate function output for channel 2*/
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN1;
		}
		MCL_GPIO_vSetPinCfg(GPIOA, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOA, GPIO_InitStruct.GPIO_Pin, GPIO_AF1_TIM1_TIM2);
	} else if (htim->Instance == TIM3) {
		RCC_TIM3_CLOCK_EN();

		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PA6 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN6;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			/* Configure PA7 as an alternate function output for channel 2*/
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN7;
		}
		MCL_GPIO_vSetPinCfg(GPIOA, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOA, GPIO_InitStruct.GPIO_Pin, GPIO_AF2_TIM3_TIM4);

	} else if (htim->Instance == TIM4) {
		RCC_TIM4_CLOCK_EN();
		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PB6 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN6;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			// Configure PB7 as an alternate function output for channel 2
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN7;
		}
		MCL_GPIO_vSetPinCfg(GPIOB, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOB, GPIO_InitStruct.GPIO_Pin, GPIO_AF2_TIM3_TIM4);

	}

	// Configure the timer peripheral for PWM output
	u8 ccmr_offset = (htim->Channel - 1) * 8;
	htim->Instance->CCMR1 &= ~(TIM_CCMR1_CC1S_Msk << ccmr_offset);
	htim->Instance->CCMR1 |= (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2) << ccmr_offset; // PWM mode 1
	htim->Instance->CCMR1 |= (TIM_CCMR1_OC1PE) << ccmr_offset; // PWM mode 1
	htim->Instance->CCER |= TIM_CCER_CC1E << ((htim->Channel - 1) * 4); // Enable output

	// Configure the timer peripheral prescaler and period
	htim->Instance->PSC = htim->Init.TIM_Prescaler;
	htim->Instance->ARR = Cp_Period - 1;

	// Enable the timer peripheral
	htim->Instance->CR1 |= TIM_CR1_CEN;
}

void TIM_PWM_Out_vInit(TIM_HandleTypeDef *htim, u32 Cp_Period, u8 Cp_DutyCycle) {
	GPIO_CfgType GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_SPEED_HIGH;

	if (htim->Instance == TIM1) {
		RCC_TIM1_CLOCK_EN();
	} else if (htim->Instance == TIM2) {
		RCC_TIM2_CLOCK_EN();
		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PA0 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN0;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			/* Configure PA1 as an alternate function output for channel 2*/
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN1;
		}
		MCL_GPIO_vSetPinCfg(GPIOA, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOA, GPIO_InitStruct.GPIO_Pin, GPIO_AF1_TIM1_TIM2);
	} else if (htim->Instance == TIM3) {
		RCC_TIM3_CLOCK_EN();

		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PA6 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN6;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			/* Configure PA7 as an alternate function output for channel 2*/
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN7;
		}
		MCL_GPIO_vSetPinCfg(GPIOA, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOA, GPIO_InitStruct.GPIO_Pin, GPIO_AF2_TIM3_TIM4);

	} else if (htim->Instance == TIM4) {
		RCC_TIM4_CLOCK_EN();
		if (htim->Channel == TIM_CHANNEL_1) {
			// Configure PB6 as an alternate function output for channel 1
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN6;
		} else if (htim->Channel == TIM_CHANNEL_2) {
			// Configure PB7 as an alternate function output for channel 2
			GPIO_InitStruct.GPIO_Pin = GPIO_PIN7;
		}
		MCL_GPIO_vSetPinCfg(GPIOB, &GPIO_InitStruct);
		MCL_GPIO_vSetPinAltFunc(GPIOB, GPIO_InitStruct.GPIO_Pin, GPIO_AF2_TIM3_TIM4);

	}

	// Configure the timer peripheral for PWM output
	u8 ccmr_offset = (htim->Channel - 1) * 8;
	htim->Instance->CCMR1 &= ~(TIM_CCMR1_CC1S_Msk << ccmr_offset);
	htim->Instance->CCMR1 |= (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2) << ccmr_offset; // PWM mode 1
	htim->Instance->CCMR1 |= (TIM_CCMR1_OC1PE) << ccmr_offset; // PWM mode 1
	htim->Instance->CCER |= TIM_CCER_CC1E << ((htim->Channel - 1) * 4); // Enable output

	// Configure the timer peripheral prescaler and period
	htim->Instance->PSC = htim->Init.TIM_Prescaler;
	htim->Instance->ARR = Cp_Period - 1;

	// Configure the pulse width
	TIM_PWM_SetDutyCycle(htim, Cp_DutyCycle);

	// Enable the timer peripheral
	htim->Instance->CR1 |= TIM_CR1_CEN;
}


void TIM_PWM_SetDutyCycle(TIM_HandleTypeDef *htim, u8 Cp_DutyCycle) {
	// Calculate the compare register value for the desired duty cycle
	u16 ccr_value = (Cp_DutyCycle * (htim->Instance->ARR + 1)) / 100;

	// Set the compare register for the selected channel
	switch (htim->Channel) {
		case TIM_CHANNEL_1: {    /* Return the capture 1 value */     htim->Instance->CCR1 = ccr_value;
			break;
		}

		case TIM_CHANNEL_2: {    /* Return the capture 2 value */      htim->Instance->CCR2 = ccr_value;
			break;
		}

		case TIM_CHANNEL_3: {/* Return the capture 3 value */          htim->Instance->CCR3 = ccr_value;
			break;
		}

		case TIM_CHANNEL_4: {/* Return the capture 4 value */          htim->Instance->CCR4 = ccr_value;
			break;
		}

		default:
			break;
	}

}

void TIM_vEnableINT(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT) {
	// Calculate the bit offset for the channel

	htim->Instance->DIER |= Cp_TIM_INT;
}

void TIM_vDisableINT(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT) {
	htim->Instance->DIER &= ~Cp_TIM_INT;
}

STD_Status TIM_xCheckINTSrc(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT) {
	if ((htim->Instance->DIER & Cp_TIM_INT) != 0)
		return SET;
	else
		return RESET;
}

void TIM_vClearFlag(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT) { (htim->Instance->SR &= ~Cp_TIM_INT); }

STD_Status TIM_xCheckINTFlag(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT) {
	if ((htim->Instance->SR & Cp_TIM_INT) != 0)
		return SET;
	else
		return RESET;
}

void TIM_vStart(TIM_HandleTypeDef *htim) {


	// Clear overflow flag
	htim->Instance->SR &= ~(TIM_SR_UIF);

	if (htim->Init.TIM_Mode == TIM_MODE_PWM) {
		// Enable PWM output for the specified channel

	} else if (htim->Init.TIM_Mode == TIM_MODE_INPUT_CAPTURE) {
		htim->Instance->SR &= ~(TIM_SR_CC1IF | TIM_SR_CC1OF);
		htim->Instance->DIER |= TIM_DIER_UIE | (TIM_DIER_CC1IE << (htim->Channel - 1));

	} else if (htim->Init.TIM_Mode == TIM_MODE_OUTPUT_COMPARE) {
		// Set timer pulse
		TIM_vSetCompareVal(htim, htim->Channel, htim->Init.TIM_Pulse);

		// Clear input capture flags
		htim->Instance->SR &= ~(TIM_SR_CC1IF | TIM_SR_CC1OF);
		// Enable output compare mode for the specified channel
		htim->Instance->DIER |= TIM_DIER_UIE | (TIM_DIER_CC1IE << (htim->Channel - 1));
	} else if (htim->Init.TIM_Mode == TIM_MODE_TIMING) {
		// Configure the timer mode
		htim->Instance->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS); // Clear the direction and center-aligned mode bits
		htim->Instance->CR1 |= htim->Init.TIM_CounterMode << TIM_CR1_DIR_Pos; // Set the up-counting mode

	}

	// Clear the counter and update flags
	htim->Instance->CNT = 0;
	// Enable timer counter
	htim->Instance->CR1 |= TIM_CR1_CEN;
}


void TIM_vStop(TIM_HandleTypeDef *htim) {
	// Stop the timer
	htim->Instance->CR1 &= ~TIM_CR1_CEN;
	htim->Instance->CNT = 0;
	TIM_vDisableINT(htim, htim->Init.TIM_INT);
	TIM_vClearFlag(htim, htim->Init.TIM_INT);
	switch (htim->Init.TIM_Mode) {
		case TIM_MODE_INPUT_CAPTURE:
			// Clear input capture flags
			htim->Instance->SR &= ~(TIM_SR_CC1IF | TIM_SR_CC1OF);
			break;

		default:
			break;
	}
}

u32 TIM_u32GetTimeElapsed(TIM_TypeDef *TIMx) {
	return TIMx->CNT;
}

u32 TIM_u32GetTimeRemaining(TIM_TypeDef *TIMx) {
	return TIMx->ARR - TIMx->CNT;
}

u32 TIM_u32ReadCapturedVal(TIM_HandleTypeDef *htim, u8 Channel) {
	u32 tmpreg = 0U;

	switch (Channel) {
		case TIM_CHANNEL_1: {    /* Return the capture 1 value */    tmpreg = htim->Instance->CCR1;
			break;
		}

		case TIM_CHANNEL_2: {    /* Return the capture 2 value */    tmpreg = htim->Instance->CCR2;
			break;
		}

		case TIM_CHANNEL_3: {/* Return the capture 3 value */        tmpreg = htim->Instance->CCR3;
			break;
		}

		case TIM_CHANNEL_4: {/* Return the capture 4 value */        tmpreg = htim->Instance->CCR4;
			break;
		}

		default:
			break;
	}

	return tmpreg;
}

void TIM_vSetCompareVal(TIM_HandleTypeDef *htim, TIM_Channel_t Channel, u32 Compare_Value) {


	switch (Channel) {
		case TIM_CHANNEL_1: {    /* Return the capture 1 value */     htim->Instance->CCR1 = Compare_Value;
			break;
		}

		case TIM_CHANNEL_2: {    /* Return the capture 2 value */      htim->Instance->CCR2 = Compare_Value;
			break;
		}

		case TIM_CHANNEL_3: {/* Return the capture 3 value */          htim->Instance->CCR3 = Compare_Value;
			break;
		}

		case TIM_CHANNEL_4: {/* Return the capture 4 value */          htim->Instance->CCR4 = Compare_Value;
			break;
		}

		default:
			break;
	}

}

void TIM_vSetClkPolarity(TIM_HandleTypeDef *TMR_Handle, TIM_Channel_t TIM_Channel, TIM_ClkPol_t polarity) {
	u8 ccer_offset = ((TMR_Handle->Channel - 1) * 4);

	if (polarity == TIM_CLOCKPOLARITY_RISING) {
		TMR_Handle->Instance->CCER &= ~(TIM_CCER_CC1P << ccer_offset);
	} else if (polarity == TIM_CLOCKPOLARITY_FALLING) {
		TMR_Handle->Instance->CCER |= TIM_CCER_CC1P << ccer_offset;
	} else if (polarity == TIM_CLOCKPOLARITY_BOTHEDGE) {
		TMR_Handle->Instance->CCER |= TIM_CCER_CC1P << ccer_offset;
		TMR_Handle->Instance->CCER |= TIM_CCER_CC1NP << ccer_offset;
	}

}

TIM_Channel_t TIM_GetChannelID(TIM_TypeDef *TIMx) {
	u8 Lc_TIM_ID;

#if defined(TIM1)
	if (TIMx == TIM1) {
		Lc_TIM_ID = TIM_CHANNEL_1;
	}
#endif

#if defined(TIM2)
	if (TIMx == TIM2) {
		Lc_TIM_ID = TIM_CHANNEL_2;
	}
#endif

#if defined(TIM3)
	if (TIMx == TIM3) {
		Lc_TIM_ID = TIM_CHANNEL_3;
	}
#endif
#if defined(TIM4)
	if (TIMx == TIM4) {
		Lc_TIM_ID = TIM_CHANNEL_4;
	}
#endif

	// Add more #if defined(TIMx) blocks for additional timers

	return Lc_TIM_ID;
}

void TIM_voidCapture_Compare_Init(TIM_TypeDef *TIMx) {
	/*DIER Register*/

	// Enable timer clock
	if (TIMx == TIM1) {
		RCC_TIM1_CLOCK_EN();
	} else if (TIMx == TIM2) {
		RCC_TIM2_CLOCK_EN();
	} else if (TIMx == TIM3) {
		RCC_TIM3_CLOCK_EN();
	} else if (TIMx == TIM4) {
		RCC_TIM4_CLOCK_EN();
	}
	GPIO_CfgType GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_MODE_AF_IN_PU;
	GPIO_InitStruct.GPIO_Speed = GPIO_SPEED_LOW;
	GPIO_InitStruct.GPIO_Pin = GPIO_PIN0;

	MCL_GPIO_vSetPinCfg(GPIOA, &GPIO_InitStruct);
	MCL_GPIO_vSetPinAltFunc(GPIOA, GPIO_InitStruct.GPIO_Pin, GPIO_AF1_TIM1_TIM2);
	// Configure Timer 2 channel 1 for input capture
	TIM2->CCMR1 |= TIM_CCMR1_CC1S_0;
	TIM2->CCER |= TIM_CCER_CC1E;

	// Enable capture interrupt for Timer 2 channel 1
	TIM2->DIER |= TIM_DIER_CC1IE;

	// Set interrupt priority for Timer 2 channel 1
	COR_NVIC_vSetPriority(TIM2_IRQn, 0, 0);

	SET_BIT(TIMx->DIER, 1);    // Capture/Compare interrupt enable

	/*CCMR1 Register*/

	SET_BIT(TIMx->CCMR1, 0);    // configure timer3 ch1 as input
	CLEAR_BIT(TIMx->CCMR1, 1);

	CLEAR_BIT(TIMx->CCMR1, 2);    // configure timer3 ch1 to capture at every edge detected
	CLEAR_BIT(TIMx->CCMR1, 3);


	CLEAR_BIT(TIMx->CCMR1, 6);
	CLEAR_BIT(TIMx->CCMR1, 7);

	/*CCER Register*/

	SET_BIT(TIMx->CCER, 0);    // Capture Enabled


	SET_BIT(TIMx->CCER, 1);    // Capture/Compare channel captures on both edges (rising & falling)
	SET_BIT(TIMx->CCER, 3);

	TIMx->PSC = (72);

	TIMx->ARR = 65535;


	SET_BIT(TIMx->CR1, 0);        // enable counter

	CLEAR_BIT(TIMx->CR1, 4);        // counter mode is up counting

}

void TIM_vInitCounter(TIM_HandleTypeDef *htim) {
	// Enable timer clock
	if (htim->Instance == TIM1) {
		RCC_TIM1_CLOCK_EN();
	} else if (htim->Instance == TIM2) {
		RCC_TIM2_CLOCK_EN();
	} else if (htim->Instance == TIM3) {
		RCC_TIM3_CLOCK_EN();
	} else if (htim->Instance == TIM4) {
		RCC_TIM4_CLOCK_EN();
	}

	// Disable the timer
	htim->Instance->CR1 &= ~TIM_CR1_CEN;

	// Set the prescaler and period
	htim->Instance->PSC = htim->Init.TIM_Prescaler;
	htim->Instance->ARR = htim->Init.TIM_Period - 1;

	// Configure the timer mode
	htim->Instance->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS); // Clear the direction and center-aligned mode bits
	htim->Instance->CR1 |= TIM_COUNTERMODE_UP; // Set the up-counting mode

	// Clear the counter and update flags
	htim->Instance->CNT = 0;
	htim->Instance->SR &= ~(TIM_SR_UIF);

}

void TIM_voidPWMInit(TIM_TypeDef *TIMx) {
	// Enable timer clock
	if (TIMx == TIM1) {
		RCC_TIM1_CLOCK_EN();
	} else if (TIMx == TIM2) {
		RCC_TIM2_CLOCK_EN();
	} else if (TIMx == TIM3) {
		RCC_TIM3_CLOCK_EN();
	} else if (TIMx == TIM4) {
		RCC_TIM4_CLOCK_EN();
	}
	MCL_RCC_vEnablePeriphClk(AHB1_BUS, GPIO_PORTA);

	// Configure PA6 as alternate function mode
	GPIOA->GPIO_MODER &= ~GPIO_MODER_MODE6;
	GPIOA->GPIO_MODER |= GPIO_MODER_MODE6_1;

	// Set alternate function 2 for PA6 (TIM3_CH1)
	GPIOA->GPIO_AFR[0] &= ~GPIO_AFRL_AFRL6;
	GPIOA->GPIO_AFR[0] |= GPIO_AFRL_AFRL6_1;

	// Set PA5 output type to push-pull
	GPIOA->GPIO_OTYPER &= ~GPIO_OTYPER_OT6;

	// Set PA5 output speed to high
	GPIOA->GPIO_OSPEEDR |= GPIO_OSPEEDR_OSPEED6;

	// Set PA5 pull-up/pull-down to none
	GPIOA->GPIO_PUPDR &= ~GPIO_PUPDR_PUPD6;

	/*Set Prescaler*/
	TIMx->PSC = (10);

	/*Set Auto Reload Register Value*/

	TIMx->ARR = 26666;

	/*Zero Counter*/

	TIMx->CNT = 0;

	/*Set PWM Mode in Capture/Compare Mode Register*/

	SET_BIT(TIMx->CCMR1, 5);
	SET_BIT(TIMx->CCMR1, 6);

	/*Enable PWM CH1*/

	SET_BIT(TIMx->CCER, 0);

	/*set pulse width 1/3 of the period */

	TIMx->CCR1 = 8889 - 1;

	/*Timer 2 Enable*/

	SET_BIT(TIMx->CR1, 0);
}