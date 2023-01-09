#include<iostream>
#include<string>
using namespace std;
void test1() {
	string str = "asdfgh";
	string subStr = str.substr(1, 3);
	cout << subStr << endl;
}
void test2() {
	string email = "lisi@gmail.com";
	int pos = email.find("@");
	string name = email.substr(0, pos);
	cout << name << endl;
}
void main() {
	test1();
	test2();
}
