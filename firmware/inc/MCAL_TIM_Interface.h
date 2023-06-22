#ifndef MCAL_TIM_INTERFACE_H_
#define MCAL_TIM_INTERFACE_H_

#include "STD_TYPES.h"
#include "MCAL_TIM_Private.h"
#include "MCAL_RCC_Private.h"

#define RCC_TIM1_CLOCK_EN()         (RCC->RCC_APB2ENR |= RCC_APB2ENR_TIM1EN)
#define RCC_TIM1_CLOCK_DIS()        (RCC->RCC_APB2ENR &= ~RCC_APB2ENR_TIM1EN)

#define RCC_TIM2_CLOCK_EN()         (RCC->RCC_APB1ENR |= RCC_APB1ENR_TIM2EN)
#define RCC_TIM2_CLOCK_DIS()        (RCC->RCC_APB1ENR &= ~RCC_APB1ENR_TIM2EN)

#define RCC_TIM3_CLOCK_EN()         (RCC->RCC_APB1ENR |= RCC_APB1ENR_TIM3EN)
#define RCC_TIM3_CLOCK_DIS()        (RCC->RCC_APB1ENR &= ~RCC_APB1ENR_TIM3EN)

#define RCC_TIM4_CLOCK_EN()         (RCC->RCC_APB1ENR |= RCC_APB1ENR_TIM4EN)
#define RCC_TIM4_CLOCK_DIS()        (RCC->RCC_APB1ENR &= ~RCC_APB1ENR_TIM4EN)

typedef enum {
	TIM_NOPRESCALER = 0,
	TIM_CLKPRESCALER_2 = 1,
	TIM_CLKPRESCALER_4 = 3,
	TIM_CLKPRESCALER_8 = 7,
	TIM_CLKPRESCALER_16 = 15,
	TIM_CLKPRESCALER_32 = 31,
	TIM_CLKPRESCALER_64 = 63,
	TIM_CLKPRESCALER_128 = 127,
	TIM_CLKPRESCALER_256 = 255,
	TIM_CLKPRESCALER_512 = 511,
	TIM_CLKPRESCALER_1024 = 1023
} TIM_ClkSrc_t;

typedef enum {
	TIM_MODE_TIMING = 0,
	TIM_MODE_PWM = 1,
	TIM_MODE_INPUT_CAPTURE = 2,
	TIM_MODE_OUTPUT_COMPARE = 3
} TIM_Mode_t;

typedef enum {
	TIM_OUTPUT_MODE_FREE_RUNNING = 0,
	TIM_OUTPUT_MODE_ACTIVE_ON_MATCH = 1,
	TIM_OUTPUT_MODE_INACTIVE_ON_MATCH = 2,
	TIM_OUTPUT_MODE_TOGGLE_ON_MATCH = 3,
	TIM_OUTPUT_MODE_FORCE_ACTIVE = 4,
	TIM_OUTPUT_MODE_FORCE_INACTIVE = 5,
	TIM_OUTPUT_MODE_PWM1 = 6,
	TIM_OUTPUT_MODE_PWM2 = 7
} TIM_Output_Mode_t;

typedef enum {
	TIM_CHANNEL_1 = 0x01U,    /*!< The active channel is 1     */
	TIM_CHANNEL_2 = 0x02U,    /*!< The active channel is 2     */
	TIM_CHANNEL_3 = 0x03U,    /*!< The active channel is 3     */
	TIM_CHANNEL_4 = 0x04U,    /*!< The active channel is 4     */
	TIM_CHANNEL_CLEARED = 0x00U     /*!< All active channels cleared */
} TIM_Channel_t;

typedef enum {
	TIM_INT_DISABLE = 0,
	TIM_INT_UPDATE = TIM_DIER_UIE,
	TIM_INT_CC1 = TIM_DIER_CC1IE,
	TIM_INT_CC2 = TIM_DIER_CC2IE,
	TIM_INT_CC3 = TIM_DIER_CC3IE,
	TIM_INT_CC4 = TIM_DIER_CC4IE,
	TIM_INT_COM = TIM_DIER_COMIE,
	TIM_INT_TRIGGER = TIM_DIER_TIE,
	TIM_INT_BREAK = TIM_DIER_BIE
} TIM_INT_t;

