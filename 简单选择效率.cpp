#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
 
//����ֵ
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
 
//ѡ������ �����Ǽ�¼��ֵ�±�
void SelectSort_Up(int *arr, int length)
{
	for (int i = 0; i < length-1; i++)
	{
		int index = i;//��¼��ֵ�±�
		for (int j = i + 1; j < length; j++)
		{
			//����
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
//ѡ������ �����Ǽ�¼��ֵ�±�
void SelectSort_Down(int *arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int index = i;//��¼��ֵ�±�
		for (int j = i + 1; j < length; j++)
		{
			//����
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
//��ӡ����Ԫ��
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
	srand((size_t)time(NULL));//�����������
	int arr[MAXSIZE] = { 0 };
	//��ÿ��Ԫ������һ�����ֵ
	for (int i = 0; i < MAXSIZE; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("����ǰ:\n");
	PrintArr(arr, MAXSIZE);
	printf("����:\n");
	SelectSort_Up(arr,MAXSIZE);
	PrintArr(arr, MAXSIZE);
	printf("����:\n");
	SelectSort_Down(arr, MAXSIZE);
	PrintArr(arr, MAXSIZE);
	system("pause");
	return 0;
}
