#include "header.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long> sum(n + 1, 0);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];
        vector<vector<long>> dp(n, vector<long>(m + 1, INT_MAX));
        for(int i = 0; i < n; ++i) dp[i][1] = sum[n] - sum[i];
        for(int j = 2; j < m + 1; ++j) {
            for(int i = n - 1; i >= 0; --i) {
                for(int k = i + 1; k < n; ++k)
                    dp[i][j] = min(dp[i][j], max(sum[k] - sum[i], dp[k][j - 1]));
            }
        }
        return dp[0][m];
    }
};

int main()
{
    Solution s;
}