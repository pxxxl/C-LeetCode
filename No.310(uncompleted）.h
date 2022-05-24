#pragma once
#include"1.h"

//看了一下题解，才知道可以直接弄最长路径找中点

class Solution {
public:
    vector<vector<int>> t;
    vector<int> dfs(int node, int& maxh, int parent) {

    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0) {
            return {};
        }
        t.resize(n);
        for (auto& e : edges) {
            t[e[0]].push_back(e[1]);
            t[e[1]].push_back(e[0]);
        }

        int branch = t[0].size();
        vector<int> bh;
        bh.resize(branch);
        vector<vector<int>> bpath;
        bpath.resize(branch);

        for (int i = 0; i < branch; i++) {
            int maxh = 0;
            bpath[0] = dfs(t[0][i], maxh, 0);
            bh[0] = maxh;
        }

        
    }
};