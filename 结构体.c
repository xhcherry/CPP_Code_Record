#include<stdio.h>
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
}book = {
	"��һ�顷",
	"����",
	48.8 ,
	{2017, 11, 11},
	"������"
}; 
int main(void)
{
	struct Book *pt;
	pt = &book;
	printf("���� ��%s\n",book.title);
	printf("���� ��%s\n",book.author);
	printf("�ۼ� ��%.2f\n",book.price);
	printf("����ʱ�� ��%d.%d.%d\n",book.date.year,book.date.month,book.date.day);
	printf("������ ��%s\n",book.publisher);
	return 0;
}
