/**
 * @file MCAL_GPIO_Interface.h
 * @brief This file contains the interface for the GPIO peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_GPIO_INTERFACE_H_
#define MCAL_GPIO_INTERFACE_H_

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "STD_TYPES.h"

/**
 * @headerfile "MCAL_EXTI_Private.h"
 * @brief This header file contains the private implementation of the EXTI peripheral.
 */
#include "MCAL_GPIO_Private.h"

/**
 * @enum GPIO_Pin_t
 * @brief This enum defines the GPIO pins.
 */
typedef enum {
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15,
} GPIO_Pin_t;

/**
 * @enum GPIO_Mode_t
 * @brief This enum defines the GPIO modes.
 */
typedef enum {
	GPIO_MODE_IN_FLOAT = 0b000000U, /**< Input floating mode */
	GPIO_MODE_IN_PU = 0b001000U, /**< Input pull-up mode */
	GPIO_MODE_IN_PD = 0b010000U, /**< Input pull-down mode */
	GPIO_MODE_OUT_PP = 0b000001U, /**< Output push-pull mode */
	GPIO_MODE_OUT_OD = 0b000101U, /**< Output open-drain mode */
	GPIO_MODE_AF_IN_PU = 0b001010U, /**< Alternate function input pull-up mode */
	GPIO_MODE_AF_IN_PD = 0b010010U, /**< Alternate function input pull-down mode */
	GPIO_MODE_AF_PP = 0b000010U, /**< Alternate function push-pull mode */
	GPIO_MODE_AF_OUT_OD = 0b000110U, /**< Alternate function open-drain mode */
	GPIO_MODE_ANALOG = 0b000011U, /**< Analog mode */
} GPIO_Mode_t;

/**
 * @enum GPIO_Speed_t
 * @brief This enum defines the GPIO speeds.
 */
typedef enum {
	GPIO_SPEED_LOW = 0, /**< Low speed */
	GPIO_SPEED_MEDIUM = 1, /**< Medium speed */
	GPIO_SPEED_HIGH = 2, /**< High speed */
	GPIO_SPEED_VERY_HIGH = 3, /**< Very high speed */
} GPIO_Speed_t;

/**
 * @def GPIO_PIN_MASK
 * @brief This macro defines the mask for the GPIO pin number.
 */
#define GPIO_PIN_MASK            0x0000FFFFU

/**
 * @struct GPIO_AF_TypeDef
 * @brief This enum defines the GPIO alternate functions.
 */
typedef enum {
	/**
	 * @brief System function.
	 */
	GPIO_AF0_SYSTEM = 0x00,
	/**
	 * @brief Alternate function TIM1 and TIM2.
	 */
	GPIO_AF1_TIM1_TIM2,
	/**
	 * @brief Alternate function TIM3 and TIM4.
	 */
	GPIO_AF2_TIM3_TIM4,
	/**
	 * @brief Alternate function TIM5, TIM9, TIM10 and TIM11.
	 */
	GPIO_AF3_TIM5_TIM9_TIM10_TIM11,
	/**
	 * @brief Alternate function I2C1, I2C2 and TIM8.
	 */
	GPIO_AF4_I2C1_I2C2_TIM8,
	/**
	 * @brief Alternate function SPI1, SPI2, I2S2 and I2S3.
	 */
	GPIO_AF5_SPI1_SPI2_I2S2_I2S3,
	/**
	 * @brief Alternate function SPI3 and I2S3.
	 */
	GPIO_AF6_SPI3_I2S3,
	/**
	 * @brief Alternate function USART1, USART2 and SPI1.
	 */
	GPIO_AF7_USART1_USART2_SPI1,
	/**
	 * @brief Alternate function USART6 and SPI3, I2S3.
	 */
	GPIO_AF8_USART6_SPI3_I2S3,
	/**
	 * @brief Alternate function CAN1, TIM12, TIM13 and TIM14.
	 */
	GPIO_AF9_CAN1_TIM12_TIM13_TIM14,
	/**
	 * @brief Alternate function OTG_FS and OTG_HS.
	 */
	GPIO_AF10_OTG_FS_OTG_HS,
	/**
	 * @brief Alternate function ETH.
	 */
	GPIO_AF11_ETH,
	/**
	 * @brief Alternate function FSMC, SDIO and OTG_HS.
	 */
	GPIO_AF12_FSMC_SDIO_OTG_HS,
	/**
	 * @brief Alternate function DCMI.
	 */
	GPIO_AF13_DCMI,
	/**
	 * @brief Alternate function LTDC.
	 */
	GPIO_AF14_LTDC,
	/**
	 * @brief Alternate function EVENTOUT.
	 */
	GPIO_AF15_EVENTOUT
} GPIO_AF_TypeDef;

