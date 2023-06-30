/**
 * @file STM32F4XX_DEVICE_HEADER_H_
 * @brief This file contains the device headers for STM32F4XX.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef STM32F4XX_DEVICE_HEADER_H_
#define STM32F4XX_DEVICE_HEADER_H_

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "STD_TYPES.h"

/**
 * @def __IO
 * @brief Macro used to define volatile memory access.
 *
 * This macro is used to define volatile memory access. It is commonly used to define volatile variables.
 */

#define __IO    volatile

/**
 * @def FLASH_MEMORY_BASE
 * @brief Base address of the flash memory.
 *
 * This macro defines the base address of the flash memory.
 */

#define FLASH_MEMORY_BASE              0x08000000UL

/**
 * @def SYSTEM_MEMORY_BASE
 * @brief Base address of the system memory.
 *
 * This macro defines the base address of the system memory.
 */

#define SYSTEM_MEMORY_BASE             0x1FFFF000UL

/**
 * @def SRAM_BASE
 * @brief Base address of the SRAM.
 *
 * This macro defines the base address of the SRAM (Static Random Access Memory).
 */

#define SRAM_BASE                      0x20000000UL

/**
 * @def CORTEX_M4_PERIPH_BASE
 * @brief Base address of the Cortex-M4 peripherals.
 *
 * This macro defines the base address of the Cortex-M4 peripherals.
 */

#define CORTEX_M4_PERIPH_BASE          0xE000E000UL

/**
 * @def PERIPH_BASE
 * @brief Base address of the peripheral memory map.
 *
 * This macro defines the base address of the peripheral memory map.
 */

#define PERIPH_BASE                    0x40000000UL

/**
 * @def APB1PERIPH_BASE
 * @brief Base address of the APB1 peripherals.
 *
 * This macro defines the base address of the APB1 peripherals.
 */

#define APB1PERIPH_BASE                PERIPH_BASE

/**
 * @def APB2PERIPH_BASE
 * @brief Base address of the APB2 peripherals.
 *
 * This macro defines the base address of the APB2 peripherals.
 */

#define APB2PERIPH_BASE                (PERIPH_BASE + 0x00010000UL)

/**
 * @def AHBPERIPH_BASE
 * @brief Base address of the AHB peripherals.
 *
 * This macro defines the base address of the AHB (Advanced High-Performance Bus) peripherals.
 */

#define AHBPERIPH_BASE                 (PERIPH_BASE + 0x00020000UL)

/**
 * @def SYSTICK_BASE
 * @brief Base address of the SysTick.
 *
 * This macro defines the base address of the SysTick peripheral.
 */

#define SYSTICK_BASE                   (CORTEX_M4_PERIPH_BASE +  0x0010UL)

/**
 * @def NVIC_BASE
 * @brief Base address of the NVIC (Nested Vectored Interrupt Controller).
 *
 * This macro defines the base address of the NVIC (Nested Vectored Interrupt Controller).
 */

#define NVIC_BASE                      (CORTEX_M4_PERIPH_BASE +  0x0100UL)

/**
 * @def SCB_BASE
 * @brief Base address of the SCB (System Control Block).
 *
 * This macro defines the base address of the SCB (System Control Block).
 */

#define SCB_BASE                       (CORTEX_M4_PERIPH_BASE +  0x0D00UL)

/**
 * @def TIM2_BASE
 * @brief Base address of the TIM2 peripheral.
 *
 * This macro defines the base address of the TIM2 (Timer 2) peripheral.
 */

#define TIM2_BASE                       (APB1PERIPH_BASE + 0x0000UL)

/**
 * @def TIM3_BASE
 * @brief Base address of the TIM3 peripheral.
 *
 * This macro defines the base address of the TIM3 (Timer 3) peripheral.
 */

#define TIM3_BASE                       (APB1PERIPH_BASE + 0x0400UL)

/**
 * @def TIM4_BASE
 * @brief Base address of the TIM4 peripheral.
 *
 * This macro defines the base address of the TIM4 (Timer 4) peripheral.
 */

#define TIM4_BASE                       (APB1PERIPH_BASE + 0x0800UL)

