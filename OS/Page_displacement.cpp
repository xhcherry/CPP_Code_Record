#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define  L  20//页面走向长度最大为20
int M;        //内存块
struct Pro//定义一个结构体
{
	int num, time;
};
int Input(int m, Pro p[L])//打印页面走向状态
{
	int i, j, c;
	cout << "请输入实际页面走向长度L(15<=L<=20)：";
	do
	{
		cin >> m;
		if (m > 20 || m < 15)cout << "实际页面长度须在15～20之间;请重新输入L： ";
		else break;
	} while (1);
	j = time(NULL);//取时钟时间
	srand(j);//以时钟时间x为种子，初始化随机数发生器
	cout << "输出随机数:  ";
	for (i = 0; i < m; i++)
	{
		p[i].num = rand() % 10 + 1;//产生1到10之间的随即数放到数组p中
		p[i].time = 0;
		cout << p[i].num << " ";
	}
	cout << endl;
	return m;
}
void print(Pro* page1)//打印当前的页面
{
	Pro* page = new Pro[M];
	page = page1;
	for (int i = 0; i < M; i++)
		if (page[i].num == -1)
			cout << "   ";
		else
			cout << page[i].num << "  ";
	cout << "√" << endl;
}
int  Search(int e, Pro* page1)//寻找内存块中与e相同的块号
{
	Pro* page = new Pro[M];
	page = page1;
	for (int i = 0; i < M; i++) if (e == page[i].num) return i;//返回i值
	return -1;
}
int Max(Pro* page1)//寻找最近最长未使用的页面
{
	Pro* page = new Pro[M];
	page = page1;
	int e = page[0].time, i = 0;
	while (i < M)         //找出离现在时间最长的页面
	{
		if (e < page[i].time)  e = page[i].time;
		i++;
	}
	for (i = 0; i < M; i++) if (e == page[i].time) return i;//找到离现在时间最长的页面返回其块号
	return -1;
}
int Count(Pro* page1, int i, int t, Pro p[L])//记录当前内存块中页面离下次使用间隔长度
{
	Pro* page = new Pro[M];
	page = page1;
	int count = 0;
	for (int j = i; j < L; j++)
	{
		if (page[t].num == p[j].num)break;//当前页面再次被访问时循环结束
		else count++;//否则count+1
	}
	return count;//返回count的值 
}
int main()
{
	int c;
	int m = 0, t = 0;
	float n = 0;
	Pro p[L];
	cout << "        *********************************************         " << endl;
	cout << "        *               页式存储管理               *          " << endl;
	cout << "        *********************************************         " << endl;
	cout << "请输入可用内存页面数m(3～5): ";
	do
	{
		cin >> M;
		if (M > 5 || M < 3)
			cout << "内存块M须在3～5之间，请重新输入M： ";
		else break;
	} while (1);
	m = Input(m, p);//调用input函数，返回m值
	Pro* page = new Pro[M];
	cout << "^-^欢迎进入操作系统界面^-^" << endl;
	cout << "1:FIFO页面置换" << endl;
	cout << "2:LRU页面置换" << endl;
	cout << "3:OPT页面置换" << endl;
	cout << "4:退出" << endl;
	do {
		cout << "按1～4键操作：" << endl;
		cin >> c;
		for (int i = 0; i < M; i++)//初试化页面基本情况
		{
			page[i].num = -1;
			page[i].time = m - 1 - i;
		}
		int i = 0;
		if (c == 1)//FIFO页面置换
		{
			n = 0;
			cout << "******************************************" << endl;
			cout << endl;
			cout << "          FIFO算法页面置换情况如下:       " << endl;			cout << endl;
			cout << "******************************************" << endl;
			while (i < m)
			{
				if (Search(p[i].num, page) >= 0)     //当前页面在内存中
				{
					cout << p[i].num << "  "; //输出当前p[i].num
					cout << "不缺页" << endl;
					i++;         //i加1
				}
				else                            //当前页不在内存中
				{
					if (t == M)t = 0;
					else
					{
						n++;                    //缺页次数加1
						page[t].num = p[i].num;//把当前页面放入内存
						cout << p[i].num << "  ";
						print(page);            //打印当前页面
						t++;                    //下一个内存块
						i++;                    //指向下一个页面
					}
				}
			}
			cout << "缺页次数：" << n << "    缺页率：" << n / m << endl;
		}
		if (c == 2)//LRU页面置换
		{
			n = 0;
			cout << "******************************************" << endl;
			cout << endl;
			cout << "          LRU算法页面置换情况如下:        " << endl;
			cout << endl;
			cout << "******************************************" << endl;
			while (i < m)
			{
				int a;
				t = Search(p[i].num, page);
				if (t >= 0)//如果已在内存块中  
				{
					page[t].time = 0;//把与它相同的内存块的时间置0
					for (a = 0; a < M; a++)
						if (a != t)page[a].time++;//其它的时间加1
					cout << p[i].num << "  ";
					cout << "不缺页" << endl;
				}
				else    //如果不在内存块中
				{
					n++;           //缺页次数加1
					t = Max(page);     //返回最近最久未使用的块号赋值给t
					page[t].num = p[i].num;    //进行替换
					page[t].time = 0;          //替换后时间置为0
					cout << p[i].num << "  ";
					print(page);
					for (a = 0; a < M; a++)
						if (a != t)page[a].time++;//其它的时间加1            
				}
				i++;
			}
			cout << "缺页次数：" << n << "    缺页率：" << n / m << endl;
		}
		if (c == 3)//OPT页面置换
		{
			n = 0;
			cout << "******************************************" << endl;
			cout << endl;
			cout << "           OPT算法置换情况如下:           " << endl;
			cout << endl;
			cout << "******************************************" << endl;
			while (i < m)
			{
				if (Search(p[i].num, page) >= 0)//如果已在内存块中
				{
					cout << p[i].num << "  ";
					cout << "不缺页" << endl;
					i++;
				}
				else//如果不在内存块中
				{
					int a = 0;
					for (t = 0; t < M; t++)
						if (page[t].num == 0)a++;//记录空的内存块数
					if (a != 0) //有空内存块
					{
						int q = M;
						for (t = 0; t < M; t++)
							if (page[t].num == 0 && q > t)q = t;//把空内存块中块号最小的找出来
						page[q].num = p[i].num;
						n++;
						cout << p[i].num << "  ";
						print(page);
						i++;
					}
					else
					{
						int temp = 0, s;
						for (t = 0; t < M; t++)//寻找内存块中下次使用离现在最久的页面							
							if (temp < Count(page, i, t, p))
							{
								temp = Count(page, i, t, p);
								s = t;
							}//把找到的块号赋给s
						page[s].num = p[i].num;
						n++;
						cout << p[i].num << "  ";
						print(page);
						i++;
					}
				}
			}
			cout << "缺页次数：" << n << "    缺页率：" << n / m << endl;
		}
		if (c == 4)
		{
			cout << " ^-^再见！^-^ " << endl;
		}
	} while (c == 1 || c == 2 || c == 3 || c == 4);
	return 0;
}
