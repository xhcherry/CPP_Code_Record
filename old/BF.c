#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxsize 10
typedef struct {
	char ch[Maxsize+1];
	int length;
} SString;
int BF(SString,SString,int);
int main() {
	SString S,T;
	int k=0;
	printf("输入主串:");
	scanf("%s",S.ch);
	printf("输入模式串:");
	scanf("%s",T.ch);
	S.length=strlen(S.ch);
	T.length=strlen(T.ch);
	k=BF(S,T,0);
	printf("匹配成功的位置 %d",k);
}
int BF(SString S,SString T,int pos) {
	int i,j;
	i=pos;
	j=0;
	while(i<S.length&&j<T.length) {
		if(S.ch[i]==T.ch[j]) {
			i++;
			j++;
		} else {
			i=i-j+1;
			j=0;
		}
	}
	if(j>T.length-1)
		return i-T.length+1;
	else
		return 0;
}
