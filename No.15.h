#pragma once
#include"1.h"


//看了题解，排序是一个很好的先决方法

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;

        for (int i = 0; i < nums.size(); ) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k && k > i) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    v.push_back({ nums[i],nums[j],nums[k] });
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    k--;
                    while (k > j && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                    while (k > j && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
                else {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }

            i++;
            while (i < nums.size() && nums[i] == nums[i-1]) {
                i++;
            }
        }

        return v;
    }
};
