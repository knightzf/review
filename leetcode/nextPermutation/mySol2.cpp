#include "header.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        for(; i > 0; --i)
        {
            if(nums[i] > nums[i - 1]) break;
        }

        if(i - 1 >= 0)
        {
            int j = i;
            while(j + 1 < n && nums[j + 1] > nums[i - 1])
            {
                j = j + 1;
            }
            swap(nums[i - 1], nums[j]);
        }

        reverse(nums.begin() + i, nums.end());
    }
};

int main()
{
    Solution s;
}