#include<stdio.h>
int f(int n);
void main() {
	int num;
	while(1) {
		scanf("%d",&num);
		if(num==0)break;
		else if(num==f(num))
			printf("是回文数\n");
		else printf("不是回文数\n");
	}
}
int f(int n) {
	int j,res=0;
	while(n) {
		res=res*10+n%10;
		n/=10;
	}
	return res;
}
