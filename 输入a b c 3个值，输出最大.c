选择结构设计
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, max;
    scanf("%d %d %d", &a, &b, &c);
    /* Use if...else... structure to determine the maximum of three numbers.
       利用if...else...结果判断3个数字的最大值。*/
    if(a>b){
        if(a>c)
            max=a;
        else
            max=c;
    }
    else{
        if(b>c)
            max=b;
        else
            max=c;
    }
    printf("Max=%d\n", max);
    system("pause");
    return 0;
}




条件表达式
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, max;
    scanf("%d %d %d", &a, &b, &c);
    /* Use conditional expressions to determine the maximum value.
       利用条件表达式判断最大值。 */
    max=(a>b ? (a>c ? a : c) : (b>c ? b : c));
    printf("Max=%d\n", max);
    system("pause");
    return 0;
}




函数的模块化设计
#include <stdio.h>
#include <stdlib.h>
int max(int x, int y, int z);               // Define the function of the maximum. 定义最大值函数。
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("Max=%d\n", max(a, b, c));
    system("pause");
    return 0;
}
int max(int x, int y, int z)
{
    return (x>y ? (x>z ? x : z) : (y>z ? y : z));  // Use conditional expressions. 利用条件表达式
}



指针法1
#include <stdio.h>
#include <stdlib.h>
void max(int *p, int *q, int *r);          // Define the function of the maximum. 定义最大值函数。
int main()
{
	int a, b, c, *x, *y, *z; 
	x=&a, y=&b, z=&c;
	printf("Please enter number a b c: ");
	scanf("%d %d %d", x, y, z);
	max(x, y, z);          // Call the function of the maximum. 调用最大值函数。
	system("pause");
	return 0;
}
void max(int *p, int *q, int *r)
{
	int m;
	m=*p>*q ? (*p>*r ? *p : *r) : (*q>*r ? *q : *r);
	printf("Max=%d\n", m);
}
