#include<iostream>
#include<ctime>
using namespace std;
struct student {
	string sname;
	int score;
};
struct teacher {
	string tname;
	struct student sarray[5];
};
void allocateSpace(struct teacher tarray[], int len) {
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++) {
		tarray[i].tname = "teacher_";
		tarray[i].tname += nameseed[i];
		for (int j = 0; j < 5; j++) {
			tarray[i].sarray[j].sname = "teacher_";
			tarray[i].sarray[j].sname += nameseed[j];
			int random = rand() % 61 + 40;
			tarray[i].sarray[j].score = random;
		}
	}
}
void printinfo(struct teacher tarray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "老师姓名："<<tarray[i].tname<<endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "xingming:" << tarray[i].sarray[j].sname << 
				"fenshu:" << tarray[i].sarray[j].score << endl;
		}
	}
}
int main() {
	srand((unsigned int)time(NULL));
	//创建3名老师的数组
	struct teacher tarray[3];
	//通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
	int len = sizeof(tarray) / sizeof(tarray[0]);
	allocateSpace(tarray, len);
	//打印所有老师及所带学生信息
	printinfo(tarray, len);
}
