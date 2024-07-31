/*
 * button.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Sanchit
 */


#include <stdlib.h>
#include <stdio.h>
#include "stm32f446xx.h"

void button_init(){
	RCC->AHB1ENR |=RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIOCEN;  //Enabling GPIOA and GPIOC
	GPIOC->MODER &=~(3<<27);  //Configuring Port-C13 to made input
	GPIOC->OSPEEDR |=(1<<26);
	GPIOC->PUPDR |=(1<<26);

	GPIOC->MODER &=~(3<16);  //Configuring Port-C8 to made input
	GPIOC->OSPEEDR |=(1<<16);
	GPIOC->PUPDR |=(2<<16);
}

int int_btn_pressed() {
    return (!(GPIOC->IDR & (1 << 13)));
}

int ext_btn_pressed() {
	return !(GPIOC->IDR & (1 << 8));
}
