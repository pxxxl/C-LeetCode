#pragma once
#include"1.h"

//动态规划经典解法，不优化
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto v = triangle;
        int l = v.size();
        int c = v[v.size() - 1].size();

        for (int i = 1; i < l; i++) {
            v[i][0] += v[i - 1][0];
        }

        for (int i = 1; i < l; i++) {
            v[i][i] += v[i - 1][i - 1];
        }

        for (int i = 1; i < l; i++) {
            for (int j = 1; j < i; j++) {
                v[i][j] += min(v[i - 1][j], v[i - 1][j - 1]);
            }
        }

        int m = 1000000;
        for (int i = 0; i < c; i++) {
            if (v[l - 1][i] <= m) {
                m = v[l - 1][i];
            }
        }
        return m;
    }
};


//滚动数组优化
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //auto v = triangle;
        //int l = v.size();
        //int c = v[v.size()-1].size();

        vector<int> v;
        v.resize(triangle.size());
        int l = triangle.size();

        //for (int i = 1; i < l; i++) {
        //    v[i][0] += v[i - 1][0];
        //}

        //for (int i = 1; i < l; i++) {
        //    v[i][i] += v[i - 1][i - 1];
        //}

        v[0] = triangle[0][0];

        //for (int i = 1; i < l; i++) {
        //    for (int j = 1; j < i; j++) {
        //        v[i][j] += min(v[i - 1][j], v[i - 1][j - 1]);
        //    }
        //}

        for (int i = 1; i < l; i++) {
            v[i] = v[i-1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--) {
                v[j] = triangle[i][j] + min(v[j], v[j - 1]);
            }
            v[0] = triangle[i][0] + v[0];
        }

        int m = 1000000;
        for (int i = 0; i < l; i++) {
            if (v[i] <= m) {
                m = v[i];
            }
        }
        return m;
    }
};