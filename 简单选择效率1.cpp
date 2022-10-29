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
		//��ʼ������Сλ��Ϊ��λ
		for(int j = i + 1; j <= length - 1; ++j)
		{
			if(arr[j] < arr[mini])
				mini = j; 
			//����и�С����������±�
		}
		
		if(mini != i)
			swap(&arr[i], &arr[mini]);
		//����±귢���仯������Сֵ�Ż���ȷλ��
	}
		while(begin < end)
	{
		int min = begin, max = end;
			//˫��ͬʱ���������Сֵ
		for(i = begin; i <= end; ++i)
		{
			if(arr[max] < arr[i])
				max = i;
			
			if(arr[min] > arr[i])
				min = i;
			//������µ������Сֵ������±�
		}
		
		swap(&arr[begin], &arr[min]);
		
		if(begin == max)
			max = min;
		//�����λΪ���ֵ��������Сֵ���н�����������±�
		swap(&arr[end], &arr[max]);
			
		++begin;
		--end;
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
	SelectSort(arr,MAXSIZE);
	PrintArr(arr, MAXSIZE);
	system("pause");
	return 0;
}

