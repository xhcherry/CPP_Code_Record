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
	printf("����һ��������");
	scanf("%d",&num);
	fp = &square;//fp = square;
	printf("%d * %d = %d\n",num,num,(*fp)(num));//fp(num)
	return 0;
}
