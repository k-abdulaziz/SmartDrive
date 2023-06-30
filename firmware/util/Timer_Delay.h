/**
 * @file timer_delay.h
 * @brief Header file for timer delay functions.
 *
 * This header file provides the function declarations for initializing and using timer-based delays.
 */

#ifndef TIMER_DELAY_H_
#define TIMER_DELAY_H_

/**
 * @headerfile "STD_TYPES.h"
 * @brief This header file contains the standard data types.
 */
#include "../inc/STD_TYPES.h"

/**
 * @brief Initialize the timer delay module.
 *
 * This function initializes the timer delay module, configuring the necessary hardware peripherals and timers.
 * It should be called before using any timer delay functions.
 */
void TimerDelay_Init(void);

/**
 * @brief Delay the execution by a specified number of microseconds.
 *
 * This function blocks the execution for the specified number of microseconds using a timer-based delay.
 * The actual delay duration may vary depending on the system clock frequency and timer configuration.
 *
 * @param Cp_u16Delay_us The delay duration in microseconds.
 */
void TimerDelay_us(vu16 Cp_u16Delay_us);

/**
 * @brief Delay the execution by a specified number of milliseconds.
 *
 * This function blocks the execution for the specified number of milliseconds using a timer-based delay.
 * The actual delay duration may vary depending on the system clock frequency and timer configuration.
 *
 * @param Cp_u16Delay_ms The delay duration in milliseconds.
 */
void TimerDelay_ms(vu16 Cp_u16Delay_ms);

#endif /* TIMER_DELAY_H_ */