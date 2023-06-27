/**
 * @file MCAL_EXTI_Private.h
 * @brief This file contains the private implementation of the EXTI peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_EXTI_PRIVATE_H_
#define MCAL_EXTI_PRIVATE_H_

/**
 * @headerfile "MCAL_EXTI_Private.h"
 * @brief This header file contains the private implementation of the EXTI peripheral.
 */
#include "MCAL_GPIO_Private.h"

/**
 * @struct	SYSCFG_Reg_t
 * @brief This structure defines the SYSCFG registers.
 */
typedef struct {
	/**
	 * @brief This register is used to remap the memory.
	 */
	vu32 MEMRMP;

	/**
	 * @brief This register is used to configure the peripheral mode.
	 */
	vu32 PMC;

	/**
	 * @brief This array of registers is used to configure the external interrupt lines.
	 */
	vu32 EXTICR[4];

	/**
	 * @brief Reserved.
	 */
	u32 RESERVED[2];

	/**
	 * @brief This register is used to configure the compensation cell.
	 */
	vu32 CMPCR;
} SYSCFG_Reg_t;

/**
 * @struct EXTI_Reg_t
 * @brief This structure defines the EXTI registers.
 */
typedef struct {

	/**
	 * @brief This register is used to mask the interrupts.
	 */
	vu32 IMR;

	/**
	 * @brief This register is used to enable the interrupts.
	 */
	vu32 EMR;

	/**
	 * @brief This register is used to set the rising trigger.
	 */
	vu32 RTSR;

	/**
	 * @brief This register is used to set the falling trigger.
	 */
	vu32 FTSR;

	/**
	 * @brief This register is used to generate software interrupt.
	 */
	vu32 SWIER;

	/**
	 * @brief This register is used to store the pending requests.
	 */
	vu32 PR;

} EXTI_Reg_t;

/**
 * @def SYSCFG
 * @brief This macro is used to get the base address of the SYSCFG peripheral.
 */
#define SYSCFG            ((SYSCFG_Reg_t *)SYSCFG_BASE)

/**
 * @def EXTI
 * @brief This macro is used to get the base address of the EXTI peripheral.
 */
#define EXTI              ((EXTI_Reg_t *)EXTI_BASE)

#endif /* MCAL_EXTI_PRIVATE_H_ */


