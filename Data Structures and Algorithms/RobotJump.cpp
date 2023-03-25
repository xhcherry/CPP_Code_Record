/*
机器人跳跃问题
机器人正在玩一个古老的基于DOS的游戏。游戏中有N+1座建筑——从0到N编号，从左到右排列。
编号为0的建筑高度为0个单位，编号为i的建筑的高度为H(i)个单位。

起初， 机器人在编号为0的建筑处。每一步，它跳到下一个（右边）建筑。
假设机器人在第k个建筑，且它现在的能量值是E, 下一步它将跳到第个k+1建筑。
它将会得到或者失去正比于与H(k+1)与E之差的能量。
如果 H(k+1) > E 那么机器人就失去 H(k+1) - E 的能量值，否则它将得到 E - H(k+1) 的能量值。

游戏目标是到达第个N建筑，在这个过程中，能量值不能为负数个单位。
现在的问题是机器人以多少能量值开始游戏，才可以保证成功完成游戏？
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32M，其他语言64M
输入描述：
第一行输入，表示一共有 N 组数据.

第二个是 N 个空格分隔的整数，H1, H2, H3, ..., Hn 代表建筑物的高度
输出描述：
输出一个单独的数表示完成游戏所需的最少单位的初始能量
示例1
输入例子：
5
3 4 3 2 4
输出例子：
4
示例2
输入例子：
3
4 4 4
输出例子：
4
示例3
输入例子：
3
1 6 4
输出例子：
3
*/
#include <vector>
#include <iostream>
#include <cmath>

class Solution {
public:
	static void solve(const std::vector<int>& data) {
		// need:到达终点的所需要最小的能量
		int need = 0;
		/**
		 * @brief: 到达终点能量为0时，开始所需能量最小。
		 *         从终点开始倒推理，推理出前一步所需的能量。
		 *         一直递推到起点
		 *
		 * 为什么需要 ceil(...)？
		 *
		 * 因为会出现 (*iter + need) 为奇数，如果不向上取整，就会少1，最后到终点时不是0，而是-1
		 *
		 * 比如，输入如下：
		 *
		 *  3
		 *  3 2 4
		 *
		 *  正确结果是3，但是实际上输出2，就是因为没有向上取整。
		*/
		for (auto iter = data.rbegin(); iter != data.rend(); ++iter) {
			need = ::ceil(static_cast<float>((*iter + need)) / 2); // 向上取整
		}
		std::cout << need << std::endl;;
	}
};

int main(int argc, char const* argv[]) {

	int N = 0;
	std::cin >> N;
	std::vector<int> data(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> data[i];
	}

	Solution::solve(data);

	return 0;
}
