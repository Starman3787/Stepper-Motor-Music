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
    RCC_AHB1ENR = 0b110000;
}