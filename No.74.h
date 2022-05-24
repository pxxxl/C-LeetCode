#pragma once
#include"1.h"

//���ڶ��ֲ��ҽⷨ�ѵ��Ѿ�ת�Ƶ���ӳ�䡱��ȥ��

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