#include "header.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int lenZero = 0;
        int lenOne = 0;
        for(int i = 0; i < n;)
        {
            if(nums[i] == 0)
            {
                if(i > 0 && nums[i - 1] == 1)
                    lenZero = lenOne + 1;
                else
                    lenZero = 1;
                res = max(res, lenZero);
                ++i;
            }
            else
            {
                int j = i;
                while(j < n && nums[j] == 1) ++j;
                lenOne = j - i;
                res = max(res, lenOne + lenZero);
                i = j;
            }
        }
        if(nums.back() == 1)
            res = max(res, lenOne + lenZero);
        return res;
    }
};

int main()
{
    Solution s;
}
