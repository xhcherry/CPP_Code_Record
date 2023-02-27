#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l1, l2, l3;
    unique_copy(v.begin(), v.end(), inserter(l1, l1.begin()));
    for (auto v : l1)
        cout << v << " ";
    cout << endl;
    unique_copy(v.begin(), v.end(), back_inserter(l2));
    for (auto v : l2)
        cout << v << " ";
    cout << endl;

    unique_copy(v.begin(), v.end(), front_inserter(l3));
    for (auto v : l3)
        cout << v << " ";
    cout << endl;

    return 0;
}