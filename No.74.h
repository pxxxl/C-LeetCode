#pragma once
#include"1.h"

//现在二分查找解法难点已经转移到“映射”上去了

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        if (matrix[0].empty()) {
            return false;
        }
        int line = matrix.size();
        int column = matrix[0].size();
        auto visit = [&](int num) {
            return matrix[num / column][num % column];
        };
        int l = 0;
        int r = line * column - 1;
        while (l <= r) {
            int  c = (l + r) / 2;
            if (visit(c) == target) {
                return true;
            }
            else if (visit(c) < target) {
                l = c + 1;
            }
            else {
                r = c - 1;
            }
        }
        return false;
    }
};