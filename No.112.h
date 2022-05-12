#pragma once
#include"1.h"

//要好好看题呀

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root);
        return has_path_sum;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target) {
                has_path_sum = true;
                return;
            }
        }
        dfs(root->left);
        dfs(root->right);
        sum -= root->val;
        return;
    }
    int target;
    bool has_path_sum = false;
    int sum = 0;
};