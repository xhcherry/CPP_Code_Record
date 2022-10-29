#include<stdio.h>
int main(void)
{
	int *p1,*p2,*p,a,b;
	printf("输入两个数：");
	scanf("%d %d",&a,&b);
	p1 = &a;
	p2 = &b;
	if(a < b)
	{
		p = p1;
		p1 = p2;
		p2 = p;
	}//此后p1指向b，p2指向a
	printf("a=%d,b=%d\n",a,b);
	printf("max=%d,min=%d\n",*p1,*p2);
	return 0;
}
