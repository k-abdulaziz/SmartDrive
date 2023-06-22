#ifndef MCAL_GPIO_INTERFACE_H_
#define MCAL_GPIO_INTERFACE_H_


#include "MCAL_GPIO_Private.h"
#include "STD_TYPES.h"

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

typedef enum {
	GPIO_MODE_IN_FLOAT = 0b000000U,
	GPIO_MODE_IN_PU = 0b001000U,
	GPIO_MODE_IN_PD = 0b010000U,
	GPIO_MODE_OUT_PP = 0b000001U,
	GPIO_MODE_OUT_OD = 0b000101U,
	GPIO_MODE_AF_IN_PU = 0b001010U,
	GPIO_MODE_AF_IN_PD = 0b010010U,
	GPIO_MODE_AF_PP = 0b000010U,
	GPIO_MODE_AF_OUT_OD = 0b000110U,
	GPIO_MODE_ANALOG = 0b000011U,
} GPIO_Mode_t;

typedef enum {
	GPIO_SPEED_LOW = 0,
	GPIO_SPEED_MEDIUM = 1,
	GPIO_SPEED_HIGH = 2,
	GPIO_SPEED_VERY_HIGH = 3,
} GPIO_Speed_t;

#define GPIO_PIN_MASK            0x0000FFFFU

typedef enum {
	GPIO_AF0_SYSTEM = 0x00,
	GPIO_AF1_TIM1_TIM2,
	GPIO_AF2_TIM3_TIM4,
	GPIO_AF3_TIM5_TIM9_TIM10_TIM11,
	GPIO_AF4_I2C1_I2C2_TIM8,
	GPIO_AF5_SPI1_SPI2_I2S2_I2S3,
	GPIO_AF6_SPI3_I2S3,
	GPIO_AF7_USART1_USART2_SPI1,
	GPIO_AF8_USART6_SPI3_I2S3,
	GPIO_AF9_CAN1_TIM12_TIM13_TIM14,
	GPIO_AF10_OTG_FS_OTG_HS,
	GPIO_AF11_ETH,
	GPIO_AF12_FSMC_SDIO_OTG_HS,
	GPIO_AF13_DCMI,
	GPIO_AF14_LTDC,
	GPIO_AF15_EVENTOUT
} GPIO_AF_TypeDef;


typedef struct {
	GPIO_Pin_t GPIO_Pin;            //GPIO selected pin
	//this parameter can be a value of  @ref GPIO_Pin_define

	GPIO_Mode_t GPIO_Mode;            //mode of GPIO selected port/pin
	//this parameter can be a value of  @ref GPIO_Mode_define

	uint8_t GPIO_Speed;            //speed of GPIO selected port/pin
	//this parameter can be a value of  @ref GPIO_Speed_define

} GPIO_CfgType;

extern GPIO_CfgType GPIO_OUT_Config;
extern GPIO_CfgType GPIO_IN_Config;

void MCL_GPIO_vInitPort(GPIO_TypeDef *GPIOx, GPIO_CfgType *Cp_GPIO_Cfg);

void MCL_GPIO_vSetPinCfg(GPIO_TypeDef *GPIOx, GPIO_CfgType *Cp_GPIO_Cfg);

void
MCL_GPIO_vSetPinMode(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_GPIO_Pin, GPIO_Mode_t Cp_GPIO_Mode, GPIO_Speed_t Cp_GPIO_Speed);

void MCL_GPIO_vSetPinAltFunc(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId, GPIO_AF_TypeDef Cp_AltFunc);

void MCL_GPIO_vAtomicSetPin(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId, Pin_State_t Cp_xPinVal);

void MCL_GPIO_vWritePins(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_u8StPin, u8 Cp_u8Length, u8 Cp_u8Value);

u8 MCL_GPIO_u8GetPinVal(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId);

void MCL_GPIO_vWritePort(GPIO_TypeDef *GPIOx, u32 Cp_u32PortVal);

u32 MCL_GPIO_u32ReadPort(GPIO_TypeDef *GPIOx);

void MCL_GPIO_vTogglePin(GPIO_TypeDef *GPIOx, GPIO_Pin_t Cp_PinId);

#endif /* MCAL_GPIO_INTERFACE_H_ */
