#include<iostream>
using namespace std;
//动物类
class Animal {
public:
	int m_Age;
};
//利用虚继承解决菱形继承的问题
//继承之前加上关键字virtual变为虚继承
//羊类
class Sheep :virtual public Animal {};
//驼类
class Tuo :virtual public Animal {};
//羊驼类
class SheepTuo :public Sheep, public Tuo {};
void test1() {
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//当菱形继承，两个父类拥有相同数据，要加作用域区分
	cout << "st.Sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age=" << st.Tuo::m_Age << endl;
}
int main() {
	test1();
}
