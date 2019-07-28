#include "header.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for(int i = 0, j = 0, prod = 1; i < n; ++i) {
            prod *= nums[i];
            while(j <= i && prod >= k) prod /= nums[j++];
            res += i - j + 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
}