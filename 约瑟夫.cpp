#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include <malloc.h>
#include <math.h>

#define maxmi 10 //ÿ���������ֵΪ10

#define maxnum 10 //��Ҫ������������Ϊ10

#define maxsx 20 //��ʼ���ҵ�����ֵΪ20
typedef struct LNode {
	int num;///���
	struct LNode *next;
} LNode, *Linklist;
Linklist head,tail;
void Createlist(int n) { ///��������n�����ĵ�ѭ������
	int i;
	Linklist p,q;
	head=(Linklist)malloc(sizeof(LNode));
	q=head;
	q->num=1;
	for(i=2; i<=n; i++) {
		p=(Linklist)malloc(sizeof(LNode));
		p->num=i;
		q->next=p;
		q=p;
	}
	p->next=head;
	tail=p;///βָ��Ҫָ��ͷ���
}
void Outlist(int k) {
	int i;
	Linklist p,q;
	p = head;
	for(i=1; i<k-1; i++) { ///ѭ��k-2��
		p = p->next;///ָ����Ҫ����Ԫ�ص�ǰһ��ָ��
	}
	q = p->next;///ָ����Ҫ����Ԫ�ص�ָ��
	while(q != p) {
		printf("%3d",q->num);
		p->next = q->next;///ɾ��q��ָ���Ԫ��
		for(i=1; i<k; i++) { ///��ΪҪ�����Ѿ�ɾ����Ԫ�أ�������Ҫ��ɾ��һ��
			p = p->next;
		}
		q = p->next;
	}
	printf("%3d\n",q->num);

}
typedef struct LinkList {
	int data;
	int password;
	struct LinkList *next;
} LL;

struct lnode {
	int pos;
	struct lnode *next;
};

/**
 * Description:����ѭ������
 */
struct lnode* create_ring(int n) {
	int i;
	struct lnode *pre, *pcur, *phead;
	phead = (struct lnode *)malloc(sizeof(struct lnode));
	phead->pos = 1;
	phead->next = NULL;
	pre = phead;

	for (i = 2; i <= n; i ++) {
		pcur = (struct lnode *)malloc(sizeof(struct lnode));
		pcur->pos = i;
		pre->next = pcur;
		pre = pcur;
	}
	pre->next = phead;

	return phead;
}

struct node {
	int data;
	struct node *next;
};

/**
 * Description:Լɪ��
 */
void kickoff_ring(struct lnode *head, int p, int n) {
	struct lnode *pre, *pcur;
	pre = pcur = head;
	int i = 1;

	while (pcur != NULL) {
		if (i == p) {
			printf("%d ", pcur->pos);
			pre->next = pcur->next;
			free(pcur);
			pcur = pre->next;
			i = 1;
		}

		pre = pcur;
		pcur = pre->next;

		if (pre == pcur) {
			printf("%d\n", pre->pos);
			free(pcur);
			break;
		}
		i ++;
	}
}

int helper(struct node *head,int k) {
	struct node *temp=head;
	while(head->next!=head) {
		struct node *pre=NULL;
		for(int i=1; i<k; i++) {
			pre=temp;
			temp=temp->next;
		}
		if(temp==head) {
			head=head->next;
		}
		pre->next=temp->next;
		free(temp);
		temp=pre->next;
	}
	return head->data;
}

int findTheWinner(int n, int k) {
	if(k==1)
		return n;
	struct node *head=NULL,*tail=NULL;
	for(int i=1; i<=n; i++) {
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=i;
		if(head==NULL)
			head=tail=newnode;
		else {
			tail->next=newnode;
			tail=newnode;
		}
		tail->next=head;
	}
	return helper(head,k);
}

typedef struct Node {
	int identifier; // �˵ı��
	int code; // �������е�����
	struct Node *next; // ָ����һ����
} Node;

Node *createRing( int );
// ��������ͷ���Ļ�������Ϊ�������������

void deleteNode( Node *, int );
// ɾ����㣬����Ϊ����Ҫɾ�Ľ��ı��

void initializeCodeOfPeople( Node *, int [], int );
// ��ʼ�����е�������,����Ϊ������̬���顢�����С

void reportNumber( Node *, int );
// ����

void display( Node * );
// �������еĽ�㣬����ʹ��

