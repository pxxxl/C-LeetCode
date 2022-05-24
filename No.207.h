#pragma once
#include"1.h"

//拓扑排序是吧，我将使用哈希表将你击败
//算了vector一样的

//看No210的三种排序方法

using Node = GNode;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node*> ns;
        vector<int> in;

        ns.resize(numCourses);
        in.resize(numCourses);

        for (int i = 0; i < numCourses;i++) {
            ns[i] = new Node(i);
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            in[prerequisites[i][0]]++;
            ns[prerequisites[i][1]]->neighbors.push_back(ns[prerequisites[i][0]]);
        }

        int find_0 = true;
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (in[j] == 0) {
                    break;
                }
            }
            if (j == numCourses) {
                find_0 = false;
                break;
            }
            for (auto& n : ns[j]->neighbors) {
                in[n->val]--;
            }
            in[j]--;
        }

        return find_0;
    }
};