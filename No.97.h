#pragma once
#include"1.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n){
            return {};
        }
        return Solution::generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            return {nullptr};
        }
        for (int i = start; i <= end; i++) {
            auto left = generate(start, i - 1);
            auto right = generate(i + 1, end);
            for (auto& v1 : left) {
                for (auto& v2 : right) {
                    auto a = new TreeNode(i, v1, v2);
                    result.push_back(a);
                }
            }
        }
        return result;
    }
};