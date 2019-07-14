#include "header.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long> sum(n + 1, 0);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];
        vector<vector<long>> dp(n, vector<long>(m + 1, INT_MAX));
        function<long(int, int)> dfs = [&](int i, int k) {
            if(dp[i][k] == INT_MAX) {
                if(k == 1) dp[i][k] = sum[n] - sum[i];
                else for(int j = i; j < n && (n - j - 1 >= k - 1); ++j) {
                    dp[i][k] = min(dp[i][k], max(sum[j + 1] - sum[i], dfs(j + 1, k - 1)));
                }
            }
            return dp[i][k];
        };
        return dfs(0, m);
    }
};

int main()
{
    Solution s;
}