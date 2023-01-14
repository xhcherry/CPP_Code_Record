#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
void test1() {
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);
	int num = count(v.begin(), v.end(), 40);
	cout << num << endl;
}
class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person& p) {
		if (this->m_Age == p.m_Age) {
			return true;
		}
		else {
			return false;
		}
	}
	string m_Name;
	int m_Age;
};
void test2() {
	vector<Person> v;
	//创建数据
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	Person p("诸葛亮", 35);
	int num = count(v.begin(), v.end(), p);
	cout << num << endl;
}
int main() {
	test1();
	test2();
}
