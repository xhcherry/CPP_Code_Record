#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define  L  20//ҳ�����򳤶����Ϊ20
int M;        //�ڴ��
struct Pro//����һ���ṹ��
{
	int num, time;
};
int Input(int m, Pro p[L])//��ӡҳ������״̬
{
	int i, j, c;
	cout << "������ʵ��ҳ�����򳤶�L(15<=L<=20)��";
	do
	{
		cin >> m;
		if (m > 20 || m < 15)cout << "ʵ��ҳ�泤������15��20֮��;����������L�� ";
		else break;
	} while (1);
	j = time(NULL);//ȡʱ��ʱ��
	srand(j);//��ʱ��ʱ��xΪ���ӣ���ʼ�������������
	cout << "��������:  ";
	for (i = 0; i < m; i++)
	{
		p[i].num = rand() % 10 + 1;//����1��10֮����漴���ŵ�����p��
		p[i].time = 0;
		cout << p[i].num << " ";
	}
	cout << endl;
	return m;
}
void print(Pro* page1)//��ӡ��ǰ��ҳ��
{
	Pro* page = new Pro[M];
	page = page1;
	for (int i = 0; i < M; i++)
		if (page[i].num == -1)
			cout << "   ";
		else
			cout << page[i].num << "  ";
	cout << "��" << endl;
}
int  Search(int e, Pro* page1)//Ѱ���ڴ������e��ͬ�Ŀ��
{
	Pro* page = new Pro[M];
	page = page1;
	for (int i = 0; i < M; i++) if (e == page[i].num) return i;//����iֵ
	return -1;
}
int Max(Pro* page1)//Ѱ������δʹ�õ�ҳ��
{
	Pro* page = new Pro[M];
	page = page1;
	int e = page[0].time, i = 0;
	while (i < M)         //�ҳ�������ʱ�����ҳ��
	{
		if (e < page[i].time)  e = page[i].time;
		i++;
	}
	for (i = 0; i < M; i++) if (e == page[i].time) return i;//�ҵ�������ʱ�����ҳ�淵������
	return -1;
}
int Count(Pro* page1, int i, int t, Pro p[L])//��¼��ǰ�ڴ����ҳ�����´�ʹ�ü������
{
	Pro* page = new Pro[M];
	page = page1;
	int count = 0;
	for (int j = i; j < L; j++)
	{
		if (page[t].num == p[j].num)break;//��ǰҳ���ٴα�����ʱѭ������
		else count++;//����count+1
	}
	return count;//����count��ֵ 
}
int main()
{
	int c;
	int m = 0, t = 0;
	float n = 0;
	Pro p[L];
	cout << "        *********************************************         " << endl;
	cout << "        *               ҳʽ�洢����               *          " << endl;
	cout << "        *********************************************         " << endl;
	cout << "����������ڴ�ҳ����m(3��5): ";
	do
	{
		cin >> M;
		if (M > 5 || M < 3)
			cout << "�ڴ��M����3��5֮�䣬����������M�� ";
		else break;
	} while (1);
	m = Input(m, p);//����input����������mֵ
	Pro* page = new Pro[M];
	cout << "^-^��ӭ�������ϵͳ����^-^" << endl;
	cout << "1:FIFOҳ���û�" << endl;
	cout << "2:LRUҳ���û�" << endl;
	cout << "3:OPTҳ���û�" << endl;
	cout << "4:�˳�" << endl;
	do {
		cout << "��1��4��������" << endl;
		cin >> c;
		system("cls");
		for (int i = 0; i < M; i++)//���Ի�ҳ��������
		{
			page[i].num = -1;
			page[i].time = m - 1 - i;
		}
		int i = 0;
		if (c == 1)//FIFOҳ���û�
		{
			n = 0;
			cout << "******************************************" << endl;
			cout << endl;
			cout << "          FIFO�㷨ҳ���û��������:       " << endl;			cout << endl;
			cout << "******************************************" << endl;
			while (i < m)
			{
				if (Search(p[i].num, page) >= 0)     //��ǰҳ�����ڴ���
				{
					cout << p[i].num << "  "; //�����ǰp[i].num
					cout << "��ȱҳ" << endl;
					i++;         //i��1
				}
				else                            //��ǰҳ�����ڴ���
				{
					if (t == M)t = 0;
					else
					{
						n++;                    //ȱҳ������1
						page[t].num = p[i].num;//�ѵ�ǰҳ������ڴ�
						cout << p[i].num << "  ";
						print(page);            //��ӡ��ǰҳ��
						t++;                    //��һ���ڴ��
						i++;                    //ָ����һ��ҳ��
					}
				}
			}
			cout << "ȱҳ������" << n << "    ȱҳ�ʣ�" << n / m << endl;
		}
		if (c == 2)//LRUҳ���û�
		{
			n = 0;
			cout << "******************************************" << endl;
			cout << endl;
			cout << "          LRU�㷨ҳ���û��������:        " << endl;
			cout << endl;
			cout << "******************************************" << endl;
			while (i < m)
			{
				int a;
				t = Search(p[i].num, page);
				if (t >= 0)//��������ڴ����  
				{
					page[t].time = 0;//��������ͬ���ڴ���ʱ����0
					for (a = 0; a < M; a++)
						if (a != t)page[a].time++;//������ʱ���1
					cout << p[i].num << "  ";
					cout << "��ȱҳ" << endl;
				}
				else    //��������ڴ����
				{
					n++;           //ȱҳ������1
					t = Max(page);     //����������δʹ�õĿ�Ÿ�ֵ��t
					page[t].num = p[i].num;    //�����滻
					page[t].time = 0;          //�滻��ʱ����Ϊ0
					cout << p[i].num << "  ";
					print(page);
					for (a = 0; a < M; a++)
						if (a != t)page[a].time++;//������ʱ���1            
				}
				i++;
			}
			cout << "ȱҳ������" << n << "    ȱҳ�ʣ�" << n / m << endl;
		}
		if (c == 3)//OPTҳ���û�
		{
			n = 0;
			cout << "******************************************" << endl;
			cout << endl;
			cout << "           OPT�㷨�û��������:           " << endl;
			cout << endl;
			cout << "******************************************" << endl;
			while (i < m)
			{
				if (Search(p[i].num, page) >= 0)//��������ڴ����
				{
					cout << p[i].num << "  ";
					cout << "��ȱҳ" << endl;
					i++;
				}
				else//��������ڴ����
				{
					int a = 0;
					for (t = 0; t < M; t++)
						if (page[t].num == 0)a++;//��¼�յ��ڴ����
					if (a != 0) //�п��ڴ��
					{
						int q = M;
						for (t = 0; t < M; t++)
							if (page[t].num == 0 && q > t)q = t;//�ѿ��ڴ���п����С���ҳ���
						page[q].num = p[i].num;
						n++;
						cout << p[i].num << "  ";
						print(page);
						i++;
					}
					else
					{
						int temp = 0, s;
						for (t = 0; t < M; t++)//Ѱ���ڴ�����´�ʹ����������õ�ҳ��							
							if (temp < Count(page, i, t, p))
							{
								temp = Count(page, i, t, p);
								s = t;
							}//���ҵ��Ŀ�Ÿ���s
						page[s].num = p[i].num;
						n++;
						cout << p[i].num << "  ";
						print(page);
						i++;
					}
				}
			}
			cout << "ȱҳ������" << n << "    ȱҳ�ʣ�" << n / m << endl;
		}
		if (c == 4)
		{
			cout << " ^-^�ټ���^-^ " << endl;
		}
	} while (c == 1 || c == 2 || c == 3 || c == 4);
	return 0;
}
