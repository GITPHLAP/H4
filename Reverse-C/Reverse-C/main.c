#include <stdio.h>

void swap(char *x, char *y);

int main(void) {
	char s[] = "rambuk";
	char *c_begin, *c_end;

	c_begin = s; // The first index in array
	c_end = (s + strlen(s)-1); // The last index in array
	printf("%s\n", s);
	while (c_begin != c_end && c_end > c_begin) {
		printf("c_begin %c c_end %c \n", *c_begin, *c_end);
		printf("c_begin %d c_end %d \n", c_begin, c_end);
		swap(c_end, c_begin); // I Want to swap the last character with the first
		printf("c_begin %d c_end %d \n", c_begin, c_end);





		c_begin++; // Point to the next place in array
		c_end--; // Point to the place before in array
	}


	printf("%d\n", strlen(s));
	printf("%s\n", s);
}

void swap(char *x, char *y) {
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

