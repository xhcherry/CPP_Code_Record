/*
毕业旅行问题
小明目前在做一份毕业旅行的规划。打算从北京出发，分别去若干个城市，然后再回到北京，
每个城市之间均乘坐高铁，且每个城市只去一次。由于经费有限，希望能够通过合理的路线安排尽可能的省一些路上的花销。
给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问一次并返回起点的最小车费花销。
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32M，其他语言64M
输入描述：
城市个数n（1<n≤20，包括北京）

城市间的车票价钱 n行n列的矩阵 m[n][n]
输出描述：
最小车费花销 s
示例1
输入例子：
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
输出例子：
13
例子说明：
共 4 个城市，城市 1 和城市 1 的车费为0，城市 1 和城市 2 之间的车费为 2，
城市 1 和城市 3 之间的车费为 6，城市 1 和城市 4 之间的车费为 5，依次类推。
假设任意两个城市之间均有单程票可购买，且票价在1000元以内，无需考虑极端情况。
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int getAns(vector<vector<int>>& nums) {

	int M = 0x7ffffff;
	int n = nums.size();
	vector<vector<int>> dp(1 << n, vector<int>(n, M));
	dp[1][0] = 0;
	for (int i = 1; i < n; i++) dp[1 << i][i] = M;
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] != M) {
				for (int k = 0; k < n; k++) {
					if ((i & (1 << k)) == 0) {
						dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + nums[j][k]);
					}
				}
			}
		}
	}
	int ans = M;
	for (int i = 1; i < n; i++) {
		ans = min(ans, dp[(1 << n) - 1][i] + nums[i][0]);
	}
	return ans;
}
int main() {
	int n;
	while (cin >> n) {
		vector<vector<int>> edges(n, vector<int>(n, 0));
		int x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> edges[i][j];
			}
		}
		cout << getAns(edges) << endl;
	}
	return 0;
}
