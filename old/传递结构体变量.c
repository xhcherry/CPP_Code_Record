#include<stdio.h>
#include<stdlib.h>
	struct Date
	{
		int year;
		int month;
		int day;
	};
	struct Book
	{
		char title[128];
		char author[40];
		float price;
		struct Date date;
		char publisher[40];
	};
	void getInput(struct Book *book);
	void printBook(struct Book *book);
	void getInput(struct Book *book)
	{
		printf("������������");
		scanf("%s",book->title);
		printf("���������ߣ�");
		scanf("%s",book->author);
		printf("�������ۼۣ�");
		scanf("%f",&book->price);
		printf("������������ڣ�");
		scanf("%d.%d.%d",&book->date.year,&book->date.month,&book->date.day);
		printf("����������磺");
		scanf("%s",book->publisher);
	}
	void printBook(struct Book *book)
	{
		printf("������%s\n",book->title);
		printf("���ߣ�%s\n",book->author);
		printf("�ۼۣ�%.2f\n",book->price);
		printf("����ʱ�� ��%d.%d.%d\n",book->date.year,book->date.month,book->date.day);
		printf("������ ��%s\n",book->publisher);
	} 
 
	int main(void)
{
	{
		struct Book *b1,*b2;
		b1 = (struct Book *)malloc(sizeof(struct Book));
		b2 = (struct Book *)malloc(sizeof(struct Book));
		if(b1 == NULL || b2 == NULL)
		{
			printf("�ڴ����ʧ�ܣ�");
			exit(1);
		}
		printf("��¼���һ�������Ϣ...\n");
		getInput(b1);
		putchar('\n');
		printf("��¼��ڶ��������Ϣ...\n");
		getInput(b2);
		printf("\n\n¼����ϣ����ڿ�ʼ��ӡ��֤...\n\n");
		printf("��ӡ��һ�������Ϣ...\n");
		printBook(b1);
		putchar('\n'); 
		printf("��ӡ�ڶ��������Ϣ...\n");
		printBook(b2); 
		free(b1);
		free(b2);
		return 0;
	}
}