/**
 * @def SYSCFG_BASE
 * @brief Base address of the SYSCFG peripheral.
 *
 * This macro defines the base address of the SYSCFG peripheral.
 */

#define SYSCFG_BASE                     (PERIPH_BASE + 0x0013800)

/**
 * @def EXTI_BASE
 * @brief Base address of the EXTI (External Interrupt/Event Controller) peripheral.
 *
 * This macro defines the base address of the EXTI peripheral.
 */

#define EXTI_BASE                       (PERIPH_BASE + 0x0013C00)

/**
 * @def TIM1_BASE
 * @brief Base address of the TIM1 peripheral.
 *
 * This macro defines the base address of the TIM1 (Timer 1) peripheral.
 */

#define TIM1_BASE                       (APB2PERIPH_BASE + 0x0000UL)

/**
 * @def RCC_BASE
 * @brief Base address of the RCC (Reset and Clock Control) peripheral.
 *
 * This macro defines the base address of the RCC peripheral.
 */

#define RCC_BASE                        (PERIPH_BASE + 0x00023800UL)

/**
 * @def GPIOA_BASE
 * @brief Base address of the GPIOA peripheral.
 *
 * This macro defines the base address of the GPIOA peripheral.
 */

#define GPIOA_BASE                      (PERIPH_BASE + 0x00020000UL)

/**
 * @def GPIOB_BASE
 * @brief Base address of the GPIOB peripheral.
 *
 * This macro defines the base address of the GPIOB peripheral.
 */

#define GPIOB_BASE                      (PERIPH_BASE + 0x00020400UL)

/**
 * @def GPIOC_BASE
 * @brief Base address of the GPIOC peripheral.
 *
 * This macro defines the base address of the GPIOC peripheral.
 */

#define GPIOC_BASE                      (PERIPH_BASE + 0x00020800UL)

/**
 * @def GPIOD_BASE
 * @brief Base address of the GPIOD peripheral.
 *
 * This macro defines the base address of the GPIOD peripheral.
 */

#define GPIOD_BASE                      (PERIPH_BASE + 0x00020C00UL)

/**
 * @def GPIOE_BASE
 * @brief Base address of the GPIOE peripheral.
 *
 * This macro defines the base address of the GPIOE peripheral.
 */

#define GPIOE_BASE                      (PERIPH_BASE + 0x00021000UL)

/**
 * @def GPIOH_BASE
 * @brief Base address of the GPIOH peripheral.
 *
 * This macro defines the base address of the GPIOH peripheral.
 */

#define GPIOH_BASE                      (PERIPH_BASE + 0x00021C00UL)

/**
 * @enum GPIO_Port_t
 * @brief Enumeration of GPIO ports.
 *
 * This enumeration defines the available GPIO ports, such as GPIO_PORTA, GPIO_PORTB, GPIO_PORTC.
 */

typedef enum {
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
} GPIO_Port_t;

/**
 * @enum USART_Index_t
 * @brief Enumeration of USART indexes.
 *
 * This enumeration defines the indexes for USART peripherals, such as USART1_INDEX, USART2_INDEX, USART3_INDEX.
 */

typedef enum {
	USART1_INDEX = 0,
	USART2_INDEX = 1,
	USART3_INDEX = 2,
} USART_Index_t;

/**
 * @enum SysBus_t
 * @brief Enumeration of system buses.
 *
 * This enumeration defines the available system buses, such as APB1_BUS, APB2_BUS, AHB1_BUS, AHB2_BUS.
 */

typedef enum {
	APB1_BUS,
	APB2_BUS,
	AHB1_BUS,
	AHB2_BUS
} SysBus_t;

/**
 * @enum SysClk_t
 * @brief Enumeration of system clock sources.
 *
 * This enumeration defines the available system clock sources, such as HSI_CLOCK, HSE_CLOCK, PLL_CLOCK.
 */

typedef enum {
	HSI_CLOCK,
	HSE_CLOCK,
	PLL_CLOCK
} SysClk_t;

/**
 * @enum ClkType_t
 * @brief Enumeration of clock types.
 *
 * This enumeration defines the types of clock sources, such as RC_CLOCK, CRYSTAL_CLOCK.
 */

