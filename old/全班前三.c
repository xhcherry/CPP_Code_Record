#include<stdio.h>
#include<stdlib.h>
int count(int s_n,int k_m) {
	int count = 0,i,j,score,max;
	for(j = 1; j <= s_n; j++) {
		int sum = 0;
		printf("第%d个学生\n",j);
		for(i = 1; i <= k_m; i++) {
			scanf("%d",&score);
			sum += score;
		}
		
	}
	return count;
}

int main() {
	int stu_n,kech_n;
	printf("学生数:");
	scanf("%d",&stu_n);
	printf("科目数:");
	scanf("%d",&kech_n);
	printf("",count(stu_n,kech_n));
	system("pause");
}
