#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>
#include <conio.h>

#define MAXNUM 100    /*医生信息表可能达到的最大长度*/

typedef struct Node { //节点类型定义
	int data;    //数据域
	struct Node* next;  //指针域
} Node,*LinkList;

typedef struct {      /*医生信息定义*/
	char dtno[10];		/*科室*/
	char dtname[20];		/*医生*/
	char time[10];		/*时间段*/
	int totalnum; 			/*总号数*/
	LinkList p;
} DOCTOR;

typedef struct {
	DOCTOR dt[MAXNUM];      /*通过类型定义变量，科室及医生信息数组*/
	int TotalDoctor;       /*最后一个元素在数组中的位置，即下标，空表为-1 */
} DoctorList;              /*医生信息表的顺序存储结构类型为DoctorList */
DoctorList  doctor_list;     /*定义科室及医生信息顺序表*/

void search_queue(LinkList L);

void InitList(LinkList *L) { //初始化单链表
	*L=(LinkList)malloc(sizeof(Node));  //建立头结点，为头结点分配存储空间
	(*L)->next=NULL;
	(*L)->data=0;     //链表的头结点做标记
}

LinkList p1,p2,p3,p4,p5,p6,p7,p8;   //8个链表对应八个头指针


void ReadList(LinkList L, FILE *p) {
	LinkList tail=L;
	int temp;
	char temp2;
	fread(&temp2, sizeof(char), 1, p);
//	InitList(L);
	if(temp2=='*')
		while (fread(&temp, sizeof(int), 1, p)) { //每次读出一个Elemtype 型的temp通过尾插法创建链表
			//	printf("%d",temp);getch();
			LinkList node = (LinkList)malloc(sizeof(Node));
			node->data = temp;
			tail->next = node;
			tail = node;
			tail->next = NULL;
		}
}

void ReadData() {	//将硬盘doctordata文件中的数据读入内存顺序表doctor_list中
	FILE *fp;
	int i;
	if ((fp=fopen("doctordata.txt","rb"))==NULL) {
		printf("Can not open the file!\n");
		return;
	}

	fread(&doctor_list.TotalDoctor,sizeof(int),1,fp);
//	printf("%d",doctor_list.TotalDoctor);getch();
	for(i=0; i<doctor_list.TotalDoctor; i++) {
		fread(&doctor_list.dt[i],sizeof(DOCTOR),1,fp);
		InitList(&doctor_list.dt[i].p);
		ReadList(doctor_list.dt[i].p,fp);
	}

	fclose(fp);
}


void WriteList(LinkList L, FILE *p) {

	LinkList head=NULL;
	head = L->next;
	char b='#';
	char c='*';
	if(head==NULL)
		fwrite(&b,sizeof(char), 1, p);
	else {
		fwrite(&c,sizeof(char), 1, p);
		while (head) {
			//printf("%d",head->data);
			fwrite(&head->data,sizeof(int), 1, p);
			head = head->next;
		}
	}

}

void WriteData() {	//将内存中顺序表doctor_list的变化，存入硬盘文件doctordata中
	FILE *fp;
	int i;
	if ( (fp=fopen("doctordata.txt","wb"))==NULL) {
		printf("Can not open the file!\n");
		return;
	}

	fwrite(&doctor_list.TotalDoctor , sizeof(int) , 1 ,fp);
	for(i=0; i<doctor_list.TotalDoctor; i++) {
		fwrite(&doctor_list.dt[i],sizeof(DOCTOR), 1,fp);
		WriteList(doctor_list.dt[i].p,fp);
	}

	fclose(fp);
}


void  Locate(DoctorList L,char e[]) {      /*查找医生信息*/
	int i=0 ;      /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	for(i=0; i<=L.TotalDoctor; i++) {
		if(strcmp(L.dt[i].dtname,e)==0) {
			printf("\n\n\n\t\t--------------------------------------------------\n");
			printf("\t\t%-8s%-20s%-10s%-8s\n",
			       "科室","医生","时间段","总号数");
			printf("\t\t--------------------------------------------------\n");
			printf("\t\t%-8s%-20s%-10s%-8d\n", doctor_list.dt[i].dtno, doctor_list.dt[i].dtname,
			       doctor_list.dt[i].time, doctor_list.dt[i].totalnum);  /*若找到，则输出该医生信息*/
			printf("\t\t--------------------------------------------------\n");
		} else
			break;
	}
	if(i>L.TotalDoctor) printf("查无此人！");  /*若没找到，则输出无*/

}

