#pragma once
#include"1.h"

//��������Ϊ���壬���Ǹ��ٵ�����
//����ʹ��ջ�����������

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        generateArray(root);
        num = -1;
        size = array.size();
    }
    void generateArray(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        generateArray(root->left);
        array.push_back(root->val);
        generateArray(root->right);
        return;
    }

    int next() {
        num++;
        return array[num];
    }

    bool hasNext() {
        if (num >= size - 1) {
            return false;
        }
        return true;
    }
    vector<int> array;
    int num;
    int size;
};