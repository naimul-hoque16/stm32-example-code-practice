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
 This program is responsible for turning on LEDs on the Board one button press at a time.
 It initally starts with the orange LED. Then, as the button is pressed, the LED changes
 in a clockwise pattern until reaching the orange LED.
 */

#include <stdint.h>


#define RCC_BASE_ADDRESS 0x40023800UL
#define RCC_AHB1ENR (RCC_BASE_ADDRESS + 0x0030) // Registers which enable peripheral clock on AHB1

#define GPIOA_BASE_ADDRESS 0x40020000UL
#define GPIOA_MODER (GPIOA_BASE_ADDRESS + 0x00)

#define GPIOD_BASE_ADDRESS 0x40020C00UL
#define GPIOD_MODER (GPIOD_BASE_ADDRESS + 0x00)
#define GPIOD_ODR (GPIOD_BASE_ADDRESS + 0x14)

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
    /*Setup Code*/

	/*Enable Clocks for GPIO Port A and D*/
	unsigned long int *rcc_ahb1enr = (unsigned long int*) RCC_AHB1ENR;
	*rcc_ahb1enr |= (1 << 3); // Enables clock for Port D
	*rcc_ahb1enr |= (1 << 0); // Enables clock for Port A

	/*Set all GPIO D Pins that LEDs are connected with to General Purpose Output Mode*/
	unsigned long int *gpio_d_moder = (unsigned long int*) GPIOD_MODER;
	*gpio_d_moder |= (85 << 24);

	/* Set GPIO A, Pin 0 as input */
	unsigned long int *gpio_a_moder = (unsigned long int*) GPIOA_MODER;
	*gpio_a_moder &= ~(1 << 1);
	*gpio_a_moder &= ~(1 << 0);

	/* By default, we turn on Orange LED First */
	unsigned long int *gpio_d_odr = (unsigned long int*) GPIOD_ODR;
	*gpio_d_odr |= (1 << 13);


	/* Loop Forever */
	for(;;);

}