typedef enum {
	RC_CLOCK,
	CRYSTAL_CLOCK,
} ClkType_t;

/**
 * @enum Pin_State_t
 * @brief Enumeration of pin states.
 *
 * This enumeration defines the states of a pin, such as PIN_RESET, PIN_SET.
 */

typedef enum {
	PIN_RESET = 0,
	PIN_SET = 1,
} Pin_State_t;

/**
 * @enum SysClk_Prescaler_t
 * @brief Enumeration of system clock prescaler options.
 *
 * This enumeration defines the available options for system clock prescaler. It represents the prescaler values used to divide the system clock frequency.
 * The options include SYSCLK_NOT_DIVIDE, SYSCLK_PRESCALER_BY2, SYSCLK_PRESCALER_BY4, SYSCLK_PRESCALER_BY8, SYSCLK_PRESCALER_BY16, SYSCLK_PRESCALER_BY64, SYSCLK_PRESCALER_BY128, SYSCLK_PRESCALER_BY256, SYSCLK_PRESCALER_BY512.
 */

typedef enum {
	SYSCLK_NOT_DIVIDE = 0000,
	SYSCLK_PRESCALER_BY2 = 1000,
	SYSCLK_PRESCALER_BY4 = 1001,
	SYSCLK_PRESCALER_BY8 = 1010,
	SYSCLK_PRESCALER_BY16 = 1011,
	SYSCLK_PRESCALER_BY64 = 1100,
	SYSCLK_PRESCALER_BY128 = 1101,
	SYSCLK_PRESCALER_BY256 = 1110,
	SYSCLK_PRESCALER_BY512 = 1111
} SysClk_Prescaler_t;

/**
 * @enum IRQ_Num_t
 * @brief Enumeration of interrupt numbers for Cortex-M4 and STM32 specific interrupts.
 *
 * This enumeration defines the interrupt numbers for Cortex-M4 processor exceptions and STM32 specific interrupts.
 * The enumeration values represent the interrupt numbers associated with each interrupt source.
 * The Cortex-M4 processor exceptions include NonMaskableInt_IRQn, MemoryManagement_IRQn, BusFault_IRQn, UsageFault_IRQn, SVCall_IRQn,
 * DebugMonitor_IRQn, PendSV_IRQn, and SysTick_IRQn.
 * The STM32 specific interrupts include various interrupt numbers such as WWDG_IRQn, PVD_IRQn, TAMP_STAMP_IRQn, RTC_WKUP_IRQn, FLASH_IRQn,
 * RCC_IRQn, EXTI0_IRQn, EXTI1_IRQn, EXTI2_IRQn, EXTI3_IRQn, EXTI4_IRQn, DMA1_Stream0_IRQn, DMA1_Stream1_IRQn, DMA1_Stream2_IRQn, and so on.
 */
