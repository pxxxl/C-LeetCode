#pragma once
#include"1.h"


//看了题解，双指针实在太秀了
class Solution {
public:
    int maxArea(vector<int>& height) {
        int hi = height.size() - 1;
        int lo = 0;
        int max1 = min(height[hi] ,height[lo])*(hi-lo);
        while (hi != lo) {
            if (height[hi] > height[lo]) {
                lo++;
            }
            else {
                hi--;
            }
            max1 = max(max1, min(height[hi], height[lo]) * (hi - lo));
        }
        return max1;
    }
};