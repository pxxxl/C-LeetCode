#pragma once
#include"1.h"

//我想这是个递推问题而不是动态规划
//可以滚动数组优化
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> v = obstacleGrid;
        int l = obstacleGrid.size();
        int c = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 0) {
            v[0][0] = 1;
        }
        else {
            return 0;
        }
        
        for (int i = 1; i < l; i++) {
            if (obstacleGrid[i][0] == 1) {
                v[i][0] = 0;
            }
            else {
                v[i][0] = v[i - 1][0];
            }
        }
        for (int i = 1; i < c; i++) {
            if (obstacleGrid[0][i] == 1) {
                v[0][i] = 0;
            }
            else {
                v[0][i] = v[0][i - 1];
            }
        }

        for (int i = 1; i < l; i++) {
            for (int j = 1; j < c; j++) {
                if (obstacleGrid[i][j] == 1) {
                    v[i][j] = 0;
                }
                else {
                    v[i][j] = v[i - 1][j] + v[i][j - 1];
                }
            }
        }
        
        return v[l - 1][c - 1];
    }
};