#include "header.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = n - 1;
        while(true)
        {
            int partionIdx = partitionImpl(nums, i, j);
            if(partionIdx > k - 1)
                j = partionIdx - 1;
            else if(partionIdx < k - 1)
                i = partionIdx + 1;
            else
                return nums[partionIdx];
        }
    }

    int partitionImpl(vector<int>& nums, int i, int j)
    {
        int pivotValue = nums[j];
        int startIdx = i;
        for(int k = i; k < j; ++k)
        {
            if(nums[k] >= pivotValue)
            {
                std::swap(nums[startIdx], nums[k]);
                ++startIdx;
            }
        }
        std::swap(nums[startIdx], nums[j]);
        return startIdx;
    }
};

int main()
{
    Solution s;
}
