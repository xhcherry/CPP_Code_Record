#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include <malloc.h>
#include <math.h>

#define maxmi 10 //每人最大密码值为10

#define maxnum 10 //需要处理的最多人数为10

#define maxsx 20 //初始查找的上限值为20
typedef struct LNode {
	int num;///编号
	struct LNode *next;
} LNode, *Linklist;
Linklist head,tail;
void Createlist(int n) { ///创建含有n个结点的单循环链表
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
	tail=p;///尾指针要指向头结点
}
void Outlist(int k) {
	int i;
	Linklist p,q;
	p = head;
	for(i=1; i<k-1; i++) { ///循环k-2次
		p = p->next;///指向需要操作元素的前一个指针
	}
	q = p->next;///指向需要操作元素的指针
	while(q != p) {
		printf("%3d",q->num);
		p->next = q->next;///删除q所指向的元素
		for(i=1; i<k; i++) { ///因为要经过已经删除的元素，所以需要多删除一次
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
 * Description:构建循环链表
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
 * Description:约瑟夫环
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
	int identifier; // 人的编号
	int code; // 人所持有的密码
	struct Node *next; // 指向下一个人
} Node;

Node *createRing( int );
// 创建带有头结点的环，参数为人数（结点数）

void deleteNode( Node *, int );
// 删除结点，参数为环、要删的结点的编号

void initializeCodeOfPeople( Node *, int [], int );
// 初始化环中的密码域,参数为环、动态数组、数组大小

void reportNumber( Node *, int );
// 报数

void display( Node * );
// 遍历环中的结点，测试使用

Node *createRing( int numberOfNodes ) {
	Node *head = NULL;
	// 头指针，指向第一个结点，也就是第一个人
	Node *temp = NULL;
	// 一直指向刚创建的结点
	Node *tail = NULL;
	// 尾指针，指向最后一个结点

	head = ( Node * )malloc( sizeof( struct Node ) );
	// 头节点
	if ( !head ) {
		// 判断是否分配到内存
		printf( "结点申请失败！" );
		exit( 0 );
	}
	head->identifier = 0;
	// 头结点的特殊标记
	head->code = numberOfNodes;
	// 头结点的密码为所有人的个数
	head->next = NULL;
	tail = head;

	for ( int i = 1; i <= numberOfNodes; ++i ) {
		// 建环
		temp = ( Node * )malloc( sizeof( struct Node ) );
		// 申请结点
		if ( !temp ) {
			// 判断是否分配到内存
			printf( "结点申请失败！" );
			exit( 0 );
		}
		temp->identifier = i;
		temp->next = tail->next;
		// temp结点永远指向头节点的下一个结点
		tail->next = temp;
		// 尾插法
		tail = temp;
		// 尾指针指向最后一个结点
	}
	tail->next = head->next;
	// 最后一个结点指向第一个结点（不是头结点），构成环

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
	// 报数计数器
	Node *temp = head->next;
	// temp指向第一个结点
	Node *preTemp = head;

	while ( head->next != NULL ) {
		// 判断是否所有人出列
		do {
			++count;
			preTemp = temp;
			// preTemp指向报数的人
			temp = temp->next;
			// temp指向将要报数的人
		} while ( count < mValue );
		// 是否到达报数值
		mValue = preTemp->code;
		// 用出列的人的密码来更新报数值
		deleteNode( head, preTemp->identifier );
		// 删除达到报数上限值的结点
		count = 0;
	}
}

void deleteNode( Node *head, int number ) {
	Node *temp = head->next;
	// 指向第一个人
	Node *preTemp = head;

	while ( temp->identifier != number ) {
		// 是否是对应的人
		preTemp = temp;
		temp = temp->next;
	}
	if ( head->next->identifier == number ) {
		// 删除第一个结点
		Node *tmp = temp->next;
		while ( tmp->next->identifier != temp->identifier ) { // 找到最后一个结点
			tmp = tmp->next;
			// tmp指向最后一个结点
		}
		tmp->next = temp->next;
		preTemp->next = temp->next;
	} else
		preTemp->next = temp->next;
	printf( "%d ", temp->identifier );
	// 输出编号
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
	} while ( temp->identifier != head->next->identifier ); // temp是否指向第一个结点
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
	//首尾相连
	return head;
}

void findAndKillK(LL * head,int k,int m) {
	LL * tail=head;
	//找到链表第一个结点的上一个结点，为删除操作做准备
	while (tail->next!=head) {
		tail=tail->next;
	}
	LL * p=head;
	//找到编号为k的人
	while (p->data!=k) {
		tail=p;
		p=p->next;
	}
	//从编号为k的人开始，只有符合p->next==p时，说明链表中除了p结点，所有编号都出列了，
	while (p->next!=p) {
		//找到从p报数1开始，报m的人，并且还要知道数m-1de人的位置tail，方便做删除操作。
		for (int i=1; i<m; i++) {
			tail=p;
			p=p->next;
		}
		tail->next=p->next;
		//从链表上将p结点摘下来
		printf("出列人的编号为:%d\n",p->data);
		free(p);
		p=tail->next;
		//继续使用p指针指向出列编号的下一个编号，游戏继续
	}
	printf("出列人的编号为:%d\n",p->data);
	free(p);
}

int cycle1(int n, int m) {
// 使用数组实现 1 代表活 0 代表淘汰（反过来也可以）
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
		// 跳过淘汰者，这些人不计入报数
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] == 1) {
			return i;
		}
	}
}

