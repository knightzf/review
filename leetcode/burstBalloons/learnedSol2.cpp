#include "header.h"

class Solution {
private:
    int n;
public:
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        //int dp[n + 2][n + 2] = {0};
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        return impl(nums, dp, -1, n);
    }

    int impl(auto& nums, auto& dp, int leftIdx, int rightIdx)
    {
        static auto getnum = [&](int i){
            if(i == -1 || i == n) return 1;
            return nums[i];
        };

        if(leftIdx + 1 == rightIdx) return 0;

        if(dp[leftIdx + 1][rightIdx + 1]) return dp[leftIdx + 1][rightIdx + 1];
        int res = 0;
        for(int i = leftIdx + 1; i < rightIdx; ++i)
        {
            res = max(res, getnum(i) * getnum(leftIdx) * getnum(rightIdx) +
                      impl(nums, dp, leftIdx, i) + impl(nums, dp, i, rightIdx));
        }

        dp[leftIdx + 1][rightIdx + 1] = res;
        return res;
    }
};

int main()
{
    Solution s;
}
