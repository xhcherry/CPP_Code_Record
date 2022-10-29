#include<stdio.h>
#include<Windows.h>
#include<ctype.h>
#include<string.h>

//**************����*********************
#define PENALTY 0.1//����0.1Ԫһ��
#define DEADLINE 60//�����ʱ��60��

//***************����ṹ��******************
struct Date//����
{
	int year;
	int month;
	int day;
};

struct Book//��
{
	char issn[30];//issn���
	char title[30];//����
	char publisher[20];//������
	char author[20];//����
	double price;//�۸�
	char available;//�Ƿ����
	char no[10];//��˭����
	struct Book *next;
};

struct History//������ʷ
{
	char no[10];//ѧ��
	char issn[30];//issn���
	struct Date borrow_date;//����ʱ��
	struct Date return_date;//����ʱ��
	double penalty;//ΥԼ��
	struct History *next;
};

struct Stu//ѧ��
{
	char no[10];//ѧ��
	char name[10];//����
	char class_no[15];//�༶
	char phone_number[15];//��ϵ��ʽ
	char gender;//�Ա�
	struct Stu *next;
};

//******************ȫ�ֱ���***********************
struct Stu *stu_head=NULL;//ѧ��ͷָ��
struct Book *book_head=NULL;//�鱾ͷָ��
struct History *history_head=NULL;//��ʷͷָ��

//************************��ʼ��/�������****************************
void initialization(void)
{
	FILE *fp;
	fp=fopen("stu.txt","wb");
	fclose(fp);
	fp=fopen("book.txt","wb");
	fclose(fp);
	fp=fopen("history.txt","wb");
	fclose(fp);
}
//*********************��д*****************************
void read_file(void);//�����ڴ�ռ䲢���ļ�
void write_file(void);//д�ļ����ͷ��ڴ�ռ�

void read_file(void)//��
{
	FILE *fp;
	struct Stu *stu_p1=NULL;
	struct Stu *stu_p2=NULL;
	struct Book *book_p1=NULL;
	struct Book *book_p2=NULL;
	struct History *history_p1=NULL;
	struct History *history_p2=NULL;
	//��ѧ���ļ�
	if((fp=fopen("stu.txt","rb"))==NULL)//��ʧ�����´���
		fp=fopen("stu.txt","wb+");
	stu_head=stu_p1=stu_p2=(struct Stu *)malloc(sizeof(struct Stu));
	fread(stu_p1,sizeof(struct Stu),1,fp);
	while(!feof(fp))
	{
		stu_p1=stu_p2;
		stu_p2=(struct Stu *)malloc(sizeof(struct Stu));
		stu_p1->next=stu_p2;
		fread(stu_p2,sizeof(struct Stu),1,fp);
	}
	if(stu_p1==stu_p2)//�ļ�Ϊ��
		stu_head=NULL;
	else
		stu_p1->next=NULL;
	free(stu_p2);//���һ������Ч�Ŀռ�
	fclose(fp);
	//��ͼ���ļ�
	if((fp=fopen("book.txt","rb"))==NULL)//��ʧ�����´���
		fp=fopen("book.txt","wb+");
	book_head=book_p1=book_p2=(struct Book *)malloc(sizeof(struct Book));
	fread(book_p1,sizeof(struct Book),1,fp);;
	while(!feof(fp))
	{
		book_p1=book_p2;
		book_p2=(struct Book *)malloc(sizeof(struct Book));
		book_p1->next=book_p2;
		fread(book_p2,sizeof(struct Book),1,fp);
	}
	if(book_p1==book_p2)//�ļ�Ϊ��
		book_head=NULL;
	else
		book_p1->next=NULL;
	free(book_p2);//���һ������Ч�Ŀռ�
	fclose(fp);
	//��������ʷ�ļ�
	if((fp=fopen("history.txt","rb"))==NULL)//��ʧ�����´���
		fp=fopen("history.txt","wb+");
	history_head=history_p1=history_p2=(struct History *)malloc(sizeof(struct History));
	fread(history_p1,sizeof(struct History),1,fp);
	while(!feof(fp))
	{
		history_p1=history_p2;
		history_p2=(struct History *)malloc(sizeof(struct History));
		history_p1->next=history_p2;
		fread(history_p2,sizeof(struct History),1,fp);
	}
	if(history_p1==history_p2)//�ļ�Ϊ��
		history_head=NULL;
	else
		history_p1->next=NULL;
	free(history_p2);//���һ������Ч�Ŀռ�
	fclose(fp);
}

