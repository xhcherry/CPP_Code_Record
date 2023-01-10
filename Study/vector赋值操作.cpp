#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
}
void test1() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	print(v1);
	//赋值
	vector<int>v2;
	v2 = v1;
	print(v2);
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	print(v3);
}

int main() {
	test1();
}
