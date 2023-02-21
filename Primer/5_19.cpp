#include <iostream>
#include <string>
using namespace std;
int main()
{
    do
    {
        cout << "输入两个字符 " << endl;
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() < s2.size())
            cout << "长度较小的是" << s1 << endl;
        else if (s1.size() > s2.size())
            cout << "长度较小的是" << s2 << endl;
        else
            cout << "两个字符串等长" << endl;
    } while (cin);
    return 0;
}