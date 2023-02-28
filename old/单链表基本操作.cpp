#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef struct Lnode {
	ElemType data;
	struct Lnode *next;
}
Lnode, *LinkList;
//链表初始化
void InitList(Lnode *p) {
	p=(LinkList)malloc(sizeof(Lnode));
}
//创建链表
Lnode *CreatList(void) {
	{
		LinkList p,head,q;
		int x,n;
		head=q=(LinkList)malloc(sizeof(Lnode)) ;
		printf( "输入数据个数为： \n");
		scanf("%d",&n);
		for(int i =0; i<n; i++) {
			p =(LinkList)malloc(sizeof(Lnode));
			scanf("%d",&x);
			p->data=x;
			q->next =p;
			q =p;
		}
		p -> next =NULL;
		return head;
	}
}
//输出链表
void PrintList(LinkList L) {
	LinkList p;
	p = L->next;
	printf("输出数据\n");
	while(p) {
		printf("%d " ,p->data);
		p=p->next;
	}
	printf("\n");
}
//插入元素
bool ListInsert(LinkList L,int i,ElemType e) {
	LinkList p,s;
	int j = 0;
	p = L;
	while(j<i-1) {
		p = p->next;
		j++;
		if(!p||j>i-1)
			return ERROR;
	}
	s = (LinkList)malloc(sizeof(Lnode));
	s->data =e;
	s->next=p->next;
	p->next=s;
	PrintList(L);
	return OK;
}
//删除
bool ListDelete(LinkList L,int i,ElemType e) {
	LinkList p,s;
	int j = 0;
	p=L;
	while(j<i-1) {
		p=p->next;
		j++;
		if(!p||j>i-1)
			return ERROR;
	}
	s=p->next;
	p->next=s->next;
	e=s->data;
	printf( "删除元素为:%d\n",e);
	free(s);
	PrintList(L);
	return OK;
}
//查找
bool GetElem(LinkList L,int i,ElemType e) {
	LinkList p;
	int j =1,flag =1;
	p=L->next;
	if(!p)return ERROR;
	while(p) {
		if(p->data==e) {
			flag=0;
			i=j;
			j++;
			printf("查找位%d",i);
			break;
		} else {
			j++ ;
			p =p->next;
		}
	}
	if(flag == 1) {
		printf("无此元素\n");
		return OK;
	}
}
//合并链表
void MergeList(LinkList La,LinkList Lb,LinkList Lc) {
	LinkList pa,pb,pc;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb) {
		if(pa->data<=pb->data) {
			pc->next=pa ;
			pc=pa;
			pa=pa->next;
		} else {
			pc->next =pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc ->next =pa?pa:pb;
	free(Lb);
	printf("合并链表为：\n");
	PrintList(Lc);
}
int main() {
	LinkList L;
	int i,e,x;
	printf("请选择以下操作\n");
	printf("1.将表初始化\n");
	printf("2.在表中插入一个新元素\n");
	printf("3.删除表中元素\n");
	printf("4.查找元素位置\n");
	printf("5.输出列表：\n");
	printf("6.合并链表：\n");
	printf("请选择:");
	scanf("%d",&x);
	switch(x) {
		case 1:
			InitList(L);
			break;
		case 2:
			L=CreatList();
			printf("插入位置，插入元素：");
			scanf("%d%d",&i,&e);
			ListInsert(L,i,e);
			break;
		case 3:
			L =CreatList();
			printf( "删除位置：");
			scanf("%d",&i);
			ListDelete(L,i, e);
			break;
		case 4:
			L = CreatList();
			printf("查找元素:");
			scanf("%d",&e);
			GetElem(L,i,e);
			break;
		case 5:
			L= CreatList();
			PrintList(L);
			break;
		case 6:
			LinkList La,Lb,Lc;
			La= CreatList();
			Lb = CreatList();
			MergeList(La,Lb,Lc);
			break;
		default:
			printf( "请输入1~5!！！") ;
	}
}

