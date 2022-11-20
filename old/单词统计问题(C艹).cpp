//输入为一行字符串，即要统计的文本。
//输出由若干行组成，第一行是一个整数，表示单词的个数，从第二行开始，每行由字符串、冒号、整数组成，其中字符串是一个出现在文本中的单词，整数则是该单词在文本中出现的次数。
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main() {
	char a[1000];
	int b[1000];
	string str[5000];
	int n,i,j,k,h;
	gets(a);
	n=strlen(a);
	int count=0;
	for(i=0; i<n; i++) {
		if(a[i]=='\40')
			count++;
	}
	cout<<count+1<<endl;
	j=0;
	int temp=0,abc;
	for(i=0; i<n; i++) {
		abc=i;
		if(a[i]=='\40') {
			for(k=temp; k<abc; k++) {
				str[j]=str[j]+a[k];
			}
			temp=i+1;
			j++;
			if(j==count) {
				for(h=i+1; h<n; h++)
					str[j]=str[j]+a[h];
			}
		}
	}
	int index;
	for(i=0; i<count; i++) {
		index=i;
		for(j=i+1; j<count+1; j++) {
			if(str[index]>str[j])
				index=j;
		}
		if(index!=i) {
			str[100]=str[i];
			str[i]=str[index];
			str[index]=str[100];
		}

	}
	int c[100];
	for(i=0; i<=count; i++) {

		if(str[i]==a)
			continue;
		c[i]=1;
		for(j=i+1; j<count+1; j++) {
			if(str[i]==str[j]) {
				str[j]=a;
				c[i]++;
			}
		}
	}
	for(i=0; i<count+1; i++) {
		if(str[i]!=a) {
			cout<<str[i]<<":"<<c[i]<<endl;
		}
	}

	return 0;
}
