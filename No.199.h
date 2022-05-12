#pragma once
#include"1.h"

//可以dfs也可以bfs
//我又掌握了更好的bfs计数方法

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
    void dfs(TreeNode* root, int height) {
        if (root == nullptr) {
            return;
        }
        if (height == result.size()) {
            result.push_back(root->val);
        }
        dfs(root->right, height + 1);
        dfs(root->left, height + 1);
        return;
    }
    vector<int> result;
};

class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>();
        }
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = nullptr;
            for (int i = q.size(); i > 0; i--) {
                cur = q.front();
                q.pop();
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            v.push_back(cur->val);
        }
        return v;
    }
};