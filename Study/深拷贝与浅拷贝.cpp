﻿#include<iostream>
using namespace std;
class Person {
public:
	Person() {
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age, int height) {
		m_Age = age;
		m_Height = new int(height);
		cout << "Person的有参构造函数调用" << endl;
	}
	//实现拷贝构造函数，解决浅拷贝的问题
	Person(const Person& p) {
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height=p.m_Height,编译器默认实现这行代码
		//深拷贝操作
		m_Height = new int(*p.m_Height);
	}
	~Person() {
		//析构代码，将堆区开辟数据做释放操作
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}
	int m_Age;
	int* m_Height;
};
void test01() {
	Person p1(18, 160);
	cout << "P1的年龄" << p1.m_Age << "身高：" << *p1.m_Height << endl;
	Person p2(p1);
	cout << "P2的年龄" << p2.m_Age << "身高：" << *p2.m_Height << endl;
}
int main() {
	test01();
}
