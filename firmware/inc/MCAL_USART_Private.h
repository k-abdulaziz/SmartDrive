/**
 * @file MCAL_USART_PRIVATE_H_
 * @brief This file contains the private of the USART peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_USART_PRIVATE_H_
#define MCAL_USART_PRIVATE_H_

/**
 * @headerfile "STM32F4xx_Device_Header.h"
 * @brief Include the header file for the STM32F4xx device.
 */
#include "STM32F4xx_Device_Header.h"

/**
 * @struct USART_TypeDef
 * @brief Structure representing the USART peripheral registers.
 *
 * This structure defines the layout of the USART peripheral registers.
 * It provides convenient access to the various registers of the USART module.
 * The registers are accessed using bit-field structures for better readability.
 */
typedef struct {
	union {
		struct {
			vu32 PE: 1;       /*!< Parity error flag */
			vu32 FE: 1;       /*!< Framing error flag */
			vu32 NE: 1;       /*!< Noise error flag */
			vu32 ORE: 1;      /*!< Overrun error flag */
			vu32 IDLE: 1;     /*!< IDLE line detected flag */
			vu32 RXNE: 1;     /*!< Read data register not empty flag */
			vu32 TC: 1;       /*!< Transmission complete flag */
			vu32 TXE: 1;      /*!< Transmit data register empty flag */
			vu32 LBD: 1;      /*!< LIN break detection flag */
			vu32 CTS: 1;      /*!< CTS flag */
		} SR_Bits;
		vu32 SR;             /*!< USART Status register,                   Address offset: 0x00 */
	};
	vu32 DR;                 /*!< USART Data register,                     Address offset: 0x04 */
	vu32 BRR;                /*!< USART Baud rate register,                Address offset: 0x08 */
	union {
		struct {
			vu32 SBK: 1;     /*!< Send break flag */
			vu32 RWU: 1;     /*!< Receiver wakeup */
			vu32 RE: 1;      /*!< Receiver enable */
			vu32 TE: 1;      /*!< Transmitter enable */
			vu32 IDLEIE: 1;  /*!< IDLE interrupt enable */
			vu32 RXNEIE: 1;  /*!< RXNE interrupt enable */
			vu32 TCIE: 1;    /*!< Transmission complete interrupt enable */
			vu32 TXEIE: 1;   /*!< TXE interrupt enable */
			vu32 PEIE: 1;    /*!< PE interrupt enable */
			vu32 PS: 1;      /*!< Parity selection */
			vu32 PCE: 1;     /*!< Parity control enable */
			vu32 WAKE: 1;    /*!< Wakeup method */
			vu32 M: 1;       /*!< Word length */
			vu32 UE: 1;      /*!< USART enable */
			vu32 : 1;        /*!< Reserved bit */
			vu32 OVER8: 1;   /*!< Oversampling mode */
			vu32 : 16;       /*!< Reserved bits */
		} CR1_Bits;
		vu32 CR1;            /*!< USART Control register 1,                Address offset: 0x0C */
	};
	vu32 CR2;                /*!< USART Control register 2,                Address offset: 0x10 */
	vu32 CR3;                /*!< USART Control register 3,                Address offset: 0x14 */
	vu32 GTPR;               /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} USART_TypeDef;

/**
 * @def USART1
 * @brief Macro to access the USART1 peripheral.
 *
 * This macro provides a convenient way to access the USART1 peripheral
 * by type-casting the base address (USART1_BASE) to the USART_TypeDef structure pointer.
 */
#define USART1         ((USART_TypeDef *) USART1_BASE)

/**
 * @def USART2
 * @brief Macro to access the USART2 peripheral.
 *
 * This macro provides a convenient way to access the USART2 peripheral
 * by type-casting the base address (USART2_BASE) to the USART_TypeDef structure pointer.
 */
#define USART2         ((USART_TypeDef *) USART2_BASE)

/**
 * @def USART3
 * @brief Macro to access the USART3 peripheral.
 *
 * This macro provides a convenient way to access the USART3 peripheral
 * by type-casting the base address (USART3_BASE) to the USART_TypeDef structure pointer.
 */
#define USART3         ((USART_TypeDef *) USART3_BASE)

/**
 * @brief Internal function to select the USART index.
 *
 * This function is used internally to determine the USART index based on the USART peripheral pointer.
 *
 * @param USARTx Pointer to the USART peripheral.
 * @return USART index.
 */
static USART_Index_t USART_xSelectIndex(USART_TypeDef *USARTx);

/**
 * @brief Internal function to calculate the USART Baud Rate Register (BRR) value.
 *
 * This function is used internally to calculate the BRR value based on the provided peripheral clock (Cp_Pclk)
 * and desired baud rate (Cp_BaudRate).
 *
 * @param Cp_Pclk Peripheral clock frequency.
 * @param Cp_BaudRate Desired baud rate.
 * @return BRR value.
 */
static u32 USART_u32CalcBRR(u32 Cp_Pclk, u32 Cp_BaudRate);

#endif /* MCAL_USART_PRIVATE_H_ */


