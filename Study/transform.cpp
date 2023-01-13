#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Transform {
public:
	int operator()(int v) {
		return v + 10;
	}
};
class print {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};
void test1() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>vT;//目标容器
	vT.resize(v.size());//需要提前开辟空间
	transform(v.begin(), v.end(), vT. begin(), Transform());
	for_each(vT.begin(), vT.end(),print());
}
int main() {
	test1();
}
