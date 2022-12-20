#include<iostream>
using namespace std;
//实现两个数字交换
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << a << endl;
	cout << b << endl;
}
void swap2(int* c, int* d)
{
	int temp = *c;
	*c = *d;
	*d = temp;
}
int main() {
	//指针函数
	int a = 10;
	int b = 20;
	//1.值传递
	//swap1(a, b);
	//2.地址传递
	//如果是地址传递，可以修饰实参
	swap2(&a, &b);
	cout << a << endl;
	cout << b << endl;
}
