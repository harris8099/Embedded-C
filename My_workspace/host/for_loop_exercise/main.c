#include <stdio.h>
#include <stdint.h>

void waitFunction(void);

int main(void){
	uint8_t i,j,userInput;
	printf("Enter a number: ");
	scanf("%hhd", &userInput);

	for(i=1; i<=userInput; i++){
		for(j=i; j>0; j--){
			printf("%hhd\t", j);
		}
		printf("\n");
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
