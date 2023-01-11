#include<iostream>
#include<set>
using namespace std;
void test1() {
	set<int>s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second) {
		cout << "第一次成功" << endl;
	}
	else {
		cout << "第一次失败" << endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		cout << "第二次成功" << endl;
	}
	else {
		cout << "第二次失败" << endl;
	}
	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main() {
	test1();
}
