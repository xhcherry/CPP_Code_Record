#include <stdio.h>
int main(void)
{
	int year,leap;//leap���жϱ�ʾ����ı�־��1���ꡣ0������
	printf("�����꣺");
	scanf("%d",&year);
	if(year%4 == 0)
	{
		if(year%400 == 0)
		{
			leap = 1;
		}
		else
		{
			leap = 0;
		}
	}
	else
	{
		leap = 0;
	}
	if(leap)
	{
		printf("%d is ",year);
	}
	else
	{
		printf("%d is not ",year);
	}
	printf("a leap year\n");
	return 0;
}



