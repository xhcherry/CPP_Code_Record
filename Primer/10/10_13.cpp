#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool predicate(const string &s)
{
    return s.size() >= 5;
}
int main()
{
    vector<string> svec = {"cccccc", "iii", "zz", "bbbbb", "c"};
    for (auto &s : svec)
        cout << s << " ";
    cout << endl;
    vector<string>::iterator pivot = partition(svec.begin(), svec.end(), predicate);
    for (auto &s : svec)
        cout << s << " ";
    cout << endl;
    for (vector<string>::iterator iter = svec.begin(); iter != pivot; ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}