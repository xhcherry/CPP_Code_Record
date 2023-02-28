#include<stdio.h>
#define StackSize 100
#define QueueSize 100
//队列的相关操作
typedef char DataType;
typedef struct {
	char data[100];
	int front, rear;
} SeqQueue; //定义队列类型
void InitQueue(SeqQueue* Q) { //初始化队列
	Q->front = 0;
	Q->rear = 0;
}
int QueueEmpty(SeqQueue* Q) { //判空队列
	return Q->rear == Q->front;
}
void EnQueue(SeqQueue* Q, DataType x) { //入队列
	if ((Q->rear + 1) % QueueSize == Q->front)
		printf("Queue overflow");
	else {

		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % QueueSize;
	}
}
DataType DeQueue(SeqQueue* Q) { //删除队列
	DataType e;
	if (Q == NULL)
		printf("No Queue!");
	else {
		e = Q->data[Q->front];
		Q->front = (Q->front + 1) % QueueSize;
	}
	return e;
}
//栈的相关操作
typedef struct {
	DataType data[100];
	int top;
} SeqStack; //栈类型的定义
void InitStack(SeqStack* S) { //初始化栈
	S->top = -1;
}
void Push(SeqStack* S, DataType x) { //入栈（进栈）
	if (S->top == StackSize - 1)
		printf("stack overflow");
	else {
		S->top = S->top + 1;
		S->data[S->top] = x;
	}
}
DataType Pop(SeqStack* S) { //退栈（出栈）
	if (S->top == -1) {
		printf("stack underflow");
		return 0;
	}
	else
		return S->data[S->top--];
}
DataType GetTop(SeqStack* S) { //取栈顶元素
	if (S->top == -1) {
		printf("stack empty");
		return 0;
	}
	else
		return S->data[S->top];
}

int Priority(DataType op) { //求运算符优先级
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
	SeqStack OS;//运算符栈
	char c, t;
	SeqStack* S;
	S = &OS;
	InitStack(S);//初始化栈
	Push(S, '#'); //压入栈底元素＃
	do { //扫描中缀表达式
		c = getchar();
		switch (c) {
		case ' ':
			break;//去除空格符
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
	} while (c != '#'); //以＃结束表达式扫描
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
	printf("输入表达式#结束\n");
	SeqQueue* Q;
	SeqQueue PostQ;//定义队列， 存放后缀表达式
	Q = &PostQ;
	InitQueue(Q);//初始化队列
	CTPostExp(Q);//调用转换函数将中缀表达式转换成后缀表达式
	printf("后缀表达式：");
	while (!QueueEmpty(Q))//输出后缀表达式
		printf("%2c", DeQueue(Q));
	printf("\n");
	Q->front = 0;
	printf("结果=");
	printf("%d\n", CPostExp(Q));
}
