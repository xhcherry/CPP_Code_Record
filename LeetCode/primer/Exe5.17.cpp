#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1, v2;
    // 这里表示输入的变量之所以没有用 int 类型
    // 是因为想用字符 'Q' 结束每个 vector 的输入
    char c;
    cout << "请输入 v1 的一组整数值：";
    while (cin >> c && c != 'Q')
        v1.push_back(c);
    cout << "请输入 v2 的一组整数值：";
    while (cin >> c && c != 'Q')
        v2.push_back(c);

    auto it1 = v1.cbegin();     // 定义 v1 的迭代器
    auto it2 = v2.cbegin();     // 定义 v2 的迭代器

    // 设定循环条件：v1 和 v2 都尚未检查完
    while (it1 != v1.cend() && it2 != v2.cend()) {
        // 如果当前位置的两个元素不相等，则肯定没有前缀关系，退出循环
        if (*it1 != *it2) {
            cout << "v1 和 v2 之间不存在前缀关系" << endl;
            break;
        }
        ++it1;                  // 迭代器移动到下一个元素
        ++it2;                  // 迭代器移动到下一个元素
    }

    if (it1 == v1.cend())       // 如果 v1 较短
        cout << "v1 是 v2 的前缀" << endl;

    if (it2 == v2.cend())       // 如果 v2 较短
        cout << "v2 是 v1 的前缀" << endl;

    return 0;
}
