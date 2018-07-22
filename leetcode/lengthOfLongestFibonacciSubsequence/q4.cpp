#include "header.h"

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();

        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
            m[A[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(dp[i][j] == 0)
                    impl(A, i, j, m, dp);
                res = max(res, dp[i][j]);
            }
        }
        return res < 3 ? 0 : res;
    }

    void impl(vector<int>& A, int i, int j, unordered_map<int, int>& m, vector<vector<int>>& dp)
    {
        int t = A[i] + A[j];
        if(m.count(t))
        {
            if(dp[j][m[t]] == 0)
            {
                impl(A, j, m[t], m, dp);
            }
            dp[i][j] = dp[j][m[t]] + 1;
        }
        else
        {
            dp[i][j] = 2;
        }
    }
};

int main()
{
    Solution s;
}
