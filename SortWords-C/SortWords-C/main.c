#include <stdio.h>
#include <string.h>


void swap(char** x, char** y);


int main(void) {
	char* s[] = { "jens", "jensen", "abe", "kasper", "ib" , "henrik"};

	int len, i, j, k;

	len = sizeof(s) / sizeof(s[0]); // Find the length of string array
	printf("%d\n", len);
	for (k = 0; k < len; k++) {
		printf("Before s[%d]: %s\n", k, s[k]);
	}
	for (i = 0; i < len; i++) 
	{

		for (j = i+1; j < len; j++)
		{
			printf("strcmp %s and %s  = %d \n", s[i], s[j], strcmp(s[i], s[j]) > 0);
			if (strcmp(s[i], s[j]) > 0) { // Compare the strings if the compare return greater then 0, the s[i] is greater in ascii
				swap(&s[i], &s[j]);
			}
		}

		for (k = 0; k < len; k++) {
			printf("UNDER %d s[%d]: %s\n", i, k, s[k]);
		}
	}
	for (k = 0; k < len; k++) {
		printf("After s[%d]: %s\n", k, s[k]);
	}
}

void swap(char** x, char** y) {
	char *temp = *x;
	*x = *y;
	*y = temp;
}