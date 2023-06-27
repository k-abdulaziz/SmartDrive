/**
 * @file MCAL_EXTI_Interface.h
 * @brief This file contains the interface for the EXTI peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_EXTI_INTERFACE_H_
#define MCAL_EXTI_INTERFACE_H_

/**
 * @headerfile "BIT_MATH.h"
 * @brief This header file contains the Bit Math operations.
 */
#include "BIT_MATH.h"

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */

#include "STD_TYPES.h"

/**
 * @headerfile "MCAL_GPIO_Interface.h"
 * @brief This header file contains the interface for the GPIO peripheral.
 */
#include "MCAL_GPIO_Interface.h"

/**
 * @headerfile "MCAL_EXTI_Private.h"
 * @brief This header file contains the private implementation of the EXTI peripheral.
 */
#include "MCAL_EXTI_Private.h"

/**
 * @headerfile "CORE_NVIC_Interface.h"
 * @brief This header file contains the interface for the NVIC peripheral.
 */
#include "CORE_NVIC_Interface.h"

/**
 * @enum EXTI_Line_t
 * @brief This enumeration defines the EXTI lines.
 */
typedef enum {
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15,
} EXTI_Line_t;

/**
 * @enum EXTIRQ_Src_t
 * @brief This enumeration defines the EXTIRQ sources.
 */
typedef enum {
	EXTIRQ0_A0,
	EXTIRQ1_A1,
	EXTIRQ2_A2,
	EXTIRQ3_A3,
	EXTIRQ4_A4,
	EXTIRQ5_A5,
	EXTIRQ6_A6,
	EXTIRQ7_A7,
	EXTIRQ8_A8,
	EXTIRQ9_A9,
	EXTIRQ10_A10,
	EXTIRQ11_A11,
	EXTIRQ12_A12,
	EXTIRQ13_A13,
	EXTIRQ14_A14,
	EXTIRQ15_A15,

	EXTIRQ16_B0,
	EXTIRQ17_B1,
	EXTIRQ18_B2,
	EXTIRQ19_B3,
	EXTIRQ20_B4,
	EXTIRQ21_B5,
	EXTIRQ22_B6,
	EXTIRQ23_B7,
	EXTIRQ24_B8,
	EXTIRQ25_B9,
	EXTIRQ26_B10,
	EXTIRQ27_B11,
	EXTIRQ28_B12,
	EXTIRQ29_B13,
	EXTIRQ30_B14,
	EXTIRQ31_B15,

	EXTIRQ32_C0,
	EXTIRQ33_C1,
	EXTIRQ34_C2,
	EXTIRQ35_C3,
	EXTIRQ36_C4,

} EXTIRQ_Src_t;

/**
 * @enum EXTI_Sense_t
 * @brief This enumeration defines the EXTI edge trigger types.
 */
typedef enum {
	EXTI_LOW_LEVEL = 0,
	EXTI_ON_CHANGE = 1,
	EXTI_FALLING_EDGE = 2,
	EXTI_RISING_EDGE = 3,
} EXTI_Sense_t;

/**
 * @struct EXTI_GPIO_Mapping_t
 * @brief This structure defines the EXTI pin configuration.
 */
typedef struct {
	/**
	 * @brief This field selects the EXTI input line number.
	 *
	 * This parameter can be a value of  @ref EXTI_LineNumber
	 */
	EXTI_Line_t EXTI_LineNum;

	/**
	 * @brief This field selects the GPIO port to be used as EXTI port.
	 *
	 * This parameter can be a peripheral instant @ MCU DEVICE HEADER
	 */
	GPIO_TypeDef *GPIO_Port;

	/**
	 * @brief This field selects the GPIO pin to be used as EXTI pin.
	 *
	 * This parameter can be a value of  @ref GPIO_Pins_define @ MCU GPIO Driver
	 */
	GPIO_Pin_t GPIO_Pin;

	/**
	 * @brief This field selects the Interrupt Vector Table request number.
	 *
	 * This parameter can be a value of @ref IVT_IRQNumber @ MCU DEVICE HEADER
	 */
	IRQ_Num_t IVT_IRQNumber;
} EXTI_GPIO_Mapping_t;

/**
 * @brief This global variable defines the EXTI GPIO mapping array.
 */
extern EXTI_GPIO_Mapping_t EXTI_Mapping[];

/**
 * @brief This structure defines the EXTI pin configuration.
 *
 * @details This structure contains the following fields:
 *
 *   * EXTI_PinMap: This field selects the EXTI input pin.
 *   * EXTI_Priority: This field selects the IRQ Priority group and subgroup.
 *   * Trigger_State: This field selects the trigger state (edge trigger).
 *   * IRQ_EN: This field selects the pending request register state.
 *   * IRQ_pCallBack: This field is a pointer to the IRQ callback function.
 */
typedef struct {
	/**
	 * @brief This field selects the EXTI input pin.
	 *
	 * This parameter can be a value of  @ref EXTI_define
	 */
	EXTI_GPIO_Mapping_t EXTI_PinMap;

	/**
	 * @brief This field selects the IRQ Priority group and subgroup.
	 */
	NVIC_CfgType EXTI_Priority;

	/**
	 * @brief This field selects the trigger state (edge trigger).
	 *
	 * This parameter can be a value of
	 */
	EXTI_Sense_t Trigger_State;

	/**
	 * @brief This field selects the pending request register state.
	 *
	 * This parameter can be a value of  @ref EXTI_IRQ_EN_define (INT_MASK + NVIC Enable/Disable)
	 */
	bool IRQ_EN;

	/**
	 * @brief This field is a pointer to the IRQ callback function.
	 */
	void (*IRQ_pCallBack)(void);
} EXTI_PinCfg_t;

/**
 * @brief This global variable defines the EXTI pin configuration array.
 */
extern EXTI_PinCfg_t EXTI_G_Cfg[];

/**
 * @brief This function is used to initialize the EXTI peripheral.
 *
 * @param [in] Cp_EXTI_Cfg Pointer to the EXTI pin configuration structure.
 *
 * @return None.
 */
void MCL_EXTI_vInit(EXTI_PinCfg_t *Cp_EXTI_Cfg);

/**
 * @brief This function is used to initialize the GPIO peripheral for EXTI.
 *
 * @param [in] GPIOx Pointer to the GPIO peripheral.
 * @param [in] Cp_EXTIPin GPIO pin number.
 *
 * @return None.
 */
void MCL_EXTI_vInitGPIO(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_EXTIPin);

/**
 * @brief This function is used to enable the EXTI interrupt.
 *
 * @param [in] Cp_EXTI_Cfg Pointer to the EXTI pin configuration structure.
 * @param [in] Lc_pCallBackFn Pointer to the IRQ callback function.
 *
 * @return None.
 */
void MCL_EXTI_vEnable(EXTI_PinCfg_t *Cp_EXTI_Cfg, void (*Lc_pCallBackFn)(void));

/**
 * @brief This function is used to disable the EXTI interrupt.
 *
 * @param [in] Cp_xLineNo EXTI line number.
 *
 * @return None.
 */
void MCL_EXTI_vDisable(EXTI_Line_t Cp_xLineNo);

#endif /* MCAL_EXTI_INTERFACE_H_ */