typedef enum {
	TIM_CLOCKPOLARITY_RISING = 0U,  /*!< Active high or rising edge */
	TIM_CLOCKPOLARITY_FALLING = 1U, /*!< Active low or falling edge */
	TIM_CLOCKPOLARITY_BOTHEDGE = 2U   /*!< Active low or falling edge */
} TIM_ClkPol_t;

typedef enum {
	TIM_COUNTERMODE_UP = 0x0000U,
	TIM_COUNTERMODE_DOWN = 0x0001U,

} TIM_CounterMode_t;

typedef struct {
	TIM_Mode_t TIM_Mode;                        //@ref TIM_Mode_Define
	TIM_Output_Mode_t TIM_Output_Mode;          //@ref TIM_Output_Mode_Define
	TIM_INT_t TIM_INT;                           //@ref TIM_INT_Define
	u16 TIM_Period;                                //Timer period value
	TIM_ClkSrc_t TIM_Prescaler;                            //Timer prescaler value
	u16 TIM_Pulse;                                //Timer pulse value
	TIM_CounterMode_t TIM_CounterMode;            //values for the timer counter mode
	u8 TIM_ClockDiv;

	void (*TIM_INT_Callback)(void);             //Callback function for TIM IRQ
} TIM_CfgType;

typedef struct {
	TIM_Channel_t IC_Channel;       // Input capture channel
	u32 IC_Prescaler;               // Input capture prescaler value
	u32 IC_Period;                  // Input capture period value
	u32 IC_Selection;               // Input capture selection
	u32 IC_TriggerSource;           // Input capture trigger source
} TIM_IC_CfgType;

typedef struct {
	TIM_TypeDef *Instance;         /*!< Register base address                             */
	TIM_CfgType Init;              /*!< TIM Time Base required parameters             */
	TIM_Channel_t Channel;           /*!< Active channel */
} TIM_HandleTypeDef;

extern TIM_IC_CfgType TIM_IC_Config;

extern TIM_HandleTypeDef PWM_htim3;

void TIM_vInit(TIM_HandleTypeDef *htim);

void TIM_IC_vInit(TIM_HandleTypeDef *htim, TIM_IC_CfgType *ic_config);

void TIM_PWM_vInit(TIM_HandleTypeDef *htim, u32 Cp_Period);

void TIM_PWM_Out_vInit(TIM_HandleTypeDef *htim, u32 Cp_Period, u8 Cp_DutyCycle);

void TIM_PWM_SetDutyCycle(TIM_HandleTypeDef *htim, u8 Cp_DutyCycle);

void TIM_vDisableINT(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT); //no notification, no ISR will operate

void TIM_vEnableINT(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

STD_Status TIM_xCheckINTFlag(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

STD_Status TIM_xCheckINTSrc(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

void TIM_vClearFlag(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

void TIM_vStart(TIM_HandleTypeDef *htim);

void TIM_vStop(TIM_HandleTypeDef *htim);

u32 TIM_u32GetTimeElapsed(TIM_TypeDef *TIMx);

u32 TIM_u32GetTimeRemaining(TIM_TypeDef *TIMx);

u32 TIM_u32ReadCapturedVal(TIM_HandleTypeDef *htim, u8 Channel);

void TIM_vSetCompareVal(TIM_HandleTypeDef *htim, TIM_Channel_t Channel, u32 Compare_Value);

void TIM_vSetClkPolarity(TIM_HandleTypeDef *TIMx, TIM_Channel_t TIM_Channel, TIM_ClkPol_t polarity);

TIM_Channel_t TIM_GetChannelID(TIM_TypeDef *TIMx);

void TIM_vInitCounter(TIM_HandleTypeDef *htim);

void TIM_voidCapture_Compare_Init(TIM_TypeDef *TIMx);

void TIM_voidPWMInit(TIM_TypeDef *TIMx);

#endif /* MCAL_TIM_INTERFACE_H_ */
