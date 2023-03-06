#include <functional>
#include <string>
#include <map>
#include <iostream>

// 普通函数
int add(int i, int j) { return i + j; }

// lambda，其产生一个未命名的函数对象类
auto mod = [] (int i, int j) { return i % j; };

// 函数对象类
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

// 列举了可调用对象与二元运算符对应关系的表格
// 所有可调用对象都必须接受两个 int，返回一个 int
// 其中的元素可以是函数指针、函数对象或者 lambda
std::map<std::string, std::function<int(int, int)>> binops = {
        {"+", add},                                 // 函数指针
        {"-", std::minus<int>()},                   // 标准库函数对象
        {"*", [] (int i, int j) { return i * j; }}, // 未命名的 lambda
        {"/", divide()},                            // 用户定义的函数对象
        {"%", mod}                                  // 命名了的 lambda 对象
};

int main() {
    while (true) {
        std::cout << "请输入（输入格式：操作数1 运算符 操作数2）：\n";
        int x, y;
        std::string s;
        std::cin >> x >> s >> y;
        std::cout << binops[s](x, y) << std::endl;
    }

    return 0;
}
