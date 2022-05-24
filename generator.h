#pragma once
#include"1.h"

//TreeNode* BTGenerate(vector<int> v) {
//	if (v.empty()) {
//		return nullptr;
//	}
//	queue<TreeNode*> q;
//	TreeNode* root = new TreeNode(v[0]);
//	q.push(root);
//	int idx = 1;//用以表示当前数组可用的元素下标
//	while (!q.empty() && idx < v.size()) {
//		int cnt = q.size();
//		for (int i = 1; i <= cnt; i++) {
//			TreeNode* cur = q.front();
//			q.pop();
//			//判断左子树是否为空
//			if (v[idx] != -1) {
//				TreeNode* t = new TreeNode(v[idx]);
//				cur->left = t;
//				q.push(cur->left);
//			}
//			idx++;
//			if (idx >= v.size()) {
//				break;
//			}
//			//判断右子树是否为空
//			if (v[idx] != -1) {
//				TreeNode* t = new TreeNode(v[idx]);
//				cur->right = t;
//				q.push(cur->right);
//			}
//			idx++;
//		}
//	}
//	return root;
//}

TreeNode* BTGenerate(vector<int> v) {
	if (v.empty()) {
		return nullptr;
	}
	TreeNode* root = new TreeNode(v[0]);
	TreeNode* cur = nullptr;
	int seq = 1;
	int size = v.size();
	queue<TreeNode*> q;
	q.push(root);
	while (true) {
		cur = q.front();
		q.pop();
		if (seq == size) {
			break;
		}
		else {
			if (v[seq] != -1) {
				cur->left = new TreeNode(v[seq]);
				seq++;
				q.push(cur->left);
			}
			else {
				seq++;
			}
		}
		if (seq == size) {
			break;
		}
		else {
			if (v[seq] != -1) {
				cur->right = new TreeNode(v[seq]);
				seq++;
				q.push(cur->right);
			}
			else {
				seq++;
			}
		}
	}
	return root;
}


ListNode* LLGenerate(vector<int> v) {
	ListNode* dumb = new ListNode;
	auto cur = dumb;
	for (auto& value : v) {
		cur->next = new ListNode(value);
		cur = cur->next;
	}
	cur = dumb->next;
	delete dumb;
	return cur;
}

//GNode* GGenerate(vector<pair<int, int>> v) {
//	map<int, GNode*> map;
//	set<int> nodes;
//	int min_num = INT_MAX;
//	for (auto& p : v) {
//		if (nodes.find(p.first) == nodes.end()) {
//			if (p.first < min_num) {
//				min_num = p.first;
//			}
//			nodes.insert(p.first);
//			map.insert({p.first, new GNode(p.first)});
//		}
//		if (nodes.find(p.second) == nodes.end()) {
//			if (p.second < min_num) {
//				min_num = p.second;
//			}
//			nodes.insert(p.second);
//			map.insert({ p.second, new GNode(p.second) });
//		}
//	}
//
//	for (auto& p : v) {
//		map[p.first]->neighbors.push_back(map[p.second]);
//		map[p.second]->neighbors.push_back(map[p.first]);
//	}
//	
//	return map[min_num];
//}

GNode* GGenerate(vector<vector<int>> v) {
	vector<GNode*> map;
	map.resize(v.size()+1);
	for (int i = 1; i < v.size() + 1;i++) {
		map[i] = new GNode(i);
	}

	for (int i = 1;i< v.size() +1;i++) {
		for (auto& n : v[i-1]) {
			map[i]->neighbors.push_back(map[n]);
		}
	}

	return map[1];
}
