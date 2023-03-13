#include <iostream>
#include <string>
template <typename T, size_t N>
void print(const T (&arr)[N])
{
    for (const auto &elem : arr)
        std::cout << elem;
    std::cout << std::endl;
}
template <typename T, size_t N>
const T *begin(const T (&arr)[N])
{
    return arr;
}
template <typename T, size_t N>
const T *end(const T (&arr)[N])
{
    return arr + N;
}
int main()
{
    int a[6] = {0, 2, 4, 6, 8, 10};
    std::string s[3] = {"c++", "primer", "5th"};
    print(a);
    print(s);
    std::cout << *begin(a) << std::endl;
    std::cout << *(end(a) - 1) << std::endl;
    std::cout << *begin(s) << std::endl;
    std::cout << *(end(s) - 1) << std::endl;
    return 0;
}