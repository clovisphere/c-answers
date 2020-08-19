#include <stdio.h>

// function prototypes
void rcomment(int);
void c99_style_comment(void);
void cpp_style_comment(void);
void echo_quote(int);

/* remove all comments from a valid C program */
int main() {
	int c;

	while ((c = getchar()) != EOF) {
		rcomment(c);
	}
	return 0;
}

/* clear: read each character, remove comment if any */
void rcomment(int current) {
	int next; // the next character
	if (current == '/') { // we may have the start of a comment
		if ((next = getchar()) == '*')
			c99_style_comment();
	    else if (next == '/')
			cpp_style_comment(); /* might be redundant ?! */
		else {
			putchar(current);
			putchar(next);
		}
	} else if (current == '\'' || current == '"') {
		echo_quote(current);
    } else {
		putchar(current); // not a comment
	}
}

/* inside a valid C style comment */
void c99_style_comment(void) {
	int current = getchar(), next = getchar(); // look at the next two characters
	while (current != '*' || next != '/') {
		current = next;
		next = getchar();
	}
}

/* inside a valid C++ style comment i.e starts with '//' */
void cpp_style_comment(void) {
	int c;
	while ((c = getchar()) != '\n');
	putchar(c);
}

/* echo_quote: echo characters within quotes */
void echo_quote(int current) {
	int next;
	putchar(current);
	while((next = getchar()) != current) {
		putchar(next);
		// to deal with escape sequence i.e: '\''
		if(next == '\\')
			putchar(getchar());
	}
	putchar(next);
}
