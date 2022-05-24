#pragma once
#include"1.h"

//常规解法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        auto i = nums.begin();
        auto j = nums.end();

        while (i + 1 != j) {
            if (*i == *(i + 1)) {
                i = nums.erase(i);
                j = nums.end();
                size--;
            }
            else {
                i++;
            }
        }
        return size;
    }
};

//fast slow双指针神速！
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 0;
        int slow = 0;

        while (fast != nums.size()) {
            if (nums[fast] == nums[slow]) {
                fast++;
            }
            else {
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }
        }
        return slow + 1;
    }
};