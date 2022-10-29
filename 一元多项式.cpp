#include<stdio.h>
#include<stdlib.h>

typedef struct LNode	//���
{
	float coef; //ϵ��
	int expn;   //ָ��
	struct LNode *next;	//��һ������ָ��
}*LinkList;	//LNodeָ��ı���

typedef LinkList polynomial;	//����ʽ
//----------------------------------------------------------------------------
void CreatList(LinkList &p, float _coef, int _expn);
void addAtTail(LinkList &p, float _coef, int _expn);
void show(polynomial &p);
void CreatPolyn(polynomial &p, int m);
bool isZero(polynomial &p);
void addPolyn(polynomial &pa, polynomial &pb);
//----------------------------------------------------------------------------
/*
	����һ����ͷ��������
	LinkList &p:������������ĵ�ַ
	float _coef:ͷ����ϵ��
	int _expn:ͷ����ָ��
	@Return void
*/
void CreatList(LinkList &p, float _coef, int _expn)
{
	p = (LinkList)malloc(sizeof(LNode));	//Ϊ����p����һ�������ڴ�
	p->next = NULL;	//ͷ������һ���ڵ�ָ�븳ֵΪNULL
	p->coef = _coef;	//ͷ����ϵ����ֵΪ_coef
	p->expn = _expn;	//ͷ����ָ����ֵΪ_expn
}
//----------------------------------------------------------------------------
/*
	������ĩβ����һ���ڵ�
	LinkList &p:������������ĵ�ַ
	float _coef:β����ϵ��
	int _expn:β����ָ��
	@Return void
*/
void addAtTail(LinkList &p, float _coef, int _expn)
{
	if (p)
	{
		/*
			����p��ΪNULL�����
			����һ���½�㲢Ϊ�˷����ڴ�
			����½���е�ϵ����ָ���ֱ�ֵΪ_coef��_expn
			������½ڵ�ŵ�����p��ĩβ
		*/
		LinkList cur;	//�µĽ��cur
		cur = (LinkList)malloc(sizeof(LNode));
		cur->next = NULL;
		cur->coef = _coef;
		cur->expn = _expn;
		LinkList temp;	//����ָ������p���һ���ָ��temp
		temp = p;		//����ָ��tempָ������p��ͷ���
		while (temp->next)	//����һ����㲻ΪNULL,ָ��temp��ָ����һ�����,ֱ����һ�����ΪNULL
			temp = temp->next;
		temp->next = cur;	//��ʱָ��tempָ�������β�ڵ�,�ѽ��cur�ŵ�������Ϊ�µ�β���
	}
	else
	{
		/*
			����pΪNULL�����
			������p����һ�������ڴ�,�������������p��ͷ���
			���ͷ����е�ϵ����ָ���ֱ�ֵΪ_coef��_expn
		*/
		p = (LinkList)malloc(sizeof(LNode));
		p->next = NULL;
		p->coef = _coef;
		p->expn = _expn;
	}
}
//----------------------------------------------------------------------------
/*
	��ʾ����ʽ,�Ѷ���ʽ��ӡ����
	polynomial &p:����ʾ�Ķ���ʽ�ĵ�ַ
	@Return void
*/
void show(polynomial &p)
{
	if (p)
	{
		polynomial temp;
		temp = p;
		int flag = 0;	//flag��ǩ,���ǰ����ϵ��Ϊ��,��ôflagΪ1,������ӡϵ��Ϊ�����,ֱ������ϵ����Ϊ�����
		if (temp->coef != 0)	//�����Ϊ��Ĵ�ӡ���
		{
			printf("%.3f", temp->coef);
			flag = 0;
		}
		else	//������Ϊ������,��ʱflag��Ϊ1
			flag = 1;

		while (temp->next)	//�ǳ�����Ĵ�ӡ���
		{
			temp = temp->next;
			if (temp->coef > 0 && flag == 0)	//���ϵ��Ϊ����flagΪ0�����
				if (temp->expn == 1)
					printf(" + %.3fx", temp->coef);
				else
					printf(" + %.3fx^%d", temp->coef, temp->expn);
			if (temp->coef < 0 && flag == 0)	//���ϵ��Ϊ����flagΪ0�����
				if (temp->expn == 1)
					printf(" - %.3fx", -temp->coef);
				else
					printf(" - %.3fx^%d", -temp->coef, temp->expn);
			if (temp->coef != 0 && flag == 1)	//���ϵ����Ϊ����flagΪ1�����,��ʱ֮ǰ���δ��ӡ
			{
				if (temp->expn == 1)
					printf("%.3fx^%d", temp->coef, temp->expn);
				else
					printf("%.3fx", temp->coef);
				flag = 0;
			}
		}

		if (flag == 1)	//�������ϵ���ͳ����Ϊ��,��ֻ��ӡһ��0
			printf("0");
		printf("\n");
	}
	else
		printf("0\n");
}
//----------------------------------------------------------------------------
/*
	�ж϶���ʽ�Ƿ�Ϊ��
	��Ϊ������������ΪNULL,�򷵻�true
	����Ϊ��,�򷵻�false
	polynomial &p:���жϵĶ���ʽ�ĵ�ַ
	@Return bool
*/
bool isZero(polynomial &p)
{
	if (p)
	{
		polynomial temp;
		temp = p;
		int flag = 1;
		if (temp->coef != 0)
			flag = 0;

		while (temp->next)
		{
			temp = temp->next;
			if (temp->coef != 0)
				flag = 0;
		}

		if (flag == 1)
			return true;
		else
			return false;
	}
	else
		return true;
}
//----------------------------------------------------------------------------
/*
	����һ������ʽ
	polynomial &p:�������Ķ���ʽ�ĵ�ַ
	int m:����ʽ������
	@Return void
*/
void CreatPolyn(polynomial &p, int m)
{
	p = NULL;	//��һ��ɾ�������������,����������
	for (int i = 0; i < m; i++)
	{
		float _coef;
		if (i == 0)
			printf("�����볣�����ֵ(��%d��):", m);
		else
			printf("������ָ��Ϊ%d�����ϵ��(��%d��):", i, m);
		scanf("%f", &_coef);
		addAtTail(p, _coef, i);
	}
	printf("\n");
}
//----------------------------------------------------------------------------
/*
	����������ʽ���,pa = pa + pb
	polynomial &pa:���ӵĶ���ʽ,����ֵ��ı�
	polynomial &pb:���ϵĶ���ʽ,����ֵ����ı�
	@Return void
*/
void addPolyn(polynomial &pa, polynomial &pb)
{
	if (!isZero(pa) && !isZero(pb))
	{
		/*
			����ʽpa�Ͷ���ʽpb����Ϊ���Ҷ���ΪNULL�����
		*/
		polynomial tempa;	//ָ�����ʽpa��������ָ��tempa
		polynomial tempb;	//ָ�����ʽpb��������ָ��tempb
		tempa = pa;	//ָ��tempa����ָ�����ʽpa��ͷ���
		tempb = pb;	//ָ��tempb����ָ�����ʽpb��ͷ���
		tempa->coef += tempb->coef;	//����ʽpa������ = ����ʽpa������ + ����ʽpb������

		while (tempa->next&&tempb->next)	//ָ��tempa��tempb��ָ����һ�����,ֱ������һ��ָ�����һ�����ΪNULL
		{
			tempa = tempa->next;
			tempb = tempb->next;
			tempa->coef += tempb->coef;	//����ʽpaĳ��ϵ�� = ����ʽpaĳ��ϵ�� + ����ʽpbĳ��ϵ��
		}
		while (!tempa->next&&tempb->next)	//������ʽpa������С��pb������,�Ͱ�pb��������ֵ��pa
		{
			tempb = tempb->next;
			addAtTail(tempa, tempb->coef, tempb->expn);
			tempa = tempa->next;
		}
	}
	if (isZero(pa) && !isZero(pb))
		/*
			����ʽpaΪ���ΪNULL�����,��ʱֱ�ӽ�pb��ͷ��㸳ֵ��pa
		*/
		pa = pb;
}
//----------------------------------------------------------------------------
int main()
{
	LinkList p1;
	int n1;
	printf("���������ʽp1������:");
	scanf("%d", &n1);
	printf("\n���������������ʽp1\n");
	CreatPolyn(p1, n1);
	printf("p1 = ");
	show(p1);
	printf("\n");

	LinkList p2;
	int n2;
	printf("���������ʽp2������:");
	scanf("%d", &n2);
	printf("\n���������������ʽp2\n");
	CreatPolyn(p2, n2);
	printf("p2 = ");
	show(p2);
	printf("\n");

	addPolyn(p1, p2);
	printf("p1 + p2 = ");
	show(p1);

	return 0;
}
