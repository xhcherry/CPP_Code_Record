#include<iostream>
using namespace std;
class Person {
public:
	//传统初始化操作
	/*Person(int a, int b, int c) {
		m_A = a;
		m_B = b;
		m_C = c;
	}*/
	//初始化列表初始化属性
	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c) {

	}
	int m_A;
	int m_B;
	int m_C;
};
void test1() {
	//Person p(10, 20, 30);
	Person p(30,20,10);
	cout << p.m_A << endl;
	cout << p.m_B << endl;
	cout << p.m_C << endl;
}
int main() {
	test1();
}
