#ifndef MCAL_USART_PRIVATE_H_
#define MCAL_USART_PRIVATE_H_

#include "STM32F4xx_Device_Header.h"

typedef struct {
	union {
		struct {
			vu32 PE: 1;
			vu32 FE: 1;
			vu32 NE: 1;
			vu32 ORE: 1;
			vu32 IDLE: 1;
			vu32 RXNE: 1;
			vu32 TC: 1;
			vu32 TXE: 1;
			vu32 LBD: 1;
			vu32 CTS: 1;
		} SR_Bits;
		vu32 SR;         /*!< USART Status register,                   Address offset: 0x00 */
	};
	vu32 DR;             /*!< USART Data register,                     Address offset: 0x04 */
	vu32 BRR;            /*!< USART Baud rate register,                Address offset: 0x08 */
	union {
		struct {
			vu32 SBK: 1;
			vu32 RWU: 1;
			vu32 RE: 1;
			vu32 TE: 1;
			vu32 IDLEIE: 1;
			vu32 RXNEIE: 1;
			vu32 TCIE: 1;
			vu32 TXEIE: 1;
			vu32 PEIE: 1;
			vu32 PS: 1;
			vu32 PCE: 1;
			vu32 WAKE: 1;
			vu32 M: 1;
			vu32 UE: 1;
			vu32 : 1;
			vu32 OVER8: 1;
			vu32 : 16;
		} CR1_Bits;
		vu32 CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
	};
	vu32 CR2;            /*!< USART Control register 2,                Address offset: 0x10 */
	vu32 CR3;            /*!< USART Control register 3,                Address offset: 0x14 */
	vu32 GTPR;           /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} USART_TypeDef;

typedef struct USART_Index_t USART_Index_t;

#define USART1         ((USART_TypeDef *) USART1_BASE)
#define USART2         ((USART_TypeDef *) USART2_BASE)
#define USART3         ((USART_TypeDef *) USART3_BASE)

static USART_Index_t USART_xSelectIndex(USART_TypeDef *USARTx);

static u32 USART_u32CalcBRR(u32 Cp_Pclk, u32 Cp_BaudRate);

#endif /* MCAL_USART_PRIVATE_H_ */


