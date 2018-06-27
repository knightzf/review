#include "header.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int startIdx = 0;
        int endIdx = n - 1;
        while(startIdx != endIdx)
        {
            int midIdx = (startIdx + endIdx) / 2;
            if(nums[midIdx] == nums[midIdx + 1])
            {
                ++midIdx;
            }

            if((midIdx - startIdx + 1) % 2 == 0)
            {
                startIdx = midIdx + 1;
            }
            else
            {
                if(nums[midIdx] == nums[midIdx - 1])
                    endIdx = midIdx - 2;
                else
                    return nums[midIdx];
            }
        }
        return nums[startIdx];
    }
};

int main()
{
    Solution s;
}
