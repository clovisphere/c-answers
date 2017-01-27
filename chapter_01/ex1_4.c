// Write a program to print the corresponding
// Celsius to Fahrenheit table.

#include<stdio.h>
    
int main(void) {
	float celsius, fahr;
	int lower, upper, step;
	
	lower = 0;
	upper = 200;
	step = 20;
	
	celsius = lower;
	
	printf("\nCelsius to fahrenheit converter.");
	printf("\n--------------------------------\n\n");
	
	while(celsius <= upper) {
		fahr = (celsius * 9.0) / 5.0 + 32.0 ;
		
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius += step;
	}
	return 0;
}
