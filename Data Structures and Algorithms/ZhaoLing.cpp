/*
Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。
现在小Y使用1024元的纸币购买了一件价值为N(0<N≤1024)的商品，请问最少他会收到多少硬币？
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32M，其他语言64M
输入描述：
一行，包含一个数N。
输出描述：
一行，包含一个数，表示最少收到的硬币数。
示例1
输入例子：
200
输出例子：
17
例子说明：
花200，需要找零824块，找12个64元硬币，3个16元硬币，2个4元硬币即可。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//方法一，贪心，必然可以找清楚，从最大的开始找
int RecvNum(int num)
{
	int sum = 0;//要找回的硬币数量
	int amount = 64;
	for (int i = 0; i < 4; i++)//四种硬币
	{
		sum += num / amount;//有多少个64元
		num %= amount;//找完64的硬币之后剩下的钱
		amount >>= 2;//换下一个面值
	}
	return sum;
}

//方法二 使用动态规划 
//dp[i]：找i元钱最少需要多少硬币
//base: dp[0]=0;dp[1]=1
//状态转移方程：dp[i]=min(dp[i],dp[i-amount]+1);

//类比
//背包问题：装最少的东西将容量为1024-N的背包装满，每次可以装1/4/16/64
//爬楼梯问题：爬最少的次数爬完1024-N层楼梯，每次可以爬1/4/16/64层
int RecvNum_dp(int num)
{
	vector<int> dp(num + 1, num + 1);//都赋上最大值
	int amount[4]{ 1,4,16,64 };
	//base
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= num; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i >= amount[j])
				dp[i] = min(dp[i], dp[i - amount[j]] + 1);
		}
	}
	return dp[num];
}

int main()
{
	int N;//花的钱
	cin >> N;
	cout << RecvNum_dp(1024 - N) << endl;
	return 0;
}
