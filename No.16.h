#pragma once
#include"1.h"


//排序，双指针解法，屡试不爽（2次）

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int sum = nums[1] + nums[2] + nums[3];
        int minsum = sum;
        int min = abs(sum - target);
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }
                else if (sum > target) {
                    if (min > abs(sum - target)) {
                        minsum = sum;
                        min = abs(sum - target);
                    }
                    k--;
                }
                else {
                    if (min > abs(sum - target)) {
                        minsum = sum;
                        min = abs(sum - target);
                    }
                    j++;
                }
            }
        }

        return minsum;
    }
};