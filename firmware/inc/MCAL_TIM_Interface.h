/**
 * @file MCAL_TIM_Interface.h
 * @brief This file contains the interface of the MCAL_TIM driver.
 *
 * @author Ahmed Abu Raya
 * @date 2023-06-20
 */

#ifndef MCAL_TIM_INTERFACE_H_
#define MCAL_TIM_INTERFACE_H_

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "STD_TYPES.h"

/**
 * @headerfile "MCAL_TIM_Private.h"
 * @brief Include the header file for the TIM private.
 */
#include "MCAL_TIM_Private.h"

/**
 * @headerfile "MCAL_RCC_Private.h"
 * @brief Include the header file for the RCC private.
 */
#include "MCAL_RCC_Private.h"

/** @def RCC_TIM1_CLOCK_EN
 *  @brief Enable the clock for TIM1 peripheral
 */
#define RCC_TIM1_CLOCK_EN()         (RCC->RCC_APB2ENR |= RCC_APB2ENR_TIM1EN)

/** @def RCC_TIM1_CLOCK_DIS
 *  @brief Disable the clock for TIM1 peripheral
 */
#define RCC_TIM1_CLOCK_DIS()        (RCC->RCC_APB2ENR &= ~RCC_APB2ENR_TIM1EN)

/** @def RCC_TIM2_CLOCK_EN
 *  @brief Enable the clock for TIM2 peripheral
 */
#define RCC_TIM2_CLOCK_EN()         (RCC->RCC_APB1ENR |= RCC_APB1ENR_TIM2EN)

/** @def RCC_TIM2_CLOCK_DIS
 *  @brief Disable the clock for TIM2 peripheral
 */
#define RCC_TIM2_CLOCK_DIS()        (RCC->RCC_APB1ENR &= ~RCC_APB1ENR_TIM2EN)

/** @def RCC_TIM3_CLOCK_EN
 *  @brief Enable the clock for TIM3 peripheral
 */
#define RCC_TIM3_CLOCK_EN()         (RCC->RCC_APB1ENR |= RCC_APB1ENR_TIM3EN)

/** @def RCC_TIM3_CLOCK_DIS
 *  @brief Disable the clock for TIM3 peripheral
 */
#define RCC_TIM3_CLOCK_DIS()        (RCC->RCC_APB1ENR &= ~RCC_APB1ENR_TIM3EN)

/** @def RCC_TIM4_CLOCK_EN
 *  @brief Enable the clock for TIM4 peripheral
 */
#define RCC_TIM4_CLOCK_EN()         (RCC->RCC_APB1ENR |= RCC_APB1ENR_TIM4EN)

/** @def RCC_TIM4_CLOCK_DIS
 *  @brief Disable the clock for TIM4 peripheral
 */
#define RCC_TIM4_CLOCK_DIS()        (RCC->RCC_APB1ENR &= ~RCC_APB1ENR_TIM4EN)

/** @enum TIM_ClkSrc_t
 *  @brief Enumeration for the clock source of a TIM peripheral
 */
typedef enum {
	TIM_NOPRESCALER = 0,         /*!< No prescaler */
	TIM_CLKPRESCALER_2 = 1,      /*!< Clock prescaler: 2 */
	TIM_CLKPRESCALER_4 = 3,      /*!< Clock prescaler: 4 */
	TIM_CLKPRESCALER_8 = 7,      /*!< Clock prescaler: 8 */
	TIM_CLKPRESCALER_16 = 15,    /*!< Clock prescaler: 16 */
	TIM_CLKPRESCALER_32 = 31,    /*!< Clock prescaler: 32 */
	TIM_CLKPRESCALER_64 = 63,    /*!< Clock prescaler: 64 */
	TIM_CLKPRESCALER_128 = 127,  /*!< Clock prescaler: 128 */
	TIM_CLKPRESCALER_256 = 255,  /*!< Clock prescaler: 256 */
	TIM_CLKPRESCALER_512 = 511,  /*!< Clock prescaler: 512 */
	TIM_CLKPRESCALER_1024 = 1023 /*!< Clock prescaler: 1024 */
} TIM_ClkSrc_t;

