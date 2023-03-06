#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const {
        return s1.size() < s2.size();
    }
};

class NotShorterThan {
private:
    int minLen_;

public:
    NotShorterThan(int len) : minLen_(len) { }
    bool operator()(const string &s) {
        return s.size() >= minLen_;
    }
};

// 如果 ctr 的值大于 1，返回 word 的复数形式
string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

void elimDups(std::vector<std::string> &words) {
    // 按字典序排序 words，以便查找重复单词
    sort(words.begin(), words.end());
    // unique 重排输入范围，使得每个单词只出现一次
    // 排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
    auto end_unique = unique(words.begin(), words.end());
    // 删除重复单词
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    // 将 words 按字典序排序，删除重复单词
    elimDups(words);
    // 按长度排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(), ShorterString());
    // 获取一个迭代器，指向第一个满足 size() >= sz 的元素
    auto wc = find_if(words.begin(), words.end(), NotShorterThan(sz));
    // 计算满足 size() >= sz 的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc, words.end(),
             [] (const string &s) {
                 cout << s << " ";
             }
    );
    cout << endl;
}

int main() {
    std::vector<std::string> svec = {"the", "quick", "red", "fox", "jumps",
                                     "over", "the", "slow", "red", "turtle"};
    // 按字典序打印 svec 中长度不小于 4 的单词
    biggies(svec, 4);

    return 0;
}
