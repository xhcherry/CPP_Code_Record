/*
雀魂启动！
小包最近迷上了一款叫做雀魂的麻将游戏，但是这个游戏规则太复杂，小包玩了几个月了还是输多赢少。
于是生气的小包根据游戏简化了一下规则发明了一种新的麻将，只留下一种花色，并且去除了一些特殊和牌方式（例如七对子等），具体的规则如下：

总共有36张牌，每张牌是1~9。每个数字4张牌。
你手里有其中的14张牌，如果这14张牌满足如下条件，即算作和牌
14张牌中有2张相同数字的牌，称为雀头。
除去上述2张牌，剩下12张牌可以组成4个顺子或刻子。顺子的意思是递增的连续3个数字牌（例如234,567等），刻子的意思是相同数字的3个数字牌（例如111,777）

例如：
1 1 1 2 2 2 6 6 6 7 7 7 9 9 可以组成1,2,6,7的4个刻子和9的雀头，可以和牌
1 1 1 1 2 2 3 3 5 6 7 7 8 9 用1做雀头，组123,123,567,789的四个顺子，可以和牌
1 1 1 2 2 2 3 3 3 5 6 7 7 9 无论用1 2 3 7哪个做雀头，都无法组成和牌的条件。

现在，小包从36张牌中抽取了13张牌，他想知道在剩下的23张牌中，再取一张牌，取到哪几种数字牌可以和牌。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ishu(vector<int>num)
{
    if (num.empty())
        return true;
    int count0 = 0;
    for(int i=0;i<num.size();++i)
    {
        if (num[0] == num[i])
            ++count0;
        else
            break;
    }
    if (num.size() % 3 != 0 && count0 >= 2)
    {
        vector<int> newnum(num.begin() + 2, num.end());
        if (ishu(newnum))
            return true;
    }
    if (count0 >= 3)
    {
        vector<int> newnum(num.begin() + 3, num.end());
        if (ishu(newnum))
            return true;
    }
    if(count(num.begin(),num.end(),num[0]+1)>0 && count(num.begin(), num.end(), num[0] + 2)>0)
    {
        vector<int> newnum(num.begin() + 1, num.end());
        newnum.erase(find(newnum.begin(), newnum.end(), num[0] + 1));
        newnum.erase(find(newnum.begin(), newnum.end(), num[0] + 2));
        if (ishu(newnum))
            return true;
    }
    return false;
}
bool hupai(vector<int>num, int n)
{
    if (count(num.begin(), num.end(), n) == 4)
        return false;
    num.push_back(n);
    sort(num.begin(),num.end());
    return ishu(num);
}
int main()
{
    vector<int> num;
    vector<int> res;
    for (int i = 0; i < 13; ++i)
    {
        int tmp;
        cin >> tmp;
        if (tmp > 0 && tmp < 10)
            num.push_back(tmp);
        else
        {
            cout << "输入错误" << endl;
            return 0;
        }
    }
    for (int n = 1; n < 10; ++n)
    {
        if (hupai(num, n))
            res.push_back(n);
    }
    if (res.empty())
        cout << 0;
    else
        for (int i = 0; i < res.size(); ++i)
            cout << res[i]<<" ";
}