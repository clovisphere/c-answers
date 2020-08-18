#include<stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word

/* count lines, words, and characters in input */
int main() {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("lines: %d, words: %d, characters: %d\n", nl, nw, nc);
	return 0;
}

/**
 * How to test the program? 
 *      Test it against a text file e.g data.txt that contains some input.
 * Bug:
 *  (+) The program considers a line with an input such as: "me (or you)" to be 
 *      made up of 3 distinct words, '(or' is considered a word, so is 'you)'.
 *      The definition of what constitutes/makes a 'word' should be refined.
 */
