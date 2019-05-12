#include "header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        for(int i = 0, j = 1; j < n; ++j)
        {
            if(nums[j] != nums[i])
            {
                nums[i + 1] = nums[j];
                ++i;
            }
        }
        return i + 1;
    }
};

int main()
{
    Solution s;
}