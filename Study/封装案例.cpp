#include<iostream>
using namespace std;
class student
{
public:
	string name;
	int id;
	void show()
	{
		cout << "姓名"<<name<<"学号"<<id<<endl;
	}
	void setname(string name1)
	{
		name = name1;
	}
};
int main()
{
	student stu;
	stu.id = 12;
	stu.setname("zhang");
	stu.show();
}
