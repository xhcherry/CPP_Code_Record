#include<iostream>
using namespace std;
//对象的初始化和清理
//构造函数 进行初始化操作
class Person
{
public:
	//没有返回值，不用void 函数名和类名相同，可以有参、能重载
	//创建对象的时候，构造函数会自动调用，而且只调用一次
	Person()
	{
		cout << "person构造函数的调用" << endl;
	}
	//析构函数进行清理操作
	//没有返回值不写void 函数名和类名相同再名称前加~
	//析构函数不可以有参数，不可以重载
	//对象在销毁前会自动调用析构函数，且仅调一次
	~Person()
	{
		cout << "person析构函数的调用" << endl;
	}
};
//构造和析构都是必须有实现，如果我们自己不提供，编译器会自动提供
void test1()
{
	Person p;//在栈上的数据，test1执行结束后，释放这个对象
}
int main()
{
	test1();
	//Person p;
	system("pause");
	return 0;
}
