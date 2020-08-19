#include <stdio.h>
#define MAXLINE          1000 /* maximum input line size */

/* function prototype */
int get_line(char line[], int maxline);
int remove_trailing_blank(char s[]);

/* remove trailing blanks and tabs, and delete blank lines */
int main() {
	char line[MAXLINE]; // (current) input line

	while (get_line(line, MAXLINE) > 0)
		if (remove_trailing_blank(line) > 0)
			printf("%s", line);
	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int limit) {
	int c, i = 0;
	while (i < limit - 1 && (c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		++i;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* remove trailing blanks and tabs from character string s */
// NOTE TO SELF: a trailing blank is any space or tab before the '\n' (newline) character
int remove_trailing_blank(char s[]) {
	int i = 0;
	while (s[i] != '\n')
		i++;
	--i; // back off from '\n'
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if (i >= 0) {
		++i;
		s[i] = '\n'; // put newline character back
		++i;
		s[i] = '\0'; // terminate the string
	}
	return i;
}
