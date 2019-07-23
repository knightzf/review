#include "header.h"

class Solution {
public:
    int numDecodings(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        if(n == 0) return 0;
        long dp[n + 1] = {0};
        dp[0] = 1;
        dp[1] = count(s[0]);
        for(int i = 1; i < n; ++i) {
            dp[i + 1] += dp[i] * count(s[i]);
            dp[i + 1] %= mod;
            dp[i + 1] += dp[i - 1] * count(s[i - 1], s[i]);
            dp[i + 1] %= mod;
        }
        return dp[n];
    }

    int count(char c) {
        return c == '*' ? 9 : (c == '0' ? 0 : 1);
    }

    int count(char a, char b) {
        if(a == '*' and b == '*') return 15;
        if(a == '*') return 1 + (b <= '6' ? 1 : 0);
        if(b == '*') return a == '1' ? 9 : (a == '2' ? 6 : 0);
        int t = (a - '0') * 10 + b - '0';
        return (t >= 10 && t <= 26) ? 1 : 0;
    }
};

int main()
{
    Solution s;
}