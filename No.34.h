#pragma once
#include"1.h"

//思想还没完全放开呀，释放二分查找的力量吧！

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }
        int left = 0;
        int right = nums.size() - 1;
        int center = (left + right) / 2;
        while (left <= right) {
            center = (left + right) / 2;
            if (nums[center] == target) {
                break;
            }
            else if (nums[center] < target) {
                left = center + 1;
            }
            else {
                right = center - 1;
            }
        }
        if (nums[center] != target) {
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }
        int lr = center;
        int lc = (left + lr) / 2;
        while (left <= lr) {
            lc = (left + lr) / 2;
            if (nums[lc] < target) {
                left = lc + 1;
            }
            else {
                lr = lc - 1;
            }
        }
        int rl = center;
        int rc = (center + right) / 2;
        while (rl <= right) {
            rc = (rl + right) / 2;
            if (nums[rc] <= target) {
                rl = rc + 1;
            }
            else {
                right = rc - 1;
            }
        }
        r.push_back(left);
        r.push_back(right);
        return r;
    }
    vector<int> r;
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.empty()) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int l = 0;
        int r = nums.size() - 1;
        int lc = 0;
        while (l <= r) {
            lc = (l + r) / 2;
            if (nums[lc] >= target) {
                r = lc - 1;
            }
            else {
                l = lc + 1;
            }
        }
        if (l != nums.size() && nums[l] == target) {
            result.push_back(l);
        }
        else {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        l = 0;
        r = nums.size() - 1;
        int rc = 0;
        while (l <= r) {
            rc = (l + r) / 2;
            if (nums[rc] <= target) {
                l = rc + 1;
            }
            else {
                r = rc - 1;
            }
        }
        result.push_back(r);
        return result;
    }
};