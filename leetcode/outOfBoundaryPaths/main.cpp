#include "header.h"

class Solution {
public:
    int findPaths(int m, int n, int N, int I, int J) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N + 1, 0)));
        int mod = 1000000007;
        for(int k = 1; k < N + 1; ++k)
        {
            static vector<int> shift{-1, 0, 1, 0, -1};
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(k == 1)
                    {
                        dp[i][j][k] = (i == 0) + (i == m - 1) + (j == 0) + (j == n -1);
                    }
                    else
                    {
                        long t = 0;
                        for(int l = 0; l < 4; ++l)
                        {
                            int newI = i + shift[l];
                            int newJ = j + shift[l + 1];
                            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && dp[newI][newJ][k - 1])
                            {
                                t += dp[newI][newJ][k - 1];
                            }
                        }
                        dp[i][j][k] = t % mod;
                    }
                }
            }
        }

        long res = 0;
        for(int i = 1; i < N + 1; ++i)
            res += dp[I][J][i];
        return res % mod;
    }
};

int main()
{
    Solution s;
}
