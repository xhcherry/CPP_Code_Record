#ifndef TEST_COMPARE_H
#define TEST_COMPARE_H
#include <cstring>
#include <functional>
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (std::less<T>()(v1, v2))
        return -1;
    if (std::less<T>()(v2, v1))
        return 1;
    return 0;
}
template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}
#endif