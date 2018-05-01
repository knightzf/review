#include "header.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; ++i)
            sum += nums[i];
        if((sum & 1) == 1) return false;
        sum /= 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false)); //dp[i][j] means if nums[til ith] can get j
        dp[0][0] = true;
        for(int i = 1; i < n + 1; ++i)
            dp[i][0] = true;
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 1; j < sum + 1; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if(nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        for(int i = 0; i < n + 1; ++i)
        {
            for(int j = 0; j < sum + 1; ++j)
            {
                std::cout<<dp[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        return dp[n][sum];
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 5, 11, 5};
    s.canPartition(a);
}
