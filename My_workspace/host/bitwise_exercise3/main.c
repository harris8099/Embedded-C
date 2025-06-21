#include <stdio.h>
#include <stdint.h>

void waitFunction(void);


int main(void){
	int32_t in1,output;
	printf("Enter input: ");
	scanf("%d",&in1);

	output = in1|0x90;
	printf("[input] [output] :0x%x 0x%x\n", in1, output);

	waitFunction();
	return 0;
}

void waitFunction(void){
	printf("\n\nPress Enter to exit the application....");
	while(getchar()!='\n'){

	}
	getchar();
}
