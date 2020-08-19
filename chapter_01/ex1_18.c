#include <stdio.h>
#define MAXLINE          1000 /* maximum input line size */

/* function prototype */
int get_line(char line[], int maxline);

/* prints all input lines that are longer than 80 characters */
int main() {
	int len;           // (current) line length
	char line[MAXLINE]; // (current) input line

	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("%s", line);
	}
	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int limit) {
	int c, i = 0;
	while (i < limit - 1 && (c = getchar()) != EOF && c != '\n') {
		if (c == '\t' || ( c == ' ' && i == 0) || (c == ' ' && i == limit - 1) ) continue; /* skip */
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
