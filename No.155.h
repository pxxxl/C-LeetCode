#pragma once
#include"1.h"

//����ʹ�ø���ջ��¼��ÿһ�����ֶ�Ӧ��min������ʱ��O��1��
//Ҳ����ʹ��һ��ջ�����Ǳ���minֵ�����ջ������min�Ĳ�ֵ�����²�ֵʹmin�ı�ʱ����int diff����

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        if (topAbove == 30001) {
            return;
        }
        arr[topAbove] = val;
        topAbove++;

        if (minPointer == -1) {
            minPointer = topAbove - 1;
        }
        else {
            if (arr[topAbove - 1] < arr[minPointer]) {
                minPointer = topAbove - 1;
            }
        }
        return;
    }

    void pop() {
        if (topAbove == 0) {
            return;
        }
        topAbove--;
        if (topAbove == minPointer) {
            if (minPointer == 0) {
                minPointer = -1;
            }
            else {
                int minPosition = 0;
                for (int i = 1; i < topAbove; i++) {
                    if (arr[i] < arr[minPosition]) {
                        minPosition = i;
                    }
                }
                minPointer = minPosition;
            }
        }
        return;
    }

    int top() {
        if (topAbove > 0) {
            return arr[topAbove-1];
        }
        else {
            return -1;
        }
    }

    int getMin() {
        return arr[minPointer];
    }
private:
    int arr[30000] = {0};
    int minPointer = -1;
    int topAbove = 0;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */