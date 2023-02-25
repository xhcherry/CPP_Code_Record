#include <iostream>
#include <vector>
using namespace std;
vector<int>::iterator search(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    for (; beg != end; ++beg)
        if (*beg == val)
            return beg;
    return end;
}
int main()
{
    vector<int> l = {1, 2, 3, 4, 5, 6, 7};
    cout << search(l.begin(), l.end(), 3) - l.begin() << endl;
    cout << search(l.begin(), l.end(), 8) - l.begin() << endl;
    return 0;
}