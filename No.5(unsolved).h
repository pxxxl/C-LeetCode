#pragma once
#include"1.h"


//¶þÎ¬DP³õ³¢ÊÔ
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> F;
        F.resize(s.size());
        for (auto& V : F) {
            V.resize(s.size());
        }
        F[0][0] = false;

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                F[i][j] = F[i][j - 1] && lae(i + j, i - j, s);
            }
        }

        for (int j = s.size() - 1; j >= 0; j--) {
            if (F[s.size() - 1][j]) {
                return s.substr(j;
            }
        }
        
    }
    //Legal and Equal
    bool lae(int a, int b, string s) {
        if (a >= 0 && a < s.size() && b >= 0 && b <= s.size() && s[a] == s[b]) {
            return true;
        }
        return false;
    }
};