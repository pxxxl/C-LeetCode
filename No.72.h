#pragma once
#include"1.h"


//哼，看了题解，接下来使用正统动态规划击败你！
//好！难！
class Solution {
public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> v;
        v.resize(word1.size() + 1);

        for (int i = 0; i < v.size(); i++) {
            v[i].resize(word2.size() + 1);
            v[i][0] = i;
        }

        for (int i = 0; i < v[0].size(); i++) {
            v[0][i] = i;
        }

        for (int i = 1; i < v.size(); i++) {
            for (int j = 1; j < v[0].size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    v[i][j] = v[i - 1][j - 1];
                }
                else {
                    v[i][j] = min(min(v[i - 1][j - 1], v[i][j - 1]), v[i - 1][j]) + 1;
                }
            }
        }

        return v[v.size() - 1][v[0].size() - 1];
    }
};