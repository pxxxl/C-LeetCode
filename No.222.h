#pragma once
#include"1.h"

//30s�ⷨ

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

//������ȫ�������Ķ���������ȡ��
//����ײ��ţ�0��1�ң������ǴӸ����׵�·��
//���ֲ���
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        
    }
};

//�󵽵ף��ҵ��ף������ȼ�Ϊ����������ֱ��pow��
//�������ȣ���Ҫ�ݹ����������������Ŀ
class Solution3 {
public:
    int countNodes(TreeNode* root) {

    }
};

//�ݹ�õ���������������ֻ��Ҫ����һ�θ߶ȣ�֮��root��ʱ�����ø߶�-1�������������߶ȣ�������pow��ߣ��������pow�ұ�
//�ٵݹ������һ��
class Solution3 {
public:
    int countNodes(TreeNode* root) {

    }
};

