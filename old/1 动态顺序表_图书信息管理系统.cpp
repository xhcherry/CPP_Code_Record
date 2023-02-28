#include <stdio.h>		// 输入输出函数所有文件
#include <stdlib.h>		// malloc()函数所在头文件
#include <string.h>		// strcmp()函数所在头文件
#include <conio.h>
// 函数结果状态
#define OVERFLOW -2
#define ERROR 0
#define OK 1
typedef int Status;

#define MAXSIZE 50	// 图书表可能达到的最大长度

// 自定义图书类型，有3个成员属性，ISBN、书名、价格
typedef struct			// 图书信息定义	
{
	char isbn[14];		// ISBN号
	char bname[20];		// 书名
	float price;		// 价格
}Book;

// 此程序中数据元素类型为图书类型
typedef Book ElemType;

// 自定义顺序表类型，有两个成员，成员1为存储顺序表的数组，成员2为顺序表中数据元素的长度
typedef struct
{
	ElemType* data;
	int length;				// 顺序表的当前长度
}SeqList;		// 图书表的顺序存储结构类型为SeqList

/*	顺序表的初始化
	即构造一个空表。设L为指向顺序表的指针参数，指向动态分配的存储空间，
	然后将表中length设置为0，表示表中没有数据元素。
*/
Status Init_SeqList(SeqList* L)	// 顺序表的初始化
{
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); //为顺序表分配空间
	if (!L->data)		// 存储分配失败
		exit(OVERFLOW);
	L->length = 0;		// 空表长度为0
	return OK;
}

/*  销毁线性表L  */
void Destroy_SeqList(SeqList* L)
{
	if ((*L).data)   // 释放存储空间
		free((*L).data);
	L->length = 0;
}


/*  求线性表L的长度  */
int GetLength(SeqList L)
{
	return L.length;
}

/* 判断线性表L是否为空表  */
int IsEmpty(SeqList L)
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

/*	插入运算
	在线性表L中第i个数据元素之前插入数据元素x
	在顺序表L的第i（1<=i<=length+1）个位置上插入新的元素x。
	如果i值不正确，则显示相应错误信息；否则将顺序表原来第i个元素及以后元素
	均后移一个位置，腾出原第i个位置为空位置，插入新元素。线性表的长度增加1。
*/
Status Insert_SeqList(SeqList* L, int i, ElemType x)
{
	int j;
	if (i<1 || i>L->length + 1)		// 检查插入位置的正确性
	{
		printf("插入位置非法，请检查后再做操作\n");
		return ERROR;
	}
	if (L->length == MAXSIZE)
	{
		printf("线性表已满，无法插入\n");
		return ERROR;
	}
	for (j = L->length; j >= i; j--)	// 向后移动；最后一个元素的下标为L->length-1
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = x;			// 新元素插入
	L->length++;				// 顺序表长度增加1
	return OK;
}

/*	删除运算
	删除顺序表L的第i（1<=i<=length）个数据元素。
	如果i值不正确，则显示相应错误信息；否则将顺序表原来第i个元素以后的元素均前移一个位置。
	最后顺序表长度减1。
*/
Status Delete_SeqList(SeqList* L, int i)
{
	int j;
	if (i<1 || i>L->length)			// 检查空表及删除位置的合法性
		return ERROR;
	for (j = i; j < L->length; j++)			// 将顺序表原来第i个元素到最后一个元素（L->data[length-1]）均前移一个位置
		L->data[j - 1] = L->data[j];
	L->length--;					// 顺序表长度减1
	return OK;
}

/* 按序号查找，根据位置i获取相应位置数据元素的内容
   获取顺序表L中的第i个元素，存在e中
 */
int GetElem(SeqList L, int i, ElemType* e)
{
	if (i<1 || i>L.length)  // 判断i值是否合理，若不合理，返回ERROR
		return ERROR;
	*e = L.data[i - 1];      // 第i-1的单元存储着第i个数据
	return OK;
}

/* 按值查找，根据指定数据获取数据所在的位置
   在此根据ISBN号进行图书查找，若找到，返回图书序号；若找不到，返回0
*/
int LocateElemSno_SeqList(SeqList L, char isbn[]) { //算法2.3 按学号在顺序表的查找图书记录
	//顺序表的查找
	int i;
	for (i = 0; i < L.length; i++)
		if (strcmp(L.data[i].isbn, isbn) == 0)
			return i + 1;//查找成功，返回序号i+1
	return 0;//查找失败，返回0
}

void Print_SeqList(SeqList L)	// 输出顺序表的每一个数据元素
{
	int i;
	printf("当前图书信息表（顺序表）读出：\n");
	for (i = 0; i < L.length; i++)
		printf("%s\t%s\t%f\n", L.data[i].isbn, L.data[i].bname, L.data[i].price);
	printf("\n");
}

