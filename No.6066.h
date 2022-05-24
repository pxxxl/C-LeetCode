#pragma once
#include"1.h"

//³¬Ê±
class CountIntervals {
public:
    CountIntervals() {
        arr = new vector<char>({ 0 });
        arr->resize(100, 0);
        countA = 0;
    }

    void add(int left, int right) {
        if (right >= arr->size()) {
            arr->resize(right + 1, 0);
        }
        for (int i = left; i <= right; i++) {
            if (( * arr)[i] == 0) {
                ( * arr)[i] = 1;
                countA++;
            }
        }
    }

    int count() {
        return countA;
    }

    vector<char>* arr;
    int countA;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */


class CountIntervals {
public:
    CountIntervals() {
        arr = new vector<pair<int, int>>({ { 0,0} });
        arr->resize(0);
        countA = 0;
    }

    void add(int left, int right) {
        int l = 0;
        int r = arr->size() - 1;
        while (l < r) {

        }
    }

    int count() {
        return countA;
    }

    vector<pair<int,int>>* arr;
    int countA;
};