#include<stdio.h>
#include<time.h>
int main(void)
{
	enum Week {sun,mon,tue,wed,thu,fri,sat};
	enum Week today;
	struct tm *p;
	time_t t;
	time(&t);
	p = localtime(&t);
	today = p -> tm_wday;
	switch(today)
	{
		case mon:
		case tue:
		case wed:
		case thu:
		case fri:
		printf("干活\n");
		break;
		case sat:
		case sun:
		printf("放假\n");
		break;
		default:
		printf("error\n");
		return 0;				
	}
} 
