#pragma once
#include"1.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return symmetricHelper(root->left, root->right);
    }
    bool symmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        else if (left != nullptr && right != nullptr) {
            return (left->val == right->val) && symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
        }
        else {
            return false;
        }
        
    }
};