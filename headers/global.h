/**
 * @file global.h
 * @author Starman
 * @brief Header file for global functions and definitions
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdint.h>

volatile uint32_t sysTicks;
volatile uint32_t seconds;

uint32_t getMilliseconds(void);

void SysTick_Hander(void);

// void delayMS(uint32_t t, void (*callback)());

// void delay_us(uint32_t nus);
// void delay_ms(uint16_t nms);