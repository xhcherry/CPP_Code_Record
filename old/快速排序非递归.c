#include<stdio.h>
#include<stdlib.h>
#define X 8

void quicksort(int * arr, int p, int r) {
	if (p < r) {
		int *stack = (int*)malloc(sizeof(int) * (r - p + 1));
		int pointer = -1;
		stack[++pointer] = p;
		stack[++pointer] = r;
		float ex = 0;
		int left, right = 0,j;
		while (pointer != -1) {
			right = stack[pointer--];
			left = stack[pointer--];
			int i = left - 1;
			float pivot = arr[right];
			for (j = left; j < right; ++j) {
				if (arr[j] < pivot) {
					i++;
					ex = arr[i];
					arr[i] = arr[j];
					arr[j] = ex;
				}
			}
			arr[right] = arr[i + 1];
			arr[i + 1] = pivot;
			if (left < i) {
				stack[++pointer] = left;
				stack[++pointer] = i;
			}
			if (i + 2 < right) {
				stack[++pointer] = i + 2;
				stack[++pointer] = right;
			}
		}
		free(stack);
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
