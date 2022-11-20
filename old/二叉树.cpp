#include <iostream>

#define MAXSIZE 100

using namespace std;

typedef struct BiTNode { //�������Ĵ洢�ṹ

	char data;

	struct BiTNode *lchild,*rchild;

} BiTNode,*BiTree;

typedef struct { //ջ�Ĵ洢�ṹ

	BiTree *base;

	BiTree *top;

	int stacksize;

} SqStack;

void InitStack(SqStack &S) { //����һ����ջ

	S.base=new BiTree[MAXSIZE];

	if(!S.base) exit(-2);

	S.top=S.base;

	S.stacksize=MAXSIZE;

}

typedef struct { //���еĴ洢�ṹ

	BiTree *base;  //�洢�ռ�Ļ�ָ��

	int front; //ͷָ�루αָ�룩

	int rear;  //βָ�루αָ�룩

} SqQueue;

//ѭ�����г�ʼ��

int InitQueue(SqQueue &Q) {
	//����һ���ն���Q

	Q.base=new BiTree[MAXSIZE];  //Ϊ���з���һ���������ΪMAXSIZE������ռ�

	if(!Q.base) exit(-2);  //�洢����ʧ��

	Q.front=Q.rear=0;  //ͷָ���βָ����Ϊ0������Ϊ��

	return 1;

}

//ѭ�������п�
bool QueueEmpty(SqQueue Q) {

	if(Q.front==Q.rear) return true;

	else return false;

}

// ѭ���������
int EnQueue(SqQueue &Q,BiTree e) {

	if((Q.rear+1)%MAXSIZE==Q.front)

		return 0;

	Q.base[Q.rear]=e;

	Q.rear=(Q.rear+1)%MAXSIZE;

	return 1;

}

//ѭ�����еĳ���
int DeQueue(SqQueue &Q,BiTree &e) {

	if(Q.front==Q.rear) return 0;

	e=Q.base[Q.front];

	Q.front=(Q.front+1)%MAXSIZE;

	return 1;

}

//ȡ��ͷԪ��
BiTree GetHead(SqQueue Q) {

	if(Q.front!=Q.rear)

		return Q.base[Q.front];

}

bool StackEmpty(SqStack S) { //�ж�ջ�Ƿ�Ϊ��

	if(S.top==S.base) return true;

	else return false;

}

int Push(SqStack &S,BiTree e) { //��ջ

	if(S.top-S.base==S.stacksize)return -1;

	*(S.top++)=e;

	return 1;

}

int Pop(SqStack &S,BiTree &e) { //��ջ

	if(S.top==S.base) return 0;

	e= *(--S.top);

	return 1;

}

void createBiTree(BiTree &T) { //����������������� �ݹ�ʵ��

	char ch;

	cin>>ch;

	if(ch=='#')T=NULL;   //�ݹ����

	else {

		T=new BiTNode;

		T->data=ch;

		createBiTree(T->lchild); //����������

		createBiTree(T->rchild);  //����������

	}

}



void FirstOrderTraverse(BiTree T) { //����������������ݹ�ʵ��

	if(T) {

		cout<<T->data;

		FirstOrderTraverse(T->lchild);

		FirstOrderTraverse(T->rchild);

	}

}

void FirstOrderTraverse_1(BiTree T) { //����������������ǵݹ�ʵ��

	SqStack S;

	InitStack(S);

	BiTree p,q;

	p=T;

	q=new BiTNode;

	while(p||!StackEmpty(S)) {

		if(p) {

			cout<<p->data;

			Push(S,p);

			p=p->lchild;

		}

		else {

			Pop(S,q);

			p=q->rchild;

		}

	}


}

void InOrderTraverse(BiTree T) { //����������������ݹ�ʵ��

	if(T) {

		InOrderTraverse(T->lchild);

		cout<<T->data;

		InOrderTraverse(T->rchild);

	}

}

void InOrderTraverse_1(BiTree T) {  //����������������ǵݹ�ʵ��

	SqStack S;

	InitStack(S);

	BiTree p,q;

	p=T;

	q=new BiTNode;

	while(p||!StackEmpty(S)) {

		if(p) {

			Push(S,p);

			p=p->lchild;

		}

		else {

			Pop(S,q);

			cout<<q->data;

			p=q->rchild;

		}

	}

}

void LastOrderTraverse(BiTree T) { //����������������ݹ�ʵ��

	if(T) {

		LastOrderTraverse(T->lchild);

		LastOrderTraverse(T->rchild);

		cout<<T->data;

	}

}

void OrderTraverse(BiTree T) { //��α���������������ʵ��

	SqQueue Q;

	InitQueue(Q);

	EnQueue(Q,T);

	BiTree p,q;

	p=T;

	q=new BiTNode;

	while(!QueueEmpty(Q)) {

		DeQueue(Q,q);

		cout<<q->data;

		if(q->lchild!=NULL)EnQueue(Q,q->lchild);

		if(q->rchild!=NULL)EnQueue(Q,q->rchild);

	}

}

void DoubleOrderTraverse(BiTree T) {  //˫��������������ݹ�ʵ��

	if(T) {

		cout<<T->data;

		DoubleOrderTraverse(T->lchild);

		cout<<T->data;

		DoubleOrderTraverse(T->rchild);

	}

}

void Copy(BiTree T,BiTree &NewT) { //���ƶ�����

	if(T==NULL) {

		NewT=NULL;

		return ;

	}

	else {

		NewT=new BiTNode;

		NewT->data=T->data;

		Copy(T->lchild,NewT->lchild);

		Copy(T->rchild,NewT->rchild);

	}

}

