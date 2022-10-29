#include<stdio.h>
#include<stdlib.h>
#define N 20
char c[N];
void get_next(char* c, int* next, int c_len) {
	int i = 1, j = 0;
	next[i] = 0;
	while (i < c_len) {
		if (j == 0 || c[i - 1] == c[j - 1]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
int main() {
	int next[N];
	int i = 1, j;
	c[1] = getchar();
	while (c[i] != '\n' && i <= N) {
		c[++i] = getchar();
	}
	get_next(c + 1, next, i - 1);
	for (j = 1; j <= i - 1; j++)
		printf("%d ", next[j]);
	return 0;
}