int cycle3(int n, int m) {
	// 继续优化数组模拟法的代码，数组值 等于 下标表示存活
	// 使用数组值引导到下一个人的下标
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
		// 优化的点
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] == i) {
			return i;
		}
	}
}

int cycle4(int n, int m) {
// 继续优化数组模拟法的代码
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
			// 删除当前存活者，p 此时指向的就是下一存活者，所以 p 指针不需要移动。
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
// 使用单索引
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
			// 删除当前存活者
			++count;
		} else {
			++j;
			c = a[c];
		}
	}
	return c;
}

int cycle2(int n, int m) {
// 优化数组模拟法的代码 0 代表活 1 代表淘汰（反过来也可以）
	int a[n] = {0};
	int i = 0, j = 0, count = 0;
	while(count < n-1) {
		if(a[i] == 0 && j == m-1) {
			j = 0;
			a[i] = 1;
			++count;
		}
		j += 1-a[i];
		// 利用 a[i] 的值来对 j 进行计数
		i = (i+1)%n;
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0) return i;
	}
}

int cycle0(int n, int m) {
// 使用链表实现
	LL* head = (LL*)malloc(sizeof(LL));
	head->data = 0;
	head->next = NULL;
	LL* tail = head;
	// 恒指向链表尾
	for(int i = 1; i < n; ++i) {
		tail->next = (LL*)malloc(sizeof(LL));
		tail = tail->next;
		tail->data = i;
		tail->next = NULL;
	}
	tail->next = head;
	// 链成环
	LL* p = head;
	int j = 0;
	// 报数器
	while(p->next != p) {
		// 如果 p 的下一个结点指向自己，说明环中只剩一个结点
		if(j == m-2) {
			// 每次报到 m-2 删除当前 p 指向结点的下一个结点
			LL* q = p->next;
			p->next = q->next;
			free(q);
			// 释放内存
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
	// 幸存人数
	int number2 = 0;
	// 报数的数
	int curIndex2 = 0;
	// 当前人下标
	int preIndex2 = count2 - 1;
	// 前一个人下标
	int *circle2 = NULL;
	int index2;

	circle2 = (int *) malloc (sizeof(int) * count2);
	//对circle数组进行初始化
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
			//出圈操作
		} else {
			preIndex2 = curIndex2;
			//处理下一个人
		}
		curIndex2 = circle2[curIndex2];
	}

	free(circle2);
}

void joseph1(int count1, int doom1) {
	int alive1 = count1;
	// 幸存人数
	int curIndex1 = 0;
	// 当前人下标
	int preIndex1 = count1 - 1;
	// 前一个人下标
	int *circle1 = NULL;
	int index1;

	circle1 = (int *) malloc(sizeof(int) * count1);
	for(index1 = 0; index1 < count1; index1++) {
		circle1[index1] = (index1 + 1) % count1;
		// 初始化链表
	}

	while(alive1 > 0) {
		// 只要还有幸存者，就继续“杀”
		int num1 = doom1 % alive1 - 1;
		// 直接计算出需要移动的人数，
		// 直接定位到要出圈的人
		for(index1 = 0; index1 < (num1 == -1 ? alive1 - 1 : num1); index1++) {
			preIndex1 = curIndex1;
			curIndex1 = circle1[curIndex1];
		}
		// 该人出圈！
		printf("%d\n", curIndex1+1);
		alive1--;
		circle1[preIndex1] = circle1[curIndex1];
		// 真正的出圈操作！
		curIndex1 = circle1[curIndex1];
		// 继续处理下一个人
	}
	// 这个算法比normalJoseph.c效率提高30%！

	free(circle1);
}

void joseph(int count, int doom) {
	int alive = count;
	//幸存人数
	int number = 0;
	//计数，当number==doom时，淘汰这个人
	int index = 0;
	//下标，为总人数-1
	int *circle = NULL;
	//根据需求设为循环数组，存储每个人

	//用calloc()函数申请得到的空间，自动初始化每个元素为0
	//所以，0表示在这个人在约瑟夫环内，1表示这个人出圈，即“淘汰”
	circle = (int *) calloc(sizeof(int), count);

	//只要幸存人数大于0，则一直进行循环
	while(alive > 0) {
		number += 1- circle[index];
		//每轮到一个人报数，不管是"0"还是"1"都进行计数
		if(number == doom) {
			//当number==doom时，就要淘汰当前这个人
			/*
				淘汰一个人需要做四步操作：
					1、输出这个人的位置
					2、把这个人的状态从在圈内"0"改为不在圈内"1"
					3、幸存人数alive--
					4、 计数器number归零
			*/
			alive == 1 ? printf("%d", index+1) : printf("%d,", index+1);
			circle[index] = 1;
			alive--;
			number = 0;
		}
		//与总人数count取余，则可以使index在0~count-1之间 一直循环，达到循环数组的目的
		index = (index +1) % count;
	}

	free(circle);
	//结束后一定要释放circle所申请的空间
}

