#pragma once
#include"1.h"
//来吧动态规划的困难题！

//我将使用动态规划正统解法将你击败！
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> A;
        vector<int> B;
        vector<int> C;
        vector<int> D;
        vector<int> E;

        A.resize(prices.size());
        B.resize(prices.size());
        C.resize(prices.size());
        D.resize(prices.size());
        E.resize(prices.size());

        A[0] = 0;
        B[0] = -prices[0];
        C[0] = -100000;
        D[0] = -100000;
        E[0] = -100000;


        for (int i = 1; i < prices.size(); i++) {
            A[i] = 0;
            B[i] = max(A[i - 1] - prices[i], B[i - 1]);
            C[i] = max(B[i - 1] + prices[i], C[i - 1]);
            i > 1 ? D[i] = max(C[i - 1] - prices[i], D[i - 1]) : D[i] = -10000;
            i > 2 ? E[i] = max(D[i - 1] + prices[i], E[i - 1]) : E[i] = -10000;
        }

        return max(max(E[prices.size() - 1], C[prices.size() - 1]), 0);
    }
};

//第一次优化，不再使用数组
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //vector<int> A;
        //vector<int> B;
        //vector<int> C;
        //vector<int> D;
        //vector<int> E;

        int A;
        int B;
        int C;
        int D;
        int E;

        //A.resize(prices.size());
        //B.resize(prices.size());
        //C.resize(prices.size());
        //D.resize(prices.size());
        //E.resize(prices.size());

        //A[0] = 0;
        //B[0] = -prices[0];
        //C[0] = -100000;
        //D[0] = -100000;
        //E[0] = -100000;

        A = 0;
        B = -prices[0];
        C = -100000;
        D = -100000;
        E = -100000;

        for (int i = 1; i < prices.size(); i++) {
            //A[i]         = 0;
            //B[i]         = max(A[i - 1] - prices[i], B[i - 1]);
            //C[i]         = max(B[i - 1] + prices[i], C[i - 1]);
            //i > 1 ? D[i] = max(C[i - 1] - prices[i], D[i - 1]) : D[i] = -10000;
            //i > 2 ? E[i] = max(D[i - 1] + prices[i], E[i - 1]) : E[i] = -10000;

            int sA = A;
            int sB = B;
            int sC = C;
            int sD = D;
            int sE = E;

            A = 0;
            B = max(sA - prices[i], sB);
            C = max(sB + prices[i], sC);
            i > 1 ? D = max(sC - prices[i], sD) : D = -10000;
            i > 2 ? E = max(sD + prices[i], sE) : E = -10000;
        }
        return max(max(E, C), 0);
    }
};