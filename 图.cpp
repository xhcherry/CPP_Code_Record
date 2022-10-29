#include<stdio.h>
#include<stdlib.h>
typedef struct ArcNode
{
	int adjvex;  //�ڽӵ���
	struct ArcNode *nextarc; //ָ����һ���ڽӵ��ָ����
	int weight;
} ArcNode; //�߽��
typedef struct VNode {
	char vertex;   //������
	ArcNode *firstarc;//��һ���ߵ�ָ��
} VNode,AdjList[10]; //����������
typedef struct {
	AdjList adjlist;
	int vexnum,arcnum;
} ALGraph;
//ͼ���ڽӾ���
typedef struct {
	int adj;
} AdjMatrix[10][10];
typedef struct {
	int vexs[10];
	AdjMatrix arcs;
	int vexnum,arcnum;
} MGraph;
int LocateVex(ALGraph &G,char v) { //���Ҷ�����Ϣ
	int k,j=0;
	for(k=0; k<G.vexnum; k++)
		if(G.adjlist[k].vertex==v) {
			j=k;
			break;
		}
	return j;
}
void CreateALGraph(ALGraph &G) {
	//��������ͼ���ڽӱ��ʾ
	int i,j,k,w;
	char v1,v2;
	ArcNode *s;
	printf("�����붥�����ͱ�����vexnum,arcnum��:");
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	for(i=0; i<G.vexnum; i++) {
		//���������
		getchar();
		printf("�������%d������Ϣ��",i+1);
		scanf("%c",&G.adjlist[i].vertex);//���붥����Ϣ
		G.adjlist[i].firstarc=NULL;//�߱���Ϊ�ձ�
	}
	for(k=0; k<G.arcnum; k++)
	{
		//�����߱�
		getchar();
		printf("�������%d�ߵĶ������źͱߵ�Ȩֵ��v1,v2,w����",k+1);
		scanf("%c,%c,%d",&v1,&v2,&w);
		j=LocateVex(G,v2);
		i=LocateVex(G,v1);
		s=(ArcNode*)malloc(sizeof(ArcNode)); //���ɱ߱���
		s->adjvex=j;//�ڽӵ����Ϊj
		s->weight=w;//Ȩֵ
		s->nextarc=G.adjlist[i].firstarc;
		G.adjlist[i].firstarc=s; //���½��*s���붥��vi�ı߱�ͷ��
		//��ͼΪ����ͼ�����������ľ���룬��ͼΪ����ͼ��ע��������ľ����
		s=(ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex=i;
		s->weight=w;
		s->nextarc=G.adjlist[j].firstarc;
		G.adjlist[j].firstarc=s;
	}
}
bool visited[20];
int v;
void DFS(ALGraph &G,int v)//��ȱ������
{
	visited[v]=true;
	printf("%c ",G.adjlist[v].vertex);
	ArcNode *w;
	for(w=G.adjlist[v].firstarc; w!=NULL; w=w->nextarc)
		if(!visited[w->adjvex])
			DFS(G,w->adjvex);
}
void DFSTraverse(ALGraph &G)//ͼ����ȱ�������
{
	for(v=0; v<G.vexnum; v++)
		visited[v]=false;
	for(v=0; v<G.vexnum; v++)
		if(!visited[v])
			DFS(G,v);
}
//����
typedef struct QNode
{
	int data;
	struct QNode *next;
} QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;
void InitQueue(LinkQueue &Q)//����һ���ն��� Q
{
	Q.rear=Q.front=(QueuePtr)malloc(sizeof(QNode));
	Q.front->next=NULL;
}
void EnQueue(LinkQueue &Q,int e)//���
{
	QNode *p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}
void DeQueue(LinkQueue &Q,int &e2)
{
	//����
	QNode *p;
	p=Q.front->next;
	e2=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
}
bool visited1[20];

void BFSTraverse(ALGraph &G)//ͼ�Ĺ�����ȱ���
{

	for(v=0; v<G.vexnum; v++)
		visited1[v]=false;
	LinkQueue Q;
	InitQueue(Q);
	for(v=0; v<G.vexnum; v++)
		if(!visited1[v])
		{
			visited1[v]=true;
			printf("%c ",G.adjlist[v].vertex);
			EnQueue(Q,v);
			int u;
			ArcNode *w;
			while(Q.front!=Q.rear)
			{
				DeQueue(Q,u);
				for(w=G.adjlist[u].firstarc; w!=NULL; w=w->nextarc)
					if(!visited1[w->adjvex])
					{
						visited1[w->adjvex]=true;
						printf("%c ",G.adjlist[w->adjvex].vertex);
						EnQueue(Q,w->adjvex);
					}
			}
		}
}
void display(ALGraph &G)//���ͼ�Ķ�����Ϣ
{
	printf("�������ڽӱ�λ��\n");
	int i;
	for(i=0; i<G.vexnum; i++)
	{
		if(G.adjlist[i].firstarc!=NULL)
		{
			printf("%c->",G.adjlist[i].vertex);
			ArcNode *p;
			p=G.adjlist[i].firstarc;
			while(p!=NULL)
			{
				printf("%d->",p->adjvex);
				p=p->nextarc;
			}
			printf("NULL\n");
		}
		else
		{
			printf("%c->NULL\n",G.adjlist[i].vertex);
		}
	}
}

int LocateVex(MGraph &G,int v)
{
	int k,j=0;
	for(k=0; k<G.vexnum; k++)
		if(G.vexs[k]==v)
		{
			j=k;
			break;
		}
	return j;
}
void Create(MGraph &G)
{
	int i,j,k;
	int v1=0,v2=0,w=0;
	printf("������ͼ�Ķ�������");
	scanf("%d",&G.vexnum);
	printf("������ͼ�ı�����");
	scanf("%d",&G.arcnum);
	for(i=0; i<G.vexnum; i++)
		G.vexs[i]=i+1;
	for(i=0; i<G.vexnum; i++)
		for(j=0; j<G.vexnum; j++)
			G.arcs[i][j].adj=0;
	for(k=0; k<G.arcnum; k++)
	{
		printf("������һ���������Ķ���v1,v2��Ȩֵ��v1,v2,w��:");
		scanf("%d,%d,%d",&v1,&v2,&w);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j].adj=w;
	}
}
void display(MGraph &G)
{

	int i,j;
	for(i=0; i<G.vexnum; i++)
	{
		for(j=0; j<G.vexnum; j++)
			printf("%d",G.arcs[i][j].adj);
		printf("\n");
	}
}

int main()
{
	int z;
	printf("������ѡ��:\n-1-����ͼ���ڽӾ���\n-2-����ͼ���ڽӱ�\n");
	scanf("%d",&z);
	if(z==1)
	{
		MGraph G;
		Create(G);
		display(G);
		scanf("%d",&z);
	}
	if(z==2)
	{
		ALGraph G;
		CreateALGraph(G);//��������ͼ�ڽӱ�
		display(G);//���ͼ�ĵĶ�����Ϣ
		printf("\n\n");
		printf("ͼ����ȱ���Ϊ��\n");
		DFSTraverse(G);
		printf("\n");
		printf("\n\n");
		printf("ͼ�Ĺ�ȱ���Ϊ��");
		BFSTraverse(G);
		printf("\n");
	}
}

