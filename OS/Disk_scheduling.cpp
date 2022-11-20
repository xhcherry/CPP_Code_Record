#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
#define maxsize 1000
/*********************�ж����������Ƿ���Ч**************************/
int decide(char str[])  //�ж����������Ƿ���Ч
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i]>'9')
		{
			return 0;
			break;
		}
		i++;
	}
	return i;
}
/******************���ַ���ת��������***********************/
int trans(char str[], int a)   //���ַ���ת��������
{
	int i;
	int sum = 0;
	for (i = 0; i < a; i++)
	{
		sum = sum + (int)((str[i] - '0') * pow(10, a - i - 1));
	}
	return sum;
}
/*********************ð�������㷨**************************/
int* bubble(int cidao[], int m)
{
	int i, j;
	int temp;
	for (i = 0; i < m; i++)    //ʹ��ð�ݷ�����С����˳������
		for (j = i + 1; j < m; j++)
		{
			if (cidao[i] > cidao[j])
			{
				temp = cidao[i];
				cidao[i] = cidao[j];
				cidao[j] = temp;
			}
		}
	cout << "�����Ĵ�������Ϊ��";
	for (i = 0; i < m; i++)   //���������
	{
		cout << cidao[i] << " ";
	}
	cout << endl;
	return cidao;
}
/*********************�����ȷ�������㷨**************************/
void FCFS(int cidao[], int m)   //�ŵ������飬����Ϊm
{
	int now;//��ǰ�ŵ���
	int sum = 0;   //��Ѱ������
	int j, i;
	int a;
	char str[100];
	float ave;   //ƽ��Ѱ������
	cout << "������������Ϊ��";
	for (i = 0; i < m; i++)   //�������ȷ���Ĳ������������������
	{
		cout << cidao[i] << " ";
	}
	cout << endl;
	cout << "�����뵱ǰ�Ĵŵ��ţ�";
B: cin >> str;  //���������ݽ�����Ч���ж�
	a = decide(str);
	if (a == 0)
	{
		cout << "�������ݵ����ʹ���,���������룡" << endl;
		goto B;
	}
	else
		now = trans(str, a);   //���뵱ǰ�ŵ���
	sum += abs(cidao[0] - now);
	cout << "����ɨ������Ϊ��";
	for (i = 0; i < m; i++)   //�������ɨ������
	{
		cout << cidao[i] << " ";
	}
	for (i = 0, j = 1; j < m; i++, j++)   //��ƽ��Ѱ������
	{
		sum += abs(cidao[j] - cidao[i]);
		ave = (float)(sum) / (float)(m);
	}
	cout << endl;
	cout << "ƽ��Ѱ�����ȣ�" << ave << endl;
}
/**********************���Ѱ��ʱ�����ȵ����㷨********************/
void SSTF(int cidao[], int m)
{
	int k = 1;
	int now, l, r;
	int i, j, sum = 0;
	int a;
	char str[100];
	float ave;
	cidao = bubble(cidao, m);    //����ð�������㷨����
	cout << "�����뵱ǰ�Ĵŵ��ţ�";
C: cin >> str;  //���������ݽ�����Ч���ж�
	a = decide(str);
	if (a == 0)
	{
		cout << "�������ݵ����ʹ���,���������룡" << endl;
		goto C;
	}
	else
		now = trans(str, a);   //���뵱ǰ�ŵ���
	if (cidao[m - 1] <= now)   //����ǰ�ŵ��Ŵ�����������������ߣ���ֱ�������������θ�����������
	{
		cout << "����ɨ������Ϊ��";
		for (i = m - 1; i >= 0; i--)
			cout << cidao[i] << " ";
		sum = now - cidao[0];
	}
	if (cidao[0] >= now)   //����ǰ�ŵ���С��������������С�ߣ���ֱ�������������θ�����������
	{
		cout << "����ɨ������Ϊ��";
		for (i = 0; i < m; i++)
			cout << cidao[i] << " ";
		sum = cidao[m - 1] - now;
	}
	if (now > cidao[0] && now < cidao[m - 1])   //����ǰ�ŵ��Ŵ���������������С����С�������
	{
		cout << "����ɨ������Ϊ��";
		while (cidao[k] < now)    //ȷ����ǰ�ŵ������ŵ������е�λ�ã�������㷨���õ��ˣ�����ֱ�Ӹ��ƺ������޸ģ���ʡʱ�䡣
		{
			k++;
		}
		l = k - 1;
		r = k;
		while ((l >= 0) && (r < m))   //��ǰ�ŵ����������з�Χ��
		{
			if ((now - cidao[l]) <= (cidao[r] - now))   //ѡ���뵱ǰ�ŵ����������������
			{
				cout << cidao[l] << " ";
				sum += now - cidao[l];
				now = cidao[l];
				l = l - 1;
			}
			else
			{
				cout << cidao[r] << " ";
				sum += cidao[r] - now;
				now = cidao[r];
				r = r + 1;
			}
		}
		if (l == -1)   //��ͷ�ƶ������е���С�ţ��������ɨ����δɨ��Ĵŵ�
		{
			for (j = r; j < m; j++)
			{
				cout << cidao[j] << " ";
			}
			sum += cidao[m - 1] - cidao[0];
		}
		else    //��ͷ�ƶ������е����ţ������ڲ�ɨ����δɨ��Ĵŵ�
		{
			for (j = l; j >= 0; j--)
			{
				cout << cidao[j] << " ";
			}
			sum += cidao[m - 1] - cidao[0];
		}
	}
	ave = (float)(sum) / (float)(m);
	cout << endl;
	cout << "ƽ��Ѱ�����ȣ� " << ave << endl;
}
/*****************************ɨ������㷨*******************************/
void SCAN(int cidao[], int m)    //��Ҫ������ǰ�ŵ��ź��ƶ��۵��ƶ�����
{
	int k = 1;
	int now, l, r, d;
	int i, j, sum = 0;
	int a;
	char str[100];
	float ave;
	cidao = bubble(cidao, m);    //����ð�������㷨����
	cout << "�����뵱ǰ�Ĵŵ��ţ�";
D: cin >> str;  //���������ݽ�����Ч���ж�
	a = decide(str);
	if (a == 0)
	{
		cout << "�������ݵ����ʹ���,���������룡" << endl;
		goto D;
	}
	else
		now = trans(str, a);   //���뵱ǰ�ŵ���
	if (cidao[m - 1] <= now)    //����ǰ�ŵ��Ŵ�����������������ߣ���ֱ�������������θ�����������,�����ͬ���Ѱ������
	{
		cout << "����ɨ������Ϊ��";
		for (i = m - 1; i >= 0; i--)
			cout << cidao[i] << " ";
		sum = now - cidao[0];
	}
	if (cidao[0] >= now)     //����ǰ�ŵ���С��������������С�ߣ���ֱ�������������θ�����������,�����ͬ���Ѱ������
	{
		cout << "����ɨ������Ϊ��";
		for (i = 0; i < m; i++)
			cout << cidao[i] << " ";
		sum = cidao[m - 1] - now;
	}
	if (now > cidao[0] && now < cidao[m - 1])   //����ǰ�ŵ��Ŵ���������������С����С�������
	{
		while (cidao[k] < now)
		{
			k++;
		}
		l = k - 1;
		r = k;
		cout << "�����뵱ǰ�ƶ��۵��ƶ��ķ��� (1 ��ʾ���� ��0��ʾ����) : ";
		cin >> d;
		if (d == 0)     //ѡ���ƶ��۷������ڣ���������ɨ��
		{
			cout << "����ɨ������Ϊ��";
			for (j = l; j >= 0; j--)
			{
				cout << cidao[j] << " ";    //�������ɨ�������
			}
			for (j = r; j < m; j++)   //��ͷ�ƶ�����С�ţ���ı䷽������ɨ��δɨ��Ĵŵ�
			{
				cout << cidao[j] << " ";    //�������ɨ�������
			}
			sum = now - 2 * cidao[0] + cidao[m - 1];
		}
		else     //ѡ���ƶ��۷������⣬��������ɨ��
		{
			cout << "����ɨ������Ϊ��";
			for (j = r; j < m; j++)
			{
				cout << cidao[j] << " ";   //�������ɨ�������
			}
			for (j = l; j >= 0; j--)    //��ͷ�ƶ������ţ���ı䷽������ɨ��δɨ��Ĵŵ�
			{
				cout << cidao[j] << " ";
			}
			sum = -now - cidao[0] + 2 * cidao[m - 1];
		}
	}
	ave = (float)(sum) / (float)(m);
	cout << endl;
	cout << "ƽ��Ѱ�����ȣ� " << ave << endl;
}
/************************ѭ��ɨ������㷨*****************************/

