﻿/*
2.
万万没想到之抓捕孔连顺
我叫王大锤，是一名特工。我刚刚接到任务：在字节跳动大街进行埋伏，抓捕恐怖分子孔连顺。和我一起行动的还有另外两名特工，我提议

1. 我们在字节跳动大街的 N 个建筑中选定 3 个埋伏地点。
2. 为了相互照应，我们决定相距最远的两名特工间的距离不超过 D 。

我特喵是个天才! 经过精密的计算，我们从X种可行的埋伏方案中选择了一种。这个方案万无一失，颤抖吧，孔连顺！
……
万万没想到，计划还是失败了，孔连顺化妆成小龙女，混在cosplay的队伍中逃出了字节跳动大街。只怪他的伪装太成功了，就是杨过本人来了也发现不了的！

请听题：给定 N（可选作为埋伏点的建筑物数）、 D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，大锤的小队有多少种埋伏选择。
注意：
1. 两个特工不能埋伏在同一地点
2. 三个特工是等价的：即同样的位置组合( A , B , C ) 只算一种埋伏方法，不能因“特工之间互换位置”而重复使用

数据范围：
0<n,d≤10的六次方
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 128M，其他语言256M
输入描述：
第一行包含空格分隔的两个数字 N和D(1 ≤ N ≤ 1000000; 1 ≤ D ≤ 1000000)

第二行包含N个建筑物的的位置，每个位置用一个整数（取值区间为[0, 1000000]）表示，从小到大排列（将字节跳动大街看做一条数轴）
输出描述：
一个数字，表示不同埋伏方案的数量。结果可能溢出，请对 99997867 取模
示例1
输入例子：
4 3
1 2 3 4
输出例子：
4
例子说明：
可选方案 (1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)
示例2
输入例子：
5 19
1 10 20 30 50
输出例子：
1
例子说明：
可选方案 (1, 10, 20)
示例3
输入例子：
2 100
1 102
输出例子：
0
例子说明：
无可选方案
*/
#include <iostream> // 输入输出流
#include <vector> // 向量类
using namespace std;

long long C(long long n) { // 计算组合数C(n,2)，输入n，返回结果
	return (n - 1) * n / 2;
}

int main() {
	long long n, d, count = 0; // 声明输入变量n、d和计数变量count，初始值为0
	cin >> n >> d; // 输入n和d的值
	vector<long long> v(n); // 定义一个容量为n的向量v
	for (int i = 0, j = 0; i < n; i++) { // 从0遍历到n-1，j是左边界的位置，i是右边界的位置
		cin >> v[i]; // 输入每个建筑的坐标值
		while (i >= 2 && (v[i] - v[j]) > d) { // 如果i和j之间的距离超过d，就把左边界往右移动
			j++; // 左边界往右移动
		}
		count += C(i - j); // 计算可以在i和j之间选出两个位置的方案数，并加到count上
	}
	cout << count % 99997867; // 输出最终的计数结果
	return 0; // 返回0表示程序正常结束
}