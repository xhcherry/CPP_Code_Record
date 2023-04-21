#include "createTree.h"
TreeNode* createTree(vector<int> nodes){
    if(!nodes.size()){
        return nullptr;
    }
    queue<TreeNode*> que;
    TreeNode *root, *node, *cur;
    bool is_left = true;
    for(auto val: nodes){
        node = val != 0 ? new TreeNode(val) : nullptr;
        if(que.empty()){
            root = node;
            que.push(node);
        }
        else if(is_left){
            cur = que.front();
            que.pop();
            cur->left = node;
            if(&node){
                que.push(node);
            }
            is_left = !is_left;
        }
        else{
            cur->right = node;
            if(&node){
                que.push(node);
            }
            is_left = !is_left;
        }
    }
    return root;
}

