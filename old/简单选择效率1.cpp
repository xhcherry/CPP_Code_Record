#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
 
 void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void SelectSort(int *arr, int length)
{
	for(int i = 0; i < length - 1; ++i)
	{
		int mini = i;
		//开始假设最小位置为首位
		for(int j = i + 1; j <= length - 1; ++j)
		{
			if(arr[j] < arr[mini])
				mini = j; 
			//如果有更小数据则更新下标
		}
		
		if(mini != i)
			swap(&arr[i], &arr[mini]);
		//如果下标发生变化，则将最小值放回正确位置
	}
		while(begin < end)
	{
		int min = begin, max = end;
			//双向同时查找最大最小值
		for(i = begin; i <= end; ++i)
		{
			if(arr[max] < arr[i])
				max = i;
			
			if(arr[min] > arr[i])
				min = i;
			//如果有新的最大最小值则更新下标
		}
		
		swap(&arr[begin], &arr[min]);
		
		if(begin == max)
			max = min;
		//如果首位为最大值，且与最小值进行交换，则更新下标
		swap(&arr[end], &arr[max]);
			
		++begin;
		--end;
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
	SelectSort(arr,MAXSIZE);
	PrintArr(arr, MAXSIZE);
	system("pause");
	return 0;
}

