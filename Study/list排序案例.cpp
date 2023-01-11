#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;
class Person {
public:
	Person(string name, int age, int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};
bool comPerson(Person& p1, Person& p2) {
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else {
		return p1.m_Age < p2.m_Age;
	}
}
void test1() {
	list<Person>L;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "name " << (*it).m_Name << " age " << it->m_Age << " height " << it->m_Height << endl;
	}
	cout << endl;
	L.sort(comPerson);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "name " << (*it).m_Name << " age " << it->m_Age << " height " << it->m_Height << endl;
	}
}
int main() {
	test1();
}
