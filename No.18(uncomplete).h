#pragma once
#include"1.h"

//失败的解法
//标准：用双指针去掉一层循环之后O3
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (3 * nums[i] + nums[j] > target) {
                j--;
                continue;
            }
            else if (3 * nums[j] + nums[i] < target) {
                i++;
                continue;
            }
            else {
                int k = i + 1;
                int l = j - 1;

                while (k < l) {
                    if (nums[i] + nums[k] + nums[l] + nums[j] == target) {
                        v.push_back({ nums[i] , nums[k] , nums[l] , nums[j] });
                        k++;while (k < l && nums[k] == nums[k - 1])k++;
                        l--;while (k < l && nums[l] == nums[l + 1])l--;
                    }
                    else if (nums[i] + nums[k] + nums[l] + nums[j] > target) {
                        l--; while (k < l && nums[l] == nums[l + 1])l--;
                    }
                    else {
                        k++; while (k < l && nums[k] == nums[k - 1])k++;
                    }
                }
            }
            i++;
        }

        i = 0;
        j = nums.size() - 1;
        while (i < j) {
            if (3 * nums[i] + nums[j] > target) {
                j--;
                continue;
            }
            else if (3 * nums[j] + nums[i] < target) {
                i++;
                continue;
            }
            else {
                int k = i + 1;
                int l = j - 1;

                while (k < l) {
                    if (nums[i] + nums[k] + nums[l] + nums[j] == target) {
                        vector<int> vec({ nums[i] , nums[k] , nums[l] , nums[j] });
                        if (find(v.begin(), v.end(), vec) == v.end()) {
                            v.push_back({ nums[i] , nums[k] , nums[l] , nums[j] });
                        }
                        k++; while (k < l && nums[k] == nums[k - 1])k++;
                        l--; while (k < l && nums[l] == nums[l + 1])l--;
                    }
                    else if (nums[i] + nums[k] + nums[l] + nums[j] > target) {
                        l--; while (k < l && nums[l] == nums[l + 1])l--;
                    }
                    else {
                        k++; while (k < l && nums[k] == nums[k - 1])k++;
                    }
                }
            }
            j--;
        }
        return v;
    }
};