Node *createRing( int numberOfNodes ) {
	Node *head = NULL;
	// ͷָ�룬ָ���һ����㣬Ҳ���ǵ�һ����
	Node *temp = NULL;
	// һֱָ��մ����Ľ��
	Node *tail = NULL;
	// βָ�룬ָ�����һ�����

	head = ( Node * )malloc( sizeof( struct Node ) );
	// ͷ�ڵ�
	if ( !head ) {
		// �ж��Ƿ���䵽�ڴ�
		printf( "�������ʧ�ܣ�" );
		exit( 0 );
	}
	head->identifier = 0;
	// ͷ����������
	head->code = numberOfNodes;
	// ͷ��������Ϊ�����˵ĸ���
	head->next = NULL;
	tail = head;

	for ( int i = 1; i <= numberOfNodes; ++i ) {
		// ����
		temp = ( Node * )malloc( sizeof( struct Node ) );
		// ������
		if ( !temp ) {
			// �ж��Ƿ���䵽�ڴ�
			printf( "�������ʧ�ܣ�" );
			exit( 0 );
		}
		temp->identifier = i;
		temp->next = tail->next;
		// temp�����Զָ��ͷ�ڵ����һ�����
		tail->next = temp;
		// β�巨
		tail = temp;
		// βָ��ָ�����һ�����
	}
	tail->next = head->next;
	// ���һ�����ָ���һ����㣨����ͷ��㣩�����ɻ�

	return head;
}

void initializeCodeOfPeople( Node *head, int array[], int size ) {
	Node *temp;

	temp = head->next;

	for ( int i = 0; i < size; ++i ) {
		temp->code = array[ i ];
		temp = temp->next;
	}
}

void reportNumber( Node *head, int mValue ) {
	int count = 0;
	// ����������
	Node *temp = head->next;
	// tempָ���һ�����
	Node *preTemp = head;

	while ( head->next != NULL ) {
		// �ж��Ƿ������˳���
		do {
			++count;
			preTemp = temp;
			// preTempָ��������
			temp = temp->next;
			// tempָ��Ҫ��������
		} while ( count < mValue );
		// �Ƿ񵽴ﱨ��ֵ
		mValue = preTemp->code;
		// �ó��е��˵����������±���ֵ
		deleteNode( head, preTemp->identifier );
		// ɾ���ﵽ��������ֵ�Ľ��
		count = 0;
	}
}

void deleteNode( Node *head, int number ) {
	Node *temp = head->next;
	// ָ���һ����
	Node *preTemp = head;

	while ( temp->identifier != number ) {
		// �Ƿ��Ƕ�Ӧ����
		preTemp = temp;
		temp = temp->next;
	}
	if ( head->next->identifier == number ) {
		// ɾ����һ�����
		Node *tmp = temp->next;
		while ( tmp->next->identifier != temp->identifier ) { // �ҵ����һ�����
			tmp = tmp->next;
			// tmpָ�����һ�����
		}
		tmp->next = temp->next;
		preTemp->next = temp->next;
	} else
		preTemp->next = temp->next;
	printf( "%d ", temp->identifier );
	// ������
	if ( temp->next == temp )
		head->next =  NULL;
	free( temp );
}

void display( Node *head ) {
	Node *temp;

	temp = head->next;

	if ( head->next == NULL ) {
		printf( "0" );
		return;
	}
	do {
		printf( "%d ", temp->identifier );
		temp = temp->next;
	} while ( temp->identifier != head->next->identifier ); // temp�Ƿ�ָ���һ�����
}

LL * initLink(int n) {
	LL * head=(LL*)malloc(sizeof(LL));
	head->data=1;
	head->next=NULL;
	LL * cyclic=head;
	for (int i=2; i<=n; i++) {
		LL * body=(LL*)malloc(sizeof(LL));
		body->data=i;
		body->next=NULL;
		cyclic->next=body;
		cyclic=cyclic->next;
	}
	cyclic->next=head;
	//��β����
	return head;
}

void findAndKillK(LL * head,int k,int m) {
	LL * tail=head;
	//�ҵ������һ��������һ����㣬Ϊɾ��������׼��
	while (tail->next!=head) {
		tail=tail->next;
	}
	LL * p=head;
	//�ҵ����Ϊk����
	while (p->data!=k) {
		tail=p;
		p=p->next;
	}
	//�ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ������ˣ�
	while (p->next!=p) {
		//�ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1de�˵�λ��tail��������ɾ��������
		for (int i=1; i<m; i++) {
			tail=p;
			p=p->next;
		}
		tail->next=p->next;
		//�������Ͻ�p���ժ����
		printf("�����˵ı��Ϊ:%d\n",p->data);
		free(p);
		p=tail->next;
		//����ʹ��pָ��ָ����б�ŵ���һ����ţ���Ϸ����
	}
	printf("�����˵ı��Ϊ:%d\n",p->data);
	free(p);
}

