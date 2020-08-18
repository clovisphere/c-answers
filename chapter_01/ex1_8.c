#include<stdio.h>

// starts program execution
int main() {
	int c; // character
	int nl, bl, tb; // newline, blank, tab

	nl = bl = tb = 0;
	while((c = getchar()) != EOF) {
		if (c == ' ') {
			++bl;
		} else if (c == '\t') {
			++tb;
		} else if (c == '\n') {
			++nl;
		}
	}
	printf("No. of blanks:   %3d\nNo. of tabs:     %3d\nNo. of newlines: %3d\n", bl, tb, nl);
	return 0;
}
