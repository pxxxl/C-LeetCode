#pragma once
#include "1.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> result({100000});
        result.resize(nums.size() ,100000);
        result[0] = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                result[i + j] = min(result[i + j], result[i] + 1);
            }
        }
        return result[nums.size() - 1];
    }
};