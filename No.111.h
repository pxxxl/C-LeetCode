#pragma once
#include"1.h"

//ºÃºÃÉóÌâÑ½
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root, 1);
        return min_depth;
    }
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (min_depth > depth) {
                min_depth = depth;
            }
            return;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
        return;
    }
    int min_depth = 100000;
};