#pragma once
#include"1.h"

//思路要清晰，这次挺不错

class Solution {
public:
    vector<vector<int>> result;
    vector<int> layerResult;
    TreeNode* layerFront = nullptr;
    queue<TreeNode*> q;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return result;
        }
        q.push(root);
        TreeNode* cur;
        while (!q.empty()) {
            cur = q.front();
            if (layerFront == nullptr) {
                if (cur->left != nullptr || cur->right != nullptr) {
                    layerFront = cur;
                }
            }
            else if(cur == layerFront->left||cur==layerFront->right) {
                layerFront = nullptr;
                result.push_back(layerResult);
                layerResult.clear();
                continue;
            }
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
            layerResult.push_back(cur->val);
            q.pop();
        }
        if (!layerResult.empty()) {
            result.push_back(layerResult);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};