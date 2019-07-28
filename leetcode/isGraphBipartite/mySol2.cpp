#include "header.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return true;
        vector<int> p(n, 0);
        for(int i = 0; i < n; ++i) p[i] = i;
        auto getParent = [&](int i) {
            while(i != p[i]) {
                p[i] = p[p[i]];
                i = p[i];
            }
            return i;
        };
        for(int i = 0; i < graph.size(); ++i) {
            const auto& v = graph[i];
            if(v.size() < 2) continue;
            int t = v[0];
            for(int i = 1; i < v.size(); ++i) {
                int pa = getParent(t);
                int pb = getParent(v[i]);
                if(pa != pb) {
                    p[pa] = pb;
                }
            }
            if(getParent(i) == getParent(t)) return false;
        }
        return true;
    }
};


int main()
{
    Solution s;
}