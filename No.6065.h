#pragma once
#include"1.h"

//³¬Ê±
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<vector<char>> b({0});
        int size = sizeof(int);

        b.resize(candidates.size(),{0});
        for (auto& v : b) {
            v.resize(size, 0);
        }

        for (int j = 0; j < candidates.size();j++) {
            int c = candidates[j];
            for (int i = 0; i < size; i++) {
                b[j][i] = c%2;
                c /= 2;
                if (c == 0) {
                    break;
                }
            }
        }

        int max = 0;
        for (int j = 0; j < size; j++) {
            int count = 0;
            for (int i = 0; i < candidates.size(); i++) {
                count += b[i][j];
            }
            if (max < count) {
                max = count;
            }
        }

        return max;
    }
};


class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<vector<char>> b({ 0 });
        int size = sizeof(int);

        b.resize(candidates.size(), { 0 });
        for (auto& v : b) {
            v.resize(size, 0);
        }

        for (int j = 0; j < candidates.size(); j++) {
            int c = candidates[j];
            for (int i = 0; i < size; i++) {
                b[j][i] = c % 2;
                c /= 2;
                if (c == 0) {
                    break;
                }
            }
        }

        int max = 0;
        for (int j = 0; j < size; j++) {
            int count = 0;
            for (int i = 0; i < candidates.size(); i++) {
                count += b[i][j];
            }
            if (max < count) {
                max = count;
            }
        }

        return max;
    }
};