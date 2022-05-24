#pragma once
#include"1.h"
/*
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
*/

//不想照着以前的模板做
//二级指针太JB难了！！！
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* versa = nullptr;

        if (slow->next == nullptr) {

        }
        else {
            ListNode* form = slow;
            ListNode* cur = slow->next;
            ListNode* save = cur->next;
            slow->next = nullptr;

            while(save != nullptr) {
                cur->next = form;
                form = cur;
                cur = save;
                save = cur->next;
            }

            cur->next = form;
            versa = cur;
        }

        ListNode** cursor = &head->next;

        while (*cursor != nullptr) {
            ListNode* vh = versa->next;
            ListNode* h = (*cursor);

            (*cursor) = versa;
            versa->next = h;
            versa = vh;
            if (vh->next == nullptr) {
                break;
            }
            cursor = &h;
        }

        return;
    }
};