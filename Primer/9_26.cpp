#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v;
    list<int> l;
    v.assign(ia, ia + sizeof(ia) / sizeof(ia[0]));
    l.assign(ia, ia + sizeof(ia) / sizeof(ia[0]));
    vector<int>::iterator v1 = v.begin();
    while (v1 != v.end())
        if (!(*v1 & 1))
            v1 = v.erase(v1);
        else
            ++v1;
    list<int>::iterator l1 = l.begin();
    while (l1 != l.end())
        if (*l1 & 1)
            l1 = l.erase(l1);
        else
            ++l1;
    for (v1 = v.begin(); v1 != v.end(); ++v1)
        cout << *v1 << " ";
    cout << endl;
    for (l1 = l.begin(); l1 != l.end(); ++l1)
        cout << *l1 << " ";
    return 0;
}