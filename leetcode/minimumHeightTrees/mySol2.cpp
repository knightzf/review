#include "header.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        unordered_map<int, unordered_set<int>> m;
        for(const auto& e : edges) {
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }
        deque<int> q;
        for(const auto& p : m) {
            if(p.second.size() == 1) q.push_back(p.first);
        }
        int qsize = q.size();
        while(m.size() > 2) {
            for(int k = 0; k < qsize; ++k) {
                int i = q.front();
                q.pop_front();
                for(int j : m[i]) {
                    m[j].erase(i);
                    if(m[j].size() == 1) q.push_back(j);
                }
                m.erase(i);
            }
            qsize = q.size();
        }
        return vector<int>(q.begin(), q.end());
    }
};

int main()
{
    //Solution s;
}