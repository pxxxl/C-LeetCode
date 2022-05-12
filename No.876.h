#pragma once
#include"1.h"
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* Fast = head;
        ListNode* Slow = head;
        while (Fast != nullptr && Fast->next != nullptr) {
            Fast = Fast->next->next;
            Slow = Slow->next;
        }
        return Slow;
    }
};