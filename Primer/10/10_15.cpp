#include <iostream>
using namespace std;
void add(int a)
{
    auto sum = [a](int b)
    {
        return a + b;
    };
    cout << sum(4) << endl;
}
int main()
{
    add(1);
    add(2);
    return 0;
}