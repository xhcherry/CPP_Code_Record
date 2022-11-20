#include <stdio.h>
int sum(int n);
int sum(int n)
{
	int result = 0;
	do
	{
		result += n;
	}while(n-- > 0);
	return result;
}
int main ()
{
	int n,result;
	printf("ÊäÈën:");
	scanf("%d",&n);
	result = sum(n);
	printf("1+2+3+4+5+6+...+(n-1)+n: %d\n",sum(n));//result
	return 0;
}
