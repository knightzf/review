#include "header.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int dp = nums[0];
        for(int i = 1; i < n; ++i) {
            if(dp > 0) dp += nums[i];
            else dp = nums[i];
            res = max(res, dp);
        }
        return res;
    }
};

int main()
{
    Solution s;
}