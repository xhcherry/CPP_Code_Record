#include <iostream>
#include <cmath>

using namespace std;

// 第一个函数通过 if-else 语句计算绝对值
double myABS(double val)
{
    if (val < 0)
        return -val;
    else
        return val;
}

// 第二个函数调用 cmath 头文件的 abs 函数计算绝对值
double myABS2(double val)
{
    return abs(val);
}

int main()
{
    double num;
    cout << "请输入一个数：";
    cin >> num;
    cout << num << " 的绝对值是：" << myABS(num) << endl;
    cout << num << " 的绝对值是：" << myABS2(num) << endl;

    return 0;
}
