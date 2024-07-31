/*
 * pwm.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Sanchit
 */


#include <pwm.h>
#include "stm32f446xx.h"
#include "usart.h"
#include "button.h"

void PWM_config(void) {
	RCC->AHB1ENR |=(1<<0);
	RCC->APB1ENR |=(1<<0);

	GPIOA->MODER |=(1<<1);
	GPIOA->AFR[0] |=(1<<0);

	TIM2->ARR=255;
	TIM2->CCMR1 = (1<<5) |(1<<6);
	TIM2->CCER |=(1<<0);
	TIM2->CR1 |=(1<<0);
}

void start_PWM_output(void) {
	short brightness =0;
	short fadeAmount =85;

    UART2_SendString("Starting PWM output. Press the button to increase intensity.\n\r");

    while(1){
    	if (int_btn_pressed()) {
    		TIM2->CCR1 =brightness;
    		brightness += fadeAmount;
    		if(brightness <= 0 || brightness>=255){
    		    fadeAmount =-fadeAmount;
    		}
    		while(int_btn_pressed());
    	}
    	if(ext_btn_pressed()){
    		TIM2->CCR1 =brightness;
    		if(brightness>0){
    			brightness=0;
    		}



			break;
    	}
    }

    UART2_SendString("Stopping PWM output.\n\r");
}
