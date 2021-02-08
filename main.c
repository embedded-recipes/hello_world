/*
@File        : main.c

@Author      : Divin Raj

@Description : Sample Application for verifing linux terminal build 

@Target      : STM32F411RE
*/



#include <stdint.h>

#define GPIOA_BASE          ((uint32_t)0x40020000)                              /* GPIOA Base address */
#define GPIOA_ODR           (GPIOA_BASE + 0x14)                                 /* Output data register */
#define GPIOA_MOD           (GPIOA_BASE)                                        /* Output mode Register */
#define RCC_BASE            ((uint32_t)0x40023830)                              /* RCC_AHB1 Base address */

#define GPIOA_CLKEN(val)    ((*(volatile uint32_t *)RCC_BASE)  |= (1 << val))   /* Enabling GPIOA CLK */
#define GPIOA_ODR_WR(pin)   ((*(volatile uint32_t *)GPIOA_ODR) |= (1 << pin))   /* Writing Output Data Register */
#define GPIOA_MOD_WR(pin)   ((*(volatile uint32_t *)GPIOA_MOD) |= (1 << 2*pin)) /* Setting Output Mode */

int main()
{

GPIOA_CLKEN(0);  /* 0 - GPIOA CLOCK ENABLE PIN  */  
GPIOA_MOD_WR(5); /* 5 - PIN NUMBER FOR USER LED */
GPIOA_ODR_WR(5); /* 5 - PIN NUMBER FOR USER LED */

return 0;
} 
