#include <stdio.h>
#include <stdint.h>

void waitFunction(void);
void areaTriangle(void);
void areaTrapezoid(void);
void areaCircle(void);
void areaSquare(void);
void areaRect(void);

int main(void){
	char user_input;
	int in;
	printf("Select one of the option:\n");
	printf("'t' for triangle\n'z' for trapezoid\n'c' for circle\n's' for square\n'r' for rectangle\n");
	in = scanf(" %c",&user_input);
	if(in){
		switch(user_input){
		case 't':
			areaTriangle();
			break;
		case 'z':
			areaTrapezoid();
			break;
		case 'c':
			areaCircle();
			break;
		case 's':
			areaSquare();
			break;
		case 'r':
			areaRect();
			break;
		default:
			printf("Invalid input.....\n");
			waitFunction();
			return 0;

		}
	}
	else{
		printf("Invalid input");
		waitFunction();
		return 0;
	}
	waitFunction();
	return 0;
}

void areaTriangle(void){
	float base, height;
	float area;
	printf("Enter value for base: ");
	scanf("%f", &base);
	printf("Enter value for height: ");
	scanf("%f", &height);
	area = 0.5*base*height;
	printf("\nArea of triangle: %f", area);
}

void areaTrapezoid(void){
	float base1,base2, height;
	float area;
	printf("Enter value for base1: ");
	scanf("%f", &base1);
	printf("Enter value for base2: ");
	scanf("%f", &base2);
	printf("Enter value for height: ");
	scanf("%f", &height);
	area = 0.5*(base1+base2)*height;
	printf("\nArea of trapazoid: %f", area);
}

void areaCircle(void){
	float r;
	float area;
	printf("Enter value for radius: ");
	scanf("%f", &r);
	area = 3.14*r*r;
	printf("\nArea of circle: %f", area);
}

void areaSquare(void){
	float side;
	float area;
	printf("Enter value for side: ");
	scanf("%f", &side);
	area = side*side;
	printf("\nArea of square: %f", area);
}

void areaRect(void){
	float l,b;
	float area;
	printf("Enter value for length: ");
	scanf("%f", &l);
	printf("Enter value for breadth: ");
	scanf("%f", &b);
	area = l*b;
	printf("\nArea of triangle: %f", area);
}

void waitFunction(void){
	printf("\n\nPress Enter to exit the application....");
	while(getchar()!='\n'){

	}
	getchar();
}
