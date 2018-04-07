#include "header.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(m + 1, INT_MAX));

        for(int i = 0; i < n; ++i)
        {
            dp[i][1] = i == 0 ? nums[i] : (nums[i] + dp[i - 1][1]);
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 2; j <= m; ++j)
            {
                if(i >= j - 1)
                {
                    int minSum = INT_MAX;
                    for(int k = i - 1; k >= j - 1 - 1; --k)
                    {
                        if(max(dp[k][j - 1], dp[i][1] - dp[k][1]) < minSum)
                            minSum = max(dp[k][j - 1], dp[i][1] - dp[k][1]);
                        else
                            break;
                    }
                    dp[i][j] = minSum;
                }
            }
        }

        /*for(int i = 0; i < n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                std::cout<<dp[i][j]<<" ";
            }
            std::cout<<std::endl;
        }*/

        return dp[n - 1][m];
    }
};

int main()
{
    Solution s;
    vector<int> a{7, 2, 5, 10, 8};
    std::cout<<s.splitArray(a, 2)<<std::endl;
}
