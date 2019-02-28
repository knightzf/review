#include "header.h"

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visits(n, 0);

        function<bool(int)> dfs = [&](int idx)
        {
            if(++visits[idx] > 1) {
                return false;
            } 

            for(int i : graph[idx])
            {
                if(visits[i] < 0) continue;
                
                if(!dfs(i)) {
                    visits[idx] = 2;
                    return false;
                }
            }

            visits[idx] = -1;
            return true;
        };

        for(int i = 0; i < n; ++i)
        {
            if(visits[i] == 0) dfs(i);
        }
        
        vector<int> res;
        for(int i = 0; i < n; ++i)
        {
            if(visits[i] < 2) res.emplace_back(i);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{1,2},{2,3},{5},{0},{5},{},{}};
    s.eventualSafeNodes(a);
}