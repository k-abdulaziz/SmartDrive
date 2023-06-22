#ifndef MCAL_GPIO_PRIVATE_H_
#define MCAL_GPIO_PRIVATE_H_

#include "STM32F4xx_Device_Header.h"

typedef struct {
	vu32 GPIO_MODER;
	vu32 GPIO_OTYPER;
	vu32 GPIO_OSPEEDR;
	vu32 GPIO_PUPDR;
	vu32 GPIO_IDR;
	vu32 GPIO_ODR;
	union {
		struct {
			vu32 BS: 16;
			vu32 BR: 16;
		} GPIO_BSRR_Bits;
		vu32 GPIO_BSRR;
	};
	vu32 GPIO_LCKR;
	vu32 GPIO_AFR[2];
} GPIO_TypeDef;

#define GPIOA                ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                ((GPIO_TypeDef *)GPIOC_BASE)

// GPIO port mode register (MODER) bit fields
#define GPIO_MODER_MODE6_1       (1U << 13)
#define GPIO_MODER_MODE6         (3U << 12)

// GPIO alternate function register (AFRL) bit fields
#define GPIO_AFRL_AFRL6_1        (1U << 13)
#define GPIO_AFRL_AFRL6          (15U << 12)

// GPIO output type register (OTYPER) bit field for PA6
#define GPIO_OTYPER_OT6         (1U << 6)

// GPIO output speed register (OSPEEDR) bit field for PA6
#define GPIO_OSPEEDR_OSPEED6    (3U << 12)

// GPIO pull-up/pull-down register (PUPDR) bit field for PA6
#define GPIO_PUPDR_PUPD6        (3U << 12)

GPIO_Port_t GPIO_xSelectPortIndex(GPIO_TypeDef *GPIOx);

GPIO_TypeDef *GPIO_xSelectReg(GPIO_Port_t GPIO_PortIndex);

#endif /* MCAL_GPIO_PRIVATE_H_ */
