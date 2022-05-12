#pragma once
#include"1.h"

//比较一般般吧这题

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        int low = min(p->val, q->val);
        int high = max(p->val, q->val);
        TreeNode* cur = root;
        while (cur->val > high || cur->val < low) {
            if (cur->val > high) {
                cur = cur->left;
            }
            else if (cur->val < low) {
                cur = cur->right;
            }
        }
        return cur;
    }
};