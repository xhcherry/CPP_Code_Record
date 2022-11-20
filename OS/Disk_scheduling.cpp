#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
#define maxsize 1000
/*********************判断输入数据是否有效**************************/
int decide(char str[])  //判断输入数据是否有效
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
/******************将字符串转换成数字***********************/
int trans(char str[], int a)   //将字符串转换成数字
{
	int i;
	int sum = 0;
	for (i = 0; i < a; i++)
	{
		sum = sum + (int)((str[i] - '0') * pow(10, a - i - 1));
	}
	return sum;
}
/*********************冒泡排序算法**************************/
int* bubble(int cidao[], int m)
{
	int i, j;
	int temp;
	for (i = 0; i < m; i++)    //使用冒泡法按从小到大顺序排列
		for (j = i + 1; j < m; j++)
		{
			if (cidao[i] > cidao[j])
			{
				temp = cidao[i];
				cidao[i] = cidao[j];
				cidao[j] = temp;
			}
		}
	cout << "排序后的磁盘序列为：";
	for (i = 0; i < m; i++)   //输出排序结果
	{
		cout << cidao[i] << " ";
	}
	cout << endl;
	return cidao;
}
/*********************先来先服务调度算法**************************/
void FCFS(int cidao[], int m)   //磁道号数组，个数为m
{
	int now;//当前磁道号
	int sum = 0;   //总寻道长度
	int j, i;
	int a;
	char str[100];
	float ave;   //平均寻道长度
	cout << "磁盘请求序列为：";
	for (i = 0; i < m; i++)   //按先来先服务的策略输出磁盘请求序列
	{
		cout << cidao[i] << " ";
	}
	cout << endl;
	cout << "请输入当前的磁道号：";
B: cin >> str;  //对输入数据进行有效性判断
	a = decide(str);
	if (a == 0)
	{
		cout << "输入数据的类型错误,请重新输入！" << endl;
		goto B;
	}
	else
		now = trans(str, a);   //输入当前磁道号
	sum += abs(cidao[0] - now);
	cout << "磁盘扫描序列为：";
	for (i = 0; i < m; i++)   //输出磁盘扫描序列
	{
		cout << cidao[i] << " ";
	}
	for (i = 0, j = 1; j < m; i++, j++)   //求平均寻道长度
	{
		sum += abs(cidao[j] - cidao[i]);
		ave = (float)(sum) / (float)(m);
	}
	cout << endl;
	cout << "平均寻道长度：" << ave << endl;
}
/**********************最短寻道时间优先调度算法********************/
void SSTF(int cidao[], int m)
{
	int k = 1;
	int now, l, r;
	int i, j, sum = 0;
	int a;
	char str[100];
	float ave;
	cidao = bubble(cidao, m);    //调用冒泡排序算法排序
	cout << "请输入当前的磁道号：";
C: cin >> str;  //对输入数据进行有效性判断
	a = decide(str);
	if (a == 0)
	{
		cout << "输入数据的类型错误,请重新输入！" << endl;
		goto C;
	}
	else
		now = trans(str, a);   //输入当前磁道号
	if (cidao[m - 1] <= now)   //若当前磁道号大于请求序列中最大者，则直接由外向内依次给予各请求服务
	{
		cout << "磁盘扫描序列为：";
		for (i = m - 1; i >= 0; i--)
			cout << cidao[i] << " ";
		sum = now - cidao[0];
	}
	if (cidao[0] >= now)   //若当前磁道号小于请求序列中最小者，则直接由内向外依次给予各请求服务
	{
		cout << "磁盘扫描序列为：";
		for (i = 0; i < m; i++)
			cout << cidao[i] << " ";
		sum = cidao[m - 1] - now;
	}
	if (now > cidao[0] && now < cidao[m - 1])   //若当前磁道号大于请求序列中最小者且小于最大者
	{
		cout << "磁盘扫描序列为：";
		while (cidao[k] < now)    //确定当前磁道在已排的序列中的位置，后面的算法都用到了，可以直接复制后少量修改，节省时间。
		{
			k++;
		}
		l = k - 1;
		r = k;
		while ((l >= 0) && (r < m))   //当前磁道在请求序列范围内
		{
			if ((now - cidao[l]) <= (cidao[r] - now))   //选择与当前磁道最近的请求给予服务
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
		if (l == -1)   //磁头移动到序列的最小号，返回外侧扫描仍未扫描的磁道
		{
			for (j = r; j < m; j++)
			{
				cout << cidao[j] << " ";
			}
			sum += cidao[m - 1] - cidao[0];
		}
		else    //磁头移动到序列的最大号，返回内侧扫描仍未扫描的磁道
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
	cout << "平均寻道长度： " << ave << endl;
}
/*****************************扫描调度算法*******************************/
void SCAN(int cidao[], int m)    //先要给出当前磁道号和移动臂的移动方向
{
	int k = 1;
	int now, l, r, d;
	int i, j, sum = 0;
	int a;
	char str[100];
	float ave;
	cidao = bubble(cidao, m);    //调用冒泡排序算法排序
	cout << "请输入当前的磁道号：";
D: cin >> str;  //对输入数据进行有效性判断
	a = decide(str);
	if (a == 0)
	{
		cout << "输入数据的类型错误,请重新输入！" << endl;
		goto D;
	}
	else
		now = trans(str, a);   //输入当前磁道号
	if (cidao[m - 1] <= now)    //若当前磁道号大于请求序列中最大者，则直接由外向内依次给予各请求服务,此情况同最短寻道优先
	{
		cout << "磁盘扫描序列为：";
		for (i = m - 1; i >= 0; i--)
			cout << cidao[i] << " ";
		sum = now - cidao[0];
	}
	if (cidao[0] >= now)     //若当前磁道号小于请求序列中最小者，则直接由内向外依次给予各请求服务,此情况同最短寻道优先
	{
		cout << "磁盘扫描序列为：";
		for (i = 0; i < m; i++)
			cout << cidao[i] << " ";
		sum = cidao[m - 1] - now;
	}
	if (now > cidao[0] && now < cidao[m - 1])   //若当前磁道号大于请求序列中最小者且小于最大者
	{
		while (cidao[k] < now)
		{
			k++;
		}
		l = k - 1;
		r = k;
		cout << "请输入当前移动臂的移动的方向 (1 表示向外 ，0表示向内) : ";
		cin >> d;
		if (d == 0)     //选择移动臂方向向内，则先向内扫描
		{
			cout << "磁盘扫描序列为：";
			for (j = l; j >= 0; j--)
			{
				cout << cidao[j] << " ";    //输出向内扫描的序列
			}
			for (j = r; j < m; j++)   //磁头移动到最小号，则改变方向向外扫描未扫描的磁道
			{
				cout << cidao[j] << " ";    //输出向外扫描的序列
			}
			sum = now - 2 * cidao[0] + cidao[m - 1];
		}
		else     //选择移动臂方向向外，则先向外扫描
		{
			cout << "磁盘扫描序列为：";
			for (j = r; j < m; j++)
			{
				cout << cidao[j] << " ";   //输出向外扫描的序列
			}
			for (j = l; j >= 0; j--)    //磁头移动到最大号，则改变方向向内扫描未扫描的磁道
			{
				cout << cidao[j] << " ";
			}
			sum = -now - cidao[0] + 2 * cidao[m - 1];
		}
	}
	ave = (float)(sum) / (float)(m);
	cout << endl;
	cout << "平均寻道长度： " << ave << endl;
}
/************************循环扫描调度算法*****************************/

void CSCAN(int cidao[], int m)
{
	int k = 1;
	int now, l, r;
	int i, j, sum = 0;
	int a;
	char str[100];
	float ave;
	cidao = bubble(cidao, m);    //调用冒泡排序算法排序
	cout << "请输入当前的磁道号：";
E: cin >> str;  //对输入数据进行有效性判断
	a = decide(str);
	if (a == 0)
	{
		cout << "输入数据的类型错误,请重新输入！" << endl;
		goto E;
	}
	else
		now = trans(str, a);   //输入当前磁道号
	if (cidao[m - 1] <= now)   //若当前磁道号大于请求序列中最大者，则直接将移动臂移动到最小号磁道依次向外给予各请求服务 
	{
		cout << "磁盘扫描序列为：";
		for (i = 0; i < m; i++)
			cout << cidao[i] << " ";
		sum = now - 2 * cidao[0] + cidao[m - 1];
	}
	if (cidao[0] >= now) //若当前磁道号小于请求序列中最小者，则直接由内向外依次给予各请求服务,此情况同最短寻道优先
	{
		cout << "磁盘扫描序列为：";
		for (i = 0; i < m; i++)
			cout << cidao[i] << " ";
		sum = cidao[m - 1] - now;
	}
	if (now > cidao[0] && now < cidao[m - 1])  //若当前磁道号大于请求序列中最小者且小于最大者
	{
		cout << "磁盘扫描序列为：";
		while (cidao[k] < now)    //单向反复地从内向外扫描
		{
			k++;
		}
		l = k - 1;
		r = k;
		for (j = r; j < m; j++)
		{
			cout << cidao[j] << " ";     //输出从当前磁道向外扫描的序列
		}
		for (j = 0; j < r; j++)     //当扫描完最大号磁道，磁头直接移动到最小号磁道，再向外扫描未扫描的磁道
		{
			cout << cidao[j] << " ";
		}
		sum = 2 * cidao[m - 1] + cidao[l] - now - 2 * cidao[0];
	}
	ave = (float)(sum) / (float)(m);
	cout << endl;
	cout << "平均寻道长度： " << ave << endl;
}
void main()
{
	int a;
	int c;     //菜单项
	int cidao[maxsize], cidao1[maxsize];
	int i = 0, count;
	char str[100];
	cout << "请输入磁道序列（0结束）：" << endl;
A:cin >> str;  //对输入数据进行有效性判断
	a = decide(str);
	if (a == 0)
	{
		cout << "输入数据的类型错误,请重新输入！" << endl;
		goto A;//输入错误，跳转到A，重新输入
	}
	else
	{
		cidao[i] = trans(str, a);
		cidao1[i] = trans(str, a);
	}
	i++;
	while (cidao[i - 1] != 0)
	{
		cin >> str;  //对输入数据进行有效性判断
		a = decide(str);
		if (a == 0)
			cout << "输入数据的类型错误,请重新输入！" << endl;
		else
		{
			cidao[i] = trans(str, a);
			cidao1[i] = trans(str, a);
			i++;
		}
	}
	count = i - 1;     //要访问的磁道数
	cout << "你输入的磁道序列为：";
	for (i = 0; i < count; i++)
	{
		cout << cidao[i] << " ";     //输出磁道序列
	}
	cout << endl;
	while (1)
	{
		cout << endl;
		cout << "**********************************************" << endl;
		cout << "******             系统菜单             ******" << endl;
		cout << "**********************************************" << endl;
		cout << "***                                        ***" << endl;
		cout << "**              1. 先来先服务               **" << endl;
		cout << "**                                          **" << endl;
		cout << "**              2. 最短寻道时间优先         **" << endl;
		cout << "**                                          **" << endl;
		cout << "**              3. 扫描调度                 **" << endl;
		cout << "**                                          **" << endl;
		cout << "**              4. 循环扫描                 **" << endl;
		cout << "**                                          **" << endl;
		cout << "**              5. 退出                     **" << endl;
		cout << "***                                        ***" << endl;
		cout << "**********************************************" << endl;
		cout << "**********************************************" << endl;
	G:cout << "请选择算法：";
	F:cin >> str;  //对输入数据进行有效性判断
		a = decide(str);
		if (a == 0)
		{
			cout << "输入数据的类型错误,请重新输入！" << endl;
			goto F;//输入错误，跳转到F，重新输入
		}
		else
			c = trans(str, a);
		if (c == 5)
			break;
		if (c > 5)
		{
			cout << "数据输入错误！请重新输入" << endl;
			goto G;
		}
		switch (c)
		{
		case 1:    //使用FCFS算法
			FCFS(cidao1, count);
			break;
		case 2:    //使用SSTF算法
			SSTF(cidao, count);
			break;
		case 3:    //使用SCAN算法
			SCAN(cidao, count);
			break;
		case 4:    //使用CSCAN算法
			CSCAN(cidao, count);
			break;
		}
	}
}
