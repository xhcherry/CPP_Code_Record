#include<stdio.h>
#include<stdlib.h>
void insertToRightPosition(int arr[],int i)
{
    int inserted = arr[i];//将需要插入的元素备份出来
    int j = i-1;
    for (; j >= 0 && arr[j] > inserted; j--)
    {
        arr[j + 1] = arr[j];//如果数组最后一个元素大于需要插入的元素，就将数组最后一个元素后移，注意此数组是已排好序的数组
    }
    arr[j + 1] = inserted;//此时，则是数组最后一个元素小于需要插入的元素，那就把需要插入的元素直接放到数组的后面
}

void insertsort(int arr[],int sz)
{
    int i = 0;
    //把数组的第一个元素作为一个已排好序的集合，数组从arr[1]后面的元素都是未排好序的集合
    for (i = 1; i < sz; i++)
    {
        insertToRightPosition(arr,i);//将arr[i]插到正确位置
    }
}
void test(int arr[],int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
	printf("原始数据：") ; 
    int arr[10] = { 1, 3, 5, 4, 6, 8, 2, 9, 7, 0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    test(arr,sz);//输出数组的元素
    printf("直接插入排序后：") ; 
	insertsort(arr,sz);
    test(arr, sz);
    system("pause");
    return 0;
}
