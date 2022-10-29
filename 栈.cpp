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
//�洢�ṹ
 typedef struct
 {
 	SElemType *base;//ջ��ָ��
	 SElemType *top;//ջ��ָ��
	 int stacksize;//ջ����������� 
 }SqStack;
Status InitStack(SqStack &S)//��ʼ��   
{  
    S.base=(SElemType*)malloc(sizeof(SElemType)*MAXSIZE);  
    if(!S.base)  
    exit(OVERFLOW);  
    S.top=S.base;  
    S.stacksize=MAXSIZE;  
    return OK;  
}   
//��ջ 
Status Push(SqStack &S,SElemType e)
{
//����eΪ�µ�ջ��Ԫ��
if(S.top-S.base==S.stacksize)
return ERROR;	//ջ��
*S.top++=e;//��eѹ��ջ��ջ��ָ���1 
return OK; 
} 
//��ջ
Status Pop(SqStack &S,SElemType &e)
{
//ɾ��ջ��Ԫ�أ���e������ֵ
if(S.top==S.base)	return ERROR;//ջ��
e=*--S.top; 
return OK;
} 
//ȡջ��Ԫ��
SElemType GetTop(SqStack S)
{
//����ջ��Ԫ�أ����޸�ջ��ָ��
if(S.top!=S.base)
return *(S.top-1);	
} 
Status In(SElemType c)//�ж�c�Ƿ�������� 
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
SElemType Precede(SElemType t1,SElemType t2)//�ж���������������ȼ���ϵ 
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
SElemType Operate(SElemType a,SElemType theta,SElemType b)//����a,b���������ֵ 
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
{//��OPTR,OPND�ֱ�Ϊ�����ջ�Ͳ���ջ
SqStack OPTR,OPND;
char ch,a,b,x,theta;
InitStack(OPTR);
InitStack(OPND);//��ʼ��
Push(OPTR,'#');//��ʼ����ջ
//scanf("%c",&ch);
ch=getchar();
while(ch!='#'||GetTop(OPTR)!='#')//���ʽû��ɨ����ϻ�OPTRջ��Ԫ�ز�Ϊ# 
{
if(!In(ch))
{
	Push(OPND,ch); 
//scanf("%c",&ch);// �������������OPNDջ 
ch=getchar();
}
else
{switch(Precede(GetTop(OPTR),ch))//�Ƚ�OPTR��ջ��Ԫ�غ�ch�����ȼ� 
{
	case '<':
	     Push(OPTR,ch);
		 //scanf("%c",&ch);//ѹ��ջ����ȡ��һ���ַ� 
		 ch=getchar();
	     break;
	case '>':
	    Pop(OPTR,theta); //����ջ��Ԫ�� �����
	    Pop(OPND,b);Pop(OPND,a); 
	    Push(OPND,Operate(a,theta,b));
	    break;
	case '='://OPTRջ��Ԫ����'('��ch��')'
	    Pop(OPTR,x);//scanf("%c",&ch);
	    ch=getchar();
		break; 	
}
} }
return GetTop(OPND)-'0';	
}
int main()
{
printf("�������㷨���ʽ,����#��β��");
//EvaluateExpression();
printf("The result of expression is %d\n",EvaluateExpression()); 
return 0;	
}
