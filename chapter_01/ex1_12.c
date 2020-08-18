#include<stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word

/* print input one word per line */
int main() {
	int c;
	while((c = getchar()) != EOF) {
		// a word is sequence of characters that does not contain
		// a blank, tab or newline. 
		if (c == ' ' || c == '\t' || c == '\n') {
			printf("\n");
			continue;
		}
		putchar(c);
	}
	return 0;
}
