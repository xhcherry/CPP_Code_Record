#include<iostream>
using namespace std;
//引用作为重载的条件
void fun(int& a) {//int &a=10;不合法
	cout<<"fun(int&a)的调用" << endl;
}
void fun(const int& a) {//const int &a=10;合法
	cout << "fun(const int&a)的调用" << endl;
}
//函数重载碰到默认参数
void fun2(int a,int b=10) {
	cout << "fun2(int a,int b)的调用" << endl;
}
void fun2(int a) {
	cout << "fun2(int a)的调用" << endl;
}
int main() {
	//int a = 10;
	//fun(a);
	//fun(10);
	//fun2(10);当函数重载碰到默认参数，出现二义性，有冲突
	return 0;
}
