#pragma once
#include"1.h"

//从记事本方法开始

class Solution {
public:
    int climbStairs(int n) {
        generate(n);
        return map[n];
    }
    void generate(int n) {
        map.insert({ 1,1 });
        map.insert({ 2,2 });
        for (int i = 3; i <= n; i++) {
            int methods = map[i - 1] + map[i - 2];
            map.insert({ i, methods });
        }
        return;
    }
    unordered_map<int, int> map;
};

//优化记事本方法
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int current = 2;
        int last = 1;
        for (int i = 3; i <= n; i++) {
            int save = current;
            current = last + current;
            last = save;
        }
        return current;
    }
};