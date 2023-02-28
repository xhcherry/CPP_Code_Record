#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

string &trans(string &s) {
    for (int p = 0; p < s.size(); ++p) {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] += ('a' - 'A');
        else if (s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    return s;
}

int main() {
    // 统计每个单词在输入中出现的次数
    unordered_map<string, size_t> word_count;   // string 到 size_t 的空 map
    string word;
    while (cin >> word)
        ++word_count[trans(word)];              // 提取 word 的计数器并将其加 1
    for (const auto &w : word_count)            // 对 map 中的每个元素
        // 打印结果
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    return 0;
}
