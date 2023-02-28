#include<stdio.h> 
#include <stdlib.h>
void SelectSort(int num[],int n)
{
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i + 1; j <= n; j++)
        {
            if(num[min] > num[j])//从剩下的元素选择一个最小的元素
                min = j;
        }
        if(min != i)//如果最小元素不是无序组起始位置元素，则与起始元素交换位置
        {
            int temp = num[min];
            num[min] = num[i];
            num[i] = temp;
        }
    }
}

int main() 
{
	int num[1024],n;
	printf("请输入要输入的元素个数：");
	scanf("%d",&n);
	printf("\n请输入要排序的序列：\n");
	for (int i = 1; i <= n; i++) //输入的元素从1开始，0做哨兵
		scanf("%d",&num[i]);
	printf("\n使用简单选择排序算法后的结果：\n");
	SelectSort(num,n);
	for(int i = 1; i <= n; i++)
		printf("%d\t",num[i]);
	printf("\n");
	system("pause");
	return 0;
}

