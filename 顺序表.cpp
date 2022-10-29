#include<stdio.h>
#include<stdlib.h>
#define N 10 //˳�����������
int length=0; //˳���ĵ�ǰԪ�ظ���
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100//���Ա�洢�Ŀռ��ʼ��������
#define LISTINCREAMENT 10 //���Ա�洢�ռ�ķ�������
typedef struct LNode { //���Ե�����洢�ṹ
	int data;
	struct LNode *next;
} LNode,*LinkList;
int CreatList_L(LinkList&L) { //����һ����������
	L=(LinkList)malloc(sizeof(LNode));//����һ���ռ��������Ϊͷ���
	if(!L) exit(OVERFLOW);
	L->next=NULL;
	return OK;
}
int DestroyList_L(LinkList &L) { //��������
	if(L) free(L);
	return OK;
}
int ListInsert_L(LinkList&L,int i,int e) { //������ĵ�i��Ԫ��ǰ����һ��Ԫ��e
	LinkList p=L;//pָ�붨λ��i-1
	LNode *s;
	int j=0;
	while(p&&j<i-1) {
		p=p->next;    //��λ
		j++;
	}
	if(!p||j>i-1) return ERROR;//���i<1���������Ԫ�ظ���+1
	s=(LNode*)malloc(sizeof(LNode));
	if(!s) exit(OVERFLOW);
	s->data=e; //��ɲ������
	s->next=p->next;
	p->next=s;
	return OK;
}
int ListDelet_L(LinkList&L,int i,int&e) { //ɾ������L�еĵ�i��Ԫ�أ������ظ�e;
	LinkList p=L;
	LNode* q;
	int j=0;
	while(!p&&j<i-1) {
		p=p->next;    //pָ�붨λ��i-1��
		j++;
	}
	if(!p->next||j>i-1) return ERROR;
	e=p->next->data; //���ɾ������
	q=p->next;
	p->next=p->next->next;
	free(q);
	return OK;
}
int ListTraverse_L(LinkList L,int n) { //����ı���
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
	if(!L->next||!L->next->next)//�����������2��Node��ô������Ҫ�ı�˳��
		return OK;
	LNode *p,*q;
	p=L->next; //��һ����Ϊp�����һ���������԰�p->next��Ϊ��
	q=p->next;
	p->next=NULL;
	p=q;
	while(p) {
		q=p->next; //��qȥ����p����һ��Node;
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
		printf("\t\t*��׿ 20050045\n");
		printf("\t\t* 1.����һ��˳��� .........(1) *\n");
		printf("\t\t* 2.��˳����в���Ԫ��.........(2) *\n");
		printf("\t\t* 3.��˳����в���Ԫ��.........(3) *\n");
		printf("\t\t* 4.��˳�����ɾ��Ԫ��.........(4) *\n");
		printf("\t\t* 5.�˳� .........(5) *\n");
		printf("\t\t********************************************\n");
		printf("\n��ѡ��������룺");
		ch=getchar();
		switch(ch) {
			case '1':
				printf("\n������ʮ��Ԫ��");
				CreatList_L(L);
				for(length=0; length<N; length++) {
					scanf("%d",&List[length]);
					getchar();
					ListInsert_L(L,length+1,List[length]);
				}
				printf("\n�����ɹ���");
				getchar();
				break;
			case '2':
				scanf("%d",&List[0]);
				if(ListTraverse_L(L,List[0]))printf("��Ԫ�ش��ڸ����ĵ�%d��λ��",ListTraverse_L(L,List[0]));
				else printf("�����ڸ�Ԫ��");
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
				printf("\n���Ƿ����Ҫ�˳�����(Y/N):");
				getchar();
				exit=getchar();
				break;
			default:
				getchar();
				printf("\n��Ч���룬������ѡ��...:");
				getchar();
				break;
		}
	} while(exit!='y'&&exit!='Y');
}

