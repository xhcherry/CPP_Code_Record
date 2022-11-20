#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int num;
	int pwd;
	struct LNode *next;
} LNode;
LNode *createNode(int m_num,int m_pwd) {
	LNode *p;
	p=(LNode *)malloc(sizeof(LNode));
	p->num=m_num;
	p->pwd=m_pwd;
	p->next=NULL;
	return p;
}
void creatLISt(LNode **ppHead,int n) {
	int i,m_pwd;
	LNode *p,*cur;
	for(i=1; i<n; i++) {
		printf("输入第%d个人的密码：",i);
		scanf("%d",&m_pwd);
		p=createNode(i,m_pwd);
		if(*ppHead==NULL) {
			*ppHead=cur=p;
			cur->next=*ppHead;
		} else {
			p->next=cur->next;
			cur->next=p;
			cur=p;
		}
	}
	printf("完成创建！\n");

}
void jose(LNode *ppHead,int m_pwd) {
	int i,j;
	LNode *p,*p_del;
	for(i=1; p!=ppHead; i++) {
		for(j=1; j<m_pwd; ++j) {
			p=ppHead;
			ppHead=ppHead->next;
		}
		p->next = ppHead->next;
		i=ppHead->pwd;
		j=ppHead->num;
		printf("第%d个人出列，密码:%d\n,j,i");
		m_pwd=ppHead->pwd;
		free(ppHead);
		ppHead=p->next;
	}
	i=ppHead->pwd;
	j=ppHead->num;
	printf("最后一个出列的是%d号，密码是:%d\n,j,i");
	free(ppHead);
}
void instruction() {
	printf("************************************************************************************\n");
	printf("约瑟夫环:\n");
	printf("编号为1，2，3，4，...，n的n个人按顺时针方向围坐一圈，没人持有一个密码\n");
	printf( "正整数一开始任选一个正整数作为报数的上限值m,从第一个人开始\n");
	printf("按顺时针方向自1开始顺序报数，报到m时停止.报m的人出列,将他的密码＼n");
	printf("m 作为新的m 值,从他在顺时针方向上的下一人开始重新从1报数，如此下去,＼n");
	printf("直到所有人全部出列为止编程打印出列顺序\n");
	printf("****************************************************************\n");
	return 0;
}
void menu() {
	printf("******************约瑟夫环******************\n");
	printf("                                                                   \n");
	printf("                         [1]约瑟夫环问题的阐述        \n");
	printf("                         [2]按要求求解约瑟夫环        \n");
	printf("                         [0]退出                               \n");
	printf("******************欢迎使用******************\n");
}
int main() {
	int n,m, x;
	LNode *ppHead=NULL;
	menu();
	for(;;) {
		printf("\n 选择要执行的操作:");
		scanf("%d",&x);
		system("cls");
		switch(x) {
			case 1:
				printf("＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*＊**＊＊＊＊＊＊＊ ＊＊＊＊＊＊*＊\n");
				printf(" 约瑟夫环\n");
				printf(" 编号为1,2,3,4…,n的n个人按顺时针方向围坐一圈，每人持有一个密码\n");
				printf( "正整数一开始任选一个正整数作为报数的上限值m,从第一个人开始\n");
				printf("按顺时针方向自1开始顺序报数，报到m时停止.报m的人出列,将他的密码＼n");
				printf("m 作为新的m 值,从他在顺时针方向上的下一人开始重新从1报数，如此下去,＼n");
				printf("直到所有人全部出列为止编程打印出列顺序\n");
				printf("****************************************************************\n");
				main();
				break;
			case 2:
				printf ("\n输入总人数n:");
				scanf("%d",&n);
				printf("输入开始上限数 m: ");
				scanf("%d",&m);
				createList(&ppHead,n);
				printf("\n");
				priatf("出队顺序：\n");
				jose(ppHead,m);
				printf("\n 约瑟夫环游戏结束!");
				main();
				break;
			case 0:
				exit(0);
			default:
				system("cls");
				printf("\n 您选择的操作有误，请重新选择...\n \n\n");
				main();
		}
	}
	return 0;
}

