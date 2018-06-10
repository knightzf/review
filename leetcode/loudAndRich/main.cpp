#include "header.h"

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        if(n == 0) return {};
        unordered_map<int, unordered_set<int>> poorMap;
        for(const auto& p : richer)
        {
            poorMap[p[1]].insert(p[0]);
        }

        unordered_map<int, int> quietMap;
        for(int i = 0; i < n; ++i)
        {
            quietMap[quiet[i]] = i;
        }

        vector<int> result(n, -1);

        for(int i = 0; i < n; ++i)
        {
            if(result[i] == -1)
            {
                dfs(poorMap, quietMap, quiet, result, i);
            }
        }
        return result;
    }

    int dfs(unordered_map<int, unordered_set<int>>& poorMap,
            unordered_map<int, int>& quietMap,
            vector<int>& quiet,
            vector<int>& result,
            int idx)
    {
        if(poorMap.count(idx) == 0)
        {
            result[idx] = idx;
            return quiet[idx];
        }

        int res = INT_MAX;
        for(const auto& p : poorMap[idx])
        {
            if(result[p] != -1)
            {
                res = min(res, quiet[result[p]]);
            }
            else
            {
                res = min(res, dfs(poorMap, quietMap, quiet, result, p));
            }
        }

        res = min(res, quiet[idx]);
        result[idx] = quietMap[res];
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int> b{3,2,5,4,6,1,7,0};
    const auto& r = s.loudAndRich(a, b);
    for(int i : r)
        cout<<i<<" ";
    cout<<endl;
}
