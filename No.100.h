#pragma once
#include"1.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p != nullptr && q != nullptr) {
            if (q->val == p->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};