//函数声明
void mueu();

LL *CreatList();

void InitList(LL *,int );

int GetPassword();

int GetPersonNumber();

int GetSX();

void GetOutput(LL *,int , int , int * );

void print(int *,int );

void menu() {
	//菜单函数
	printf("————选择菜单————\n");
	printf("|			|\n");
	printf("|请选择以下功能：	|\n");
	printf("|			|\n");
	printf("|（1）了解约瑟夫环问题	|\n");
	printf("|			|\n");
	printf("|（2）约瑟夫环从1开始	|\n");
	printf("|			|\n");
	printf("|（3）约瑟夫环任意开始	|\n");
	printf("|			|\n");
	printf("|（4）退出程序		|\n");
	printf("|			|\n");
	printf("————————————\n");
	printf("请输入功能的编号（1-4）：");
}

LL *CreatList() {
	//单链表的初始化
	LL *l;
	l = (LL *)malloc(sizeof(LL));
	if(l == NULL) {
		printf("内存分配失败！");
		exit(1);
		//非正常运行导致退出程序
	}
	return l;
}

void InitList(LL *l,int personNumber) {
	//建立循环单链表
	LL *p,*q;
	int i;
	p = l;
	p->data = 1;
	p->password = GetPassword();
	for(i = 2; i <= personNumber; i++) {
		q = (LL *)malloc(sizeof(LL));
		if(q==NULL) {
			printf("内存空间分配失败！");
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
	//输入处理的人数
	int personNumber;
	printf("请输入人数：");
	scanf("%d",&personNumber);
	while(personNumber > maxnum || personNumber < 0) {
		printf("\n对不起，您输入的数字无效，请输入在0到%d的整数：",maxnum);
		scanf("%d",&personNumber);
	}
	printf("本次求约瑟夫环的出列顺序人数为%d人。\n\n",personNumber);
	return personNumber;
}

int GetPassword() {
	//为每个人赋密码
	int password;
	static int count = 1;
	printf("请输入第%d人的密码：",count);
	scanf("%d",&password);
	while(password > maxmi || password < 0) {
		printf("对不起，您输入的数字无效，请输入在0到%d的整数：",maxmi);
		scanf("%d",&password);
	}
	count++;
	return password;
}

int GetSX() {
	//确定开始的上限
	int sx;
	printf("请输入报数的上限值：");
	scanf("%d",&sx);
	while(sx > maxsx || sx < 0) {
		printf("\n对不起，您输入的数字无效，请输入在0到%d的整数：",maxsx);
		scanf("%d",&sx);
	}
	printf("最终的报数上限值为%d。\n\n",sx);
	return sx;
}

void GetOutput(LL *l,int personNumber,int sx,int array[maxnum]) {
	//得到出队顺序
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
	//输出最终结果
	int i;
	printf("\n按每人的编号(1~%d)依次出列的顺序为：",personNumber);
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
	system("title 约瑟夫环问题");
flag1:
	menu();
	ch=getchar();
	system("cls");
	switch (ch) {
		case '1':
			printf("  编号是1,2,……,n的n个人按照顺时针方向围坐一圈,\n");
			printf("每个人只有一个密码(正整数)。\n");
			printf("一开始任选一个正整数作为报数上限值m,");
			printf("从第一个仍开始顺时针方向自1开始顺序报数,\n");
			printf("报到m时停止报数。报m的人出列,将他的密码作为新的m值,");
			printf("从他在顺时针方向的下一个人\n");
			printf("开始重新从1报数,如此下去,直到所有人全部出列为止。\n\n");
			printf("	请按任意键继续");
			getch();
			system("cls");
			break;

		case '2':
			printf("————约瑟夫环问题————\n");
			personNumber = GetPersonNumber();
			SX = GetSX();
			l = CreatList();
			InitList(l,personNumber);
			GetOutput(l,personNumber,SX,array);
			print(array,personNumber);
			printf("请按任意键继续");
			getch();
			system("cls");
			break;
		case '3':
			int k,n;
			printf("-----------约瑟夫环问题---------\n");
			printf("\n请输入总人数和从第几个人开始报数n,k：\n");
			scanf("%d%d",&n,&k);
			Createlist(n);
			printf("\n出队的次序：\n");
			Outlist(k);
		case '4':
			printf("谢谢使用，再见！\n");
			return 0;
	}

	goto flag1;
	return 0;

}
