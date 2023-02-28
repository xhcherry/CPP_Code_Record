#include <iostream>
#include <list>
#include<algorithm>
using namespace std;
void output_words(list<string> &words)
{
    for (auto &s : words)
        cout << s << " ";
    cout << words.size() << endl;
}
void elimDups(list<string> &words)
{
    output_words(words);
    words.sort();
    output_words(words);
    words.unique();
    output_words(words);
    for_each(words.begin(), words.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
}
int main()
{
    list<string> slist = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(slist);
    return 0;
}