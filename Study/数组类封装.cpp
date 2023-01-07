#include<iostream>
#include"MyArray.hpp"
using namespace std;
void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}
void test1() {
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++) {
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出：" << endl;
	printIntArray(arr1);
	cout << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl;
	MyArray<int>arr2(arr1);
	cout << "arr2的打印输出：" << endl;
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "arr2尾删：" << endl;
	cout << "arr2的容量为：" << arr2.getCapacity() << endl;
	cout << "arr2的大小为：" << arr2.getSize() << endl;
	MyArray<int>arr3(100);
	arr3 = arr1;
}
//测试自定义数据类型
class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};
void printPersonArray(MyArray<Person>& personArr) {
	for (int i = 0; i < personArr.getSize(); i++) {
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}
}
void test2() {
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);
	//插入数据
	pArray.Push_Back(p1);
	pArray.Push_Back(p2);
	pArray.Push_Back(p3);
	pArray.Push_Back(p4);
	pArray.Push_Back(p5);
	printPersonArray(pArray);
	cout << "pArray的大小：" << pArray.getSize() << endl;
	cout << "pArray的容量：" << pArray.getCapacity() << endl;
}
int main() {
	test1();
	test2();
}