int cycle1(int n, int m) {
// ʹ������ʵ�� 1 ����� 0 ������̭��������Ҳ���ԣ�
	int a[n];
	for(int i = 0; i < n; ++i) {
		a[i] = 1;
	}
	int i = 0, j = 0, count = 0;
	while(count < n-1) {
		i %= n;
		if(a[i] == 1) {
			if(j == m-1) {
				j = 0;
				a[i] = 0;
				++count;
			} else ++j;
			++i;
		} else while(a[(++i)%n] == 0) {}
		// ������̭�ߣ���Щ�˲����뱨��
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] == 1) {
			return i;
		}
	}
}

int cycle3(int n, int m) {
	// �����Ż�����ģ�ⷨ�Ĵ��룬����ֵ ���� �±��ʾ���
	// ʹ������ֵ��������һ���˵��±�
	int a[n];
	for(int i = 0; i < n; ++i) {
		a[i] = i;
	}
	int i = 0, j = 0, count = 0;
	while(count < n-1) {
		i %= n;
		if(a[i] == i) {
			if(j == m-1) {
				j = 0;
				a[i] = a[(i+1)%n];
				++count;
			} else ++j;
			++i;
		} else i = a[i];
		// �Ż��ĵ�
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] == i) {
			return i;
		}
	}
}

int cycle4(int n, int m) {
// �����Ż�����ģ�ⷨ�Ĵ���
	int a[n];
	a[n-1] = 0;
	for(int i = 0; i < n-1; ++i) {
		a[i] = i+1;
	}
	int c = 0, p = n-1, j = 0, count = 0;
	while(count < n-1) {
		if(j == m-1) {
			j = 0;
			a[p] = a[c];
			// ɾ����ǰ����ߣ�p ��ʱָ��ľ�����һ����ߣ����� p ָ�벻��Ҫ�ƶ���
			++count;
		} else {
			++j;
			p = c;
		}
		c = a[c];
	}
	return c;
}

int cycle5(int n, int m) {
// ʹ�õ�����
	int a[n];
	a[n-1] = 0;
	for(int i = 0; i < n-1; ++i) {
		a[i] = i+1;
	}
	int c = n-1, j = 0, count = 0;
	while(count < n-1) {
		if(j == m-1) {
			j = 0;
			a[c] = a[a[c]];
			// ɾ����ǰ�����
			++count;
		} else {
			++j;
			c = a[c];
		}
	}
	return c;
}

int cycle2(int n, int m) {
// �Ż�����ģ�ⷨ�Ĵ��� 0 ����� 1 ������̭��������Ҳ���ԣ�
	int a[n] = {0};
	int i = 0, j = 0, count = 0;
	while(count < n-1) {
		if(a[i] == 0 && j == m-1) {
			j = 0;
			a[i] = 1;
			++count;
		}
		j += 1-a[i];
		// ���� a[i] ��ֵ���� j ���м���
		i = (i+1)%n;
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0) return i;
	}
}

int cycle0(int n, int m) {
// ʹ������ʵ��
	LL* head = (LL*)malloc(sizeof(LL));
	head->data = 0;
	head->next = NULL;
	LL* tail = head;
	// ��ָ������β
	for(int i = 1; i < n; ++i) {
		tail->next = (LL*)malloc(sizeof(LL));
		tail = tail->next;
		tail->data = i;
		tail->next = NULL;
	}
	tail->next = head;
	// ���ɻ�
	LL* p = head;
	int j = 0;
	// ������
	while(p->next != p) {
		// ��� p ����һ�����ָ���Լ���˵������ֻʣһ�����
		if(j == m-2) {
			// ÿ�α��� m-2 ɾ����ǰ p ָ�������һ�����
			LL* q = p->next;
			p->next = q->next;
			free(q);
			// �ͷ��ڴ�
			p = p->next;
			j = 0;
		} else {
			p = p->next;
			++j;
		}
	}
	return p->data;
}

void joseph(int count, int doom);

void joseph1(int count1, int doom1);

void joseph2(int count2, int doom2);

int josef(int a[],int n,int m) {
	int i,j,k=0;
	for(i=0; i<n; i++) {
		j=1;
		while(j<m) {
			while(a[k]==0)
				k=(k+1)%n;
			j++;
			k=(k+1)%n;
		}
		while(a[k]==0)
			k=(k+1)%n;
		printf("%d ",a[k]);
		a[k]=0;
	}
	return 0;
}

