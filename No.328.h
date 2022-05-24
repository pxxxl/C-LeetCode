#pragma once
#include"1.h"

//Ä¥Á·Ö¸Õë¹¦µ×
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dumb = new ListNode(0, head);
        ListNode* ddumb = new ListNode(0, dumb);
        ListNode* cur  = ddumb;
        ListNode* twi  = new ListNode(0, nullptr);
        ListNode* tcur = twi;

        while (cur->next->next != nullptr && cur->next->next->next != nullptr) {
            tcur->next = cur->next->next->next;
            cur->next->next->next = cur->next->next->next->next;
            cur = cur->next;
            tcur = tcur->next;
        }

        if (cur->next->next == nullptr) {
            cur->next->next = twi->next;
            tcur->next = nullptr;
        }
        else {
            cur->next->next->next = twi->next;
            tcur->next = nullptr;
        }

        return dumb->next;
    }
};

//½úÉý¶þÐÇ³ÌÐòÔ±
class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode* o = head;
        ListNode* t = head->next;

        ListNode** odd = &head->next;
        ListNode** twi = &head->next->next;

        while ((*twi)->next != nullptr && (*twi)->next->next != nullptr) {
            (*odd) = (*twi)->next;
            odd = &(*twi)->next;
            (*twi) = (*odd)->next;
            twi = &(*odd)->next;
        }

        if ((*twi)->next == nullptr) {
            (*twi) = nullptr;
            (*odd) = t;
        }
        else {
            (*odd) = (*twi)->next;
            odd = &(*twi)->next;
            (*twi) = nullptr;
            (*odd) = t;
        }

        return o;
    }
};