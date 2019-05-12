#include "header.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) dp[i][i] = true;
        string res = string(1, s[0]);
        for(int len = 2; len <= n; ++len)
        {
            for(int i = 0; i + len <= n; ++i)
            {
                if(s[i] == s[i + len - 1] && (i + 1 > i + len - 2 || dp[i + 1][i + len -2]))
                {
                    dp[i][i + len - 1] = true;
                    if(len > res.size()) {
                        res = s.substr(i, len);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.longestPalindrome("cccc")<<endl;
}