#pragma once
#include"1.h"

//˫ָ�뷨��ע��ϸ�ڣ�
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                j--;
            }
            else {
                i++;
            }
        }

        return i;
    }
};