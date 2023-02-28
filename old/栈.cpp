#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<malloc.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define MAXSIZE 100 
typedef int Status;
typedef char SElemType;
//存储结构
 typedef struct
 {
 	SElemType *base;//栈底指针
	 SElemType *top;//栈顶指针
	 int stacksize;//栈可用最大容量 
 }SqStack;
Status InitStack(SqStack &S)//初始化   
{  
    S.base=(SElemType*)malloc(sizeof(SElemType)*MAXSIZE);  
    if(!S.base)  
    exit(OVERFLOW);  
    S.top=S.base;  
    S.stacksize=MAXSIZE;  
    return OK;  
}   
//入栈 
Status Push(SqStack &S,SElemType e)
{
//插入e为新的栈顶元素
if(S.top-S.base==S.stacksize)
return ERROR;	//栈满
*S.top++=e;//将e压入栈，栈顶指针加1 
return OK; 
} 
//出栈
Status Pop(SqStack &S,SElemType &e)
{
//删除栈顶元素，用e返回其值
if(S.top==S.base)	return ERROR;//栈空
e=*--S.top; 
return OK;
} 
//取栈顶元素
SElemType GetTop(SqStack S)
{
//返回栈顶元素，不修改栈顶指针
if(S.top!=S.base)
return *(S.top-1);	
} 
Status In(SElemType c)//判断c是否是运算符 
{
	switch(c)
	{
	case '+':
	     return 1;break;
    case '-':
	     return 1;break;
    case '*':
	     return 1;break;
    case '/':
	     return 1;break;
    case '(':
    	return 1;break;
    case ')':
    	return 1;break;
    case '#':
    	return 1;break;
	default:return 0;	
	} 
}
SElemType Precede(SElemType t1,SElemType t2)//判断两个运算符的优先级关系 
{
SElemType f;
switch(t2)
{
case '+':
    if(t1=='('||t1=='#')
	f='<';
	else
	f='>';
	break;
case '-':
	if(t1=='('||t1=='#')
	f='<';
	else
	f='>';
	break;
case '*':
	if(t1=='*'||t1=='/'||t1==')')
	f='>';
	else
	f='<';
	break;
case '/':
	if(t1=='/'||t1==')')
	f='>';
	else
	f='<';
	break;
case '(':
	if(t1!=')')
	f='<';
	break;
case ')':
	if(t1=='(')
	f='=';
	else if(t1!='#')
	f='<';
	break;
case '#':
	if(t1=='#')
	f='=';
	else if(t1!='(')
	f='>';
	break;
}	
return f;
}
SElemType Operate(SElemType a,SElemType theta,SElemType b)//计算a,b操作后的数值 
{
SElemType c;
a=a-48;b=b-48;
switch(theta)
{
case '+':c=a+b+48;break;
case '-':c=a-b+48;break;
case '*':c=a*b;break;
case '/':c=a/b;break;	
} 
return c;
}
 
int EvaluateExpression()
{//设OPTR,OPND分别为运算符栈和操作栈
SqStack OPTR,OPND;
char ch,a,b,x,theta;
InitStack(OPTR);
InitStack(OPND);//初始化
Push(OPTR,'#');//起始符入栈
//scanf("%c",&ch);
ch=getchar();
while(ch!='#'||GetTop(OPTR)!='#')//表达式没有扫描完毕或OPTR栈顶元素不为# 
{
if(!In(ch))
{
	Push(OPND,ch); 
//scanf("%c",&ch);// 不是运算符，进OPND栈 
ch=getchar();
}
else
{switch(Precede(GetTop(OPTR),ch))//比较OPTR的栈顶元素和ch的优先级 
{
	case '<':
	     Push(OPTR,ch);
		 //scanf("%c",&ch);//压入栈，读取下一个字符 
		 ch=getchar();
	     break;
	case '>':
	    Pop(OPTR,theta); //弹出栈顶元素 运算符
	    Pop(OPND,b);Pop(OPND,a); 
	    Push(OPND,Operate(a,theta,b));
	    break;
	case '='://OPTR栈顶元素是'('且ch是')'
	    Pop(OPTR,x);//scanf("%c",&ch);
	    ch=getchar();
		break; 	
}
} }
return GetTop(OPND)-'0';	
}
int main()
{
printf("请输入算法表达式,并以#结尾：");
//EvaluateExpression();
printf("The result of expression is %d\n",EvaluateExpression()); 
return 0;	
}
