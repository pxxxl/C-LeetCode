#pragma once
#include"1.h"

//链表转换成数组，我认为还蛮快的

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            nums.push_back(cur->val);
        }
        return sortedArrayToBST(nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return reverseBST(nums, 0, nums.size());
    }
    TreeNode* reverseBST(vector<int>& nums, int begin, int end) {
        if (begin >= end) {
            return nullptr;
        }
        int mid = (begin + end) / 2;
        TreeNode* root = nullptr;
        root = new TreeNode(nums[mid]);
        root->left = reverseBST(nums, begin, mid);
        root->right = reverseBST(nums, mid + 1, end);
        return root;
    }
    vector<int> nums;
};

//利用搜索树中序遍历得到递增数列的特性，一边建树一边中序遍历

class Solution2 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        return midTravel(head, 0, getLength(head));
    }
    TreeNode* midTravel(ListNode*& head, int begin, int end) {
        if (end - begin == 1) {
            TreeNode* t = new TreeNode(head->val);
            head = head->next;
            return t;
        }
        if (end - begin == 0||head == nullptr) {
            return nullptr;
        }
        TreeNode* t = new TreeNode(0);
        int mid = (end + begin) / 2;
        t->left = midTravel(head, begin, mid);
        t->val = head->val;
        head = head->next;
        t->right = midTravel(head, mid + 1, end);
        return t;
    }
    int getLength(ListNode* head) {
        int i = 0;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next, i++); 
        return i;
    }
};

//也可以建好完全二叉树之后中序遍历填值
class Solution3 {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return putValue(buildTree(getLength(head)), head);
    }
    TreeNode* buildTree(int length){
        if (length <= 0) {
            return nullptr;
        }
        int count = 0;
        TreeNode* root = new TreeNode;
        q.push(root);
        count++;
        if (count == length) {
            return root;
        }
        while(true) {
            TreeNode* cur = q.front();
            q.pop();
            cur->left = new TreeNode;
            count++;
            if (count == length) {
                break;
            }
            q.push(cur->left);

            cur->right = new TreeNode;
            count++;
            if (count == length) {
                break;
            }
            q.push(cur->right);
        }
        return root;
    }
    TreeNode* putValue(TreeNode* root, ListNode*& head) {
        if (root == nullptr) {
            return nullptr;
        }
        putValue(root->left, head);
        root->val = head->val;
        head = head->next;
        putValue(root->right, head);
        return root;
    }
    int getLength(ListNode* head) {
        int i = 0;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next, i++);
        return i;
    }
    queue<TreeNode*> q;
};