#include "header.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int t = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                res = max(res, t);
                t = 0;
            }
            else
                ++t;
        }
        res = max(res, t);
        return res;
    }
};

int main()
{
    Solution s;
}
