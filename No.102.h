#pragma once
#include"1.h"

//条件判别好麻烦

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        q.push(root);
        LayerFront = root;
        while (!q.empty()) {
            Cur = q.front();
            if (LayerFront != nullptr && (Cur == LayerFront->left || (Cur == LayerFront->right && LayerFront->left == nullptr))) {
                Result.push_back(LayerResult);
                LayerResult.clear();
                LayerFront = nullptr;
            }
            if (LayerFront == nullptr && (Cur->left != nullptr || Cur->right != nullptr)) {
                LayerFront = Cur;
            }
            q.pop();
            if (Cur->left != nullptr) {
                q.push(Cur->left);
            }
            if (Cur->right != nullptr) {
                q.push(Cur->right);
            }
            LayerResult.push_back(Cur->val);
        }
        if (!LayerResult.empty()) {
            Result.push_back(LayerResult);
        }
        return Result;
    }
private:
    vector<vector<int>> Result;
    vector<int> LayerResult;
    queue<TreeNode*> q;
    TreeNode* Cur;
    TreeNode* LayerFront;
};