#include<iostream>
#include<string>
#include<set>
using namespace std;
class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class comP {
public:
	bool operator()(const Person& p1, const Person& p2)const {
		return p1.m_Age > p2.m_Age;
	}

};
void test1() {
	set<Person,comP>s;
	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person, comP>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "name " << it->m_Name << " age " << it->m_Age << endl;
	 }
}
int main() {
	test1();
}
