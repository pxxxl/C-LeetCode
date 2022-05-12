#pragma once
#include"1.h"

class Solution {
public:
    unordered_map<int, int> map;
    int cursor;
    TreeNode* buildHelper(int begin, int end, vector<int>& inorder, vector<int>& postorder) {
        if (begin >= end) {
            return nullptr;
        }
        int position = map[postorder[cursor]];
        TreeNode* t = new TreeNode(postorder[cursor]);
        cursor--;
        t->right = buildHelper(position + 1, end, inorder, postorder);
        t->left = buildHelper(begin, position, inorder, postorder);
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            map.insert({ inorder[i], i });
        }
        cursor = inorder.size() - 1;
        return buildHelper(0, inorder.size(), inorder, postorder);
    }
};