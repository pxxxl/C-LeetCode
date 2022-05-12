#pragma once
#include"1.h"

//��ͨ�������ֱ�ݹ鴦������������������������

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

//ԭ�ط����������������ӵ������������һ���ڵ㣬Ȼ������������ӵ����������Ѿ����ˣ���
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