/**
 * @enum TIM_Mode_t
 * @brief Enumeration for the mode of a TIM peripheral
 */
typedef enum {
	TIM_MODE_TIMING = 0,              /*!< Timing mode */
	TIM_MODE_PWM = 1,                 /*!< PWM mode */
	TIM_MODE_INPUT_CAPTURE = 2,       /*!< Input capture mode */
	TIM_MODE_OUTPUT_COMPARE = 3       /*!< Output compare mode */
} TIM_Mode_t;

/**
 * @enum TIM_Output_Mode_t
 * @brief Enumeration for the output mode of a TIM peripheral
 */
typedef enum {
	TIM_OUTPUT_MODE_FREE_RUNNING = 0,             /*!< Free running mode */
	TIM_OUTPUT_MODE_ACTIVE_ON_MATCH = 1,          /*!< Active on match mode */
	TIM_OUTPUT_MODE_INACTIVE_ON_MATCH = 2,        /*!< Inactive on match mode */
	TIM_OUTPUT_MODE_TOGGLE_ON_MATCH = 3,          /*!< Toggle on match mode */
	TIM_OUTPUT_MODE_FORCE_ACTIVE = 4,             /*!< Force active mode */
	TIM_OUTPUT_MODE_FORCE_INACTIVE = 5,           /*!< Force inactive mode */
	TIM_OUTPUT_MODE_PWM1 = 6,                     /*!< PWM mode 1 */
	TIM_OUTPUT_MODE_PWM2 = 7                      /*!< PWM mode 2 */
} TIM_Output_Mode_t;

/**
 * @enum TIM_Channel_t
 * @brief Enumeration for the active channel of a TIM peripheral
 */
typedef enum {
	TIM_CHANNEL_1 = 0x01U,           /*!< Active channel is 1 */
	TIM_CHANNEL_2 = 0x02U,           /*!< Active channel is 2 */
	TIM_CHANNEL_3 = 0x03U,           /*!< Active channel is 3 */
	TIM_CHANNEL_4 = 0x04U,           /*!< Active channel is 4 */
	TIM_CHANNEL_CLEARED = 0x00U      /*!< All active channels cleared */
} TIM_Channel_t;

/**
 * @enum TIM_INT_t
 * @brief Enumeration for the interrupt type of a TIM peripheral
 */
typedef enum {
	TIM_INT_DISABLE = 0,          /*!< Interrupt disabled */
	TIM_INT_UPDATE = TIM_DIER_UIE,        /*!< Update interrupt */
	TIM_INT_CC1 = TIM_DIER_CC1IE,         /*!< Capture/Compare 1 interrupt */
	TIM_INT_CC2 = TIM_DIER_CC2IE,         /*!< Capture/Compare 2 interrupt */
	TIM_INT_CC3 = TIM_DIER_CC3IE,         /*!< Capture/Compare 3 interrupt */
	TIM_INT_CC4 = TIM_DIER_CC4IE,         /*!< Capture/Compare 4 interrupt */
	TIM_INT_COM = TIM_DIER_COMIE,         /*!< COM interrupt */
	TIM_INT_TRIGGER = TIM_DIER_TIE,       /*!< Trigger interrupt */
	TIM_INT_BREAK = TIM_DIER_BIE          /*!< Break interrupt */
} TIM_INT_t;

/**
 * @enum TIM_ClkPol_t
 * @brief Enumeration for the clock polarity of a TIM peripheral
 */
typedef enum {
	TIM_CLOCKPOLARITY_RISING = 0U,       /*!< Active high or rising edge */
	TIM_CLOCKPOLARITY_FALLING = 1U,      /*!< Active low or falling edge */
	TIM_CLOCKPOLARITY_BOTHEDGE = 2U      /*!< Active low or falling edge */
} TIM_ClkPol_t;

