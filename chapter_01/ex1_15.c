#include <stdio.h>

#define UPPER 300
#define STEP  20

/* function prototype */
float f2c(int);

// starts program execution
int main() {
	printf("\nFahrenheit-Celsius table\n");
	for (int i = 0; i < UPPER; i += STEP)
		printf("%4d\t%6.1f\n", i, f2c(i));
	return 0;
}

// convert fahrenheit temperature to its celsius equivalent
float f2c(int fahr) {
	return (5.0/9.0) * (fahr - 32.0);
}
