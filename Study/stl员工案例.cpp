#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <ctime>
class Person {
public:
	string name;
	int money;
};
void addPerson(vector<Person>& A) {
	string str = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		string name = "员工";
		name += str[i];
		Person p;
		//初始化姓名
		p.name = name;
		//随机工资
		p.money = 10000 + rand() % 10000;
		//插入到容器中
		A.push_back(p);
	}
}
void addBumen(vector<Person>& A, multimap<int, Person>& B) {
	for (int i = 0; i < A.size(); i++) {
		B.insert(make_pair(rand() % 3, A[i]));
	}
}
void showInfo(multimap<int, Person>& B) {
	multimap<int, Person>::iterator it = B.begin();
	int i = 0;
	cout << "策划部门:" << endl;
	for (i = 0; it != B.end() && i < B.count(0); it++, i++) {
		cout << "姓名是: " << it->second.name << " 工资是:" << it->second.money << endl;
	}
	cout << "----------------------" << endl;
	cout << "美术部门:" << endl;
	for (i = 0; it != B.end() && i < B.count(1); it++, i++) {
		cout << "姓名是: " << it->second.name << " 工资是:" << it->second.money << endl;
	}
	cout << "----------------------" << endl;
	cout << "研发部门:" << endl;
	for (i = 0; it != B.end() && i < B.count(2); it++, i++) {
		cout << "姓名是: " << it->second.name << " 工资是:" << it->second.money << endl;
	}
}
void test01() {
	//创建随机数种子
	srand((unsigned int)time(NULL));
	//创建10个员工并且填写姓名随机工资
	vector<Person>A;
	addPerson(A);
	//随机分配部门
	multimap<int, Person>B;
	addBumen(A, B);
	//分部门显示员工信息
	showInfo(B);
}
int main() {
	test01();
}
