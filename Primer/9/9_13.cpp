#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main()
{
    vector<int> v{7, 6, 5, 4, 3, 2, 1};
    list<int> l{1, 2, 3, 4, 5, 6, 7};
    vector<double> devc(l.begin(), l.end());
    vector<double> levc(v.begin(), v.end());
    cout << devc.capacity() << " " << devc.size() << " " << devc[0] << " " << devc[devc.size() - 1] << endl;
    cout << levc.capacity() << " " << levc.size() << " " << levc[0] << " " << levc[levc.size() - 1] << endl;
    return 0;
}