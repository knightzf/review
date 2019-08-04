#include "header.h"

class Solution {
public:
    int knightDialer(int N) {
        static vector<vector<int>> v {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };
        int mod = 1e9 + 7;
        vector<vector<long>> dp(10, vector<long>(N + 1, -1));
        for(int i = 0; i < 10; ++i) dp[i][0] = 0, dp[i][1] = 1;
        function<long(int, int)> dfs = [&](int i, int n) {
            if(dp[i][n] != -1) return dp[i][n];
            long res = 0;
            for(int j : v[i]) {
                res += dfs(j, n - 1);
                res %= mod;
            }
            dp[i][n] = res;
            return res;
        };
        long res = 0;
        for(int i = 0; i < 10; ++i) res += dfs(i, N);
        return res % mod;
    }
};

int main()
{
    Solution s;
}