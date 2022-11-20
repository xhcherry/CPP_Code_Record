选择结构
#include <stdio.h>
#include <math.h>
int main()
{
    int x, y;
    printf("Please enter x: ");
    scanf("%d", &x);
    if (x < 1)
        y = x;
    else if (x >= 1 && x <10)
        y = 2 * x - 1;
    else
        y = 3 * x - 11;
    printf("y = %d\n", y);
    return 0;
}



函数的模块化设计
#include <stdio.h>
void input();                                         //定义输入函数
void function(int m);                                 //定义功能函数
void action1(int n);                                  //定义行为1函数
void action2(int p);                                  //定义行为2函数
void action3(int q);                                  //定义行为3函数
int x;                                                //定义全局变量
int main()
{
	input();                                          //调用输入函数
	function(x);                                      //调用功能函数
	return 0;
}
//输入函数
void input()
{
	printf("Please enter x: ");
	scanf("%d", &x);
}
//功能函数
void function(int m)
{
    //通过条件表达式判断，然后执行相应的行为函数
	m < 1 ? action1(m) : (m >= 10 ? action3(m) : action2(m));
}
//行为1函数
void action1(int n)
{
	printf("y = %d\n", n);
}
//行为2函数
void action2(int p)
{
	printf("y = %d\n", 2*p-1);
}
//行为3函数
void action3(int q)
{
	printf("y = %d\n", 3*q-11);
}



switch结构
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x, y;
	printf("Please enter x: ");
	scanf("%d", &x);
	if (x>=10) y=3*x-11;
	switch(x){
	case 0: y=x; break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9: y=2*x-1; break;
	}
	printf("Y=%d\n", y);
	system("pause");
	return 0;
}
