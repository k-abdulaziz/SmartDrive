/**
 * @file MCAL_TIM_Private.h
 * @brief This file contains the private of the MCAL_TIM driver.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_TIM_PRIVATE_H_
#define MCAL_TIM_PRIVATE_H_

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "STD_TYPES.h"

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief Include the header file for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @struct TIM_TypeDef
 * @brief TIM register structure.
 */
typedef struct {
	/**
	 * @brief TIM control register 1.
	 */
	__IO uint32_t CR1;
	/**
	 * @brief TIM control register 2.
	 */
	__IO uint32_t CR2;
	/**
	 * @brief TIM slave mode control register.
	 */
	__IO uint32_t SMCR;
	/**
	 * @brief TIM DMA/interrupt enable register.
	 */
	__IO uint32_t DIER;
	/**
	 * @brief TIM status register.
	 */
	__IO uint32_t SR;
	/**
	 * @brief TIM event generation register.
	 */
	__IO uint32_t EGR;
	/**
	 * @brief TIM capture/compare mode register 1.
	 */
	__IO uint32_t CCMR1;
	/**
	 * @brief TIM capture/compare mode register 2.
	 */
	__IO uint32_t CCMR2;
	/**
	 * @brief TIM capture/compare enable register.
	 */
	__IO uint32_t CCER;
	/**
	 * @brief TIM counter register.
	 */
	__IO uint32_t CNT;
	/**
	 * @brief TIM prescaler.
	 */
	__IO uint32_t PSC;
	/**
	 * @brief TIM auto-reload register.
	 */
	__IO uint32_t ARR;
	/**
	 * @brief TIM repetition counter register.
	 */
	__IO uint32_t RCR;
	/**
	 * @brief TIM capture/compare register 1.
	 */
	__IO uint32_t CCR1;
	/**
	 * @brief TIM capture/compare register 2.
	 */
	__IO uint32_t CCR2;
	/**
	 * @brief TIM capture/compare register 3.
	 */
	__IO uint32_t CCR3;
	/**
	 * @brief TIM capture/compare register 4.
	 */
	__IO uint32_t CCR4;
	/**
	 * @brief TIM break and dead-time register.
	 */
	__IO uint32_t BDTR;
	/**
	 * @brief TIM DMA control register.
	 */
	__IO uint32_t DCR;
	/**
	 * @brief TIM DMA address for full transfer.
	 */
	__IO uint32_t DMAR;
	/**
	 * @brief TIM option register.
	 */
	__IO uint32_t OR;
} TIM_TypeDef;

/**
 * @def TIM1
 * @brief TIM1 peripheral base address.
 */
#define TIM1                ((TIM_TypeDef *)TIM1_BASE)

/**
 * @def TIM2
 * @brief TIM2 peripheral base address.
 */
#define TIM2                ((TIM_TypeDef *)TIM2_BASE)

/**
 * @def TIM3
 * @brief TIM3 peripheral base address.
 */
#define TIM3                ((TIM_TypeDef *)TIM3_BASE)

/**
 * @def TIM4
 * @brief TIM4 peripheral base address.
 */
#define TIM4                ((TIM_TypeDef *)TIM4_BASE)

/**
 * @def TIM_CR1_CEN_Pos
 * @brief Position of the CEN (Counter Enable) bit in the TIM_CR1 register.
 */
#define TIM_CR1_CEN_Pos         (0U)

/**
 * @def TIM_CR1_CEN_Msk
 * @brief Bit mask of the CEN (Counter Enable) bit in the TIM_CR1 register.
 */
#define TIM_CR1_CEN_Msk         (0x1U << TIM_CR1_CEN_Pos)

/**
 * @def TIM_CR1_CEN
 * @brief Counter Enable (CEN) bit in the TIM_CR1 register.
 */
#define TIM_CR1_CEN             TIM_CR1_CEN_Msk

/**
 * @def TIM_CR1_UDIS_Pos
 * @brief Position of the UDIS (Update Disable) bit in the TIM_CR1 register.
 */
#define TIM_CR1_UDIS_Pos        (1U)

/**
 * @def TIM_CR1_UDIS_Msk
 * @brief Bit mask of the UDIS (Update Disable) bit in the TIM_CR1 register.
 */
#define TIM_CR1_UDIS_Msk        (0x1U << TIM_CR1_UDIS_Pos)

/**
 * @def TIM_CR1_UDIS
 * @brief Update Disable (UDIS) bit in the TIM_CR1 register.
 */
#define TIM_CR1_UDIS            TIM_CR1_UDIS_Msk

/**
 * @def TIM_CR1_URS_Pos
 * @brief Position of the URS (Update Request Source) bit in the TIM_CR1 register.
 */
#define TIM_CR1_URS_Pos         (2U)

/**
 * @def TIM_CR1_URS_Msk
 * @brief Bit mask of the URS (Update Request Source) bit in the TIM_CR1 register.
 */
#define TIM_CR1_URS_Msk         (0x1U << TIM_CR1_URS_Pos)

/**
 * @def TIM_CR1_URS
 * @brief Update Request Source (URS) bit in the TIM_CR1 register.
 */
#define TIM_CR1_URS             TIM_CR1_URS_Msk

/**
 * @def TIM_CR1_OPM_Pos
 * @brief Position of the OPM (One-Pulse Mode) bit in the TIM_CR1 register.
 */
#define TIM_CR1_OPM_Pos         (3U)

/**
 * @def TIM_CR1_OPM_Msk
 * @brief Bit mask of the OPM (One-Pulse Mode) bit in the TIM_CR1 register.
 */
#define TIM_CR1_OPM_Msk         (0x1U << TIM_CR1_OPM_Pos)

/**
 * @def TIM_CR1_OPM
 * @brief One-Pulse Mode (OPM) bit in the TIM_CR1 register.
 */
#define TIM_CR1_OPM             TIM_CR1_OPM_Msk

/**
 * @def TIM_CR1_DIR_Pos
 * @brief Position of the DIR (Direction) bit in the TIM_CR1 register.
 */
#define TIM_CR1_DIR_Pos         (4U)

/**
 * @def TIM_CR1_DIR_Msk
 * @brief Bit mask of the DIR (Direction) bit in the TIM_CR1 register.
 */
#define TIM_CR1_DIR_Msk         (0x1U << TIM_CR1_DIR_Pos)

/**
 * @def TIM_CR1_DIR
 * @brief Direction (DIR) bit in the TIM_CR1 register.
 */
#define TIM_CR1_DIR             TIM_CR1_DIR_Msk

/**
 * @def TIM_CR1_CMS_Pos
 * @brief Position of the CMS (Center-aligned Mode Selection) bits in the TIM_CR1 register.
 */
#define TIM_CR1_CMS_Pos           (5U)

/**
 * @def TIM_CR1_CMS_Msk
 * @brief Bit mask of the CMS (Center-aligned Mode Selection) bits in the TIM_CR1 register.
 */
#define TIM_CR1_CMS_Msk           (0x3UL << TIM_CR1_CMS_Pos)

/**
 * @def TIM_CR1_CMS
 * @brief Center-aligned Mode Selection (CMS) bits in the TIM_CR1 register.
 */
#define TIM_CR1_CMS               TIM_CR1_CMS_Msk


/**
 * @def TIM_CR1_CMS_0
 * @brief Value of the CMS (Center-aligned Mode Selection) bits with a shift of TIM_CR1_CMS_Pos.
 */
#define TIM_CR1_CMS_0             (0x1UL << TIM_CR1_CMS_Pos)                    /*!< 0x0020 */

