#include<stdio.h>

int count(int s_n,int k_m) {
	int count = 0,sum,i,j,score,max;
	for(j = 1; j <= s_n; j++) {
		sum = 0;
		printf("第%d个学生\n",j);
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
	printf("学生数:");
	scanf("%d",&stu_n);
	printf("科目数:");
	scanf("%d",&kech_n);
	printf("平均分不及格的有%d人",count(stu_n,kech_n));
}
