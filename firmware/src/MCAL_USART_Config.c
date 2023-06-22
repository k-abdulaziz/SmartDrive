#include "../inc/STM32F4xx_Device_Header.h"
#include "../inc/MCAL_USART_Interface.h"

USART_CfgType USART_G_Config = {
		.USART_Mode = USART_MODE_TX_RX,

		.BaudRate = USART_BAUDRATE_9600,

		.Payload_Length = USART_PAYLOAD_LENGTH_8B,

		.Parity = USART_NONE_PARITY,

		.StopBits = USART_1_STOPBIT,

		.HWFlowCTRL = USART_HWFLOWCTRL_NONE,

		.IRQ_State = USART_IRQ_DISABLE,
};
