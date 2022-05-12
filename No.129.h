#pragma once
#include"1.h"

//»ØËİµİ¹éÕæË¬

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
    void dfs(TreeNode* root, int current) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            sum += current * 10 + root->val;
            return;
        }
        dfs(root->left, current * 10 + root->val);
        dfs(root->right, current * 10 + root->val);
        return;
    }
    int sum;
};