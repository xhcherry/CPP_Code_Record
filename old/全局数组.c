#include<stdio.h>
float max = 0,min = 0;//全局变量
int main(void)
{
	float average(float array[],int n);
	float ave,score[10];
	int i;
	printf("输入十个数：");
	for(i = 0;i < 10;i++)
	{
		scanf("%f",&score[i]);
	}
	ave = average(score,10);
	printf("max=%6.2f,min=%6.2f,average=%6.2f\n",max,min,ave);
}
float average(float array[],int n)//定义函数，形参为数组
{
	int i;
	float aver,sum = array[0];
	max = min = array[0];
	for(i = 1;i < n; i++)
	{
		if(array[i] > max)
			max = array[i];
		else if(array[i] < min)
			min = array[i];
		sum += array[i];
	}
	aver = sum / n;
	return aver;
}


