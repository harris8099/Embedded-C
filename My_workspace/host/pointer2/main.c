#include <stdio.h>

long long int g_data = 0xFFFEABCD11112345;

int main(void){

	short *pAddress1;
	pAddress1 = (short*)&g_data;
	printf("Value at address %p is: %x\n", pAddress1, *pAddress1);

	pAddress1 += 1;
	printf("Value at address %p is: %x\n", pAddress1, *pAddress1);


	return 0;
}
