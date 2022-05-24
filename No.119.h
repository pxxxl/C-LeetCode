#pragma once
#include"1.h"

//这种题目就属于把动态规划往我嘴里塞
//No.118也是的

class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> layer;
        layer.push_back(1);
        for (int i = 1; i <= numRows; i++) {
            layer.push_back(layer[layer.size() - 1]);
            for (int j = layer.size() - 2; j > 0; j--) {
                layer[j] = layer[j] + layer[j - 1];
            }
        }
        return layer;
    }
};