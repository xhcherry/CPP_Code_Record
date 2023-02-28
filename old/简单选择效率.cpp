#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
 
//交换值
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
 
//选择排序 核心是记录最值下标
void SelectSort_Up(int *arr, int length)
{
	for (int i = 0; i < length-1; i++)
	{
		int index = i;//记录最值下标
		for (int j = i + 1; j < length; j++)
		{
			//升序
			if (arr[index] > arr[j])
			{
				index = j;
			}
		}
		if (i != index)
		{
			Swap(&arr[i], &arr[index]);
		}
	}
}
//选择排序 核心是记录最值下标
void SelectSort_Down(int *arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int index = i;//记录最值下标
		for (int j = i + 1; j < length; j++)
		{
			//降序
			if (arr[index] < arr[j])
			{
				index = j;
			}
		}
		if (i != index)
		{
			Swap(&arr[i], &arr[index]);
		}
	}
}
//打印数组元素
void PrintArr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}
 
 
int main(int argc, char *argv[])
{
	srand((size_t)time(NULL));//设置随机种子
	int arr[MAXSIZE] = { 0 };
	//给每个元素设置一个随机值
	for (int i = 0; i < MAXSIZE; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("排序前:\n");
	PrintArr(arr, MAXSIZE);
	printf("升序:\n");
	SelectSort_Up(arr,MAXSIZE);
	PrintArr(arr, MAXSIZE);
	printf("降序:\n");
	SelectSort_Down(arr, MAXSIZE);
	PrintArr(arr, MAXSIZE);
	system("pause");
	return 0;
}
