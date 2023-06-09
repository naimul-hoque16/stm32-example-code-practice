/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 This program will blink an LED at a specific frequency. This code is meant to be
 run on STM32F407G Board and will be blinking the Blue LED.

 Blue LED is labeled as LD6 on the silkscreen. Blue LED is connected to
 GPIO Port D Pin 15.

 */

#include <stdint.h>
#include <stdbool.h>


/* Macros*/
#define AHB1_BASE_ADDRESS 0x40020000UL
#define RCC_BASE_ADDRESS 0x40023800UL
#define GPIO_D_BASE_ADDRESS 0x40020C00UL
#define RCC_AHB1_ENR (RCC_BASE_ADDRESS + 0x0030)
#define GPIO_D_ODR (GPIO_D_BASE_ADDRESS + 0x0014)

const bool ALL_LEDS = true;




#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
    // Enable GPIO Port D Clock
    unsigned long int *rcc_ahb1_enr = (unsigned long int*)RCC_AHB1_ENR;
    *rcc_ahb1_enr |= (1 << 3);


    // Configure GPIO Port D by setting proper registers
    // This part sets GPIO MODE to General Purpose Output Mode for Pin 15
    unsigned long int *gpio_d_moder = (unsigned long int*)GPIO_D_BASE_ADDRESS;
    if (ALL_LEDS == false){
    	// This part sets GPIO MODE to General Purpose Output Mode for Pin 15
    	*gpio_d_moder |= (1 << 30);
    }
    else{
    	// This part sets GPIO MODE to General Purpose Output Mode for Pin 12, 13, 14, and 15
    	*gpio_d_moder |= (85 << 24);
    }


    unsigned long int *gpio_d_odr = (unsigned long int*)GPIO_D_ODR;
    if (ALL_LEDS == false){
		// This part sets the output value for bit 15 on the LED
		*gpio_d_odr |= (1 << 15);
    }else{
    	// This part turns on all LEDS that are connected to GPIO Port D i.e 12, 13, 14, 15
    	*gpio_d_odr |= (15 << 12);
    }


    /* Loop forever */
	for(;;);
}
