#pragma once
#include"1.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            return;
        }

        ListNode* Fast = head;
        ListNode* Slow = head;
        while (Fast != nullptr && Fast->next != nullptr) {
            Fast = Fast->next->next;
            Slow = Slow->next;
        }

        ListNode Dumb(0, Slow);
        ListNode* DumbNode = &Dumb;
        ListNode* Back = DumbNode;
        ListNode* Cur = Slow;
        ListNode* Front = Slow->next;
        while (Front != nullptr) {
            Cur->next = Back;
            Back = Cur;
            Cur = Front;
            Front = Front->next;
        }
        Cur->next = Back;
        Slow->next = nullptr;

        ListNode* End = Cur;
        ListNode* Frontier = head;

        ListNode* EndHold;
        ListNode* FrontierHold;
        while (Frontier != End) {
            FrontierHold = Frontier->next;
            EndHold = End->next;
            Frontier->next = End;
            End->next = FrontierHold;

            End = EndHold;
            Frontier = FrontierHold;
        }
        return;
    }
};