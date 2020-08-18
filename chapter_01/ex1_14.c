#include <stdio.h>
#include <stdbool.h>
#define SIZE 30 // maximum size of the array

/* histogram of the frequency of different characters in input */
int main() {
	int c, count = 0, map[SIZE] = {0};
	char ch[SIZE];
	bool seen = false;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') continue; /* skip: ignore blank */
		else {
			for (int i = 0; i < SIZE; i++) {
				if (ch[i] == c) {
					seen = true;
					++map[i];
					break;
				}
				seen = false;
			}
			if (!seen) {
				ch[count] = c;
				++map[count];
				++count;
			}
		}
	}
	printf("\n");
    // histogram - horizontal orientation
	for (int i = 0; i < SIZE; i++) {
		if (map[i] == 0) continue; /* skip */
		printf("%c: ", ch[i]);
		for(int j = 0; j < map[i]; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
