#include<iostream>
#include<string>
using namespace std;
//普通计算器
class Calculator {
public:
	int getResult(string oper) {
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
	}
	int m_Num1 = 0;
	int m_Num2 = 0;
};
void test1() {
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 11;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
}
//多态计算器
//好处：结构清晰；可读性强；易于前后期拓展和维护
//计算器抽象类
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_Num1 = 0;
	int m_Num2 = 0;
};
class Add :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};
class Sub :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};
class Mul :public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};
void test2() {
	//多态使用条件，父类指针或引用指向子类对象
	AbstractCalculator* abc = new Add;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	//用完要销毁
	delete abc;
	abc = new Sub;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = new Mul;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
}
int main() {
	test2();
}
