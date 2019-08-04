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
        vector<vector<long>> dp(10, vector<long>(N + 1, 0));
        for(int i = 0; i < 10; ++i) dp[i][1] = 1;
        for(int j = 2; j <= N; ++j) {
            for(int i = 0; i < 10; ++i) {
                for(int k : v[i]) dp[i][j] += dp[k][j - 1];
                dp[i][j] %= mod;
            }
        }
        long res = 0;
        for(int i = 0; i < 10; ++i) res += dp[i][N];
        return res % mod;
    }
};

int main()
{
    Solution s;
}