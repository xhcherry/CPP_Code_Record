#include<stdio.h>

int count(int s_n,int k_m) {
	int count = 0,sum,i,j,score,max;
	for(j = 1; j <= s_n; j++) {
		sum = 0;
		printf("��%d��ѧ��\n",j);
		for(i = 1; i <= k_m; i++) {
			scanf("%d",&score);
			sum += score;
		}
		if(sum / k_m < 60)
			count++;
	}
	return count;
}

void main() {
	int stu_n,kech_n;
	printf("ѧ����:");
	scanf("%d",&stu_n);
	printf("��Ŀ��:");
	scanf("%d",&kech_n);
	printf("ƽ���ֲ��������%d��",count(stu_n,kech_n));
}
