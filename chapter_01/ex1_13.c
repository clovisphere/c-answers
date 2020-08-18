#include <stdio.h>

#define SIZE 15 // maximum size of the array

/* print histogram of the lengths of words in its input */
int main() {
	int c, count = 0, words[SIZE] = {0};
	// ensure we count blanks only once, and 
	// empty lines are ignored
	char previous = '\0';

	while ((c = getchar()) != EOF) {
		if (previous == c)
			continue;

		if ( c == ' ' || c == '\t' || c == '\n') {
			previous = c;
			++count;
		}
		else {
			++words[count]; 
			previous = '\0';
		}
	}
	printf("\n");
	// histogram - vertical orientation
	for (int i = SIZE; i > 0; --i) {
		printf("%2d ", i);
		for (int j = 0; j < SIZE; j++) {
			if (words[j] == 0) continue; /* skip */
			if (i > words[j])
				printf("  ");
			else
				printf(". ");
		}
		printf("\n");
	}
	return 0;
}