void write_file(void)//д
{
	FILE *fp;
	struct Stu *stu_p1=NULL;
	struct Stu *stu_p2=NULL;
	struct Book *book_p1=NULL;
	struct Book *book_p2=NULL;
	struct History *history_p1=NULL;
	struct History *history_p2=NULL;
	//дѧ���ļ�
	fp=fopen("stu.txt","wb");
	if(stu_head!=NULL)//��Ϊ�գ�д����
	{
		stu_p1=stu_p2=stu_head;
		while(stu_p2!=NULL)
		{
			stu_p1=stu_p2;
			fwrite(stu_p1,sizeof(struct Stu),1,fp);
			stu_p2=stu_p1->next;
		}
	}
	fclose(fp);
	//дͼ���ļ�
	fp=fopen("book.txt","wb");
	if(book_head!=NULL)//��Ϊ�գ�д����
	{
		book_p1=book_p2=book_head;
		while(book_p2!=NULL)
		{
			book_p1=book_p2;
			fwrite(book_p1,sizeof(struct Book),1,fp);
			book_p2=book_p1->next;
		}
	}
	fclose(fp);
	//д��ʷ�ļ�
	fp=fopen("history.txt","wb");
	if(history_head!=NULL)//��Ϊ�գ�д����
	{
		history_p1=history_p2=history_head;
		while(history_p2!=NULL)
		{
			history_p1=history_p2;
			fwrite(history_p1,sizeof(struct History),1,fp);
			history_p2=history_p1->next;
		}
	}
	fclose(fp);

}
void freeall(void)//�ͷſռ�
{
	struct Stu *stu_p1=NULL;
	struct Stu *stu_p2=NULL;
	struct Book *book_p1=NULL;
	struct Book *book_p2=NULL;
	struct History *history_p1=NULL;
	struct History *history_p2=NULL;
	if(stu_head!=NULL)//��Ϊ��
	{
		stu_p1=stu_p2=stu_head;
		while(stu_p2!=NULL)
		{
			stu_p1=stu_p2;
			stu_p2=stu_p1->next;
			free(stu_p1);//�ͷſռ�	
		}
		stu_head=NULL;
	}
	if(book_head!=NULL)//��Ϊ��
	{
		book_p1=book_p2=book_head;
		while(book_p2!=NULL)
		{
			book_p1=book_p2;
			book_p2=book_p1->next;
			free(book_p1);//�ͷſռ�
		}
		book_head=NULL;
	}
	if(history_head!=NULL)//��Ϊ�գ�д����
	{
		history_p1=history_p2=history_head;
		while(history_p2!=NULL)
		{
			history_p1=history_p2;
			history_p2=history_p1->next;
			free(history_p1);//�ͷſռ�
		}
		history_head=NULL;
	}
}

//*****************ת����Сд���������س�************************
char upper_getchar(void)
{
	char ch;
	while (ch = toupper(getchar()))
	{
		if (ch == '\n')
			continue;
		else
			break;
	}
	return ch;
}
//**********************�������ڼ���***************************
int datecmp(struct Date start,struct Date end) //�ж����ڴ�С�Ƿ�Ϸ�
{
	if(start.year*10000+start.month*100+start.day<=end.year*10000+end.month*100+end.day)//������ת��Ϊ20180227����ʽ���ȴ�С
		return 1;//��ȷ
	else
		return -1;//����
}

