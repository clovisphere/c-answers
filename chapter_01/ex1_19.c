#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

/* function prototype */
int get_line(char line[], int maxline);
void reverse(char to[], char from[], int limit);
void clear(char s[], int limit);

/* print reversed input line */
int main() {
	int len;            // current line length
	char text[MAXLINE]; // current text input
	char new[MAXLINE];  // the reversed text input

	while ((len = get_line(text, MAXLINE)) > 0) {
		reverse(new, text, len);
		printf("%s\n", new);
		/* clean after yourself:-) */
		clear(text, len);
		clear(new, len);
	}
	return 0;
}

/* get_line: read a line into line[], return line's length */
int get_line(char line[], int maxline) {
	int c, i;
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	line[i] = '\0';
	return i;
}

/* reverse: take a str saved in from[], reverse it and saved it to to[] */
void reverse(char to[], char from[], int limit) {
	for (int i = limit - 1, j = 0; i >= 0; i--, j++)
		to[j] = from[i];
}

/* clear: clear s after use ~> set all its elements' value, up to limit, to '\0' */
void clear(char s[], int limit) {
	for (int i = 0; i < limit; i++)
		s[i] = '\0';
}
