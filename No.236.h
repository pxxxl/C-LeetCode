#pragma once
#include"1.h"

//最暴力解法，tm二话不说生成parent散列
//然后为所欲为

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        generateParentHash(root);
        parent.insert({ root, nullptr });
        TreeNode* cur = p;
        while (cur != nullptr) {
            path1.push_back(cur);
            cur = parent[cur];
        }
        cur = q;
        while (cur != nullptr) {
            path2.push_back(cur);
            cur = parent[cur];
        }
        TreeNode* save;
        for (auto& v1 : path1) {
            for (auto& v2 : path2) {
                if (v1 == v2) {
                    save = v1;
                    goto out;
                }
            }
        }
    out:
        return save;
    }
    void generateParentHash(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            parent.insert({ root->left, root });
            generateParentHash(root->left);
        }
        if (root->right != nullptr) {
            parent.insert({ root->right,root });
            generateParentHash(root->right);
        }
    }
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
};

//回溯法确定路径

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        dfs(root);
        TreeNode* save = nullptr;
        for (auto& v1 : path1) {
            for (auto& v2 : path2) {
                if (v1 == v2) {
                    save = v1;
                }
            }
        }
        return save;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root);
        if (root == p) {
            if (path1.empty()) {
                path1 = path;
            }
            else {
                path2 = path;
            }
        }
        if (root == q) {
            if (path1.empty()) {
                path1 = path;
            }
            else {
                path2 = path;
            }
        }
        dfs(root->left);
        dfs(root->right);
        path.pop_back();
        return;
    }
    TreeNode* p;
    TreeNode* q;
    vector<TreeNode*> path;
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
};