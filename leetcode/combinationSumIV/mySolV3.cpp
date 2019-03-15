#include "header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dp;
        dp[0] = 1;

        function<int(int)> impl = [&](int sum)
        {
            if(dp.count(sum)) return dp[sum];

            int res = 0;
            for(int i = 0; i < n; ++i)
            {
                if(sum >= nums[i])
                {                    
                    res += 1 * impl(sum - nums[i]);
                }                    
            }
            dp[sum] = res;

            return res;
        };

        for(auto& p : dp)
            cout<<p.first<<" "<<p.second<<endl;

        return impl(target);
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 3};
    cout<<s.combinationSum4(a, 4)<<endl;
}