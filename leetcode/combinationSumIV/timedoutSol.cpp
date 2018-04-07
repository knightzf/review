#include "header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        impl(nums, target, res, 0);
        return res;
    }

    void impl(vector<int>& nums, int target, int& res, int sum)
    {
        if(sum == target)
        {
            ++res;
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(sum + nums[i] <= target)
            {
                impl(nums, target, res, sum + nums[i]);
            }
        }
    }
};

int main()
{
    Solution s;
}
