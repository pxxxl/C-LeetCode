#pragma once
#include"1.h"

//这个可以双端队列

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        inStack(root);
        last_node = root;
        while (!stackA.empty() || !stackB.empty()) {
            cur_node = outStack();
            if (dir == direction::to_left) {
                if (cur_node->right != nullptr) {
                    swapStack();
                    inStack(cur_node->right);
                    swapStack();
                }
                if (cur_node->left != nullptr) {
                    swapStack();
                    inStack(cur_node->left);
                    swapStack();
                }
            }
            else {
                if (cur_node->left != nullptr) {
                    swapStack();
                    inStack(cur_node->left);
                    swapStack();
                }
                if (cur_node->right != nullptr) {
                    swapStack();
                    inStack(cur_node->right);
                    swapStack();
                }
            }
            layer_result.push_back(cur_node->val);
            if (nowStackEmpty()) {
                swapStack();
                swapDirection();
                result.push_back(layer_result);
                layer_result.clear();
            }
        }
        if (!layer_result.empty()) {
            result.push_back(layer_result);
        }
        return result;
    }
private:
    enum class direction {
        to_left,
        to_right
    };
    enum class current_stack {
        A,
        B
    };
    void inStack(TreeNode* t) {
        if (cur_s == current_stack::A) {
            stackA.push(t);
        }
        else {
            stackB.push(t);
        }
    }
    TreeNode* outStack() {
        TreeNode* hold;
        if (cur_s == current_stack::A) {
            hold = stackA.top();
            stackA.pop();
            return hold;
        }
        else {
            hold = stackB.top();
            stackB.pop();
            return hold;
        }
    }
    bool nowStackEmpty() {
        if (cur_s == current_stack::A) {
            return stackA.empty();
        }
        else {
            return stackB.empty();
        }
    }
    TreeNode* lookStack() {
        if (cur_s == current_stack::A) {
            return stackA.top();
        }
        else {
            return stackB.top();
        }
    }
    void swapStack() {
        if (cur_s == current_stack::A) {
            cur_s = current_stack::B;
        }
        else {
            cur_s = current_stack::A;
        }
    }
    void swapDirection() {
        if (dir == direction::to_right) {
            dir = direction::to_left;
        }
        else {
            dir = direction::to_right;
        }
    }
    vector<vector<int>> result;
    vector<int> layer_result;
    stack<TreeNode*> stackA;
    stack<TreeNode*> stackB;
    direction dir       = direction::to_right;
    current_stack cur_s = current_stack::A;
    TreeNode* last_node = nullptr;
    TreeNode* cur_node = nullptr;
};