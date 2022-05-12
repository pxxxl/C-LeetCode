#pragma once
#include"1.h"

//����ʹ�ö���

class Solution {
public:
    int firstUniqChar(string s) {
        for (auto& c : s) {
            if (m.find(c) == m.end()) {
                m.insert({ c,0 });
            }
            else {
                m[c]++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 0) {
                return i;
            }
        }
        return -1;
    }
private:
    unordered_map<char, int> m;
};