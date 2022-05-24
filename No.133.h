#pragma once
#include"1.h"

using Node = GNode;

//没什么经验
//写之前要做好规划呀

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* a = nullptr;
        dfs(a, node);
        return a;
    }

    void dfs(Node*& node, Node*& sample) {
        if (map.find(sample->val) != map.end()) {
            return;
        }
        node = new Node(sample->val);
        map.insert({ node->val, node });
        node->neighbors.resize(sample->neighbors.size());
        for (int i = 0; i < sample->neighbors.size();i++) {
            if (map.find(sample->neighbors[i]->val) != map.end()) {
                node->neighbors[i] = map[sample->neighbors[i]->val];
                continue;
            }
            dfs(node->neighbors[i], sample->neighbors[i]);
        }
        return;
    }

    unordered_map<int, Node*> map;
}; 