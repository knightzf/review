#include "header.h"

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        unordered_map<int, unordered_set<int>> m;
        for(const auto& v : edges) {
            m[v[0]].insert(v[1]);
            m[v[1]].insert(v[0]);
        }
        vector<bool> visited(n, false);
        function <bool(int, int)> dfs = [&](int idx, int pre)
        {
            if(visited[idx]) return false;
            visited[idx] = true;
            for(int next : m[idx]) {
                if(next != pre) {
                    if(!dfs(next, idx)) return false;
                }
            }
            return true;
        };
        for(int i = 0; i < n; ++i) {
            if(m.count(i) && !visited[i]) {
                if(!dfs(i, -1)) return false;
            }
        }
        return true;
    }
};

int main()
{
    //Solution s;
}