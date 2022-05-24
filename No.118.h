#pragma once
#include"1.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        vector<int> layer;
        layer.push_back(1);
        r.push_back(layer);
        for (int i = 2; i <= numRows; i++) {
            layer.push_back(layer[layer.size() - 1]);
            for (int j = layer.size() - 2; j > 0; j--) {
                layer[j] = layer[j] + layer[j - 1];
            }
            r.push_back(layer);
        }
        return r;
    }
};