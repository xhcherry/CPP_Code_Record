﻿#include<iostream>
using namespace std;
//拷贝构造函数调用时机
class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int age)
	{
		cout << "Person有参构造函数调用" << endl;
		m_Age = age;
	}
	Person(const Person& p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
	int m_Age;
};
//1.使用一个已经创建完毕的对象来初始化一个新对象
void test1()
{
	Person p1(20);
	Person p2(p1);
	cout<<"p2年龄：" << p2.m_Age << endl;
}
//2.值传递的方式给函数参数传值
void doWork(Person p)
{

}
void test2()
{
	Person p;
	doWork(p);
}
//3.值方式返回局部对象
Person work()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}
void test3()
{
	Person p = work();
	cout << (int*)&p << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
}
