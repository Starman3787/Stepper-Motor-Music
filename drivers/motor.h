/**
 * @file motor.h
 * @author Starman
 * @brief 
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdint.h>

// motor 0 - PF_13
// motor 1 - PE_9
// motor 2 - PE_11
// motor 3 - PF_14
// motor 4 - PE_13

// GPIO base addresses
#define GPIO_F              (*((uint32_t volatile *)0x40021400))
#define GPIO_E              (*((uint32_t volatile *)0x40021000))

// GPIO address offsets
#define MODER               (0x00)
#define OTYPER              (0x04)
#define ODR                 (0x14)

// GPIO addresses
// F
#define GPIO_F_MODER        (*((uint32_t volatile *)GPIO_F + MODER))
#define GPIO_F_OTYPER       (*((uint32_t volatile *)GPIO_F + OTYPER))
#define GPIO_F_ODR          (*((uint32_t volatile *)GPIO_F + ODR))
// E
#define GPIO_E_MODER        (*((uint32_t volatile *)GPIO_E + MODER))
#define GPIO_E_OTYPER       (*((uint32_t volatile *)GPIO_E + OTYPER))
#define GPIO_E_ODR          (*((uint32_t volatile *)GPIO_E + ODR))

// RCC base address
#define RCC                 (*((uint32_t volatile *)0x40023800))

// RCC address offsets
#define AHB1ENR             (0x30)

// RCC addresses
#define RCC_AHB1ENR         (*((uint32_t volatile *)RCC + AHB1ENR))