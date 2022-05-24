#pragma once
#include"1.h"

//������Ŀ�����ڰѶ�̬�滮����������
//No.118Ҳ�ǵ�

class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> layer;
        layer.push_back(1);
        for (int i = 1; i <= numRows; i++) {
            layer.push_back(layer[layer.size() - 1]);
            for (int j = layer.size() - 2; j > 0; j--) {
                layer[j] = layer[j] + layer[j - 1];
            }
        }
        return layer;
    }
};