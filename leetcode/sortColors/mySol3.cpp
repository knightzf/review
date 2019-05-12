#include "header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int oneStart = 0, twoEnd = n - 1;
        for(int i = 0; i < n;)
        {
            if(nums[i] == 0 && i > oneStart)
            {
                swap(nums[i], nums[oneStart++]);
                ++i;
            }
            else if(nums[i] == 2 && i < twoEnd)
            {
                swap(nums[i], nums[twoEnd--]);
            }
            else ++i;
        }
    }
};

int main()
{
    Solution s;
}