typedef enum {
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
	NonMaskableInt_IRQn = -14,    /*!< 2 Non Maskable Interrupt                                          */
	MemoryManagement_IRQn = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
	BusFault_IRQn = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
	UsageFault_IRQn = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
	SVCall_IRQn = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
	DebugMonitor_IRQn = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
	PendSV_IRQn = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
	SysTick_IRQn = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
	WWDG_IRQn = 0,      /*!< Window WatchDog Interrupt                                         */
	PVD_IRQn = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
	TAMP_STAMP_IRQn = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
	RTC_WKUP_IRQn = 3,      /*!< RTC Wakeup interrupt through the EXTI line                        */
	FLASH_IRQn = 4,      /*!< FLASH global Interrupt                                            */
	RCC_IRQn = 5,      /*!< RCC global Interrupt                                              */
	EXTI0_IRQn = 6,      /*!< EXTI Line0 Interrupt                                              */
	EXTI1_IRQn = 7,      /*!< EXTI Line1 Interrupt                                              */
	EXTI2_IRQn = 8,      /*!< EXTI Line2 Interrupt                                              */
	EXTI3_IRQn = 9,      /*!< EXTI Line3 Interrupt                                              */
	EXTI4_IRQn = 10,     /*!< EXTI Line4 Interrupt                                              */
	DMA1_Stream0_IRQn = 11,     /*!< DMA1 Stream 0 global Interrupt                                    */
	DMA1_Stream1_IRQn = 12,     /*!< DMA1 Stream 1 global Interrupt                                    */
	DMA1_Stream2_IRQn = 13,     /*!< DMA1 Stream 2 global Interrupt                                    */
	DMA1_Stream3_IRQn = 14,     /*!< DMA1 Stream 3 global Interrupt                                    */
	DMA1_Stream4_IRQn = 15,     /*!< DMA1 Stream 4 global Interrupt                                    */
	DMA1_Stream5_IRQn = 16,     /*!< DMA1 Stream 5 global Interrupt                                    */
	DMA1_Stream6_IRQn = 17,     /*!< DMA1 Stream 6 global Interrupt                                    */
	ADC_IRQn = 18,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
	EXTI9_5_IRQn = 23,     /*!< External Line[9:5] Interrupts                                     */
	TIM1_BRK_TIM9_IRQn = 24,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
	TIM1_UP_TIM10_IRQn = 25,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
	TIM1_TRG_COM_TIM11_IRQn = 26,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
	TIM1_CC_IRQn = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
	TIM2_IRQn = 28,     /*!< TIM2 global Interrupt                                             */
	TIM3_IRQn = 29,     /*!< TIM3 global Interrupt                                             */
	TIM4_IRQn = 30,     /*!< TIM4 global Interrupt                                             */
	I2C1_EV_IRQn = 31,     /*!< I2C1 Event Interrupt                                              */
	I2C1_ER_IRQn = 32,     /*!< I2C1 Error Interrupt                                              */
	I2C2_EV_IRQn = 33,     /*!< I2C2 Event Interrupt                                              */
	I2C2_ER_IRQn = 34,     /*!< I2C2 Error Interrupt                                              */
	SPI1_IRQn = 35,     /*!< SPI1 global Interrupt                                             */
	SPI2_IRQn = 36,     /*!< SPI2 global Interrupt                                             */
	USART1_IRQn = 37,     /*!< USART1 global Interrupt                                           */
	USART2_IRQn = 38,     /*!< USART2 global Interrupt                                           */
	EXTI15_10_IRQn = 40,     /*!< External Line[15:10] Interrupts                                   */
	RTC_Alarm_IRQn = 41,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
	OTG_FS_WKUP_IRQn = 42,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
	DMA1_Stream7_IRQn = 47,     /*!< DMA1 Stream7 Interrupt                                            */
	SDIO_IRQn = 49,     /*!< SDIO global Interrupt                                             */
	TIM5_IRQn = 50,     /*!< TIM5 global Interrupt                                             */
	SPI3_IRQn = 51,     /*!< SPI3 global Interrupt                                             */
	DMA2_Stream0_IRQn = 56,     /*!< DMA2 Stream 0 global Interrupt                                    */
	DMA2_Stream1_IRQn = 57,     /*!< DMA2 Stream 1 global Interrupt                                    */
	DMA2_Stream2_IRQn = 58,     /*!< DMA2 Stream 2 global Interrupt                                    */
	DMA2_Stream3_IRQn = 59,     /*!< DMA2 Stream 3 global Interrupt                                    */
	DMA2_Stream4_IRQn = 60,     /*!< DMA2 Stream 4 global Interrupt                                    */
	OTG_FS_IRQn = 67,     /*!< USB OTG FS global Interrupt                                       */
	DMA2_Stream5_IRQn = 68,     /*!< DMA2 Stream 5 global interrupt                                    */
	DMA2_Stream6_IRQn = 69,     /*!< DMA2 Stream 6 global interrupt                                    */
	DMA2_Stream7_IRQn = 70,     /*!< DMA2 Stream 7 global interrupt                                    */
	USART6_IRQn = 71,     /*!< USART6 global interrupt                                           */
	I2C3_EV_IRQn = 72,     /*!< I2C3 event interrupt                                              */
	I2C3_ER_IRQn = 73,     /*!< I2C3 error interrupt                                              */
	FPU_IRQn = 81,      /*!< FPU global interrupt                                             */
	SPI4_IRQn = 84       /*!< SPI4 global Interrupt                                            */
} IRQ_Num_t;

#endif /* STM32F4XX_DEVICE_HEADER_H_ */