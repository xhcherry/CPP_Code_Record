//递归
#include<stdio.h>
#include<stdlib.h>

void quicksort(int * arr, int p, int r) {
	if (p < r) {
		static float ex = 0;
		int i = p - 1;
		float pivot = arr[r];
		for (int j = p; j < r; ++j) {
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
	int arr[] = {2,5,3,6,1,0};
	quicksort(arr, 0, 5);
	for (int i = 0; i < 6; ++i) {
		printf("%d ", arr[i]);
	}
}

//栈（非重复）
#include<stdio.h>
#include<stdlib.h>

void quicksort_non_recurrence(int * arr, int p, int r) {
	if (p < r) {
		int *stack = (int*)malloc(sizeof(int) * (r - p + 1));
		int pointer = -1;
		stack[++pointer] = p;
		stack[++pointer] = r;
		float ex = 0;
		int left, right = 0;
		while (pointer != -1) {
			right = stack[pointer--];
			left = stack[pointer--];
			int i = left - 1;
			float pivot = arr[right];
			for (int j = left; j < right; ++j) {
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
	int arr[] = {2,5,3,6,1,0};
	quicksort_non_recurrence(arr, 0, 5);
	for (int i = 0; i < 6; ++i) {
		printf("%d ", arr[i]);
	}
}
