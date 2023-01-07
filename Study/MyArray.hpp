#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
class MyArray {
public:
	//构造函数
	MyArray(int capacity) {
		cout << "myarray有参构造" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}
	//拷贝构造
	MyArray(const MyArray& arr) {
		cout << "myarray拷贝构造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;
		this->pAddress = new T[arr.m_Capacity];//深拷贝
		//将arr中的数据拷贝过来
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//防止浅拷贝
	MyArray& operator=(const MyArray& arr) {
		cout << "myarray的operator=构造" << endl;
		//先判断原阿里堆区是否有数据
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void Push_Back(const T& val) {
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size) {
			return;
		}
		this->pAddress[this->m_Size] = val;//在数组末尾插入数据
		this->m_Size++;//更新数组大小
	}
	//尾删
	void Pop_Back() {
		//让用户无法访问最后一个元素，逻辑删除
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}
	//通过下标方式数组中的元素
	T& operator[](int index) {
		return this->pAddress[index];
	}
	//返回数组容量
	int getCapacity() {
		return this->m_Capacity;
	}
	int getSize() {
		return this->m_Size;
	}
	~MyArray() {
		if (this->pAddress != NULL) {
			cout << "myarray析构构造" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;  //指向一个堆空间，这个空间存储真正的数据
	int m_Capacity; //容量
	int m_Size;   // 大小
};