int cal_date(struct Date start,struct Date end)//�������ڼ��
{
	if(datecmp(start,end)==-1)
	{
		puts("���ڴ���");
		return -1;
	}
	else
	{
		int y1,m1,d1;
		int y2,m2,d2;
		m1 = (start.month + 9) % 12;
		y1 = start.year - m1/10;
		d1 = 365*y1 + y1/4 - y1/100 + y1/400 + (m1*306 + 5)/10 + (start.day - 1);
		m2 = (end.month + 9) % 12;
		y2 = end.year- m2/10;
		d2 = 365*y2 + y2/4 - y2/100 + y2/400 + (m2*306 + 5)/10 + (end.day - 1);
 
		return (d2 - d1);//���ڼ��
	}
}

//****************��ѯϵͳ**********************
void query(void);//��ѯϵͳ
int search_book(char issn[],struct Book **book_p1,struct Book **book_p2);//ͼ���ѯ
int search_stu(char no[],struct Stu **stu_p1,struct Stu **stu_p2);//ѧ����Ϣ��ѯ
int search_history(char no[],char issn[],struct History **history_p1,struct History **history_p2);//��ʷ��ѯ
void return_book_now(void);//�߽�ͼ��
void query(void)
{
	struct Stu *stu_p1=NULL;
	struct Book *book_p1=NULL;
	struct History *history_p1=NULL;
	struct Stu *stu_p2=NULL;
	struct Book *book_p2=NULL;
	struct History *history_p2=NULL;
	char buffer_issn[30];//�鼮issn���
	char buffer_no[30];//ѧ��ѧ��
	char option;
	system("cls");
	do
	{
		puts("************��ѯϵͳ************");
		puts("A.ͼ���ѯ");
		puts("B.ѧ����Ϣ��ѯ");
		puts("C.��ʷ��Ϣ��ѯ");
		puts("D.�߽�ͼ��");
		puts("Q.����ͼ�����ϵͳ");
		puts("������ѡ����س���ȷ�ϣ���Сд����");
		switch (option = upper_getchar())
		{
			case 'A':puts("������issn��ţ����س�ȷ��");
					 scanf("%s",buffer_issn);
					 search_book(buffer_issn,&book_p1,&book_p2); 
					 break;
			case 'B':puts("������ѧ�ţ����س�ȷ��");
					 scanf("%s",buffer_no);
					 search_stu(buffer_no,&stu_p1,&stu_p2);
					 break;
			case 'C':puts("������ѧ�ţ����س�ȷ��");
					 scanf("%s",buffer_no);
					 search_history(buffer_no,"ALL",&history_p1,&history_p2);//"ALL"������ѧ������
					 break;
			case 'D':return_book_now();
			case 'Q':break;
			default:puts("\n\n�������Ӧ������Ӣ����ĸѡ�����");
					system("Pause");
					break;
		}
		system("cls");
	} while (option != 'Q');
}
//��ѯ��
int search_book(char issn[],struct Book **book_p1,struct Book **book_p2)//p1Ϊǰһ��ָ�룬p2�Ǵ�����ָ��
{
	int flag=0;//�����û�ҵ�����ʼֵ0
	*book_p1=*book_p2=book_head;
	while(*book_p2!=NULL)
	{
		if(strcmp(issn,(*book_p2)->issn)==0)
		{
			flag=1;
			break;
		}
		*book_p1=*book_p2;
		*book_p2=(*book_p1)->next;
	}
	if(flag)//�ҵ���
	{
		puts("�ҵ�����");
		printf("������%s issn��ţ�%s \n�����磺%s ���ߣ�%s \n�۸�%lf \n",
				(*book_p2)->title,(*book_p2)->issn,
				(*book_p2)->publisher,(*book_p2)->author,
				(*book_p2)->price);
		printf("��˭���ߣ�%s\n",(*book_p2)->no);
	}
	else
		puts("�޴˼�¼������");
	system("pause");

	return flag;
}

