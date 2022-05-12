#pragma once
#include"1.h"

//特点：二叉搜索树中序遍历为有序序列

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        findTarget(root);
        swap(Target1->val, Target2->val);
        return;
    }
private:
    void findTarget(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        findTarget(root->left);
        if (FormerNode->val > root->val) {
            if (Target1 == nullptr) {
                Target1 = FormerNode;
                Target2 = root;
            }
            else {
                Target2 = root;
            }
        }
        FormerNode = root;
        findTarget(root->right);
        return;
    }
    TreeNode* Target1 = nullptr;
    TreeNode* Target2 = nullptr;
    TreeNode  FirstNode = { -1024 * 1024 * 1024 * 2, nullptr, nullptr };
    TreeNode* FormerNode = &FirstNode;

};