#include "header.h"

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for(const auto& v : transactions)
        {
            balance[v[0]] -= v[2];
            balance[v[1]] += v[2];
        }

        vector<int> nonZero;
        for(const auto& p : balance)
            if(p.second) nonZero.push_back(p.second);

        return dfs(nonZero, 0);
    }

    int dfs(vector<int>& nonZero, int idx)
    {
        while(idx < nonZero.size() && !nonZero[idx]) ++idx;
        int res = INT_MAX;
        for(int j = idx + 1; j < nonZero.size(); ++j)
        {
            if(nonZero[j] * nonZero[idx] < 0)
            {
                nonZero[j] += nonZero[idx];
                res = min(res, 1 + dfs(nonZero, idx + 1));
                nonZero[j] -= nonZero[idx];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    Solution s;
}
