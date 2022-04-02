#include<stdio.h>
int count(int s_n,int k_m) {
	int i,j,score,count = 0,sum,max,bukao,h_bk = 0,s_bk,h_kc = 0,s_kc,dk_kc,ds_kc,dk,max1 = 0,max2 = 0,max3 = 0,m1,m2,m3;
	for(j = 1; j <= s_n; j++) {
		sum = 0;
		max = 0;
		bukao = 0;
		printf("请输入第%d个学生的各科成绩：",j);
		for(i = 1; i <= k_m; i++) {
			scanf("%d",&score);
			sum += score;
			if(max1 < sum) {
				max3 = max2;
				m3 = m2;
				max2 = max1;
				m2 = m1;
				max1 = sum;
				m1 = j;
			} else if(max2<sum) {
				max3 = max2;
				m3 = m2;
				max2 = sum;
				m2 = j;
			} else if(max3 < sum) {
				max3 = sum;
				m3 = j;
			}
			if(max < score)
				max = score;
			if(score < 60)
				bukao++;
			if(score > dk_kc) {
				dk_kc = score;
				ds_kc = j;
				dk = i;
			}
			printf("第%d个学生第%d门的分数为%d\n",j,i,score);
		}
		printf("第%d个学生需要补考%d门\n",j,bukao);
		printf("第%d个学生最高分数为%d\n",j,max);
		printf("第%d个学生总分数为%d\n",j,sum);
		if(sum / k_m < 60)
			count++;
		if(bukao > h_bk) {
			s_bk = j;
			h_bk = bukao;
		}
		if(max > h_kc) {
			h_kc = max;
			s_kc = j;
		}
	}
	printf("第%d个学生补考最多,为%d门 \n",s_bk,h_bk);
	printf("第%d个学生有最高分%d \n",s_kc,h_kc);
	printf("第%d个学生第%d门课为最高分%d \n",ds_kc,dk,dk_kc);
	printf("前三名学生：第%d个分数%d,第%d个分数%d,第%d个分数%d\n",m1,max1,m2,max2,m3,max3);
	return count;
}

void main() {
	int stu_n,kech_n;
	printf("请输入有多少个学生:");
	scanf("%d",&stu_n);
	printf("请输入多少门课:");
	scanf("%d",&kech_n);
	printf("平均分不及格有%d个人\n",count(stu_n,kech_n));
}
