#include<stdio.h>
#include<stdlib.h>
int main ()
{
	float r,h;
	scanf_s("%f%f",&r,&h);
	float C1,Sa,Sb,Va,Vb;
	double PI=3.14;
	C1=2*PI*r;
	Sa=PI*r*r;
	Sb=4*PI*r*r;
	Va=(4.0/3)*PI*r*r*r;
	Vb=PI*r*r*h;
	getchar();
	printf("C1=%.2f\nSa=%.2f\nSb=%.2f\nVa=%.2f\nVb=%.2f\n",C1,Sa,Sb,Va,Vb);
	system("pause");
	return 0;
}
