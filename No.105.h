#pragma once
#include"1.h"

class Solution {
public:
    unordered_map<int, int> map;
    int cursor = 0;
    TreeNode* buildHelper(int begin, int end, vector<int>& preorder, vector<int>& inorder) {
        if (begin >= end) {
            return nullptr;
        }
        int position = map[preorder[cursor]];
        cursor++;
        TreeNode* t = new TreeNode(inorder[position]);
        t->left = buildHelper(begin, position, preorder, inorder);
        t->right = buildHelper(position + 1, end, preorder, inorder);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map.insert({ inorder[i], i });
        }
        return buildHelper(0, inorder.size(), preorder, inorder);
    }
};