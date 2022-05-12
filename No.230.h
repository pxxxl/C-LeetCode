#pragma once
#include"1.h"

//可以在建树的时后用hash或节点内部存储其左子树的节点数
//查起来容易一些

//可以avl

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        kth = k;
        dfs(root);
        return target->val;
    }
    void dfs(TreeNode* root) {
        if (count == kth|| root == nullptr) {
            return;
        }
        dfs(root->left);
        count++;
        if (count == kth) {
            target = root;
            return;
        }
        dfs(root->right);
        return;
    }
    TreeNode* target;
    int count;
    int kth;
};