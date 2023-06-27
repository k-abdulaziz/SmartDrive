/**
 * @file CORE_NVIC_Private.h
 * @brief This file contains the private definitions for the NVIC peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef CORE_NVIC_PRIVATE_H_
#define CORE_NVIC_PRIVATE_H_

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief This header file contains the definitions for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "STD_TYPES.h"

/**
 * @struct NVIC_Reg_t
 * @brief The structure for the NVIC registers.
 */
typedef struct {

	/**
	 * @brief The interrupt enable register.
	 */
	vu32 NVIC_ISER[8];

	/**
	 * @brief Reserved.
	 */
	u32 resersed0[24];

	/**
	 * @brief The interrupt clear register.
	 */
	vu32 NVIC_ICER[8];

	/**
	 * @brief Reserved.
	 */
	u32 resersed1[24];

	/**
	 * @brief The interrupt set pending register.
	 */
	vu32 NVIC_ISPR[8];

	/**
	 * @brief Reserved.
	 */
	u32 resersed2[24];

	/**
	 * @brief The interrupt clear pending register.
	 */
	vu32 NVIC_ICPR[8];

	/**
	 * @brief Reserved.
	 */
	u32 resersed3[24];

	/**
	 * @brief The interrupt active bit register.
	 */
	vu32 NVIC_IABR[8];

	/**
	 * @brief Reserved.
	 */
	u32 resersed4[24];

	/**
	 * @brief The interrupt priority register.
	 */
	vu32 NVIC_IP[8];

	/**
	 * @brief Reserved.
	 */
	u32 resersed5[24];

	/**
	 * @brief The interrupt priority register.
	 */
	vu8 NVIC_IPR[240];

	/**
	 * @brief The software trigger interrupt register.
	 */
	vu32 NVIC_STIR;

} NVIC_Reg_t;


/**
 * @struct SCB_Reg_t
 * @brief The structure for the SCB registers.
 */
typedef struct {
	/**
	 * @brief The CPUID register.
	 */
	vu32 CPUID;

	/**
	 * @brief The interrupt controller status register.
	 */
	vu32 ICSR;

	/**
	 * @brief The vector table offset register.
	 */
	vu32 VTOR;

	/**
	 * @brief The application interrupt control register.
	 */
	vu32 AIRCR;

	/**
	 * @brief The system control register.
	 */
	vu32 SCR;

	/**
	 * @brief The control register.
	 */
	vu32 CCR;

	/**
	 * @brief The system handler priority registers 1.
	 */
	vu32 SHPR1;

	/**
	 * @brief The system handler priority registers 2.
	 */
	vu32 SHPR2;

	/**
	 * @brief The system handler priority registers 3.
	 */
	vu32 SHPR3;

	/**
	 * @brief The system handler control and status register.
	 */
	vu32 SHCSR;

	/**
	 * @brief The configurable fault status register.
	 */
	vu32 CFSR;

	/**
	 * @brief The hard fault status register.
	 */
	vu32 HFSR;

	/**
	 * @brief The debug fault status register.
	 */
	vu32 DFSR;

	/**
	 * @brief The memory management fault address register.
	 */
	vu32 MMFAR;

	/**
	 * @brief The bus fault address register.
	 */
	vu32 BFAR;

	/**
	 * @brief The auxiliary fault status register.
	 */
	vu32 AFSR;
} SCB_Reg_t;

/**
 * @def VECTKEY
 * @brief The value of the key used to access the NVIC registers.
 */
#define VECTKEY            0x5FA

/**
 * @def ACTLR_REG
 * @brief The address of the Auxiliary Control Register.
 */
#define ACTLR_REG          ((volatile u32 *)CORTEX_M4_PERIPHERALS_BASE+0x008)

/**
 * @def NVIC
 * @brief The base address of the NVIC registers.
 */
#define NVIC               ((volatile NVIC_Reg_t *)NVIC_BASE)

/**
 * @def SCB
 * @brief The base address of the SCB registers.
 */
#define SCB                ((volatile SCB_Reg_t *)SCB_BASE)

#endif /* CORE_NVIC_PRIVATE_H_ */
