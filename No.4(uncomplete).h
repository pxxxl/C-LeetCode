#pragma once
#include"1.h"



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int k = 0;
        if (n % 2 == 0) {
            k = n / 2;
        }
        else {
            k = n / 2 + 1;
        }

        int b1 = 0;
        int b2 = 0;
        while (k != 1) {
            if (b1 + k < nums1.size() && b2 + k < nums2.size()) {
                int t1 = b1 + k - 1;
                int t2 = b2 + k - 1;

                if (nums1[t1] < nums2[t2]) {
                    k -= t1 - b1;
                    b1 = t1;
                }
                else {
                    k -= t2 - b2;
                    b2 = t2;
                }
            }
        }


    }
};