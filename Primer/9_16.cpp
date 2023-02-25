#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool l_v_equal(vector<int> &ivec, list<int> &ilist)
{
    // 比较 list 和 vector 元素个数
    if (ilist.size() != ivec.size())
        return false;

    // auto lb = ilist.cbegin(); // 也可
    list<int>::const_iterator lb = ilist.cbegin();  // list 首元素
    list<int>::const_iterator le = ilist.cend();    // list 尾后位置
    vector<int>::const_iterator vb = ivec.cbegin(); // vector 首元素
    for (; lb != le; ++lb, ++vb)
        if (*lb != *vb)
            return false;
    return true;
}

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    list<int> ilist1 = {1, 2, 3, 4, 5};
    list<int> ilist2 = {1, 2, 3, 4, 5, 6, 8};
    list<int> ilist3 = {1, 2, 3, 4, 5, 7, 6};

    cout << l_v_equal(ivec, ilist) << endl;
    cout << l_v_equal(ivec, ilist1) << endl;
    cout << l_v_equal(ivec, ilist2) << endl;
    cout << l_v_equal(ivec, ilist3) << endl;

    return 0;
}
