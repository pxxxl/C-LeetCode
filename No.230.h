#pragma once
#include"1.h"

//�����ڽ�����ʱ����hash��ڵ��ڲ��洢���������Ľڵ���
//����������һЩ

//����avl

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        kth = k;
        dfs(root);
        return target->val;
    }
    void dfs(TreeNode* root) {
        if (count == kth|| root == nullptr) {
            return;
        }
        dfs(root->left);
        count++;
        if (count == kth) {
            target = root;
            return;
        }
        dfs(root->right);
        return;
    }
    TreeNode* target;
    int count;
    int kth;
};