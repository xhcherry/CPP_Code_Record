#include<iostream>
#include <set>
using namespace std;
//查找和统计
void test01() {
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	//查找
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end()) {
		cout << "找到了元素 ： " << *pos << endl;
	}
	else {
		cout << "未找到元素" << endl;
	}

	//统计,对于set而言，统计结果要么是0，要么是1
	int num = s1.count(30);
	cout << "num = " << num << endl;
}
int main() {
	test01();
}
