#include <iostream>
using namespace std;

template <typename T>

void print(T t) {
    cout << "The value is " << t << endl;
}

template <>

void print<char*>(char* c) {
    cout << "The string is " << c << endl;
}

int main() {
    char str[] = "TrendMicro[char]";
    unsigned char ustr[] = "TrendMicro[unsigned char]";
    print(str);
    print(ustr);
    return 0;
}
/*下面函数为具体化，上面是模板
匹配规则：
(1)普通函数，如果类型匹配，优先选中，重载解析结束；（也就是重载的优先级高于所有模板）
(2)如果没有普通函数匹配，那么所有的基础函数模版进入候选，编译器开始平等挑选，类型最匹配的，则被选中，注意，此时才会进入第(3)步继续筛选；
(3)如果第(2)步里面选中了一个模版基础函数，则查找这个模版基础函数是否有全特化版本，如果有且类型匹配，则选中全特化版本，重载解析结束，否则使用(2)里面选中的模版函数，重载解析依然结束。
(4)如果第(2)步里面没有选中任何函数基础模版，那么匹配失败，编译器会报错，程序员需要检查下代码
The string is TrendMicro[char]
The value is TrendMicro[unsigned char]
*/
