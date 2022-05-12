#pragma once
#include"1.h"

//可以从上到下检查，不必像我一样
//可以中序遍历。BST中序遍历必定递增

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return get<0>(detailValidBST(root));
    }

    tuple<bool, int, int> detailValidBST(TreeNode* root) {
        if (root == nullptr)return { true,0,0 };
        int maxHold;
        int minHold;
        if (root->left != nullptr) {
            auto t1 = detailValidBST(root->left);
            if (get<0>(t1) == false || get<1>(t1) >= root->val) {
                return { false, 0,0 };
            }
            minHold = get<2>(t1);
        }
        else {
            minHold = root->val;
        }
        
        if (root->right != nullptr) {
            auto t2 = detailValidBST(root->right);
            if (get<0>(t2) == false || get<2>(t2) <= root->val) {
                return { false,0,0 };
            }
            maxHold = get<1>(t2);
        }
        else {
            maxHold = root->val;
        }
        return { true, maxHold, minHold };
    }
};

class Solution1 {
public:
    bool isValidBST(TreeNode* root) {

    }
};