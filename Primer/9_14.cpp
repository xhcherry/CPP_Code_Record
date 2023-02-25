#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    list<char *> l = {"hello", "world", "!"};
    vector<string> v;
    v.assign(l.begin(), l.end());
    cout << v.capacity() << " " << v.size() << " " << v[0] << " " << v[v.size() - 1] << endl;
    return 0;
}