void InsList(DoctorList *L,int i,DOCTOR e) { /*插入医生信息*/
	int k;
	if( (i<1)||(i>L->TotalDoctor+2) ) {   /*首先判断插入位置是否合法*/
		printf("插入位置i值不合法\n");
		printf("信息插入失败！\n");
	}
	if(L->TotalDoctor>=MAXNUM-1) {
		printf("表已满无法插入\n");
		printf("信息插入失败！\n");
	}

	for(k=L->TotalDoctor-1; k>=i-1; k--)   /*其后元素后移*/
		L->dt[k+1]=L->dt[k];
	L->dt[i-1]=e; /*数据插入，第i个元素的下标为i-1*/
	InitList(&L->dt[i-1].p);
	L->TotalDoctor++;
	printf("信息插入成功！\n");
	WriteData();
}

void  DelList(DoctorList *L,int i,DOCTOR *e)     /*删除*/
/*在顺序表L中删除第i个数据元素，并用指针参数e返回其值*/
{
	int k;
	if((i<1)||(i>L->TotalDoctor+1)) {
		printf("删除位置不合法！\n");
		printf("信息删除失败！\n");
	}
	*e= L->dt[i-1];      /* 将删除的元素存放到e所指向的变量中*/
	for(k=i; k<L->TotalDoctor; k++)
		L->dt[k-1]=L->dt[k];     /*将后面的元素依次前移*/
	L->TotalDoctor--;
	printf("信息删除成功！\n");
	WriteData();
}


int showx(DoctorList L) {	//打印清单(查找页面）
	int i,x;
	printf("\t\t%-8s%-20s%-10s%-8s\n",
	       "科室","医生","时间段","总号数");
	printf("\t\t--------------------------------------------------\n");
	for (i=0; i<L.TotalDoctor; i++)
		printf("\t\t%-8s%-20s%-10s%-8d\n", L.dt[i].dtno, L.dt[i].dtname,
		       L.dt[i].time, L.dt[i].totalnum);
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t0. 退出\n");
	printf("\t\t1. 查找\n");
	printf("\t\t2. 插入\n");
	printf("\t\t3. 删除\n");
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t请输入要选择的功能编号：");
	scanf("%d",&x);
	return x;
}

void doctorlist() {    /*查看科室及医生信息功能*/
	int i,w,x;
	char a[10];
	DOCTOR add;
	DoctorList *l;
	l=&doctor_list;
	do {
		system("cls");
		x=showx(doctor_list);
		switch(x) {	//根据选择项调用对应的函数
			case 0:
				break;
			case 1:
				system("cls");
				printf("输入要查找医生的姓名：");
				scanf("%s",a);
				Locate(doctor_list,a);    /*查找*/
				getch();
				break;
			case 2:
				system("cls");          /*插入*/
				printf("请输入信息要插入的位置：");
				scanf("%d",&w);
				printf("请输入要插入的信息，科室、医生姓名、时间段、总号数：");
				scanf("%s %s %s %d",add.dtno,add.dtname,add.time,&add.totalnum);
				InsList(l,w,add);
				getch();
				break;
			case 3:
				system("cls");        /*删除*/
				printf("请输入要删除信息所在的位置：");
				scanf("%d",&w);
				DOCTOR E,*e;
				e=&E;
				DelList(l,w,e);
				getch();
				break;
		}
	} while(x);
}


int  ListLength_L(LinkList L) { //求表长
	//返回L中数据元素个数
	LinkList p;
	int i;
	p=L->next;  //p指向第一个结点
	i=0;
	while(p) {
		//遍历单链表,统计结点数
		i++;
		p=p->next;
	}
	return i;
}

Node*  ListLength_p(LinkList L) { //求表尾结点
	//返回L中数据元素个数
	LinkList p;
	p=L;  //p指向第一个结点
	while(p->next!=NULL) {
		//遍历单链表
		p=p->next;
	}
	return p;
}

