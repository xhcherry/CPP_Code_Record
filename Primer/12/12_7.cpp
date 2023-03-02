#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_vector()
{
    // 返回一个值初始化的 vector<int> 的 shared_ptr
    return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> spv)
{
    int v;
    while (cin >> v)
    {
        spv->push_back(v);
    }
}

void print_ints(shared_ptr<vector<int>> spv)
{
    for (const auto &i : *spv)
        cout << i << " ";
    cout << endl;
}

int main()
{
    shared_ptr<vector<int>> ivecsp = new_vector();
    read_ints(ivecsp);
    print_ints(ivecsp);

    return 0;
}
