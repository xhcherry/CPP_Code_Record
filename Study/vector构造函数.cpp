#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test1() {
	vector<int>v1;//默认构造，无参
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	print(v1);
	vector<int>v2(v1.begin(), v1.end());
	print(v2);
	vector<int>v3(10, 100);
	print(v3);
	vector<int>v4(v3);//拷贝构造
	print(v4);
}
int main() {
	test1();
}
