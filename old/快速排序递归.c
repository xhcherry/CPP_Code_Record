#include<stdio.h>
#include<stdlib.h>
#define X 8

void quicksort(int * arr, int p, int r) {
	if (p < r) {
		static float ex = 0;
		int i = p - 1,j;
		float pivot = arr[r];
		for (j = p; j < r; ++j) {
			if (arr[j] < pivot) {
				i++;
				ex = arr[i];
				arr[i] = arr[j];
				arr[j] = ex;
			}
		}
		arr[r] = arr[i + 1];
		arr[i + 1] = pivot;
		quicksort(arr, p, i);
		quicksort(arr, i + 2, r);
	}
}
int main() {
	int arr[] = {2,5,35,6,17,11,12,8},i;
	printf("排序前：");
	for (i = 0; i < X; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	quicksort(arr, 0, X-1);
	printf("排序后：");
	for (i = 0; i < X; ++i) {
		printf("%d ", arr[i]);
	}
}