/**
 * @def TIM_CR1_CMS_1
 * @brief Value of the CMS (Center-aligned Mode Selection) bits with a shift of TIM_CR1_CMS_Pos.
 */
#define TIM_CR1_CMS_1             (0x2UL << TIM_CR1_CMS_Pos)                    /*!< 0x0040 */

/**
 * @def TIM_CCMR1_CC1S_Pos
 * @brief Position of the CC1S (Capture/Compare 1 Selection) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_CC1S_Pos                  (0U)

/**
 * @def TIM_CCMR1_CC1S_Msk
 * @brief Bit mask of the CC1S (Capture/Compare 1 Selection) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_CC1S_Msk                  (0x3UL << TIM_CCMR1_CC1S_Pos)

/**
 * @def TIM_CCMR1_CC1S
 * @brief CC1S (Capture/Compare 1 Selection) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_CC1S                      TIM_CCMR1_CC1S_Msk

/**
 * @def TIM_CCMR1_CC1S_0
 * @brief Value of the CC1S (Capture/Compare 1 Selection) bits with a shift of TIM_CCMR1_CC1S_Pos.
 */
#define TIM_CCMR1_CC1S_0                    (0x1UL << TIM_CCMR1_CC1S_Pos)       /*!< 0x00000001 */

/**
 * @def TIM_CCMR1_CC1S_1
 * @brief Value of the CC1S (Capture/Compare 1 Selection) bits with a shift of TIM_CCMR1_CC1S_Pos.
 */
#define TIM_CCMR1_CC1S_1                    (0x2UL << TIM_CCMR1_CC1S_Pos)       /*!< 0x00000002 */

/**
 * @def TIM_CCMR1_OC1FE_Pos
 * @brief Position of the OC1FE (Output Compare 1 Fast enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1FE_Pos                 (2U)

/**
 * @def TIM_CCMR1_OC1FE_Msk
 * @brief Bit mask of the OC1FE (Output Compare 1 Fast enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1FE_Msk                 (0x1UL << TIM_CCMR1_OC1FE_Pos)

/**
 * @def TIM_CCMR1_OC1FE
 * @brief OC1FE (Output Compare 1 Fast enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1FE                     TIM_CCMR1_OC1FE_Msk

/**
 * @def TIM_CCMR1_OC1PE_Pos
 * @brief Position of the OC1PE (Output Compare 1 Preload enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1PE_Pos                 (3U)

/**
 * @def TIM_CCMR1_OC1PE_Msk
 * @brief Bit mask of the OC1PE (Output Compare 1 Preload enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1PE_Msk                 (0x1UL << TIM_CCMR1_OC1PE_Pos)

/**
 * @def TIM_CCMR1_OC1PE
 * @brief OC1PE (Output Compare 1 Preload enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1PE                     TIM_CCMR1_OC1PE_Msk

/**
 * @def TIM_CCMR1_OC1M_Pos
 * @brief Position of the OC1M (Output Compare 1 Mode) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1M_Pos                  (4U)

/**
 * @def TIM_CCMR1_OC1M_Msk
 * @brief Bit mask of the OC1M (Output Compare 1 Mode) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1M_Msk                  (0x7UL << TIM_CCMR1_OC1M_Pos)

/**
 * @def TIM_CCMR1_OC1M
 * @brief OC1M (Output Compare 1 Mode) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1M                      TIM_CCMR1_OC1M_Msk

/**
 * @def TIM_CCMR1_OC1M_0
 * @brief Value of the OC1M (Output Compare 1 Mode) bits with a shift of TIM_CCMR1_OC1M_Pos.
 */
#define TIM_CCMR1_OC1M_0                    (0x1UL << TIM_CCMR1_OC1M_Pos)       /*!< 0x00000010 */

/**
 * @def TIM_CCMR1_OC1M_1
 * @brief Value of the OC1M (Output Compare 1 Mode) bits with a shift of TIM_CCMR1_OC1M_Pos.
 */
#define TIM_CCMR1_OC1M_1                    (0x2UL << TIM_CCMR1_OC1M_Pos)


/**
 * @def TIM_CCMR1_OC1M_2
 * @brief Value of the OC1M (Output Compare 1 Mode) bits with a shift of TIM_CCMR1_OC1M_Pos.
 */
#define TIM_CCMR1_OC1M_2                    (0x4UL << TIM_CCMR1_OC1M_Pos)       /*!< 0x00000040 */

/**
 * @def TIM_CCMR1_OC1CE_Pos
 * @brief Position of the OC1CE (Output Compare 1 Clear Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1CE_Pos                 (7U)

/**
 * @def TIM_CCMR1_OC1CE_Msk
 * @brief Bit mask of the OC1CE (Output Compare 1 Clear Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1CE_Msk                 (0x1UL << TIM_CCMR1_OC1CE_Pos)

/**
 * @def TIM_CCMR1_OC1CE
 * @brief OC1CE (Output Compare 1 Clear Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC1CE                     TIM_CCMR1_OC1CE_Msk

/**
 * @def TIM_CCMR1_CC2S_Pos
 * @brief Position of the CC2S (Capture/Compare 2 Selection) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_CC2S_Pos                  (8U)

/**
 * @def TIM_CCMR1_CC2S_Msk
 * @brief Bit mask of the CC2S (Capture/Compare 2 Selection) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_CC2S_Msk                  (0x3UL << TIM_CCMR1_CC2S_Pos)

/**
 * @def TIM_CCMR1_CC2S
 * @brief CC2S (Capture/Compare 2 Selection) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_CC2S                      TIM_CCMR1_CC2S_Msk

/**
 * @def TIM_CCMR1_CC2S_0
 * @brief Value of the CC2S (Capture/Compare 2 Selection) bits with a shift of TIM_CCMR1_CC2S_Pos.
 */
#define TIM_CCMR1_CC2S_0                    (0x1UL << TIM_CCMR1_CC2S_Pos)       /*!< 0x00000100 */

/**
 * @def TIM_CCMR1_CC2S_1
 * @brief Value of the CC2S (Capture/Compare 2 Selection) bits with a shift of TIM_CCMR1_CC2S_Pos.
 */
#define TIM_CCMR1_CC2S_1                    (0x2UL << TIM_CCMR1_CC2S_Pos)       /*!< 0x00000200 */

/**
 * @def TIM_CCMR1_OC2FE_Pos
 * @brief Position of the OC2FE (Output Compare 2 Fast Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2FE_Pos                 (10U)

/**
 * @def TIM_CCMR1_OC2FE_Msk
 * @brief Bit mask of the OC2FE (Output Compare 2 Fast Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2FE_Msk                 (0x1UL << TIM_CCMR1_OC2FE_Pos)

/**
 * @def TIM_CCMR1_OC2FE
 * @brief OC2FE (Output Compare 2 Fast Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2FE                     TIM_CCMR1_OC2FE_Msk

/**
 * @def TIM_CCMR1_OC2PE_Pos
 * @brief Position of the OC2PE (Output Compare 2 Preload Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2PE_Pos                 (11U)

/**
 * @def TIM_CCMR1_OC2PE_Msk
 * @brief Bit mask of the OC2PE (Output Compare 2 Preload Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2PE_Msk                 (0x1UL << TIM_CCMR1_OC2PE_Pos)

/**
 * @def TIM_CCMR1_OC2PE
 * @brief OC2PE (Output Compare 2 Preload Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2PE                     TIM_CCMR1_OC2PE_Msk

/**
 * @def TIM_CCMR1_OC2M_Pos
 * @brief Position of the OC2M (Output Compare 2 Mode) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2M_Pos                  (12U)

/**
 * @def TIM_CCMR1_OC2M_Msk
 * @brief Bit mask of the OC2M (Output Compare 2 Mode) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2M_Msk                  (0x7UL << TIM_CCMR1_OC2M_Pos)

/**
 * @def TIM_CCMR1_OC2M
 * @brief OC2M (Output Compare 2 Mode) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2M                      TIM_CCMR1_OC2M_Msk

/**
 * @def TIM_CCMR1_OC2M_0
 * @brief Value of the OC2M (Output Compare 2 Mode) bits with a shift of TIM_CCMR1_OC2M_Pos.
 */
