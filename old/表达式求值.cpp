#include<stdio.h>
#define StackSize 100
#define QueueSize 100
//���е���ز���
typedef char DataType;
typedef struct {
	char data[100];
	int front, rear;
} SeqQueue; //�����������
void InitQueue(SeqQueue* Q) { //��ʼ������
	Q->front = 0;
	Q->rear = 0;
}
int QueueEmpty(SeqQueue* Q) { //�пն���
	return Q->rear == Q->front;
}
void EnQueue(SeqQueue* Q, DataType x) { //�����
	if ((Q->rear + 1) % QueueSize == Q->front)
		printf("Queue overflow");
	else {

		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % QueueSize;
	}
}
DataType DeQueue(SeqQueue* Q) { //ɾ������
	DataType e;
	if (Q == NULL)
		printf("No Queue!");
	else {
		e = Q->data[Q->front];
		Q->front = (Q->front + 1) % QueueSize;
	}
	return e;
}
//ջ����ز���
typedef struct {
	DataType data[100];
	int top;
} SeqStack; //ջ���͵Ķ���
void InitStack(SeqStack* S) { //��ʼ��ջ
	S->top = -1;
}
void Push(SeqStack* S, DataType x) { //��ջ����ջ��
	if (S->top == StackSize - 1)
		printf("stack overflow");
	else {
		S->top = S->top + 1;
		S->data[S->top] = x;
	}
}
DataType Pop(SeqStack* S) { //��ջ����ջ��
	if (S->top == -1) {
		printf("stack underflow");
		return 0;
	}
	else
		return S->data[S->top--];
}
DataType GetTop(SeqStack* S) { //ȡջ��Ԫ��
	if (S->top == -1) {
		printf("stack empty");
		return 0;
	}
	else
		return S->data[S->top];
}

int Priority(DataType op) { //����������ȼ�
	switch (op) {
	case '(':
	case'#':
		return (0);
	case '-':
	case'+':
		return (1);
	case '*':
	case'/':
		return (2);
	}
	return -1;
}
void CTPostExp(SeqQueue* Q) {
	SeqStack OS;//�����ջ
	char c, t;
	SeqStack* S;
	S = &OS;
	InitStack(S);//��ʼ��ջ
	Push(S, '#'); //ѹ��ջ��Ԫ�أ�
	do { //ɨ����׺���ʽ
		c = getchar();
		switch (c) {
		case ' ':
			break;//ȥ���ո��
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			EnQueue(Q, c);
			break;
		case '(':
			Push(S, c);
			break;
		case ')':
		case '#':
			do {
				t = Pop(S);
				if (t != '(' && t != '#') EnQueue(Q, t);
			} while (t != '(' && S->top != -1);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			while (Priority(c) <= Priority(GetTop(S))) {
				t = Pop(S);
				EnQueue(Q, t);
			}
			Push(S, c);
			break;
		}//EndSwitch
	} while (c != '#'); //�ԣ��������ʽɨ��
}
int CPostExp(SeqQueue* Q) {
	SeqStack VS, * S;
	char ch;
	int x, y;
	S = &VS;
	InitStack(S);
	while (!QueueEmpty(Q)) {
		ch = DeQueue(Q);
		if (ch >= '0' && ch <= '9')
			Push(S, ch - '0');
		else {
			y = Pop(S);
			x = Pop(S);
			switch (ch) {
			case '+':
				Push(S, x + y);
				break;



			case '-':
				Push(S, x - y);
				break;
			case '*':
				Push(S, x * y);
				break;
			case '/':
				Push(S, x / y);
				break;
			}
		}
	}
	return GetTop(S);
}
int main() {
	printf("������ʽ#����\n");
	SeqQueue* Q;
	SeqQueue PostQ;//������У� ��ź�׺���ʽ
	Q = &PostQ;
	InitQueue(Q);//��ʼ������
	CTPostExp(Q);//����ת����������׺���ʽת���ɺ�׺���ʽ
	printf("��׺���ʽ��");
	while (!QueueEmpty(Q))//�����׺���ʽ
		printf("%2c", DeQueue(Q));
	printf("\n");
	Q->front = 0;
	printf("���=");
	printf("%d\n", CPostExp(Q));
}
