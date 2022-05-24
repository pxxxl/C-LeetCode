#pragma once
#include"1.h"


//ʲôbug
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool is_valid = true;
        bool check[9] = { 0 };
        auto clear = [&]() {
            check[0] = 0;
            check[1] = 0;
            check[2] = 0;
            check[3] = 0;
            check[4] = 0;
            check[5] = 0;
            check[6] = 0;
            check[7] = 0;
            check[8] = 0;
        };
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]-'0']) {
                        check[j] = true;
                    }
                    else {
                        return false;
                    }
                }
            }
            clear();
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (check[board[j][i] - '0']) {
                        check[j] = true;
                    }
                    else {
                        return false;
                    }
                }
            }
            clear();
        }

        auto c = [&](int lb, int le, int cb, int ce) {
            clear();
            for (int i = lb; i < le; i++) {
                for (int j = cb; j < ce; j++) {
                    if (board[i][j] != '.') {
                        if (check[board[i][j] - '0']) {
                            check[j] = true;
                        }
                        else {
                            is_valid = false;
                        }
                    }
                }
            }
        };

        c(0, 3, 0, 3);
        c(3, 6, 0, 3);
        c(6, 9, 0, 3);

        c(0, 3, 3, 6);
        c(3, 6, 3, 6);
        c(6, 9, 3, 6);

        c(0, 3, 6, 9);
        c(3, 6, 6, 9);
        c(6, 9, 6, 9);
        return is_valid;
    }
};