#pragma once
#include"1.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        dfs(root);
        return result;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        sum += root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target) {
                result.push_back(path);
            }
            path.pop_back();
            sum -= root->val;
            return;
        }
        dfs(root->left);
        dfs(root->right);
        sum -= root->val;
        path.pop_back();
        return;
    }
    vector<vector<int>> result;
    vector<int> path;
    int sum;
    int target;
};

//�и���С�����⣬for(...;i < stack.size();i++){��ջ����}
//����stack sizeһֱ�ڼ�С������Ҫ�ñ�������stacksize��

//���ɣ���map����ÿһ���ӽڵ�ĸ��ڵ�

class Solution2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        generateMap(root);
        bfs(root);
        return result;
    }
    void bfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        q.push({ root, root->val});
        while (!q.empty()) {
            auto pairs = q.front();
            q.pop();
            if (pairs.first->left == nullptr && pairs.first->right == nullptr) {
                if (pairs.second == target) {
                    generatePath(pairs.first);
                }
            }
            if (pairs.first->left != nullptr) {
                q.push({ pairs.first->left, pairs.second + pairs.first->left->val });
            }
            if (pairs.first->right != nullptr) {
                q.push({ pairs.first->right, pairs.second + pairs.first->right->val });
            }
        }
        return;
    }
    void generatePath(TreeNode* leave) {
        if (leave == nullptr) {
            return;
        }
        stack<TreeNode*> anti_path;
        anti_path.push(leave);
        auto parent = map.find(leave);
        for (; parent != map.end(); parent = map.find(parent->second)) {
            anti_path.push(parent->second);
        }
        path.clear();
        int size = anti_path.size();
        for (int i = 0; i < size; i++) {
            path.push_back(anti_path.top()->val);
            anti_path.pop();
        }
        result.push_back(path);
        return;
    }
    void generateMap(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            map.insert({ root->left, root });
        }
        if (root->right != nullptr) {
            map.insert({ root->right, root });
        }
        generateMap(root->left);
        generateMap(root->right);
        return;
    }
    vector<vector<int>> result;
    vector<int> path;
    queue<pair<TreeNode*, int>> q;
    unordered_map<TreeNode*, TreeNode*> map;
    int target;
};