/**
 * @enum TIM_CounterMode_t
 * @brief Enumeration for the counter mode of a TIM peripheral
 */
typedef enum {
	TIM_COUNTERMODE_UP = 0x0000U,        /*!< Counter up mode */
	TIM_COUNTERMODE_DOWN = 0x0001U       /*!< Counter down mode */
} TIM_CounterMode_t;

/**
 * @struct TIM_CfgType
 * @brief Structure that contains the configuration parameters of a TIM peripheral
 */
typedef struct {
	TIM_Mode_t TIM_Mode;                    /*!< TIM mode */
	TIM_Output_Mode_t TIM_Output_Mode;      /*!< TIM output mode */
	TIM_INT_t TIM_INT;                      /*!< TIM interrupt type */
	u16 TIM_Period;                         /*!< Timer period value */
	TIM_ClkSrc_t TIM_Prescaler;              /*!< Timer prescaler value */
	u16 TIM_Pulse;                          /*!< Timer pulse value */
	TIM_CounterMode_t TIM_CounterMode;      /*!< Timer counter mode */
	u8 TIM_ClockDiv;                        /*!< Timer clock division */
	void (*TIM_INT_Callback)(void);         /*!< Callback function for TIM interrupt */
} TIM_CfgType;

/**
 * @struct TIM_IC_CfgType
 * @brief Structure that contains the configuration parameters of a TIM input capture
 */
typedef struct {
	TIM_Channel_t IC_Channel;           /*!< Input capture channel */
	u32 IC_Prescaler;                   /*!< Input capture prescaler value */
	u32 IC_Period;                      /*!< Input capture period value */
	u32 IC_Selection;                   /*!< Input capture selection */
	u32 IC_TriggerSource;               /*!< Input capture trigger source */
} TIM_IC_CfgType;

/**
 * @struct TIM_HandleTypeDef
 * @brief Structure that contains the handle for a TIM peripheral
 */
typedef struct {
	TIM_TypeDef *Instance;              /*!< Register base address */
	TIM_CfgType Init;                   /*!< TIM Time Base required parameters */
	TIM_Channel_t Channel;              /*!< Active channel */
} TIM_HandleTypeDef;

/**
 * @brief Configuration structure for TIM input capture
 */
extern TIM_IC_CfgType TIM_IC_Config;

/**
 * @brief Handle structure for PWM TIM peripheral
 */
extern TIM_HandleTypeDef PWM_htim3;

/**
 * @brief Initialize the TIM peripheral with the specified configuration.
 *
 * @param htim Pointer to the TIM handle structure.
 */
void TIM_vInit(TIM_HandleTypeDef *htim);

/**
 * @brief Initialize the TIM input capture with the specified configuration.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param ic_config Pointer to the TIM input capture configuration structure.
 */
void TIM_IC_vInit(TIM_HandleTypeDef *htim, TIM_IC_CfgType *ic_config);

/**
 * @brief Initialize the PWM TIM peripheral with the specified configuration.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Cp_Period The period value for the PWM.
 */
void TIM_PWM_vInit(TIM_HandleTypeDef *htim, u32 Cp_Period);

/**
 * @brief Initialize the PWM TIM peripheral output with the specified configuration.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Cp_Period The period value for the PWM.
 * @param Cp_DutyCycle The duty cycle value for the PWM.
 */
void TIM_PWM_Out_vInit(TIM_HandleTypeDef *htim, u32 Cp_Period, u8 Cp_DutyCycle);

/**
 * @brief Set the duty cycle of the PWM TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Cp_DutyCycle The duty cycle value for the PWM.
 */
void TIM_PWM_SetDutyCycle(TIM_HandleTypeDef *htim, u8 Cp_DutyCycle);

/**
 * @brief Disable the specified interrupt of the TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Cp_TIM_INT The interrupt type to be disabled.
 *                   (TIM_INT_DISABLE to disable all interrupts).
 */
