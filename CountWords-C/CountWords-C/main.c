#include <stdio.h>

int isLetter(char *letter);

int main(void) {
	char s[] = "Hej med dig7    f sdf sd 23rsdks sasd3as 3";
	char *pts;
	int counter = 0;
	pts = s;
	while (*pts != '\0')
	{
		if (isLetter(pts)) {

			pts++;
			if (*pts == '\0') {
				counter++;
				break;
			}
			else if (*pts == ' ') { // Check if the next is space and then count a word 
				counter++;
			} else if (!isLetter(pts)) {
				counter++;
			}
			continue;
		}
		pts++;
		

	}
	printf("words %d\n", counter);

}

int isLetter(char *letter) {
	int i;
	char allLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅabcdefghijklmnopqrstuvwxyzæøå";
	char* ptl;
	ptl = allLetters;

	for (i = 0; i < strlen(allLetters)-1; i++)
	{
		if (*letter == *(ptl + i)) {
			return 1;
		}
	}
	return 0;
}

