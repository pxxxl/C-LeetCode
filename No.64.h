#pragma once
#include"1.h"

//不错的动态规划问题
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto v = grid;
        int l = v.size();
        int c = v[0].size();

        for (int i = 1; i < l; i++) {
            v[i][0] += v[i - 1][0];
        }

        for (int i = 1; i < c; i++) {
            v[0][i] += v[0][i - 1];
        }

        for (int i = 1; i < l; i++) {
            for (int j = 1; j < c; j++) {
                v[i][j] += min(v[i - 1][j], v[i][j - 1]);
            }
        }

        return v[l - 1][c - 1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto v = grid;
        int l = v.size();
        int c = v[0].size();

        for (int i = 1; i < l; i++) {
            v[i][0] += v[i - 1][0];
        }

        for (int i = 1; i < c; i++) {
            v[0][i] += v[0][i - 1];
        }

        for (int i = 1; i < l; i++) {
            for (int j = 1; j < c; j++) {
                v[i][j] += min(v[i - 1][j], v[i][j - 1]);
            }
        }

        return v[l - 1][c - 1];
    }
};