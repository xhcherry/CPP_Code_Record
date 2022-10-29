#include<stdio.h>
double average(double array[10]);
int main(void)
{
	double score[10] = {82,100,87.5,89,78,85,67.5,92.5,93,94},result;
	result = average(score);
	printf("average score is %5.2f\n",result);
	putchar('\n');
}
double average(double array[10])
{
	double result = 0;
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		result += array[i];
	}
	result /= 10;
	return result;
}
