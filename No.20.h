#pragma once
#include "1.h"

//����ʹ��map����߿ɶ���

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (auto v : s) {
            if (S.empty()) {
                S.push(v);
                continue;
            }
            switch (S.top()) {
            case '(':
                if (v == ')') {
                    S.pop();
                }
                else {
                    S.push(v);
                }
                break;
            case '[':
                if (v == ']') {
                    S.pop();
                }
                else {
                    S.push(v);
                }
                break;
            case '{':
                if (v == '}') {
                    S.pop();
                }
                else {
                    S.push(v);
                }
                break;
            }
        }
        if (S.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};