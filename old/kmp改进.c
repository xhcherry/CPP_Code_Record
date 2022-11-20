#include<stdio.h>
#include<stdlib.h>
#define N 20
char c[N];
void get_nextval(char *c, int *nextval, int c_len) {
	int i = 1, j = 0;
	nextval[i] = 0;
	while (i < c_len) {
		if (j == 0 || c[i - 1] == c[j - 1]) {
			i++;
			j++;
			if (c[i - 1] == c[j - 1])
				nextval[i] = nextval[j];
			else if(c[i - 1] != c[j - 1])
				nextval[i] = j;
		} else {
			j = nextval[j];
		}
	}
}
//a
int main() {
	int nextval[N];
	int i = 1,j;
	c[1] = getchar();
	while (c[i] != '\n' && i <= N) {
		c[++i] = getchar();
	}
	get_nextval(c+1, nextval, i - 1);
	for (j = 1; j <= i - 1; j++)
		printf("%d ",nextval[j]);
	return 0;
}

