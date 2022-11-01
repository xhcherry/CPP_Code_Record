#include <stdio.h>		// ����������������ļ�
#include <stdlib.h>		// malloc()��������ͷ�ļ�
#include <string.h>		// strcmp()��������ͷ�ļ�
#include <conio.h>
// �������״̬
#define OVERFLOW -2
#define ERROR 0
#define OK 1
typedef int Status;

#define MAXSIZE 50	// ͼ�����ܴﵽ����󳤶�

// �Զ���ͼ�����ͣ���3����Ա���ԣ�ISBN���������۸�
typedef struct			// ͼ����Ϣ����	
{
	char isbn[14];		// ISBN��
	char bname[20];		// ����
	float price;		// �۸�
}Book;

// �˳���������Ԫ������Ϊͼ������
typedef Book ElemType;

// �Զ���˳������ͣ���������Ա����Ա1Ϊ�洢˳�������飬��Ա2Ϊ˳���������Ԫ�صĳ���
typedef struct
{
	ElemType* data;
	int length;				// ˳���ĵ�ǰ����
}SeqList;		// ͼ����˳��洢�ṹ����ΪSeqList

/*	˳���ĳ�ʼ��
	������һ���ձ���LΪָ��˳����ָ�������ָ��̬����Ĵ洢�ռ䣬
	Ȼ�󽫱���length����Ϊ0����ʾ����û������Ԫ�ء�
*/
Status Init_SeqList(SeqList* L)	// ˳���ĳ�ʼ��
{
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); //Ϊ˳������ռ�
	if (!L->data)		// �洢����ʧ��
		exit(OVERFLOW);
	L->length = 0;		// �ձ���Ϊ0
	return OK;
}

/*  �������Ա�L  */
void Destroy_SeqList(SeqList* L)
{
	if ((*L).data)   // �ͷŴ洢�ռ�
		free((*L).data);
	L->length = 0;
}


/*  �����Ա�L�ĳ���  */
int GetLength(SeqList L)
{
	return L.length;
}

/* �ж����Ա�L�Ƿ�Ϊ�ձ�  */
int IsEmpty(SeqList L)
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

/*	��������
	�����Ա�L�е�i������Ԫ��֮ǰ��������Ԫ��x
	��˳���L�ĵ�i��1<=i<=length+1����λ���ϲ����µ�Ԫ��x��
	���iֵ����ȷ������ʾ��Ӧ������Ϣ������˳���ԭ����i��Ԫ�ؼ��Ժ�Ԫ��
	������һ��λ�ã��ڳ�ԭ��i��λ��Ϊ��λ�ã�������Ԫ�ء����Ա�ĳ�������1��
*/
Status Insert_SeqList(SeqList* L, int i, ElemType x)
{
	int j;
	if (i<1 || i>L->length + 1)		// ������λ�õ���ȷ��
	{
		printf("����λ�÷Ƿ����������������\n");
		return ERROR;
	}
	if (L->length == MAXSIZE)
	{
		printf("���Ա��������޷�����\n");
		return ERROR;
	}
	for (j = L->length; j >= i; j--)	// ����ƶ������һ��Ԫ�ص��±�ΪL->length-1
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = x;			// ��Ԫ�ز���
	L->length++;				// ˳���������1
	return OK;
}

/*	ɾ������
	ɾ��˳���L�ĵ�i��1<=i<=length��������Ԫ�ء�
	���iֵ����ȷ������ʾ��Ӧ������Ϣ������˳���ԭ����i��Ԫ���Ժ��Ԫ�ؾ�ǰ��һ��λ�á�
	���˳����ȼ�1��
*/
Status Delete_SeqList(SeqList* L, int i)
{
	int j;
	if (i<1 || i>L->length)			// ���ձ�ɾ��λ�õĺϷ���
		return ERROR;
	for (j = i; j < L->length; j++)			// ��˳���ԭ����i��Ԫ�ص����һ��Ԫ�أ�L->data[length-1]����ǰ��һ��λ��
		L->data[j - 1] = L->data[j];
	L->length--;					// ˳����ȼ�1
	return OK;
}

/* ����Ų��ң�����λ��i��ȡ��Ӧλ������Ԫ�ص�����
   ��ȡ˳���L�еĵ�i��Ԫ�أ�����e��
 */
int GetElem(SeqList L, int i, ElemType* e)
{
	if (i<1 || i>L.length)  // �ж�iֵ�Ƿ����������������ERROR
		return ERROR;
	*e = L.data[i - 1];      // ��i-1�ĵ�Ԫ�洢�ŵ�i������
	return OK;
}

/* ��ֵ���ң�����ָ�����ݻ�ȡ�������ڵ�λ��
   �ڴ˸���ISBN�Ž���ͼ����ң����ҵ�������ͼ����ţ����Ҳ���������0
*/
int LocateElemSno_SeqList(SeqList L, char isbn[]) { //�㷨2.3 ��ѧ����˳���Ĳ���ͼ���¼
	//˳���Ĳ���
	int i;
	for (i = 0; i < L.length; i++)
		if (strcmp(L.data[i].isbn, isbn) == 0)
			return i + 1;//���ҳɹ����������i+1
	return 0;//����ʧ�ܣ�����0
}

