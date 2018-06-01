#include "header.h"

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return true;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i)
            dp[i][i] = nums[i];

        for(int len = 2; len <= n; ++len)
        {
            for(int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                if(len == 2)
                    dp[i][j] = max(nums[i], nums[j]);
                else
                    dp[i][j] = max(nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                                   nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
            }
        }
        return dp[0][n - 1] * 2 >= accumulate(nums.begin(), nums.end(), 0);
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 5, 233, 7};
    cout<<s.PredictTheWinner(a)<<endl;
}
