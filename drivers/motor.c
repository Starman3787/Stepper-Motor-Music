/**
 * @file motor.c
 * @author Starman
 * @brief Motor driver
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdint.h>
#include "./motor.h"

// motor 0 - PF_13
// motor 1 - PE_9
// motor 2 - PE_11
// motor 3 - PF_14
// motor 4 - PE_13

void initMotors()
{
    RCC_AHB1ENR |= (0b1 << 4);
    RCC_AHB1ENR |= (0b1 << 5);

    GPIO_E_MODER |= (0b01 << (9 * 2));
    GPIO_E_MODER |= (0b01 << (11 * 2));
    GPIO_E_MODER |= (0b01 << (13 * 2));
    GPIO_F_MODER |= (0b01 << (13 * 2));
    GPIO_F_MODER |= (0b01 << (14 * 2));

    GPIO_E_OTYPER = 0;
    GPIO_F_OTYPER = 0;

    GPIO_E_ODR = 0;
    GPIO_F_ODR;
}

void toggleMotor(char gpio, uint8_t pin)
{
    switch (gpio)
    {
        case 'E': {
            GPIO_E_ODR ^= (0b1 << pin);
            return;
        }
        case 'F': {
            GPIO_F_ODR ^= (0b1 << pin);
            return;
        }
    }
}