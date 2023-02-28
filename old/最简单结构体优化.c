#include<stdio.h>
#include<stdlib.h>
typedef struct Date
{
	int year;
	int month;
	int day;
}DATE, *PDATE;
int main(void)
{
	struct Date *date;
	date = (PDATE)malloc(sizeof(DATE));
	if(date == NULL)
	{
		printf("内存分配失败！\n");
		exit(1);
	}
	date->year = 2021;
	date->month = 9;
	date->day = 21;
	printf("%d.%d.%d\n",date->year,date->month,date->day);
	return 0;
} 
