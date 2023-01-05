#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void test1() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "shi bai" << endl;
		return;
	}
	//四种读数据
	//1
	char buf1[1024] = { 0 };
	while (ifs >> buf1) {
		cout << buf1 << endl;
	}
	//2
	char buf2[1024] = { 0 };
	while (ifs.getline(buf2, sizeof(buf2))) {
		cout << buf2 << endl;
	}
	//3
	string buf3;
	while (getline(ifs, buf3)) {
		cout << buf3 << endl;
	}
	//4，一个一个读，效率慢
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}
	ifs.close();
}
int main() {
	test1();
}