void joseph2(int count2, int doom2) {
	int alive2 = count2;
	// �Ҵ�����
	int number2 = 0;
	// ��������
	int curIndex2 = 0;
	// ��ǰ���±�
	int preIndex2 = count2 - 1;
	// ǰһ�����±�
	int *circle2 = NULL;
	int index2;

	circle2 = (int *) malloc (sizeof(int) * count2);
	//��circle������г�ʼ��
	for(index2 = 0; index2 < count2; index2++) {
		circle2[index2] = (index2 + 1) % count2;
	}

	while(alive2 > 0) {
		number2++;
		if(number2 == doom2) {
			alive2 == 1 ? printf("%d", curIndex2+1) : printf("%d,", curIndex2+1);
			alive2--;
			number2 = 0;
			circle2[preIndex2] = circle2[curIndex2];
			//��Ȧ����
		} else {
			preIndex2 = curIndex2;
			//������һ����
		}
		curIndex2 = circle2[curIndex2];
	}

	free(circle2);
}

void joseph1(int count1, int doom1) {
	int alive1 = count1;
	// �Ҵ�����
	int curIndex1 = 0;
	// ��ǰ���±�
	int preIndex1 = count1 - 1;
	// ǰһ�����±�
	int *circle1 = NULL;
	int index1;

	circle1 = (int *) malloc(sizeof(int) * count1);
	for(index1 = 0; index1 < count1; index1++) {
		circle1[index1] = (index1 + 1) % count1;
		// ��ʼ������
	}

	while(alive1 > 0) {
		// ֻҪ�����Ҵ��ߣ��ͼ�����ɱ��
		int num1 = doom1 % alive1 - 1;
		// ֱ�Ӽ������Ҫ�ƶ���������
		// ֱ�Ӷ�λ��Ҫ��Ȧ����
		for(index1 = 0; index1 < (num1 == -1 ? alive1 - 1 : num1); index1++) {
			preIndex1 = curIndex1;
			curIndex1 = circle1[curIndex1];
		}
		// ���˳�Ȧ��
		printf("%d\n", curIndex1+1);
		alive1--;
		circle1[preIndex1] = circle1[curIndex1];
		// �����ĳ�Ȧ������
		curIndex1 = circle1[curIndex1];
		// ����������һ����
	}
	// ����㷨��normalJoseph.cЧ�����30%��

	free(circle1);
}

void joseph(int count, int doom) {
	int alive = count;
	//�Ҵ�����
	int number = 0;
	//��������number==doomʱ����̭�����
	int index = 0;
	//�±꣬Ϊ������-1
	int *circle = NULL;
	//����������Ϊѭ�����飬�洢ÿ����

	//��calloc()��������õ��Ŀռ䣬�Զ���ʼ��ÿ��Ԫ��Ϊ0
	//���ԣ�0��ʾ���������Լɪ���ڣ�1��ʾ����˳�Ȧ��������̭��
	circle = (int *) calloc(sizeof(int), count);

	//ֻҪ�Ҵ���������0����һֱ����ѭ��
	while(alive > 0) {
		number += 1- circle[index];
		//ÿ�ֵ�һ���˱�����������"0"����"1"�����м���
		if(number == doom) {
			//��number==doomʱ����Ҫ��̭��ǰ�����
			/*
				��̭һ������Ҫ���Ĳ�������
					1���������˵�λ��
					2��������˵�״̬����Ȧ��"0"��Ϊ����Ȧ��"1"
					3���Ҵ�����alive--
					4�� ������number����
			*/
			alive == 1 ? printf("%d", index+1) : printf("%d,", index+1);
			circle[index] = 1;
			alive--;
			number = 0;
		}
		//��������countȡ�࣬�����ʹindex��0~count-1֮�� һֱѭ�����ﵽѭ�������Ŀ��
		index = (index +1) % count;
	}

	free(circle);
	//������һ��Ҫ�ͷ�circle������Ŀռ�
}

//��������
void mueu();

LL *CreatList();

void InitList(LL *,int );

int GetPassword();

int GetPersonNumber();

int GetSX();

void GetOutput(LL *,int , int , int * );

void print(int *,int );

void menu() {
	//�˵�����
	printf("��������ѡ��˵���������\n");
	printf("|			|\n");
	printf("|��ѡ�����¹��ܣ�	|\n");
	printf("|			|\n");
	printf("|��1���˽�Լɪ������	|\n");
	printf("|			|\n");
	printf("|��2��Լɪ�򻷴�1��ʼ	|\n");
	printf("|			|\n");
	printf("|��3��Լɪ�����⿪ʼ	|\n");
	printf("|			|\n");
	printf("|��4���˳�����		|\n");
	printf("|			|\n");
	printf("������������������������\n");
	printf("�����빦�ܵı�ţ�1-4����");
}

