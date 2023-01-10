#include<iostream>
#include<deque>
using namespace std;
void print(deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
}
void test1() {
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	print(d1);
	//尾删
	d1.pop_back();
	//头删
	d1.pop_front();
	print(d1);
}
//插入
void test02() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	print(d);
	d.insert(d.begin(), 1000);
	print(d);
	d.insert(d.begin(), 2, 10000);
	print(d);
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d.insert(d.begin(), d2.begin(), d2.end());
	print(d);
}
//删除
void test03() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	print(d);
	d.erase(d.begin());
	print(d);
	d.erase(d.begin(), d.end());
	d.clear();
	print(d);
}
int main() {
	test1();
}
