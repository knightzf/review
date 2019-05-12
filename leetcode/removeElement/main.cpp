#include "header.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), j = n - 1;
        for(int i = 0; i <= j; ++i)
        {
            if(nums[i] == val)
            {
                swap(nums[i], nums[j]);
                --j;
                --i;
            }
        }
        return j + 1;
    }
};

int main()
{
    Solution s;
}