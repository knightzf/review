#include "header.h"

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        map<tuple<int, int, int>, int> m;
        function<int(int, int, int)> dfs = [&](int startIdx, int endIdx, int val)
        {
            auto key = make_tuple(startIdx, endIdx, val);
            if(!m.count(key))
            {
                int t = dp[startIdx][endIdx] + A[startIdx] * A[endIdx] * val;
                for(int i = startIdx + 1; i < endIdx; ++i)
                {
                    t = min(t, dfs(startIdx, i, val) + dfs(i, endIdx, val));
                }
                m[key] = t;
            }
            return m[key];
        };
        for(int len = 2; len < n; ++len)
        {
            for(int i = 0; i + len < n; ++i)
            {
                dp[i][i + len] = dfs(i, i + len - 1, A[i + len]);
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    Solution s;
    vector<int> a{35,73,90,27,71,80,21,33,33,13,48,12,68,70,80,36,66,3,70,58};
    cout<<s.minScoreTriangulation(a)<<endl;
}

