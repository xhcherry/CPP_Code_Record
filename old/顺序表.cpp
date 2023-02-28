#include<stdio.h>
#include<stdlib.h>
#define N 10 //顺序表的最大容量
int length=0; //顺序表的当前元素个数
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100//线性表存储的空间初始化分配量
#define LISTINCREAMENT 10 //线性表存储空间的分配增量
typedef struct LNode { //线性单链表存储结构
	int data;
	struct LNode *next;
} LNode,*LinkList;
int CreatList_L(LinkList&L) { //创建一个线性链表
	L=(LinkList)malloc(sizeof(LNode));//分配一个空间给链表，作为头结点
	if(!L) exit(OVERFLOW);
	L->next=NULL;
	return OK;
}
int DestroyList_L(LinkList &L) { //销毁链表
	if(L) free(L);
	return OK;
}
int ListInsert_L(LinkList&L,int i,int e) { //再练表的第i个元素前插入一个元素e
	LinkList p=L;//p指针定位于i-1
	LNode *s;
	int j=0;
	while(p&&j<i-1) {
		p=p->next;    //定位
		j++;
	}
	if(!p||j>i-1) return ERROR;//如果i<1或大于链表元素个数+1
	s=(LNode*)malloc(sizeof(LNode));
	if(!s) exit(OVERFLOW);
	s->data=e; //完成插入操作
	s->next=p->next;
	p->next=s;
	return OK;
}
int ListDelet_L(LinkList&L,int i,int&e) { //删除链表L中的第i个元素，并返回给e;
	LinkList p=L;
	LNode* q;
	int j=0;
	while(!p&&j<i-1) {
		p=p->next;    //p指针定位于i-1；
		j++;
	}
	if(!p->next||j>i-1) return ERROR;
	e=p->next->data; //完成删除操作
	q=p->next;
	p->next=p->next->next;
	free(q);
	return OK;
}
int ListTraverse_L(LinkList L,int n) { //链表的遍历
	int i=0;
	if(!L)return ERROR;
	L=L->next;
	while(L) {
		if(L->data==n)return i;
		L=L->next;
		i++;
	}
	return FALSE;
}
int InverseSingleList_L(LinkList &L) {
	if(!L->next||!L->next->next)//如果链表少于2个Node那么链表不需要改变顺序
		return OK;
	LNode *p,*q;
	p=L->next; //第一次因为p是最后一个连接所以把p->next设为空
	q=p->next;
	p->next=NULL;
	p=q;
	while(p) {
		q=p->next; //用q去保留p后面一个Node;
		p->next=L->next;
		L->next=p;
		p=q;
	}
	return OK;
}
int main() {
	int List[N];
	LinkList L;
	int ch,exit='N';
	do {
		system("CLS");
		printf("\t\t********************************************\n");
		printf("\t\t*陈卓 20050045\n");
		printf("\t\t* 1.创建一个顺序表 .........(1) *\n");
		printf("\t\t* 2.在顺序表中查找元表.........(2) *\n");
		printf("\t\t* 3.在顺序表中插入元表.........(3) *\n");
		printf("\t\t* 4.在顺序表中删除元表.........(4) *\n");
		printf("\t\t* 5.退出 .........(5) *\n");
		printf("\t\t********************************************\n");
		printf("\n请选择操作代码：");
		ch=getchar();
		switch(ch) {
			case '1':
				printf("\n请输入十个元素");
				CreatList_L(L);
				for(length=0; length<N; length++) {
					scanf("%d",&List[length]);
					getchar();
					ListInsert_L(L,length+1,List[length]);
				}
				printf("\n创建成功！");
				getchar();
				break;
			case '2':
				scanf("%d",&List[0]);
				if(ListTraverse_L(L,List[0]))printf("该元素存在该年表的第%d个位置",ListTraverse_L(L,List[0]));
				else printf("不存在该元素");
				getchar();
				break;
			case '3':
				scanf("%d%d",&length,&List[0]);
				ListInsert_L(L,length,List[0]);
				system("pause");
				break;
			case '4':
				scanf("%d",&length);
				ListDelet_L(L,length,List[0]);
				system("pause");
				break;
			case '5':
				printf("\n您是否真的要退出程序(Y/N):");
				getchar();
				exit=getchar();
				break;
			default:
				getchar();
				printf("\n无效输入，请重新选择...:");
				getchar();
				break;
		}
	} while(exit!='y'&&exit!='Y');
}

