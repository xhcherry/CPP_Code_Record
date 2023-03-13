#include <iostream>
#include <string>
template <typename T, size_t N>
void print(const T (&arr)[N])
{
    for (const auto &elem : arr)
        std::cout << elem;
    std::cout << std::endl;
}
int main()
{
    int a[6] = {0, 2, 4, 6, 8, 10};
    std::string s[3] = {"C++", "primer", "5th"};
    print(a);
    print(s);
    return 0;
}