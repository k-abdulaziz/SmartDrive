/**
 * @file MCAL_RCC_Private.h
 * @brief This file contains the private definitions of the MCAL_RCC driver.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_RCC_PRIVATE_H_
#define MCAL_RCC_PRIVATE_H_

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief Include the header file for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @def RCC_APB2ENR_TIM1EN_Pos
 * @brief Position of TIM1EN in RCC_APB2ENR register
 */
#define RCC_APB2ENR_TIM1EN_Pos (0U)

/**
 * @def RCC_APB2ENR_TIM1EN_Msk
 * @brief Mask for TIM1EN in RCC_APB2ENR register
 */
#define RCC_APB2ENR_TIM1EN_Msk (0x1UL << RCC_APB2ENR_TIM1EN_Pos)

/**
 * @def RCC_APB2ENR_TIM1EN
 * @brief RCC_APB2ENR_TIM1EN: TIM1 clock enable
 */
#define RCC_APB2ENR_TIM1EN RCC_APB2ENR_TIM1EN_Msk

/**
 * @def RCC_APB1ENR_TIM2EN_Pos
 * @brief Position of TIM2EN in RCC_APB1ENR register
 */
#define RCC_APB1ENR_TIM2EN_Pos (0U)

/**
 * @def RCC_APB1ENR_TIM2EN_Msk
 * @brief Mask for TIM2EN in RCC_APB1ENR register
 */
#define RCC_APB1ENR_TIM2EN_Msk (0x1UL << RCC_APB1ENR_TIM2EN_Pos)

/**
 * @def RCC_APB1ENR_TIM2EN
 * @brief RCC_APB1ENR_TIM2EN: TIM2 clock enable
 */
#define RCC_APB1ENR_TIM2EN RCC_APB1ENR_TIM2EN_Msk

/**
 * @def RCC_APB1ENR_TIM3EN_Pos
 * @brief Position of TIM3EN in RCC_APB1ENR register
 */
#define RCC_APB1ENR_TIM3EN_Pos (1U)

/**
 * @def RCC_APB1ENR_TIM3EN_Msk
 * @brief Mask for TIM3EN in RCC_APB1ENR register
 */
#define RCC_APB1ENR_TIM3EN_Msk (0x1UL << RCC_APB1ENR_TIM3EN_Pos)

/**
 * @def RCC_APB1ENR_TIM3EN
 * @brief RCC_APB1ENR_TIM3EN: TIM3 clock enable
 */
#define RCC_APB1ENR_TIM3EN RCC_APB1ENR_TIM3EN_Msk

/**
 * @def RCC_APB1ENR_TIM4EN_Pos
 * @brief Position of TIM4EN in RCC_APB1ENR register
 */
#define RCC_APB1ENR_TIM4EN_Pos (2U)

/**
 * @def RCC_APB1ENR_TIM4EN_Msk
 * @brief Mask for TIM4EN in RCC_APB1ENR register
 */
#define RCC_APB1ENR_TIM4EN_Msk (0x1UL << RCC_APB1ENR_TIM4EN_Pos)

/**
 * @def RCC_APB1ENR_TIM4EN
 * @brief RCC_APB1ENR_TIM4EN: TIM4 clock enable
 */
#define RCC_APB1ENR_TIM4EN RCC_APB1ENR_TIM4EN_Msk

/**
 * @struct RCC_TypeDef
 * @brief This structure defines the RCC registers.
 */
typedef struct {
	struct {
		vu32 HSION: 1;    /*!< Bit 0: HSE oscillator ON */
		vu32 HSIRDY: 1;   /*!< Bit 1: HSE oscillator ready */
		u32 : 1;
		vu32 HSITRIM: 5;  /*!< Bits 6:3: HSI clock trimming */
		vu32 HSICAL: 8;   /*!< Bits 14:7: HSI clock calibration */
		vu32 HSEON: 1;    /*!< Bit 15: HSE oscillator bypass */
		vu32 HSERDY: 1;   /*!< Bit 19: Clock security system enable */
		vu32 HSEBYP: 1;
		vu32 CSSON: 1;
		u32 : 4;
		vu32 PLLON: 1;    /*!< Bit 24: PLL enable */
		vu32 PLLRDY: 1;   /*!< Bit 25: PLL clock ready */
		vu32 PLLI2SON: 1;
		vu32 PLLI2RDY: 1;
		u32 : 4;
	} RCC_CR;

	vu32 RCC_PLLCFGR;
	union {
		struct {
			vu32 SWn: 2;
			vu32 SWSn: 2;
			vu32 HPRE: 4;
			u32 : 2;
			vu32 PPRE1: 3;
			vu32 PPRE2: 3;
			vu32 RTCPRE: 5;
			vu32 MCO1: 2;       /*!< Bits 23-24: Microcontroller clock output 1 */
			vu32 I2SSC: 1;      /*!< Bit 25: I2S clock selection */
			vu32 MCO1_PRE: 3;   /*!< Bits 26-28: MCO1 prescaler */
			vu32 MCO2_PRE: 3;   /*!< Bits 29-31: MCO2 prescaler */
			vu32 MCO2: 2;       /*!< Bits 32-33: Microcontroller clock output 2 */
		} RCC_CFGR_bits;
		vu32 RCC_CFGR;
	};

	vu32 RCC_CIR;
	vu32 RCC_AHB1RSTR;
	vu32 RCC_AHB2RSTR;
	u32 reserved0[2];
	vu32 RCC_APB1RSTR;
	vu32 RCC_APB2RSTR;
	u32 reserved1[2];
	vu32 RCC_AHB1ENR;
	vu32 RCC_AHB2ENR;
	u32 reserved2[2];
	vu32 RCC_APB1ENR;
	vu32 RCC_APB2ENR;
	u32 reserved3[2];
	vu32 RCC_AHB1LPENR;
	vu32 RCC_AHB2LPENR;
	u32 reserved4[2];
	vu32 RCC_APB1LPENR;
	vu32 RCC_APB2LPENR;
	u32 reserved5[2];
	vu32 RCC_BDCR;
	vu32 RCC_CSR;
	u32 reserved6[2];
	vu32 RCC_SSCGR;
	vu32 RCC_PLLI2SCFGR;
	u32 reserved7;
	vu32 RCC_DCKCFGR;
} RCC_TypeDef;

/**
 * @def RCC
 * @brief RCC base address
 */
#define RCC ((RCC_TypeDef *)RCC_BASE)

/**
 * @def RCC_APB2ENR_SYSCFGEN
 * @brief Position of SYSCFGEN in RCC_APB2ENR register
 */
#define RCC_APB2ENR_SYSCFGEN 5

#endif /* MCAL_RCC_PRIVATE_H_ */
