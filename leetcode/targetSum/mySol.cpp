#include "header.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int sum = 0;
        for(int num : nums)
        {
            sum += num;
        }
        if(sum < S || -sum > S) return 0;

        int begin = min(-sum, S - sum);
        int end = max(sum, S + sum);

        vector<vector<int>> dp(n, vector<int>(end - begin + 1, 0));
        dp[0][-nums[0] - begin] += 1;
        dp[0][nums[0] - begin] += 1;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < end - begin + 1; ++j)
            {
                dp[i][j] += dp[i - 1][j - nums[i]];
                dp[i][j] += dp[i - 1][j + nums[i]];
            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < end - begin + 1; ++j)
            {
                std::cout<< dp[i][j]<<" ";
            }
            std::cout<<std::endl;
        }

        return dp[n - 1][S - begin];
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 1, 1, 1, 1};
    //std::cout<<s.findTargetSumWays(a, 3)<<std::endl;
    //vector<int> a{1};
    //std::cout<<s.findTargetSumWays(a, 1)<<std::endl;
    //vector<int> a{0, 0, 0, 0, 0, 0, 0, 0, 1};
    //std::cout<<s.findTargetSumWays(a, 1)<<std::endl;
    //vector<int> a{7,9,3,8,0,2,4,8,3,9};
    //std::cout<<s.findTargetSumWays(a, 0)<<std::endl;
}
