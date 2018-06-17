#include "header.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return impl(s, 0, n - 1, dp);
    }

    int impl(const string& s, int startIdx, int endIdx, vector<vector<int>>& dp)
    {
        if(startIdx > endIdx) return 0;
        if(startIdx == endIdx) return 1;
        if(dp[startIdx][endIdx] != -1) return dp[startIdx][endIdx];

        if(s[startIdx] == s[endIdx])
            dp[startIdx][endIdx] = 2 + impl(s, startIdx + 1, endIdx - 1, dp);
        else
            dp[startIdx][endIdx] = max(impl(s, startIdx + 1, endIdx, dp),
                                       impl(s, startIdx, endIdx - 1, dp));
        return dp[startIdx][endIdx];
    }
};

int main()
{
    Solution s;
}
