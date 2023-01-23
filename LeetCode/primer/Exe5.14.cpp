#include <iostream>
#include <string>

using namespace std;

int main() {
    // 定义 3 个字符串变量，分别表示：
    // 当前操作的字符串、前一个字符串、当前出现次数最多的字符串
    string currString, preString = "", maxString;
    // 定义 2 个整型变量，分别表示：
    // 当前连续出现的字符串数量、当前出现次数最多的字符串数量
    int currCnt = 1, maxCnt = 0;
    while (cin >> currString && currString != "Q") { // 检查每个字符串
        // 如果当前字符串与前一个字符串一致，更新状态
        if (currString == preString) {
            ++currCnt;
            if (currCnt > maxCnt) {
                maxCnt = currCnt;
                maxString = currString;
            }
        } else {
            // 如果当前字符串与前一个字符串不一致，重置 currCnt
            currCnt = 1;
        }
        // 更新 preString 以便于下一次循环使用
        preString = currString;
    }
    if (maxCnt > 1)
        cout << "出现最多的字符串是：" << maxString
             << "，次数是：" << maxCnt << endl;
    else
        cout << "每个字符串都只出现了一次" << endl;
    return 0;
}
