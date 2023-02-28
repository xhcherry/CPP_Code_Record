#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int remain_time;									//进程剩余执行时间
	int arrive_time;									//进程到达时间
	int Tp;												//进入就绪队列的时间
	int Tc;												//进入执行队列的时间
	int To;												//进程执行结束的时间
	int number;											//进程编号
}Process_Block;											//定义进程模块

typedef struct _Queue
{
	Process_Block PB;
	struct _Queue* next;
}_Block, * Process;										//定义一个进程模块队列中结点

typedef struct
{
	Process head;										//队列头指针
	Process end;										//队列尾指针
}Process_Queue;											//进程队列

Process_Queue	PQ;										//定义一个全局队列变量
int				t;										//全局时间
Process			Run_Now;							//当前正在运行的进程，作为全局变量

void InitQueue(Process_Queue PQ)
{
	PQ.head->next = NULL;
	PQ.end->next = PQ.head;
}/*初始化队列*/
int IsEmpty(Process_Queue PQ)
{
	if (PQ.end->next == PQ.head)
		return 1;					//队列空的条件为头指针指向尾指针并且尾指针指向头指针
	else
		return 0;
}/*判定队列是否为空队列*/
void EnQueue(Process_Queue PQ, Process P)
{
	Process temp = (Process)malloc(sizeof(_Block));
	temp = PQ.end;
	temp->next->next = P;
	PQ.end->next = P;
}/*插入队列操作*/
Process DeQueue(Process_Queue PQ)
{
	if (IsEmpty(PQ))
		return NULL;
	Process temp = PQ.head->next;
	PQ.head->next = temp->next;
	if (PQ.end->next == temp)
		PQ.end->next = PQ.head;
	return temp;
}/*出列操作*/
Process ShortestProcess(Process_Queue PQ)
{
	if (IsEmpty(PQ))									//如果队列为空，返回
	{
		if (!Run_Now)
			return NULL;
		else
			return Run_Now;
	}
	Process temp, shortest, prev;
	int min_time;
	if (Run_Now)										//如果当前有进程正在执行，
	{
		shortest = Run_Now;			  	//那么最短进程初始化为当前正在执行的进程，
		min_time = Run_Now->PB.remain_time;
	}
	else											//如果当前没有进程执行，
	{
		shortest = PQ.head->next;					//则最短进程初始化为队列中第一个进程
		min_time = PQ.head->next->PB.remain_time;
	}
	temp = PQ.head;
	prev = temp;
	while (temp->next)
	{
		if (temp->next->PB.remain_time < min_time)	//如果当前进程的剩余时间比min_time短，
		{
			shortest = temp->next;					//则保存当前进程，
			min_time = shortest->PB.remain_time;
			prev = temp;								//及其前驱
		}
		temp = temp->next;
	}
	if (shortest == PQ.end->next)			//如果最短剩余时间进程是队列中最后一个进程，
		PQ.end->next = prev;					//则需要修改尾指针指向其前驱
	prev->next = shortest->next;				//修改指针将最短剩余时间进程插入到队头
	return shortest;
}/*调度最短剩余时间的进程至队头*/
void Run()
{
	Run_Now->PB.remain_time--;						//某一时间运行它的剩余时间减
	return;
}/*运行函数*/
void Wait()
{
	return;
}
int sum(int array[], int n)
{
	int i, sum = 0;
	for (i = 0; i < n; i++)
		sum += array[i];
	return sum;
}
int main()
{
	PQ.head = (Process)malloc(sizeof(_Block));
	PQ.end = (Process)malloc(sizeof(_Block));
	Run_Now = (Process)malloc(sizeof(_Block));
	Run_Now = NULL;
	InitQueue(PQ);
	int i, N, Total_Time = 0;							//Total_Time为所有进程的执行时间之和
	printf("请输入计算机中的进程数目:\n");
	scanf("%d", &N);
	Process* P, temp;
	P = (Process*)malloc(N * sizeof(Process));
	int* wt, * circle_t;
	wt = (int*)malloc(N * sizeof(int));
	circle_t = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++)
	{
		P[i] = (Process)malloc(sizeof(_Block));
		P[i]->PB.number = i + 1;
		P[i]->next = NULL;
		wt[i] = 0;
		circle_t[i] = 0;
		printf("输入第%d个进程的到达时间及剩余执行时间:\n", i + 1);
		scanf("%d %d", &P[i]->PB.arrive_time, &P[i]->PB.remain_time);
	}
	for (i = 0; i < N; i++)
		Total_Time += P[i]->PB.remain_time;
	printf("\n进程按顺序运行依次为:\n");
	i = 0;
	int k = 0;
	for (t = 0;; t++)
	{
		if (Run_Now)										//如果当前有进程正在执行
		{
			Run();
			if (t == P[i]->PB.arrive_time)				//如果当前时间正好有进程进入
			{
				if (P[i]->PB.remain_time < Run_Now->PB.remain_time)
				{
					temp = P[i];
					P[i] = Run_Now;
					Run_Now = temp;							//则调度它至运行队列中，
					Run_Now->PB.Tp = t;
					Run_Now->PB.Tc = t;
					wt[Run_Now->PB.number - 1] += Run_Now->PB.Tc - Run_Now->PB.Tp;
					printf("%d ", Run_Now->PB.number);
				}
				EnQueue(PQ, P[i]);					//并将当前运行进程重新插入队列中
				P[i]->PB.Tp = t;
				k++;
				i = (i + 1) > (N - 1) ? (N - 1) : (i + 1);

			}
			if (Run_Now->PB.remain_time == 0)					//如果当前进程运行结束，
			{
				Run_Now->PB.To = t;								//进程运行结束的时间
				circle_t[Run_Now->PB.number - 1] += t - Run_Now->PB.arrive_time;
				free(Run_Now);								//则将它所占资源释放掉，
				Run_Now = NULL;								//并修改Run_Now为NULL
				Run_Now = ShortestProcess(PQ);	//从就绪队列中调出最短剩余时间进程至队头，
				if (!Run_Now)							//如果队列为空，转为等待状态
				{
					if (IsEmpty(PQ) && k >= N) break;
					Wait();
					continue;

				}
				else
				{
					Run_Now->PB.Tc = t;
					wt[Run_Now->PB.number - 1] += Run_Now->PB.Tc - Run_Now->PB.Tp;
					printf("%d ", Run_Now->PB.number);
				}
			}
		}
		else											//如果当前运行进程为空，那么
		{
			if (t == P[i]->PB.arrive_time)				//如果正好这时有进程入队
			{
				k++;
				EnQueue(PQ, P[i]);
				Run_Now = DeQueue(PQ);					//则直接被调入运行队列中
				Run_Now->PB.Tp = t;
				Run_Now->PB.Tc = t;
				printf("%d ", Run_Now->PB.number);
				i = (i + 1) > (N - 1) ? (N - 1) : (i + 1);
			}
			else
			{
				Wait();
				continue;
			}
		}

	}
	printf("\n");
	printf("平均等待时间是:\n%f\n", ((float)sum(wt, N)) / N);
	printf("平均周转时间是:\n%f\n", ((float)sum(circle_t, N)) / N);
	return 0;
}