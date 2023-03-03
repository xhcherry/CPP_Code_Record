#include <iostream>
#include <string>
#include <memory>
#define LENGTH 100

using namespace std;

int main()
{
    allocator<string> alloc;
    // 分配 100 个未初始化的 string
    auto const p = alloc.allocate(LENGTH);
    string s;
    string *q = p; // q 指向第一个 string
    while (cin >> s && q != p + LENGTH)
        alloc.construct(q++, s); // 用 s 初始化 *q
    const size_t size = q - p;   // 记住读取了多少个 string

    for (size_t i = 0; i < size; i++)
        cout << p[i] << endl;

    while (q != p)
        alloc.destroy(--q);      // 释放我们真正构造的 string
    alloc.deallocate(p, LENGTH); // 释放内存

    return 0;
}
