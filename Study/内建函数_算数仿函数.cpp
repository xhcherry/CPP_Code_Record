#include<iostream>
using namespace std;
#include<functional>
//negate一元仿函数 取反仿函数
void test1() {
	negate<int>n;
	cout << n(50) << endl;
}
void test2() {
	plus<int>p;
	cout << p(10, 20) << endl;
}
int main() {
	test1();
	test2();
}
