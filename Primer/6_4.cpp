#include <iostream>

using namespace std;

int fact(int val)
{
    if (val < 0)
        return -1;
    int ret = 1; // 局部变量，用于保存计算结果
    while (val > 1)
        ret *= val--; // 把 ret 和 val 的乘积赋给 ret，然后将 val 减 1
    return ret;       // 返回结果
}

int main()
{
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    cout << num << " 的阶乘是：" << fact(num) << endl;
    return 0;
}
