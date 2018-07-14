#include "header.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> t = nums;
        sort(t.begin(), t.end());
        int n = nums.size();
        int start = n - 1;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != t[i])
            {
                start = i;
                break;
            }
        }

        int end = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(nums[i] != t[i])
            {
                end = i;
                break;
            }
        }

        return start < end ? end - start + 1 : 0;
    }
};

int main()
{
    Solution s;
}
