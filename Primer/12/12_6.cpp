#include <iostream>
#include <vector>
using namespace std;

vector<int> *new_vector()
{
    return new (nothrow) vector<int>;
}

void read_ints(vector<int> *pv)
{
    int v;
    while (cin >> v)
    {
        pv->push_back(v);
    }
}

void print_ints(vector<int> *pv)
{
    for (const auto &i : *pv)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> *ivecp = new_vector();
    if (!ivecp)
    {
        cout << "内存不足！" << endl;
        return -1;
    }
    read_ints(ivecp);
    print_ints(ivecp);
    delete ivecp;    // ivecp 变为无效
    ivecp = nullptr; // 指出 ivecp 不再绑定到任何对象

    return 0;
}
