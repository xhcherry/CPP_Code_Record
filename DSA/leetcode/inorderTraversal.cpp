#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree(vector<int> nodes);

TreeNode *createTree(vector<int> nodes) {
    if (!nodes.size()) {
        return nullptr;
    }
    queue<TreeNode *> que;
    TreeNode *root, *node, *cur;
    bool is_left = true;
    for (auto val: nodes) {
        node = val != 0 ? new TreeNode(val) : nullptr;
        if (que.empty()) {
            root = node;
            que.push(node);
        } else if (is_left) {
            cur = que.front();
            que.pop();
            cur->left = node;
            if (&node) {
                que.push(node);
            }
            is_left = !is_left;
        } else {
            cur->right = node;
            if (&node) {
                que.push(node);
            }
            is_left = !is_left;
        }
    }
    return root;
}
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

                st.push(node);                          // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
            } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();           // 将空节点弹出
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到结果集
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> tree = {4, 2, 7, 1, 3, 6, 9};
    TreeNode *root = createTree(tree);
    // cout << root << endl;
    Solution s = Solution();
    vector<int> travel = s.inorderTraversal(root);
    for (auto a: travel) {
        cout << a << " " << endl;
    }
    return 0;
}
