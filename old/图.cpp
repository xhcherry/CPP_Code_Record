#include<stdio.h>
#include<stdlib.h>
typedef struct ArcNode
{
	int adjvex;  //邻接点域
	struct ArcNode *nextarc; //指向下一个邻接点的指针域
	int weight;
} ArcNode; //边结点
typedef struct VNode {
	char vertex;   //顶点域
	ArcNode *firstarc;//第一条边的指针
} VNode,AdjList[10]; //顶点结点向量
typedef struct {
	AdjList adjlist;
	int vexnum,arcnum;
} ALGraph;
//图的邻接矩阵
typedef struct {
	int adj;
} AdjMatrix[10][10];
typedef struct {
	int vexs[10];
	AdjMatrix arcs;
	int vexnum,arcnum;
} MGraph;
int LocateVex(ALGraph &G,char v) { //查找顶点信息
	int k,j=0;
	for(k=0; k<G.vexnum; k++)
		if(G.adjlist[k].vertex==v) {
			j=k;
			break;
		}
	return j;
}
void CreateALGraph(ALGraph &G) {
	//建立无向图的邻接表表示
	int i,j,k,w;
	char v1,v2;
	ArcNode *s;
	printf("请输入顶点数和边数（vexnum,arcnum）:");
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	for(i=0; i<G.vexnum; i++) {
		//建立顶点表
		getchar();
		printf("请输入第%d顶点信息：",i+1);
		scanf("%c",&G.adjlist[i].vertex);//读入顶点信息
		G.adjlist[i].firstarc=NULL;//边表置为空表
	}
	for(k=0; k<G.arcnum; k++)
	{
		//建立边表
		getchar();
		printf("请输入第%d边的顶点对序号和边的权值（v1,v2,w）：",k+1);
		scanf("%c,%c,%d",&v1,&v2,&w);
		j=LocateVex(G,v2);
		i=LocateVex(G,v1);
		s=(ArcNode*)malloc(sizeof(ArcNode)); //生成边表结点
		s->adjvex=j;//邻接点序号为j
		s->weight=w;//权值
		s->nextarc=G.adjlist[i].firstarc;
		G.adjlist[i].firstarc=s; //将新结点*s插入顶点vi的边表头部
		//若图为无向图则加上下面的四句代码，若图为有向图则注释下面的四句代码
		s=(ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex=i;
		s->weight=w;
		s->nextarc=G.adjlist[j].firstarc;
		G.adjlist[j].firstarc=s;
	}
}
bool visited[20];
int v;
void DFS(ALGraph &G,int v)//深度遍历输出
{
	visited[v]=true;
	printf("%c ",G.adjlist[v].vertex);
	ArcNode *w;
	for(w=G.adjlist[v].firstarc; w!=NULL; w=w->nextarc)
		if(!visited[w->adjvex])
			DFS(G,w->adjvex);
}
void DFSTraverse(ALGraph &G)//图的深度遍历操作
{
	for(v=0; v<G.vexnum; v++)
		visited[v]=false;
	for(v=0; v<G.vexnum; v++)
		if(!visited[v])
			DFS(G,v);
}
//队列
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
void InitQueue(LinkQueue &Q)//构造一个空队列 Q
{
	Q.rear=Q.front=(QueuePtr)malloc(sizeof(QNode));
	Q.front->next=NULL;
}
void EnQueue(LinkQueue &Q,int e)//入队
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
	//出队
	QNode *p;
	p=Q.front->next;
	e2=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
}
bool visited1[20];

void BFSTraverse(ALGraph &G)//图的广度优先遍历
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
void display(ALGraph &G)//输出图的顶点信息
{
	printf("建立的邻接表位：\n");
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
	printf("请输入图的顶点数：");
	scanf("%d",&G.vexnum);
	printf("请输入图的边数：");
	scanf("%d",&G.arcnum);
	for(i=0; i<G.vexnum; i++)
		G.vexs[i]=i+1;
	for(i=0; i<G.vexnum; i++)
		for(j=0; j<G.vexnum; j++)
			G.arcs[i][j].adj=0;
	for(k=0; k<G.arcnum; k++)
	{
		printf("请输入一条边依附的顶点v1,v2及权值（v1,v2,w）:");
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
	printf("请输入选择:\n-1-建立图的邻接矩阵\n-2-建立图的邻接表\n");
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
		CreateALGraph(G);//建立无向图邻接表
		display(G);//输出图的的顶点信息
		printf("\n\n");
		printf("图的深度遍历为：\n");
		DFSTraverse(G);
		printf("\n");
		printf("\n\n");
		printf("图的广度遍历为：");
		BFSTraverse(G);
		printf("\n");
	}
}

