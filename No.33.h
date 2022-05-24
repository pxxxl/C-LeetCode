#pragma once
#include"1.h"

//1min版本

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto i = find(nums.begin(), nums.end(), target);
        int j = 0;
        for (auto cur = nums.begin(); cur != i; cur++, j++);
        if (j == nums.size()) {
            return -1;
        }
        return j;
    }
};

//这个solution2是我写过的最精妙的解法之一
//紧缩区间二分查找与环形偏置转换简直是艺术
//可惜计算bias最长是o(n)

class Solution2 {
public:
    int search(vector<int>& nums, int target) {

        if (nums.empty()) {
            return -1;
        }

        int bias = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                bias = i;
                break;
            }
        }

        auto Bias = [bias, n = nums.size()](int a){
            return (a + bias + n) % n;
        };
        auto deBias = [bias, n = nums.size()](int a){
            return (a - bias + n) % n;
        };

        int right = Bias(nums.size() - 1);
        int left  = Bias(0);

        if (nums[right] == target) {
            return right;
        }

        while (deBias(left) < deBias(right)) {
            int center = Bias((deBias(left) + deBias(right) - 1)/2);
            if (nums[center] == target) {
                return center;
            }
            else if (nums[center] < target) {
                left = Bias(deBias(center) + 1);
            }
            else {
                right = center;
            }
        }
        return -1;
    }
};

class Solution3 {
public:
    int search(vector<int>& nums, int target) {

        int cut_point = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                cut_point = i;
                break;
            }
        }

        int left  = 0;
        int right = cut_point - 1;
        while (left <= right) {
            int center = (left + right) / 2;
            if (nums[center] == target) {
                return center;
            }
            else if (nums[center] < target) {
                left = center + 1;
            }
            else {
                right = center - 1;
            }
        }
        left = cut_point;
        right = nums.size() - 1;
        while (left <= right) {
            int center = (left + right) / 2;
            if (nums[center] == target) {
                return center;
            }
            else if (nums[center] < target) {
                left = center + 1;
            }
            else {
                right = center - 1;
            }
        }
        return -1;
    }
};