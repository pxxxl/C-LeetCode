#pragma once
#include"1.h"

//30s解法

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

//利用完全二叉树的二进制特性取巧
//把最底层编号，0左1右，正好是从根到底的路径
//二分查找
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        
    }
};

//左到底，右到底，如果相等即为满二叉树，直接pow。
//如果不相等，则要递归计算左右子树的数目
class Solution3 {
public:
    int countNodes(TreeNode* root) {

    }
};

//递归得到左子树（左子树只需要计算一次高度，之后root左降时可以用高度-1），与右子树高度，如果相等pow左边，如果不等pow右边
//再递归计算另一边
class Solution3 {
public:
    int countNodes(TreeNode* root) {

    }
};

