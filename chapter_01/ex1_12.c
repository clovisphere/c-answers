#include<stdio.h>

/* print input one word per line */
int main() {
	int c;
	while((c = getchar()) != EOF) {
		// a word is sequence of characters that does not contain
		// a blank, tab or newline. 
		if (c == ' ' || c == '\t' || c == '\n')
			putchar('\n');
		else 
			putchar(c);
	}
	return 0;
}
