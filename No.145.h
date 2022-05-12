#pragma once
#include"1.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        travel(root);
        return result;
    }
    void travel(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        travel(root->left);
        travel(root->right);
        result.push_back(root->val);
    }
    vector<int> result;
};