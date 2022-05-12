#pragma once
#include"1.h"

//使用单调栈生成nums2的每一个右最大元素，用散列表存储结果

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for (int i = nums2.size() - 1; i != -1; i--) {
            auto& v = nums2[i];
            while (true) {
                if (s.empty()) {
                    m.insert({ v, -1 });
                    break;
                }
                else {
                    if (v < s.top()) {
                        m.insert({ v, s.top() });
                        break;
                    }
                    else {
                        s.pop();
                    }
                }
            }
            s.push(v);
        }
        for (auto& v : nums1) {
            result.push_back(m[v]);
        }
        return result;
    }
private:
    vector<int> result;
    stack<int> s;
    unordered_map<int, int> m;
};