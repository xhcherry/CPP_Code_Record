//?¡§?(2^2)!+(3^2)!
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
long square(int p);//???¡è?
long factorial(int q);//?????
int main(void)
{
	int i;
	long s = 0;
/*	for(i = 2;i <= 3;i++)
	{
		s = s + square(i);
	}*/
	s = square(2) + square(3);
	printf("%d\n",s);
}
long square(int p)
{
	int k;
	long r;
	long factorial(int);
	k = p * p;
	r = factorial(k);
	return r;
}
long factorial(int q)
{
	long c = 1;
	int i ;
	for(i = 1;i <= q;i++)
	{
		c *= i;
	}
	return c;
}
