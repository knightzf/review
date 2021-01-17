class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (sum + S & 1)) return 0;
        int target = (sum + S) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i : nums) {
            for(int j = target; j >= i; --j) {
                dp[j] += dp[j - i];
            }
        }
        return dp[target];
    }
};