#define TIM_CCMR1_OC2M_0                    (0x1UL << TIM_CCMR1_OC2M_Pos)       /*!< 0x00001000 */

/**
 * @def TIM_CCMR1_OC2M_1
 * @brief Value of the OC2M (Output Compare 2 Mode) bits with a shift of TIM_CCMR1_OC2M_Pos.
 */
#define TIM_CCMR1_OC2M_1                    (0x2UL << TIM_CCMR1_OC2M_Pos)

/**
 * @def TIM_CCMR1_OC2M_2
 * @brief Value of the OC2M (Output Compare 2 Mode) bits with a shift of TIM_CCMR1_OC2M_Pos.
 */
#define TIM_CCMR1_OC2M_2                    (0x4UL << TIM_CCMR1_OC2M_Pos)       /*!< 0x00004000 */

/**
 * @def TIM_CCMR1_OC2CE_Pos
 * @brief Position of the OC2CE (Output Compare 2 Clear Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2CE_Pos                 (15U)

/**
 * @def TIM_CCMR1_OC2CE_Msk
 * @brief Bit mask of the OC2CE (Output Compare 2 Clear Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2CE_Msk                 (0x1UL << TIM_CCMR1_OC2CE_Pos)

/**
 * @def TIM_CCMR1_OC2CE
 * @brief OC2CE (Output Compare 2 Clear Enable) bit in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_OC2CE                     TIM_CCMR1_OC2CE_Msk

/**
 * @def TIM_CCMR1_IC1PSC_Pos
 * @brief Position of the IC1PSC (Input Capture 1 Prescaler) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC1PSC_Pos                (2U)

/**
 * @def TIM_CCMR1_IC1PSC_Msk
 * @brief Bit mask of the IC1PSC (Input Capture 1 Prescaler) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC1PSC_Msk                (0x3UL << TIM_CCMR1_IC1PSC_Pos)

/**
 * @def TIM_CCMR1_IC1PSC
 * @brief IC1PSC (Input Capture 1 Prescaler) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC1PSC                    TIM_CCMR1_IC1PSC_Msk

/**
 * @def TIM_CCMR1_IC1PSC_0
 * @brief Value of the IC1PSC (Input Capture 1 Prescaler) bits with a shift of TIM_CCMR1_IC1PSC_Pos.
 */
#define TIM_CCMR1_IC1PSC_0                  (0x1UL << TIM_CCMR1_IC1PSC_Pos)     /*!< 0x00000004 */

/**
 * @def TIM_CCMR1_IC1PSC_1
 * @brief Value of the IC1PSC (Input Capture 1 Prescaler) bits with a shift of TIM_CCMR1_IC1PSC_Pos.
 */
#define TIM_CCMR1_IC1PSC_1                  (0x2UL << TIM_CCMR1_IC1PSC_Pos)     /*!< 0x00000008 */

/**
 * @def TIM_CCMR1_IC1F_Pos
 * @brief Position of the IC1F (Input Capture 1 Filter) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC1F_Pos                  (4U)

/**
 * @def TIM_CCMR1_IC1F_Msk
 * @brief Bit mask of the IC1F (Input Capture 1 Filter) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC1F_Msk                  (0xFUL << TIM_CCMR1_IC1F_Pos)

/**
 * @def TIM_CCMR1_IC1F
 * @brief IC1F (Input Capture 1 Filter) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC1F                      TIM_CCMR1_IC1F_Msk

/**
 * @def TIM_CCMR1_IC1F_0
 * @brief Value of the IC1F (Input Capture 1 Filter) bits with a shift of TIM_CCMR1_IC1F_Pos.
 */
#define TIM_CCMR1_IC1F_0                    (0x1UL << TIM_CCMR1_IC1F_Pos)       /*!< 0x00000010 */

/**
 * @def TIM_CCMR1_IC1F_1
 * @brief Value of the IC1F (Input Capture 1 Filter) bits with a shift of TIM_CCMR1_IC1F_Pos.
 */
#define TIM_CCMR1_IC1F_1                    (0x2UL << TIM_CCMR1_IC1F_Pos)       /*!< 0x00000020 */

/**
 * @def TIM_CCMR1_IC1F_2
 * @brief Value of the IC1F (Input Capture 1 Filter) bits with a shift of TIM_CCMR1_IC1F_Pos.
 */
#define TIM_CCMR1_IC1F_2                    (0x4UL << TIM_CCMR1_IC1F_Pos)       /*!< 0x00000040 */

/**
 * @def TIM_CCMR1_IC1F_3
 * @brief Value of the IC1F (Input Capture 1 Filter) bits with a shift of TIM_CCMR1_IC1F_Pos.
 */
#define TIM_CCMR1_IC1F_3                    (0x8UL << TIM_CCMR1_IC1F_Pos)       /*!< 0x00000080 */

/**
 * @def TIM_CCMR1_IC2PSC_Pos
 * @brief Position of the IC2PSC (Input Capture 2 Prescaler) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC2PSC_Pos                (10U)

/**
 * @def TIM_CCMR1_IC2PSC_Msk
 * @brief Bit mask of the IC2PSC (Input Capture 2 Prescaler) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC2PSC_Msk                (0x3UL << TIM_CCMR1_IC2PSC_Pos)

/**
 * @def TIM_CCMR1_IC2PSC
 * @brief IC2PSC (Input Capture 2 Prescaler) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC2PSC                    TIM_CCMR1_IC2PSC_Msk

/**
 * @def TIM_CCMR1_IC2PSC_0
 * @brief Value of the IC2PSC (Input Capture 2 Prescaler) bits with a shift of TIM_CCMR1_IC2PSC_Pos.
 */
#define TIM_CCMR1_IC2PSC_0                  (0x1UL << TIM_CCMR1_IC2PSC_Pos)     /*!< 0x00000400 */

/**
 * @def TIM_CCMR1_IC2PSC_1
 * @brief Value of the IC2PSC (Input Capture 2 Prescaler) bits with a shift of TIM_CCMR1_IC2PSC_Pos.
 */
#define TIM_CCMR1_IC2PSC_1                  (0x2UL << TIM_CCMR1_IC2PSC_Pos)     /*!< 0x00000800 */

/**
 * @def TIM_CCMR1_IC2F_Pos
 * @brief Position of the IC2F (Input Capture 2 Filter) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC2F_Pos                  (12U)

/**
 * @def TIM_CCMR1_IC2F_Msk
 * @brief Bit mask of the IC2F (Input Capture 2 Filter) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC2F_Msk                  (0xFUL << TIM_CCMR1_IC2F_Pos)

/**
 * @def TIM_CCMR1_IC2F
 * @brief IC2F (Input Capture 2 Filter) bits in the TIM_CCMR1 register.
 */
#define TIM_CCMR1_IC2F                      TIM_CCMR1_IC2F_Msk

