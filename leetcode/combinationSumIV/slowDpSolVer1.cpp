#include "header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = 1; i <= target; ++i)
        {
            int cnt = 0;
            if(s.find(i) != s.end())
                ++cnt;
            for(int j = i - 1; j > 0; --j)
            {
                if(dp[j] != 0 && s.find(i - j) != s.end())
                    cnt += dp[j];
            }
            dp[i] = cnt;
        }

        return dp[target];
    }
};

int main()
{
    Solution s;
}
