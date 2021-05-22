/**
 * @file arm-cortex-m7.h
 * @author Starman
 * @brief Definitions for the ARM Cortex-M7 registers
 * @version 0.1
 * @date 2021-04-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdint.h>

/**
 * @brief SysTick Registers
 * 
 */

#define SYST_CSR                (*((uint32_t volatile *)0xE000E010)) // Control and status register
#define SYST_RVR                (*((uint32_t volatile *)0xE000E014)) // Reload value register
#define SYST_CVR                (*((uint32_t volatile *)0xE000E018)) // Current value register
#define SYST_CALIB              (*((uint32_t volatile *)0xE000E01C)) // Calibration value register