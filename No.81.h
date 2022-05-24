#pragma once
#include"1.h"

//No.33抄过来之前还是检查一下再交吧哈哈哈

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        if (nums.empty()) {
            return false;
        }

        int bias = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
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
        int left = Bias(0);

        if (nums[right] == target) {
            return true;
        }

        while (deBias(left) < deBias(right)) {
            int center = Bias((deBias(left) + deBias(right) - 1) / 2);
            if (nums[center] == target) {
                return true;
            }
            else if (nums[center] < target) {
                left = Bias(deBias(center) + 1);
            }
            else {
                right = center;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(nums.begin(), nums.end(), target) != nums.end();
    }
};