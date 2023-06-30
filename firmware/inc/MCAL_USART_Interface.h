/**
 * @file MCAL_USART_INTERFACE_H_
 * @brief This file contains the interface of the USART peripheral.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_USART_INTERFACE_H_
#define MCAL_USART_INTERFACE_H_

/**
 * @headerfile "MCAL_GPIO_Interface.h"
 * @brief This header file contains the interface for the GPIO peripheral.
 */
#include "MCAL_GPIO_Interface.h"

/**
 * @headerfile "MCAL_RCC_Interface.h"
 * @brief Include the header file for the RCC interface.
 */
#include "MCAL_RCC_Interface.h"

/**
 * @headerfile "MCAL_USART_Private.h"
 * @brief Include the header file for the USART private.
 */
#include "MCAL_USART_Private.h"

/**
 * @def RCC_USART1_CLOCK_EN
 * @brief Macro to enable the clock for USART1 peripheral.
 */
#define RCC_USART1_CLOCK_EN()            MCL_RCC_vEnablePeriphClk(APB2_BUS, BIT4)

/**
 * @def RCC_USART2_CLOCK_EN
 * @brief Macro to enable the clock for USART2 peripheral.
 */
#define RCC_USART2_CLOCK_EN()            MCL_RCC_vEnablePeriphClk(APB1_BUS, BIT17)

/**
 * @def RCC_USART3_CLOCK_EN
 * @brief Macro to enable the clock for USART3 peripheral.
 */
#define RCC_USART3_CLOCK_EN()            MCL_RCC_vEnablePeriphClk(APB1_BUS, BIT18)

/**
 * @def RCC_USART1_CLOCK_DIS
 * @brief Macro to disable the clock for USART1 peripheral.
 */
#define RCC_USART1_CLOCK_DIS()            MCL_RCC_vDisablePeriphClk(APB2_BUS, BIT4)

/**
 * @def RCC_USART2_CLOCK_DIS
 * @brief Macro to disable the clock for USART2 peripheral.
 */
#define RCC_USART2_CLOCK_DIS()            MCL_RCC_vDisablePeriphClk(APB1_BUS, BIT17)

/**
 * @def RCC_USART3_CLOCK_DIS
 * @brief Macro to disable the clock for USART3 peripheral.
 */
#define RCC_USART3_CLOCK_DIS()            MCL_RCC_vDisablePeriphClk(APB1_BUS, BIT5)

/**
 * @enum USART_IRQEvent_t
 * @brief Enumeration of USART IRQ events.
 */
typedef enum {
	USART_IRQ_TXE,    // Transmit data register empty
	USART_IRQ_TC,     // Transmission complete
	USART_IRQ_RXNE,   // Received data ready to be read
	USART_IRQ_ORE,    // Overrun error detected
	USART_IRQ_PE      // Parity error
} USART_IRQEvent_t;

/**
 * @enum USART_Mode_t
 * @brief Enumeration of USART operating modes.
 */
typedef enum {
	USART_MODE_RX = (u32) (1 << 2),         // Receive mode (RE = 1)
	USART_MODE_TX = (u32) (1 << 3),         // Transmit mode (TE = 1)
	USART_MODE_TX_RX = (u32) (1 << 2) | (1 << 3)  // Transmit and receive mode
} USART_Mode_t;

/**
 * @enum USART_StopBits_t
 * @brief Enumeration of USART stop bit options.
 */
typedef enum {
	USART_1_STOPBIT = ~(3 << 12),           // 1 stop bit
	USART_HALF_STOPBIT = (u32) (1 << 12),   // 0.5 stop bit
	USART_2_STOPBIT = (u32) (2 << 12),      // 2 stop bits
	USART_1_HALF_STOPBIT = (u32) (3 << 12)  // 1.5 stop bits
} USART_StopBits_t;

/**
 * @enum USART_Payload_t
 * @brief Enumeration of USART payload length options.
 */
typedef enum {
	USART_PAYLOAD_LENGTH_8B = ~(1 << 12),   // 8-bit data length
	USART_PAYLOAD_LENGTH_9B = (u32) (1 << 12)  // 9-bit data length
} USART_Payload_t;

/**
 * @enum USART_DataMode_t
 * @brief Enumeration of USART data transfer modes.
 */
typedef enum {
	DATA_MODE_UNIDI_FULL_DUPLEX = ~((1 << 10) | (1 << 14) | (1 << 15)),  // Unidirectional full duplex mode
	DATA_MODE_UNIDI_RECEIVE_ONLY = (u16) (1 << 10),                      // Unidirectional receive-only mode
	DATA_MODE_BIDI_RECEIVE_ONLY = (u16) (1 << 15),                       // Bidirectional receive-only mode
	DATA_MODE_BIDI_TRANSMIT_ONLY = (u16) (1 << 15) | (1 << 14)           // Bidirectional transmit-only mode
} USART_DataMode_t;

