#include "header.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> depMap;
        for(const auto& v : prerequisites) {
            depMap[v[0]].insert(v[1]);
        }
        unordered_map<int, bool> m;
        vector<bool> visited(numCourses, false);
        function<bool(int)> dfs = [&](int idx)
        {
            if(!m.count(idx))
            {
                bool res = true;
                if(visited[idx]) res = false;
                else if(depMap.count(idx)) {
                    visited[idx] = true;
                    for(int i : depMap[idx]) {
                        if(!dfs(i)) {
                            res = false;
                            break;
                        }
                    }
                    visited[idx] = false;
                }                
                m[idx] = res;
            }
            return m[idx];
        };

        for(int i = 0; i < numCourses; ++i) {
            if(!m.count(i))
                if(!dfs(i)) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
}