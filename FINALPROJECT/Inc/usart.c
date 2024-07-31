/*
 * usart.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Sanchit
 */


#include "usart.h"
#include "stm32f446xx.h"

void UART2_SendChar(char ch) {
    USART2->DR = ch;
    while (!(USART2->SR & (1 << 6))); // Wait for transmission complete
}

void UART2_SendString(char *string) {
    while (*string != '\0') {
        UART2_SendChar(*string);
        string++;
    }
}

void USART2_config(void) {
    RCC->AHB1ENR |= (1 << 2); // Enable GPIOC clock
    RCC->AHB1ENR |= (1 << 0); // Enable GPIOA clock
    RCC->APB1ENR |= (1 << 17); // Enable USART2 clock

    GPIOC->MODER &= ~(3 << 27); // PC13 input mode
    GPIOC->OSPEEDR |= (3 << 26); // High speed for PC13

    GPIOA->MODER |= (2 << 4); // PA2 alternate function mode
    GPIOA->MODER |= (2 << 6); // PA3 alternate function mode
    GPIOA->OSPEEDR |= (3 << 4); // High speed for PA2
    GPIOA->OSPEEDR |= (3 << 6); // High speed for PA3
    GPIOA->AFR[0] |= (7 << 8); // PA2 AF7 (USART2_TX)
    GPIOA->AFR[0] |= (7 << 12); // PA3 AF7 (USART2_RX)

    USART2->CR1 = 0x00; // Clear all
    USART2->CR1 |= (1 << 13); // Enable USART2
    USART2->CR1 &= ~(1 << 12); // Word length 8 bits

    USART2->BRR = (1 << 0) | (24 << 4); // Baud rate

    USART2->CR1 |= (1 << 2); // Enable receiver
    USART2->CR1 |= (1 << 3); // Enable transmitter
}

uint8_t UART_getchar(void) {
    while (!(USART2->SR & (1 << 5))); // Wait for data to be received
    return USART2->DR;
}

