/*
 * dac.h
 *
 *  Created on: Jul 27, 2024
 *      Author: Sanchit
 */


#ifndef USART_H
#define USART_H

#include <stdint.h>

void UART2_SendChar(char ch);
void UART2_SendString(char *string);
void USART2_config(void);
uint8_t UART_getchar(void);

#endif // USART_H
