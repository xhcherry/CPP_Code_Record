#include<stdio.h> 
#include <stdlib.h>
void SelectSort(int num[],int n)
{
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i + 1; j <= n; j++)
        {
            if(num[min] > num[j])//��ʣ�µ�Ԫ��ѡ��һ����С��Ԫ��
                min = j;
        }
        if(min != i)//�����СԪ�ز�����������ʼλ��Ԫ�أ�������ʼԪ�ؽ���λ��
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
	printf("������Ҫ�����Ԫ�ظ�����");
	scanf("%d",&n);
	printf("\n������Ҫ��������У�\n");
	for (int i = 1; i <= n; i++) //�����Ԫ�ش�1��ʼ��0���ڱ�
		scanf("%d",&num[i]);
	printf("\nʹ�ü�ѡ�������㷨��Ľ����\n");
	SelectSort(num,n);
	for(int i = 1; i <= n; i++)
		printf("%d\t",num[i]);
	printf("\n");
	system("pause");
	return 0;
}