void CSCAN(int cidao[], int m)
{
	int k = 1;
	int now, l, r;
	int i, j, sum = 0;
	int a;
	char str[100];
	float ave;
	cidao = bubble(cidao, m);    //����ð�������㷨����
	cout << "�����뵱ǰ�Ĵŵ��ţ�";
E: cin >> str;  //���������ݽ�����Ч���ж�
	a = decide(str);
	if (a == 0)
	{
		cout << "�������ݵ����ʹ���,���������룡" << endl;
		goto E;
	}
	else
		now = trans(str, a);   //���뵱ǰ�ŵ���
	if (cidao[m - 1] <= now)   //����ǰ�ŵ��Ŵ�����������������ߣ���ֱ�ӽ��ƶ����ƶ�����С�Ŵŵ�������������������� 
	{
		cout << "����ɨ������Ϊ��";
		for (i = 0; i < m; i++)
			cout << cidao[i] << " ";
		sum = now - 2 * cidao[0] + cidao[m - 1];
	}
	if (cidao[0] >= now) //����ǰ�ŵ���С��������������С�ߣ���ֱ�������������θ�����������,�����ͬ���Ѱ������
	{
		cout << "����ɨ������Ϊ��";
		for (i = 0; i < m; i++)
			cout << cidao[i] << " ";
		sum = cidao[m - 1] - now;
	}
	if (now > cidao[0] && now < cidao[m - 1])  //����ǰ�ŵ��Ŵ���������������С����С�������
	{
		cout << "����ɨ������Ϊ��";
		while (cidao[k] < now)    //���򷴸��ش�������ɨ��
		{
			k++;
		}
		l = k - 1;
		r = k;
		for (j = r; j < m; j++)
		{
			cout << cidao[j] << " ";     //����ӵ�ǰ�ŵ�����ɨ�������
		}
		for (j = 0; j < r; j++)     //��ɨ�������Ŵŵ�����ͷֱ���ƶ�����С�Ŵŵ���������ɨ��δɨ��Ĵŵ�
		{
			cout << cidao[j] << " ";
		}
		sum = 2 * cidao[m - 1] + cidao[l] - now - 2 * cidao[0];
	}
	ave = (float)(sum) / (float)(m);
	cout << endl;
	cout << "ƽ��Ѱ�����ȣ� " << ave << endl;
}
void main()
{
	int a;
	int c;     //�˵���
	int cidao[maxsize], cidao1[maxsize];
	int i = 0, count;
	char str[100];
	cout << "������ŵ����У�0��������" << endl;
A:cin >> str;  //���������ݽ�����Ч���ж�
	a = decide(str);
	if (a == 0)
	{
		cout << "�������ݵ����ʹ���,���������룡" << endl;
		goto A;//���������ת��A����������
	}
	else
	{
		cidao[i] = trans(str, a);
		cidao1[i] = trans(str, a);
	}
	i++;
	while (cidao[i - 1] != 0)
	{
		cin >> str;  //���������ݽ�����Ч���ж�
		a = decide(str);
		if (a == 0)
			cout << "�������ݵ����ʹ���,���������룡" << endl;
		else
		{
			cidao[i] = trans(str, a);
			cidao1[i] = trans(str, a);
			i++;
		}
	}
	count = i - 1;     //Ҫ���ʵĴŵ���
	cout << "������Ĵŵ�����Ϊ��";
	for (i = 0; i < count; i++)
	{
		cout << cidao[i] << " ";     //����ŵ�����
	}
	cout << endl;
	while (1)
	{
		cout << endl;
		cout << "**********************************************" << endl;
		cout << "******             ϵͳ�˵�             ******" << endl;
		cout << "**********************************************" << endl;
		cout << "***                                        ***" << endl;
		cout << "**              1. �����ȷ���               **" << endl;
		cout << "**                                          **" << endl;
		cout << "**              2. ���Ѱ��ʱ������         **" << endl;
		cout << "**                                          **" << endl;
		cout << "**              3. ɨ�����                 **" << endl;
		cout << "**                                          **" << endl;
		cout << "**              4. ѭ��ɨ��                 **" << endl;
		cout << "**                                          **" << endl;
		cout << "**              5. �˳�                     **" << endl;
		cout << "***                                        ***" << endl;
		cout << "**********************************************" << endl;
		cout << "**********************************************" << endl;
	G:cout << "��ѡ���㷨��";
	F:cin >> str;  //���������ݽ�����Ч���ж�
		a = decide(str);
		if (a == 0)
		{
			cout << "�������ݵ����ʹ���,���������룡" << endl;
			goto F;//���������ת��F����������
		}
		else
			c = trans(str, a);
		if (c == 5)
			break;
		if (c > 5)
		{
			cout << "���������������������" << endl;
			goto G;
		}
		switch (c)
		{
		case 1:    //ʹ��FCFS�㷨
			FCFS(cidao1, count);
			break;
		case 2:    //ʹ��SSTF�㷨
			SSTF(cidao, count);
			break;
		case 3:    //ʹ��SCAN�㷨
			SCAN(cidao, count);
			break;
		case 4:    //ʹ��CSCAN�㷨
			CSCAN(cidao, count);
			break;
		}
	}
}
