#pragma once
#include"1.h"

//±È½Ï¸´ÔÓµÄµÝ¹é
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int to_root = -1001;
        int total = -1001;
        dfs(root, to_root, total);
        if (total == -1001) {
            return 0;
        }
        else {
            return total;
        }
    }

    void dfs(TreeNode* root, int& to_root, int& total) {
        if (root == nullptr) {
            return;
        }

        int l_to_root = -1001;
        int r_to_root = -1001;
        int l_t = -1001;
        int r_t = -1001;

        dfs(root->left, l_to_root, l_t);
        dfs(root->right, r_to_root, r_t);

        if (l_to_root <= 0 && r_to_root <= 0) {
            to_root = root->val;
        }
        else {
            to_root = max(l_to_root, r_to_root) + root->val;
        }

        int ancle = (l_to_root>0?l_to_root:0)+(r_to_root>0?r_to_root:0)+root->val;

        total = max({ ancle, l_t, r_t });
    }
};