void TIM_vDisableINT(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

/**
 * @brief Enable the specified interrupt of the TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Cp_TIM_INT The interrupt type to be enabled.
 */
void TIM_vEnableINT(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

/**
 * @brief Check if the specified interrupt flag of the TIM peripheral is set.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Cp_TIM_INT The interrupt type to check.
 * @return STD_Status STD_OK if the interrupt flag is set, otherwise STD_ERROR.
 */
enum STD_Status TIM_xCheckINTFlag(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

/**
 * @brief Check if the specified interrupt source of the TIM peripheral is enabled.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Cp_TIM_INT The interrupt type to check.
 * @return STD_Status STD_OK if the interrupt source is enabled, otherwise STD_ERROR.
 */
enum STD_Status TIM_xCheckINTSrc(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

/**
 * @brief Clear the specified interrupt flag of the TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Cp_TIM_INT The interrupt type to clear.
 */
void TIM_vClearFlag(TIM_HandleTypeDef *htim, TIM_INT_t Cp_TIM_INT);

/**
 * @brief Start the specified TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 */
void TIM_vStart(TIM_HandleTypeDef *htim);

/**
 * @brief Stop the specified TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 */
void TIM_vStop(TIM_HandleTypeDef *htim);

/**
 * @brief Get the elapsed time of the specified TIM peripheral.
 *
 * @param TIMx TIM peripheral instance.
 * @return u32 The elapsed time in units of the TIM peripheral's timer resolution.
 */
u32 TIM_u32GetTimeElapsed(TIM_TypeDef *TIMx);

/**
 * @brief Get the remaining time of the specified TIM peripheral.
 *
 * @param TIMx TIM peripheral instance.
 * @return u32 The remaining time in units of the TIM peripheral's timer resolution.
 */
u32 TIM_u32GetTimeRemaining(TIM_TypeDef *TIMx);

/**
 * @brief Read the captured value from the specified channel of the TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Channel The channel from which to read the captured value.
 * @return u32 The captured value from the specified channel.
 */
u32 TIM_u32ReadCapturedVal(TIM_HandleTypeDef *htim, u8 Channel);

/**
 * @brief Set the compare value for the specified channel of the TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 * @param Channel The channel for which to set the compare value.
 * @param Compare_Value The compare value to be set.
 */
void TIM_vSetCompareVal(TIM_HandleTypeDef *htim, TIM_Channel_t Channel, u32 Compare_Value);

/**
 * @brief Set the clock polarity for the specified channel of the TIM peripheral.
 *
 * @param TIMx TIM peripheral instance.
 * @param TIM_Channel The channel for which to set the clock polarity.
 * @param polarity The clock polarity to be set.
 */
void TIM_vSetClkPolarity(TIM_HandleTypeDef *TIMx, TIM_Channel_t TIM_Channel, TIM_ClkPol_t polarity);

/**
 * @brief Get the channel ID of the specified TIM peripheral.
 *
 * @param TIMx TIM peripheral instance.
 * @return TIM_Channel_t The channel ID of the TIM peripheral.
 */
TIM_Channel_t TIM_GetChannelID(TIM_TypeDef *TIMx);

/**
 * @brief Initialize the counter of the specified TIM peripheral.
 *
 * @param htim Pointer to the TIM handle structure.
 */
void TIM_vInitCounter(TIM_HandleTypeDef *htim);

/**
 * @brief Initialize the capture/compare mode of the specified TIM peripheral.
 *
 * @param TIMx TIM peripheral instance.
 */
void TIM_voidCapture_Compare_Init(TIM_TypeDef *TIMx);

/**
 * @brief Initialize the PWM mode of the specified TIM peripheral.
 *
 * @param TIMx TIM peripheral instance.
 */
void TIM_voidPWMInit(TIM_TypeDef *TIMx);

#endif /* MCAL_TIM_INTERFACE_H_ */