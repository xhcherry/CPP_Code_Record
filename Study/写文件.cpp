#include<iostream>
using namespace std;
#include<fstream>
void test1() {
	ofstream ofs;
	ofs.open("test.txt",ios::out);
	ofs << "name:zhangsan" << endl;
	ofs.close();
}
int main() {
	test1();
}
