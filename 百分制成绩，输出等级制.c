switch选择结构
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int score, g;
    scanf("%d", &score);
    while (score < 0 || score > 100){
        printf("Error! Retry!\n");
        scanf("%d", &score);
    }
    g = score / 10;
    if (g >= 9)
        printf("Grade is A!\n");
    switch(g){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5: printf("Grade is E!\n"); break;
    case 6: printf("Grade is D!\n"); break;
    case 7: printf("Grade is C!\n"); break;
    case 8: printf("Grade is B!\n"); break;
    }
    system("pause");
    return 0;
}


条件结构
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int score;
    scanf("%d", &score);
    while (score < 0 || score >100){
        printf("Error! Retry!\n");
        scanf("%d", &score);
    }
    if (score < 60)
        printf("Grade is E!\n");
    else if (score >= 60 && score < 70)
        printf("Grade is D!\n");
    else if (score >= 70 && score < 80)
        printf("Grade is C!\n");
    else if (score >=80 && score < 90)
        printf("Grade is B!\n");
    else
        printf("Grade is A!\n");
    system("pause");
    return 0;
}



函数的模块化设计
#include <stdio.h>
#include <stdlib.h>
void grade();                                      //定义等级函数
void input();                                      //定义输入函数
void function(double x);                           //定义分级判断函数
void error();                                      //定义出错函数
double score;                                      //定义全局变量，分数
int main()
{
	grade();                                       //调用等级函数
	system("pause");
	return 0;
}
//等级函数
void grade()
{
	input();                                       //调用输入函数
	function(score);                               //调用分级判断函数
}
//输入函数
void input()
{
	printf("Please enter score: ");
	scanf("%lf", &score);
}
//分级判断函数
void function(double x)
{
	int n;
	n = x / 10;
	switch(n){
	case 9: printf("Grade is A!\n"); break;
	case 8: printf("Grade is B!\n"); break;
	case 7: printf("Grade is C!\n"); break;
	case 6: printf("Grade is D!\n"); break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1: 
	case 0: printf("Grade is E!\n"); break;
	//此处为了区别100.1至100.9也属于出错范围而设置
	default: x == 100 ? printf("Grade is A!\n") : (error(), grade()); break;
	}
}
//出错函数
void error()
{
	printf("Error! Retry!\n");
}



动态分配内存
#include <stdio.h>
#include <stdlib.h>
void input(double *s);
void score_output(double *s);
int main()
{
	double *score=(double*)malloc(sizeof(double));
	input(score);
	score_output(score);
	system("pause");
	return 0;
}
void input(double *s)
{
	printf("Enter score: ");
	scanf("%lf", s);
}
void score_output(double *s)
{
	int grade=*s/10;
	switch(grade){
	case 10:
	case 9: printf("A\n"); break;
	case 8: printf("B\n"); break;
	case 7: printf("C\n"); break;
	case 6: printf("D\n"); break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0: printf("E\n"); break;
	default: break;
	}
}
