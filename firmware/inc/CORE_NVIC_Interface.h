/**
 * @file CORE_NVIC_Interface.h
 * @brief This file contains the interface for the NVIC peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 *
 */

#ifndef CORE_NVIC_INTERFACE_H_
#define CORE_NVIC_INTERFACE_H_

/**
 * @headerfile <stdbool.h>
 * @brief This header file contains the definition of the boolean type.
 */
#include <stdbool.h>

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "STD_TYPES.h"

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief This header file contains the definitions for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @enum NVIC_Grouping_t
 * @brief The enumeration for the NVIC grouping options.
 */
typedef enum {
	Group16_NoneSub = 0b011,
	Group8_2Sub = 0b100,
	Group4_4Sub = 0b101,
	Group2_8Sub = 0b110,
	GroupNone_16SubGroup = 0b111
} NVIC_Grouping_t;

/**
 * @enum IRQ_State_t
 * @brief The enumeration for the NVIC interrupt state.
 */
typedef enum {
	NVIC_IRQ_DISABLE = 0,
	NVIC_IRQ_ENABLE = 1
} IRQ_State_t;

/**
 * @enum NVIC_CfgType
 * @brief The structure for the NVIC configuration.
 */
typedef struct {
	NVIC_Grouping_t NVIC_GroupBits;
	u8 NVIC_GroupID;
	u8 NVIC_SubGroupID;
} NVIC_CfgType;

/**
 * @brief The global variable for the NVIC configuration.
 */
extern NVIC_CfgType NVIC_G_Config;

/**
 * @brief This function enables the specified interrupt.
 *
 * @param Cp_xIRQId The interrupt ID.
 */
void COR_NVIC_vEnableInterrupt(IRQ_Num_t Cp_xIRQId);

/**
 * @brief This function disables the specified interrupt.
 *
 * @param Cp_xIRQId The interrupt ID.
 */
void COR_NVIC_vDisableInterrupt(IRQ_Num_t Cp_xIRQId);

/**
 * @brief This function sets the pending flag for the specified interrupt.
 *
 * @param Cp_xIRQId The interrupt ID.
 */
void COR_NVIC_vSetPendFlag(IRQ_Num_t Cp_xIRQId);

/**
 * @brief This function clears the pending flag for the specified interrupt.
 *
 * @param Cp_xIRQId The interrupt ID.
 */
void COR_NVIC_vClrPendFlag(IRQ_Num_t Cp_xIRQId);

/**
 * @brief This function gets the active flag for the specified interrupt.
 *
 * @param Cp_xIRQId The interrupt ID.
 *
 * @return The active flag.
 */
bool CR_NVIC_vGetActiveFlag(IRQ_Num_t Cp_xIRQId);

/**
 * @brief This function sets the priority configuration for the NVIC.
 *
 * @param Cp_u8PriorityOption The priority option.
 */
void COR_NVIC_vSetPriorityCfg(NVIC_Grouping_t Cp_u8PriorityOption);

/**
 * @brief This function sets the priority for the specified interrupt.
 *
 * @param Cp_xIRQId The interrupt ID.
 * @param Cp_u8GroupId The group ID.
 * @param Cp_u8SubGroupId The sub group ID.
 */
void COR_NVIC_vSetPriority(IRQ_Num_t Cp_xIRQId, u8 Cp_u8GroupId, u8 Cp_u8SubGroupId);

/**
 * @brief This function sets the software interrupt.
 *
 * @param Cp_IntNum The interrupt number.
 */
void COR_NVIC_vSetSoftwareInt(IRQ_Num_t Cp_IntNum);

#endif /* CORE_NVIC_INTERFACE_H_ */
