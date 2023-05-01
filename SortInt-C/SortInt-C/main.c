#include <stdio.h>

void swap(int* x, int* y);

int main(void) {
	int a[10] = { 0,5,2,4,3,9,6,7,8, 1 };
	int *pta, *pta_next, len, i, j, k;

	len = sizeof(a) / sizeof(a[0]);
	printf("%d\n", len);
	for (k = 0; k < 10; k++) {
		printf("Before a[%d]: %d\n", k, a[k]);
	}
	for (i = 0; i < len; i++)
	{
		pta = &a[i];
		printf("pta %d\n", *pta);

		for (j = i+1; j < len; j++)
		{
			pta_next = &a[j];
			if (*pta_next > *pta) {
				swap(pta_next, pta);
			}
			pta_next++;
		}

		for (k = 0; k < 10; k++) {
			printf("UNDER %d a[%d]: %d\n", i, k, a[k]);
		}
	}
	for (k = 0; k < 10; k++) {
		printf("After a[%d]: %d\n", k, a[k]);
	}
}

void swap(int* x, int* y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

