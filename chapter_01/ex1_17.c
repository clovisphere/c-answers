#include <stdio.h>
#define MAXLINE          1000 /* maximum input line size */
#define MIN_TEXT_LENGTH    80 /* the length the input text to print has to exceed */
/* function prototype */
int get_line(char line[], int maxline);

/* prints all input lines that are longer than 80 characters */
int main() {
	int len;           // (current) line length
	char line[MAXLINE]; // (current) input line

	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > MIN_TEXT_LENGTH)
			printf("%s", line);
	return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int limit) {
	int c, i;
	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
