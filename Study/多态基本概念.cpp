#include<iostream>
using namespace std;
class Animal {
public:
	//虚函数
	virtual void speak() {
		cout << "动物说话" << endl;
	}
};
class Cat :public Animal {
public:
	void speak() {
		cout << "猫说话" << endl;
	}
};
//地址早绑定 在编译阶段确认函数地址
//如果想让猫先说话，那么这个函数地址就不能提前绑定
void doSpeak(Animal& animal) {
	animal.speak();
}
void test1() {
	Cat cat;
	doSpeak(cat);
}
int main() {
	test1();
}
