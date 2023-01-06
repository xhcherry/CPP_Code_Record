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
	//删除职工
	void Del_Emp();
	//按照职工编号判断职工是否存在, 若存在返回职工在数组中位置，不存在返回 - 1
	int IsExist(int id);
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//排序职工
	void Sort_Emp();
	//清空文件
	void Clean_File();
};
