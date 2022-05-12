#pragma once
#include"1.h"
using Node = NextTreeNode;

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* layer_front = root;
        while (layer_front->left != nullptr) {
            Node* cur = layer_front;
            cur->left->next = cur->right;
            while (cur->next != nullptr) {
                cur->right->next = cur->next->left;
                cur = cur->next;
                cur->left->next = cur->right;
            }
            cur->right->next = nullptr;
            layer_front = layer_front->left;
        }
        return root;
    }
};