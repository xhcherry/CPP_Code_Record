#include<iostream>
using namespace std;
class Person {
public:
	Person(int age) {
		this->age = age;
	}
	Person& PersonAdd(Person &p) {
		this->age += p.age;
		//this指向p2的指针，而*this指向的就是p2对象的本体
		return *this;
	}
	int age;
};
void test1() {
	Person p1(18);
	cout << p1.age << endl;
}
void test2() {
	Person p1(10);
	Person p2(10);
	//链式编程思想
	p2.PersonAdd(p1).PersonAdd(p1);
	cout << p2.age << endl;
}
int main() {
	//test1();
	test2();
}
