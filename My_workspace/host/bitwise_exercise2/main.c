#include <stdio.h>
#include <stdint.h>

void waitFunction(void);


int main(void){
	int32_t in1;
	printf("Enter input: ");
	scanf("%d",&in1);

	if(in1&1){
		printf("%d is odd number\n", in1);
	}
	else{
		printf("%d is even number\n", in1);
	}

	waitFunction();
	return 0;
}

void waitFunction(void){
	printf("\n\nPress Enter to exit the application....");
	while(getchar()!='\n'){

	}
	getchar();
}
