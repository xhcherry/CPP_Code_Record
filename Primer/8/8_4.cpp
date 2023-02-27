#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    // ../data 为文件data的文件名及其相对路径（是相对于可执行程序所在目录的相对路径）
    ifstream in("../data"); // 打开文件
    if (!in)
    {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while (getline(in, line))  // 从文件中读取一行
        words.push_back(line); // 添加到 vector 中

    in.close(); // 输入完毕，关闭文件

    vector<string>::const_iterator it = words.begin(); // 迭代器
    while (it != words.end())
    {                        // 遍历 vector
        cout << *it << endl; // 输出 vector 中的元素
        ++it;
    }

    return 0;
}