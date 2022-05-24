#pragma once
#include"1.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        auto hold = head;
        ListNode* cur = head;
        ListNode** h = &head;
        ListNode* headhold = nullptr;
        bool first = true;
        while (cur != nullptr) {
            for (int i = 1; i < k; i++) {
                cur = cur->next;
                if (cur == nullptr) {
                    goto out;
                }
            }

            if (first) {
                headhold = cur;
                first = false;
            }
            ListNode* taillater = reverseZone(*h, cur);

            ListNode* hold = *h;
            *h = cur;
            h = &(hold->next);
            *h = taillater;
            cur = taillater;
        }

    out:
        return headhold;
    }

    //双闭返回尾后
    //认为双非null
    //认为h！=t
    ListNode* reverseZone(ListNode* head, ListNode* tail) {
        auto hold = tail->next;

        ListNode* cur = head->next;
        ListNode* form = head;
        
        while (cur != tail) {
            ListNode* place = cur->next;
            cur->next = form;
            form = cur;
            cur = place;
            
        }

        tail->next = form;
        return hold;
    }
};