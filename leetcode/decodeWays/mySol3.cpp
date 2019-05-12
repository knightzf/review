#include "header.h"

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        if(s[0] != '0') dp[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            int a = s[i] - '0';
            if(a > 0) dp[i] = dp[i - 1];
            int b = (s[i - 1] - '0') * 10 + a;
            if(10 <= b && b <= 26) dp[i] += i >= 2 ? dp[i - 2] : 1;
        }
        return dp[n - 1];
    }
};



int main()
{
    Solution s;
}