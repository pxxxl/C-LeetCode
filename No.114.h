#pragma once
#include"1.h"

//普通方法，分别递归处理左子树和右子树，再链接

class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        if (root->left == nullptr) {
            if (root->right == nullptr) {
                return root;
            }
            root->right = helper(root->right);
            return root;
        }
        auto hold = root->right;
        auto cur = root;
        root->right = helper(root->left);
        root->left = nullptr;
        while (cur->right != nullptr) {
            cur = cur->right;
        }
        cur->right = helper(hold);
        return root;
    }
};

//原地方法：把右子树链接到左子树的最后一个节点，然后把左子树链接到右子树（已经空了）上
class Solution2 {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        auto cur = root;
        while (cur->left != nullptr || cur->right != nullptr) {
            if (cur->left == nullptr) {
                cur = cur->right;
            }
            else if (cur->right == nullptr) {
                cur->right = cur->left;
                cur->left = nullptr;
                cur = cur->right;
            }
            else {
                auto prior = cur;
                prior = cur->left;
                while (prior->right != nullptr) {
                    prior = prior->right;
                }
                prior->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
                cur = cur->right;
            }
        }
        return;
    }
};