#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode {
	ElemType data;
	struct Lnode *next;
} Lnode, *LinkList;
//创建链表
Lnode *CreatList(void) {
	LinkList p,q,head;
	int n,x;
	head = q = (LinkList)malloc(sizeof(Lnode));
	printf("输入数据个数为：\n");
	scanf( "%d",&n);
	for(int i = 0; i<n; i++) {
		p =(LinkList)malloc(sizeof(Lnode));
		scanf("%d",&x);
		p->data= x;
		q->next=p;
		q=p;
	}
	p->next =NULL;
	return head;
}
//输出链表
void PrintList(LinkList L) {
	LinkList p;
	p =L->next;
	while(p) {
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
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
	LinkList La,Lb,Lc;
	La= CreatList();
	Lb = CreatList();
	MergeList(La,Lb,Lc);
}
