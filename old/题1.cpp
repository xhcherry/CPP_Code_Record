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

    stack<int> stk; // ��ջ���洢���ڵ�ǰ���������±�
    for (int i = n; i >= 1; i--)
    {
        while (!stk.empty() && q[i] >= q[stk.top()])
            stk.pop(); // �����ǰ���ĸ߶ȱ�ջ�������ĸ߶�С���򵯳�ջ������

        if (!stk.empty())
            res[i] = stk.top(); // ��ǰ������Զ���Ϊջ���������±�
        else
            res[i] = 0; // ���ջΪ�գ���ǰ����������Զ���

        stk.push(i); // ����ǰ�����±���뵽ջ��
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";

    return 0;
}
