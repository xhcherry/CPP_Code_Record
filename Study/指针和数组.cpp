﻿#include<iostream>
using namespace std;
int main() {
	//指针和数组，利用指针访问数组中的元素
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "第一个元素：" << arr[0] << endl;
	int* p = arr;//arr是数组首地址
	cout << "利用指针访问第一个元素" << *p << endl;
	p++;//让指针向后偏移4个字节
	cout << "利用指针访问第二个元素" << *p << endl;
	//指针遍历数组
	int* p2 = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << *p2 << endl;
		p2++;
	}
}
