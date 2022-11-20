#include<stdio.h>
int square(int);
int square(int num)
{
	return num * num;
}
int main()
{
	int num;
	int (*fp)(int);
	printf("输入一个整数：");
	scanf("%d",&num);
	fp = &square;//fp = square;
	printf("%d * %d = %d\n",num,num,(*fp)(num));//fp(num)
	return 0;
}
