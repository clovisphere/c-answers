#include<stdio.h>

#define YES  1 // encoutered a blank
#define NO   0 // no blank

//starts program execution
int main() {
	int c, state;
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') { // blank can be a space or a tab ?!
			state = YES;
		} else {
			if(state == YES) {
				state = NO;
				putchar(' ');
			}
			putchar(c);
		}
	}
}
