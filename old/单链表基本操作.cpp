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
//�����ʼ��
void InitList(Lnode *p) {
	p=(LinkList)malloc(sizeof(Lnode));
}
//��������
Lnode *CreatList(void) {
	{
		LinkList p,head,q;
		int x,n;
		head=q=(LinkList)malloc(sizeof(Lnode)) ;
		printf( "�������ݸ���Ϊ�� \n");
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
//�������
void PrintList(LinkList L) {
	LinkList p;
	p = L->next;
	printf("�������\n");
	while(p) {
		printf("%d " ,p->data);
		p=p->next;
	}
	printf("\n");
}
//����Ԫ��
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
//ɾ��
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
	printf( "ɾ��Ԫ��Ϊ:%d\n",e);
	free(s);
	PrintList(L);
	return OK;
}
//����
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
			printf("����λ%d",i);
			break;
		} else {
			j++ ;
			p =p->next;
		}
	}
	if(flag == 1) {
		printf("�޴�Ԫ��\n");
		return OK;
	}
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
	LinkList L;
	int i,e,x;
	printf("��ѡ�����²���\n");
	printf("1.�����ʼ��\n");
	printf("2.�ڱ��в���һ����Ԫ��\n");
	printf("3.ɾ������Ԫ��\n");
	printf("4.����Ԫ��λ��\n");
	printf("5.����б�\n");
	printf("6.�ϲ�����\n");
	printf("��ѡ��:");
	scanf("%d",&x);
	switch(x) {
		case 1:
			InitList(L);
			break;
		case 2:
			L=CreatList();
			printf("����λ�ã�����Ԫ�أ�");
			scanf("%d%d",&i,&e);
			ListInsert(L,i,e);
			break;
		case 3:
			L =CreatList();
			printf( "ɾ��λ�ã�");
			scanf("%d",&i);
			ListDelete(L,i, e);
			break;
		case 4:
			L = CreatList();
			printf("����Ԫ��:");
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
			printf( "������1~5!����") ;
	}
}

