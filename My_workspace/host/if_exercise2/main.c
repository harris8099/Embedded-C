#include <stdio.h>
#include <stdint.h>

int main(void){
	int32_t num1,num2;
	printf("Enter two numbers: ");
	scanf(" %d %d",&num1,&num2);
	if(num1>num2){
		printf("%d is greater than %d",num1,num2);
	}
	else if(num1 == num2){
		printf("Both %d and %d are equal",num1,num2);
	}
	else{
		printf("%d is greater than %d",num2,num1);
	}

	printf("\n\nPress ENTER to exit the application.....");
	while(getchar()!='\n'){

	}
	getchar();
	return 0;
}
