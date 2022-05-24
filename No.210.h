#pragma once
#include"1.h"

using Node = GNode;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node*> ns;
        vector<int> in;

        ns.resize(numCourses);
        in.resize(numCourses);

        for (int i = 0; i < numCourses; i++) {
            ns[i] = new Node(i);
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            in[prerequisites[i][0]]++;
            ns[prerequisites[i][1]]->neighbors.push_back(ns[prerequisites[i][0]]);
        }

        vector<int> found;
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
            found.push_back(j);
            for (auto& n : ns[j]->neighbors) {
                in[n->val]--;
            }
            in[j]--;
        }

        if (find_0) {
            return found;
        }
        else {
            return vector<int>();
        }
    }
};


//dfs,配合栈
class Solution2 {
public:
    //你的下一张图，又何必是图
    vector<vector<int>> g;
    vector<int> visit;
    vector<int> result;//假栈
    bool valid = true;

    void dfs(int node) {
        if (visit[node] == 2) {
            return;
        }
        visit[node] = 1;
        for (auto& n : g[node]) {
            if (visit[n] == 1) {
                valid = false;
                return;
            }
            dfs(n);
            if (!valid) {
                return;
            }
        }

        visit[node] = 2;
        result.push_back(node);
        return;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visit.resize(numCourses);
        g.resize(numCourses);
        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }
        
        if (valid) {
            reverse(result.begin(), result.end());
            return result;
        }
        else {
            return {};
        }
    }
};


//bfs，属于是我的解法的优化
class Solution3 {
public:
    vector<vector<int>> g;
    queue<int> q;
    vector<int> result;
    vector<int> in;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        in.resize(numCourses);

        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);
            in[p[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& n : g[node]) {
                in[n]--;
                if (in[n] == 0) {
                    q.push(n);
                }
            }
            result.push_back(node);
        }

        if (result.size() == numCourses) {
            return result;
        }
        return {};
    }
};