#pragma once
#include"1.h"

//哑节点真能解决很多复杂的细节问题！
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }
        ListNode* dumb = new ListNode(0, head);
        ListNode* fast = head;
        ListNode* slow = dumb;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* save = slow->next;
        if (save == nullptr) {
            delete dumb;
            return head;
        }
        else {
            slow->next = slow->next->next;
            delete save;
        }

        save = dumb->next;
        delete dumb;
        return save;
        

    }
};