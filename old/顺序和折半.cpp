#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define maxsize 20//全局定义

#define OK 1
#define OVERFLOW -2
typedef struct {
	int key;//关键字
} ElemType;
typedef struct {
	ElemType *elem;
	int length;
} sqlist;
int initList(sqlist &L) {
	L.elem=new ElemType[maxsize];//分配数组存储空间
	if(!L.elem) exit (OVERFLOW);
	L.length=0;
	return OK;
}
void display(sqlist &L) { //自定义输出函数，将顺序表的key值输出。
	int i;
	for(i=0; i<L.length; i++)
		printf("%d ",L.elem[i].key);
	printf("\n");
}
void get(sqlist &L,int size) { //3.自定义取值函数利用循环依次为elem[i].key取值，
	for(int i=0; i<size; i++) {
		scanf("%d",&L.elem[i].key);
		L.length++;
	}
}
int search(sqlist L,int key) { //自定义顺序查找函数，在顺序表L中顺序查找其关键字等于key的数据元素，若找到，则函数值为该元素在表中的位置，否则为0.
	clock_t start1,finish1;
	start1=clock();
	for(int i=L.length; i>=1; --i)
		if(L.elem[i].key==key)  return i;
		finish1=clock();
		double Cost_time1 = (double)(finish1-start1)/CLOCKS_PER_SEC;
		printf("顺序查找所花费的时间为：%d 秒",Cost_time1);
	return 0;
}
int search_Bin(sqlist L,int key) { //6.自定义折半查找函数，置查找区间初值，low为1，high为表长；当low小于等于high时，mid取low和high的中间值，将给定值key与中间位置记录的关键字进行比较，若查找成功返回mid，若不相等则利用中间位置记录将表对分成前后两个子表。如果key比中间位置记录的关键字小，则high取为mid-1,否则low取为mid+1；循环结束，说明查找区间为空，则查找失败，返回0.
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
	printf("折半查找所花费的时间为：%d 秒",Cost_time2);
	return 0;
}


int main() {
	int m,x,y;
	int m1,x1,y1;
	sqlist L,M;
	initList(L);
	initList(M);
	printf("请输入顺序表的长度(顺序查找)\n");
	scanf("%d",&m);
	printf("请输入一批数据\n");
	get(L,m);
	printf("以下为输入的顺序表(顺序查找)\n");
	display(L);
	printf("请输入你想查找的元素(顺序查找)\n");
	scanf("%d",&x);
	y=search(L,x);
	printf("经过顺序查找发现查找的元素在第%d位\n",y+1);
	printf("请输入顺序表的长度(折半查找)\n");
	scanf("%d",&m1);
	printf("请按由大到小输入一批数据(折半查找)\n");
	get(M,m1);
	printf("以下为输入的顺序表(折半查找)\n");
	display(M);
	printf("请输入你想查找的元素(折半查找)\n");
	scanf("%d",&x1);
	y1=search_Bin(M,x1);
	printf("经过折半查找发现查找的元素在第%d位\n",y1+1);
	
	return 0;



}

