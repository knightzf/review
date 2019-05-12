#include "header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= n; ++i)
        {
            if(p[i - 1] == '*') dp[0][i] = dp[0][i - 2];
        }

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(isalpha(p[j - 1])) dp[i][j] = s[i - 1] == p[j - 1] && dp[i - 1][j - 1];
                else if(p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    if(isalpha(p[j - 2])) {
                        dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] && (dp[i - 1][j] || dp[i - 1][j - 1]));
                    } else {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution s;
    cout<<s.isMatch("aa", "a")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("ab", ".*")<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
    cout<<s.isMatch("mississippi", "mis*is*p*.")<<endl;
}