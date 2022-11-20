#include<stdio.h>
int main() {
	int n=20,i;
	long long fact=1,sum=0;
	for(i=1; i<=n; i++) {
		fact*=i;
		sum+=fact;
	}
	printf("%lld\n",sum);
	return 0;
}