/* 清空顺序表中的内容 */
int Clear_SeqList(SeqList* L)
{
	printf("清空线性表数据\n");
	L->length = 0; //将线性表的长度置为0
	return OK;
}

/* 从文件中读图书信息到线性表L中 */
Status ReadFile_SeqList(SeqList* L)
{
	int i;
	FILE* fp;

	i = 0;
	fp = fopen("book.txt", "r");
	if (!fp) {
		printf("错误！未找到文件！\n");
		return ERROR;
	}
	printf("从文件读入数据\n");
	fread(&(*L).length, sizeof(int), 1, fp);
	fread(&((*L).data[i]), sizeof(ElemType), (*L).length, fp);
	printf("从 book.txt 中导入图书信息完毕\n\n");
	fclose(fp);
	return OK;
}


/* 保存顺序表中图书信息到文件中 */
Status Save_SeqList(SeqList* L)
{
	int i;
	FILE* fp;
	if ((fp = fopen("book.txt", "w")) == NULL)
	{
		printf("\n图书信息文件打开失败，请按任意键返回!\n");
		system("pause");
		return ERROR;
	}
	fwrite(&L->length, sizeof(int), 1, fp);

	for (i = 0; i < L->length; i++)
		fwrite(L->data, sizeof(ElemType), L->length, fp);
	fclose(fp);
	printf("图书信息保存到文件完毕，请按任意键返回\n");
	system("pause");
	return OK;
}

void menu() {
	printf("\t\t  小型图书信息管理系统 \n");
	printf("\t\t  1.初始化顺序表 \n");
	printf("\t\t  2.按序号顺序输出图书记录\n");
	printf("\t\t  3.按序号插入图书记录\n");
	printf("\t\t  4.按序号删除图书记录\n");
	printf("\t\t  5.按序号查找图书信息\n");
	printf("\t\t  6.按ISBN查找图书信息\n");
	printf("\t\t  7.清空线性表\n");
	printf("\t\t  8.从文件中读图书信息\n");
	printf("\t\t  9.保存图书信息\n");
	printf("\t\t  0.清屏\n");
	printf("\t\t  886.退出\n\n");
}

int main() {
	SeqList L;
	int i = 0, temp, choose;
	char isbn[10];
	ElemType e;

	menu();

	choose = -1;
	while (choose != 886) {
		printf("请选择操作:");
		scanf("%d", &choose);
		switch (choose) {
		case 1: // 初始化顺序表
			if (Init_SeqList(&L))
				printf("成功建立顺序表\n\n");
			else
				printf("顺序表建立失败\n\n");
			break;
		case 2: // 顺序输出
			Print_SeqList(L);
			break;
		case 3: //顺序表的插入
			printf("请输入插入的位置和图书信息，格式：“插入位置 ISBN 图书名 价格（用空格隔开）”:\n");
			scanf("%d", &i);
			scanf("%s%s%f", e.isbn, e.bname, &e.price);
			if (Insert_SeqList(&L, i, e))
				printf("插入成功！\n\n");
			else
				printf("插入失败！\n\n");
			break;
		case 4:	// 顺序表的删除
			printf("请输入所要删除的图书的序号：");
			scanf("%d", &i);
			if (Delete_SeqList(&L, i))
				printf("删除成功!\n\n");
			else
				printf("删除失败!\n\n");
			break;
		case 5: { // 按序号查找
			printf("请输入一个位置用来取值：\n");
			scanf("%d", &i);
			temp = GetElem(L, i, &e);
			if (temp != 0) {
				printf("查找成功\n");
				printf("第%d个图书的信息是：\n", i);
				printf("%s\t%s\t%f\n", e.isbn, e.bname, e.price);
			}
			else
				printf("查找失败！位置超出范围\n\n");
		}
			  break;
		case 6:	// 按ISBN值查找
			printf("请输入所要查询的图书ISBN:");
			scanf("%s", isbn);
			temp = LocateElemSno_SeqList(L, isbn);
			if (temp != 0) {
				printf("查找成功\n");
				printf("该学号对应的图书为：%s\t%s\t%f\n\n", L.data[temp - 1].isbn, L.data[temp - 1].bname, L.data[temp - 1].price);
			}
			else {
				printf("查找失败！没有ISBN号为%s对应的图书\n\n", isbn);
			}
			break;
		case 7: // 清空顺序表
			Clear_SeqList(&L);
			break;

		case 8:  // 从文件中导入图书信息到顺序表中
			ReadFile_SeqList(&L);
			break;
		case 9: // 保存顺序表
			Save_SeqList(&L);
			break;
		case 0: // 清屏
			system("CLS");
			menu();
			break;
		}
	}
	return 0;
}
