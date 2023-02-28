#include<stdio.h>
void main()
{
	void exchange(int *q1,int *q2,int *q3);//使得a>b>c;
	int a,b,c,*p1,*p2,*p3;
	printf("输入三个数:"); 
	scanf("%d %d %d",&a,&b,&c);
	p1 = &a;
	p2 = &b;
	p3 = &c;
	exchange(p1,p2,p3);//确保a>b>c
	printf("%d %d %d\n",a,b,c);
}
void exchange(int *q1,int *q2,int *q3)//int *q1 = p1;
{
	void swap(int *pt1,int *pt2);
	if(*q1 < *q2)
	{
		swap(q1,q2);
	}
	if(*q1 < *q3)
	{
		swap(q1,q3);
	}
	if(*q2 < *q3)
	{
		swap(q2,q3);
	}
}
void swap(int *pt1,int *pt2)
{
	int temp;
	temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;
}

