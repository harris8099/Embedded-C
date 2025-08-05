#include <stdint.h>

#define ADC_BASE_ADDR  0x40012000UL
#define ADC_CR1_REG_OFFSET 0x04UL
#define ADC_CR1_REG_ADDR (ADC_BASE_ADDR + ADC_CR1_REG_OFFSET)

#define RCC_BASE_ADDR 0x40023800UL
#define RCC_APB2_ENR_OFFSET 0x44UL
#define RCC_APB2_ADDR (RCC_BASE_ADDR + RCC_APB2_ENR_OFFSET)

int main(void)
{
	uint32_t *pAdcCrlReg = (uint32_t*)ADC_CR1_REG_ADDR;
	uint32_t *pRccApb2EnReg = (uint32_t*)RCC_APB2_ADDR;

	//1. Enable the peripheral clock ADC1
	*pRccApb2EnReg |= (1 << 8);

	//2. modify the ADC crl register

	*pAdcCrlReg |= (1 << 8);
    /* Loop forever */
	for(;;);
}
