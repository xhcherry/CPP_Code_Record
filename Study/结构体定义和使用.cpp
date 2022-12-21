#include<iostream>
using namespace std;
//创建学生数据类型
//自定义数据类型，一些类型的集合
//语法 struct 类型名称{成员列表}
struct Student
{
	//成员列表
	//姓名
	string name;
	//分数
	int score;
	int age;
} s3;//顺便创建变量
//2.通过学生类型创建具体学生
//2.1 struct Student s1
//2.2 struct student s2={...}
//2.3 在定义结构体时顺便创建具体学生
int main() {
	struct Student s1;//struct创建可省略，定义不可以
	s1.name = "zhangsan";
	s1.age = 14;
	s1.score = 99;
	cout << s1.name << s1.age << s1.score << endl;
	struct Student s2 = { "zhang",19,90 };
	cout << s2.name << s2.age << s2.score << endl;
	s3.name = "zhang1";
	cout << s3.name << endl;
}
