#include <stdint.h>
#include "./headers/stm32f767xx.h"
#include "./headers/CMSIS/core_cm7.h"

uint64_t microseconds = 0;
uint32_t milliseconds = 0;

void initSysTick(void)
{
    SysTick->LOAD = 18749UL;
    SysTick->VAL = 0UL;
    SysTick->CTRL = 0b111;
}

uint64_t currentMicroseconds(void)
{
    return microseconds;
}

uint32_t currentMilliseconds(void)
{
    return milliseconds;
}

void SysTick_Handler(void)
{
    milliseconds++;
}