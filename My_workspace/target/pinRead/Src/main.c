#include <stdint.h>
#include <stdio.h>

int main(void)
{
	uint32_t volatile *pClkctrlreg =   (uint32_t *)0x40023830;
	uint32_t volatile *pPortAModereg = (uint32_t *)0x40020000;
	uint32_t volatile *pPortAInpreg =  (uint32_t *)0x40020010;
	uint32_t volatile *pPortDModereg = (uint32_t *)0x40020C00;
	uint32_t volatile *pPortDOutreg =  (uint32_t *)0x40020C14;
	uint8_t pinStatus;

	*pClkctrlreg |= (1 << 0); // enable clock for port A
	*pClkctrlreg |= (1 << 3); // enable clock for port D

	*pPortAModereg &= ~(3 << 0);

	*pPortDModereg &= ~(3 << 24);
	*pPortDModereg |= (1<<24);

	while(1){

		pinStatus = (uint8_t)(*pPortAInpreg & 0x1);

		if(pinStatus){
			*pPortDOutreg  |= (1<<12);
		}
		else{
			*pPortDOutreg  &= ~(1<<12);
		}

	}

}
