#include <stdio.h>
#define M 1000
int a[M],b[M];
void Merge(int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	while(i <= mid && j <= right) {
		if(a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i <= mid)
		b[k++] = a[i++];
	while(j <= right)
		b[k++] = a[j++];
	for(i=left; i<=right; i++) {
		a[i] = b[i];
		printf("%d ",a[i]);
	}
	printf("\n");
}

void MergeSort(int a, int b) {
	if(a < b) {
		int mid = (a + b)/2;
		MergeSort(a, mid);
		MergeSort(mid+1, b);
		Merge(a, mid, b);
	}
}

int main() {
	int i,n;
	scanf("%d",&n);
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	MergeSort(0,n-1);
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
}
