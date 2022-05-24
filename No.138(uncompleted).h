#pragma once
#include"1.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//原始方法
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* cur = head;
        Node* copy = new Node(cur->val);
        Node* ccur = copy;
        map.insert({ cur, ccur });
        map.insert({ nullptr, nullptr });
        while (cur->next != nullptr) {
            ccur->next = new Node(cur->next->val);
            map.insert({ cur->next, ccur->next });
            cur = cur->next;
            ccur = ccur->next;

        }
        ccur->next = nullptr;

        cur = head;
        ccur = copy;

        while (ccur != nullptr) {
            ccur->random = map[cur->random];
            ccur = ccur->next;
            cur = cur->next;
        }

        return copy;
    }

    map<Node*, Node*> map;
};

//令人惊叹的改进
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        Node* newnode;
        if (head == nullptr) {
            return nullptr;
        }
        if (!map.count(head)) {
            newnode = new Node(head->val);
            map[head] = newnode;
            newnode->next = copyRandomList(head->next);
            newnode->random = copyRandomList(head->random);
        }
        return map[head];
    }
    unordered_map<Node*, Node*> map;
};

//最后，完美的空间O（1）
//有bug难得改了
class Solution3 {
public:
    Node* copyRandomList(Node* head) {
        Node* dumb = new Node(0);
        dumb->next = head;
        Node* cur = dumb;
        Node* tool = nullptr;


        while (cur->next != nullptr) {
            tool = cur->next->next;
            cur->next->next = new Node(cur->next->val);
            cur->next->next->next = tool;
            cur = cur->next->next;
        }


        cur = dumb;
        while (cur->next != nullptr) {
            if (cur->next->random == nullptr) {
                cur->next->next->random = nullptr;
            }
            else {
                cur->next->next->random = cur->next->random->next;
            }
            cur = cur->next->next;
        }
        

        Node* chain = new Node(0);
        cur = chain;
        while (cur->next != nullptr) {
            chain->next = cur->next->next;
            cur->next->next = cur->next->next->next;
            cur = chain->next;
        }

        cur = chain->next;
        delete chain;
        delete dumb;
        return cur;
    }
};