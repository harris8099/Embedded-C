#include <stdio.h>

int main(void){

	float num1, num2, num3;
	float avg;

	printf("Enter the 3 number: ");
	scanf("%f %f %f",&num1,&num2,&num3);

	avg = (num1+num2+num3)/3.0;

	printf("\navg is: %f\n", avg);

	printf("Press ENTER key to exit the application......");
	while(getchar() != '\n'){

	}
	getchar();
	return 0;
}

