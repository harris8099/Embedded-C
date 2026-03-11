/*
 * it.c
 *
 *  Created on: Mar 8, 2026
 *      Author: harri
 */
#include "main.h"

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