/**
 * @struct GPIO_CfgType
 * @brief This struct defines the GPIO configuration.
 */
typedef struct {
	/**
	 * @brief GPIO selected pin.
	 *
	 * This parameter can be a value of @ref GPIO_Pin_define.
	 */
	GPIO_Pin_t GPIO_Pin;
	/**
	 * @brief Mode of GPIO selected port/pin.
	 *
	 * This parameter can be a value of @ref GPIO_Mode_define.
	 */
	GPIO_Mode_t GPIO_Mode;
	/**
	 * @brief Speed of GPIO selected port/pin.
	 *
	 * This parameter can be a value of @ref GPIO_Speed_define.
	 */
	uint8_t GPIO_Speed;
} GPIO_CfgType;

/**
 * @brief This extern declaration defines the GPIO_OUT_Config struct.
 */
extern GPIO_CfgType GPIO_OUT_Config;

/**
 * @brief This extern declaration defines the GPIO_IN_Config struct.
 */
extern GPIO_CfgType GPIO_IN_Config;

/**
 * @brief This function initializes the GPIO port.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_GPIO_Cfg The GPIO configuration structure.
 */
void MCL_GPIO_vInitPort(GPIO_TypeDef *GPIOx, GPIO_CfgType *Cp_GPIO_Cfg);

/**
 * @brief This function sets the GPIO pin configuration.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_GPIO_Cfg The GPIO configuration structure.
 */
void MCL_GPIO_vSetPinCfg(GPIO_TypeDef *GPIOx, GPIO_CfgType *Cp_GPIO_Cfg);

/**
 * @brief This function sets the GPIO pin mode.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_GPIO_Pin The GPIO pin to set the mode for.
 * @param Cp_GPIO_Mode The GPIO mode to set.
 * @param Cp_GPIO_Speed The GPIO speed to set.
 */
void
MCL_GPIO_vSetPinMode(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_GPIO_Pin, GPIO_Mode_t Cp_GPIO_Mode, GPIO_Speed_t Cp_GPIO_Speed);

/**
 * @brief This function sets the GPIO pin alternate function.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_PinId The GPIO pin to set the alternate function for.
 * @param Cp_AltFunc The GPIO alternate function to set.
 */
void MCL_GPIO_vSetPinAltFunc(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId, GPIO_AF_TypeDef Cp_AltFunc);

/**
 * @brief This function sets the GPIO pin value atomically.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_PinId The GPIO pin to set the value for.
 * @param Cp_xPinVal The GPIO pin value to set.
 */
void MCL_GPIO_vAtomicSetPin(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId, Pin_State_t Cp_xPinVal);

/**
 * @brief This function writes the specified value to the specified GPIO pins.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_u8StPin The start GPIO pin.
 * @param Cp_u8Length The number of GPIO pins to write.
 * @param Cp_u8Value The value to write to the GPIO pins.
 */
void MCL_GPIO_vWritePins(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_u8StPin, u8 Cp_u8Length, u8 Cp_u8Value);

/**
 * @brief This function reads the value of the specified GPIO pin.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_PinId The GPIO pin to read the value from.
 *
 * @return The value of the GPIO pin.
 */
u8 MCL_GPIO_u8GetPinVal(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId);

/**
 * @brief This function writes the specified value to the GPIO port.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_u32PortVal The value to write to the GPIO port.
 */
void MCL_GPIO_vWritePort(GPIO_TypeDef *GPIOx, u32 Cp_u32PortVal);

/**
 * @brief This function reads the value of the GPIO port.
 *
 * @param GPIOx The GPIO port to initialize.
 *
 * @return The value of the GPIO port.
 */
u32 MCL_GPIO_u32ReadPort(GPIO_TypeDef *GPIOx);

/**
 * @brief This function toggles the specified GPIO pin.
 *
 * @param GPIOx The GPIO port to initialize.
 * @param Cp_PinId The GPIO pin to toggle.
 */
void MCL_GPIO_vTogglePin(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId);

#endif /* MCAL_GPIO_INTERFACE_H_ */