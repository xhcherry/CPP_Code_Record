#include <stdio.h>    
#include <process.h>       
void Initbitmap(int map[8][8])
{
	int cylinder, track, sector;
	char choice = 'Y';
	printf("��ʼ��λ��ͼ...\n");
	while (choice == 'y' || choice == 'Y')
	{
		printf("����ţ�0~7��:");
		scanf("%d", &cylinder);
		for (; cylinder < 0 || cylinder>7;)
		{
			printf("���������������������룡\n");
			printf("����ţ�0~7��:");
			scanf("%d", &cylinder);
		}
		printf("�ŵ��ţ�0~1��:");
		scanf("%d", &track);
		for (; track < 0 || track>1;)
		{
			printf("�ŵ����������ݴ������������룡\n");
			printf("�ŵ��ţ�0~1��:");
			scanf("%d", &track);
		}
		printf("�����¼�ţ�0~3��:");
		scanf("%d", &sector);
		for (; sector < 0 || sector>3;)
		{
			printf("�����¼���������ݴ������������룡\n");
			printf("�����¼�ţ�0~3��:");
			scanf("%d", &sector);
		}
		map[cylinder][4 * track + sector] = 1;
		printf("contiune?(y/n)");
		getchar();
		scanf("%c", &choice);
	}
}
void allocate(int map[8][8])
{
	int i, j;

	int flag = 0;
	int cylinder, track, sector;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			if (map[i][j] == 0) { map[i][j] = 1; flag = 1; break; }
		if (flag == 1) break;
	}
	if (flag == 1)
	{
		cylinder = i;
		track = j / 4;
		sector = j % 4;
		printf("���䵽������š��ŵ��š������¼��");
		printf("%d\t%d\t%d", cylinder, track, sector);
		printf("\n");
	}
	else printf("�ռ䲻�㣬����ʧ��!");
}

void reclaim(int map[8][8])
{
	int cylinder, track, sector;
	printf("�����:");
	scanf("%d", &cylinder);
	printf("�ŵ���:");
	scanf("%d", &track);
	printf("�����¼��:");
	scanf("%d", &sector);
	if (map[cylinder][4 * track + sector] == 0)
	{
		printf("�˿�Ϊδ����飡���ճ���");
		getchar();
	}
	else
	{
		map[cylinder][4 * track + sector] = 0;
		printf("���տ��Ӧ���ֽں�:%4d\tλ��:%4d\n", cylinder, 4 * track + sector);
	}
}
void main()
{
	int bitmap[8][8] = { 0 };
	int i, j;
	int choice;
	Initbitmap(bitmap);
	while (1)
	{
		printf("\n������ѡ��:");
		printf("1--���䣬2---���գ�3--��ʾλʾͼ��0--�˳�\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:allocate(bitmap); break;
		case 2:reclaim(bitmap); break;
		case 3:for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
				printf("%8d", bitmap[i][j]);
			printf("\n");
		}
			  break;
		case 0:exit(0);
		default:printf("����ѡ��");
			break;
		}
	}
}
