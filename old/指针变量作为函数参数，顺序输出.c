//�������������������С˳��������ú���ʵ�ֽ�������
#include<stdio.h>
void swap(int *p1,int *p2);
void main()
{
	int a,b;
	int *pointer_1,*pointer_2;
	printf("������������:"); 
	scanf("%d %d",&a,&b);
	pointer_1 = &a;
	pointer_2 = &b;
	if(a < b)
	{
		swap(pointer_1,pointer_2);//swapʵ�ֽ���
	}
	printf("\n%d > %d\n",a,b);
}
void swap(int *p1,int *p2)
{
	int temp;
	printf("swapping......\nwait");
	temp = *p1;//temp = a;
	*p1 = *p2;//a = b;
	*p2 = temp;//b = temp;
}