int Depth(BiTree T) { //��������������

	int m,n;

	if(T==NULL) return 0;

	else {

		m=Depth(T->lchild);

		n=Depth(T->rchild);

		if(m>n) return(m+1);

		else return(n+1);

	}

}

int NodeCount(BiTree T) { //ͳ�ƽ�����

	if(T==NULL) return 0;

	else {

		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;

	}

}

int NodeCount_0(BiTree T) { //ͳ��Ҷ�ӽ�����

	if(T==NULL)return 0;

	else if(T->lchild==NULL&&T->rchild==NULL)

		return NodeCount_0(T->lchild)+NodeCount_0(T->rchild)+1;

	else return NodeCount_0(T->lchild)+NodeCount_0(T->rchild);

}

int NodeCount_1(BiTree T) { //ͳ�ƶ�Ϊ1�Ľ�����

	if(T==NULL)return 0;

	else if((T->lchild==NULL&&T->rchild!=NULL)||(T->lchild!=NULL&&T->rchild==NULL))

		return NodeCount_1(T->lchild)+NodeCount_1(T->rchild)+1;

	else return NodeCount_1(T->lchild)+NodeCount_1(T->rchild);

}

int NodeCount_2(BiTree T) { //ͳ�ƶ�Ϊ2�Ľ�����

	if(T==NULL)return 0;

	else if(T->lchild!=NULL&&T->rchild!=NULL)

		return NodeCount_2(T->lchild)+NodeCount_2(T->rchild)+1;

	else return NodeCount_2(T->lchild)+NodeCount_2(T->rchild);


}

void changeChild(BiTree &T) { //������������

	BiTree t;

	if(T==NULL) return ;

	else {

		t=new BiTNode;

		t=T->lchild;

		T->lchild=T->rchild;

		T->rchild=t;

		changeChild(T->lchild);

		changeChild(T->rchild);

	}

}

void menu() { //�˵�����

	cout<<"��ѡ�������"<<endl;

	cout<<"      1.����������"<<endl;

	cout<<"      2.�������������"<<endl;

	cout<<"      3.�������������"<<endl;

	cout<<"      4.�������������"<<endl;

	cout<<"      5.�������������"<<endl;

	cout<<"      6.˫�����������"<<endl;

	cout<<"      7.���ƶ�����"<<endl;

	cout<<"      8.������������"<<endl;

	cout<<"      9.ͳ�ƽ�����"<<endl;

	cout<<"      10.ͳ��Ҷ�ӽ�����"<<endl;

	cout<<"      11.ͳ�ƶ�Ϊ1�Ľ�����"<<endl;

	cout<<"      12.ͳ�ƶ�Ϊ2�Ľ�����"<<endl;

	cout<<"      13.������������"<<endl;

	cout<<"      14.�˳�"<<endl;

}

int main() {

	BiTree T;

	int choose;

	menu();

	while(cin>>choose&&choose!=14) {

		switch(choose) {

			case 1: {

				cout<<"�밴�����������˳������һ����������������#��ǣ�:";

				createBiTree(T);

				cout<<"�����������ɹ���"<<endl;

				break;
			}

			case 2: {

				cout<<"��������Ľ��Ϊ:"<<endl;

				FirstOrderTraverse(T);

				cout<<endl;

				FirstOrderTraverse_1(T);

				cout<<endl;

				break;
			}

			case 3: {

				cout<<"��������Ľ��Ϊ:"<<endl;

				InOrderTraverse(T);

				cout<<endl;

				InOrderTraverse_1(T);

				cout<<endl;

				break;
			}

			case 4: {

				cout<<"��������Ľ��Ϊ:"<<endl;

				LastOrderTraverse(T);

				cout<<endl;

				break;
			}

			case 5: {

				cout<<"��α����Ľ��Ϊ:"<<endl;

				OrderTraverse(T);

				cout<<endl;

				break;
			}

			case 6: {

				cout<<"˫������Ľ��Ϊ:"<<endl;

				DoubleOrderTraverse(T);

				cout<<endl;

				break;
			}

			case 7: {

				BiTree NewT;

				Copy(T,NewT);

				cout<<"������ϣ�"<<endl;

				cout<<"���ƺ�Ķ������������Ϊ:"<<endl;

				FirstOrderTraverse(NewT);

				cout<<endl;

				break;
			}

			case 8: {

				cout<<"�����������Ϊ:";

				cout<<Depth(T);

				cout<<endl;

				break;
			}

			case 9: {

				cout<<"�������н�����Ϊ:";

				cout<<NodeCount(T);

				cout<<endl;

				break;
			}

			case 10: {

				cout<<"��������Ҷ�ӽ�����Ϊ:";

				cout<<NodeCount_0(T);

				cout<<endl;

				break;
			}

			case 11: {

				cout<<"�������ж�Ϊ1�Ľ�����Ϊ:";

				cout<<NodeCount_1(T);

				cout<<endl;

				break;
			}

			case 12: {

				cout<<"�������ж�Ϊ2�Ľ�����Ϊ:";

				cout<<NodeCount_2(T);

				cout<<endl;

				break;
			}

			case 13: {

				cout<<"�ѽ�����������";

				changeChild(T);

				cout<<endl;

				break;
			}

			default: {

				cout<<"������������������"<<endl;

				break;
			}

		}


	}

}

