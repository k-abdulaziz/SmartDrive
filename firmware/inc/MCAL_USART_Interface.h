#ifndef MCAL_USART_INTERFACE_H_
#define MCAL_USART_INTERFACE_H_

#include "MCAL_GPIO_Interface.h"
#include "MCAL_RCC_Interface.h"
#include "MCAL_USART_Private.h"

#define RCC_USART1_CLOCK_EN()            MCL_RCC_vEnablePeriphClk(APB2_BUS, BIT4)
#define RCC_USART2_CLOCK_EN()            MCL_RCC_vEnablePeriphClk(APB1_BUS, BIT17)
#define RCC_USART3_CLOCK_EN()            MCL_RCC_vEnablePeriphClk(APB1_BUS, BIT18)

#define RCC_USART1_CLOCK_DIS()            MCL_RCC_vDisablePeriphClk(APB2_BUS, BIT4)
#define RCC_USART2_CLOCK_DIS()            MCL_RCC_vDisablePeriphClk(APB1_BUS, BIT17)
#define RCC_USART3_CLOCK_DIS()            MCL_RCC_vDisablePeriphClk(APB1_BUS, BIT5)

typedef enum {
	USART_IRQ_TXE,    //transmit data register empty
	USART_IRQ_TC,    //Transmission complete
	USART_IRQ_RXNE,    //received data ready to be read
	USART_IRQ_ORE,    //overrun error detected
	USART_IRQ_PE     //Parity error
} USART_IRQEvent_t;

typedef enum {
	USART_MODE_RX = (u32) (1 << 2),    //RE = 1
	USART_MODE_TX = (u32) (1 << 3),    //TE = 1
	USART_MODE_TX_RX = (u32) (1 << 2) | (1 << 3)
} USART_Mode_t;

typedef enum {
	USART_1_STOPBIT = ~(3 << 12),
	USART_HALF_STOPBIT = (u32) (1 << 12),
	USART_2_STOPBIT = (u32) (2 << 12),
	USART_1_HALF_STOPBIT = (u32) (3 << 12),
} USART_StopBits_t;

typedef enum {
	USART_PAYLOAD_LENGTH_8B = ~(1 << 12),
	USART_PAYLOAD_LENGTH_9B = (u32) (1 << 12)
} USART_Payload_t;

typedef enum {
	DATA_MODE_UNIDI_FULL_DUPLEX = ~((1 << 10) | (1 << 14) | (1 << 15)),
	DATA_MODE_UNIDI_RECEIVE_ONLY = (u16) (1 << 10),
	DATA_MODE_BIDI_RECEIVE_ONLY = (u16) (1 << 15),
	DATA_MODE_BIDI_TRANSMIT_ONLY = (u16) (1 << 15) | (1 << 14),

} USART_DataMode_t;

typedef enum {
	USART_NONE_PARITY = ~(1 << 10),
	USART_EVEN_PARITY = (u32) (1 << 10),
	USART_ODD_PARITY = (u32) (1 << 10) | (1 << 9),
} USART_Parity_t;

typedef enum {
	USART_HWFLOWCTRL_NONE = ~(3 << 9),
	USART_HWFLOWCTRL_CTS = (u32) (1 << 9),
	USART_HWFLOWCTRL_RTS = (u32) (1 << 8),
	USART_HWFLOWCTRL_CTS_RTS = (u32) (1 << 9) | (1 << 8),
} USART_HWFlow_t;

typedef enum {
	USART_BAUDRATE_2400 = 2400,
	USART_BAUDRATE_9600 = 9600,
	USART_BAUDRATE_19200 = 19200,
	USART_BAUDRATE_57600 = 57600,
	USART_BAUDRATE_115200 = 115200,
	USART_BAUDRATE_230400 = 230400,
	USART_BAUDRATE_460800 = 460800,
	USART_BAUDRATE_921600 = 921600,
	USART_BAUDRATE_2250000 = 2250000,
	USART_BAUDRATE_4500000 = 4500000,
} USART_BaudRate_t;

typedef enum {
	USART_IRQ_DISABLE = ~(7 << 5),
	USART_IRQ_ENABLE_TXE = (u32) (1 << 7),
	USART_IRQ_ENABLE_TC = (u32) (1 << 6),
	USART_IRQ_ENABLE_RXNE = (u32) (1 << 5),
	USART_IRQ_ENABLE_PE = (u32) (1 << 8),
} USART_IRQState_t;

typedef enum {
	USART_POLLING_DIASBLE,
	USART_POLLING_ENABLE
} Polling_Mechanism_t;

typedef struct {
	USART_Mode_t USART_Mode;        //select USART TX/RX mode.
	USART_BaudRate_t BaudRate;            //configure USART communication baud rat
	USART_Payload_t Payload_Length;        //select transmitted or received data word length (8 or 9 bits)
	USART_Parity_t Parity;                //select parity mode
	USART_StopBits_t StopBits;            //select number of Stop Bits
	USART_HWFlow_t HWFlowCTRL;            //enable or disable HW flow control modes
	USART_IRQState_t IRQ_State;            //enable or disable USART IRQ TX/RX
	void (*P_IRQ_CallBack)(
			USART_IRQEvent_t Cp_USART_IRQEvent);        //pointer to IRQ call back function which will be called once IRQ happened
} USART_CfgType;

extern USART_CfgType USART_G_Config;

void MCL_USART_vInit(USART_TypeDef *USARTx, USART_CfgType *Cp_USART_Cfg);

void MCL_USART_vDeinit(USART_TypeDef *USARTx);

void MCL_USART_vSetGPIOPins(USART_TypeDef *USARTx);

void MCL_USART_vTransmitData(USART_TypeDef *USARTx, u16 *Cp_pTxBuffer, Polling_Mechanism_t Cp_PollingState);

void MCL_USART_vReceiveData(USART_TypeDef *USARTx, u16 *Cp_pRxBuffer, Polling_Mechanism_t Cp_PollingState);

#endif /* MCAL_USART_INTERFACE_H_ */
