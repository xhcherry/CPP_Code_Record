﻿#pragma once
#include"employee.h"
//构造函数
Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示个人信息
void Employee::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t普通岗位职责完成任务" << endl;
}
//获取职工岗位名称
string Employee::getDeptName() {
	return string("普通员工");
}
