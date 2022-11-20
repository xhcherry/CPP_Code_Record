#include <stdio.h>
int s1,s2,s3;
int vs(int a,int b,int c)
{
	int v;
	v = a * b * c;
	s1 = a * b;
	s2 = b * c;
	s3 = a * c;
	return v;
}
void main()
{
	int v,l,w,h;
	printf("lengh width high\n");
	scanf("%d%d%d",&l,&w,&h);
	v = vs(l,w,h);
	printf("v=%d,s1=%d,s2=%d,s3=%d\n",v,s1,s2,s3);
}