/**
 * @def TIM_CCMR1_IC2F_0
 * @brief Value of the IC2F (Input Capture 2 Filter) bits with a shift of TIM_CCMR1_IC2F_Pos.
 */
#define TIM_CCMR1_IC2F_0                    (0x1UL << TIM_CCMR1_IC2F_Pos)       /*!< 0x00001000 */

/**
 * @def TIM_CCMR1_IC2F_1
 * @brief Value of the IC2F (Input Capture 2 Filter) bits with a shift of TIM_CCMR1_IC2F_Pos.
 */
#define TIM_CCMR1_IC2F_1                    (0x2UL << TIM_CCMR1_IC2F_Pos)

/**
 * @def TIM_CCMR1_IC2F_2
 * @brief Value of the IC2F (Input Capture 2 Filter) bits with a shift of TIM_CCMR1_IC2F_Pos.
 */
#define TIM_CCMR1_IC2F_2                    (0x4UL << TIM_CCMR1_IC2F_Pos)       /*!< 0x00004000 */

/**
 * @def TIM_CCMR1_IC2F_3
 * @brief Value of the IC2F (Input Capture 2 Filter) bits with a shift of TIM_CCMR1_IC2F_Pos.
 */
#define TIM_CCMR1_IC2F_3                    (0x8UL << TIM_CCMR1_IC2F_Pos)       /*!< 0x00008000 */

/**
 * @def TIM_CCMR2_CC3S_Pos
 * @brief Position of the CC3S (Capture/Compare 3 Selection) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_CC3S_Pos                  (0U)

/**
 * @def TIM_CCMR2_CC3S_Msk
 * @brief Bit mask of the CC3S (Capture/Compare 3 Selection) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_CC3S_Msk                  (0x3UL << TIM_CCMR2_CC3S_Pos)

/**
 * @def TIM_CCMR2_CC3S
 * @brief CC3S (Capture/Compare 3 Selection) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_CC3S                      TIM_CCMR2_CC3S_Msk

/**
 * @def TIM_CCMR2_CC3S_0
 * @brief Value of the CC3S (Capture/Compare 3 Selection) bits with a shift of TIM_CCMR2_CC3S_Pos.
 */
#define TIM_CCMR2_CC3S_0                    (0x1UL << TIM_CCMR2_CC3S_Pos)       /*!< 0x00000001 */

/**
 * @def TIM_CCMR2_CC3S_1
 * @brief Value of the CC3S (Capture/Compare 3 Selection) bits with a shift of TIM_CCMR2_CC3S_Pos.
 */
#define TIM_CCMR2_CC3S_1                    (0x2UL << TIM_CCMR2_CC3S_Pos)       /*!< 0x00000002 */

/**
 * @def TIM_CCMR2_OC3FE_Pos
 * @brief Position of the OC3FE (Output Compare 3 Fast enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3FE_Pos                 (2U)

/**
 * @def TIM_CCMR2_OC3FE_Msk
 * @brief Bit mask of the OC3FE (Output Compare 3 Fast enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3FE_Msk                 (0x1UL << TIM_CCMR2_OC3FE_Pos)

/**
 * @def TIM_CCMR2_OC3FE
 * @brief OC3FE (Output Compare 3 Fast enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3FE                     TIM_CCMR2_OC3FE_Msk

/**
 * @def TIM_CCMR2_OC3PE_Pos
 * @brief Position of the OC3PE (Output Compare 3 Preload enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3PE_Pos                 (3U)

/**
 * @def TIM_CCMR2_OC3PE_Msk
 * @brief Bit mask of the OC3PE (Output Compare 3 Preload enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3PE_Msk                 (0x1UL << TIM_CCMR2_OC3PE_Pos)

/**
 * @def TIM_CCMR2_OC3PE
 * @brief OC3PE (Output Compare 3 Preload enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3PE                     TIM_CCMR2_OC3PE_Msk

#/**
 * @def TIM_CCMR2_OC3M_Pos
 * @brief Position of the OC3M (Output Compare 3 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3M_Pos                  (4U)

/**
 * @def TIM_CCMR2_OC3M_Msk
 * @brief Bit mask of the OC3M (Output Compare 3 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3M_Msk                  (0x7UL << TIM_CCMR2_OC3M_Pos)

/**
 * @def TIM_CCMR2_OC3M
 * @brief OC3M (Output Compare 3 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3M                      TIM_CCMR2_OC3M_Msk

/**
 * @def TIM_CCMR2_OC3M_0
 * @brief Bit 0 of OC3M (Output Compare 3 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3M_0                    (0x1UL << TIM_CCMR2_OC3M_Pos)

/**
 * @def TIM_CCMR2_OC3M_1
 * @brief Bit 1 of OC3M (Output Compare 3 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3M_1                    (0x2UL << TIM_CCMR2_OC3M_Pos)

/**
 * @def TIM_CCMR2_OC3M_2
 * @brief Bit 2 of OC3M (Output Compare 3 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3M_2                    (0x4UL << TIM_CCMR2_OC3M_Pos)

/**
 * @def TIM_CCMR2_OC3CE_Pos
 * @brief Position of the OC3CE (Output Compare 3 Clear Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3CE_Pos                 (7U)

/**
 * @def TIM_CCMR2_OC3CE_Msk
 * @brief Bit mask of the OC3CE (Output Compare 3 Clear Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3CE_Msk                 (0x1UL << TIM_CCMR2_OC3CE_Pos)

/**
 * @def TIM_CCMR2_OC3CE
 * @brief OC3CE (Output Compare 3 Clear Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC3CE                     TIM_CCMR2_OC3CE_Msk

/**
 * @def TIM_CCMR2_CC4S_Pos
 * @brief Position of the CC4S (Capture/Compare 4 Selection) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_CC4S_Pos                  (8U)

/**
 * @def TIM_CCMR2_CC4S_Msk
 * @brief Bit mask of the CC4S (Capture/Compare 4 Selection) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_CC4S_Msk                  (0x3UL << TIM_CCMR2_CC4S_Pos)

/**
 * @def TIM_CCMR2_CC4S
 * @brief CC4S (Capture/Compare 4 Selection) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_CC4S                      TIM_CCMR2_CC4S_Msk

/**
 * @def TIM_CCMR2_CC4S_0
 * @brief Bit 0 of CC4S (Capture/Compare 4 Selection) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_CC4S_0                    (0x1UL << TIM_CCMR2_CC4S_Pos)

/**
 * @def TIM_CCMR2_CC4S_1
 * @brief Bit 1 of CC4S (Capture/Compare 4 Selection) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_CC4S_1                    (0x2UL << TIM_CCMR2_CC4S_Pos)

/**
 * @def TIM_CCMR2_OC4FE_Pos
 * @brief Position of the OC4FE (Output Compare 4 Fast Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4FE_Pos                 (10U)

/**
 * @def TIM_CCMR2_OC4FE_Msk
 * @brief Bit mask of the OC4FE (Output Compare 4 Fast Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4FE_Msk                 (0x1UL << TIM_CCMR2_OC4FE_Pos)

/**
 * @def TIM_CCMR2_OC4FE
 * @brief OC4FE (Output Compare 4 Fast Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4FE                     TIM_CCMR2_OC4FE_Msk

/**
 * @def TIM_CCMR2_OC4PE_Pos
 * @brief Position of the OC4PE (Output Compare 4 Preload Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4PE_Pos                 (11U)

/**
 * @def TIM_CCMR2_OC4PE_Msk
 * @brief Bit mask of the OC4PE (Output Compare 4 Preload Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4PE_Msk                 (0x1UL << TIM_CCMR2_OC4PE_Pos)

/**
 * @def TIM_CCMR2_OC4PE
 * @brief OC4PE (Output Compare 4 Preload Enable) bit in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4PE                     TIM_CCMR2_OC4PE_Msk

/**
 * @def TIM_CCMR2_OC4M_Pos
 * @brief Position of the OC4M (Output Compare 4 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4M_Pos                  (12U)

/**
 * @def TIM_CCMR2_OC4M_Msk
 * @brief Bit mask of the OC4M (Output Compare 4 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4M_Msk                  (0x7UL << TIM_CCMR2_OC4M_Pos)

/**
 * @def TIM_CCMR2_OC4M
 * @brief OC4M (Output Compare 4 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4M                      TIM_CCMR2_OC4M_Msk

/**
 * @def TIM_CCMR2_OC4M_0
 * @brief Bit 0 of OC4M (Output Compare 4 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4M_0                    (0x1UL << TIM_CCMR2_OC4M_Pos)

/**
 * @def TIM_CCMR2_OC4M_1
 * @brief Bit 1 of OC4M (Output Compare 4 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4M_1                    (0x2UL << TIM_CCMR2_OC4M_Pos)

/**
 * @def TIM_CCMR2_OC4M_2
 * @brief Bit 2 of OC4M (Output Compare 4 Mode) bits in the TIM_CCMR2 register.
 */
