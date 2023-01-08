#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void test1() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	//通过迭代器访问容器数据
	//vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
	//vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	//利用stl标准算法
	for_each(v.begin(), v.end(), myPrint);
}
void myPrint(int val) {
	cout << val << endl;
}
void main() {
	test1();
}
