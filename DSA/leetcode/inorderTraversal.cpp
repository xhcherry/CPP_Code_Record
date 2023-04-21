#include<bits/stdc++.h>
#include"createTree.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> res;
        stack<TreeNode*> sk;
        TreeNode *cur = root;
        while(cur || !sk.empty()){
            if(cur){
                sk.push(cur);
                cur = cur->left;
            }
            else{
                cur = sk.top();
                sk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    vector<int> tree = {4,2,7,1,3,6,9};
    TreeNode *root = createTree(tree);
    // cout << root << endl;
    Solution s = Solution();
    vector<int> travel = s.inorderTraversal(root);
    for(auto a: travel){
        cout << a << " " << endl;
    }
    return 0;
}
