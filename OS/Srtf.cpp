#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int remain_time;									//����ʣ��ִ��ʱ��
	int arrive_time;									//���̵���ʱ��
	int Tp;												//����������е�ʱ��
	int Tc;												//����ִ�ж��е�ʱ��
	int To;												//����ִ�н�����ʱ��
	int number;											//���̱��
}Process_Block;											//�������ģ��

typedef struct _Queue
{
	Process_Block PB;
	struct _Queue* next;
}_Block, * Process;										//����һ������ģ������н��

typedef struct
{
	Process head;										//����ͷָ��
	Process end;										//����βָ��
}Process_Queue;											//���̶���

Process_Queue	PQ;										//����һ��ȫ�ֶ��б���
int				t;										//ȫ��ʱ��
Process			Run_Now;							//��ǰ�������еĽ��̣���Ϊȫ�ֱ���

void InitQueue(Process_Queue PQ)
{
	PQ.head->next = NULL;
	PQ.end->next = PQ.head;
}/*��ʼ������*/
int IsEmpty(Process_Queue PQ)
{
	if (PQ.end->next == PQ.head)
		return 1;					//���пյ�����Ϊͷָ��ָ��βָ�벢��βָ��ָ��ͷָ��
	else
		return 0;
}/*�ж������Ƿ�Ϊ�ն���*/
void EnQueue(Process_Queue PQ, Process P)
{
	Process temp = (Process)malloc(sizeof(_Block));
	temp = PQ.end;
	temp->next->next = P;
	PQ.end->next = P;
}/*������в���*/
Process DeQueue(Process_Queue PQ)
{
	if (IsEmpty(PQ))
		return NULL;
	Process temp = PQ.head->next;
	PQ.head->next = temp->next;
	if (PQ.end->next == temp)
		PQ.end->next = PQ.head;
	return temp;
}/*���в���*/
Process ShortestProcess(Process_Queue PQ)
{
	if (IsEmpty(PQ))									//�������Ϊ�գ�����
	{
		if (!Run_Now)
			return NULL;
		else
			return Run_Now;
	}
	Process temp, shortest, prev;
	int min_time;
	if (Run_Now)										//�����ǰ�н�������ִ�У�
	{
		shortest = Run_Now;			  	//��ô��̽��̳�ʼ��Ϊ��ǰ����ִ�еĽ��̣�
		min_time = Run_Now->PB.remain_time;
	}
	else											//�����ǰû�н���ִ�У�
	{
		shortest = PQ.head->next;					//����̽��̳�ʼ��Ϊ�����е�һ������
		min_time = PQ.head->next->PB.remain_time;
	}
	temp = PQ.head;
	prev = temp;
	while (temp->next)
	{
		if (temp->next->PB.remain_time < min_time)	//�����ǰ���̵�ʣ��ʱ���min_time�̣�
		{
			shortest = temp->next;					//�򱣴浱ǰ���̣�
			min_time = shortest->PB.remain_time;
			prev = temp;								//����ǰ��
		}
		temp = temp->next;
	}
	if (shortest == PQ.end->next)			//������ʣ��ʱ������Ƕ��������һ�����̣�
		PQ.end->next = prev;					//����Ҫ�޸�βָ��ָ����ǰ��
	prev->next = shortest->next;				//�޸�ָ�뽫���ʣ��ʱ����̲��뵽��ͷ
	return shortest;
}/*�������ʣ��ʱ��Ľ�������ͷ*/
void Run()
{
	Run_Now->PB.remain_time--;						//ĳһʱ����������ʣ��ʱ���
	return;
}/*���к���*/
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
	int i, N, Total_Time = 0;							//Total_TimeΪ���н��̵�ִ��ʱ��֮��
	printf("�����������еĽ�����Ŀ:\n");
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
		printf("�����%d�����̵ĵ���ʱ�估ʣ��ִ��ʱ��:\n", i + 1);
		scanf("%d %d", &P[i]->PB.arrive_time, &P[i]->PB.remain_time);
	}
	for (i = 0; i < N; i++)
		Total_Time += P[i]->PB.remain_time;
	printf("\n���̰�˳����������Ϊ:\n");
	i = 0;
	int k = 0;
	for (t = 0;; t++)
	{
		if (Run_Now)										//�����ǰ�н�������ִ��
		{
			Run();
			if (t == P[i]->PB.arrive_time)				//�����ǰʱ�������н��̽���
			{
				if (P[i]->PB.remain_time < Run_Now->PB.remain_time)
				{
					temp = P[i];
					P[i] = Run_Now;
					Run_Now = temp;							//������������ж����У�
					Run_Now->PB.Tp = t;
					Run_Now->PB.Tc = t;
					wt[Run_Now->PB.number - 1] += Run_Now->PB.Tc - Run_Now->PB.Tp;
					printf("%d ", Run_Now->PB.number);
				}
				EnQueue(PQ, P[i]);					//������ǰ���н������²��������
				P[i]->PB.Tp = t;
				k++;
				i = (i + 1) > (N - 1) ? (N - 1) : (i + 1);

			}
			if (Run_Now->PB.remain_time == 0)					//�����ǰ�������н�����
			{
				Run_Now->PB.To = t;								//�������н�����ʱ��
				circle_t[Run_Now->PB.number - 1] += t - Run_Now->PB.arrive_time;
				free(Run_Now);								//������ռ��Դ�ͷŵ���
				Run_Now = NULL;								//���޸�Run_NowΪNULL
				Run_Now = ShortestProcess(PQ);	//�Ӿ��������е������ʣ��ʱ���������ͷ��
				if (!Run_Now)							//�������Ϊ�գ�תΪ�ȴ�״̬
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
		else											//�����ǰ���н���Ϊ�գ���ô
		{
			if (t == P[i]->PB.arrive_time)				//���������ʱ�н������
			{
				k++;
				EnQueue(PQ, P[i]);
				Run_Now = DeQueue(PQ);					//��ֱ�ӱ��������ж�����
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
	printf("ƽ���ȴ�ʱ����:\n%f\n", ((float)sum(wt, N)) / N);
	printf("ƽ����תʱ����:\n%f\n", ((float)sum(circle_t, N)) / N);
	return 0;
}