int search_stu(char no[],struct Stu **stu_p1,struct Stu **stu_p2)//p1Ϊǰһ��ָ�룬p2�Ǵ�����ָ��
{
	int flag=0;//�����û�ҵ�����ʼֵ0
	*stu_p1=*stu_p2=stu_head;
	while(*stu_p2!=NULL)
	{
		if(strcmp(no,(*stu_p2)->no)==0)
		{
			flag=1;
			break;
		}
		*stu_p1=*stu_p2;
		*stu_p2=(*stu_p1)->next;
	}
	if(flag)//�ҵ���
	{
		puts("�ҵ���ѧ��");
		printf("ѧ��:%s ����:%s �༶:%s ��ϵ��ʽ:%s �Ա�:%c\n",(*stu_p2)->no,(*stu_p2)->name,(*stu_p2)->class_no,
			(*stu_p2)->phone_number,(*stu_p2)->gender);
	}
	else
		puts("�޴˼�¼������");
	system("pause");
	
	return flag;
}

int search_history(char no[],char issn[],struct History **history_p1,struct History **history_p2)//p1Ϊǰһ��ָ�룬p2�Ǵ�����ָ��
{
	int flag=0;//�����û�ҵ�����ʼֵ0
	*history_p1=*history_p2=history_head;
	if(strcmp(issn,"ALL")==0)
	{
		while(*history_p2!=NULL)
		{
			if((strcmp(no,(*history_p2)->no)==0))
			{
				flag=1;
				printf("ѧ��:%s issn��ţ�%s\n�������ڣ�%d/%d/%d\n�������ڣ�%d/%d/%d\nΥԼ��%lf\n",
				(*history_p2)->no,(*history_p2)->issn,
				(*history_p2)->borrow_date.year,(*history_p2)->borrow_date.month,(*history_p2)->borrow_date.day,
				(*history_p2)->return_date.year,(*history_p2)->return_date.month,(*history_p2)->return_date.day,
				(*history_p2)->penalty);
				puts("**********************");
			}
			*history_p1=*history_p2;
			*history_p2=(*history_p1)->next;
		}
		puts("**********************");
		system("pause");
	}
	else
	{
		while(*history_p2!=NULL)
		{
			if(strcmp(no,(*history_p2)->no)==0&&strcmp(issn,(*history_p2)->issn)==0&&(*history_p2)->return_date.year==0)//ѧ���ҵ�������ҵ�����û�л���
			{
				flag=1;
				break;//�ҵ�������
			}
			*history_p1=*history_p2;
			*history_p2=(*history_p1)->next;
		}
		if(flag)//�ҵ���
		{
			puts("�ҵ��˼�¼");
			printf("ѧ��:%s issn��ţ�%s\n�������ڣ�%d/%d/%d\n�������ڣ�%d/%d/%d\nΥԼ��%lf\n",
			(*history_p2)->no,(*history_p2)->issn,
			(*history_p2)->borrow_date.year,(*history_p2)->borrow_date.month,(*history_p2)->borrow_date.day,
			(*history_p2)->return_date.year,(*history_p2)->return_date.month,(*history_p2)->return_date.day,
			(*history_p2)->penalty);
		}
		else
			puts("�޴˼�¼������");
		system("pause");
	}
	return flag;
}

void return_book_now(void)//�û����ˣ��߽�
{
	struct History *history_p;
	struct Stu *stu_p1=NULL;
	struct Stu *stu_p2=NULL;
	struct Date date;
	puts("�������������");
	scanf("%d%d%d",&date.year,&date.month,&date.day);
	history_p=history_head;
	while(history_p!=NULL)
	{
		if(history_p->return_date.year==0&&cal_date(history_p->borrow_date,date)>DEADLINE)//û�����ҳ�������
		{
			printf("�߽�:�鱾��ţ�%s ѧ��:%s\n",history_p->issn,history_p->no);
			search_stu(history_p->no,&stu_p1,&stu_p2);
			puts("****************************************");
		}
		history_p=history_p->next;
	}
	system("pause");
}


//***********************ѧ������ϵͳ*******************
void stu_management(void);//ѧ������ϵͳ

void add_stu(void);//���ѧ��
void modify_stu(void);//�޸�ѧ����Ϣ
void delete_stu(void);//ɾ��ѧ����Ϣ
void view_stu(void);//�鿴ѧ����Ϣ


