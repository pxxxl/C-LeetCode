#pragma once
#include "1.h"

class Solution {
public:
    int calPoints(vector<string>& ops) {
        for (auto& str : ops) {
            if (str == "C") {
                s.pop();
            }
            else if (str == "D") {
                s.push(s.top() * 2);
            }
            else if (str == "+") {
                int sum = s.top();
                int save = s.top();
                s.pop();
                sum += s.top();
                s.push(save);
                s.push(sum);
            }
            else {
                s.push(stoi(str));
            }
        }
        int result = 0;
        while(!s.empty()) {
            result += s.top();
            s.pop();
        }
        return result;
    }
private:
    stack<int> s;
};