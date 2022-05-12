#pragma once
#include"1.h"

//错的，要看清题目
//不过这段代码不错

//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        TreeNode* root = nullptr;
//        if (nums.empty()) {
//            return nullptr;
//        }
//        root = new TreeNode(nums[0]);
//        for (int i = 1; i < nums.size();i++) {
//            TreeNode* cur = root;
//            while (true) {
//                if (cur->val > nums[i]) {
//                    if (cur->left == nullptr) {
//                        cur->left = new TreeNode(nums[i]);
//                        break;
//                    }
//                    cur = cur->left;
//                }
//                else {
//                    if (cur->right == nullptr) {
//                        cur->right = new TreeNode(nums[i]);
//                        break;
//                    }
//                    cur = cur->right;
//                }
//            }
//        }
//        return root;
//    }
//};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return reverseBST(nums, 0, nums.size());
    }
    TreeNode* reverseBST(vector<int>& nums, int begin, int end) {
        if (begin >= end) {
            return nullptr;
        }
        int mid = (begin + end) / 2;
        TreeNode* root = nullptr;
        root = new TreeNode(nums[mid]);
        root->left = reverseBST(nums, begin, mid);
        root->right = reverseBST(nums, mid+1, end);
        return root;
    }
};