LL *CreatList() {
	//������ĳ�ʼ��
	LL *l;
	l = (LL *)malloc(sizeof(LL));
	if(l == NULL) {
		printf("�ڴ����ʧ�ܣ�");
		exit(1);
		//���������е����˳�����
	}
	return l;
}

void InitList(LL *l,int personNumber) {
	//����ѭ��������
	LL *p,*q;
	int i;
	p = l;
	p->data = 1;
	p->password = GetPassword();
	for(i = 2; i <= personNumber; i++) {
		q = (LL *)malloc(sizeof(LL));
		if(q==NULL) {
			printf("�ڴ�ռ����ʧ�ܣ�");
			exit(1);
		}
		q->password = GetPassword();
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = l;
}

int GetPersonNumber() {
	//���봦�������
	int personNumber;
	printf("������������");
	scanf("%d",&personNumber);
	while(personNumber > maxnum || personNumber < 0) {
		printf("\n�Բ����������������Ч����������0��%d��������",maxnum);
		scanf("%d",&personNumber);
	}
	printf("������Լɪ�򻷵ĳ���˳������Ϊ%d�ˡ�\n\n",personNumber);
	return personNumber;
}

int GetPassword() {
	//Ϊÿ���˸�����
	int password;
	static int count = 1;
	printf("�������%d�˵����룺",count);
	scanf("%d",&password);
	while(password > maxmi || password < 0) {
		printf("�Բ����������������Ч����������0��%d��������",maxmi);
		scanf("%d",&password);
	}
	count++;
	return password;
}

int GetSX() {
	//ȷ����ʼ������
	int sx;
	printf("�����뱨��������ֵ��");
	scanf("%d",&sx);
	while(sx > maxsx || sx < 0) {
		printf("\n�Բ����������������Ч����������0��%d��������",maxsx);
		scanf("%d",&sx);
	}
	printf("���յı�������ֵΪ%d��\n\n",sx);
	return sx;
}

void GetOutput(LL *l,int personNumber,int sx,int array[maxnum]) {
	//�õ�����˳��
	LL *p,*q;
	int count = 1,i = 0;
	p = l;
	while(personNumber) {
		while(count != sx) {
			q = p;
			p = p->next;
			count++;
		}
		array[i++] = p->data;
		sx = p->password;
		q->next = p->next;
		free(p);
		p = q->next;
		count = 1;
		personNumber--;
	}
}

void print(int array[],int personNumber) {
	//������ս��
	int i;
	printf("\n��ÿ�˵ı��(1~%d)���γ��е�˳��Ϊ��",personNumber);
	for(i = 0; i < personNumber; i++) {
		printf("%-4d",array[i]);
	}
	printf("\n");
}

int main() {
	char(ch);
	LL *l;
	int personNumber,SX;
	int array[maxnum];
	system("title Լɪ������");
flag1:
	menu();
	ch=getchar();
	system("cls");
	switch (ch) {
		case '1':
			printf("  �����1,2,����,n��n���˰���˳ʱ�뷽��Χ��һȦ,\n");
			printf("ÿ����ֻ��һ������(������)��\n");
			printf("һ��ʼ��ѡһ����������Ϊ��������ֵm,");
			printf("�ӵ�һ���Կ�ʼ˳ʱ�뷽����1��ʼ˳����,\n");
			printf("����mʱֹͣ��������m���˳���,������������Ϊ�µ�mֵ,");
			printf("������˳ʱ�뷽�����һ����\n");
			printf("��ʼ���´�1����,�����ȥ,ֱ��������ȫ������Ϊֹ��\n\n");
			printf("	�밴���������");
			getch();
			system("cls");
			break;

		case '2':
			printf("��������Լɪ�����⡪������\n");
			personNumber = GetPersonNumber();
			SX = GetSX();
			l = CreatList();
			InitList(l,personNumber);
			GetOutput(l,personNumber,SX,array);
			print(array,personNumber);
			printf("�밴���������");
			getch();
			system("cls");
			break;
		case '3':
			int k,n;
			printf("-----------Լɪ������---------\n");
			printf("\n�������������ʹӵڼ����˿�ʼ����n,k��\n");
			scanf("%d%d",&n,&k);
			Createlist(n);
			printf("\n���ӵĴ���\n");
			Outlist(k);
		case '4':
			printf("ллʹ�ã��ټ���\n");
			return 0;
	}

	goto flag1;
	return 0;

}
