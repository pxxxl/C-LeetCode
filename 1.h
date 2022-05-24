#pragma once

#include<vector>
#include<tuple>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<array>


using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct NextTreeNode {
		int val;
		NextTreeNode* left;
		NextTreeNode* right;
		NextTreeNode* next;
		NextTreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}
		NextTreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
		NextTreeNode(int _val, NextTreeNode* _left, NextTreeNode* _right, NextTreeNode* _next)
			: val(_val), left(_left), right(_right), next(_next) {}
};

class GNode {
public:
	int val;
	vector<GNode*> neighbors;
	GNode() {
		val = 0;
		neighbors = vector<GNode*>();
	}
	GNode(int _val) {
		val = _val;
		neighbors = vector<GNode*>();
	}
	GNode(int _val, vector<GNode*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};