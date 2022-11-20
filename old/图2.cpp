//ͼ�Ĳ���
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_NUM 20

typedef int Status;
typedef int QElemType;
typedef char VexType;

typedef  struct EdgeNode {
	int adjvex;            //�����λ��
	struct EdgeNode *next;//��һ�������λ��
} EdgeNode,*EdgeLink; //�����ڽӱ�

typedef struct Vex {
	VexType data;      //���������
	EdgeNode *firstEdge;//ָ���һ���ڽڵ��ָ��
} VexNode,AdjList[MAX_NUM]; //�����������飻 //�ṹ����

typedef struct {
	AdjList adjlist;
	int vexNum,edgeNum;//�������ͱߵ���Ŀ
} ALGraph; //ͼ���ڽӱ�洢�ṹ

//���еĴ洢�ṹ ͼ�Ĺ������

typedef struct Node {
	QElemType data;
	struct Node *next;

} QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;

//��ʼ������

Status InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	if(Q->front) {
		Q->front->next = NULL;
		return OK;
	}
}


//�ж��Ƿ�Ϊ��

Status IsEmpty(LinkQueue Q) {
	if(Q.front->next == NULL) {
		return TRUE;
	} else return FALSE;
}
//���

Status EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(p) {
		p->data = e;
		p->next= NULL;
		Q->rear->next = p;
		Q->rear = p;
		return OK;
	} else return ERROR;

}

//����(����ͷ���)

Status DeQueue(LinkQueue *Q, QElemType *e) {
	QueuePtr q;
	if(Q->front==Q->rear)return ERROR;
	q = Q->front->next;
	*e = q->data;
	Q->front->next = q->next;
	if(Q->rear = q) {
		Q->rear = Q->front;
	}
	free(q);
	return OK;

}


//����ͼ���ڽӱ��ʾ��(����ͼ)
Status CreateGraph(ALGraph *G) {

	int i,j,k;
	EdgeLink e;
	printf("�����붥�����ͱ���\n");
	scanf("%d %d",&G->vexNum,&G->edgeNum);
//	scanf("%d",&G->edgeNum);
	getchar();//�Ե��س�
	//����������������
	printf("����������������:\n");
	for(i=0; i<G->vexNum; i++) { //��ʼ����������
		scanf("%c",&G->adjlist[i].data);
		if(G->adjlist[i].data=='\n') {
			i--;
			continue;
		}
		G->adjlist[i].firstEdge=NULL;
	}
	//
	printf("�����붥�㣨vi,vj)�߶�������\n");

	for(k=0; k<G->edgeNum; k++) {
		scanf("%d %d",&i,&j);
		//	scanf("%d",&j);
		e = (EdgeLink)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjlist[i].firstEdge ;
		G->adjlist[i].firstEdge = e;
		e = (EdgeLink)malloc(sizeof(EdgeNode));
		e->adjvex=i;
		e->next = G->adjlist[j].firstEdge;
		G->adjlist[j].firstEdge = e;

	}
	return OK;
}
int visited[MAX_NUM];    //���ڼ�¼����״̬
//* �ݹ�ӵ�i�����������ȱ���ͼ
void DFS(ALGraph G, int i) {
	EdgeLink e;
	visited[i] = TRUE;
	printf("%c",G.adjlist[i].data);
	e = G.adjlist[i].firstEdge;
	while(e) {
		if(!visited[e->adjvex]) {
			DFS(G,e->adjvex);
		}
		e =e->next;
	}
}
//���
Status BFSTraverse(ALGraph G) {
	int i;
	EdgeLink p;
	LinkQueue Q;
	InitQueue(&Q);
	for(i=0; i<MAX_NUM; i++) {
		visited[i] = FALSE;
	}
	for(i=0; i<G.vexNum; i++) {
		if(!visited[i]) {
			visited[i] = TRUE;
			printf("%c",G.adjlist[i].data);
			EnQueue(&Q, i);
			while(!IsEmpty(Q)) {
				DeQueue(&Q, &i);
				p = G.adjlist[i].firstEdge;
				while(p) {
					if(!visited[p->adjvex]) {
						visited[p->adjvex] = TRUE;
						printf("%c",G.adjlist[p->adjvex].data);
						EnQueue(&Q, p->adjvex);

					}
					p = p->next;
				}
			}
		}
	}
	return OK;
}
int main() {
	ALGraph G;
	CreateGraph(&G);
	printf("������ȱ���:");
	DFS(G,0);
	printf("\n������ȱ���:");
	BFSTraverse(G);
	printf("\n");
}

