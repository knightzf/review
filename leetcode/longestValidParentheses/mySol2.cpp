#include "header.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; ++i)
        {
            if(s[i] == ')')
            {
                if(s[i - 1] == ')') {
                    if(dp[i - 1]) {
                        int j = i - 1 - dp[i - 1];
                        if(j >= 0 && s[j] == '(') {
                            dp[i] = dp[i - 1] + 2;
                        }
                    } 
                } else {
                    dp[i] = 2;
                }

                if(i - dp[i] >= 0 && dp[i - dp[i]]) {
                    dp[i] += dp[i - dp[i]];
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.longestValidParentheses("()(())");
}