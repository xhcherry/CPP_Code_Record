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
		printf("�����%d���˵����룺",i);
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
	printf("��ɴ�����\n");

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
		printf("��%d���˳��У�����:%d\n,j,i");
		m_pwd=ppHead->pwd;
		free(ppHead);
		ppHead=p->next;
	}
	i=ppHead->pwd;
	j=ppHead->num;
	printf("���һ�����е���%d�ţ�������:%d\n,j,i");
	free(ppHead);
}
void instruction() {
	printf("************************************************************************************\n");
	printf("Լɪ��:\n");
	printf("���Ϊ1��2��3��4��...��n��n���˰�˳ʱ�뷽��Χ��һȦ��û�˳���һ������\n");
	printf( "������һ��ʼ��ѡһ����������Ϊ����������ֵm,�ӵ�һ���˿�ʼ\n");
	printf("��˳ʱ�뷽����1��ʼ˳����������mʱֹͣ.��m���˳���,�����������n");
	printf("m ��Ϊ�µ�m ֵ,������˳ʱ�뷽���ϵ���һ�˿�ʼ���´�1�����������ȥ,��n");
	printf("ֱ��������ȫ������Ϊֹ��̴�ӡ����˳��\n");
	printf("****************************************************************\n");
	return 0;
}
void menu() {
	printf("******************Լɪ��******************\n");
	printf("                                                                   \n");
	printf("                         [1]Լɪ������Ĳ���        \n");
	printf("                         [2]��Ҫ�����Լɪ��        \n");
	printf("                         [0]�˳�                               \n");
	printf("******************��ӭʹ��******************\n");
}
int main() {
	int n,m, x;
	LNode *ppHead=NULL;
	menu();
	for(;;) {
		printf("\n ѡ��Ҫִ�еĲ���:");
		scanf("%d",&x);
		system("cls");
		switch(x) {
			case 1:
				printf("������������������������������������������������������������*��**�������������� ������������*��\n");
				printf(" Լɪ��\n");
				printf(" ���Ϊ1,2,3,4��,n��n���˰�˳ʱ�뷽��Χ��һȦ��ÿ�˳���һ������\n");
				printf( "������һ��ʼ��ѡһ����������Ϊ����������ֵm,�ӵ�һ���˿�ʼ\n");
				printf("��˳ʱ�뷽����1��ʼ˳����������mʱֹͣ.��m���˳���,�����������n");
				printf("m ��Ϊ�µ�m ֵ,������˳ʱ�뷽���ϵ���һ�˿�ʼ���´�1�����������ȥ,��n");
				printf("ֱ��������ȫ������Ϊֹ��̴�ӡ����˳��\n");
				printf("****************************************************************\n");
				main();
				break;
			case 2:
				printf ("\n����������n:");
				scanf("%d",&n);
				printf("���뿪ʼ������ m: ");
				scanf("%d",&m);
				createList(&ppHead,n);
				printf("\n");
				priatf("����˳��\n");
				jose(ppHead,m);
				printf("\n Լɪ����Ϸ����!");
				main();
				break;
			case 0:
				exit(0);
			default:
				system("cls");
				printf("\n ��ѡ��Ĳ�������������ѡ��...\n \n\n");
				main();
		}
	}
	return 0;
}

