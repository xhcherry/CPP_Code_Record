#include <iostream>
using namespace std;

// 在函数体内部通过解引用操作改变指针所指的内容
void mySwap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;

    cout << "指针 p 的地址为：" << p << endl;
    cout << "指针 q 的地址为：" << q << endl;
}

int main()
{
    int a = 5, b = 10;
    int *r = &a, *s = &b;
    cout << "交换前:a = " << a << ",b = " << b << endl;
    cout << "指针 r 的地址为：" << r << endl;
    cout << "指针 s 的地址为：" << s << endl;
    mySwap(r, s);
    cout << "交换后:a = " << a << ",b = " << b << endl;

    return 0;
}
