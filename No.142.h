#pragma once
#include"1.h"

//set��ɱ��ͬʱ��Ȥ����ѧ�Ƶ�
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        set<ListNode*> set;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (set.find(cur) != set.end()) {
                return cur;
            }
            set.insert(cur);
            cur = cur->next;
        }

        return nullptr;
    }
};