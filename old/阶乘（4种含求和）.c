#include<stdio.h>
#include<string.h>
void main() {
	int n = 1;
	long current = 1,sum = 0;
	while(n < 5) {
		current *= n;
		sum += current;
		n++;
	}
	printf("%d",sum);
}




#include<stdio.h>
#include<string.h>
int  factorial(int n);
void main() {
	int n = 1;
	long sum = 0;
	while(n < 5) {
		sum += factorial(n);
		n++;
	}
	printf("%d",sum);
}
int factorial(int n) {
	long s = 1;
	if(n == 1)return s;
	else
		return n*factorial(n-1);
}




#include<stdio.h>
#include<string.h>
int  factorial(int n);
void main() {
	int n = 1;
	long sum = 0;
	while(n < 5) {
		sum += factorial(n);
		n++;
	}
	printf("%d",sum);
}
int factorial(int n) {
	static long s = 1;
	s *= n;
	return s;
}




#include<stdio.h>
#include<string.h>
int  factorial(int n);
void main() {
	int n = 1;
	long sum = 0;
	while(n < 5) {
		sum += factorial(n);
		n++;
	}
	printf("%d",sum);
}
int factorial(int n) {
	int i;
	long s = 1;
	for(i = 1; i <= n; i++)
		s *= i;
	return s;
}


//求和
#include<stdio.h>
int main() {
	int n,i;
	long long fact=1,sum=0;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		fact*=i;
		sum+=fact;
	}
	printf("%lld\n",sum);
	return 0;
}
