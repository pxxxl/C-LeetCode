#pragma once

#include"1.h"

//这个方法叫记事本吧，下面用动态规划做一下试试

class Solution {
public:
    int numTrees(int n) {
        int heap[1000] = { 0 };
        this->table = heap;
        this->table[0] = 1;
        this->table[1] = 2;
        if (!n) {
            return {};
        }
        return Solution::generate(1, n);
    }

    int generate(int start, int end) {
        if (start > end) {
            return 1;
        }
        if (this->table[end - start] != 0) {
            return this->table[end - start];
        }
        int sum = 0;
        for (int i = start; i <= end; i++) {
            auto left = generate(start, i - 1);
            auto right = generate(i + 1, end);
            sum += left * right;
        }
        this->table[end - start] = sum;
        return sum;
    }
private:
    int* table;
};

