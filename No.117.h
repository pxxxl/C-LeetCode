#pragma once
#include"1.h"
using Node = NextTreeNode;

//利用已有的next，这题也可以BFS

class Solution {
public:
    Node* connect(Node* root) {
        Node* layer_front = root;
        Node* cur = root;
        while (true) {
            while (cur != nullptr) {
                if (cur->left != nullptr) {
                    layer_front = cur->left;
                    break;
                }
                if (cur->right != nullptr) {
                    layer_front = cur->right;
                    break;
                }
                cur = cur->next;
            }
            if (cur == nullptr) {
                break;
            }
            Node* son = layer_front;
            //cur的下一层:单层开始
            while (cur != nullptr) {
                if (son == cur->left && cur->right != nullptr) {
                    son->next = cur->right;
                    son = cur->right;
                }
                else {
                    cur = cur->next;
                    while (cur != nullptr) {
                        if (cur->left != nullptr) {
                            son->next = cur->left;
                            son = cur->left;
                            break;
                        }
                        if (cur->right != nullptr) {
                            son->next = cur->right;
                            son = cur->right;
                            break;
                        }
                        cur = cur->next;
                    }
                }
            }
            son->next = nullptr;
            cur = layer_front;
        }
        return root;
    }
};

//BFS
//再遍历某一层时，记录下下一层的节点个数是一个很好的方法

class Solution2 {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        int next_layer_node_num = 1;
        q.push(root);
        while (next_layer_node_num != 0) {
            int this_layer_node_num_left = next_layer_node_num;
            next_layer_node_num = 0;
            Node* cur = nullptr;
            Node* last_cur = nullptr;
            while (this_layer_node_num_left > 0) {
                last_cur = cur;
                cur = q.front();
                q.pop();
                if (last_cur != nullptr) {
                    last_cur->next = cur;
                }
                this_layer_node_num_left--;
                if (cur->left != nullptr) {
                    q.push(cur->left);
                    next_layer_node_num++;
                }
                if (cur->right!= nullptr) {
                    q.push(cur->right);
                    next_layer_node_num++;
                }
            }
            cur->next = nullptr;
        }
        return root;
    }
    queue<Node*> q;
};