#include<iostream>
using namespace std;
int main() {
	int a = 100;
	int* p;
	p = &a;
	cout << "p地址" << p << endp;
	cout << "a地址" << &a << endl;
	*p = 200;
	cout << "*p=" << *p << endl;
	cout << "a=" << a << endl;
	cout << "sizeof (int *)=" << sizeof(int*) << endl;
	cout << "sizeof (char *)=" << sizeof(char*) << endl;
	cout << "sizeof (double *)=" << sizeof(double*) << endl;
	cout << "sizeof (float *)=" << sizeof(float*) << endl;
}
