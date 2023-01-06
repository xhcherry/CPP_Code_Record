#include<iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//函数模板
template<typename T>//声明一个模板
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void test1() {
	int a = 10;
	int b = 20;
	//自动推到类型
	//mySwap(a, b);
	//显示指定类型
	mySwap<int>(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}
int main() {
	test1();
}
