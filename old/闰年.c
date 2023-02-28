#include <stdio.h>
int main(void)
{
	int year,leap;//leap是判断表示闰年的标志，1闰年。0非闰年
	printf("输入年：");
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



