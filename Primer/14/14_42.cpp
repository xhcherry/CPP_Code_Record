#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
    using std::placeholders::_1;

    // 统计大于 1024 的值有多少个
    std::vector<int> ivec{1000, 2000, 3000, 4000, 5000};
    std::cout << std::count_if(ivec.begin(), ivec.end(),
            std::bind(std::greater<int>(), _1, 1024)) << std::endl;

    // 找到第一个不等于 pooth 的字符串
    std::vector<std::string> svec{"pooth", "pooth", "abc", "pooth"};
    std::cout << *std::find_if(svec.begin(), svec.end(),
            std::bind(std::not_equal_to<std::string>(), _1, "pooth"))
            << std::endl;

    // 将所有的值乘以 2
    std::transform(ivec.begin(), ivec.end(), ivec.begin(),
            std::bind(std::multiplies<int>(), _1, 2));
    for (const auto &i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
