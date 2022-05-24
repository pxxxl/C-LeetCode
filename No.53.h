#pragma once
#include"1.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        F.push_back(nums[0]);
        G.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            G.push_back(max(nums[i], nums[i] + G[i - 1]));
        }
        for (int i = 1; i < nums.size(); i++) {
            F.push_back(max(max(G[i - 1] + nums[i], F[i - 1]), nums[i]));
        }
        return F[nums.size() - 1];
    }
    vector<int> F;
    vector<int> G;
};