#define TIM_CCMR2_OC4M_2                    (0x4UL << TIM_CCMR2_OC4M_Pos)

#define TIM_CCMR2_OC4CE_Pos                 (15U)
#define TIM_CCMR2_OC4CE_Msk                 (0x1UL << TIM_CCMR2_OC4CE_Pos)      /*!< 0x00008000 */
#define TIM_CCMR2_OC4CE                     TIM_CCMR2_OC4CE_Msk                /*!<Output Compare 4 Clear Enable */

#define TIM_CCMR2_IC3PSC_Pos                (2U)
#define TIM_CCMR2_IC3PSC_Msk                (0x3UL << TIM_CCMR2_IC3PSC_Pos)     /*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC                    TIM_CCMR2_IC3PSC_Msk               /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_0                  (0x1UL << TIM_CCMR2_IC3PSC_Pos)     /*!< 0x00000004 */
#define TIM_CCMR2_IC3PSC_1                  (0x2UL << TIM_CCMR2_IC3PSC_Pos)     /*!< 0x00000008 */

#define TIM_CCMR2_IC3F_Pos                  (4U)
#define TIM_CCMR2_IC3F_Msk                  (0xFUL << TIM_CCMR2_IC3F_Pos)       /*!< 0x000000F0 */
#define TIM_CCMR2_IC3F                      TIM_CCMR2_IC3F_Msk                 /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0                    (0x1UL << TIM_CCMR2_IC3F_Pos)       /*!< 0x00000010 */
#define TIM_CCMR2_IC3F_1                    (0x2UL << TIM_CCMR2_IC3F_Pos)       /*!< 0x00000020 */
#define TIM_CCMR2_IC3F_2                    (0x4UL << TIM_CCMR2_IC3F_Pos)       /*!< 0x00000040 */
#define TIM_CCMR2_IC3F_3                    (0x8UL << TIM_CCMR2_IC3F_Pos)       /*!< 0x00000080 */

#define TIM_CCMR2_IC4PSC_Pos                (10U)
#define TIM_CCMR2_IC4PSC_Msk                (0x3UL << TIM_CCMR2_IC4PSC_Pos)     /*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC                    TIM_CCMR2_IC4PSC_Msk               /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_0                  (0x1UL << TIM_CCMR2_IC4PSC_Pos)     /*!< 0x00000400 */
#define TIM_CCMR2_IC4PSC_1                  (0x2UL << TIM_CCMR2_IC4PSC_Pos)     /*!< 0x00000800 */

#define TIM_CCMR2_IC4F_Pos                  (12U)
#define TIM_CCMR2_IC4F_Msk                  (0xFUL << TIM_CCMR2_IC4F_Pos)       /*!< 0x0000F000 */
#define TIM_CCMR2_IC4F                      TIM_CCMR2_IC4F_Msk                 /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0                    (0x1UL << TIM_CCMR2_IC4F_Pos)       /*!< 0x00001000 */
#define TIM_CCMR2_IC4F_1                    (0x2UL << TIM_CCMR2_IC4F_Pos)       /*!< 0x00002000 */
#define TIM_CCMR2_IC4F_2                    (0x4UL << TIM_CCMR2_IC4F_Pos)       /*!< 0x00004000 */
#define TIM_CCMR2_IC4F_3                    (0x8UL << TIM_CCMR2_IC4F_Pos)       /*!< 0x00008000 */

#define TIM_CCER_CC1E_Pos         (0U)
#define TIM_CCER_CC1E_Msk         (0x1UL << TIM_CCER_CC1E_Pos)                  /*!< 0x00000001 */
#define TIM_CCER_CC1E             TIM_CCER_CC1E_Msk                            /*!<Capture/Compare 1 output enable                 */
#define TIM_CCER_CC1P_Pos         (1U)
#define TIM_CCER_CC1P_Msk         (0x1UL << TIM_CCER_CC1P_Pos)                  /*!< 0x00000002 */
#define TIM_CCER_CC1P             TIM_CCER_CC1P_Msk                            /*!<Capture/Compare 1 output Polarity               */
#define TIM_CCER_CC1NE_Pos        (2U)
#define TIM_CCER_CC1NE_Msk        (0x1UL << TIM_CCER_CC1NE_Pos)                 /*!< 0x00000004 */
#define TIM_CCER_CC1NE            TIM_CCER_CC1NE_Msk                           /*!<Capture/Compare 1 Complementary output enable   */
#define TIM_CCER_CC1NP_Pos        (3U)
#define TIM_CCER_CC1NP_Msk        (0x1UL << TIM_CCER_CC1NP_Pos)                 /*!< 0x00000008 */
#define TIM_CCER_CC1NP            TIM_CCER_CC1NP_Msk                           /*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos         (4U)
#define TIM_CCER_CC2E_Msk         (0x1UL << TIM_CCER_CC2E_Pos)                  /*!< 0x00000010 */
#define TIM_CCER_CC2E             TIM_CCER_CC2E_Msk                            /*!<Capture/Compare 2 output enable                 */
#define TIM_CCER_CC2P_Pos         (5U)
#define TIM_CCER_CC2P_Msk         (0x1UL << TIM_CCER_CC2P_Pos)                  /*!< 0x00000020 */
#define TIM_CCER_CC2P             TIM_CCER_CC2P_Msk                            /*!<Capture/Compare 2 output Polarity               */
#define TIM_CCER_CC2NE_Pos        (6U)
#define TIM_CCER_CC2NE_Msk        (0x1UL << TIM_CCER_CC2NE_Pos)                 /*!< 0x00000040 */
#define TIM_CCER_CC2NE            TIM_CCER_CC2NE_Msk                           /*!<Capture/Compare 2 Complementary output enable   */
#define TIM_CCER_CC2NP_Pos        (7U)
#define TIM_CCER_CC2NP_Msk        (0x1UL << TIM_CCER_CC2NP_Pos)                 /*!< 0x00000080 */
#define TIM_CCER_CC2NP            TIM_CCER_CC2NP_Msk                           /*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos         (8U)
#define TIM_CCER_CC3E_Msk         (0x1UL << TIM_CCER_CC3E_Pos)                  /*!< 0x00000100 */
#define TIM_CCER_CC3E             TIM_CCER_CC3E_Msk                            /*!<Capture/Compare 3 output enable                 */
#define TIM_CCER_CC3P_Pos         (9U)
#define TIM_CCER_CC3P_Msk         (0x1UL << TIM_CCER_CC3P_Pos)                  /*!< 0x00000200 */
#define TIM_CCER_CC3P             TIM_CCER_CC3P_Msk                            /*!<Capture/Compare 3 output Polarity               */
#define TIM_CCER_CC3NE_Pos        (10U)
#define TIM_CCER_CC3NE_Msk        (0x1UL << TIM_CCER_CC3NE_Pos)                 /*!< 0x00000400 */
#define TIM_CCER_CC3NE            TIM_CCER_CC3NE_Msk                           /*!<Capture/Compare 3 Complementary output enable   */
#define TIM_CCER_CC3NP_Pos        (11U)
#define TIM_CCER_CC3NP_Msk        (0x1UL << TIM_CCER_CC3NP_Pos)                 /*!< 0x00000800 */
#define TIM_CCER_CC3NP            TIM_CCER_CC3NP_Msk                           /*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos         (12U)
#define TIM_CCER_CC4E_Msk         (0x1UL << TIM_CCER_CC4E_Pos)                  /*!< 0x00001000 */
#define TIM_CCER_CC4E             TIM_CCER_CC4E_Msk                            /*!<Capture/Compare 4 output enable                 */
#define TIM_CCER_CC4P_Pos         (13U)
#define TIM_CCER_CC4P_Msk         (0x1UL << TIM_CCER_CC4P_Pos)                  /*!< 0x00002000 */
#define TIM_CCER_CC4P             TIM_CCER_CC4P_Msk                            /*!<Capture/Compare 4 output Polarity               */
#define TIM_CCER_CC4NP_Pos        (15U)
#define TIM_CCER_CC4NP_Msk        (0x1UL << TIM_CCER_CC4NP_Pos)                 /*!< 0x00008000 */
#define TIM_CCER_CC4NP            TIM_CCER_CC4NP_Msk                           /*!<Capture/Compare 4 Complementary output Polarity */


