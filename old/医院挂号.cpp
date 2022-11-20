#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>
#include <conio.h>

#define MAXNUM 100    /*ҽ����Ϣ����ܴﵽ����󳤶�*/

typedef struct Node { //�ڵ����Ͷ���
	int data;    //������
	struct Node* next;  //ָ����
} Node,*LinkList;

typedef struct {      /*ҽ����Ϣ����*/
	char dtno[10];		/*����*/
	char dtname[20];		/*ҽ��*/
	char time[10];		/*ʱ���*/
	int totalnum; 			/*�ܺ���*/
	LinkList p;
} DOCTOR;

typedef struct {
	DOCTOR dt[MAXNUM];      /*ͨ�����Ͷ�����������Ҽ�ҽ����Ϣ����*/
	int TotalDoctor;       /*���һ��Ԫ���������е�λ�ã����±꣬�ձ�Ϊ-1 */
} DoctorList;              /*ҽ����Ϣ���˳��洢�ṹ����ΪDoctorList */
DoctorList  doctor_list;     /*������Ҽ�ҽ����Ϣ˳���*/

void search_queue(LinkList L);

void InitList(LinkList *L) { //��ʼ��������
	*L=(LinkList)malloc(sizeof(Node));  //����ͷ��㣬Ϊͷ������洢�ռ�
	(*L)->next=NULL;
	(*L)->data=0;     //�����ͷ��������
}

LinkList p1,p2,p3,p4,p5,p6,p7,p8;   //8�������Ӧ�˸�ͷָ��


void ReadList(LinkList L, FILE *p) {
	LinkList tail=L;
	int temp;
	char temp2;
	fread(&temp2, sizeof(char), 1, p);
//	InitList(L);
	if(temp2=='*')
		while (fread(&temp, sizeof(int), 1, p)) { //ÿ�ζ���һ��Elemtype �͵�tempͨ��β�巨��������
			//	printf("%d",temp);getch();
			LinkList node = (LinkList)malloc(sizeof(Node));
			node->data = temp;
			tail->next = node;
			tail = node;
			tail->next = NULL;
		}
}

