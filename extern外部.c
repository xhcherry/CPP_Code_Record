#include<stdio.h>
int max(int x,int y)
{
	int z;
	z = x > y ? x : y;
	return z;
}
void main()
{
	extern A,B;
	printf("%d\n",max(A,B));
}
int A = 13,B = -8;
