#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

/* function prototype */
int get_line(char line[], int maxline);
void reverse(char s[]);

/* print reversed input line */
int main() {
	int len;            // current line length
	char text[MAXLINE]; // current text input

	while ((len = get_line(text, MAXLINE)) > 0) {
		reverse(text);
		printf("%s", text);
	}
	return 0;
}

/* get_line: read a line into line[], return line's length */
int get_line(char line[], int maxline) {
	int c, i;
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* reverse a given str */
void reverse(char s[]) {
	int i, j;
	char temp;
	
	i = 0;
	while (s[i] != '\0')
		++i;
	--i;                 // back off from '\0'
	if (s[i] == '\n')
		--i;			 // leave newline in place
	j = 0;               // beginning of new string s
	while (j < i) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}
