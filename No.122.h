#pragma once
#include"1.h"


//动态规划正统解法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> own_stock;
        vector<int> off_stock;

        own_stock.push_back(-prices[0]);
        off_stock.push_back(0);

        for (int i = 1; i < prices.size(); i++) {
            own_stock.push_back(max(own_stock[i - 1], off_stock[i - 1] - prices[i]));
            off_stock.push_back(max(own_stock[i - 1] + prices[i], off_stock[i - 1]));
        }

        return off_stock[prices.size() - 1];
    }
};

//动态规划正统解法的空间优化

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //vector<int> own_stock;
        //vector<int> off_stock;

        int own_stock = 0;
        int off_stock = 0;

        //own_stock.push_back(-prices[0]);
        //off_stock.push_back(0);

        own_stock = -prices[0];
        off_stock = 0;

        for (int i = 1; i < prices.size(); i++) {
            //own_stock.push_back(max(own_stock[i - 1], off_stock[i - 1] - prices[i]));
            //off_stock.push_back(max(own_stock[i - 1] + prices[i], off_stock[i - 1]));

            int save = own_stock;
            own_stock = max(own_stock, off_stock - prices[i]);
            off_stock = max(save + prices[i], off_stock);
        }

        //return off_stock[prices.size() - 1];

        return off_stock;
    }
};