void ReadData() {	//��Ӳ��doctordata�ļ��е����ݶ����ڴ�˳���doctor_list��
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

void WriteData() {	//���ڴ���˳���doctor_list�ı仯������Ӳ���ļ�doctordata��
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


void  Locate(DoctorList L,char e[]) {      /*����ҽ����Ϣ*/
	int i=0 ;      /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	for(i=0; i<=L.TotalDoctor; i++) {
		if(strcmp(L.dt[i].dtname,e)==0) {
			printf("\n\n\n\t\t--------------------------------------------------\n");
			printf("\t\t%-8s%-20s%-10s%-8s\n",
			       "����","ҽ��","ʱ���","�ܺ���");
			printf("\t\t--------------------------------------------------\n");
			printf("\t\t%-8s%-20s%-10s%-8d\n", doctor_list.dt[i].dtno, doctor_list.dt[i].dtname,
			       doctor_list.dt[i].time, doctor_list.dt[i].totalnum);  /*���ҵ����������ҽ����Ϣ*/
			printf("\t\t--------------------------------------------------\n");
		} else
			break;
	}
	if(i>L.TotalDoctor) printf("���޴��ˣ�");  /*��û�ҵ����������*/

}

void InsList(DoctorList *L,int i,DOCTOR e) { /*����ҽ����Ϣ*/
	int k;
	if( (i<1)||(i>L->TotalDoctor+2) ) {   /*�����жϲ���λ���Ƿ�Ϸ�*/
		printf("����λ��iֵ���Ϸ�\n");
		printf("��Ϣ����ʧ�ܣ�\n");
	}
	if(L->TotalDoctor>=MAXNUM-1) {
		printf("�������޷�����\n");
		printf("��Ϣ����ʧ�ܣ�\n");
	}

	for(k=L->TotalDoctor-1; k>=i-1; k--)   /*���Ԫ�غ���*/
		L->dt[k+1]=L->dt[k];
	L->dt[i-1]=e; /*���ݲ��룬��i��Ԫ�ص��±�Ϊi-1*/
	InitList(&L->dt[i-1].p);
	L->TotalDoctor++;
	printf("��Ϣ����ɹ���\n");
	WriteData();
}

void  DelList(DoctorList *L,int i,DOCTOR *e)     /*ɾ��*/
/*��˳���L��ɾ����i������Ԫ�أ�����ָ�����e������ֵ*/
{
	int k;
	if((i<1)||(i>L->TotalDoctor+1)) {
		printf("ɾ��λ�ò��Ϸ���\n");
		printf("��Ϣɾ��ʧ�ܣ�\n");
	}
	*e= L->dt[i-1];      /* ��ɾ����Ԫ�ش�ŵ�e��ָ��ı�����*/
	for(k=i; k<L->TotalDoctor; k++)
		L->dt[k-1]=L->dt[k];     /*�������Ԫ������ǰ��*/
	L->TotalDoctor--;
	printf("��Ϣɾ���ɹ���\n");
	WriteData();
}


int showx(DoctorList L) {	//��ӡ�嵥(����ҳ�棩
	int i,x;
	printf("\t\t%-8s%-20s%-10s%-8s\n",
	       "����","ҽ��","ʱ���","�ܺ���");
	printf("\t\t--------------------------------------------------\n");
	for (i=0; i<L.TotalDoctor; i++)
		printf("\t\t%-8s%-20s%-10s%-8d\n", L.dt[i].dtno, L.dt[i].dtname,
		       L.dt[i].time, L.dt[i].totalnum);
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t0. �˳�\n");
	printf("\t\t1. ����\n");
	printf("\t\t2. ����\n");
	printf("\t\t3. ɾ��\n");
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t������Ҫѡ��Ĺ��ܱ�ţ�");
	scanf("%d",&x);
	return x;
}

void doctorlist() {    /*�鿴���Ҽ�ҽ����Ϣ����*/
	int i,w,x;
	char a[10];
	DOCTOR add;
	DoctorList *l;
	l=&doctor_list;
	do {
		system("cls");
		x=showx(doctor_list);
		switch(x) {	//����ѡ������ö�Ӧ�ĺ���
			case 0:
				break;
			case 1:
				system("cls");
				printf("����Ҫ����ҽ����������");
				scanf("%s",a);
				Locate(doctor_list,a);    /*����*/
				getch();
				break;
			case 2:
				system("cls");          /*����*/
				printf("��������ϢҪ�����λ�ã�");
				scanf("%d",&w);
				printf("������Ҫ�������Ϣ�����ҡ�ҽ��������ʱ��Ρ��ܺ�����");
				scanf("%s %s %s %d",add.dtno,add.dtname,add.time,&add.totalnum);
				InsList(l,w,add);
				getch();
				break;
			case 3:
				system("cls");        /*ɾ��*/
				printf("������Ҫɾ����Ϣ���ڵ�λ�ã�");
				scanf("%d",&w);
				DOCTOR E,*e;
				e=&E;
				DelList(l,w,e);
				getch();
				break;
		}
	} while(x);
}


int  ListLength_L(LinkList L) { //���
	//����L������Ԫ�ظ���
	LinkList p;
	int i;
	p=L->next;  //pָ���һ�����
	i=0;
	while(p) {
		//����������,ͳ�ƽ����
		i++;
		p=p->next;
	}
	return i;
}

Node*  ListLength_p(LinkList L) { //���β���
	//����L������Ԫ�ظ���
	LinkList p;
	p=L;  //pָ���һ�����
	while(p->next!=NULL) {
		//����������
		p=p->next;
	}
	return p;
}

void CreateFromTail(LinkList L,DoctorList Q,int x) {  //�ź� (�ж��Ƿ���ʣ����룬��ʾ�źųɹ���ʧ�ܣ�
	Node *r,*s;
	int a;   //aΪ����L�ĳ���
	r=ListLength_p(L);   /*rָ��ʼ�ն�ָ̬������ĵ�ǰ��β*/
	a=ListLength_L(L);     //����L������Ԫ�ظ�����a��
	if(a<Q.dt[x].totalnum) {     //��ҽ����ʱ��ε��ܺ���δ������ɽ����ź�

		s=(Node*)malloc(sizeof(Node));    //����һ���½��
		s->data=(r->data)+1;    //�ź�������һ�ż�һ
		r->next=s;
		s->next=NULL;
		printf("�źųɹ���");
		L->data=s->data;
	} else printf("�ź�ʧ�ܣ���ҽ����ʱ����������");
	WriteData();
}

void search_queue(LinkList L) { //��ʾ���ź����
	LinkList p;
	if(L->next==NULL) {
		printf("���ڻ�û���ŶӵĲ�����");
		return ;
	}

	else {
		p=L->next;
		printf("�����ŶӵĲ��˺���ֱ���");
		while(p!=NULL) {
			printf("%d",p->data);
			p=p->next;
		}
	}
}


int showuser(DoctorList L) {	//�ź�ѡ��ҳ��
	int ph,i,s=0;
	printf("\t\t%-8s%-20s%-10s%-8s\n",
	       "����","ҽ��","ʱ���","�ܺ���");
	printf("\t\t--------------------------------------------------\n");
	for (i=0; i<L.TotalDoctor; i++,s++)
		printf("\t\t%d.%-8s%-20s%-10s%-8d\n",s, L.dt[i].dtno, L.dt[i].dtname,
		       L.dt[i].time, L.dt[i].totalnum);
	printf("\t\t--------------------------------------------------\n");
	printf("\t\t��������Ҫѡ���źŵı�ţ�");
	scanf("%d",&ph);
	return ph;
}

void rnumber() {  //�źŹ���
	int user;
	system("cls");   //����
	user=showuser(doctor_list);
	CreateFromTail(doctor_list.dt[user].p,doctor_list,user);   //���ú����ź�
}


void rsearch() {  //�źŲ鿴����
	int user;
	system("cls");   //����
	user=showuser(doctor_list);
	search_queue(doctor_list.dt[user].p);
}

void dttake(LinkList L) { //ҽ��ȡ��
	LinkList p;
	if(L->next==NULL) {
		printf("û�в����Ŷ�");
	} else if(L->next==ListLength_p(L)) {
		printf("%d�Ų������������",L->next->data);
		p=L->next;
		L->next=NULL;
		free(p);
	} else {
		printf("%d�Ų������������",L->next->data);
		p=L->next;
		L->next=p->next;
		free(p);
	}

}

void dtsearch() {  //�źŲ鿴����
	int user;
	system("cls");   //����
	user=showuser(doctor_list);
	dttake(doctor_list.dt[user].p);
}

int showsel() {  	//��ʾ���˵�
	int sel;
	printf("\t\t����ҽԺ�ź�ϵͳ\n");
	printf("\t---------------------------------\n");
	printf("\t\t0. �˳�\n");
	printf("\t\t1. �鿴���Ҽ�ҽ����Ϣ\n");
	printf("\t\t2. �ź�\n");
	printf("\t\t3. �鿴���ź����\n");
	printf("\t\t4. ҽ��ȡ��\n");
	printf("\t----------------------------------\n");
	printf("\t\t������Ҫѡ��Ĺ��ܱ�ţ�");
	scanf("%d",&sel);
	return sel;
}

int main() {
	int sel;
	ReadData();		//�Ƚ�Ӳ����doctordata���±��е����ݶ��뵽˳���doctor_list��
	do {
		system("cls");		//����
		sel=showsel();		//�������˵��е�ѡ����
		switch(sel) {	//����ѡ������ö�Ӧ�ĺ���
			case 0:
				break;
			case 1:
				system("cls");
				doctorlist();
				getch();
				break;   /*�鿴���Ҽ�ҽ����Ϣ����*/
			case 2:
				system("cls");
				rnumber();
				getch();
				break;      //�źŹ���
			case 3:
				system("cls");
				rsearch();
				getch();
				break;     //�鿴�ź����
			case 4:
				system("cls");
				dtsearch();       //ҽ��ȡ�Ź���
				getch();
				break;
			case 5:
				system("cls");
				dtsearch();
				getch();
				break;	   //�����û��ɽ����ѯ��ɾ��������ԤԼ(δ��ɣ�
		}
	} while(sel);	//��ѡ�����˵������0ʱ����������
	return 0;
}

