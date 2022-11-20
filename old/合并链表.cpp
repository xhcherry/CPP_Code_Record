#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode {
	ElemType data;
	struct Lnode *next;
} Lnode, *LinkList;
//��������
Lnode *CreatList(void) {
	LinkList p,q,head;
	int n,x;
	head = q = (LinkList)malloc(sizeof(Lnode));
	printf("�������ݸ���Ϊ��\n");
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
//�������
void PrintList(LinkList L) {
	LinkList p;
	p =L->next;
	while(p) {
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
//�ϲ�����
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
	printf("�ϲ�����Ϊ��\n");
	PrintList(Lc);
}
int main() {
	LinkList La,Lb,Lc;
	La= CreatList();
	Lb = CreatList();
	MergeList(La,Lb,Lc);
}
