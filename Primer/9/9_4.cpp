#include <iostream>
#include <vector>
using namespace std;
bool search(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    for (; beg != end; ++beg)
        if (*beg == val)
            return true;
    return false;
}
int main()
{
    vector<int> l = {1, 2, 3, 4, 5, 6, 7};
    cout << search(l.begin(), l.end(), 3) << endl;
    cout << search(l.begin(), l.end(), 8) << endl;
    return 0;
}