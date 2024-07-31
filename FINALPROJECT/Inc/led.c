/*
 * led.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Suman
 */


#include "led.h"
#include "button.h"
#include "stm32f446xx.h"
#include <stdlib.h>
#include <stdio.h>

void delay(uint32_t n){
	for(int i = 0; i<1000000*n; i++);
}

void LED_init(){
	RCC->AHB1ENR |=(1<<0);
	GPIOA->MODER |=(1<<10);
	GPIOA->OTYPER &=~(1<<5);
	GPIOA->OSPEEDR |=(1<<10);
	GPIOA->PUPDR &=~(3<<10);
}

void blink(float n){
	GPIOA->ODR ^=(1<<5);
	delay(n);
}

void LED_Blinking(){
	//float delay_values[]={1, 2, 3, 4};
	//int i=0;
	int delay_value =1;

	while(1){
		//blink(delay_values[i]);
		blink(delay_value);
		if (int_btn_pressed()) {

			delay_value += 1;
			if(delay_value >=4){
				delay_value =1;
			}
//			if (i<3){
//				i++;
//			}else{
//				i=0;
//			}
			while(int_btn_pressed());
		}
		if(ext_btn_pressed()){
			GPIOA->ODR &=~(1<<5);

			break;
		}
	}
}
