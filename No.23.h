#pragma once
#include"1.h"

//堆排序，但是结果没有想象中那么好
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        heap.resize(1);
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                inHeap({ i, lists[i] });
            }
        }

        ListNode* cur = new ListNode(0, nullptr);
        ListNode* dumb = cur;
        ListNode* tool = nullptr;
        pair<int, ListNode*> hold = outHeap();
        while (hold.first != -1) {
            cur->next = hold.second;
            cur = hold.second;
            tool = lists[hold.first];
            lists[hold.first] = tool->next;
            delete tool;
            inHeap({ hold.first, lists[hold.first] });

            hold = outHeap();
        }

        cur->next = nullptr;
        cur = dumb->next;
        delete dumb;
        return cur;
    }

    pair<int, ListNode*> outHeap() {
        if (heap.size() == 1) {
            return{ -1,nullptr };
        }
        auto hold = heap[1];
        int cur = 1;
        bool placed = false;
        while (2 * cur < heap.size()) {
            if (2 * cur + 1 > heap.size()-1) {
                if (heap[heap.size()-1].second->val < heap[2 * cur].second->val) {
                    heap[cur] = heap[heap.size()-1];
                    placed = true;
                    break;
                }
                else {
                    heap[cur] = heap[2 * cur];
                    cur *= 2;
                }
            }
            else {
                if (heap[2 * cur].second->val < heap[2 * cur + 1].second->val) {
                    if (heap[heap.size()-1].second->val < heap[2 * cur].second->val) {
                        heap[cur] = heap[heap.size()-1];
                        placed = true;
                        break;
                    }
                    else {
                        heap[cur] = heap[2 * cur];
                        cur *= 2;
                    }
                }
                else {
                    if (heap[heap.size()-1].second->val < heap[2 * cur + 1].second->val) {
                        heap[cur] = heap[heap.size()-1];
                        placed = true;
                        break;
                    }
                    else {
                        heap[cur] = heap[2 * cur + 1];
                        cur = 2 * cur + 1;
                    }
                }
            }

        }
        if (!placed) {
            heap[cur] = heap[heap.size()-1];
        }
        heap.resize(heap.size()-1);
        return hold;
    }

    void inHeap(pair<int, ListNode*> in) {
        if (in.second == nullptr) {
            return;
        }
        int s = heap.size();
        heap.resize(heap.size() + 1);

        while (s > 1 && in.second->val < heap[s/2].second->val) {
            heap[s] = heap[s / 2];
            s = s / 2;
        }

        heap[s] = in;
        return;
    }

    vector<pair<int, ListNode*>> heap;
};