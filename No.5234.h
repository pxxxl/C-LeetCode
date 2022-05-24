#pragma once
#include"1.h"

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        word1.resize(26);
        word2.resize(26);

        auto it = words.begin();
        it++;
        while (it != words.end()) {
            auto form = it-1;
            if (isSDiff(*form, *it)) {
                it = words.erase(it);
            }
            else {
                it++;
            }
        }
        return words;
    }

    bool isSDiff(string a, string b) {
        if (a.size() == b.size()) {
            word1.erase(word1.begin(), word1.end());
            word1.resize(26, 0);
            word2.erase(word2.begin(), word2.end());
            word2.resize(26, 0);
            for (auto& c : a) {
                word1[c - 'a']++;
            }
            for (auto& c : b) {
                word2[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (word1[i] != word2[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    vector<int> word1;
    vector<int> word2;
};