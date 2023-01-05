#pragma once
#include"Boss.h"
Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示个人信息
void Boss::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\tboss岗位职责完成任务" << endl;
}
//获取岗位名称
string Boss::getDeptName() {
	return string("boss");
}
