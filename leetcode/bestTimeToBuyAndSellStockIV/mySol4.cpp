/**
 * dp[i, j] represents the max profit up until prices[j] using at most i transactions. 
 * dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }
 *          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
 * dp[0, j] = 0; 0 transactions makes 0 profit
 * dp[i, 0] = 0; if there is only one price data point you can't make any transaction.
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0 || n == 0) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for(int i = 1; i < k + 1; ++i) {
            int localMax = dp[i - 1][0] - prices[0];
            for(int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + localMax);
                localMax = max(localMax, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};
