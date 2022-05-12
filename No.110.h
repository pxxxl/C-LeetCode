#pragma once
#include"1.h"

//Ë¼Â·²»´í

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        heightAndJudge(root);
        return isBalance;
    }
    int heightAndJudge(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        else {
            int lh = heightAndJudge(root->left);
            int rh = heightAndJudge(root->right);
            if (abs(lh - rh) > 1) {
                isBalance = false;
            }
            return max(lh, rh) + 1;
        }
    }
    bool isBalance = true;
};