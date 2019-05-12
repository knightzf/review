#include "header.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> t;
        function<void(int, int)> dfs = [&](int idx, int cnt)
        {
            if(cnt == 0) {
                res.emplace_back(t);
                return;
            }

            if(n - idx < cnt) return;

            for(int i = idx; i < n; ++i)
            {
                t.push_back(i);
                dfs(i + 1, cnt - 1);
                t.pop_back();
            }
        };
        dfs(1, k);
        return res;
    }
};


int main()
{
    Solution s;
}