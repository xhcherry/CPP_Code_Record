#include <stdio.h>
#define N 50
int data[N][N];
int dp[N][N];
int n;
void tower_walk() {
	for (int i = 0; i < n; ++i) {
		dp[n - 1][i] = data[n - 1][i];
	}
	int temp_max;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			if(dp[i + 1][j] > dp[i + 1][j + 1]) {
				temp_max = dp[i + 1][j];
			} else {
				temp_max =dp[i + 1][j + 1];
			}
			dp[i][j] = temp_max + data[i][j];
		}
	}
}

void print_result() {
	printf("最大路径和：%d\n",dp[0][0]);
	printf("最大路径：%d",data[0][0]);
	int node_value;
	int j = 0;
	for (int i = 1; i < n; ++i) {
		node_value = dp[i - 1][j] - data[i - 1][j];
		if (node_value == dp[i][j + 1]) ++j;
		printf("->%d",data[i][j]);
	}
}

int main() {
	printf("输入塔的层数n=");
	scanf("%d",&n);
	printf("输入塔的节点数据(第i层有i个节点)：\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			scanf("%d",&data[i][j]);
		}
	}
	tower_walk();
	print_result();
}
