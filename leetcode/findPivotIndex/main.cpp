#include "header.h"

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int presum = 0;
        for(int i = 0, n = nums.size(); i < n; ++i)
        {
            if(presum == sum - presum - nums[i])
            {
                return i;
            }
            presum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;
}
