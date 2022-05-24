#pragma once
#include"1.h"

//һ����д�������Ӹ�

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int c = 0;
        while (l <= r) {
            c = (l + r) / 2;
            if (nums[c] >= target) {
                r = c - 1;
            }
            else {
                l = c + 1;
            }
        }
        return l;
    }
};