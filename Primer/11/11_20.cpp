#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
string &trans(string &s)
{
    for (int p = 0; p < s.size(); ++p)
    {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] += ('a' - 'A');
        else if (s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    return s;
}
int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        auto ret = word_count.insert({trans(word), 1});
        if (!ret.second)
            ++ret.first->second;
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }
    return 0;
}