#define TIM_SR_UIF_Pos            (0U)
#define TIM_SR_UIF_Msk            (0x1UL << TIM_SR_UIF_Pos)                     /*!< 0x00000001 */
#define TIM_SR_UIF                TIM_SR_UIF_Msk                               /*!<Update interrupt Flag              */
#define TIM_SR_CC1IF_Pos          (1U)
#define TIM_SR_CC1IF_Msk          (0x1UL << TIM_SR_CC1IF_Pos)                   /*!< 0x00000002 */
#define TIM_SR_CC1IF              TIM_SR_CC1IF_Msk                             /*!<Capture/Compare 1 interrupt Flag   */
#define TIM_SR_CC2IF_Pos          (2U)
#define TIM_SR_CC2IF_Msk          (0x1UL << TIM_SR_CC2IF_Pos)                   /*!< 0x00000004 */
#define TIM_SR_CC2IF              TIM_SR_CC2IF_Msk                             /*!<Capture/Compare 2 interrupt Flag   */
#define TIM_SR_CC3IF_Pos          (3U)
#define TIM_SR_CC3IF_Msk          (0x1UL << TIM_SR_CC3IF_Pos)                   /*!< 0x00000008 */
#define TIM_SR_CC3IF              TIM_SR_CC3IF_Msk                             /*!<Capture/Compare 3 interrupt Flag   */
#define TIM_SR_CC4IF_Pos          (4U)
#define TIM_SR_CC4IF_Msk          (0x1UL << TIM_SR_CC4IF_Pos)                   /*!< 0x00000010 */
#define TIM_SR_CC4IF              TIM_SR_CC4IF_Msk                             /*!<Capture/Compare 4 interrupt Flag   */
#define TIM_SR_COMIF_Pos          (5U)
#define TIM_SR_COMIF_Msk          (0x1UL << TIM_SR_COMIF_Pos)                   /*!< 0x00000020 */
#define TIM_SR_COMIF              TIM_SR_COMIF_Msk                             /*!<COM interrupt Flag                 */
#define TIM_SR_TIF_Pos            (6U)
#define TIM_SR_TIF_Msk            (0x1UL << TIM_SR_TIF_Pos)                     /*!< 0x00000040 */
#define TIM_SR_TIF                TIM_SR_TIF_Msk                               /*!<Trigger interrupt Flag             */
#define TIM_SR_BIF_Pos            (7U)
#define TIM_SR_BIF_Msk            (0x1UL << TIM_SR_BIF_Pos)                     /*!< 0x00000080 */
#define TIM_SR_BIF                TIM_SR_BIF_Msk                               /*!<Break interrupt Flag               */
#define TIM_SR_CC1OF_Pos          (9U)
#define TIM_SR_CC1OF_Msk          (0x1UL << TIM_SR_CC1OF_Pos)                   /*!< 0x00000200 */
#define TIM_SR_CC1OF              TIM_SR_CC1OF_Msk                             /*!<Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos          (10U)
#define TIM_SR_CC2OF_Msk          (0x1UL << TIM_SR_CC2OF_Pos)                   /*!< 0x00000400 */
#define TIM_SR_CC2OF              TIM_SR_CC2OF_Msk                             /*!<Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos          (11U)
#define TIM_SR_CC3OF_Msk          (0x1UL << TIM_SR_CC3OF_Pos)                   /*!< 0x00000800 */
#define TIM_SR_CC3OF              TIM_SR_CC3OF_Msk                             /*!<Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos          (12U)
#define TIM_SR_CC4OF_Msk          (0x1UL << TIM_SR_CC4OF_Pos)                   /*!< 0x00001000 */
#define TIM_SR_CC4OF              TIM_SR_CC4OF_Msk                             /*!<Capture/Compare 4 Overcapture Flag */

