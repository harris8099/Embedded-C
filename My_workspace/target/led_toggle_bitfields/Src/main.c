#include <stdint.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
	RCC_AHB1ENR_t volatile *const pClkCtrlReg = (RCC_AHB1ENR_t *)0x40023830;
	GPIOx_MODE_t volatile *const pPortDModereg = (GPIOx_MODE_t *)0x40020C00;
	GPIOx_ODR_t volatile *const pPortDOutreg = (GPIOx_ODR_t *)0x40020C14;

	pClkCtrlReg->gpiod_en = 1;


	pPortDModereg->pin_12 = 1;

	while(1){
		pPortDOutreg->pin_12 = 1;
		for(uint32_t i=0; i< 300000; i++);
		pPortDOutreg->pin_12 = 0;
		for(uint32_t i=0; i< 300000; i++);
	}
}
