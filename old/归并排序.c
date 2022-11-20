//     分治
#include <stdio.h>
void MergeSortArr(int arr[], int left, int mid, int right){
    int temp[right-left+1];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];
    for(i=0; i<k; i++)
        arr[left+i] = temp[i];
}

void MergeSort(int arr[], int left, int right){
	int i;
    if(left == right)
        return;
    int mid = (left + right)/2;
    MergeSort(arr, left, mid);				//二分
    MergeSort(arr, mid+1, right);			//二分
    MergeSortArr(arr, left, mid, right);	//归并
    for(i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[10] = {3, 1, 2, 8, 7, 5, 9, 4, 0, 6};
    MergeSort(arr, 0, 9);
}
