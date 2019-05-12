#include "header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for(int i = 1; i < n + 1; ++i) {
            dp[0][i] = p[i - 1] == '*' && dp[0][i - 1];
        }

        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                switch(p[j - 1])
                {
                    case '?': dp[i][j] = dp[i - 1][j - 1]; break;
                    case '*': dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; break;
                    default: dp[i][j] = s[i - 1] == p[j - 1] && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
}