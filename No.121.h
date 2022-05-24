#pragma once
#include"1.h"


//用正统的DP来试一试
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v;
        v.push_back(0);
        int minDay = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[minDay]) {
                minDay = i;
            }
            v.push_back(max(v[i - 1], prices[i] - prices[minDay]));
        }
        return v[prices.size()-1];
    }
};