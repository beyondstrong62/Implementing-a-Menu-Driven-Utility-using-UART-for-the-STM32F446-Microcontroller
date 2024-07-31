/*
 * clock.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Sanchit
 */


#include "clock.h"
#include "stm32f446xx.h"

void SysClockConfig(void) {
    #define PLL_M 4
    #define PLL_N 180
    #define PLL_P 0  // PLLP = 2

    RCC->CR |= RCC_CR_HSEON; // Enable HSE
    while (!(RCC->CR & RCC_CR_HSERDY)); // Wait for HSE to be ready

    RCC->APB1ENR |= RCC_APB1ENR_PWREN; // Enable power interface clock
    PWR->CR |= PWR_CR_VOS; // Set voltage regulator

    FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_5WS; // Flash settings

    RCC->CFGR |= RCC_CFGR_HPRE_DIV1; // AHB prescaler
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV4; // APB1 prescaler
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2; // APB2 prescaler

    RCC->PLLCFGR = (PLL_M << 0) | (PLL_N << 6) | (PLL_P << 16) | (RCC_PLLCFGR_PLLSRC_HSE); // Configure PLL

    RCC->CR |= RCC_CR_PLLON; // Enable PLL
    while (!(RCC->CR & RCC_CR_PLLRDY)); // Wait for PLL to be ready

    RCC->CFGR |= RCC_CFGR_SW_PLL; // Select PLL as system clock source
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); // Wait for PLL to be used
}
