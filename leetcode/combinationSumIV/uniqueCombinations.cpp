#include "header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for(int i = 0; i < n; ++i) dp[i][0] = 1;
        for(int i = 1; i < target + 1; ++i) dp[0][i] = (i % nums[0] ? 0 : 1);
        for(int i = 1; i < n; ++i)
        {
            for(int j = 1; j < target + 1; ++j)
            {
                dp[i][j] += dp[i - 1][j];
                if(j >= nums[i]) dp[i][j] += dp[i][j - nums[i]];            
            }
        }
        for(auto& i : dp)
        {
            for(int j : i) cout<<j<<" ";
            cout<<endl;
        }

        //Version 2
        vector<int> dp2(target + 1, 0);
        dp2[0] = 1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = nums[i]; j < target + 1; ++j)
                dp2[j] += dp2[j - nums[i]];
        }
        for(int i : dp2)
            cout<<i<<" ";
        cout<<endl;

        return dp[n - 1][target];
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 2, 3};
    vector<int> a{2, 1};
    cout<<s.combinationSum4(a, 5)<<endl;
}