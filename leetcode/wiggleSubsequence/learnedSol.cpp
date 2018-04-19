#include "header.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;

        vector<int> res{nums[0]};
        int i = 1;
        while(i < n && nums[i] == nums[0]) ++i;
        if(i == n) return 1;

        res.push_back(nums[i]);
        bool direction = res.back() > res[0];

        for(i = i + 1; i < n; ++i)
        {
            if(nums[i] != res.back())
            {
                if((direction && nums[i] > res.back()) ||
                    (!direction && nums[i] < res.back()) ) res.back() = nums[i];
                else
                {
                     res.push_back(nums[i]);
                     direction = !direction;
                }
            }
        }

        return res.size();
    }
};

int main()
{
    Solution s;
}
