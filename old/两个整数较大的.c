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
	printf("����������������");
	scanf("%d %d",&a,&b);
	c = max(a,b);
	printf("�ϴ�ֵ�ǣ�%d\n",c); 
	return 0;
}
