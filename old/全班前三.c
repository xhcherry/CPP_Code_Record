#include<stdio.h>
#include<stdlib.h>
int count(int s_n,int k_m) {
	int count = 0,i,j,score,max;
	for(j = 1; j <= s_n; j++) {
		int sum = 0;
		printf("��%d��ѧ��\n",j);
		for(i = 1; i <= k_m; i++) {
			scanf("%d",&score);
			sum += score;
		}
		
	}
	return count;
}

int main() {
	int stu_n,kech_n;
	printf("ѧ����:");
	scanf("%d",&stu_n);
	printf("��Ŀ��:");
	scanf("%d",&kech_n);
	printf("",count(stu_n,kech_n));
	system("pause");
}
