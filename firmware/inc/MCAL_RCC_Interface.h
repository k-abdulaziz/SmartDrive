/**
 * @file MCAL_RCC_Interface.h
 * @brief This file contains the interface functions of the MCAL_RCC driver.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_RCC_INTERFACE_H_
#define MCAL_RCC_INTERFACE_H_

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "STD_TYPES.h"

/**
 * @headerfile "MCAL_RCC_Config.h"
 * @brief Include the header file for the RCC configurations.
 */
#include "MCAL_RCC_Config.h"

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief Include the header file for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @struct RCC_CfgType
 * @brief This structure contains the configuration parameters of the RCC driver.
 */
typedef struct {
	SysClk_t System_ClkSelection; /**< The system clock selection. */
	u32 System_ClkFreq; /**< The system clock frequency. */
	SysClk_Prescaler_t System_ClkPrescaler; /**< The system clock prescaler. */
	ClkType_t System_ClkType; /**< The system clock type. */
} RCC_CfgType;

/**
 * @brief The global configuration of the RCC driver.
 */
extern RCC_CfgType RCC_G_Config;

/**
 * @brief This function initializes the system clock.
 *
 * @param Cp_xRCC_Cfg The pointer to the RCC configuration structure.
 */
void MCL_RCC_vInitSysClk(RCC_CfgType *Cp_xRCC_Cfg);

/**
 * @brief This function enables the peripheral clock.
 *
 * @param Cp_u8SysBus The system bus.
 * @param Cp_u8Periph The peripheral.
 */
void MCL_RCC_vEnablePeriphClk(SysBus_t Cp_u8SysBus, u8 Cp_u8Periph);

/**
 * @brief This function disables the peripheral clock.
 *
 * @param Cp_u8SysBus The system bus.
 * @param Cp_u8Periph The peripheral.
 */
void MCL_RCC_vDisablePeriphClk(SysBus_t Cp_u8SysBus, u8 Cp_u8Periph);

/**
 * @brief This function gets the system clock frequency.
 *
 * @return The system clock frequency.
 */
u32 MCL_RCC_GetSYSCLKFreq(void);

/**
 * @brief This function gets the HCLK frequency.
 *
 * @return The HCLK frequency.
 */
u32 MCL_RCC_GetHCLKFreq(void);

/**
 * @brief This function gets the PCLK1 frequency.
 *
 * @return The PCLK1 frequency.
 */
u32 MCL_RCC_GetPCLK1Freq(void);

/**
 * @brief This function gets the PCLK2 frequency.
 *
 * @return The PCLK2 frequency.
 */
u32 MCL_RCC_GetPCLK2Freq(void);

#endif /* MCAL_RCC_INTERFACE_H_ */
