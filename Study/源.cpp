#include<iostream>
using namespace std;
int p(int a, int b) {
	return a + b;
}
int main() {
	int a, b,sum;
	cin >> a >> b;
	sum=p(a,b);
	cout << sum;
}
