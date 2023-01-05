#include<iostream>
using namespace std;
class CPU {//抽象cpu类
public:
	//抽象的计算函数
	virtual void cal() = 0;
};
class Video {//抽象显卡类
public:
	//抽象的显示函数
	virtual void display() = 0;
};
class Memory {//抽象内存类
public:
	//抽象的存储函数
	virtual void storage() = 0;
};
class Computer {
public:
	Computer(CPU* cpu, Video* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work() {
		m_cpu->cal();
		m_vc->display();
		m_mem->storage();
	}
	//析构函数，释放电脑零件
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;
	Video* m_vc;
	Memory* m_mem;
};
//具体厂商
class Intel :public CPU {
public:
	virtual void cal() {
		cout << "intel cpu open" << endl;
	}
};
class IntelVideo :public Video {
public:
	virtual void display() {
		cout << "intel gpu open" << endl;
	}
};
class IntelMem :public Memory {
public:
	virtual void storage() {
		cout << "intel mem open" << endl;
	}
};
void test1() {
	//第一台电脑零件
	CPU* intelCpu = new Intel;
	Video* intelCard = new IntelVideo;
	Memory* intelMem = new IntelMem;
	//创建第一台电脑
	Computer* com1 = new Computer(intelCpu, intelCard, intelMem);
	com1->work();
	delete com1;
	Computer* com2 = new Computer(new Intel, new IntelVideo, new IntelMem);
	com2->work();
	delete com2;
}
int main() {
	test1();
}
