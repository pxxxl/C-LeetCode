#pragma once
#include"1.h"


//可行，但超时
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> v({false});
        v.resize(nums.size(), false);
        v[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i] && j + i < nums.size(); j++) {
                v[i + j] = v[i];
            }
        }

        return v[nums.size() - 1];
    }
};