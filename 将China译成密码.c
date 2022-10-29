顺序结构
#include<stdio.h>
int main(){
  char c1='C',c2='h',c3='i',c4='n',c5='a';
  c1+=4;
  c2+=4;
  c3+=4;
  c4+=4;
  c5+=4;
  printf("%c%c%c%c%c",c1,c2,c3,c4,c5);
  printf("\n");
  return 0;
}



数组
#include<stdio.h>
int main() {
	int i;
	char a[5]= {'C','h','i','n','a'};
	for(i=0; i<5; i++) {
		a[i]+=4;
		printf("%c",a[i]);
	}
}



函数的模块化设计
#include <stdio.h>
#include <stdlib.h>
void encrypt(char pw[], int c);                       //定义加密函数
int main(){
	char c[5];
	for (int i = 0; i < 5; scanf("%c", &c[i]), i++);  //输入5个字符
	encrypt(c, 5);                                    //加密
	puts(c);
	system("pause");
	return 0;
}
//加密函数
void encrypt(char pw[], int c){
	for (int i = 0; i < c; pw[i] += 4, i++);
	pw[i] = '\0';
}




动态分配内存
#include <stdio.h>
#include <stdlib.h>
void input(char *p);
void complie(char *p);
int main(){
	char *password=(char*)malloc(30*sizeof(char));
	input(password);
	complie(password);
	system("pause");
	return 0;
}
void input(char *p){
	printf("Enter word: ");
	scanf("%s", p);
}
void complie(char *p){
	char *s;
	for(s=p; *s!='\0'; s++)
		*s+=4;
	printf("result: %s\n", p);
}