void Print_SeqList(SeqList L)	// ���˳����ÿһ������Ԫ��
{
	int i;
	printf("��ǰͼ����Ϣ��˳���������\n");
	for (i = 0; i < L.length; i++)
		printf("%s\t%s\t%f\n", L.data[i].isbn, L.data[i].bname, L.data[i].price);
	printf("\n");
}

/* ���˳����е����� */
int Clear_SeqList(SeqList* L)
{
	printf("������Ա�����\n");
	L->length = 0; //�����Ա�ĳ�����Ϊ0
	return OK;
}

/* ���ļ��ж�ͼ����Ϣ�����Ա�L�� */
Status ReadFile_SeqList(SeqList* L)
{
	int i;
	FILE* fp;

	i = 0;
	fp = fopen("book.txt", "r");
	if (!fp) {
		printf("����δ�ҵ��ļ���\n");
		return ERROR;
	}
	printf("���ļ���������\n");
	fread(&(*L).length, sizeof(int), 1, fp);
	fread(&((*L).data[i]), sizeof(ElemType), (*L).length, fp);
	printf("�� book.txt �е���ͼ����Ϣ���\n\n");
	fclose(fp);
	return OK;
}


/* ����˳�����ͼ����Ϣ���ļ��� */
Status Save_SeqList(SeqList* L)
{
	int i;
	FILE* fp;
	if ((fp = fopen("book.txt", "w")) == NULL)
	{
		printf("\nͼ����Ϣ�ļ���ʧ�ܣ��밴���������!\n");
		system("pause");
		return ERROR;
	}
	fwrite(&L->length, sizeof(int), 1, fp);

	for (i = 0; i < L->length; i++)
		fwrite(L->data, sizeof(ElemType), L->length, fp);
	fclose(fp);
	printf("ͼ����Ϣ���浽�ļ���ϣ��밴���������\n");
	system("pause");
	return OK;
}

void menu() {
	printf("\t\t  С��ͼ����Ϣ����ϵͳ \n");
	printf("\t\t  1.��ʼ��˳��� \n");
	printf("\t\t  2.�����˳�����ͼ���¼\n");
	printf("\t\t  3.����Ų���ͼ���¼\n");
	printf("\t\t  4.�����ɾ��ͼ���¼\n");
	printf("\t\t  5.����Ų���ͼ����Ϣ\n");
	printf("\t\t  6.��ISBN����ͼ����Ϣ\n");
	printf("\t\t  7.������Ա�\n");
	printf("\t\t  8.���ļ��ж�ͼ����Ϣ\n");
	printf("\t\t  9.����ͼ����Ϣ\n");
	printf("\t\t  0.����\n");
	printf("\t\t  886.�˳�\n\n");
}

int main() {
	SeqList L;
	int i = 0, temp, choose;
	char isbn[10];
	ElemType e;

	menu();

	choose = -1;
	while (choose != 886) {
		printf("��ѡ�����:");
		scanf("%d", &choose);
		switch (choose) {
		case 1: // ��ʼ��˳���
			if (Init_SeqList(&L))
				printf("�ɹ�����˳���\n\n");
			else
				printf("˳�����ʧ��\n\n");
			break;
		case 2: // ˳�����
			Print_SeqList(L);
			break;
		case 3: //˳���Ĳ���
			printf("����������λ�ú�ͼ����Ϣ����ʽ��������λ�� ISBN ͼ���� �۸��ÿո��������:\n");
			scanf("%d", &i);
			scanf("%s%s%f", e.isbn, e.bname, &e.price);
			if (Insert_SeqList(&L, i, e))
				printf("����ɹ���\n\n");
			else
				printf("����ʧ�ܣ�\n\n");
			break;
		case 4:	// ˳����ɾ��
			printf("��������Ҫɾ����ͼ�����ţ�");
			scanf("%d", &i);
			if (Delete_SeqList(&L, i))
				printf("ɾ���ɹ�!\n\n");
			else
				printf("ɾ��ʧ��!\n\n");
			break;
		case 5: { // ����Ų���
			printf("������һ��λ������ȡֵ��\n");
			scanf("%d", &i);
			temp = GetElem(L, i, &e);
			if (temp != 0) {
				printf("���ҳɹ�\n");
				printf("��%d��ͼ�����Ϣ�ǣ�\n", i);
				printf("%s\t%s\t%f\n", e.isbn, e.bname, e.price);
			}
			else
				printf("����ʧ�ܣ�λ�ó�����Χ\n\n");
		}
			  break;
		case 6:	// ��ISBNֵ����
			printf("��������Ҫ��ѯ��ͼ��ISBN:");
			scanf("%s", isbn);
			temp = LocateElemSno_SeqList(L, isbn);
			if (temp != 0) {
				printf("���ҳɹ�\n");
				printf("��ѧ�Ŷ�Ӧ��ͼ��Ϊ��%s\t%s\t%f\n\n", L.data[temp - 1].isbn, L.data[temp - 1].bname, L.data[temp - 1].price);
			}
			else {
				printf("����ʧ�ܣ�û��ISBN��Ϊ%s��Ӧ��ͼ��\n\n", isbn);
			}
			break;
		case 7: // ���˳���
			Clear_SeqList(&L);
			break;

		case 8:  // ���ļ��е���ͼ����Ϣ��˳�����
			ReadFile_SeqList(&L);
			break;
		case 9: // ����˳���
			Save_SeqList(&L);
			break;
		case 0: // ����
			system("CLS");
			menu();
			break;
		}
	}
	return 0;
}
