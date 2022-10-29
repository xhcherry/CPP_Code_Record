#include<stdio.h>
void quick_sort(int array[],int left,int right)
{
	int i = left,j = right;
	int temp;
	int pivot;
	pivot = array[(left + right) / 2];
	while (i <= j)
	{
		//�������ҵ����ڻ�׼���Ԫ��
		while(array[i] < pivot)
		{
			i++;
		} 
		//���ҵ����ҵ�С�ڵ��ڻ�׼���Ԫ��
		while (array[j] > pivot)
		{
			j--;
		}
		//���i <= j,����
		if(i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		} 
	}
	if(left < j)
	{
		quick_sort(array,left,j);
	}
	if(i < right)
	{
		quick_sort(array,i,right);
	}
}
int main(void)
{
    int array[] = {73,108,111,118,101,70,105,115,104,67,46,99,111,109};
    int i,length;
    length = sizeof(array) / sizeof(array[0]);
    quick_sort(array,0,length - 1);
    printf("�����Ľ���ǣ�");
    for(i = 0;i < length;i++)
    {
    	printf("%d ",array[i]);
	}
	putchar('\n');
    return 0;
}
