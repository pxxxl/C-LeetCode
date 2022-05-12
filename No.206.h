#pragma once
#include"1.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode Dumb(0, head);
        ListNode* DumbNode = &Dumb;
        ListNode* Back = DumbNode;
        ListNode* Cur = head;
        ListNode* Front = head->next;
        while (Front != nullptr) {
            Cur->next = Back;
            Back = Cur;
            Cur = Front;
            Front = Front->next;
        }
        Cur->next = Back;
        head->next = nullptr;
        return Cur;
    }
};