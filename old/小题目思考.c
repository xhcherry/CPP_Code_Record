#include<stdio.h>
int main(void)
{
	char a = 0, b = 0;
	int *p = (int *)&b;
	*p = 258;
	printf("%d %d\n",a,b);
	return 0;
}
