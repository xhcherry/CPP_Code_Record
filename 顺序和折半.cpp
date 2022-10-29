#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define maxsize 20//ȫ�ֶ���

#define OK 1
#define OVERFLOW -2
typedef struct {
	int key;//�ؼ���
} ElemType;
typedef struct {
	ElemType *elem;
	int length;
} sqlist;
int initList(sqlist &L) {
	L.elem=new ElemType[maxsize];//��������洢�ռ�
	if(!L.elem) exit (OVERFLOW);
	L.length=0;
	return OK;
}
void display(sqlist &L) { //�Զ��������������˳����keyֵ�����
	int i;
	for(i=0; i<L.length; i++)
		printf("%d ",L.elem[i].key);
	printf("\n");
}
void get(sqlist &L,int size) { //3.�Զ���ȡֵ��������ѭ������Ϊelem[i].keyȡֵ��
	for(int i=0; i<size; i++) {
		scanf("%d",&L.elem[i].key);
		L.length++;
	}
}
int search(sqlist L,int key) { //�Զ���˳����Һ�������˳���L��˳�������ؼ��ֵ���key������Ԫ�أ����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0.
	clock_t start1,finish1;
	start1=clock();
	for(int i=L.length; i>=1; --i)
		if(L.elem[i].key==key)  return i;
		finish1=clock();
		double Cost_time1 = (double)(finish1-start1)/CLOCKS_PER_SEC;
		printf("˳����������ѵ�ʱ��Ϊ��%d ��",Cost_time1);
	return 0;
}
int search_Bin(sqlist L,int key) { //6.�Զ����۰���Һ������ò��������ֵ��lowΪ1��highΪ������lowС�ڵ���highʱ��midȡlow��high���м�ֵ��������ֵkey���м�λ�ü�¼�Ĺؼ��ֽ��бȽϣ������ҳɹ�����mid����������������м�λ�ü�¼����Էֳ�ǰ�������ӱ����key���м�λ�ü�¼�Ĺؼ���С����highȡΪmid-1,����lowȡΪmid+1��ѭ��������˵����������Ϊ�գ������ʧ�ܣ�����0.
	clock_t start2,finish2;
	start2=clock();
	int low=1,high=L.length,mid;
	while(low<=high) {
		mid=(low+high)/2;
		if(key==L.elem[mid].key) return mid;
		else if(key<L.elem[mid].key)  high=mid-1;
		else  low=mid+1;
	}
	finish2=clock();
	double Cost_time2 = (double)(finish2-start2)/CLOCKS_PER_SEC;
	printf("�۰���������ѵ�ʱ��Ϊ��%d ��",Cost_time2);
	return 0;
}


int main() {
	int m,x,y;
	int m1,x1,y1;
	sqlist L,M;
	initList(L);
	initList(M);
	printf("������˳���ĳ���(˳�����)\n");
	scanf("%d",&m);
	printf("������һ������\n");
	get(L,m);
	printf("����Ϊ�����˳���(˳�����)\n");
	display(L);
	printf("������������ҵ�Ԫ��(˳�����)\n");
	scanf("%d",&x);
	y=search(L,x);
	printf("����˳����ҷ��ֲ��ҵ�Ԫ���ڵ�%dλ\n",y+1);
	printf("������˳���ĳ���(�۰����)\n");
	scanf("%d",&m1);
	printf("�밴�ɴ�С����һ������(�۰����)\n");
	get(M,m1);
	printf("����Ϊ�����˳���(�۰����)\n");
	display(M);
	printf("������������ҵ�Ԫ��(�۰����)\n");
	scanf("%d",&x1);
	y1=search_Bin(M,x1);
	printf("�����۰���ҷ��ֲ��ҵ�Ԫ���ڵ�%dλ\n",y1+1);
	
	return 0;



}

