#include<iostream>
using namespace std;
class Add {
public:
	int operator()(int v1,int v2) {
		return v1 + v2;
	}
};
void test1() {
	Add add;
	cout << add(10, 10) << endl;
}
class Myp {
public:
	Myp() {
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}
	int count;
};
void test2() {
	Myp myp;
	myp("hello");
	myp("hello");
	myp("hello");
	cout << myp.count << endl;
}
void doP(Myp& mp, string test) {
	mp(test);
}
void test3() {
	Myp myp;
	doP(myp, "he");
}
int main() {
	test1();
	test2();
	test3();
}