void stu_management(void)
{
	char option;
	system("cls");
	do
	{
		puts("************ѧ����Ϣ����************");
		puts("A.���ѧ����Ϣ");
		puts("B.�޸�ѧ��������Ϣ");
		puts("C.ɾ��ѧ��������Ϣ");
		puts("D.�鿴����ѧ��������Ϣ");
		puts("Q.����ͼ�����ϵͳ");
		puts("������ѡ����س���ȷ�ϣ���Сд����");
		puts("������Ϣ�����d����");
		switch (option = upper_getchar())
		{
			case 'A':add_stu(); break;
			case 'B':modify_stu(); break;
			case 'C':delete_stu(); break;
			case 'D':view_stu(); break;
			case 'Q':break;
			default:puts("\n\n�������Ӧ������Ӣ����ĸѡ�����");
					system("Pause");
					break;
		}
		system("cls");
	} while (option != 'Q');
}


//���ѧ��ǰ�Ȳ����Ƿ�����ظ���Ȼ�������
void add_stu(void)
{
	char option;//ѡ��
	struct Stu *stu_p1=NULL;
	struct Stu *stu_p2=NULL;
	struct Stu stu;


	puts("������ѧ��");
	printf("ѧ��:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",stu.no);
	puts("������...");
	if(search_stu(stu.no,&stu_p1,&stu_p2)==1)//�ظ���
	{
		puts("���и�ѧ������¼");
		Sleep(1000);
		return;
	}

	puts("����д��������ϸ��Ϣ,���س���¼��");

	printf("ѧ��:%s\n",stu.no);
	printf("����:_______\b\b\b\b\b\b");
	scanf("%s",&stu.name);
	puts("������¼��");
	
	printf("�༶:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&stu.class_no);
	puts("�༶��¼��");

	printf("�Ա�:____\b\b");
	stu.gender=upper_getchar();
	puts("�Ա���¼��");

	printf("��ϵ��ʽ:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&stu.phone_number);
	puts("��ϵ��ʽ��¼��");
	
	stu.next=NULL;

	puts("�Ƿ񱣴�,����Y/N�������ִ�Сд");
	do
	{
		option=upper_getchar();
		if(option=='Y')
		{
			stu_p2=(struct Stu *)malloc(sizeof(struct Stu));
			*stu_p2=stu;
			system("pause");
			if(stu_head==NULL)//������
				stu_head=stu_p2;
			else
				stu_p1->next=stu_p2;
			puts("��¼�룡");
			Sleep(500);
		}
	}while(!(option=='Y'||option=='N'));//��������Y/N
}

//�޸�ѧ��ǰ�Ȳ����Ƿ����
void modify_stu(void)
{
	char option;//ѡ��
	struct Stu stu;
	struct Stu *stu_p1=NULL;
	struct Stu *stu_p2=NULL;

	puts("������ѧ��");
	printf("ѧ��:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&stu.no);
	puts("������...");
	if(search_stu(stu.no,&stu_p1,&stu_p2)==0)//ѧ��������
	{
		Sleep(1000);
		return;
	}

	puts("����д��ϸ��Ϣ,���س���¼��");
	printf("����:_______\b\b\b\b\b\b");
	scanf("%s",&stu.name);
	puts("������¼��");
	printf("�༶:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&stu.class_no);
	printf("�༶��¼��");
	printf("�Ա�:___\b\b");
	stu.gender=upper_getchar();
	puts("�Ա���¼��");
	printf("��ϵ��ʽ:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&stu.phone_number);
	puts("��ϵ��ʽ��¼��");
	puts("�Ƿ񱣴�,����Y/N�������ִ�Сд");
	stu.next=stu_p2->next;
	do
	{
		option=upper_getchar();
		if(option=='Y')
		{
			//д��ȥ�����ǣ��������滻
			*stu_p2=stu;
			puts("��¼�룡");
			Sleep(500);
		}
	}while(!(option=='Y'||option=='N'));
}

//ɾ��ѧ��ǰ���Ȳ����Ƿ����
void delete_stu(void)
{
	char option;//ѡ��
	struct Stu stu;
	struct Stu *stu_p1=NULL;
	struct Stu *stu_p2=NULL;
	puts("������ѧ��");
	printf("ѧ��:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&stu.no);
	puts("������...");
	if(search_stu(stu.no,&stu_p1,&stu_p2)==0)//ѧ��������
	{
		Sleep(1000);
		return;
	}
	else//һ���ҵ��ˣ�p2ָ�����Ҫɾ����ѧ����,p1��p2֮ǰ��
	{
		puts("�Ƿ�ɾ��������Y/N�������ִ�Сд");
		do
		{
			option=upper_getchar();
			if(option=='Y')
			{
				if(stu_p2==stu_head)//����ͷ
					stu_head=stu_p2->next;
				else
					stu_p1->next=stu_p2->next;
				free(stu_p2);
				puts("ɾ���ɹ���");
				Sleep(1000);
				return;
			}
		}while(!(option=='Y'||option=='N'));
	}	
}
//�鿴ѧ����Ϣ
void view_stu(void)
{
	struct Stu *stu_p;
	stu_p=stu_head;
	while(stu_p!=NULL)
	{	
		printf("ѧ��:%s ����:%s �༶��%s �Ա�:%c\n",stu_p->no,stu_p->name,stu_p->class_no,stu_p->gender);
		printf("************************************\n");
		stu_p=stu_p->next;
	}
	system("pause");
}
//********************�鼮����ϵͳ*****************
void book_management(void);//�鼮����ϵͳ
void add_book(void);//�������
void modify_book(void);//�޸��鼮��Ϣ
void delete_book(void);//ɾ���鼮��Ϣ
void view_book(void);//�鿴ͼ����Ϣ

void book_management(void)
{
	char option;
	system("cls");
	do
	{
		puts("************ͼ����Ϣ����************");
		puts("A.�����ͼ����Ϣ");
		puts("B.�޸�ͼ����Ϣ");
		puts("C.ɾ��ͼ��");
		puts("D.�鿴ͼ����Ϣ");
		puts("Q.����ͼ�����ϵͳ");
		puts("������ѡ����س���ȷ�ϣ���Сд����");
		puts("������Ϣ�����d����");
		switch (option = upper_getchar())
		{
			case 'A':add_book(); break;
			case 'B':modify_book(); break;
			case 'C':delete_book(); break;
			case 'D':view_book(); break;
			case 'Q':break;
			default:puts("\n\n�������Ӧ������Ӣ����ĸѡ�����");
					system("Pause");
					break;
		}
		system("cls");
	} while (option != 'Q');
}

//���ͼ��ǰ�Ȳ����Ƿ�����ظ���Ȼ�������
void add_book(void)
{
	
	char option;//ѡ��
	struct Book book;
	struct Book *book_p1=NULL;
	struct Book *book_p2=NULL;
	
	puts("������issn���");
	printf("issn���:______________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&book.issn);
	puts("������...");
	if(search_book(book.issn,&book_p1,&book_p2)==1)//�ظ���
	{
		puts("���и��鼰��¼");
		Sleep(1000);
		return;
	}

	strcpy(book.no,"��");//��ʼ��
	puts("����д��������ϸ��Ϣ,���س���¼��");
	printf("issn���:%s\n",book.issn);
	printf("����:_____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&book.title);
	puts("������¼��");
	printf("����:____________\b\b\b\b\b\b\b");
	scanf("%s",&book.author);
	puts("������¼��");
	printf("������:_____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&book.publisher);
	puts("��������¼��");
	printf("�۸�:_____\b\b\b\b");
	scanf("%lf",&book.price);
	puts("�۸���¼��");
	puts("�Ƿ񱣴�,����Y/N�������ִ�Сд");
	book.next=NULL;
	do
	{
		option=upper_getchar();
		if(option=='Y')
		{
			book_p2=(struct Book *)malloc(sizeof(struct Book));
			*book_p2=book;
			if(book_head==NULL)//������
				book_head=book_p2;
			else
				book_p1->next=book_p2;
			puts("��¼�룡");
			Sleep(500);
		}
	}while(!(option=='Y'||option=='N'));//��������Y/N
}

//�޸�ͼ��ǰ�Ȳ����Ƿ����
void modify_book(void)
{
	char option;//ѡ��
	struct Book book;
	struct Book *book_p1=NULL;
	struct Book *book_p2=NULL;
	

	puts("������issn���");
	printf("issn���:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&book.issn);
	puts("������...");
	if(search_book(book.issn,&book_p1,&book_p2)==0)//ѧ��������
	{
		Sleep(1000);
		return;
	}

	//һ���ҵ��ˣ�ָ����ڴ�ͼ����Ϣ��
	puts("����д��������ϸ��Ϣ,���س���¼��");
	printf("issn���:%s\n",book.issn);
	printf("����:_____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&book.title);
	puts("������¼��");
	printf("����:____________\b\b\b\b\b\b\b");
	scanf("%s",&book.author);
	puts("������¼��");
	printf("������:_____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&book.publisher);
	puts("��������¼��");
	printf("�۸�:_____\b\b\b\b");
	scanf("%lf",&book.price);
	puts("�۸���¼��");
	book.available=book_p2->available;//��ʼ��
	book.next=book_p2->next;
	puts("�Ƿ񱣴�,����Y/N�������ִ�Сд");
	do
	{
		option=upper_getchar();
		if(option=='Y')
		{
			//д��ȥ�����ǣ��������滻
			*book_p2=book;
			puts("��¼�룡");
			Sleep(500);
		}
	}while(!(option=='Y'||option=='N'));
}

//ɾ��ͼ��ǰ���Ȳ����Ƿ����
void delete_book(void)
{
	char option;//ѡ��
	struct Book book;
	struct Book *book_p1=NULL;
	struct Book *book_p2=NULL;

	puts("������issn���");
	printf("issn���:______________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&book.issn);
	puts("������...");
	if(search_book(book.issn,&book_p1,&book_p2)==0)//ͼ�鲻����
	{
		Sleep(1000);
		return;
	}
	else//һ���ҵ��ˣ�p2ָ�����Ҫɾ����ͼ�鴦
	{
		puts("�Ƿ�ɾ��������Y/N�������ִ�Сд");
		do
		{
			option=upper_getchar();
			if(option=='Y')
			{
				if(book_p2==book_head)//����ͷ
					book_head=book_p2->next;
				else
					book_p1->next=book_p2->next;
				free(book_p2);
				puts("ɾ���ɹ���");
				Sleep(1000);
				return;
			}
		}while(!(option=='Y'||option=='N'));
	}
}
//�鿴ͼ����Ϣ
void view_book(void)
{
	struct Book *book_p;
	book_p=book_head;
	while(book_p!=NULL)
	{
		printf("������%s issn��ţ�%s \n�����磺%s ���ߣ�%s \n�۸�%lf \n",
			book_p->title,book_p->issn,
			book_p->publisher,book_p->author,
			book_p->price);
		printf("************************************\n");
		book_p=book_p->next;
	}
	system("pause");
}

//**********************��/����********************
void borrow_or_return_book(void);
void borrow_book(void);//����
void return_book(void);//����

void borrow_or_return_book(void)
{
	char option;
	system("cls");
	do
	{
		puts("************��/����************");
		puts("A.����");
		puts("B.����");
		puts("Q.����ͼ�����ϵͳ");
		puts("������ѡ����س���ȷ�ϣ���Сд����");
		switch (option = upper_getchar())
		{
			case 'A':borrow_book(); break;
			case 'B':return_book(); break;
			case 'Q':break;
			default:puts("\n\n�������Ӧ������Ӣ����ĸѡ�����");
					system("Pause");
					break;
		}
		system("cls");
	} while (option != 'Q');
}
void borrow_book(void)//����
{
	char option;//ѡ��
	struct Stu stu;
	struct Stu *stu_p1=NULL;
	struct Stu *stu_p2=NULL;

	struct Book book;
	struct Book *book_p1=NULL;
	struct Book *book_p2=NULL;

	struct History history;
	struct History *history_p1=NULL;
	struct History *history_p2=NULL;

	puts("������ѧ��");
	printf("ѧ��:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&stu.no);
	puts("������...");
	if(search_stu(stu.no,&stu_p1,&stu_p2)==0)//ѧ��������
	{
		Sleep(1000);
		return;
	}
	puts("������ͼ���issn���");
	printf("issn���:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&book.issn);
	puts("������...");
	if(search_book(book.issn,&book_p1,&book_p2)==0)//ͼ�鲻����
	{
		Sleep(1000);
		return;
	}

	if(book_p2->available=='N')
	{
		puts("��ͼ���Ѿ������ߣ�");
		system("pause");
		return;//��������
	}
	search_history(stu.no,book.issn,&history_p1,&history_p2);
	book=*book_p2;
	book.available='N';//������
	strcpy(book.no,stu.no);
	puts("���������ʱ��");
	scanf("%d%d%d",&history.borrow_date.year,&history.borrow_date.month,&history.borrow_date.day);
	strcpy(history.issn,book.issn);
	strcpy(history.no,stu.no);
	history.penalty=0;
	history.return_date.day=0;
	history.return_date.month=0;
	history.return_date.year=0;
	history.next=NULL;
	puts("�Ƿ����,����Y/N�������ִ�Сд");
	do
	{
		option=upper_getchar();
		if(option=='Y')
		{
			*book_p2=book;
			history_p2=(struct History *)malloc(sizeof(struct History));
			*history_p2=history;
			if(history_head==NULL)//������
				history_head=history_p2;
			else
				history_p1->next=history_p2;
			puts("��¼�룡");
			Sleep(500);
		}
	}while(!(option=='Y'||option=='N'));
}


void return_book(void)
{

	char option;//ѡ��
	struct History history;
	struct Book book;
	struct History *history_p1=NULL;
	struct History *history_p2=NULL;
	struct Book *book_p1=NULL;
	struct Book *book_p2=NULL;

	puts("������ѧ��");
	printf("ѧ��:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&history.no);
	puts("������ͼ���issn���");
	printf("issn���:___________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s",&history.issn);
	puts("������...");
	if(search_history(history.no,history.issn,&history_p1,&history_p2)==0)//��¼������
	{
		Sleep(1000);
		return;
	}
	history=*history_p2;
	search_book(history.issn,&book_p1,&book_p2);
	book=*book_p2;
	book.available='Y';//��ʼ��
	strcpy(book.no,"��");//��ʼ��
	puts("�����뻹��ʱ��");
	scanf("%d%d%d",&history.return_date.year,&history.return_date.month,&history.return_date.day);
	if(cal_date(history.borrow_date,history.return_date)-DEADLINE>0)//��������������
		history.penalty=(cal_date(history.borrow_date,history.return_date)-DEADLINE)*PENALTY;
	else
		history.penalty=0;
	puts("�Ƿ���,����Y/N�������ִ�Сд");
	do
	{
		option=upper_getchar();
		if(option=='Y')
		{	
			*book_p2=book;
			*history_p2=history;
			puts("��¼�룡");
			if(history.penalty)
				printf("���ν������ڣ�\n����%lf",history.penalty);
			system("pause");
		}
	}while(!(option=='Y'||option=='N'));
}
//*********************������*********************
int main(void)
{
	char option;
	do
	{
		puts("************ͼ�����ϵͳ************");
		puts("A.ѧ����Ϣ����");
		puts("B.ͼ����Ϣ����");
		puts("C.��/����");
		puts("D.�ۺϲ�ѯ");
		puts("E.�������/��ʼ��");
		puts("Q.�˳�");
		puts("������ѡ����س���ȷ�ϣ���Сд����");
		switch (option = upper_getchar())
		{
		case 'A':stu_management(); write_file();break;
		case 'B':book_management(); write_file();break;
		case 'C':borrow_or_return_book();write_file(); break;
		case 'D':query();break;
		case 'E':freeall();initialization();break;
		case 'Q':break;
		default:puts("\n\n�������Ӧ������Ӣ����ĸѡ�����");
				system("Pause");
				break;
		}
		system("cls"); //��һ�β�������
	} while (option != 'Q');
	freeall();
	for(int i=0;i<6;i++)//�˳���Ч
	{
		for(int j=0;j<i;j++)
			printf("\n");
		puts("��лʹ�ã�");
		Sleep(500);
		system("cls");
	}
	return 0;
}
