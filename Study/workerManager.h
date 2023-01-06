#pragma once//防止头文件重复包含
#include<iostream>
#include<fstream>
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#define FILENAME "empFile.txt"
using namespace std;
class WorkerManager {
public:
	WorkerManager();
	void Show_menu();
	void ExitSystem();
	int m_EmpNum;
	Worker** m_EmpArray;
	void Add_Emp();
	int get_EmpNum();
	void save();
	bool m_FileIsEmpty;
	~WorkerManager();
	//初始化员工
	void init_Emp();
	//显示职工
	void Show_Emp();
};