void CreateFromTail(LinkList L,DoctorList Q,int x) {  //排号 (判断是否还有剩余号码，显示排号成功或失败）
	Node *r,*s;
	int a;   //a为链表L的长度
	r=ListLength_p(L);   /*r指针始终动态指向链表的当前表尾*/
	a=ListLength_L(L);     //返回L中数据元素个数到a中
	if(a<Q.dt[x].totalnum) {     //若医生该时间段的总号数未满，则可进行排号

		s=(Node*)malloc(sizeof(Node));    //建立一个新结点
		s->data=(r->data)+1;    //排号数由上一号加一
		r->next=s;
		s->next=NULL;
		printf("排号成功！");
		L->data=s->data;
	} else printf("排号失败，该医生该时段已排满！");
	WriteData();
}

void search_queue(LinkList L) { //显示已排好情况
	LinkList p;
	if(L->next==NULL) {
		printf("现在还没有排队的病人呦");
		return ;
	}

	else {
		p=L->next;
		printf("正在排队的病人号码分别是");
		while(p!=NULL) {
			printf("%d",p->data);
			p=p->next;
		}
	}
}


int showuser(DoctorList L) {	//排号选择页面
	int ph,i,s=0;
	printf("\t\t%-8s%-20s%-10s%-8s\n",
	       "科室","医生","时间段","总号数");
	printf("\t\t--------------------------------------------------\n");
	for (i=0; i<L.TotalDoctor; i++,s++)
		printf("\t\t%d.%-8s%-20s%-10s%-8d\n",s, L.dt[i].dtno, L.dt[i].dtname,
		       L.dt[i].time, L.dt[i].totalnum);
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t请输入想要选择排号的编号：");
	scanf("%d",&ph);
	return ph;
}

void rnumber() {  //排号功能
	int user;
	system("cls");   //清屏
	user=showuser(doctor_list);
	CreateFromTail(doctor_list.dt[user].p,doctor_list,user);   //调用函数排号
}


void rsearch() {  //排号查看功能
	int user;
	system("cls");   //清屏
	user=showuser(doctor_list);
	search_queue(doctor_list.dt[user].p);
}

void dttake(LinkList L) { //医生取号
	LinkList p;
	if(L->next==NULL) {
		printf("没有病人排队");
	} else if(L->next==ListLength_p(L)) {
		printf("%d号病人请进来就诊",L->next->data);
		p=L->next;
		L->next=NULL;
		free(p);
	} else {
		printf("%d号病人请进来就诊",L->next->data);
		p=L->next;
		L->next=p->next;
		free(p);
	}

}

void dtsearch() {  //排号查看功能
	int user;
	system("cls");   //清屏
	user=showuser(doctor_list);
	dttake(doctor_list.dt[user].p);
}

int showsel() {  	//显示主菜单
	int sel;
	printf("\t\t简易医院排号系统\n");
	printf("\t---------------------------------\n");
	printf("\t\t0. 退出\n");
	printf("\t\t1. 查看科室及医生信息\n");
	printf("\t\t2. 排号\n");
	printf("\t\t3. 查看已排号情况\n");
	printf("\t\t4. 医生取号\n");
	printf("\t----------------------------------\n");
	printf("\t\t请输入要选择的功能编号：");
	scanf("%d",&sel);
	return sel;
}

int main() {
	int sel;
	ReadData();		//先将硬盘中doctordata记事本中的数据读入到顺序表doctor_list中
	do {
		system("cls");		//清屏
		sel=showsel();		//返回主菜单中的选择项
		switch(sel) {	//根据选择项调用对应的函数
			case 0:
				break;
			case 1:
				system("cls");
				doctorlist();
				getch();
				break;   /*查看科室及医生信息功能*/
			case 2:
				system("cls");
				rnumber();
				getch();
				break;      //排号功能
			case 3:
				system("cls");
				rsearch();
				getch();
				break;     //查看排号情况
			case 4:
				system("cls");
				dtsearch();       //医生取号功能
				getch();
				break;
			case 5:
				system("cls");
				dtsearch();
				getch();
				break;	   //后序用户可进入查询、删除并重新预约(未完成）
		}
	} while(sel);	//当选择主菜单中序号0时，结束程序
	return 0;
}

