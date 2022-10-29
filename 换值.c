#include<stdio.h>
void swap(int *x,int *y);
void swap(int *x,int *y)
{
	int temp;
	printf("in swap,»¥»»Ç°:x = %d, y = %d\n",*x,*y);
	temp = *x;
	*x = *y;
	*y = temp;
	printf("in swap,»¥»»ºó:x = %d,y = %d\n",*x,*y);
}
int main()
{
	int x = 3,y = 5;
	printf("in main,»¥»»Ç°:x = %d, y = %d\n",x,y);
	swap(&x,&y);
	printf("in main,»¥»»ºó:x = %d, y = %d\n",x,y);
	return 0;
}
