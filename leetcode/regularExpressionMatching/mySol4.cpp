#include "header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i < n; ++i) dp[0][i + 1] = p[i] == '*' && dp[0][i - 1];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                switch(p[j]) {
                    case '.':
                        dp[i + 1][j + 1] = dp[i][j];
                        break;
                    case '*':
                        dp[i + 1][j + 1] = dp[i + 1][j] || dp[i + 1][j - 1] ||
                            (p[j - 1] == '.' && dp[i][j + 1]) || (dp[i][j] && s[i] == p[j - 1]);
                        break;
                    default:
                        dp[i + 1][j + 1] = s[i] == p[j] && dp[i][j];
                        break;
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    //cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("aaa", "ab*ac*a")<<endl;
}