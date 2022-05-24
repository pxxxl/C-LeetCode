#pragma once
#include"1.h"

//过了，就是太慢
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        this->numOfQueen = 0;
        string a(n, '.');
        v.resize(n,a);
        reverse(-1, n-1);
        return result;
    }

    void reverse(int l, int c) {
        int i = l;
        int j = c;
        while (nextPlace(i, j)) {
            if (canPlace(i, j)) {
                s.insert({ i,j });
                v[i][j] = 'Q';
                numOfQueen++;
                if (numOfQueen == n) {
                    result.push_back(v);
                }
                else {
                    reverse(i, j);
                }
                s.erase({ i,j });
                v[i][j] = '.';
                numOfQueen--;
            }
        }
        return;
    }

    bool nextPlace(int& l, int& c) {
        if (c != n - 1) {
            c++;
        }
        else {
            c = 0;
            l++;
        }
        if (l == n) {
            return false;
        }
        return true;
    }

    bool canPlace(int l, int c) {
        for (auto& queen : s) {
            if (l == queen.first || c == queen.second || (l - queen.first) == (c - queen.second) || (l - queen.first) == (queen.second - c)) {
                return false;
            }
            else {
                continue;
            }
        }
        return true;
    }
    vector<string> v;
    vector<vector<string>> result;
    set<pair<int, int>> s;
    int n;
    int numOfQueen;
};

class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        this->numOfQueen = 0;
        string a(n, '.');
        v.resize(n, a);
        reverse(-1, n - 1);
        return result;
    }

    void reverse(int l, int c) {
        int i = l;
        int j = c;
        while (nextPlace(i, j)) {
            if (canPlace(i, j)) {
                s.insert({ i,j });
                v[i][j] = 'Q';
                numOfQueen++;
                if (numOfQueen == n) {
                    result.push_back(v);
                }
                else {
                    reverse(i, j);
                }
                s.erase({ i,j });
                v[i][j] = '.';
                numOfQueen--;
            }
        }
        return;
    }

    bool nextPlace(int& l, int& c) {
        if (c != n - 1) {
            c++;
        }
        else {
            c = 0;
            l++;
        }
        if (l == n) {
            return false;
        }
        return true;
    }

    bool canPlace(int l, int c) {
        for (auto& queen : s) {
            if (l == queen.first || c == queen.second || (l - queen.first) == (c - queen.second) || (l - queen.first) == (queen.second - c)) {
                return false;
            }
            else {
                continue;
            }
        }
        return true;
    }
    vector<string> v;
    vector<vector<string>> result;
    set<pair<int, int>> s;
    int n;
    int numOfQueen;
};