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
	// lines, words characters
	printf("%3d %3d %3d\n", nl, nw, nc);
	return 0;
}

/**
 * Test data:
 *  (+) no input                                 | output: 0 0 0
 *  (+) one-character word                       | output: 1 1 2
 *  (+) 2 one-character words, one word per line | output: 2 2 4
 *
 * Input that may uncover bugs:
 *  (+) no input
 *  (+) no words, just newlines
 *  (+) no words, just blanks, tabs and newlines
 *  .
 *  .
 *  etc
 */
