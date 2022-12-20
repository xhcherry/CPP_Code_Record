#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 1e5 + 10;

int n;
int q[N];
int res[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> q[i];

    stack<int> stk; // 用栈来存储大于当前树的树的下标
    for (int i = n; i >= 1; i--)
    {
        while (!stk.empty() && q[i] >= q[stk.top()])
            stk.pop(); // 如果当前树的高度比栈顶的树的高度小，则弹出栈顶的树

        if (!stk.empty())
            res[i] = stk.top(); // 当前树的配对对象为栈顶的树的下标
        else
            res[i] = 0; // 如果栈为空，则当前树不存在配对对象

        stk.push(i); // 将当前树的下标加入到栈中
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";

    return 0;
}