/**
 * @enum USART_Parity_t
 * @brief Enumeration of USART parity options.
 */
typedef enum {
	USART_NONE_PARITY = ~(1 << 10),                  // No parity
	USART_EVEN_PARITY = (u32) (1 << 10),              // Even parity
	USART_ODD_PARITY = (u32) (1 << 10) | (1 << 9)     // Odd parity
} USART_Parity_t;

/**
 * @enum USART_HWFlow_t
 * @brief Enumeration of USART hardware flow control options.
 */
typedef enum {
	USART_HWFLOWCTRL_NONE = ~(3 << 9),                // No hardware flow control
	USART_HWFLOWCTRL_CTS = (u32) (1 << 9),             // CTS flow control
	USART_HWFLOWCTRL_RTS = (u32) (1 << 8),             // RTS flow control
	USART_HWFLOWCTRL_CTS_RTS = (u32) (1 << 9) | (1 << 8)  // CTS and RTS flow control
} USART_HWFlow_t;

/**
 * @enum USART_BaudRate_t
 * @brief Enumeration of USART baud rate options.
 */
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
	USART_BAUDRATE_4500000 = 4500000
} USART_BaudRate_t;

/**
 * @enum USART_IRQState_t
 * @brief Enumeration of USART IRQ state options.
 */
typedef enum {
	USART_IRQ_DISABLE = ~(7 << 5),                    // Disable all IRQs
	USART_IRQ_ENABLE_TXE = (u32) (1 << 7),            // Enable TXE IRQ
	USART_IRQ_ENABLE_TC = (u32) (1 << 6),             // Enable TC IRQ
	USART_IRQ_ENABLE_RXNE = (u32) (1 << 5),           // Enable RXNE IRQ
	USART_IRQ_ENABLE_PE = (u32) (1 << 8)              // Enable PE IRQ
} USART_IRQState_t;

/**
 * @enum Polling_Mechanism_t
 * @brief Enumeration of USART polling mechanism options.
 */
typedef enum {
	USART_POLLING_DISABLE,    // Polling mechanism disabled
	USART_POLLING_ENABLE      // Polling mechanism enabled
} Polling_Mechanism_t;

/**
 * @struct USART_CfgType
 * @brief Structure defining the USART configuration parameters.
 */
typedef struct {
	USART_Mode_t USART_Mode;                    // Select USART TX/RX mode
	USART_BaudRate_t BaudRate;                  // Configure USART communication baud rate
	USART_Payload_t Payload_Length;             // Select transmitted or received data word length (8 or 9 bits)
	USART_Parity_t Parity;                      // Select parity mode
	USART_StopBits_t StopBits;                  // Select number of stop bits
	USART_HWFlow_t HWFlowCTRL;                  // Enable or disable hardware flow control modes
	USART_IRQState_t IRQ_State;                 // Enable or disable USART IRQ TX/RX
	void (*P_IRQ_CallBack)(USART_IRQEvent_t);   // Pointer to IRQ callback function, called when an IRQ event occurs
} USART_CfgType;

/**
 * @brief External declaration of USART configuration structure.
 */
extern USART_CfgType USART_G_Config;

/**
 * @brief Initializes the USART peripheral with the provided configuration.
 * @param USARTx Pointer to the USART peripheral.
 * @param Cp_USART_Cfg Pointer to the USART configuration structure.
 */
void MCL_USART_vInit(USART_TypeDef *USARTx, USART_CfgType *Cp_USART_Cfg);

/**
 * @brief Deinitializes the USART peripheral.
 * @param USARTx Pointer to the USART peripheral.
 */
void MCL_USART_vDeinit(USART_TypeDef *USARTx);

/**
 * @brief Sets the GPIO pins for USART communication.
 * @param USARTx Pointer to the USART peripheral.
 */
void MCL_USART_vSetGPIOPins(USART_TypeDef *USARTx);

/**
 * @brief Transmits data using USART communication.
 * @param USARTx Pointer to the USART peripheral.
 * @param Cp_pTxBuffer Pointer to the transmit buffer.
 * @param Cp_PollingState Polling mechanism state (enable/disable).
 */
void MCL_USART_vTransmitData(USART_TypeDef *USARTx, u16 *Cp_pTxBuffer, Polling_Mechanism_t Cp_PollingState);

/**
 * @brief Receives data using USART communication.
 * @param USARTx Pointer to the USART peripheral.
 * @param Cp_pRxBuffer Pointer to the receive buffer.
 * @param Cp_PollingState Polling mechanism state (enable/disable).
 */
void MCL_USART_vReceiveData(USART_TypeDef *USARTx, u16 *Cp_pRxBuffer, Polling_Mechanism_t Cp_PollingState);

#endif /* MCAL_USART_INTERFACE_H_ */