#define TIM_DIER_UIE_Pos          (0U)
#define TIM_DIER_UIE_Msk          (0x1UL << TIM_DIER_UIE_Pos)                   /*!< 0x00000001 */
#define TIM_DIER_UIE              TIM_DIER_UIE_Msk                             /*!<Update interrupt enable */
#define TIM_DIER_CC1IE_Pos        (1U)
#define TIM_DIER_CC1IE_Msk        (0x1UL << TIM_DIER_CC1IE_Pos)                 /*!< 0x00000002 */
#define TIM_DIER_CC1IE            TIM_DIER_CC1IE_Msk                           /*!<Capture/Compare 1 interrupt enable   */
#define TIM_DIER_CC2IE_Pos        (2U)
#define TIM_DIER_CC2IE_Msk        (0x1UL << TIM_DIER_CC2IE_Pos)                 /*!< 0x00000004 */
#define TIM_DIER_CC2IE            TIM_DIER_CC2IE_Msk                           /*!<Capture/Compare 2 interrupt enable   */
#define TIM_DIER_CC3IE_Pos        (3U)
#define TIM_DIER_CC3IE_Msk        (0x1UL << TIM_DIER_CC3IE_Pos)                 /*!< 0x00000008 */
#define TIM_DIER_CC3IE            TIM_DIER_CC3IE_Msk                           /*!<Capture/Compare 3 interrupt enable   */
#define TIM_DIER_CC4IE_Pos        (4U)
#define TIM_DIER_CC4IE_Msk        (0x1UL << TIM_DIER_CC4IE_Pos)                 /*!< 0x00000010 */
#define TIM_DIER_CC4IE            TIM_DIER_CC4IE_Msk                           /*!<Capture/Compare 4 interrupt enable   */
#define TIM_DIER_COMIE_Pos        (5U)
#define TIM_DIER_COMIE_Msk        (0x1UL << TIM_DIER_COMIE_Pos)                 /*!< 0x00000020 */
#define TIM_DIER_COMIE            TIM_DIER_COMIE_Msk                           /*!<COM interrupt enable                 */
#define TIM_DIER_TIE_Pos          (6U)
#define TIM_DIER_TIE_Msk          (0x1UL << TIM_DIER_TIE_Pos)                   /*!< 0x00000040 */
#define TIM_DIER_TIE              TIM_DIER_TIE_Msk                             /*!<Trigger interrupt enable             */
#define TIM_DIER_BIE_Pos          (7U)
#define TIM_DIER_BIE_Msk          (0x1UL << TIM_DIER_BIE_Pos)                   /*!< 0x00000080 */
#define TIM_DIER_BIE              TIM_DIER_BIE_Msk                             /*!<Break interrupt enable               */
#define TIM_DIER_UDE_Pos          (8U)
#define TIM_DIER_UDE_Msk          (0x1UL << TIM_DIER_UDE_Pos)                   /*!< 0x00000100 */
#define TIM_DIER_UDE              TIM_DIER_UDE_Msk                             /*!<Update DMA request enable            */
#define TIM_DIER_CC1DE_Pos        (9U)
#define TIM_DIER_CC1DE_Msk        (0x1UL << TIM_DIER_CC1DE_Pos)                 /*!< 0x00000200 */
#define TIM_DIER_CC1DE            TIM_DIER_CC1DE_Msk                           /*!<Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos        (10U)
#define TIM_DIER_CC2DE_Msk        (0x1UL << TIM_DIER_CC2DE_Pos)                 /*!< 0x00000400 */
#define TIM_DIER_CC2DE            TIM_DIER_CC2DE_Msk                           /*!<Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos        (11U)
#define TIM_DIER_CC3DE_Msk        (0x1UL << TIM_DIER_CC3DE_Pos)                 /*!< 0x00000800 */
#define TIM_DIER_CC3DE            TIM_DIER_CC3DE_Msk                           /*!<Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos        (12U)
#define TIM_DIER_CC4DE_Msk        (0x1UL << TIM_DIER_CC4DE_Pos)                 /*!< 0x00001000 */
#define TIM_DIER_CC4DE            TIM_DIER_CC4DE_Msk                           /*!<Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos        (13U)
#define TIM_DIER_COMDE_Msk        (0x1UL << TIM_DIER_COMDE_Pos)                 /*!< 0x00002000 */
#define TIM_DIER_COMDE            TIM_DIER_COMDE_Msk                           /*!<COM DMA request enable               */
#define TIM_DIER_TDE_Pos          (14U)
#define TIM_DIER_TDE_Msk          (0x1UL << TIM_DIER_TDE_Pos)                   /*!< 0x00004000 */
#define TIM_DIER_TDE              TIM_DIER_TDE_Msk                             /*!<Trigger DMA request enable           */

#define TIM_EGR_UG_Pos                      (0U)
#define TIM_EGR_UG_Msk                      (0x1UL << TIM_EGR_UG_Pos)           /*!< 0x00000001 */
#define TIM_EGR_UG                          TIM_EGR_UG_Msk                     /*!<Update Generation */
#define TIM_EGR_CC1G_Pos                    (1U)
#define TIM_EGR_CC1G_Msk                    (0x1UL << TIM_EGR_CC1G_Pos)         /*!< 0x00000002 */
#define TIM_EGR_CC1G                        TIM_EGR_CC1G_Msk                   /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos                    (2U)
#define TIM_EGR_CC2G_Msk                    (0x1UL << TIM_EGR_CC2G_Pos)         /*!< 0x00000004 */
#define TIM_EGR_CC2G                        TIM_EGR_CC2G_Msk                   /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos                    (3U)
#define TIM_EGR_CC3G_Msk                    (0x1UL << TIM_EGR_CC3G_Pos)         /*!< 0x00000008 */
#define TIM_EGR_CC3G                        TIM_EGR_CC3G_Msk                   /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos                    (4U)
#define TIM_EGR_CC4G_Msk                    (0x1UL << TIM_EGR_CC4G_Pos)         /*!< 0x00000010 */
#define TIM_EGR_CC4G                        TIM_EGR_CC4G_Msk                   /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos                    (5U)
#define TIM_EGR_COMG_Msk                    (0x1UL << TIM_EGR_COMG_Pos)         /*!< 0x00000020 */
#define TIM_EGR_COMG                        TIM_EGR_COMG_Msk                   /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos                      (6U)
#define TIM_EGR_TG_Msk                      (0x1UL << TIM_EGR_TG_Pos)           /*!< 0x00000040 */
#define TIM_EGR_TG                          TIM_EGR_TG_Msk                     /*!<Trigger Generation */
#define TIM_EGR_BG_Pos                      (7U)
#define TIM_EGR_BG_Msk                      (0x1UL << TIM_EGR_BG_Pos)           /*!< 0x00000080 */
#define TIM_EGR_BG                          TIM_EGR_BG_Msk                     /*!<Break Generation */

#define TIM_BDTR_DTG_Pos                    (0U)
#define TIM_BDTR_DTG_Msk                    (0xFFUL << TIM_BDTR_DTG_Pos)        /*!< 0x000000FF */
#define TIM_BDTR_DTG                        TIM_BDTR_DTG_Msk                   /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0                      (0x01UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000001 */
#define TIM_BDTR_DTG_1                      (0x02UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000002 */
#define TIM_BDTR_DTG_2                      (0x04UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000004 */
#define TIM_BDTR_DTG_3                      (0x08UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000008 */
#define TIM_BDTR_DTG_4                      (0x10UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000010 */
#define TIM_BDTR_DTG_5                      (0x20UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000020 */
#define TIM_BDTR_DTG_6                      (0x40UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000040 */
#define TIM_BDTR_DTG_7                      (0x80UL << TIM_BDTR_DTG_Pos)        /*!< 0x00000080 */

#define TIM_BDTR_LOCK_Pos                   (8U)
#define TIM_BDTR_LOCK_Msk                   (0x3UL << TIM_BDTR_LOCK_Pos)        /*!< 0x00000300 */
#define TIM_BDTR_LOCK                       TIM_BDTR_LOCK_Msk                  /*!<LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_0                     (0x1UL << TIM_BDTR_LOCK_Pos)        /*!< 0x00000100 */
#define TIM_BDTR_LOCK_1                     (0x2UL << TIM_BDTR_LOCK_Pos)        /*!< 0x00000200 */

