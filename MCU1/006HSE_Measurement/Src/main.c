#include <stdint.h>

#define RCC_BASE_ADDR 0x40023800UL
#define RCC_CFGR_REG_OFFSET 0x08UL
#define RCC_CFGR_REG_ADDR (RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET)
#define RCC_CR_REG_OFFSET 0x00UL
#define RCC_CR_REG_ADDR (RCC_BASE_ADDR + RCC_CR_REG_OFFSET)
#define GPIOA_BASE_ADDR 0x40020000UL

int main(void)
{
	uint32_t *pRccCrReg = (uint32_t *)RCC_CR_REG_ADDR;
	uint32_t *pRccCfgrReg = (uint32_t *)RCC_CFGR_REG_ADDR;
	//1. Enable the HSE clock using HSECON bit (RCC_CR)
	*pRccCrReg |= (1 << 16);

	//2. Wait until HSE clock from the external crystal stabilizes (only if crystal is connected)
	while( ! (*pRccCrReg & (1 << 17)) );

	//3. Switch the system clock to HSE (RCC_CFGR)
	*pRccCfgrReg |= (1 << 0);

	//4. Do MCO1 settings to measure it

	/*=============================MCO Settings================================ */
	//1. Configure the RCC CFGR register
	*pRccCfgrReg |= (1 << 22); //Clear 21 and set 22 bit position

	//Configure MCO1 prescaler // divisor as 4
	*pRccCfgrReg |= (1 << 25);
	*pRccCfgrReg |= (1 << 26);

	//2. Configure PA8 to AF0 mode to behave as MCO1 signal

	//a) Enable the peripheral clock for GPIOA peripheral
	uint32_t *pRCCAhb1Enr = (uint32_t*)(RCC_BASE_ADDR + 0x30);
	*pRCCAhb1Enr |= (1 << 0); //Enable GPIOA peripheral Clock

	//b) Configure the mode of GPIOA pin8 as alternate function mode
	uint32_t *pGPIOModeReg = (uint32_t*)(GPIOA_BASE_ADDR+00);
	*pGPIOModeReg &= ~(0x3 << 16); // Clear
	*pGPIOModeReg |= (0x2 << 16); // Clear

	//c) Configure the alteration function register to set the mode 0 for PA8
	uint32_t *pGPIOAAltFunHighReg = (uint32_t*)(GPIOA_BASE_ADDR+0x24);
	*pGPIOAAltFunHighReg &= ~(0xf << 0);
    /* Loop forever */
	for(;;);
}
