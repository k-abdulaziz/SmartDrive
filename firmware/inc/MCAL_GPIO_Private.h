/**
 * @file MCAL_GPIO_Private.h
 * @brief This file contains the private implementation of the GPIO peripheral driver.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_GPIO_PRIVATE_H_
#define MCAL_GPIO_PRIVATE_H_

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief Include the header file for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @struct GPIO_TypeDef
 * @brief Typedef for the GPIO peripheral register structure.
 */
typedef struct {
	vu32 GPIO_MODER; /*!< GPIO port mode register */
	vu32 GPIO_OTYPER; /*!< GPIO output type register */
	vu32 GPIO_OSPEEDR; /*!< GPIO output speed register */
	vu32 GPIO_PUPDR; /*!< GPIO pull-up/pull-down register */
	vu32 GPIO_IDR; /*!< GPIO input data register */
	vu32 GPIO_ODR; /*!< GPIO output data register */
	union {
		struct {
			vu32 BS: 16; /*!< Bit set/reset register */
			vu32 BR: 16; /*!< Bit set/reset register */
		} GPIO_BSRR_Bits;
		vu32 GPIO_BSRR; /*!< Bit set/reset register */
	};
	vu32 GPIO_LCKR; /*!< GPIO lock register */
	vu32 GPIO_AFR[2]; /*!< GPIO alternate function registers */
} GPIO_TypeDef;

/**
 * @def GPIOA
 * @brief Macro definitions for GPIO port A base addresses.
 */
#define GPIOA                ((GPIO_TypeDef *)GPIOA_BASE)

/**
 * @def GPIOB
 * @brief Macro definitions for GPIO port B base addresses.
 */
#define GPIOB                ((GPIO_TypeDef *)GPIOB_BASE)

/**
 * @def GPIOC
 * @brief Macro definitions for GPIO port C base addresses.
 */
#define GPIOC                ((GPIO_TypeDef *)GPIOC_BASE)

/**
 * @def GPIO_MODER_MODE6_1
 * @brief Macro definitions for GPIO port mode register bit fields.
 */
#define GPIO_MODER_MODE6_1       (1U << 13) /*!< PA6 mode 10: Output mode, push-pull */

/**
 * @def GPIO_MODER_MODE6
 * @brief Macro definitions for GPIO port mode register bit fields.
 */
#define GPIO_MODER_MODE6         (3U << 12) /*!< PA6 mode 11: Output mode, open-drain */

/**
 * @def	GPIO_AFRL_AFRL6_1
 * @brief Macro definitions for GPIO alternate function register bit fields.
 */
#define GPIO_AFRL_AFRL6_1        (1U << 13) /*!< PA6 alternate function 1 */

/**
 * @def	GPIO_AFRL_AFRL6
 * @brief Macro definitions for GPIO alternate function register bit fields.
 */
#define GPIO_AFRL_AFRL6          (15U << 12) /*!< PA6 alternate function 15 */

/**
 * @def	GPIO_OTYPER_OT6
 * @brief Macro definitions for GPIO output type register bit field for PA6.
 */
#define GPIO_OTYPER_OT6         (1U << 6) /*!< PA6 output type: push-pull */

/**
 * @def GPIO_OSPEEDR_OSPEED6
 * @brief Macro definitions for GPIO output speed register bit field for PA6.
 */
#define GPIO_OSPEEDR_OSPEED6    (3U << 12) /*!< PA6 output speed: medium speed */

/**
 * @def	GPIO_PUPDR_PUPD6
 * @brief Macro definitions for GPIO pull-up/pull-down register bit field for PA6.
 */
#define GPIO_PUPDR_PUPD6        (3U << 12) /*!< PA6 pull-up/pull-down: pull-up */

/**
 * @brief Selects the GPIO port index based on the GPIO peripheral pointer.
 *
 * @param GPIOx Pointer to the GPIO peripheral.
 * @return The corresponding GPIO port index.
 */
GPIO_Port_t GPIO_xSelectPortIndex(GPIO_TypeDef *GPIOx);

/**
 * @brief Selects the GPIO peripheral register structure based on the GPIO port index.
 *
 * @param GPIO_PortIndex The index of the GPIO port.
 * @return Pointer to the corresponding GPIO peripheral register structure.
 */
GPIO_TypeDef *GPIO_xSelectReg(GPIO_Port_t GPIO_PortIndex);

#endif /* MCAL_GPIO_PRIVATE_H_ */
