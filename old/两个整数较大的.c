#include<stdio.h>
int max(int ,int );
int max(int x,int y)
{
	if( x > y )
	return x;
	else
	return y;
	printf("shuai\n");
}
int main()
{
	int a,b,c;
	printf("请输入两个整数：");
	scanf("%d %d",&a,&b);
	c = max(a,b);
	printf("较大值是：%d\n",c); 
	return 0;
}
