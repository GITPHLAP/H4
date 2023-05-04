#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define arr_size 100000000
void swap(int* x, int* y);
void upgradedSwap(int* x, int* y);
int* getRandomIntArr();
void selectionSort(int* arr);
void printResult(int* arr);
void insertionSort(int* arr);
void mergeSort(int* arr, int p, int r);
void merge(int* arr, int p, int q, int r);
int* getSortedIntArr();


int main(void) {
	clock_t start, end;
	int* input_arr;

	//// Selection Sort
	//printf("****** Selection sort ******\n");
	//input_arr = getRandomIntArr(); // Get random values in array
	//start = clock();
	//selectionSort(input_arr);
	//end = clock();
	//printf("Cpu time used: %f \n", ((double)(end - start)) / CLOCKS_PER_SEC);

	//// Insertion Sort
	//printf("\n\n\n****** Insertion sort ******\n");
	//input_arr = getRandomIntArr(); // Get random values in array
	//start = clock();
	//insertionSort(input_arr);
	//end = clock();
	//printf("Cpu time used: %f \n", ((double)(end - start)) / CLOCKS_PER_SEC);

	// Merge Sort
	printf("\n\n\n****** Merge sort ******\n");
	input_arr = getRandomIntArr(); // Get random values in array
	start = clock();
	mergeSort(input_arr, 0, arr_size-1);
	end = clock();
	printf("Cpu time used: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
	


	//// Selection Sort
	//printf("****** Selection sort SORTED******\n");
	//input_arr = getSortedIntArr(); // Get random values in array
	//start = clock();
	//selectionSort(input_arr);
	//end = clock();
	//printf("Cpu time used: %f \n", ((double)(end - start)) / CLOCKS_PER_SEC);

	//// Insertion Sort
	//printf("\n\n\n****** Insertion sort SORTED******\n");
	//input_arr = getSortedIntArr(); // Get random values in array
	//start = clock();
	//insertionSort(input_arr);
	//end = clock();
	//printf("Cpu time used: %f \n", ((double)(end - start)) / CLOCKS_PER_SEC);

	// Merge Sort
	printf("\n\n\n****** Merge sort SORTED******\n");
	//input_arr = getSortedIntArr(); // Get random values in array
	start = clock();
	mergeSort(input_arr, 0, arr_size - 1);
	end = clock();
	printf("Cpu time used: %f \n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

void swap(int* x, int* y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
void upgradedSwap(int* x, int* y) {
	
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

int* getRandomIntArr() {
	static int result[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		result[i] = rand() % 16000;
	}
	return result;
}

void selectionSort(int* arr) {
	//printResult(arr);
	for (int i = 0; i < arr_size; i++) {

		int min_index = i;

		for (int j = i + 1; j < arr_size; j++)
		{
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
	//printResult(arr);
}

void printResult(int* arr) {
	printf("\n\n");
	for (int k = 0; k < arr_size; k++) {
		printf(" a[%d]: %d\n", k, arr[k]);
	}
}


void insertionSort(int* arr) {
	//printResult(arr);

	for (int i = 2; i < arr_size; i++)
	{
		int j = i;

		while (j>1 && arr[j-1]>arr[j])
		{
			upgradedSwap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
	//printResult(arr);
}

void mergeSort(int* arr, int start, int end) {
	//printf("MERGE SORT\n");
	//printResult(arr);

	if (start < end) {
		int mid = start + (end - start) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);

	}

	//printResult(arr);
}

void merge(int* arr, int start, int mid, int end) {
	//printf("MERGE\n");
	//printResult(arr);
	int l1 = mid - start + 1;
	int l2 = end - mid;

	int *L = malloc(l1 * sizeof(int));
	int *R = malloc(l2 * sizeof(int));

	for (int i = 0; i < l1; i++)
	{
		L[i] = arr[start + i];
	}
	for (int j = 0; j < l2; j++)
	{
		R[j] = arr[mid + j+1];
	}

	int i = 0;
	int j = 0;
	int k = start;
	while (i < l1 && j < l2)
	{

		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < l1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	
	while (j < l2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	//printResult(arr);

	free(L);
	free(R);
}

int* getSortedIntArr()
{
	static int result[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		result[i] = i;
	}
	return result;
}
