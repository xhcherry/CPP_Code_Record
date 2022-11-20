for循环和数组
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n, i, j, k, b[5];
	printf("Please enter number: ");
	for (i=0; ; i++){
		scanf("%d", &n);
		if (n<100000) break;
		else printf("Error!\nPlease enter number: ");
	}
	for (i=1, j=1; i<=10000; i*=10, j++)
		if (n/i>0&&n/i<10){
			printf("Bit=%d\n", j);
			break;
		}
	for (k=0; i>=1; b[k++]=n/i, n%=i, i/=10);
	for (i=0; i<j; printf("%d ", b[i++]));
	printf("\n");
	for (i=j-1; i>=0; printf("%d ", b[i--]));
	printf("\n");
	return 0;
}







条件选择结构
#include <stdio.h>
#include <stdlib.h>
int main(){
    int x, a, b, c, d, e;
    //输入一个整数
	printf("Please enter number: ");
    scanf("%d", &x);
    //以下是判断整数是否多于5位，多于判断出错，重新输入
    while (x < 0 || x > 99999){
        printf("Error! Retry!\nPlease enter number: ");
        scanf("%d", &x);
    }
    //以下判断出该数是几位数
    a = x / 10000;
    b = x / 1000;
    c = x / 100;
	d = x / 10;
    e = x - d * 10;
    if (a >= 1 && a <= 9){
        printf("%d is 5 bits!\n", x);
        printf("%d %d %d %d %d\n", a, b-a*10, c-b*10, d-c*10, e);
        printf("%d %d %d %d %d\n", e, d-c*10, c-b*10, b-a*10, a);
    }
    else if (b >= 1 && b <= 9){
        printf("%d is 4 bits!\n", x);
        printf("%d %d %d %d\n", b, c-b*10, d-c*10, e);
        printf("%d %d %d %d\n", e, d-c*10, c-b*10, b);
    }
    else if (c >= 1 && c <= 9){
        printf("%d is 3 bits!\n", x);
        printf("%d %d %d\n", c, d-c*10, e);
        printf("%d %d %d\n", e, d-c*10, c);
    }
	else if (d >= 1 && d <= 9){
		printf("%d is 2 bits!\n", x);
        printf("%d %d\n", d, e);
        printf("%d %d\n", e, d);
	}
    else{
        printf("%d is 1 bits!\n", x);
        printf("%d\n", x);
    }
    return 0;
}





数组、swtich和循环结构
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int num, i, j, bit, c[7], n[7];
	printf("Please enter number: ");               //输入一个整数
	scanf("%d", &num);
	//判断整数是否多于5位，报错，重新输入
	while (num >= 100000){
		printf("Error!\nPlease enter number: ");
		scanf("%d", &num);
	}
	//判断整数是几位数
	for (i = 1; i < 1000000 && j != 0; i *= 10)
		j = num / i;
	i /= 100;
	switch(i){
	case 1: bit = 1; break;
	case 10: bit = 2; break;
	case 100: bit = 3; break;
	case 1000: bit = 4; break;
	case 10000: bit = 5; break;
	default: break;
	}
	printf("%d is %d bits!\n", num, bit);
	//此处是一个为输出数字的中间模块
	for (i = 0; i <= bit; i++)
		c[i] = num / pow(10, bit-i);
    //分别输出整数的每位数字
	for (i = 0; i < bit; i++){
		n[i] = c[i+1] - c[i] * 10;
		printf("%d ", n[i]);
	}
	printf("\n");
	//逆序输出每位数字
	for (i = bit-1; i >= 0; i--)
		printf("%d ", n[i]);
	printf("\n");
	return 0;
}





函数的模块化设计
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void input();                       //定义输入函数
void bits(int x);                   //定义数字位数函数
void output(int x);                 //定义数字输出函数
void re_output(int x);              //定义数字逆序输出函数
void error();                       //定义报错函数
int num, i, bit, c[7], n[7];        //定义全局变量
int main(){
	input();                        //调用输入函数
	bits(num);                      //调用数字位数函数
	output(num);                    //调用数字输出函数
	re_output(num);                 //调用数字逆序输出函数
	return 0;
}
//输入函数
void input(){
	printf("Please enter number: ");
	scanf("%d", &num);
	//一旦数字超过5位，调用报错函数并递归调用本函数
	while (num >= 100000){
		error();
		input();
	}
}
//数字位数函数
void bits(int x){
	int j;
	for (i = 1; i < 1000000 && j != 0; i *= 10)
		j = x / i;
	i /= 100;
	switch(i){
	case 1: bit = 1; break;
	case 10: bit = 2; break;
	case 100: bit = 3; break;
	case 1000: bit = 4; break;
	case 10000: bit = 5; break;
	default: break;
	}
	printf("%d is %d bits!\n", x, bit);
}
//数字输出函数
void output(int x){
	for (i = 0; i <= bit; i++)
		c[i] = x / pow(10, bit-i);
	for (i = 0; i < bit; i++){
		n[i] = c[i+1] - c[i] * 10;
		printf("%d ", n[i]);
	}
	printf("\n");
}
//数字逆序输出函数
void re_output(int x){
	for (i = bit-1; i >= 0; i--)
		printf("%d ", n[i]);
	printf("\n");
}
//报错函数
void error(){
	printf("Error!\n");
}








动态分配内存
#include <stdio.h>
#include <stdlib.h>
void input(int *n);
void bits(int n);
void output(int n);
void reverse(int n);
int main(){
	int *num=(int*)malloc(sizeof(int));
	input(num);
	bits(*num);
	output(*num);
	reverse(*num);
	return 0;
}
void input(int *n){
	printf("Enter number: ");
	scanf("%d", n);
	while(*n>10000){
		printf("Error! Enter number: ");
		scanf("%d", n);
	}
}
void bits(int n){
	int i, g;
	for(i=1, g=n/i; i<=1000&&g>10; i*=10, g=n/i);
	switch(i){
	case 1: printf("%d is 1 bits.\n", n); break;
	case 10: printf("%d is 2 bits.\n", n); break;
	case 100: printf("%d is 3 bits.\n", n); break;
	case 1000: printf("%d is 4 bits.\n", n); break;
	default: break;
	}
}
void output(int n){
	int mod, i;
	for(i=1000, mod=i; i>=1; i/=10){
		mod=n/i;
		if(mod!=0)
			printf("%d ", mod);
		n=n%i;
	}
	printf("\n");
}
void reverse(int n){
	int mod, i;
	for(i=10; n!=0; n/=i){
		mod=n%i;
		printf("%d ", mod);
	}
	printf("\n");
}
