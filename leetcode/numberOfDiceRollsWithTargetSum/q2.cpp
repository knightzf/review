#include "header.h"

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        int mod = 1e9 + 7;
        for(int i = 1; i <= d; ++i) {
            for(int j = 1; j <= target; ++j) {
                for(int k = 1; k <= f; ++k) {
                    if(j >= k) {
                        dp[i][j] = (static_cast<long>(dp[i][j]) + dp[i - 1][j - k]) % mod;
                    }
                }
            }
        }
        return dp[d][target];
    }
};

int main()
{
    Solution s;
    s.numRollsToTarget(1, 6, 3);
}