#define TIM_BDTR_OSSI_Pos                   (10U)
#define TIM_BDTR_OSSI_Msk                   (0x1UL << TIM_BDTR_OSSI_Pos)        /*!< 0x00000400 */
#define TIM_BDTR_OSSI                       TIM_BDTR_OSSI_Msk                  /*!<Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos                   (11U)
#define TIM_BDTR_OSSR_Msk                   (0x1UL << TIM_BDTR_OSSR_Pos)        /*!< 0x00000800 */
#define TIM_BDTR_OSSR                       TIM_BDTR_OSSR_Msk                  /*!<Off-State Selection for Run mode */
#define TIM_BDTR_BKE_Pos                    (12U)
#define TIM_BDTR_BKE_Msk                    (0x1UL << TIM_BDTR_BKE_Pos)         /*!< 0x00001000 */
#define TIM_BDTR_BKE                        TIM_BDTR_BKE_Msk                   /*!<Break enable */
#define TIM_BDTR_BKP_Pos                    (13U)
#define TIM_BDTR_BKP_Msk                    (0x1UL << TIM_BDTR_BKP_Pos)         /*!< 0x00002000 */
#define TIM_BDTR_BKP                        TIM_BDTR_BKP_Msk                   /*!<Break Polarity */
#define TIM_BDTR_AOE_Pos                    (14U)
#define TIM_BDTR_AOE_Msk                    (0x1UL << TIM_BDTR_AOE_Pos)         /*!< 0x00004000 */
#define TIM_BDTR_AOE                        TIM_BDTR_AOE_Msk                   /*!<Automatic Output enable */
#define TIM_BDTR_MOE_Pos                    (15U)
#define TIM_BDTR_MOE_Msk                    (0x1UL << TIM_BDTR_MOE_Pos)         /*!< 0x00008000 */
#define TIM_BDTR_MOE                        TIM_BDTR_MOE_Msk                   /*!<Main Output enable */

#define TIM_SMCR_SMS_Pos                    (0U)
#define TIM_SMCR_SMS_Msk                    (0x7UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000007 */
#define TIM_SMCR_SMS                        TIM_SMCR_SMS_Msk                   /*!<SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCR_SMS_0                      (0x1UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000001 */
#define TIM_SMCR_SMS_1                      (0x2UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000002 */
#define TIM_SMCR_SMS_2                      (0x4UL << TIM_SMCR_SMS_Pos)         /*!< 0x00000004 */

#define TIM_SMCR_TS_Pos                     (4U)
#define TIM_SMCR_TS_Msk                     (0x7UL << TIM_SMCR_TS_Pos)          /*!< 0x00000070 */
#define TIM_SMCR_TS                         TIM_SMCR_TS_Msk                    /*!<TS[2:0] bits (Trigger selection) */
#define TIM_SMCR_TS_0                       (0x1UL << TIM_SMCR_TS_Pos)          /*!< 0x00000010 */
#define TIM_SMCR_TS_1                       (0x2UL << TIM_SMCR_TS_Pos)          /*!< 0x00000020 */
#define TIM_SMCR_TS_2                       (0x4UL << TIM_SMCR_TS_Pos)          /*!< 0x00000040 */

#define TIM_SMCR_MSM_Pos                    (7U)
#define TIM_SMCR_MSM_Msk                    (0x1UL << TIM_SMCR_MSM_Pos)         /*!< 0x00000080 */
#define TIM_SMCR_MSM                        TIM_SMCR_MSM_Msk                   /*!<Master/slave mode */

#define TIM_SMCR_ETF_Pos                    (8U)
#define TIM_SMCR_ETF_Msk                    (0xFUL << TIM_SMCR_ETF_Pos)         /*!< 0x00000F00 */
#define TIM_SMCR_ETF                        TIM_SMCR_ETF_Msk                   /*!<ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0                      (0x1UL << TIM_SMCR_ETF_Pos)         /*!< 0x00000100 */
#define TIM_SMCR_ETF_1                      (0x2UL << TIM_SMCR_ETF_Pos)         /*!< 0x00000200 */
#define TIM_SMCR_ETF_2                      (0x4UL << TIM_SMCR_ETF_Pos)         /*!< 0x00000400 */
#define TIM_SMCR_ETF_3                      (0x8UL << TIM_SMCR_ETF_Pos)         /*!< 0x00000800 */

#define TIM_SMCR_ETPS_Pos                   (12U)
#define TIM_SMCR_ETPS_Msk                   (0x3UL << TIM_SMCR_ETPS_Pos)        /*!< 0x00003000 */
#define TIM_SMCR_ETPS                       TIM_SMCR_ETPS_Msk                  /*!<ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_0                     (0x1UL << TIM_SMCR_ETPS_Pos)        /*!< 0x00001000 */
#define TIM_SMCR_ETPS_1                     (0x2UL << TIM_SMCR_ETPS_Pos)        /*!< 0x00002000 */

#define TIM_SMCR_ECE_Pos                    (14U)
#define TIM_SMCR_ECE_Msk                    (0x1UL << TIM_SMCR_ECE_Pos)         /*!< 0x00004000 */
#define TIM_SMCR_ECE                        TIM_SMCR_ECE_Msk                   /*!<External clock enable */
#define TIM_SMCR_ETP_Pos                    (15U)
#define TIM_SMCR_ETP_Msk                    (0x1UL << TIM_SMCR_ETP_Pos)         /*!< 0x00008000 */
#define TIM_SMCR_ETP                        TIM_SMCR_ETP_Msk                   /*!<External trigger polarity */

#define TIM_OCMODE_TIMING                   0x00000000U                                              /*!< Frozen                                 */
#define TIM_OCMODE_ACTIVE                   TIM_CCMR1_OC1M_0                                         /*!< Set channel to active level on match   */
#define TIM_OCMODE_INACTIVE                 TIM_CCMR1_OC1M_1                                         /*!< Set channel to inactive level on match */
#define TIM_OCMODE_TOGGLE                   (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0)                    /*!< Toggle                                 */
#define TIM_OCMODE_PWM1                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1)                    /*!< PWM mode 1                             */
#define TIM_OCMODE_PWM2                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0) /*!< PWM mode 2                             */
#define TIM_OCMODE_FORCED_ACTIVE            (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0)                    /*!< Force active level                     */
#define TIM_OCMODE_FORCED_INACTIVE          TIM_CCMR1_OC1M_2                                         /*!< Force inactive level                   */

#define TIM_ICSELECTION_DIRECTTI           TIM_CCMR1_CC1S_0                     /*!< TIM Input 1, 2, 3 or 4 is selected to be
                                                                                     connected to IC1, IC2, IC3 or IC4, respectively */
#define TIM_ICSELECTION_INDIRECTTI         TIM_CCMR1_CC1S_1                     /*!< TIM Input 1, 2, 3 or 4 is selected to be
                                                                                     connected to IC2, IC1, IC4 or IC3, respectively */
#define TIM_ICSELECTION_TRC                TIM_CCMR1_CC1S                       /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to TRC */

#define TIM_TS_ITR0          0x00000000U                                                       /*!< Internal Trigger 0 (ITR0)              */
#define TIM_TS_ITR1          TIM_SMCR_TS_0                                                     /*!< Internal Trigger 1 (ITR1)              */
#define TIM_TS_ITR2          TIM_SMCR_TS_1                                                     /*!< Internal Trigger 2 (ITR2)              */
#define TIM_TS_ITR3          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1)                                   /*!< Internal Trigger 3 (ITR3)              */
#define TIM_TS_TI1F_ED       TIM_SMCR_TS_2                                                     /*!< TI1 Edge Detector (TI1F_ED)            */
#define TIM_TS_TI1FP1        (TIM_SMCR_TS_0 | TIM_SMCR_TS_2)                                   /*!< Filtered Timer Input 1 (TI1FP1)        */
#define TIM_TS_TI2FP2        (TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                                   /*!< Filtered Timer Input 2 (TI2FP2)        */
#define TIM_TS_ETRF          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                   /*!< Filtered External Trigger input (ETRF) */
#define TIM_TS_NONE          0x0000FFFFU                                                       /*!< No trigger selected                    */

#endif /* MCAL_TIM_PRIVATE_H_ */