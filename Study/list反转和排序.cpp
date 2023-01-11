#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
void print(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test1() {
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(40);
	print(L1);
	L1.reverse();
	print(L1);
}
bool myCom(int v1,int v2) {
	//降序，第一个数大于第二个数
	return v1 > v2;
}
void test2() {
	list<int>L1;
	L1.push_back(20);
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(40);
	print(L1);
	//所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供对应一些算法
	L1.sort();//默认从小到大
	print(L1);
	L1.sort(myCom);
	print(L1);
}
int main() {
	test1();
	test2();
}
