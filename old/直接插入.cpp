#include<stdio.h>
#include<stdlib.h>
void insertToRightPosition(int arr[],int i)
{
    int inserted = arr[i];//����Ҫ�����Ԫ�ر��ݳ���
    int j = i-1;
    for (; j >= 0 && arr[j] > inserted; j--)
    {
        arr[j + 1] = arr[j];//����������һ��Ԫ�ش�����Ҫ�����Ԫ�أ��ͽ��������һ��Ԫ�غ��ƣ�ע������������ź��������
    }
    arr[j + 1] = inserted;//��ʱ�������������һ��Ԫ��С����Ҫ�����Ԫ�أ��ǾͰ���Ҫ�����Ԫ��ֱ�ӷŵ�����ĺ���
}

void insertsort(int arr[],int sz)
{
    int i = 0;
    //������ĵ�һ��Ԫ����Ϊһ�����ź���ļ��ϣ������arr[1]�����Ԫ�ض���δ�ź���ļ���
    for (i = 1; i < sz; i++)
    {
        insertToRightPosition(arr,i);//��arr[i]�嵽��ȷλ��
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
	printf("ԭʼ���ݣ�") ; 
    int arr[10] = { 1, 3, 5, 4, 6, 8, 2, 9, 7, 0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    test(arr,sz);//��������Ԫ��
    printf("ֱ�Ӳ��������") ; 
	insertsort(arr,sz);
    test(arr, sz);
    system("pause");
    return 0;
}
