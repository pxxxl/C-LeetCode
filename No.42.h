#pragma once
#include"1.h"

//超时
class Solution {
public:
    int trap(vector<int>& height) {
        for (auto h : height) {
            if (live < h) {
                live = h;
                virt.resize(live, 0);
            }
            for (int i = 0; i < h; i++) {
                water += virt[i];
                virt[i] = 0;
            }
            for (int i = h; i < live;i++) {
                virt[i]++;
            }
        }
        return water;

    }
private:
    vector<int> virt;
    int live  = 0;
    int water = 0;
};

//动态规划
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        vector<int> lh(height.size());
        vector<int> rh(height.size());

        int lefth = 0;
        int righth = 0;

        lh[0] = 0;
        rh[height.size() - 1] = 0;

        for (int i = 1; i < lh.size(); i++) {
            lh[i] = max(lh[i - 1], height[i - 1]);
        }

        for (int i = rh.size() - 2; i > -1; i--) {
            rh[i] = max(rh[i + 1], height[i + 1]);
        }

        int water = 0;

        for (int i = 0; i < height.size(); i++) {
            water += max((min(lh[i], rh[i]) - height[i]), 0);
        }
        return water;
    }
};